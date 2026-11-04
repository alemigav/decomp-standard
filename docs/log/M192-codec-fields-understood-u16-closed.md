# M192 — the codec's header fields are understood, and `u16@+4` is closed with its reason

Two threads. The codec gave up its last two fields; `u16@+4` gave up the last explanation that would have
made it assignable.

## 1. The codebook's fields are no longer just "in range" — they are semantic

M191 showed the two header nibbles take the right *ranges*: codebook index 0–7 (all used) and shift 0–12.
That is a weaker claim than it sounds, because ranges can be satisfied by accident. Three predictions turn
them into meanings, and all three hold.

**(a) The 30 nibbles are signed residuals.** If they are 4-bit deltas, their histogram must be a Laplacian
tent around zero. Over **6 538 320** nibbles:

```
value  0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15
   %  16.6 13.6  9.6  6.7  4.0  1.9  0.9  0.9  0.2  0.4  1.0  1.9  4.0  6.7  9.6 14.4
```

Peaks at **0 and 15** — 0 and −1 — and decays symmetrically to **0.22 %** at the far end. That is a residual
distribution, not a sample distribution, and it is what the `[A.nib 16]` field is *for*.

**(b) The shift scales the frame.** If the low nibble is an exponent that normalises the frame, it must track
amplitude. Measured over all 435 888 blocks, the median `|raw|` of the frame falls monotonically with the
shift across the nine shifts that carry real weight:

| shift | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|---|
| median abs(raw) | 10 338 | 6 946 | 5 121 | 3 494 | 2 289 | 1 547 | 936 | 428 | 260 |

correlation **−0.407** over all 217 944 frames. The gate asserts monotonicity over those nine and not over all
thirteen, because above 8 the sample count collapses — asserting thirteen would be asserting sample size.

**(c) The frame boundary is real, and it sits between the two raw pairs.** This is the sharpest test in the
whole thread. `[A.raw 4][B.raw 4]` predicts two *adjacent* sample pairs separated by a frame boundary, so:

| pair | correlation |
|---|---|
| `corr(A0, A1)` — within frame A's raw pair | **+0.816** |
| `corr(B0, B1)` — within frame B's raw pair | **+0.813** |
| `corr(A1, B0)` — across the boundary | **−0.001** |
| `corr(B1, next A0)` — across the group boundary | **−0.006** |

Two pairs correlate at 0.81 and the two crossings correlate at zero. The 4-byte blocks are sample pairs, the
boundary is where the layout says it is, and the group boundary is real too. This also explains why the
pooled figure M187 quoted was only +0.298: that number averages the within-pair and cross-boundary edges
together, diluting a 0.81 with a 0.00.

**And the 256-byte prelude is audio, not a codebook.** It is *exactly* the size a "128-entry int16 table"
would be, so M190's reading deserved a real test rather than the byte census it had: adjacent correlation
**+0.731** against −0.004 shuffled, **0 of 1 192** preludes monotone in magnitude, 127 distinct values. A
table would be sorted or near-sorted; this is a waveform. The size coincidence is arithmetic.

## 2. `u16@+4`: the last explanation is now tested, and it fails too

M191 closed the field as unassignable and named the surviving reading — a **frame count**. The obvious repair
after that is "then the payload should be frame-structured, and the frame size should be visible in it". It
is not:

* **No byte-aligned frame period exists.** For every period `F` from 4 to 64, the entropy of the bytes at
  positions `≡ 0 (mod F)` differs from the rest by at most **0.0011** at F = 16/20/32/40/59, and the maximum
  over the whole range 4–64 is **0.003**. There is no periodic structure of any byte width.
* **Byte `+10` is not a mode selector.** It takes 65 values, so the natural hope was that it selects a codec
  mode and explains the ratio spread. Within each of its frequent values the `payload/field` span is still
  **≥ 16.7 bytes** — the full 8.7–32.5 range survives inside every mode.

So if `u16@+4` counts frames, those frames are **bit-aligned**, which is exactly why `payload/field` is
continuous and never integral: a frame of *n* bits averages to a non-integer number of bytes. That is a
consistent story and it is not a measurement.

For the record, with the pool's own durations as the only available yardstick (median **0.562 s**, max
12.29 s):

| reading of `u16@+4` | median duration | max |
|---|---|---|
| milliseconds | 0.347 s | 7.65 s |
| 32-sample frames | 0.705 s | 15.3 s |
| 64-sample frames | 1.410 s | 30.6 s |

All three are plausible for a voice bank; the pool's median sits between the first two; **nothing here
separates them.** The field stays unassigned, and the closing statement is now the full one: it is refuted as
a note, a duration (twice), a sample count, a loop point, a bitrate ladder and any exact ratio of payload; the
payload has no byte-aligned frame for it to count; no CPU path reads it; and the voice codec is unknown, so
there is no calibration. **Decoding the voice codec is the only remaining lever, and it needs the tables that
are not in the cartridge data.**

## 3. Gates

`file table (cartridge)` **75 → 81**: the nibble tent with its peak values and decay, the shift's monotone
scaling over the dense shifts, the within-pair versus cross-boundary correlations, the prelude as audio rather
than a table, the absence of any byte-aligned period, and byte `+10` failing to act as a mode.

Four of these bounds were mine and had to be corrected against the measurement: the nibble shares are
16.6/14.4 % and not 16/14, the shift medians are monotone over the nine dense shifts but flatten above 8, a
`+10` value with a single record has a span of zero, and high and low nibbles are independent fields so their
histograms are not equal. Each was found by running the gate rather than by reasoning about it.

Audit **44/44, 0 vacuous**; ratchet refused `75 → 81` until `--write`.

Repository is **33 suites / 420 cases**, of which **12 suites / 208 cases** are cartridge-gated, so the
runnable tier is **21 suites / 212 cases**.
