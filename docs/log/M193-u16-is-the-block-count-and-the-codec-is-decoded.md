# M193 — `u16@+4` is the block count, and the pool codec is decoded

The two questions this thread has carried since M179 are both answered. One of them arrived from outside:
**re2studio**, a GPL-3.0 RE2 N64 romhacking suite, documents both sound codecs — and every fact taken from
it was then confirmed against this cartridge, not adopted on its word.

## 1. `u16@+4` is the `MORT` clip's block count

The header is **16 bytes**, and its fourth field is the length:

| offset | field | evidence |
|---|---|---|
| +0 | `MORT` | 588/588 |
| +4 | **block count** | 26–7 647; 160 samples per block |
| +6 | rate | 588/588 in {16 000, 8 000} |
| +8 | **clip length ÷ 4** | **588/588** — and the reason every record length is divisible by 4 |
| +16 | the bit stream | a 12-byte prefix is skipped, then 1-bit selector runs |

That closes the field M179 opened, and it explains the number I could not: a **normal block is a fixed 260
bits**, and 260/8 = **32.5 bytes**. The ceiling I measured at 32.5 in M189 *was* 260 bits per block. The
continuous ratio below it is the silent runs — a 4-bit length can encode up to 16 silent blocks.

Verified as a bound rather than a guess: no clip's payload exceeds `12 + 32.5·blocks` by more than **20 B**
(a partial final block plus the four-byte pad).

**M189's 12-byte header is retracted.** The alignment test could not distinguish 12 from 16 — both satisfy
`(len − h) % 4 == 0` — and the `0000 4e8a` I saw at +8 in M178 was `0x4E8A = 20 106 = 80 424/4`, which I had
recorded as "a field taking 65 values" without reading it.

## 2. The pool codec is decoded — and my prelude reading was wrong

The sample data is `[256-byte codebook] then N × 40-byte frames`, where a frame is two runs of
`2 raw int16 + 15 nibble bytes`, decoded as

```
y = clamp16((a1*prev1 + a2*prev2 + (delta << 11)) >> 11),   delta = sign_extend(nibble) << (12 - stored)
```

with `a1`, `a2` read from the codebook — `a2` at `p*32`, `a1` at `p*32+16` for predictor `p`.

`tools/sound_decode.py` implements it (independently, in Python, from the description) and the gated result
is audio, not merely numbers:

| | |
|---|---|
| samples decoding to adjacent correlation > 0.7 | **1 180 of 1 192** |
| median adjacent correlation | **+0.901** |
| decode never shorter than the declared length | **1 192 of 1 192** |
| clipping | 0.01 % |

**And the codebook is shared by the bank, not per sample.** This is the discriminator that makes the decode
a measurement rather than a plausible reconstruction: decoding each sample with **its own** first 256 bytes
gives only **658** good, against **1 180** with the one at the head of the blob. So the bytes I called "128
raw big-endian int16 samples" in M190 and M192 are the codebook — the byte census that looked like PCM was
coefficient magnitudes — and **the per-sample copy is not what the decoder uses**.

## 3. The directory's unnamed fields are named

The 28-byte record, as the player reads it:

| offset | field |
|---|---|
| +0 (>>16) | index |
| +4 | byte offset into the sample blob |
| +12 (& 0xFFFF) | rate |
| **+16 (& 0x00FFFFFF)** | **declared length in samples** |
| **+20** | **loop start** |
| **+24** | **loop end** |

M185 called `+6`, `+16`, `+18`, `+22`, `+26` "a census, not laws". Three of them are now laws, and the
declared length is validated by the decoder: it never exceeds what the frames produce, on 1 192 of 1 192.

## 4. What is still open, stated exactly

* **The voice codec's algorithm.** Its decoder is `FUN_800b53f4`, **which is in our corpus**, and the format
  is described but not implemented here: a 1-bit selector, 7-bit normal and 4-bit silent run lengths, eight
  scale fields of 6/6/5/5/4/4/3/3 bits, and four groups of four side values (7/2/2/6 bits) plus thirteen
  three-bit coefficients. Implementing it is the next step, and it needs no table from anywhere — the
  coefficients are **in the stream**.
* **12 of 1 192 samples** do not decode cleanly. They are not explained.
* **What the pool's four key classes mean** (M188).

## 5. Gates

New suite **`sound decode (cartridge)` — 5 cases**: the shared-book result, the per-sample-book refutation,
the decode-versus-declared reconciliation, the codebook's size and position, and the codebook not being
sparse padding. `file table (cartridge)` **81 → 83**: `u32@+8 == length/4` on 588/588, and the block-count
bound. The fixture `fixtures/sound/codec.json` now carries both codecs' constants and is asserted against
the cartridge.

Two of my own errors were found by running the gates rather than by reasoning: `offs[:-1]` was slicing a
*real* record because a later block re-binds `offs` to 588 starts rather than 589 ends — the same slice bug
as M189, now removed everywhere — and the block bound is 20 bytes, not 16.

Audit **44/44, 0 vacuous**; ratchet refused the increases until `--write`. Attribution: **re2studio is
GPL-3.0 and none of its code is used**; the facts are cited in `THIRD_PARTY.md` and each is confirmed here.

Repository is **34 suites / 427 cases**, of which **13 suites / 215 cases** are cartridge-gated, so the
runnable tier is **21 suites / 212 cases**.
