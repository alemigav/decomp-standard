# M166 — `h1` is the true height, not a stride

Audited against both candidate readings across all 65 tiles:

| hypothesis | fits |
|---|---|
| `h1 == h` — a second height, same for both formats | 44 / 65 |
| **`h1 == h·8/bpp`** — the true pixel height, `h` being its 8-bit equivalent | **65 / 65** |
| `h1 == w·bpp/8` — row stride in bytes | **2 / 65** |
| `h1 == stride/8` — row stride in 8-byte words | **0 / 65** |
| `w·h1·bpp/8 == pixel bytes` — h1 is the height that accounts for the data | **65 / 65** |
| `w·h·bpp/8 == pixel bytes` — h is that height | 44 / 65 |

So the stride reading is dead (2/65 and 0/65), and `h1` is the **height**. The second field at offset 6 is not a
duplicate: it is `h1·bpp/8`, i.e. the height expressed in **one byte per pixel** — which is why the two coincide
for 8 bpp and differ by a factor of two for 4 bpp. That also completes M165's nibble result: a 4 bpp tile with
`h1 = 64, h = 32` holds 64·64 = 4 096 pixels in 2 048 bytes, and `w·h1·bpp/8 = 2048` is exactly what the file
carries.

## The header, final

| offset | field | meaning |
|---|---|---|
| 0 | `0xBE1E` | magic |
| 2 | **height** | true pixel height (`h1`) |
| 4 | **width** | |
| 6 | **height, 8-bit units** | `h1·bpp/8` |
| 8 | **format** | 1 = 4 bpp (16-entry TLUT, 2 indices/byte), 2 = 8 bpp (256-entry TLUT) |
| 10 | **palette entries** | 16 / 256 |
| 12, 14 | zero | |
| 16… | palette | `entries` × RGBA5551 |
| … | pixels | `width × height` at 4 or 8 bpp, raw |

## Gate

`01 41 container` is now **27 cases**, four of them about `h1`: it equals `h·8/bpp` on every tile; `w·h1·bpp/8`
equals the pixel byte count on every tile; and both stride readings are refuted with explicit bounds (≤ 2 and
0). **181 cases across 17 fixtures**, `ci.sh: ok`, 18/18 marker checks, audit 15/15.

## Where the container stands

Every field of the 16-byte T64 header is now either **decoded and gated** (magic, height, width, 8-bit height,
format, palette count) or provably zero. The two open questions from M165 are down to one: whether the engine
shares palettes between tiles (the file duplicates them per tile), which is a question about *usage*, not format —
and that one is answered by reading `FUN_800874d4`'s callers rather than the data.
