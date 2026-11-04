#!/usr/bin/env python3
"""Cooperative scheduler on top of the partial MIPS harness.

Goal: drive the game's own thread graph from the boot chain and watch
`FUN_8004cc5c(0)` fire by itself, rather than calling it per slot.

What is real: instruction execution, both RAM images, the cartridge mapping,
message-queue semantics (osCreateMesgQueue/osRecvMesg/osSendMesg on emulated
memory), thread creation and round-robin scheduling.

What is stubbed: hardware registers read as zero and ignore writes (0xA0000000-
0xB0000000 and 0xB4000000-0xC0000000), video, controllers, RSP/RDP. A thread that
polls a register waiting for a value will therefore spin — the run reports where it
spun instead of pretending it completed.

Every event (thread create/start/block, and any call to the loader) is logged, so
the output says exactly how far execution got.
"""
import struct, sys
from mips_harness import Cpu, Memory, Fault, RAM_BASE, RAM_SIZE, CART_BASE, CART_MASK, SENTINEL
from mips_harness import BOOT_VA, STAGE2_VA, DESC_TABLE, REGISTRY

O_CREATE_THREAD = 0x80006D60
O_START_THREAD = 0x8000DB90
O_CREATE_MQ = 0x80006D30
O_RECV = 0x8000C9E0
O_SEND = 0x8000CB60
INFLATE_INIT, INFLATE_RUN, INFLATE_FREE = 0x80004550, 0x800045DC, 0x80004594
OPEN = 0x8004CC5C

class Block(Exception):
    def __init__(self, mq): self.mq = mq

class HwMemory(Memory):
    """RAM + cartridge + a small real hardware model.

    Corrects two mapping errors: 0x80000180 is RDRAM (physical 0x180), NOT
    cartridge ROM — the earlier "ROM 0xd00" was this harness's image-projection
    offset, not a hardware translation — and 0xBFC00380 is the PIF boot ROM at
    physical 0x1FC00380, a different component from the cartridge's IPL3.

    MI_INTR (0xA4300008) holds per-device pending bits, MI_INTR_MASK (0xA430000C)
    is the mask, and the MI aggregate asserts **CAUSE_IP3 (0x400)** — one CPU
    interrupt line for all RCP devices. A device bit must never be mapped straight
    onto an arbitrary Cause bit: IP6 (0x2000) is external interrupt level 6.
    """
    MI_INTR, MI_MASK, RCP_IP3 = 0xA4300008, 0xA430000C, 0x400
    def _loc(self, a, n):
        try:
            return Memory._loc(self, a, n)
        except Fault:
            if 0xA0000000 <= a < 0xC0000000:
                return bytes(n), 0
            raise
    def __init__(self, ram, rom):
        super().__init__(ram, rom)
        self.watch = {}            # address -> label, for vector installation
        self.mi_pending = 0
        self.mi_mask = 0
        self.watch_hits = []
    def assert_device(self, bit):
        """A device raises its MI pending bit; MI then decides about IP3."""
        self.mi_pending |= bit
        return self.rcp_asserted()
    def ack_device(self, bit):
        self.mi_pending &= ~bit
        return self.rcp_asserted()
    def rcp_asserted(self):
        return 0x400 if (self.mi_pending & self.mi_mask) else 0
    def read(self, a, n):
        if a == self.MI_INTR: return self.mi_pending
        if a == self.MI_MASK: return self.mi_mask
        return Memory.read(self, a, n)
    def write(self, a, n, v):
        if a in self.watch:
            self.watch_hits.append((a, self.watch[a], v, n))
        if a == self.MI_INTR:            # writing 1s clears pending device bits
            self.mi_pending &= ~v
            return
        if a == self.MI_MASK:
            self.mi_mask = v
            return
        if 0xA0000000 <= a < 0xC0000000 and not (CART_BASE <= a < CART_BASE + 0x04000000):
            return
        Memory.write(self, a, n, v)

class Sched:
    def __init__(self, rom, stage2, budget=3_000_000, slice_steps=30_000):
        ram = bytearray(RAM_SIZE)
        ram[BOOT_VA - RAM_BASE:BOOT_VA - RAM_BASE + 0x13600] = rom[0x1000:0x14600]
        ram[STAGE2_VA - RAM_BASE:STAGE2_VA - RAM_BASE + len(stage2)] = stage2
        self.mem = HwMemory(ram, rom)
        self.stage2 = stage2
        self.budget, self.slice = budget, slice_steps
        self.threads = {}           # id -> dict(regs, pc, stack, state, waiting)
        self.by_addr = {}           # thread struct addr -> id
        self.queues = {}            # mq addr -> dict(count, buf, n, idx, waiters)
        self.events = []
        self.loads = []
        self.stubcalls = []
        self.event_msgs = []        # (mq, msg) as registered via osSetEventMesg
        self.frames = 0
        self.on_slice = None
        # ---- guest scheduler structures -------------------------------------
        # libultra keeps ready threads on a CIRCULAR list whose terminator is the
        # queue head node itself. Node layout, taken from the dispatcher at
        # 0x80000f14 ("lw t6,0x4(t8)" priority, "lw t8,0x0(t8)" next):
        #   +0x00 next, +0x04 priority, +0x08 queue, +0x0C tlnext,
        #   +0x10 state, +0x14 id, +0x18 fp, +0x20 context
        self.READY_HEAD = 0x80012940     # sentinel node; 0x80012948/0x8001294c point here
        self.NODE_NEXT, self.NODE_PRI = 0, 4
        self.NODE_STATE, self.NODE_ID = 0x10, 0x14
        self.CURRENT = 0x80012950
        self.TAIL = 0x80012954
        self.guest_ready = []
        self.dispatch_log = []      # phase 1: host choice vs guest queue state
        self.msglog = []        # every send/recv with PC, message value and queue state
        self.current = None
        self.hooks = {}
        self._install()
        self.cpu = Cpu(self.mem, self.hooks)
        self.mem.watch = {0x80000000: "UT_VEC", 0x80000080: "XUT_VEC",
                          0x80000100: "ECC_VEC", 0x80000180: "E_VEC"}

    # ---------------- kernel hooks ----------------
    def _install(self):
        def create_thread(c, a0, a1, a2, a3, *rest):
            tid, entry, stack = a1, a2, None
            # osCreateThread(t, id, entry, arg, stack, pri) -> 5th arg is on stack
            # osCreateThread(t, id, entry, arg, stack, pri): stack and pri are the
            # 5th/6th arguments and travel on the stack, at 16(sp) and 20(sp).
            stack = self.mem.read(c.r[29] + 16, 4) if c.r[29] else 0
            pri = self.mem.read(c.r[29] + 20, 4) if c.r[29] else 0
            self.by_addr[a0] = tid
            # build the guest OSThread header so its own code can read it
            self.mem.write(a0 + self.NODE_NEXT, 4, self.READY_HEAD)
            self.mem.write(a0 + self.NODE_PRI, 4, pri)
            self.mem.write(a0 + 8, 4, 0)
            self.mem.write(a0 + 0x0C, 4, 0)
            self.mem.write(a0 + self.NODE_STATE, 4, 1)      # STOPPED
            self.mem.write(a0 + self.NODE_ID, 4, tid)
            self.threads[tid] = {"regs": [0]*32, "pc": entry, "stack": stack,
                                 "os_thread": a0,
                                 "state": "created", "waiting": None, "runs": 0}
            self.events.append(("create", tid, entry, stack))
            return 0
        def start_thread(c, a0, a1, a2, a3):
            tid = self.by_addr.get(a0)
            if tid in self.threads and self.threads[tid]["state"] == "created":
                self.threads[tid]["state"] = "runnable"
                self.mem.write(self.threads[tid]["os_thread"] + self.NODE_STATE, 4, 2)
                self.ready_insert(tid)
                self.events.append(("start", tid, 0, 0))
            return 0
        def create_mq(c, a0, a1, a2, a3):
            self.queues[a0] = {"buf": a1, "n": a2, "idx": 0, "count": 0, "waiters": []}
            return 0
        def recv(c, a0, a1, a2, a3):
            q = self.queues.setdefault(a0, {"buf": 0, "n": 8, "idx": 0, "count": 0, "waiters": []})
            self.msglog.append((c.pc, "recv", a0, None, q["count"], a2, self.current))
            if q["count"] == 0:
                if a2:                    # OS_MESG_BLOCK
                    q["waiters"].append(self.current)
                    raise Block(a0)
                return -1
            val = self.mem.read(q["buf"] + q["idx"]*4, 4)
            q["idx"] = (q["idx"] + 1) % max(1, q["n"]); q["count"] -= 1
            if a1: self.mem.write(a1, 4, val)
            return 0
        def send(c, a0, a1, a2, a3):
            q = self.queues.get(a0, {"count": 0})
            self.msglog.append((c.pc, "send", a0, a1, q["count"], a2, self.current))
            return self.post(a0, a1)
        def inflate_init(c, a0, a1, a2, a3): return 0
        def inflate_run(c, a0, a1, a2, a3):
            import zlib
            raw = bytes(self.mem.read(a1+i, 1) for i in range(a3))
            try: out = zlib.decompress(raw)
            except Exception: return 1
            for i, b in enumerate(out): self.mem.write(a2+i, 1, b)
            self.loads.append({"src": a1, "dst": a2, "csize": a3, "usize": len(out),
                               "thread": self.current})
            return 0
        def inflate_free(c, a0, a1, a2, a3): return 0
        def raw_pi(c, a0, a1, a2, a3):
            for i in range(a3): self.mem.write(a2+i, 1, self.mem.rom[(a1+i) & CART_MASK])
            self.loads.append({"dma_cart": a1, "dma_dst": a2, "len": a3, "thread": self.current})
            return 0
        def note_open(c, a0, a1, a2, a3):
            self.events.append(("OPEN", self.current, a0, 0))
            return None
        def set_event_mesg(c, a0, a1, a2, a3):
            """osSetEventMesg(event, mq, msg): the hardware-interrupt inbox."""
            self.event_msgs.append((a1, a2))
            self.stubcalls.append((c.pc, a0, a1, a2, a3))
            return 0
        def stub(c, a0, a1, a2, a3):
            self.stubcalls.append((c.pc, a0, a1, a2, a3))
            return 0
        self.hooks.update({
            O_CREATE_THREAD: create_thread, O_START_THREAD: start_thread,
            O_CREATE_MQ: create_mq, O_RECV: recv, O_SEND: send,
            0x8000CC90: set_event_mesg,
            INFLATE_INIT: inflate_init, INFLATE_RUN: inflate_run,
            INFLATE_FREE: inflate_free, 0x8000C870: raw_pi,
            OPEN: note_open,
        })
        for a in (0x8000BE50, 0x8000BE60, 0x8000E920, 0x8000CEC0, 0x8000E350,
                  0x800072E0, 0x80007300, 0x8000E4C0, 0x8000E800,
                  0x80006D00, 0x8000DB70, 0x8000CE20):
            self.hooks.setdefault(a, stub)

    def _walk(self, node):
        """Read node->next defensively: the guest may corrupt the list too."""
        try: return self.mem.read(node + self.NODE_NEXT, 4)
        except Fault: return None

    def ready_insert(self, tid):
        """Append a thread node to the guest's circular ready list."""
        node = self.threads.get(tid, {}).get("os_thread")
        if not node or tid in self.guest_ready: return
        p, guard = self.READY_HEAD, 0
        while guard < 64:
            nxt = self._walk(p)
            if nxt is None or nxt == self.READY_HEAD or nxt == 0: break
            p = nxt; guard += 1
        self.mem.write(node + self.NODE_NEXT, 4, self.READY_HEAD)
        self.mem.write(p + self.NODE_NEXT, 4, node)
        self.mem.write(self.TAIL, 4, node)
        self.guest_ready.append(tid)

    def ready_remove(self, tid):
        """Unlink a thread node from the circular ready list."""
        node = self.threads.get(tid, {}).get("os_thread")
        if not node: return
        p, guard = self.READY_HEAD, 0
        while guard < 64:
            nxt = self._walk(p)
            if nxt is None or nxt == self.READY_HEAD or nxt == 0: break
            if nxt == node:
                self.mem.write(p + self.NODE_NEXT, 4, self.mem.read(node + self.NODE_NEXT, 4))
                if tid in self.guest_ready: self.guest_ready.remove(tid)
                return
            p = nxt; guard += 1

    def post(self, mq, msg):
        """osSendMesg semantics, shared by the app and by hardware ticks."""
        q = self.queues.setdefault(mq, {"buf": 0, "n": 8, "idx": 0, "count": 0, "waiters": []})
        if q["count"] >= q["n"]:
            return -1
        pos = (q["idx"] + q["count"]) % max(1, q["n"])
        if q["buf"]:
            try: self.mem.write(q["buf"] + pos*4, 4, msg)
            except Fault: pass
        q["count"] += 1
        while q["waiters"]:
            tid = q["waiters"].pop(0)
            if self.threads[tid]["state"] == "blocked":
                self.threads[tid]["state"] = "runnable"
                self.threads[tid]["waiting"] = None
                self.ready_insert(tid)
                if self.threads[tid].get("os_thread"):
                    self.mem.write(self.threads[tid]["os_thread"] + self.NODE_STATE, 4, 2)
                self.events.append(("wake", tid, mq, msg))
                break
        return 0

    # ---------------- scheduling ----------------
    def run(self, root_entry, root_a0=0, max_frames=200, vi_after=None):
        self.mem.write(self.READY_HEAD + self.NODE_NEXT, 4, self.READY_HEAD)  # empty circular
        self.mem.write(self.READY_HEAD + self.NODE_PRI, 4, 0)
        self.mem.write(self.TAIL, 4, 0)
        tid = 0
        self.threads[tid] = {"regs": [0]*32, "pc": root_entry, "stack": 0x803FF000,
                             "state": "runnable", "waiting": None, "runs": 0}
        self.events.append(("create", tid, root_entry, 0))
        spent = 0
        stalls = 0
        while spent < self.budget:
            live = [t for t, v in self.threads.items() if v["state"] == "runnable"]
            if not live:
                # every thread is blocked: this is the moment a hardware interrupt
                # would fire. Deliver the next message registered via
                # osSetEventMesg and let the interrupt-handler thread drain it.
                if not self.event_msgs or stalls >= max_frames:
                    break
                mq, msg = self.event_msgs[stalls % len(self.event_msgs)]
                q = self.queues.setdefault(mq, {"buf": 0, "n": 8, "idx": 0,
                                                "count": 0, "waiters": []})
                if self.post(mq, msg) == 0:
                    self.frames += 1
                    self.events.append(("tick", stalls, mq, msg))
                    stalls += 1
                else:
                    break
                continue
            tid = live[0] if self.current is None else (live[(live.index(self.current)+1) % len(live)] if self.current in live else live[0])
            self.current = tid
            if getattr(self, "on_slice", None):
                self.on_slice()
            if vi_after is not None and spent > vi_after and not getattr(self, "_vi", False):
                self._vi = True
                # Device layer: VI raises its MI pending bit. MI decides whether the
                # aggregate RCP line asserts CAUSE_IP3 (0x400). The CPU never sees
                # 0x08 or 0x2000 — only IP3.
                self.mem.mi_mask |= 0x08              # enable VI in MI_INTR_MASK
                self.mem.assert_device(0x08)          # MI_INTR bit 3 = VI
                self.events.append(("irq", 0x08, self.mem.mi_mask,
                                    self.mem.rcp_asserted()))
            th = self.threads[tid]
            # The guest keeps its own idea of the current thread in 0x80012950 and
            # the exception handler dereferences it. A host-side scheduler that
            # does not maintain it is a semantic gap: threads run, but the guest's
            # __osCurrentThread stays stale.
            # A preempted thread goes BACK on the ready list; only the running one
            # is off it. Removing without re-inserting makes the guest queue a
            # fiction that happens to terminate.
            if self.current is not None and self.current != tid:
                prev = self.threads.get(self.current, {})
                if prev.get("state") == "runnable":
                    if prev.get("os_thread"):
                        self.mem.write(prev["os_thread"] + self.NODE_STATE, 4, 2)
                    self.ready_insert(self.current)
            # phase 1 differential: snapshot the guest's own view before we choose
            order, p_, guard = [], self.READY_HEAD, 0
            while guard < 64:
                try:
                    p_ = self.mem.read(p_ + self.NODE_NEXT, 4)
                except Fault:
                    break                      # malformed: stop, keep what we have
                if p_ == self.READY_HEAD: break
                if p_ == 0:                       # malformed: node->next == 0
                    break
                order.append(p_); guard += 1
            prios = {n: self.mem.read(n + self.NODE_PRI, 4) for n in order}
            guest_best = max(order, key=lambda n: prios.get(n, 0)) if order else None
            self.dispatch_log.append({"step": spent, "host": th.get("os_thread"),
                                      "order": order, "prios": prios,
                                      "guest_best": guest_best})
            self.ready_remove(tid)          # running threads are off the ready list
            self.mem.write(self.CURRENT, 4, th.get("os_thread") or 0)
            if th.get("os_thread"):
                self.mem.write(th["os_thread"] + self.NODE_STATE, 4, 4)   # RUNNING
            c = self.cpu
            c.r = list(th["regs"]); c.pc = th["pc"]; c.delay = None
            c.r[29] = th["stack"] or 0x803FF000
            c.r[31] = SENTINEL
            th["runs"] += 1
            n = 0
            try:
                while n < self.slice and spent < self.budget:
                    if c.pc == SENTINEL:
                        th["state"] = "done"
                        self.ready_remove(tid); break
                    if c.pc in self.hooks:
                        fn = self.hooks[c.pc]
                        ret = fn(c, c.r[4], c.r[5], c.r[6], c.r[7])
                        if c.pc == OPEN: pass
                        c.r[2] = (ret or 0) & 0xFFFFFFFF
                        c.pc = c.r[31]; n += 1; spent += 1
                        continue
                    c.count = (c.count + 1) & 0xFFFFFFFF
                    if c.compare and c.count == c.compare:
                        c.timer_pending = True
                    c.hw_pending = (c.hw_pending & ~0x400) | self.mem.rcp_asserted()
                    if c.interrupt_pending():
                        c.pc = c.interrupt_entry()
                        c.delay = None
                        n += 1; spent += 1
                        continue
                    cur, after = c.pc, c.delay
                    c.delay = None
                    c.step(cur)
                    if c.jump_now is not None:
                        c.pc, c.jump_now = c.jump_now, None
                        n += 1; spent += 1
                        continue
                    c.pc = after if after is not None else cur + 4
                    n += 1; spent += 1
            except Block as b:
                th["state"] = "blocked"; th["waiting"] = b.mq
                self.ready_remove(tid)
                if th.get("os_thread"):
                    self.mem.write(th["os_thread"] + self.NODE_STATE, 4, 8)   # WAITING
                self.events.append(("block", tid, b.mq, 0))
            except Fault as e:
                self.events.append(("fault", tid, c.pc, str(e)[:30]))
                th["state"] = "faulted"
            th["regs"], th["pc"] = list(c.r), c.pc
            if th["state"] == "runnable" and n >= self.slice:
                pass    # preempted by slice, stays runnable
            self.current = None
        return spent

import hashlib, json, os

def save_checkpoint(s, outdir="checkpoint"):
    """Preserve a full, replayable snapshot of a run.

    Purpose is reproducibility, not debugging: given the same cartridge, the same
    two images and the same initial state, this state must recur. A digest over
    every file except itself makes that checkable in one comparison.
    """
    os.makedirs(outdir, exist_ok=True)
    names = ["r0","at","v0","v1","a0","a1","a2","a3","t0","t1","t2","t3","t4","t5","t6","t7",
             "s0","s1","s2","s3","s4","s5","s6","s7","t8","t9","k0","k1","gp","sp","s8","ra"]
    def w(name, obj):
        with open(os.path.join(outdir, name), "w") as f:
            json.dump(obj, f, indent=1, sort_keys=True)
    w("cpu_registers.json", {str(t): {names[i]: format(v, "#010x")
                                      for i, v in enumerate(th["regs"])}
                             for t, th in sorted(s.threads.items())})
    w("fpu_registers.json", {str(t): [format(v, "#018x") for v in s.cpu.f]
                             for t in sorted(s.threads)})
    w("thread_table.json", {str(t): {"state": th["state"], "pc": format(th["pc"], "#010x"),
                                     "stack": format(th["stack"], "#010x"),
                                     "waiting_on": (format(th["waiting"], "#x")
                                                    if th["waiting"] else None),
                                     "slices": th["runs"]}
                            for t, th in sorted(s.threads.items())})
    w("message_queues.json", {format(mq, "#010x"): {"count": q["count"], "capacity": q["n"],
                                                    "waiters": len(q["waiters"])}
                              for mq, q in sorted(s.queues.items())})
    w("memory_regions.json", {
        "ram": {"base": "0x80000000", "size": len(s.mem.ram),
                "sha256": hashlib.sha256(bytes(s.mem.ram)).hexdigest()},
        "cartridge": {"base": "0xb0000000", "size": len(s.mem.rom),
                      "sha256": hashlib.sha256(s.mem.rom).hexdigest()},
        "images": {"boot": {"vram": "0x80000480", "rom": "0x1000..0x14600"},
                   "stage2": {"vram": "0x80018a80", "length": len(s.stage2),
                              "sha256": hashlib.sha256(s.stage2).hexdigest()}},
        "hardware_window": {"range": "0xa0000000-0xc0000000",
                            "behaviour": "reads as zero, writes ignored"}})
    w("execution_trace.json", {
        "instructions": s.spent if hasattr(s, "spent") else None,
        "events": [{"kind": e[0], "a": e[1], "b": e[2], "c": e[3]} for e in s.events],
        "loader_calls": s.loads,
        "event_registrations": [{"mq": format(m, "#x"), "msg": format(g, "#x")}
                                for m, g in s.event_msgs]})
    w("unresolved_instructions.json", [{"thread": e[1], "pc": format(e[2], "#010x"),
                                        "reason": e[3]}
                                       for e in s.events if e[0] == "fault"])
    dig = hashlib.sha256()
    for n in sorted(os.listdir(outdir)):
        if n == "run_digest.json": continue
        dig.update(open(os.path.join(outdir, n), "rb").read())
    w("run_digest.json", {"digest": dig.hexdigest(), "files": sorted(
        n for n in os.listdir(outdir) if n != "run_digest.json")})
    return dig.hexdigest()


def main():
    rom = open("rom/Resident Evil 2 (USA) (Rev 1).z64", "rb").read()
    stage2 = open("assets/unpacked/00000_0014420_1172240.bin", "rb").read()
    s = Sched(rom, stage2)
    # the boot chain ends by creating + starting thread 7 (entry FUN_8004d190)
    spent = s.run(0x8004D344)
    print(f"executed {spent:,} instructions\n")
    print("threads:", {t: (v["state"], format(v["pc"], '#x'), v["runs"])
                       for t, v in s.threads.items()})
    print("\nevents:")
    for e in s.events:
        if e[0] in ("create", "start", "block"):
            print(f"  {e[0]:7} thread {e[1]:<3} {format(e[2], '#010x')}")
        else:
            print(f"  {e}")
    print(f"\nloader calls observed: {len(s.loads)}")
    for l in s.loads[:10]:
        print("  ", {k: (format(v, '#010x') if isinstance(v, int) and v > 0xFF else v)
                     for k, v in l.items()})
    for t, v in sorted(s.threads.items()):
        print(f"  thread {t}: {v['state']:9} pc={v['pc']:#010x} runs={v['runs']}"
              + (f" waiting on {v['waiting']:#x}" if v['waiting'] else ""))
    print("\n=== event-delivery trace (pc, op, queue, msg, count_before, flag, thread) ===")
    for pc, op, mq, msg, cnt, flag, tid in s.msglog:
        mv = format(msg, "#x") if msg is not None else "-"
        who = f"thread {tid}"
        print(f"  {pc:#010x} {op:4} q={mq:#010x} msg={mv:>8} before={cnt} "
              f"flag={flag} {who}")
    print(f"\nframes ticked: {s.frames}   events delivered: "
          f"{sorted({m for _, m in s.event_msgs})}")
    for e in s.events:
        if e[0] == "tick":
            print(f"  tick {e[1]:<3} -> mq {format(e[2],'#x')} msg {format(e[3],'#x')}")
    d = save_checkpoint(s)
    print(f"\nopen(0) fired: {any(e[0] == 'OPEN' for e in s.events)}")
    print(f"checkpoint written to checkpoint/  run digest {d[:32]}…")
    print("\nstub calls whose first argument looks like a small event id "
          "(osSetEventMesg candidates):")
    seen = set()
    for pc, a0, a1, a2, a3 in s.stubcalls:
        if a0 <= 15 and a1 > 0x80000000 and (pc, a0, a1, a2) not in seen:
            seen.add((pc, a0, a1, a2))
            q = "known-queue" if a1 in s.queues else ""
            print(f"  stub {pc:#010x}(event={a0}, mq={a1:#010x}, msg={a2:#x}) {q}")

if __name__ == "__main__":
    main()
