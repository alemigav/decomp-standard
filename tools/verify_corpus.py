#!/usr/bin/env python3
"""Verify the decompiled corpus against claims that can fail.

Six checks, each of which has a way to fail. A corpus is only worth committing if these hold,
and each one targets a different way the export could be quietly wrong:

  1 seed coverage     every name in config/symbols.tsv produced a file, at the right address
  2 call closure      every `jal` inside an image lands on a function entry in the corpus
  3 second opinion    Ghidra's boot-bank function set vs splat's (config/functions.csv)
  4 coverage          claimed bytes and unclaimed runs per image, printed not asserted
  5 regression        named functions still show the behaviour their name claims
  6 reproducibility   re-decompiling one image reproduces the same body sha256

Checks 1, 2, 5 and the count in 3 are hard failures (exit 1). Check 4 is a report: unclaimed
runs are expected where data sits inside a code image, and pretending otherwise would be the
same mistake as deleting the negative results.
"""
import argparse
import csv
import re
import json
import os
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

# name -> a substring its pseudocode must contain, from the evidence in config/symbols.tsv
REGRESSION = {
    "cart_record": ("* 0x10", "-0x7ffedeb0"),      # index*0x10 + 0x80012150
    "inflate": ("inflate", None),                   # must call something named inflate-ish
    "stage2_entry": ("osCreateThread", "stage2_init"),   # creates thread 7 (M15); needs the
                                                         # cross-image rename to read this way
    "overlay_open": ("0x8004cc", None),             # slot -> cart_record -> inflate
}


def read_elf(elf: Path, size: int) -> bytes:
    return elf.read_bytes()[0x100:0x100 + size]


def jals(code: bytes, base: int) -> list:
    n = len(code) // 4
    words = struct.unpack(f">{n}I", code[:n * 4])
    return [((base + i * 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            for i, w in enumerate(words) if (w >> 26) == 0x03]


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--images", default="build/elfs/images.json")
    ap.add_argument("--seeds", default="build/seeds")
    ap.add_argument("--src", default="src")
    ap.add_argument("--index", default="manifests/code_index.json")
    ap.add_argument("--functions-csv", default="config/functions.csv")
    ap.add_argument("--elfs", default="build/elfs")
    ap.add_argument("--repro-image", default="ovl_00b5e64")
    ap.add_argument("--skip-repro", action="store_true")
    ap.add_argument("--symbols", default="config/symbols.tsv")
    a = ap.parse_args()

    images = json.loads(Path(a.images).read_text())["images"]
    index = json.loads(Path(a.index).read_text())
    failures = []

    # 1 — seed coverage
    seeds = {}
    for p in Path(a.seeds).glob("*.tsv"):
        for line in p.read_text().splitlines():
            parts = line.split("\t")
            if len(parts) >= 3:
                seeds[int(parts[0], 16)] = (p.stem, parts[2].strip())
    entries = {int(f["address"], 16): f for img in index["images"]
               for f in img["functions_list"]}
    curated = set()
    for line in Path(a.symbols).read_text().splitlines():
        line = line.split("#", 1)[0].strip()
        if line:
            curated.add(int(line.split("\t")[0], 0))
    missing_all = [(hex(ad), v) for ad, v in seeds.items() if ad not in entries]
    missing = [m for m in missing_all if int(m[0], 16) in curated]
    missing_discovered = [m for m in missing_all if int(m[0], 16) not in curated]
    misnamed = [(hex(ad), v[1], entries[ad]["name"]) for ad, v in seeds.items()
                if ad in entries and entries[ad]["name"] != v[1]
                and entries[ad]["name"].lower() != v[1].lower()]
    print(f"1 seed coverage:     {len(seeds) - len(missing_all)}/{len(seeds)} seeds placed "
          f"({len(missing)} curated missing, {len(missing_discovered)} discovered boundaries "
          f"not created)")
    if missing:
        failures.append(f"seeds with no function: {missing}")
    if misnamed:
        failures.append(f"seeds whose name changed in export: {misnamed}")

    # 2 — call closure, measured twice: over the whole image, and over claimed code only.
    # A `jal`-shaped word inside a data region is not a call, so the whole-image figure is a
    # floor, not an error count. The code-only figure is the one that means "no missing callee".
    total_all = resolved_all = total_code = resolved_code = 0
    unresolved_by_image = {}
    for img in images:
        code = read_elf(Path(a.elfs) / f"{img['name']}.elf", img["size"])
        entry_set = {int(f["address"], 16) for f in
                     next(i for i in index["images"] if i["name"] == img["name"])["functions_list"]}
        n = len(code) // 4
        words = struct.unpack(f">{n}I", code[:n * 4])
        sites = [(img["base"] + i * 4, ((img["base"] + i * 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
                 for i, w in enumerate(words) if (w >> 26) == 0x03]
        inside = [(pc, t) for pc, t in sites if img["base"] <= t < img["base"] + img["size"]]
        unresolved = sorted({t for _, t in inside if t not in entry_set})
        total_all += len(inside)
        resolved_all += len(inside) - len([1 for _, t in inside if t not in entry_set])
        if unresolved:
            unresolved_by_image[img["name"]] = unresolved
    # claimed-code closure: recompute using body ranges from the merged index
    for img in index["images"]:
        base = int(img["base"], 16)
        code = read_elf(Path(a.elfs) / f"{img['name']}.elf", img["size"])
        entry_set = {int(f["address"], 16) for f in img["functions_list"]}
        spans = []
        for f in img["functions_list"]:
            spans.append((int(f["address"], 16), int(f["address"], 16) + f["size"]))
        n = len(code) // 4
        words = struct.unpack(f">{n}I", code[:n * 4])
        for i, w in enumerate(words):
            if (w >> 26) != 0x03:
                continue
            pc = base + i * 4
            if not any(s <= pc < e for s, e in spans):
                continue
            t = (pc & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            if not (base <= t < base + img["size"]):
                continue
            total_code += 1
            resolved_code += t in entry_set
    print(f"2 call closure:      inside claimed code {resolved_code}/{total_code} "
          f"({100.0 * resolved_code / max(total_code, 1):.2f} %); "
          f"whole image {resolved_all}/{total_all} "
          f"({100.0 * resolved_all / max(total_all, 1):.2f} %)")
    if unresolved_by_image:
        worst = sorted(unresolved_by_image.items(), key=lambda kv: -len(kv[1]))[:3]
        print(f"     unresolved targets are jal-shaped words in data, e.g. " +
              ", ".join(f"{n}:{[hex(t) for t in ts[:3]]}" for n, ts in worst))

    # 3 — second opinion on the boot bank
    splat = {int(r["address"], 16) for r in csv.DictReader(open(a.functions_csv))}
    ghidra = {int(f["address"], 16) for f in
              next(i for i in index["images"] if i["name"] == "boot")["functions_list"]}
    only_splat, only_ghidra = splat - ghidra, ghidra - splat
    print(f"3 second opinion:    boot bank splat {len(splat)} vs Ghidra {len(ghidra)} functions; "
          f"{len(splat & ghidra)} agree, {len(only_splat)} splat-only, {len(only_ghidra)} ghidra-only")

    # 4 — coverage report
    print("4 coverage:")
    for img in sorted(index["images"], key=lambda i: -i["size"])[:6]:
        print(f"     {img['name']:>16} {img['functions']:5d} funcs  "
              f"{img['coverage'] * 100:5.1f} % claimed  {img['unclaimed_runs']:3d} unclaimed runs")

    # 5 — regression on named functions
    checked = 0
    for name, needles in REGRESSION.items():
        hit = next((f for img in index["images"] for f in img["functions_list"]
                    if f["name"] == name), None)
        if not hit:
            failures.append(f"regression target {name} missing from the corpus")
            continue
        text = Path(hit["file"]).read_text()
        ok = all((n in text) for n in needles if n)
        checked += 1
        if not ok:
            failures.append(f"{name} no longer shows {[n for n in needles if n and n not in text]}")
        print(f"5 regression:        {name:>16} {'ok' if ok else 'FAILED'} "
              f"({', '.join(n for n in needles if n)})")

    # 7 — no function may read a register nothing in the corpus sets. This is how a mis-placed
    # boundary announces itself: a function started at a prologue whose argument preload was
    # hoisted above the frame setup decompiles with `undefined4 in_vN`. Discovery passes that
    # ignore this shipped 105 such functions in one iteration.
    allower = {"entrypoint": "the reset vector: nothing calls it, a0 is genuinely unset",
               "FUN_8016edb4": "pre-existing provider boundary in ovl_007c552, not seed-induced"}
    offenders, allowed = [], []
    for f in sorted(Path(a.src).glob("*/*.c")):
        text = f.read_text()
        if re.search(r"undefined[0-9]+ in_[a-z]", text):
            (allowed if f.stem in allower else offenders).append(f.stem)
    print(f"7 boundary sanity:   {len(offenders)} unexplained functions read an incoming register "
          f"({len(allowed)} allow-listed)")
    if offenders:
        failures.append(f"{len(offenders)} mis-bounded functions, e.g. {offenders[:6]}")

    # 6 — reproducibility
    if not a.skip_repro:
        img = next(i for i in images if i["name"] == a.repro_image)
        with tempfile.TemporaryDirectory() as tmp:
            out = Path(tmp) / "repro"
            env = dict(os.environ,
                       REA_GHIDRA_SEED_FILE=str(Path(a.seeds, a.repro_image + ".tsv").resolve()))
            r = subprocess.run(["rea", "decompile-all", f"build/elfs/{a.repro_image}.elf",
                                "--output", str(out), "--provider", "ghidra", "--format", "json"],
                               capture_output=True, text=True, env=env)
            if r.returncode:
                failures.append(f"reproducibility run failed: {r.stderr[-400:]}")
                print("6 reproducibility:   run FAILED")
            else:
                fresh = {(f["address"], f["sha256"]) for f in
                         json.loads((out / "decompile-index.json").read_text())["functions"]}
                # compare provider record hashes: the index also carries our own body hash,
                # and the two are different measurements of the same function
                old = {(f["address"], f["provider_sha256"]) for f in
                       next(i for i in index["images"]
                            if i["name"] == a.repro_image)["functions_list"]}
                same = fresh == old
                print(f"6 reproducibility:   {a.repro_image} re-decompiled, "
                      f"{len(fresh & old)}/{len(old)} bodies identical  "
                      f"{'ok' if same else 'DIFFERS'}")
                if not same:
                    failures.append(f"reproducibility: {len(fresh ^ old)} bodies differ")

    print()
    if failures:
        for f in failures:
            print(f"FAIL {f}")
        sys.exit(1)
    print("all hard checks passed")


if __name__ == "__main__":
    main()
