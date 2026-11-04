#!/usr/bin/env python3
"""M211: the derived opcode registry — one record per stage-2 opcode, and what it is allowed to claim.

`fixtures/scd/registry.json` answers one question per opcode: **where does this handler send the command
pointer, and on what evidence?** It gathers what until now lived in four different places —

  * the published advance and the control-flow class (`fixtures/scd/profile.json`, status ok|jump|dynamic);
  * the name and its provenance (`fixtures/scd/opcodes.json` = the MIT-licensed PlayStation table,
    `fixtures/scd/inferred_names.json` = read out of these handlers by this project, `measured` reserved for
    a name this project established by measurement — no opcode uses it yet);
  * the handler address, and the advance `tools/walk_stream.py` measures with its forward dataflow;
  * how the handler actually writes `ctx+0x1c`, re-read from the handler's own instructions or from its
    decompiled body wherever the dataflow and the code disagree;
  * whether the corpus contains the handler at all. 82 of the 138 distinct handler addresses are not inside
    any Ghidra function body in `fixtures/decomp/ranges.json`, so no `src/stage2/FUN_<handler>.c` exists for
    them. `in_function_body` says which, and `evidence` follows it: `"walk_stream.resolve"` where the corpus
    has a body, `"walk_stream.resolve (bytes)"` where the advance can only have come from the image, and a
    `path:line` citation only where the body was actually read.

It **refuses** to claim four things, and each refusal is enforced by `--check`:

  * **that a folded constant is a constant.** `walk_stream.advance_set` is a linear forward dataflow with no
    path sensitivity, so for opcodes `0x0d` and `0x1b` it reports `[6, 12]`. The truth is one constant path
    — 6, the fall-through into the loop body (`0x8006de50 addiu a3,a3,6` -> `0x8006de80 sw a3,28(t2)`) — and
    one *variable* path, `cmd + s16[cmd+2] + 6`, the loop-exit skip (`lh t0,2(a3)` -> `addu` -> `addiu +6` ->
    `sw`). The `12` is the scan carrying `a3 = cmd+6` across the two mutually exclusive branch arms
    (`0x8006de30 beq v0,zero,0x8006dea4`), so nothing ever advances by 12. The folded shape in its C form is
    `src/stage2/FUN_8006d5dc.c:22`, `*(uint *)(param_1 + 0x1c) = iVar2 + (uint)uVar1;` — a pointer set from a
    loaded value, which is why the registry stores `{"kind": "variable"}` for such a path and no value at all.
  * **a length for the six `dynamic` opcodes.** Their profile length is null, so `published` is null: the
    number would be invented, and the handler's destination is a saved pointer or a table entry.
  * **anything about the scheduler.** Every `scheduler_effect` is `"unknown"`; the key exists so M212 can fill
    it without changing the schema (or invalidating this tool's `--check`).
  * **a name where none is known.** An unnamed opcode keeps `name: null` and `name_source: null`; an inferred
    name is attributed to `inferred_names.json` and never inherits the PlayStation table's authority.

Two further conventions. A `constant` entry carries a number and nothing else. A `variable` entry carries the
expression that computes the pointer, the address of the `sw ...,0x1c(...)` it was read from, and the source
line it was inferred from — the decompiled body where one exists, otherwise the line in `tools/walk_stream.py`
or `fixtures/scd/inferred_names.json` that already recorded the same instructions. And `published` is the
*profile's* number, not this tool's measurement: where it is not one of the handler's own constant advances
(`0x07`, `0x13`, `0x17`, `0x18`) the registry says so instead of manufacturing a constant to match.

Usage:
  ./opcode_registry.py --write      # regenerate fixtures/scd/registry.json from the inputs
  ./opcode_registry.py --check      # validate the committed registry against the inputs
"""
import argparse
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import walk_stream

PROFILE = "fixtures/scd/profile.json"
REGISTRY = "fixtures/scd/registry.json"
OPCODES = "fixtures/scd/opcodes.json"
INFERRED = "fixtures/scd/inferred_names.json"
WALK = "tools/walk_stream.py"
ENTRIES = walk_stream.TABLE_ENTRIES
BASE = walk_stream.STAGE2_BASE
CTX_CMDPTR = walk_stream.CTX_CMDPTR

NAME_SOURCE = {"ps1": "opcodes.json", "inferred": "inferred_names.json", None: None}
SCHEDULER = "unknown"

# Handlers that both advance by a constant and re-point `ctx+0x1c` at a computed or saved address. For these
# the constant alone would be a lie, so both paths are recorded. Verified per opcode below.
CONSTANT_PATH = {
    0x0D: 6,      # the fall-through into the loop body: 0x8006de50 addiu a3,a3,6 -> 0x8006de80 sw a3,28(t2)
    0x0E: 2,      # the counter-expiry path: 0x8006dfc8 addiu v0,v0,2 -> 0x8006dfcc sw v0,28(a0)
    0x0F: 4,      # the block body: 0x8006e040 addiu a3,4(a1) -> 0x8006e070 sw v0,28(s1)
    0x12: 2,      # the header advance: 0x8006e1a4 sw v1,28(s1) on the constant arm (FUN_8006e138.c:18)
    0x1B: 6,      # the fall-through into the loop body: 0x8006df00 addiu a3,a3,6 -> 0x8006df3c sw a3,28(t2)
    # M226: 0x36 is a constant after all. Its handler dispatches through a static five-entry table at
    # 0x800b98e0 (not 0x800c98e0 -- that is `addiu v0,v0,-26400`'s immediate read unsigned, -0x6720 gives a
    # base 0x10000 lower) and *every* arm then runs one tail: 0x800712c8 addiu v0,s0,12 -> 0x800712cc
    # sw v0,28(s1). The store is outside the handler's Ghidra extent, which is why the scan sees nothing;
    # tools/callback_table.py measures it from the five arms, and the extent correction is queued.
    0x36: 12,
}

# The computed `ctx+0x1c` write no constant covers: expression, the `sw` it was read from, and how to cite it.
# ("walk", n) cites the tools/walk_stream.py line that records opcode n's instruction trace; ("inferred", n)
# cites the fixtures/scd/inferred_names.json evidence line for its handler; ("src", path) cites the last
# `... + 0x1c) = ...` line of that decompiled body (the re-pointing write, not the header advance above it).
VARIABLE_PATH = {
    0x01: dict(expression="*(ctx + 0x144 + (s8[ctx+2] - 1) * 4)", store="0x8006db78",
               cite=("walk", 0x01)),
    0x03: dict(expression="*(0x80114f2c) + u16[cmd+3]", store="0x8006d624",
               cite=("src", "src/stage2/FUN_8006d5dc.c")),
    0x07: dict(expression="cmd + u16[cmd+2]", store="0x8006dc90", cite=("walk", 0x07)),
    0x0D: dict(expression="cmd + s16[cmd+2] + 6", store="0x8006deb0", cite=("walk", 0x0D)),
    0x0E: dict(expression="*(ctx + s8[ctx+2]*16 + s8[ctx+s8[ctx+2]+8]*4 + 0x20)", store="0x8006dfc0",
               cite=("inferred", 0x0E)),
    0x0F: dict(expression="*(ctx + s8[ctx+2]*16 + (s8[ctx+s8[ctx+2]+8] + 1)*4 + 0x60)", store="0x8006e070",
               cite=("src", "src/stage2/FUN_8006dfe4.c")),
    0x10: dict(expression="*(ctx + s8[ctx+2]*16 + s8[ctx+s8[ctx+2]+8]*4 + 0x20)", store="0x8006e0bc",
               cite=("walk", 0x10)),
    0x12: dict(expression="*(ctx + s8[ctx+2]*16 + s8[ctx+s8[ctx+2]+8]*4 + 0x20)", store="0x8006e1a4",
               cite=("src", "src/stage2/FUN_8006e138.c")),
    0x13: dict(expression="cmd + 4, scanned by entry + u16[entry+2]; exit entry + 2 (tag 0x15) or entry + 6 "
                          "(case match)", store="0x8006e32c", cite=("walk", 0x13)),
    0x17: dict(expression="cmd + s16[cmd+4]", store="0x8006e3d0", cite=("walk", 0x17)),
    0x18: dict(expression="*(0x80114f2c) + u16[cmd+1]", store="0x8006e430", cite=("walk", 0x18)),
    0x19: dict(expression="*(ctx + 0x144 + (u8[ctx+2] - 1) * 4)", store="0x8006e45c", cite=("walk", 0x19)),
    0x1A: dict(expression="*(ctx + s8[ctx+2]*16 + s8[ctx+s8[ctx+2]+8]*4 + 0x60)", store="0x8006e4b4",
               cite=("walk", 0x1A)),
    0x1B: dict(expression="cmd + s16[cmd+2] + 6", store="0x8006df6c", cite=("walk", 0x1B)),
}

# Only handlers whose decompiled body was read for the classification. Every other opcode's advance came from
# the bytes: `walk_stream.resolve` where the corpus has a body for the handler, `(bytes)` where it does not.
EVIDENCE = {
    0x03: "src/stage2/FUN_8006d5dc.c:22",
    0x0F: "src/stage2/FUN_8006dfe4.c:34",
    0x12: "src/stage2/FUN_8006e138.c:25",
}

BODIES = "fixtures/decomp/ranges.json"


def _evidence(number, in_body):
    if number in EVIDENCE:
        return EVIDENCE[number]
    return "walk_stream.resolve" if in_body else "walk_stream.resolve (bytes)"


NOTES = {
    0x01: "tools/walk_stream.py's DYNAMIC text records only the ctx[2]==0 arm, where the handler writes no "
          "pointer and returns 2; the ctx[2]!=0 arm at 0x8006db44-0x8006db7c does write ctx+0x1c, from the "
          "slot 0x18 saves. This entry records that arm rather than the note's 'no pointer write at all'.",
    0x03: "the write is in the callee FUN_8006d5dc (0x8006d624), which the handler calls at 0x8006dba8; the "
          "index is byte 3 of the command.",
    0x07: "published 4 is the command's own size; the handler's only ctx+0x1c write is the skip target "
          "computed from the u16 at byte 2 (0x8006dc84 lhu v0,2(v1) -> 0x8006dc8c addu v1,v1,v0), so this "
          "ElseStart has no constant path to walk by.",
    0x0D: "resolve() reports [6, 12] and 12 is the trap: the scan carries a3 = cmd+6 out of the fall-through "
          "arm (0x8006de50) into the loop-exit arm, where 0x8006dea4 lh t0,2(a3) -> 0x8006dea8 addu v0,a3,t0 "
          "-> 0x8006deac addiu v0,v0,6 -> 0x8006deb0 sw v0,28(t2) is one variable path. The arms are the two "
          "sides of 0x8006de30 beq v0,zero, so the second advance is a skip of s16[cmd+2]+6, never a 12.",
    0x0E: "the counter-expiry arm advances 2 at 0x8006dfcc; while the counter is non-zero the handler "
          "re-points ctx+0x1c at the block-start slot ctx+0x20 (0x8006dfb8 lw v0,32(v0) with the store in "
          "the 0x8006dfbc j delay slot), which is a loop back to a recorded target, not a length.",
    0x0F: "the constant 4 is the block body; the second write restores the block end saved at iVar6+0x60 on "
          "the arm where the condition function FUN_8006e1bc returns 0, so the M154 override of the advance "
          "scan to 4 needs this second path recorded beside it.",
    0x10: "a block return: the pointer comes back from the per-thread slot ctx+0x20, at an index that is "
          "itself read out of the context (s8[ctx+s8[ctx+2]+8]), so no operand of the command names it.",
    0x12: "the constant 2 is the header advance; on the arm where FUN_8006e1bc returns non-zero the handler "
          "re-points ctx+0x1c at the block-start slot ctx+0x20 instead.",
    0x13: "resolve() reports 14, which is the linear scan chaining the tag-exit's cmd+6 (0x8006e2f8) with the "
          "6-byte loop stride (0x8006e310) and the tag exit again (0x8006e320). A case-table scan has no "
          "single constant, and published 4 is the header, so Switch claims no constant advance at all.",
    0x17: "published 6 is the command's own size; the only ctx+0x1c write is the computed target, stored in "
          "the jr ra delay slot at 0x8006e3d0 (0x8006e3a4 lh t0,4(a1) -> 0x8006e3bc addu a1,a1,t0), so Goto "
          "has no fall-through to walk by.",
    0x18: "published 2 is the command's own size; the handler also saves cmd+2 into ctx+0x144+idx*4 at "
          "0x8006e3f0, which is the slot 0x19 and 0x01 pop, and then sets the pointer from the script table "
          "*(0x80114f2c) + u16[cmd+1].",
    0x19: "pops the slot 0x18 pushes (ctx+0x144+idx*4) and reloads ctx+0x140 from the frame at 0x8006e480.",
    0x1A: "block return from the ctx+0x60 end slot that 0x0d, 0x0f and 0x1b write.",
    0x1B: "same shape as 0x0d and the same trap: resolve() reports [6, 12] because the scan carries "
          "a3 = cmd+6 out of the fall-through arm (0x8006df00) into the loop-exit arm "
          "(0x8006df60 lh t0,2(a3) -> 0x8006df68 addiu v0,v0,6 -> 0x8006df6c sw v0,28(t2)). The licensed "
          "table has no entry for this number, so the name stays null.",
    0x36: "retracted in M226, twice over. The dispatch is `jr *(0x800b98e0 + (u16[cmd+4] >> 8)*4)` with the "
          "index bounds-checked against 5 -- at 0x800b98e0, not the 0x800c98e0 this file published, which is "
          "what `addiu v0,v0,-26400` gives if its immediate is read unsigned (it is -0x6720, so the base is "
          "0x10000 lower). And the target is not a callback: the five entries are five arms of one dispatch, "
          "each selecting a base object before a shared tail computes three coordinates, calls FUN_80077adc "
          "and writes ctx+0x1c = cmd+12. So the advance is the constant 12 and the index selects a "
          "sub-opcode. Measured by tools/callback_table.py; the base objects the arms select *are* "
          "runtime-initialised, which is where that reading belongs.",
}


# --- inputs --------------------------------------------------------------------------------------------
def _lines(path):
    return Path(path).read_text().splitlines()


def _stage2_bodies():
    """[(start, end)] of the Ghidra function bodies in the stage-2 image, ascending.

    82 of the 138 distinct handler addresses are **not** inside one of these — the handlers are layout-adjacent
    code the provider never split into functions — so `src/stage2/FUN_<handler>.c` does not exist for them and
    their advance can only come from the bytes.
    """
    ranges = json.loads(Path(BODIES).read_text())["images"]["stage2"]
    return sorted((f["start"], f["end"]) if isinstance(f, dict) else (f[0], f[1]) for f in ranges)


def _in_body(handler, bodies):
    return any(start <= handler < end for start, end in bodies)


def _inputs():
    profile = json.loads(Path(PROFILE).read_text())["opcodes"]
    if not Path(walk_stream.STAGE2_FILE).exists():
        raise SystemExit("%s is missing: unpack the cartridge first (tools/build_images.py)"
                         % walk_stream.STAGE2_FILE)
    words = walk_stream.load_stage2()
    resolved = walk_stream.resolve(words)
    handlers = sorted({r["handler"] for r in resolved.values()})
    return profile, words, resolved, handlers


def _extent(handler, words, handlers):
    return walk_stream.handler_extent(handler, words, BASE, handlers)


def _word(words, addr):
    return words[(addr - BASE) // 4]


def _slot_stores(handler, words, handlers):
    """Every `sw <reg>,0x1c(<reg>)` in the handler's own extent, minus the stack frame's `28(sp)`.

    The stack frame of a handler that saves registers uses the same 0x1c offset as the command pointer
    (`sw ra,28(sp)`), so those are dropped; 0x6b and 0x7c put their write in the delay slot of the last
    instruction of their extent, which is examined the way `walk_stream.advance_set` examines it.
    """
    end = min((_extent(handler, words, handlers) - BASE) // 4, len(words))
    start = (handler - BASE) // 4
    out = [BASE + 4 * i for i in range(start, end)
           if (words[i] >> 26) == 0x2B and (words[i] & 0xFFFF) == CTX_CMDPTR
           and ((words[i] >> 21) & 0x1F) != 29]
    if end - 1 >= start and end < len(words):
        last, nxt = words[end - 1], words[end]
        terminator = ((last >> 26) == 0x03 or (last >> 26) in (0x04, 0x05, 0x06, 0x07)
                      or ((last >> 26) == 0 and (last & 0x3F) in (0x08, 0x09)))
        if (terminator and (nxt >> 26) == 0x2B and (nxt & 0xFFFF) == CTX_CMDPTR
                and ((nxt >> 21) & 0x1F) != 29):
            out.append(BASE + 4 * end)
    return out


def _jal_targets(handler, words, handlers):
    """Every `jal` target inside the handler's own extent, so a store in a callee can be attributed."""
    end = min((_extent(handler, words, handlers) - BASE) // 4, len(words))
    start = (handler - BASE) // 4
    return [((words[i] & 0x3FFFFFF) << 2) | (BASE + 4 * i & 0xF0000000)
            for i in range(start, end) if (words[i] >> 26) == 0x03]


# --- citations -----------------------------------------------------------------------------------------
def _cite(kind, key, resolved):
    """The line this opcode's variable path was inferred from, as `path:line`."""
    if kind == "walk":
        pattern = re.compile(r"^\s*0x%02x:" % key, re.IGNORECASE)
        for number, line in enumerate(_lines(WALK), 1):
            if pattern.match(line):
                return "%s:%d" % (WALK, number)
        raise SystemExit("no %s line records opcode 0x%02x" % (WALK, key))
    if kind == "inferred":
        needle = "0x%08x" % resolved[key]["handler"]
        for number, line in enumerate(_lines(INFERRED), 1):
            if needle in line and line.strip().startswith('"evidence"'):
                return "%s:%d" % (INFERRED, number)
        raise SystemExit("%s records no evidence for the handler at %s" % (INFERRED, needle))
    if kind == "src":
        hits = [number for number, line in enumerate(_lines(key), 1) if "+ 0x1c) =" in line]
        if not hits:
            raise SystemExit("%s has no `+ 0x1c) =` write to cite" % key)
        return "%s:%d" % (key, hits[-1])
    raise SystemExit("unknown citation kind %r" % (kind,))


def _source_line(citation):
    """`path:line` -> (path, line number, that line's text) or None."""
    match = re.match(r"^(.*):(\d+)$", citation)
    if not match:
        return None
    path, number = Path(match.group(1)), int(match.group(2))
    if not path.exists():
        return None
    lines = path.read_text().splitlines()
    if not 1 <= number <= len(lines):
        return None
    return path, number, lines[number - 1]


# --- build ---------------------------------------------------------------------------------------------
def build() -> dict:
    profile, _words, resolved, _handlers = _inputs()
    bodies = _stage2_bodies()
    opcodes = {}
    for key in sorted(profile, key=lambda k: int(k, 16)):
        number = int(key, 16)
        prof, r = profile[key], resolved[number]
        constant, variable = CONSTANT_PATH.get(number), VARIABLE_PATH.get(number)
        if constant is None and variable is None:
            if len(r["advances"]) != 1:
                raise SystemExit("opcode 0x%02x has %d measured advances and no classification"
                                 % (number, len(r["advances"])))
            constant = r["advances"][0]
        # Two records of the same fact have to agree: this table's constant and the length the profile
        # publishes. They can differ from `advances` because walk_stream's LENGTH_OVERRIDE exists for the
        # case where the store lies outside the handler's scan (M226 added 0x36 that way), so the override's
        # value is accepted -- and the profile's status has to be "ok" for it to count.
        override_ok = (r["length"] == constant and r["status"] == "ok")
        if constant is not None and constant not in r["advances"] and not override_ok:
            raise SystemExit("opcode 0x%02x claims constant %d, resolve() measured %s and publishes %s"
                             % (number, constant, r["advances"], r["length"]))
        advances = []
        if constant is not None:
            advances.append({"kind": "constant", "value": constant})
        if variable is not None:
            advances.append({"kind": "variable",
                             "expression": variable["expression"],
                             "store": variable["store"],
                             "source": _cite(variable["cite"][0], variable["cite"][1], resolved)})
        name = (r["name"] or None)
        opcodes[key] = {
            "number": number,
            "name": name[1:] if name and name.startswith("~") else name,
            "name_source": NAME_SOURCE[r["name_source"] or None],
            "handler": "0x%08x" % r["handler"],
            "published": prof["length"],
            "control_flow": prof["status"],
            "advances": advances,
            "scheduler_effect": SCHEDULER,
            "in_function_body": _in_body(r["handler"], bodies),
            "evidence": _evidence(number, _in_body(r["handler"], bodies)),
            "note": NOTES.get(number),
        }
    return {"milestone": "M211",
            "answers": "where each of the 141 stage-2 opcodes sends the command pointer, and on what evidence",
            "refuses": "a folded constant as a constant, a length for the six dynamic opcodes, any scheduler "
                       "claim, and any name the inputs do not give",
            "inputs": {"profile": PROFILE, "opcodes": OPCODES, "inferred_names": INFERRED,
                       "walk_stream": WALK, "handlers": "src/stage2/*.c", "function_bodies": BODIES},
            "totals": _totals(opcodes),
            "opcodes": opcodes}


def _totals(opcodes) -> dict:
    advances = [a for entry in opcodes.values() for a in entry["advances"]]
    by_flow = {}
    for entry in opcodes.values():
        by_flow[entry["control_flow"]] = by_flow.get(entry["control_flow"], 0) + 1
    return {"opcodes": len(opcodes),
            "constant_advances": sum(1 for a in advances if a["kind"] == "constant"),
            "variable_advances": sum(1 for a in advances if a["kind"] == "variable"),
            "scheduler_unknown": sum(1 for e in opcodes.values() if e["scheduler_effect"] == SCHEDULER),
            "in_function_body": sum(1 for e in opcodes.values() if e["in_function_body"]),
            "without_function_body": sum(1 for e in opcodes.values() if not e["in_function_body"]),
            "control_flow": by_flow}


def render(registry) -> str:
    return json.dumps(registry, indent=1, sort_keys=True) + "\n"


# --- check ---------------------------------------------------------------------------------------------
def _pairs(pairs):
    seen = {}
    for key, value in pairs:
        if key in seen:
            raise ValueError("duplicate key %r" % key)
        seen[key] = value
    return seen


def _fixture(path):
    return json.loads(Path(path).read_text())


def _constant_supported(number, value, resolved):
    """A constant advance must be one resolve() measured, or a literal in the handler's own source."""
    if value in resolved[number]["advances"]:
        return True
    source = Path("src/stage2/FUN_%08x.c" % resolved[number]["handler"])
    if not source.exists():
        return False
    return bool(re.search(r"(?<![\w$])%d(?![\w$])" % value, source.read_text()))


def check() -> int:
    cases = []

    def case(label, ok, detail=""):
        cases.append((label, ok, detail))

    try:
        committed = json.loads(Path(REGISTRY).read_text(), object_pairs_hook=_pairs)
        case("the committed registry parses, with no duplicate key", True)
    except (OSError, ValueError) as exc:
        case("the committed registry parses, with no duplicate key", False, str(exc))
        return _report(cases)

    profile, words, resolved, handlers = _inputs()
    entries = committed.get("opcodes") or {}

    case("141 entries", len(entries) == ENTRIES == len(profile),
         "registry %d, profile %d, table %d" % (len(entries), len(profile), ENTRIES))
    missing = sorted(set(profile) - set(entries))
    extra = sorted(set(entries) - set(profile))
    case("every opcode in profile.json is present exactly once", not missing and not extra,
         "missing %s, extra %s" % (missing, extra))

    published, flow, handler, effects = [], [], [], []
    for key, entry in entries.items():
        number = int(key, 16)
        prof, r = profile.get(key), resolved.get(number)
        if prof is None or r is None:
            published.append("%s: no input" % key)
            continue
        if entry.get("number") != number:
            published.append("%s: number %r" % (key, entry.get("number")))
        if entry.get("published") != prof["length"]:
            published.append("%s: %r != %r" % (key, entry.get("published"), prof["length"]))
        if entry.get("control_flow") != prof["status"]:
            flow.append("%s: %r != %r" % (key, entry.get("control_flow"), prof["status"]))
        if entry.get("handler") != "0x%08x" % r["handler"]:
            handler.append("%s: %r != 0x%08x" % (key, entry.get("handler"), r["handler"]))
        if entry.get("scheduler_effect") != SCHEDULER:
            effects.append("%s: %r" % (key, entry.get("scheduler_effect")))
    case("number, published and handler match the inputs", not published, "; ".join(published[:4]))
    case("control_flow matches the profile status", not flow, "; ".join(flow[:4]))
    case("every scheduler_effect is unknown", not effects and len(entries) == ENTRIES,
         "; ".join(effects[:4]) or "count %d" % len(entries))

    bodies = _stage2_bodies()
    proof = []
    for key, entry in entries.items():
        number = int(key, 16)
        in_body = _in_body(resolved[number]["handler"], bodies)
        if entry.get("in_function_body") is not in_body:
            proof.append("%s: in_function_body %r, corpus says %r"
                         % (key, entry.get("in_function_body"), in_body))
            continue
        evidence = entry.get("evidence") or ""
        if evidence in ("walk_stream.resolve", "walk_stream.resolve (bytes)"):
            want = "walk_stream.resolve" if in_body else "walk_stream.resolve (bytes)"
            if evidence != want:
                proof.append("%s: evidence %r with in_function_body %r" % (key, evidence, in_body))
            continue
        line = _source_line(evidence)
        if line is None or "+ 0x1c" not in line[2]:
            proof.append("%s: evidence %r does not resolve to a ctx+0x1c write" % (key, evidence))
        elif not in_body:
            proof.append("%s: cites a source line but has no function body" % key)
    case("in_function_body matches the corpus ranges, and evidence agrees with it", not proof,
         "; ".join(proof[:4]))

    licences = ("opcodes.json", "inferred_names.json", "measured")
    ps1, implied = _fixture(OPCODES)["opcodes"], _fixture(INFERRED)["opcodes"]
    named = []
    for key, entry in entries.items():
        source = entry.get("name_source")
        if source not in licences and source is not None:
            named.append("%s: name_source %r" % (key, source))
            continue
        want = ([v["name"] for v in ps1[key]] if source == "opcodes.json" and key in ps1
                else [implied[key]["name"]] if source == "inferred_names.json" and key in implied
                else [None])
        if entry.get("name") not in want:
            named.append("%s: %r not in %r" % (key, entry.get("name"), want))
    case("every name_source is a fixture this project has, and the name is that fixture's",
         not named, "; ".join(named[:4]))

    constants, variables, stores = [], [], []
    for key, entry in entries.items():
        number = int(key, 16)
        for advance in entry.get("advances") or []:
            kind = advance.get("kind")
            if kind == "constant":
                value = advance.get("value")
                if not isinstance(value, int) or value <= 0:
                    constants.append("%s: value %r" % (key, value))
                elif not _constant_supported(number, value, resolved):
                    constants.append("%s: %d is neither measured nor in the handler's source" % (key, value))
            elif kind == "variable":
                if "value" in advance:
                    variables.append("%s: a variable path carries value %r" % (key, advance["value"]))
                line = _source_line(advance.get("source") or "")
                text = line[2].lower() if line else ""
                if not advance.get("expression"):
                    variables.append("%s: no expression" % key)
                if line is None:
                    variables.append("%s: source %r does not resolve" % (key, advance.get("source")))
                elif ("0x%02x" % number) not in text and "0x1c" not in text:
                    variables.append("%s: source line does not name the opcode or the pointer" % key)
                if advance.get("store") is not None:
                    addr = int(str(advance["store"]), 16)
                    word = _word(words, addr) if BASE <= addr < BASE + 4 * len(words) else 0
                    inside = _extent(resolved[number]["handler"], words, handlers)
                    reachable = [t for t in _jal_targets(resolved[number]["handler"], words, handlers)
                                 if t <= addr <= t + 0x1000]
                    if (word >> 26) != 0x2B or (word & 0xFFFF) != CTX_CMDPTR:
                        stores.append("%s: %s is not `sw ...,0x1c(...)`" % (key, advance["store"]))
                    elif not (resolved[number]["handler"] <= addr < inside or reachable):
                        stores.append("%s: %s is outside the handler and its callees"
                                      % (key, advance["store"]))
            else:
                constants.append("%s: kind %r" % (key, kind))
    case("every constant advance is one resolve() measured or a literal in the handler's source",
         not constants, "; ".join(constants[:4]))
    case("every variable entry names the source line it was inferred from", not variables,
         "; ".join(variables[:4]))
    case("every variable store is a sw into ctx+0x1c inside the handler or a callee", not stores,
         "; ".join(stores[:4]))

    over, folded = [], []
    for key, entry in entries.items():
        number = int(key, 16)
        sites = len(_slot_stores(resolved[number]["handler"], words, handlers))
        if len(entry.get("advances") or []) > max(1, sites):
            over.append("%s: %d path(s), %d store site(s)" % (key, len(entry["advances"]), sites))
        if sites > 1 and not any(a.get("kind") == "variable" for a in entry.get("advances") or []):
            folded.append("%s: %d store sites, no variable path" % (key, sites))
    case("no opcode claims more advance paths than it has ctx+0x1c store sites", not over,
         "; ".join(over[:4]))
    case("every handler with several ctx+0x1c store sites carries a variable path", not folded,
         "; ".join(folded[:4]))

    unaccounted = []
    for key, entry in entries.items():
        number = int(key, 16)
        claimed = {a["value"] for a in entry.get("advances") or [] if a.get("kind") == "constant"}
        spare = [v for v in resolved[number]["advances"] if v not in claimed]
        if spare and not any(a.get("kind") == "variable" for a in entry.get("advances") or []):
            unaccounted.append("%s: %s unaccounted" % (key, spare))
    case("every resolve() advance is either recorded or explained by a variable path", not unaccounted,
         "; ".join(unaccounted[:4]))

    mismatched = sorted(int(k, 16) for k, e in entries.items()
                        if e.get("published") is not None
                        and e["published"] not in [a.get("value") for a in e.get("advances") or []
                                                   if a.get("kind") == "constant"])
    case("the opcodes whose published length is not one of their own constants claim no constant",
         mismatched == [0x07, 0x13, 0x17, 0x18], "found %s" % [hex(n) for n in mismatched])

    totals = committed.get("totals") or {}
    case("the committed totals match the committed entries", totals == _totals(entries),
         "committed %r, recomputed %r" % (totals, _totals(entries)))

    try:
        case("the committed file is exactly what --write produces",
             render(build()) == Path(REGISTRY).read_text(), "run --write")
    except SystemExit as exc:
        case("the committed file is exactly what --write produces", False, str(exc))

    return _report(cases)


def _report(cases) -> int:
    passed = 0
    for label, ok, detail in cases:
        passed += bool(ok)
        print("  %s %s%s" % ("PASS" if ok else "FAIL", label, "" if ok else ": " + detail))
    print("%d/%d registry case(s)" % (passed, len(cases)))
    return 0 if passed == len(cases) else 1


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true", help="regenerate %s" % REGISTRY)
    ap.add_argument("--check", action="store_true", help="validate the committed registry")
    args = ap.parse_args()
    if args.write:
        registry = build()
        Path(REGISTRY).write_text(render(registry))
        totals = registry["totals"]
        print("registry: %d opcodes, %d constant + %d variable advance path(s), %d scheduler effect(s) "
              "unknown -> %s" % (totals["opcodes"], totals["constant_advances"],
                                 totals["variable_advances"], totals["scheduler_unknown"], REGISTRY))
        return
    if args.check:
        sys.exit(check())
    ap.error("one of --write or --check is required")


if __name__ == "__main__":
    main()
