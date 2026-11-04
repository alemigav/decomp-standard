# The toolchain: what is proven, what is hypothesised, and what the owner has to supply

A matching decompilation needs three things this repository does not vendor: a **MIPS assembler and linker**, the
**original compiler**, and a **linker layout** per image. This document keeps them separate, because they fail
for different reasons and are proved by different measurements.

**Status as of M245: all three pieces exist on this machine.** `mips-linux-gnu-as`/`-ld` (GNU 2.42) and
**IDO 5.3 and 7.1, recompiled to run natively** (`cc`, `as0`, `as1`, `ugen`, `uopt`, `ujoin`, `usplit`,
`upas`, `uld`). The stage-4 blocker is gone: the original compilers execute here and produce MIPS objects.

A probe through IDO 7.1 — `int probe_add(int a, int b) { return a + b; }` at `-O2 -non_shared -G 0 -mips2` —
emits `.text` `03e00008 00851021` = `jr ra; addu v0,a0,a1`, which is the N64-era form with the add in the
delay slot. So the toolchain is not merely present, it produces the idiom this cartridge uses.

Read the dates, not the optimism.

## 1. Assembler and linker — open source, being provisioned now

`splat` emits `.s` files. Without `mips-linux-gnu-as` and `-ld` they are text: no object, no link, no byte
comparison. `tools/toolchain/provision.sh` builds them from GNU source into `build/toolchain/` (gitignored).

```
sh tools/toolchain/provision.sh --doctor   # report only
sh tools/toolchain/provision.sh            # build, then report
```

**Measured obstacles on macOS 14 / Apple clang 17**, each one found by running it rather than reading about it:

| obstacle | what happened | resolution |
|---|---|---|
| `--disable-gas=no` | not a real flag; configure died | removed — my bug |
| configure run by relative path from the build dir | ran the wrong file, output sent to `/dev/null`, reported only "FAIL configure" | absolute path + log to `build/toolchain/configure.log` |
| **`cc1` cannot parse comments** | this build answers `/* ... */` -- trailing or on its own line -- with `parse error before ...`, and the message is mojibake when the previous line was missing a typedef, so the two defects present identically | no fix: every source in `tools/compile_probe.py` is comment-free, and a new probe must be too. Found while transcribing `osCreateThread`, where a `/* 0x100 */` column of field offsets cost two compile attempts (M298) |
| **gcc 2.8.1's constant-pool floats** on a 64-bit host | a CONST_DOUBLE holds two 32-bit *target-pattern* words, but the fast path that stores one is guarded by `sizeof u == 2 * sizeof (HOST_WIDE_INT)` -- 8 == 16 here -- so SFmode/DFmode fell through to a raw `bcopy` of the emulator's packed internal form. Every pool float came out as `0`, and `mips_const_double_ok`, which reads the same words, never chose `li.s` either | three coordinated edits (writer, `REAL_VALUE_FROM_CONST_DOUBLE`, pool) applied by `tools/toolchain/patch_gcc281_fp.py`, re-run by `provision.sh`; verified by a corpus case that checks `3.0e38f` emits `0x7f61b1e6` and 30.0f becomes `li.s` (M261) |
| binutils' **bundled zlib** vs the macOS SDK | `zutil.h` defines `fdopen(fd,mode) NULL` when `HAVE_FDOPEN` is undetected, which collides with `_stdio.h:322` | `ac_cv_func_fdopen` did **not** help (inline, exported, and `--without-zlib` all failed); the fallback is deleted from the build tree by a one-line patch that is re-applied every run from a fresh tarball |

The honest conclusion: **macOS is a bad host for 1990s binutils, but it is survivable.** The build works with
four workarounds (zlib `fdopen`, `MAKEINFO` as a make *command-line* variable, no texinfo, `--without-zlib`),
all encoded in `provision.sh` and all discovered by running it rather than reading about it.

**And binutils turns out not to be on the critical path.** IDO ships `as0`/`as1` (its assembler) and `uld` (its
linker), which is what the game was actually built with; the recompiler makes those native too. GNU `as` is
needed only if a probe wants splat's GNU-dialect output. Two assemblers, one of them the original, is a better
position than one.

## 2. The compiler — named by the SDK's own makefiles, and now runnable and proven

The owner supplied the **Nintendo 64 Developers Toolkit v5.2** disc (M247). It is a Mode-2 raw CD image; once
the sector framing is stripped it mounts, and inside:

| path | what it is |
|---|---|
| `pc/basic/data1.cab` (InstallShield, `unshield`) | 811 files: `NuSTD`, `NuSystem`, `misc` — the libraries and tools, **no compiler** |
| `sgi/n64kit52.tar` | the IRIX kit: `ccbl`, `HVQ`, `niff`, `nustd`, `nusys`, `misc` — again libraries, no `cc1` |

So the toolchain binary is not on this disc; what *is* on it is the build contract. **The compiler is now built
from GNU source and proven** (see §4 for the flags and the evidence, and `tools/toolchain/provision.sh` for the
recipes) — the disc settled *which* compiler, the build settled *that* it reproduces the cartridge. What the disc
gives is:

```
NuSTD/src/makefile:   CC = gcc          CFLAGS = -c -O -G 0 $(WFLAGS) ...
                      INCLUDES = -I$(GCCDIR)/mipse/include
NuSystem/sample/…:    LDFLAGS = … -L$(GCCDIR)/mipse/lib -lkmc
```

`gcc` for the **`mipse`** target (big-endian MIPS), **`-O` — not `-O2`** — and **`-G 0`**, with the runtime
named `-lkmc`. That corroborates the census that refuted IDO (§ below) and fixes the next profile to test.

To *run* it the options are, in order of cost: wine over the Windows-hosted gcc (not on this disc either), or a
native build of gcc 2.7.2 for the host — `n64chain` and `modern-n64-sdk` exist for exactly that, and they are
the next provisioning target. Until one of those exists, the probe corpus can test IDO and nothing else.

## 2b. The compiler question as it stood before the disc

The candidate set for a 1999 N64 title is small and none of it is guessable:

| candidate | why it is plausible | how it would be tested |
|---|---|---|
| **IDO 5.3** | the common N64-era SGI compiler | compile a probe corpus, diff against the image |
| **IDO 7.1** | used by later N64 titles; the Ocarina of Time toolchain | same |
| **gcc 2.7.2 / 2.8.1** | some 1999 titles used GNU | same |

`decompals/ido-static-recomp` (86★) recompiles **the original IRIX binaries** for a modern host. That means the
IRIX binaries must come from the machine's owner, and **this repository will not fetch, commit or redistribute
them** — a decompilation that ships its compiler has a licensing problem, not a shortcut.

Set `IDO_53_DIR` / `IDO_71_DIR` to directories holding the IRIX IDO binaries, and the doctor will say whether
the recompiler can use them. Until then the compiler question is **open**, and no function here has been
compiled against anything.

## 3. What "proven" means for each piece

| claim | evidence required | state |
|---|---|---|
| the split tiles an image | `splat_boot.py --check`: files tile `0x1000..0x12140`, every emitted file covers its extent word for word | **proven on boot** (M243) |
| the map reassembles the image | the same check: slicing the cartridge by the split's own extents reproduces 69 952 B byte for byte | **proven on boot** (M243) |
| the built image equals the cartridge | `match_diff.py`: `build/elfs/boot.elf` vs the ROM slice, 100.000 % | **proven on boot** (M242) |
| the emitted asm assembles | assemble it and compare the object's `.text` with the image | **possible now** — two assemblers exist; not yet run on splat's output |
| C compiles back to the original bytes | one function, one compiler profile, byte equality | **possible now** — IDO 5.3 and 7.1 both run; the measurement has not been made |

## 3b. The SDK-era assembler (M249)

`binutils 2.7` (1996) is built at `build/toolchain/src/bu27-build`, and it settles a question M247 could not:

| tool | `int f(int a){return a;}` | the cartridge |
|---|---|---|
| **binutils 2.7 `as`** | `00801021` **`addu`** | `addu` |
| binutils 2.42 `as` | `00801025` `or` | — |
| IDO's own `as1` | `00801025` `or` | — |

So the corpus no longer normalises `move` when the 2.7 assembler is present: the real tool does what the cartridge
does. With it, p1/p2/p4 are byte-exact and p3 is 6 of 8 (M249).

Two host problems, both recorded rather than papered over:

- **2.7's `ld` writes an empty file on this host.** It builds, runs, and produces zero bytes. Linking therefore
  uses 2.42's `ld`, with 2.42's `objcopy` first — 2.7 writes a `.symtab` whose `sh_info` modern `ld` rejects
  (*"local symbol at index N >= sh_info"*), and `objcopy` rewrites exactly that.
- **2.7's `configure` needs a modern `config.sub`.** It calls it with old-style multiple arguments, which a
  current `config.sub` rejects and which 2.7's own cannot answer for `aarch64-apple-darwin`; 2.42's copies work
  for both.

## 4. The compile probe, run — and what it settled

The corpus was built the way this section used to argue it should be, and it answered the question.

**Chosen by codegen class, not by address**, and now also by *function*: four generic probes (an empty body, a
returned argument, a linked conditional global store, and a byte-copy loop) plus three whole functions recovered
from the disassembly — `0x8004fd1c`, `0x80057e1c` and `0x80024558`, whose arms are a state machine, a second state
machine and a block of Gfx command packets. Four codegen classes are **refused with a measurement** rather than
probed with weakened C, which is the honest outcome when the cartridge has no cheap example.

**What it settled**, each by measurement rather than by reading:

- **IDO is refuted**, and not by preference: for `int f(int a){return a;}` it emits `or v0,a0,zero`, while the
  cartridge contains `addu rd,rs,zero` 8 501 times and `or rd,rs,zero` zero times.
- **gcc 2.8.1 for `mips-elf` at `-O2 -G 0 -mips2 -mcpu=r4300`** reproduces every probe, and **binutils 2.7** is the
  assembler that expands `move` to `addu` — invoked as `-EB -mips2 -mcpu=r4300 -g -G 0`. **The `-g` is required and it
  is not about debug info**: gas's `mips_optimize` defaults to 2, and at that level `tc-mips.c` fills a branch's delay
  slot by *swapping the branch with the preceding instruction* unless a label, a `nop` or `.set noreorder` blocks it;
  `-g` sets `mips_optimize = 0` and stops it. The image shows the swap never happened — **none of its 2 237 `jr ra`
  instructions has a load in the delay slot** — and the first function that could tell was `0x800701d8`, whose 44 arms
  are `load; jr ra; nop` (3 words) against our 2, a 41-word difference that vanishes under `-g` (M281). `-mcpu=r4300` is not optional on either: on the compiler it selects the
  load's `READY-DELAY` and therefore the instruction order, on the assembler it stops hazard `nop`s after `mtc1`.
- **One more patched behaviour, and it is about the pool's *sharing* rule (M291).** The image gives every **DFmode**
  constant its own pool slot — the double 2^32 appears seven times inside `FUN_800a3094`, at
  `0x800ba630..0x800ba660` — and shares its **SFmode** ones (both `4.0f` reads in `FUN_80024558` hit one slot).
  M267 removed deduplication for every mode and lost 46 words because the float side then flooded the pool;
  excluding only `DFmode` from `immed_double_const`'s chain search and from `force_const_mem`'s pool hash is the
  asymmetry the image shows, and it moves `0x80024558` from 136 to **137 of 139** words with no change to any other
  recovered function. `patch_gcc281_fp.py` carries it as edits 6 and 7.
- **The float-address split is off too (M292).** `mips_check_split` refuses to split an address only when the mode
  is wider than a word, so a `DFmode` pool load stays symbolic and the assembler expands it with `$1` — but an
  `SFmode` one is 4 bytes, so the pool address was split into a pseudo register and the load came out as `lui $2`
  where the image has `lui $1`. Excluding the float class from that guard reproduces the image and takes
  `0x80024558` from 137 to **139 of 139** words.
- **Two places where the image contradicts what the disc's makefile implies.** The kit's makefile says `CC = gcc`
  with `CFLAGS = -c -O -G 0`, but `-O2` is what reproduces the image (`-O` misses by 10 words on the two
  byte-exact functions), so either that makefile is the libraries' contract rather than the game's, or the game
  was built with different flags. And the image's constant pool holds **no `li.s` expansion anywhere** — a scan of
  the whole 1.9 MB finds zero `mtc1 $at` — so the original compiler never took the float-immediate path, which
  vanilla 2.8.1 does and which therefore has to be patched out.
- **Two whole functions are byte-exact**, and a third differs in three words whose causes are known and recorded.

The verdict is still `match_diff.py`'s: the first differing instruction, never a hash.
