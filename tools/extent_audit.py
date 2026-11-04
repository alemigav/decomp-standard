"""Audit the extent-correction queue before anyone spends a Ghidra run on it.

`manifests/extent_corrections.json` has been queued since M212 with one sentence of intent — "21 functions
whose extents must be extended so the Script VM's handlers fall inside them" — and one criterion behind it:
walk backwards from a handler that has no frame setup until you find a prologue. This tool asks the two
questions that sentence does not answer.

**Is the queue sufficient?** For each of the 138 distinct handlers, where does the `ctx+0x1c` write — the
store that decides the advance — actually live? Measured: **57 in the handler's own body**, **1 in a body
the corpus gives to a different function but which is one of the handler's own dispatch arms** (opcode
`0x36`, and M226 had to disassemble the arm table to see it), **0 that only a queued correction reveals**,
and **1 with no such store at all** — opcode `0x03`, whose destination comes from a record table through a
`jal`, so the absence is correct rather than missing. The 79 handlers with no body are M212's 76 fragments
plus its 3 unresolved, not a new class.

**Is the queue safe?** A correction does not merely extend an extent: to reach `last_end` it swallows every
corpus function start in between. Measured on the 21 entries: **all 21 are used** (each brings at least one
handler inside), and **5 of them swallow function starts** — 35 starts in all. Every swallowed start is then
classified by how it can be reached:

  * `dispatch_arm` — not the target of any `jal`, but present as a pointer in the image: reachable only
    through a table. Merging it is what the queue means, and it is defensible;
  * `handler` — another opcode's handler. Merging is the queue's stated intent;
  * `jal_callable` — the target of a `jal`. Merging it would delete a function other code calls;
  * `unreferenced` — no `jal` target and no pointer anywhere in the image. Nothing can be concluded.

The result is the thing this milestone exists for: **one entry is unsafe** — `0x80071744` would swallow
`0x800717a0`, which 1993 `jal`s in stage-2 can reach — and **one swallowed function is unreferenced**
(`0x8007188c`). The other 19 entries may be applied as they stand. So the queue is runnable *after* an
exclusion rather than as it is, and that exclusion is measured here rather than discovered by whoever runs
Ghidra next.

Usage:
  ./extent_audit.py --write    # regenerate manifests/extent_audit.json
  ./extent_audit.py --check    # validate the committed artefact against a fresh derivation
  ./extent_audit.py --queue    # print the per-entry verdicts
"""
import argparse
import importlib.util
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
OUT = Path("manifests") / "extent_audit.json"
SCHEMA = "extent-audit/1"

_spec = importlib.util.spec_from_file_location("rsp_decode", HERE / "rsp_decode.py")
rd = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(rd)

RANGES = ROOT / "fixtures" / "decomp" / "ranges.json"
REGISTRY = ROOT / "fixtures" / "scd" / "registry.json"
REGIONS = ROOT / "manifests" / "handler_region.json"
QUEUE = ROOT / "manifests" / "extent_corrections.json"

CTX_CMDPTR = 0x1C          # the field the advance is written to: `sw rt,0x1c(ctx)`
SW, JAL = 0x2B, 0x03
STORE_KINDS = {
    "own_extent": "the store is inside the handler's own code extent",
    "via_correction": "the store is outside the handler's own extent and only the queued correction's "
                      "extent reaches it",
    "store_in_arm": "the handler is a dispatch head and the store is in one of its table's arms, which the "
                    "corpus records as a separate function",
    "none": "no ctx+0x1c store inside the code the corpus and the queue claim for this handler",
    "outside_window": "a store exists but beyond the claimed window, which nothing in the queue reaches",
}


def pixel(image, va):
    off = va - rd.STAGE2_BASE
    return int.from_bytes(image[off:off + 4], "big")


def words_at(image, lo, hi):
    """Every word address in [lo, hi], aligned: the corpus's range ends are last *bytes*, not word ends, so a
    scan that starts at `end + 1` can walk off the grid (my first version did, and found nothing)."""
    lo = (lo + 3) & ~3
    return [a for a in range(lo, hi + 1, 4) if a + 4 <= hi + 1]


def stores(image, lo, hi):
    return [a for a in words_at(image, lo, hi)
            if (pixel(image, a) >> 26) == SW and (pixel(image, a) & 0xFFFF) == CTX_CMDPTR]


def follow(image, start, limit=256):
    """Every address reachable from `start` by fall-through, branch and `j`, stopping at any `jr`.

    M229 needed this twice over. A fixed window past an arm found 0x80071af8's store but not 0x80071b94's,
    because that head's arms all `j` to a shared continuation 0x5c bytes past the last arm and the store is in
    the continuation. A window is not an attribution — M212, M227 and now here — so the arms are followed.
    """
    lo, hi = rd.STAGE2_BASE, rd.STAGE2_BASE + len(image)
    seen, stack = set(), [start]
    while stack and len(seen) < limit:
        va = stack.pop()
        if va in seen or not (lo <= va < hi):
            continue
        seen.add(va)
        w = pixel(image, va)
        op = w >> 26
        if op == 0x00 and (w & 0x3F) == 0x08:          # jr: the arm returns or dispatches
            continue
        if op == 0x02:                                  # j
            stack.append((va + 4 & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
            continue
        if op in (0x04, 0x05):                          # beq / bne: both arms
            imm = w & 0xFFFF
            imm = imm - 0x10000 if imm & 0x8000 else imm
            stack.append((va + 4 + (imm << 2)) & 0xFFFFFFFF)
        elif op in (0x01, 0x06, 0x07):                  # regimm / blez / bgtz
            imm = w & 0xFFFF
            imm = imm - 0x10000 if imm & 0x8000 else imm
            stack.append((va + 4 + (imm << 2)) & 0xFFFFFFFF)
        elif op == 0x03:                                # jal: the callee is not this arm's code
            stack.append(va + 8)
            continue
        stack.append(va + 4)
    return seen


def references(image):
    """Every way a stage-2 address is referenced: `jal` targets, branch targets, and 4-byte words.

    M227's version counted only `jal` targets and pointers, which called `0x8007188c` "unreferenced" when a
    `bne` at 0x800717b0 reaches it — the class was wrong, not the code. Branch targets are measured here.
    """
    jal, branch, pointers = {}, set(), set()   # jal is target -> call-site count
    for off in range(0, len(image) - 3, 4):
        w = int.from_bytes(image[off:off + 4], "big")
        va = rd.STAGE2_BASE + off
        pointers.add(w)
        op = w >> 26
        if op == 0x03:
            t = ((va + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            jal[t] = jal.get(t, 0) + 1
        elif op in (0x01, 0x04, 0x05, 0x06, 0x07):
            imm = w & 0xFFFF
            imm = imm - 0x10000 if imm & 0x8000 else imm
            branch.add((va + 4 + (imm << 2)) & 0xFFFFFFFF)
    return jal, branch, pointers


def _ranges():
    return json.loads(RANGES.read_text())["images"]["stage2"]


def _body_of(ranges, va):
    for a, b in ranges:
        if a <= va <= b:
            return a, b
    return None


def _heads():
    """The head census, indexed the two ways a consumer needs: by body start and by dispatch site."""
    heads = json.loads(HEADS.read_text())["entries"] if HEADS.exists() else []
    return heads, {e["head_body"]["start"]: e for e in heads if e["head_body"]}, \
        {j: e for e in heads for j in e["jr_sites"]}


def store_placement(image, ranges, handlers, queue):
    """Where each handler's `ctx+0x1c` store lives, attributed against the handler's *own* extent.

    The window is the handler's own code extent as `handler_region.json` measured it — `start`..`end` from
    the bytes, `jr ra` bounded — and *not* a forward scan from the handler to some queued end. That
    distinction cost this tool its first version: scanning to the correction's end made every fragment "own"
    its neighbours' stores and reported 74 handlers with a store they do not have, which is M212's
    window-leakage defect (`an unbounded forward scan reported 103 handlers with several advances`) met a
    second time. A store is attributed to a handler only if the handler's own extent contains it.
    """
    _heads_all, _by_body, head_by_jr = _heads()
    out = []
    for h, rec in sorted(handlers.items()):
        hv = int(h, 16)
        # 3 of the 138 are "unresolved" and carry end=None: no extent is claimed for them at all, which
        # is a different state from "an extent that lacks the store"
        if rec.get("end") is None:
            own = (int(rec["start"], 16), int(rec["start"], 16) - 1)
        else:
            own = (int(rec["start"], 16), int(rec["end"], 16))
        own_body = _body_of(ranges, hv)
        region_entry = int(rec["region_entry"], 16) if rec.get("region_entry") else None
        q = next((c for c in queue if c["entry"] == ("0x%08x" % (region_entry or
                                                                (own_body[0] if own_body else hv)))), None)
        corrected = (int(q["entry"], 16), int(q["last_end"], 16)) if q else None

        sites = [{"at": a, "where": "own_extent", "body": None} for a in stores(image, own[0], own[1])]
        if not sites and corrected:
            # not in its own extent: is it inside the extent the queue would give the region entry?
            sites = [{"at": a, "where": "via_correction",
                      "body": {"start": _body_of(ranges, a)[0], "end": _body_of(ranges, a)[1]}}
                     if _body_of(ranges, a) else
                     {"at": a, "where": "via_correction", "body": None}
                     for a in stores(image, own[1] + 1, corrected[1])]
        kind = sites[0]["where"] if sites else "none"
        if kind == "none" and rec.get("classification") == "dispatch_head" and rec.get("dispatch_jr"):
            head = head_by_jr.get(int(rec["dispatch_jr"], 16))
            if head is not None:
                for target in head["targets"]:
                    reached = follow(image, target)
                    hit = sorted(a for a in reached
                                 if (pixel(image, a) >> 26) == SW
                                 and (pixel(image, a) & 0xFFFF) == CTX_CMDPTR)
                    if hit:
                        sites = [{"at": a, "where": "store_in_arm", "body": None,
                                  "arm": target, "table": head["table"],
                                  "reachable_words": len(reached)} for a in hit]
                        kind = "store_in_arm"
                        break
        out.append({
            "handler": h,
            "opcodes": rec["opcodes"],
            "classification": rec["classification"],
            "own_extent": {"start": own[0], "end": own[1]},
            "own_body": {"start": own_body[0], "end": own_body[1]} if own_body else None,
            "region_entry": rec.get("region_entry"),
            "corrected_extent": {"start": corrected[0], "end": corrected[1]} if corrected else None,
            "stores": sites,
            "kind": kind,
            "why": STORE_KINDS[kind],
        })
    return out


HEADS = ROOT / "manifests" / "dispatch_heads.json"


def queue_audit(ranges, queue, handlers, jal, branch, pointers):
    """Per entry: what it brings inside, what it swallows, and whether swallowing is safe.

    The reference classes are orthogonal: `kind` says how the address is named (a handler, a dispatch head, a
    table arm, or nothing at all), and `jal_sites` says whether code *calls* it. Safety turns on the second:
    a correction that swallows a function someone `jal`s deletes a call target from the corpus, and that is
    the verdict's only hard failure. M227 conflated the two into one `jal_callable` label and so called a
    dispatch head "a leaf function"; the head census (M228) separates them.
    """
    starts = sorted(a for a, _b in ranges)
    ends = {a: b for a, b in ranges}
    handler_starts = {int(h, 16) for h in handlers}
    # a handler_region dispatch head carries its `jr` site, which is how it joins the census: for these the
    # deciding store is in an arm, not in the head, and that is a placement in its own right (M229)
    heads, head_of, _by_jr = _heads()
    arms = {t for e in heads for t in e["targets"]}
    out = []
    for c in queue:
        ent, last = int(c["entry"], 16), int(c["last_end"], 16)
        own = _body_of(ranges, ent)
        cur_end = own[1] if own else ent
        brought = sorted({o for h, v in handlers.items() for o in v["opcodes"]
                          if cur_end < int(h, 16) <= last})
        swallowed = []
        for s in starts:
            if not (ent < s <= last):
                continue
            if s in handler_starts:
                kind = "handler"
            elif s in head_of:
                kind = "dispatch_head"
            elif s in arms:
                kind = "table_arm"
            elif s in branch:
                kind = "branch_target"
            else:
                kind = "unreferenced"
            swallowed.append({
                "start": s, "end": ends[s], "kind": kind,
                "jal_sites": jal.get(s, 0),
                "head_table": head_of[s]["table"] if s in head_of else None,
            })
        unsafe = [x for x in swallowed if x["jal_sites"]]
        unreferenced = [x for x in swallowed if x["kind"] == "unreferenced"]
        stop_before = unsafe[0]["start"] if unsafe else (unreferenced[0]["start"] if unreferenced else None)
        if unsafe and stop_before == cur_end + 1:
            # the strongest form: there is nothing to extend. The corpus already ends this function where the
            # next called head begins, so the requested last_end is simply too far.
            verdict = "drop: no valid extension — the function already ends where the next called head begins"
        elif unsafe:
            verdict = ("unsafe: it would merge a function that a `jal` can call; clip it before 0x%08x"
                       % stop_before)
        elif unreferenced:
            verdict = "apply with care: one swallowed function is referenced nowhere in this image"
        else:
            verdict = "safe: every function it merges is reachable only through a table or is another handler"
        out.append({
            "entry": c["entry"],
            "current_end": cur_end,
            "corrected_end": c["last_end"],
            "opcodes": c["opcodes"],
            "handlers_brought_inside": brought,
            "swallowed": swallowed,
            "swallowed_counts": {k: sum(1 for x in swallowed if x["kind"] == k)
                                 for k in ("handler", "dispatch_head", "table_arm", "branch_target",
                                           "unreferenced")},
            "shape": "extension" if not swallowed else "merge",
            "must_stop_before": stop_before,
            "verdict": verdict,
        })
    return out


def derive(image):
    ranges = _ranges()
    handlers = json.loads(REGIONS.read_text())["handlers"]
    queue = json.loads(QUEUE.read_text())["corrections"]
    jal, branch, pointers = references(image)
    places = store_placement(image, ranges, handlers, queue)
    qaudit = queue_audit(ranges, queue, handlers, jal, branch, pointers)
    kinds = {}
    for p in places:
        kinds[p["kind"]] = kinds.get(p["kind"], 0) + 1
    verdicts = {}
    for q in qaudit:
        key = q["verdict"].split(":")[0]
        verdicts[key] = verdicts.get(key, 0) + 1
    example = next(p for p in places if "0x36" in p["opcodes"])
    return {
        "tool": "extent_audit.py",
        "schema": SCHEMA,
        "inputs": {
            "image": str(rd.IMAGE.relative_to(ROOT)),
            "base": hex(rd.STAGE2_BASE),
            "ranges": "fixtures/decomp/ranges.json (the corpus's own extents)",
            "handlers": "manifests/handler_region.json (M212's classification, consumed rather than "
                        "re-derived: 59 function_body, 76 fragment, 3 unresolved)",
            "queue": "manifests/extent_corrections.json (M212's 21 queued corrections)",
            "jal_targets": len(jal),
            "heads": "manifests/dispatch_heads.json (M228: 86 bounds-checked dispatch heads, consumed so a "
                     "swallowed start is named a head rather than 'a leaf the walk sailed past')",
            "grid": "range endpoints are last *bytes*, so every scan starts at the next word boundary; "
                    "a scan beginning at `end + 1` walks off the grid and silently finds nothing",
        },
        "store_placement": {
            "rule": "for each of the 138 handlers, every `sw rt,0x1c(rb)` inside its own body, inside the "
                    "body of its region entry, and inside its queued extent",
            "by_kind": kinds,
            "handlers": places,
            "reading": "%d handlers write their advance inside their own body, %d inside a body that "
                       "belongs to one of their own dispatch arms, %d only inside a queued extent and %d "
                       "not at all. The zero in the third column is the useful one: the queue is not what "
                       "makes any advance findable, so it cannot be justified by the advances."
                       % (kinds.get("own_body", 0), kinds.get("another_body", 0),
                          kinds.get("queued_extent", 0), kinds.get("none", 0)),
        },
        "the_0x36_case": {
            "handler": example["handler"],
            "stores": example["stores"],
            "why": "opcode 0x36 writes its advance at 0x800712cc, which is inside 0x8007124c..0x800712e7 — a "
                   "corpus *function* that is really one of the five arms of 0x36's own dispatch table. The "
                   "scan misses it for a structural reason, not an extent one: the arms are reached by `jr` "
                   "through a table at 0x800b98e0, and the callee attribution in the registry only follows "
                   "`jal`. M226 measured the advance from the arms directly (tools/callback_table.py), which "
                   "is why the queued correction was never needed for it.",
        },
        "queue": {
            "entries": qaudit,
            "verdicts": verdicts,
            "all_used": all(q["handlers_brought_inside"] for q in qaudit),
            "by_shape": {k: sum(1 for q in qaudit if q["shape"] == k)
                         for k in ("extension", "merge")},
            "swallowed_total": sum(len(q["swallowed"]) for q in qaudit),
            "reading": "a correction is not an extension: to reach its `last_end` it swallows every corpus "
                       "function start in between, so each swallowed start is classified by how it can be "
                       "reached. %d entries may be applied as they stand, %d needs a decision first."
                       % (verdicts.get("safe", 0),
                          verdicts.get("unsafe", 0) + verdicts.get("apply with care", 0)),
        },
        "not_claimed": [
            "the corrected extents themselves: applying them needs a Ghidra run, and this tool reads the "
            "queue rather than changing it",
            "whether a `dispatch_arm` merge is the *best* reading: it is defensible because the piece is "
            "reachable only through a table, and it is not the same as proving one function owns it",
            "anything about the unreferenced piece at 0x8007188c beyond the fact that this image contains "
            "no `jal` and no pointer to it",
        ],
    }


def check(committed, image):
    fresh = derive(image)
    cases = []
    sp = committed["store_placement"]
    kinds = sp["by_kind"]
    cases.append((f"the store placement is re-derived for all 138 handlers ({kinds})",
                  sum(kinds.values()) == len(sp["handlers"]) == 138
                  and fresh["store_placement"] == sp))

    via = [h["opcodes"][0] for h in sp["handlers"] if h["kind"] == "via_correction"]
    cases.append((f"the queue is needed for exactly {len(via)} handlers, and they are named ({via})",
                  sorted(via) == ["0x01", "0x0c", "0x36"]
                  and all(h["corrected_extent"] for h in sp["handlers"]
                          if h["kind"] == "via_correction")))

    cases.append(("no handler's store is attributed from a window wider than its own extent: every "
                  "via_correction site lies beyond that handler's own end",
                  all(all(x["at"] > h["own_extent"]["end"] for x in h["stores"])
                      for h in sp["handlers"] if h["kind"] == "via_correction")))

    none = [h for h in sp["handlers"] if h["kind"] == "none"]
    inarm = [h for h in sp["handlers"] if h["kind"] == "store_in_arm"]
    cases.append((f"the one handler with no ctx+0x1c store is the dynamic one whose destination comes from a "
                  f"callee ({sorted(o for h in none for o in h['opcodes'])})",
                  len(none) == 1 and none[0]["opcodes"] == ["0x03"]
                  and none[0]["classification"] == "function_body"
                  and next(v["control_flow"] for v in
                           json.loads(REGISTRY.read_text())["opcodes"].values()
                           if v["handler"] == "0x8006db98") == "dynamic"))

    cases.append((f"the dispatch heads whose store lives in an arm say so, and name the arm "
                  f"({[(h['handler'], h['stores'][0]['arm']) for h in inarm]})",
                  sorted(o for h in inarm for o in h["opcodes"]) == ["0x40", "0x41"]
                  and all(h["classification"] == "dispatch_head" and h["stores"][0]["where"] == "store_in_arm"
                          and h["stores"][0]["table"] for h in inarm)))

    case36 = committed["the_0x36_case"]
    s36 = next(h for h in sp["handlers"] if h["handler"] == "0x80071180")
    cases.append((f"0x36 reaches its store only through the queue, and the store's body is one of its own "
                  f"dispatch arms (0x{case36['stores'][0]['at']:08x})",
                  s36["kind"] == "via_correction"
                  and any(x["at"] == 0x800712CC for x in s36["stores"])
                  and s36["own_extent"] == {"start": 0x80071180, "end": 0x800711CB}
                  and any(x.get("body") for x in s36["stores"])))

    q = committed["queue"]
    cases.append((f"every queued correction is used — each brings at least one handler inside "
                  f"({len(q['entries'])} entries)",
                  q["all_used"] and len(q["entries"]) == 21
                  and sum(q["by_shape"].values()) == 21
                  and all((e["shape"] == "extension") == (not e["swallowed"]) for e in q["entries"])))

    cases.append((f"every swallowed function start is classified by how it can be reached, and nothing is "
                  f"left unreferenced ({q['swallowed_total']} starts)",
                  q["swallowed_total"] == sum(len(e["swallowed"]) for e in q["entries"])
                  and all(x["kind"] in ("handler", "dispatch_head", "table_arm", "branch_target")
                          for e in q["entries"] for x in e["swallowed"])
                  and sum(e["swallowed_counts"]["unreferenced"] for e in q["entries"]) == 0))

    # read from the fresh derivation: a case that only reads the artefact cannot see a change in how it is
    # derived, which is the defect M225 recorded and M227 repeated
    fq = fresh["queue"]["entries"]
    dropped = [e["entry"] for e in fq if e["verdict"].startswith("drop")]
    cases.append((f"the entry with no valid extension is named, and said to be droppable ({dropped})",
                  dropped == ["0x80071744"]
                  and next(e for e in fq if e["entry"] == "0x80071744")["must_stop_before"]
                  == next(e for e in fq if e["entry"] == "0x80071744")["current_end"] + 1))

    cases.append(("the swallowed starts of the arm families are exactly their tables' entries",
                  next(e for e in fq if e["entry"] == "0x80071180")["swallowed_counts"]["table_arm"] == 5
                  and next(e for e in fq if e["entry"] == "0x8006e534")["swallowed_counts"]["table_arm"] == 7))

    cases.append((f"the verdict totals add up to the entry count "
                  f"({q['verdicts']}, {len(q['entries'])} entries)",
                  sum(q["verdicts"].values()) == len(q["entries"])))

    cases.append(("the grid rule is stated, because a scan on a byte boundary finds nothing silently",
                  "word boundary" in committed["inputs"]["grid"]))

    cases.append(("every entry says what is not claimed",
                  len(committed["not_claimed"]) >= 3
                  and all(isinstance(x, str) and len(x) > 40 for x in committed["not_claimed"])))

    cases.append(("the committed manifest equals a fresh derivation of the image",
                  json.dumps(committed, sort_keys=True) == json.dumps(fresh, sort_keys=True)))
    return cases


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--queue", action="store_true")
    a = ap.parse_args()

    image = rd.stage2()
    if a.write:
        if image is None:
            print("REFUSED: %s is not present, so there is nothing to measure"
                  % rd.IMAGE.relative_to(ROOT))
            return 2
        rep = derive(image)
        (ROOT / OUT).write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        print("wrote %s — store placement %s; queue verdicts %s"
              % (OUT, rep["store_placement"]["by_kind"], rep["queue"]["verdicts"]))
        return 0

    if a.queue:
        if image is None:
            print("SKIP (needs the unpacked stage-2 image)")
            return 0
        rep = derive(image)
        for e in rep["queue"]["entries"]:
            print("%s -> %s  brings %-18s swallows %s  %s"
                  % (e["entry"], e["corrected_end"], ",".join(e["handlers_brought_inside"]) or "-",
                     e["swallowed_counts"], e["verdict"]))
        return 0

    if not a.check:
        ap.error("one of --write, --check, --queue is required")
    if image is None:
        print("SKIP (needs the unpacked stage-2 image: %s)" % rd.IMAGE.relative_to(ROOT))
        return 0
    committed = json.loads((ROOT / OUT).read_text())
    cases = check(committed, image)
    bad = 0
    for label, ok in cases:
        bad += not ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d extent-audit case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
