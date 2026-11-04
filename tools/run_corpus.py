#!/usr/bin/env python3
"""Run the two-phase corpus pipeline and report the differential honestly.

The phases exist so that "discovery added N functions" is a measurement rather than a claim:

  baseline  every image decompiled with the *curated* seeds only (config/symbols.tsv)
  final     every image decompiled with curated + discovered boundaries (build/seeds_extra)

`tools/find_missed_functions.py` reads the baseline to find what the provider left unclaimed. If
it read the final run instead, the gaps would already be filled and it would find nothing — the
order is load-bearing, which is why it lives in one place.

**The assertion that matters:** a cancelled run is not a failure. REA exits with a
`{"code":"cancelled"}` envelope, leaves the partially written output directory in place, and the
index in it looks complete: on one overlay a cancelled run left 34 of 103 functions with
`failed: 0`. So this runner requires `normalized_result` in the reply and treats anything else as
"not run", deleting the partial directory before retrying. Exit status is not enough.

Usage:
  ./run_corpus.py baseline --seeds build/seeds-baseline
  ./run_corpus.py final    --seeds build/seeds
  ./run_corpus.py report
"""
import argparse
import json
import os
import shutil
import subprocess
import sys
from pathlib import Path

IMAGES = "build/elfs/images.json"
ELF_DIR = "build/elfs"


def images() -> list:
    return json.loads(Path(IMAGES).read_text())["images"]


def seed_count(path: Path) -> int:
    return sum(1 for line in path.read_text().splitlines() if line.strip()) if path.exists() else 0


def run_one(img: dict, out_root: Path, seeds: Path) -> tuple:
    """Decompile one image. Returns (ok, written, failed, reason)."""
    target = out_root / img["name"]
    seed_file = seeds / f"{img['name']}.tsv"
    env = dict(os.environ, REA_GHIDRA_SEED_FILE=str(seed_file.resolve()),
               REA_GHIDRA_DECOMPILE_TIMEOUT_SECONDS=os.environ.get(
                   "REA_GHIDRA_DECOMPILE_TIMEOUT_SECONDS", "120"))
    proc = subprocess.run(["rea", "decompile-all", f"{ELF_DIR}/{img['name']}.elf",
                           "--output", str(target), "--provider", "ghidra", "--format", "json"],
                          capture_output=True, text=True, env=env)
    try:
        doc = json.loads(proc.stdout)
    except json.JSONDecodeError:
        reason = (proc.stderr or proc.stdout or "no output")[-160:]
        return False, 0, 0, f"unparseable reply: {reason}"
    if "normalized_result" not in doc:
        # cancelled or refused: the directory may exist and look plausible — remove it
        if target.exists():
            shutil.rmtree(target, ignore_errors=True)
        return False, 0, 0, f"{doc.get('code')}: {doc.get('message', '')[:100]}"
    counts = doc["normalized_result"]["counts"]
    # A second silent-partial mode: the index can report status "written" for entries whose file
    # was never flushed (measured on ovl_0095446: 36 of 93). Verify the files exist before
    # believing the count.
    index = target / "decompile-index.json"
    if not index.exists():
        shutil.rmtree(target, ignore_errors=True)
        return False, 0, 0, "no index after a successful reply"
    missing = [e for e in json.loads(index.read_text())["functions"]
               if e["status"] == "written" and not (target / e["relative_path"]).exists()]
    if missing:
        shutil.rmtree(target, ignore_errors=True)
        return False, 0, 0, f"{len(missing)} of {len(json.loads(index.read_text())['functions'])} files missing"
    return True, counts["written"], counts["failed"], doc["analysis_profile"]["digest"]


def phase(name: str, out_root: Path, seeds: Path, images_list: list) -> None:
    out_root.mkdir(parents=True, exist_ok=True)
    print(f"phase {name}: {len(images_list)} images -> {out_root}, seeds from {seeds}")
    print(f"{'image':>16} {'seeds':>5} {'written':>8} {'failed':>6}  note")
    totals = [0, 0]
    retried = []
    for img in images_list:
        index = out_root / img["name"] / "decompile-index.json"
        if index.exists():
            n = len(json.loads(index.read_text())["functions"])
            print(f"{img['name']:>16} {seed_count(seeds / (img['name'] + '.tsv')):5d} "
                  f"{n:8d} {'-':>6}  already present, skipped")
            totals[0] += n
            continue
        ok, written, failed, note = run_one(img, out_root, seeds)
        print(f"{img['name']:>16} {seed_count(seeds / (img['name'] + '.tsv')):5d} "
              f"{written if ok else 0:8d} {failed if ok else 0:6d}  {note[:70] if not ok else 'ok'}")
        if not ok:
            retried.append(img["name"])
            continue
        totals[0] += written
        totals[1] += failed
    print(f"\n{name}: {totals[0]} functions, {totals[1]} failed")
    if retried:
        print(f"{len(retried)} images did not complete and must be re-run: {retried}")
        sys.exit(1)


def report() -> None:
    """The four axes, baseline vs final, so the delta can be attributed."""
    imgs = images()
    rows, tot = [], [0] * 8
    for img in imgs:
        b = Path("build/decomp-baseline") / img["name"] / "decompile-index.json"
        f = Path("build/decomp") / img["name"] / "decompile-index.json"
        if not (b.exists() and f.exists()):
            continue
        bd, fd = json.loads(b.read_text()), json.loads(f.read_text())
        def stats(doc):
            n = len(doc["functions"])
            failed = sum(1 for x in doc["functions"] if x["status"] == "failed")
            covered = set()
            for x in doc["functions"]:
                if x["body"]["available"]:
                    for r in x["body"]["ranges"]:
                        covered.update(range(int(r["start"], 16), int(r["end"], 16) + 1, 4))
            return n, failed, len(covered) * 4
        bn, bf, bc = stats(bd)
        fn, ff, fc = stats(fd)
        rows.append((img["name"], bn, fn, bf, ff, bc, img["size"], fc))
        tot[0] += bn; tot[1] += fn; tot[2] += bf; tot[3] += ff
        tot[4] += bc; tot[5] += img["size"]; tot[6] += fc
    print(f"{'image':>16} {'funcs B':>8} {'funcs F':>8} {'d':>5} {'fail B':>7} {'fail F':>7} "
          f"{'cover B':>8} {'cover F':>8}")
    for n, bn, fn, bf, ff, bc, size, fc in sorted(rows, key=lambda r: r[2] - r[1], reverse=True)[:10]:
        print(f"{n:>16} {bn:8d} {fn:8d} {fn - bn:+5d} {bf:7d} {ff:7d} "
              f"{100 * bc / size:7.1f}% {100 * fc / size:7.1f}%")
    print(f"\n{'TOTAL':>16} {tot[0]:8d} {tot[1]:8d} {tot[1] - tot[0]:+5d} "
          f"{tot[2]:7d} {tot[3]:7d} {100 * tot[4] / tot[5]:7.1f}% {100 * tot[6] / tot[5]:7.1f}%")
    print("\nReading the axes: function count moves only if discovery added splits (it cannot move")
    print("under identical ELFs, which carry no symbols); failed must fall if discovery resolved")
    print("real decompile failures rather than just adding names; coverage is the share of code")
    print("bytes attributed to a body, and it is the honest headline — not the function count.")


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("phase", choices=("baseline", "final", "report"))
    ap.add_argument("--seeds", default="build/seeds")
    ap.add_argument("--out", default=None)
    a = ap.parse_args()
    if a.phase == "report":
        report()
        return
    out = Path(a.out or ("build/decomp-baseline" if a.phase == "baseline" else "build/decomp"))
    phase(a.phase, out, Path(a.seeds), images())


if __name__ == "__main__":
    main()
