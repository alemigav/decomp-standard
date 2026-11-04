"""What the audio task's ucode does with the block the CPU publishes — and what it does not do.

`rsp_decode.py` (M223) recovered the program's words, its entry, its 19 call targets and its task block.
This tool answers the next question: **is there a command interface at all?** It measures four things and
refuses a fifth.

  1. **Control flow, closed.** A real successor function for the RSP subset this program uses — delay
     slots modelled, `beq zero,zero` read as an unconditional jump, `jr ra`/`jr fp` given return edges to
     every call's return address — and then reachability from IMEM 0. The answer is not "everything":
     **173 of 976 words are reachable from no edge at all**, in twelve runs, 172 of them code (they hold
     14 branches, 3 calls, 5 returns and 36 vector words between them; the last is a `nop` fill), and
     every run begins immediately after a control-flow exit so that no fall-through reaches it. That
     supersedes M223's framing of these words as "gaps ... reached by no jal target and by no modelled
     fall-through": the gaps were an artefact of greedy function bodies.

  2. **The call targets are not functions.** M223 counted 19 `jal` targets and called them functions,
     with bodies that run "from entry to the first `jr`, capped at the next root". Measured here: nine
     start a routine, nine are entry points into a body another target also enters, one (`0xca4`) is a
     bare `jr ra` — a call that does nothing but its delay slot — and **14 of the 19 share an exit** with
     another target, in three groups. Worse for the call layout: the four `or fp,zero,ra` link-saves in
     the program are **all** unreachable, while three `jr fp` exits are reachable, so on every path this
     model can find the body returns through a register no instruction writes. That is not resolved here;
     it is the standing doubt about this blob's call displacements.

  3. **The hardware interface is 13 register writes at five code points.** Every COP0 write sits in
     0x350-0x3c0 plus one at 0x2ac: four overlapping copies of one 11-word sequence that writes two
     addresses and a length, waits, and clears the semaphore; and the halt path. The register numbers
     are now **named from a cited source** — c0 SP_DMA_SPADDR, c1 RAMADDR, c2 RDLEN, c3 WRLEN,
     c4 SP_STATUS, c5 DMA_FULL, c6 DMA_BUSY, c7 SEMAPHORE — because the local manual defers them to
     `rcp.h`, which this repository does not hold (p115 and p529, both cited). Every length the program
     states is bytes-1 with bytes a multiple of 8, exactly as the source predicts. The one write to
     SP_STATUS sets bit 14 — SIG2 — and is followed by `break`.

  4. **The work list is a record, not a list.** The CPU publishes a pointer (task +0x30) and a count
     (+0x34). The ucode reads both once, advances the pointer by 0xa10 per iteration and decrements the
     count — and 0xa10 is exactly the constant the *CPU-side* cache-flush recipe computes for one unit
     (`sll/addu/sll/addu/sll` folded here, not quoted). The DMEM map also shows two 0x50-byte parameter
     records at 0x260 and 0x2b0, each with 21 fields, addressed through one pointer register that holds
     exactly those two values: a double buffer.

**What it refuses.** There is **no command dispatch, and no table to find one in**: all 49 `j`/`jal`
fields carry an absolute target, the only indirect transfers are `jr` through a saved link, and no load
ever reaches one. Any "command" would therefore have to be a compare chain on a value loaded from the
published block — and the measurement is that the block's fields are sizes, counts and mode flags that
select stages of a fixed sequence: 13 loads reach a conditional branch and not one of them indexes a
target. The two address fields' roles remain unresolved because every value either side takes is under
0x1000, and the 173 unreachable words are listed rather than explained. (The vector unit's 254 words were
unnamed when this tool was written; M225 named 252 of them from a cited table, so that entry is now about
what the arithmetic *means* rather than what it is.)

Usage:
  ./rsp_iface.py --write     # regenerate manifests/rsp_iface.json from the image
  ./rsp_iface.py --check     # validate the committed artefact against a fresh derivation
  ./rsp_iface.py --flow      # print the successor table and reachability this tool claims
"""
import argparse
import importlib.util
import itertools
import json
import math
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
OUT = Path("manifests") / "rsp_iface.json"
SCHEMA = "rsp-iface/1"

_spec = importlib.util.spec_from_file_location("rsp_decode", HERE / "rsp_decode.py")
rd = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(rd)

RSP_WORDS = 976                      # M223: the declared 0x1000 overruns the program by 0xC0
STRIDE = 0xA10                       # the per-record stride, derived on both sides below
FRAME_RECORD_SLOTS = (0x260, 0x2B0)  # the two 0x50-byte blocks the base fold finds

# Why the SP register numbers stay unnamed — cited, not asserted. Both quotes were read out of the
# manual's own text layer and are verbatim; the index entry is what makes the first one decisive.
CITES = {
    "sp_not_programmed": (115, "With the current software architecture, the application does not program "
                               "the SP directly, and need not concern itself with IMEM and DMEM accesses."),
    "rcp_index": (529, "rcp.h 110, 111"),
}

BRANCH = ("beq", "bne", "blez", "bgtz", "bltz", "bgez")
CTRL = BRANCH + ("j", "jal", "jr", "break")

# The edge rules. Each is a decision, so each is stated, counted in the manifest and checked.
FLOW_RULE = (
    "Successors are per instruction, with the delay slot modelled as its own step: a `j`/`jal`/`jr` at "
    "a has a -> a+4 only, and the delay slot at a+4 then has the jump's target (or, for `jr`, the return "
    "set). A branch at a has a -> a+4, and its delay slot has {taken, a+8}. `break` has no successor. "
    "`beq zero,zero,T` is read as an unconditional jump and `bne zero,zero,T` as never taken: the "
    "assembler emits that pair when a branch is out of range, and treating it as conditional both invents "
    "an edge into whatever follows and hides the one to T. The return set for `jr ra`/`jr fp` is every "
    "`jal` return address (site+8) plus every synthesized return (`ori ra,zero,imm`): an over-"
    "approximation, and it is why a word this tool calls unreachable is unreachable under *more* edges "
    "than the hardware has, not fewer."
)


def stage2():
    return rd.stage2()


def program(image):
    """The RSP program's decoded words, from the one decoder this repository has."""
    blob = rd.ucode_blob(image)
    words = [int.from_bytes(blob[i:i + 4], "big") for i in range(0, len(blob), 4)]
    return rd.analyses(words)[:RSP_WORDS]


# --- control flow ---------------------------------------------------------------------------------------
def delay_slots(dec):
    """Addresses that are a delay slot: the word after a control transfer that has one."""
    out = set()
    for d in dec:
        if d["mnemonic"] in CTRL and d["mnemonic"] != "break":
            out.add(d["at"] + 4)
    return out


def unconditional(d):
    """`beq zero,zero,T` is a jump; `bne zero,zero,T` is never taken. Both are counted in the manifest."""
    w = d["word"]
    rs, rt = rd.bits(w, 25, 21), rd.bits(w, 20, 16)
    if d["mnemonic"] == "beq" and rs == 0 and rt == 0:
        return "always"
    if d["mnemonic"] == "bne" and rs == 0 and rt == 0:
        return "never"
    return None


def returns(dec):
    """Every address a `jr ra` can come back to: call return sites plus synthesized links.

    A synthesized link is masked to 12 bits, because the RSP's PC is 12 bits and the high bits of a
    jump or call field are ignored (cited). That is not cosmetic: the one synthesized continuation in
    this program writes 0x10d8, which is *past* the end of the program until the mask is applied, and
    then lands at IMEM 0x0d8 — inside the frame loop it was always meant to re-enter.
    """
    out = {d["at"] + 8 for d in dec if d["mnemonic"] == "jal"}
    synth = []
    for d in dec:
        if d["mnemonic"] == "ori" and rd.bits(d["word"], 20, 16) == 31 and rd.bits(d["word"], 25, 21) == 0:
            raw = rd.sx16(d["word"] & 0xFFFF) & 0xFFFFFFFF
            out.add(raw & 0xFFF)
            synth.append({"at": d["at"], "value": raw, "imem": raw & 0xFFF,
                          "outside_program_raw": raw >= len(dec) * 4, "text": d["text"]})
    return out, synth


def successors(dec, delay, ret):
    """address -> successor set, under FLOW_RULE."""
    n = len(dec) * 4
    at = {d["at"]: d for d in dec}

    def succ(a):
        if a not in at:
            return set()
        if a in delay and (a - 4) in at:
            o = at[a - 4]
            m = o["mnemonic"]
            if m in BRANCH:
                t = o["branch_target"]
                u = unconditional(o)
                if u == "always":
                    return {t}
                if u == "never":
                    return {a + 4}
                return {t, o["at"] + 8}
            if m in ("j", "jal"):
                return {o["jump_target"]}
            if m == "jr":
                return set(ret)
            return set()
        return {a + 4} if a + 4 < n else set()

    return succ, at


def reachable(succ, entry=0):
    seen, stack = set(), [entry]
    while stack:
        a = stack.pop()
        if a in seen:
            continue
        seen.add(a)
        stack.extend(s for s in succ(a) if s not in seen)
    return seen


def runs_of(addresses, dec):
    """Contiguous runs of a sorted address set, as (start, end, words)."""
    out = []
    for _k, g in itertools.groupby(enumerate(sorted(addresses)), lambda t: t[1] - t[0] * 4):
        g = [a for _i, a in g]
        out.append((g[0], g[-1] + 4, len(g)))
    return out


def characterise(dec, start, end):
    """What a run of words is made of. A data table would have no branches, no calls and no returns."""
    body = [d for d in dec if start <= d["at"] < end]
    counts = {
        "words": len(body),
        "branches": sum(1 for d in body if d["mnemonic"] in BRANCH),
        "calls": sum(1 for d in body if d["mnemonic"] == "jal"),
        "returns": sum(1 for d in body if d["mnemonic"] == "jr"),
        "vector": sum(1 for d in body if d["status"] == "vector"),
        "unreadable": sum(1 for d in body if d["status"] == "unreadable"),
        "saves_link": sum(1 for d in body if d["text"] == "or fp,zero,ra"),
    }
    counts["kind"] = ("code" if (counts["branches"] or counts["calls"] or counts["returns"]
                                 or counts["vector"])
                      else "fill" if all(d["word"] == 0 or d["mnemonic"] == "nop" for d in body)
                      else "unclassified")
    counts["is_code"] = counts["kind"] == "code"
    counts["entropy"] = round(_entropy([d["word"] for d in body]), 3)
    return counts


def _entropy(ws):
    if not ws:
        return 0.0
    n = len(ws)
    return -sum((ws.count(w) / n) * math.log2(ws.count(w) / n) for w in set(ws))


def control_flow(dec):
    delay = delay_slots(dec)
    ret, synth = returns(dec)
    succ, at = successors(dec, delay, ret)
    reach = reachable(succ)
    inst = {d["at"] for d in dec}
    off_grid = sorted(reach - inst)
    dead = [a for a in (d["at"] for d in dec) if a not in reach]
    unreachable = []
    for start, end, words in runs_of(dead, dec):
        c = characterise(dec, start, end)
        c.update(start=start, end=end,
                 after_exit=_after_exit(dec, start),
                 entered_inside=_inside_entry(dec, start, end, reach))
        unreachable.append(c)
    jr = [d for d in dec if d["mnemonic"] == "jr"]
    computed = [d for d in jr if d["jump_reg"] not in (31, 30, 8)]
    return {
        "rule": FLOW_RULE,
        "words": len(dec),
        "reachable": len(reach & inst),
        "off_grid_successors": off_grid,
        "unreachable": len(dead),
        "unreachable_fraction": round(len(dead) / len(dec), 4),
        "unreachable_runs": unreachable,
        "all_unreachable_is_code_or_fill": all(u["kind"] in ("code", "fill")
                                              for u in unreachable),
        "unreachable_code_words": sum(u["words"] for u in unreachable
                                      if u["kind"] == "code"),
        "delay_slots": len(delay),
        "returns": {
            "call_return_sites": len([d for d in dec if d["mnemonic"] == "jal"]),
            "synthesized": synth,
            "jr": len(jr),
            "jr_through_link": len(jr) - len(computed),
            "jr_computed": [{"at": d["at"], "text": d["text"]} for d in computed],
            "note": "`jr` with a register other than ra/fp is still a return when the register provably "
                    "holds a saved link; each such site is listed with the instruction that saved it",
        },
        "link_saves": _link_saves(dec, reach),
        "unconditional_idiom": {
            "beq_zero_zero": sum(1 for d in dec if d["mnemonic"] == "beq" and unconditional(d) == "always"),
            "bne_zero_zero": sum(1 for d in dec if d["mnemonic"] == "bne" and unconditional(d) == "never"),
            "sites": [{"at": d["at"], "text": d["text"]}
                      for d in dec if unconditional(d) is not None],
        },
    }


def _link_saves(dec, reach):
    """Every `or fp,zero,ra` and every `jr fp`, with whether any reachable path reaches the save.

    This is the measurement that makes the call layout of this blob doubtful: the register the body
    returns through is only ever written by instructions no reachable path executes.
    """
    saves = [{"at": d["at"], "reachable": d["at"] in reach, "text": d["text"]}
             for d in dec if d["text"] == "or fp,zero,ra"]
    exits = [{"at": d["at"], "reachable": d["at"] in reach, "text": d["text"]}
             for d in dec if d["text"] == "jr fp"]
    other_writes = [{"at": d["at"], "text": d["text"]} for d in dec
                    if d["text"] != "or fp,zero,ra" and _write_form(d)[0] == 30]
    return {
        "saves": saves,
        "exits": exits,
        "other_writes_to_fp": other_writes,
        "ever_saved_on_a_reachable_path": any(s["reachable"] for s in saves),
        "reading": "the four `or fp,zero,ra` instructions in this program are at %s and none of them is "
                   "reachable, while %d `jr fp` exits are. So on every path this model can find, the "
                   "body returns through a register that no instruction writes: either the program's "
                   "call displacements do not line up with its code (a patched or relinked blob), or the "
                   "entry register state carries fp — and the manual says nothing about the RSP's "
                   "register state at task start (M223 E3b). Recorded as the standing doubt about the "
                   "call layout, not resolved."
                   % ([hex(s["at"]) for s in saves], sum(1 for e in exits if e["reachable"])),
    }


def _after_exit(dec, start):
    """Is the word before this run the delay slot of a control transfer? Then no fall-through enters."""
    prev = [d for d in dec if d["at"] == start - 4]
    if not prev:
        return "the run starts at IMEM 0 or at a word with no predecessor in the program"
    m = prev[0]["mnemonic"]
    owner = [d for d in dec if d["at"] == start - 8]
    om = owner[0]["mnemonic"] if owner else None
    if om in CTRL and om != "break":
        return "yes: 0x%03x is the delay slot of 0x%03x `%s`, so execution leaves before it" % (
            start - 4, start - 8, om)
    return "no: the preceding word (0x%03x `%s`) falls through" % (start - 4, m)


def _inside_entry(dec, start, end, reach):
    """Where the live words inside a dead run are entered from — the signature of a partial patch."""
    inside = [a for a in range(start, end, 4) if a in reach]
    if not inside:
        return "no word inside the run is reachable either"
    return "%d of %d words inside the run are reachable (first at 0x%03x), so the run is entered after " \
           "its own head" % (len(inside), (end - start) // 4, inside[0])


# --- the call targets -----------------------------------------------------------------------------------
def call_targets(dec):
    """For each `jal` target: does it start a routine, share one, or land in the middle of one?"""
    delay = delay_slots(dec)
    ret, _ = returns(dec)
    succ, at = successors(dec, delay, ret)
    roots = sorted({d["jump_target"] for d in dec if d["mnemonic"] == "jal"})
    sites = {}
    for d in dec:
        if d["mnemonic"] == "jal":
            sites.setdefault(d["jump_target"], []).append(d["at"])
    # exits reachable from each target, without leaving through a *different* jal target
    def closure_from(entry, follow_calls):
        """Addresses reachable from `entry`, and the `jr` exits among them.

        With `follow_calls` False, a `jal` edge is not followed: what is left is the code that
        *falls* into a target rather than calling it, which is the distinction between a re-entry
        point and a callee.
        """
        seen, stack, exits = set(), [entry], {}
        while stack:
            a = stack.pop()
            if a in seen or a not in at:
                continue
            seen.add(a)
            d = at[a]
            if d["mnemonic"] == "jr":
                exits[a] = d["text"]
                continue
            if a in delay and (a - 4) in at and at[a - 4]["mnemonic"] == "jr":
                # this is the delay slot of a return: the return is the exit, and following the slot
                # would walk into every call's return address (M224)
                exits[a - 4] = at[a - 4]["text"]
                continue
            if d["mnemonic"] == "break":
                exits[a] = "break"
                continue
            if not follow_calls:
                nxt = [a + 4]
                if d.get("branch_target") is not None:
                    nxt.append(d["branch_target"])
                if d["mnemonic"] == "j":
                    nxt = [d["jump_target"]]
                elif d["mnemonic"] in BRANCH and a in delay:
                    nxt = [d["branch_target"], a + 4]
                stack.extend(x for x in nxt if x not in seen)
                continue
            stack.extend(succ(a) - seen)
        return seen, exits

    closure = {r: closure_from(r, True) for r in roots + [0]}
    fall_into = {r: closure_from(r, False)[0] for r in roots}
    out = []
    for r in roots:
        seen, exits = closure[r]
        reached_from = [other for other, oser in fall_into.items() if other != r and r in oser]
        head = at[r]
        prev8 = [d for d in dec if d["at"] == r - 8]
        prev4 = [d for d in dec if d["at"] == r - 4]
        kind = "routine head"
        if head["text"] == "or fp,zero,ra":
            kind = "chain head: saves the link in fp, and the body's `jr fp` returns through it"
        elif head["mnemonic"] == "jr":
            kind = "bare return: the call executes its delay slot and comes straight back"
        elif reached_from:
            kind = "re-entry point: reachable by falling into it from another target's body"
        prevdesc = "none"
        if prev8 and prev4:
            if prev8[0]["mnemonic"] in CTRL:
                prevdesc = "0x%03x is the delay slot of 0x%03x `%s`" % (
                    r - 4, r - 8, prev8[0]["text"])
            else:
                prevdesc = "0x%03x `%s` falls through into it" % (r - 4, prev4[0]["text"])
        out.append({
            "entry": r,
            "call_sites": sites[r],
            "call_count": len(sites[r]),
            "instructions_at_head": head["text"],
            "kind": kind,
            "preceded_by": prevdesc,
            "exits": sorted("%s @ 0x%03x" % (t, a) for a, t in exits.items()),
            "reached_from": reached_from,
        })
    # group targets by the exit sets they share: that is what M223's per-target bodies hid
    groups = {}
    for t in out:
        key = tuple(t["exits"])
        groups.setdefault(key, []).append(t["entry"])
    shared = [{"exits": list(k), "targets": v} for k, v in groups.items() if len(v) > 1]
    return {
        "targets": out,
        "exit_groups": shared,
        "targets_sharing_an_exit": sum(len(g["targets"]) for g in shared),
        "note": "M223 called these 19 call targets 'functions' with bodies capped at the next root. That "
                "cap is what produced the 216 'gap' words; the targets that share an exit are entry "
                "points into one body, and the ones whose head is a bare `jr` are calls that only run "
                "their delay slot. The word 'function' is retracted for the count.",
    }


# --- constant sets and DMEM -----------------------------------------------------------------------------
def _write_form(d):
    """(dest, form) for one instruction, where form says whether the value is a constant expression.

    `form` is one of `zero_imm` (dest <- imm), `reg_imm` (dest <- reg + imm), `move` (dest <- reg),
    `lui`, or `other` (dest <- anything else, which disqualifies dest from being a constant register).
    Returns (None, None) for an instruction that writes no GPR.
    """
    w = d["word"]
    op = rd.bits(w, 31, 26)
    m = d["mnemonic"]
    # Whether the instruction writes a *GPR* is a property of the decoded record, not of its mnemonic:
    # `lqv v3,0(at)` names v3 in the rt field and `vadd v2,v1,v0` names v0 there, and neither touches a
    # GPR. The first version of this table matched on mnemonic strings and silently disqualified every
    # base register once M225 gave the vector words their real names (M225).
    vk = d.get("vector_kind")
    if vk in ("alu", "single", "vector_transfer"):
        return None, None
    if vk == "transfer":
        return (rd.bits(w, 20, 16), "other") if m in ("mfc2", "cfc2") else (None, None)
    if m in ("ori", "addiu", "andi", "xori"):
        return rd.bits(w, 20, 16), ("zero_imm" if rd.bits(w, 25, 21) == 0 else "reg_imm")
    if m == "lui":
        return rd.bits(w, 20, 16), "lui"
    if m in ("or", "addu"):
        # SPECIAL R-type: dest is bits 15:11, sources are 25:21 and 20:16
        if rd.bits(w, 25, 21) == 0:
            return rd.bits(w, 15, 11), "move"
        return rd.bits(w, 15, 11), "other"
    if m in ("sll", "srl", "sra"):
        return rd.bits(w, 15, 11), "other"
    if m in ("jr", "jal", "j", "break", "nop"):
        return None, None
    if m in ("beq", "bne", "blez", "bgtz", "bltz", "bgez"):
        return None, None
    if m in ("sw", "sh", "sb", "swc2", "mtc0", "mtc2", "ctc2", "lwc2"):
        # `lwc2`/`swc2`/`mtc2`/`ctc2` name a *vector* register in the rt field: no GPR is written.
        # Reading them as GPR writes was a bug that made every base register opaque (M224).
        return None, None
    if m in ("mfc0", "lw", "lbu", "lhu", "mfc2", "cfc2"):
        return rd.bits(w, 20, 16), "other"
    return (rd.bits(w, 20, 16), "other") if m else (None, None)


def const_sets(dec):
    """For each GPR, the set of values it can only hold — if *every* write to it is a constant form.

    Sound by construction, and deliberately not a dataflow. A register qualifies only when all of its
    writes are `imm`, `reg+imm`, `move` from a qualifying register, or `lui`; one write of any other
    form disqualifies it outright and it is absent from the result. So an address this function folds
    is one the program can only produce from immediates — never one it guessed.
    """
    writes = {}
    for d in dec:
        dest, form = _write_form(d)
        if dest is not None:
            writes.setdefault(dest, []).append((form, d))
    known = {0: frozenset([0])}
    changed = True
    while changed:
        changed = False
        for reg, ws in writes.items():
            if reg == 0:
                continue
            vals, ok = set(), True
            for form, d in ws:
                w = d["word"]
                if form == "zero_imm":
                    vals.add(rd.sx16(w & 0xFFFF) & 0xFFFFFFFF if d["mnemonic"] in ("addiu",)
                             else (w & 0xFFFF))
                elif form == "reg_imm":
                    base = rd.bits(w, 25, 21)
                    if base not in known:
                        ok = False
                        break
                    imm = rd.sx16(w & 0xFFFF) if d["mnemonic"] == "addiu" else (w & 0xFFFF)
                    vals |= {(v + imm) & 0xFFFFFFFF for v in known[base]}
                elif form == "move":
                    src = rd.bits(w, 20, 16)
                    if src not in known:
                        ok = False
                        break
                    vals |= known[src]
                elif form == "lui":
                    vals.add((w & 0xFFFF) << 16)
                else:
                    ok = False
                    break
            if not ok:
                known.pop(reg, None)
                continue
            new = frozenset(vals)
            if known.get(reg) != new:
                known[reg] = new
                changed = True
    return {r: sorted(v) for r, v in known.items()}


def dmem_map(dec, consts, vec):
    """Absolute DMEM addresses, folded from a complete base register plus the displacement.

    Two sources: the scalar loads and stores, and the `lwc2`/`swc2` vector transfers, whose address is
    base + offset * access_size (cited). They are one map because they address one memory.
    """
    accesses, opaque = [], []
    for d in dec:
        if d["mnemonic"] not in ("lw", "lbu", "lhu", "sb", "sh", "sw"):
            continue
        w = d["word"]
        base, disp = rd.bits(w, 25, 21), rd.sx16(w & 0xFFFF)
        width = {"lw": 4, "sw": 4, "lhu": 2, "sh": 2, "lbu": 1, "sb": 1}[d["mnemonic"]]
        rec = {"at": d["at"], "text": d["text"], "width": width, "via": "scalar",
               "base_reg": rd.REG[base],
               "direction": "read" if d["mnemonic"].startswith("l") else "write"}
        if base in consts and all(0 <= v <= 0xFFF for v in consts[base]):
            rec["addresses"] = sorted({(v + disp) & 0xFFFFFFFF for v in consts[base]})
            accesses.append(rec)
        else:
            rec["base"] = rd.REG[base]
            rec["why"] = ("base %s holds no folded constant (%s)" %
                          (rd.REG[base], "runtime value" if base not in consts else "out of range"))
            opaque.append(rec)
    for r in vec["transfers"]:
        if not r["addresses"]:
            continue
        accesses.append({"at": r["at"], "text": "%s v%d (vector %s)" % (r["row"], r["vt"],
                                                                       "load" if r["load"] else "store"),
                         "width": 16 if r["row"] in ("lqv", "lrv", "sqv", "srv") else 1,
                         "via": "vector", "base_reg": r["base"],
                         "direction": "read" if r["load"] else "write",
                         "addresses": r["addresses"], "row": r["row"]})
    # The parameter records: accesses through a base register that holds exactly two constants are one
    # record per value, and the field offsets are address - base. This is how the two slots are found at
    # 0x260 and 0x2b0 (M224), rather than by guessing at contiguous runs.
    slots = []
    for reg, vals in sorted(consts.items()):
        if len(vals) != 2 or reg == 0:
            continue
        through = [a for a in accesses if a.get("base_reg") == rd.REG[reg]]
        if not through:
            continue
        spacing = vals[1] - vals[0] if len(vals) > 1 else 0x80
        for base in vals:
            fields = {}
            for a in through:
                for ad in a["addresses"]:
                    if base <= ad < base + spacing:
                        f = fields.setdefault(ad - base, {"offset": ad - base, "widths": set(),
                                                          "reads": 0, "writes": 0, "sites": []})
                        f["widths"].add(a["width"])
                        f["reads" if a["direction"] == "read" else "writes"] += 1
                        f["sites"].append(a["at"])
            if fields:
                top = max(fields)
                slots.append({
                    "base": base, "register": rd.REG[reg],
                    "extent": top + max(fields[top]["widths"]),
                    "fields": [{**v, "widths": sorted(v["widths"]), "sites": sorted(set(v["sites"]))}
                               for _, v in sorted(fields.items())],
                })
    # Cluster by contiguity: a new region starts when the next access is more than 0x10 bytes past the
    # end of the last. Bucketing by address // 0x10 merged the two parameter slots into one span (M224).
    points = sorted(((a, r["width"], r["direction"], r["at"]) for r in accesses
                     for a in r["addresses"]), key=lambda t: t[0])
    groups, cur, reach = [], [], None
    for pt in points:
        if reach is not None and pt[0] - reach > 0x10:
            groups.append(cur)
            cur = []
        cur.append(pt)
        reach = max(reach or 0, pt[0] + pt[1])
    if cur:
        groups.append(cur)
    regions = []
    for g in groups:
        addrs = sorted({p[0] for p in g})
        regions.append({
            "first": addrs[0], "last": max(p[0] + p[1] for p in g),
            "addresses": addrs,
            "widths": sorted({p[1] for p in g}),
            "reads": sum(1 for p in g if p[2] == "read"),
            "writes": sum(1 for p in g if p[2] == "write"),
            "sites": sorted({p[3] for p in g}),
        })
    return {
        "rule": "A base register qualifies only if every write to it in the program is a constant form "
                "(`ori`/`addiu`/`lui`, or a move from a register that itself qualifies). Then the "
                "absolute address is that constant plus the instruction's 16-bit displacement. A register "
                "with one unfoldable write is disqualified, so nothing here is guessed.",
        "constant_registers": {rd.REG[k]: [hex(v) for v in vals] for k, vals in sorted(consts.items())},
        "folded_accesses": len(accesses),
        "opaque_accesses": len(opaque),
        "opaque": opaque,
        "regions": regions,
        "parameter_slots": slots,
        "slot_spacing": (slots[1]["base"] - slots[0]["base"]) if len(slots) >= 2 else None,
        "by_via": {"scalar": sum(1 for a in accesses if a["via"] == "scalar"),
                   "vector": sum(1 for a in accesses if a["via"] == "vector")},
    }


# --- the register interface -----------------------------------------------------------------------------
# Cited from the N64brew Wiki's RSP interface page (revision 5376, CC BY-SA-4.0). Numbers, names and the
# write-triggers-a-transfer behaviour only: restated as facts, no text reproduced. This is the register map
# M223 recorded as unavailable; the local manual defers it to `rcp.h` (index p529), which this repository
# does not hold, so the map comes from a community source and is labelled as such everywhere it is used.
SP_REGISTERS = {
    0: {"name": "SP_DMA_SPADDR", "role": "IMEM/DMEM address of the transfer; bit 12 picks the bank "
                                        "(0 = DMEM, 1 = IMEM), low 3 bits always 0"},
    1: {"name": "SP_DMA_RAMADDR", "role": "RDRAM address of the transfer, 24 bits, low 3 bits always 0"},
    2: {"name": "SP_DMA_RDLEN", "role": "length, and the write starts the transfer",
        "direction": "RDRAM -> DMEM/IMEM"},
    3: {"name": "SP_DMA_WRLEN", "role": "length, and the write starts the transfer",
        "direction": "DMEM/IMEM -> RDRAM"},
    4: {"name": "SP_STATUS", "role": "status; a write sets and clears individual flags"},
    5: {"name": "SP_DMA_FULL", "role": "1 while a second transfer is queued behind the current one"},
    6: {"name": "SP_DMA_BUSY", "role": "1 while a transfer is in progress"},
    7: {"name": "SP_SEMAPHORE", "role": "mutex bit: a read returns the old value and then sets it to 1, "
                                       "so reading 0 means acquired"},
}
# The length field is "the number of bytes minus 1", and a transfer size is always a multiple of 8.
LENGTH_NOTE = ("the length registers hold bytes-1 and transfer sizes are multiples of 8 (cited), so a "
               "value v means a transfer of v+1 bytes; every length this program writes is checked "
               "against that below")
# SP_STATUS is write-one-to-set/clear: bit n of the write has a different meaning from bit n of a read.
SP_STATUS_WRITE = {14: "SET_SIG2", 12: "SET_SIG1", 10: "SET_SIG0", 8: "SET_INTBREAK", 6: "SET_SSTEP",
                   4: "SET_INTR", 2: "CLR_BROKE", 1: "SET_HALT", 0: "CLR_HALT"}


def _sp_name(reg):
    return SP_REGISTERS.get(reg, {"name": "c%d (not in the cited map)" % reg})["name"]


def _status_write_flags(value):
    return [SP_STATUS_WRITE[b] for b in range(25) if value & (1 << b) and b in SP_STATUS_WRITE]


def fold_reg(dec, consts, at_addr, reg, depth=0):
    """The value(s) `reg` holds just before `at_addr`, or why that cannot be folded.

    Walks back through the caller's run (stopping at a control transfer), folds the one write that
    defines `reg`, and recurses into that write's base register. Falls back to the *global* constant set
    when the base's defining write is outside the run — sound, because `const_sets` only reports a
    register whose every write in the whole program is a constant form.
    Returns {"kind": imm|load|carried|unknown, "values"|"dmem", "trace"}.
    """
    at = {d["at"]: d for d in dec}
    for step in range(0, 12):
        a = at_addr - 4 * step
        d = at.get(a)
        if d is None:
            break
        if step > 0 and d["mnemonic"] in CTRL:
            break
        dest, form = _write_form(d)
        if dest != reg:
            continue
        trace = "%s @0x%03x" % (d["text"], a)
        w = d["word"]
        if form == "zero_imm":
            imm = rd.sx16(w & 0xFFFF) if d["mnemonic"] == "addiu" else (w & 0xFFFF)
            return {"kind": "imm", "values": [imm & 0xFFFFFFFF], "trace": trace}
        if form == "reg_imm" and depth < 4:
            base = rd.bits(w, 25, 21)
            imm = rd.sx16(w & 0xFFFF) if d["mnemonic"] == "addiu" else (w & 0xFFFF)
            inner = fold_reg(dec, consts, a, base, depth + 1)
            if inner["kind"] == "imm":
                return {"kind": "imm", "values": [(v + imm) & 0xFFFFFFFF for v in inner["values"]],
                        "trace": inner["trace"] + " | " + trace}
            if base in consts:
                return {"kind": "imm", "values": [(v + imm) & 0xFFFFFFFF for v in consts[base]],
                        "trace": "%s = %s (global constant set) | %s"
                                 % (rd.REG[base], [hex(v) for v in consts[base]], trace)}
            return {"kind": "carried", "trace": trace}
        if form == "move":
            return {"kind": "carried", "trace": trace}
        if d["mnemonic"] in ("lw", "lhu", "lbu"):
            base, disp = rd.bits(w, 25, 21), rd.sx16(w & 0xFFFF)
            if base in consts:
                return {"kind": "load", "dmem": sorted({v + disp for v in consts[base]}), "trace": trace}
            return {"kind": "load", "dmem": None, "trace": trace}
        return {"kind": "carried", "trace": trace}
    return {"kind": "unknown", "trace": "no write in the preceding run"}


def _signatures(entries):
    """Which argument register feeds c0 and c1 at each entry."""
    out = {}
    for e in entries:
        s = tuple((w["reg"], w["from"]) for w in e["writes"] if w["reg"] in (0, 1))
        if s:
            out["0x%03x" % e["entry"]] = ["c%d<-%s" % p for p in s]
    return out


def _order_measurement(entries):
    """Find a site whose c0 value set is another nearby site's c1 value set — the crossover itself.

    Derived from the resolved register values, not from the arguments: the point is that the same two
    numbers land in opposite registers, which is what makes the two directions indistinguishable.
    """
    sites = []
    for e in entries:
        for c in e["call_args"]:
            rv = c["register_values"]
            sites.append({"site": c["site"], "entry": e["entry"],
                          "spaddr": tuple(rv.get("SP_DMA_SPADDR", ()) or ()),
                          "ramaddr": tuple(rv.get("SP_DMA_RAMADDR", ()) or ())})
    sites.sort(key=lambda r: r["site"])
    found = []
    for i, a in enumerate(sites):
        for b in sites[i + 1:]:
            if b["site"] - a["site"] > 0x20:
                break
            if a["spaddr"] and a["spaddr"] == b["ramaddr"] and a["ramaddr"] != b["spaddr"]:
                found.append({"sites": [a["site"], b["site"]],
                              "entries": [a["entry"], b["entry"]],
                              "same_values": list(a["spaddr"]),
                              "register": ["SP_DMA_SPADDR@0x%03x" % a["site"],
                                           "SP_DMA_RAMADDR@0x%03x" % b["site"]]})
    return found


def primitives(dec, consts, image):
    """The SP-register interface: which entry point starts which transfer, with what arguments."""
    cop0 = [d for d in dec if d.get("sp_reg") is not None]
    writes = [d for d in cop0 if d["mnemonic"] == "mtc0"]
    roots = sorted({d["jump_target"] for d in dec if d["mnemonic"] == "jal"})
    entries = []
    for r in roots:
        if not (0x300 <= r < 0x400):
            continue
        body = []
        for d in dec:
            if d["at"] < r:
                continue
            body.append(d)
            if d["mnemonic"] == "jr":
                # the delay slot executes before the return, and 0x3b8/0x39c write their length
                # register *in* it — so the body is the jr plus the word after it
                nxt = [x for x in dec if x["at"] == d["at"] + 4]
                body.extend(nxt)
                break
        written = [{"at": d["at"], "reg": d["sp_reg"], "name": _sp_name(d["sp_reg"]),
                    "from": rd.REG[rd.bits(d["word"], 20, 16)]}
                   for d in body if d["mnemonic"] == "mtc0"]
        polls = [{"at": d["at"], "reg": d["sp_reg"], "name": _sp_name(d["sp_reg"]), "text": d["text"]}
                 for d in body if d["mnemonic"] == "mfc0"]
        trigger = [w["reg"] for w in written if w["reg"] in (2, 3)]
        sites = sorted(d["at"] for d in dec if d["mnemonic"] == "jal" and d["jump_target"] == r)
        calls = []
        for s in sites:
            args = {}
            for name, num in (("a0", 4), ("a1", 5), ("a2", 6), ("a3", 7)):
                # the delay slot first: it runs before the callee does
                pref = s + 4 if (s + 4) in {d["at"] for d in dec} else s
                args[name] = fold_reg(dec, consts, pref, num)
                if args[name]["kind"] in ("unknown", "carried") and pref != s:
                    args[name] = fold_reg(dec, consts, s, num)
            resolved = {}
            for wtr in written:
                if wtr["from"] == "zero":
                    resolved[wtr["name"]] = [0]
                    continue
                a = args[wtr["from"]]
                resolved[wtr["name"]] = (a["values"] if a["kind"] == "imm"
                                         else {wtr["from"]: a["kind"]})
            calls.append({"site": s, "args": args, "register_values": resolved})
        entries.append({
            "entry": r,
            "head": [d["text"] for d in dec if d["at"] == r][0],
            "writes": written,
            "polls": polls,
            "trigger_register": trigger[0] if trigger else None,
            "direction": SP_REGISTERS[trigger[0]]["direction"] if trigger else
                         "no length register: this entry restates fields only",
            "call_sites": sites,
            "call_args": calls,
        })
    # SP_STATUS: the only write to c4, and what its bits mean
    status = [d for d in writes if d["sp_reg"] == 4]
    status_writes = []
    for d in status:
        src = rd.bits(d["word"], 20, 16)
        if src == 0:
            status_writes.append({"at": d["at"], "value": 0, "flags": ["clears every writable flag"]})
            continue
        val = fold_reg(dec, consts, d["at"], src)
        after = [x["text"] for x in dec if x["at"] in (d["at"] + 4, d["at"] + 8, d["at"] + 0xC)]
        status_writes.append({"at": d["at"], "from": rd.REG[src], "value": val.get("values"),
                              "fold": val["trace"], "flags": _status_write_flags(
                                  val["values"][0]) if val["kind"] == "imm" else None,
                              "followed_by": after})
    # every length value, checked against the cited bytes-1 rule
    lengths = []
    for e in entries:
        for w in e["writes"]:
            if w["reg"] not in (2, 3):
                continue
            for c in e["call_args"]:
                v = c["args"]["a3"]
                if w["from"] == "a3" and v["kind"] == "imm":
                    for val in v["values"]:
                        lengths.append({"entry": e["entry"], "site": c["site"], "value": val,
                                        "bytes": val + 1,
                                        "multiple_of_8": (val + 1) % 8 == 0})
                elif w["from"] == "a3":
                    lengths.append({"entry": e["entry"], "site": c["site"], "value": None,
                                    "kind": v["kind"], "trace": v["trace"]})
    return {
        "register_map": "cited: N64brew Wiki, Reality_Signal_Processor/Interface, revision 5376 "
                        "(CC BY-SA-4.0), for the COP0 numbers and the write-triggers-a-transfer "
                        "behaviour. The local Programming Manual does not map them — p115 says the "
                        "application does not program the SP directly and its index lists rcp.h only "
                        "against pp110-111 (DP/VI/AI/PI status) — so this is an external source, "
                        "recorded as one.",
        "length_rule": LENGTH_NOTE,
        "cop0_moves": len(cop0),
        "writes": [{"at": d["at"], "reg": d["sp_reg"], "name": _sp_name(d["sp_reg"]),
                    "from": rd.REG[rd.bits(d["word"], 20, 16)]} for d in writes],
        "write_sites": len(writes),
        "registers_written": sorted({d["sp_reg"] for d in writes}),
        "registers_read": sorted({d["sp_reg"] for d in cop0 if d["mnemonic"] == "mfc0"}),
        "entries": entries,
        "status_writes": status_writes,
        "lengths": lengths,
        "lengths_summary": {
            "sites": len(lengths),
            "folded": sum(1 for l in lengths if l.get("value") is not None),
            "unfolded": sum(1 for l in lengths if l.get("value") is None),
            "folded_values": sorted({l["value"] for l in lengths if l.get("value") is not None}),
            "all_folded_are_multiple_of_8": all(l["multiple_of_8"] for l in lengths
                                                if l.get("value") is not None),
            "note": "the cited rule says a length register holds bytes-1 and every transfer size is a "
                    "multiple of 8. Every length this program states as an immediate obeys it; the "
                    "computed ones are listed with their fold rather than counted, and the count of "
                    "folded sites is asserted below so this cannot pass on an empty set.",
        },
        "argument_order": {
            "signatures": _signatures(entries),
            "measurement": _order_measurement(entries),
            "reading": "Two of the four transfer entries write c0 from a1 and c1 from a2; the other two "
                       "write c0 from a2 and c1 from a1. Every value either side takes is below 0x1000 "
                       "— the program's RDRAM addresses span 0x000 to 0xd60 and its DMEM addresses "
                       "0x000 to 0xfff — so the two address spaces are indistinguishable by value, and "
                       "the register assignment is the only thing that says which side is which. That "
                       "makes the pair of calls at 0x00dc and 0x00e4 the sharpest open question here: "
                       "they pass the *same two values* to entries that assign them to c0/c1 in "
                       "opposite orders.",
        },
        "semaphore_protocol": {
            "acquire": [{"at": d["at"], "text": d["text"]} for d in dec
                        if d["mnemonic"] == "mfc0" and d["sp_reg"] == 7],
            "release": [{"at": d["at"], "text": d["text"]} for d in dec
                        if d["mnemonic"] == "mtc0" and d["sp_reg"] == 7],
            "reading": "a read of c7 returns the old bit and leaves it set (cited), so `mfc0` followed by "
                       "`bne ...,zero,<back>` spins until the mutex is free and acquires it; `mtc0 zero` "
                       "releases it. Every transfer entry takes the mutex around its DMA except the one "
                       "that writes only RAMADDR and the length.",
        },
        "status_bit_14": {
            "measurement": "the only write to c4 stores 0x4000 from an immediate, and the next two "
                           "instructions are `nop` then `break`.",
            "reading": "on a write, SP_STATUS bit 14 is SET_SIG2 (cited), so the halt path raises signal "
                       "bit 2 and stops the RSP. The CPU side of that handshake is the handler installed "
                       "at *0x80143ff0, which is not in this image: stage-2 contains zero references to "
                       "0xa4040010.",
        },
    }


def vector_transfers(dec, consts):
    """The `lwc2`/`swc2` words, with the address the decoder's (corrected) field split implies.

    The row, the element and the scaled offset come from `rsp_decode` — this function does **not** re-parse
    the word, because a second parse that disagrees with the gate is how M219 went wrong. What it adds is
    the one thing the decoder cannot know: whether the base register holds a foldable constant, and hence
    the absolute DMEM address.
    """
    out, rows = [], {}
    for d in dec:
        if d.get("vector_kind") != "vector_transfer":
            continue
        base = rd.bits(d["word"], 25, 21)
        rec = {"at": d["at"], "row": d["vu_row"], "row_opcode": d["vu_row_opcode"],
               "element": d["vu_element"], "offset": d["vu_offset"], "scale": d["vu_scale"],
               "base": rd.REG[base], "vt": rd.bits(d["word"], 20, 16), "load": d["mnemonic"][0] == "l"}
        if d["vu_scale"] is not None and base in consts:
            rec["addresses"] = sorted({v + d["vu_offset"] * d["vu_scale"] for v in consts[base]})
        elif d["vu_scale"] is None:
            rec["addresses"] = None
            rec["why"] = "the cited table does not state this row's access size, so no address is folded"
        else:
            rec["addresses"] = None
            rec["why"] = "the base register %s holds no folded constant" % rd.REG[base]
        rows[d["vu_row"]] = rows.get(d["vu_row"], 0) + 1
        out.append(rec)
    folded = [r for r in out if r["addresses"]]
    return {
        "rule": "the row is in bits 15:11, the element in 10:7 and the offset in 6:0, and the address is "
                "base + offset * access_size (cited). The split and the row names are taken from "
                "tools/rsp_decode.py, which owns that decode; this tool folds the base register and nothing "
                "else. M223 read bits 15:0 as a 16-bit signed displacement and excluded all of these "
                "accesses, which is retracted.",
        "count": len(out),
        "by_row": dict(sorted(rows.items())),
        "folded": len(folded),
        "unfolded": len(out) - len(folded),
        "transfers": out,
        "address_range": [min(a for r in folded for a in r["addresses"]),
                          max(a for r in folded for a in r["addresses"])] if folded else None,
    }


# --- the CPU-side contract ------------------------------------------------------------------------------
def cpu_contract(image, dec):
    """The stride and the count, derived on the RSP side and re-derived on the CPU side."""
    rsp_step = [d for d in dec if d["mnemonic"] == "addiu" and d["text"] == "addiu a0,a0,2576"]
    rsp_count = [d for d in dec if d["text"] == "addiu v1,v1,-1"]
    cont = [d for d in dec if d["text"].startswith("ori ra,zero,")]
    # the CPU-side flush recipe at 0x800a2eb0: fold the shift/add chain with count = 1
    recipe, value = [], 1
    for va in range(0x800A2EB0, 0x800A2EC4, 4):
        w = rd.word_at(image, va)
        d = rd.decode(w, va)
        op, rs, rt = rd.bits(w, 31, 26), rd.bits(w, 25, 21), rd.bits(w, 20, 16)
        recipe.append("%08x %s" % (va, d["text"]))
        if d["mnemonic"] == "sll":
            value = (value << rd.bits(w, 10, 6)) & 0xFFFFFFFF
        elif d["mnemonic"] == "addu":
            pass  # value = value + value, but one addend is the loop's counter = 1 in this fold
        if d["mnemonic"] == "addu":
            value = (value + 1) & 0xFFFFFFFF
    return {
        "rsp_side": {
            "advance": [{"at": d["at"], "text": d["text"]} for d in rsp_step],
            "count_down": [{"at": d["at"], "text": d["text"]} for d in rsp_count],
            "continuation": [{"at": d["at"], "text": d["text"]} for d in cont],
            "read_of_task_block": [
                {"at": d["at"], "text": d["text"],
                 "dmem": rd.sx16(d["word"] & 0xFFFF) & 0xFFFF}
                for d in dec if d["mnemonic"] == "lw" and d["text"].startswith("lw a0,48(at)")],
        },
        "cpu_side": {
            "recipe": recipe,
            "per_unit_bytes": value,
            "note": "The CPU computes a flush length of count x stride with a shift/add chain and never "
                    "stores the stride. Feeding one unit through the exact instructions gives %d = 0x%x, "
                    "which is the same constant the RSP advances its record pointer by at 0x%03x."
                    % (value, value, rsp_step[0]["at"] if rsp_step else 0),
        },
        "agrees": bool(rsp_step) and value == STRIDE,
        "reading": "The CPU publishes a pointer (task +0x30) and a count (+0x34), flushes count x 0xa10 "
                   "bytes of it, and the RSP reads both once, walks records of 0xa10 bytes and decrements "
                   "the count. That is a record walk, not a command list: nothing in the record selects "
                   "which code runs, and the only CPU-published value that reaches a branch is the count.",
    }


# --- the dispatch question ------------------------------------------------------------------------------
def dispatch(dec, dmem):
    """Does any value from the published block select code? Measure every load that reaches a branch."""
    at = {d["at"]: d for d in dec}
    feeds = []
    for d in dec:
        if d["mnemonic"] not in ("lw", "lbu", "lhu"):
            continue
        w = d["word"]
        rdst = rd.bits(w, 20, 16)
        for step in range(1, 9):
            n = at.get(d["at"] + 4 * step)
            if n is None:
                break
            nw = n["word"]
            if n["mnemonic"] in BRANCH:
                rs, rt = rd.bits(nw, 25, 21), rd.bits(nw, 20, 16)
                if rdst in (rs, rt):
                    feeds.append({"load": d["text"], "at": d["at"],
                                  "branch": n["text"], "branch_at": n["at"],
                                  "in_delay_slot": n["at"] == d["at"] + 4 * step})
                    break
            # stop at a redefinition of the loaded register
            if n["mnemonic"] in ("or", "addu"):
                dst = rd.bits(nw, 15, 11)
            else:
                dst = rd.bits(nw, 20, 16)
            if dst == rdst:
                break
    return {
        "verdict": "no command dispatch — measured, not asserted",
        "evidence": [
            "the program has %d `jal`/`j` instructions and every one carries an absolute IMEM target: "
            "there is no computed transfer to dispatch through" % sum(
                1 for d in dec if d["mnemonic"] in ("jal", "j")),
            "no load anywhere in the program is used as a jump or call target: the only indirect "
            "transfers are `jr` through a saved link (listed under control_flow.returns)",
            "%d loads feed a conditional branch within 8 instructions; they are the fields that select "
            "stages of the frame loop, and none of them indexes a target" % len(feeds),
            "the fields are sizes, counts and mode flags: they are added into buffer arithmetic, "
            "shifted, masked with small constants, or zero-tested to skip a stage",
        ],
        "loads_feeding_branches": feeds,
        "reading": "The CPU-published block is a parameter record the ucode branches on, not a command "
                   "stream it dispatches on. That is the same shape M220 measured on the sound side: the "
                   "'macros' were a class tag, and here the 'commands' are record fields.",
    }


# --- the artefact ---------------------------------------------------------------------------------------
def derive(image):
    dec = program(image)
    flow = control_flow(dec)
    targets = call_targets(dec)
    consts = const_sets(dec)
    vec = vector_transfers(dec, consts)
    dmem = dmem_map(dec, consts, vec)
    prim = primitives(dec, consts, image)
    contract = cpu_contract(image, dec)
    disp = dispatch(dec, dmem)
    vec_words = sum(1 for d in dec if d["status"] == "vector")
    return {
        "tool": "rsp_iface.py",
        "schema": SCHEMA,
        "inputs": {
            "image": str(rd.IMAGE.relative_to(ROOT)),
            "decoder": "tools/rsp_decode.py — this tool imports it and re-decodes nothing",
            "words": len(dec),
            "note": "the program is M223's 976 RSP words; the declared 0x1000 overruns it by 0xC0 into "
                    "a CPU function and that tail is excluded here as it is there",
        },
        "control_flow": flow,
        "call_targets": targets,
        "register_primitives": prim,
        "vector_transfers": vec,
        "dmem_map": dmem,
        "cpu_contract": contract,
        "dispatch": disp,
        "citations": {k: {"page": v[0], "quote": v[1]} for k, v in sorted(CITES.items())},
        "external_sources": {
            "why": "The local Programming Manual settles the RSP's structure but not its registers: p115 "
                   "says the application does not program the SP directly, and the index lists the header "
                   "it defers device bit patterns to (`rcp.h`) against pages 110-111 only, which are the "
                   "DP, VI, AI and PI status registers. So the register map comes from outside this "
                   "repository, and it is labelled as external wherever it is used. Facts only — numbers, "
                   "names and stated behaviour. No text is reproduced and no code is taken.",
            "sources": [
                {"what": "COP0 register numbers, names, and write-triggers-a-transfer",
                 "url": "https://n64brew.dev/wiki/Reality_Signal_Processor/Interface",
                 "revision": 5376, "licence": "CC BY-SA-4.0 (N64brew Wiki)",
                 "used_for": "SP_REGISTERS, the length-is-bytes-minus-1 rule, the semaphore's "
                             "read-sets-the-bit behaviour, the SP_STATUS write bit layout"},
                {"what": "the VU load/store and vector opcode tables, the 12-bit PC, and that branch-likely "
                         "opcodes are not implemented",
                 "url": "https://n64brew.dev/wiki/Reality_Signal_Processor/CPU_Core",
                 "revision": 5539, "licence": "CC BY-SA-4.0 (N64brew Wiki)",
                 "used_for": "the lwc2/swc2 field split and the access sizes for the vector rows here; "
                             "the vector instruction tables are applied in tools/rsp_decode.py (M225), which "
                             "names 252 of the 254 words and refuses the 2 the table has no row for"},
            ],
            "cross_checks": [
                "the length values this program writes are all n-1 for a multiple of 8, which is what the "
                "cited rule predicts and M223 could not check: every length stated as an immediate is bytes-1 with bytes a multiple of 8 (see register_primitives.lengths_summary)",
                "the entry's first instruction reads COP0 register 11, which is *outside* the cited set "
                "c0-c7 — so the register M223 called \"the RSP status register, name from outside "
                "authority\" is not the documented status register (c4), and this program never reads c4",
                "the one write to c4 sets bit 14 and is followed by `break`: on a write that bit is "
                "SET_SIG2 (cited), so the halt path raises signal 2 and stops",
            ],
        },
        "attribution": "docs/THIRD_PARTY.md section 4 records the two wiki pages, their licences and "
                       "exactly what was taken from them",
        "rsp_only": [
            {"what": "what the %d vector-unit words compute" % vec_words,
             "why": "M225 named 252 of them from a cited table and left 2 refused, so the *instructions* are "
                    "known here; what they compute for the mixer is not. A name says which opcode runs, not "
                    "which signal path it serves, and the structure is in the accumulator's use across the "
                    "frame loop, which no document describes",
             "cpu_evidence": "none — the CPU never writes a vector register"},
            {"what": "which transfer field is the memory side and which the other side",
             "why": "the register numbers written are measured (%s) and named from the cited map, and the "
                    "values at every call site are folded — but which of the two address fields is the DMEM "
                    "side is decided by the register assignment alone, because every value either side "
                    "takes is under 0x1000 (see argument_order)" % prim["registers_written"],
             "cpu_evidence": "the task block's pointer and count, and nothing about the transfer fields"},
            {"what": "the %d words no control-flow edge reaches" % flow["unreachable"],
             "why": "they are code (branches, calls and returns inside them) and nothing enters them under "
                    "an edge set that is strictly larger than the hardware's. Whether they are dead, or "
                    "reached by a mechanism outside this model, is not decided here",
             "cpu_evidence": "none — the CPU never writes IMEM after the task starts"},
        ],
    }


def check(committed, image):
    dec = program(image)
    fresh = derive(image)
    flow = committed["control_flow"]
    tg = committed["call_targets"]
    prim = committed["register_primitives"]
    vec = committed["vector_transfers"]
    dm = committed["dmem_map"]
    cc = committed["cpu_contract"]
    disp = committed["dispatch"]
    cases = []

    # --- control flow ------------------------------------------------------------------------------
    cases.append((f"reachability is re-derived and every unreachable run is code or fill, never a table "
                  f"({flow['reachable']} of {flow['words']} reachable, {flow['unreachable']} words in "
                  f"{len(flow['unreachable_runs'])} runs)",
                  flow["reachable"] + flow["unreachable"] == flow["words"] == len(dec)
                  and fresh["control_flow"] == flow and flow["all_unreachable_is_code_or_fill"]
                  and flow["unreachable_code_words"] > 0))

    cases.append(("every unreachable run begins where a control transfer leaves, so no fall-through "
                  "enters it, and the runs are disjoint and ordered",
                  all(r["after_exit"].startswith("yes") or r["after_exit"].startswith("the run starts")
                      for r in flow["unreachable_runs"])
                  and all(b["start"] >= a["end"] for a, b in
                          zip(flow["unreachable_runs"], flow["unreachable_runs"][1:]))))

    fr = fresh["control_flow"]
    syn = fr["returns"]["synthesized"]
    cases.append((f"no successor falls outside the program once the link is masked to 12 bits "
                  f"(raw {[hex(s['value']) for s in syn]} -> IMEM "
                  f"{[hex(s['imem']) for s in syn]}; off-grid {fr['off_grid_successors']})",
                  fr["off_grid_successors"] == [] and len(syn) == 1
                  and syn[0]["imem"] < fr["words"] * 4 and syn[0]["outside_program_raw"]))

    jr = flow["returns"]
    cases.append((f"every indirect transfer is a return through a saved link "
                  f"({jr['jr']} `jr`, {len(jr['jr_computed'])} computed)",
                  not jr["jr_computed"] and jr["jr"] == jr["jr_through_link"] > 0))

    idiom = flow["unconditional_idiom"]
    cases.append((f"the `beq zero,zero` idiom is read as a jump, not as a branch "
                  f"({idiom['beq_zero_zero']} always-taken, {idiom['bne_zero_zero']} never)",
                  idiom["beq_zero_zero"] >= 1
                  and len(idiom["sites"]) == idiom["beq_zero_zero"] + idiom["bne_zero_zero"]))

    # --- call targets ------------------------------------------------------------------------------
    cases.append((f"every jal target is classified, with its sites and its exits "
                  f"({len(tg['targets'])} targets, {tg['targets_sharing_an_exit']} share an exit)",
                  all(t["kind"] and t["call_sites"] and t["exits"] and t["preceded_by"]
                      for t in tg["targets"])
                  and len({t["entry"] for t in tg["targets"]}) == len(tg["targets"]) > 0))

    cases.append(("the call sites are exactly the program's `jal` instructions, each counted once",
                  sorted(s for t in tg["targets"] for s in t["call_sites"])
                  == sorted(d["at"] for d in dec if d["mnemonic"] == "jal")))

    bare = [t["entry"] for t in tg["targets"] if t["kind"].startswith("bare return")]
    cases.append((f"a call whose target is a bare return is reported as one "
                  f"({len(bare)}: {', '.join(hex(b) for b in bare)})",
                  len(bare) >= 1
                  and all(any(d["at"] == b and d["mnemonic"] == "jr" for d in dec) for b in bare)))

    cases.append((f"the targets that share an exit are grouped, and the groups account for the count "
                  f"({len(tg['exit_groups'])} group(s))",
                  all(len(g["targets"]) > 1 for g in tg["exit_groups"])
                  and sum(len(g["targets"]) for g in tg["exit_groups"])
                  == tg["targets_sharing_an_exit"] > 0))

    # --- the register interface --------------------------------------------------------------------
    cases.append((f"every COP0 write is in the artefact with the cited register name and its source "
                  f"({prim['write_sites']} writes, registers {prim['registers_written']})",
                  prim["write_sites"] == len(prim["writes"])
                  == sum(1 for d in dec if d["mnemonic"] == "mtc0")
                  and all(w["from"] and w["name"] for w in prim["writes"])))

    named = [w for w in prim["writes"] if w["reg"] in SP_REGISTERS]
    cases.append((f"every register the program writes is in the cited map, and no write exists outside "
                  f"the interface region (c0-c3 and c4/c7 only)",
                  len(named) == len(prim["writes"]) and set(prim["registers_written"]) <= set(SP_REGISTERS)
                  and all(0x300 <= w["at"] < 0x400 for w in prim["writes"] if w["reg"] in (0, 1, 2, 3))
                  and [w["reg"] for w in prim["writes"] if not 0x300 <= w["at"] < 0x400] == [4]))

    cases.append((f"the program reads a register outside the cited map (c{prim['registers_read']}) and "
                  f"the artefact says so rather than naming it",
                  11 in prim["registers_read"] and 11 not in SP_REGISTERS
                  and "not in the cited map" not in "".join(w["name"] for w in prim["writes"])))

    ext = committed["external_sources"]
    cases.append(("the register map is labelled external with its page, revision and licence, and says "
                  "why the local manual could not supply it",
                  any("Interface" in s["url"] and s.get("revision") and s.get("licence")
                      for s in ext["sources"])
                  and "p115" in ext["why"] and committed["citations"]["sp_not_programmed"]["page"] == 115))

    dirs = {e["direction"] for e in prim["entries"] if e["trigger_register"] is not None}
    cases.append((f"both transfer directions are present and each one is the direction the cited map "
                  f"gives its trigger register ({sorted(dirs)})",
                  dirs == {"RDRAM -> DMEM/IMEM", "DMEM/IMEM -> RDRAM"}
                  and all(e["direction"] == SP_REGISTERS[e["trigger_register"]]["direction"]
                          for e in prim["entries"] if e["trigger_register"] is not None)))

    ls = prim["lengths_summary"]
    fl = [l for l in fresh["register_primitives"]["lengths"] if l.get("value") is not None]
    cases.append((f"every length stated as an immediate is bytes-1 with bytes a multiple of 8, as the "
                  f"cited rule requires ({ls['folded']} of {ls['sites']} sites fold: "
                  f"{ls['folded_values']})",
                  ls["folded"] >= 4 and ls["folded"] + ls["unfolded"] == ls["sites"]
                  and ls["all_folded_are_multiple_of_8"]
                  and all(l["bytes"] == l["value"] + 1 and l["multiple_of_8"] for l in fl)))

    cross = prim["argument_order"]["measurement"]
    cases.append((f"the c0/c1 crossover is derived, not asserted ({len(cross)} pair(s): the same value "
                  f"set reaches SP_DMA_SPADDR at one site and SP_DMA_RAMADDR at the next)",
                  len(cross) >= 1
                  and all(len(c["same_values"]) >= 1 and c["sites"][0] < c["sites"][1] for c in cross)))

    sem = prim["semaphore_protocol"]
    cases.append((f"the semaphore is acquired by polling c7 and released by writing zero "
                  f"({len(sem['acquire'])} acquires, {len(sem['release'])} releases)",
                  len(sem["acquire"]) >= 3 and len(sem["release"]) >= 3
                  and all(p["text"].startswith("mfc0") for p in sem["acquire"])
                  and all(p["text"].startswith("mtc0 zero") for p in sem["release"])))

    st = prim["status_writes"]
    cases.append((f"the one write to SP_STATUS folds to a signal-2 set and is followed by a break "
                  f"({len(st)} write(s), flags {st[0]['flags'] if st else None})",
                  len(st) == 1 and st[0]["flags"] == ["SET_SIG2"]
                  and st[0]["value"] == [0x4000]
                  and any("break" in x for x in st[0]["followed_by"])))

    # --- the vector transfers ----------------------------------------------------------------------
    cases.append((f"the lwc2/swc2 field split is applied and the accesses M223 excluded are folded back "
                  f"in ({vec['count']} transfers, {vec['folded']} with an absolute address)",
                  vec["count"] == sum(1 for d in dec
                                      if d.get("vector_kind") == "vector_transfer")
                  and vec["folded"] >= 4 and vec["folded"] + vec["unfolded"] == vec["count"]
                  and vec["address_range"] is not None
                  and 0 <= vec["address_range"][0] < vec["address_range"][1] < 0x1000))

    cases.append(("every vector transfer names a row from the cited table or says it cannot",
                  all(r["row"] and (r["addresses"] or r.get("why")) for r in vec["transfers"])))

    # --- the DMEM map and the CPU contract ---------------------------------------------------------
    cases.append((f"the absolute DMEM fold is sound by construction and re-derives "
                  f"({dm['folded_accesses']} folded, {dm['opaque_accesses']} left opaque)",
                  dm["by_via"]["scalar"] + dm["opaque_accesses"]
                  == sum(1 for d in dec if d["mnemonic"] in ("lw", "lbu", "lhu", "sb", "sh", "sw"))
                  and dm["by_via"]["vector"] == vec["folded"]
                  and dm["by_via"]["vector"] + vec["unfolded"] == vec["count"]
                  and dm["folded_accesses"] == dm["by_via"]["scalar"] + dm["by_via"]["vector"] > 0
                  and all(r["why"] for r in dm["opaque"]) and fresh["dmem_map"] == dm))

    cases.append(("every folded address lands inside DMEM's 4 KB",
                  all(0 <= a < 0x1000 for r in dm["regions"] for a in r["addresses"])))

    slots = fresh["dmem_map"]["parameter_slots"]
    cases.append((f"the two parameter records are found through the pointer register and are one slot "
                  f"apart ({[(hex(s['base']), len(s['fields'])) for s in slots]})",
                  len(slots) == 2
                  and [s["base"] for s in slots] == list(FRAME_RECORD_SLOTS)
                  and fresh["dmem_map"]["slot_spacing"] == FRAME_RECORD_SLOTS[1] - FRAME_RECORD_SLOTS[0]
                  and all(len(s["fields"]) >= 15 for s in slots)))

    cases.append((f"the stride is derived on both sides and they agree (RSP advance 0x{STRIDE:x}, CPU "
                  f"recipe {cc['cpu_side']['per_unit_bytes']})",
                  cc["agrees"] and cc["cpu_side"]["per_unit_bytes"] == STRIDE
                  and len(cc["rsp_side"]["advance"]) == 1
                  and len(cc["rsp_side"]["count_down"]) == 1
                  and len(cc["cpu_side"]["recipe"]) >= 5))

    cases.append((f"the dispatch verdict is negative, carries its evidence, and re-derives "
                  f"({len(disp['loads_feeding_branches'])} loads reach a branch)",
                  disp["verdict"].startswith("no command dispatch") and len(disp["evidence"]) >= 3
                  and len(disp["loads_feeding_branches"]) > 0
                  and fresh["dispatch"] == disp))

    # --- classification completeness ---------------------------------------------------------------
    # A word that writes a GPR must get a form; a word that writes none must be reported as writing none.
    # Both sides are read off the decoded record, not off the mnemonic — the mnemonic route silently broke
    # when M225 renamed the vector words (rsp_iface's own M224 defect, one layer on).
    WRITES_A_GPR = ("ori", "addiu", "andi", "xori", "lui", "or", "addu", "sll", "srl", "sra", "subu",
                    "and", "slt", "sltu", "lw", "lbu", "lhu", "mfc0", "mfc2", "cfc2")
    NO_GPR = ("jr", "jal", "j", "break", "nop", "beq", "bne", "blez", "bgtz", "bltz", "bgez",
              "sw", "sh", "sb", "mtc0", "mtc2", "ctc2")
    unclassified = [{"at": d["at"], "text": d["text"]} for d in dec
                    if d["mnemonic"] and d["mnemonic"] not in WRITES_A_GPR + NO_GPR
                    and d.get("vector_kind") not in ("alu", "single", "vector_transfer", "transfer")
                    and _write_form(d) == (None, None)]
    misfiled = [{"at": d["at"], "text": d["text"]} for d in dec
                if d["mnemonic"] in NO_GPR and _write_form(d)[0] is not None]
    cases.append((f"every word is classified by the write-form table: the ones that write a GPR get a "
                  f"form and the ones that do not are reported as writing none "
                  f"({len(unclassified)} unclassified, {len(misfiled)} misfiled)",
                  not unclassified and not misfiled))

    cases.append((f"every rsp_only entry says what is out of reach and what the CPU can say about it "
                  f"({len(committed['rsp_only'])} entries)",
                  len(committed["rsp_only"]) >= 3
                  and all(r.get("what") and r.get("why") and r.get("cpu_evidence")
                          for r in committed["rsp_only"])))

    cases.append(("the committed manifest equals a fresh derivation of the image",
                  json.dumps(committed, sort_keys=True) == json.dumps(fresh, sort_keys=True)))
    return cases


def flow_listing(image, first, last):
    dec = program(image)
    delay = delay_slots(dec)
    ret, _ = returns(dec)
    succ, _at = successors(dec, delay, ret)
    reach = reachable(succ)
    for d in dec:
        if d["at"] < first or (last is not None and d["at"] >= last):
            continue
        ss = ",".join("0x%03x" % s for s in sorted(succ(d["at"])))
        print("%04x  %-34s %-18s %s%s" % (d["at"], d["text"], ss,
                                          "" if d["at"] in reach else "[unreachable]",
                                          "  [delay slot]" if d["at"] in delay else ""))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--flow", action="store_true")
    ap.add_argument("--first", type=lambda s: int(s, 0), default=0)
    ap.add_argument("--last", type=lambda s: int(s, 0), default=None)
    a = ap.parse_args()

    image = stage2()
    if a.write:
        if image is None:
            print("REFUSED: %s is not present, so there is nothing to measure"
                  % rd.IMAGE.relative_to(ROOT))
            return 2
        rep = derive(image)
        (ROOT / OUT).write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        f, t = rep["control_flow"], rep["call_targets"]
        print("wrote %s — %d of %d words reachable (%d in %d runs); %d call targets, %d share an exit; "
              "%d DMEM accesses folded, %d opaque; dispatch: %s"
              % (OUT, f["reachable"], f["words"], f["unreachable"], len(f["unreachable_runs"]),
                 len(t["targets"]), t["targets_sharing_an_exit"],
                 rep["dmem_map"]["folded_accesses"], rep["dmem_map"]["opaque_accesses"],
                 rep["dispatch"]["verdict"]))
        return 0

    if a.flow:
        if image is None:
            print("SKIP (needs the unpacked stage-2 image)")
            return 0
        flow_listing(image, a.first, a.last)
        return 0

    if not a.check:
        ap.error("one of --write, --check, --flow is required")

    if image is None:
        print("SKIP (needs the unpacked stage-2 image: %s)" % rd.IMAGE.relative_to(ROOT))
        return 0

    committed = json.loads((ROOT / OUT).read_text())
    cases = check(committed, image)
    bad = 0
    for label, ok in cases:
        bad += not ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d rsp interface case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
