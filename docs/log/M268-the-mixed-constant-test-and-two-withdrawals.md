# M268 — the mixed-constant test: duplication is uniform, and "the image dedups floats" was wrong

M267 proposed a discriminating test: find a function that uses one double constant twice and one float constant
twice, and see whether the double is duplicated while the float is shared. The test comes back **negative**, and
finding out why withdraws two claims M267 made.

## 1. The scan

387 float pool loads resolved in the image (`lui R,HI` then `lwc1`/`ldc1` on base `R`, restricted to the
`.rdata` pool window `0x800b0000..0x800c0000` — the unrestricted version picked up `lwc1` from stale registers
pointing into RAM and produced two false "mixed" functions).

**No function contains both behaviours.** And the aggregate is unambiguous:

| constant size | distinct values | appear at 2+ pool addresses | **shared by 2+ loads from one address** |
|---|---|---|---|
| 4 bytes (float) | 86 | **38** | **0** |
| 8 bytes (double) | 20 | **10** | **0** |

The duplicated floats are not marginal values: `4f000000` (2^31 f) at **52** addresses, `3f800000` (1.0 f) at
**41**, `45800000` (4096.0 f) at **13**, `40800000` (4.0 f) at **12**; and on the double side `41f0000000000000`
(2^32) at **60**, `3ff0000000000000` (1.0) at 8. Functions duplicate *every* constant they use — `FUN_80070708`
has three different doubles each at 2 addresses, `FUN_8009ef50` four doubles at 3 addresses each.

## 2. Two M267 claims are withdrawn

- **"The image does dedup `4.0f` — both uses in p8 share one slot."** Wrong. p8's image pool is
  `[2^32][4.0f][2^32]`: the float appears **once** because p8 **loads it once** and keeps it in `$f4` for both
  multiplies — not because the pool was deduplicated. I inferred a pool property from a register-allocation
  outcome.
- **"The original's behaviour is mode-asymmetric."** Not supported. Duplication is uniform across both sizes
  (38 of 86 floats, 10 of 20 doubles), so there is one rule, not two.

The corrected statement is simpler and stronger: **the original never shares a pool entry between two loads — the
pool is per use, for floats and doubles alike.** And the test as designed could never have discriminated, because
"shared by two loads" does not occur anywhere in 387 resolved sites: the only way a constant is reused is by
keeping it in a register.

## 3. What that changes about the earlier experiment

M267's blanket no-dedup rebuild measured **p8 90/139** and was read as "removing dedup is wrong". Given the
corrected picture, no-dedup is the *right* model, so that 46-word loss was not a semantic error — it must be a
**layout** consequence (a bigger pool changes which entries sit at which offsets, and hence every `%lo` immediate),
possibly compounded by our expression tree loading `4.0f` twice where the original loads it once. That is now a
question with a shape: reduce the source's constant loads to the image's count *and* turn dedup off, then compare.
It was not re-run in this milestone — it needs the source and the compiler changed together, which is exactly the
kind of coupled change that produced M264's and M265's false starts when attempted one at a time.

## 4. State

- **p6 byte-exact (98/98), p7 byte-exact (84/84), p8 136/139**, corpus **22 cases, all passing**, no tool change.
- Two claims withdrawn and one rule corrected — the third self-correction in this arc (M261 corrected a pool
  reading, M264 a pool word, this one a dedup inference). Each was caught by a measurement that cost one scan, and
  each is recorded rather than quietly replaced.
- Next, precisely: make p8's source load `4.0f` **once** to match the image's single float slot (i.e. hoist the
  constant into a local), and *with* dedup off, re-measure. If the pool layout then matches, the residual is only
  the `$at` tie-break and the padding.
