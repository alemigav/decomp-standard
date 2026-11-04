#!/usr/bin/env python3
"""Render the project's progress as a block map, and keep the README's copy honest.

Two panels, both derived from fixtures rather than drawn by hand:

  * **the cartridge**, one row per image, one cell per group of functions. The shading is the *matching* question --
    a cell is bright only when a function in it has been reproduced from the disassembly and recompiled to the
    byte. Everything else is the pseudocode corpus: present, but not yet evidence that we know what produced it.
  * **the record**, one bar per phase, read from the README's own phase table, so the picture cannot drift from the
    table beside it.

Why generated: this project's whole claim is that no number in the docs is a habit. A hand-drawn chart is a habit
with better typography. `--check` fails if the README's block differs from what this produces, exactly like
`counts.py` and `milestone_index.py` do for the numbers.

Usage:
  ./progress_map.py --write     # regenerate the block in README.md
  ./progress_map.py --check     # fail if it is stale (run by the gate suite)
  ./progress_map.py             # print to stdout
"""
import argparse
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
README = ROOT / "README.md"
CODE_INDEX = ROOT / "manifests" / "code_index.json"
BEGIN = "<!-- progress-map:begin -->"
END = "<!-- progress-map:end -->"
CELLS = 58

# The functions reproduced from the disassembly and recompiled. Each one is asserted byte-exact (or, for the last,
# its residue is itemised) by a case in tools/compile_probe.py, which is the evidence; this table is only a pointer.
MATCHED = {
    0x8004FD1C: ("exact", "98 words, p6: a five-arm state machine"),
    0x80057E1C: ("exact", "84 words, p7: a seven-arm state machine"),
    0x80070120: ("exact", "46 words, p9: a predicate dispatcher"),
    0x80059868: ("exact", "167 words: a seven-state game-state machine"),
    0x80059530: ("exact", "206 words: a twelve-arm state machine"),
    0x800ACAE4: ("exact", "53 words: a clamp-then-dispatch predicate"),
    0x80024558: ("exact", "139 words: a six-arm dispatcher over float constants"),
    0x8007E590: ("recovered", "229 words, 226 exact: three words, one register in case 4's select"),
    0x800701D8: ("exact", "141 words: a 44-arm accessor dispatcher"),
    0x8006FC5C: ("exact", "53 words: a seven-arm record writer"),
    0x8006E68C: ("exact", "41 words: a seven-operator predicate dispatcher"),
    0x8006E574: ("exact", "23 words: a bit-test leaf"),
    0x800704E0: ("exact", "123 words: a 44-arm address-of dispatcher"),
    0x80006D30: ("exact", "9 words: osCreateMesgQueue, from libultra"),
    0x8000CC90: ("exact", "24 words: osSetEventMesg, pre-PRENMI libultra"),
    0x8006FF48: ("exact", "98 words: a 44-arm accessor setter"),
}


def load_corpus():
    d = json.loads(CODE_INDEX.read_text())
    images = []
    for im in d["images"]:
        fns = sorted((int(f["address"], 0), f.get("name", "")) for f in im["functions_list"])
        images.append((im["name"], fns))
    return images


def cell_of(name, group):
    """The shade for one cell: the best status among the functions it covers."""
    best = "-"
    for addr, _ in group:
        st = MATCHED.get(addr, (None, None))[0]
        if st == "exact":
            return "#"
        if st == "recovered":
            best = "+"
    return best


def panel_images(images):
    shade = {"#": "\u2588", "+": "\u2593", "-": "\u2592", ".": "\u00b7"}
    total = sum(len(f) for _, f in images)
    exact = sum(1 for _, f in images for a, _ in f if MATCHED.get(a, ("",))[0] == "exact")
    rec = sum(1 for _, f in images for a, _ in f if MATCHED.get(a, ("",))[0] == "recovered")
    out = ["the cartridge \u2014 one cell per group of functions, shaded by how far each is *matched*", ""]
    for name, fns in images:
        n = len(fns)
        row = []
        for i in range(CELLS):
            lo = i * n // CELLS
            hi = max((i + 1) * n // CELLS, lo + 1)
            row.append(shade[cell_of(name, fns[lo:hi])])
        out.append("%-12s %2d\u2502%s\u2502" % (name, n, "".join(row)))
    out += ["", "%d functions across %d images \u00b7 %s %d reproduced byte-for-byte (%.2f%%) \u00b7 %s %d recovered, residue itemised"
            % (total, len(images), shade["#"], exact, 100.0 * exact / total, shade["+"], rec),
            "%s matched byte-for-byte   %s recovered, not exact   %s pseudocode body only (not yet evidence of a match)"
            % (shade["#"], shade["+"], shade["-"])]
    return out


def panel_phases():
    text = README.read_text()
    rows = re.findall(r"^\| (P\d+) \| \**M(\d+)[\u2013-]M(\d+)\** \|", text, re.M)
    if not rows:
        return []
    last = max(int(b) for _, _, b in rows)
    width = 48
    out = ["", "the record \u2014 one bar per phase, from the phase table's own ranges (M0\u2013M%d)" % last, ""]
    for tag, a, b in rows:
        a, b = int(a), int(b)
        n = b - a + 1
        bar = int(round(width * n / (last + 1)))
        out.append("%-4s M%-3d\u2502%s\u2502 %d" % (tag, a, "\u2588" * max(bar, 1), n))
    return out


def render():
    images = load_corpus()
    body = "\n".join(panel_images(images) + panel_phases())
    return "%s\n```\n%s\n```\n%s" % (BEGIN, body, END)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args(argv)
    block = render()
    text = README.read_text()
    if args.check:
        if BEGIN not in text or END not in text:
            print("FAIL the README has no progress-map block")
            return 1
        have = text[text.index(BEGIN):text.index(END) + len(END)]
        if have != block:
            print("FAIL the progress map is stale -- run tools/progress_map.py --write")
            return 1
        missing = [hex(a) for a in MATCHED
                   if a not in {int(f["address"], 0) for im in json.loads(CODE_INDEX.read_text())["images"]
                                for f in im["functions_list"]}]
        if missing:
            print("FAIL claimed as recovered but not in the corpus: %s" % ", ".join(missing))
            return 1
        # three assertions, each of which aborts above rather than reaching this line
        print("  ok   the README carries a progress-map block")
        print("  ok   the block matches `manifests/code_index.json` and the README's own phase table")
        print("  ok   all %d functions claimed as recovered are in the corpus" % len(MATCHED))
        print("3/3 progress map case(s)")
        return 0
    if args.write:
        if BEGIN in text and END in text:
            new = text[:text.index(BEGIN)] + block + text[text.index(END) + len(END):]
        else:
            new = text.replace("\n## What is decoded", "\n" + block + "\n\n## What is decoded", 1)
        if new != text:
            README.write_text(new)
            print("wrote the progress map into the README")
        else:
            print("progress map already current")
        return 0
    print(block)
    return 0


if __name__ == "__main__":
    sys.exit(main())
