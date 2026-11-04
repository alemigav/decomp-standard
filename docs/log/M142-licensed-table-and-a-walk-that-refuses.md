# M142 — the licensed table is imported, the walk refuses to guess, and M141's own correction was wrong

Both halves landed: `fixtures/scd/opcodes.json` (names, from MIT-licensed source) and a length resolver that
**stops** instead of advancing by a number the handler never performs. Doing the second honestly exposed an
error in M141 that has to be recorded first.

## 1. The correction: M141's "16 handlers contain several advances" was an artifact

M141 reported that 16 handlers hold several advance constants, and concluded that M136's "one length per
opcode" was wrong. **The direction was right and the evidence was not.** The advance scan used Ghidra's
function ends as bounds — and for a whole family of these handlers **Ghidra has no function range at all**
(the tiny thunks at `0x8006db28`, `0x8006dc74`, …). Those fell through to a fixed ±512-instruction window,
which walks straight into the **neighbouring handler** and collects *its* advances. That is why opcode
`0x00` — a five-instruction NOP — appeared to hold `[1,2,3,4]`.

The extent is now:

```
min( next handler address in the dispatch table,
     next Ghidra function start,
     handler + 0x1000 bytes )
```

and the classification across all 141 opcodes becomes:

| class | count | meaning |
|---|---|---|
| **ok** | **117** | exactly one advance inside the handler's own extent — walk by it |
| **unverified** | **24** | *no* advance inside that extent |
| **ambiguous** | **0** | several advances, and the table cannot choose |

So the truth is not "16 handlers have several lengths"; it is "24 handlers have **none**". M136's published
number for those 24 came from somewhere *outside* the handler, which is precisely the failure mode M141 was
trying to describe.

Two corrections follow immediately:

* **`0x2d ObjModelSet` now measures 38** — exactly the PlayStation size — where M136 published **3**;
* **`0x46 AotReset` now measures 10** — exactly the PlayStation size — where M136 published **2**.

Of the **37** walkable opcodes that have a PlayStation entry, **35 match the size exactly**, and only **two
conflict**:

| opcode | name | our measured advance | PlayStation size |
|---|---|---|---|
| `0x09` | `Sleep` | 1 | 4 |
| `0x26` | `Calc` | 6 | 5 (`Calc`) / 4 (`Calc2`) |

Both are reported by `--lens` with `(ps1 size … disagrees)` rather than silently reconciled — the port's own
advance is what the console does.

## 2. Why 24 opcodes are `unverified` — and it is not all a gap

**Seven** of the 24 are named, and **five of those are the control-flow family**:

```
0x07 ElseStart   0x0d ForStart   0x13 Switch   0x17 Goto   0x18 GoSub
0x32 PosSet      0x37 ScaIdSet
```

For the five control-flow commands, "no constant advance" is the **semantics**, not a missing measurement:
a `goto`/`gosub`/`for`/`switch`/`else` sets the command pointer from an operand — the `addu a1,a1,t0`
flavour M98 identified as the second advance flavour. A decoder for those needs their **jump targets**,
which the PlayStation sizes locate (`Goto` 6, `ForStart` 6, `Switch` 4, `ElseStart` 4, `GoSub` 2).

The other 17 (`0x01`, `0x03`, `0x10`, `0x11`, `0x19`, `0x1a`, `0x1b`, `0x27`, `0x31`, `0x33`, `0x36`, `0x48`,
`0x49`, `0x6b`, `0x7c`, `0x7e`, `0x7f`) are unnamed and unresolved — genuinely open.

## 3. What was built

**`fixtures/scd/opcodes.json`** — 45 opcode numbers, **46 variants** (`0x26` carries both `Calc` 5 and
`Calc2` 4), each entry a name plus the PlayStation command size. It carries an `attribution` block naming
the source repository, its **MIT** licence, the file transcribed (`fileio/rdt_scd.go`) and the method
(field sum, no padding). This is the first artifact in this repository derived from **licensed** source
rather than inferred from the binary, and it is committed *because* MIT permits it.

**`walk_stream.py`** now has `ps1_opcodes()`, `handler_extent()`, `advance_set()` and `resolve()`, with
statuses `ok` / `unverified` / `ambiguous`, and:

* `--lens` prints `opcode, handler, length, status, name, advances` and fails only on ambiguity;
* the walk prints `opcode 0x44 SceEmSet len 22` and `Id(byte3)=…` for the enemy command, and **stops loudly**
  on `unverified`/`ambiguous`:

  ```
  opcode 0x07 ElseStart — STOP: no advance inside its own handler. Walking on would advance by a
  guess and desynchronise the rest of the walk.
  ```

**The fixture grew from 8 to 15 cases** — seven new ones for the new machinery, including the two that were
failing before the fix: *"a handler with no advance is unverified, never guessed"* and *"two advances plus
one matching ps1 size → the table decides, and names it"*. Writing them caught two defects in my own new
code: `advance_set` broke after the first advance (so `ambiguous` was unreachable), and the name was taken
from the variants' list order instead of the chosen size.

**Gate**: `walk_stream length map 15/15`; **105 cases across 10 fixtures**; `ci.sh: ok`.

## 4. What is left

* **`0x32 PosSet`** — the one opcode of the original "unexplained" pair still open (`0x46 AotReset` is now
  settled at 10). Its handler is `0x8006fe44`; the PlayStation size is 8 and our scan finds nothing inside
  the extent, so it needs reading, not scanning.
* **Jump semantics** for the five control-flow opcodes, which is what turns `unverified` into a decoder
  rather than a stop.
* The 17 unnamed unresolved opcodes.

```
python3 tools/walk_stream.py --lens        # 117/141 walkable, 45 named, 24 unverified, 2 conflicts
python3 tools/walk_stream.py --self-test   # 15/15
python3 tools/acceptance.py                # 105 cases, 10 fixtures
```
