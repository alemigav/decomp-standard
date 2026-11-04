#!/usr/bin/env python3
"""Diff the harness's emulated RDRAM against an ares RDRAM dump, page by page.

Why memory instead of instructions: the instruction-level differential (Unicorn) could not
run past 158 instructions, and ares' release build has no CPU debugger. But `Tools -> Memory
Editor -> Export` in ares writes an 8 MB RDRAM image on demand, which is ground truth for the
whole machine. Comparing memory tests CPU, scheduler, memory map and loaders *together* and
reports the first divergent page rather than the first divergent instruction.

Pages are classified, because a raw count is misleading:

  same         identical
  harness-zero the harness never loaded this page (unexplored, not a bug)
  ares-zero    the harness wrote something the real machine never did  <- interesting
  both-differ  both hold data and it disagrees                          <- interesting

The first two classes are expected in bulk: the harness only loads the boot bank and the
stage-2 image, while ares has run the whole game. Only the last two are evidence.
"""
import argparse, glob, os, struct, sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__)))
from mips_harness import Cpu, RAM_BASE, RAM_SIZE, SENTINEL

PAGE = 0x1000

def load_ares(path, size=RAM_SIZE):
    d = open(path, "rb").read()
    return d[:size] if len(d) >= size else d + b"\0" * (size - len(d))

def harness_ram(entry, steps):
    """Run the harness from `entry` for `steps` instructions and return its RAM."""
    import run_guest_sched as P
    rom = open("rom/Resident Evil 2 (USA) (Rev 1).z64", "rb").read()
    s2 = open("assets/unpacked/00000_0014420_1172240.bin", "rb").read()
    # The correct initial image now includes IPL3's stub plus its boot variables, since
    # the installer and the 4/8 MB layout decision live there (see M75/M76).
    mem = P.build(rom, s2, with_ipl3=True)
    log = []
    hooks = P.hooks_for(mem, log)
    cpu = Cpu(mem, hooks); cpu.r[29] = 0x803FF000; cpu.r[31] = SENTINEL
    cpu.pc = entry; cpu.delay = None
    n = 0
    while n < steps:
        if cpu.pc == SENTINEL: break
        if cpu.pc in hooks:
            r = hooks[cpu.pc](cpu, *cpu.r[4:8]); cpu.r[2] = (r or 0) & 0xFFFFFFFF
            cpu.pc = cpu.r[31]; n += 1; continue
        cur, after = cpu.pc, cpu.delay; cpu.delay = None
        try:
            cpu.step(cur)
        except Exception:
            break
        cpu.pc = cpu.jump_now if cpu.jump_now is not None else (after if after is not None else cur + 4)
        cpu.jump_now = None
        n += 1
    return bytes(mem.ram), n

def classify(harness, ares, off):
    h = harness[off:off+PAGE]; a = ares[off:off+PAGE]
    if h == a: return "same", 0
    n = sum(1 for x, y in zip(h, a) if x != y)
    if not any(h): return "harness-zero", n
    if not any(a): return "ares-zero", n
    return "both-differ", n

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--ares", help="ares RDRAM dump (8 MB), or omit to use the newest in rom/")
    ap.add_argument("--harness-file", help="pre-dumped harness RAM instead of running it")
    ap.add_argument("--entry", type=lambda s: int(s, 0), default=0x80000520,
                    help="default 0x80000520 = main, which installs the vectors")
    ap.add_argument("--steps", type=int, default=150000)
    ap.add_argument("--top", type=int, default=8)
    ap.add_argument("--page", type=lambda s: int(s, 0),
                    help="inspect one page in detail (virtual address)")
    a = ap.parse_args()

    ares_path = a.ares or sorted(glob.glob("rom/*rdram*.bin"), key=os.path.getmtime)[-1]
    ares = load_ares(ares_path)
    raw = os.path.getsize(ares_path)
    print(f"ares dump : {os.path.basename(ares_path)}  ({raw:,} B on disk, {len(ares):,} compared)")

    if a.harness_file:
        harness = load_ares(a.harness_file); steps = -1
        print(f"harness   : {a.harness_file}")
    else:
        harness, steps = harness_ram(a.entry, a.steps)
        print(f"harness   : ran {steps:,} instructions from {a.entry:#x}")

    if a.page is not None:
        off = a.page - RAM_BASE
        kind, n = classify(harness, ares, off)
        print(f"\npage {a.page:#010x}: {kind}, {n} byte(s) differ")
        for i in range(0, PAGE, 16):
            h = harness[off+i:off+i+16]; r = ares[off+i:off+i+16]
            if h != r:
                print(f"  +{i:#05x}  harness {h.hex(' ')}")
                print(f"           ares    {r.hex(' ')}")
        return

    counts = {}
    pages = []
    for off in range(0, RAM_SIZE, PAGE):
        kind, n = classify(harness, ares, off)
        counts[kind] = counts.get(kind, 0) + 1
        if kind != "same":
            pages.append((kind, off, n))

    total = RAM_SIZE // PAGE
    print(f"\npages compared {total} "
          f"(0x80000000-0x80{RAM_SIZE-1:06x})")
    for k in ("same", "harness-zero", "ares-zero", "both-differ"):
        print(f"  {k:13s} {counts.get(k,0):>5}")

    for label in ("both-differ", "ares-zero"):
        sel = [(o, n) for k, o, n in pages if k == label]
        if not sel: continue
        print(f"\n--- {label}: {len(sel)} page(s), top {a.top} by bytes differing ---")
        for off, n in sorted(sel, key=lambda t: -t[1])[:a.top]:
            va = RAM_BASE + off
            first = next(i for i in range(PAGE)
                         if harness[off+i] != ares[off+i])
            hb = harness[off+first:off+first+16]
            ab = ares[off+first:off+first+16]
            print(f"  page {va:#010x}  {n:>4} bytes differ  first diff @+{first:#05x}")
            print(f"      harness {hb.hex(' ')}")
            print(f"      ares    {ab.hex(' ')}")

    if pages:
        kinds = {k for k, _, _ in pages}
        first = min(o for k, o, n in pages if k in ("both-differ", "ares-zero"))
        print(f"\nfirst evidence page: {RAM_BASE+first:#010x}")

if __name__ == "__main__":
    main()
