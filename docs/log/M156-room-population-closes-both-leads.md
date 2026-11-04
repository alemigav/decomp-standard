# M156 — both leads closed, by asking a smaller question

The two leads from M152/M153 are closed — not by better modelling but by noticing the population was wrong:
**only 50 of the 1 087 "script blocks" are room scripts.** Everything M151–M154 measured about "dead code" was
mostly about files the room loader never loads.

## 1. The population

`DAT_80131fa8` — the table `0x8009b27c` uses to pick a room's script (M145) — holds **285 ids**. Of those,
**50 are present as script blocks** and 116 have no block at all. Against that, my heuristic admits **1 087**
blocks, so **~95 % of what was being analysed is not a room script**. The three object-table writers from M153
(`0x6a`, `0x7a`, `0x7f`) do not occur in *any* room script.

That single fact recontextualises four milestones, and it is the kind of error that no amount of care inside the
model would have caught: the model was fine, the **sample** was wrong.

## 2. Lead 1 — the `0x10` stack assumption: immaterial for room scripts

* 67 blocks have a record 0 that begins with `0x10`; **0 of them are in the room table**.
* Within the 50 room scripts, exactly **one** of 468 record walks ends at a `0x10` pop.

So the assumption that mattered for 115 non-room blocks costs one record in the population we care about. Closed
as: *the stack assumption is immaterial for room scripts; the earlier 115 were an artefact of the sample.*

## 3. Lead 2 — the ~250 stream exits: zero in room scripts

Within the 50 room scripts, **no walk leaves the command stream at all**. All 468 record walks end at a jump, a
dynamic opcode or a terminator:

| how the walk stops | count |
|---|---|
| jump `0x0d ForStart` | 251 |
| jump `0x18 GoSub` | 103 |
| jump `0x17 Goto` | 49 |
| jump `0x13 Switch` | 47 |
| jump `0x07 ElseStart` | 8 |
| terminator `0x01` | 5 |
| dynamic `0x36` | 4 |
| pop `0x10` | 1 |

(The jump rows are the census stopping at the jump, not a property of the code.) Every "left the command stream"
case was in a non-room block. Closed as: *the stream-exit worry does not exist in the room-script population.*

## 4. The dead-code residue, final

Under the generous closure, within room scripts, **two opcodes** appear only in code unreachable from record 0:

| opcode | occurrences | what it is |
|---|---|---|
| `0x8a` | 4 | **queue post**: `FUN_80052bd0(u16@2, u16@4)`, which allocates a slot via `FUN_80052f10`/`FUN_80052eec` on the queue at `0x8010bfd8` |
| `0x8b` | 1 | the same shape against the queue at `0x8010c124`, via `FUN_80052c6c(u16@2, u8@1, u16@4)` |

Five occurrences of two request-posting commands, in records no room script reaches. That is the whole remaining
claim, and it is small enough to state without hedging: **no path from a room's script entry reaches these five
commands.**

## 5. Tooling: the population is now a mode, not a judgement call

`cfg_reach.py` gained `--rooms` (restrict to the loader's id table) and `--check-rooms`, with three gated cases:
the table resolves a population of the right size, **no room-script walk leaves the command stream**, and the
three object-table writers never occur there. The audit gained a matching entry — disabling the filter makes the
second case fail, so the room-scoping itself is proven load-bearing (**11/11 audits, 0 vacuous**).

## 6. Gate

**150 cases across 16 fixtures**, `ci.sh: ok`, 18/18 marker checks.

## 7. The lesson this milestone is actually about

Five milestones of increasingly careful modelling, and the decisive step was a **join against a table that had
been on disk since M145**. The corpus was never the object of study; the room table was. Recording it as the
rule: *before modelling a population, prove the population*. The audit gates would not have caught this one —
every check passed, on the wrong sample — which is why it belongs in the log next to them.
