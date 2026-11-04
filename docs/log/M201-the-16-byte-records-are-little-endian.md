# M201 — the 16-byte records, and the encoding hiding in them

The class-3 records from M200 are 16 bytes: `{stride=16, key@+4, four u16 params@+8..+14}`, the stride
field identical in 241/241. Read as big-endian the four parameters look like noise — 59395, 62465, 53255,
40975 — and that is exactly how they would have been written down if the histogram had not been taken.

## Byte-swapped, they are round numbers

`0xE803` → **1000**, `0xF401` → **500**, `0xD007` → **2000**, `0xA00F` → **4000**, `0xFA00` → **250**. The
parameters are **little-endian inside a big-endian container**: a plausible consequence of the pool being
built on a little-endian host, and a trap for anyone reading the section as big-endian throughout.

## And the two fields differ in kind

| field | swapped values | reading |
|---|---|---|
| `+10` | 1000 ×99, 3000 ×25, 4000 ×17, 5000 ×17, 2000 ×14, **plus 8000 and 16000** | a **rate** field: it carries the two rates the voice bank uses |
| `+14` | 1000 ×140, 0 ×38, 500 ×18, 250 ×7, 200 ×7 | **no** rate at all — levels or durations |

My first version of the case asserted "no canonical rate occurs in either field". That was wrong, the gate
said so on its first run, and the corrected case is stronger than the guess: `+10` is a rate field *because*
8000 and 16000 appear in it, and `+14` is not one *because* they do not.

## Gated

One case pins the whole thing: 241 records with stride 16, `+10` with 1000 ×99 and containing 8000 and
16000, `+14` with 1000 ×140 and intersecting no canonical rate. One mutation reads the parameters
big-endian (the swap becomes identity) and the case fails. Audit **51/51, 0 vacuous**.

Not established: what `+8` and `+12` are. `+8` has 50 distinct values including 0 ×52 and 59395 ×29 (1000),
and `+12` has 33 including 16 ×100 and 0 ×59 — the same little-endian reading presumably applies, but the
values are not yet round enough to name.
