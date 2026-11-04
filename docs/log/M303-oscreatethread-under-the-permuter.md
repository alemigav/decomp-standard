# M303 — `osCreateThread` under the permuter: a negative result, the shape/allocation boundary, and an inert setting

The ask was the obvious follow-up to M302: point the newly-validated permuter at `osCreateThread` (`0x80006d60`,
boot image, 52 words, **23 of 52** from M298). It produced **no improvement** — and on the way it exposed that one
of M300's two "harness defects" was never a defect at all, because the settings file was never read.

## 1. The run

`make_target.py` gained two flags so any function in any of the 36 images can be an objective — `--image-offset`
(boot is the ROM at `0x1000`, base `0x80000480`) and `--symbol` — and built the boot target: **52 words, 208 B,
byte-identical to the image**, verified.

```
iterations           167 244
compile errors       124 043   (74 %)
better-score events       38
permuter score        ~1000 -> 860
candidate dirs            52
```

## 2. Nothing improves the function

| source | words identical (of 52) | content-aligned | compiled words |
|---|---|---|---|
| `base.c` (control) | **23** | 41 | 52 |
| best by word count | **26** | 39 | **56** |
| second | 25 | 38 | 56 |
| the other 50 | 23 | 40 … 41 | 52 |

The two candidates that gain words **emit four instructions too many** and are *worse* content-aligned, so neither
is an improvement. **Zero of 52 is.**

## 3. The boundary, measured instead of assumed

`p6` went **86 → 98** under this same harness (M302). The difference is what kind of residue each function has:

| function | residue | permuter |
|---|---|---|
| p6 `0x8004fd1c` | the **shape** of case 4 — a statement order, then a temporary | **closed it, byte-exact** |
| `osCreateThread` `0x80006d60` | **parameter-load scheduling and register allocation** | **moved nothing** |

> **The permuter is a shape search.** Its moves — temporaries, types, statement order, same-line-ness — change how
> the source is written, not which register the allocator picks. An allocation residue stays hand work, which is
> the corpus's own standing rule arriving again from a new direction: *size is not what makes a function hard;
> allocation is.*

This is a genuinely useful negative: it says where to spend the permuter (shape residues — the arm-shaped family,
the statement-order cases) and where not to (the allocation-limited ones, `osCreateThread` here and `0x8007e590`'s
case-4 select register).

## 4. The retraction: `compiler_type` was never read

`get_settings()` opens **`settings.toml`** and nothing else. This directory's `f.toml` — the name M256 chose, and
which I kept — was therefore **never opened**, from M256 through M302. Two consequences, both now recorded:

- **M300's "second defect" is withdrawn.** It said `compiler_type` was `"ido"` and that correcting it to `"gcc"`
  mattered. The correction was **inert**: the file was not read before or after, so **M256, M259, M300 and M302 all
  ran on the default `[base]` weights**. M300's phrase "under both weightings" is wrong — it was **one** weighting
  and **two objectives**. The M302 result is unaffected and is in fact cleaner: the only variable that moved was
  the objective, which is what that milestone claims anyway.
- **This run is the first in the project where a non-default weighting applied** (`settings.toml`, `gcc` weights).
  It did not rescue the allocation residue, which is the honest way to report it.

`fixtures/permuter/p6/` is corrected in place (`settings.toml` renamed, the row rewritten, `scores.json` carries a
`correction` field) rather than left to disagree with the new one.

## Numbers

- compile probe **49 → 51 cases** (51/51 pass): the `osCreateThread` draft reproduced at 23/52 with a 52-instruction
  object, and its best candidate pinned at 26/52 *with 56 instructions* so the "no improvement" claim is measured
- `fixtures/permuter/d60/` — base, `settings.toml`, the best candidate, `scores.json`, README; `make_target.py`
  gained `--image-offset` and `--symbol`
- tree: **73 suites / 1 026 cases** (740 need the cartridge), 100 tools, 3 416 functions, 1 211 256 B — unchanged
