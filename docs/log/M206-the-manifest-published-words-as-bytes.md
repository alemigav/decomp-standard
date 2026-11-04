# M206 — the manifest published a word count as `covered_bytes`

`manifests/code_index.json` carried a byte-shaped name over a word count: `covered_bytes=len(covered)`, where
`covered` is a set of **4-byte word starts**. Boot published 14 409 and 12 316 B unclaimed, which the reader can
only reconcile by knowing the units — 14 409 + 12 316 ≠ 69 952, and 14 409 × 4 + 12 316 = 69 952.

That is the same class of error M205 fixed one layer up, left behind in the manifest that M205 did not touch.
Found by the strategic plan's own first question ("reproduce the numbers") pointed at a file nobody re-derived.

## 1. The fix

* `covered_bytes` is now `len(covered) * 4`; the word count survives as `covered_words` so the intermediate is
  still readable.
* `coverage` was `len(covered) / (size / 4)` — a ratio of words to words, which happened to be right; it is now
  `len(covered) * 4 / size`, which is right for a reason a reader can check.
* `src/INDEX.md`'s headline said "code bytes"; the writer now says "**image bytes** inside a known function
  body", and `counts.py` accepts only that wording — M205 corrected the readers of this sentence and missed its
  author.

## 2. The gate

A new structural case in `tools/counts.py`: the per-image `covered_bytes` must sum to the derived coverage
(1 210 600 B) **and** `covered_bytes + unclaimed_bytes` must equal each image's size on all 36. The second half
is what catches a unit slip, because it fails no matter which side of the sum is mis-scaled.

Mutation: restore the word count in one image of the committed manifest → `1 167 373 covered` and the tiling
case fails. (Mutating the artifact rather than the tool is deliberate: the value is what was wrong.)

## 3. Environment gaps closed at the same time

The new case reads `manifests/code_index.json`, which was in **neither** the audit sandbox nor the counts
self-test fixture — so every audit of the counts gate would have "detected" a missing file. Both now carry it.
That is the fifth time in this arc that an audit environment was wrong for a tool, and the second time in two
milestones, which is why the list is in `audit_gates.py`'s own comment.

## 4. Gates

`counts (repository)` **21 → 22**; `gate audit` **74 → 75** at the time this landed. Note and log row as usual.
