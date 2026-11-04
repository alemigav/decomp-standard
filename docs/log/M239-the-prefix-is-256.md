# M239 — the prefix is 256 after all: M238's central claim was wrong, and the patch it implied must not be made

The instruction was to patch `sound_decode.py` to a 16-byte prefix and then chase the frame-0 anomaly. Chasing
it first is what stopped the patch: **the prefix is 256, the patch would have broken the decoder, and there is
no frame-0 anomaly** — bytes 16..255 were never frames. This note is the retraction.

## 1. What fooled me

Every stored length is `16 (mod 40)`. That is true, and it is *also* what `256` looks like, because
`256 = 6*40 + 16`. So the measurement M238 leaned on — "the frame grid is at phase 16" — **cannot separate
16 from 256**: they are the same phase class. I reported a phase test as if it decided the prefix, and it does
not. The tell was there and I read past it: under the 16-byte model the slack between the frame grid and the
declared count came out `122..519` with one sample needing a *different* prefix from the others; under 256 it
is `72..135` for all 1192. A model that has to make an exception for sample 0 is the wrong model.

## 2. What decides it: legality by frame index

A predictor byte is legal when its high nibble indexes one of the book's 8 predictors and its low nibble is
≤ 12. Anchoring a grid at `+16` and counting illegal predictor bytes **by frame index** across all 1192
samples:

| frame index | bytes | illegal predictor runs |
|---|---|---|
| 0 | 16..55 | **48 %** |
| 1 | 56..95 | **52 %** |
| 2 | 96..135 | **42 %** |
| 3 | 136..175 | **55 %** |
| 4 | 176..215 | **39 %** |
| 5 | 216..255 | **49 %** |
| **6** | **256..295** | **0 of 2384** |
| 7..11 | 296..495 | **0 of 2384** each |

A step from ~50 % to exactly zero at `+256`. The first six slots are **not nibble frames** — they are raw
`int16`, which is why their "predictor bytes" are the high bytes of small signed values (`0xff` ×353, `0xfe`
×79, `0xfd` ×32 …) and why, read as `int16`, they correlate at **0.732** with themselves against **0.062** for
nibble data read the same way.

So `sound_decode.py`'s `stored[256:]` is **correct**, and the "frame 0 anomaly" M238 reported is an artifact of
numbering frames that do not exist.

## 3. The 256-byte block is not audio either

Having established what it is *not*, three measurements on what the block is:

| | |
|---|---|
| magnitude of its 128 `int16` | median **397**, p99 **9 069**, max **17 696** |
| the decoded audio's peak | **32 768** (median over 50 clips, and max) |
| best correlation with the clip's decoded **head** | **0.419** |
| best correlation with the clip's decoded **tail** | **0.465** |
| correlation with itself when read as `int16` | **0.732** |

Values that never approach full scale, and no relationship to the clip's own signal at either end: it is a
**per-sample parameter block**, not stored audio. Its 16-byte sub-header plus 240 bytes mirrors the codebook's
8 × 32-byte record layout, which is a shape worth testing and is **not** claimed here.

## 4. What stands from M238

The record layout, unchanged and still gated: `u16 index, u16 0, u32 offset, u32 0, u16 15360, u16 rate, u8 3,
u24 count, u32 f1, u32 f2`, with `15360` and the codec byte `3` constant on all 1192 and the count a **u24
starting at byte +17**. The loop fields still refuse to be loop points (**1005** records carry `(2,0)`; of the
**187** with `f2 > 0`, **123** are ordered and **64** are not). The block is still not a seed (2 of 1191) and
not a copy of the previous sample (0 of 63).

## 5. What changed in code

- `tools/smpdir.py` — rewritten to the 256 model: the phase sweep (which cannot decide) is replaced by the
  frame-index legality census (which does), the slack is `72..135` on 1192, and the block's magnitude and
  head/tail correlations are derived as evidence rather than asserted. 10 cases, 3 mutations, re-aimed: the
  grid counted from 16 bytes, the census anchored at the block instead of the 16-byte sub-header, and the count
  read as 16 bits. Mutating `BLOCK` itself was tried and rejected — it crashes the 128-`int16` read, and a
  mutation that crashes proves only that the code is fragile.
- `tools/sound_decode.py` — **no behaviour change**. A comment now records why the 256-byte skip is right and
  what the block is not, so the next reader does not re-derive M238's mistake. Its own gate is unchanged at
  7/7 and its numbers (1 180 shared / 658 own) are untouched.
- `manifests/smpdir.json` regenerated; the wrong numbers are gone.

## 6. The lesson, stated for the record

I published a retraction-class claim on a measurement that was **insensitive to the distinction it was being
used to make**. `stored % 40 == 16` and "the grid starts at 16" are not the same statement, and the second does
not follow from the first. The census that decides it — legality by frame index — was one loop away and would
have cost five minutes; instead it cost a milestone. The check that would have caught it is now in the tool: a
case asserts the step at `+256`, and the one-sample exception under the 16-model is written into the artefact
as the reason the model is wrong.
