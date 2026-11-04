# M264 — re-read under the r4300 cost model: p6 is byte-exact too, and p8's last difference is a placement

M263 found `-mcpu=r4300` and made p7 exact, leaving p6 at 8 hunks and p8 at 3. Re-reading both with the corrected
cost model **and with the image disassembled at its real addresses** — the first reading had the image at vma 0, so
every branch target printed as a different string and inflated the hunk count — gives a much smaller residue than
the numbers suggested.

## 1. Most of the "hunks" were my own instrument

Both diffs were re-done with the image's words assembled into a real ELF at the image's vma. Under that reading:

- **p6**: of 12 hunks, **10 were branch/jump target text** (`beqz v0,0x184` against `beqz v0,8004fea0`). One real
  difference remained, in one instruction.
- **p8**: of 6 hunks, **4 were the same artifact**. Two remained, and both are one thing.

The tool never had this problem — it compares raw words, not disassembly text — but the *reading* did, and a hunk
count quoted from a text diff with mismatched vmas overstates the work. That is worth writing down: the summary
line the probe prints is the honest one.

## 2. p6 was one statement out of order, and is now byte-exact

The single real difference sat in arm 4:

```
image:  lbu a0,1(a3) ; bnez a0 ; li v1,131 ; lbu v0,2(a3) ; sb v1,0(a3) ; addu v0,a0,v0
mine:   lbu v0,1(a3) ; bnez v0 ; li v1,131 ; lbu v0,1(a3) ; lbu a0,2(a3) ; sb v1,0(a3) ; addu v0,v0,a0
```

Mine **reloads** `s->b1` where the image keeps the already-loaded value in `a0`. The cause is the order of the two
statements in the `if` body, and swapping them is the whole fix:

```diff
-      if (s->b1 == 0) { s->b0 = 131; s->b1 = s->b1 + s->b2; }
+      if (s->b1 == 0) { s->b1 = s->b1 + s->b2; s->b0 = 131; }
```

| version | offset | content | hunks |
|---|---|---|---|
| `s->b0 = 131` first | 86 / 98 | 90 / 98 | 8 |
| sum first | **98 / 98** | **98 / 98** | 1 (padding) |
| sum via a temp | 98 / 98 | 98 / 98 | 1 (padding) |

With the store to `s->b0` *last*, nothing has to be reloaded across it: the sum is computed while the cached byte
is still live. So the original source ordered the sum first — a **source fact recovered from a reload**, exactly
the kind of evidence that makes a reconstruction worth writing down.

**p6 `0x8004fd1c` is now byte-exact over all 98 of the image's words.** The one remaining "hunk" is 2 words of
trailing `.text` alignment padding *past* the image's extent (`first at 0x8004fea4`, which is the image's end), so
the extra-words count is a link artifact and not codegen. The probe now states the claim directly:
`same_offset == image_instrs`.

## 3. p8's last difference is the constant-pool *placement*, and forcing it alone is worse

Both of p8's real differences are the same thing: our compiler emits `li.s` for the FP constant

```
image:  lui at,0x800b ; lwc1 $f4,27088(at)     # a pool load
mine:   lui at,0x4080 ; mtc1 at,$f4            # li.s, inlined
```

and, downstream, our `ldc1 $f0,27088(at)` is one pool slot away from the image's `27096`. That is M261's second
symptom — `mips_const_double_ok` — and there is now hard evidence about what the original build did:

**A scan of the entire 1.9 MB image finds zero `mtc1 $at`** — that is, **no `li.s`/`li.d` expansion anywhere**.
`li.s` is the only way gcc emits a float immediate on MIPS, so the original compiler never took the immediate path
for a float constant: every one of them is loaded from memory. p8's two differences are therefore not a
reconstruction error at all — they are the *one* systematic codegen difference left between our build and the
cartridge's.

That is testable, so it was tested: patching `mips_const_double_ok` to return `FALSE` for float constants makes
our build pool everything. **It makes p8 worse — 134/139 instead of 136/139, and 5 hunks instead of 3** — for a
reason M260 already identified: **our constant pool is emitted *before* the jump table**
(`CONSTANT_POOL_BEFORE_FUNCTION` defaults to 1 and mips does not override it), so once constants stop being
inlined the pool grows *in front of* the table and every table reference shifts by two instructions. The image has
`[table][pool]`; we would have `[pool][table]`.

So matching p8 needs **two coupled changes, or neither**: pool every float constant *and* emit the pool after the
function body. Each alone moves the function away from the image. The patch was reverted and the negative result is
recorded rather than pinned: the gate stays at `>= 136`, not lowered to fit.

## 4. State

- **p6 byte-exact (98/98, padding aside). p7 byte-exact (84/84, zero hunks). p8 136/139 with 3 words differing,
  all of them the constant-pool placement.**
- **Corpus 22 cases, all passing**, and two of the three recovered functions are now reproduced word for word from
  reconstructed C. The one case that had to change was the old "the head's delay slot still matches" assertion —
  it was true when the head's `beq` offset was the first difference; the head is now identical, so it was replaced
  by the stronger `same_offset == 98` claim rather than deleted.
- Next, precisely: `CONSTANT_POOL_BEFORE_FUNCTION 0` *plus* `mips_const_double_ok` returning `FALSE`, applied
  together, and p8 re-measured — with the pool contents now checkable too, since M261 made them correct.
