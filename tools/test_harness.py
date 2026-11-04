#!/usr/bin/env python3
"""Regression tests for the instruction the loader question depends on.

Why this exists: `mips_harness.py` was described as a "verified path", but the only fixture it
ever had is `mkmips.py`'s countdown loop, which exercises `addiu`, `addu`, `bnez` and `jr` — not
`signed byte and halfword loads` and not `the unaligned stores`. The four instructions below sit in
the same `step()` dispatch as the verified ones but in separate branches, so "verified path" was
true of the whole and false of the parts. Changing an uncovered branch cannot regress a covered
one; the rule that applies is "do not touch code without a test", so the test comes first.

Ground truth is the architecture, not the harness's current behaviour:

  LB   sign-extends the byte            LBU  zero-extends it
  LH   sign-extends the halfword        LHU  zero-extends it
  SWL  stores rt's most-significant bytes upward from the address
  SWR  stores rt's least-significant bytes downward from the address

With the base word `0xAABBCCDD` and `rt = 0x11223344`, at byte offset k from the word:

  SWL  k=0 0x11223344   k=1 0xAA112233   k=2 0xAABB1122   k=3 0xAABBCC11
  SWR  k=0 0x44BBCCDD   k=1 0x3344CCDD   k=2 0x223344DD   k=3 0x11223344

Usage:
  ./test_harness.py            # 0 = all pass, 1 = failures listed
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import mips_harness as H

RAM_BASE = H.RAM_BASE
CODE = RAM_BASE + 0x1000
DATA = RAM_BASE + 0x2000


def make_cpu():
    """A fresh machine per case: `Cpu.run` rezeros `r`, so fixture state must be set after it."""
    mem = H.Memory(4 * 1024 * 1024, b"\0" * 0x1000)
    return H.Cpu(mem, {}), mem


def run(cpu, mem, word, **args):
    """Execute `word` then `jr ra` through the harness's own run loop.

    `Cpu.step(pc)` does not advance `self.pc` — the caller does, and branches are tracked through
    `self.delay` / `self.jump_now`. So a fixture must go through `Cpu.run()`, which sets `ra` to
    SENTINEL and terminates there, rather than hand-driving `step`.
    """
    mem.write(CODE, 4, word)
    mem.write(CODE + 4, 4, 0x03E00008)          # jr ra
    mem.write(CODE + 8, 4, 0x00000000)          # delay slot
    cpu.run(CODE, a0=DATA, **args)


# (name, instruction word, memory setup (offset, value, size), expected register value)
LOADS = [
    ("LB  0xff",  (0x20 << 26) | (4 << 21) | (5 << 16) | 0x00, (0x00, 0xFF, 1), 0xFFFFFFFF),
    ("LB  0x01",  (0x20 << 26) | (4 << 21) | (5 << 16) | 0x01, (0x01, 0x01, 1), 0x00000001),
    ("LBU 0xff",  (0x24 << 26) | (4 << 21) | (5 << 16) | 0x00, (0x00, 0xFF, 1), 0x000000FF),
    ("LH  0xfffe", (0x21 << 26) | (4 << 21) | (5 << 16) | 0x02, (0x02, 0xFFFE, 2), 0xFFFFFFFE),
    ("LH  0x0001", (0x21 << 26) | (4 << 21) | (5 << 16) | 0x02, (0x02, 0x0001, 2), 0x00000001),
    ("LHU 0xfffe", (0x25 << 26) | (4 << 21) | (5 << 16) | 0x02, (0x02, 0xFFFE, 2), 0x0000FFFE),
]

STORES = [("SWL", 0x2A, [(0x11223344, 0xAA112233)], 0x11223344),
          ("SWR", 0x2E, [], 0x11223344)]

WORD = 0xAABBCCDD
SWL_EXPECT = {0: 0x11223344, 1: 0xAA112233, 2: 0xAABB1122, 3: 0xAABBCC11}
SWR_EXPECT = {0: 0x44BBCCDD, 1: 0x3344CCDD, 2: 0x223344DD, 3: 0x11223344}


def main() -> None:
    failures, passed = [], 0

    for name, word, (off, val, size), expect in LOADS:
        cpu, mem = make_cpu()
        mem.write(DATA + off, size, val)
        try:
            run(cpu, mem, word)
            got = cpu.r[5] & 0xFFFFFFFF
        except Exception as exc:                       # a fault is a failure, not a crash
            failures.append(f"{name}: faulted ({exc})")
            continue
        if got == expect:
            passed += 1
        else:
            failures.append(f"{name}: got {got:#010x}, architecture {expect:#010x}")

    for op, expect_by_k in ((0x2A, SWL_EXPECT), (0x2E, SWR_EXPECT)):
        mnem = "SWL" if op == 0x2A else "SWR"
        for k in range(4):
            cpu, mem = make_cpu()
            mem.write(DATA, 4, WORD)
            try:
                # the value arrives in a1: Cpu.run rezeros r, so it cannot be poked in beforehand
                run(cpu, mem, (op << 26) | (4 << 21) | (5 << 16) | k, a1=0x11223344)
                got = mem.read(DATA, 4)
            except Exception as exc:
                failures.append(f"{mnem} k={k}: faulted ({exc})")
                continue
            expect = expect_by_k[k]
            if got == expect:
                passed += 1
            else:
                failures.append(f"{mnem} k={k}: got {got:#010x}, architecture {expect:#010x}")

    # the pre-existing fixture, so a fix cannot regress the branch it sits beside
    cpu, mem = make_cpu()
    for i, w in enumerate([0x24080005, 0x00001021, 0x00481021, 0x2508FFFF,
                           0x1500FFFD, 0x00000000, 0x03E00008, 0x00000000]):
        mem.write(CODE + 4 * i, 4, w)
    cpu.run(CODE)
    if (cpu.r[2] & 0xFFFFFFFF) == 15:
        passed += 1
    else:
        failures.append(f"countdown loop: v0 = {cpu.r[2] & 0xFFFFFFFF}, architecture 15")

    total = len(LOADS) + 8 + 1
    print(f"{passed}/{total} passed")
    for f in failures:
        print(f"  FAIL {f}")
    sys.exit(1 if failures else 0)


if __name__ == "__main__":
    main()
