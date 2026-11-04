# M153 — both leads closed: the dead-only list falls from 8 to 2, and the stream exits were right

Closing the two leads M152 left open changed the answer in one direction and vindicated the decoder in the
other.

## 1. Lead 1 — the `0x10` empty-stack pops, and a generous closure

Classifying the pops that stopped a record-0 walk:

| openers seen before the pop | blocks |
|---|---|
| **0** — the pop is the record's **first** command | **115** |
| 1 | 11 |
| 3 | 6 |
| 7 / 15 / 31 / 63 | 1 each |
| 127 / 511 — my stack depth cap of 24 was hit | 1 each |

So the dominant case is not a deep structure I failed to model: **115 blocks begin with a `0x10` return**. A
record that starts by popping is a fragment — it only makes sense entered by a caller.

Rather than guess the caller, the model now takes the **sound direction**: when a pop cannot be resolved, the
walk resumes at **every record start** in the block. Nothing that could be reached is then missed, at the cost
of over-approximating reachability. The effect:

| | M152 (empty stack = stop) | generous closure |
|---|---|---|
| record starts reached from record 0 | 1 493 / 7 309 (20.4 %) | **2 384 / 7 309 (33.2 %)** |
| opcodes only outside reachable code | **8** | **2** |

**Six of M151's eight were artefacts of the empty-stack stop**: `0x59 XaOn` (29 occurrences now reachable),
`0x5f` (4), `0x62` (5), `0x71` (2), `0x4c SceEsprKill` (1), `0x6a` (1). Only two survive:

| opcode | count | len | what it does |
|---|---|---|---|
| `0x7a` | 15 | 16 | indexes a **stride-76** table at `*(ctx+0x154)+0x234` by byte 2, ORs `0x4a` into a flags word, packs bytes 3/4/5 into one word at `96(entry)`, and writes five u16s from bytes 6–15 into `304`–`316` — an object/effect setup |
| `0x7f` | 10 | 6 | walks the object table `*(0x800c76b0+0x20000)+636` at **stride 20**, indexing by bytes 1, 2, 3 — the same table `0x6b`/`0x7c` write (M145) |

Both are object/table manipulation in records that no path reaches, in blocks of the kind that begin with a
return.

## 2. Lead 2 — the ~250 stream exits were correct behaviour, not a defect

Every walk that "left the command stream" did so on a byte **≥ `0x8d`** — and `0x8d` is one past the last table
index, so such a byte **cannot be an opcode at all**:

```
stop bytes: 0x90 ×31, 0xcd ×18, 0x98 ×15, 0xa0 ×15, 0xff ×11, 0xa8 ×10, 0x8d ×8, 0x8e ×8 …
all stop bytes >= 0x8d?  True
```

64 of them stopped on the record's **first** byte, i.e. that offset points at data and the block is not a script
record at all — the heuristic's false positives, not decode errors. Two conclusions:

* the decoder does **not** wander into data; it stops exactly where a command region ends;
* the M152 worry ("worth one pass to see whether these are length errors") is resolved: they are not, and no
  fix is needed. `Switch` case tables were already ruled out (687 of 923 had no `Switch` nearby), and this
  closes the alternative explanation too.

## 3. Where the claim now stands

The theory is refuted by code (M152: every engine call starts index 0), and the observation has narrowed from
eight opcodes to **two**, under a model that over-approximates reachability. The remaining gap is explicit and
small: the 115 blocks whose record 0 begins with a return are fragments by nature, so "reachable from record 0"
is not well-defined for them — they are the one place a hidden caller could still exist, and the code search
found none.

Stated plainly: **`0x7a` and `0x7f` appear only in records that neither the engine nor any script path from
record 0 can enter.** That is a stronger statement than M151's eight, and the same statement — not a proof of
universal deadness, because a proof would need the 115 fragment blocks resolved, which needs a caller that the
code does not contain.

## 4. Gate

No suite changes: **133 cases across 14 fixtures**, `cfg_reach --check` 5/5, `ci.sh: ok`, 18/18 marker checks.
The measurements in this milestone are scripts over the corpus, recorded here with their numbers so the next
session can re-derive them.

## 5. What is left, honestly

* **The 115 fragment blocks.** Either they are genuinely unreferenced library data, or something outside the
  36 images starts them. A bounded search for code that writes `ctx+0x1c` directly (rather than via
  `FUN_8006d5dc`) is the remaining test.
* **`0x7a` and `0x7f` naming.** Both read as object-table writers; the next dozen reads should start there,
  since they are now the only opcodes with no execution evidence at all.
