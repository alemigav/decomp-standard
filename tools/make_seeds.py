#!/usr/bin/env python3
"""Turn config/symbols.tsv into one REA_GHIDRA_SEED_FILE per image.

Why a separate step: Ghidra applies seed names **before** auto-analysis and digests them into
the analysis profile, so names must be decided first and then re-seeded for every image. A
name that lands outside an image's range would silently create a bogus symbol, so each seed
file is filtered to `[base, base+size)` and cross-checked against the image manifest.

The seed format REA expects is `address<TAB>kind<TAB>name` — the evidence column in
config/symbols.tsv is for humans and is stripped here.

Usage:
  ./make_seeds.py --images build/elfs/images.json --out build/seeds
"""
import argparse
import fnmatch
import json
import sys
from pathlib import Path

SYMBOLS = Path(__file__).resolve().parent.parent / "config" / "symbols.tsv"


def read_symbols(path: Path) -> list:
    out = []
    for lineno, line in enumerate(path.read_text().splitlines(), 1):
        line = line.split("#", 1)[0].strip()
        if not line:
            continue
        parts = [p.strip() for p in line.split("\t")]
        if len(parts) < 3:
            sys.exit(f"{path}:{lineno}: expected address<TAB>kind<TAB>name")
        addr, kind, name = parts[0], parts[1], parts[2]
        if kind not in ("function", "label", "code"):
            sys.exit(f"{path}:{lineno}: unknown kind {kind!r}")
        out.append((int(addr, 0), kind, name, parts[3] if len(parts) > 3 else ""))
    return out


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--symbols", default=str(SYMBOLS))
    ap.add_argument("--images", default="build/elfs/images.json")
    ap.add_argument("--out", default="build/seeds")
    ap.add_argument("--extra", action="append", default=None,
                    help="candidate boundary directories (find_missed_functions, find_jump_tables)")
    a = ap.parse_args()

    symbols = read_symbols(Path(a.symbols))
    # boundaries found in unclaimed code (tools/find_missed_functions.py) carry func_ names;
    # a curated name in config/symbols.tsv always wins over a discovered boundary.
    curated = {ad for ad, _, _, _ in symbols}
    images = json.loads(Path(a.images).read_text())["images"]
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)

    # An address alone does not identify an image: twenty overlays share the load address
    # 0x80161cf0, so filtering by range broadcasts one image's boundaries into all of them and
    # decorates each with functions that belong to different bytes. A discovered boundary is
    # therefore applied to its own image only, and a curated name must fall inside exactly one
    # image or the run fails.
    extra_by_image = {}
    # versioned deny-list: images whose discovered boundaries were measured and rejected
    rejected = {}
    deny = Path("config/rejected_seeds.txt")
    if deny.exists():
        for line in deny.read_text().splitlines():
            line = line.split("#", 1)[0].strip()
            if line:
                parts = line.split()
                rejected[parts[0]] = " ".join(parts[2:]) or "listed in config/rejected_seeds.txt"

    for d in (a.extra or ["build/seeds_extra"]):
        if not Path(d).is_dir():
            continue
        for p in sorted(Path(d).glob("*.tsv")):
            rows = [(int(x.split("\t")[0], 0), x.split("\t")[1], x.split("\t")[2])
                    for x in p.read_text().splitlines()
                    if len(x.split("\t")) >= 3 and int(x.split("\t")[0], 0) not in curated]
            hit = next((why for pat, why in rejected.items()
                        if fnmatch.fnmatch(p.stem, pat)), None)
            if hit is not None:
                print(f"  {p.stem}: {len(rows)} discovered seeds REJECTED — {hit[:70]}")
                continue
            seen = {r[0] for r in extra_by_image.get(p.stem, [])}
            extra_by_image.setdefault(p.stem, []).extend(r for r in rows if r[0] not in seen)

    total = 0
    print(f"{len(symbols)} symbols, {len(images)} images")
    for img in images:
        lo, hi = img["base"], img["base"] + img["size"]
        mine = [(ad, k, n) for ad, k, n, _ in symbols if lo <= ad < hi]
        mine += extra_by_image.get(img["name"], [])
        path = out / f"{img['name']}.tsv"
        path.write_text("".join(f"{ad:#010x}\t{k}\t{n}\n" for ad, k, n in mine))
        total += len(mine)
        if mine:
            print(f"  {img['name']:>16}  {len(mine):2d} seeds  "
                  f"({', '.join(n for _, _, n in mine[:4])}{'…' if len(mine) > 4 else ''})")
        else:
            print(f"  {img['name']:>16}   0 seeds")

    placed = {ad for img in images for ad in
              (ad for ad, _, _, _ in symbols if img["base"] <= ad < img["base"] + img["size"])}
    orphans = [s for s in symbols if s[0] not in placed]
    print(f"\n{total} seed entries written to {out}/")
    if orphans:
        print(f"{len(orphans)} symbols fall in no image — an address or a base is wrong:")
        for ad, _, name, _ in orphans:
            print(f"  {ad:#010x}  {name}")
        sys.exit(1)


if __name__ == "__main__":
    main()
