# M250 — gcc 2.8.1: four of four probes byte-exact, and the compiler is identified

M249 localised p3's residue to the compiler (both gas versions expand `sw $2,symbol` into `lui $at`; the image has
`lui $3`, a general register, before the `addiu`). This builds **gcc 2.8.1** — the 1998 release a 1999 SDK would
ship — and it closes the probe.

## 1. The answer

| probe | class | IDO 5.3/7.1 | gcc 2.7.2 | **gcc 2.8.1** |
|---|---|---|---|---|
| p1 `void f(void){}` | empty body | MATCH | MATCH | **MATCH** |
| p2 `int f(int a,int b){return b;}` | argument move | differ | MATCH | **MATCH** |
| p3 conditional global store (**linked**) | address materialisation | differ | differ | **MATCH** |
| p4 byte-copy loop | delayed branch | differ | MATCH | **MATCH** |

```
p3 want = got = 3c028013 8c4214cc 10400003 3c038013 24020001 ac6244c0 03e00008 00000000
```

**4 of 4.** The two compilers differ exactly where M249 predicted: 2.8.1 materialises the store's address into a
general register (`lui $3`) and its delay-slot filler hoists that `lui` into the `beq` slot; 2.7.2 hands the
address to the assembler, which uses `$at` and fills the slot with the `addiu`. One instruction's scheduling,
two words in the image, and it is the difference between "a compiler that reproduces this cartridge" and one
that does not.

So the toolchain is:

```
cc1 (gcc 2.8.1, mips-elf)  ->  as (binutils 2.7, `move` -> addu)  ->  ld (2.42, with objcopy)
```

and `-O` and `-O2` are still indistinguishable: both give 4 of 4 on this corpus. That is the next probe's job,
not this one's.

## 2. Building 2.8.1 on a modern host: five patches

| failure | fix |
|---|---|
| `configure: can not guess host type` | 2.8.1's `config.guess` predates `aarch64-apple-darwin`; 2.42's copies handle both old- and new-style calls |
| `Configuration aarch64-apple-darwin25.6.0 not supported` | the host case ends in `exit 1`; a `*-*-darwin*` branch using the generic `xm-linux.h` **plus** `xm-std32.h` (2.8.1 has no 64-bit host config, and the exit codes live there) |
| bare vs prefixed paths | `xm_file` wants bare names — the Makefile prefixes `config/` itself, so a path yields `config/config/…` |
| `c-lex.c: TARGET_NEWLINE undeclared` | `config.h` is generated with host macros only, and only `crtstuff.c` includes `tm.h`; appending `#include "tm.h"` to the generated `config.h` is what makes cc1 compile |
| `obstack.h: lvalue required as increment operand` | the same three `*((T **)__o->next_free)++ = …` macros as 2.7.2, rewritten as two statements |
| `cccp` cannot find the target macros | not needed: `make cc1` builds the compiler alone, and the standalone preprocessor is not in this pipeline |

Plus the five `const` patches on `sys_nerr`/`sys_errlist` that both gccs need, and the `<varargs.h>` shim.

## 3. What this means for the matching build

Three things are now settled that the roadmap's stage 4 asked for: **the compiler** (gcc 2.8.1 for `mips-elf`),
**the assembler** (binutils 2.7, which is also what produces the `addu` move idiom), and **the flag set's shape**
(`-G 0`, big-endian, `-mips2`; `-O` vs `-O2` still open).

What is *not* settled, stated so it is not assumed: four probes are not a compiler proof. They cover a leaf, an
argument move, a linked global store and a delayed loop — deliberately different codegen classes, but four
functions out of 3 638. The next step is the same corpus extended by the classes the four do not reach: a
`switch` that compiles to a jump table (the corpus has 86 dispatch heads to draw from), a struct copy, an
integer multiply/divide, and a floating-point expression. If those also match, the compiler identification is
solid enough to translate against.
