# M300 — the permuter re-run: its ceiling is 94/98 under both weightings, and its objective was never the ROM

The permuter was re-run with the word metric as the verdict, and its harness was committed. The run added 67
candidates and **moved nothing**: no candidate above **94/98** in 144 310 further iterations. It also exposed
why the earlier verdicts were hard to trust — not the scoring this time, but the *objective*.

## 1. Two defects in the harness, both real

- **`compiler_type` was `"ido"`** (M256). It selects IDO's randomisation weights for a compiler that is not IDO;
  this project's compiler is gcc 2.8.1. Corrected to `"gcc"`.
- **The permuter needs `objdump` on `PATH`**, and the toolchain's binutils are not installed system-wide. The
  first launch died instantly — `Could not find any objdump executables … for mips` — which is also why the
  harness cannot be run from a bare shell without `export PATH="$PWD/build/toolchain/binutils/bin:$PATH"`.
  Documented in the fixture README.

Neither defect was in the source, and neither changes the conclusion. But together they are why "re-run the
permuter" was never as cheap as it looked.

## 2. The run

```
iterations          144 310
compile errors      113 224   (78 % — the randomiser keeps emitting C this cc1 rejects)
better-score events      34
permuter's own score  1980 -> 1790  (lower is better)
new candidate dirs       67   (82 -> 149)
```

Scored with the word metric — compile, link `.text` at `0x8004fd1c`, `.rodata` at `0x800b8bd0`, compare word for
word against the stage-2 image:

| source | words identical (of 98) | content-aligned | hunks |
|---|---|---|---|
| `base.c` (control) | 86 | 90 | 8 |
| `P6_SOURCE` (control; must be 98) | **98** | 98 | 1 |
| 16 candidates, including 2 from this run | **94** | 94 | 4 |
| the other 133 | 86 … 92 | | |
| any candidate at 98 | **none** | | |

So the plateau that M299 found in the M259 pool is **not an artefact of the old pool**: 67 fresh candidates from
a corrected-weighting run land in exactly the same place, four words short. **The permuter cannot reach this
function's shape by randomisation; the shape solver reached it in nine enumerated variants** because the
difference is the *order of two statements*, which is a search move, not a guess.

## 3. The finding: `target.o` is a proxy, not the function

`target.o` — the object the permuter steers toward — is **116 instructions**, produced by compiling an earlier
draft. The function in the image is **98**. Its first two words match the image (`sltiu v0,a2,5`, then the first
branch offset is `1040005e` against `10400070`), and it carries **unresolved relocations** (`lui v0,0x0` pending
`R_MIPS_HI16`) where the image has resolved immediates.

That is a defensible choice — a relocatable object compares like with like against a relocatable candidate — but
it means **the permuter's objective was never the cartridge**. Its score is a proxy, and every verdict phrased in
its score (M259's "10 % gain, zero words") is a statement about the proxy. The verdict has to come from the word
metric against the image, which is what M299 and this run both do. **Whether rebuilding `target.o` from the
image's own 98 words moves the 94/98 plateau is now an open question, stated as one.**

## 4. Why `build/` is gitignored, and what got committed instead

`build/` is **1.5 GB**: `toolchain/` 1.0 G (gcc 2.8.1 + binutils sources and objects), `sdk/` 346 M (**Nintendo's
SDK**, copyrighted), `splat/` + `decomp*` ~105 M (other games' trees), plus `elfs/` — the 36 images decompressed
out of the cartridge. It is ignored for three reasons in that order of seriousness: it is where **cartridge-derived
bytes** land, it holds **third-party copyrighted trees**, and everything in it is rebuildable from
`tools/provision.sh` + `build_images.py`. `asm/` is ignored by the same rule, which shows the rule is "nothing
derived is committed", not "nothing big".

**M259's failure was not that rule — it was granularity.** The one input that was neither cartridge-derived nor
third-party was `base.c`, our own 737 bytes, and it lived only in a wiped tree. So the fix is a committed
**harness**, not a committed `build/`:

```
fixtures/permuter/p6/
  base.c                     the draft (ours)
  compile.sh                 the build hook, repo-root-relative (ours)
  f.toml                     compiler_type = "gcc"
  target.o                   the proxy objective (compiled output, ours -- 1 772 B, no ROM bytes)
  candidate-*.c              two of the sixteen 94/98 candidates (ours)
  scores.json                every number above, with run provenance
  README.md                  what each file is, the caveat, and how to re-run
```

Two probe cases now keep it honest, so the claim is measured rather than remembered: the harness **re-scores to
its recorded verdict** (base 86, best 94, nothing at 98), and **the objective's size is pinned** (`target.o` 116
words against the image's 98). Corpus **45 → 47 cases, 47/47 passing**.

## Numbers

- compile probe **45 → 47 cases** (47/47 pass), fixtures **+8 files**
- suites, tools, functions, fragments, coverage and the analysis ladder unchanged
- `build/permuter/p6/` keeps growing locally (149 dirs); only the two best are committed, per the README's rule
