#!/usr/bin/env python3
"""Phase 2: the guest owns thread scheduling.

Architecture, deliberately different from run_scheduler.py:

  * ONE architectural CPU state — PC, GPRs, HI/LO, CP0, FPU. There is no host
    thread table and no per-thread register file. Suspended contexts live in guest
    RDRAM inside their OSThread structures, exactly where the guest put them.
  * NO hooks on osCreateThread / osStartThread / osCreateMesgQueue / osRecvMesg /
    osSendMesg. Those run as guest instructions and mutate the guest's own circular
    lists and thread states.
  * The host still models hardware: cartridge reads, the inflate primitive, PI DMA,
    MI pending/mask, and register reads that would otherwise spin forever.
  * Python follows the PC the guest establishes. It never chooses a thread and
    never writes 0x80012950.

Everything the guest decides is recorded: context switches (writes to
0x80012950 by guest code), every message-queue structure change, and the
resulting PC.
"""
import json, struct, sys, zlib

from mips_harness import Cpu, Fault, SENTINEL, RAM_BASE, RAM_SIZE, CART_BASE, CART_MASK
from run_scheduler import HwMemory, BOOT_VA, STAGE2_VA

INFLATE_INIT, INFLATE_RUN, INFLATE_FREE = 0x80004550, 0x800045DC, 0x80004594
RAW_PI_DMA, PI_WAIT = 0x8000C870, 0x8000BE50
CURRENT = 0x80012950

def build(rom, stage2, with_ipl3=False):
    ram = bytearray(RAM_SIZE)
    ram[BOOT_VA - RAM_BASE:BOOT_VA - RAM_BASE + 0x13600] = rom[0x1000:0x14600]
    # The real machine also has IPL3 resident at 0x80000000-0x8000047f. An ares RDRAM
    # dump pinned the mapping exactly: RDRAM 0x80000010 held bytes found at ROM 0x4d0,
    # so RDRAM 0x80000000 <-> ROM 0x4c0. Without it the harness starts with that region
    # zeroed and misses the PI/cache setup that lives there.
    # IPL3's R4300 stub at 0x80000000-0x800003ff (extent pinned from an ares RDRAM dump;
    # 0x80000400-0x8000047f is zero there). DEFAULT OFF: with it present the harness
    # faults after 3407 instructions at 0x80088554 on an access to 0x805ee000, with
    # either a 0x400- or 0x480-byte load - so something in this harness executes that
    # region, which the real machine does not. Enable only for that investigation.
    if with_ipl3:
        ram[0:0x400] = rom[0x4C0:0x8C0]
        # ...but 0x80000300-0x800003FF is NOT code. IPL3 WRITES boot variables there:
        # an ares dump shows 0x80000318 = 0x00800000 (the detected RDRAM size, 8 MB on
        # ares' default config) and 0x300/0x31C/0x320/0x33C = 0. FUN_8004D190 compares
        # 0x80000318 against 0x400001 to choose the 4 MB or 8 MB video layout, so loading
        # IPL3's bytes over it fed the game a garbage "RDRAM size" and sent it to
        # framebuffers past the end of this 4 MB harness.
        # 0x80000300 must be NON-ZERO: main does
        #   lw v0,0x300(v0) / bne v0,zero,+0xc / beq v0,zero,-0x4
        # i.e. it spins forever at 0x8000057c unless IPL3 left a non-zero value there.
        # An ares dump shows 1. Zeroing it (my earlier "restore the boot variables")
        # is what made every run from main sit in that loop.
        ram[0x300:0x304] = (1).to_bytes(4, "big")
        for a in (0x31C, 0x320, 0x33C):
            ram[a:a+4] = b"\0\0\0\0"
        ram[0x318:0x31C] = (RAM_SIZE).to_bytes(4, "big")   # this machine has 4 MB
    ram[STAGE2_VA - RAM_BASE:STAGE2_VA - RAM_BASE + len(stage2)] = stage2
    mem = HwMemory(ram, rom)
    mem.watch = {CURRENT: "current_thread"}
    return mem

def hooks_for(mem, log):
    def inflate_init(c, a0, a1, a2, a3): return 0
    def inflate_run(c, a0, a1, a2, a3):
        raw = bytes(mem.read(a1 + i, 1) for i in range(a3))
        try: out = zlib.decompress(raw)
        except Exception: return 1
        for i, b in enumerate(out): mem.write(a2 + i, 1, b)
        log.append(("inflate", a1 & CART_MASK, a3, a2, len(out), c.pc))
        return 0
    def inflate_free(c, a0, a1, a2, a3): return 0
    def raw_pi(c, a0, a1, a2, a3):
        for i in range(a3): mem.write(a2 + i, 1, mem.rom[(a1 + i) & CART_MASK])
        log.append(("pi_dma", a1, a3, a2, 0, c.pc))
        return 0
    def pi_wait(c, *a): return 0            # hardware: PI idle
    return {INFLATE_INIT: inflate_init, INFLATE_RUN: inflate_run,
            INFLATE_FREE: inflate_free, RAW_PI_DMA: raw_pi, PI_WAIT: pi_wait}

def run(rom, stage2, entry, budget=200000):
    mem = build(rom, stage2)
    log, switches = [], []
    hooks = hooks_for(mem, log)
    cpu = Cpu(mem, hooks)
    cpu.status = 0                       # guest decides when interrupts are enabled
    cpu.r[29] = 0x803FF000
    cpu.r[31] = SENTINEL
    cpu.pc = entry
    cpu.delay = None
    n = 0
    while n < budget:
        if cpu.pc == SENTINEL: break
        if cpu.pc in hooks:
            fn = hooks[cpu.pc]
            ret = fn(cpu, cpu.r[4], cpu.r[5], cpu.r[6], cpu.r[7])
            cpu.r[2] = (ret or 0) & 0xFFFFFFFF
            cpu.pc = cpu.r[31]; n += 1
            continue
        before = mem.read(CURRENT, 4)
        try:
            cpu.count = (cpu.count + 1) & 0xFFFFFFFF
            cur, after = cpu.pc, cpu.delay
            cpu.delay = None
            cpu.step(cur)
            if cpu.jump_now is not None:
                cpu.pc, cpu.jump_now = cpu.jump_now, None
            else:
                cpu.pc = after if after is not None else cur + 4
        except Fault as e:
            return {"entry": entry, "instructions": n, "fault": str(e),
                    "pc": cpu.pc, "switches": switches, "log": log, "mem": mem, "cpu": cpu}
        n += 1
        now = mem.read(CURRENT, 4)
        if now != before:
            switches.append((n, cpu.pc, before, now))
    return {"entry": entry, "instructions": n, "fault": None, "pc": cpu.pc,
            "switches": switches, "log": log, "mem": mem, "cpu": cpu}

def report(label, r):
    print(f"\n=== {label} (entry {r['entry']:#x}) ===")
    print(f"  {r['instructions']:,} instructions; stopped pc={r['pc']:#010x}"
          + (f"; FAULT {r['fault']}" if r["fault"] else " (budget or return)"))
    print(f"  guest context switches (writes to 0x80012950 by guest code): {len(r['switches'])}")
    for step, pc, a, b in r["switches"][:8]:
        print(f"    step {step:>7}  at pc {pc:#010x}  {a:#010x} -> {b:#010x}")
    print(f"  host primitives used: {[(k, hex(v[0]) if len(v)>1 else '') for k,*v in [(e[0], e[1] if len(e)>1 else 0) for e in r['log'][:5]]]}")
    print(f"  current thread now: {r['mem'].read(CURRENT,4):#010x}")

def main():
    rom = open("rom/Resident Evil 2 (USA) (Rev 1).z64", "rb").read()
    stage2 = open("assets/unpacked/00000_0014420_1172240.bin", "rb").read()
    for label, entry in (("boot loader FUN_80000598", 0x80000598),
                         ("stage-2 entry FUN_8004D344", 0x8004D344)):
        report(label, run(rom, stage2, entry, budget=200000))

if __name__ == "__main__":
    main()
