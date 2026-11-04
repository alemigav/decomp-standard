# M255 — arms 2–4: the order was already right, and the region comparison was not

The instruction was to fix arms 2–4 by dividing before incrementing and loading before storing. **Both are
already what my compiled arms do.** What was wrong was the *comparison*: it sliced both sides at the image's
region addresses, so the moment any region differs in size it compares misaligned code.

## 1. The per-region numbers were an artefact

Slicing at `0x8004fda0` (arm 2) read my output at that offset, where — because arm 1 is 8 bytes longer — a
*different part* of the same arm sits. Arms 2–4 therefore read as 0/21, 0/23 and 0/21 words.

Aligned by content (`SequenceMatcher` over the instruction sequences), the same function is:

| | |
|---|---|
| image | **98** instructions |
| compiled | **104** instructions (+6) |
| identical | **81** |
| difference hunks | **14** |
| first difference | `0x8004fd20` — the head's `beq` offset |

Confirmed directly: my arms 2 and 3 begin

```
lbu v0,a3,1     ; s[1]
lbu v1,a3,2     ; s[2]
divu v0,v1      ; divide FIRST
... mflo, sll, sh v0,a1,0      ; *p = (s[1]/s[2]) << 4
lbu v0,a3,1     ; RELOAD s[1] after the store
addiu v0,v0,1   ; then increment
sb v0,a3,1
```

which is instruction-for-instruction the image's arm 2 (`0x8004fda0…0x8004fdd8`) and arm 3 (`0x8004fdf4…`). The
reload across the store happens on its own — no `volatile` needed, and marking the pointer `volatile` made the
whole function *worse* (22% identical against 27%), as did `volatile short *p` (11%).

## 2. What the 14 hunks actually are

Not the sequencing. Three kinds, all small:

- **load order**: the image loads `s[3], s[2], s[1]` where mine loads `s[1], s[2], s[3]` (arm 1's second half);
- **`mult` operand order**: `mult a0,v1` (s[3]×s[2]) against `mult v1,v0` (a different pairing), which follows
  from the load order;
- **one nop where the image fills the slot**: `beq v1,v0,+66; addiu v0,v1,1` in the image against
  `beq a0,v0,+71; nop; lbu v0,1(a3); addiu v0,v0,1` in mine — the same reason the head's slot needed the arms.

So the remaining work is *expression* work: which order the loads are written in, and which operand goes first in
each `mult`. That is exactly what a permuter searches, and it is not something to guess at by hand — 14 hunks with
81 instructions already identical is a search problem, not a reading problem.

## 3. The honest state

- The head and arm 0 are byte-exact; 81 of 98 instructions across the whole function are identical; 6 instructions
  are extra.
- The delay-slot claim from M254 survives: with the arms in place the head differs **only** in the `beq` offset,
  which is the arms' total size.
- No `-O`/`-O2` difference and no `volatile` helps; `-fno-strict-aliasing` is not accepted by gcc 2.8.1's cc1.

The probe now compares by content, so every future edit to the C is scored on 98 instructions instead of being
read off a misaligned slice.
