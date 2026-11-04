# M165 — the T64 tiles decoded: no compression, a palette and raw indices

The compression hypothesis is **refuted**, and the format is now fully described. The "anomalous" data lengths
were never compressed — they carried a **palette** nobody had accounted for.

## 1. The law

```
data length = palette_entries × 2  +  width × height × bpp/8
```

**65 of 65 tiles.** No compression, no padding, no exceptions. The header is 16 bytes:

| offset | field | values |
|---|---|---|
| 0 | magic `0xBE1E` | constant |
| 2 | `h1` | 32 / 64 / 128 — **still unidentified** |
| 4 | **width** | 32 / 64 / 128 |
| 6 | **height** | 16 / 32 / 64 |
| 8 | **format** | **1 = 4 bpp, 2 = 8 bpp** |
| 10 | **palette entries** | 16 (fmt 1) / 256 (fmt 2) |
| 12, 14 | zero | |

then `entries` × **RGBA5551** colours (2 bytes each), then the pixels.

## 2. Both formats verified independently

| format | tiles | test | result |
|---|---|---|---|
| **1 — 4 bpp (CI4)** | **21** | every nibble ≤ 15, and exactly `2·w·h` nibbles | **21/21** |
| **2 — 8 bpp (CI8)** | **44** | one byte per pixel, exactly `w·h` of them | **44/44** |

The nibble reading is what closed it: at 4 bpp a byte holds **two** indices, so 2 048 bytes carry 4 096 indices —
which is why the `fmt=1` tiles first looked impossible (indices reaching 255 against a 16-entry palette). Read as
nibbles, the same bytes are all ≤ 15, exactly as a 4 bpp image with a 16-colour TLUT requires.

## 3. What this also explains, in hindsight

* **M161's "no clean RGBA5551"**: the payload was never 16-bit colour — it is **4/8-bit indices**. The RGBA5551
  values exist only in the palette at the head (16 or 256 entries), which is also why "mask-shaped" values like
  `0x3fff`/`0x7fff` showed up in a 16-bit scan of what are really packed nibbles and index bytes.
* **M164's "descending RGB555 gradient"**: that was the **palette**, read correctly as colours, at the point where
  the palette starts. The reading was right; the object it was attributed to was wrong.
* **M159/M160's `N`-record prologue** belongs to the *model* container (`01 41`), not to these tiles — the tile
  format has no `N` records at all, which is why no correlation with it was ever going to fit.

## 4. What remains unknown, precisely

* **`h1`** (32/64/128) — consistent within a tile but unexplained. It equals neither width nor height in general
  (id 5922: `h1`=32, w=64, h=32; id 5980: `h1`=128, w=32, h=64), so it is not a dimension. A row stride, a TMEM
  tile width in 8-byte units, or an atlas slot is the plausible shape; nothing measured yet distinguishes them.
* Whether the **palette is per-tile** (it is stored per-tile here) or shared in the engine's own use of the
  format — the file duplicates it, which is itself worth knowing.

## 5. Gate

`01 41 container` is now **23 cases**, four of them the format law: every tile's length equals
`palette·2 + w·h·bpp/8`; the 4 bpp tiles have nibbles ≤ 15 and `2·w·h` of them; the 8 bpp tiles have `w·h`
bytes; and both formats are present, so the law is not one format's special case. **177 cases across 17
fixtures**, `ci.sh: ok`, 18/18 marker checks, audit 15/15.

## 6. The container thread, closed

```
T64 tile = [0xBE1E][h1][w][h][fmt 1|2][entries][0][0]
           palette: entries × RGBA5551
           pixels : w·h at 4 bpp (nibbles) or 8 bpp (bytes)   -- raw, uncompressed
```

That is a complete, gated description of a resource kind that was, four milestones ago, an unexplained
`0x01410000` family. The remaining unknowns are one header field and the engine's use of the palette, both stated
as such rather than rounded off.
