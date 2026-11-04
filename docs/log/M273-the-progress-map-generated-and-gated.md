# M273 — the progress map: generated, gated, and honest about being mostly empty

The instruction was to add something to the README that visualises progress — "a block map, or other". This is that,
done the way the rest of the project is done: **generated from the fixtures, and checked by a gate**, because a
hand-drawn chart in a repository whose whole claim is *no number in the docs is a habit* would be a habit with
better typography.

## 1. What it shows

Two panels in one fenced block, wrapped in `<!-- progress-map:begin -->` markers so it can be regenerated in place.

**The cartridge** — one row per image, one cell per group of functions, 58 cells wide:

```
stage2       1911│▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒██▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒│
3638 functions across 36 images · █ 4 reproduced byte-for-byte (0.11%) · ▓ 1 recovered, residue itemised
█ matched byte-for-byte   ▓ recovered, not exact   ▒ pseudocode body only (not yet evidence of a match)
```

The shading is deliberately the **matching** question, not the "has a decompiled body" question — all 3 638
functions have a body, and every one of them has had it since the corpus was generated (M209's point about
"3 638 decompiled" being one claim and not four). So a cell is bright only where a function has been **reproduced
from the disassembly and recompiled to the byte**, and the map's most useful property is that it is honest about
being mostly grey: four bright cells out of 3 638, all in `stage2`, which is exactly where the recovered functions
are.

**The record** — one bar per phase, and the bars are read from **the README's own phase table**, so the picture
cannot drift from the table beside it:

```
P15  M231│████│ 20
P16  M251│████│ 22
```

## 2. Why generated

`tools/progress_map.py` reads `manifests/code_index.json` for the per-image function lists, and holds one table of
recovered functions whose *evidence* is the probe: each entry names the case in `tools/compile_probe.py` that
asserts it. `--check` fails if the README's block differs from what the fixtures produce, and also fails if any
claimed function is **not in the corpus** — so the map cannot invent progress, and cannot silently fall behind it.

It is wired as a **repository-only** suite (`progress map (repository)`, 1 case), so it runs in CI without the
cartridge. Suite counts moved with it: 72 suites, 993 cases, 31 runnable.

## 3. What went into the numbers

| | |
|---|---|
| functions in the corpus | 3 638 over 36 images |
| reproduced byte-for-byte | **4** — `0x8004fd1c` (98 words), `0x80057e1c` (84), `0x80070120` (46), `0x80059868` (167) |
| recovered, residue itemised | **1** — `0x80024558` (136 of 139) |
| everything else | a pseudocode body, awaiting the same treatment |

## 4. A note on what the map argues

The bottom panel exists because the top one is discouraging in isolation: four cells from 3 638 reads as "nothing
has been done", when in fact the *hard* part — identifying the compiler, the assembler, the cpu flag, the two
constant-pool behaviours and the aliasing rule that decides instruction order — was done in M245–M265 and is what
made four functions fall out at all. The phase bars are the counterweight: the work is 16 phases deep, and the
matching phase (P16) is the most recent and the densest.

That tension is worth showing rather than resolving: **the map's grey area is the honest size of the remaining
task, and the bars are the honest size of the road already walked.**
