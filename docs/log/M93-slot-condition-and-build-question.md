# M93 — the slot condition fully traced, `cart_record(0)` is a *crash* path, and the build question

## 1. `s1`, shown

The audit is right that the previous trace asserted the conclusion without showing the instruction
that makes it. Full window, with `s1`'s definition included:

```
0x80032890  2465fff0  addiu a1,a0,-16      ; a1 = slot - 16
0x800328c0  2ca20010  sltiu v0,a1,16       ; v0 = ((slot-16) < 16) = slot < 32
0x800328c4  10400002  beq   v0,zero,d0     ; slot >= 32 -> skip the clamp
0x800328c8  00808821  addu  s1,a0,zero     ; DELAY SLOT (always): s1 = slot
0x800328cc  24110010  addiu s1,zero,16     ; executed only when slot < 32: s1 = 16
0x800328d0  24020010  addiu v0,zero,16
0x800328d4  16220017  bne   s1,v0,0x80032934  ; taken iff s1 != 16 iff slot >= 32
0x800328d8  00008021  addu  s0,zero,zero   ; DELAY SLOT (always): s0 = 0
0x800328dc  24100001  addiu s0,zero,1      ; executed only when the branch is NOT taken
```

`s1` is `slot` or the clamp `16`, so `s1 == 16 ⟺ slot < 32`, and **`s0 = 1` iff `slot < 32`**. The
conclusion stands; it now derives from a shown definition rather than from an assumption. (The
mitigation for this class, as the audit says, is showing five or six instructions instead of the
branch and its delay slot — direction is not toolable the way address arithmetic is.)

## 2. `cart_record(0)` is not a no-op — it is an out-of-cartridge inflate

The 16 bytes at `0x80012150` are the marker itself:

```
4f 56 45 52  4c 41 59 54  41 42 4c 45  4e 55 4d 43     "OVERLAYTABLENUMC"
record[0] = 0x4f564552      -> cart pointer 0x0f564552 — the cartridge is 0x04000000, so ~4x past its end
record[1] = 0x4c415954      -> NOT zero: branch 0 does not fire
record[2] = 0x41424c45      }
record[3] = 0x4e554d43      }  span = 0x0d1300fe != record[1]: branch 1 does not fire
                            -> branch 2: inflate(0xb0000000 + 0x0f564552, dest, 0x4c415954)
```

So a slot in **17–31** does not "read the header harmlessly": it asks the loader to inflate
**1.28 GB from a cart address four times the cartridge's size**. That is a crash-class path, distinct
from slot 16's silent failure, and the watch at `0x80071ebc` should therefore cover **`[16, 32)`** and
report which of the two it is:

| slot | map byte | record | branch | effect |
|---|---|---|---|---|
| **16** | 39 | 39 (bank C) | 2 | zlib rejects non-`CM==8`; return discarded; destination unchanged |
| **17–31** | 0 | 0 (`OVERLAYTABLENUMC`) | 2 | inflate from `0x0f564552`, length `0x4c415954` — out of range |
| 32–49, 51, 52, 54–56, 58, 59, 62, 63 | 11–38 | bank B | 1 or 2 | the live path |

`0x80071ebc` is `lbu a0, 3(v0)` (`0x90440003`) — the load of the slot byte, immediately before
`jal FUN_8003287c` at `0x80071ec0`. That is the right watch site: it sees `a0` right before the call.

## 3. The stamp record's fragility is different from what the audit supposed

`s0`-independent check of record 67's fields:

```
b0 0c 86 24  cd cd cd cd  00 00 00 00  00 00 00 00
record[0] = 0xb00c8624   -> cart pointer 0x0c8624 (the stamp)
record[1] = 0xcdcdcdcd   -> NOT zero, so branch 0 does NOT fire
record[2] = record[3] = 0
```

So the stamp record does **not** survive by hitting `record[1] == 0`. It survives because **nothing
passes it to `FUN_800327ec` at all**: boot calls `cart_record(67)` at `0x80004964` and then reads
field 0 itself as a pointer (`a0 = lw 0(v0)` → `0x0c8624`) with length `0x28`, straight to a
copy/DMA. Had any code handed record 67 to the loader, branch 2 would fire with length
`0xcdcdcdcd` — a 3.4 GB inflate from the stamp.

That is the fragility worth recording: **the stamp record is only safe because of which function
reads it**, not because of its own field values.

## 4. The dev-build question: three signals, all weak

| signal | measurement | reading |
|---|---|---|
| build date | **two** stamps: boot data `RE.093099.1542` (Sep 30 1999 15:42) and cart `0xc8624` `Tue Sep 28 02:31:44 1999` | two days apart — one build, late September 1999. RE2 for N64 shipped in North America in **October 1999**, so a late-September master is what a retail build looks like, not what a prototype looks like |
| `0xCDCDCDCD` | **exactly 1 occurrence in the whole 64 MB cartridge**, at `0x13104` — a single record field | the audit's own test ("if it appears in multiple places it is a dev-build marker") **fails**: one word in one field is not a fill pattern, it is one uninitialised field or one coincidence |
| `d:/bio2/prog/em00_0.bin` | a Windows path in `.rodata`, unreferenced (M89) | the PSX original was built on Windows and its volume/path names survive in ports; retained build paths are common in retail N64 titles |

Header, for completeness: title `Resident Evil II`, cart id `NREE`, CRC1 `0xaa18b1a5`, CRC2
`0x07db6aeb`. **This repository cannot settle it further**: `n64info.py` deliberately does not
reimplement the N64 CRC table and refuses to claim a CRC verdict, so a known-good comparison needs an
external database.

**Conclusion: no evidence of a non-retail build.** The one thing the audit is right about is the
*conditionality* of my claims — every finding in M81–M93 is a statement about **these bytes**, so
"dead data", "bank C is not compressed" and "311 KB swing" all already mean "in this cartridge". If
the cartridge later proves to be a prototype, they remain true of it; only their generalisation to
retail would need the qualifier, and none of them was ever generalised.

## 5. Minor items

* **"Same 28 slots" clarified**: the two maps occupy the *same slot positions*
  (16, 32–49, 51, 52, 54–56, 58, 59, 62, 63) but map them to **different records** — `array1` to
  11–38, `array2` to 39–66. Same positions, different mappings.
* **Where `0xCDCDCDCD` lives**: exactly one place, record 67's `stored` field at `0x13104` (ROM) /
  `0x80012588` (vram). "The reader ignores it" means the boot consumer reads only field 0.
* **The table layout, bounded exactly**:

```
0x80012150   record 0      the "OVERLAYTABLENUMC" marker (4 ASCII words)
0x80012160   records 1-66  66 * 16 = 0x420, ending at 0x80012580
0x80012580   record 67     the stamp descriptor (pointer 0x0c8624, stored 0xCDCDCDCD)
0x80012590   zlib static inflate tables
```

  68 entries, no overflow — and any `cart_record(i)` for `i > 67` reads zlib's tables.

## 6. Next

1. **Watch `0x80071ebc` for `a0` in `[16, 32)`** — and report *which* value, because 16 and 17–31 are
   different failures (silent stale destination vs an out-of-cartridge inflate).
2. If it is ever 17–31, that is a genuine bug in this build and worth its own note.
