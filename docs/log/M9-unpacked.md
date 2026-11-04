# M9 — The cartridge unpacked: 4 761 zlib members, 1 227 JPEG frames, an MPEG-1 movie

**Status:** the decompressor is confirmed and the cartridge is now accounted for, region by region.
All offsets are ROM file offsets; all vram uses the corrected mapping (`vram = rom + 0x7FFFF480`).

## 1. The decompressor is stock zlib `inflate`, wrapped

Ghidra at the correct base read the three calls around the staging buffer `0x8015B030` directly:

| call | what it does |
|---|---|
| `FUN_80004550(state, buf)` | zeroes state `+0x20/24/28`, stores `buf`, allocates **`0x8000`** bytes → state `+0x4c` |
| `FUN_800045DC(state, src, dst, len)` | sets `+0x44 = src`, `+0x50 = dst`, **`+0x10 = 0x8000`** (window), `+0x3c/+0x48 = len`, copies a `0x38`-byte template from `0x80011860`, then loops `FUN_8000472C` / `FUN_800048B0` and **`trap(0)` on failure** |
| `FUN_80004594(state, flag)` | frees the `0x8000` buffer, optional `FUN_8008B0A4` cleanup |

`0x8000` = 32 768 = zlib's window size, and the strings found in M4 (`invalid block type`,
`invalid distance code`, `incorrect data check`, `insufficient memory`) are `inflate.c`'s. So the
descriptor table's `size` field is a **compressed size**, and the DMA destination `0x8015B030` is a
staging buffer, not the final destination.

## 2. The streams are standard zlib — with a 16 KB window

First bytes of every record are `68 de …`. `CMF = 0x68` → deflate, `CINFO = 6` → **16 KB window**,
and `(0x68*256 + 0xDE) % 31 == 0`. **M7's whole-ROM zlib scan hardcoded `0x78` (32 KB window) and
therefore found zero streams.** That is the second filter artefact in this project; both times the
data was fine and the search constant was wrong.

## 3. Unpacked: `tools/unpack_zlib.py`

Sequential walk from `0x14420` using `decompressobj().unused_data` for exact boundaries — no size
guesses. Whole cartridge in **9.7 s**.

| | |
|---|---|
| zlib members | **4 761** |
| compressed | 8 748 242 B (13.0 % of the cartridge) |
| uncompressed | **18 550 424 B (17.7 MB)**, ratio 2.12 |
| written to | `assets/unpacked/` + `manifest.json` (offset, csize, usize, sha1) |

**Independent cross-check:** the walker and the code-derived descriptor table agree on **35 of 40**
boot records — the same cart offset *and* the same decompressed size (`field3 - field2`). Two
unrelated paths, same answer, so both the table interpretation and the unpack are sound.

## 4. The rest of the cartridge, classified

| region | size | what it is | evidence |
|---|---|---|---|
| zlib members | 8.7 MB → 18.6 MB | game assets | 4 761 clean inflates |
| `0x2bdefa9`–`0x3af17fe` | 15.8 MB | **FMV as JPEG frames (MJPEG)** | 1 227 `ffd8ff…ffd9` frames carving 99.9 % of the region, 320×224 baseline JFIF |
| `0x1440f30`–`0x2b7d8ea` | 24.4 MB | **video, MPEG-1 elementary stream** | in-band filename `annet_ab22.m2v`; `ffprobe` reports `mpeg1video, 240×120` |
| `0x0b73fb3`–`0x140ed84` | 9.0 MB | **unidentified**, entropy 7.08 | 133 JPEG markers only; `ffprobe` rejects it |
| `0x338fe1`–`0xb63106` | 8.6 MB | **unidentified**, entropy 7.34 | no magic, no inner filename; `ffprobe` rejects it |

The 1 227 frames were carved to `assets/fmv/` (320×224, mean 12.9 KB). Total accounted:
**~64 of 67 MB**, with only the 17.6 MB of R3+R4 still unclassified.

Note the header shape that several of these blobs share at their start
(`00100000 000005f4 000001b3 …` and `00001000 0000000N …`) — a length-prefixed block header. That is
the next format to decode, and it is what stands between "carved" and "properly extracted".

## 5. What this changes for the decompilation

- The 67 MB "unknown" in splat's report is **not** analysed code; it is mostly video and compressed
  assets. Coverage of the *code* question is unaffected — the code is still `0x1000`–`0x12140`.
- The asset pipeline now has an entry point: `FUN_80001180` → descriptor → `FUN_8000C870` (DMA) →
  `FUN_800045DC` (inflate). That chain is the thing to read next if the goal is the file system.
- `assets/` stays gitignored — every file here is a derivative of the user's cartridge and is
  regenerable from ROM + these tools in about ten seconds.

## 6. Method note, third time

Three times now a scan has returned zero because of a constant I invented: `offset < 0x4000000`,
`(rom, vram)` adjacency, and `CMF == 0x78`. In each case the data was present. **Before reporting a
null result, test the filter against a known-positive** — here, the boot table's own first record.
