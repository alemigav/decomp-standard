# M218 — WP1: the six project lists are named by their consumers, and the macro opcodes are not here

The audio review's first work package: decode the `SND_PROJ` group headers and find the macro opcode space. Both
have answers, and one of them is negative in a useful way.

## 1. The header, corrected

| offset | field | evidence |
|---|---|---|
| +0 | `u32` stride | 417 strides + the 4-byte terminator tile the 102 148-byte member exactly (92 distinct strides, 68…1092) |
| +4 | `u16` key | a bijection onto 0…417 less `11` |
| **+6** | **`u16` flag — 0 or 1** | **0 on 130 records, 1 on 287**, and `FUN_800a86a0` reaches `FUN_800adb48` **only when it is 1** |
| +8…+28 | six `u32` list offsets | each in record range, each a fixed position — **not** a sequence |

**I had this wrong earlier today.** My first dump of record 0 read `+6` as a constant 0 and I wrote "the record has
a pad at +6". It is a two-valued flag that the loader branches on, and one record is not a sample. The artefact
records the distribution, so the claim cannot be made from a single record again.

## 2. What each of the six lists is, by its consumer

| # | width | values | classes | consumer — and therefore what the list is |
|---|---:|---:|---|---|
| 0 | 2 | 3 468 | all **0** | `FUN_800ad62c` per key against the pool chain: the project's **sample binding**, the only feed that touches no cache table |
| 1 | 2 | 3 316 | all **0** | `FUN_800add28` walking the 12-byte registry at `0x8014e170` — the **registered-directory** feed |
| 2 | 2 | 261 | all **3** | `FUN_800ad0c0` → the key-sorted cache at `0x8014e1e0` |
| 3 | 2 | **4** | all **1** | `FUN_800acbc0` → the cache at `0x801521f0` |
| 4 | 2 | 339 | all **2** | `FUN_800ace1c` → the cache at `0x80152a00`, keyed by **key and rate** |
| 5 | **12** | 3 822 | — | **a record array, not keys**: `FUN_800adb48` stores `{key, count, pointer}` into the bank at `0x80157e20` when the flag is 1, and `FUN_800ae034` hands the array to `FUN_800ab43c` — a binary search at **stride `0xc`** through a comparison callback |

That is the whole "what are the other macro commands / what is a sound group" question answered at the container
level: a project record is **six typed feeds plus a flag-selected row array**, each feed carrying exactly one pool
class. The class split is total — 3 468 + 3 316 = 6 784 class-0 keys, 261 class-3, 4 class-1, 339 class-2 — with
**182 values that resolve to no pool class**, published as `unresolved` rather than dropped.

## 3. The macro opcodes are not in `SND_PROJ`, and that is the answer

`command_streams: 0`, `command_stream_candidates: []`. Nothing in the project file parses as an opcode stream: not
the six lists, not the 12-byte row array, not the record slack. The macro space therefore lives on the `SND_POOL`
side, and the artefact says which class to look in — the row array's `{key, count, pointer}` shape is a *directory*
of rows, and each row's `pointer` is where a program would have to begin.

That is the next work package's entry point, and it is a much narrower one than "decode all macros": follow
`FUN_800adb48`'s stores into `0x80157e20` and read what the pointer in each row addresses.


## 5. The base is wrong in four published milestones, and that is queued as M219

Decoding the lists correctly required establishing where they start, and the answer refutes earlier work. The
test is decisive: reading the six spans at **`record + 0 + offset`** makes them **overlap in 417 of 417 records**;
at **`record + 8 + offset`** they overlap in **0 of 417** — and `+8` is where the six offset fields themselves
begin, which is the base `FUN_800a86a0` adds.

Everything this project published about *list contents* was read at `record + 0`, so:

| claim | published | at the correct base |
|---|---|---|
| M185 — proj lists hold | 5 136 shorts, 4 301 pool keys (83.7 %) | **7 388 shorts (lists 0–4), 6 784 pool keys (91.8 %)** |
| M186 — "every list opens `[0, a, 0, b]`", 834 prologue zeros | a two-parameter prologue | **no such prologue**: the lists open on negative class-1/2 keys, and the "zeros" were header bytes |
| M186/M188 — 531 is a dangling reference | the pool's one hole | **it survives** — 531 is one of **4** distinct unresolved keys (`-32616, -16251, 531, 16385`); the *count* changes, the finding does not |
| M200/M202 — list 5 is the sample-to-parameter pairing, 142 + 148 keys | a u16 key list | **list 5 is a 12-byte row array** (`{key, count, pointer}`), 3 822 rows |
| M200 — list 2 holds 2 027 distinct keys | the whole sample space | **2 026** |

The *structural* claims survive because they never read a list: the 417-record chain, the `+4` key bijection onto
0…417 less `11`, the rotation from 118, and the tiling.

**Why this is queued and not done here.** Correcting it means re-deriving six gate cases across four milestones,
and two of the affected claims (the pool's hole at 531, and which sections the lists reference) need their own
measurement rather than a mechanical substitution — the first attempt to patch them raised `IndexError` because a
list position that used to have four entries has none at the right base. A rushed rewrite at the end of a long
session is how a base error becomes a second base error. **M219: re-derive the project lists at the correct base
and retract what does not survive.** The gate is green in the meantime because the file-table cases still assert
their old numbers; that is a stale gate, not a correct one, and the log's retraction table carries it.

## 6. Gates

`sound project (cartridge)`: **28 cases** — the 417-record chain tiles the member; each of the six offsets is in
range and parses to its declared terminator (list 5's differs by flag: `0xffffffff` when the flag is 0, count-prefixed
and unterminated when 1); the per-list widths match a fresh derivation; the class distributions sum to the value
counts; **and two source-shape cases** for the consumers (`*(short *)((int)param_1 + 6) == 1` is the flag gate;
`FUN_800ae034` walks the row array at `0xc` and `FUN_800ab43c` is the binary search).

Two mutations at the artefact: list 5 widened back to `u16` keys, and a command stream claimed where there is
none. Both are caught by the derivation comparison rather than by a semantic case — the same limitation M214
recorded, and the same reason: the artefact is wholly derived, so any edit to it is first a staleness.
