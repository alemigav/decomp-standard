# M238 — the sampler record decoded, and the six frames the decoder never sees

The next bank after id 1979 is id **1983**, the 9 MB sampler bank M184 framed (1 192 samples tiled exactly,
per-sample rates) and M189–M199 decoded. Its *codec* is not what this milestone moves: it is the **record**
around it, and one measurement that turns into a defect in the shipped decoder.

## 1. The 28-byte record, every field

```
u16 index   1..1192, sequential
u16 0       zero on all 1192
u32 offset  into id 1983, first 0, strictly ascending
u32 0       zero on all 1192
u16 15360   constant on all 1192   (0x3c00)
u16 rate    the 15 canonical rates M184 counted
u8  3       constant on all 1192   (codec / version)
u24 count   the true sample count, 43 .. 127 487
u32 f1      a position inside the sample
u32 f2      a position inside the sample
```

The count is a **u24 that starts at byte +17**, which is why the high byte of `u32@+16` reads as a 0/1 flag on
1 182/10 records: those ten are simply the samples longer than 65 535. Two fields are constant on the whole
bank — `15360` and the codec byte `3` — and two are zero on it.

## 2. The prefix is 16 bytes, not 256

Two independent measurements:

| | |
|---|---|
| stored length, mod 40 | **16 on 1192 of 1192** — every sample is `16 + 40*N` |
| legal frame headers at phase `p`, over 32 sampled clips | phase **16**: **89.7 %..100 %**; every other phase: **≤ 79.7 %** |

A predictor byte is legal when its high nibble indexes one of the codebook's 8 predictors and its low nibble
(shift bias) is ≤ 12. At the true phase almost every header is legal; at any other phase the count collapses to
what chance gives. So the frame grid begins **16 bytes** into every sample.

**And that is where the 256 came from.** The codebook at the file head is real — decoding a sample against the
head gives adjacent correlation > 0.7 on **49 of 50** sampled clips, against **0–32 of 50** for random 256-byte
slices taken elsewhere in the file, and 22 of 50 for the sample's own first 256 bytes. It is 256 bytes and it
sits inside sample 0's extent (sample 0's offset is 0). Since `256 = 6*40 + 16`, a decoder that skips 256 bytes
from *every* sample stays on the frame grid and silently **starts six frames late** — dropping
`6 × 64 = 384` samples from every sample after the first. That is what `sound_decode.py` does today.

## 3. What that skip hides

Frame 0's predictor bytes are frequently **illegal**:

| | count of 1192 |
|---|---|
| run 0's predictor illegal (high > 7 or low > 12) | **568** (353 of them `0xff`) |
| run 1's predictor illegal | **582** (all of them > `0x7f`) |

No run of the shipped decoder has ever seen either byte, because frame 0 is one of the six it skips. So the
**first frame of about half the bank is not a well-formed frame under the two-run reading** — and the reading
has never had to say so. Whether those bytes are damage or a different block form for that one frame is left
open; both counts are published rather than one interpretation.

## 4. `f1`/`f2` are positions, and are *not* loop points

Both are inside the sample (`f1 < count` on 1192/1192; `f2 ≤ count` on 1192/1192), which is what a pair of
sample positions looks like. But the loop reading does not survive:

- **1005** records carry the pair `(2, 0)` — a no-loop default, by far the most common state;
- of the **187** with `f2 > 0`, only **123** satisfy `f1 < f2`, and **64** do not;
- no ordering convention repairs all of them, so "loop start / loop end" cannot be asserted.

That is the honest state: two fields that *are* positions, a default that reads as "no loop", and a
disagreement count that keeps the semantics open. The seam test that would settle it is blocked on knowing
which order is which.

## 5. Two refutations that keep the 16-byte prefix open

What the 16 bytes *hold* is still unknown, and two natural guesses are refuted rather than left as
possibilities:

- **not a seed for frame 0's history**: prefix's last pair equals frame 0's first history pair on **2 of
  1191** samples — chance;
- **not a copy of the previous sample's bytes**: the 16 bytes appear literally inside the previous sample's
  extent on **0 of 63** checked.

## 6. The tool

`tools/smpdir.py` → `manifests/smpdir.json`, **10 cases**, 3 mutations (the prefix back to 256; the predictor
byte's low nibble unbounded; the count read as 16 bits). Not fixed here, and deliberately: changing
`sound_decode.py`'s prefix moves that suite's own numbers (1 180 and 658) and the codec fixture, so the fix is
its own change with its own re-derivation. This milestone is the measurement that shows the fix is needed, and
the numbers it has to preserve.

Not claimed: that `f1`/`f2` are loop points; what the 16-byte prefix holds; that frame 0's illegal predictors
are damage rather than a second block form; anything about how the samples sound.
