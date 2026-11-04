# M6 — the ROM→VRAM mapping is not a stored table (three hypotheses eliminated)

2026-10-30. Following M5, the goal was: resolve the bank containing ROM `0x16264DD`,
then read its descriptor list. **The premise was wrong**, and the eliminations are worth
more than a forced answer.

## Correction to M5: there is no caller at 0x16264DD

`0x16264DD % 4 == 1`. MIPS instructions are 4-byte aligned, so a `jal` cannot start
there. The bytes were:

```
aligned word @0x16264DC = 0x700C0030
aligned word @0x16264E0 = 0xFC02A257
```

My whole-ROM search matched the 4-byte `jal` encoding *at any byte offset*, which of
course finds coincidences inside data and inside longer instructions. **The one reported
call site was a false positive.**

Corrected position: **both DMA routines (`0x800077A0`, `0x8000C3F0`) have zero direct
callers anywhere in the 64 MB.** All dispatch to them is through function pointers —
consistent with the libultra device-manager design and with the 84-slot dispatch table
found at `0x128B8`.

Any future byte-pattern scan must assert `offset % 4 == 0` and, where possible, that the
surrounding words decode as plausible MIPS.

## Hypothesis 1 eliminated: no (rom, vram) descriptor table

Scanned all 16.7 M words for increasing runs of ≥6 records where one field is a ROM
offset (`0 < x < 0x4000000`) and the other a VRAM pointer (`0x80000000–0x803FFFFF`),
across **strides 2, 3 and 4 in both orders**. Result: **0 candidates.**

## Hypothesis 2 eliminated: no file-size table

Scanned for contiguous runs of ≥32 words all below 2 MB (a size ceiling), on the theory
that offsets are the cumulative sum. Four large runs surfaced — and all are **structured
game data, not sizes**:

| ROM offset | words | pattern |
|---|---|---|
| `0x0B782C` | 509 | `0x16100, 0x1DC00, 0x21700, …` repeating in threes |
| `0x0BED40` | 373 | repeating pairs `0x1BC00, 0x3F300, …` |
| `0x0B6C70` | 317 | repeating triples, same shape |
| `0x0C8654` | 300 | alternating large/small — offset,count pairs |

The periodic repetition is decisive: a file table would not repeat the same three values
hundreds of times. These are object/room parameter arrays.

## What remains — and it changes the plan

The mapping is very likely **not stored at all**: N64 ROMs frequently embed the triple
`(cartAddr, vramAddr, length)` as immediates at each load site, because the linker fixed
the addresses at build time. If so, the map has to be recovered from **code**, not data.

That makes the next step a code-search problem, and the indirect dispatch means `jal`
scanning will not find the sites. What will:

1. Find the **device-manager table** in the boot bank (`0x80012910`-ish, indexed by the
   device handle at `lbu 9(s0)` in `0x800077A0`) — it holds the function pointers used for
   dispatch, and reading it names the real entry points.
2. Then find code that *loads DMA argument registers* and calls through those pointers —
   i.e. look for `lui/ori` pairs building a `0x80xxxxxx` destination plus a length
   immediate near an indirect `jalr`.
3. Only after that will the (cart, vram) pairs become visible, one load site at a time.

## Status

Bounds and structure are established (M1–M4); the mapping mechanism is now known to be
code-embedded rather than tabular. That is a real narrowing, not a dead end — but it means
the next phase is per-bank code analysis, which is the expensive kind. Worth a fresh
context window before starting it.
