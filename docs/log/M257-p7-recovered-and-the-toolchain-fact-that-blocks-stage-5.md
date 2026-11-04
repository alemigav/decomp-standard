# M257 — p7 recovered: 60 of 84 words, a table that matches 8 of 8, and the toolchain fact that blocks stage 5

M256 left the permuter plateaued on p6 and named the next function: **p7 at `0x80057e1c`** — 336 bytes, bound
**7**, index **the byte at `ctx+6`**, table `0x800b8f78`. It is a different *shape* from p6 in the one way that
matters: all seven arms live inside **one contiguous range** (p6's five were six separate corpus functions), and
**two of them fall through** (`0` into `1`, `4` into `5`), so the table's entries land mid-arm.

## 1. What the function is

A state machine on `ctx->mode`:

```
case 0: f1e8 = 0x06000700; mode = 1; f1e0 = 0; RMW(dev+0x19a5c) |= 0xc0;   /* falls through */
case 1: mode += FUN_80089d54(ctx, a1, tbl, 0x200); break;
case 2: D_8012BFA8[0] = 2; RMW(dev+0x19a5c) |= 0x8000; D_80131780[0] = 1;
        *(u32*)(D_80131780+0x44) = *(u32*)(dev+0x19a60); mode = 3; break;
case 3: break;
case 4: f1e8 = 0x06000700; mode = 5;                                       /* falls through */
case 5: mode += FUN_80089d54(ctx, a1, tbl, 0x10200); break;
case 6: FUN_800551e0(); *(u32*)&ctx->f4 = 0x01000000; RMW(dev+0x19a5c) &= ~0x80; RMW(...) &= ~0x40; break;
```

The prototype is **forced by the callee**, not guessed: `0x80089d54` does `lbu t1,488(a0); move a1,a2; jal
0x80089dc8` — it forwards its `a1`/`a2` and reads only `a0`, so `FUN_80057e1c` must take `(ctx, a1, tbl)` and pass
the two through, with `a3` a flag word. That is the first prototype in this project derived from a **callee's**
argument use rather than the function's own.

## 2. Result: 60 of 84 by offset, 64 aligned by content, and the table 8 of 8

| region | words |
|---|---|
| head + dispatch | **14 / 14** |
| case 0 | 0 / 14 |
| case 1 tail | 3 / 3 |
| case 2 | 10 / 20 |
| cases 4 + 5 | **14 / 14** |
| case 6 | **15 / 15** |
| epilogue | 4 / 4 |
| **jump table (placed by the linker at `0x800b8f78`)** | **8 / 8** |

Both residues are **instruction permutations, and the multiset of mnemonics is equal on each side** (a
`collections.Counter` over the arm says so). So the operations are right and the *order* is not:

- **case 0**: the image materialises `0x06000700`, stores it, *then* builds the `0x18000` register; mine builds the
  register first and sinks that store past `lw 6748`. A store moved below a load gcc decided does not alias.
- **case 2**: mine hoists `lw 6752(v0)` above `sw 6748(v0)`; the image leaves it after.

Two numbers are reported rather than one because they answer different questions, and the difference is the same
discipline M255 had to learn: **by offset** is the matching-decompilation question (60/84), **aligned by content**
is the reconstruction question (64/84 in 6 hunks). The probe asserts both.

## 3. The lever that mattered, and it is a source-shape fingerprint

`0x18000 + 0x1a5c` comes out as `lui 0x1 / ori 0x8000 / addu` — that is
`LEGITIMIZE_ADDRESS` splitting a `PLUS(REG, 0x19a5c)` at `& ~0x7fff`, and **it only fires when the base is a
pointer pseudo derived from an `extern` symbol**. A literal, or `sym + 0x18000` folded at compile time, becomes
`lui 0x800e` instead. Declaring `dev` **inside each case block** rather than at function scope is what makes the
allocator coalesce base and result the way the image does: **49/84 → 60/84**. That is a fingerprint worth keeping:
the idiom proves the original built the address from a *pointer variable over an extern*, never from a constant.

## 4. Three instrument facts, one of them corrected

- **`build/toolchain/mips-gcc-2.8.1/bin/cc1` cannot parse any comment.** Verified:
  `int f(int a) { /* a comment */ return a; }` → `parse error before `(null)'`. There is no driver and **no `cpp`
  in that prefix** — only `cc1` — and `cc1` is the *preprocessed-input* backend, so it never sees comments,
  `#include`s or macros. This is not a curiosity: **stage 5's real sources are `#include`-bearing splat output**,
  so either 2.8.1's `cccp` gets built (M250 skipped `make cccp`, and it exists in the tree) or the pipeline
  preprocesses with the host's `cpp` first. Corollary found the same way: a **missing typedef** produces the same
  `parse error before <mojibake>` plus a possible SIGBUS, so that error in this toolchain almost always means
  "undefined type earlier", not a real parse problem.
- **`mips-linux-gnu-objdump` needs `-EB` only for a raw slice.** With `-b binary` there is no header to state the
  endianness and every word decodes little-endian into plausible nonsense; on a real ELF object objdump honours
  the object's own endianness and `-EB` is unnecessary. **Measured, not assumed** — this is the correction to the
  handed-over claim: `objdump -d eb.o` and `objdump -EB -d eb.o` both print `27bdffe8 addiu sp,sp,-24`. It is the
  same trap that made M256's first comparison wrong, and it is worth stating in the exact form that is true.
- **Before linking a binutils-2.7 `as` object, run
  `objcopy --set-section-alignment .text=4 --set-section-alignment .rodata=8`.** 2.7's `as` leaves `.text` at the
  default 16-byte alignment, which shifts the whole function by 4 bytes; every word then looks different for a
  reason unrelated to the C. `.rodata` needs 8 for the same reason the image's tables are 8-aligned (M253).

## 5. State

- **p7 is in the corpus**: `tools/compile_probe.py` gains `P7_SOURCE`/`p7_function()` and two cases (whole
  function, table), so the corpus is **17 cases, all passing**, with the acceptance pin moved to 17.
- Two functions are now recovered from the image and re-compiled: **p6 (82/98 by offset) and p7 (60/84)**, both
  with every residue named as a scheduling difference. Neither is byte-exact, and that is said plainly: the open
  item on both is **which store/load/hazard position gcc picks**, one class of problem, not two.
- Next: the case-0/case-2 store position is the same question as p6's hoisted `lbu`. A permuter will not answer it
  (M256); reading gcc's `mips.c` scheduling decisions against the image will.
