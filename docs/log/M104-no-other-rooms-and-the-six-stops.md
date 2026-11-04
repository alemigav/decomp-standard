# M104 — no other rooms available, and the six "desyncs" are stream ends

## 1. "The other rooms" cannot be walked: they are not in hand

The three room dumps are **byte-identical** — same sha256 (`6704425b…`), same six live contexts, same
pointers:

```
20261031-130325   sha 6704425bfe2b   live ctx 6
20261031-130332   sha 6704425bfe2b   identical to previous: True
20261031-130338   sha 6704425bfe2b   identical to previous: True
```

So they are **one instant exported three times**, not three moments, and the two older dumps predate a
room load entirely. Walking "the other rooms" therefore needs **one dump per room**, which is the same
human action as before (enter a room, Tools → Memory Editor → region RDRAM → Export). Nothing in this
repository can produce them.

What I can do, and did, is finish the diagnosis of this room's walks.

## 2. The six stops are stream ends, not desyncs

Diagnosis of each stop:

| ctx | stop address | byte there | is it a table index? |
|---|---|---|---|
| 0 | `0x8052a728` | `0xff` | no (≥141) |
| 1 | `0x8052a728` | `0xff` | no |
| 2 | `0x8052a7f8` | `0xff` | no |
| 3 | `0x8052a874` | `0xf3` | no |
| 4 | `0x8052a874` | `0xf3` | no |
| 5 | `0x8052a728` | `0xff` | no |

Four independent walks stop at **the same address** `0x8052a728`, and two at `0x8052a874`. That is the
deciding evidence: a wrong command length desynchronises a walk into *arbitrary* positions, so six walks
from six different starts would scatter. They converge instead — on bytes that **cannot be table
indices** (a real command's opcode is < 141).

Two more checks agree:

* the byte at each stop is a **single** `0xff` / `0xf3` inside dense data — not filler (a `0xff` run
  length of 1 and 0 respectively), so the walk has not run into a blank region;
* the area beyond the stop is **4-byte-aligned records**, not bytecode: at `0x8052a860` the pattern is
  `0e 00 00 00 | 4c 04 12 00 | 00 00 3a 00 | 0e 00 00 00`, and similar groups repeat — a different
  structure that the byte-stream walk correctly refuses to interpret.

So: **the streams end and the walk leaves the command area.** `walk_stream.py` now says exactly that
instead of calling it a desync:

```
[56] 0x8052a728: opcode 0xff — not a table index (>= 141) -> the stream ENDED here
```

Per-context command counts before the stop: **56, 84, 4, 18, 10, 2** — 174 total, matching M103.

## 3. Why there is no terminator byte to key on

The dispatcher does not stop on a byte in the stream; it stops on state. In `FUN_8006da14` the loop
tests and decrements a counter held in a **frame** inside the context (the area `ctx+0x140` points into,
frames of 0x20), not a sentinel at the end of the commands:

```
0x8006da3c  lbu  v0,1(s0)         ; a context flag
0x8006dabc  lbu  v0,4(v1)         ; a countdown in the frame
            addiu v0,v0,-1
0x8006dacc  sltiu v0,s1,10        ; and at most ten contexts
```

So the correct walk length per context is **the frame's counter**, not "until a byte ≥ 141". Reading
that counter for each live context out of a dump would bound every walk exactly, and it is a small
addition — the frame pointer is at `ctx+0x140` and the countdown at `+4` of its target.

The contexts' own headers, for reference (dump, six live contexts):

```
ctx0 00 00 00 00 ff 00 00 00 ff ...   [1]=0 [3]=0(ctx id) [4]=0xff [8]=0xff
ctx1 00 00 00 01 ff 00 00 00 ff ...   [1]=0 [3]=1
ctx2 00 01 00 02 ff 00 00 00 00 ...   [1]=1 [3]=2 [8]=0
ctx3 00 01 00 03 ff 00 00 00 00 ...   [1]=1 [3]=3
ctx4 00 00 00 04 ff 00 00 00 ff ...   [1]=0 [3]=4
ctx5 00 01 00 05 ff 00 00 00 ff ...   [1]=1 [3]=5
```

`[3]` is the context id (0–5) and `[4] = 0xff` for all six; `[1]` is 0 or 1 and `[8]` is `0xff` or 0 —
candidate "busy/suspended" flags, not stated as fact.

## 4. What this changes about the earlier conclusion

Nothing in M103's answer moves: **no `0x44` command is pending in this room**, and the last-executed one
(`0x8052a614`, slot 31, gate passing) selected descriptor 0 — nothing. The walk's 174 commands and 30
opcodes stand; what changes is only the *label* on the stopping points: **ends, not desyncs.**

What it does add is a correction of the tool's own earlier framing: it reported six "desync stops" as if
they were a decoder defect. They were the walk correctly refusing to read record data as bytecode, and
convergence on two addresses is the positive evidence.

## 5. To go further

1. **One dump per room** — the only way to walk other rooms.
2. **Read the frame counter** at `*(ctx+0x140)+4` for each live context to bound the walks exactly,
   instead of stopping at the first byte ≥ 141. That turns "56 commands then a non-command byte" into
   "the N commands the context was told to run".
3. Only then is a slot in **16 or 32–63** something the data can settle rather than merely not
   contradict.
