# M157 — the rule applied backwards: every earlier population, audited

M156's lesson — *before modelling a population, prove the population* — run retrospectively. Each milestone's
headline claim is listed with the population it rests on, and each population is now either **proven**,
**assumed**, or **refuted**. Three proofs and two refutations came out of it, one of them on M156 itself.

## 1. Populations proven today

| claim (milestone) | population | verdict |
|---|---|---|
| the unpacked corpus is every zlib member (M85, M129) | 4 761 members covering 8.5 MB of 67 MB | **proven**: the 58.4 MB left uncovered sits in 4 744 gaps, and **no zlib stream inflates anywhere inside them** (0 found, scanning every offset whose two bytes form a known zlib header). The corpus is complete with respect to zlib. Limit: the scan is header-dependent, so a stream with an unusual `FLG` byte would be missed — stated, not glossed |
| the dispatch table has 141 entries (M95) | words from `0x80113898` | **proven**: 141 non-zero words, a zero terminator at `0x80113acc`, and zeros beyond it |
| the file table has 8 091 entries (M146) | `cart_record(0x43)`, `0x28` header | **proven**: header word 0 is the count, the build stamp follows, and every entry parses |

## 2. Populations refuted today

**(a) M156's own room table read — 285 ids was an overrun.** `DAT_80131fa8` is indexed by a **byte**
(`*(byte *)(DAT_800dfb58 + 0xc)` in `0x8009b27c`), so **no entry past 255 can ever be selected** — a provable
bound. M156 read 400 entries and thereby took 138 entries of neighbouring data for ids:

| | M156 published | correct |
|---|---|---|
| entries considered | 400 (assumed) | **256 (provable from the byte index)** |
| distinct ids | 285 | **147** |
| zero entries | — | 90 |
| ids with a script block | 50 | **50** |

The *conclusion* survives (50 room scripts, zero stream exits, the three object-table writers absent) — only
the denominator was wrong, and the ratio changes from "50 of 285" to **"50 of 147"**. `cfg_reach.ROOM_TABLE_MAX`
is now 256 with that reasoning in the constant's comment.

**(b) The layout covers a third of the room population, not all of it.** Of the 147 room ids:

| layout | ids | what it is |
|---|---|---|
| u16 record table at offset 0 | **50** | the layout every milestone since M146 has decoded |
| **32-byte container header** | **48** | starts `01 41 …`, a **count byte at +7 taking values 1–5**, and a big-endian **u32 at +8 which equals `filesize − 32` in 27 of 48** cases |
| other | 93 | includes the 50 scripts above and the container blocks' neighbours |
| not zlib | 6 | loaded by a different path |

So **five milestones modelled about a third of the room-script population** and never noticed that a third of
it carries a container header instead of a record table. The size field's meaning holds in 27 of 48 — a partial
reading, recorded as such rather than rounded up to a format.

## 3. The retrospective table

| milestone | headline claim | population | verdict |
|---|---|---|---|
| M95 | 141-entry handler table | the table in the image | **proven** (§1) |
| M99/M136 | every handler advances by its own constant | the 141 handlers | **assumed** — corrected twice since (M142 per-start extents, M154 `0x0f`), and still 3 opcodes unexplained (`0x09`, `0x26` sizes) |
| M111–M123 | census 111 179 operands, 13 567 attributed (12.2 %) | stage-2 code, 3 292 functions, 61.3 % decompiled | **assumed** — the population is "whatever Ghidra found", and the 61.3 % decompile rate is itself the evidence that the rest was never examined |
| M121/M122 | `--stk-check` 0 of 14 371, `--arg-check` 0 of 43 293 | call sites in decompiled code | **assumed**, same reason: zero *flagged* among what was decoded is not zero in the code |
| M110 | bank C closed: slot 31 in three rooms | 8 dumps, 3 rooms | **assumed** — the population is one playthrough; M110 said so explicitly |
| M129 | synthetic cartridge runs the corpus machinery | 16 synthetic words | **proven** for the machinery, never claimed for the format |
| M146 | a room script decodes from the cartridge | file id 1881 | **proven for that block**, and now known to be one of 50 with that layout |
| M147 | 1 049 script blocks, 102 673 commands | every zlib member passing a heuristic | **refuted as a population**: 95 % are not room scripts (M156) |
| M151–M154 | dead code / orphans / stream exits | the same over-broad set | **refuted** as to population; re-asked of the 50 room scripts in M156 |
| M155 | the gates can fail | 11 mechanisms | **proven by mutation** — and note it could not have caught §2(b) |

## 4. What to quote from now on

* members: **4 761**, complete w.r.t. zlib (§1)
* handler table: **141** entries (§1)
* file table: **8 091** entries (§1)
* room ids: **147** (not 285), of which **50** decode today and **48** need the container header modelled
* room-script dead-code residue: **two opcodes, five occurrences** (`0x8a`, `0x8b`) — measured on the 50

## 5. The next question, and it is a population question again

The 48 container blocks are the largest unmodelled piece of the room population. Their header gives a **count of
1–5** at offset 7 and a payload length at 8 — the natural reading is a **section table with 1–5 entries**, i.e.
the room's script is one section among several, and the "record table" layout of the other 50 is what a
single-section container looks like once unpacked. That is a hypothesis with a cheap test: for the 27 blocks
where the size relation holds, parse the 32-byte header as a section table and check whether any section
contains a u16 record table.

## 6. Gate

`cfg_reach --check-rooms` still 3/3 with the corrected 256 bound; **150 cases across 16 fixtures**, `ci.sh: ok`,
18/18 marker checks, audit 11/11. The tool change is a constant and its comment; the conclusions it governs did
not move, which is the point — the audit was of the *denominator*.
