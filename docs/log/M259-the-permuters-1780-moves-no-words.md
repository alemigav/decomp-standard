# M259 — the permuter's 1 780 is not a matching improvement: its score and the byte diff disagree

M256 ran decomp-permuter on p6's 392 bytes against a base of 2 000 and it plateaued at 1 900 with an identity
`inline_fn` wrapper as its best find. The instruction was to run it again — and by now the base is better: M256
swapped the `mult` operands (`s->b3 * s->b2`), so the base scores **1 980** and the search has something to work
with. It did much better this time, and the result is more informative than a failure.

## 1. The run

110 242 iterations the first time; **132 202** this time, 4 workers, **20 improvements**, base **1 980 → best
1 780** and 87 candidate directories written. That is a 10% gain, five times the first run's.

Two setup fixes were needed before it would run at all, both mine:

- `mktemp /tmp/permXXXXXX.s` **collides across the four workers** on macOS (`mkstemp failed… File exists`), so the
  base "could not be compiled" and the run died before iteration 1. `mktemp /tmp/perm.XXXXXX.s` with a `trap` to
  remove it is the fix.
- The `compile.sh` calling convention from M256 (`<in.c> -o <out.o>`, output named after a flag) still applies.

## 2. What 1 780 buys: nothing in the matching metric

The best two candidates were compiled through the real pipeline and scored the same way the probe scores p6 —
linked `.text` at `0x8004fd1c`, `.rodata` at the table, word compared against the image:

| source | offset-identical | content-aligned | hunks |
|---|---|---|---|
| base (M256's swap) | 28 / 98 | 82 / 98 | 12 |
| `output-1780-1` (best) | 28 / 98 | 82 / 98 | 12 |
| `output-1780-2` (best) | 28 / 98 | 82 / 98 | 12 |

**Identical in every column.** And the offset number being low next to the content number is not a contradiction:
p6's first differing word is `0x8004fd20` — the head's `beq` offset — so six extra instructions shift everything
after it and only 28 words land at the same index, while 82 are the same instruction in a slightly different place
(that difference is exactly what M255 and M257 had to learn to report separately).

So the permuter's own penalty improved by 200 points while **the instruction content did not change at all**. Its
score counts register numbers, operand order and its own structural weights; the matching question counts words.
The two are not the same function of the code, and a 10% score gain that moves zero words is the clearest
demonstration of it this project has.

## 3. What the winning edits are

Both `output-1780-1` and `output-1780-2` add an identity helper and route an expression through it:

```c
inline unsigned char inline_fn(S *arg0) { return arg0->b1; }
...
-      *p = (s->b1 / s->b2) << 4;
+      *p = (inline_fn(s) / s->b2) << 4;
```

That changes *register allocation* (it gives the allocator a separate live range to colour) and nothing about the
computation. Nine of the 87 candidates contain no `inline_fn` at all and are plain randomisations of the same
score class, so the search's gains are not even uniformly this artifact — they are a mixture of allocation
accidents and rewrites the metric cannot see.

**Not adopted.** Writing `inline_fn` into the reconstruction would be recording a permuter artifact as source.

## 4. Why this is not the same plateau as M256, and what it means for p6

M256's plateau said "the neighbourhood does not contain the answer". This run says something sharper: **the
neighbourhood contains scores, not answers.** decomp-permuter optimises a weighted penalty over 98 instructions;
p6's residue is one scheduling tie-break (the `lbu` of `s->b1` issued before the `mult` in the image and after it
in mine), and M258 showed that class of difference is decided by **aliasing facts about how accesses are typed**,
not by the shape of the expression. In p6 both sides already reload `s->b1` across the `*p` store — the dependence
is kept on both — so there is no mixed struct/non-struct pair left to make uniform, which is the lever M258 used
to go from 60 to 74 on p7. What remains is a tie-break inside a legal reordering, and a mutator of expressions has
no representation of it.

**Verdict: two runs, 242 000 iterations, and the honest conclusion is that p6's last 16 words are not an
expression-search problem.** Either the reconstruction's types are still wrong somewhere (M258's lesson, worth one
more pass on `short *p` against `S *s`), or the tie-break depends on the surrounding schedule, which is not yet
right either.

## 5. Moving on

The instruction was "then move to the next function", and the next one is already in flight: **p8 at
`0x80024558`** — 80 bytes, bound **6**, index a **global byte**, table `0x800b69b0` — the third of the four heads
from M253, recovered with M257's pipeline and M258's aliasing rule. See the next note.

State: no tool change in this milestone; the corpus remains **18 cases, all passing**, p6 pinned at 82/98
content-aligned, p7 at 74/84 offset with case 0 byte-exact.
