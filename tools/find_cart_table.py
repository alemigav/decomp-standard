#!/usr/bin/env python3
"""Find cart descriptor records: 16-byte tuples (offset|0xB0000000, size, vram, vram_end).

Format recovered from FUN_80001180 (vram 0x80012150), see notes/M8-file-table-found.md.
The 0xB top nibble is a flag, not part of the offset; the real offset is `& 0x0FFFFFFF`.
"""
import argparse, struct, sys

ROM_VA_BASE = 0x80000480     # vram of rom_offset 0x1000
ROM_OFF_BASE = 0x1000

def to_vram(off): return ROM_VA_BASE + (off - ROM_OFF_BASE)
def to_off(vram): return ROM_OFF_BASE + (vram - ROM_VA_BASE)

def is_record(d, o):
    if o + 16 > len(d): return False
    f0, f1, f2, f3 = struct.unpack(">4I", d[o:o+16])
    return ((f0 >> 28) == 0xB and f1 < 0x2000000
            and 0x80000000 <= f2 < 0x80400000
            and 0x80000000 <= f3 <= 0x80400000 and f3 >= f2
            and (f0 & 0x0FFFFFFF) < len(d))

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("rom")
    ap.add_argument("--start", type=lambda s: int(s, 0), default=None,
                    help="ROM offset of the table (default: whole-ROM sweep)")
    ap.add_argument("--stride", type=int, default=4)
    a = ap.parse_args()
    d = open(a.rom, "rb").read()

    if a.start is not None:
        i, bad = 0, 0
        while bad < 8:
            if is_record(d, a.start + i*16): bad = 0
            else: bad += 1
            i += 1
        n = i - bad
        recs = [(a.start + k*16, struct.unpack(">4I", d[a.start+k*16:a.start+k*16+16]))
                for k in range(n) if is_record(d, a.start + k*16)]
        size = sum(r[1][1] for r in recs)
        print(f"table at ROM {a.start:#07x} (vram {to_vram(a.start):#010x}): {len(recs)} records, "
              f"{size:,} B payload ({size/1048576:.2f} MB)")
        for off, r in recs[:10]:
            print(f"  rom {off:#07x}  cart {r[0] & 0x0FFFFFFF:#09x} size {r[1]:>9,} "
                  f"-> vram {r[2]:#010x}..{r[3]:#010x}")
        return

    hits = [o for o in range(0, len(d) - 16, a.stride) if is_record(d, o)]
    print(f"{len(hits)} record-shaped words at stride {a.stride}")
    runs = []
    for o in hits:
        if runs and o - runs[-1][1] == 16: runs[-1][1] = o; runs[-1][2] += 1
        else: runs.append([o, o, 1])
    for s, e, n in sorted(runs, key=lambda r: -r[2])[:15]:
        print(f"  ROM {s:#07x}..{e:#07x} (vram {to_vram(s):#010x})  {n} consecutive records")

if __name__ == "__main__":
    main()
