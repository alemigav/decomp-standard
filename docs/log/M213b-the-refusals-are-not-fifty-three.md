# M213b — the 53 refusals are 59, and 51 of them are model containers read as scripts

M213 left a number that read like a defect count: 53 rooms refused to decode. A refusal is *honest* — the decoder
raises rather than skipping a byte — so the useful next step was to turn each one into something a researcher can
act on. Doing that changed the count, and the reason is the finding.

## 1. The partition closes at 59, not 53

Sweeping all 256 rooms through the decoder's own strict path:

| | rooms |
|---|---:|
| decoded cleanly | **107** |
| refused | **59** |
| no block entry at all | **90** |
| total | **256** |

M213 reported 53 refused, and **107 + 53 + 90 = 250**, so six rooms were unaccounted for. They are the sixth kind:
file-table entries that **do not inflate at all** — 17–33 byte ASCII labels (`"Police Memorandum"`,
`"OPERATION REPORT"`, `"MAIL TO THE CHIEF"`, `"FILM R"`). The room table names a *text resource* for those rooms,
not a script. With them counted, the partition closes on 256, and `refused` is 59.

## 2. The four work items, and what the biggest one actually is

| kind | rooms | what settles it |
|---|---:|---|
| `record_start_not_code` | **38** | the block is a **`01 41` container** — word 0 is `0x01410000`, so the record table's first `u16` is the magic's halfword (`0x141`) and the seed lands inside the payload. Not a script; a model container the room loader (0x8009b27c) reads differently |
| `unknown_opcode` | **13** | the same population, misaligned one byte — the same non-script, not a missing opcode |
| `other` | **6** | the ASCII labels above |
| `unresolved_advance` | **2** | rooms 6 and 21 reach **`0x36`**, which dispatches through `*(0x800c98e0 + (s16[cmd+4] >> 8) * 4)` — a callback, correctly unmodelled |

So **51 of the 59 refusals are one thing**: blocks that are not scripts, being decoded as scripts. That is not a
decoder defect and it is not 51 research problems — it is one question, *what is a `01 41` container doing in the
room-sound table*, and the repository already knows the format (`01 41` is the model container, version 321,
relocated by `FUN_800824b8`).

**And it is a warning worth recording:** all 51 rooms with an unknown opcode byte are `01 41` containers. Do not
add `0xff` or `0x94` to the opcode registry on their strength — the bytes are payload, not commands.

## 3. Gates

`script vm refusals (cartridge)`: **9 cases** — the sweep partitions 256 exactly; `refused` is one row per
refusal and `by_kind` counts them kind for kind; `no_block` is sorted, unique and disjoint from `refused`; every
refusal files under exactly one work item and the counts agree; every work item states its next step; the
artefact is under the 4 MiB tracking limit; and a **re-sweep reproduces every room's kind, pc and message**.

Two mutations, each verified against its own case: one refusal filed under a kind that has no work item, and a
`refused` total that no longer matches the rows. Both first attempts anchored on strings that repeat in the
artefact, and the M216 lint caught that in 0.04 s — the rule working on the person who wrote it.
