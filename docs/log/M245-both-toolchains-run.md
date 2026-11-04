# M245 — both toolchains run: IDO 5.3 and 7.1 native, GNU as/ld for mips

Stage 4's prerequisite is a compiler and an assembler. Both now exist on this machine, and one of them arrived
from outside the repository in a way worth recording.

## 1. What is installed, and how it got there

```
build/toolchain/binutils/bin/mips-linux-gnu-{as,ld}     GNU Binutils 2.42
build/toolchain/ido-7.1/{cc, as0, as1, ugen, uopt, ujoin, usplit, upas, uld}
build/toolchain/ido-5.3/{…the same set…}
```

`splat` emits `.s` files; without a MIPS assembler they are text. `tools/toolchain/provision.sh` builds GNU
`as`/`ld` from source, and builds **IDO 5.3 and 7.1** by static recompilation of the original IRIX binaries.

The IRIX binaries are not fetched by this repository: they are proprietary, and a decompilation that
redistributes its compiler has a licensing problem rather than a shortcut. The owner supplied
`ido-static-recomp-main.zip`, which carries `ido/5.3` and `ido/7.1` under their own licence; the script takes it
via `IDO_RECOMP_ZIP` or `IDO_RECOMP_DIR` and recompiles locally.

## 2. The probe that proves the compiler works

```
$ USR_LIB=build/toolchain/ido-7.1 build/toolchain/ido-7.1/cc -c -O2 -non_shared -G 0 -mips2 probe.c
$ .text = 03e00008 00851021        # jr ra; addu v0,a0,a1
```

`int f(int a, int b){return a+b;}` at N64-era flags produces the N64-era form, with the add in the delay slot.
The toolchain is not merely present; it produces this target's idiom.

## 3. Six failures found by running it, not by reading about it

| failure | cause | fix |
|---|---|---|
| `--disable-gas=no` | not a flag; my invention | removed |
| configure "FAIL" with no reason | run by a relative path from the build dir, output to `/dev/null` | absolute path, logged |
| bundled zlib vs macOS 14 SDK | `zutil.h` defines `fdopen(fd,mode) NULL` when undetected, colliding with `_stdio.h` | three outside overrides failed (inline, exported, `--without-zlib`); a verified `sed` removes all three copies and asserts the count |
| `grep -c` assertion | `grep -c` prints `0` **and** exits 1, so `|| echo 0` yielded `"0\n0"` | `|| true` |
| `info-recursive` aborts | no texinfo on the host | `MAKEINFO` passed as a **make command-line variable** (the Makefile defines it, so an environment variable does not override it) |
| IDO "cannot execute binary file" | `USR_LIB` pointed at `ido/<ver>/usr/lib`, so `cc` exec'd the IRIX `cfe` | flatten the native tools + `err.english.cc` into `build/toolchain/ido-<ver>/` and point `USR_LIB` there |

Two more relative-path bugs of the same class were caught while encoding it, which is why every path in the
script is now built from `$root`.

## 4. What it unlocks, and what it does not

Unlocked: the compile-probe corpus (M246), which refutes IDO in favour of the GNU toolchain. Also unlocked:
assembling splat's output, which is the half of the boot rehearsal M243 could not run.

Not unlocked: a **linker script per image** and a working `uld` invocation. `as`/`ld` existing is not the same
as a build that reproduces an image; that is stage 5, and it starts with the boot image whose map is already
verified.

Also noted from `command-tab/awesome-n64-development`: `m2c` + `m3c` (MIPS→C, with `decomp-permuter`),
`asm-differ`, `y64_linker` (MIPS64 ELF relocation resolution), `ultralib`/`libreultra` (a decompiled libultra,
relevant if RE2 links one), `n64sym`, and `f3dex2` (matching RSP microcode disassembly). The macOS N64 binutils
tap needs `brew trust`, which is the owner's decision; it is moot now that IDO's own assembler works.
