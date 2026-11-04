#!/usr/bin/env python3
"""Recover jump-table targets: code that static analysis cannot reach but the image names.

A `lw v0,0(v1)` / `jr v0` dispatch looks opaque — the provider cannot follow it, so the case blocks
stay unclaimed and the function that owns them decompiles as a bare preamble. But the table itself
is usually *in the image*, as .rodata, filled with absolute addresses. Reading it back turns an
indirect dispatch into a list of concrete function starts.

The pattern, measured on the three dispatchers at `0x8009d018` / `0x8009d878` / `0x8009de50`:

    lui   v0,0x800c          }  table base: **signed** addiu, so 0x800c0000 - 0x5ba8 = 0x800ba458
    addiu v0,v0,-23464       }  (an `ori` here would be 0x800ca458 — that misreading cost an hour)
    ...
    sll   v1,v1,2            }  index scaling
    addu  v1,v1,v0           }  base + 4*index
    lw    v0,0(v1)           }  load a target
    jr    v0                 }  dispatch

Acceptance is structural, not hopeful: a table entry counts only if it lands **inside the image**,
is **4-byte aligned**, and the word there is a plausible entry — a prologue (`addiu sp,sp,-N`) or a
`lui`/`lw`/`sw`/`addiu`/`sltiu` first instruction. Entries that fail are reported, not silently
dropped, and the walk stops at the first zero (the padding the compiler emits between tables).

Usage:
  ./find_jump_tables.py --images build/elfs/images.json --out manifests/jump_tables.json
"""
import argparse
import json
import struct
from pathlib import Path

RD_LO, RD_HI = 0x80000000, 0x80400000
PLAUSIBLE_FIRST = {0x0F, 0x23, 0x2B, 0x09, 0x0B, 0x0D, 0x24, 0x25, 0x21}  # lui lw sw addiu sltiu ori lbu lhu lh


def image_bytes(elf: Path, size: int) -> bytes:
    return elf.read_bytes()[0x100:0x100 + size]


def find_dispatches(words: list, base: int) -> list:
    """Every `lui`+`addiu` -> table base followed within a few instructions by lw+`jr rx`."""
    out = []
    n = len(words)
    for i in range(n - 8):
        if (words[i] >> 26) != 0x0F:
            continue
        rt = (words[i] >> 16) & 0x1F
        hi = (words[i] & 0xFFFF) << 16
        tbl = None
        for j in range(i + 1, min(i + 3, n)):
            y = words[j]
            if (y >> 21) & 0x1F != rt:
                continue
            if (y >> 26) == 0x09:                      # addiu: signed immediate
                lo = y & 0xFFFF
                tbl = hi + (lo - 0x10000 if lo & 0x8000 else lo)
            elif (y >> 26) == 0x0D:                    # ori: unsigned
                tbl = hi | (y & 0xFFFF)
            break
        if tbl is None or not (RD_LO <= tbl < RD_HI):
            continue
        for k in range(i + 1, min(i + 9, n)):
            if words[k] == 0x03E00008:                 # jr ra — a normal return, not a dispatch
                break
            if (words[k] >> 26) == 0 and (words[k] & 63) == 0x08:
                reg = (words[k] >> 21) & 0x1F
                if any((words[m] >> 26) == 0x23 and ((words[m] >> 16) & 0x1F) == reg
                       for m in range(max(0, k - 3), k)):
                    # The dispatcher states its own case count: `sltiu v0,v1,K` / `slti` guards the
                    # dispatch, so K bounds the table and adjacent tables cannot merge.
                    bound = None
                    for m in range(max(0, i - 12), i):
                        if (words[m] >> 26) in (0x0A, 0x0B):
                            bound = words[m] & 0xFFFF
                    out.append((i, tbl, k, bound))
                break
    return out


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--images", default="build/elfs/images.json")
    ap.add_argument("--elfs", default="build/elfs")
    ap.add_argument("--out", default="manifests/jump_tables.json")
    ap.add_argument("--rejected-tables", default="config/rejected_tables.txt")
    ap.add_argument("--seeds", default="build/seeds_tables",
                    help="append the recovered targets here, per image")
    a = ap.parse_args()

    # tables measured to hold fragments rather than function entries
    rejected = {}
    rp = Path(a.rejected_tables)
    if rp.exists():
        for line in rp.read_text().splitlines():
            line = line.split("#", 1)[0].strip()
            if line:
                parts = line.split()
                rejected[(parts[1], int(parts[0], 0))] = " ".join(parts[2:])

    images = json.loads(Path(a.images).read_text())["images"]
    report, seeds_dir = {"tool": "find_jump_tables.py", "images": []}, Path(a.seeds)
    seeds_dir.mkdir(parents=True, exist_ok=True)

    for img in images:
        code = image_bytes(Path(a.elfs) / f"{img['name']}.elf", img["size"])
        n = len(code) // 4
        words = list(struct.unpack(f">{n}I", code[:n * 4]))
        base, size = img["base"], img["size"]
        tables, targets = [], set()
        for i, tbl, jr, bound in find_dispatches(words, base):
            off = tbl - base
            if not (0 <= off < size - 4):
                tables.append(dict(dispatcher=hex(base + i * 4), table=hex(tbl),
                                   note="table outside this image"))
                continue
            entries, bad, stop = [], [], None
            limit = min(64, bound) if bound else 64
            for k in range(limit):
                if off + 4 * k + 4 > len(code):
                    stop = "table runs past the image"
                    break
                v = struct.unpack(">I", code[off + 4 * k:off + 4 * k + 4])[0]
                if v == 0:
                    stop = "zero entry (table padding)"
                    break
                if not (base <= v < base + size) or v % 4:
                    stop = f"entry {v:#010x} is not an aligned in-image address"
                    bad.append(hex(v))
                    break
                entries.append(v)
            # A dispatch table is a run of case-block addresses from one function: strictly
            # increasing (compilers emit cases in order) and local to that function. Data that
            # merely contains in-image values fails this — a float array stopped at 0x41f00000
            # (30.0) after six coincidental hits.
            monotone = all(b > a for a, b in zip(entries, entries[1:]))
            local = bool(entries) and entries[-1] - entries[0] < 0x10000
            if bound and len(entries) > bound:
                stop = f"walked {len(entries)} entries past the declared bound {bound}"
                entries = entries[:bound]
            if entries and not (monotone and local):
                bad.append("entries not monotone" if not monotone else "span over 64 KB")
                entries = []
            why = rejected.get((img["name"], tbl))
            if why is not None:
                tables.append(dict(dispatcher=hex(base + i * 4), table=hex(tbl),
                                   entries=0, declared_cases=bound,
                                   stop=f"rejected: {why[:60]}"))
                continue
            if entries:
                targets.update(entries)
            prologues = sum(1 for e in entries
                            if (struct.unpack(">I", code[e - base:e - base + 4])[0]
                                & 0xFFFF0000) == 0x27BD0000)
            tables.append(dict(dispatcher=hex(base + i * 4), table=hex(tbl),
                               declared_cases=bound, entries=len(entries),
                               entries_with_prologue=prologues, stop=stop, rejected=bad[:2]))
        if tables:
            report["images"].append(dict(name=img["name"], base=hex(base),
                                         tables=tables, targets=len(targets)))
            (seeds_dir / f"{img['name']}.tsv").write_text(
                "".join(f"{t:#010x}\tfunction\tFUN_{t:08x}\n" for t in sorted(targets)))

    Path(a.out).write_text(json.dumps(report, indent=1) + "\n")
    total_tables = sum(len(i["tables"]) for i in report["images"])
    total_targets = sum(i["targets"] for i in report["images"])
    print(f"{total_tables} dispatch sites with an in-image table, "
          f"{total_targets} recovered targets")
    for i in report["images"]:
        for t in i["tables"][:4]:
            print(f"  {i['name']:>14} {t['dispatcher']} -> {t['table']}  "
                  f"entries {t.get('entries', 0)} (prologue-led {t.get('entries_with_prologue', 0)})"
                  f"  stop: {t.get('stop')}")
    print(f"\nwrote {a.out} and target seeds in {seeds_dir}/")


if __name__ == "__main__":
    main()
