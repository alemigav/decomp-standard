# M149 — the two-NOP question, and three more reads (one of them a random number generator)

`0x00` and `0x20` do **not** differ in behaviour — they share one handler. What differs is how the data uses
them, and that took three failed measurements to establish honestly.

## 1. What can be decided, and what cannot

`0x00`, `0x1e`, `0x1f` and `0x20` all point at `0x8006db14`, which is four instructions:

```
0x8006db14  lw    v0,28(a0)      ; the command pointer
0x8006db18  addiu v0,v0,1        ; advance 1
0x8006db1c  sw    v0,28(a0)
0x8006db20  jr    ra
0x8006db24  addiu v0,zero,1      ; return 1
```

So **no interpreter can distinguish them**; whatever differs is in the data. On decoded sequences (not raw
bytes) the difference is sharp:

| | `0x00` | `0x20` |
|---|---|---|
| count | 16 573 | 7 753 |
| most common predecessor | `0x02` ×7 202, itself ×3 993 | **itself ×7 147** |
| runs | short | 606 runs, **median 10, p90 31, max 62**; 191 runs ≥ 20 covering 5 254 occurrences |

`0x20` therefore marks **long empty stretches**; `0x00` pads **between commands**. Named `~Nop` and `~Fill`,
with the caveat stated in the fixture: which opcode an interpreter actually *executes* at a given position is
decidable only by reachability, and our reachability test cannot decide it yet (see §2).

## 2. Three measurements that failed, recorded so they are not repeated

* **"Trailing bytes after the last decoded command".** A record's code **jumps around inside itself**, so
  "the bytes after the last linearly-decoded command" is not padding — the measure produced 2.7 MB of
  "tail", median 34 B per record, which is nonsense on its face.
* **Raw-byte run analysis.** 94 642 maximal `0x20` runs with 85 265 of length 1 — yet the decoded sequences
  contain 7 147 `0x20 → 0x20` pairs. The contradiction is the tell: most `0x20` bytes are **operand bytes**,
  not opcodes. Any byte-level statistic here is measuring the wrong thing.
* **Reachability from record starts.** Marked **96 %** of both opcodes' positions unreachable, because the
  CFG walk stops at the five dynamic opcodes (`0x03`, `0x10`, `0x19`, `0x1a`, `0x36`) — a test with no power,
  since it measures where the walker stops, not what executes.

What *did* work was measuring what sits **immediately before a record start**: `0x00` in **3 746 of 6 185**
cases (61 %), with `0x01` two bytes earlier in 3 661 — i.e. records end `01 00` and then begin. That is a
bonus finding: **`0x01` is the record terminator** and `0x00` pads the record to an even boundary. It also
retroactively explains `0x01`'s classification as `dynamic` at M145 ("no pointer write at all, returns 2") —
a terminator needs to do neither.

## 3. Three more reads

| opcode | count | len | name | evidence |
|---|---|---|---|---|
| `0x28` | 1 175 | 1 | `~Rand` | `0x8006eae0` advances 1 and calls `FUN_8006d284`, which is a **generator**: `seed = seed + ((seed & 0x7fffffff) >> 15) + (seed & 0x7fff8000)*2`, result halfword to `DAT_800e8cb2`. Followed by itself 1 018× — several rolls in a row. |
| `0x05` | 732 | 2 | `~ClearSlot` | `0x8006dbf4` reads byte 1 as an index, computes a 0x6c-strided entry in the table at `0x80113ad0`, and clears **byte 1** of it — a per-slot deactivate. |
| `0x88` | 681 | 3 | `~CountdownSlot` | `0x800728ec` advances 3, calls `FUN_8008c51c(byte1)`; for a non-negative result it indexes `0x800c76b0 + idx*8 + 0x20000`, subtracts byte 2 from the counter at 6169, and when that reaches zero clears 6168/6169/6170 and calls `FUN_8008c568`. |

`~Rand` is the one worth pausing on: a **random number generator inside the script VM** means room logic can
be probabilistic — which is exactly what `0x28` appearing 1 175 times and self-following 1 018 times looks
like (repeated rolls, e.g. for enemy spawn placement or item drops).

## 4. State

**45 licensed + 17 inferred = 62 of 141 named**, 79 unnamed. Profile regenerated with the new names and
provenance; counts unchanged. **128 cases across 13 fixtures**, `walk_stream --self-test` 22/22, `ci.sh: ok`,
18/18 marker checks.

## 5. What the two-NOP question still needs

Reachability, done properly: a CFG walk that does not stop at the dynamic opcodes. That requires modelling
the per-thread state they use — the block-return slots at `ctx + thread*8 + 0x20`/`+0x60` for `0x10`/`0x1a`
(the GoSub return slot at `ctx+0x144+idx*4` is already modelled) — which is a bounded piece of work and the
prerequisite for any "executed vs filler" claim, here and for every other positional question.

```
python3 tools/walk_stream.py --lens        # 141 classified; 45 licensed + 17 inferred
python3 tools/script_profile.py            # sweep with name_source
python3 tools/acceptance.py                # 128 cases, 13 fixtures
```
