# M161 — the display-list reading, tested and refuted

The proposal was specific: the 16-byte records are N64 GBI display list commands, the opcode is the high byte of
word 0, and the payload is a texture. That is exactly the kind of claim this project tests rather than adopts, and
it fails its own test on every record.

## 1. The opcode census: 0 of 1 355

| high byte of word 0 | records | share |
|---|---|---|
| `0x01` | 364 | 26.9 % |
| `0x00` | 221 | 16.3 % |
| `0x20`, `0x2f`, `0x17`, `0x3f`, `0x11`, `0x07`, `0x12`, `0x2a`, `0x2c`, `0x31` | 18–27 each | ~1.5 % each |

**Records whose first byte falls in the GBI command window `0xE4–0xFF`: 0 of 1 355 (0.0 %).** Not a cluster of
`0xFD`/`0xF3`/`0xE6` — none at all. The 8-byte variant of the same test fails too: the high byte of **word 2**
(where an 8-byte command's opcode would sit) is `0x00` (620), `0xff` (460), `0xb2` (113), `0xfe` (82) — colour-like,
not opcodes.

So these are **not display lists**, and the "pre-compiled TMEM loader" reading does not survive its first check.

## 2. The texture reading: no clean signal

If the payload were a raw RGBA5551 texture, the alpha bit (bit 0 of each 16-bit unit) would be strongly biased —
near all-set or all-clear depending on convention. Measured over **1 062 058** 16-bit units: **38.4 %** have it set.
And the most common 16-bit values are `0x0000`, `0x00ff`, `0x3fff`, `0x7fff`, `0x7f00`, `0x7f7f` — mask-shaped
rather than colour-shaped. Payload sizes take **264 distinct values**.

Not proof of "not a texture", but the reading that would have followed from a confirmation is not supported either.

## 3. The constants are data, not code

`0xb2b2b2ff` and `0x7f7f7fff` occur **zero times** in the 1 172 240-byte stage-2 image. So whatever they mean, the
code does not build them: they are carried in the data. That weakens "graphics state set by code" and leaves
"graphics *content*" as the live reading — the constants sit in the records, not in the renderer.

The RGBA reading of those two words (grey-178 and grey-127, alpha 255) remains plausible; what does not follow is
that the records are commands. A 16-byte *record of values* — four words, two of them mid-grey with full alpha and
one a small integer — is equally consistent with a **quantisation or dither table**, which is also what the
mask-shaped payload values suggest.

## 4. What the milestone changed

* The container's framing (M159/M160) is untouched: magic, `N`, payload length, payload at `16·N`, `N` records.
* The record's **content** reading is now narrowed by elimination: not GBI commands (§1), not clean RGBA5551
  (§2), not code-generated constants (§3).
* Three **new gated cases** encode the refutations, so no future session can quietly revive the display-list
  reading: the GBI census must stay zero, the alpha-bit share must stay in the inconclusive band, and the
  constants must stay absent from code. Plus an audit entry that widens the GBI window to every byte and makes
  the census case fail: **14/14 audits, 0 vacuous**.

## 5. Gate

`01 41 container (cartridge)` is now **11 cases**; **164 cases across 17 fixtures**, `ci.sh: ok`, 18/18 marker
checks.

## 6. Where this leaves the pipeline

The honest status is that the **framing** of this resource is decoded and its **content** is not, and the two
candidate readings that would have explained it (display list, raw texture) are now excluded by measurement
rather than by opinion. The next productive step is not another guess at the semantics but a **corpus-wide
comparison**: these 355 blocks are one kind among 2 447 code-bearing and 2 050 other blocks, and a block whose
payload is mask-shaped and whose records hold mid-greys is more likely to be a *palette-plus-mask table* for
something else in the same corpus than a standalone asset. Finding which blocks reference these ids is the
cheap discriminator — and that is a population question, which is where this project's recent progress has come
from.
