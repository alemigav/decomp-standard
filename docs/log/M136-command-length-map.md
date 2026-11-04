# M136 — the 141 handlers, mapped: every opcode advances the stream by its own N

The worklist that opened this session was M97/M98-era: map the command lengths, find the script
initializer, and settle bank C at runtime. Two of the three were already answered (M99 for the stride,
M110 for bank C) and one was answered **in the wrong shape** — the "initializer" is not an initializer.
What was genuinely missing is the artifact: the length map was computable by `walk_stream.py` but had
never been printed, so nobody had seen all 141 entries at once. That is now measured, and it settles
M97 §4 completely.

## 1. The map — 141 of 141, fifteen distinct lengths

```
python3 tools/walk_stream.py --lens        # 141/141 opcodes mapped, exit 0
```

Every table entry at `0x80113898` points at a handler that advances the command pointer itself:

| N | entries | opcodes |
|---|---|---|
| 1 | 26 | `0x00`, `0x01`, `0x02`, `0x09`, `0x0b`, `0x0c`, `0x1c`, `0x1e`, `0x1f`, `0x20`, `0x26`, `0x27`, `0x28`, `0x2a`, `0x30`, `0x42`, `0x63`, `0x66`, `0x6c`, `0x70`, `0x71`, `0x79`, `0x83`, `0x86`, `0x87`, `0x89` |
| 2 | 31 | `0x05`, `0x07`, `0x08`, `0x0d`, `0x0e`, `0x0f`, `0x10`, `0x11`, `0x12`, `0x15`, `0x16`, `0x1b`, `0x29`, `0x3c`, `0x40`, `0x46`, `0x47`, `0x4a`, `0x4e`, `0x5a`, `0x5b`, `0x5d`, `0x5e`, `0x5f`, `0x62`, `0x65`, `0x69`, `0x6f`, `0x80`, `0x84`, `0x88` |
| 3 | 15 | `0x0a`, `0x25`, `0x2d`, `0x2e`, `0x35`, `0x38`, `0x3d`, `0x48`, `0x49`, `0x4b`, `0x5c`, `0x72`, `0x76`, `0x81`, `0x82` |
| 4 | 35 | `0x03`, `0x04`, `0x06`, `0x17`, `0x18`, `0x19`, `0x1a`, `0x1d`, `0x21`, `0x22`, `0x24`, `0x2f`, `0x31`, `0x32`, `0x33`, `0x34`, `0x3f`, `0x43`, `0x4f`, `0x50`, `0x52`, `0x53`, `0x56`, `0x58`, `0x59`, `0x61`, `0x6a`, `0x6b`, `0x6d`, `0x74`, `0x77`, `0x7c`, `0x7d`, `0x7e`, `0x7f` |
| 5 | 8 | `0x36`, `0x37`, `0x3a`, `0x45`, `0x4c`, `0x54`, `0x64`, `0x75` |
| 6 | 11 | `0x13`, `0x14`, `0x23`, `0x2b`, `0x3e`, `0x55`, `0x6e`, `0x78`, `0x85`, `0x8a`, `0x8b` |
| 8 | 5 | `0x39`, `0x51`, `0x57`, `0x73`, `0x8c` |
| 10 | 1 | `0x41` |
| 14 | 1 | `0x60` |
| 16 | 2 | `0x7a`, `0x7b` |
| 20 | 1 | `0x2c` |
| 22 | 2 | `0x44`, `0x4d` |
| 28 | 1 | `0x67` |
| 32 | 1 | `0x3b` |
| 40 | 1 | `0x68` |

Sum 141. The 141 entries resolve to **138 distinct handler addresses**: `0x8006db14` serves four
opcodes (`0x00`, `0x1e`, `0x1f`, `0x20`), each length 1 — four spellings of a one-byte no-operand
command. **No handler advances backwards**; the two backward advances M99 found (`−256`, `−38`) are in
loop code at `0x80084c20` and `0x80099388`, not in the table.

## 2. Action 1, answered: variable — the dispatcher delegates advancement

The lengths are **variable**, 15 distinct values from 1 to 40, so the answer to the question as posed
is: the dispatcher does *not* advance. It reads byte 0, indexes the table, and `jalr`s; the handler
advances `ctx+0x1c` by its own N. That is the standard VM arrangement, and it is now measured for
**every** entry rather than inferred from a sample.

**M97's "inconsistency" is therefore resolved, not smoothed over.** The `+2` at `0x8006e150` belongs to
`FUN_8006e138` — opcode `0x12`, a **2-byte block command** — and opcode `0x0f` (`FUN_8006dfe4`) is the
same shape. Byte-3 reads belong to the 22-byte family (`0x44`, `0x4d`). A 2-byte command cannot have a
meaningful byte 3, and no 2-byte command is read at byte 3: the two facts were always about different
command classes.

## 3. Action 2: `FUN_8006e1bc` is a nested-block runner, not an initializer

M97 predicted "no `jal` callers ⇒ it is itself an opcode handler". **Both halves of that are false**,
and the correction matters because it identifies the construct:

* It has **two `jal` callers**, both in stage-2: `0x8006e05c` inside `FUN_8006dfe4` (table entry `0x0f`)
  and `0x8006e160` inside `FUN_8006e138` (table entry `0x12`).
* It is **not** in the table (checked all 141 entries), and no `lui`+`addiu`/`jalr` construction of its
  address exists in stage-2.

What it is, read from its own body: a **block runner**. The call site at `0x8006e150` sets it up as

```
0x8006e150  addiu a1,a1,2        ; past the block header
0x8006e154  sw    a1,28(r17)     ; ctx+0x1c = first inner command
0x8006e158  lbu   a2,-1(a1)      ; a2 = the header's byte 1  <- the block's span
0x8006e15c  lb    s0,2(r17)      ; the block's context field
0x8006e160  jal   0x8006e1bc
```

and the callee computes its stop address as `r19 = a1 + a2` (`0x8006e1fc addu r19,a1,a2`), dispatches
inside its own loop (`0x8006e1e4 lbu v0,0(a1)` → `0x8006e1e8 addiu s0,v1,14488` → `jalr v0`), and exits
when `ctx+0x1c` reaches it (`0x8006e204 beq a1,r19`). So a 2-byte command `[opcode][span]` executes the
inner block of `span` bytes — which is exactly where M97's `+2` lives: **it is the block header's own
length, not a command stride.**

The room-loading code that hands the stream to the interpreter is therefore **not** a caller of this
function; it is the two writers of `*(0x800df92c)` that M98 already found — the overlay's
`FUN_8016e8d0` at `0x8016ea70` (fixed buffer) and stage-2's `FUN_800635b0` at `0x80063698` (heap list) —
with `FUN_8006d8f0` reading the pointer and `jal FUN_8006da14` to start the loop.

## 4. Action 3: bank C was settled at M110 — no new dump was taken

Recorded rather than re-run, because M110 closed it by measurement and then took a decision. The
observed value **is** inside the range the worklist asked about: byte 3 = **31** in every one of eight
room captures spanning **three rooms** (three distinct stream-pointer pairs, matching the owner's two
door animations), and slot 31's entry in the immutable 48-byte map is **0**, so the loader is handed
`cart_record(0)` — the `OVERLAYTABLENUM` marker — branch 2 fails its inflate, and the return is
discarded with the destination unchanged. `31 ∈ [16, 32)`, so the "silent failed inflate" branch was the
one observed, and it is **by design**, not a hunting target.

Re-running ares to re-derive that would use a weaker instrument: M109 measured that the debugger route
feeds the game `ff ff ff ff` (no controller), and M110's own decision reads **"No more ares dumps."**
Overturning that needs a reason the existing three-room evidence does not already answer — a capture in
a room whose script differs, which is a playthrough, not an emulator session.

## 5. What changed in the tools, and two wrong turns worth recording

`walk_stream.py` now derives all 141 lengths, prints them (`--lens`), and carries a synthetic fixture
(`--self-test`, 8/8) wired into `acceptance.py` as a tenth suite — **98 cases across 10 fixtures**, green.
`--lens` **fails** (exit 1) on a missing length or on fewer than two distinct lengths, the second being
the non-vacuity condition: a scan that sees nothing also reports no inconsistency. Verified by breaking
it — pointing entry `0x4d` at a padding word gives `FAIL 1 opcode(s) with no derived advance: ['0x4d']`,
`140/141`, exit 1.

Two rewrites I attempted first were **wrong, and were discarded rather than shipped**:

* a clobber-tracking forward scan (register set, invalidation on write) produced **74/141** and nonsense
  lengths — hand-rolled dataflow, not worth carrying;
* widening the proven idiom's window to 0x80 and allowing a different destination register mapped
  **141/141** but changed **ten** handlers' lengths (`0x0f` 2→4, `0x0f` is measured `+2` at
  `0x8006e150`), because a later, unrelated `addiu` from the same register matched.

What shipped instead is a **fallback pass**: the proven single-register idiom first (140 entries), then
the cross-register form only where it found nothing — which adds exactly one entry, `0x4d = 22`
(handler `0x8009bd84`: `lw a1,0x1c(a3)` at `0x8009bd90`, `addiu v0,a1,22` at `0x8009be54`,
`sw v0,0x1c(a3)` at `0x8009be58`). The other 140 results are byte-identical to before.

Also recorded: my own first all-image `jal` scan reported "no callers" for `FUN_8006e1bc` because I
computed the target as `pc + 4 + ((imm26 << 2) − 0x10000000)`; the correct form is
`((pc + 4) & 0xF0000000) + (imm26 << 2)`. A wrong answer about the *absence* of a caller is the same
class of error as the near-miss lists M99 warns about, and it very nearly became a section of this note.

## 6. What this settles, what it leaves

**Settled:** the stride question for all 141 opcodes; M97 §4's inconsistency (block headers vs command
lengths); the identity of `FUN_8006e1bc` (block runner, two handler callers, not a handler); and bank C's
runtime posture (M110, unchanged).

**Left:** the *contents* of the command stream (runtime, M99) and the meaning of the 141 opcodes — the
lengths are known, the semantics of 138 handlers are not named. The `+38` advance in the global sweep at
`0x8009936c` is loop code, as are `−38` and `−256`.

**Limit stated:** a length is derived from the advance idiom, so a handler that advances by a *computed*
amount (`addu a1,a1,t0`, the second flavour M98 named) would be missed rather than mis-measured. All 141
entries currently match a constant form, so that gap is not currently biting — but it is a gap in the
method, not a proof that every command length is a constant.

```
python3 tools/walk_stream.py --lens            # 141/141, 15 distinct lengths
python3 tools/walk_stream.py --self-test       # 8/8
python3 tools/acceptance.py                    # 98 cases, 10 fixtures
```
