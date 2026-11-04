# M299 — the re-score: M259's verdict was measured against a base that no longer exists, and the solver that follows

Two things, in the order asked. Re-scoring decomp-permuter's M259 candidates overturned a recorded conclusion — not
because the permuter changed, but because **the inputs to that conclusion were never committed**. Then the shape solver
was built, and it closed a function on its first run.

## 1. The re-score

All 82 surviving candidate directories in `build/permuter/p6/` were compiled through the canonical pipeline and scored
with the byte metric — `.text` at `0x8004fd1c`, `.rodata` at the table, word compared against the image — the same way
the probe scores p6:

| source | offset-identical | content-aligned | hunks |
|---|---|---|---|
| `base.c` | **86 / 98** | 90 | 8 |
| best candidate (`output-1780-1`, `-1780-2`, `-1880-3`, `-1980-3/5/7/8/26`) | **94 / 98** | 94 | **4** |
| probe's `P6_SOURCE` (control, for the scorer) | **98 / 98** | 98 | 1 |

**19 of 82 candidates beat the base by eight words.** M259's headline was the opposite — base 28/98, candidate 28/98,
"a 10% score gain that moved zero words". So the two measurements disagree, and the reason is not the permuter:

- `base.c` today differs from the byte-exact `P6_SOURCE` by **one line** — the order of `s->b0 = 131;` and
  `s->b1 = s->b1 + s->b2;` inside case 4's braces — and that one transposition costs 12 of 98 words (86 against 98). A
  base at 28/98 was a *different, much rougher* draft.
- `build/` is gitignored, and the file timestamps show the whole directory was rewritten later (`base.c` 15:47,
  candidates 15:50). **The base M259 measured no longer exists anywhere in the repository.**
- The two candidate explanations that could have bridged it were tested and refuted: the assembler flag makes no
  difference here (`base.c` scores 86/98 with and without `-g`), and reverting the two compiler patches (M291 per-use
  doubles, M292 unsplit float addresses), rebuilding `cc1` and re-scoring also changes nothing (86/98, 94/98 both times).

**So M259's verdict is unreproducible rather than wrong-by-measurement**: it may have been correct for the draft it saw.
What this re-score establishes is the thing that matters for the plan — **the permuter's candidate pool contained
genuine, word-level improvements of the current base (86 → 94)** that the project never took, because the verdict closed
the route. And the correct fix for *both* problems is the same: score with the byte metric, and commit the outputs.

## 2. The solver

`tools/shape_solver.py` automates the loop the project has been running by hand: enumerate *shape* variants of a draft,
compile each, score by words identical to the image, rank. Two variant sources, and the second is generic:

- `--rules f.json` — `[{"name":…, "old":…, "new":[…]}]`, one variant per option, plus pairwise combinations;
- `--permute-stmts` — every adjacent transposition of statements, **including statements that share a line inside
  `{ … }`**.

**Its first run closed a function.** Given `base.c` (86/98) as the draft, it enumerated nine variants and found the one
that is byte-exact:

```
variant                                offset-aligned  content-aligned  hunks
base                                   86/98           90                8
braces swap s->b0 = 131 | s->b1 = s->b1 + s->b2   98/98   98           1
perm swap L13/14                       75/98           82               12
…                                       …
```

Two defects of the tool itself were exposed by that run and fixed, both worth recording because they are the same class:

1. **lines are not statements.** The first version only swapped whole lines; p6's two misplaced statements share one
   line inside `{ … }`, so the exact shape was unreachable until the generator split on `;`.
2. **a rejoined block must keep its terminating semicolon.** `"; ".join(parts)` dropped the last `;`, cc1 rejected the
   variant, and the scorer silently returned `None` — the search reported the base as best because the winner did not
   compile.

It is registered as a repository suite (`shape solver (repository)`, **6 cases**, all pure-Python: what the generator
enumerates), so CI can run it without a cartridge; the scoring half needs one and is exercised through the probe.

## 3. State, and what this changes

**73 suites / 1020 cases** (from 72/1014), 100 tools, corpus unchanged at 45 cases all passing, map unchanged at
`3416 functions · █ 15 reproduced byte-for-byte · ▓ 1 recovered`.

The important shift is methodological. The project's cost per function has been *human*: one shape tried per attempt, and
~25 shape facts discovered one at a time. The solver turns that catalogue into a search — and the p6 demo shows what the
loop is worth: **the shape that took M255–M257 three milestones to find is one of nine variants a script can compile and
rank in seconds.**

Next, in the order that follows from this: (a) re-run decomp-permuter itself with the byte metric as its objective and
**commit its candidate directories**, since the M259 pool was worth 8 words and was thrown away; (b) point the solver at
the two live residues (`0x8007e590` 226/229, `osCreateThread` 23/52) with the rule file built from the catalogue.
