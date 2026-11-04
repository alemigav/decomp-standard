#!/usr/bin/env python3
"""Parse the cartridge's self-describing load table and validate every record.

The table sits at vram 0x80012150 (ROM 0x12cd0) and *names itself*: the 16 bytes
there are ASCII `OVERLAYTABLENUM` followed by one count byte (0x43 = 67). This is
found by searching for the marker, not by trusting a hardcoded address, so the
tool fails loudly if the cartridge in `rom/` is not the expected dump.

Record layout (verified against FUN_80001180, which computes `index*0x10 + base`):

    +0   cart pointer 0xB0xxxxxx  (KSEG1 window; physical offset is & 0x0FFFFFFF)
    +4   stored (compressed) size
    +8   destination vram start
    +12  destination vram end

A record is emitted only when four independent constraints hold at once, because
any one of them alone is satisfied by one sixteenth of all random words:

    1. pointer in 0xB0000000-0xB3FFFFFF
    2. stored size inside the cartridge
    3. vram_end >= vram_start, both in RDRAM
    4. decompressed size equals the unpacked member's size, when one exists

Measured 2026-10-31: 67 declared, 66 valid, one unused slot at vram 0x80012580
whose size field is 0xCDCDCDCD — the only occurrence of that word in the 64 MB
cartridge. Records target only four destinations, so this is a fixed load list
into staging banks, not a per-room overlay selector.

Usage:
  ./read_overlay_table.py rom/re2.z64 --out manifests/overlay_table.json
"""
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path

VRAM_BASE = 0x7FFFF480          # vram = rom_offset + VRAM_BASE
MARKER = b"OVERLAYTABLENUM"     # 15 bytes; the 16th byte of the header is the count
HEADER = 16
CART_LO, CART_HI = 0xB0000000, 0xB4000000
RAM_LO, RAM_HI = 0x80000000, 0x80400000


def vram(rom_off: int) -> int:
    return rom_off + VRAM_BASE


def find_table(d: bytes) -> int:
    off = d.find(MARKER)
    if off < 0:
        sys.exit("marker OVERLAYTABLENUM not found — wrong cartridge?")
    if off % 16:
        sys.exit(f"marker at ROM {off:#x} is not 16-byte aligned — not the table header")
    return off


def unpacked_sizes(unpacked: Path) -> dict:
    """rom offset -> (decompressed size, filename), from the names unpack_zlib.py writes."""
    sizes = {}
    if not unpacked.is_dir():
        return sizes
    for p in unpacked.iterdir():
        parts = p.stem.split("_")
        if len(parts) == 3:
            sizes[int(parts[1], 16)] = (int(parts[2]), p.name)
    return sizes


def check(rec: tuple, rom_len: int, sizes: dict) -> list:
    ptr, stored, vs, ve = rec
    why = []
    if not (CART_LO <= ptr < CART_HI):
        why.append(f"pointer {ptr:#010x} outside the cart window")
    cart = ptr & 0x0FFFFFFF
    if cart + stored > rom_len:
        why.append(f"stored {stored} runs past the end of the cartridge")
    if not (RAM_LO <= vs <= RAM_HI and RAM_LO <= ve <= RAM_HI):
        why.append(f"destination {vs:#010x}..{ve:#010x} outside RDRAM")
    elif ve < vs:
        why.append(f"vram_end {ve:#010x} below vram_start {vs:#010x}")
    if stored and cart in sizes and sizes[cart][0] != ve - vs:
        why.append(f"decompressed {ve - vs} != unpacked member size {sizes[cart][0]}")
    return why


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("rom")
    ap.add_argument("--unpacked", default="assets/unpacked")
    ap.add_argument("--out", default="manifests/overlay_table.json")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args()

    d = Path(a.rom).read_bytes()
    before = hashlib.sha256(d).hexdigest()
    table = find_table(d)
    declared = d[table + HEADER - 1]
    sizes = unpacked_sizes(Path(a.unpacked))

    records, rejected = [], []
    for i in range(declared):
        off = table + HEADER + i * HEADER
        rec = struct.unpack(">4I", d[off:off + HEADER])
        why = check(rec, len(d), sizes)
        if why:
            rejected.append({"slot": i, "rom": hex(off), "vram": hex(vram(off)),
                             "fields": [hex(x) for x in rec], "why": why})
        else:
            records.append({"slot": i, "rom": off, "vram": vram(off),
                            "cart": rec[0] & 0x0FFFFFFF, "stored": rec[1],
                            "vram_start": rec[2], "vram_end": rec[3],
                            "decompressed": rec[3] - rec[2],
                            "unpacked_member": (sizes.get(rec[0] & 0x0FFFFFFF) or (0, None))[1]})

    dests = {}
    for r in records:
        dests.setdefault(r["vram_start"], []).append(r)
    groups = []
    for base, rs in sorted(dests.items()):
        groups.append({"vram_start": base, "records": len(rs),
                       "slots": [r["slot"] for r in rs],
                       "decompressed": [r["decompressed"] for r in rs]})

    after = hashlib.sha256(Path(a.rom).read_bytes()).hexdigest()
    doc = {
        "tool": "read_overlay_table.py",
        "cart_sha256": before,
        "cart_unchanged": before == after,
        "header": {"rom": table, "vram": vram(table),
                   "marker": MARKER.decode(), "declared_count": declared},
        "valid": len(records), "rejected": rejected,
        "destinations": groups, "records": records,
    }
    Path(a.out).write_text(json.dumps(doc, indent=1) + "\n")

    if not a.quiet:
        print(f"cart sha256 {before}  {'UNCHANGED' if before == after else 'CHANGED — INVESTIGATE'}")
        print(f"table header at ROM {table:#07x} (vram {vram(table):#010x}): "
              f"{MARKER.decode()!r} + count {declared}")
        print(f"{len(records)} valid records, {len(rejected)} rejected")
        for r in rejected:
            print(f"  rejected slot {r['slot']} rom {r['rom']}: {'; '.join(r['why'])}")
        print(f"\n{'slot':>4}  {'cart':>9} {'stored':>8} {'decompressed':>12}  {'destination':>10}")
        for r in records:
            print(f"{r['slot']:4d}  {r['cart']:#09x} {r['stored']:8d} {r['decompressed']:12d}  "
                  f"{r['vram_start']:#010x}")
        print(f"\npayload {sum(r['stored'] for r in records):,} B stored, "
              f"{sum(r['decompressed'] for r in records):,} B decompressed")
        print(f"destinations: {len(groups)} distinct")
        for g in groups:
            print(f"  {g['vram_start']:#010x}  {g['records']:3d} records  slots {g['slots'][:6]}"
                  f"{'…' if g['records'] > 6 else ''}")
    print(f"wrote {a.out}")


if __name__ == "__main__":
    main()
