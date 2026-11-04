# The permuter on `osCreateThread` (0x80006d60) — a negative result, with the boundary named

52 words in the **boot** image, base `0x80000480`. The draft (`base.c`) is the M298 reconstruction: the `OSThread`
layout read off the stores, the constants pinned, **23 of 52 words**. The objective is built from the image by
[`../p6/make_target.py`](../p6/make_target.py) (`--image-offset 0x1000 --base 0x80000480 --symbol osCreateThread`).

## The run

```
iterations           167 244
compile errors       124 043   (74 %)
better-score events       38
permuter score        ~1000 -> 860
candidate dirs            52
```

## The verdict: nothing improves the function

| source | words identical (of 52) | content-aligned | compiled words |
|---|---|---|---|
| `base.c` (control) | **23** | 41 | 52 |
| `candidate-765-1.c` (best by words) | **26** | 39 | **56** |
| `candidate-965-2.c` | 25 | 38 | 56 |
| the other 50 | 23 | 40 … 41 | 52 |

Both candidates that beat the base by word count **emit four instructions too many** and are *worse*
content-aligned, so neither is an improvement. **Zero of 52 candidates is.**

## Why — and why that is the useful part

`p6` went from 86 to 98 under exactly this harness: its difference was a **shape** (a statement order, then a
temporary), and the permuter randomises shape. `osCreateThread`'s residue is **parameter-load scheduling and
register allocation** — M298's diagnosis, unchanged here. The randomiser's moves (temporaries, types, statement
order, same-line-ness) do not change which register the allocator picks, and the only way it found to move the
score was to add a temporary, which overshoots the function's size.

So the boundary is now measured rather than assumed:

> **The permuter is a shape search. It closes shape residues and does not touch allocation residues** — and the
> corpus's standing rule ("size is not what makes a function hard; allocation is") predicts exactly this split.

## A harness defect this exposed (worth more than the result)

`get_settings()` reads **`settings.toml`**, not `f.toml`. Every permuter run in this project — M256, M259, M300,
M302 — had its settings file under the wrong name, so **`compiler_type` was never read**: all of them ran on the
default `[base]` weights with the function name auto-detected. Two consequences:

- M300 recorded "two harness defects: `compiler_type` was `ido`, corrected to `gcc`". **That correction was
  inert** — the file was never opened, so both runs used `base` weights and M300's phrasing "under both
  weightings" is wrong: it was **one** weighting and **two objectives**.
- The M302 result stands unchanged (98/98 against the image), but its *cause* is stated more cleanly: the only
  variable that moved was the objective.

The file is now `settings.toml` in both harnesses, and this run is the first in the project where a non-default
weighting actually applied. It is worth noting that it did not rescue the allocation residue either.
