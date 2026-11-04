# M189 — id 1979 is a second codec, its header is 12 bytes, and the 418 is a rotation

Three questions were open: `u16@+4` in the `MORT` record, why `SND_PROJ` has 418 slots for 417 records, and
2.42 % of the pool's codec groups. The first two are answered as far as the data goes. The answer to the
first is *not* an assignment — but two of the three came back with something better than what was asked.

## 1. The `MORT` bank is a **different codec** from the pool

M187 identified the sample pool (id 1983) as MusyX ADPCM: 40-byte groups of two 20-byte frames behind a
16-byte prologue, `len ≡ 16 (mod 40)` on **1 192/1 192**. The obvious next test is whether the 588 `MORT`
records obey the same law.

**They do not.** Only **50 of 588** payloads satisfy `16 + 40k`, and the byte planes are symmetric:

| | pool (M187) | `MORT` bank |
|---|---|---|
| frame law | 1 192/1 192 | **50/588** |
| high plane entropy | 7.006 | **7.937** |
| low plane entropy | 7.309 | **7.937** |
| `0x00`+`0xFF` share of high plane | 8.1 % | **0.3 %** |

Near-perfectly flat planes with no `0x00`/`0xFF` concentration is what a **compressed bitstream** looks like,
and it is also why the earlier test for 16-bit PCM failed on this bank. So the sound family contains **two
codecs**: the pool's ADPCM for the 15-rate music/SFX bank, and a high-entropy codec for the 588 records at
**16 000 / 8 000 Hz** — the speech rates.

That is the split the secondary sources described, and it is now measured rather than reported: **the "very
strong compression" is real, and it is on the voice bank.**

## 2. The `MORT` header is 12 bytes, not 10

M178 established a 10-byte record header — `MORT`, `u16` field, `u16` rate, `u16` zero — because the payload
begins after it. The alignment settles a new size:

```
(len - 10) % 4 == 0 :    0 / 588
(len - 12) % 4 == 0 :  588 / 588
```

So the header is **12 bytes**, and the tenth byte is not padding: **byte +10 takes 65 distinct values**
(top values 2 and 4). The M178 reading was not wrong about the fields it named — +8 and +9 really are zero
in 588/588 — it was wrong about where the header *ends*.

## 3. `u16@+4` — a second, independent refutation, and still unassigned

M179 refuted "duration in ms" assuming 16-bit PCM. The codec is not PCM, so that refutation needed
replacing. The replacement does not assume a codec at all:

| rate group | modal payload/field |
|---|---|
| 16 000 Hz (565 records) | **32.51** |
| 8 000 Hz (23 records) | **32.51** |

A duration would have to **double** at 8 kHz — 32.51 and 16.26. It does not move at all. So `u16@+4` is not a
duration, for a reason that holds whatever the payload is.

And it is **not an exact ratio** either: `2·payload == 65·field` holds on **0/588**, as does `32·field` and
`32.5·field ± 1`. The modal 32.51 is a *minority mode* — the residual `payload − 32.5·field` has median
**−1 568** and a tail down to 8.7 bytes per unit for 69 records.

**Still unassigned.** What has changed is the description: the field is proportional to payload length with
a modal 32.5 and a long tail toward heavier compression, and it is neither a duration nor a count of
anything the payload length determines.

## 4. The 418-vs-417 question was the wrong question

`SND_PROJ` has 417 records whose keys are all of 0..417 except **11**. The "418 slots" framing suggested a
capacity or a missing table entry. It is neither: the chain order is a **rotation** of the key range.

* **370 of 416** adjacent pairs are consecutive **mod 418**.
* The chain **starts at key 118** and **ends at 117** — i.e. it runs 118 → 417, wraps, → 117.
* The first deviation is at position 13, where keys **412–417** are pulled forward, then the run resumes at
  131.

So `418` is simply the size of the key range (0..417), the order is a rotation beginning at 118, and the only
real anomaly is the absent key **11** — which M186 already showed is an **unused slot**, not a dangling
target.

**Why 118 starts the rotation, and why 11 is absent, remain open.** Both are single facts about one file, not
patterns, and guessing at them would produce exactly the kind of unfalsifiable story this project keeps
refusing.

## 5. Gates

`file table (cartridge)` **65 → 72**: the `MORT` payload's failure to satisfy the pool's frame law with its
plane entropies, the 12-byte header against the 10-byte one, byte +10's 65 values, the 32.51 mode in both
rate groups (with what a duration would have required), the 0/588 exact-ratio refutation, and the rotation
fit with its start and end keys.

Three of these case corrections were mine, and are worth recording because each would have been a false
claim: the payload count is **50/588** and I asserted 0; the rotation had to be computed on `SND_PROJ`
(id 1980), and I first read it out of the `MORT` bank; and one label said `370/587` and "id 1979" when the
run is 416 pairs of id 1980.

Audit **44/44, 0 vacuous**; ratchet refused `65 → 72` until `--write`; counts derived and asserted in
sixteen places.

Repository is **33 suites / 408 cases**, of which **12 suites / 199 cases** are cartridge-gated, so the
runnable tier is **21 suites / 209 cases**.
