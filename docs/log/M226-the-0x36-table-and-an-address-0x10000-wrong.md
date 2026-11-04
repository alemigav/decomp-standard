# M226 — the 0x36 table: five entries, and an address that was 0x10000 wrong

The plan's step 4, and the smallest milestone in this arc with the largest correction in it. `0x36` has been
described since M211 as `jr <*(0x800c98e0 + (s16[cmd+4] >> 8)*4)>` — *"a callback pointer, not a command
address"* — which is why `scd_vm.py` refuses it and why two of 256 rooms could never be decoded. Both halves
of that sentence are wrong, and the second one is wrong because the first one was.

## 1. The address: `addiu` sign-extends

The handler builds the base in two instructions:

```
800711b0  3c02800c   lui   v0,0x800c
800711b4  244298e0   addiu v0,v0,-26400
```

`244298e0` encodes the immediate `0x98e0`, which `addiu` **sign-extends**: it is −0x6720, so the base is
`0x800c0000 − 0x6720 = **0x800B98E0**`. Reading the immediate as unsigned gives `0x800C98E0`, exactly
0x10000 higher — and *that* address holds 259 zero words in the image. So "the table is empty, therefore it
must be filled at runtime" was a coherent explanation of a table that is **static, five entries, and 0x10000
lower**:

```
0x800b98e0:  800711cc 800711dc 800711fc 8007121c 8007124c
```

Five code addresses, and the corpus had them all along: Ghidra resolved this dispatch as a `switch` with
five cases (`switchD_800711c4::caseD_0`…`caseD_4`) because it followed the table Ghidra could find. The
project's documents disagreed with its own decompilation for fifteen milestones, and nobody put the two side
by side.

**I made the same mistake while looking for it.** My first scan searched for `lui 0x800c` followed by `addiu`
with immediate `0x98e0`, found nothing, and I wrote "there is no `0x800c98e0` anywhere in stage-2" — printing
the conclusion before checking the one word whose low half is `0x98e0`. It was `244298e0` all along. A
displacement read with the wrong sign is not a subtle error; it is a *repeatable* one, which is why the
correction now lives in a gate rather than in a note.

## 2. The dispatch: a bounds-checked index into five arms

```
80071194  8e30001c   lw    s0,28(s1)        # s0 = ctx->0x1c = the command pointer
80071198  86050004   lh    a1,4(s0)         # the halfword at cmd+4
800711a4  00052202   srl   a0,a1,8          # idx = u16[cmd+4] >> 8
800711a8  2c820005   sltiu v0,a0,5          # idx < 5 ?
800711ac  10400032   beq   v0,zero,0x80071278
800711c0  8c620000   lw    v0,0(v1)          # v1 = 0x800b98e0 + idx*4
800711c4  00400008   jr    v0                # through the table entry
```

The entry count is not a guess: it is the `5` in `sltiu`, and the five table words agree. The **high** byte
of `u16[cmd+4]` is the sub-opcode; the **low** byte is a separate operand that two of the arms index by.

Each arm is folded from its own instructions (a three-register `constant + coefficient × lo` evaluator, so
none of this is read off a decompiler's local names):

| idx | arm | selects |
|---|---|---|
| 0 | `0x800711cc` | the zero base — all three offsets start from 0 |
| 1 | `0x800711dc` | a pointer loaded from `0x800e13e8`; the tail reads `+0x28/+0x2c/+0x30` through it |
| 2 | `0x800711fc` | a pointer loaded from `0x800e13ec` |
| 3 | `0x8007121c` | a pointer loaded from `0x800e13f0 + 4·lo` |
| 4 | `0x8007124c` | a row at `0x800e18f8 + 0x368·lo`, dereferenced by the tail |

All five reach the same tail (`0x80071278`/`0x80071284`), which adds `s16[cmd+6/8/10]` to the three base
words, packs a 24-bit id from `u8[cmd+1]` and `u16[cmd+2]`, calls `FUN_80077adc`, and then:

```
800712c8  2602000c   addiu v0,s0,12        # ctx+0x1c = cmd + 12
800712cc  ae22001c   sw    v0,28(s1)
800712d0  ...        lw ra / lw s1 / lw s0
800712dc  24020001   addiu v0,zero,1        # return 1
```

**So the advance is the constant 12, on every arm, and the index selects a sub-opcode.** The targets are
not callbacks: they are five variants of one command, all of them code inside this image, all reached only
from this handler, all sharing one exit. M211's "a callback pointer, not a command address" is retracted.

## 3. What *is* runtime-initialised, and why that mattered

The base objects the arms select are zero in the image (`0x800e13e8`, `0x800e13ec`, `0x800e18f8`). That is a
real and separate fact: the command positions something at a base the engine fills at run time. The earlier
reading was looking for a runtime-filled thing and found one — it was just the wrong one, and the wrong
address made it look true.

## 4. Consequences, all re-derived

| what | before | after |
|---|---|---|
| registry advance classes | 131 constant + 15 variable | **132 constant + 14 variable** |
| opcodes with no constant advance | 10 | **9** |
| opcodes left `unresolved` | 1 (`0x36`) | **0** |
| rooms decoding cleanly | 107 of 256 | **109** |
| rooms refused | 59 | **57** |
| `unresolved_advance` refusals | 2 (rooms 6, 21) | **0** |
| distinct instruction lengths | 17 | **18** — `12` joins the set |

Rooms **6 and 21** decode now. The 12-byte advance is also the first new instruction length in ten
milestones, which `counts.py` derives rather than trusting a sentence.

Three things needed fixing downstream rather than just regenerating: `scd_vm`'s `DYNAMIC_MODEL` and the
registry's constant table had to agree (a new check accepts `LENGTH_OVERRIDE`'s value *only* when the
profile's status is `ok`, so two records of one fact must still match); the synthetic trace fixture asserted
that `0x36` raises `unresolved` and now asserts it advances 12 **and** that a record shorter than 12 bytes
truncates; and three audit anchors were sitting on manifest text that the regeneration moved — the M216 lint
found all three in 0.04 s.

The audit's expected case count needed no chasing at all, because M224 made it derived. That fix paid for
itself one milestone later, which is the argument for it.

## 5. What this does not claim

* **What the command does.** The id is bank/program/note-shaped and `FUN_80077adc` splits it into three
  indices against per-bank tables before calling into the sound engine at `0x800787dc`. That reads as a
  positioned sound trigger, and it is labelled **inferred** in the artefact: the structure is measured, the
  purpose is not.
* **The handler's extent.** The store at `0x800712cc` lies *outside* the Ghidra body
  `0x80071180..0x800711cb`, which is the mechanical reason the advance scan never saw it. That is a corpus
  extent correction — the M212 class — and it is queued, not claimed. The advance was measured from the arms
  themselves instead, which is why it did not need the correction first.
* **The tail's three deltas** are named by their offsets (`cmd+6/+8/+10`) and not by their meaning.

## 6. Gates

`callback table (cartridge)`: **9 cases**, new suite. Three mutations aimed at the artefact's own outcomes —
the sign extension (so the table moves 0x10000 and the address case fails), the `5` in `sltiu` (so the entry
count case fails), and the tail's advance (so the 12 case fails). All three proven in a throw-away copy
before the commit.

**And a defect of my own, found by the damage it did.** The log row for this milestone was inserted through an
anchor that was a *prefix* of the M225 row's line, so the replacement put a newline in the middle of that row
and split it in half — leaving an M225 row with no detail and an M226 row carrying M225's evidence. Every
other gate read the result as "M225 has no summary"; `counts` and `milestone_index` both went on passing.
`check_markers.py` now asserts the **shape** of the two tables — a milestone row has 3 or 4 cells (the early
rows have no title column), a retraction row has 3, no cell is empty, and cells are split on *unescaped* pipes
only because three rows legitimately contain `\|` — with three self-test cases including the exact
split-in-half shape. It immediately found **two pre-existing rows** (M104, M192) with an unescaped `|` in a
code span, which have been escaped. The lesson is M216's, one level up: an anchor is checked for uniqueness and
for being a no-op, and neither of those is the same as *ending where a line ends*.

**The audit found a vacuous entry and the verifier refused the run.** `verify.py` came back
`INCONCLUSIVE` — `117/118, 1 vacuous` — for `scd_vm: an opcode with no advance is skipped as one byte`, whose
subject this milestone deleted: with no unresolved opcode left, that mutation had nothing to act on. So the
`admission` rule did exactly what it exists for, and the entry is re-aimed at the property that still holds
and is still load-bearing — *a byte the table does not know must be refused as unknown*. Two candidate
mutations were rejected first because they **crash** (`rec` is `None` one line later; `advance_class` indexes
the same table), and a mutation that raises the wrong exception proves only that the code is fragile, not that
the refusal is load-bearing. The accepted one conflates the refusal's *kind* (unknown → truncated) and fails
cleanly on the fixture case that names `0x8d`.

`all 59 runnable suite(s) pass (843 cases)`; `gate audit 118/118`, 0 vacuous.
