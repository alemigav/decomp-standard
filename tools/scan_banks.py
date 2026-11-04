#!/usr/bin/env python3
"""Cheap structural discovery on an N64 ROM — no disassembly, no Ghidra.

Two scans, both byte-level:

1. CODE DENSITY — count the fingerprints of compiled MIPS per block. Real code is
   dense in `jr ra` (03e00008) and `addiu sp,sp,-N` (27bdffxx); data and video are not.
2. POINTER TABLES — maximal runs of big-endian words in 0x80000000..0x80400000.
   A bank/load table looks exactly like this in N64 ROMs, and finding it converts
   "N MB of unknown" into segments with known VRAM bases.

Usage: ./scan_banks.py <rom.z64> [--block 4096] [--min-run 8]
"""
import argparse
import array
import sys

JR_RA = b"\x03\xe0\x00\x08"
ADDIU_SP = b"\x27\xbd"          # addiu sp, sp, -N  (high halfword)
VRAM_LO, VRAM_HI = 0x80000000, 0x80400000


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("rom")
    ap.add_argument("--block", type=int, default=4096)
    ap.add_argument("--min-run", type=int, default=8)
    ap.add_argument("--top", type=int, default=12)
    a = ap.parse_args()

    data = open(a.rom, "rb").read()
    size = len(data)

    # ---- pointers: interpret the whole ROM as big-endian u32 -----------------
    words = array.array("I")
    words.frombytes(data[: size & ~3])
    if sys.byteorder == "little":
        words.byteswap()

    runs = []
    i, n = 0, len(words)
    while i < n:
        w = words[i]
        if VRAM_LO <= w < VRAM_HI:
            j = i
            while j < n and VRAM_LO <= words[j] < VRAM_HI:
                j += 1
            if j - i >= a.min_run:
                runs.append((i * 4, j - i, min(words[i:j]), max(words[i:j])))
            i = j
        else:
            i += 1

    # ---- code density --------------------------------------------------------
    blocks = []
    for off in range(0, size, a.block):
        chunk = data[off: off + a.block]
        jr = chunk.count(JR_RA)
        sp = chunk.count(ADDIU_SP)
        score = jr * 4 + sp
        if score:
            blocks.append((score, jr, sp, off))
    blocks.sort(reverse=True)

    print(f"rom: {a.rom}  {size} bytes ({size*8//1024//1024} Mbit)")
    print()
    print(f"pointer runs >= {a.min_run} words in 0x80000000..0x80400000: {len(runs)}")
    print(f"{'rom_off':>10} {'count':>6} {'vram_lo':>10} {'vram_hi':>10}   (candidate load tables)")
    for off, cnt, lo, hi in sorted(runs, key=lambda r: -r[1])[: a.top]:
        print(f"0x{off:08X} {cnt:6d} 0x{lo:08X} 0x{hi:08X}")
    print()
    print(f"code density, top blocks of {a.block} B (score = 4*jr_ra + addiu_sp)")
    print(f"{'rom_off':>10} {'score':>7} {'jr_ra':>6} {'addiu_sp':>9}   (candidate code)")
    for score, jr, sp, off in blocks[: a.top]:
        print(f"0x{off:08X} {score:7d} {jr:6d} {sp:9d}")


if __name__ == "__main__":
    main()
