#!/usr/bin/env python3
"""Distil the Ghidra decompile indices into the address metadata the analyses actually use.

`build/decomp/<image>/decompile-index.json` is 9.5 MB across 36 images, almost none of which is addresses:
each function entry also carries a `relative_path`, a `sha256`, a `limitations` list and `status` prose. The
analyses only ever read `body.ranges` — the function start/end pairs.

M129 put the *synthetic* corpus in CI. The real acceptance checks need two things a runner does not have:

  * **stage2's bytes** (1.17 MB of cartridge code) — cartridge content, and this project does not commit ROM
    bytes, so CI can only get them from an owner-provided secret;
  * **exact region boundaries** — measured, not assumed: with the prologue heuristic in place of the index,
    acceptance test 1b fails and revives the M117 artifact (`a0 = ret(80001180)` instead of `unk`).

The boundary half is pure address metadata — the same class of fact `src/INDEX.md` already publishes — so it
is distilled to `fixtures/decomp/ranges.json` (~100 KB) and committed. That way a runner that *is* given the
cartridge needs nothing else, and drift between the fixture and `build/decomp` is detectable.

Usage:
  ./export_ranges.py                 # write fixtures/decomp/ranges.json from build/decomp
  ./export_ranges.py --check         # verify the fixture still matches build/decomp (exit 1 on drift)
"""
import argparse
import json
import sys
from pathlib import Path

DECOMP = Path("build/decomp")
OUT = Path("fixtures/decomp/ranges.json")
BUILD_IMAGES = Path("build/elfs/images.json")
OUT_IMAGES = Path("fixtures/decomp/images.json")
IMAGE_FIELDS = ("name", "role", "base", "size", "source")


def collect():
    images = {}
    for path in sorted(DECOMP.glob("*/decompile-index.json")):
        name = path.parent.name
        ranges = []
        for fn in json.loads(path.read_text()).get("functions", []):
            for r in (fn.get("body") or {}).get("ranges") or []:
                ranges.append([int(r["start"], 16), int(r["end"], 16)])
        images[name] = sorted(ranges)
    return images


def image_inventory():
    """The 36-image extent table, minus the build-side commentary: layout metadata, no bytes.

    M205 committed `fixtures/decomp/images.json` by hand, which made it the one fixture with no producer --
    the class of artifact that drifts silently. M210 gives it the generator its sibling always had.
    """
    build = json.loads(BUILD_IMAGES.read_text())
    return {"note": ("the 36 executable images: load address, extent and origin. Layout metadata only - no "
                     "cartridge bytes. Regenerate with tools/export_ranges.py --write-images."),
            "cart_sha256": build.get("cart_sha256"),
            "images": [{k: i[k] for k in IMAGE_FIELDS if k in i} for i in build["images"]]}


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true", help="compare against the committed fixture")
    ap.add_argument("--write-images", action="store_true", help="regenerate fixtures/decomp/images.json")
    ap.add_argument("--check-images", action="store_true", help="verify images.json against build/elfs")
    args = ap.parse_args()

    if args.write_images or args.check_images:
        if not BUILD_IMAGES.exists():
            print("%s not present — nothing to distil (expected on a fresh clone)" % BUILD_IMAGES)
            return 0 if args.check_images else 1
        fresh = image_inventory()
        if args.write_images:
            OUT_IMAGES.parent.mkdir(parents=True, exist_ok=True)
            OUT_IMAGES.write_text(json.dumps(fresh, indent=1) + "\n")
            print("wrote %s: %d images, %d bytes" % (OUT_IMAGES, len(fresh["images"]),
                                                    sum(i["size"] for i in fresh["images"])))
            return 0
        want = json.loads(OUT_IMAGES.read_text())
        bad = [k for k in ("cart_sha256", "images") if want.get(k) != fresh.get(k)]
        print(("PASS" if not bad else "FAIL") + " fixtures/decomp/images.json matches build/elfs/images.json"
              + ("" if not bad else " — differs in: %s" % ", ".join(bad)))
        print(f"1/1 image-inventory case(s)" if not bad else f"0/1 image-inventory case(s)")
        return 1 if bad else 0

    if not DECOMP.exists():
        print("%s not present — nothing to distil (this is expected on a fresh clone)" % DECOMP)
        return 0 if args.check else 1

    got = collect()
    if args.check:
        if not OUT.exists():
            print("FAIL %s is missing" % OUT)
            return 1
        want = json.loads(OUT.read_text())["images"]
        if {k: [list(r) for r in v] for k, v in want.items()} != got:
            drift = [k for k in set(want) | set(got) if want.get(k) != got.get(k)]
            print("FAIL fixture differs from build/decomp for: %s" % ", ".join(sorted(drift)[:6]))
            return 1
        print("PASS fixtures/decomp/ranges.json matches build/decomp (%d images, %d ranges)"
              % (len(got), sum(len(v) for v in got.values())))
        return 0

    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps({"note": "address metadata distilled from build/decomp/*/decompile-index.json; "
                                       "regenerate with tools/export_ranges.py",
                               "images": got}, indent=0, sort_keys=True) + "\n")
    print("wrote %s: %d images, %d ranges, %d bytes" % (
        OUT, len(got), sum(len(v) for v in got.values()), OUT.stat().st_size))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
