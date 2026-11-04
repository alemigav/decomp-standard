# M266 — `-msplit-addresses` is refuted, and case 3/4 is an unsigned conversion

Two asks: try `-msplit-addresses` for the `$at`/`$v0` difference in p8, then revisit case 3/4's double
arithmetic. The first is a clean refutation; the second decodes the arithmetic and narrows p8's last three words to
one open question, which is not the one I expected.

## 1. `-msplit-addresses` is already on, and turning it off is catastrophic

`mips.c:3703` sets `mips_split_addresses` from `TARGET_GAS && TARGET_SPLIT_ADDRESSES && optimize && ! flag_pic &&
Pmode == SImode`, and the emitted forms say it is **on** by default here:

| flag | a pool float load | a global load |
|---|---|---|
| default / `-msplit-addresses` | `lui $2,%hi($LC0)` + `l.s $f0,%lo($LC0)($2)` | `lui $2,%hi(g)` + `lw $2,%lo(g)($2)` |
| `-mno-split-addresses` | `l.s $f0,$LC0` (assembler expands with `$at`) | `lw $2,g` (same) |
| `-mgas` / `-m gp32` | identical to the default | identical |
| `-mno-gas` | **rejected** by `cc1` | — |

`-mno-split-addresses` does produce the image's `$at` form — by handing the bare symbol to the assembler — but it
changes *every* address materialisation, and the measurement is unambiguous:

| flag | p6 | p7 | p8 |
|---|---|---|---|
| default | **98 / 98** | **84 / 84** | 136 / 139 |
| `-mno-split-addresses` | 3 / 98 | 7 / 84 | 5 / 139 |

p3's own image (`lui v0,0x8013; lw v0,0x14cc(v0)`) proves the image's globals went through gcc-allocated
registers, so the image's build had split addresses **on** too. **Conclusion: the `$at` is not a flag.** It is one
allocated register inside the same split form — the same `lui` immediate, the same `lwc1`/`lwc1` offset, only the
register differs — so it is an allocation tie-break, and the reason the tie-break differs is the thing in §2.

## 2. Case 3/4 decoded: it is an *unsigned* conversion, and we already do that

The FP tower in the image, with the pool resolved:

```
lw    a1,14296(v0)          # a1 = DAT_801137d8
mtc1  a1,$f2 ; cvt.d.w      # $f2 = (double)(s32)a1
bgez  a1, +4 words          #   if (a1 < 0) {
  ldc1  $f0, 0x800b69c8     #     $f0 = 4294967296.0     <- 41f00000 00000000
  add.d $f2,$f2,$f0         #     $f2 += 2^32
                            #   }
lwc1  $f4, 0x800b69d0       # $f4 = 4.0f                  <- 40800000
cvt.s.d $f0,$f2
mul.s $f0,$f0,$f4
```

`(double)(s32)x` plus a *conditional* `+ 2^32` is gcc's `floatunsidf` expansion: it is what
`(float)(unsigned int)x` compiles to. So the source converts an **unsigned** value, and the pool's `41f00000
00000000` is not 30.0 f misread — it is the double `4294967296.0`, which I had decoded wrongly in M264 by reading
the word as a float. Our source already types those globals `u32`, so this part of the reconstruction was right and
the instruction sequence matches; the 4.0 f that follows is `(s32)`-truncated later, as recorded.

## 3. What p8's last three words are, and the one that is still open

| where | image | ours | what it is |
|---|---|---|---|
| `0x8002466c` | `lui $at` + `lwc1 (at)` | `lui $v0` + `lwc1 (v0)` | allocation tie-break (§1) |
| `0x800246a4` | `ldc1 (at)+0x69d8` | `ldc1 (at)+0x69c8` | the pool holds the **same double twice** in the image |
| `0x80024784` | — | `00000000` | trailing `.text` padding |

The middle one is the interesting one. The image's `.rdata` for p8 is
`[table 6][41f00000 0][40800000 0][41f00000 0]` — **two copies of the same 2^32 double**, and the second conversion
in case 3/4 loads the second copy. Ours dedups to one entry and both conversions share it.

I checked whether that is a blanket difference and **it is not**: a two-call function compiled with our build pools
`2^32` and `4.0f` once each, and the image dedups its *single-precision* constant (both `4.0f` uses share one
entry). So the image's pool collapses one class of constant and duplicates another — `force_const_mem` dedups by a
hash of the descriptor plus `CONST_DOUBLE_MEM`, so a duplicated **double** means the two `CONST_DOUBLE`s reaching it
were *not equal by its test* even though their 8 bytes are. That is the same family of failure M261 fixed on our
side (a `REAL_VALUE_TYPE` comparison disagreeing with the stored target pattern) — and reproducing it would mean
deliberately re-breaking a comparison our build now gets right.

**Deliberately not done.** p8's code is byte-different in two words and **functionally identical**; matching those
bytes would require shipping a compiler defect, and unlike the `-mcpu` and pool-placement findings there is no
independent evidence of *what* the original defect was — only that its pool did not collapse an identical double.
The honest next step is to look for a third function that uses the same double twice and see whether the image
duplicates it there too: if yes, it is a systematic constant-comparison defect worth characterising and reproducing;
if no, p8's duplicate comes from something in this function's own expression tree.

## 4. State

- **p6 byte-exact (98/98), p7 byte-exact (84/84), p8 136/139** with all three differing words now explained and one
  of them carrying an explicit open question. Corpus **22 cases, all passing**; no tool change in this milestone.
- Refuted lever recorded so it is not retried: `-msplit-addresses` is already the default and its negation costs
  95 words on p6 and 77 on p7.
- Corrected from M264: the pool word `41f00000 00000000` is the **double 2^32**, not a float 30.0 — the float
  reading was mine and was wrong.
