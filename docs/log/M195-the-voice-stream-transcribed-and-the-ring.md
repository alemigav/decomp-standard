# M195 — `FUN_800b53f4` transcribed field by field, and why the decode still does not run

I transcribed the voice decoder from **our own decompilation** rather than from the description, which was the
next step M194 named. The transcription succeeded and is gated. The decode still does not run, and the reason
is now a specific one rather than "it does not work".

## 1. What the routine says, field by field

The bit reader, in the routine's own terms:

```
bitpos   = *(uint *)(ctx + 0x11c8)              starts at 96, i.e. byte 12 of the record
ring     = ctx + 0x1a0                          4 KiB
word     = be32(ring[(bitpos >> 3) & ~3])       aligned to four bytes
value    = word >> (bitpos & 31)                then masked to the field width
```

Fields, in order, with the arrays they land in:

| field | width | target |
|---|---|---|
| selector | 1 | `+0x18a` (0) or `+0x18c` (1) |
| a normal run | 7, **+1** | counted down in `+0x18a` |
| a silent run | 4, **+1** | counted down in `+0x18c` |
| 8 scale fields | **6, 6, 5, 5, 4, 4, 3, 3** | `local_130` … `local_122` |
| per group ×4: side values | **7, 2, 2, 6** | `local_120`, `local_110`, `local_118`, `local_108` |
| per group ×4: coefficients | **13 × 3** | `local_100`, `local_fe`, `local_fc`, … `local_ea` |

**The widths sum to 260** — `36 + 4 × (17 + 39)` — which is the same number the third-party tool states, arrived
at here from the code. That part of the description is confirmed independently, and it is the reason the
32.5-byte ceiling in M189 exists.

The synthesis is not in this routine: it calls `FUN_800b62c0`, which takes `(param_1 & 7)`, a table index and
the 13 coefficients, and scatters a transformed copy of them at **stride 3** into a 42-short table — a
polyphase kernel — alongside `FUN_800b63b4` and `FUN_800b4dc0`. All three are in the corpus, and a case pins
that.

## 2. The test, and it fails both ways

Parsing every clip to its declared block count, under each bit order the reader could plausibly imply:

| reading | clips overrunning | clips terminating within 8 bits of the end |
|---|---|---|
| MSB-first | **362 / 588** | **3** |
| LSB-first | **339 / 588** | **0** |

Neither reconciles. A correct transcription of a correct layout should terminate within the padding for
essentially every clip, and this terminates for three.

## 3. What that means, stated as the blocker

The code's reader consumes the **low bits** of `word >> (bitpos & 31)`, which is LSB-first within a big-endian
word — and that reading is *worse* than MSB-first, which is not a coincidence but a clue:

> **the bytes the decoder reads are not the record's payload bytes.**

`FUN_800b53f4` reads from a **4 KiB ring at `ctx + 0x1a0`**, which `FUN_800b4a04` fills in `0x400`-byte chunks
from the clip address. Nothing in this project has established what that copy does to the bytes — and a
byte-swap, a halfword swap, or a chunked re-layout would each leave the record's bytes bit-incompatible with
the reader while leaving the field widths correct. That is consistent with everything measured: the widths sum
to 260, the aggregate is 1.17× over budget (M194), and no bit order of the raw payload parses.

**So the next step is not another bit order.** It is to establish the ring-fill transform — read
`FUN_800b4a04`'s copy and its `0x400` chunking, or trace a real buffer — and only then re-run this parse. I am
recording that instead of guessing once more, because three failures in a row is the point at which a fourth
guess stops being informative.

## 4. What is not claimed

**No audio is decoded.** The block layout is transcribed and its widths are confirmed; the bit stream's
provenance is not. Nothing here should be read as "the voice codec is nearly done": the remaining work is an
unknown transform plus the synthesis path, and the synthesis path alone is four routines.

## 5. Gates

`file table (cartridge)` **83 → 87**: the MSB-first refutation with its counts, the LSB-first refutation with
its counts, the width sum as an independent confirmation of 260, and the three synthesis routines pinned by
path so a re-decompile that drops one invalidates the reading rather than silently keeping it.

Audit **44/44, 0 vacuous**; ratchet refused `83 → 87` until `--write`; counts derived and asserted in
seventeen places. The suite now takes ~30 s, which is the cost of parsing 588 clips twice and is stated rather
than hidden.

Repository is **34 suites / 433 cases**, of which **13 suites / 221 cases** are cartridge-gated, so the
runnable tier is **21 suites / 212 cases**.
