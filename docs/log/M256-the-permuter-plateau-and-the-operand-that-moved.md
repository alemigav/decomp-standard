# M256 — the permuter plateaued at 1 900; the fix it could not find was one operand order

M255 closed with the honest diagnosis: the residue in p6's body is *expression* work — which order the loads are
written in and which operand goes first in each `mult` — and that is a search problem, so run
[decomp-permuter](https://github.com/simonlindholm/decomp-permuter) on it. This is what came back, and what a
minute of reading found that 110 242 iterations did not.

## 1. Getting the permuter to run at all — three fixes, none of them the search

The checkout needed a venv (`toml`, `pycparser`); the mips `ido` driver shells out to `mips-linux-gnu-objdump`, so
binutils had to be on `PATH`. Two of the fixes are worth recording because they are silent:

- **The driver calls the script as `compile.sh <in.c> -o <out.o>`** — four arguments, output *named after a flag*.
  The first version wrote the object to a file called `-o` and the permuter reported `CalledProcessError` on
  `objdump` of an empty file. Handled `-o` explicitly.
- **`objcopy` has no `-o`**; the object can be used directly, so the pipeline is `cc1 -O2 -G 0 -mips2` →
  `as 2.7` and nothing else.

With those, the base scored **2 000** against the 392-byte target (the whole 8-word-head-plus-five-arms function,
assembled from the image with real `%hi/%lo` relocations so the unlinked comparison is legitimate).

## 2. What 110 242 iterations produced: one candidate, worth 100 points, and it was noise

```
iteration 750, score = 1920   found a better score! (1920 vs 2000)
iteration 1137, score = 1900  tied best score!  (1900 vs 2000)
```

Four workers, ~110 k iterations, two score events. The best candidate's whole diff is:

```diff
+inline int inline_fn(int arg0) { return arg0; }
-      *p = (s->b1 / s->b2) << 4;
+      *p = inline_fn(s->b1 / s->b2) << 4;
```

An identity wrapper in one arm, which changed register allocation incidentally and nothing else. That is the
signature of a search whose neighbourhood does not contain the answer: the permuter mutates **expressions and
statements**, and the thing that was wrong is the *order of operands inside one expression* — reachable in
principle, but with four workers it spent its budget on the 690 iterations in 1 000 that did not even compile
(the target language here is gcc 2.8.1's C, and the permuter's mutations are tuned for IDO-era sources).

**Verdict: not converged, and reported as that.** A permuter that plateaus with `2 000 → 1 900` has told you the
answer is not a local rewrite of your C.

## 3. The operand order was in the source, and the disassembly says which

The image's `mult` takes its operands **`b3` first**:

```
lbu a0,3(a3) ; lbu v1,2(a3) ; mult a0,v1        arm 1 — b3 × b2
lbu v1,3(a3) ; lbu a0,2(a3) ; mult v1,a0        arm 3 — b3 × b2, other registers
```

and mine took `b2` first, because I wrote `s->b2 * s->b3`. Swapping the operands in the three comparisons is the
entire edit:

```c
if (s->b1 == s->b3 * s->b2 - 1) break;                 /* arm 1 */
if ((unsigned char)s->b1 != s->b3 * s->b2) break;      /* arms 2, 3 */
```

| | identical of 98 | hunks | extra | 
|---|---|---|---|
| `s->b2 * s->b3` (M255) | 81 | 14 | 6 |
| `s->b3 * s->b2` (M256) | **82** | **12** | 6 |

Two words and two hunks, and it also settles *which* operand order the original wrote: gcc 2.8.1 evaluates the
right operand of `*` first at `-O2`, so `s->b3 * s->b2` in the source is what puts `b3` in the first `mult` slot.
The probe's pin moves with the measurement (`same >= 82`, `extra <= 6`) rather than staying where it was.

## 4. The rest, read correctly this time

M255's numbers came from a script that disassembled the image slice as a **raw binary** and my object as **ELF**.
Both halves were wrong in a way that flattered the comparison: `objdump -b binary -m mips:4300` decodes a slice
with no mapping (branch targets print as garbage mnemonics — `beq` came out `bgtzl`), and the object's columns
carry relocations that the image does not. The correct instrument is cheap: emit the image's words as `.word`
directives, assemble them into a real ELF, and disassemble both sides the same way.

Re-read that way, p6 is **96 of 98 instructions mnemonic-identical with 2 extra instructions**, and every
remaining hunk falls in one of three classes:

1. **`s->b1`'s load is hoisted before the `mult`** in the image (arms 1–3): the image issues `lbu b3, lbu b2,
   lbu b1, mult`, mine issues `lbu b3, lbu b2, mult, lbu b1`. A scheduler tie-break — the load is independent of
   the product either way, and gcc issued it in the multiply's shadow.
2. **one hazard `nop` sits in a different position** relative to the same `mflo`/`addiu` pair.
3. **branch offsets**, which are the sizes of (1) and (2), not separate facts.

So what M255 called "14 hunks" is really *one* expression-level fix plus *one* scheduling habit, and the word-level
count overstates it because every shifted instruction re-aligns the comparison.

## 5. State after this milestone

- The corpus is **15 cases, all passing**; p6 whole-function pin raised to the measured values.
- The permuter is installed, reproducible (`build/permuter/p6/`, `compile.sh` honouring `-o`), and its failure
  here is a *recorded* result: an expression mutator cannot fix an operand order the source never contained.
- Unexplained: why gcc hoists that `lbu` in the image and not in mine. It is one scheduling decision in three
  arms and it is the next thing to try on p6 — but it is not a semantic difference, and the function is 96/98
  mnemonic-identical.
- In parallel, **p7** (`0x80057e1c`, 336 B, bound 7 on the byte at `ctx+6`, all seven arms inside one contiguous
  range rather than in separate corpus functions) is being recovered; that is the first function whose arms are
  *not* separate ranges, and it is the next report.
