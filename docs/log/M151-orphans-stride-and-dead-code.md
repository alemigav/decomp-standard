# M151 — the 1 % was my own defect, the GoSub stride settles, and the dead-code list exists but is not proof

Three results, two of them retractions of M150 and one of them a measurement of mine that was wrong in the same
way twice.

## 1. The 1 % unreachable starts were an artefact of my own tool

M150 seeded **all** record starts into one shared node budget. Because the work list is a LIFO stack and the
budget is global, the earlier starts consumed it and the later ones were never expanded — which is exactly how
34 of block 3505's 35 records came out "unreachable". Giving **each start its own budget**:

| | M150 | now |
|---|---|---|
| record starts reached | 7 146 / 7 216 (99.0 %) | **7 216 / 7 216 (100 %)** |
| `0x00` reachable | 95.9 % | **100 %** |
| `0x20` reachable | 100 % | 100 % |

So **retraction (a)**: M150's "`0x00` reaches only 95.9 %, ~4 % genuinely skipped" was the same starvation
artefact. Both NOP aliases are fully executed; there is no skipped `0x00`.

Diagnosing it also produced a fact worth keeping: blocks **3507 and 3627 are byte-identical duplicates** — same
size, same record table, same head bytes — so the archive deduplicates nothing.

## 2. The GoSub stride is 2 — settled structurally, not by decode quality

M150 called the stride unresolved on the strength of a test that scored *decodability* (3.92 vs 3.73 commands
over 169 sites, 161 ties). That test was the wrong one: in these blocks **any offset decodes**, because the
data is dense with valid opcodes. The discriminating test is whether the computed target lands on a
**record-table entry**:

```
block 3505, every GoSub index sampled:
  idx  0 -> stride2 0x46  (entry)      stride64 0x46   (entry, coincidence)
  idx  4 -> stride2 0x2f6 (entry)      stride64 0x132e (not an entry)
  idx  6 -> stride2 0x396 (entry)      stride64 0x2d01 (not an entry)
  idx 15 -> stride2 0x978 (entry)      stride64 0xbfda (not an entry)
  idx 21 -> stride2 0xa7e (entry)      stride64 0x340f (not an entry)
```

Stride 2 lands on an entry **every time**; stride 64 essentially never does. **Retraction (b)**: the stride is
`2`, and the stride-64 candidate is gone from the model.

## 3. Seeding every record start is near-tautological — so the tool now has an entry mode

With every table entry as a seed, each record trivially "reaches" its own code, which makes the measure useless
for a dead-code question. `cfg_reach.py --entry` seeds **only record 0** — the room's real entry, the one
`FUN_8006d5dc(ctx, 0)` starts (M145). From that seed:

* **1 493 of 7 309 record starts (20.4 %)** are reached;
* **12 639** command starts are reachable, **54 476** are outside.

## 4. Opcodes that appear only outside entry-point-reachable code

Eight, with counts:

| opcode | count | name |
|---|---|---|
| `0x59` | 234 | `XaOn` *(licensed)* |
| `0x4c` | 100 | `SceEsprKill` *(licensed)* |
| `0x6a` | 51 | — |
| `0x62` | 38 | — |
| `0x5f` | 17 | — |
| `0x7a` | 15 | — |
| `0x71` | 14 | — |
| `0x7f` | 10 | — |

**These are not proven dead, and the licence names say why.** "Unreachable from record 0" is a *relative*
statement: those records may be entered by the **engine** rather than by any script path from record 0 — door
and event callbacks, or enemy scripts started by `SceEmSet`. The two licensed names in the list are
suspiciously consistent with that: `XaOn` (start XA audio) and `SceEsprKill` (kill an effect) are things an
engine-driven callback would do. What the result does establish is narrower and still useful: **no script path
from a room's entry point reaches those eight opcodes**, so any decoder run from `FUN_8006d5dc(ctx,0)`
will never encounter them.

## 5. Gate

`cfg reachability (cartridge)` is now **5/5** — the two artifact-dependent cases are replaced by two honest
ones: *every record start is reachable from some record start* (the directory is complete) and *restricting the
seed to record 0 leaves a large fraction unreached, so the two modes differ*. **133 cases across 14 fixtures**,
`ci.sh: ok`, 18/18 marker checks.

## 6. The lesson, written down because it is the second time

Both errors in this milestone were **my measurement**, not the code: a shared budget that starved later work
items, and a discriminating test (decodability) that did not discriminate. The project's existing rule — *a
mechanism check needs a non-vacuity condition* — would have caught the first, and *name the mechanism that
cleared each finding* would have caught the second. Recorded here rather than only in the log row.

```
python3 tools/cfg_reach.py --check       # 5/5, all record starts reachable
python3 tools/cfg_reach.py --entry       # from record 0: 20.4% of starts, 8 opcodes outside
python3 tools/acceptance.py              # 133 cases, 14 fixtures
```
