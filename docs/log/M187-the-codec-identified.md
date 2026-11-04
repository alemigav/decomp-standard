# M187 — the codec is identified: MusyX ADPCM, with a 16-byte prologue

M184 recorded the per-sample codec of id 1983 as a named gap, with the ranges and rates needed to test any
claim about it. A third-party claim arrived — **MusyX's own ADPCM**, 32 samples per 20-byte frame, two
frames per 40-byte group laid out `[A.raw 4][B.raw 4][A.nib 16][B.nib 16]` — carrying two predictions. One
is **refuted as stated**; the other is **confirmed at 97.58 %**.

It was tested against the 1 192 real ranges, not against synthetic data.

## 1. The length prediction is refuted, and the refutation is informative

The claim predicts `len % 40 == 0` (or 20) for nearly all ranges, with a gcd of 20 or 40. Measured:

```
len % 40 == 0 :     0 / 1192
len % 40        :  16, for all 1192
gcd of the 1192 lengths : 8
```

So the test as written **would have rejected this data**. But `len ≡ 16 (mod 40)` on **1 192/1 192** is not
noise — it is a **16-byte prologue** followed by whole 40-byte groups. And the prologue is not a header:

| byte positions | distinct values over 1 192 samples |
|---|---|
| even (0, 2, …, 14) | **at most 51**, dominated by `0x00` and `0xFF` |
| odd (1, 3, …, 15) | **at least 234** |

That is the signature of **eight big-endian int16 samples** — the 16 bytes are audio, not fields. So the
frame layout in the claim is right and its arithmetic is off by one prologue.

## 2. The structure prediction is overwhelming

Folding at 40 with phase 16 and requiring the high nibble of both codebook bytes to be ≤ 7, over every
non-silent group:

| phase | groups passing |
|---|---|
| **16** | **219 550 / 224 991 = 97.58 %** |
| 0 | 129 452 / 224 999 = 57.53 % |

Chance is 25 %. At 224 991 groups the binomial floor is about 10^−135 000, and the phase-0 row is the
alignment control: the same test one prologue earlier collapses to 57.5 %, which is what a correct
structural test looks like when it is deliberately misaligned.

## 3. The raw pairs are samples, and they behave like samples

The four bytes at each group's head are two big-endian int16 output samples, so adjacent values must
correlate:

| | median adjacent correlation over 400 samples |
|---|---|
| as stored | **+0.378** |
| same values shuffled | **−0.004** |

## 4. The remainder, stated

**5 441 of 224 991 groups (2.42 %)** fail the codebook test. They are **scattered**: **0 of 1 192** samples
has a majority failing, so there is **no second codec class** hiding in the pool — which is what the
"voice uses a stronger codec" story would have predicted and does not get.

What those 2.4 % are is not established. Candidates: frames whose codebook byte is a raw/silence marker,
or an encoder path that does not constrain the nibble. They stay open and named.

## 5. What this changes, and what it does not

* **Identified**: the sample pool is **MusyX ADPCM with a 16-byte prologue of 8 uncompressed samples**,
  established by structure on real bytes, not by attribution.
* **Not decoded**: no range has been *decoded* to PCM here. The claim's decoder is bit-exact against an HLE
  reimplementation on synthetic trials, but nothing in this repository has decoded an RE2 sample, and the
  HLE is a reimplementation rather than documentation. Identifying a format from its structure and
  reproducing its output are different claims, and only the first is made.
* **Still open**: `u16@+4` in id 1979 (M179/M182), the 2.42 % of groups, and the two single key holes
  (M185's `11`, M186's `531`).

One thing the claim asserted that measurement does not support: the **9-byte VADPCM** frame is not involved
here — `len ≡ 16 (mod 40)` leaves no room for it — so "MusyX's own ADPCM, not Nintendo's VADPCM" is right
about this pool rather than merely asserted.

## 6. Gates

`file table (cartridge)` **53 → 59**: the length refutation *as stated* together with the ±16 correction
and its gcd, the prologue's byte census, the 97.58 % structure figure with its phase-0 control, the
raw-pair correlation against a seeded shuffle, and the scattered 2.42 % with the zero-second-class bound.

Both the refutation and the confirmation are gated together on purpose: a claim can be wrong in its
arithmetic and right about the codec, and a gate that recorded only one of those would misrepresent what
was checked.

Audit **44/44, 0 vacuous**; ratchet refused `53 → 59` until `--write`; counts derived and asserted in
twelve places.

Repository is **33 suites / 391 cases**, of which **12 suites / 186 cases** are cartridge-gated, so the
runnable tier is **21 suites / 205 cases**.
