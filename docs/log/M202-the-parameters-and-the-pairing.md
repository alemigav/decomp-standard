# M202 — the four parameters named, and what feeds cache B

M201 found the class-3 records were little-endian and that `+10` carries the bank's two rates. This
milestone finishes the other two fields and answers the cache-B question, both as gates.

## The record, complete

| field | swapped values | reading |
|---|---|---|
| `+8` | 1000 ×29, 2000 ×20, 1500 ×18, 500 ×16, 4000, 300, 17 — range 0–14000 | a **time**, in round hundreds |
| `+10` | 8000, 16000, 1000, 3000, 4000, 5000 | the **rate** (M201) |
| `+12` | **4096 ×100**, 2048 ×7, 1228 ×23, 1638 ×8, 0 ×59 — range 0–**4096** | a **size in bytes**, capped at 4096 |
| `+14` | 1000 ×140, 0 ×38, 500 ×18, 250 ×7, 200 ×7 | a **level**, no rate |

The ceiling is the point: `+12` never exceeds **4096**, which is exactly the ring-fill chunk of
`FUN_800b4a04` traced in M197. A field capped at the DMA chunk size is a size, not a count — that is the
anchor the case leans on, rather than the roundness of the numbers.

## Cache B is a pairing, not a set

List `[5]` decomposes as **142 sample-tagged keys + 148 tag-3 keys, nothing else**, and **all 142 sample
keys also appear in list[2]** — the full sample list. So it is not an independent key space: it pairs each
of 142 samples with one of the 148 parameter records, which is why the only mixed-tag list is the one whose
cache holds a resolved object. Cache B stores **sample → parameters**.

Two mutations, both non-vacuous: reading `+12` big-endian (without the swap it reads as `16`), and inverting
the subset test so list[5] is treated as its own set. Audit **53/53, 0 vacuous**.

## What is now known about the four caches

| cache | fed by | holds |
|---|---|---|
| A `0x8014e1e0` | list `[4]`, 736 sample keys | sample-keyed objects |
| B `0x801521f0` | list `[5]`, 142 samples ↔ 148 parameters | the pairing |
| C `0x80152a00` | list `[6]`, 65 tag-3 keys, **key + rate** | tag-3 objects cached per rate |

Answered since: cache C's third field is the **rate**, not a length. Still open: what a "sample"
and a "parameter set" are *called* in the engine, and what cache C's old length
means given the parameter records already carry their own size at `+12`.
