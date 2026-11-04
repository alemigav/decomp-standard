# M283 — re-measured under `-g`: both partials are untouched, and case 4 is still one register

`-g` fixed `0x800701d8` by stopping a *gas* transformation, so the natural next question was whether the two partial
functions were also short because of gas. They are not. Both were re-measured under the corrected pipeline and both
are **byte-identical to their pre-`-g` values**, with the same words in the same places. Case 4 of `0x8007e590` is
therefore unparked, re-swept in the now-exact context, and still **226 of 229**.

## 1. The two re-measurements

| function | without `-g` | with `-g` | the words that differ |
|---|---|---|---|
| `0x80024558` | 136 / 139 | **136 / 139** | `0x8002466c` `lui $1,0x800b` vs `lui $2,0x800b`; `0x80024670` `lwc1 $f4,-0x6950($1)` vs `($2)`; `0x800246a4` `ldc1 $f0,-0x6968` vs `-0x6948` |
| `0x8007e590` | 226 / 229 | **226 / 229** | `0x8007e8ac` `li v0,5` vs `li a0,5`; `0x8007e8b0` `li v0,4` vs `li a0,4`; `0x8007e8b4` `sb v0,5(s0)` vs `sb a0,5(s0)` |

That is the useful part of the answer: **`-g` closed the toolchain question without moving either residue.** Both are
`cc1`'s register allocation, which the assembler cannot touch — and the mechanism is visible in the shape of each
residue. `0x80024558`'s first two words are one decision, not two: the base register of a constant-address `lwc1`, where
the image uses `$at` (gas's macro temporary) and ours uses `$v0`; the third is pool *placement*, the per-use entry
M268/M269 measured at 21 words of layout to reproduce. `0x8007e590`'s three are one decision as well: which register
holds the value of a select.

## 2. Case 4, unparked: twelve more shapes, all 226

Every one of these was built from the **current** source, in which the other 226 words are exact, so any variant that
moved the register would show up as 229. None did.

| variant | offset |
|---|---|
| current: `if (!(A && B)) sel; else f5 = 0;` with a ternary | **226** |
| `u8 m` temporary, braced, then `s->f5 = m` | 226 |
| nested `else if` (two copies of the select in the source) | 226 |
| condition read through a cast, `*(u8 *)((u8 *)s + 5) == 22` | 226 |
| `(u8)(...)` cast on the select | 226 |
| `(u32)s->f5 == 22` | 226 |
| `int m` temporary via `s->f5 = (m = ...)` | 226 |
| `u8 *dev` hoisted to function scope and assigned in case 4 | 216 |
| a `u8 f` local holding `s->f5` across the test | 187 |
| the device base written inline instead of through a local | 178 |
| `(s->f5 != 22) ? 5 : 4` | 225 (flips `bne` to `beq`) |
| `4 + (s->f5 != 22)` | 225 (leaves the value-select class) |
| `if`/`else` assigning `4` and `5` | 194 (two stores — confirms the value select) |
| natural polarity, `if (A && B) f5 = 0; else sel` | 188 |
| `switch (s->f5) { case 22: … }` | 194 |

## 3. What that means, stated plainly

The image reuses **`v0`** — the register that held the constant `22` — for the select's result and stores from it. Our
`cc1` puts the result in **`a0`**, which is dead on both sides. With every instruction around it identical, the live
ranges are identical, so this is `local_alloc`'s tie-break alone: the same class as `0x80024558`'s three words, and the
same conclusion M270 reached for that function after five refuted hypotheses — **a tie-break that survives twenty-odd
source shapes is not steerable from the source**.

The honest count across this arc is now: **seven exact of nine recovered** (46, 53, 84, 98, 141, 167, 206 words), plus
two at `136 of 139` and `226 of 229`, both residues being register allocation with the mechanism named. Nothing in the
corpus changed this milestone; `0x8007e590` stays a partial pin at `>= 226` with `case3 == 113`, and `0x80024558`
stays `>= 136`.
