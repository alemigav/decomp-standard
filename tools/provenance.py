#!/usr/bin/env python3
"""Pointer provenance, layer 1: what an address is, inside one function.

The two scanners this project already has answer a narrower question than the one that keeps being asked.
`find_readers.py` computes an address when it is **built in the same function** (`lui` + `ori`/`addiu`);
`xref_registry.py` adds pointers stored into globals and reloaded. Between them they cannot see a pointer
that spends the night in a **stack slot**, arrives as an **argument**, or comes back as a **return value**
— which is exactly where the four hand-composed-address incidents lived (M84/M86/M87/M94).

This file is step 1 of experiment B (`docs/format_notes.md`, "Experiments B and C: scoped, not done"): the
intra-procedural dataflow, and nothing else. Specifically:

  * an abstract value per register and per stack slot — `const(addr)`, `param(k)`, `ret(fn)`, `load`, `unk`;
  * a real **CFG per function** with a merge at every join (a value survives a join only if every predecessor
    agrees), because a linear scan that ignores branches is the unsoundness that produced 167 false
    near-misses (M95);
  * **invalidate on loads**: a loaded register is `load`, never a stale constant — the same rule that bug
    violated;
  * caller-saved clobber across `jal`/`jalr`, and `v0 = ret(target)` recorded but **deliberately not
    resolved**: cross-function resolution is step 2 and is forbidden until this fixture is 10/10.

The fixture is synthetic MIPS with hand-computed answers, in the spirit of `test_harness.py`: each case is a
mistake this project actually made, or a merge rule that a linear scan would get wrong.

Usage:
  ./provenance.py --self-test
  ./provenance.py --target 0x800eb260 [--window 0x10]     # accesses to a window, with their abstract base
  ./provenance.py --census [--json manifests/provenance.json]
"""
import argparse
import json
import struct
import sys
from pathlib import Path

CALLER_SAVED = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 31}
ZERO, V0, SP, RA = 0, 2, 29, 31

CONST = "const"
PARAM = "param"
RET = "ret"
LOAD = "load"
PAROFF = "paroff"          # (param k << scale) + addend: parameter-derived, not a known address
CBASE = "cbase"            # (base, bias): a KNOWN base plus an unknown offset — "reads 0x800eb204 + ?"
JTENT = "jtent"            # one entry of the jump table at this address: "the jump goes to the table at X"
SPLOC = "spoff"            # a stack location: sp + bias, the frame address of a local
PARAMSTK = "paramstk"      # an INCOMING stack argument: frame-relative bias >= 0, never stored here
WIDTH = {"lb": 1, "lbu": 1, "lh": 2, "lhu": 2, "lw": 4, "lwu": 4, "ld": 8,
         "sb": 1, "sh": 2, "sw": 4, "sd": 8}      # access width by mnemonic, for byte-granular presence
TABLE_MAX = 512            # bound on entries walked out of one table
TABLE_STATS = {"jtent": 0, "tables": 0, "in_region": 0, "cross": 0, "unresolved": 0}
SLOT_STATS = {"hit": 0, "miss_merge": 0, "miss_never": 0, "miss_unstable": 0}
STK_STATS = {"asked": 0, "resolved": 0}   # stack arguments a call site had to supply, and those it could
CHECK_STK = False        # when set, every call site is checked for a stack argument the caller never stored
CHECK_ARG = False        # when set, every dereferenced register argument is checked for pointer shape
CURRENT_IMAGE = {"name": "?"}   # overlays share vaddrs, so a finding must be keyed by (image, pc)
ARG_FINDINGS = {}        # pc -> {target, k, value}; keyed by pc so fixpoint rounds dedupe
ARG_STATS = {"deref": 0, "const_address": 0, "const_implausible": 0, "derived": 0, "unknown": 0}
STK_FINDINGS = {}        # pc -> {target, missing:[(bias, key, kind)]}; keyed by pc so fixpoint rounds dedupe
UNK = "unk"

LOADS = {0x23: "lw", 0x24: "lbu", 0x25: "lhu", 0x21: "lh", 0x37: "ld", 0x1F: "lwu"}
STORES = {0x2B: "sw", 0x28: "sb", 0x29: "sh", 0x3F: "sd"}
BRANCHES = {0x01, 0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17}
LIKELY = {0x14, 0x15, 0x16, 0x17}      # beql/bnel/blezl/bgtzl: the delay slot runs ONLY if we branch

U = (UNK, 0)

# Opt-in: a word loaded from a *constant* address may itself be a pointer. The rule is narrow and
# reportable — the word must land inside RDRAM — and it is off by default because a data word that looks
# like an address is exactly the kind of plausible inference this project refuses to publish by accident.
FOLLOW_POINTERS = False
IMAGES = {}
MEM_WORDS = {}             # explicit word overrides: fixtures pin synthetic tables here


def image_word_at(addr):
    """The stored word at a virtual address, if it lies in one of the images (read-only)."""
    if addr in MEM_WORDS:
        return MEM_WORDS[addr]
    for (base, data) in IMAGES.items():
        if base <= addr < base + len(data):
            off = addr - base
            return struct.unpack(">I", data[off:off + 4])[0]
    return None


def in_rdram(word):
    return 0x80000480 <= word <= 0x80800000


def sext16(imm):
    return imm - 0x10000 if imm >= 0x8000 else imm


def fmt(v):
    kind, a = v
    if kind == CONST:
        return "const(%08x)" % a
    if kind == PARAM:
        return "param(a%d)" % a
    if kind == RET:
        return "ret(%08x)" % a
    if kind == PAROFF:
        k, scale, addend = a
        return "param(a%d)<<%d%+d" % (k, scale, addend)
    if kind == CBASE:
        base, bias = a
        return "%08x%+d+?" % (base, bias)
    if kind == SPLOC:
        return "sp%+d" % a
    if kind == PARAMSTK:
        return "stkarg(%+d)" % a
    return kind


class Instr:
    __slots__ = ("pc", "word", "op", "rs", "rt", "rd", "sa", "imm", "simm")

    def __init__(self, pc, word):
        self.pc, self.word = pc, word
        self.op = (word >> 26) & 0x3F
        self.rs = (word >> 21) & 0x1F
        self.rt = (word >> 16) & 0x1F
        self.rd = (word >> 11) & 0x1F
        self.sa = (word >> 6) & 0x1F
        # J-type (j/jal) carry a **26-bit** target field; masking it to 16 bits silently truncates every
        # jump target beyond 0x3ffff and makes interprocedural resolution point at the wrong function.
        self.imm = (word & 0x03FFFFFF) if self.op in (0x02, 0x03) else (word & 0xFFFF)
        self.simm = sext16(word & 0xFFFF)

    @property
    def funct(self):
        return self.word & 0x3F

    @property
    def name(self):
        if self.op == 0x0F:
            return "lui"
        if self.op == 0x0D:
            return "ori"
        if self.op in (0x08, 0x09, 0x18, 0x19):
            return {0x08: "addi", 0x09: "addiu", 0x18: "daddi", 0x19: "daddiu"}[self.op]
        if self.op in LOADS:
            return LOADS[self.op]
        if self.op in STORES:
            return STORES[self.op]
        if self.op == 0x03:
            return "jal"
        if self.op == 0x02:
            return "j"
        if self.op == 0x00:
            return {0x21: "addu", 0x2D: "daddu", 0x25: "or", 0x23: "subu", 0x08: "jr",
                    0x09: "jalr", 0x02: "srl", 0x00: "nop"}.get(self.funct, "special:0x%02x" % self.funct)
        if self.op in BRANCHES:
            return "branch:0x%02x" % self.op
        return "op:0x%02x" % self.op


class State:
    """Abstract state: register -> value, stack offset -> value, and why a register became unknown."""

    __slots__ = ("reg", "slot", "cause", "spbias", "written", "tested")

    def __init__(self, reg=None, slot=None, cause=None, spbias=0, written=None, tested=None):
        self.reg = dict(reg or {})
        self.slot = dict(slot or {})
        self.cause = dict(cause or {})
        # every frame byte a store has covered, so a halfword read inside a word store is not "missing"
        self.written = set(written or ())
        # REGISTERS compared against zero anywhere on this path: a dereference through one of them is
        # treated as guarded. Register-based rather than parameter-based because a value is routinely
        # copied into a callee-saved register first, and merges over loops lose the parameter identity.
        self.tested = set(tested or ())       # register -> mnemonic of the instruction that made it unknown
        # stack slots are keyed relative to the **function entry** sp, not the current sp: a frame
        # adjustment (`addiu sp,sp,-N`) otherwise gives the same local two different keys and the
        # spilled value is lost.
        self.spbias = spbias

    def copy(self):
        return State(self.reg, self.slot, self.cause, self.spbias, self.written, self.tested)

    def __eq__(self, other):
        return (self.reg == other.reg and self.slot == other.slot and self.cause == other.cause
                and self.spbias == other.spbias and self.written == other.written
                and self.tested == other.tested)

    def merge(self, other):
        """A value survives a join only if both predecessors agree; otherwise it becomes unknown."""
        out = State()
        for k in set(self.reg) | set(other.reg):
            a, b = self.reg.get(k, U), other.reg.get(k, U)
            out.reg[k] = a if a == b else U
        for k in set(self.slot) | set(other.slot):
            a, b = self.slot.get(k, U), other.slot.get(k, U)
            out.slot[k] = a if a == b else U
        for k in set(self.cause) | set(other.cause):
            c = self.cause.get(k)
            out.cause[k] = c if c == other.cause.get(k) else "join"
        out.spbias = self.spbias if self.spbias == other.spbias else None    # unstable frame: no slot keys
        out.written = self.written | other.written      # a byte written on any path is written
        out.tested = self.tested | other.tested         # "may be null-tested": the direction that yields
                                                        # fewer defect flags, which is what we want here
        return out

    def get(self, r):
        if r == ZERO:
            return (CONST, 0)                    # $zero is a constant, not an unknown
        return self.reg.get(r, U)

    def put(self, r, v, why=None):
        if r == ZERO:
            return
        self.reg[r] = v
        if v[0] == UNK:
            self.cause[r] = why or "?"
        else:
            self.cause.pop(r, None)


class Access:
    __slots__ = ("pc", "name", "base", "offset", "target", "unreached", "args", "call_target", "cause",
                 "guarded")

    def __init__(self, pc, name, base, offset, unreached=False, args=None, call_target=None, cause=None):
        self.pc, self.name, self.base, self.offset = pc, name, base, offset
        self.args = args
        self.call_target = call_target
        self.cause = cause                 # mnemonic that made the base register unknown
        self.guarded = False               # a PARAM base that was null-tested earlier on this path      # which function a `jal` goes to, independent of what it returns
        self.target = base[1] + offset if base[0] == CONST else None
        self.unreached = unreached

    def attributed(self):
        return self.target is not None

    def __str__(self):
        if self.target is not None:
            return "%08x  %-4s %08x  [%s%+d] attributed" % (self.pc, self.name, self.target,
                                                            fmt(self.base), self.offset)
        return "%08x  %-4s      -     [%s%+d] unrecognised base" % (self.pc, self.name,
                                                                    fmt(self.base), self.offset)


CURRENT = {"name": "?"}


def transfer(state, ins, accesses, stores_seen=None, classify=False):
    """Apply one instruction. Returns (state, kind) where kind is None | 'branch' | 'jump' | 'return'."""
    op, rs, rt, rd = ins.op, ins.rs, ins.rt, ins.rd
    CURRENT["name"] = ins.name
    if op == 0x0F:                                              # lui
        state.put(rt, (CONST, (ins.imm << 16) & 0xFFFFFFFF))
        return state, None
    if op == 0x0D:                                              # ori
        base = state.get(rs)
        state.put(rt, (CONST, base[1] | ins.imm) if base[0] == CONST else U)
        return state, None
    if op in (0x08, 0x09, 0x18, 0x19):                          # addi/addiu/daddi/daddiu
        base = state.get(rs)
        if base[0] == CONST:
            state.put(rt, (CONST, (base[1] + ins.simm) & 0xFFFFFFFF))   # immediate is SIGNED
        elif rs == ZERO:
            state.put(rt, (CONST, ins.simm & 0xFFFFFFFF))              # li rt, imm
        elif base[0] == PARAM:                       # a parameter plus a known bias is STILL parameter-
            state.put(rt, (PAROFF, (base[1], 0, ins.simm)))            # derived: this was the single
        elif base[0] == PAROFF:                                        # largest source of `unk` (63.9 %)
            k, sc, add = base[1]
            state.put(rt, (PAROFF, (k, sc, add + ins.simm)))
        elif base[0] == CBASE:
            b, bias = base[1]
            state.put(rt, (CBASE, (b, bias + ins.simm)))
        elif rs == SP and rt == SP:
            state.spbias = (state.spbias or 0) + ins.simm               # frame adjustment, entry-relative
        elif rs == SP:
            state.put(rt, (SPLOC, (state.spbias or 0) + ins.simm))      # frame address of a local
        elif base[0] == SPLOC:
            state.put(rt, (SPLOC, base[1] + ins.simm))
        else:
            state.put(rt, U, CURRENT["name"])
        return state, None
    if op == 0x00:
        f = ins.funct
        if f == 0x00 and ins.word == 0:                          # nop
            return state, None
        if f in (0x21, 0x2D):                                   # addu / daddu: also `move rd, rs`
            a, b = state.get(rs), state.get(rt)
            if b == (CONST, 0):
                state.put(rd, a)
                return state, None
            if a == (CONST, 0):
                state.put(rd, b)
                return state, None
            if a[0] == PAROFF and b[0] == CONST:
                k, sc, add = a[1]
                state.put(rd, (PAROFF, (k, sc, add + b[1])))
                return state, None
            if b[0] == PAROFF and a[0] == CONST:
                k, sc, add = b[1]
                state.put(rd, (PAROFF, (k, sc, add + a[1])))
                return state, None
            if a[0] == CONST and b[0] == PARAM:
                state.put(rd, (PAROFF, (b[1], 0, a[1])))
                return state, None
            if b[0] == CONST and a[0] == PARAM:
                state.put(rd, (PAROFF, (a[1], 0, b[1])))
                return state, None
            if a[0] == CONST and b[0] == UNK and a[1] >= 0x80000000:
                state.put(rd, (CBASE, (a[1], 0)))
                return state, None
            if b[0] == CONST and a[0] == UNK and b[1] >= 0x80000000:
                state.put(rd, (CBASE, (b[1], 0)))
                return state, None
            if a[0] == CBASE and b[0] == CONST:
                base, bias = a[1]
                state.put(rd, (CBASE, (base, bias + b[1])))
                return state, None
            if b[0] == CBASE and a[0] == CONST:
                base, bias = b[1]
                state.put(rd, (CBASE, (base, bias + a[1])))
                return state, None
            if a[0] == CBASE and b[0] == UNK:
                state.put(rd, a)
                return state, None
            if b[0] == CBASE and a[0] == UNK:
                state.put(rd, b)
                return state, None
            if a[0] == CONST and b[0] == CONST:
                state.put(rd, (CONST, (a[1] + b[1]) & 0xFFFFFFFF))
            else:
                state.put(rd, U, CURRENT["name"])
            return state, None
        if f == 0x25:                                           # or
            a, b = state.get(rs), state.get(rt)
            if a[0] == CONST and b[0] == CONST:
                state.put(rd, (CONST, a[1] | b[1]))
            elif b == (CONST, 0):
                state.put(rd, a)
            elif a == (CONST, 0):
                state.put(rd, b)
            else:
                state.put(rd, U, CURRENT["name"])
            return state, None
        if f == 0x23:                                           # subu
            a, b = state.get(rs), state.get(rt)
            state.put(rd, (CONST, (a[1] - b[1]) & 0xFFFFFFFF) if a[0] == b[0] == CONST else U)
            return state, None
        if f in (0x00, 0x02, 0x03):                              # sll / srl / sra
            a, sh = state.get(rt), ins.sa
            if a[0] == CONST and f == 0x00:
                state.put(rd, (CONST, (a[1] << sh) & 0xFFFFFFFF))
            elif a[0] == PARAM and f == 0x00:
                state.put(rd, (PAROFF, (a[1], sh, 0)))           # param << scale: parameter-derived
            else:
                state.put(rd, U, CURRENT["name"])
            return state, None
        if f == 0x08:                                           # jr
            return state, "return" if rs == RA else "jump"
        if f == 0x09:                                           # jalr: unknown target
            for r in CALLER_SAVED:
                state.put(r, U)
            state.put(V0, (RET, 0))
            return state, "call"
        state.put(rd, U, CURRENT["name"])
        return state, None
    if op in LOADS:
        offset = ins.simm                                       # lw offsets are SIGN-EXTENDED
        base = state.get(rs)
        if rs == SP and state.spbias is not None:
            base = (SPLOC, state.spbias)                        # report the frame, entry-relative
        acc = Access(ins.pc, ins.name, base, offset,
                     cause=(state.cause.get(rs) if base[0] == UNK else None))
        if base[0] == PARAM and rs in state.tested:
            acc.guarded = True
        accesses.append(acc)
        slot_key = None
        if state.spbias is None and classify:
            SLOT_STATS["miss_unstable"] += 1
        if state.spbias is not None:
            if rs == SP:
                slot_key = state.spbias + ins.simm
            elif base[0] == SPLOC:
                slot_key = base[1] + ins.simm
        if slot_key is not None and slot_key in state.slot:       # reload from a tracked stack slot
            v = state.slot[slot_key]
            SLOT_STATS["hit"] += 1
        elif slot_key is not None:
            # nothing stored to this slot in this frame. At bias >= 0 it lies ABOVE the entry sp, i.e. in
            # the caller's outgoing argument area: that is an incoming stack argument, and its value is
            # resolvable at the call site. Below zero it is a local read before being written: unknown.
            v = (PARAMSTK, slot_key) if slot_key >= 0 else U
            if classify:
                # distinguish "no store to this slot anywhere in the region" (incoming stack arguments,
                # a caller's frame) from "a store exists but the paths disagreed" (a merge killed it)
                SLOT_STATS["miss_merge" if (stores_seen and slot_key in stores_seen) else "miss_never"] += 1
        elif base[0] == CONST:
            v = (LOAD, base[1] + offset)                         # concrete address, unknown contents
            if FOLLOW_POINTERS and ins.name in ("lw", "lwu", "ld"):
                stored = image_word_at(base[1] + offset)
                if stored is not None and in_rdram(stored):
                    v = (CONST, stored)                          # the load *is* a pointer we can name
        elif base[0] == CBASE:
            # known base + unknown index: this load reads one entry of the table at that base, and an
            # indirect jump through it may go to ANY entry. That is the jump-table edge.
            v = (JTENT, base[1][0] + base[1][1])
        else:
            v = U
        state.put(rt, v)
        return state, None
    if op in STORES:
        base = state.get(rs)
        if rs == SP and state.spbias is not None:
            base = (SPLOC, state.spbias)
        acc = Access(ins.pc, ins.name, base, ins.simm,
                     cause=(state.cause.get(rs) if base[0] == UNK else None))
        if base[0] == PARAM and rs in state.tested:
            acc.guarded = True
        accesses.append(acc)
        store_key = None
        if state.spbias is not None:
            if rs == SP:
                store_key = state.spbias + ins.simm
            elif base[0] == SPLOC:
                store_key = base[1] + ins.simm
        if store_key is not None:
            width = WIDTH.get(ins.name, 4)
            state.written.update(range(store_key, store_key + width))
            state.slot[store_key] = state.get(rt)                # spilled value is remembered
            if stores_seen is not None:
                stores_seen.add(store_key)
        return state, None
    if op == 0x03:                                              # jal
        return state, "call"
    if op == 0x02:
        return state, "jump"
    if op in BRANCHES:
        if op in (0x04, 0x05, 0x14, 0x15):               # beq/bne/beql/bnel against $zero
            state.tested.add(rt if rs == ZERO else rs)   # the register tested against zero
        return state, "branch"
    state.put(rt, U, CURRENT["name"])                                            # anything unmodelled writes rt
    return state, None


def table_targets(table, lo, hi):
    """Entry indices of the table at `table` whose words land inside [lo, hi).

    Bounded twice: by TABLE_MAX and by the first entry that is not code-address-shaped **after** at least
    one valid entry. A case table of plain constants therefore yields nothing rather than a wrong edge.
    """
    out = []
    TABLE_STATS["tables"] += 1
    for k in range(TABLE_MAX):
        w = image_word_at(table + 4 * k)
        if w is None:
            TABLE_STATS["unresolved"] += 1
            break
        if in_rdram(w):
            TABLE_STATS["entries"] = TABLE_STATS.get("entries", 0) + 1
            if lo <= w < hi:
                out.append((w - lo) // 4)
                TABLE_STATS["in_region"] += 1
            else:
                TABLE_STATS["cross"] += 1      # a handler that is its own region: already analysed
        elif out:
            break
    return out


def build_cfg(words, base, extra=None):
    """Basic blocks over one function's words; leaders are the entry, branch targets and branch tails."""
    n = len(words)
    ins = [Instr(base + 4 * i, words[i]) for i in range(n)]
    leaders = {0}
    for i, x in enumerate(ins):
        kind = None
        if x.op in BRANCHES:
            target = i + 1 + x.simm
            if 0 <= target < n:
                leaders.add(target)
            leaders.add(min(i + 2, n))
        elif x.op in (0x02, 0x03) or (x.op == 0x00 and x.funct in (0x08, 0x09)):
            leaders.add(min(i + 2, n))
        elif x.op == 0x00 and x.funct == 0x08 and x.rs == RA:
            leaders.add(min(i + 2, n))
    for k, targets in (extra or {}).items():
        leaders.add(k)
        for t in targets:
            leaders.add(t)
    starts = sorted(i for i in leaders if 0 <= i < n)
    blocks = {}
    for bi, s in enumerate(starts):
        e = starts[bi + 1] if bi + 1 < len(starts) else n
        blocks[s] = {"end": e, "succ": set()}
    for s, b in blocks.items():
        i, last = s, None
        while i < b["end"]:
            last = i
            if ins[i].op in BRANCHES or ins[i].op in (0x02, 0x03) or \
               (ins[i].op == 0x00 and ins[i].funct in (0x08, 0x09)):
                break
            i += 1
        if last is None:
            continue
        x = ins[last]
        nxt = b["end"]
        if x.op in BRANCHES:
            t = last + 1 + x.simm
            for cand in (last + 2, t):
                if cand in blocks:
                    b["succ"].add(cand)
        elif x.op == 0x02:
            t = ((x.pc + 4) & 0xF0000000) | (x.imm << 2)
            t = (t - base) // 4
            if t in blocks:
                b["succ"].add(t)
        elif x.op == 0x03:
            t = last + 2
            if t in blocks:
                b["succ"].add(t)
        elif x.op == 0x00 and x.funct in (0x08, 0x09):
            pass
        else:
            if nxt in blocks:
                b["succ"].add(nxt)
        for t in (extra or {}).get(last, ()):
            if t in blocks:
                b["succ"].add(t)
    return ins, blocks


def resolve(value, args, summaries, seen=(), args_stk=None):
    """Substitute a **callee-space** value into the caller's terms.

    A summary is expressed in its own parameter space, so `param(1)` means "whatever the caller passed
    in a1" and `ret(f)` means "whatever f returns". Both are substituted here, with `seen` breaking the
    recursion of mutually recursive functions.
    """
    kind, a = value
    if kind == PARAM:
        return args[a] if a < len(args) else U
    if kind == PARAMSTK:
        got = (args_stk or {}).get(a)
        return value if got is None else got          # keep the label when the caller stored nothing
    if kind == PAROFF:
        # a callee's summary can return `(its param k) << scale + addend`. Leaving that form untouched
        # makes the CALLEE's parameter index read as the CALLER's, which is how `a0=param(a0)<<4+…`
        # appeared at a call site whose real argument was an unknown byte loaded from a map.
        k, scale, addend = a
        inner = resolve((PARAM, k), args, summaries, seen, args_stk)
        if inner[0] == CONST:
            return (CONST, ((inner[1] << scale) + addend) & 0xFFFFFFFF)
        if inner[0] == PARAM and inner[1] == k:
            return value                                  # genuinely the caller's own parameter
        if inner[0] in (PARAM, PAROFF, CBASE):
            return inner                                  # keep what the caller's value really is
        return U
    if kind == RET:
        if a in seen or a not in summaries:
            return (RET, a)                     # unresolvable callee: keep the name, claim nothing
        return resolve(summaries[a]["ret"], args, summaries, seen + (a,), args_stk)
    return value


def _apply_call(state, ins, accesses, summaries=None, summary_out=None):
    """A call clobbers caller-saved registers; arguments come from the callee's summary when known."""
    args = [state.get(4 + k) for k in range(4)]          # read BEFORE the clobber
    for r in CALLER_SAVED:
        state.put(r, U)
    if ins.op != 0x03:                                   # jalr: target unknown
        state.put(V0, U, CURRENT["name"])
        accesses.append(Access(ins.pc, "jalr", U, 0, args=args, call_target=0))
        return
    target = ((ins.pc + 4) & 0xF0000000) | (ins.imm << 2)
    if summary_out is not None:
        summary_out.setdefault("calls", []).append((ins.pc, target))
        for k in range(4):                               # our own parameter escapes into the callee
            if args[k][0] == PARAM:
                summary_out.setdefault("escapes", set()).add(args[k][1])
    summary = (summaries or {}).get(target)
    args_stk = {}
    if summary is not None:
        for b in {b for b, _ in summary.get("stk", ())}:    # callee's incoming stack args, caller's outgoing
            STK_STATS["asked"] += 1
            key = (state.spbias or 0) + b
            if key in state.slot:
                args_stk[b] = state.slot[key]
                STK_STATS["resolved"] += 1
    if CHECK_ARG and summary is not None:
        for k, declared in enumerate(summary.get("params", [])):
            if declared[0] != PARAM:
                continue                                  # the callee does not dereference this argument
            ARG_STATS["deref"] += 1
            v = args[k]
            if v[0] == CONST:
                # The meaningful question on this hardware is not "KSEG or KUSEG" but **mapped or not**:
                # address 0 is the RDRAM mirror and reads fine, so a small integer is a *valid* N64
                # address even though it is never a real pointer. Only a constant outside every mapped
                # range is a genuine shape defect — that is the M92/M93 class (an out-of-cartridge
                # dereference such as 0x0f564552).
                w_ = v[1]
                ok = (w_ <= 0x007FFFFF                       # RDRAM mirror (physical)
                      or in_rdram(w_)                        # RDRAM KSEG0
                      or 0x1FC00000 <= w_ <= 0x1FC007FF      # PIF ROM
                      or 0xA0000000 <= w_ <= 0xBFFFFFFF      # cartridge KSEG1
                      or 0xC0000000 <= w_ <= 0xDFFFFFFF)     # RDRAM uncached mirror
                ARG_STATS["const_address" if ok else "const_implausible"] += 1
                if not ok:
                    ARG_FINDINGS[(CURRENT_IMAGE["name"], ins.pc)] = {
                        "image": CURRENT_IMAGE["name"], "pc": ins.pc, "target": target,
                        "k": k, "value": v[1]}
            elif v[0] == UNK:
                ARG_STATS["unknown"] += 1
            else:
                ARG_STATS["derived"] += 1
    if CHECK_STK and summary is not None:
        missing = []
        for b, width in summary.get("stk", ()):
            key = (state.spbias or 0) + b
            # byte-granular presence: a halfword read at +0x12 inside a word store at +0x10 is supplied
            if not any(off in state.written for off in range(key, key + max(width, 1))):
                # `interior` = the slot lies inside the caller's own frame, so a store was expected and is
                # absent: a real defect signature. `forwarded` = the slot is above the caller's entry sp,
                # i.e. the value arrives from the caller's own caller and is being passed straight through.
                missing.append((b, key, "interior" if key < 0 else "forwarded"))
        if missing:
            STK_FINDINGS[ins.pc] = {"pc": ins.pc, "target": target, "missing": missing}
        else:
            STK_FINDINGS.pop(ins.pc, None)
    if summary is None:
        state.put(V0, (RET, target))
        accesses.append(Access(ins.pc, "jal", (RET, target), 0, args=args, call_target=target))
        return
    # NOTE: the callee's `params` summary describes what the CALLEE does with its argument. It says
    # nothing about what the caller's a0-a3 hold after the call — those are caller-saved and were
    # clobbered above. Writing them back fabricated argument values that then appeared at later call
    # sites in the same function (found when Ghidra boundaries changed which call sites are in a region).
    lowered = resolve(summary["ret"], args, summaries, (), args_stk)
    state.put(V0, lowered)
    accesses.append(Access(ins.pc, "jal", lowered, 0, args=args, call_target=target))


def _walk(state, ins, s, e, accesses, tag_unreached=False, summaries=None, summary_out=None,
          disc=None, lo=0, hi=0, stores_seen=None, classify=False, succs=None):
    """Run one basic block, honouring MIPS delay slots. Returns the outgoing state."""
    cur = state.copy()
    found = []
    for i in range(s, e):
        pre = cur.get(ins[i].rs)                             # before the transfer clobbers anything
        _, kind = transfer(cur, ins[i], found, stores_seen, classify)
        if kind in ("jump", "call") and pre[0] == JTENT:
            TABLE_STATS["jtent"] += 1
        if kind in ("jump", "call") and disc is not None and pre[0] == JTENT:
            targets = table_targets(pre[1], lo, hi)
            if targets:
                disc[i] = set(targets)
        if kind is None:
            continue
        delay = i + 1
        if delay < len(ins):
            if ins[i].op in LIKELY:
                # a likely-branch delay slot is conditional. Asserting it runs is how the map read at
                # 0x800329ec got attributed to 0x800eb222: the `li s1,0x2e` that produced the index sits
                # in a `beql` delay slot, so the index is only 0x2e on one path. Merge both outcomes.
                taken = cur.copy()
                transfer(taken, ins[delay], found, stores_seen, classify)
                cur = cur.merge(taken)
            else:
                transfer(cur, ins[delay], found, stores_seen, classify)   # ordinary delay slot
        if kind == "branch" and succs is not None:
            # a branch whose two sides are both known constants has ONE feasible successor. Without
            # this, a caller's value can never prune the callee's paths — which is exactly what the
            # polymorphic argument sites need.
            a, b = cur.get(ins[i].rs), cur.get(ins[i].rt)
            if a[0] == CONST and b[0] == CONST:
                taken = (a[1] == b[1]) if ins[i].op in (0x04, 0x14) else (a[1] != b[1])
                succs.append((i + 1 + ins[i].simm) if taken else (i + 2))
        if kind == "call":
            _apply_call(cur, ins[i], found, summaries, summary_out)
        if kind == "return" and summary_out is not None:
            summary_out.setdefault("rets", []).append(cur.get(V0))
        if tag_unreached:
            for a in found:
                a.unreached = True
        accesses.extend(found)
        return cur
    if tag_unreached:
        for a in found:
            a.unreached = True
    accesses.extend(found)
    return cur


def _fixpoint(ins, blocks, summaries, summary_out, disc, base, nwords, seed=None):
    """Dataflow to a fixed point over one CFG. `disc` collects jump-table edges discovered on the way."""
    state_in = {s: None for s in blocks}
    entry = State()
    for k in range(4):                                       # a0-a3 NAMED here, resolved only by summaries
        entry.put(4 + k, (PARAM, k))
    for r, v in (seed or {}).items():
        entry.put(r, v)                                      # caller-supplied argument value
    if 0 in state_in:
        state_in[0] = entry
    lo, hi = base, base + 4 * nwords
    sink = []
    changed, rounds = True, 0
    while changed and rounds < 200:
        changed, rounds = False, rounds + 1
        for s in sorted(blocks):
            if state_in[s] is None:
                continue
            succs = []
            out = _walk(state_in[s], ins, s, blocks[s]["end"], sink, False, summaries, summary_out,
                        disc, lo, hi, succs=succs)
            for t in (succs or blocks[s]["succ"]):
                if t not in state_in:                        # decided target outside this region
                    continue
                merged = out if state_in[t] is None else state_in[t].merge(out)
                if state_in[t] is None or merged != state_in[t]:
                    state_in[t] = merged
                    changed = True
    return state_in


def analyse(words, base, summaries=None, summary_out=None, seed=None):
    """CFG and dataflow iterated together: a jump-table edge is only visible *after* the load resolves.

    Up to four rounds. Each round runs the dataflow, collects the entry points an indirect jump could reach
    through its table, and rebuilds the CFG with those edges; when a round discovers nothing new, that CFG is
    the answer. This is what turns `jr t9` from a dead end into edges, and it is why the `unreached` bucket
    shrinks.
    """
    if not words:
        return [], 0, 0
    extra = {}
    for _ in range(4):
        ins, blocks = build_cfg(words, base, extra)
        disc = {}
        _fixpoint(ins, blocks, summaries, None, disc, base, len(words), seed)   # summaries only on the last run
        merged = dict(extra)
        for k, v in disc.items():
            merged[k] = set(merged.get(k, set())) | v
        if merged == extra:
            break
        extra = merged
    ins, blocks = build_cfg(words, base, extra)
    state_in = _fixpoint(ins, blocks, summaries, summary_out, None, base, len(words), seed)
    lo, hi = base, base + 4 * len(words)
    accesses = []
    stores_seen = set()
    for s in sorted(blocks):
        if state_in[s] is None:
            # no entry state reached this block even with the table edges: count its operands as
            # `unreached` so the totals reconcile instead of quietly vanishing
            _walk(State(), ins, s, blocks[s]["end"], accesses, True, None, None, None, lo, hi)
        else:
            _walk(state_in[s], ins, s, blocks[s]["end"], accesses, False, summaries, None, None, lo, hi,
                  stores_seen)
    for s in sorted(blocks):                                     # second pass: classify the misses
        if state_in[s] is not None:
            _walk(state_in[s], ins, s, blocks[s]["end"], [], False, summaries, None, None, lo, hi,
                  stores_seen, classify=True)
    attributed = sum(1 for a in accesses if a.attributed() and not a.unreached)
    if summary_out is not None:
        # `params` must mean "this function DEREFERENCES the argument" — a value merely forwarded to
        # another call escapes, it is not dereferenced here. Merging the two made every pass-through
        # parameter look like a pointer-taking one (found by the register-argument check flagging
        # libultra calls that pass small integers).
        touched = set()
        for a in accesses:
            if a.base[0] == PARAM and not a.guarded:
                touched.add(a.base[1])
        summary_out["guarded"] = sum(1 for a in accesses if a.base[0] == PARAM and a.guarded)
        summary_out["params"] = [(PARAM, k) if k in touched else U for k in range(4)]
        raw = summary_out.get("rets", [])
        summary_out["ret"] = raw[0] if raw and len(set(raw)) == 1 else U
        summary_out.pop("rets", None)
        # the stack arguments must be collected AFTER `ret` is known: a callee that only *returns* an
        # incoming stack argument has no access whose base is that argument
        stk = set(summary_out.get("stk", set()))
        for a in accesses:
            # a `jal` pseudo-access carries the CALL'S RETURN value in `base`; counting it would report
            # the inner callee's stack argument as this function's own. Only a memory access can show
            # that THIS function reads an incoming stack argument.
            if a.call_target is None and a.base[0] == PARAMSTK:
                stk.add((a.base[1], WIDTH.get(a.name, 4)))
        if summary_out["ret"][0] == PARAMSTK:
            stk.add((summary_out["ret"][1], 4))         # returned straight through: width is not observed
        summary_out["stk"] = stk
        summary_out.setdefault("escapes", set())
    return accesses, attributed, len(extra)


def summarise(regions, rounds=5):
    """Iterate {region start -> {params, ret, calls}} until nothing changes.

    `regions` is a list of (start_vaddr, words). The summaries are caller-independent: a function is
    analysed in its own parameter space, so `param(k)` always means "the caller's k-th argument".
    """
    summaries = {}
    for _ in range(rounds):
        new = {}
        for start, words in regions:
            out = {}
            analyse(words, start, summaries, out)
            new[start] = {"params": out.get("params", [U] * 4), "ret": out.get("ret", U),
                          "calls": out.get("calls", []), "stk": out.get("stk", set())}
        if new == summaries:
            break
        summaries = new
    return summaries


# --------------------------------------------------------------------------------------------- fixtures
def enc_lui(rt, imm):        return (0x0F << 26) | (rt << 16) | (imm & 0xFFFF)
def enc_ori(rt, rs, imm):    return (0x0D << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)
def enc_addiu(rt, rs, imm):  return (0x09 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)
def enc_lw(rt, off, rs):     return (0x23 << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)
def enc_sw(rt, off, rs):     return (0x2B << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)
def enc_addu(rd, rs, rt):    return (rs << 21) | (rt << 16) | (rd << 11) | 0x21
def enc_jal(target):         return (0x03 << 26) | ((target >> 2) & 0x03FFFFFF)
def enc_jr(rs):              return (rs << 21) | 0x08
def enc_sll(rd, rt, sa):     return (rt << 16) | (rd << 11) | (sa << 6)
def enc_beql(rs, rt, off):   return (0x14 << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)
def enc_beq(rs, rt, off):    return (0x04 << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)
def enc_nop():               return 0


BASE = 0x80001000


def fixture_cases():
    """Ten cases. Each returns (name, words, predicate over (accesses, attributed))."""

    def base_addr(a):
        return a[0][0] if a else None

    cases = []

    w = [enc_lui(2, 0x800E), enc_ori(2, 2, 0xB204), enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("1 lui+ori builds a constant and the load through it is attributed",
                  w, lambda acc, n: n == 1 and acc[0].target == 0x800EB204))

    w = [enc_lui(2, 0x800C), enc_addiu(2, 2, -23464), enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("2 addiu immediate is signed: 0x800c0000 - 23464 = 0x800ba458",
                  w, lambda acc, n: n == 1 and acc[0].target == 0x800BA458))

    w = [enc_lui(2, 0x800F), enc_lw(3, 0xB264, 2), enc_jr(RA), enc_nop()]
    cases.append(("3 lw offset is sign-extended: 0x800f0000 + sext(0xb264) = 0x800eb264",
                  w, lambda acc, n: n == 1 and acc[0].target == 0x800EB264))

    w = [enc_addiu(SP, SP, -32), enc_sw(5, 0x10, SP), enc_lw(3, 0x10, SP),
         enc_lw(4, 0, 3), enc_jr(RA), enc_nop()]
    cases.append(("4 a value spilled to the stack and reloaded keeps its provenance",
                  w, lambda acc, n: len(acc) == 3 and acc[2].base == (PARAM, 1)))

    w = [enc_lw(3, 8, 4), enc_jr(RA), enc_nop()]
    cases.append(("5 a parameter used as a base is reported as param, not unknown",
                  w, lambda acc, n: n == 0 and acc[0].base == (PARAM, 0)))

    w = [enc_lui(8, 0x8011), enc_lw(8, 0, 4), enc_lw(3, 0, 8), enc_jr(RA), enc_nop()]
    cases.append(("6 a load invalidates the register: no stale constant survives it",
                  w, lambda acc, n: n == 0 and acc[1].base == U and acc[1].target is None))

    w = [enc_lui(8, 0x8011), enc_jal(0x80002000), enc_nop(), enc_lw(3, 0, 8), enc_jr(RA), enc_nop()]
    cases.append(("7 call clobbers caller-saved: t0 is dead after jal",
                  w, lambda acc, n: n == 0 and acc[1].base == U
                  and any(a.name == "jal" and a.base == (RET, 0x80002000) for a in acc)))

    w = [enc_beq(4, 0, 2), enc_nop(), enc_lui(2, 0x8011),
         enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("8 a join disagrees, so the value becomes unknown",
                  w, lambda acc, n: n == 0 and acc[0].target is None))

    w = [enc_lui(2, 0x800E), enc_ori(2, 2, 0xB204), enc_beq(4, 0, 1), enc_nop(),
         enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("9 a join where both paths agree keeps the constant",
                  w, lambda acc, n: n == 1 and acc[0].target == 0x800EB204))

    w = [enc_addiu(2, ZERO, 0x1234), enc_addu(3, 2, ZERO), enc_lw(4, 0, 3), enc_jr(RA), enc_nop()]
    cases.append(("10 li + move preserve the constant",
                  w, lambda acc, n: n == 1 and acc[0].target == 0x1234))

    return cases


def fixture_cases_layer2():
    """Four cases that only pass if summaries are substituted across functions."""
    a_base, b_base = 0x80100000, 0x80101000
    cases = []

    # A returns a constant; B calls A and dereferences the result
    A = [enc_addiu(2, ZERO, 0x1234), enc_jr(RA), enc_nop()]
    B = [enc_jal(a_base), enc_nop(), enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("L1 a callee's constant return is substituted at the call site",
                  [(a_base, A), (b_base, B)],
                  lambda summ, acc: any(x.target == 0x1234 for x in acc)))

    # A returns its own first argument; B passes a constant
    A = [enc_addu(2, 4, ZERO), enc_jr(RA), enc_nop()]
    B = [enc_ori(4, ZERO, 0x8011), enc_jal(a_base), enc_nop(), enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("L2 a parameter passed through a return keeps its caller-side value",
                  [(a_base, A), (b_base, B)],
                  lambda summ, acc: any(x.base == (CONST, 0x8011) or x.target == 0x8011 for x in acc)))

    # a call with NO summary at all (target outside every region) must claim nothing
    B = [enc_jal(0x80500000), enc_nop(), enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("L3 an unknown callee leaves ret(name) unresolved, and nothing is attributed",
                  [(b_base, B)],
                  lambda summ, acc: all(x.target is None for x in acc)
                  and any(x.base[0] == RET for x in acc)))

    # L12: path sensitivity clears a polymorphic site and keeps a genuinely unsafe one
    callee = [enc_addiu(8, ZERO, 0x0A), enc_beq(4, 8, 2), enc_nop(),
              enc_lw(3, 0, 4), enc_jr(RA), enc_nop()]
    cases.append(("L12 an id-valued caller is cleared by path pruning, an unsafe one is not",
                  [(a_base, callee)],
                  lambda summ, acc, W=callee, S=a_base: (not deref_reachable(W, S, 0, 0x0A, summ))
                  and deref_reachable(W, S, 0, 0x0B, summ)))

    # L11: a dereferenced register argument passed a constant that cannot be a pointer
    callee = [enc_lw(3, 0, 4), enc_jr(RA), enc_nop()]
    # 0x0f564552 is the value M92/M93 found being inflated from: outside every mapped range, which is
    # the only shape this hardware lets us condemn by constant alone.
    bad = [enc_lui(4, 0x0F56), enc_ori(4, 4, 0x4552), enc_jal(a_base), enc_nop(), enc_jr(RA), enc_nop()]
    good = [enc_lui(4, 0x8011), enc_ori(4, 4, 0x5284), enc_jal(a_base), enc_nop(), enc_jr(RA), enc_nop()]
    cases.append(("L11 an out-of-map constant passed where the callee dereferences is flagged, and only there",
                  [(a_base, callee), (b_base, bad), (0x80300000, good)],
                  lambda summ, acc: _arg_case_ok()))

    # L10: the caller-side check flags a stack argument the caller never stored
    callee = [enc_lw(2, 0x10, SP), enc_jr(RA), enc_nop()]
    bad = [enc_addiu(SP, SP, -32), enc_jal(a_base), enc_nop(), enc_jr(RA), enc_nop()]
    good = [enc_addiu(SP, SP, -32), enc_lui(8, 0x8011), enc_ori(8, 8, 0x5284),
            enc_sw(8, 0x10, SP), enc_jal(a_base), enc_nop(), enc_jr(RA), enc_nop()]
    cases.append(("L10 the caller-side check flags a missing stack argument, and only for the bad caller",
                  [(a_base, callee), (b_base, bad), (0x80300000, good)],
                  lambda summ, acc: _stk_case_ok()))

    # L9: a callee's incoming stack argument resolves to the caller's outgoing store
    callee = [enc_lw(2, 0x10, SP), enc_jr(RA), enc_nop()]
    caller = [enc_addiu(SP, SP, -32), enc_lui(8, 0x8011), enc_ori(8, 8, 0x5284),
              enc_sw(8, 0x10, SP), enc_jal(a_base), enc_nop(), enc_lw(3, 0, 2),
              enc_jr(RA), enc_nop()]
    cases.append(("L9 an incoming stack argument resolves to the caller's outgoing store",
                  [(a_base, callee), (b_base, caller)],
                  lambda summ, acc: any(x.target == 0x80115284 for x in acc)))

    # L8: stack slots are keyed against the entry sp, so a frame adjustment does not lose them
    A = [enc_addiu(SP, SP, -32), enc_sw(4, 0x20, SP), enc_addiu(SP, SP, -16),
         enc_lw(2, 0x30, SP), enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("L8 a spilled value survives a frame adjustment (entry-relative slot keys)",
                  [(a_base, A)],
                  lambda summ, acc: any(x.base == (PARAM, 0) for x in acc)))

    # L7: an indirect jump through a table reaches handlers that no other edge can reach
    lo = 0x80200000
    A = [enc_lui(4, 0x8021), enc_lw(2, 0, 7), enc_sll(2, 2, 2), enc_addu(2, 2, 4),
         enc_lw(25, 0, 2), enc_jr(25), enc_nop()]
    A += [enc_nop()] * 5                                     # 7..11
    for i, (hi, off, tgt) in enumerate(((0x8011, 0x100, None), (0x8012, 0x100, None), (0x8013, 0x200, None))):
        A += [enc_lui(3, hi), enc_ori(3, 3, off), enc_lw(8, 0, 3), enc_jr(RA), enc_nop()]
        if i < 2:
            A += [enc_nop()] * 3
    MEM_WORDS.update({0x80210000: 0x80200030, 0x80210004: 0x80200050,
                      0x80210008: 0x80200070, 0x8021000C: 0x00000000})
    cases.append(("L7 a jump table's edges make its handlers reachable",
                  [(lo, A)],
                  lambda summ, acc: {x.target for x in acc if x.target} >= {0x80110100, 0x80120100, 0x80130200}
                  and all(not x.unreached for x in acc if x.target in (0x80110100, 0x80120100, 0x80130200))))

    # L6: a known base plus an unknown index keeps the base and claims nothing about the sum
    A = [enc_lui(4, 0x800E), enc_ori(4, 4, 0xB204), enc_lw(5, 0, 6), enc_addu(2, 4, 5),
         enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("L6 known base + unknown index is reported as base+?, not as unknown",
                  [(a_base, A)],
                  lambda summ, acc: any(x.base[0] == CBASE and x.base[1][0] == 0x800EB204 for x in acc)
                  and all(x.target is None for x in acc)))

    # L5: a branch-likely delay slot is conditional, so its constant must not survive
    A = [enc_beql(4, 0, 1), enc_addiu(4, ZERO, 0x2E), enc_lw(3, 0, 4), enc_jr(RA), enc_nop()]
    cases.append(("L5 a value set in a branch-likely delay slot does not survive",
                  [(a_base, A)],
                  lambda summ, acc: all(x.target is None for x in acc)))

    # a shifted parameter is parameter-derived, never an address
    A = [enc_sll(4, 4, 2), enc_lw(3, 0x10, 4), enc_jr(RA), enc_nop()]
    cases.append(("L4 a shifted parameter is reported as parameter-derived",
                  [(a_base, A)],
                  lambda summ, acc: any(x.base[0] == PAROFF for x in acc)
                  and all(x.target is None for x in acc)))
    return cases


def _stk_case_ok():
    """Both halves of L10: exactly one finding, at the caller that stored nothing."""
    findings = list(STK_FINDINGS.values())
    pcs = sorted(f["pc"] for f in findings)
    return pcs == [0x80101004] and findings[0]["missing"][0][2] == "interior"


def _arg_case_ok():
    """Exactly one finding, at the caller that passed 0x1234, and none for the valid pointer."""
    pcs = sorted(ARG_FINDINGS)
    return [pc for _, pc in pcs] == [0x80101008] and ARG_FINDINGS[pcs[0]]["value"] == 0x0F564552


def self_test2():
    passed = 0
    cases = fixture_cases_layer2()
    for name, regions, check in cases:
        STK_FINDINGS.clear()
        ARG_FINDINGS.clear()
        ARG_STATS.update({"deref": 0, "const_address": 0, "const_implausible": 0, "derived": 0, "unknown": 0})
        globals()["CHECK_STK"] = True
        globals()["CHECK_ARG"] = True                 # the check runs inside analyse; findings dedupe by pc
        summaries = summarise(regions)
        acc = []
        for start, words in regions:
            a, _, _ = analyse(words, start, summaries, {})
            acc.extend(a)
        try:
            ok = bool(check(summaries, acc))
        except Exception as exc:
            ok = False
            print("    exception in the check: %r" % exc)
        print("%s  %s" % ("PASS" if ok else "FAIL", name))
        if not ok:
            for a in acc:
                print("      %s" % a)
        passed += 1 if ok else 0
    globals()["CHECK_STK"] = False
    globals()["CHECK_ARG"] = False
    print("\n%d/%d (layer 2)" % (passed, len(cases)))
    return 0 if passed == len(cases) else 1


def self_test():
    passed = 0
    cases = fixture_cases()
    for name, words, check in cases:
        accesses, attributed, _ = analyse(words, BASE)
        try:
            ok = bool(check(accesses, attributed))
        except Exception as exc:                                # a fixture may legitimately run out of data
            ok = False
            print("    exception in the check: %r" % exc)
        print("%s  %s" % ("PASS" if ok else "FAIL", name))
        if not ok:
            for a in accesses:
                print("      %s  (%s)" % (a, fmt(a.base)))
        passed += 1 if ok else 0
    total = len(cases)
    print("\n%d/%d" % (passed, total))
    if total != 10:
        print("the fixture must contain exactly 10 cases; it has %d" % total)
        return 1
    return 0 if passed == total else 1


# --------------------------------------------------------------------------------------------- real images
def load_images(manifest=None):
    manifest = manifest or MANIFEST
    data = json.loads(Path(manifest).read_text())
    cart_sha = data.get("cart_sha256")
    rom = Path(ROM_PATH)
    if not rom.exists():
        sys.exit("cartridge not found at %s" % rom)
    blob = rom.read_bytes()
    import hashlib
    if hashlib.sha256(blob).hexdigest() != cart_sha:
        sys.exit("cartridge sha256 does not match the manifest — refusing to analyse")
    return [(im["name"], im["base"], im["size"], im.get("source")) for im in data["images"]], blob


def image_regions(name, base, words):
    """Ghidra's function ranges when available, else the heuristic — and count which was used."""
    regions = ghidra_regions(name, base, len(words))
    if regions is not None:
        REGION_STATS["ghidra_images"] += 1
        REGION_STATS["ranges"] += len(regions)
        REGION_STATS["covered"] += sum(e - s for s, e in regions)
        REGION_STATS["total"] += len(words)
        return regions
    REGION_STATS["fallback_images"].append(name)
    return function_bounds(words)


def image_words(blob, base, size, source=None):
    """Read an image's bytes from where they actually live.

    Only `boot` sits uncompressed in the cartridge (`source` = "ROM 0x…"); every other image is a
    **decompressed zlib member** listed as `assets/unpacked/…`, so reading the cartridge at
    `base - 0x7ffff480` returns compressed bytes — which decode as nonsense: stage2 then contains **zero**
    `jr ra` instructions and one prologue in 293 060 words. That looked like a boundary-heuristic problem
    and was a loader problem.
    """
    if source and source.startswith("ROM 0x"):
        raw = blob[int(source.split()[1], 16):]
    elif source:
        raw = Path(source).read_bytes()
    else:
        raw = blob[base - 0x7FFFF480:]
    raw = raw[:size]
    return list(struct.unpack(">%dI" % (len(raw) // 4), raw[:len(raw) // 4 * 4]))


DECOMP = "build/decomp"          # overridable (--decomp) so a synthetic fixture can drive the pipeline
ROM_PATH = "rom/Resident Evil 2 (USA) (Rev 1).z64"
MANIFEST = "build/elfs/images.json"
REGION_STATS = {"ghidra_images": 0, "fallback_images": [], "ranges": 0, "multi_range": 0,
                "covered": 0, "total": 0, "index_images": 0, "fixture_images": 0}


RANGES_FIXTURE = "fixtures/decomp/ranges.json"
_RANGES = {}


def fixture_ranges(name):
    """Committed address metadata distilled from the Ghidra index (tools/export_ranges.py).

    `build/decomp` is gitignored, so a fresh checkout has no index. The exact function boundaries still
    matter — measured in M130: with the prologue heuristic instead of the index, acceptance test 1b fails
    and revives the M117 artifact — so the ranges are committed as a 101 KB metadata fixture.
    """
    if not _RANGES:
        path = Path(RANGES_FIXTURE)
        _RANGES["images"] = json.loads(path.read_text()).get("images", {}) if path.exists() else {}
    return _RANGES["images"].get(name)


def ghidra_regions(name, base, nwords):
    """Function ranges from the Ghidra index, or from the committed distilled fixture.

    `end` is **inclusive** (`0x80000480..0x800004ef` is 28 words, and the next function starts at
    `0x800004f0`). Returns None when neither source knows this image, so the caller can fall back to the
    heuristic and say so.
    """
    pairs = None
    path = Path(DECOMP) / name / "decompile-index.json"
    if path.exists():
        pairs = []
        for fn in json.loads(path.read_text()).get("functions", []):
            for r in (fn.get("body") or {}).get("ranges") or []:
                pairs.append((int(r["start"], 16), int(r["end"], 16)))
        if len(pairs) > 0 and any(len((fn.get("body") or {}).get("ranges") or []) > 1
                                  for fn in json.loads(path.read_text()).get("functions", [])):
            REGION_STATS["multi_range"] += 1
        REGION_STATS["index_images"] += 1
    else:
        raw = fixture_ranges(name)
        if raw is None:
            return None
        pairs = [(int(s), int(e)) for s, e in raw]
        REGION_STATS["fixture_images"] += 1
    out, seen = [], set()
    for start_a, end_a in pairs:
        s_idx = max(0, (start_a - base) // 4)
        e_idx = min(nwords, (end_a + 4 - base) // 4)
        if e_idx <= s_idx or (s_idx, e_idx) in seen:
            continue
        seen.add((s_idx, e_idx))
        out.append((s_idx, e_idx))
    return out or None


def function_bounds(words):
    """Region boundaries: a prologue (`addiu sp,sp,-N`) or the instruction after a `jr ra`.

    An earlier version cut each function at its first `jr ra`, which silently **dropped every leaf
    function** — code after a `jr ra` with no prologue of its own got no entry state, so nothing in it
    was ever analysed. That was visible as a suspicious zero at a target the boot code demonstrably
    reaches. Both boundaries are heuristics; the honest statement is that they delimit *regions*, not
    proven functions.
    """
    """FALLBACK region splitter: prologue or post-`jr ra`. Used only for an image with no Ghidra index."""
    starts = {0}
    for i, w in enumerate(words):
        if (w >> 26) == 0x09 and ((w >> 21) & 0x1F) == SP and ((w >> 16) & 0x1F) == SP \
                and sext16(w & 0xFFFF) < 0:
            starts.add(i)                                        # prologue
        if i > 0 and words[i - 1] == 0x03E00008 and i < len(words):
            starts.add(i)                                        # code after `jr ra`: likely an entry
    starts = sorted(s for s in starts if s < len(words))
    bounds = []
    for bi, s in enumerate(starts):
        e = starts[bi + 1] if bi + 1 < len(starts) else len(words)
        bounds.append((s, e))
    return bounds


def run_images(target=None, window=0x10, census=False, out=None):
    images, blob = load_image_bytes()
    report = {"images": [], "target": None}
    for name, base, size, source in images:
        words = image_words(blob, base, size, source)
        total_acc = attr = 0
        kinds = {}
        for s, e in image_regions(name, base, words):
            accesses, attributed, _ = analyse(words[s:e], base + 4 * s)
            total_acc += len(accesses)
            attr += attributed
            for a in accesses:
                if a.unreached:
                    k = "unreached+const" if a.base[0] == CONST else "unreached"
                else:
                    k = a.base[0]
                kinds[k] = kinds.get(k, 0) + 1
            if target is not None:
                for a in accesses:
                    if a.target is not None and target <= a.target < target + window:
                        print("%-8s %08x  %-4s %08x  base=%s%+d" % (
                            name, a.pc, a.name, a.target, fmt(a.base), a.offset))
                        report["target"] = report["target"] or []
                        report["target"].append({"image": name, "pc": a.pc, "op": a.name,
                                                 "target": a.target})
        report["images"].append({"image": name, "accesses": total_acc, "attributed": attr,
                                 "unattributed": total_acc - attr,
                                 "bases": dict(kinds)})
        if census:
            print("%-10s %6d memory operands, %6d attributed (%.1f%%), %6d unrecognised" % (
                name, total_acc, attr, 100.0 * attr / max(total_acc, 1), total_acc - attr))
    print("jump tables: %d indirect jump(s) through a table, %d table(s) walked, "
          "%d entry(ies) inside the region, %d outside it, %d unresolvable" % (
              TABLE_STATS["jtent"], TABLE_STATS["tables"], TABLE_STATS["in_region"],
              TABLE_STATS["cross"], TABLE_STATS["unresolved"]))
    tot = sum(r["accesses"] for r in report["images"])
    at = sum(r["attributed"] for r in report["images"])
    dist = {}
    for r in report["images"]:
        for k, v in r["bases"].items():
            dist[k] = dist.get(k, 0) + v
    print("base kinds: " + ", ".join("%s %d" % (k, v) for k, v in sorted(dist.items(), key=lambda x: -x[1])))
    print("\n%d images: %d memory operands, %d attributed (%.1f%%), %d unrecognised "
          "(parameters, loaded bases, returns — step 2's input)" % (
              len(images), tot, at, 100.0 * at / max(tot, 1), tot - at))
    if out:
        Path(out).parent.mkdir(parents=True, exist_ok=True)
        Path(out).write_text(json.dumps(report, indent=1) + "\n")
        print("wrote %s" % out)
    return 0


def deref_reachable(words, start, k, value, summaries):
    """Is the callee's dereference of a_k still reachable when a_k is exactly `value`?

    This is one level of context sensitivity: seed the callee with the caller's constant and let constant
    branch pruning answer. A polymorphic callee that uses a_k as an id on one path and a pointer on
    another will have its pointer path pruned away for the id-valued callers.
    """
    acc, _, _ = analyse(words, start, summaries, {}, seed={4 + k: (CONST, value)})
    return any(a.base == (CONST, value) and not a.unreached for a in acc)


def load_image_bytes():
    """Populate IMAGES with each image's real bytes — the census path was missing this, so every table it
    tried to walk came back `unresolvable` while `--region` resolved the same tables fine."""
    images, blob = load_images()
    IMAGES.clear()
    for name, base, size, source in images:
        if source and source.startswith("ROM 0x"):
            off = int(source.split()[1], 16)
            IMAGES[base] = blob[off:off + size]
        elif source:
            IMAGES[base] = Path(source).read_bytes()[:size]
    return images, blob


def load_regions():
    """Every region in every image, keyed by start address, with its image name."""
    images, blob = load_images()
    regions, index = [], {}
    for name, base, size, source in images:
        words = image_words(blob, base, size, source)
        for s, e in image_regions(name, base, words):
            start = base + 4 * s
            regions.append((start, words[s:e], name))
            index[start] = (name, base + 4 * e)
    return regions, index


def acceptance():
    """The two pre-registered experiment-B tests, as executable checks so they cannot drift.

    Test 1's expectation was corrected in M117: the *structure* holds (record fields read through the
    function's own `a0`, two call sites in `FUN_8003287c`), but the argument is a byte loaded from the slot
    map at `0x800329ec`, so its provenance is `unk` — the earlier `ret(80001180)` was a labelling artifact
    of a missing substitution inside `paroff`.
    """
    global FOLLOW_POINTERS
    FOLLOW_POINTERS = True                       # test 2 needs the opt-in load-through rule
    load_image_bytes()
    regions, _ = load_regions()
    summaries = summarise([(st, w) for st, w, _ in regions], rounds=4)
    by_start = {st: (w, n) for st, w, n in regions}

    def region_of(addr):
        for st, w, n in regions:
            if st <= addr < st + 4 * len(w):
                return st, w
        return None, None

    checks = []

    st, w = region_of(0x800327EC)
    acc, _, _ = analyse(w, st, summaries, {})
    fields = sorted({a.offset for a in acc if a.base == (PARAM, 0) and a.name == "lw"})
    checks.append(("test 1a: FUN_800327ec reads its record fields through param(a0)",
                   {0x0, 0x4, 0x8, 0xC} <= set(fields), "offsets seen: %s" % [hex(x) for x in fields]))

    st, w = region_of(0x8003287C)
    acc, _, _ = analyse(w, st, summaries, {})
    sites = [(a.pc, a.args[0] if a.args else None) for a in acc if a.call_target == 0x800327EC]
    pc_ok = [hex(p) for p, _ in sites] == ["0x80032a04", "0x80032a84"]
    arg_ok = all(v == U for _, v in sites)
    checks.append(("test 1b: both call sites are in FUN_8003287c and the argument is unknown",
                   pc_ok and arg_ok,
                   "sites %s, a0 %s" % ([hex(p) for p, _ in sites],
                                        [fmt(v) if v else "?" for _, v in sites])))

    st, w = region_of(0x800329EC)
    acc, _, _ = analyse(w, st, summaries, {})
    want = {0x800329EC: 0x800EB204, 0x80032A5C: 0x800EB264}
    got = {a.pc: a.base[1][0] for a in acc if a.pc in want and a.base[0] == CBASE}
    checks.append(("test 2: the map read and the pointer-table load report their known base",
                   got == want, "got %s" % {hex(k): hex(v) for k, v in got.items()}))

    ok = 0
    for name, passed, detail in checks:
        print("%s  %s\n      %s" % ("PASS" if passed else "FAIL", name, detail))
        ok += 1 if passed else 0
    print("\n%d/%d acceptance check(s)" % (ok, len(checks)))
    return 0 if ok == len(checks) else 1


def run_layer2(args):
    global FOLLOW_POINTERS
    FOLLOW_POINTERS = bool(args.follow_pointers)
    load_image_bytes()
    regions, index = load_regions()
    summaries = summarise([(st, w) for st, w, _ in regions], rounds=4)

    deref = sum(1 for v in summaries.values() if any(p[0] == PARAM for p in v["params"]))
    const_ret = sum(1 for v in summaries.values() if v["ret"][0] == CONST)
    param_ret = sum(1 for v in summaries.values() if v["ret"][0] == PARAM)
    calls = sum(len(v["calls"]) for v in summaries.values())
    resolved = sum(1 for _, v in summaries.items() for _, t in v["calls"] if t in summaries)
    print("%d regions; %d deref a parameter, %d return a constant, %d return a parameter"
          % (len(regions), deref, const_ret, param_ret))
    print("%d call sites, %d resolve to a known region" % (calls, resolved))

    if args.region is not None:
        for start, words, name in regions:
            end = start + 4 * len(words)
            if start <= args.region < end:
                accesses, attributed, _ = analyse(words, start, summaries, {})
                print("\nregion %08x..%08x (%s), %d access(es)" % (start, end, name, len(accesses)))
                for a in accesses:
                    mark = "A" if a.target is not None else ("U" if a.unreached else " ")
                    print("%s %08x  %-4s base=%-22s off=%+#x%s" % (
                        mark, a.pc, a.name, fmt(a.base), a.offset,
                        ("  -> %08x" % a.target) if a.target is not None else ""))
                break
        else:
            print("no region contains %08x" % args.region)

    if args.callers is not None:
        print("\ncall sites of %08x, with the caller-side argument values:" % args.callers)
        shown = 0
        for start, words, name in regions:
            accesses, _, _ = analyse(words, start, summaries, {})
            for a in accesses:
                if a.call_target == args.callers:
                    print("  %-10s %08x in %08x  a0=%-18s a1=%-18s v0=%s" % (
                        name, a.pc, start,
                        fmt(a.args[0]) if a.args else "-", fmt(a.args[1]) if a.args else "-",
                        fmt(a.base)))
                    shown += 1
        if not shown:
            print("  none resolved to a known region (the callee has no summary)")

    if args.arg_check:
        globals()["CHECK_ARG"] = True
        ARG_FINDINGS.clear()
        sites = 0
        owner_map = {}
        for start, words, name in regions:
            CURRENT_IMAGE["name"] = name
            accesses, _, _ = analyse(words, start, summaries, {})
            sites += sum(1 for a in accesses if a.call_target)
            for a in accesses:
                if a.call_target:
                    owner_map[(name, a.pc)] = start
        globals()["CHECK_ARG"] = False
        print("%d call site(s) analysed; %d dereferenced register argument(s)" % (sites, ARG_STATS["deref"]))
        print("  %d passed a constant that IS a plausible address, %d passed a constant that cannot be one" % (
            ARG_STATS["const_address"], ARG_STATS["const_implausible"]))
        print("  %d derived (parameter/return/loaded), %d unknown" % (ARG_STATS["derived"], ARG_STATS["unknown"]))
        kept, cleared = [], []
        for (name, pc), f in sorted(ARG_FINDINGS.items()):
            # Resolve the callee: `boot` and `stage2` are resident and map disjoint address ranges, so
            # a target inside them is unambiguous. Overlays share vaddrs, so fall back to the caller's
            # own image first and only then to every candidate.
            all_c = [(st, w, n) for st, w, n in regions if st <= f["target"] < st + 4 * len(w)]
            resident = [c for c in all_c if c[2] in ("boot", "stage2")]
            same = [c for c in all_c if c[2] == name]
            chosen = resident or same or all_c
            candidates = [(st, w) for st, w, n in chosen]
            if not candidates:
                kept.append((name, pc, f, "callee address maps to no region"))
                continue
            if any(deref_reachable(w, st, f["k"], f["value"], summaries) for st, w in candidates):
                kept.append((name, pc, f, "deref still reachable in %s" % chosen[0][2]))
            else:
                cleared.append((name, pc, f))
        print("\n%d flagged site(s): %d cleared by path pruning (the callee's pointer path is "
              "unreachable for that value), %d kept" % (len(ARG_FINDINGS), len(cleared), len(kept)))
        for name, pc, f, why in kept:
            print("  KEPT    %-10s %08x in %08x -> %08x   a%d = %08x   (%s)" % (
                name, pc, owner_map.get((name, pc), 0), f["target"], f["k"], f["value"], why))
        for name, pc, f in cleared[:10]:
            print("  cleared %-10s %08x -> %08x   a%d = %08x" % (
                name, pc, f["target"], f["k"], f["value"]))
        if args.json:
            Path(args.json).parent.mkdir(parents=True, exist_ok=True)
            Path(args.json).write_text(json.dumps({"stats": ARG_STATS, "flagged": list(ARG_FINDINGS.values())},
                                                  indent=1) + "\n")
            print("wrote %s" % args.json)
        return 0

    if args.stk_check:
        globals()["CHECK_STK"] = True
        STK_FINDINGS.clear()
        sites = 0
        for start, words, name in regions:
            CURRENT_IMAGE["name"] = name
            accesses, _, _ = analyse(words, start, summaries, {})
            sites += sum(1 for a in accesses if a.call_target)
        globals()["CHECK_STK"] = False
        interior = [(pc, f) for pc, f in STK_FINDINGS.items()
                    if any(k == "interior" for _, _, k in f["missing"])]
        forwarded = [(pc, f) for pc, f in STK_FINDINGS.items()
                     if all(k == "forwarded" for _, _, k in f["missing"])]
        print("%d call site(s) analysed; %d of them leave a stack argument unsupplied" % (
            sites, len(STK_FINDINGS)))
        print("  %d site(s) where the missing slot is INSIDE the caller's own frame (a store was "
              "expected and is absent)" % len(interior))
        print("  %d site(s) where it lies above the caller's entry sp (the value is passed straight "
              "through from the caller's caller)" % len(forwarded))
        def owner(pc):
            for start, words, name in regions:
                if start <= pc < start + 4 * len(words):
                    return name, start
            return "?", 0
        print("\nfirst 20 interior cases (caller region, call site, target, missing biases):")
        for pc, f in sorted(interior)[:20]:
            name, start = owner(pc)
            print("  %-10s %08x in %08x -> %08x   biases %s" % (
                name, pc, start, f["target"],
                [("%+d" % b) for b, _, _ in f["missing"] if True]))
        if args.json:
            Path(args.json).parent.mkdir(parents=True, exist_ok=True)
            Path(args.json).write_text(json.dumps({
                "sites": sites,
                "unsupplied": len(STK_FINDINGS),
                "interior": [{"pc": pc, "target": f["target"],
                              "missing": [b for b, _, k in f["missing"] if k == "interior"]}
                             for pc, f in sorted(interior)],
                "forwarded": len(forwarded)}, indent=1) + "\n")
            print("wrote %s" % args.json)
        return 0

    if args.census:
        tot = attr = 0
        kinds = {}
        for start, words, name in regions:
            accesses, attributed, _ = analyse(words, start, summaries, {})
            tot += len(accesses)
            attr += attributed
            for a in accesses:
                if a.unreached:
                    k = "unreached+const" if a.base[0] == CONST else "unreached"
                else:
                    k = a.base[0]
                kinds[k] = kinds.get(k, 0) + 1
        print("base kinds: " + ", ".join("%s %d" % (k, v) for k, v in sorted(kinds.items(), key=lambda x: -x[1])))
        print("regions: %d image(s) resolved (%d from build/decomp, %d from fixtures/decomp), "
              "%d range(s), %d multi-range function(s), "
              "%.1f%% of image bytes inside a known function; fallback heuristic used for: %s" % (
                  REGION_STATS["ghidra_images"], REGION_STATS["index_images"],
                  REGION_STATS["fixture_images"], REGION_STATS["ranges"], REGION_STATS["multi_range"],
                  100.0 * REGION_STATS["covered"] / max(REGION_STATS["total"], 1),
                  ", ".join(REGION_STATS["fallback_images"]) or "none"))
        h = SLOT_STATS["hit"]
        m = SLOT_STATS["miss_merge"] + SLOT_STATS["miss_never"] + SLOT_STATS["miss_unstable"]
        print("stack arguments: %d asked for by a callee, %d supplied by the caller (%.1f%%)" % (
            STK_STATS["asked"], STK_STATS["resolved"],
            100.0 * STK_STATS["resolved"] / max(STK_STATS["asked"], 1)))
        print("frame slots: %d access(es), %d resolved (%.1f%%); missed: %d never stored in this region, "
              "%d killed by a merge, %d with an unstable frame" % (
                  h + m, h, 100.0 * h / max(h + m, 1), SLOT_STATS["miss_never"],
                  SLOT_STATS["miss_merge"], SLOT_STATS["miss_unstable"]))
        print("%d regions, %d memory operands, %d attributed (%.1f%%), %d unrecognised" % (
            len(regions), tot, attr, 100.0 * attr / max(tot, 1), tot - attr))
        if args.json:
            Path(args.json).parent.mkdir(parents=True, exist_ok=True)
            Path(args.json).write_text(json.dumps(
                {"regions": len(regions), "operands": tot, "attributed": attr, "kinds": kinds}, indent=1) + "\n")
            print("wrote %s" % args.json)
        return 0

    if args.unk_causes:
        hist = {}
        for start, words, name in regions:
            accesses, _, _ = analyse(words, start, summaries, {})
            for a in accesses:
                if a.base[0] == UNK and not a.unreached:
                    hist[a.cause or "?"] = hist.get(a.cause or "?", 0) + 1
        total = sum(hist.values())
        print("\n%d unknown-base operand(s), by the instruction that made the base unknown:" % total)
        for k, v in sorted(hist.items(), key=lambda x: -x[1])[:20]:
            print("  %-14s %6d  %5.1f%%" % (k, v, 100.0 * v / max(total, 1)))
        return 0

    if args.param_accesses:
        lo = args.near - args.window2 if args.near is not None else 0
        hi = args.near + args.window2 if args.near is not None else 1 << 32
        print("\nparameter-derived accesses%s:" % (
            "" if args.near is None else " within %08x +-%#x" % (args.near, args.window2)))
        shown = 0
        for start, words, name in regions:
            accesses, _, _ = analyse(words, start, summaries, {})
            for a in accesses:
                if a.base[0] in (PARAM, PAROFF) and lo <= a.pc < hi:
                    print("  %-10s %08x  %-4s base=%-22s off=%+#x" % (
                        name, a.pc, a.name, fmt(a.base), a.offset))
                    shown += 1
        if not shown:
            print("  none (a parameter-derived base inside the window)")
    return 0


def corpus_self_test():
    """Drive the whole corpus pipeline over `fixtures/corpus` and assert mechanism-level invariants.

    A synthetic cartridge cannot reproduce RE2's addresses, so this does not re-test the pre-registered
    acceptance findings. What it does is exercise the code path CI otherwise never touches: manifest and
    cartridge loading, Ghidra-index regions, the interprocedural fixpoint, and the three checkers — the
    places where the whole-corpus crashes lived (M115's stale key, M119/M120's un-threaded state).
    """
    global ROM_PATH, MANIFEST, DECOMP
    ROM_PATH, MANIFEST, DECOMP = "fixtures/corpus/cart.z64", "fixtures/corpus/images.json", "fixtures/corpus/decomp"
    images, _ = load_image_bytes()
    regions, _ = load_regions()
    summaries = summarise([(st, w) for st, w, _ in regions], rounds=3)

    checks = []
    checks.append(("one synthetic image, three regions taken from the fixture's index",
                   len(images) == 1 and len(regions) == 3,
                   "%d image(s), %d region(s)" % (len(images), len(regions))))

    tot = attr = 0
    kinds = {}
    for st, w, name in regions:
        acc, a, _ = analyse(w, st, summaries, {})
        tot += len(acc)
        attr += a
        for x in acc:
            k = ("unreached+const" if x.base[0] == CONST else "unreached") if x.unreached else x.base[0]
            kinds[k] = kinds.get(k, 0) + 1
    checks.append(("the census identity holds: every bucket accounted for",
                   sum(kinds.values()) == tot,
                   "%d operand(s) in %s" % (tot, dict(sorted(kinds.items())))))
    checks.append(("attribution equals the const bucket, and finds the fixture's one address",
                   attr == kinds.get("const", 0) == 1,
                   "attributed %d, const %d" % (attr, kinds.get("const", 0))))

    target = 0x800004B0
    sites = []
    for st, w, name in regions:
        for a in analyse(w, st, summaries, {})[0]:
            if a.call_target == target:
                sites.append(a.pc)
    checks.append(("the jal resolves to the fixture's third region",
                   sites == [0x800004A0], "sites %s" % [hex(x) for x in sites]))

    globals()["CHECK_STK"] = True
    STK_FINDINGS.clear()
    for st, w, name in regions:
        analyse(w, st, summaries, {})
    globals()["CHECK_STK"] = False
    checks.append(("the stack-argument checker runs and finds nothing to flag",
                   len(STK_FINDINGS) == 0, "%d finding(s)" % len(STK_FINDINGS)))

    globals()["CHECK_ARG"] = True
    ARG_FINDINGS.clear()
    ARG_STATS.update({"deref": 0, "const_address": 0, "const_implausible": 0, "derived": 0, "unknown": 0})
    for st, w, name in regions:
        analyse(w, st, summaries, {})
    globals()["CHECK_ARG"] = False
    checks.append(("the register-argument checker runs, and the caller passes a derived value",
                   len(ARG_FINDINGS) == 0 and ARG_STATS["deref"] > 0 and ARG_STATS["derived"] > 0,
                   "deref %d, derived %d, flagged %d" % (
                       ARG_STATS["deref"], ARG_STATS["derived"], len(ARG_FINDINGS))))

    passed = 0
    for name, ok, detail in checks:
        print("%s  %s\n      %s" % ("PASS" if ok else "FAIL", name, detail))
        passed += 1 if ok else 0
    print("\n%d/%d corpus mechanism check(s)" % (passed, len(checks)))
    return 0 if passed == len(checks) else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--self-test2", action="store_true")
    ap.add_argument("--acceptance", action="store_true", help="run the two experiment-B acceptance tests")
    ap.add_argument("--corpus-self-test", action="store_true",
                    help="drive the corpus pipeline over fixtures/corpus (no cartridge needed)")
    ap.add_argument("--rom", default=None, help="cartridge path (default: rom/Resident Evil 2 (USA) (Rev 1).z64)")
    ap.add_argument("--manifest", default=None, help="image manifest (default: build/elfs/images.json)")
    ap.add_argument("--decomp", default=None, help="Ghidra index root (default: build/decomp)")
    ap.add_argument("--arg-check", action="store_true",
                    help="flag a dereferenced register argument passed a constant that cannot be a pointer")
    ap.add_argument("--stk-check", action="store_true",
                    help="flag call sites whose callee reads a stack argument the caller never stored")
    ap.add_argument("--layer2", action="store_true", help="interprocedural fixpoint over the cartridge")
    ap.add_argument("--region", type=lambda s: int(s, 0), help="dump every access in the function holding this address")
    ap.add_argument("--param-accesses", action="store_true", help="list parameter-derived accesses")
    ap.add_argument("--callers", type=lambda s: int(s, 0), help="call sites of a function, with caller-side arguments")
    ap.add_argument("--unk-causes", action="store_true", help="histogram of why bases are unknown")
    ap.add_argument("--follow-pointers", action="store_true",
                    help="treat a word loaded from a constant address as a pointer when it lands in RDRAM")
    ap.add_argument("--near", type=lambda s: int(s, 0), help="with --region/--param-accesses: stay within this vaddr")
    ap.add_argument("--window2", type=lambda s: int(s, 0), default=0x4000)
    ap.add_argument("--target", type=lambda s: int(s, 0))
    ap.add_argument("--window", type=lambda s: int(s, 0), default=0x10)
    ap.add_argument("--census", action="store_true")
    ap.add_argument("--json", default="manifests/provenance.json")
    args = ap.parse_args()
    global ROM_PATH, MANIFEST, DECOMP
    if args.rom:
        ROM_PATH = args.rom
    if args.manifest:
        MANIFEST = args.manifest
    if args.decomp:
        DECOMP = args.decomp
    if args.corpus_self_test:
        return corpus_self_test()
    if args.self_test:
        return self_test()
    if args.self_test2:
        return self_test2()
    if args.acceptance:
        return acceptance()
    if args.layer2 or args.region or args.param_accesses or args.callers is not None \
            or args.unk_causes or args.census or args.stk_check or args.arg_check:
        return run_layer2(args)
    return run_images(args.target, args.window, args.census or args.target is None, args.json)


if __name__ == "__main__":
    raise SystemExit(main())
