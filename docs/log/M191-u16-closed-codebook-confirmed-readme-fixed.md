# M191 — `u16@+4` closed as unassignable, the codebook fields confirmed, and the README fixed

Three things: the last two open questions in the sound family, and a front page that had gone from stale to
**wrong** — it was quoting two numbers M190 had retracted.

## 1. `u16@+4`: the chase ends, and the answer is that it cannot be closed here

The pool codec turned out to have a **256-byte raw prelude**, which suggested `id 1979`'s payload might have
one too — and if it did, subtracting it should make `payload/field` exact. It does not:

* For every prelude size `k` from 0 to 80, the coefficient of variation of `(payload − k)/field` **rises**
  (0.1858 at `k = 0` to 0.1861 at `k = 5`), and the number of exact `32.5` matches stays at 0–3.
* There is **no raw-PCM signature at any depth**: over the first 16, 32, 48, 64, 128 and 256 bytes the even
  and odd byte positions are equally varied (210–229 distinct each), where a prelude of 16-bit samples
  would show even positions collapsing to a few dozen values — as the pool's does (≤ 74 against ≥ 234).

So `id 1979`'s payload is a compressed stream from **byte 0**, with no prelude, unlike the pool.

The next idea was to *calibrate against the pool*: its codec is now known (256-byte prelude + 64 samples per
40-byte group), so if any directory field equalled the group count or the decoded sample count, that would
identify what kind of quantity these fields are. Measured across all five unassigned fields (`+6`, `+16`,
`+18`, `+22`, `+26`), against five candidate quantities: the best match is **5 of 1 192**. No field is a
count of groups or samples.

**The chase is closed.** `u16@+4` is:

| tested | result |
|---|---|
| a MIDI note | refuted — 503/588 above 127 |
| a duration in ms | refuted twice — exact on 8/588 assuming PCM; and the modal ratio is identical at 16 kHz and 8 kHz, where a duration must halve |
| a sample count | refuted — 0/588 |
| a loop point | doubtful — `field/payload ∈ [0.031, 0.114]` on 588/588, no mass at 0 or ≈1 |
| a bitrate ladder | refuted — the ratio is continuous, 8.7 → 32.5 |
| an exact ratio of payload | refuted — `32·field`, `65/2·field`, `32.5·field ± 1` all 0/588 |

What survives is a **frame count**: proportional to payload length, continuous down from a ceiling of 32.5.
At 32 samples per frame that is 2.2–8.1 bits/sample; at 64, 1.1–4.1. **The data does not choose**, and the
reason is now stated rather than deferred: no CPU path reads the field (M182), the voice codec is unknown, and
the pool offers no analogue to calibrate against. Closing it needs one of those three, not another test.

## 2. The codebook's fields are now confirmed one by one

M187's layout was `[A.raw 4][B.raw 4][A.nib 16][B.nib 16]` with a codebook index and a shift in byte 0 of each
nibble block. At the **correct** phase (256) that is now confirmed field by field rather than as a whole:

| field | measured |
|---|---|
| nibbles per block | **30**, in all **435 888** blocks — `2 raw + 30 nibbles = 32 samples` exactly |
| codebook index (high nibble) | **all 8 values used**, 25 087–70 900 occurrences each |
| shift (low nibble) | **0–12**, 13 distinct, concentrated at 2–4; 13–15 never occur, as a right shift would require |
| codebooks per sample | **1 099 of 1 192** samples use all eight |
| raw pairs | adjacent-correlation median **+0.298** at phase 256, against **−0.004** shuffled |

So the *structure* is settled: the group arithmetic closes, every field takes exactly the range its role
predicts, and the fields are used. What is **not** available is the **codebook contents** — eight tables of
128 int16 — which are not in the cartridge's data as far as anything here has found, and most likely live in
the audio microcode. Decoding a sample needs those tables, not more structure.

## 3. The README was quoting retracted numbers

The front page still said **"16-byte prologue"** and **"97.58 % structural agreement"** — both retracted at
M190 — and listed the 2.42 % residual as an open item after it had been resolved. That is worse than stale:
a released v1.1 whose front page asserts the numbers its own log retracts.

Fixed, and then *made unfixable-by-rote*: the three constants the sentence quotes now live in
**`fixtures/sound/codec.json`**, and are checked from both sides —

* `tools/file_table.py --check` asserts all **12** fixture constants against the cartridge, so a measurement
  that moves fails **first**, before any document can drift with it;
* `tools/counts.py --check` asserts the README quotes those fixture values, so the prose cannot rot away from
  the fixture.

That is the same two-layer design as acceptance-versus-ratchet: one side binds the number to reality, the
other binds it to the text.

Two smaller fixes fell out of writing it: the counts gate had to normalise thin spaces and commas inside
quoted numbers (it was dictating a format), and its pattern needed `\s+` where prose wraps a line.

## 4. Gates

`file table (cartridge)` **73 → 75**: the fixture against the cartridge, and the constants restated.
`counts (repository)` **16 → 17**: the README's codec sentence against the fixture.

Audit **44/44, 0 vacuous**; ratchet refused both increases until `--write`.

Repository is **33 suites / 414 cases**, of which **12 suites / 202 cases** are cartridge-gated, so the
runnable tier is **21 suites / 212 cases**.
