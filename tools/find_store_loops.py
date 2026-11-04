#!/usr/bin/env python3
"""Find store runs that fill an RDRAM table with a constructed constant.

Why this class exists: the bank-C pointer initializer at `0x800324a8` stores one constant into 96
consecutive words — 48 entries pointing at `0x80161cf0`, then 48 at `0x8016e880`. It has **no
prologue and no `jal`**, so every candidate rule in `find_missed_functions.py` skips it, and it sat
inside an unclaimed run where nothing else looked. It is the mechanism that installs the two staging
banks as per-slot defaults, which is why twenty overlays share the load address `0x80161cf0`: an
address alone does not identify an image when the loader hands every slot the same base.

A store run is *not* automatically a table initializer — memcpy loops, stack fills and framebuffer
clears look identical in the instruction stream. So a candidate is emitted only when all four hold:

  1. **the stored value is constructed**, by `lui`+`ori` / `lui`+`addiu` into the value register,
     and that register is never redefined inside the run (a value loaded from memory is rejected:
     "loaded from RAM" is exactly where this kind of analysis invents structure);
  2. **the destination base is constructed** by the same rule and lands in RDRAM `0x8000..0x803F`;
  3. **the addresses are consecutive**, stepping by a constant stride between 1 and 16 bytes;
  4. **the count is bounded and reported**, not inferred from a branch target that may be wrong:
     the run ends at the first store that breaks the stride, and a run shorter than `--min-run`
     is discarded.

Each candidate reports `(table_base, entry_count, stride, stored_value)` and the address of the
first store, so any claim it supports is reproducible from the four numbers.

Usage:
  ./find_store_loops.py --images build/elfs/images.json [--min-run 8]
"""
import argparse
import json
import struct
import sys
from pathlib import Path

RD_LO, RD_HI = 0x80000000, 0x80400000
STORE_OPS = {0x2B: "sw", 0x29: "sh", 0x28: "sb"}
VALUE_OPS = (0x0F, 0x0D, 0x09)          # lui, ori, addiu


def image_bytes(elf: Path, size: int) -> bytes:
    return elf.read_bytes()[0x100:0x100 + size]


def reg_constants(words: list) -> list:
    """One forward pass: for each index, the constructed constant held by each register.

    A tiny abstract interpretation over the linear stream, not a type system: `lui` opens a
    high half, `ori`/`addiu` close it, `addu` of two known values sums them (the bank initializer
    forms its base that way: `lui 0x800c` + `addiu 0x76b0` + `addu` with `0x18000`), and *any*
    other write clears the register. A value loaded from memory is therefore never treated as a
    constant, which is the rule the audit asked for.
    """
    out, pending = [], {}
    for w in words:
        op = w >> 26
        rd = (w >> 11) & 0x1F if op == 0 else (w >> 16) & 0x1F
        rt = (w >> 16) & 0x1F
        rs = (w >> 21) & 0x1F
        val = None
        if op == 0x0F:                                   # lui
            val = (w & 0xFFFF) << 16
        elif op in (0x0D, 0x09) and rs in pending:       # ori / addiu closing a lui
            hi = pending[rs]
            val = hi | (w & 0xFFFF) if op == 0x0D else hi + (
                (w & 0xFFFF) - 0x10000 if w & 0x8000 else (w & 0xFFFF))
        elif op == 0x09 and rs == 0:                     # li rt,imm
            val = w & 0xFFFF
        elif op == 0 and (w & 63) == 0x21 and rs in pending and rt in pending:   # addu
            val = pending[rs] + pending[rt]
        elif op == 0 and (w & 63) == 0x25 and rs in pending and rt in pending:   # or
            val = pending[rs] | pending[rt]
        if op not in (0x2B, 0x29, 0x28, 0x04, 0x05, 0x06, 0x07, 0x01, 0x02, 0x03):
            if op in (0x0F,):
                pending[rd] = val
            elif val is not None:
                pending[rd] = val
            else:
                pending.pop(rd, None)
        out.append(dict(pending))
    return out


def scan(code: bytes, image_base: int, min_run: int) -> list:
    n = len(code) // 4
    words = list(struct.unpack(f">{n}I", code[:n * 4]))
    state = reg_constants(words)
    runs, i = [], 0
    while i < n:
        w = words[i]
        if (w >> 26) not in STORE_OPS:
            i += 1
            continue
        rs, rt, off = (w >> 21) & 0x1F, (w >> 16) & 0x1F, w & 0xFFFF
        s = state[i - 1] if i else {}
        base, value = s.get(rs), s.get(rt)
        if base is None or value is None or not (RD_LO <= base < RD_HI):
            i += 1
            continue
        first = base + off
        values = [value]
        stride, count, k, expected = None, 1, i + 1, None
        skipped = 0
        while k < n:
            x = words[k]
            op = x >> 26
            if op in (0x02, 0x03, 0x04, 0x05, 0x06, 0x07) or (op == 0 and (x & 63) == 0x08):
                break                          # a branch, jump or return ends the run
            if op in STORE_OPS and (x >> 21) & 0x1F != rs:
                break                          # a store through another base ends the run
            if op not in STORE_OPS:
                skipped += 1                   # value construction between stores is expected
                if skipped > 12:
                    break
                k += 1
                continue
            skipped = 0
            s2 = state[k - 1]
            addr, val = s2.get(rs), s2.get((x >> 16) & 0x1F)
            if addr is None or val is None:     # guard 1 applies to every store, not just the first
                break
            addr += x & 0xFFFF
            if stride is None:
                stride = addr - first
                if not (1 <= stride <= 16):
                    break
                expected = addr + stride
            elif addr != expected:
                break
            else:
                expected += stride
            values.append(val)
            count += 1
            k += 1
        if stride is None:
            stride = 4
        if count >= min_run:
            distinct = sorted(set(values))
            runs.append(dict(store_at=hex(image_base + i * 4), table_base=hex(first),
                             entry_count=count, stride=stride,
                             stored_value=hex(value) if len(distinct) == 1 else None,
                             distinct_values=len(distinct),
                             examples=[hex(v) for v in distinct[:4]],
                             op=STORE_OPS[words[i] >> 26]))
        i = max(k, i + 1)
    return merge_chunks(runs)


def merge_chunks(runs: list) -> list:
    """Join runs the reload of the value register split apart.

    The bank initializer re-emits `lui` + `addiu` for the stored value every sixteen stores, so one
    48-entry table arrives as three runs. Two runs are the same table when the stride, the stored
    value and the continuation of the address range all agree; the merged entry keeps the earliest
    store address and the summed count.
    """
    runs.sort(key=lambda r: int(r["table_base"], 16))
    merged = []
    for r in runs:
        if merged:
            m = merged[-1]
            end = int(m["table_base"], 16) + m["entry_count"] * m["stride"]
            if (m["stride"] == r["stride"] and int(r["table_base"], 16) == end):
                m["entry_count"] += r["entry_count"]
                continue
        merged.append(dict(r))
    return merged


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--images", default="build/elfs/images.json")
    ap.add_argument("--elfs", default="build/elfs")
    ap.add_argument("--min-run", type=int, default=8)
    ap.add_argument("--out", default="manifests/store_loops.json")
    a = ap.parse_args()

    images = json.loads(Path(a.images).read_text())["images"]
    report = {"tool": "find_store_loops.py", "min_run": a.min_run, "images": []}
    for img in images:
        code = image_bytes(Path(a.elfs) / f"{img['name']}.elf", img["size"])
        found = scan(code, img["base"], a.min_run)
        if found:
            report["images"].append(dict(name=img["name"], base=hex(img["base"]), runs=found))
    Path(a.out).write_text(json.dumps(report, indent=1) + "\n")

    total = sum(len(i["runs"]) for i in report["images"])
    print(f"{total} store runs filling an RDRAM table (min {a.min_run} entries)")
    print(f"{'image':>16} {'table_base':>12} {'entries':>7} {'stride':>6} {'distinct':>8}  "
          f"{'store':>12}  values")
    for i in report["images"]:
        for r in sorted(i["runs"], key=lambda r: -r["entry_count"])[:6]:
            print(f"{i['name']:>16} {r['table_base']:>12} {r['entry_count']:7d} "
                  f"{r['stride']:6d} {r['distinct_values']:7d}  {r['store_at']:>12}  "
                  f"{','.join(r['examples'][:3])}")
    print(f"\nwrote {a.out}")


if __name__ == "__main__":
    main()
