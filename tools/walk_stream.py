#!/usr/bin/env python3
"""Walk a room's command stream from the live command pointer.

The static work (M95-M99) established the pieces: a 141-entry opcode->handler table at `0x80113898`,
ten contexts at `0x80113ad0 + i*0x174`, a command pointer at `ctx+0x1c`, and - the part that makes a
walk possible - **each handler advances the pointer by its own command length**. This tool turns that
into a decoder:

  1. for every table slot i, find every advance `lw v,0x1c(rX)` -> `addiu w,v,N` -> `sw w,0x1c(rX)`
     performed **inside the handler's own extent**, and classify it (M142):
       ok          exactly one advance, so that is the command length;
       unverified  none at all, so the number published at M136 came from *outside* the handler and
                   there is nothing here to walk by;
       ambiguous   several, and the licensed PlayStation table cannot choose between them;
  2. read a memory dump, take the live command pointer from `ctx+0x1c` (falling back to the descriptor
     `*(0x80115284)` that the handler itself reads);
  3. walk: `opcode = byte[p]`, `p += length[opcode]`, recording each command's bytes.

The extent rule is the load-bearing part. These handlers are layout-adjacent and Ghidra has no function
range for several of them, so a scan with a fixed forward window reads advances out of its neighbours -
which is how M136's map and M141's first correction both went wrong. The extent is
min(next handler in the table, next Ghidra function start, +0x1000 bytes).

Guards, because a wrong length desynchronises the whole walk:

  * a command is only accepted when `byte[p]` is a table index in status `ok`, and the next address stays
    inside RDRAM;
  * the walk **stops loudly** at the first `unverified` or `ambiguous` opcode. 24 opcodes are
    `unverified` today, and for five of them that is the semantics rather than a gap: the named
    control-flow commands (`Goto`, `GoSub`, `ForStart`, `Switch`, `ElseStart`) set the pointer from an
    operand instead of advancing it by a constant.

Opcode names and PlayStation command sizes come from `fixtures/scd/opcodes.json`, transcribed from the
MIT-licensed OpenBiohazard2 (`fileio/rdt_scd.go`). The port's own measured advance always wins over the
PlayStation size, and any disagreement is printed rather than hidden.

For opcode `0x44` (`SceEmSet`, 22 bytes) it also prints byte 3 - that command's `Id` field - and byte 9,
so the walk answers "which enemy id does a room ask for?" directly.

Usage:
  ./walk_stream.py --lens                  # the whole opcode -> length map, with names and statuses
  ./walk_stream.py --self-test             # the synthetic fixture (15 cases)
  ./walk_stream.py <rdram-dump.bin> [--commands 64]
"""
import argparse
import json
import struct
import tempfile
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

RD_BASE = 0x80000000
TABLE = 0x80113898
TABLE_ENTRIES = 141
CTX_BASE = 0x80113AD0
CTX_STRIDE = 0x174
CTX_COUNT = 10
CTX_CMDPTR = 0x1C
DESCRIPTOR = 0x80115284
SLOT_OPCODE = 0x44
SLOT_LEN = 22                  # the handler's own advance, re-derived below

STAGE2_BASE = 0x80018A80
STAGE2_FILE = "assets/unpacked/00000_0014420_1172240.bin"


def load_stage2() -> tuple:
    data = Path(STAGE2_FILE).read_bytes()
    n = len(data) // 4
    return struct.unpack(f">{n}I", data[:n * 4])


def handler_lengths(words, base=STAGE2_BASE, table=TABLE, entries=TABLE_ENTRIES) -> dict:
    """opcode -> (handler address, command length), from the advance each handler performs itself.

    Two forms of the same idiom, in order of preference. The **proven** form holds one register
    throughout — `lw X,0x1c(base)` -> `addiu X,X,N` -> `sw X,0x1c(base)` — and covers 140 of the 141
    entries. The **cross-register** form (`lw X` -> `addiu Y,X,N` -> `sw Y`) is a fallback for the one
    that does not, opcode `0x4d`: its handler loads into `a1` at `0x8009bd90`, adds into `v0` fifty
    instructions later at `0x8009be54`, and stores `v0`.

    The order matters and was measured: running the relaxed form first changes **ten** handlers'
    lengths, because a later, unrelated `addiu` from the same register matches. As a fallback it adds
    exactly the one entry and leaves the other 140 byte-identical.
    """
    n = len(words)

    def in_image(va):
        return base <= va < base + 4 * n

    def proven(h):
        """One register end to end. Returns the first positive advance, or None."""
        length = None
        for j in range(h, min(h + 0x400, n - 6)):
            w = words[j]
            if (w >> 26) != 0x23 or (w & 0xFFFF) != CTX_CMDPTR:
                continue
            rt, rbase = (w >> 16) & 0x1F, (w >> 21) & 0x1F
            for k in range(j + 1, min(j + 5, n)):
                y = words[k]
                if (y >> 26) != 0x09 or ((y >> 21) & 0x1F) != rt or not (y & 0xFFFF):
                    continue
                N = y & 0xFFFF
                N = N - 0x10000 if N & 0x8000 else N
                for m in range(k + 1, min(k + 3, n)):
                    z = words[m]
                    if ((z >> 26) == 0x2B and (z & 0xFFFF) == CTX_CMDPTR
                            and ((z >> 21) & 0x1F) == rbase and ((z >> 16) & 0x1F) == rt):
                        if N > 0 and length is None:
                            length = N
                        break
                break
        return length

    def cross(h, window=0x40):
        """`lw X` -> `addiu Y,X,N` -> `sw Y`: only for handlers where `proven` found nothing.

        The first `addiu` from the loaded register is the only candidate considered; if it does not
        feed the store, this handler has no advance of this shape and the answer is None, not the next
        load in the function.
        """
        for j in range(h, min(h + 0x400, n - 6)):
            w = words[j]
            if (w >> 26) != 0x23 or (w & 0xFFFF) != CTX_CMDPTR:
                continue
            loaded, rbase = (w >> 16) & 0x1F, (w >> 21) & 0x1F
            for k in range(j + 1, min(j + 1 + window, n)):
                y = words[k]
                if (y >> 26) != 0x09 or ((y >> 21) & 0x1F) != loaded or not (y & 0xFFFF):
                    continue
                N = y & 0xFFFF
                N = N - 0x10000 if N & 0x8000 else N
                dst = (y >> 16) & 0x1F
                for m in range(k + 1, min(k + 3, n)):
                    z = words[m]
                    if ((z >> 26) == 0x2B and (z & 0xFFFF) == CTX_CMDPTR
                            and ((z >> 21) & 0x1F) == rbase and ((z >> 16) & 0x1F) == dst):
                        return N if N > 0 else None
                return None
        return None

    out = {}
    for i in range(entries):
        off = (table + 4 * i - base) // 4
        if not (0 <= off < n):
            continue
        handler = words[off]
        if not in_image(handler):
            continue
        h = (handler - base) // 4
        length = proven(h)
        if length is None:
            length = cross(h)
        if length is not None:
            out[i] = (handler, length)
    return out


INFERRED_FIXTURE = "fixtures/scd/inferred_names.json"


def inferred_names() -> dict:
    """opcode -> {name, evidence}, read from the handlers by this project (not from the licensed table).

    Kept separate from `ps1_opcodes()` on purpose: those names are the original developers', these are
    descriptions of what the code does. A PlayStation name always wins, and an inferred one is printed with a
    leading `~` so the two can never be confused.
    """
    try:
        doc = json.loads(Path(INFERRED_FIXTURE).read_text())
    except (OSError, ValueError):
        return {}
    return {int(k, 16): v for k, v in doc.get("opcodes", {}).items()}


# Handlers whose true command length the advance scan gets wrong, with the instruction that shows it.
LENGTH_OVERRIDE = {
    # M226: the scan cannot see this one because the store lies outside the handler's Ghidra extent -- the
    # handler is a dispatch head whose five arms live at 0x800711cc, 0x800711dc, 0x800711fc, 0x8007121c and
    # 0x8007124c, and the shared tail that writes the pointer is at 0x800712c8. Every one of the five arms
    # reaches 0x80071278, and the tail is `addiu v0,s0,12` / `sw v0,28(s1)`: twelve regardless of the arm.
    # Established by tools/callback_table.py, which folds the table address (lui 0x800c + addiu -26400 =
    # 0x800b98e0, *not* the 0x800c98e0 three documents published) and disassembles all five arms.
    0x36: (12, "the handler's five table arms all reach the same tail, which writes ctx+0x1c = cmd+12 "
               "(0x800712c8/0x800712cc). The store is outside the handler's bounded body, which is why the "
               "advance scan reports nothing; tools/callback_table.py measures it from the arms themselves."),
    0x0F: (4, "0x8006dfe4 writes ctx+0x1c = cmd+4 (the block body) and computes the block end as "
              "cmd+4+u16@2, so the header is [opcode][span][u16 end] = 4 bytes. The 2 the scan measured is "
              "the span byte, not the command length (M154)."),
}

PS1_FIXTURE = "fixtures/scd/opcodes.json"
RANGES_FIXTURE = "fixtures/decomp/ranges.json"


def ps1_opcodes() -> dict:
    """opcode -> [(name, size)] from the MIT-licensed OpenBiohazard2 table.

    The sizes are the *PlayStation* command sizes, derived by that project's own struct fields. They name
    our opcodes; they do not overrule our measurement — where the two disagree, the handler's own advance is
    what the console actually does, and the disagreement is reported rather than hidden.
    """
    try:
        doc = json.loads(Path(PS1_FIXTURE).read_text())
    except (OSError, ValueError):
        return {}
    out = {}
    for key, variants in doc.get("opcodes", {}).items():
        out[int(key, 16)] = [(v["name"], v["size"]) for v in variants]
    return out


_RANGES = None


def _stage2_ranges():
    global _RANGES
    if _RANGES is None:
        try:
            rng = json.loads(Path(RANGES_FIXTURE).read_text())["images"]["stage2"]
            _RANGES = sorted(((f["start"], f["end"]) if isinstance(f, dict) else (f[0], f[1])) for f in rng)
        except (OSError, KeyError, ValueError, TypeError):
            _RANGES = []
    return _RANGES


def handler_extent(h, words, base, handlers) -> int:
    """Where this handler ends: the next handler in the table, the next Ghidra function, or 0x1000 bytes.

    The table bound matters because these handlers are layout-adjacent and Ghidra has **no range at all**
    for several of them — which is how M136's scans came to read advances from outside the handler.
    """
    closer = [x for x in handlers if x > h]
    end = min(closer) if closer else base + 4 * len(words)
    for s, _e in _stage2_ranges():
        if h < s < end:
            end = s
    for s, e in _stage2_ranges():
        if s <= h < e:
            end = min(end, e)
    return min(end, h + 0x1000)


CALLER_SAVED = set(range(2, 16)) | {24, 25}    # v0-v1, a0-a3, t0-t9: a call clobbers these


def advance_set(h, words, base, handlers) -> list:
    """Every distinct positive advance of `ctx+0x1c` performed inside the handler's own extent.

    This is a small forward dataflow rather than a window search, because a window is what got both M136 and
    M142 wrong: `0x32` writes the pointer back four instructions after its `addiu` (recording three other
    fields first) and `0x37` nine instructions later, so any fixed window either misses them or reaches into
    the neighbouring handler. Registers derived from the command pointer are tracked until they are
    overwritten; a call or a return clears them, **except** that its delay slot is examined first, because
    `0x28` and `0x45` write the pointer back there.
    """
    n = len(words)
    if not (base <= h < base + 4 * n):
        return []
    j0 = (h - base) // 4
    lim = min((handler_extent(h, words, base, handlers) - base) // 4, n)
    derived = {}                     # register -> constant offset from the command pointer
    out = set()

    def store_matches(x):
        """`sw <derived>, 0x1c(<any base>)` -> record the offset it carries."""
        rt = (x >> 16) & 0x1F
        if rt in derived and derived[rt] > 0:
            out.add(derived[rt])
            return True
        return False

    for j in range(j0, lim):
        x = words[j]
        op = x >> 26
        rs = (x >> 21) & 0x1F
        rt = (x >> 16) & 0x1F
        rd = (x >> 11) & 0x1F
        imm = x & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm

        # a load of the command pointer starts a new derivation
        if op == 0x23 and imm == CTX_CMDPTR:
            derived.clear()
            derived[rt] = 0
            continue
        # add a constant to a derived register
        if op == 0x09 and rs in derived:
            value = derived[rs] + simm          # read before popping: `addiu v0,v0,N` has rt == rs
            derived.pop(rt, None)
            derived[rt] = value
            continue
        # copy / add two registers: derived if exactly one side is derived
        if op == 0 and (x & 0x3F) == 0x21:
            a, b = rs in derived, rt in derived
            value = derived[rs] if a and not b else (derived[rt] if b and not a else None)
            derived.pop(rd, None)
            if value is not None:
                derived[rd] = value
            continue
        # write the pointer back
        if op == 0x2B and (x & 0xFFFF) == CTX_CMDPTR:
            store_matches(x)
            continue
        # call / return: examine the delay slot, then the derived set is gone
        if op == 0 and (x & 0x3F) == 0x08:
            # `jr` is a **jump**, not a call: no register is clobbered by transferring control. Opcode 0x40
            # ends with a table of `jr v0` arms before it adds 8 to `t0`, so clearing here lost that
            # advance entirely (`t0` is caller-saved). Its delay slot still executes first.
            if j + 1 < lim and (words[j + 1] >> 26) == 0x2B and (words[j + 1] & 0xFFFF) == CTX_CMDPTR:
                store_matches(words[j + 1])
            continue
        if op == 0x03:                     # jal
            if j + 1 < lim:
                nxt = words[j + 1]
                if (nxt >> 26) == 0x2B and (nxt & 0xFFFF) == CTX_CMDPTR:
                    store_matches(nxt)
            # A call clobbers only the *caller-saved* registers. Opcode 0x2d's handler keeps the command
            # pointer in `s2` across four calls and adds 38 to it afterwards.
            for r in [r for r in derived if r in CALLER_SAVED]:
                derived.pop(r, None)
            continue
        if op == 0 and (x & 0x3F) == 0x09:          # jalr
            for r in [r for r in derived if r in CALLER_SAVED]:
                derived.pop(r, None)
            continue
        # any other write to a tracked register invalidates it
        writes = set()
        if op == 0x00:
            if (x & 0x3F) in (0x00, 0x02, 0x03, 0x21, 0x23, 0x24, 0x25, 0x26, 0x27, 0x2A, 0x2B):
                writes.add(rd)
        elif op in (0x04, 0x05, 0x06, 0x07, 0x01, 0x08, 0x0C, 0x0E):
            writes = set()                      # branches write nothing
        elif op in (0x28, 0x29, 0x2A, 0x2B, 0x2E):
            writes = set()                      # stores write MEMORY: `sw a1,40(v1)` does not kill a1
        elif op == 0x0F:
            writes.add(rt)
        else:
            writes.add(rt)
        for r in writes:
            derived.pop(r, None)
    # A terminator sitting on the last instruction of the extent still owns its delay slot, and two
    # handlers (0x6b, 0x7c) put `sw a1,28(a0)` exactly there.
    if lim - 1 >= j0 and lim < n:
        last = words[lim - 1]
        terminator = ((last >> 26) == 0x03 or (last >> 26) in (0x04, 0x05, 0x06, 0x07)
                      or ((last >> 26) == 0 and (last & 0x3F) in (0x08, 0x09)))
        nxt = words[lim]
        if terminator and (nxt >> 26) == 0x2B and (nxt & 0xFFFF) == CTX_CMDPTR:
            store_matches(nxt)
    return sorted(out)


DYNAMIC = {
    0x03: "script jump by table index: ctx+0x1c = *(0x80114f2c) + u16[byte3] (FUN_8006d5dc; resets the thread)",
    0x10: "block return: ctx+0x1c = *(ctx + thread*8 + 0x20), a saved pointer",
    0x19: "return from the GoSub slot: ctx+0x1c = *(ctx + 0x144 + idx*4), the address 0x18 saves",
    0x1A: "block return: ctx+0x1c = *(ctx + thread*8 + 0x60), a saved pointer",
    # 0x36 was here until M226: it is not dynamic at all. Its handler bounds-checks the index
    # (`sltiu v0,a0,5`), jumps through a *static* five-entry table at 0x800b98e0, and every one of the five
    # arms ends at the same tail, which writes ctx+0x1c = cmd+12. The table is `LENGTH_OVERRIDE`'s job, not
    # DYNAMIC's.
    0x01: "no pointer write at all: it returns 2 to the dispatcher and lets it decide",
}


RAW_SCRIPT_BASE = None          # set by --raw: the block IS the script base
RAW_SCRIPT_TABLE = None         # idx -> u16 offset from the block start


JUMP_FAMILY = {
    0x07: {"size": 4, "operand": ("u16", 2), "base": "cmd", "add": 0, "conditional": True,
           "from": "0x8006dc84 lhu v0,2(v1) -> 0x8006dc8c addu v1,v1,v0 -> sw v1,28(a0)"},
    0x0D: {"size": 6, "operand": ("s16", 2), "base": "cmd", "add": 6, "conditional": True,
           "from": "0x8006dea4 lh t0,2(a3) -> addu v0,a3,t0 -> 0x8006deac addiu v0,v0,6 -> sw v0,28(r10)"},
    0x13: {"size": 4, "operand": ("u16", 2), "base": "cmd", "add": 0, "conditional": True,
           "from": "0x8006e288 lhu t0,2(a3) -> 0x8006e2b8 addu a0,a3,t0 (case-table skip); the body then "
                   "scans 0x0c-marked case entries and lands on a match or on that skip target"},
    0x17: {"size": 6, "operand": ("s16", 4), "base": "cmd", "add": 0, "conditional": False,
           "from": "0x8006e3a4 lh t0,4(a1) -> 0x8006e3bc addu a1,a1,t0 -> 0x8006e3d0 sw a1,28(a0)"},
    0x1B: {"size": 6, "operand": ("s16", 2), "base": "cmd", "add": 6, "conditional": True,
           "from": "0x8006df60 lh t0,2(a3) -> addu v0,a3,t0 -> 0x8006df68 addiu v0,v0,6 -> sw v0,28(t2); "
                   "the other path advances 6 and records a loop target at 96(v0). Same shape as 0x0d, "
                   "but the PlayStation table has no entry for this number, so the *name* is unknown"},
    0x18: {"size": 2, "operand": ("u8", 1), "base": "script_table", "add": 0, "conditional": False,
           "saves_return": True,
           "from": "0x8006e3dc lbu a2,1(v1) -> sll a2,a2,6 -> +*(0x80114f2c) -> lhu v0,0(a2) -> "
                   "0x8006e42c addu v0,v1,v0 -> sw v0,28(a0); the return address `cmd+2` is saved to "
                   "0x8006e3f0 sw v1,324(v0)"},
}


def near_conditional(op, sups):
    """True when the command has a fall-through we can take (everything except an unconditional jump)."""
    spec = JUMP_FAMILY.get(op)
    return bool(spec and spec["conditional"])


def _read_operand(cmd, kind, offset):
    width = {"u8": 1, "s8": 1, "u16": 2, "s16": 2}[kind]
    if len(cmd) < offset + width:
        return None
    raw = int.from_bytes(cmd[offset:offset + width], "big")
    if kind.startswith("s") and raw >= (1 << (8 * width - 1)):
        raw -= 1 << (8 * width)
    return raw


def successors(op, cmd, addr, script_base=None, script_table=None):
    """Where a control-flow command goes next: [(target or None, how)], plus the fall-through when it has one.

    `target` is None when the destination is dynamic — GoSub needs the runtime script table, whose base is
    loaded from `*(0x80114f2c)` and is therefore not in the image.
    """
    spec = JUMP_FAMILY.get(op)
    if spec is None:
        return []
    value = _read_operand(cmd, *spec["operand"])
    out = []
    if value is None:
        return [("truncated", "command shorter than its operand")]
    if spec["base"] == "script_table":
        # The destination is `script_base + u16[index]`. Both halves are outside the command: the base is
        # `*(0x80114f2c)` at runtime and the u16 sits at the *start of the script block*. So it is dynamic
        # unless the caller supplies both — which `--raw` can, because there the block **is** the base.
        offset = script_table(value) if script_table is not None else None
        if offset is None or script_base is None:
            out.append((None, f"dynamic: script record {value} (base *(0x80114f2c) + u16[index])"))
        else:
            out.append((script_base + offset, f"script record {value} (+{offset:#x})"))
    else:
        target = addr + value + spec["add"]
        how = f"cmd{value:+d}" + (f"{spec['add']:+d}" if spec["add"] else "")
        out.append((target, how))
    if spec["conditional"]:
        out.append((addr + spec["size"], "fall-through"))
    return out


def resolve(words, base=STAGE2_BASE, table=TABLE, entries=TABLE_ENTRIES) -> dict:
    """opcode -> what to walk by, its name, and whether walking by it is defensible.

    status is one of:
      ok          exactly one advance inside the handler's own extent — walk by it;
      unverified  **no** advance inside that extent, so the number published at M136 came from outside the
                  handler; refuse rather than guess (this is the M141 correction made operational);
      ambiguous   several advances inside the extent and the licensed table does not choose between them.
    """
    n = len(words)
    handlers = sorted({words[(table + 4 * i - base) // 4] for i in range(entries)
                       if 0 <= (table + 4 * i - base) // 4 < n
                       and base <= words[(table + 4 * i - base) // 4] < base + 4 * n})
    ps1 = ps1_opcodes()
    out = {}
    for i in range(entries):
        off = (table + 4 * i - base) // 4
        if not (0 <= off < n):
            continue
        h = words[off]
        if not (base <= h < base + 4 * n):
            continue
        advances = advance_set(h, words, base, handlers)
        variants = ps1.get(i, [])
        if i in DYNAMIC:
            out[i] = {"handler": h, "length": None, "advances": advances, "status": "dynamic",
                      "name": variants[0][0] if variants else "", "name_source": "ps1" if variants else "",
                      "ps1_sizes": [v[1] for v in variants], "conflict": False, "why": DYNAMIC[i]}
            continue
        name = variants[0][0] if variants else ""
        chosen = None
        if len(advances) == 1:
            status, chosen = "ok", advances[0]
            same = [v for v in variants if v[1] == chosen]
            if same:
                name = same[0][0]
        elif not advances:
            status = "unverified"
        else:
            picked = [v for v in variants if v[1] in advances]
            if len(picked) == 1:
                status, chosen = "ok", picked[0][1]
                name = picked[0][0]
            else:
                status = "ambiguous"
        if i in LENGTH_OVERRIDE:
            status, chosen = "ok", LENGTH_OVERRIDE[i][0]
        if i in JUMP_FAMILY:
            spec = JUMP_FAMILY[i]
            status, chosen = "jump", spec["size"]
            same = [v for v in variants if v[1] == chosen]
            if same:
                name = same[0][0]
        source = "ps1" if variants else ""
        if not name and i in inferred_names():
            name = "~" + inferred_names()[i]["name"]
            source = "inferred"
        conflict = bool(variants) and chosen is not None and chosen not in [v[1] for v in variants]
        out[i] = {"handler": h, "length": chosen, "advances": advances, "status": status,
                  "name": name, "name_source": source if (name and chosen is not None) else "",
                  "ps1_sizes": [v[1] for v in variants], "conflict": conflict}
    return out


def report_lengths(words) -> int:
    """Print the whole opcode -> length map with names and safety, and fail if anything is unresolved."""
    res = resolve(words)
    ps1 = ps1_opcodes()
    named = sum(1 for r in res.values() if r["name"])
    ok = [i for i, r in res.items() if r["status"] == "ok"]
    unverified = [i for i, r in res.items() if r["status"] == "unverified"]
    ambiguous = [i for i, r in res.items() if r["status"] == "ambiguous"]
    jumps = [i for i, r in res.items() if r["status"] == "jump"]
    dynamic = [i for i, r in res.items() if r["status"] == "dynamic"]
    conflicts = [i for i, r in res.items() if r["conflict"]]
    print(f"opcode -> command length: {len(res)} of {TABLE_ENTRIES} handlers, "
          f"{named} named from the MIT-licensed PlayStation table")
    for i in range(TABLE_ENTRIES):
        if i not in res:
            continue
        r = res[i]
        length = "  ?" if r["length"] is None else f"{r['length']:2d}"
        tag = {"ok": "ok", "jump": "JUMP", "dynamic": "DYNAMIC", "unverified": "UNVERIFIED",
               "ambiguous": "AMBIGUOUS"}[r["status"]]
        extra = ""
        if r["conflict"]:
            extra = f"  (ps1 size {r['ps1_sizes']} disagrees)"
        print(f"  0x{i:02x}: {r['handler']:#010x}  len {length}  {tag:10s} "
              f"{r['name'] or '-':14s} advances={r['advances']}{extra}")
    print(f"  named: {named} of {len(res)}; ps1 table has {len(ps1)} opcode number(s)")
    print(f"  walkable {len(ok)}, jump-family {len(jumps)}, dynamic {len(dynamic)}, "
          f"unverified {len(unverified)}, ambiguous {len(ambiguous)}, size conflicts {len(conflicts)}")
    for i in dynamic:
        print(f"  dynamic 0x{i:02x}: {res[i]['why']}")
    if jumps:
        print(f"  jump family (target computed from an operand, decoded from the handler): "
              f"{[hex(i) + ' ' + str(res[i]['name']) for i in jumps]}")
    if unverified:
        print(f"  UNVERIFIED (no advance inside the handler's own extent): "
              f"{[hex(i) for i in unverified]}")
        print("  These are the opcodes whose M136 length came from outside the handler. A walk stops at "
              "the first of them rather than advancing by a number the handler never performs.")
    if ambiguous:
        print(f"  AMBIGUOUS (several advances, table does not choose): {[hex(i) for i in ambiguous]}")
    print(f"  {len(ok) + len(jumps)}/{len(res)} opcodes walkable (of which {len(jumps)} by computed target)")
    return 0 if not ambiguous else 1


def self_test() -> int:
    """A synthetic table with one handler per shape of the idiom — no cartridge needed."""
    base, table, ctx = 0x80000000, 0x80001000, 16
    words = [0] * 0x3000

    def put(va, x):
        words[(va - base) // 4] = x

    def lw(rt, off, rs):    return (0x23 << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)
    def sw(rt, off, rs):    return (0x2B << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)
    def addiu(rt, rs, imm): return (0x09 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)

    proven_A, proven_B, cross_C, none_D = base + 0x2000, base + 0x2100, base + 0x2200, base + 0x2300
    # A: the proven form, and also a later cross-register store that must NOT win.
    put(proven_A, lw(2, 0x1C, ctx))
    put(proven_A + 4, addiu(2, 2, 4))
    put(proven_A + 8, sw(2, 0x1C, ctx))
    put(proven_A + 4 * 99, addiu(3, 2, 999))
    put(proven_A + 4 * 100, sw(3, 0x1C, ctx))
    # B: the scene-slot length.
    put(proven_B, lw(5, 0x1C, ctx))
    put(proven_B + 4, addiu(5, 5, 22))
    put(proven_B + 8, sw(5, 0x1C, ctx))
    # C: load into a1, add into v0 fifty instructions later, store v0 — opcode 0x4d's shape.
    put(cross_C, lw(5, 0x1C, ctx))
    put(cross_C + 4 * 50, addiu(2, 5, 38))
    put(cross_C + 4 * 51, sw(2, 0x1C, ctx))
    # D: an `lw 0x1c` with no advance at all.
    put(none_D, lw(6, 0x1C, ctx))
    put(none_D + 4, sw(6, 0x14, ctx))
    for i, h in enumerate((proven_A, proven_B, cross_C, none_D)):
        put(table + 4 * i, h)

    got = handler_lengths(words, base=base, table=table, entries=4)
    cases = [
        ("proven idiom",                     got.get(0, (None, None))[1], 4),
        ("scene-slot opcode",                got.get(1, (None, None))[1], 22),
        ("cross-register fallback",          got.get(2, (None, None))[1], 38),
        ("handler with no advance is absent", 3 in got, False),
        ("three of four entries mapped",      len(got), 3),
        ("handler addresses are the table's", got.get(0, (None, None))[0], proven_A),
        ("distinct lengths are non-vacuous",  len(set(v[1] for v in got.values())), 3),
        ("proven wins over a later relaxed match", got.get(0, (None, None))[1] != 999, True),
    ]

    # --- naming and length-safety cases: a second synthetic table, wide enough to reach named opcodes
    B2, T2, E2 = 0x80000000, 0x80002000, 0x85          # wide enough to reach opcode 0x7f
    w2 = [0] * 0x9000
    def put2(va, x): w2[(va - B2) // 4] = x
    def handler_at(slot, advances):
        h = B2 + 0x4000 + slot * 0x100
        put2(h, lw(2, 0x1C, ctx))
        for k, n in enumerate(advances):
            put2(h + 4 + 8 * k, addiu(2, 2, n))
            put2(h + 8 + 8 * k, sw(2, 0x1C, ctx))
        put2(T2 + 4 * slot, h)
    handler_at(0x44, [22])          # named, and the ps1 size agrees
    handler_at(0x09, [1])           # named, but the ps1 size disagrees
    handler_at(0x7F, [])            # no advance at all -> must be unverified, never guessed
    handler_at(0x26, [4, 9])        # two advances; only 4 matches a ps1 variant -> table decides
    handler_at(0x50, [4, 5])        # two advances, no ps1 entry -> ambiguous, the walk must stop
    res2 = resolve(tuple(w2), base=B2, table=T2, entries=E2)
    # a second table, so 0x26 can be exercised with ONE advance as well as two: a single advance must still
    # take the name of the variant whose size it matches (Calc2), not the variants' list order (Calc).
    # Without this case the "name follows the chosen size" line can be deleted and everything still passes.
    w3 = [0] * 0x9000
    def put3(va, x): w3[(va - B2) // 4] = x
    h3 = B2 + 0x4000 + 0x26 * 0x100
    put3(h3, lw(2, 0x1C, ctx)); put3(h3 + 4, addiu(2, 2, 4)); put3(h3 + 8, sw(2, 0x1C, ctx))
    put3(T2 + 4 * 0x26, h3)
    res3 = resolve(tuple(w3), base=B2, table=T2, entries=E2)
    op44, op09, op7f = res2.get(0x44, {}), res2.get(0x09, {}), res2.get(0x7F, {})
    op26, op50 = res2.get(0x26, {}), res2.get(0x50, {})
    def succ(op, raw, addr):
        return [(t, h) for t, h in successors(op, bytes(raw), addr)]
    cases += [
        ("Goto target is cmd + s16 at byte 4, with no fall-through",
         [t for t, _h in succ(0x17, [0x17, 0, 0, 0, 0xFF, 0xFA], 0x1000)], [0x0FFA]),
        ("ElseStart has a jump target (u16 at byte 2) and a fall-through",
         [t for t, _h in succ(0x07, [0x07, 0, 0x00, 0x0A], 0x1000)], [0x100A, 0x1004]),
        ("ForStart target is cmd + s16 at byte 2 + 6 (its own size), plus fall-through",
         [t for t, _h in succ(0x0D, [0x0D, 0, 0x00, 0x04, 0, 0], 0x1000)], [0x100A, 0x1006]),
        ("Switch has a case-table skip target and a header fall-through",
         [t for t, _h in succ(0x13, [0x13, 0, 0x00, 0x14], 0x1000)], [0x1014, 0x1004]),
        ("GoSub carries only a record index, so its destination stays dynamic",
         [t for t, _h in succ(0x18, [0x18, 0x03], 0x1000)], [None]),
    ]
    cases += [
        ("the inferred overlay names 0x84 but never overrides a licensed name",
         (inferred_names().get(0x84, {}).get("name"), ps1_opcodes().get(0x44, [("", 0)])[0][0]), ("SndMode", "SceEmSet")),
        ("a licensed name wins over an inferred one at the same opcode", ps1_opcodes().get(0x07)[0][0], "ElseStart"),
        ("the ps1 fixture loads and names SceEmSet at 0x44",
         (ps1_opcodes().get(0x44) or [(None, None)])[0], ("SceEmSet", 22)),
        ("0x26 carries two ps1 variants (Calc/Calc2)",
         len(ps1_opcodes().get(0x26, [])), 2),
        ("a named opcode resolves to its own advance and its name",
         (op44.get("status"), op44.get("length"), op44.get("name")), ("ok", 22, "SceEmSet")),
        ("a handler with no advance is unverified, never guessed",
         (op7f.get("status"), op7f.get("length")), ("unverified", None)),
        ("a measured length disagreeing with the ps1 size is flagged",
         (op09.get("status"), op09.get("conflict")), ("ok", True)),
        ("one advance matching the second ps1 variant is named after that variant",
         (res3.get(0x26, {}).get("length"), res3.get(0x26, {}).get("name")), (4, "Calc2")),
        ("two advances plus one matching ps1 size -> the table decides, and names it",
         (op26.get("status"), op26.get("length"), op26.get("name")), ("ok", 4, "Calc2")),
        ("two advances with no ps1 entry are ambiguous, not guessed",
         (op50.get("status"), op50.get("length"), op50.get("name")), ("ambiguous", None, "")),
    ]

    passed = 0
    for label, actual, expected in cases:
        ok = actual == expected
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}"
              + ("" if ok else f": got {actual!r}, expected {expected!r}"))
    print(f"{passed}/{len(cases)} walk_stream self-test case(s)")
    return 0 if passed == len(cases) else 1


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("dump", nargs="?")
    ap.add_argument("--raw", default=None,
                    help="walk a raw block instead of a dump: the file is placed in a synthetic RDRAM")
    ap.add_argument("--base", default="0x80400000", help="address to place a --raw block at")
    ap.add_argument("--start", default="0", help="offset inside a --raw block to start walking from")
    ap.add_argument("--commands", type=int, default=64)
    ap.add_argument("--ctx", type=int, default=None, help="context index 0-9 (default: all with a pointer)")
    ap.add_argument("--lens", action="store_true",
                    help="print the full opcode -> command length map and exit")
    ap.add_argument("--self-test", action="store_true",
                    help="run the synthetic length-map fixture and exit")
    a = ap.parse_args()

    if a.self_test:
        sys.exit(self_test())

    words = load_stage2()
    if a.lens:
        sys.exit(report_lengths(words))
    if a.raw:
        # A cartridge block has no RDRAM to read: build one. The block is placed in a synthetic 8 MiB
        # image and a context is pointed at `base + start`, so the *same* walk code runs - no second
        # decoder, and nothing about the path changes just because the bytes came from the cartridge.
        blob = Path(a.raw).read_bytes()
        base = int(str(a.base), 16) if str(a.base).startswith("0x") else int(a.base)
        start = int(str(a.start), 16) if str(a.start).startswith("0x") else int(a.start)
        dump_bytes = bytearray(8 * 1024 * 1024)
        off = base - RD_BASE
        if off < 0 or off + len(blob) > len(dump_bytes):
            ap.error(f"{len(blob)} bytes at {base:#x} does not fit in the synthetic RDRAM")
        dump_bytes[off:off + len(blob)] = blob
        struct.pack_into(">I", dump_bytes, CTX_BASE - RD_BASE + CTX_CMDPTR, base + start)
        tmpdir = Path(tempfile.mkdtemp(prefix="walkraw."))
        (tmpdir / "raw_rdram.bin").write_bytes(bytes(dump_bytes))
        a.dump = str(tmpdir / "raw_rdram.bin")
        global RAW_SCRIPT_BASE, RAW_SCRIPT_TABLE
        RAW_SCRIPT_BASE = base
        RAW_SCRIPT_TABLE = lambda idx: (struct.unpack_from(">H", blob, 2 * idx)[0]
                                        if 2 * idx + 2 <= len(blob) else None)
        print(f"raw block {a.raw}: {len(blob)} B at {base:#010x}, walking from +{start:#x}")
    if not a.dump:
        ap.error("a dump is required unless --lens, --self-test or --raw is given")

    res = resolve(words)
    named = sum(1 for r in res.values() if r["name"])
    unverified = {i for i, r in res.items() if r["status"] == "unverified"}
    print(f"opcode -> command length: {len(res)} of {TABLE_ENTRIES} handlers, {named} named, "
          f"{len(unverified)} unverified (a walk stops at those)")
    dump = Path(a.dump).read_bytes()

    def rd(va, n):
        o = va - RD_BASE
        if o < 0 or o + n > len(dump):
            raise ValueError(f"{va:#010x} outside the dump")
        return dump[o:o + n]

    def word(va):
        return struct.unpack(">I", rd(va, 4))[0]

    ctxs = range(CTX_COUNT) if a.ctx is None else [a.ctx]
    pointers = []
    for i in ctxs:
        base = CTX_BASE + i * CTX_STRIDE
        # The dispatcher's pop path decrements `lbu 4(ctx + signed(ctx[2]))` — so the only place a
        # per-context count could live is there. MEASURED: it reads 0xff in every context of both
        # room dumps, i.e. it is a flag, not a remaining count. Recorded, not trusted as a bound.
        rel = rd(base + 2, 1)[0]
        rel = rel - 0x100 if rel & 0x80 else rel
        counter_addr = base + rel + 4
        try:
            counter = rd(counter_addr, 1)[0]
        except ValueError:
            counter = None
        p = word(CTX_BASE + i * CTX_STRIDE + CTX_CMDPTR)
        desc = word(DESCRIPTOR)
        tags = []
        if RD_BASE <= p < RD_BASE + len(dump) and p:
            tags.append("ctx")
        if p == desc:
            tags.append("== descriptor")
        print(f"  ctx{i}: ctx+0x1c = {p:#010x}  counter@{counter_addr:#010x} = "
              f"{counter if counter is None else hex(counter)}  {tags if tags else '(not in RDRAM)'}")
        if tags:
            pointers.append((i, p))
    if not pointers:
        print("\nno context holds a live command pointer — this dump predates a room load")
        return

    print("\nnote: the counter byte is a FLAG (0xff) in every context measured, so it cannot bound a "
          "walk; the dispatcher's only numeric bound is `sltiu s1,10` — ten iterations per call. Walks "
          "therefore run until the stream ends (first byte >= 141).")
    for ci, start in pointers:
        print(f"\n=== walking from ctx{ci} = {start:#010x} ===")
        p = start
        return_stack = []
        seen = {}
        slots = []
        for k in range(a.commands):
            try:
                op = rd(p, 1)[0]
            except ValueError:
                print(f"  [{k:2d}] {p:#010x}: outside the dump — stop")
                break
            if op not in res:
                kind = ("not a table index (>= 141) -> the stream ENDED here and the walk left "
                        "the command area" if op >= TABLE_ENTRIES else
                        "a table index with no resolvable handler")
                print(f"  [{k:2d}] {p:#010x}: opcode 0x{op:02x} — {kind}")
                break
            r = res[op]
            if r["status"] == "jump":
                length = r["length"]
                cmd = rd(p, min(length, 64))
                sups = successors(op, cmd, p, RAW_SCRIPT_BASE, RAW_SCRIPT_TABLE)
                label = f" {r['name']}" if r["name"] else ""
                print(f"  [{k:2d}] {p:#010x}: opcode 0x{op:02x}{label} len {length:2d} -> "
                      f"{cmd[:8].hex(' ')}")
                for target, how in sups:
                    shown = "dynamic" if target is None else f"{target:#010x}"
                    print(f"        {how:34s} -> {shown}")
                if op == 0x13:                      # Switch: the case table follows the header
                    p += length
                    continue
                if op == 0x18 and sups and sups[0][0] is not None:
                    return_stack.append(p + length)      # GoSub saves `cmd+2`; a return pops it
                if not near_conditional(op, sups):
                    # an unconditional computed jump (Goto) can be followed; GoSub cannot be resolved
                    statics = [t for t, _h in sups if t is not None]
                    if len(sups) == 1 and statics:
                        print(f"        following the computed target (not the fall-through)")
                        p = statics[0]
                        continue
                    print(f"        STOP: destination is dynamic, so the walk cannot continue")
                    break
                p += length                        # conditional: follow the fall-through and say so
                continue
            if r["status"] == "dynamic":
                if op == 0x19 and return_stack:
                    p = return_stack.pop()
                    print(f"  [{k:2d}] 0x{op:02x} return -> {p:#010x}")
                    continue
                print(f"  [{k:2d}] {p:#010x}: opcode 0x{op:02x} {r['name']} — STOP: destination is dynamic: "
                      f"{r['why']}")
                break
            if r["status"] != "ok":
                which = ("no advance inside its own handler" if r["status"] == "unverified"
                         else "several advances and the table does not choose")
                print(f"  [{k:2d}] {p:#010x}: opcode 0x{op:02x} {r['name'] or ''} — STOP: {which}. "
                      f"Walking on would advance by a guess and desynchronise the rest of the walk.")
                break
            handler, length = r["handler"], r["length"]
            cmd = rd(p, min(length, 64))
            seen[op] = seen.get(op, 0) + 1
            extra = ""
            if op == SLOT_OPCODE:
                slot = cmd[3] if len(cmd) > 3 else None
                gate = cmd[9] if len(cmd) > 9 else None
                slots.append((p, slot, gate))
                extra = f"  Id(byte3)={slot}" + (f"  gate(byte9)={gate:#04x}" if gate is not None else "")
            label = f" {r['name']}" if r["name"] else ""
            print(f"  [{k:2d}] {p:#010x}: opcode 0x{op:02x}{label} len {length:2d} -> "
                  f"{cmd[:8].hex(' ')}{extra}")
            p += length
        print(f"\n  distinct opcodes: {len(seen)}; top: "
              f"{sorted(seen.items(), key=lambda kv: -kv[1])[:6]}")
        if slots:
            print(f"  scene-slot commands: {len(slots)}; Id values {sorted(s for _, s, _ in slots)}")
        else:
            print("  scene-slot commands (opcode 0x44 SceEmSet): none in this walk")


if __name__ == "__main__":
    main()
