# M247 — gcc 2.7.2 matches: three of four probes byte-for-byte, against IDO's one

M246 refuted IDO on the cartridge's move idiom (`addu` 6 560 times, `or` never) and the SDK's own makefiles
named the replacement: `CC = gcc`, `CFLAGS = -c -O -G 0`, `-I$(GCCDIR)/mipse/include`. This milestone builds that
compiler — **gcc 2.7.2.3 for `mips-elf`**, the `mipse` target the SDK means — and runs the same corpus on it.

## 1. The answer

| probe | class | IDO 5.3/7.1 | **gcc 2.7.2** |
|---|---|---|---|
| p1 `void f(void){}` | empty body | MATCH | **MATCH** |
| p2 `int f(int a,int b){return b;}` | return an argument | differ (homes args) | **MATCH** |
| p3 conditional global store | relocation-bearing | differ | differ — *unfalsifiable until linked* |
| p4 byte-copy loop | delayed branch | differ | **MATCH** |

**3 of 4, and the fourth is the probe that compares an object with relocations in it.** IDO reaches 1 of 4 — the
empty function — and fails p2 for a structural reason (it homes both arguments to the stack) that no C can fix.

Per profile: `gcc2.7.2 -O` **3/4**, `gcc2.7.2 -O2` **3/4**, `ido-5.3 G0` 1/4, `ido-7.1 G0` 1/4.

## 2. Two things had to be understood before the comparison meant anything

**`move` is a pseudo-instruction and the assembler expands it.** gcc emits

```
	.set	nomacro
	j	$31
	move	$2,$4
```

and the *assembler* decides the encoding. Modern gas 2.42 chooses `or rd,rs,$zero`; the cartridge has
`addu rd,rs,$zero` — the 1998 SDK's `as` chose `addu`. So M246's census was measuring the **assembler**, not the
compiler, and the corpus now performs that expansion explicitly (`move` → `addu rd,rs,$0`) instead of pretending
the difference is codegen. That is a correction to how the refutation should be read: it still refutes IDO (whose
own `as1` emits `or`), but it does **not** by itself refute a compiler.

**The C's loop shape is part of the probe.** p4's first form was `while (d < e) { *d++ = *s++; }`, which gcc
hoists the test out of; the cartridge has the test at the bottom. `do { … } while (d < e)` reproduces the 36
bytes exactly. A probe that "almost matches" is a C-recovery problem, not a compiler problem, and the corpus says
which probe is which.

## 3. Building a 1996 compiler on a 2026 host: six patches

Configure succeeded on the first try (`--target=mips-elf --with-gnu-as --with-gnu-ld --enable-languages=c`). Six
things then had to change, and **none of them touches code generation**:

| failure | fix |
|---|---|
| `<varargs.h>` is a refusal stub in modern clang/gcc | a host shim defining `va_dcl`, `VA_START`, `VA_END` in terms of `<stdarg.h>` |
| `sys_nerr` / `sys_errlist` are `const` in the modern SDK, not in 1996 | `extern const …` in three files (`cccp.c`, `gcc.c`, `cpplib.c`; `cp/g++.c` too) |
| configure missed `vprintf`, so the pre-ANSI `va_start(ap)` branch compiled | `-DHAVE_VPRINTF=1 -DHAVE_STRERROR=1 -DHAVE_VFPRINTF=1` |
| `CLIB` picked `-lmld`, an SGI library | `CLIB="-lm"` |
| clang rejects lvalue casts (`reorg.c`) and GCC 16 rejects the old `obstack` grow macros | build with **`gcc-16 -std=gnu89 -fcommon -w`** instead of clang; rewrite the three `obstack_*_grow` macros as two statements |
| `deduced.h` / `enquire.o` fail on `.stabs` | not needed: `cc1` is the compiler, and it built |

`cc1` is 2.8 MB and works. The driver `xgcc` also built but execs the host `cc`; calling `cc1` directly is
simpler and is what the corpus does. The assembler is GNU `as` 2.42 for `mips-linux-gnu`, so **the toolchain is:
`cc1` (1996) → `as` (modern, with the `move` expansion the cartridge uses)**.

## 4. What is left before this is a matching build

- **A linker run.** Every probe that names a symbol (p3) is unfalsifiable at object level; `mips-linux-gnu-ld`
  with a script placing `.text` at the function's address is the next step, and the boot image's map is already
  verified (M243).
- **The flags still to sweep**: `-O` vs `-O2` are indistinguishable on these probes (both 3/4), so the real
  discriminator will be a probe where they differ — a loop with a multiply, or a `switch`.
- **p1's object pads `.text` to 16 bytes** where the image has 8. A linker section with the right alignment
  removes that; at object level it is a note, not a mismatch.

Tooling: `provision.sh` now builds all four toolchains (`gas`/`ld`, gcc 2.7.2, IDO 5.3, IDO 7.1) and its doctor
reports each; `compile_probe.py` carries the profile matrix, the `move` expansion, and the 6 560 : 0 census that
started this.
