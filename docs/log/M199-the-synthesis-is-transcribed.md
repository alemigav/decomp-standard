# M199 — the voice synthesis is transcribed, and it agrees with the cartridge sample for sample

M198 got the audio by executing the cartridge's own code, because `FUN_800b6634` passes its arguments in
registers the pseudocode does not model. This milestone removes that dependency: the synthesis is
reimplemented in Python, and it is graded against the emulator rather than trusted — **13 clips, 634 blocks,
every sample identical**.

## The two defects, both found by breakpoint rather than by reading

**1. The taps were unsigned.** The kernels return `t & 0xFFFF`, and the cartridge unpacks each packed tap
with `sra` — a *signed* halfword. My lattice multiplied `65126` where the cartridge multiplies `-410`.
That is invisible while every tap is positive, which is exactly why the first frame of every clip was
bit-exact and everything after it was not.

**2. The shaper is three segments, not two.** Probed directly off K4 (`0x800b686c`):

| `|a|` | result |
|---|---|---|
| ≤ 11059 | `2a` |
| 11060 … 20070 | **`a + 11059`** |
| > 20070 | `(a>>2) + 26112` |

My reading had a plain doubling up to 20070 and the compression above it — right at the ends, wrong in the
middle, where a 11468 operand produced 22936 instead of 22527.

## What the transcription consists of

`tools/voice_decode.py` now carries the whole decoder: the bit reader (LSB-first inside big-endian 32-bit
words), the field map, `FUN_800b62c0`'s dequantisation and stride-3 scatter, the pitch predictor (latched
period, history shifted by 40, window read *after* the shift, 40 residuals per call), `FUN_800b4dc0`'s eight
affines and bank toggle (written, mixed, *then* flipped), and `FUN_800b6470`'s eight-stage lattice with its
interleaved updates, per-sample accumulator and the `& 0xFFF8` output.

Every one of those details was wrong in some earlier reading of mine. The ones worth naming, because they
are all "the loop runs one more time than it looks":

- band counts are `t3+1` = **13/14/13/120**, because `bgtz` tests the counter *before* the delay slot
  decrements it — so the 160 samples are contiguous, with no gaps at 12/26/39;
- the predictor appends **40** residuals, not 39, which is why the scatter table holds 40 entries;
- the accumulator is a halfword and truncates **once per block**, after all four bands.

## The gate

Two new cases compare the transcription against the emulator, block for block: clip 27 (26 blocks, 4 160
samples) and clip 2 (40 blocks, 6 400 samples), both **0 differ**. The suite is 9 cases and is
cartridge-gated, so a clone SKIPs it — and the tool says so loudly if no interpreter has the emulator.

## Six of my own probes were wrong, and that is the lesson

The breakpoint work cost more than the fix. Each of these produced a confident, wrong answer for a turn:
a `t3` read before the loop decrement (so "band counts are 12/13/12/119"); a screenshot taken *after* the
latch, so the lag was one call stale; a double sign-conversion that made equal values print as `-4294967344`
(a number I twice explained away as an artefact instead of fixing); a `spy[i]` compared against `cart[i]`
and printed as "after band i−1", a one-band mislabel that manufactured a "phase offset"; a hand-rolled
predict sequence that double-dequantised and produced three bogus "differences"; and an output read that
was compared against a history taken at a different moment.

The rule that finally worked: **verify the arithmetic in isolation first** — call the kernel, call the
lattice, with chosen inputs — and only then wire it into the composition. Every time I skipped that, the
pipeline lied to me in a way that looked like a real finding.

## State of the tree

`voice_decode.py --check` **9/9**; transcription verified on clips 0, 2, 5, 15, 22, 27, 40, 100, 200, 300,
434, 500, 587 (634 blocks, 0 samples differing); counts **36 suites / 454 cases**, of which 22 / 218 run
without the cartridge; audit **48/48, 0 vacuous**. No audio claim is new here — the same WAVs come out,
now from a decoder that does not need an emulator to produce them.

## Appendix — the two dumps the transcription was debugged with

These were stdout from throwaway probes and were not kept, which was a mistake: they are the evidence for
the last two turns of debugging. Regenerated after the fix and recorded verbatim. Every line now matches —
including block 14's hand-off into block 15, which is exactly the line that showed the defect (it read
`[21, 10, 3, -1, 5, 6, 3, 13] acc=144` against the cartridge's `[25, 11, 1, -1, 5, 6, 4, 16] acc=152`
before the shaper's middle segment was found).

```
=== clip 2, block 13: state at all four band entries ===
  band 0 entry  s=[-3, -1, -1, 4, 20, 1, -5, -10]                acc=-38
  band 1 entry  s=[-8, -16, -17, 17, 4, 28, -4, 22]              acc=-22
               mine after band 0  [-8, -16, -17, 17, 4, 28, -4, 22]  acc=-22  MATCH
  band 2 entry  s=[21, 24, 2, 35, 8, 16, -19, -18]               acc=129
               mine after band 1  [21, 24, 2, 35, 8, 16, -19, -18]  acc=129  MATCH
  band 3 entry  s=[40, 1, -74, 30, -4, 35, -10, 39]              acc=78
               mine after band 2  [40, 1, -74, 30, -4, 35, -10, 39]  acc=78  MATCH
  hand-off into block 14: cart [-37, -53, 35, -34, -18, 11, -18, 8] acc=-140
                          mine [-37, -53, 35, -34, -18, 11, -18, 8] acc=-140  MATCH

=== clip 2, block 14: state at all four band entries ===
  band 0 entry  s=[-37, -53, 35, -34, -18, 11, -18, 8]           acc=-140
  band 1 entry  s=[-90, 4, -9, 44, -23, 10, 0, -4]               acc=-216
               mine after band 0  [-90, 4, -9, 44, -23, 10, 0, -4]  acc=-216  MATCH
  band 2 entry  s=[-11, 8, -14, 6, -12, -6, -4, -24]             acc=-100
               mine after band 1  [-11, 8, -14, 6, -12, -6, -4, -24]  acc=-100  MATCH
  band 3 entry  s=[56, -28, 54, 14, -52, 18, -11, -14]           acc=137
               mine after band 2  [56, -28, 54, 14, -52, 18, -11, -14]  acc=137  MATCH
  hand-off into block 15: cart [25, 11, 1, -1, 5, 6, 4, 16] acc=152
                          mine [25, 11, 1, -1, 5, 6, 4, 16] acc=152  MATCH
```

Reproduce with two commands, added in M199 for exactly this reason:

```sh
python3 tools/voice_decode.py --diff 27                 # 26 blocks, 4 160 samples, 0 differ
python3 tools/voice_decode.py --dumps 2 --block 14      # the table above, from the cartridge
```

`--diff` compares the transcription against the emulator sample for sample and exits non-zero on any
difference; `--dumps` prints the cartridge's band-entry states for one block. The differential gate in
`--check` runs the same comparison on clips 27 and 2, so a regression shows up there rather than in a probe.

