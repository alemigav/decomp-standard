# M147 — the whole file table swept: 102 673 commands, every opcode seen, and the shape of a scenario

All 8 091 entries are swept, and the profile is committed as `fixtures/scd/profile.json`. It is **counts and
opcode numbers only** — no cartridge bytes — so it describes the script *format* without carrying any of the
game's content.

## 1. What the sweep found

| | |
|---|---|
| entries in the cart file table | **8 091** |
| zlib blocks | 7 978 |
| **script blocks** | **1 049** |
| records walked | 5 111 |
| **commands decoded** | **102 673** |
| opcodes ever seen | **141 of 141** |
| named (from the MIT table) | 45 |

Rejections, stated because they bound the claim: **3 126** entries are not zlib, **3 803** decompress but do
not look like scripts (models, TIMs, audio), **113** are empty. "Script block" is a **heuristic**, not a proof:
it decompresses, its head is a plausible u16 record table, and record 0 decodes into at least four commands
with known opcodes.

## 2. The profile, and what it says

Top of the distribution, with the opcode each is most often followed by:

| opcode | count | len | name | most common successors |
|---|---|---|---|---|
| `0x00` | 16 573 | 1 | — | `0x17`×6379, `0x00`×3993, `0x26`×641 |
| `0x06` | 9 105 | 4 | `IfElseStart` | `0x23`×6672, `0x21`×1706, `0x3e`×213 |
| `0x02` | 9 010 | 1 | — | `0x00`×7202, `0x30`×473, `0x0e`×229 |
| `0x20` | 7 753 | 1 | — | **`0x20`×7147**, `0x00`×377 |
| `0x23` | 6 791 | 6 | `Compare` | `0x02`×6261, `0x04`×102 |
| `0x17` | 6 610 | 6 | `Goto` | `0x06`×6168, `0x00`×134 |
| `0x08` | 2 259 | 2 | — | `0x08`×976, `0x06`×258 |
| `0x21` | 2 125 | 4 | `CheckBitTest` | `0x06`×432, `0x22`×271 |
| `0x09` | 1 730 | 1 | `Sleep` | `0x0a`×1363 |
| `0x18` | 1 317 | 2 | `GoSub` | `0x06`×321, `0x18`×204 |
| `0x2e` | 1 440 | 3 | `WorkSet` | `0x00`×1255 |
| `0x22` | 1 387 | 4 | `SetBit` | `0x22`×473, `0x04`×114 |

The skeleton of a scenario script is visible in those numbers, and it agrees with the door script decoded at
M146:

* **`IfElseStart` → `Compare`** (6 672) — the header is immediately followed by the condition it tests;
* **`Compare` → `0x02`** (6 261) — whatever `0x02` is, it is what a comparison is followed by, so it is
  plausibly the branch/body marker;
* **`0x00` → `Goto`** (6 379) and **`Goto` → `IfElseStart`** (6 168) — the loop closes: no-op padding, a jump,
  and the next conditional. That is exactly the `IfElseStart … Goto -12` cycle M146 decoded;
* **`Sleep` → `0x0a`** (1 363) — a wait, then its partner;
* **`0x20` → `0x20`** (7 147) — a long self-run, which is what padding looks like. `0x20` shares the
  one-byte NOP handler with `0x00`/`0x1e`/`0x1f` (M136), so the most likely reading is **fill**, and the
  distinction between `0x00` and `0x20` is now an interesting question rather than an unknowable one.

Frequency alone would not have said any of that; the context column is doing the work, which is why it is
part of the schema.

## 3. Two bugs in my own profiler, both caught by cross-checks

* **Flat bigrams across records.** My first version concatenated every record's commands into one list, so
  the last command of a record was counted as adjacent to the first of the next — inventing a bigram at every
  boundary. Counting per record changed the ranking materially (`0x00`'s top successor moved off `0x00`).
* **`sort_keys=True` destroyed the ranking.** The successors were a dict, and `json.dump(..., sort_keys=True)`
  re-sorted its keys alphabetically, so the committed file claimed `IfElseStart` is followed by `0x05` (25
  times) when the truth is `0x23` (6 672). The data was right and the serialisation lied; successors are now
  an **ordered list of pairs**, and the ranking survives a round trip.

Both were caught by comparing against an independent recount and against `walk_stream`'s CLI output on id
1881 — which is now a permanent case in the suite (`the profile walker agrees with the CLI on id 1881's
record 0`).

## 4. Limits, stated

* Counts are **lower bounds**: the walker stops at the five non-return dynamic opcodes (`0x03`, `0x10`,
  `0x1a`, `0x36`, `0x01`) and at `0x19` when its stack is empty, so anything after such a point in the same
  record is uncounted.
* At most **8 records per block** and **200 commands per record** are walked.
* The script/not-script split is a heuristic; a block that happens to begin with a plausible table but is not
  a script would be counted.
* Only `{opcode → count}` and `{opcode → successor counts}` are stored. No byte content, no offsets, nothing
  that could reconstruct a script.

## 5. Gate

New cartridge-gated suite `script profile (cartridge)` — 5 cases: the sweep finds script blocks, it decodes a
substantial number of commands, most opcodes are seen, `DoorModelSet` appears (as a door script implies), and
the profiler agrees with the CLI. **126 cases across 13 fixtures**, `ci.sh: ok`, 18/18 marker checks.

## 6. What this makes possible

* **Naming the 96 unnamed opcodes from context.** `0x02` (after `Compare`, 6 261), `0x0a` (after `Sleep`),
  `0x30`, `0x08`, `0x84`–`0x87` and `0x20` (padding) now each have a frequency, a length and a habitual
  company — the three things needed to pick the next dozen reads.
* **Pseudocode.** With `IfElseStart`/`Compare`/`Goto`/`GoSub`/`Sleep` named and their operands sized, a
  printer from decoded commands to something readable is a small step, not a research project.
* **Per-room coverage.** 1 049 script blocks against 8 091 entries means the remaining script-ish entries can
  be hunted by the same route M146 used for `DOOR_SCD`.

```
python3 tools/script_profile.py            # sweep and print the summary
python3 tools/script_profile.py --check     # 5/5, needs the cartridge
python3 tools/acceptance.py                 # 126 cases, 13 fixtures
```
