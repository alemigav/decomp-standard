# M190 — the 2.42 % was my alignment error, and `u16@+4` stays unassigned

Two open items. The second one resolved completely and in the least flattering way: **the residual was
mine.** The first did not resolve, but it is now bounded better than before.

## 1. The 2.42 % of "failing" groups was a 256-byte prelude misread

M187 folded the pool's 40-byte groups at **phase 16** and reported 97.58 % passing, with the 2.42 % residual
called *scattered* and left open. The failures are not scattered. They sit at **group index 0–5 and nowhere
else**:

| group index | failures |
|---|---|
| 0–5 | **5 441** |
| ≥ 6 | **0** of 218 000 |

And the nibble census says why. At index ≥ 6 the codebook byte's high nibble is **always 0–7**, spread
across all eight values (12 571 … 35 451 each) — a textbook codebook field. At index < 6 it is concentrated
at **0 and 15** (3 195 and 3 513, with almost nothing in 3–12): the bytes are `0x0_` and `0xF_`, which is
what **raw 16-bit samples near silence** look like, not codebook data.

Six groups × 40 bytes + the 16 already known = **256 bytes.** So each pool sample is:

```
[256 bytes = 128 raw big-endian int16 samples]  then  N × 40-byte MusyX ADPCM groups
```

and the arithmetic confirms it twice over: `(len − 256) % 40 == 0` on **1 192/1 192**, and folding at
**phase 256** gives

> **0 failing groups out of 217 944 — 100.00 %.**

The byte census over the *whole* 256-byte prelude has the 16-bit PCM signature (even positions ≤ 74 distinct
values, odd ≥ 234), not just the first 16 bytes I looked at in M187.

So the sample pool's codec is **clean, not 97.58 %**: every one of 217 944 groups satisfies the codebook
constraint. The residual was never a codec anomaly, a second class, or "voice using something stronger" —
it was the six groups that a 16-byte phase puts *inside* the prelude.

## 2. `u16@+4` — still unassigned, and now bounded

M189 refuted "duration" without assuming a codec: the modal `payload/field` is 32.51 at both 16 kHz and
8 kHz, and a duration would have to halve at 8 kHz. The natural repair was "then it is a bitrate, so the
ratio should be a **ladder** of discrete modes". It is not:

```
payload/field histogram, 588 records
 [8,9)    1   [14,15)  2   [20,21) 20   [26,27) 41   [31,32) 37
 [9,10)   2   [15,16)  8   [21,22) 18   [27,28) 50   [32,33) 85  <- ceiling
[10,11)   1   [16,17)  6   [22,23) 31   [28,29) 42
[11,12)   2   [17,18)  9   [23,24) 35   [29,30) 46
[12,13)   2   [18,19) 19   [24,25) 38   [30,31) 36
[13,14)   2   [19,20) 15   [25,26) 40
```

**Continuous from 8.7 to 32.5, peaking hard against a ceiling at 32.5.** That is a *variable-rate* stream
whose maximum rate is ~1 byte per unit, not a set of fixed bitrates.

No exact form survives: `pay == 32·field` on 0/588, `2·pay == 65·field` on 0/588, `32.5·field ± 1` on 0/588,
and `pay − 32·field` has median **−1 374** over a range of ±30 000.

What the ceiling does say, as a **reading and not a finding**: if `field` counts units of 32 samples, then
the payload runs at **8.7–32.5 bytes per 32-sample unit = 2.2–8.1 bits/sample**, which is a speech-codec
range and would make `u16@+4` a **frame count**. If the unit is 64 samples the range is 1.1–4.1 bits/sample,
also plausible. The data does not choose between them, and no code path reads the field (M182), so the frame
size cannot be recovered from the corpus either.

**Unassigned.** The description is now: *proportional to payload length, continuous down from a ceiling of
32.5, rate-independent* — and a frame count is the surviving candidate rather than a duration.

## 3. Retractions this carries

| retracted | by | what changed |
|---|---|---|
| "a 16-byte prologue of 8 samples" (M187) | **M190** | the prelude is **256 bytes / 128 samples**; M187 read only the first 16 bytes of it |
| "97.58 %, with a scattered 2.42 % residual" (M187) | **M190** | **100.00 %** at phase 256 — 0 failures in 217 944 groups; the residual was the misalignment |

Both are the same error seen twice: I fixed a phase from a prefix instead of from the structural boundary.
The test that would have caught it in M187 is the one now gated — *failures confined to indices 0–5* — which
is a positional check, not a rate check.

## 4. Gates

`file table (cartridge)` **72 → 73**: the 256-byte prelude with its byte census and the `(len−256) % 40 = 0`
law, the misaligned phase-16 figure kept **as the figure M187 published** (so the retraction is visible in
the gate), the phase-256 **0/217 944**, and the positional bound that makes the misalignment diagnosis
checkable rather than asserted.

Audit **44/44, 0 vacuous**; ratchet refused `72 → 73` until `--write`; counts derived and asserted in
sixteen places.

Repository is **33 suites / 409 cases**, of which **12 suites / 199 cases** are cartridge-gated, so the
runnable tier is **21 suites / 210 cases**.
