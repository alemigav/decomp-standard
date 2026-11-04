# M148 — a dozen opcode reads, and a second naming source that cannot be confused with the first

Twelve of the unnamed opcodes are read and named — descriptively, from their own handlers — taking the named
count from 45 to **57 of 141**. The names live in a **separate fixture** from the licensed table, and the tool
prints them with a `~` so provenance is never ambiguous.

## 1. The dozen

| opcode | count | len | name | what the handler does |
|---|---|---|---|---|
| `0x02` | 9 010 | 1 | `~CondEnd` | advance 1, **return 2** (the `0x00` NOP returns 1); follows `Compare` 6 261× |
| `0x08` | 2 259 | 2 | `~EndBlock` | pops the frame (`ctx+0x140 -= 4`), advances 2, drops the thread's block depth |
| `0x0a` | 1 628 | 3 | `~WaitCount` | decrements a u16 at `160(thread)` and **does not advance** until it expires |
| `0x0e` | 985 | 2 | `~LoopWhile` | same counter, but while non-zero reloads `ctx+0x1c` from a saved slot at `32(thread)` |
| `0x2f` | 844 | 4 | `~SetMotion` | writes a u16 operand to `344(ctx + slot*8)` — the halfword `0x30` reads |
| `0x30` | 1 361 | 1 | `~ApplyMotion` | adds `ctx+344/346/348` into position 40/44/48 and `ctx+350/352/354` into angles 100/102/104 |
| `0x81` | 1 080 | 3 | `~StateDispatch` | tests a global flag `& 0x80`, loads a table byte at 6169, dispatches on both operands |
| `0x82` | 827 | 3 | `~ReleaseByKey` | clears 124-byte table entries whose field 108 matches `FUN_800717a0(byte1, byte2)` |
| `0x84` | 1 232 | 2 | `~SndMode` | mode byte 4, flag 1, ORs `0x8000` into a state word at 6748, stores byte 1 as status |
| `0x85` | 693 | 6 | `~SndPlay3D` | calls `FUN_8006ab40` with **two 3-axis vectors** (objects' 40/44/48) plus `u16@4`, `u8@3` |
| `0x86` | 767 | 1 | `~SndBusy` | advances 1, returns `u16@7476 != 0` — a predicate |
| `0x87` | 705 | 1 | `~SndStop` | advances 1, writes `0x01000000` to `4404(0x800e…)` |

Five families fall out of that:

* **condition/block scaffolding** — `~CondEnd` and `~EndBlock`, which pair with the licensed `IfElseStart`
  (0x06), `ElseStart` (0x07) and `Compare` (0x23): the corpus's modal sequence is now
  `IfElseStart → Compare → ~CondEnd` and `… → Goto → IfElseStart`;
* **timed waits** — `~WaitCount` and `~LoopWhile` are both **blocking**: they leave `ctx+0x1c` untouched until
  a 16-bit counter expires, so the dispatcher re-runs the same command. That is a new *mechanism* fact, not
  just a name: it explains why `Sleep` (0x09) is followed by `~WaitCount` 1 363 times;
* **motion** — `~SetMotion` writes the halfword `~ApplyMotion` consumes, a producer/consumer pair;
* **state and effects** — `~StateDispatch` branches on a global flag, `~ReleaseByKey` frees table entries by
  key;
* **sound** — `~SndMode`, `~SndPlay3D` (two positions ⇒ a positioned source), `~SndBusy`, `~SndStop`.

## 2. Two naming sources, kept apart on purpose

`fixtures/scd/opcodes.json` is transcribed from MIT-licensed OpenBiohazard2 and carries the **original
developers'** names. `fixtures/scd/inferred_names.json` is ours, read from the handlers, and its entries carry
an `evidence` string naming the instructions the reading rests on.

The rule the code enforces: a licensed name always wins; an inferred one is printed with a leading `~`; the
profile records `name_source` per opcode so no consumer can quietly treat the two as equal. Two fixture cases
hold it: the overlay loads `0x84` as `SndMode`, and `0x07` still reports its licensed `ElseStart`, not any
inferred name.

## 3. The profile now says which names are whose

`fixtures/scd/profile.json` regenerated: **45 licensed + 12 inferred + 84 unnamed**, with `name_source` on every
entry. Counts are unchanged (the sweep is the same), so the file's diff is names and provenance only.

Two numbers worth noting from it: **`SceEmSet` (0x44) fires 953 times** and **`DoorModelSet` (0x4d) 494** — the
enemy-set command is not exotic, which makes M145's "byte 3 is an `Id`" the operand to profile next.

## 4. A guard firing on me, twice

`patch_text.py` refused a spec of mine with *"`old` and `new` are identical — that is a no-op by
construction"*: I had built a replacement and never applied it to the string I passed as `new`. The same
mistake — spec built, patch not really made — bit this session at M145. The tool caught both. That is two
independent saves in four milestones, which is the best argument yet for every edit going through it.

## 5. Gate

**128 cases across 13 fixtures**, `walk_stream --self-test` **22/22** (two new naming cases), `ci.sh: ok`,
18/18 marker checks.

## 6. What is left unnamed — and what it looks like

| opcode | count | len | habitual successor |
|---|---|---|---|
| `0x00` | 16 573 | 1 | `0x17 Goto` 6 379× |
| `0x20` | 7 753 | 1 | `0x20` 7 147× |
| `0x01` | 1 862 | — | dynamic (returns 2) |
| `0x28` | 1 175 | 1 | `0x28` 1 018× |
| `0x05` | 732 | 2 | `0x05` 280× |
| `0x88` | 681 | 3 | `0x88` 378× |

`0x00` and `0x20` share the one-byte NOP handler (M136) and both run in long self-runs, so the open question
there is not *what* they are but *why two* — probably two different fillers (skip vs padding), which the
record-level context can answer. `0x28`, `0x05` and `0x88` are the next three reads by frequency.

```
python3 tools/walk_stream.py --lens        # 141 classified; 45 licensed + 12 inferred names
python3 tools/script_profile.py            # the sweep, now with name_source
python3 tools/acceptance.py                # 128 cases, 13 fixtures
```
