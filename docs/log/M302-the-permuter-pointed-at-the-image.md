# M302 — the permuter, pointed at the image, closes the function: 94/98 was the objective, not the tool

M300 left one question open — *"whether rebuilding `target.o` from the image's own 98 words moves the 94/98
ceiling"* — and called it one command. It was, and the answer overturns M300's own conclusion.

## What was built

`fixtures/permuter/p6/make_target.py` builds the permuter's objective **from the cartridge**: it reads the
function's 98 words out of the stage-2 image, assembles them through `.word` directives (so the assembler cannot
"improve" anything), and then **verifies the object's `.text` is byte-identical to the image** — 392 B, checked,
not assumed. Two implementation facts worth keeping:

- a raw `objcopy -I binary` object **does not disassemble** (no ELF arch flags), so the words go through `gas`
  and the section is then trimmed with `--update-section` — `as` pads `.text` out to its 16-byte section
  alignment, which is 400 B rather than 392;
- the object is **deliberately not committed**: it is 392 bytes of the cartridge's code. `make_target.py`
  regenerates it, and `.gitignore` now un-ignores exactly one `.o` in that directory — `target-draft.o`, which
  is *ours*, and which is the evidence that the old objective was a proxy.

## The result

| run | objective | iterations | best by the word metric |
|---|---|---|---|
| M259's pool (82 candidates) | draft proxy | — | 94 / 98 |
| M300 re-run (`gcc` weights) | draft proxy | 144 310 | 94 / 98 (16 candidates, none at 98) |
| **M302 run** | **the image's 98 words** | 83 834 | **98 / 98** |

The permuter's own score fell from 1790 to 320 on the way, and the byte metric confirms it: of 25 candidates,
**one is byte-exact**, one is 97, two are 95, four are 94. The winner:

```
base.c                86 / 98
candidate-image-310-1 98 / 98   (98 identical by offset, 98 by content, 1 hunk, 0 extra words)
```

**And it is a different shape from the hand reconstruction.** M255–M257 spent three milestones discovering that
the fix was to swap two statements inside case 4's braces; the permuter, with the right objective, found a
different route — it keeps a **`new_var` temporary** (`new_var = s->b1; … s->b1 = new_var + s->b2;`) where the hand
solution transposed the two statements. Two different C sources, the same 98 words. That is the ordinary reality
of matching decompilation, and it is worth stating plainly: **"the" reconstruction is not unique, and a search
that is pointed at the real target will find shapes a human did not consider.**

## What this retracts

**M300's conclusion — "the permuter cannot reach this shape by randomisation; the last four words are an order
swap the shape solver reaches in nine variants" — is wrong.** The tool reached it in 83 834 iterations, which is
one to two minutes of wall clock on eight cores. What the permuter could not reach was a **stale target**: a
116-instruction object compiled from an earlier draft, with unresolved relocations, standing in for a 98-instruction
function. Every earlier statement of the form "the permuter's ceiling is 94/98" describes the *proxy*, and M299's
re-score inherits the same limit — its numbers (base 86, best 94) remain correct as measurements of that pool
against the image, but "the pool held improvements the project never took" understates it: the pool was
improvements *of a proxy*.

The lesson is M259's own, arriving from the other side: **a tool's verdict is only as good as its objective**, and
the objective was never committed, reproducible, or the ROM.

## Numbers

- compile probe **47 → 49 cases** (49/49 pass): one re-aimed at the draft proxy (still 116 words), one new for the
  image objective (98 words, byte-identical, no relocations), one new for the byte-exact candidate
- `fixtures/permuter/p6/`: **+3 files** (`make_target.py`, `candidate-image-310-1.c`, `target-draft.o`),
  `scores.json` now carries both runs and the verdict
- suites, tools, functions, fragments, coverage: unchanged — **73 suites / 1 024 cases**, 100 tools,
  3 416 functions / 1 211 256 B
