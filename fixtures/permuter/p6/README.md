# The permuter harness for `p6` (0x8004fd1c), committed

This is decomp-permuter's working directory for the five-arm switch at `0x8004fd1c`, kept in the tree so
the experiment is reproducible. `build/` is gitignored — correctly, it is 1.5 GB of cartridge-derived
images, provisioned toolchain and other projects' decomp trees — and that is why the *inputs* of the
M256/M259 permuter runs no longer existed when M299 tried to re-measure them. Only our own artifacts live
here: the draft, the build hook, the settings, and the scored candidates. No cartridge bytes are committed,
and the scoring reads the image at run time.

## What each file is

| file | provenance |
|---|---|
| `base.c` | our own draft of the function — the starting point the permuter randomises. At M299 it is **one statement transposition** away from the byte-exact source, and that transposition is worth 12 of 98 words |
| `compile.sh` | the build hook the permuter shells out to: `cc1 -O2 -G 0 -mips2 -mcpu=r4300`, then the binutils-2.7 `as` |
| `settings.toml` | `compiler_type = "gcc"`. **The file must be called `settings.toml`**: `get_settings()` opens that name only, so M256–M302 ran with this file called `f.toml` and never read it — every run before M303 used the default `[base]` weights (see M303) |
| `target.o` | **generated** by `make_target.py` from the image's own 98 words (not committed — it is cartridge code) |
| `target-draft.o` | the old **proxy** objective: 116 instructions compiled from an earlier draft, kept for provenance |
| `candidate-image-310-1.c` | the **byte-exact** candidate the image-objective run found — a different shape from the hand reconstruction |
| `make_target.py` | builds and verifies the image objective |
| `candidate-1780-1.c`, `candidate-1980-26.c` | two of the 16 candidates that reach **94/98** — the proxy-objective ceiling |
| `scores.json` | every number below, with the run's provenance |

## The measurement

Scored with the word metric — compile the candidate, link `.text` at `0x8004fd1c` and `.rodata` at
`0x800b8bd0`, compare word for word against the stage-2 image:

| source | words identical (of 98) | content-aligned | hunks |
|---|---|---|---|
| `base.c` (control) | **86** | 90 | 8 |
| the probe's `P6_SOURCE` (control, must be 98) | **98** | 98 | 1 |
| best candidate, 16 of them | **94** | 94 | 4 |
| the other 133 | 86 … 94 | | |

Three runs, and the objective is what separated them:

| run | objective | iterations | best by the word metric |
|---|---|---|---|
| M259's pool (82 candidates) | the draft proxy | — | 94 / 98 |
| M300 re-run | the draft proxy | 144 310 | **94 / 98** (16 candidates, none at 98) |
| **M302 run** | **the image's own 98 words** | 83 834 | **98 / 98 — byte-exact** |

So **the plateau was the objective, not the tool.** Against a proxy compiled from an earlier draft the permuter
circles 94/98 forever; against the cartridge it closed the function — and by a *different* route than the hand
reconstruction: `candidate-image-310-1.c` keeps a `new_var` temporary in case 4 where the hand solution
transposed two statements. Both compile to the same 98 words. **M300's conclusion — "the permuter cannot reach
this shape by randomisation" — is retracted here**; what it could not reach was a *stale* target.

The 78 % compile-error rate is unchanged and is a property of the randomiser on struct-heavy source, not of the
objective.

A correction that belongs here rather than in a footnote: **all three runs used the default `[base]` weights**, not
`gcc`. The settings file was called `f.toml` until M303 and `get_settings()` opens `settings.toml` only, so
`compiler_type` never applied. What moved the result was the **objective** — proxy versus image — and nothing else.

## The two objectives, and why the second one is the point

`make_target.py` builds the objective **from the image itself**: it reads the function's 98 words, assembles them,
and verifies the object's `.text` is byte-identical (392 B) before writing it. That object is deliberately not
committed — it is cartridge code — so run the script once with your dump present:

```sh
python3 fixtures/permuter/p6/make_target.py          # -> fixtures/permuter/p6/target.o
python3 fixtures/permuter/p6/make_target.py --check  # verify the one you have
```

`target-draft.o` is the **old** objective, kept for provenance: 116 instructions compiled from an earlier draft,
with unresolved relocations, against a 98-instruction function. Every verdict phrased in the permuter's score
against *it* (M259's "10 % gain, zero words") describes the proxy, not the cartridge. That is why the word metric
— which links both sides and compares bytes — stays the verdict.

One asymmetry survives and is stated rather than hidden: the image's pool reference is *resolved*
(`lui v0,0x800c` / `addiu v0,-29744` = the switch table), while a candidate carries `R_MIPS_HI16`/`R_MIPS_LO16`
against its own local table label. The permuter normalises those to symbol names, so a few lines differ on every
candidate; the ranking is unaffected and the byte metric does not care.

## Re-running it

```sh
export PATH="$PWD/build/toolchain/binutils/bin:$PATH"   # the permuter needs objdump on PATH
python3 build/toolchain/src/decomp-permuter/permuter.py fixtures/permuter/p6 -j 8
python3 tools/compile_probe.py --check                   # scores the committed sources
```

The permuter writes `output-<score>-<n>/` directories into this folder; they are worth committing when they
beat `scores.json`'s best, and worth deleting when they do not.
