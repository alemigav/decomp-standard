"""Resolve the table opcode `0x36` dispatches through — and correct the address every document had wrong.

Since M211 this project has described opcode `0x36` as `jr <*(0x800c98e0 + (s16[cmd+4] >> 8)*4)>` and called
its targets "a callback pointer, not a command address", which is why `scd_vm.py` refuses it and why two of
256 rooms (6 and 21) could not be decoded. This tool reads the handler's instructions and settles both
halves of that sentence.

**The address was wrong by 0x10000, and that is why the table looked empty.** The handler builds the base
with `lui v0,0x800c` at `0x800711b0` and `addiu v0,v0,-26400` at `0x800711b4`. `addiu` **sign-extends** its
immediate, so the encoded `0x98e0` is the signed value **−0x6720**, and the address is
`0x800c0000 − 0x6720 = 0x800B98E0`. Reading the immediate as unsigned gives `0x800C98E0` — 0x10000 higher —
where this image holds **259 words of zero**. That is the whole of the "the table is empty, so it must be
filled at runtime" story: a displacement read with the wrong sign. The corpus had it right all along, which
is why Ghidra's decompiler resolved five distinct switch cases where this project's documents could see
nothing.

**The table is static, five entries, all inside the image.** At `0x800b98e0`: `800711cc 800711dc 800711fc
8007121c 8007124c` — five code addresses, each one a `switchD_800711c4::case` in the corpus, and the
handler bounds-checks the index (`sltiu v0,a0,5` / `beq v0,zero,<out of range>`) before indexing it.

**The targets are commands, not callbacks.** Each entry is an arm of one dispatch: it selects a *base
object* (zero, or a word read from `0x800e13e8`/`0x800e13ec`/`0x800e13e8+(idx+2)*4`, or a `0x368`-stride
row at `0x800e18f8`), and every arm then runs the same tail, which computes three coordinates
(`base + s16[cmd+6/+8/+10]`), packs a 24-bit id from `u8[cmd+1]` and `u16[cmd+2]`, calls `FUN_80077adc`,
and writes `ctx->0x1c = cmd + 0xc`. So `0x36`'s advance is the **constant 12**, its index selects a
**sub-opcode**, and its five targets never leave the image. What is genuinely runtime-initialised is the
*base objects* the arms select — those words are zero in the image — not the table.

Usage:
  ./callback_table.py --write    # regenerate manifests/callback_table.json from the image
  ./callback_table.py --check    # validate the committed artefact against a fresh derivation
  ./callback_table.py --arms     # print the handler, the five arms and the shared tail
"""
import argparse
import importlib.util
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
OUT = Path("manifests") / "callback_table.json"
SCHEMA = "callback-table/1"

_spec = importlib.util.spec_from_file_location("rsp_decode", HERE / "rsp_decode.py")
rd = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(rd)

RANGES = ROOT / "fixtures" / "decomp" / "ranges.json"

HANDLER = 0x80071180          # the registry's `handler` for opcode 0x36
BASE_LUI = 0x800711B0         # lui v0,0x800c
BASE_ADDIU = 0x800711B4       # addiu v0,v0,-26400
TABLE = 0x800B98E0            # what those two instructions compute
PUBLISHED_WRONG = 0x800C98E0  # what the documents since M211 say, and what 0x10000 of nothing looks like
ENTRIES = 5                   # `sltiu v0,a0,5`
TAIL_LO, TAIL_HI = 0x80071278, 0x800712E8
OPCODE = 0x36

REG = rd.REG


def sx16(v):
    return v - 0x10000 if v & 0x8000 else v


def word(image, va):
    off = va - rd.STAGE2_BASE
    return int.from_bytes(image[off:off + 4], "big")


def dis(image, va):
    """One CPU word as text. The decoder is `rsp_decode`'s — one decoder for both sides — but its
    branch and jump targets are masked to a 12-bit IMEM, which is right for the RSP and wrong here, so
    they are recomputed for a 32-bit address space and the substitution is recorded in the artefact."""
    w = word(image, va)
    d = rd.decode(w, va)
    m = d["mnemonic"]
    if m in ("jal", "j"):
        return "%s 0x%08x" % (m, (va + 4 & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
    if d.get("branch_target") is not None:
        tgt = va + 4 + (sx16(w & 0xFFFF) << 2)
        rs, rt = rd.bits(w, 25, 21), rd.bits(w, 20, 16)
        return ("%s %s,%s,0x%08x" % (m, REG[rs], REG[rt], tgt) if m in ("beq", "bne")
                else "%s %s,0x%08x" % (m, REG[rs], tgt))
    return d["text"]


def listing(image, lo, hi):
    return [{"at": va, "word": word(image, va), "text": dis(image, va)} for va in range(lo, hi, 4)]


def fold_base(image):
    """The two instructions that build the table address, folded with `addiu`'s sign extension."""
    lui, addiu = word(image, BASE_LUI), word(image, BASE_ADDIU)
    hi = (lui & 0xFFFF) << 16
    imm = sx16(addiu & 0xFFFF)
    unsigned = addiu & 0xFFFF
    return {
        "instructions": [dis(image, BASE_LUI), dis(image, BASE_ADDIU)],
        "upper": hi,
        "immediate_signed": imm,
        "immediate_as_encoded": unsigned,
        "address": (hi + imm) & 0xFFFFFFFF,
        "address_if_read_unsigned": (hi + unsigned) & 0xFFFFFFFF,
        "difference": (hi + unsigned) - (hi + imm),
        "why": "`addiu` sign-extends, so the encoded 0x%04x is the signed %d and the address is 0x%08x. "
               "Reading the immediate as unsigned instead gives 0x%08x, 0x%x higher -- and that is the "
               "address every document since M211 published."
               % (unsigned, imm, (hi + imm) & 0xFFFFFFFF, (hi + unsigned) & 0xFFFFFFFF,
                  (hi + unsigned) - (hi + imm)),
    }


def dispatch(image):
    """The handler's head, instruction by instruction, and the index rule read out of it."""
    head = listing(image, HANDLER, 0x800711CC)
    idx_rule = None
    bound = None
    for rec in head:
        if rec["text"].startswith("sltiu v0,a0,5"):
            bound = rec["at"]
        if rec["text"].startswith("srl a0,a1,8"):
            idx_rule = rec["at"]
    return {
        "handler": HANDLER,
        "head": head,
        "index_instruction": idx_rule,
        "bound_instruction": bound,
        "index_rule": "idx = u16[cmd+4] >> 8, from `lhu a1,4(s0)` then `srl a0,a1,8`",
        "bound": "`sltiu v0,a0,5` then `beq v0,zero,0x80071278`: idx < 5 or the dispatch is skipped",
        "dispatch": "`lw v0,0(v1)` then `jr v0` through the table entry",
    }


def entries(image):
    """The five pointers, what each arm computes, and whether it is code this project has bounded."""
    ranges = json.loads(RANGES.read_text())["images"]["stage2"]
    starts = {a for a, _b in ranges}

    def containing(va):
        # a list, not a tuple: this value is committed as JSON and re-derived here, and a tuple compares
        # unequal to the list it round-trips through even when the manifest is identical
        for a, b in ranges:
            if a <= va <= b:
                return [a, b]
        return None

    pointers = [word(image, TABLE + 4 * i) for i in range(ENTRIES)]
    out = []
    for i, va in enumerate(pointers):
        # an arm runs from its own pointer to the next one's (the last runs to the shared tail), so the
        # window is the code the dispatch actually gives that sub-opcode -- not a fixed guess
        hi = pointers[i + 1] if i + 1 < len(pointers) else TAIL_LO
        arm_words = [word(image, a) for a in range(va, min(hi, va + 4 * 24), 4)]
        arm = [dis(image, a) for a in range(va, min(hi, va + 4 * 24), 4)]
        out.append({
            "index": i,
            "pointer": va,
            "in_image": rd.STAGE2_BASE <= va < rd.STAGE2_BASE + len(image),
            "is_a_range_start": va in starts,
            "bounded_by": containing(va),
            "arm_head": arm,
            "selects": _arm_reading(arm_words),
        })
    return out


def _linear(arm_words):
    """Fold an arm into (constant, coefficient) per register: value = constant + coefficient * idx.

    A three-register abstract evaluator over the nine instruction forms this switch uses, so what an arm
    selects is computed from its bytes rather than matched against a string. `idx` is the only input the
    arms read, and it is the low byte of `s16[cmd+4]`.
    """
    # a1 holds the raw halfword u16[cmd+4], so its low byte -- the field arms 3 and 4 index by -- is the
    # one free variable in an arm. (The *high* byte is the sub-opcode itself, already used to get here.)
    regs = {r: (0, 0) for r in range(32)}
    regs[5] = (0, 1)
    for w in arm_words:
        op, rs, rt = rd.bits(w, 31, 26), rd.bits(w, 25, 21), rd.bits(w, 20, 16)
        imm = sx16(w & 0xFFFF)
        if op == 0x0F:
            regs[rt] = ((w & 0xFFFF) << 16, 0)
        elif op in (0x0D, 0x09) and rs == 0:
            regs[rt] = ((w & 0xFFFF) if op == 0x0D else imm, 0)
        elif op in (0x0D, 0x09):
            c, k = regs[rs]
            regs[rt] = (c + ((w & 0xFFFF) if op == 0x0D else imm), k)
        elif op == 0x00 and rd.bits(w, 5, 0) == 0x21:
            a, b = regs[rd.bits(w, 25, 21)], regs[rd.bits(w, 20, 16)]
            regs[rd.bits(w, 15, 11)] = (a[0] + b[0], a[1] + b[1])
        elif op == 0x00 and rd.bits(w, 5, 0) == 0x23:
            a, b = regs[rd.bits(w, 25, 21)], regs[rd.bits(w, 20, 16)]
            regs[rd.bits(w, 15, 11)] = (a[0] - b[0], a[1] - b[1])
        elif op == 0x00 and rd.bits(w, 5, 0) == 0x00:
            c, k = regs[rt]
            sa = rd.bits(w, 10, 6)
            regs[rd.bits(w, 15, 11)] = (c << sa, k << sa)
        elif op == 0x0C:
            c, k = regs[rs]
            mask = w & 0xFFFF
            regs[rt] = (0, 1) if k else (c & mask, 0)
        elif op in (0x21, 0x23, 0x24, 0x25):
            break
    return regs


def _arm_reading(arm_words):
    """What one arm selects, computed from its own instructions.

    Two shapes exist. Arms 1 and 2 load a *pointer* and jump to the tail, which then reads three words at
    +0x28/+0x2c/+0x30 from it. Arms 0, 3 and 4 leave a *base row* in v1 and let the tail dereference it
    directly. The low byte of u16[cmd+4] (`lo`) is what arms 3 and 4 index by.
    """
    w0 = arm_words[0]
    if (rd.bits(w0, 31, 26) == 0 and rd.bits(w0, 20, 16) == 0 and rd.bits(w0, 25, 21) == 0):
        return "the zero base: all three offsets start from 0"
    regs = _linear(arm_words)
    for w in arm_words:
        op, rs = rd.bits(w, 31, 26), rd.bits(w, 25, 21)
        if op in (0x21, 0x23, 0x24, 0x25):
            c, k = regs[rs]
            addr = (c + sx16(w & 0xFFFF)) & 0xFFFFFFFF
            if not k:
                return "a pointer loaded from 0x%08x; the tail reads +0x28/+0x2c/+0x30 through it" % addr
            return ("a pointer loaded from 0x%08x + %d * lo; the tail reads +0x28/+0x2c/+0x30 through it"
                    % (addr, k))
    c, k = regs[3]      # v1 survives to the tail as the base
    addr = c & 0xFFFFFFFF
    if not k:
        return "base 0x%08x, dereferenced by the tail" % addr
    return "a row at 0x%08x + %d * lo, dereferenced by the tail" % (addr, k)


def tail(image):
    """The shared tail's own instructions, and the advance it writes."""
    body = listing(image, TAIL_LO, TAIL_HI)
    store = [r for r in body if r["text"].startswith("sw v0,28(s1)")]
    adv = [r for r in body if r["text"].startswith("addiu v0,s0,12")]
    return {
        "listing": body,
        "advance_instruction": adv[0] if adv else None,
        "store_instruction": store[0] if store else None,
        "advance": 12 if adv and store else None,
        "note": "every arm reaches this tail and it is the only writer of the command pointer, so the "
                "advance is 12 on all five arms -- which is what the registry could not see while the "
                "store sat outside the handler's bounded body, and why 0x36 was refused as dynamic",
    }


def derive(image):
    base = fold_base(image)
    disp = dispatch(image)
    ents = entries(image)
    tl = tail(image)
    wrong_region = [word(image, PUBLISHED_WRONG + 4 * k) for k in range(8)]
    return {
        "tool": "callback_table.py",
        "schema": SCHEMA,
        "inputs": {
            "image": str(rd.IMAGE.relative_to(ROOT)),
            "base": hex(rd.STAGE2_BASE),
            "opcode": hex(OPCODE),
            "decoder": "tools/rsp_decode.py (shared); its branch/jump targets are recomputed for a 32-bit "
                       "address space here, because that decoder masks them to a 12-bit IMEM for the RSP",
        },
        "address": base,
        "dispatch": disp,
        "table": {
            "address": TABLE,
            "entries": ents,
            "entry_count": len(ents),
            "all_in_image": all(e["in_image"] for e in ents),
            "all_bounded": all(e["bounded_by"] for e in ents),
        },
        "tail": tl,
        "classification": {
            "verdict": "sub-opcode family",
            "reading": "the five pointers are code in this image, each an arm of one dispatch reached only "
                       "from this handler, and each selects a base object before the same tail runs and "
                       "writes the same advance. So a table entry is a variant of one command, not a host "
                       "callback: 0x36 is a command whose index selects a sub-opcode. M211's 'a callback "
                       "pointer, not a command address' is retracted.",
            "what_is_runtime_initialised": "the base objects the arms select -- the words at 0x800e13e8, "
                                           "0x800e13ec and 0x800e18f8 are zero in this image. That is where "
                                           "the 'filled at runtime' reading belongs, not on the table",
        },
        "the_wrong_address": {
            "published_since": "M211 (tools/opcode_registry.py, tools/walk_stream.py, tools/vm_refusals.py)",
            "published": PUBLISHED_WRONG,
            "correct": TABLE,
            "what_is_at_the_published_address": wrong_region,
            "why_it_looked_empty": "0x%08x holds %d zero words in this image, which is why 'the table is "
                                   "empty, so it must be filled at runtime' was a coherent but wrong "
                                   "explanation for a table that is static, five entries, and 0x10000 lower"
                                   % (PUBLISHED_WRONG, len(wrong_region)),
        },
        "id_and_coordinates": {
            "id_rule": "u8[cmd+1] << 24 | (u16[cmd+2] >> 8) << 16 | (u16[cmd+2] & 0xff)",
            "coordinate_rule": "base + s16[cmd+6], base + s16[cmd+8], base + s16[cmd+10]",
            "callee": "FUN_80077adc(id, &coords) at 0x800712c0",
            "note": "the callee splits the id into three indices and looks each up in a per-bank table "
                    "(&DAT_80119ea8 / &DAT_80119ecc); whether that is a sound trigger is *inferred*, not "
                    "measured here, and is recorded as an inference",
        },
    }


def check(committed, image):
    fresh = derive(image)
    cases = []
    base = committed["address"]["address"]
    cases.append((f"the table address folds from `lui 0x800c` + `addiu v0,v0,-26400` with the immediate "
                  f"sign-extended, to {hex(base)}",
                  fresh["address"]["address"] == base == TABLE
                  and fresh["address"]["immediate_signed"] == -26400
                  and fresh["address"]["address_if_read_unsigned"] == PUBLISHED_WRONG
                  and fresh["address"]["difference"] == 0x10000))

    cases.append((f"the address every document carries is 0x10000 higher and holds nothing "
                  f"({hex(PUBLISHED_WRONG)}: {committed['the_wrong_address']['what_is_at_the_published_address']})",
                  committed["the_wrong_address"]["correct"] == base
                  and committed["the_wrong_address"]["published"] == PUBLISHED_WRONG
                  and all(w == 0 for w in committed["the_wrong_address"]["what_is_at_the_published_address"])))

    disp = committed["dispatch"]
    cases.append((f"the handler bounds-checks the index before indexing the table "
                  f"({disp['index_rule']}; {disp['bound']})",
                  disp["handler"] == HANDLER and disp["index_instruction"] and disp["bound_instruction"]
                  and any(r["text"].startswith("jr") for r in disp["head"])
                  and fresh["dispatch"] == disp))

    ents = committed["table"]["entries"]
    cases.append((f"the table holds {committed['table']['entry_count']} entries, all of them code this "
                  f"project has bounded and all of them range starts",
                  len(ents) == ENTRIES
                  and committed["table"]["entry_count"] == ENTRIES
                  and all(e["in_image"] and e["bounded_by"] and e["is_a_range_start"] for e in ents)))

    cases.append(("every entry's first instruction is disassembled from the image, not quoted",
                  all(e["arm_head"] and e["arm_head"][0].startswith(("addu", "lui", "andi"))
                      for e in ents)
                  and fresh["table"] == committed["table"]))

    tl = committed["tail"]
    cases.append((f"the shared tail writes the advance once, and it is {tl['advance']} bytes",
                  tl["advance"] == 12 and tl["advance_instruction"]["at"] == 0x800712C8
                  and tl["store_instruction"]["at"] == 0x800712CC
                  and any(r["at"] == 0x800712C0 and r["text"].startswith("jal 0x80077adc")
                          for r in tl["listing"])))

    cases.append((f"the classification is a sub-opcode family and says what is runtime-initialised "
                  f"({committed['classification']['verdict']})",
                  committed["classification"]["verdict"] == "sub-opcode family"
                  and "not a host callback" in committed["classification"]["reading"]
                  and committed["classification"]["what_is_runtime_initialised"]))

    cases.append(("the artefact records that the decoder's targets were recomputed for a 32-bit space",
                  "recomputed" in committed["inputs"]["decoder"]))

    cases.append(("the committed manifest equals a fresh derivation of the image",
                  json.dumps(committed, sort_keys=True) == json.dumps(fresh, sort_keys=True)))
    return cases


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--arms", action="store_true")
    a = ap.parse_args()

    image = rd.stage2()
    if a.write:
        if image is None:
            print("REFUSED: %s is not present, so there is nothing to measure"
                  % rd.IMAGE.relative_to(ROOT))
            return 2
        rep = derive(image)
        (ROOT / OUT).write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        print("wrote %s — table at %s (not %s), %d entries, advance %d, %s"
              % (OUT, hex(rep["address"]["address"]), hex(PUBLISHED_WRONG),
                 rep["table"]["entry_count"], rep["tail"]["advance"],
                 rep["classification"]["verdict"]))
        return 0

    if a.arms:
        if image is None:
            print("SKIP (needs the unpacked stage-2 image)")
            return 0
        rep = derive(image)
        print("== handler 0x%08x" % HANDLER)
        for r in rep["dispatch"]["head"]:
            print("   %08x  %08x  %s" % (r["at"], r["word"], r["text"]))
        print("== table 0x%08x" % TABLE)
        for e in rep["table"]["entries"]:
            print("   [%d] 0x%08x  %-28s %s" % (e["index"], e["pointer"], e["selects"],
                                                "; ".join(e["arm_head"][:3])))
        print("== tail 0x%08x" % TAIL_LO)
        for r in rep["tail"]["listing"]:
            print("   %08x  %08x  %s" % (r["at"], r["word"], r["text"]))
        return 0

    if not a.check:
        ap.error("one of --write, --check, --arms is required")
    if image is None:
        print("SKIP (needs the unpacked stage-2 image: %s)" % rd.IMAGE.relative_to(ROOT))
        return 0
    committed = json.loads((ROOT / OUT).read_text())
    cases = check(committed, image)
    bad = 0
    for label, ok in cases:
        bad += not ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d callback-table case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
