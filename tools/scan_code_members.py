#!/usr/bin/env python3
"""Census the decompressed members for MIPS code, and derive load addresses.

Why this exists: the project's code inventory came from a fixed list — the boot bank plus the
seven payloads the cart's load table names. But the table only explains 7 of 4 761 manifest
members, and a prologue scan shows `addiu sp,sp,-0x20` at offset 0 in more members than the
table explains. So "how much code is in this cartridge" has never been measured; it was
assumed. This tool measures it.

Signals are code-specific, never entropy — compressed data also has high entropy, so entropy
cannot separate code from assets:

    prologue   addiu sp,sp,-N   (0x27BD0000 mask, negative immediate)  frame setup
    frame_save  sw ra,N(sp)     (0xAFBF0000 mask)                      return-address store
    jrra        0x03E00008                                             function return
    jal         opcode 3                                               direct call
    ramcons     lui rt,0x8000-0x803F                                   RDRAM pointer build

Load-address derivation for a member the cart table does not name uses the M7 technique: a
`jal` target is absolute (`(pc & 0xF0000000) | imm26 << 2`), so the targets of one image's
internal calls must all fall inside a window exactly `size` wide. Candidate base = the
window start holding the most targets. `--self-test` runs that derivation on the seven images
whose base *is* known and reports whether it recovers them, so a null on the unknowns is
believable rather than merely disappointing.

Usage:
  ./scan_code_members.py rom/re2.z64 --unpacked assets/unpacked \
       --table manifests/overlay_table.json --out manifests/code_census.json [--self-test]
"""
import argparse
import json
import struct
import sys
from pathlib import Path

MASK32 = 0xFFFFFFFF
T26 = 0x3FFFFFF


def signals(data: bytes) -> dict:
    n = len(data) // 4
    if n == 0:
        return dict(words=0, prologue=0, frame_save=0, jrra=0, jal=0, ramcons=0)
    w = struct.unpack(f">{n}I", data[:n * 4])
    prologue = frame_save = jrra = jal = ramcons = 0
    for x in w:
        if (x & 0xFFFF0000) == 0x27BD0000 and (x & 0x8000):
            prologue += 1
        elif (x & 0xFFFF0000) == 0xAFBF0000:
            frame_save += 1
        elif x == 0x03E00008:
            jrra += 1
        elif (x >> 26) == 0x03:
            jal += 1
        elif (x >> 26) == 0x0F:
            hi = x & 0xFFFF
            if 0x8000 <= hi < 0x8040:
                ramcons += 1
    return dict(words=n, prologue=prologue, frame_save=frame_save, jrra=jrra,
                jal=jal, ramcons=ramcons)


def jal_targets_t26(data: bytes, limit: int = 900) -> list:
    """Low 26 bits of every `jal` target, sampled if the member has many."""
    n = len(data) // 4
    w = struct.unpack(f">{n}I", data[:n * 4])
    t = [(x & T26) << 2 for x in w if (x >> 26) == 0x03]
    if len(t) > limit:
        step = len(t) / limit
        t = [t[int(i * step)] for i in range(limit)]
    return t


def derive_base(data: bytes, size: int) -> tuple:
    """Window of width `size` in 26-bit space holding the most jal targets."""
    t = jal_targets_t26(data)
    if len(t) < 4:
        return None, 0.0
    best, best_n = None, -1
    for start in t:
        n = sum(1 for v in t if (v - start) % (T26 + 1) < size)
        if n > best_n:
            best, best_n = start, n
    return 0x80000000 | (best & T26), best_n / len(t)


def internal_fraction(data: bytes, base: int, size: int) -> float:
    n = len(data) // 4
    w = struct.unpack(f">{n}I", data[:n * 4])
    targets = [((base & 0xF0000000) | ((x & T26) << 2)) for x in w if (x >> 26) == 0x03]
    if not targets:
        return 0.0
    return sum(1 for a in targets if base <= a < base + size) / len(targets)


def classify(s: dict, size: int) -> tuple:
    """Absolute floors plus density, so a tiny member cannot score on one lucky word.

    The floors are `jrra >= 3`, `prologue >= 1`, `jal + jrra >= 6` and both densities — a 464-byte
    payload carries 4 returns and 4 frames, which no data blob does by accident, while an earlier
    flat `jal >= 10` floor wrongly rejected three real code stubs.
    """
    kb = max(size / 1024.0, 1.0)
    score = (s["jal"] + s["jrra"] + s["prologue"]) / kb
    code = (s["jrra"] >= 3 and s["prologue"] >= 1 and s["jal"] + s["jrra"] >= 6
            and s["jrra"] / kb >= 0.3 and s["jal"] / kb >= 0.5)
    return ("code" if code else "not code"), round(score, 2)


def members(unpacked: Path) -> list:
    out = []
    for p in sorted(unpacked.iterdir()):
        parts = p.stem.split("_")
        if len(parts) == 3:
            out.append(dict(path=p, idx=int(parts[0]), rom=int(parts[1], 16),
                            size=int(parts[2])))
    return out


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("rom")
    ap.add_argument("--unpacked", default="assets/unpacked")
    ap.add_argument("--table", default="manifests/overlay_table.json")
    ap.add_argument("--out", default="manifests/code_census.json")
    ap.add_argument("--self-test", action="store_true",
                    help="derive the base of the seven known images and compare")
    ap.add_argument("--top", type=int, default=25)
    a = ap.parse_args()

    rom = Path(a.rom).read_bytes()
    table = json.loads(Path(a.table).read_text())
    known = {}
    for r in table["records"]:
        if r["stored"]:
            known[r["cart"]] = r["vram_start"]
    boot = dict(path=None, idx=-1, rom=0x1000, size=0x11140, base=0x80000480)

    rows, code_rows = [], []
    for m in members(Path(a.unpacked)):
        data = m["path"].read_bytes()
        s = signals(data)
        kind, score = classify(s, m["size"])
        base = known.get(m["rom"])
        row = dict(idx=m["idx"], rom=hex(m["rom"]), size=m["size"], **s, kind=kind,
                   score=score, base=hex(base) if base else None,
                   base_source="cart table" if base else None)
        if base:
            row["internal_calls"] = round(internal_fraction(data, base, m["size"]), 3)
        elif kind == "code":
            dbase, conf = derive_base(data, m["size"])
            if dbase:
                row["base"] = hex(dbase)
                row["base_source"] = "derived"
                row["derive_confidence"] = round(conf, 3)
                row["internal_calls"] = round(internal_fraction(data, dbase, m["size"]), 3)
        rows.append(row)
        if kind == "code":
            code_rows.append(row)

    # positive control: the boot bank is code too
    boot_data = rom[boot["rom"]:boot["rom"] + boot["size"]]
    bs = signals(boot_data)
    bkind, bscore = classify(bs, boot["size"])
    boot_row = dict(idx=-1, rom=hex(boot["rom"]), size=boot["size"], **bs, kind=bkind,
                    score=bscore, base=hex(boot["base"]), base_source="ROM (boot bank)",
                    internal_calls=round(internal_fraction(boot_data, boot["base"],
                                                           boot["size"]), 3))

    self_test = []
    if a.self_test:
        for rom_off, base in sorted(known.items()):
            m = next((r for r in rows if r["rom"] == hex(rom_off)), None)
            if not m:
                continue
            data = Path(a.unpacked).joinpath(
                f"{m['idx']:05d}_{rom_off:07x}_{m['size']}.bin").read_bytes()
            dbase, conf = derive_base(data, m["size"])
            self_test.append(dict(member=m["idx"], rom=hex(rom_off), known=hex(base),
                                  derived=hex(dbase) if dbase else None,
                                  match=dbase == base, confidence=round(conf, 3)))

    doc = dict(tool="scan_code_members.py", cart_sha256=table["cart_sha256"],
               members_scanned=len(rows), boot_bank=boot_row,
               code_members=len(code_rows) + (1 if bkind == "code" else 0),
               self_test=self_test, code=code_rows,
               all=sorted(rows, key=lambda r: -r["score"]))
    Path(a.out).write_text(json.dumps(doc, indent=1) + "\n")

    print(f"scanned {len(rows)} members ({sum(r['size'] for r in rows):,} B decompressed)")
    print(f"boot bank: kind={bkind} score={bscore} "
          f"internal_calls={boot_row['internal_calls']}  <- positive control")
    if self_test:
        print(f"\nbase derivation self-test on the {len(self_test)} cart-table images:")
        for t in self_test:
            print(f"  member {t['member']:5d} rom {t['rom']:>9}  known {t['known']}  "
                  f"derived {t['derived']}  {'MATCH' if t['match'] else 'MISS'}  "
                  f"confidence {t['confidence']}")
    print(f"\n{len(code_rows)} members classified as code:")
    print(f"{'idx':>5} {'rom':>9} {'size':>7} {'jal':>5} {'jrra':>5} {'pro':>4} "
          f"{'score':>6}  {'base':>10} {'src':>10} {'internal':>8}")
    for r in sorted(code_rows, key=lambda r: r["rom"]):
        print(f"{r['idx']:5d} {r['rom']:>9} {r['size']:7d} {r['jal']:5d} {r['jrra']:5d} "
              f"{r['prologue']:4d} {r['score']:6.2f}  {r['base'] or '-':>10} "
              f"{r['base_source'] or '-':>10} {r.get('internal_calls', 0):8.3f}")
    print(f"\nhighest scores among non-code members (threshold sanity):")
    for r in [x for x in doc["all"] if x["kind"] != "code"][:a.top]:
        print(f"  member {r['idx']:5d} rom {r['rom']:>9} size {r['size']:7d} "
              f"jal {r['jal']:4d} jrra {r['jrra']:4d} pro {r['prologue']:3d} score {r['score']}")
    print(f"\nwrote {a.out}")


if __name__ == "__main__":
    sys.exit(main())
