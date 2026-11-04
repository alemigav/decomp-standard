# M4 — ROM structure without disassembly

2026-10-30. Tool: `tools/scan_banks.py` (byte-level, 2.2 s for the whole ROM, no Ghidra).

## Code region: now confirmed by three independent methods

| Method | Says code ends around |
|---|---|
| splat segment analysis (M2) | ROM `0x12140` |
| Ghidra function bodies (M2 partial) | within the same window |
| byte fingerprints — `jr ra` + `addiu sp,sp,-N` density | top blocks all ≤ ROM `0xF000`, nothing above `0x12000` scores |

Three unrelated techniques agreeing is the strongest boundary statement the project has.

## The ROM is banked — proven

Histogram of every in-range pointer (`0x80000000–0x803FFFFFF`) in the cartridge:

```
total in-range pointers: 30,687      distinct 64 KB buckets: 64
span: 0x80000000 .. 0x803F0000        (= the full 4 MB of RDRAM)
most common: 0x80000000 (4,401)  0x80070000 (907)  0x80060000 (723)  0x800F0000 (665)
             0x80300000 (657)   0x803A0000 (626)   0x801D0000 (619)
```

Pointers reach every 64 KB of RDRAM. A flat single-image layout cannot produce that:
the game loads code/data to many VRAM bases. **The boot bank — the only part analysed so
far — is the 0x80000000 cluster.**

## Pointer tables found

Seven runs of ≥8 consecutive pointers, all clustered immediately *after* the code end:

| ROM offset | entries | target range |
|---|---|---|
| `0x000128B8` | 84 | 0x8000F618 – 0x8000FA58 |
| `0x00012490` | 16 | 0x80004DCC – 0x80004E98 |
| `0x00012310` | 14 | 0x80003220 – 0x800036D0 |
| `0x000133B0` | 11 | 0x80011870 – 0x800118E8 |
| `0x000121D8` | 10 | 0x8000174C – 0x80002158 |
| `0x00012238` | 10 | 0x80002474 – 0x80002A68 |
| `0x000124F0` | 9 | 0x800009C4 – 0x80000C68 |

Every target lies inside the boot bank, so these are **function/data pointer tables**, not
load descriptors. They sit in a tight 4 KB cluster right after the code — likely the
game's own tables for initialisation.

## What did not work

A scan for adjacent `(rom_offset, vram)` record pairs — the naive shape of a load table —
found **zero** runs of ≥5 records. So the mapping is not stored as plain pairs. Options
remaining: a packed/compressed table, per-entry file IDs resolved through code, or a
structure with a header the naive scan cannot see.

## Next step

Read the 84-entry table at ROM `0x128B8` by hand (it is the largest and densest), and
identify the loader routine in the boot bank that consumes it. That is the shortest path
to converting 67 MB of `bin` into VRAM-anchored segments.

---

## Correction: the 0x128B8 table read (2026-10-30)

I read the 84-entry table by hand. **It is not a load table**, and my earlier note
guessing "the game's own tables for initialisation" was wrong.

**Shape:** 84 slots, but only **9 distinct targets**, all inside a 0x440-byte window
(`0x8000F618`–`0x8000FA58`); **68 of 84 slots hold the same pointer `0x8000FA58`**. A
load table needs 84 distinct (offset, vram) descriptors; this is a **dispatch table with a
default handler**.

**What surrounds it** (run-length dump of `0x12840`–`0x12A40`) is the giveaway:

- integers `1, 2, 4, 8, 0x10` — a powers-of-two table;
- doubles `0x4341C37937E08000` = **1e16** and `0x4693B8B5B5056E17` = **1e32** — the newlib
  `p10` table used by `printf`/`dtoa`;
- ASCII filenames from `assert` messages: `epirawread.c`, `pirawread.c`, `sirawdma.c`,
  `sirawread.c`, `sirawwrite.c`, `sprawdma.c`.

Those are **libultra's own I/O source filenames**. So this whole region is the libultra
runtime — C library data plus PI/SI device code — not game logic, and the 84-slot table is
a **libultra I/O dispatch table**. The targets `0x8000F618`–`0x8000FA58` are therefore
libultra routines.

### Two consequences

1. **Part of the 243 "functions" is libultra, not RE2.** Those can be *named from public
   SDK sources* instead of reverse-engineered — a real saving, because libultra is
   documented and its code is identical across N64 games of this era.
2. **A reusable naming lever:** embedded `.c` filenames give file-level attribution. A
   whole-ROM pass found **145 ASCII runs containing `.c`**; the strictly-filename-shaped
   ones are `epirawread.c`, `pirawread.c`, `sirawdma.c`, `sirawread.c`, `sirawwrite.c`,
   `sprawdma.c` (+ 4 noise strings). Extract these with their addresses and they anchor
   which functions belong to which subsystem.

### Still open

The real ROM→VRAM load table remains unfound. It is not plain `(rom, vram)` pairs and it
is not this table. Next candidates: the loader routine itself in the boot bank (search for
the code that writes PI registers / calls `osPiStartDma`), or a table keyed by file ID.
