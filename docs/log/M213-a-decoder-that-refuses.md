# M213 — a decoder that refuses

The Script VM has had a length map since M136 and a registry since M211. What it did not have is a program that
takes bytes, produces instructions and a state machine, and **fails loudly** where the format is unknown. That is
what `tools/scd_vm.py` is, and the refusals are the design.

## 1. What it decodes

A real room end to end: `--decode 0` resolves file id 1881, decompresses 538 B, finds **9 records**, and walks
them into a deterministic trace — one record per step:

```
0x012 0x13 Switch           advance   4  continue   0x28 (cmd+22), 0x16 (fall-through)
0x016 0x14 SwitchCase       advance   6  continue   -
```

Each step carries `pc`, opcode, name, the advance *and how it was obtained*, its successors with their evidence,
and the resulting state (`continue` / `yield` / `blocked` / `terminated`). The scheduler contract is the
interpreter's own (`src/stage2/FUN_8009b880.c`): a handler returning 1 runs again, 2 yields — the case the
project had only as a reading until M210 pinned it by source shape.

**No game effects.** The decoder does not spawn anything, render anything, or claim that a computed jump target
is valid code. It claims the instruction stream and the state transitions, and the docstring says so.

## 2. The refusals, which are the milestone

| situation | behaviour |
|---|---|
| an opcode with **no** advance (`0x36`, a callback pointer) | raises `UnresolvedAdvance`, naming the opcode and the registry's note |
| a byte outside the record | raises with the offset and the opcode |
| an unknown opcode byte | raises, naming the byte |
| a truncated instruction | raises rather than returning a short read |
| a step cap reached without a state | `--check` fails; a decode never "ends because it got tired" |

The mutation that keeps this honest disables exactly one of them: `if cls == "unresolved": raise …` becomes
`pass`, and the case reports *"no advance at all: 0x36 dispatches through a callback pointer, so it is unresolved:
got …"*. A decoder that silently advances by one byte on an unknown command is the failure mode this project has
spent several milestones learning to catch — M141's phantom multi-advance family was exactly a walk that kept
walking.

## 3. Agreement with the existing models, not a second one

The decoder imports `walk_stream.succ`, `JUMP_FAMILY` and `cfg_reach`'s push/pop sets rather than restating them,
and the gate asserts that: **the two sets the trace pushes and pops are `cfg_reach`'s, unchanged**, and the
conditional-branch case records both successors. Where the registry and the walker disagree, the decoder does not
pick a winner — it reports.

## 4. Gates

`script vm decoder (cartridge)`: **33 cases** — **26** synthetic (15 fixture cases: fall-through, both branch
arms, computed jump, GoSub + return, block push/pop, yield, truncated instruction, unknown opcode, no-advance
opcode; 3 operand; 8 registry) and **7** on a real room (determinism, the state histogram, the GoSub return
through the block's own record table, and the `cfg_reach` agreement).

**Two corrections to what I first wrote, both from the build:** the registry has **10** opcodes without a
constant advance, not 9 — 4 jump-family (`0x07 0x13 0x17 0x18`), 5 modelled (`0x10`/`0x1a` block slots,
`0x19`/`0x01` GoSub slot, `0x03` record table) and exactly **1** that raises (`0x36`, callback dispatch); and
`0x01` and `0x19` share one registry expression, so `0x01` is a GoSub return when a slot is open and a
scheduler yield otherwise — it ends 5 of room 0's 9 records.

**And the number that makes it a research result rather than a tool:** sweeping all **256 rooms** — **107 decode
cleanly**, **53 hit at least one honest refusal** (mostly `0x36`, or a record start at `0x141` that is not code),
and **90 have no block entry at all**. A decoder that refused nothing would have reported 256 successes and
taught nothing.

One mutation, verified to fail its own case: the unresolved advance becomes a silent skip.
