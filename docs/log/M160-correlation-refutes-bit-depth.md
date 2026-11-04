# M160 — the correlation run: N is neither a bit depth nor a value count

The question was whether `N` (the number of 16-byte prologue units) tracks the payload's distinct-value count or
its bit depth. **Both are refuted**, and the refutations are clean. What the run did find is that the units are
**records with constants**, not a directory.

## 1. Bit depth: refuted by one number

The maximum payload byte is **255 in every one of the 355 blocks**, including the 238 with `N = 1`:

```
N=1 blocks:  max byte 255, distinct values 19..256 (median 125)
N=2 blocks:  max byte 255, distinct 89..244
N≥7 blocks:  max byte 255, distinct 256
```

A payload at bit depth `N` cannot contain a byte above `2^N − 1`, so `N = 1` would cap the payload at **1**. It
contains 255. The weaker form — `distinct ≤ 2^N` — holds for 55 of 355, which for `N ≥ 8` is trivially true since
distinct caps at 256. Bit depth is out.

## 2. N = distinct values: refuted pairwise

**0 of 355** blocks have `N` equal to their payload's distinct-value count. Correlation is `+0.595` — real but
useless for prediction, and the counts (median 125 at `N=1`, 256 at `N≥7`) move in the opposite direction from
`N` for the small values.

## 3. What the run *did* establish

* **`r(N, payload length) = +0.856`**, and **`payload % N == 0` in 296 of 355** (83 %). So `N` scales with the
  content, and in most blocks the payload divides evenly into `N` parts — suggestive of `N` parts, but not
  uniform enough to call a partition.
* **The prologue is more structured than the payload**: mean byte entropy **3.46** vs **5.60** bits, and the
  prologue is the lower of the two in **120 of 120** sampled blocks. It is a table, not data.
* **No word position is an offset table.** For the 77 blocks with `N ≥ 3`, reading word 0, 1, 2 or 3 of each unit
  as an offset gives ascending in-bounds values in **zero** blocks — so the units are not a directory, confirming
  M159's refutation across all four fields rather than one.
* **Unit 1 recurs as a template.** The most common first extra unit across blocks is

  ```
  00000000 0000000N b2b2b2ff 7f7f7fff      (23 blocks with word1 = 4, 16 with 2, 11 with 0xc)
  ```

  — a fixed shape whose only varying word is small. That is a *record*, and a shared one.

## 4. Verdict

`N` is the **count of 16-byte prologue records**. The framing is now fully described — magic `0x01410000`, `N`,
payload length, payload at `16·N`, and `N` records of which the first-extra one has a stable template — while the
records' *meaning* is not decoded. The honest stopping point is that one further step and no more: the records
contain constants shared across blocks, so they encode **graphics state** rather than per-block metadata.

## 5. The gate, and one of my own cases caught vacuous

The suite is now **8 cases**: the family is large, the length law holds, the counts span ≥ 10 values, the units
are not a section table, **N is not a bit depth**, **N is not the distinct-value count**, a large share of
payloads divides by `N`, and unit 1 recurs as a template.

The second of the new refutations was first written as

```python
all(n != d for n, d in zip(...)) or True
```

— an assertion that cannot fail, of exactly the kind the audit exists to find. It is now computed pairwise, and
it has an audit entry that forces `N == distinct` and makes it fail: **13/13 audits, 0 vacuous**.

**160 cases across 17 fixtures**, `ci.sh: ok`, 18/18 marker checks.
