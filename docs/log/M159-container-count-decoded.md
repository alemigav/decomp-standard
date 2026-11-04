# M159 — the `01 41` count field is decoded: 16 bytes per unit, proven on 355 of 355

The count field is no longer a guess. It is the number of **16-byte units in the prologue**, and the payload
length is `filesize − 16·count` — true for **every one of the 355 family blocks**, across **21 distinct count
values**.

## 1. The law

| word | meaning | evidence |
|---|---|---|
| `word0` | magic `0x01410000` | **constant across all 355** |
| `word1` | **N, the number of 16-byte units before the payload** | §2 |
| `word2` | **payload length = `filesize − 16·N`** | **355 / 355**, N from 1 to 29 |
| `word3` | zero | every block in the family |

So the payload begins at `16·N`: **16 bytes** for N=1 (238 blocks), **32** for N=2 (40), **48** for N=3 (11), and
so on to **464** for N=29. The header is not a fixed 24- or 32-byte structure — my own M158 reading ("32-byte
header, count at word1's low byte") was the N=2 case generalised, and is retracted here.

## 2. Why the law is not a coincidence

The earlier hypothesis `filesize − (16 + 8·count)` fit only the 40 count-2 blocks and failed on the other 315.
The correct form fits **all** of them:

```
count  blocks  word2 == filesize - 16*count
    1     238   238/238
    2      40    40/40
    3      11    11/11
    4       7     7/7
    5       2     2/2
   ...    ...     ...
   29       1     1/1
```

Twenty-one independent count values, each passing on every block that carries it, is what makes this a law and
not a fit.

## 3. What the extra units are *not*

Refuted, on every block with N > 2: the units are **not a section table**. Reading the third word of each unit as
an offset gives data-like values in ascending order in **zero** blocks:

```
count=17, id 5599:  entry 3 = 0x35f23763, 0xd24b5bff, ...
                    entry 4 = 0x296b3757, 0x2e485eff, ...
```

Those are colour/mask-shaped words, not offsets into the payload. So the prologue is **flat** — `16·N` bytes of
something — and what that something is remains unresolved. The plausible candidate is a **palette or mask
table** (the constant pairs `0xb2b2b2ff`, `0x7f7f7fff` appear in every block; M147's `pad_layout` work showed how
convincingly such constants can look like structure). Recorded as a candidate, not a finding.

## 4. What this settles for the resource question

* The family is **355 blocks**, sizes 160 B – 64 KB, and its framing is now **fully decoded**: magic, unit count,
  payload length, payload at `16·N`.
* So the 48 room-table ids in this family are **not scripts** (their payload does not begin with a record table,
  M158), and they are **not section containers** either. They are an opaque payload with a decoded framing — the
  largest identified-but-undeclared resource kind in the corpus.

## 5. Gate

New cartridge-gated suite **`01 41 container (cartridge)`** — four cases: the family is found and large, every
block satisfies the length law, the counts span ≥ 10 values (so the law is not a special case), and the extra
units are *not* a section table. The audit gained a matching entry that mutates `UNIT = 16` to `32`, which makes
the law fail: **12/12 audits, 0 vacuous**.

**155 cases across 17 fixtures**, `ci.sh: ok`, 18/18 marker checks.

## 6. What is left, and the honest next question

The prologue's contents. One measurement would decide between "palette" and "mask table": whether the unit values
correlate with the payload — e.g. whether `count` equals a bit depth or the number of distinct payload values.
That is a *content* question on a now well-framed container, which is a much better place to be than M157's
guess-the-layout.
