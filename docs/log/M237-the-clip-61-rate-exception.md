# M237 — the clip-61 rate exception: real in the data, and not a reading error

M236 named one disagreement out of 674 and left it at that: at `0x801158ec` index 64 the entry is `0x003d` —
clip **61** *without* bit 15 — while clip 61's own record declares **8 000 Hz**, and the same clip appears as
`0x803d` in two other lists. The question asked of it was the right one: is that a real outlier, or a typo in
my reading? It is real, and the numbers below are why it is not a reading error.

## 1. Not a typo, three ways

| check | result |
|---|---|
| the raw word at `0x801158ec + 2*64` | `0x003d` — dumped as words, not read through a structure |
| the same array's other entries | **82 of 83** non-zero entries resolve to valid clips and agree with their records |
| the same array's *own* flagged entries | **6 flagged, 6 pointing at 8 kHz records** |

The third is the one that matters: within the very list that carries the exception, the convention the
exception violates is followed six times. A mis-segmentation of that array would show up as *many*
disagreements inside it, not one. And the earlier worry — that `0x801158ec`'s length of 84 might be several
lists merged — does not survive inspection either: descents inside an array are normal here (up to **6** in
`0x801155ec` and `0x801156b0`, and **4** in this one), so unsortedness is not evidence of concatenation.

## 2. The flag is a selector, not decoration

The question behind "outlier or typo" is whether bit 15 means anything at all. Tabulating every reference
against the record it resolves to answers it:

| | record 8 000 Hz | record 16 000 Hz |
|---|---|---|
| **bit 15 set** | **38** | **0** |
| **bit 15 clear** | **1** | **635** |

If the flag were unrelated to the record — decoration, a padding bit, a copy-paste artefact — the
off-diagonal would be **61.4** disagreements, because 565 of the 588 records are 16 kHz and 38 flagged
references would land on them most of the time. It is **1**. So bit 15 is a rate selector that is **61 times
more consistent than chance**, and the single disagreement is a fact about the data rather than about the flag.

## 3. The exception's shape is "one lost bit", not "different policy"

- **39** references in the whole bank point at 8 kHz clips: **38 flagged, 1 not**.
- Clip 61 is **the only clip in the bank referenced both ways** — `[2 flagged, 1 unflagged]`.
- The other **22** 8 kHz clips are referenced once or twice each and are flagged **every** time.

A deliberate "play this one fast" policy would more likely show up as *some other* 8 kHz clip also getting an
unflagged reference; instead the whole population is uniform and one reference in 39 is not. That is the
signature of a single lost flag bit.

**But this is a probability, not a proof, and the counter-argument is real**: at 16 kHz an 8 kHz clip plays at
**double speed**, which is impossible to miss by ear. A shipped game catching that would either fix it or mean
it. So "deliberate one-off effect" survives — and whichever it is, the *behaviour* is the same, because
`FUN_80004a6c` passes the rate it computed from this bit to the voice starter and never consults the record's
field. The list is authoritative; the record's `u16@+6` is a label.

## 4. What the two readings would each require

| | would require |
|---|---|
| **lost flag** | one bit wrong in one list; the scene that uses `0x801158ec` plays its clip-61 cue a fifth above and twice as fast |
| **deliberate** | the author of one list choosing a speed-up for one cue while the other 38 8 kHz references in the bank stay at their native rate |

The first is the parsimonious reading and the one I would defend; the second is not excluded, and no byte in
the image decides between them. What *is* decided: the entry is not a typo, the flag is load-bearing, and the
list — not the record — is what the player is told.

## 5. Where it now lives

`tools/voice_lists.py` carries the tabulation as derived fields — `rate_cross` (the 2×2), `mixed_clips`
(clips referenced both ways) and `last_array_rule` (the within-list control) — and **12 cases**, three of them
new: the off-diagonal against its chance expectation, the within-list 6-of-6, and clip 61 as the only mixed
clip. One new mutation tabulates the flag as always clear, which collapses the 2×2 and fails all three.
