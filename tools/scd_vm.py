#!/usr/bin/env python3
"""M213: a reference decoder and a trace format for the game's script VM.

**What this claims.**

  * a **decoded instruction stream**. A command is `[opcode][operands...]`; the opcode selects a handler
    in the 141-entry table at `0x80113898`, and `fixtures/scd/registry.json` (M211) records, per opcode,
    how many bytes the command occupies (`published`) and where the handler sends the command pointer
    (`advances`, `control_flow`). The decoder walks that: it reads the opcode byte, reads the command's
    documented operands, and steps the pc by the registry's own number. A command whose length the
    registry does not have is **not** walked by a guessed 1 - it is a refusal (below).
  * a **state machine** over that stream, with four states, taken from the scheduler contract in
    `src/stage2/FUN_8009b880.c`:

        continue     the handler asks to run again in the same frame: `while (iVar1 == 1)` (line 25);
        yield        the handler gives the frame back: the `iVar1 == 2` arm of the break at line 26.
                     `0x01` is the one opcode `tools/walk_stream.py` records that way ("it returns 2 to the
                     dispatcher and lets it decide"), so `0x01` with no GoSub slot to resume is this
                     state - and it is how five of room 0's nine records end;
        blocked      the command's destination is a slot or a table the trace does not carry: a block
                     return with no opener on the stack, a GoSub with no record table, the `0x36`
                     callback dispatch. The decode stops and reports **which** slot is missing rather
                     than inventing a value for it;
        terminated   the command leaves this record: its stream ends at exactly the record's last byte,
                     or the computed target lies outside the record.

    The mapping from opcode to state is this tool's contract, **not** a claim about a handler's return
    value. `scheduler_effect` is `"unknown"` for all 141 opcodes in the registry and stays unknown here.
  * a **trace**: one record per step, `{pc, opcode, name, advance, successors, state}`, with no
    wall-clock and no randomness, so two runs are byte-identical and a reviewer can diff them.
    `advance` is the constant pc step the step was taken by, or `null` when the destination was a
    computed target, a popped slot or a table entry. `successors` is `[{target, how}]`: the jump family's
    from `walk_stream.successors`, the frame a pop resumed, or the record a table named - empty only
    where the constant advance already says everything.

**What this refuses to claim.**

  * **no game effects.** It never says what a command does to a room, an actor, a flag or a sound. The
    22 bytes of a `0x4d DoorModelSet` are 22 bytes and nothing more.
  * **no rendering**, and no timing: a trace is a decode order, not a frame budget.
  * **no assertion that a jump target is valid code.** Targets are arithmetic on an operand
    (`walk_stream.successors`) or an entry of the block's own `u16[]` record table. Nothing here checks
    that a target starts an instruction, and a target inside *another* record is recorded as a successor
    while this record's trace ends there.
  * **no second jump model.** The jump family, the operand offsets, the sign extension and the operand
    arithmetic are `tools/walk_stream.py`'s (`JUMP_FAMILY`, `successors`, `_read_operand`); the
    block/GoSub stack is `tools/cfg_reach.py`'s (`OPENERS`, `POPPERS`, `SUBCALL`, `SUBRET`) with its
    save-on-open, resume-on-pop rule. This tool adds only the joining of the two, the frame kind (the VM
    keeps the block slots at `ctx+0x20`/`ctx+0x60` and the GoSub slots at `ctx+0x144` in separate arrays)
    and the state names. `0x12` keeps the registry's constant advance of 2 (its measured `ok` path); its
    block-pop arm is `cfg_reach`'s, and a linear trace does not take it.
  * **no claim that a record is reached.** Each record is decoded from its own start, independently.

The 9 opcodes the registry gives no constant advance, and what supplies each one's pc (it was 10 until
M226 resolved `0x36`, which is a constant after all):

    jump family, both successors from `walk_stream.successors`   0x07 0x13 0x17 0x18
    block slot, popped from the cfg_reach stack                  0x10 0x1a
    GoSub slot (`ctx+0x144+idx*4`, the slot 0x18 saves)          0x19
    GoSub slot on one arm, yield on the other                    0x01
    the block's `u16[]` record table (`FUN_8006d5dc`)            0x03
    **nothing**: a callback pointer, not a command address        0x36 -> UnresolvedAdvance

Usage:
  ./scd_vm.py --decode 0                  # a real room, end to end (needs the cartridge)
  ./scd_vm.py --decode 0 --records 3 --trace /tmp/t.json
  ./scd_vm.py --self-test                 # the synthetic fixture: no cartridge
  ./scd_vm.py --check                     # the gate: fixture + one real room
"""
import argparse
import json
import struct
import sys
import zlib
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import cfg_reach                                              # noqa: E402
import room_script                                            # noqa: E402
import walk_stream as ws                                      # noqa: E402

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

REGISTRY = ROOT / "fixtures" / "scd" / "registry.json"
FIXTURE = ROOT / "fixtures" / "scd" / "trace_fixture.json"
ROM = room_script.ROM                                        # the same cartridge path as the other suites

STAGE2_MEMBER = 0x14420        # first zlib member of the cartridge: the stage-2 image (unpack_zlib.py)
ROOM_TABLE = cfg_reach.ROOM_TABLE
ROOM_TABLE_MAX = cfg_reach.ROOM_TABLE_MAX
DEFAULT_ROOM = 0               # DAT_80131fa8[0] = file id 1881, the first DOOR_SCD

MAX_STEPS = 256                # per record, a backstop: a loop is reported by the revisit rule below
STATES = ("continue", "yield", "blocked", "terminated")

# The five `dynamic` opcodes of the registry, each with the model that supplies its destination. It
# was six until M226: 0x36 is a constant advance over a static five-entry table, so it left both this
# table and the registry's dynamic set.
# Keys must equal the registry's `control_flow == "dynamic"` set; `--self-test` asserts that.
DYNAMIC_MODEL = {
    0x01: "gosub_slot_or_yield",   # *(ctx+0x144+(s8[ctx+2]-1)*4) -- walk_stream records the ctx[2]==0 arm
    0x03: "record_table",          # *(0x80114f2c)+u16[cmd+3], in the callee FUN_8006d5dc (src/stage2)
    0x10: "block_pop",             # *(ctx + s8[ctx+2]*16 + s8[ctx+s8[ctx+2]+8]*4 + 0x20)
    0x19: "gosub_slot",            # *(ctx+0x144+(u8[ctx+2]-1)*4): the slot cfg_reach.SUBRET pops
    0x1A: "block_pop",             # *(ctx + s8[ctx+2]*16 + s8[ctx+s8[ctx+2]+8]*4 + 0x60)
    # 0x36 left this table in M226: its dispatch is over a static five-entry table at 0x800b98e0 (not
    # 0x800c98e0 -- the published address was the addiu immediate read unsigned) and every arm ends with the
    # same ctx+0x1c = cmd+12, so it has a constant advance and no destination of its own to model.
}

# cfg_reach's own push/pop sets, so the two tools cannot drift: an opener saves its continuation, a
# pop resumes there, and GoSub saves `cmd+2` (SUBCALL) which SUBRET (0x19) reloads.
PUSHERS = frozenset(cfg_reach.OPENERS) | {cfg_reach.SUBCALL}
SLOT_POPPERS = frozenset(cfg_reach.POPPERS) | {cfg_reach.SUBRET}     # {0x10, 0x12, 0x1a} + 0x19

_REG = None


def registry():
    """opcode -> its M211 record. Read once; nothing here writes to any of it."""
    global _REG
    if _REG is None:
        doc = json.loads(REGISTRY.read_text())
        _REG = {int(k, 16): v for k, v in doc["opcodes"].items()}
    return _REG


def constant_advance(rec):
    """The registry's constant advance for one record, or None. A `variable` path carries no number."""
    for adv in rec.get("advances", ()):
        if adv.get("kind") == "constant":
            return adv.get("value")
    return None


def advance_class(op, reg=None):
    """How this opcode's pc is found.

    `jump` wins over `constant` for `0x0d` and `0x1b`, which have both: a conditional branch needs its
    computed target *and* its fall-through, and the jump family records both.
    """
    reg = registry() if reg is None else reg
    if op in ws.JUMP_FAMILY:
        return "jump"
    if constant_advance(reg[op]) is not None:
        return "constant"
    return DYNAMIC_MODEL.get(op, "unresolved")


class DecodeError(Exception):
    """A refusal, not a guess. Every subclass carries `.kind`, `.offset` and `.opcode`."""

    kind = "decode"

    def __init__(self, offset, opcode):
        self.offset = offset                   # set before `message()`, which interpolates both
        self.opcode = opcode
        super().__init__(self.message())

    def message(self):
        return f"{self.kind} error at {self.offset:#x}"


class TruncatedInstruction(DecodeError):
    kind = "truncated"

    def __init__(self, offset, opcode, want):
        self.want = want
        super().__init__(offset, opcode)

    def message(self):
        op = "no opcode byte" if self.opcode is None else f"opcode {self.opcode:#04x}"
        return (f"truncated instruction at {self.offset:#x}: {op} needs {self.want} byte(s) and the "
                f"record ends first")


class UnknownOpcode(DecodeError):
    kind = "unknown"

    def message(self):
        return (f"unknown opcode {self.opcode:#04x} at {self.offset:#x}: not a slot of the 141-entry "
                f"table, so there is no handler and no length")


class UnresolvedAdvance(DecodeError):
    kind = "unresolved"

    def __init__(self, offset, opcode, why=""):
        self.why = why
        super().__init__(offset, opcode)

    def message(self):
        tail = f" ({self.why})" if self.why else ""
        return (f"unresolved advance at {self.offset:#x}: opcode {self.opcode:#04x} has no constant "
                f"advance and no jump spec, and no slot or table supplies its destination{tail}")


class Reader:
    """A bounds-checked window on one record: `end` is the record's own end, not the block's.

    Reading past it raises `TruncatedInstruction` carrying the offset and the opcode, which is the point:
    a command that runs off the end of its record is a fact about the stream, not a reason to read the
    next record's bytes as if they were the tail of this one.
    """

    def __init__(self, data, start=0, end=None):
        self.data = bytes(data)
        self.start = max(0, start)
        self.end = len(self.data) if end is None else min(end, len(self.data))

    def byte(self, pc, opcode=None):
        if not (self.start <= pc < self.end):
            raise TruncatedInstruction(pc, opcode, 1)
        return self.data[pc]

    def take(self, pc, n, opcode):
        if n < 0 or pc < self.start or pc + n > self.end:
            raise TruncatedInstruction(pc, opcode, n)
        return self.data[pc:pc + n]


_OPERAND_WIDTH = {"u8": 1, "s8": 1, "u16": 2, "s16": 2}


def decode_one(reader, pc, reg=None):
    """One instruction: the opcode byte, the published length, and the operands at their offsets.

    The operand *offsets and kinds* are `walk_stream.JUMP_FAMILY`'s, which is the only field map the
    inputs give (the registry names the expression an advance computes, not a layout). For every other
    opcode the command's payload is reported as `raw`, because no field map exists for it and inventing
    one would be the same class of error as inventing a length.
    """
    reg = registry() if reg is None else reg
    op = reader.byte(pc)
    rec = reg.get(op)
    if rec is None:
        raise UnknownOpcode(pc, op)
    spec = ws.JUMP_FAMILY.get(op)
    published = rec["published"]
    length = published if published is not None else (spec["size"] if spec else None)
    operands = []
    if spec is not None:
        kind, offset = spec["operand"]
        width = _OPERAND_WIDTH[kind]
        cmd = reader.take(pc, offset + width, op)          # bounds-checked before the value is read
        operands.append({"kind": kind, "offset": offset,
                         "value": ws._read_operand(cmd, kind, offset)})
    raw = reader.take(pc, length, op) if length is not None else reader.take(pc, 1, op)
    return {"pc": pc, "opcode": op, "name": rec["name"], "handler": rec["handler"],
            "published": published, "length": length, "operands": operands, "raw": raw.hex(" ")}


def pop_frame(stack, kind):
    """Resume the newest saved continuation **of this kind**, or None.

    `cfg_reach` keeps one LIFO and pops its top; the VM keeps the block slots (`ctx+0x20`, `ctx+0x60`) and
    the GoSub slots (`ctx+0x144+idx*4`) in separate arrays, so a block pop can never resume a GoSub frame
    or the other way round. Each array is a stack, so the newest frame of the kind is that array's top.
    """
    for i in range(len(stack) - 1, -1, -1):
        if stack[i][1] == kind:
            return stack.pop(i)
    return None


def step(reader, pc, reg, stack, table):
    """One step: the instruction, where it goes, and the state it leaves the context in.

    -> (trace record, next pc or None, why). `advance` and `successors` together say how the pc was
    found; `state` is one of `STATES`. `stack` is cfg_reach's LIFO of saved continuations and `table`
    is the block's `u16[]` record table, or None when the decode has no block.
    """
    ins = decode_one(reader, pc, reg)
    op = ins["opcode"]
    cls = advance_class(op, reg)
    succ, why, advance, nxt = [], "", None, None

    if cls == "unresolved":
        raise UnresolvedAdvance(pc, op, (reg[op].get("note") or "").strip()[:120])

    size = ins["length"] or (ws.JUMP_FAMILY[op]["size"] if op in ws.JUMP_FAMILY else None)
    if op in PUSHERS:
        # an opener's continuation is its own fall-through; GoSub's is `cmd+2`, the address 0x19 pops
        stack.append((pc + size, "gosub" if op == cfg_reach.SUBCALL else "block"))

    if cls == "constant":
        advance = constant_advance(reg[op])
        nxt = pc + advance
    elif cls == "jump":
        cmd = reader.take(pc, size, op)
        # script_base 0: this trace works in block-relative offsets, exactly as `walk_stream --raw`
        # works in absolute ones. Without a table the successor stays `None` and the step is blocked.
        succ = [{"target": t, "how": h}
                for t, h in ws.successors(op, cmd, pc, 0 if table is not None else None, table)]
        if ws.near_conditional(op, succ):
            advance, nxt = size, pc + size
        else:
            targets = [s["target"] for s in succ if s["target"] is not None]
            if len(targets) == 1:
                nxt = targets[0]
            else:
                why = f"{op:#04x} needs the block's record table"
    elif cls in ("block_pop", "gosub_slot", "gosub_slot_or_yield"):
        frame = pop_frame(stack, "gosub" if cls.startswith("gosub") else "block")
        if frame is not None:
            nxt, kind = frame
            why = f"resumes the {kind} frame its opener saved"
            succ = [{"target": nxt, "how": f"popped {kind} frame"}]
        elif cls == "gosub_slot_or_yield":
            why = (f"walk_stream.py's DYNAMIC record: {op:#04x} returns 2 to the dispatcher "
                   f"(FUN_8009b880.c:26) with no GoSub slot open")
        elif cls == "block_pop":
            why = f"{op:#04x} pops a block slot and no opener pushed one"
        else:
            why = f"{op:#04x} pops the GoSub slot and no GoSub pushed one"
    elif cls == "record_table":
        index = reader.byte(pc + 3, op)                    # the index is byte 3 (FUN_8006d5dc.c:22)
        offset = table(index) if table is not None else None
        if offset is None:
            why = f"{op:#04x} reads u16[{index}] from the block's record table, which this trace lacks"
        else:
            nxt = offset
            why = f"script record {index} (+{offset:#x})"
            succ = [{"target": nxt, "how": why}]

    if nxt is None:
        # `0x01` has two arms and the slot array decides which one ran: the GoSub slot if a GoSub is
        # open, the dispatcher otherwise. Any other missing destination is a slot the trace cannot fill.
        state = "yield" if cls == "gosub_slot_or_yield" else "blocked"
        why = why or "the destination is a slot or table this trace does not carry"
    elif not (reader.start <= nxt < reader.end):
        state = "terminated"
        where = (f"the record's stream ends at {nxt:#x}" if nxt == reader.end else
                 f"{nxt:#x} is past this record's end ({reader.end:#x})" if nxt > reader.end else
                 f"{nxt:#x} is before this record's start ({reader.start:#x})")
        why = f"{where}; {why}" if why else where
    else:
        state, why = "continue", why or ""

    return ({"pc": pc, "opcode": op, "name": ins["name"], "advance": advance,
             "successors": succ, "state": state}, nxt, why)


def trace_record(reader, start, reg=None, table=None, max_steps=MAX_STEPS, strict=True):
    """Decode one record from `start`: its steps, and why the decode stopped.

    Deterministic by construction - the same bytes and the same start give the same list. A trace visits
    each address at most once: a second visit is a loop, and a decode reports it as a revisit instead of
    unrolling it (`Goto` back to an `IfElseStart` is the common case in a real room). `max_steps` is only
    a backstop so that no input can run away.

    `strict` decides what a refusal does. Strict - the fixture's mode - raises, because a refusal *is* the
    answer there. Decoding a real room is not strict: the refusal becomes the reason this record's decode
    stopped and the steps before it are kept, so one byte the table cannot explain in the fourth record
    cannot hide the other records of the same block.
    """
    reg = registry() if reg is None else reg
    stack, steps, seen, p, why = [], [], set(), start, ""
    while True:
        if len(steps) >= max_steps:
            return {"start": start, "steps": steps, "stop": f"step cap {max_steps}"}
        if p in seen:
            return {"start": start, "steps": steps,
                    "stop": f"revisit: {p:#x} was already decoded in this record"}
        seen.add(p)
        try:
            rec, nxt, why = step(reader, p, reg, stack, table)
        except DecodeError as exc:
            if strict:
                raise
            return {"start": start, "steps": steps, "stop": f"refused at {exc.offset:#x}: {exc}"}
        steps.append(rec)
        if rec["state"] != "continue" or nxt is None:
            return {"start": start, "steps": steps,
                    "stop": f"{rec['state']}: {why}" if why else rec["state"]}
        p = nxt


class OffsetTable:
    """`u16[index]` from the head of a record block - FUN_8006d5dc's table, and walk_stream's stride 2.

    The same table `room_script.records()` lists, wrapped as the callable `walk_stream.successors` wants
    for GoSub and for `0x03`. Out of range -> None, which the decoder reports as blocked, not as 0.
    """

    def __init__(self, offsets):
        self.offsets = list(offsets)

    def __call__(self, index):
        return self.offsets[index] if 0 <= index < len(self.offsets) else None


def stage2_image(rom):
    """The stage-2 image, inflated from the cartridge itself: the first zlib member, at 0x14420.

    `walk_stream.load_stage2()` reads the same bytes out of `assets/unpacked/`, which is generated; this
    route needs only the cartridge, so the room table is reachable without the unpack step.
    """
    d = zlib.decompressobj()
    out = d.decompress(rom[STAGE2_MEMBER:STAGE2_MEMBER + (4 << 20)]) + d.flush()
    if not d.eof:
        raise ValueError(f"the cartridge has no complete zlib member at {STAGE2_MEMBER:#x}")
    return out


def room_file_id(image, room):
    """DAT_80131fa8[room] -> the file id the room loader hands the archive (M145)."""
    if not (0 <= room < ROOM_TABLE_MAX):
        raise ValueError(f"room {room} is outside the room table (0..{ROOM_TABLE_MAX - 1})")
    off = ROOM_TABLE - ws.STAGE2_BASE + 2 * room
    if off + 2 > len(image):
        raise ValueError(f"room {room}: the stage-2 image ends before the room table entry")
    return struct.unpack_from(">H", image, off)[0]


def decode_room(room, limit=None):
    """A real room end to end: room id -> block, record table, and one trace per record start.

    The route is the one M145 established and `room_script.py` walks: room byte -> file id -> cart file
    table (record 0x43) -> zlib member -> the `u16[]` record-offset table at the block's head. A record's
    span is its own start to the next record's start (or the end of the block), so a decode that runs
    off a record is a truncated instruction rather than a read into its neighbour.
    """
    rom = ROM.read_bytes()
    file_id = room_file_id(stage2_image(rom), room)
    if not file_id:
        return None
    raw = room_script.block(rom, file_id)
    table = room_script.records(raw)                 # the whole table: a GoSub may target a later record
    offsets = table[:limit] if limit is not None else table
    records = []
    for i, start in enumerate(offsets):
        end = offsets[i + 1] if i + 1 < len(offsets) else len(raw)
        trace = trace_record(Reader(raw, start, end), start, table=OffsetTable(table), strict=False)
        records.append({"start": start, "end": end, "trace": trace})
    return {"room": room, "file_id": file_id, "bytes": len(raw),
            "record_table": table, "records": records}


def _fixture():
    return json.loads(FIXTURE.read_text())


def run_case(case, reg=None):
    """One synthetic case -> the trace it produces, or the refusal it makes.

    A case is `bytes` (hex), an optional `start`/`end`/`record_table`/`max_steps`, and the `expect`ed
    trace. Nothing here reads the cartridge: the fixture *is* the specification. A refusal is part of the
    result, not an error to be caught by hand - `{"raises": kind, "offset": n, "opcode": m}` is exactly
    what the fixture asserts for the cases that must be refused.
    """
    data = bytes.fromhex(case["bytes"])
    start = case.get("start", 0)
    end = case.get("end", len(data))
    table = case.get("record_table")
    try:
        out = trace_record(Reader(data, 0, end), start, reg=reg,
                           table=OffsetTable(table) if table is not None else None,
                           max_steps=case.get("max_steps", MAX_STEPS))
    except DecodeError as exc:
        return {"raises": exc.kind, "offset": exc.offset, "opcode": exc.opcode}
    return {"trace": out["steps"], "stop": out["stop"]}


def fixture_cases():
    """The synthetic cases: each one runs, and its trace or its refusal is compared whole."""
    reg = registry()
    cases = []
    for case in _fixture()["cases"]:
        expect = case["expect"]
        got = run_case(case, reg)
        ok = all(got.get(k) == v for k, v in expect.items())
        cases.append((case["name"], ok, "" if ok else f"got {json.dumps(got)[:200]}"))
    return cases


def decode_cases(reg=None):
    """One instruction at a time: the published length, and the operand at its documented offset.

    The jump family is the only place the inputs give a field map, so it is the only place this decoder
    claims to know where an operand is. `0x17`'s operand is signed and sits at byte 4 - a `Goto` backwards
    is the common case in a real room - and every other opcode gets its payload as raw bytes only.
    """
    reg = registry() if reg is None else reg

    def case(label, actual, expected):
        return (label, actual == expected, "" if actual == expected
                else f"got {actual!r}, expected {expected!r}")

    goto = decode_one(Reader(bytes.fromhex("17 00 00 00 ff fa")), 0, reg)
    for_start = decode_one(Reader(bytes.fromhex("0d 00 ff fe 00 00")), 0, reg)
    scene = decode_one(Reader(bytes.fromhex("44 " + "00 " * 21)), 0, reg)
    return [
        case("0x17 Goto is 6 bytes and its operand is the signed 16-bit value at byte 4 (-6)",
             (goto["published"], goto["length"], goto["operands"]),
             (6, 6, [{"kind": "s16", "offset": 4, "value": -6}])),
        case("the operand is read at the offset walk_stream documents, not at byte 1",
             (for_start["operands"], for_start["raw"]),
             ([{"kind": "s16", "offset": 2, "value": -2}], "0d 00 ff fe 00 00")),
        case("an opcode with no field map reports its published length and its raw bytes only",
             (scene["published"], scene["length"], scene["operands"], len(scene["raw"].split())),
             (22, 22, [], 22)),
    ]


def registry_cases():
    """The partition the decoder's step function rests on, asserted against the registry itself.

    Every step of `step()` branches on `advance_class`, so the partition *is* the decoder: if the registry
    and this table disagree, the decode is right about the wrong opcode. These cases say so loudly, and
    each one fails if the corresponding line of `advance_class`/`DYNAMIC_MODEL` is changed.
    """
    reg = registry()
    classes = {}
    for op in reg:
        classes.setdefault(advance_class(op, reg), []).append(op)
    dynamic = {op for op, r in reg.items() if r["control_flow"] == "dynamic"}
    no_constant = [op for op in reg if constant_advance(reg[op]) is None]

    def case(label, actual, expected):
        return (label, actual == expected, "" if actual == expected
                else f"got {actual!r}, expected {expected!r}")

    return [
        case("the table has 141 opcodes and each one has exactly one advance class",
             (len(reg), sum(len(v) for v in classes.values())), (141, 141)),
        case("the five dynamic opcodes are exactly the ones a slot or table model supplies",
             (sorted(dynamic), sorted(DYNAMIC_MODEL)), (sorted(DYNAMIC_MODEL), sorted(dynamic))),
        case("the advance classes are constant 129, jump 6, and one each of the four models",
             {k: len(v) for k, v in sorted(classes.items())},
             {"block_pop": 2, "constant": 130, "gosub_slot": 1, "gosub_slot_or_yield": 1,
              "jump": 6, "record_table": 1}),
        case("the only opcode that is both a constant advance and a slot pop is 0x12",
             sorted(op for op in classes.get("constant", []) if op in SLOT_POPPERS), [0x12]),
        case("9 opcodes have no constant advance: 4 jump, 5 modelled by a slot or table, and none unresolved",
             (len(no_constant), len([o for o in no_constant if o in ws.JUMP_FAMILY]),
              len(no_constant) - len([o for o in no_constant if o in ws.JUMP_FAMILY])
              - len(classes.get("unresolved", []))), (9, 4, 5)),
        # M226: this used to assert that 0x36 was the one unresolved opcode. It is not unresolved any
        # more -- its handler's five arms share one tail that writes cmd+12 -- so the case now holds the
        # stronger property: nothing in the table is left without an advance.
        case("no opcode is left without a constant advance or a model",
             classes.get("unresolved", []), []),
        case("every jump-family opcode has a published length to read its operand from",
             sorted(op for op in ws.JUMP_FAMILY if reg[op]["published"] is None), []),
        case("the two sets the trace pushes and pops are cfg_reach's, unchanged",
             (sorted(PUSHERS), sorted(SLOT_POPPERS)), ([6, 13, 17, 19, 24, 27], [16, 18, 25, 26])),
    ]


def room_cases(limit=None):
    """A real room decoded end to end: the seven facts a reference decoder has to get right."""
    try:
        got = decode_room(DEFAULT_ROOM, limit)
    except (ValueError, DecodeError) as exc:
        return [(f"room {DEFAULT_ROOM} resolves to a script block", False, str(exc))]
    if got is None:
        return [(f"room {DEFAULT_ROOM} resolves to a script block", False, "its entry is empty")]
    steps = [s for rec in got["records"] for s in rec["trace"]["steps"]]
    states = {name: sum(1 for s in steps if s["state"] == name) for name in STATES}
    gosub = [s for s in steps if s["opcode"] == cfg_reach.SUBCALL]
    conditional = [s for s in steps if len(s["successors"]) == 2]
    stops = [rec["trace"]["stop"] for rec in got["records"]]
    again = decode_room(DEFAULT_ROOM, limit)
    return [
        (f"room {DEFAULT_ROOM} resolves to file id {got['file_id']} and a record table",
         got["bytes"] > 100 and len(got["record_table"]) >= 2, ""),
        ("every record start decodes to at least one instruction",
         all(rec["trace"]["steps"] for rec in got["records"]), ""),
        ("every record's decode stops on a state, never on the step cap",
         all(not st.startswith("step cap") for st in stops), "; ".join(stops[:2])),
        ("a GoSub is resolved through the block's own record table",
         any(s["successors"] and s["successors"][0]["target"] is not None for s in gosub),
         f"{len(gosub)} GoSub"),
        ("a conditional branch records both of its successors",
         bool(conditional), f"{len(conditional)} branch(es)"),
        ("two runs decode to the same trace (deterministic)",
         json.dumps(again, sort_keys=True) == json.dumps(got, sort_keys=True), ""),
        ("the state histogram is non-vacuous: the room continues and yields",
         states["continue"] > 0 and states["yield"] > 0, json.dumps(states)),
    ]


def report(cases):
    """Print the cases and the tally line the gate suite keys on."""
    passed = 0
    for label, ok, extra in cases:
        passed += bool(ok)
        print(f"  {'PASS' if ok else 'FAIL'} {label}" + ("" if ok else f": {extra}"))
    print(f"{passed}/{len(cases)} decoder case(s)")
    return 0 if passed == len(cases) else 1


def self_test():
    return report(fixture_cases() + decode_cases() + registry_cases())


def check():
    if not ROM.exists():
        print(f"SKIP: no cartridge at {ROM.relative_to(ROOT)}")
        return 0
    try:
        got = decode_room(DEFAULT_ROOM)
    except (ValueError, DecodeError) as exc:
        print(f"room {DEFAULT_ROOM}: {exc}")          # the case below reports it as a failure
        got = None
    if got is not None:
        steps = sum(len(r["trace"]["steps"]) for r in got["records"])
        states = {name: 0 for name in STATES}
        for rec in got["records"]:
            for s in rec["trace"]["steps"]:
                states[s["state"]] += 1
        print(f"room {DEFAULT_ROOM} -> file id {got['file_id']}: {got['bytes']} B, "
              f"{len(got['records'])} record(s), {steps} instruction(s)")
        for rec in got["records"]:
            print(f"  record {rec['start']:#05x}..{rec['end']:#05x}: "
                  f"{len(rec['trace']['steps'])} step(s), stop {rec['trace']['stop']}")
        print(f"  states: {json.dumps(states)}")
    return report(fixture_cases() + decode_cases() + registry_cases() + room_cases())


def show(room, limit, trace_path):
    try:
        got = decode_room(room, limit)
    except (ValueError, DecodeError) as exc:
        print(f"room {room}: {exc}")
        return 1
    if got is None:
        print(f"room {room} has no script block (its room-table entry is empty)")
        return 1
    print(f"room {room} -> file id {got['file_id']}: {got['bytes']} B decompressed, "
          f"{len(got['record_table'])} record(s)")
    states = {name: 0 for name in STATES}
    total = 0
    for rec in got["records"]:
        steps = rec["trace"]["steps"]
        total += len(steps)
        for s in steps:
            states[s["state"]] += 1
        head = " ".join(f"{s['opcode']:#04x}" for s in steps[:8])
        print(f"\nrecord {rec['start']:#05x}..{rec['end']:#05x}: {len(steps)} step(s) -> "
              f"{head}{' ...' if len(steps) > 8 else ''}")
        for s in steps:
            name = s["name"] or "-"
            adv = "  -" if s["advance"] is None else f"{s['advance']:3d}"
            succ = ", ".join("dynamic" if x["target"] is None else f"{x['target']:#x} ({x['how']})"
                             for x in s["successors"]) or "-"
            print(f"  {s['pc']:#05x} {s['opcode']:#04x} {name:16s} advance {adv}  {s['state']:10s} "
                  f"{succ}")
        print(f"  stop: {rec['trace']['stop']}")
    print(f"\n{len(got['records'])} record(s), {total} instruction(s); states "
          f"{json.dumps(states)}")
    if trace_path:
        doc = {"format": "scd-vm-trace/1", "decoder": "tools/scd_vm.py",
               "room": {"id": got["room"], "file_id": got["file_id"], "bytes": got["bytes"]},
               "record_table": got["record_table"],
               "records": [{"start": r["start"], "end": r["end"], "stop": r["trace"]["stop"],
                            "steps": r["trace"]["steps"]} for r in got["records"]],
               "totals": {"records": len(got["records"]), "instructions": total, "states": states}}
        Path(trace_path).write_text(json.dumps(doc, indent=1) + "\n")
        print(f"trace written to {trace_path}")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--decode", type=int, default=None, metavar="ROOM",
                    help="decode a real room's script block end to end")
    ap.add_argument("--records", type=int, default=None,
                    help="stop after N records of the block (default: all of them)")
    ap.add_argument("--trace", default=None, metavar="OUT.json",
                    help="write the trace as JSON")
    ap.add_argument("--self-test", action="store_true",
                    help="the synthetic fixture and the registry partition: no cartridge")
    ap.add_argument("--check", action="store_true",
                    help="the gate: the fixture, then one real room decoded end to end")
    args = ap.parse_args()

    if args.self_test:
        return self_test()
    if args.check:
        return check()
    if args.decode is None:
        ap.error("one of --decode ROOM, --self-test or --check is required")
    return show(args.decode, args.records, args.trace)


if __name__ == "__main__":
    raise SystemExit(main())
