#!/usr/bin/env python3
"""Find functions the provider did not split, from the bytes it left unclaimed.

A decompiled corpus reports what it claimed; the interesting part is what it left over. Stage-2
had 243 unclaimed runs, and one of them (0x8009d014) turned out to contain a prologue followed by
a scaled-index `jr v0` dispatch — a real function, reached by an indirect call, which the
provider's call-graph-driven discovery never created.

This tool turns that observation into a repeatable pass. For each image it takes the function
bodies the provider claimed, computes the complement, and looks for *prologue-led code* inside it:

    a candidate is emitted only when
      * the word is `addiu sp,sp,-N` (a frame setup), and
      * it sits inside a run the provider left unclaimed, and
      * that run also carries call/return evidence (>= 3 `jal`, or >= 2 `jr ra`)

The third condition is what separates a missed function from data that happens to contain a
prologue-shaped word: over the whole cartridge, `jal`-shaped data words are common (the census
found members with 510 of them and no returns), but a run with real returns and real calls is code.

Candidates are emitted as *boundaries*, not names: `func_<address>`. A boundary is a claim about
structure and is checkable by re-running the export; a name is a claim about meaning and needs the
evidence rules in config/symbols.tsv.

Usage:
  ./find_missed_functions.py --images build/elfs/images.json --decomp build/decomp \
      --out manifests/missed_functions.json --seeds build/seeds_extra
"""
import argparse
import json
import struct
import sys
from pathlib import Path


def image_bytes(elf: Path, size: int) -> bytes:
    return elf.read_bytes()[0x100:0x100 + size]


def is_prologue(w: int) -> bool:
    return (w & 0xFFFF0000) == 0x27BD0000 and (w & 0x8000) != 0


def entry_before_prologue(words: list, base: int, prologue: int) -> int:
    """An entry whose argument preload was hoisted above the frame setup.

    Measured at 0x8009d020 / 0x8009d880 / 0x8009de58: each prologue is preceded by
    `lui rt,0x8013` + `lhu rt,off(rt)`, loading the dispatch index the prologue is followed by a
    switch on. Seeding the prologue alone produces a function that reads an incoming register and
    Ghidra says so (`undefined4 in_v1`), which is how a mis-placed boundary announces itself. When
    the two words before the prologue are a lui + load pair into RDRAM, the entry is the lui.
    """
    i = (prologue - base) // 4
    if i < 2:
        return prologue
    hi, ld = words[i - 2], words[i - 1]
    if (hi >> 26) != 0x0F or not (0x8000 <= (hi & 0xFFFF) < 0x8040):
        return prologue
    rt = (hi >> 16) & 0x1F
    if (ld >> 26) not in (0x23, 0x25, 0x24) or ((ld >> 21) & 0x1F) != rt:
        return prologue
    return prologue - 8


def unclaimed_runs(base: int, size: int, covered: set) -> list:
    gaps = sorted(set(range(base, base + size, 4)) - covered)
    runs = []
    for g in gaps:
        if runs and g - runs[-1][1] == 4:
            runs[-1][1] = g
        else:
            runs.append([g, g])
    return runs


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--images", default="build/elfs/images.json")
    ap.add_argument("--elfs", default="build/elfs")
    ap.add_argument("--decomp", default="build/decomp")
    ap.add_argument("--out", default="manifests/missed_functions.json")
    ap.add_argument("--seeds", default="build/seeds_extra")
    ap.add_argument("--check", action="store_true",
                    help="re-derive and compare with the committed census; write nothing")
    a = ap.parse_args()

    images = json.loads(Path(a.images).read_text())["images"]
    seeds_dir = Path(a.seeds)
    seeds_dir.mkdir(parents=True, exist_ok=True)
    report = {"tool": "find_missed_functions.py", "images": []}

    for img in images:
        index_path = Path(a.decomp) / img["name"] / "decompile-index.json"
        if not index_path.exists():
            sys.exit(f"missing {index_path}")
        entries = json.loads(index_path.read_text())["functions"]
        covered = set()
        for e in entries:
            if e["body"]["available"]:
                for r in e["body"]["ranges"]:
                    covered.update(range(int(r["start"], 16), int(r["end"], 16) + 1, 4))

        base, size = img["base"], img["size"]
        code = image_bytes(Path(a.elfs) / f"{img['name']}.elf", size)
        words = struct.unpack(f">{len(code) // 4}I", code[:len(code) // 4 * 4])
        at = lambda addr: words[(addr - base) // 4] if 0 <= (addr - base) // 4 < len(words) else None

        candidates, runs = [], []
        for s, e in unclaimed_runs(base, size, covered):
            span = [at(s + 4 * i) for i in range((e - s) // 4 + 1)]
            prologues = [s + 4 * i for i, w in enumerate(span) if w is not None and is_prologue(w)]
            jal = sum(1 for w in span if w is not None and (w >> 26) == 0x03)
            jr = sum(1 for w in span if w == 0x03E00008)
            codeish = bool(prologues) and (jal >= 3 or jr >= 2)
            if prologues or jal or jr:
                runs.append(dict(start=hex(s), bytes=e - s + 4, prologues=[hex(p) for p in prologues],
                                 jal=jal, jr_ra=jr, verdict="code" if codeish else "data-ish"))
            if codeish:
                candidates.extend(entry_before_prologue(words, base, p) for p in prologues)

        candidates = sorted(set(candidates))
        if not a.check:      # `--check` compares and writes nothing, seeds included
            (seeds_dir / f"{img['name']}.tsv").write_text(
                "".join(f"{c:#010x}\tfunction\tFUN_{c:08x}\n" for c in candidates))
        report["images"].append(dict(
            name=img["name"], unclaimed_runs=len(runs), candidates=len(candidates),
            candidate_bytes=4 * len(candidates),
            code_runs=[r for r in runs if r["verdict"] == "code"],
            runs=runs))
        if candidates:
            print(f"{img['name']:>16}  {len(candidates):3d} candidate starts  "
                  f"in {sum(1 for r in runs if r['verdict'] == 'code'):3d} code-like runs")

    if a.check:
        # M208: the committed census was a whole corpus generation stale -- 265 runs / 24 candidates from
        # an M83-era index, against 437 / 1 today -- and nothing compared the two. This is that comparison.
        committed = json.loads(Path(a.out).read_text())
        fresh = {i["name"]: (i["unclaimed_runs"], i["candidates"]) for i in report["images"]}
        old = {i["name"]: (i["unclaimed_runs"], i["candidates"]) for i in committed["images"]}
        drift = {k: (old.get(k), v) for k, v in fresh.items() if old.get(k) != v}
        cands = [(i["name"], r["start"], r["bytes"]) for i in report["images"] for r in i["code_runs"]]
        cases = [
            (f"the committed census matches a fresh derivation on {len(fresh)}/{len(fresh)} images",
             not drift, "ok" if not drift else f"drift: {list(drift.items())[:2]}"),
            (f"the candidate set is pinned: {[(n, s, b) for n, s, b in cands]}",
             cands == [("stage2", "0x8008bb10", 656)]),
        ]
        bad = 0
        for label, ok, *rest in cases:
            bad += not ok
            print(f"  {'PASS' if ok else 'FAIL'} {label}" + (f" — {rest[0]}" if rest else ""))
        print(f"{len(cases) - bad}/{len(cases)} census case(s)")
        sys.exit(1 if bad else 0)

    Path(a.out).write_text(json.dumps(report, indent=1) + "\n")
    total = sum(i["candidates"] for i in report["images"])
    code_bytes = sum(r["bytes"] for i in report["images"] for r in i["code_runs"])
    print(f"\n{total} candidate function starts; {code_bytes:,} B of code-like unclaimed runs")
    print(f"wrote {a.out} and per-image seed files in {seeds_dir}/")


if __name__ == "__main__":
    main()
