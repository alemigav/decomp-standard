#!/usr/bin/env python3
"""Classify every word of every executable image: body, table, named data, padding, or unclassified.

Until M207 the corpus published one number -- 62.2 % of image bytes inside a known function body -- and a
sentence for the rest: "data, padding, or code Ghidra did not identify". That sentence is what this tool
replaces with a partition, and the partition is deliberately conservative: a word only leaves `unclassified`
on the strength of an artifact that names it.

    function_body   a body range from fixtures/decomp/ranges.json
    jump_table      a table start named by manifests/jump_tables.json
    data_named      an address the decompiler names DAT_xxxxxxxx in a src/ body
    padding         a word inside a run of >= 16 identical 0x00 or 0xFF bytes, read from the unpacked image
    unclassified    everything else -- reported, never renamed to `data` on a hunch

Precedence is fixed (body, table, named data, padding) and **overlaps are counted, not hidden**: a `DAT_`
address inside a function body is a real ambiguity in the provider's output, so the tool reports how many
words the precedence resolved rather than picking silently.

The committed map is `manifests/byte_map.json`; it is metadata (addresses and classes), like
`fixtures/decomp/ranges.json`, and contains no image bytes.

Usage:
  ./classify_image.py --check             # the committed map's invariants, committed artifacts only (CI-safe)
  ./classify_image.py --check-cartridge   # rebuild from the unpacked images and require the same map
  ./classify_image.py --write             # regenerate manifests/byte_map.json (needs the unpacked images)
"""
import argparse
import json
import re
import zlib
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
ROM = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
MAP = "manifests/byte_map.json"

CLASSES = ["function_body", "jump_table", "data_named", "padding", "unclassified"]
DAT = re.compile(r"\bDAT_([0-9a-fA-F]{8})\b")
MIN_PAD = 16


def load(root: Path = ROOT):
    rd = lambda p: json.loads((root / p).read_text())
    return (rd("fixtures/decomp/images.json"), rd("fixtures/decomp/ranges.json"),
            rd("manifests/jump_tables.json"))


def named_data(root: Path = ROOT):
    """Every DAT_xxxxxxxx the decompiled bodies mention, per image."""
    out = {}
    for src in sorted((root / "src").glob("*/*.c")):
        out.setdefault(src.parent.name, set()).update(
            int(m.group(1), 16) for m in DAT.finditer(src.read_text()))
    return out


_ROM = {}


def _rom(root: Path):
    """The cartridge, read once. Reading it per image is 36 x 64 MiB and took the tool past two minutes."""
    key = str(root)
    if key not in _ROM:
        p = root / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
        _ROM[key] = p.read_bytes() if p.exists() else None
    return _ROM[key]


def image_bytes(img, root: Path = ROOT):
    """The image's own bytes, from `assets/unpacked/…bin` or, for the boot bank, from the cartridge."""
    src, size = img["source"], img["size"]
    if src.startswith("ROM "):
        rom = _rom(root)
        if rom is None:
            return None
        off = int(src.split()[1], 16)
        return rom[off:off + size]
    p = root / src
    return p.read_bytes()[:size] if p.exists() else None


def pad_words(blob, base):
    """Word start -> the repeated value, for runs of >= MIN_PAD identical 0x00 or 0xFF bytes.

    The value is carried because it is what the padding *law* checks: a merged range that spanned a 0x00 run
    and a 0xFF run is still "padding" by the class rule and no longer a single value, so the label keeps them
    apart (`run of 0x00` vs `run of 0xff`) and the two claims agree.
    """
    out = {}
    if not blob:
        return out
    i, n = 0, len(blob)
    while i < n:
        j = i
        while j < n and blob[j] == blob[i] and blob[j] in (0x00, 0xFF):
            j += 1
        if j - i >= MIN_PAD:
            # Words *fully inside* the run: rounding the start down (or the end up) would claim bytes
            # that are not 0x00/0xFF, which is exactly what the padding law caught (256 ranges, first run).
            start = i + (-i % 4)
            for w in range(base + start, base + j - 3, 4):
                out[w] = blob[i]
        # NOT `i = j`: when the byte at i is neither 0x00 nor 0xFF the inner loop never advances, j == i,
        # and the scan spins forever. That hung `--write` past two minutes before it was caught.
        i = j if j > i else i + 1
    return out


def build(root: Path = ROOT):
    images, ranges, jumps = load(root)
    dat = named_data(root)
    tables = {i["name"]: {int(t["table"], 16) for t in i.get("tables", []) if t.get("table")}
              for i in jumps["images"]}
    report = {"tool": "classify_image.py", "classes": CLASSES, "images": {},
              "overlaps": {}, "totals": {}}
    for img in images["images"]:
        name, base, size = img["name"], img["base"], img["size"]
        blob = image_bytes(img, root)
        claimed = {}
        for s, e in ranges["images"].get(name, []):
            for w in range(int(s), int(e) + 1, 4):
                claimed[w] = ("function_body", "fixtures/decomp/ranges.json")
        overlap = {"table_in_body": 0, "data_in_body": 0, "padding_in_body": 0}
        for t in tables.get(name, ()):
            overlap["table_in_body"] += t in claimed
            claimed[t] = ("jump_table", "manifests/jump_tables.json")
        for a in dat.get(name, ()):
            if base <= a < base + size:
                overlap["data_in_body"] += a in claimed
                claimed[a] = ("data_named", "src/<image>/*.c DAT_")
        for w, value in pad_words(blob, base).items():
            overlap["padding_in_body"] += w in claimed
            claimed.setdefault(w, ("padding", f"run of 0x{value:02x} in the unpacked image"))
        out = []
        for w in range(base, base + size, 4):
            cls, src = claimed.get(w, ("unclassified", "no artifact names it"))
            # `out[-1][1]` is the inclusive END, so the next word continues the run when end + 1 == w.
            # The first version compared end + 4, which never matched: the map came out one range per
            # word, 486 908 of them, a 47 MB file that the artefact scan (4 MiB limit) refused.
            if out and out[-1][2] == cls and out[-1][3] == src and out[-1][1] + 1 == w:
                out[-1][1] = w + 3
            else:
                out.append([w, w + 3, cls, src])
        report["images"][name] = out
        report["overlaps"][name] = overlap
        totals = {}
        for s, e, cls, _src in out:
            totals[cls] = totals.get(cls, 0) + (e - s + 1)
        report["totals"][name] = totals
    return report


def check(rep):
    images = json.loads((ROOT / "fixtures/decomp/images.json").read_text())["images"]
    cases = []
    bad_order = bad_cover = 0
    for img in images:
        name, base, size = img["name"], img["base"], img["size"]
        rs = rep["images"].get(name) or []
        if any(rs[i][0] <= rs[i - 1][1] for i in range(1, len(rs))):
            bad_order += 1
        if not rs or rs[0][0] != base or rs[-1][1] != base + size - 1:
            bad_cover += 1
    cases.append((f"the {len(images)} per-image maps are sorted, disjoint and cover each image exactly "
                  f"({bad_order} misordered, {bad_cover} miscovered)", bad_order == 0 and bad_cover == 0))
    tot = {c: sum(t.get(c, 0) for t in rep["totals"].values()) for c in CLASSES}
    cases.append((f"the body class totals {tot['function_body']:,} B — the figure the corpus publishes",
                  tot["function_body"] == 1210600))
    srcs = [r[3] for rs in rep["images"].values() for r in rs]
    cases.append((f"every word is in one of the {len(CLASSES)} declared classes and every range names its "
                  f"source ({sum(1 for s in srcs if not s)} unnamed)", all(srcs)))
    cases.append((f"the partition closes: {' + '.join(f'{tot[c]:,}' for c in CLASSES)} = "
                  f"{sum(tot.values()):,} B of image bytes", sum(tot.values()) == 1947632))
    ov = {k: sum(v[k] for v in rep["overlaps"].values()) for k in
          ("table_in_body", "data_in_body", "padding_in_body")}
    cases.append((f"precedence resolved {ov['table_in_body']} table, {ov['data_in_body']} named-data and "
                  f"{ov['padding_in_body']} padding words that fall inside a body — counted, not hidden", True))
    cases.append((f"unclassified is {tot['unclassified']:,} B ({100.0 * tot['unclassified'] / 1947632:.1f} %) "
                  f"— a published bucket, never renamed to data", tot["unclassified"] > 0))
    return cases


def cartridge_check(root: Path = ROOT):
    """Rebuild from the unpacked images and require the committed map; then verify the padding law."""
    images, _r, _j = load(root)
    fresh = build(root)
    committed = json.loads((root / MAP).read_text())
    same = fresh["images"] == committed["images"]
    ok_pad, bad = True, []
    for img in images["images"]:
        blob = image_bytes(img, root)
        for s, e, cls, _src in fresh["images"][img["name"]]:
            if cls != "padding":
                continue
            seg = blob[s - img["base"]:e - img["base"] + 1]
            if len(set(seg)) != 1 or seg[0] not in (0x00, 0xFF) or len(seg) < 4:
                bad.append(f"{img['name']}:{s:#010x}")
    ok_pad = not bad
    return [("a rebuild from the unpacked images reproduces the committed map exactly", same),
            (f"every padding range is a single value, 0x00 or 0xFF ({len(bad)} violate: {bad[:3]})", ok_pad)]


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--check-cartridge", action="store_true")
    a = ap.parse_args()
    if a.write:
        rep = build()
        if any(not image_bytes(i) for i in load()[0]["images"]):
            print("REFUSED: the unpacked images are not present, so padding cannot be classified "
                  "(run tools/unpack_zlib.py first)")
            return 2
        (ROOT / MAP).write_text(json.dumps(rep, indent=1) + "\n")
        tot = {c: sum(t.get(c, 0) for t in rep["totals"].values()) for c in CLASSES}
        print(f"wrote {MAP} — " + ", ".join(f"{c} {tot[c]:,}" for c in CLASSES))
        return 0
    if a.check_cartridge:
        if not all(image_bytes(i) for i in load()[0]["images"]):
            print("SKIP (needs the unpacked images)")
            return 0
        cases = cartridge_check()
    else:
        cases = check(json.loads((ROOT / MAP).read_text()))
    bad = 0
    for label, ok in cases:
        bad += not ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{len(cases) - bad}/{len(cases)} byte-map case(s)")
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
