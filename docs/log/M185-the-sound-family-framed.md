# M185 — the sound family is framed: proj and pool are chained section tables

M184 framed id 1983 by its directory and id 1979 by its own header. This milestone frames the three files
that sit between them — **1980, 1981, 1982** — so the whole family is described the same way, before anyone
touches a codec.

All three are **zlib members**, unlike 1979 and 1983 which are stored raw. That is why the file table's own
predicate (byte 3 of every record zero, M82) excluded exactly one payload from the raw class: the sound
family is split across both storage kinds.

## 1. The idiom, from the code

`FUN_800a86a0` walks `SND_PROJ` and `SND_POOL` identically, and `FUN_800ad330` walks `SND_SMPDIR` the same
way:

```c
iVar4 = *param_1;                          /* a relative offset to the first record */
while (iVar4 != -1) {                      /* -1 ends the chain */
    if (*(short *)(param_1 + 1) == param_2)   /* a u16 key at +4 */
    ...
    piVar5 = (int *)((int)param_5 + *param_5);   /* same shape, per record */
    piVar5 = (int *)((int)piVar5 + *piVar5);     /* stride = this record's first u32 */
```

So each file starts with a relative offset to its first record, each record's first word is the stride to
the next, and `-1` terminates. The chain **tiles** its container — which is what makes each file frameable
without knowing what any field means.

## 2. SND_PROJ (id 1980) — 102 148 B

* **417 records**, strides tiling to 102 144, the 4-byte `-1` closing the member exactly.
* `u16` at +4: **417 distinct values**, a **bijection onto 0..417 less one hole, `11`.**

That last point is a correction of my own first assertion. I wrote the case as `keys == range(118, 535)`
because the first twelve values are 118, 119, 120, … and **it failed**. The keys are not sequential in
record order at all; the *set* is a contiguous range with a single hole, which is a stronger statement and
one worth naming — a table with exactly one missing entry invites the question of what occupied 11.

* `u32` at +8 is an offset, 24..32, from the record start to a **short list terminated by `-1`**. Over the
  417 records those lists hold **5 136** shorts.

## 3. SND_POOL (id 1981) — 167 168 B, four sections

The head is four `u32` section offsets — **16, 139 452, 143 328, 147 460** — and each section is the same
construct: a relative offset to its first record, a chain, and `-1`.

| section | first record at | records | keys |
|---|---|---|---|
| 0 | +112 | **2 025** | 1..2026 |
| 1 | +16 | **241** | −16383..−16132 |
| 2 | +1032 | **3** | 16386..16388 |
| 3 | +60 | **326** | −32766..−32440 |

**2 595 records in all, all keys distinct**, and the decisive structural law: **every section's `-1`
terminator abuts the next section's declared offset, and the last abuts EOF** — **4/4**. So the four
sections partition the member with no slack, exactly as the 1 192 directory records partition id 1983.

The negative key ranges in sections 1 and 3 are *reported, not interpreted*. Both are narrow and
consecutive (−32766..−32440 is 326 values for 326 records), which says the `+4` field there is not the same
kind of key as section 0's 1..2026 — but what it is, is not established.

## 4. SND_SMPDIR (id 1982) — framed in M184, restated here

33 380 B = **1 192 × 28** + `ffffffff`; `u16@+0` a sequential index; `u32@+4` ascending byte offsets into
id 1983 that **tile it exactly**; `u16@+14` a rate in 15 canonical values. Fields at +6, +16, +18, +22 and
+26 remain **unassigned** — a census, not laws.

## 5. The cross-file link, measured and not rounded up

The code implies it: `FUN_800a86a0` compares each `SND_PROJ` list short against the keys in the `SND_POOL`
chain. Measured: of the **5 136** shorts in the proj lists, **4 301 (83.7 %)** are pool keys.

That is a real link and **not a total one**, and the case is written to assert both the numerator and the
denominator so it cannot later be described as a complete mapping. The 835 that do not resolve are the
honest remainder — most likely a different object class in the same lists, which is the next question here.

## 6. On the codec claim

The suggestion that the sample codec is "a custom ADPCM tailored to MusyX" is **compatible with everything
measured and adds nothing testable**. It cannot be falsified as stated: any irregular length distribution is
explained by "different block size or a more sophisticated entropy stage", and no observation would count
against it.

What is now in hand is the ground a codec claim needs: **1 192 exact byte-ranges with their rates** (id
1983), and the negative evidence that they are **not** plain 16-bit PCM (high-plane entropy 7.006, `0x00`/
`0xFF` only 8.1 % of it), **not** 15 other obvious packings, and **not** derivable from any directory field.
A future claim about the codec can be tested against those ranges; "proprietary ADPCM" cannot.

Also worth separating, since the claim bundles them: **MusyX is Factor 5's** audio middleware, and the FMV
work was **Angel Studios'** — the two names are not interchangeable, and this project has measured the
audio path (ids 1979–1983, `FUN_800b3704`, `FUN_800a86a0`, `FUN_800ad330`) independently of any account of
who wrote it.

## 7. Gates

`file table (cartridge)` **43 → 48**: proj's chain and exact tiling, proj's key bijection with its hole,
pool's four section offsets, pool's per-section record counts and distinctness, the 4/4 terminator abutment,
and the 5 136 / 4 301 cross-reference. Audit **44/44, 0 vacuous**; ratchet refused `43 → 48` until
`--write`; counts derived and asserted in twelve places.

Repository is **33 suites / 380 cases**, of which **12 suites / 175 cases** are cartridge-gated, so the
runnable tier is **21 suites / 205 cases**.
