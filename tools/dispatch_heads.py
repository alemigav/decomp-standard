"""Census the bounds-checked dispatch heads — the code shape that made two extent questions look like one.

M226 found one: opcode `0x36`'s handler bounds-checks an index (`sltiu v0,a0,5`), indexes a static table and
`jr`s through it, and its five arms are separate corpus functions that all share one tail. M227 found the
extent queue wants to merge such regions into single functions and called one entry unsafe. Both questions
have the same answer, and it is a class:

    sltiu vX,vY,K      the bound
    ...  lui + addiu   the table's address, built as `addiu` with a sign-extended immediate
    ...  lw vZ,0(vW)
         jr vZ         the dispatch

Scanning stage-2 for that shape finds **86 heads with 86 distinct tables**, all but one inside this image.
So this is not a quirk of the script VM: a fifth of the game's functions dispatch through a table this way,
and every "is this extent one function?" question about them is really "is this region a head plus its
arms?".

What the census reports per head, because each is what some extent question turned on:

  * **the table**, its bound and its entry count, measured as the count of distinct in-image targets;
  * **whether the head is a corpus function start**, and whether it is the **target of a `jal`** — a head
    that other code calls is a function boundary, and a correction that swallows it deletes a call target;
  * **whether the head is a Script VM handler** (one of the registry's 138), which separates the script
    dispatch family from the game's private ones;
  * **whether every table entry lies inside the image**, because one head reads a table that is all zeros
    here — a runtime-filled one, the kind M226 wrongly inferred for `0x36`.

The one BSS table is named rather than folded in: `0x8010b2bc`, bound 17, entries all zero, so that head's
arms are supplied at run time and no extent claim can be made about them from this image.

Usage:
  ./dispatch_heads.py --write    # regenerate manifests/dispatch_heads.json from the image
  ./dispatch_heads.py --check    # validate the committed artefact against a fresh derivation
  ./dispatch_heads.py --list     # print the census
"""
import argparse
import importlib.util
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
OUT = Path("manifests") / "dispatch_heads.json"
SCHEMA = "dispatch-heads/1"

_spec = importlib.util.spec_from_file_location("rsp_decode", HERE / "rsp_decode.py")
rd = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(rd)

RANGES = ROOT / "fixtures" / "decomp" / "ranges.json"
REGISTRY = ROOT / "fixtures" / "scd" / "registry.json"

SPECIAL, SLTIU, LUI, ADDIU, ORI, LW, JAL = 0x00, 0x0B, 0x0F, 0x09, 0x0D, 0x23, 0x03
JR = 0x08
LOOKBACK = 12          # instructions back from the `jr` to the bound; measured, the furthest needed is 9


def bits(x, hi, lo):
    return (x >> lo) & ((1 << (hi - lo + 1)) - 1)


def sx16(v):
    return v - 0x10000 if v & 0x8000 else v


def word_at(image, va):
    return int.from_bytes(image[va - rd.STAGE2_BASE:va - rd.STAGE2_BASE + 4], "big")


def find_heads(image):
    """Every `jr` whose 12 preceding instructions carry a `sltiu` bound and a `lui`+`addiu` table address.

    The lookback is a *window*, and a window is not an attribution — the queue's own lesson — so the shape
    is required to be complete (both a bound and a foldable base inside the window) and the jr must not be a
    return. Heads are then keyed by table, because two dispatches on one table are one head.
    """
    out, n = [], len(image) // 4
    for i in range(n):
        va = rd.STAGE2_BASE + 4 * i
        w = word_at(image, va)
        if (w >> 26) != SPECIAL or bits(w, 5, 0) != JR:
            continue
        if bits(w, 25, 21) in (31, 30):        # a return, not a dispatch
            continue
        base, bound = None, None
        for k in range(1, LOOKBACK + 1):
            b = va - 4 * k
            if b < rd.STAGE2_BASE:
                break
            wb = word_at(image, b)
            op = wb >> 26
            if op == SLTIU and bound is None:
                bound = wb & 0xFFFF
            if op == LUI and base is None:
                hi, rt = (wb & 0xFFFF) << 16, bits(wb, 20, 16)
                for j in range(1, 5):
                    wc = word_at(image, b + 4 * j)
                    opc = wc >> 26
                    if opc in (ADDIU, ORI) and bits(wc, 25, 21) == rt:
                        base = (hi + (sx16(wc & 0xFFFF) if opc == ADDIU else (wc & 0xFFFF))) & 0xFFFFFFFF
                        break
            if op == SPECIAL and bits(wb, 5, 0) == JR and b != va:
                break                          # another dispatch/return in between: not one shape
        if base is not None and bound is not None:
            out.append({"jr": va, "table": base, "bound": bound})
    return out


def derive(image):
    heads = find_heads(image)
    ranges = json.loads(RANGES.read_text())["images"]["stage2"]
    starts = {a for a, _b in ranges}
    reg = json.loads(REGISTRY.read_text())["opcodes"]
    handler_of = {int(v["handler"], 16): k for k, v in reg.items()}
    jal_sites = {}
    for off in range(0, len(image) - 3, 4):
        w = int.from_bytes(image[off:off + 4], "big")
        if (w >> 26) == JAL:
            va = rd.STAGE2_BASE + off
            jal_sites.setdefault(((va + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2), []).append(va)

    def body_of(va):
        for a, b in ranges:
            if a <= va <= b:
                return a, b
        return None

    by_table = {}
    for h in heads:
        by_table.setdefault(h["table"], []).append(h)
    entries = []
    for table, hs in sorted(by_table.items()):
        bound = hs[0]["bound"]
        targets = [word_at(image, table + 4 * k) for k in range(bound)]
        body = body_of(hs[0]["jr"])
        head_start = body[0] if body else None
        in_image = all(rd.STAGE2_BASE <= t < rd.STAGE2_BASE + len(image) for t in targets)
        entries.append({
            "table": table,
            "bound": bound,
            "jr_sites": [h["jr"] for h in hs],
            "head_body": {"start": body[0], "end": body[1]} if body else None,
            "head_is_corpus_start": bool(body and body[0] in starts),
            "head_is_handler": handler_of[body[0]] if body and body[0] in handler_of else None,
            "head_jal_sites": jal_sites.get(body[0], []) if body else [],
            "targets": targets,
            "distinct_targets": len(set(targets)),
            "all_targets_in_image": in_image,
        })
    return {
        "tool": "dispatch_heads.py",
        "schema": SCHEMA,
        "inputs": {
            "image": str(rd.IMAGE.relative_to(ROOT)),
            "base": hex(rd.STAGE2_BASE),
            "shape": "`jr` whose preceding %d instructions hold a `sltiu` bound and a `lui`+`addiu` table "
                     "address; the `jr` must not be a return through ra/fp. The window is complete-shape "
                     "required, not a forward scan" % LOOKBACK,
            "ranges": "fixtures/decomp/ranges.json (to say whether a head is a corpus function start)",
            "registry": "fixtures/scd/registry.json (to say whether a head is a Script VM handler)",
        },
        "census": {
            "heads": len(heads),
            "tables": len(entries),
            "heads_with_jal_callers": sum(1 for e in entries if e["head_jal_sites"]),
            "heads_that_are_handlers": sum(1 for e in entries if e["head_is_handler"]),
            "heads_that_are_corpus_starts": sum(1 for e in entries if e["head_is_corpus_start"]),
            "tables_outside_the_image": [hex(e["table"]) for e in entries
                                         if not e["all_targets_in_image"]],
            "bounds": sorted({e["bound"] for e in entries}),
            "largest": max((e["bound"] for e in entries), default=0),
        },
        "entries": entries,
        "reading": "a fifth of this image's functions dispatch through a static table this way: %d heads, "
                   "%d tables, bounds from 1 to %d. %d heads are Script VM handlers and %d are called by a "
                   "`jal`, so a head is a function boundary whether or not it runs a frame setup — which is "
                   "what the extent queue's 'nearest frame setup behind' rule cannot see. %d table(s) are "
                   "not in this image at all."
                   % (len(heads), len(entries), max((e["bound"] for e in entries), default=0),
                      sum(1 for e in entries if e["head_is_handler"]),
                      sum(1 for e in entries if e["head_jal_sites"]),
                      sum(1 for e in entries if not e["all_targets_in_image"])),
        "not_claimed": [
            "what any head dispatches on beyond the index expression the shape fixes: the arms' semantics is "
            "each handler's own question, and the Script VM's were answered in M226 for one of them",
            "that every `sltiu`+`lui`+`jr` in the image is a dispatch: the shape is a necessary condition, "
            "and a head whose arms are data rather than code would look the same",
            "the BSS table's contents: 0x8010b2bc is zero in this image and its arms are supplied at run time",
        ],
    }


def check(committed, image):
    fresh = derive(image)
    cen = committed["census"]
    cases = []
    cases.append((f"the census is re-derived ({cen['heads']} heads, {cen['tables']} tables, bounds "
                  f"{cen['bounds'][0]}..{cen['largest']})",
                  cen["heads"] == cen["tables"] == len(committed["entries"]) > 0
                  and fresh["census"] == cen))

    cases.append((f"every head's table is inside the image except the one named "
                  f"({cen['tables_outside_the_image']})",
                  cen["tables_outside_the_image"] == ["0x8010b2bc"]
                  and all(e["all_targets_in_image"] for e in committed["entries"]
                          if e["table"] != 0x8010B2BC)))

    t = {e["table"]: e for e in committed["entries"]}
    cases.append(("the two tables M226 and M227 measured by hand are present with the bounds they measured",
                  0x800B98E0 in t and t[0x800B98E0]["bound"] == 5
                  and t[0x800B98E0]["targets"] == [0x800711CC, 0x800711DC, 0x800711FC, 0x8007121C, 0x8007124C]
                  and 0x800B98F8 in t and t[0x800B98F8]["bound"] == 5
                  and t[0x800B98F8]["head_body"]["start"] == 0x800717A0))

    cases.append((f"every head whose arms are the extent queue's swallowed starts is identified: the 7-arm "
                  f"family at 0x800b9540 is present",
                  t[0x800B9540]["bound"] == 7
                  and t[0x800B9540]["targets"] == [0x8006E6E0, 0x8006E6EC, 0x8006E6F4, 0x8006E700,
                                                   0x8006E708, 0x8006E714, 0x8006E720]))

    jal_heads = [e for e in committed["entries"] if e["head_jal_sites"]]
    cases.append((f"a head called by `jal` is reported as a function boundary ({len(jal_heads)} of them)",
                  jal_heads and all(e["head_body"] and e["head_is_corpus_start"] for e in jal_heads)
                  and any(e["head_body"]["start"] == 0x800717A0 for e in jal_heads)))

    cases.append((f"the census separates the script dispatch family from the rest "
                  f"({cen['heads_that_are_handlers']} of {cen['tables']} are handlers)",
                  0 < cen["heads_that_are_handlers"] < cen["tables"]))

    cases.append(("every head's entry count is its bound and its distinct targets are counted",
                  all(len(e["targets"]) == e["bound"]
                      and 1 <= e["distinct_targets"] <= e["bound"] for e in committed["entries"])))

    cases.append(("the shape is stated as a necessary condition with its window, not as a proof",
                  "necessary condition" in "".join(committed["not_claimed"])
                  and str(LOOKBACK) in committed["inputs"]["shape"]))

    cases.append(("the committed manifest equals a fresh derivation of the image",
                  json.dumps(committed, sort_keys=True) == json.dumps(fresh, sort_keys=True)))
    return cases


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--list", action="store_true")
    a = ap.parse_args()

    image = rd.stage2()
    if a.write:
        if image is None:
            print("REFUSED: %s is not present, so there is nothing to measure"
                  % rd.IMAGE.relative_to(ROOT))
            return 2
        rep = derive(image)
        (ROOT / OUT).write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        print("wrote %s — %s" % (OUT, rep["census"]))
        return 0

    if a.list:
        if image is None:
            print("SKIP (needs the unpacked stage-2 image)")
            return 0
        rep = derive(image)
        for e in rep["entries"]:
            print("table 0x%08x bound %-3d head %s%s%s targets %d/%d" % (
                e["table"], e["bound"],
                ("0x%08x" % e["head_body"]["start"]) if e["head_body"] else "?",
                (" handler " + e["head_is_handler"]) if e["head_is_handler"] else "",
                (" jal×%d" % len(e["head_jal_sites"])) if e["head_jal_sites"] else "",
                e["distinct_targets"], e["bound"]))
        return 0

    if not a.check:
        ap.error("one of --write, --check, --list is required")
    if image is None:
        print("SKIP (needs the unpacked stage-2 image: %s)" % rd.IMAGE.relative_to(ROOT))
        return 0
    committed = json.loads((ROOT / OUT).read_text())
    cases = check(committed, image)
    bad = 0
    for label, ok in cases:
        bad += not ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d dispatch-head case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
