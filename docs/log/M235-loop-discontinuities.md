# M235 — loop discontinuities: there are none, and the reason is silence

The backlog carried "loop discontinuities in the voice bank" as an open defect. Measured, the premise does not
hold: the bank's clips are **bounded by silence**, so the seam between a clip's last sample and its first is
small for the same reason the first sample is — both sit at or next to zero — and not because anything loops.

## 1. What was measured

All **588** MORT clips of cartridge id 1979, transcribed with the same `voice_decode.transcribe()` the rest of
the sound arc uses (M194–M199). Per clip: the first and last sample, `wrap = |s[0] - s[-1]|`, and the same
quantity at an **ordinary boundary inside the clip**, `|s[n/2] - s[n/2-1]|`. Both are compared against the
clip's own **p99** of adjacent sample differences — a boundary is "discontinuous" if it exceeds the clip's own
99th percentile.

## 2. The endpoints are silence

| | |
|---|---|
| clips whose **last** sample is exactly `0` | **440** of 588 |
| clips whose **first** sample is exactly `0` | **518** of 588 |
| clips where **both** are exactly `0` | **393** |
| largest `|last|` | 7 352 (of a ±32 767 range) |
| largest endpoint as a fraction of its clip's peak | **0.225** |

So most of the bank starts and ends in silence, which is what a clip meant to be played once and stopped does.
The residue is reported rather than smoothed: **70** clips neither begin nor end at zero, and one of them ends
at 22.5 % of its own peak.

## 3. The wrap is not an ordinary boundary, and the control proves the test can fire

| | count | expected if the wrap were an ordinary boundary |
|---|---|---|
| clips whose **wrap** exceeds their own p99 | **0** | 5.88 |
| clips whose **midpoint gap** exceeds their own p99 | **8** | 5.88 |

`P(0 of 588 | p = 0.01) = 0.0027` — the wrap is not merely "not an outlier", it is **less discontinuous than a
random boundary**, which is what silence bounding predicts. And the midpoint fires at the rate its percentile
implies (8 against 5.88), so the test is not too weak to see a seam; there is simply no seam to see.

The p99 comparison is per clip, which matters: the largest wrap in the bank is **9 816**, which *sounds* large
until it is placed against that clip's own p99 of ~9 952 — the endpoint-to-endpoint step is inside the clip's
ordinary sample-to-sample variation. A threshold on the raw magnitude would have called it a defect.

## 4. What this does not say

- **No loop point is read from a MORT record.** M194's header is `MORT`, a rate, a length in words and a count;
  it carries no loop flag, so "the clip loops" is not a claim this file can make in either direction.
- **A small wrap is not evidence of looping** — on a silence-bounded clip it is evidence of zeros. That is the
  whole finding, and it is the opposite of the backlog's framing.
- Nothing about how the audio sounds, and nothing that maps a clip to a game event.
- The 70 clips with non-zero endpoints are measured and named by index; their wraps are inside their own p99,
  which is all that is claimed about them.

## 5. The tool

`tools/voice_loops.py` → `fixtures/sound/loop_sweep.json`, **7 cases**, 3 mutations (the control boundary
collapsed onto the wrap so the test grades itself; the percentile dropped to the median; the last sample read
as the first). The whole-bank sweep is a manual `--sweep` (40 s at 8 workers) and the gate re-derives a
**5-clip stratum** — clips 0, 146, 293, 439, 587, the same evenly spaced set `voice_sweep.py` gates on — then
reads the whole-bank aggregates out of the artefact. That split is stated in the case labels: the stratum is
what makes the aggregates trustworthy, and a gate that re-derived 588 clips would cost 40 s for numbers the
stratum already proves current.
