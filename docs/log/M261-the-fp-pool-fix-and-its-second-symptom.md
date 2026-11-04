# M261 — the FP pool bug is a 64-bit-host bug, and fixing it changed *codegen*, not just data

M260 found two defects in one 8-word window. This fixes the one that gates everything FP: **`cc1` wrote every
constant-pool float as 0.** It turned out to be one arithmetic test, and fixing it moved p8's score — which was
not expected, because a constant's *value* should not change the instructions.

## 1. The bug: one comparison, false only on a 64-bit host

`varasm.c`'s `immed_real_const_1` stores a real into a CONST_DOUBLE, which holds exactly **two 32-bit words**,
and every reader — including the constant pool — decodes those words as the **target** bit pattern. The fast path
that does that is:

```c
  if (sizeof u == 2 * sizeof (HOST_WIDE_INT))
    return immed_double_const (u.i[0], u.i[1], mode);
```

On the 32-bit host this code was written for, `sizeof u` is 8 and `2 * sizeof (HOST_WIDE_INT)` is 8. **On a
64-bit host it is 8 against 16**, so the test is false, SFmode and DFmode fall through to the path that exists for
reals *wider* than two words, and there a raw `bcopy` drops the emulator's packed internal form into the rtx. Every
reader then decodes that as a target pattern. Measured before the fix:

```
float g(void) { return 30.0f; }        .word  0x00000000   # 0 (float)
float g3(void){ return 1.0f/3.0f; }    .word  0x00000000   # 7.95748421612e-315 (float)   <- a denormal, i.e. 8 raw bytes read as a pattern
static float arr[1] = {30.0f};         .word  0x41f00000   # 30  <- the *initialiser* path was always fine
```

That last line is what made the diagnosis cheap: the tree → `assemble_real` path converts correctly, so the
emulator and the parser were never the problem — only the rtx round-trip.

## 2. The fix is three coordinated edits

In `tools/toolchain/patch_gcc281_fp.py`, re-applied by `provision.sh` and idempotent per file:

1. **writer** — `immed_real_const_1` builds the target pattern with `REAL_VALUE_TO_TARGET_SINGLE`/`_DOUBLE` and
   returns through `immed_double_const`, for `SFmode`/`DFmode`, before the >2-word path can be reached;
2. **reader** — `REAL_VALUE_FROM_CONST_DOUBLE` becomes the exact inverse, via `ereal_from_float` /
   `ereal_from_double`, instead of the `bcopy` of the packed form;
3. **pool** — `output_constant_pool` reads through that accessor instead of doing its own `bcopy`.

Verified by measurement, not by reading: `3.0e38f` now emits `.word 0x7f61b1e6`, which is exactly
`struct.pack('>f', 3.0e38)`.

**The first version of the patch script duplicated the block.** Its anchors include a fallback it re-states, so a
second run matched its own output and applied again — caught by `grep -c M261` returning 2. The script is now
one-shot per file and verified by a no-op run; that is recorded here because the tree it patches is gitignored, so
nothing else would have caught it.

## 3. The surprise: the same words gate `li.s`

The fix improved p8 from **116 to 118 of 139 words** and cut its hunks from 14 to 12 — which should be impossible
for a *constant's value*. The reason is `mips.c:486`, `mips_const_double_ok`:

```c
  /* ??? li.s does not work right with SGI's Irix 6 assembler.  */
  if (mips_abi != ABI_32 && mips_abi != ABI_EABI)
    return FALSE;

  REAL_VALUE_FROM_CONST_DOUBLE (d, op);          /* <- the macro fixed above */
  ...
      if (REAL_VALUES_LESS (d, sfhigh) && REAL_VALUES_LESS (sflow, d))
	return TRUE;
```

It reads the constant with **the same macro**, to decide whether an SF constant may be an immediate. With the
packed form it decoded garbage, said no, and every constant went to the pool; with the fix it says yes and
`li.s` appears (`lui at,0x41f0` + `mtc1 at,$f0`). So the defect had **two** symptoms and only one of them was data:
the pool was zero **and** an optimisation was silently disabled. Both are now pinned as separate assertions in the
corpus, because a rebuilt compiler could fix one and not the other.

A knock-on: with no pool needed for that constant, our `.rodata` for p8 starts with the **jump table** and the table
now lands at `0x800b69b0`, the image's own address, instead of 16 bytes late. The p8 table case says
"0 words into .rodata" and that is now the honest number.

## 4. The `30.0f` retry: measured, and it changes nothing

M260's lead was that the image's word after the table is `41f00000` = **30.0f** while the recovered source
multiplies by `4.0f`. Both sources were compiled and scored through the real pipeline:

| source | offset-identical | content-aligned | hunks |
|---|---|---|---|
| `4.0f` | 118 / 139 | 128 / 139 | 12 |
| `30.0f` | 118 / 139 | 128 / 139 | 12 |

**Identical, and that is the expected result** — a float constant is loaded from a pool or an immediate either way,
so its *value* cannot move a single instruction. The lead was still worth having: the image's `41f00000` proves the
original source's constant, and the source should now say `30.0f` because the data matches even though the code
does not. What it does **not** do is explain the remaining 21 words.

And the image's own load is worth recording, because it does not match ours: the image computes
`lwc1 $f4,27088(at)` — a **pool** load — while our fixed compiler emits `li.s`. Every flag tried (`-mips2`,
`-mips3`, `-mabi=eabi`, `-mabi=o64`, `-msoft-float`, `-mno-abicalls`) keeps `li.s`, so whatever made the image's
build take the pool path is still unexplained. **That is the next question, and it is now a precise one**: either
the image's compiler was built where `mips_const_double_ok` answered differently, or the source's expression is not
what I think it is. The image's sequence also interleaves — `mtc1`/`cvt.d.w`, then the pool load, then
`cvt.s.d`, then `mul.s` — which is a scheduling fact I cannot reproduce while the constant arrives as an immediate.

## 5. State

- **Corpus 21 cases, all passing**; pin moved to 21. p6 and p7 are unchanged by the fix (neither has FP), which is
  the check that this is a targeted fix.
- p8: **118 / 139 by offset, 128 by content, 12 hunks**, case 0 exact, epilogue exact, table exact and now at the
  image's address.
- The `floating point` entry in `CLASSES_WITHOUT_A_PROBE` is still a refusal — it refuses a *cartridge probe*, and
  what changed is the *instrument*. With a correct pool an FP probe is now possible in principle; it still needs a
  real function whose C is recoverable, and M251's candidate remains a fragment.
