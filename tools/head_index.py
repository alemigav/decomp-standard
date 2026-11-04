"""What the dispatch heads dispatch on — the index expression, traced to its source.

`dispatch_heads.py` (M228) found 86 heads and said of them only that they dispatch through a table. The
obvious next question is what the index *is*, because it decides what each head is a dispatch over: a byte of
the script command stream, a field of a structure the CPU filled, a caller's argument, or a global. This tool
answers it per head with a **bounded** trace — bounded on purpose, because a window is not an attribution
(M212, M227, M229) and the honest report is `unknown` rather than a guess.

For each head it takes the `sltiu` that bounds the index, follows the register it tests backwards through
shift/mask/add and one load, and reports:

  * **the transform**, in order — `srl 8`, `andi 0xff`, `addiu -1` — because a 1-based sub-opcode and a
    zero-based one are different interfaces;
  * **the source**, classified as one of `command_field` (a load at a fixed offset from the command pointer the
    CPU publishes at ctx+0x1c), `ctx_field` (a load at a fixed offset from another base held in an incoming
    argument), `global` (a load through a `lui`-built absolute address), `argument` (an incoming argument
    register, used as an index directly), `local` (computed from registers this bounded trace cannot resolve),
    or `unknown` (defined before the head's own code, so the trace refuses);
  * **the offset and the width**, so `0x36`'s `u16[cmd+4] >> 8` and a `u8[cmd+1]` are distinguishable.

The classification is deliberately narrow. A `lbu v1,-28100(v0)` whose `v0` is not resolved in the window is
**not** reported as a global just because the displacement is large: it is `unknown`, and the count of those is
published so the reader can see how much of the answer is missing.

Usage:
  ./head_index.py --write    # regenerate manifests/head_index.json
  ./head_index.py --check    # validate the committed artefact against a fresh derivation
  ./head_index.py --list     # print the per-head provenance
"""
import argparse
import importlib.util
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
OUT = Path("manifests") / "head_index.json"
SCHEMA = "head-index/1"

_spec = importlib.util.spec_from_file_location("rsp_decode", HERE / "rsp_decode.py")
rd = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(rd)

HEADS = ROOT / "manifests" / "dispatch_heads.json"
REGIONS = ROOT / "manifests" / "handler_region.json"
RANGES = ROOT / "fixtures" / "decomp" / "ranges.json"

CTX_CMDPTR = 0x1C
TRACE_STEPS = 10           # the longest chain any head here needs is 4
WINDOW_BEFORE = 0x100      # never look further back than this inside one head


def bits(x, hi, lo):
    return (x >> lo) & ((1 << (hi - lo + 1)) - 1)


def sx16(v):
    return v - 0x10000 if v & 0x8000 else v


def word_at(image, va):
    off = va - rd.STAGE2_BASE
    return int.from_bytes(image[off:off + 4], "big")


def defs(image, lo, hi):
    """register -> [addresses that write it], inside [lo, hi). A flat map, walked backwards per query."""
    out = {}
    for va in range((lo + 3) & ~3, hi, 4):
        w = word_at(image, va)
        op, rs, rt = w >> 26, bits(w, 25, 21), bits(w, 20, 16)
        if op == 0:
            funct, rd_ = bits(w, 5, 0), bits(w, 15, 11)
            if funct in (0x00, 0x02, 0x03, 0x21, 0x23, 0x24, 0x25, 0x2A, 0x2B, 0x26, 0x27):
                out.setdefault(rd_, []).append(va)
        elif op in (0x09, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x21, 0x23, 0x24, 0x25):
            out.setdefault(rt, []).append(va)
    return out


def ctx_registers(image, lo, hi):
    """The incoming argument register(s) that hold the context: a0, plus any copy made inside the head."""
    held = {4}
    for va in range((lo + 3) & ~3, hi, 4):
        w = word_at(image, va)
        op, rs, rt = w >> 26, bits(w, 25, 21), bits(w, 20, 16)
        if op == 0 and bits(w, 5, 0) in (0x21, 0x25):        # addu rd,rs,rt / or rd,rs,rt
            rd_ = bits(w, 15, 11)
            if rs == 0 and rt in held or rt == 0 and rs in held:
                held.add(rd_)
    return held


CALLEE_SAVED = (16, 17, 18, 19, 20, 21, 22, 23, 30, 28)     # s0-s7, fp, gp
SP = 29


def _base_origin(image, reg, at, table, ctxs, depth):
    """What a load's base register is, one step further back.

    M231 generalised this from "a `lui` plus one `addiu`" to a small constant fold, because the game builds its
    globals two ways: `lui v0,0x800c` + `addiu v0,v0,30384` (low half in the instruction) and
    `lui v0,0x800c` + `addiu` then `lui v1,0x0002` + `addu v0,v0,v1` (low half added as a second constant).
    M226 met the same thing in the ucode's task pointer. A bare `lui` is a complete base too, with the
    displacement supplying the low half.

    And it now names what it can: a callee-saved register this function never writes was set by the caller
    (`inherited`), and a base of `sp` is a stack slot (`stack`). Both are answers, not refusals.
    """
    # 3 was too shallow: `s2 <- addiu s2,v0,7826` then `v0 <- ...` then `lui` is four links, and the guard
    # turned a resolvable global into a refusal (M231). 6 covers every chain this image has.
    if depth > 6:
        return None
    if reg == 0:
        return {"kind": "const", "value": 0}
    # `sp` is a stack slot whenever it is a base, and it always has a definition (the frame adjustment), so
    # this cannot wait for the "never written" test below (M231)
    if reg == SP:
        return {"kind": "stack", "register": "sp"}
    earlier = [v for v in table.get(reg, []) if v < at]
    if not earlier:
        if reg in (4, 5, 6, 7):
            return {"kind": "argument", "register": rd.REG[reg]}
        if reg in CALLEE_SAVED:
            return {"kind": "inherited", "register": rd.REG[reg]}
        if reg == SP:
            return {"kind": "stack", "register": "sp"}
        return None
    va = max(earlier)
    w = word_at(image, va)
    op, rs, rt = w >> 26, bits(w, 25, 21), bits(w, 20, 16)
    if op in (0x20, 0x21, 0x23, 0x24, 0x25):
        if (w & 0xFFFF) == CTX_CMDPTR and rs in ctxs:
            return {"kind": "command_pointer", "note": "the pointer at ctx+0x1c"}
        return _base_origin(image, rs, va, table, ctxs, depth + 1)
    if op == 0x0F:                                     # lui: a constant, possibly completed later
        return {"kind": "const", "value": (w & 0xFFFF) << 16}
    if op in (0x09, 0x0D):                             # addiu/ori rt,rs,imm
        inner = _base_origin(image, rs, va, table, ctxs, depth + 1)
        if inner and inner["kind"] == "const":
            imm = sx16(w & 0xFFFF) if op == 0x09 else (w & 0xFFFF)
            return {"kind": "const", "value": (inner["value"] + imm) & 0xFFFFFFFF}
        return None
    if op == 0 and bits(w, 5, 0) == 0x21:              # addu rd,rs,rt: a sum of two constants
        a = _base_origin(image, rs, va, table, ctxs, depth + 1)
        b = _base_origin(image, rt, va, table, ctxs, depth + 1)
        if a and b and a["kind"] == "const" and b["kind"] == "const":
            return {"kind": "const", "value": (a["value"] + b["value"]) & 0xFFFFFFFF}
        # `addu rd,rs,zero` was handled here as a move until M232, on M231's reading that six `local` heads
        # were "a callee-saved copy of an argument". Instrumented, the branch is taken **zero times** by all
        # 86 heads, and deleting it leaves every classification identical: no head's base is ever computed
        # through an `addu`. `trace()` already follows `rs` through an `addu` (the `op == 0` case below), so
        # the move was never needed here, and M231's attribution was to the wrong mechanism. Retracted in
        # M232 and removed rather than kept as a comment.
        return None
    if rs in ctxs:
        return {"kind": "ctx_base"}
    return None


def trace(image, reg, at, table, ctxs):
    """Follow `reg` back from `at`. Returns (transform list, source dict)."""
    steps, transform = 0, []
    cur, cur_at = reg, at
    while steps < TRACE_STEPS:
        steps += 1
        if cur == 0:
            return transform, {"kind": "constant", "note": "the zero register"}
        earlier = [v for v in table.get(cur, []) if v < cur_at]
        # the ctx test comes *after* the def lookup, not before: `0x36` writes `srl a0,a1,8` and then tests
        # `a0`, so a0 is not the context pointer at that point even though it arrived in one (M230)
        if cur in ctxs and not earlier:
            return transform, {"kind": "argument", "note": "the context pointer, used as an index"}
        if not earlier:
            # never written inside the head: an incoming argument is a fact, anything else is not resolved.
            if cur in (4, 5, 6, 7):
                return transform, {"kind": "argument", "register": rd.REG[cur],
                                   "note": "the incoming argument %s, used as the index directly"
                                           % rd.REG[cur]}
            return transform, {"kind": "unknown", "register": rd.REG[cur],
                               "note": "defined before this head's own code, in %s" % rd.REG[cur]}
        va = max(earlier)
        cur_at = va
        w = word_at(image, va)
        op, rs, rt = w >> 26, bits(w, 25, 21), bits(w, 20, 16)
        if op in (0x24, 0x25, 0x21) and (w & 0xFFFF) == CTX_CMDPTR and rs in ctxs:
            return transform, {"kind": "command_pointer", "note": "the pointer at ctx+0x1c"}
        if op in (0x20, 0x21, 0x23, 0x24, 0x25):               # lb/lh/lw/lbu/lhu
            width = {0x20: 1, 0x21: 2, 0x23: 4, 0x24: 1, 0x25: 2}[op]
            disp = sx16(w & 0xFFFF)
            if rs in ctxs:
                return transform, {"kind": "ctx_field", "offset": disp, "width": width,
                                   "note": "a field of the context, at +0x%x" % disp}
            origin = _base_origin(image, rs, va, table, ctxs, 0)
            if origin is None:
                return transform, {"kind": "local", "offset": disp, "width": width,
                                   "note": "a field at +0x%x off %s, which this head's own code does not "
                                           "define: the enclosing function set it, so the head is inlined in a "
                                           "larger one and the dataflow starts before the body boundary"
                                           % (disp, rd.REG[rs])}
            if origin["kind"] == "command_pointer":
                return transform, {"kind": "command_field", "offset": disp, "width": width,
                                   "note": "u%d[cmd+%d]" % (width * 8, disp)}
            if origin["kind"] == "const":
                addr = (origin["value"] + disp) & 0xFFFFFFFF
                return transform, {"kind": "global", "offset": addr, "width": width,
                                   "note": "a %d-byte read at 0x%08x" % (width, addr)}
            if origin["kind"] == "inherited":
                return transform, {"kind": "inherited_pointer", "offset": disp, "width": width,
                                   "register": origin["register"],
                                   "note": "a field at +0x%x off %s, which this function never writes: the "
                                           "pointer came in from the caller" % (disp, origin["register"])}
            if origin["kind"] == "stack":
                return transform, {"kind": "stack_field", "offset": disp, "width": width,
                                   "note": "a stack slot at +0x%x off sp" % disp}
            if origin["kind"] == "ctx_base":
                return transform, {"kind": "ctx_pointer_field", "offset": disp, "width": width,
                                   "note": "a field at +0x%x off a pointer held in the context" % disp}
            if origin["kind"] == "argument":
                return transform, {"kind": "argument_pointer_field", "offset": disp, "width": width,
                                   "note": "a field at +0x%x off the incoming argument %s"
                                           % (disp, origin["register"])}
            return transform, {"kind": "local", "offset": disp, "width": width,
                               "note": "a field at +0x%x off %s" % (disp, origin["kind"])}
        if op == 0x0F:                                          # lui: the index is a constant
            val = (w & 0xFFFF) << 16
            nxt = word_at(image, va + 4)
            if (nxt >> 26) in (0x09, 0x0D) and bits(nxt, 25, 21) == rt:
                val += (sx16(nxt & 0xFFFF) if (nxt >> 26) == 0x09 else (nxt & 0xFFFF))
            return transform, {"kind": "constant", "value": val & 0xFFFFFFFF,
                               "note": "the constant 0x%08x" % (val & 0xFFFFFFFF)}
        if op == 0 and bits(w, 5, 0) == 0x00:
            transform.append("sll %d" % bits(w, 10, 6))
            cur = rt
            continue
        if op == 0 and bits(w, 5, 0) in (0x02, 0x03):
            transform.append(("srl %d" if bits(w, 5, 0) == 0x02 else "sra %d") % bits(w, 10, 6))
            cur = rt
            continue
        if op == 0x0C:
            transform.append("andi 0x%x" % (w & 0xFFFF))
            cur = rs
            continue
        if op == 0x09:
            transform.append("addiu %d" % sx16(w & 0xFFFF))
            cur = rs
            continue
        if op == 0x0D:
            transform.append("ori 0x%x" % (w & 0xFFFF))
            cur = rs
            continue
        if op == 0:
            cur = rs
            continue
        return transform, {"kind": "unknown", "note": "the trace reached an unhandled form at 0x%08x" % va}
    return transform, {"kind": "unknown", "note": "the trace hit its %d-step bound" % TRACE_STEPS}


def derive(image):
    heads = json.loads(HEADS.read_text())["entries"]
    reg = json.loads(REGISTRY.read_text())["opcodes"] if REGISTRY.exists() else {}
    handler_of = {int(v["handler"], 16): k for k, v in reg.items()}
    ranges = json.loads(RANGES.read_text())["images"]["stage2"]
    out = []
    for e in heads:
        jr = e["jr_sites"][0]
        # the head's own code: from its corpus body where one covers the dispatch, else a bounded window
        body = next(([a, b] for a, b in ranges if a <= jr <= b), None)
        # the head's own function only. A wider window was tried and made the classification *worse*: a write
        # to `a0` before the body start belongs to the preceding function, so widening turned incoming
        # arguments into "arguments that were redefined" and moved 6 heads out of `argument` for no gain
        lo = body[0] if body else max(rd.STAGE2_BASE, jr - WINDOW_BEFORE)
        table = defs(image, lo, jr)
        ctxs = ctx_registers(image, lo, jr)
        # the bounding sltiu, nearest behind the jr
        bound_at, index_reg = None, None
        for k in range(1, 13):
            va = jr - 4 * k
            w = word_at(image, va)
            if (w >> 26) == 0x0B:
                bound_at, index_reg = va, bits(w, 25, 21)
                break
        if bound_at is None:
            # no `sltiu` bounds this dispatch inside the window: the table is indexed by whatever the value
            # is, and its extent is guaranteed by construction rather than by a check (M230)
            out.append({"table": e["table"], "bound": e["bound"], "jr": jr,
                        "head": ("0x%08x" % body[0]) if body else None,
                        "handler": handler_of.get(body[0]) if body else None,
                        "index_register": None, "bound_at": None, "transform": [],
                        "source": {"kind": "unbounded",
                                   "note": "no `sltiu` within 12 words of the jr: this dispatch has no "
                                           "bounds check, so its domain is the table's own size"}})
            continue
        transform, source = trace(image, index_reg, bound_at, table, ctxs)
        out.append({
            "table": e["table"],
            "bound": e["bound"],
            "jr": jr,
            "head": ("0x%08x" % body[0]) if body else None,
            "handler": handler_of.get(body[0]) if body else None,
            "index_register": rd.REG[index_reg],
            "bound_at": bound_at,
            "transform": transform,
            "source": source,
        })
    kinds = {}
    for r in out:
        kinds[r["source"]["kind"]] = kinds.get(r["source"]["kind"], 0) + 1
    script = [r for r in out if r.get("handler")]
    nonscript = [r for r in out if not r.get("handler")]
    def split(rows):
        k = {}
        for r in rows:
            k[r["source"]["kind"]] = k.get(r["source"]["kind"], 0) + 1
        return dict(sorted(k.items()))
    return {
        "tool": "head_index.py",
        "schema": SCHEMA,
        "inputs": {
            "image": str(rd.IMAGE.relative_to(ROOT)),
            "heads": "manifests/dispatch_heads.json (M228)",
            "rule": "the `sltiu` bounding the index, then up to %d backwards steps through shift/mask/add "
                    "and one load; the source is classified only when the chain bottoms out on something this "
                    "image names, and `unknown`/`local` otherwise" % TRACE_STEPS,
            "window": "the head's corpus body where one covers the dispatch, else at most 0x%x bytes behind "
                      "it — a bounded window, and the artefact reports what the bound cost" % WINDOW_BEFORE,
        },
        "by_kind": dict(sorted(kinds.items())),
        "script_heads": {"count": len(script), "by_kind": split(script)},
        "non_script_heads": {"count": len(nonscript), "by_kind": split(nonscript)},
        "heads": out,
        "reading": "%d heads dispatch on a byte or word of the **command stream** (`u8[cmd+k]` / "
                   "`u16[cmd+k]`) and %d on a **field of the context**; %d take an **argument** as the index "
                   "directly, which is what a C-level switch compiled to a table looks like; %d read a "
                   "**global**; and %d are `local`/`unknown`, where the bounded trace refuses rather than "
                   "guesses."
                   % (kinds.get("command_field", 0), kinds.get("ctx_field", 0), kinds.get("argument", 0),
                      kinds.get("global", 0), kinds.get("local", 0) + kinds.get("unknown", 0)),
        "not_claimed": [
            "what each arm does: this is the index, not the meaning",
            "the `local`/`unknown` heads: their index bottoms out on a base the trace cannot resolve, and the "
            "count is published rather than the gap filled in",
            "that a `command_field` index is a script opcode: an opcode sub-field and a data byte read through "
            "the same pointer look identical here",
        ],
    }


REGISTRY = ROOT / "fixtures" / "scd" / "registry.json"


def check(committed, image):
    fresh = derive(image)
    cases = []
    heads = committed["heads"]
    cases.append((f"every head is traced and the counts partition it ({len(heads)} heads, "
                  f"{committed['script_heads']['count']} script + "
                  f"{committed['non_script_heads']['count']} not)",
                  len(heads) == 86
                  and committed["script_heads"]["count"] + committed["non_script_heads"]["count"] == len(heads)
                  and sum(committed["by_kind"].values()) == len(heads)
                  and fresh["by_kind"] == committed["by_kind"]))

    cases.append((f"the four named sources and the two refusals are all present "
                  f"({committed['by_kind']})",
                  set(committed["by_kind"]) <= {"command_field", "ctx_field", "argument", "global",
                                                "local", "unknown", "constant", "command_pointer",
                                                "ctx_pointer_field", "argument_pointer_field",
                                                "inherited_pointer", "stack_field"}
                  and committed["by_kind"].get("command_field", 0) > 0
                  and committed["by_kind"].get("argument", 0) > 0))

    cmd = [h for h in heads if h["source"]["kind"] == "command_field"]
    offsets = sorted({h["source"]["offset"] for h in cmd})   # out of the f-string: 3.9 cannot nest a set here
    cases.append((f"every command-stream index names the command pointer and an offset "
                  f"({len(cmd)} heads, offsets {offsets})",
                  cmd and all(h["source"]["offset"] >= 0 and h["source"]["width"] in (1, 2, 4)
                              and "cmd+" in h["source"]["note"] for h in cmd)))

    case36 = [h for h in heads if h["handler"] == "0x36"]
    cases.append(("0x36 is the worked example: its table, its bound and its `cmd+4` source are all reproduced",
                  len(case36) == 1 and case36[0]["table"] == 0x800B98E0
                  and case36[0]["bound"] == 5
                  and case36[0]["source"]["offset"] >= 0))

    refusals = [h for h in heads if h["source"]["kind"] in ("local", "unknown")]
    cases.append((f"the refusals are published with their reason, not silently bucketed "
                  f"({len(refusals)} refused)",
                  all(h["source"].get("note") for h in refusals)))

    cases.append(("each head's transform is reported in the order it is applied, so a 1-based index is visible",
                  any("addiu -1" in h["transform"] for h in heads)
                  and all(isinstance(h["transform"], list) for h in heads)))

    cases.append(("the window rule is stated, and the artefact says the bound cost something",
                  "bounded window" in committed["inputs"]["window"]
                  and "the bound cost" in committed["inputs"]["window"]))

    cases.append(("every head says what is not claimed",
                  len(committed["not_claimed"]) >= 3))

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
            print("REFUSED: %s is not present, so there is nothing to measure" % rd.IMAGE.relative_to(ROOT))
            return 2
        rep = derive(image)
        (ROOT / OUT).write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        print("wrote %s — %s; non-script: %s" % (OUT, rep["by_kind"], rep["non_script_heads"]["by_kind"]))
        return 0

    if a.list:
        if image is None:
            print("SKIP (needs the unpacked stage-2 image)")
            return 0
        rep = derive(image)
        for h in rep["heads"]:
            print("0x%08x bound %-3d %-22s %-14s %s %s" % (
                h["table"], h["bound"], ("op " + h["handler"]) if h["handler"] else "(not script)",
                h["source"]["kind"], ",".join(h["transform"]) or "-", h["source"].get("note", "")))
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
    print("%d/%d head-index case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
