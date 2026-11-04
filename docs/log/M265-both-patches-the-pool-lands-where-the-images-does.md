# M265 — both patches together: the pool lands where the image's does, and p8's residue changes kind

M264 predicted that forcing every float constant into the pool *alone* makes p8 worse, and that it needs the pool
emitted **after** the function body as well. Both are now applied together, and the prediction was right in the way
that matters: p8 still reports 136 of 139, but **the three remaining words are a different question entirely.**

## 1. The two changes

1. **`mips_const_double_ok` returns `FALSE`** for a float constant. Evidence: a scan of the whole 1.9 MB image
   finds **zero `mtc1 $at`**, and `li.s`/`li.d` is the only way gcc puts a float immediate on MIPS — so the
   original compiler never took that path, for any constant, anywhere.
2. **`CONSTANT_POOL_BEFORE_FUNCTION 0`** in `config/mips/mips.h`. The image's `.rodata` is
   `[jump table][constant pool]`, which only happens if the pool is emitted after the body; varasm.c's default
   puts it before, and with a non-empty pool that shifts every table reference (the M264 measurement).

Both live in `tools/toolchain/patch_gcc281_fp.py`, applied by `provision.sh`.

## 2. What it bought: the pool now matches the image byte for byte at its start

Our `.rodata` and the image's, from `0x800b69b0`:

```
ours :  80024594 80024770 80024770 80024600 80024600 80024770 41f00000 00000000 40800000 00000000 ...
image:  80024594 80024770 80024770 80024600 80024600 80024770 41f00000 00000000 40800000 00000000 ...
```

**The first ten words are identical** — the jump table (six arm addresses) at the image's own address, then the
30.0 f that case 3/4 uses (`41f00000`) and its pad, then the 4.0 f that the multiply uses (`40800000`). Before this
milestone we had `[pool][table]` with a zeroed pool; now the layout and the values are the image's.

## 3. What p8's three words are now

| where | image | ours | what it is |
|---|---|---|---|
| `0x8002466c` | `3c01800b` `c42469d0` | `3c02800b` `c44469d0` | the pool base in **`$at`** against **`$v0`** — the load is otherwise the same instruction at the same address |
| `0x800246a4` | `d42069d8` | `d42069c8` | our `ldc1` reads the pool **16 bytes earlier** |
| `0x80024784` | — | `00000000` | one word of trailing `.text` padding past the image's extent |

Those are three *different* small things, and none of them is "the compiler inlines our constants" any more:

- **`$at` versus `$v0`** is a split-addresses/allocator difference: `$at` is the assembler's scratch, so the
  image's build let the *assembler* materialise the pool base while ours has gcc allocate `$v0`. `-msplit-addresses`
  is the obvious candidate and is the next cheap test.
- **the 16-byte pool offset** is a *source* fact: the image's pool holds a second `41f00000` at `0x800b69d8` that
  ours does not, because the image's code converts through **doubles** (`cvt.d.w` → `ldc1` → `add.d` → `cvt.s.d`)
  where our reconstruction does the arithmetic in `float`. So case 3/4's constant expression is still not the
  original's — ordinary reconstruction work, no longer blocked by the toolchain.
- the padding word is the same `.text` alignment artifact p6 has.

## 4. A build gotcha worth its own line

The first rebuild after adding `CONSTANT_POOL_BEFORE_FUNCTION 0` **changed nothing**: the `.s` still showed
`.rdata` before `.text`. 2.8.1's Makefile carries **no header dependencies**, so editing a target macro rebuilds
only the object that includes `tm.h` directly — `varasm.o` stayed stale and the macro was never re-read. Touching
`varasm.c` and `function.c` fixed it. `provision.sh` now touches every file the patch script edits, because this
is exactly the class of failure that produces a confident wrong measurement.

## 5. State

- **p6 byte-exact (98/98), p7 byte-exact (84/84, 0 hunks), p8 136/139 with three words of three different kinds.**
- Corpus **22 cases, all passing**. The FP case was rewritten rather than deleted: it now asserts that `4.0f` and
  `3.0e38f` both go to the pool with the right IEEE bits and **no `li.s`**, and it cross-checks the claim against
  the image itself (`0 mtc1 $at` in 1.9 MB). Asserting `li.s` was the M261-era behaviour and is now the wrong
  behaviour; a gate that keeps asserting the old symptom would block the fix that matches the cartridge.
- Next: `-msplit-addresses` for the `$at` question, and case 3/4's double-versus-single arithmetic for the pool
  offset. Neither is a toolchain mystery any more.
