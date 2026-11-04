# M158 — the section-table hypothesis is refuted, and the room table turns out to be a resource table

The parse was run on the 27 blocks (and then all 48 of the family) and the answer is clean: **there is no section
table**. What the parse did establish is what the descriptor is, and that changes what the room table means.

## 1. The header, read properly

```
id 1931 (2192 B):
  01 41 00 00 | 00 00 00 02 | 00 00 08 70 | 00 00 00 00 | 00 00 00 00 | 00 00 00 04 | b2 b2 b2 ff | 7f 7f 7f ff
  word0 magic 0x01410000   word1 count = 2   word2 payload = 0x870 = filesize-32
  word3,4 zero             word5 = 4 or 5    word6,7 = mask-like constants
```

So the "count byte at +7" from M157 is the low byte of **word1**, and the size field from M157 is **word2** — the
header is a **24-byte-plus descriptor**: magic, count, payload length, flags/masks. There is no per-section
offset/size array.

## 2. The test, and its result

* **No section table at `+32`** in any of the 48 blocks: the u16s there are `0, 0, 0, 0, 0x94, 0xf781`, not an
  ascending offset table.
* Candidate layouts of 8/12/16/20-byte entries starting at `+32` were tried and **none stays in bounds** on any
  block — an empty intersection, not a partial fit.

So the natural reading of M157 — "the room's script is one section among 1–5" — **is wrong**, and the
"record-table-at-offset-0" layout of the other 50 is not a single-section instance of it.

## 3. What the descriptor family actually is

Scanning the whole corpus for the magic:

| kind | blocks |
|---|---|
| starts with an opcode (`< 0x8d`) | 2 447 |
| `01 41` descriptor family | **355** |
| other | 2 050 |

Within the family the count field takes values **1, 2, 3, 4, 11, 15, 17**, and the size relation
(`word2 == filesize − 32`) holds **only for the count-2 subset** (40 blocks). So the header's length semantics are
count-dependent, or my field boundaries are wrong for the other counts — **the format is not decoded**; only its
magic is identified. Recorded as such rather than generalised from the 40.

## 4. The consequence for the population question

`DAT_80131fa8`'s 147 ids lead to a **mixture of resource kinds**:

| kind | ids |
|---|---|
| script-shaped (u16 record table at 0) | **50** |
| `01 41` descriptor family | 48 |
| other | 43 |
| not zlib | 6 |

So the table is a **scene → resource** table, not a script table. M145's reading — that `0x8009b27c` loads a
room's *script* — is correct for the 50 entries that are scripts, and M156's population of **50 room scripts**
stands; but the neighbouring 97 ids are other resources, not scripts we failed to parse. That is the cleaner
version of M157's finding: it was not "we modelled a third of the population", it was "we modelled the
population, and the population is 50".

## 5. What this closes and what it opens

* **Closed**: the section-table hypothesis (0 of 48, no candidate layout in bounds), and with it the worry that
  five milestones were decoding a fraction of the room scripts.
* **Opened**: the `01 41` family — 355 blocks, sizes 160–64 496 B, count field 1–17 — is now the largest
  identified-but-undecoded resource kind in the corpus. Its payload starts with zeros and constants, not code.

## 6. Gate

No tool change was needed: `cfg_reach --check-rooms` still reports 50 blocks, 468 records, zero stream exits.
**150 cases across 16 fixtures**, `ci.sh: ok`, 18/18 marker checks, audit 11/11.

## 7. The rule, third time

M156: the population was wrong (1 087 → 50). M157: the bound was wrong (285 → 147). M158: the *kind* was
assumed — 97 of those 147 were never scripts, and no model of a script could have parsed them. Each iteration of
asking "is this population real?" moved the question, and none of the three could have been caught by a gate
that only checks whether a mechanism can fail.
