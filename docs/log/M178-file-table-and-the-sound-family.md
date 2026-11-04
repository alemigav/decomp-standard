# M178 — the file table is the file system, and the 17.6 MB is the sound family

Every milestone since M146 used `cart_record(0x43)` (`0xb00c8624`) as a **zlib manifest**, because the
files it was first used on — room scripts — are zlib members. It is not a zlib manifest. It is the whole
file system, and **39 % of it is stored raw**:

| | | |
|---|---|---|
| entries | **8 091** | header word 0 |
| sentinels | **113** | `offset 0xFFFFFFFF, size 0` — and no half-formed variant exists |
| real | **7 978** | |
| → begin `68 DE` and inflate | **4 852** | 8 167 529 B stored |
| → do not | **3 126** | **58 270 043 B** stored |

The 3 126 non-zlib entries are the media, stored uncompressed: their heads are `ffd8ffe0` **×1 257**
(JPEG SOI/JFIF) and `000001b3` **×271** (MPEG-1 sequence header) — which reproduces M9's independently
carved counts (1 227 frames, 271 blocks) from a completely different direction. No `[0x80][u24]` prefix
exists: payloads start exactly at `0xC8624 + off`, and precisely the 4 852 that inflate begin `68 DE`.

## 1. The 17.6 MB is two files, and it is the sound family

"R3" and "R4" were never regions between files. Each is **one entry**:

| | id | cart extent | size |
|---|---|---|---|
| was "R4" | **1979** | `0x0338fea`–`0x0b630fe` | 8 560 916 B |
| was "R3" | **1983** | `0x0b73fbc`–`0x140ed7c` | 9 022 912 B |

Sum **17 583 828 B**. M9's region bounds (M9 §4) sit 9 B outside the head and 8 B outside the tail of
each file — the region estimates were 17 bytes too generous on each blob, which is why "unidentified"
looked like a gap rather than a boundary.

Both are named by the sound initialiser, `FUN_800759d8`:

```c
iVar5 = func_0x80004cfc(0x7bc, dst, 0, "SND_PROJ");     /* 1980 */
iVar5 = func_0x80004cfc(0x7bd, dst, 0, "SND_POOL");     /* 1981 */
iVar5 = func_0x80004cfc(0x7be, dst, 0, "SND_SMPDIR");   /* 1982 */
DAT_8011a704 = func_0x80004930(0x7bf);                  /* 1983 */
uVar3        = func_0x80004930(0x7bb);                  /* 1979 */
FUN_800b3f54(uVar3, 0);
```

and the 69 310 bytes between the two blobs are **exactly ids 1980, 1981 and 1982** — the three files the
code tags on the way in. So the family is ids **1979–1983**, contiguous in cart order with no padding,
and the entire 17.6 MB belongs to the audio subsystem.

## 2. id 1979's format is decoded

`FUN_800b3f54` consumes `[u32 count][count × u32]` — `*param_1` is stored as the count, `param_1 + 1` as
the table, and `count << 2` bytes are copied. The file is exactly that, followed by `count` records:

```
header   u32 588
         588 × u32  `0x01000000 | offset`
           first offset == 4 + 4·588 = 2356 = the table's own end
           587/587 ascending, 588/588 in range (max 0x828b08, file 0x82a114)
record   `MORT`  u16 field  u16 rate  u16 0        then payload
           magic `MORT`            588/588
           rate ∈ {16000, 8000}    588/588
           word at +8 == 0         588/588
```

The top byte of each directory word is **not a flag**. It is clear on 23 of the 588 offsets, and those 23
are **set-identical** to the 23 records whose rate is 8 000 Hz — a bijection, not a coincidence, and the
reason the constant `0x01000000` should not be masked off as if it were padding.

## 3. What is deliberately not claimed

* **`u16` at +4 is unassigned.** It ranges 26–7 647. It is not the record length — `len == 32·field`
  holds **0/588** — and no constant header size makes the payload a multiple of 16 or of 9
  (10-byte header: **0/588** and 59/588). So the natural guess "16-byte VAG/DSP frames" is *refuted for
  this container*, not confirmed, and R4's entropy of 7.925 (vs R3's 7.169) is a property of 588 framed
  records with headers, not of one opaque blob.
* **`MORT` has no assigned meaning.** It is the ASCII at every record start and nothing more is known.
  It is a fourcc candidate, kept labelled.
* **Whether id 1983 is audio at all is inferred.** Its head reads as small signed 16-bit values and it
  carries no `MORT` and no count structure (word 0 read as a count would be 4 264 033 908), but no code
  reading of a parser for it exists. The evidence is the call site, not a format.
* **The 8 bytes after id 1979** read `00 01 00 00 00 82 a1 14`, where `0x0082a114` *is* 8 560 916 — its
  own size. Recorded as a measurement, not explained.

## 4. The third-party lead, checked and refuted

`zrksyd/N64-Tools` defines `#define RESIDENTEVIL2 18`, which reads like a dedicated codec. It is a game
id in a 19-entry list, and its entire implementation is three lines: emit `0x68, 0xDE` and start inflating
at offset 2 (`GECompression.cpp:462`, `:561`). **It is stock zlib with CMF `0x68`** — the same
16 KB-window variant `docs/format_notes.md` §3 records, found here from the cartridge. Two directions,
one answer.

The tool's other RE2 claim — that the table is `[flag][u24 addr]` at cart `0x2C794`–`0x2EFD8`, flag `0x00`
raw and `0x80` compressed — is **refuted on the bytes it names**. That span holds 2 577 words whose
first byte takes no flag distribution at all (`0x00` and `0x80` together are **0.6 %** of it, where a flag
byte requires 100 %), and its `(u24 < romsize)` acceptance test cannot fail for any 64 MB cartridge. Its
*structural* half — that a raw class exists — is correct, and §1 above is that class, at a different
table.

## 5. The 91 unaccounted members, closed

M9's walker finds **4 761** zlib members; this table names **4 852** zlib entries. The difference is not
a missing class:

* 4 852 entries resolve to **4 726 distinct offsets** — **126 entries are repeats over 67 shared offsets**;
* **every** one of those 4 726 offsets is a member the walker found (**0** table-only);
* the walker finds **35** members the table does not name, and they are the early boot/stage members
  addressed by the *descriptor* table (§2), not by the file table.

4 726 + 35 = **4 761**, exactly.

One negative worth keeping: cart `0xB6248`–`0xC8624`, the 28-payload non-zlib container of M82/M90, has
**no owning entry** in the file table. It is not a file, which fits it being addressed by the 16-byte
load list and rules out reading it as one.

## 6. What this changes

* "The two unidentified blobs" is retired as a phrase. The cartridge is accounted for: 4 852 zlib
  members, 58.3 MB of raw media, and the sound family.
* R4 is not a blob to be attacked with codecs. It is a 588-record bank with a decoded directory and a
  10-byte record header, and its payload codec is a per-record question — a much smaller search than
  8.5 MB of unexplained entropy.
* The open question in the sound family is now **`u16` at +4**, and it is answerable from the record
  extents alone.

## 7. Gates

New suite `file table (cartridge)` — **20 cases**: the census and its arithmetic, the two file
identities and their 9/8-byte relation to M9's bounds, the contiguity of ids 1979–1983, the five `MORT`
laws, the 23/23 flag/rate bijection, the two refutations that keep `u16@+4` and the 16-byte framing
unsolved, id 1983's negative structure, the 4 726 + 35 accounting, and the N64-Tools refutation. Four
mutation audits, one of which reinstates **this tool's own first bug** — the entry offsets are relative
to `0xC8624`, and slicing the cartridge with one double-counts it, which reads a plausible file out of
the wrong place and still looks sane. Audit **30/30, 0 vacuous**; every new mutation was verified by hand
to fail on its intended case (15/20, 19/20, 19/20, 19/20), not by exception.

The repository is now **28 suites / 297 cases**, of which **12 suites / 133 cases** are cartridge-gated
and report `SKIP` without the cartridge — the four new audit cases are gated with the suite they audit,
so the runnable tier stays 16 suites / 164 cases.

`tools/file_table.py --report` prints the census for a human. The suite needs the cartridge **and**
`assets/unpacked/` (for the 35), both regenerable in ~20 s.
