# M194 — the voice decoder is not implemented, and the description does not fit this cartridge

I set out to implement the voice codec from the description M193 recorded and test it. **It does not
reconcile with the cartridge**, and the arithmetic says so before any audio is involved. That is the result,
and it undoes part of M193.

## 1. The block cost cannot be 260 bits for these clips

The description gives a normal block as `36` bits of scales (6+6+5+5+4+4+3+3) plus four groups of `17` side
bits and `13×3` coefficient bits — **260 bits**, which is exactly the 32.5-byte ceiling measured in M189. It
sums correctly. It just cannot be true here:

| | |
|---|---|
| declared blocks (`u16@+4`) across the bank | **307 038** |
| payload available | **8 551 504 B** = 68 412 032 bits |
| at 260 bits per block that needs | **9 978 735 B — 1.17× the payload** |
| available bits per declared block | **222.8** |
| clips that individually cannot hold `260 × blocks` bits | **531 of 588** |

So either `u16@+4` is not a block count, or a normal block is not 260 bits, or the two are not in the same
units. One of those is false and the description does not say which.

And the parse fails empirically, not just in aggregate. I tried every combination of the documented geometry
— stream at `+12` or `+16`, both selector polarities, scales per block or per run — and each overruns the
payload on **151 to 406 of 588** clips. The best variant still fails on a quarter of the bank. A guess that
works on three quarters is a wrong guess with a large coincidence attached.

**So the voice decoder is not implemented.** What is missing is not a table — M193 established the
coefficients are in the stream — it is the actual bit layout, which `FUN_800b53f4` (616 lines, every field
read inlined) encodes and which I have not transcribed correctly. Implementing it by search has now been
tried and does not work.

## 2. Two of M193's claims are retracted

| retracted | what changed |
|---|---|
| "`u16@+4` **is** the block count" (M193) | **not established.** The tool names the field that, and the per-clip bound `payload ≤ 12 + 32.5·blocks + 20` holds — but that bound is satisfied by *any* value small enough, so it was weak evidence, and §1 kills the strong reading |
| "the `MORT` header is **16** bytes" (M193) | **back to 12.** `u32@+8` ends exactly at `+12`, and re2studio's `FirstBitPosition = 0x60` is 96 bits = **12 bytes** — the header — so the stream starts there. M193 read `HeaderSize = 16` as the header length when it is the minimum clip size |

That is a flip-flop: M189 said 12, M193 said 16, M194 says 12 again. The record shows all three because
each was made on different evidence and the later one is not more flattering. What survives on solid ground is
narrower than either: **`u32@+8` is the clip length in four-byte words, on 588 of 588** — which is why every
length is divisible by 4 — and **`u16@+6` is the rate**. `u16@+4` is a small integer proportional to payload
length, still unnamed.

## 3. "12 bad samples" was my threshold, not a failure set

M193 reported 12 of 1 192 pool samples decoding poorly. There is no such set. The adjacent correlation of the
decoded audio runs **continuously from +0.443 to +0.980 with no gap above 0.05** — the 0.7 line I drew ran
through the middle of a continuous distribution. And the low tail is **noise-like content**, which is what a
low adjacent correlation *means*:

| | zero-crossing rate, median |
|---|---|
| the 12 lowest-correlation decodes | **0.282** |
| the other 1 180 | **0.127** |

Percussion and noise-based effects cross zero twice as often as tonal material and correlate far less between
adjacent samples. So the pool codec decodes **all 1 192 samples**; the tail is content, not breakage. Both
facts are gated — the continuity and the zero-crossing ratio — because "12 failures" was a claim I published
and this is the correction.

## 4. What the sound thread now claims

**Established:** the pool codec's format and a decoder that produces audio (`tools/sound_decode.py`, 7 gated
cases); the 256-byte shared codebook; the directory record's six fields; `u32@+8` and `u16@+6` in the voice
header; both codecs need **no table from outside the cartridge**.

**Not established:** the voice codec's bit layout and therefore its audio; the meaning of `u16@+4`; the pool's
four key classes.

The honest next step is the one I avoided: **transcribe `FUN_800b53f4` properly**, field by field, with the
inlined bit reads turned into a bit reader and each field's width checked against the routine rather than
against a description. That is a milestone of careful reading, not of search.

## 5. Gates

`sound decode (cartridge)` **5 → 7**: correlation continuity with no bimodality, and the low tail's
zero-crossing rate against the rest. `file table (cartridge)` **83 → 83**, with the block-count *bound* case
replaced by the **refutation** (`531/588` clips cannot hold `260 × blocks`), and the header case flipped back
to 12 with its reason in the label.

Audit **44/44, 0 vacuous**; counts derived and asserted in seventeen places.

Repository is **34 suites / 429 cases**, of which **13 suites / 217 cases** are cartridge-gated, so the
runnable tier is **21 suites / 212 cases**.
