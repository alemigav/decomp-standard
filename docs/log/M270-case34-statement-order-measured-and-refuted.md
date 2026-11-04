# M270 — case 3/4 in the image's statement order: measured, and the current expression is the best of the family

The hypothesis from M269 was that the pool's order (`[2^32][4.0f]` in the image, ours the reverse) reveals the
original's *statement order* — the conversion written before the multiply. Four source shapes test that, and the
answer is that the current single-expression form is the best of them by a wide margin.

## 1. The variants

All four are semantically identical; only the shape changes. Compiled and linked at the image's addresses as usual:

| shape | p8 offset | hunks | note |
|---|---|---|---|
| **single expression (current)** | **136 / 139** | 3 | `... = ((s32)((float)A * 4.0f) & 0xFFF) << 12 \| ((s32)((float)B * 4.0f) & 0xFFF);` |
| two locals, declarations first (C89) | 72 / 139 | 19 | conversions before the combine, as the image reads |
| two stores (`w1 = …; w1 \|= …`) | 74 / 139 | 9 | and the **arm addresses moved** (`0x80024774` against `0x80024770`): the code grew 4 bytes |
| operands swapped inside the `\|` | 78 / 139 | 14 | same tree, other evaluation order |
| *(M269)* hoist `4.0f` into a local | 115 / 139 | 6 | the load left the branch |

And one that failed to compile at all: declarations *after* statements, because **cc1 is a C89 compiler** —
`u32 a = …` below `Gfx *_g = p;` is `parse error before (null)`, the same mojibake error M257 documented as
pointing at an earlier undefined thing.

## 2. Why reshaping costs so much

p8 is a **139-word function** that keeps its argument in `s1`, the save area in `s0`, and runs a four-register
packet cursor through `t6…t9`. Changing where a value is computed changes which pseudo gets `t6` against `t7`, and
that propagates through every packet address in the function:

```
img :  01c03021 25ce0008 3c08e300        # move a2,t6  addiu t6,t6,8
mine:  01e03021 25ef0008 3c08e300        # move a2,t7  addiu t7,t7,8
```

One register decision, 14 words apart in the diff. That is why the "two locals" variant loses 64 words while being
semantically identical, and it is the same effect M262 measured from the other direction: in a function this size,
only a rewrite that leaves allocation untouched can improve the score, and every restructure I can express does
not.

## 3. What that settles

The pool's order is a *consequence* of the source, and the source shapes that would produce the image's order cost
far more than they gain. So p8's three words are not reachable from the C:

| word | ours | image | why it stays |
|---|---|---|---|
| `0x8002466c` | `lui $v0` | `lui $at` | `$at` is the assembler's scratch; the image's build let the assembler materialise the pool base. Not a flag (M266: `-mno-split-addresses` costs 95 words on p6) and not reachable from the source |
| `0x800246a4` | pool entry `0x69c8` | `0x69d8` | the original keeps **one pool entry per use** (M268); reproducing it needs no-dedup, which costs 21 words of layout (M269) |
| `0x80024784` | `nop` | — | `.text` aligned to 16 bytes past the image's extent, same as p6 |

**p8 is functionally identical and byte-different in 3 of 139 words.** Both remaining causes are compiler-side, both
were measured, and each is more expensive than the three words it would win. That is the honest stopping point for
this function unless a different lever appears — not a claim that it is impossible.

## 4. State

- **p6 byte-exact (98/98), p7 byte-exact (84/84), p8 136/139**, corpus **22 cases, all passing**, no tool change.
- Five hypotheses about p8's residue have now been tested and refuted (flag, pool placement, dedup, hoist, source
  order), each recorded with its cost. The pattern across them is consistent: **the residue is allocation, and
  allocation in a 139-word function is not steerable from the source.**
- The productive direction is therefore the one M264 opened and never finished: another function of this size whose
  C *is* fully recoverable, to test whether the `-mcpu=r4300` profile reproduces big functions as reliably as it did
  p7 — that is a question about the method's coverage, not about p8's last three words.
