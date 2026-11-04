# M214 — 50 of 1 049 are room scripts, and the other 999 now have names for what they are

M156 refuted "1 049 scripts" as a *population* and the docs have carried the refutation ever since. This milestone
replaces it with a partition: every one of the 1 049 candidates in `fixtures/scd/profile.json` lands in exactly one
category, with the evidence that put it there.

## 1. The partition

| category | count | evidence |
|---|---:|---|
| `room_table` | **50** | the file id is an entry of `DAT_80131fa8`, the table the room loader reads |
| `code_referenced` | **0** | no file id appears as a word reachable from executable code |
| `script_referenced` | **0** | no GoSub-style script-table reference leaves the classified set |
| `heuristic_only` | **485** | decompresses and decodes, but nothing references it |
| `not_a_script` | **514** | fails the decoder's own criterion |

**50 of 1 049 = 4.8 %**, which is the number that settles M156: 95.2 % of the population is not a room script. The
147-id room table agrees by two routes — the cartridge-inflated stage 2 and `cfg_reach.room_script_ids()` — and
M158's earlier accounting (48 container + 43 other + 6 non-zlib) is consistent with the 514.

## 2. Two empty categories, and why empty is not blind

`code_referenced` is **0**, and the tool proves the scan can see: it anchors on a *derived* file-table accessor —
`0x80004930` (entry = `base + 8*id`, `v0,0(a0)` / `v1+v0`), with `0x80004c9c` for sizes and `0x80004cfc` for reads
into a buffer, reached by `file_table.py`'s own sound ids 1979–1983 and each carrying the 8-byte stride — rather
than on bare immediates. A case then shows the anchor filters: **18** bare immediate matches collapse to **4**
call arguments and **0** accessors, because the 18 are coordinates, struct fields, draw-call arguments and
`0x84xxxxxx` RSP microcode data embedded in the image. A scan that had simply found nothing would not have
earned that 0.

`script_referenced` is 0 by *mechanism*: the reference is a `u8` index into the block's own `u16[]` table, so it
cannot point outside the block. The refused numeric alternative is recorded in the artefact's `refused` field, so
the negative is inspectable.

## 3. A disagreement worth keeping

The M213 decoder admits **34 375 instructions** where `walk_stream`'s linear walk counts **102 673** on the same
5 111 records. That is not a bug in either: the walker follows fall-through through bytes the decoder refuses.
**907 blocks contain a refusal** — 2 349 truncated, 638 unknown opcode, 192 unresolved at record level — and 110
refuse at the first byte. Both numbers are published; neither is called the right one.

## 4. Gates

`script population (cartridge)`: **13 cases** — all 1 049 present exactly once; each category count matches its
list; `room_table` is exactly the room table's file ids; every `code_referenced` entry carries an instruction
address; the accessor anchor is shown to be load-bearing; every `not_a_script` states why; the artefact equals a
fresh derivation byte for byte and stays under 4 MiB.

Two mutations, both at the totals: `room_table` 50 → 49 and `not_a_script` 514 → 513. Both are caught by the
derivation comparison rather than by the per-category case — recorded here because it tells a future editor that
the totals are guarded by *staleness*, so a hand-edited total is caught but a wrong derivation would not be.
