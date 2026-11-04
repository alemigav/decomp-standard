# M105 — the counter is a flag, and the first real scene-slot commands are found

## 1. The `ctx+0x140` counter: added, measured, and it is not a bound

The dispatcher's pop path decrements a byte at `ctx + signed(ctx[2]) + 4`, so that is the only place a
per-context remaining count could live. Added to the walker and measured on **both** room dumps:

```
ctx0..ctx5   counter@ctx+0x1c... = 0xff   in every context
frame areas *(ctx+0x140): zeroed, except a single command pointer word
*(frame-4), *(frame-8), *(frame-12): 0x0 for every context
```

**It is a flag (`0xff`), not a countdown**, and the frame holds a command pointer rather than a queue of
counts. So M104's "read the frame counter to bound the walk" is **refuted by measurement** — the byte
never varies from `0xff`, and nothing in the frame decreases.

The dispatcher's only numeric bound is `sltiu s1,10`: **ten iterations per call**, a loop count, not a
command count. So a walk is bounded by its *stream* (first byte ≥ 141), which is what
`walk_stream.py` reports. The counter is still printed per context — as a recorded flag, explicitly not
as a bound.

## 2. The new dump is a different room state

`…-rdram-20261031-132514.bin`, sha `bf3e2fa5…` (the earlier three were all `6704425b…`). Same script
descriptor `0x80529d40`, **different** stream pointers (`+0x48 = 0x8052a408` vs `0x8052a3c8`), and
different context pointers (`0x8052a5a2`, `0x8052a59e`, `0x8052a8ca`, `0x8052a996`, `0x8052a9bc`,
`0x8052a723`). `*(0x80115284) = 0x8052a896`, byte 3 = **31**, byte 9 = `0x41` → gate passes.

## 3. All six walks, on the new room

| ctx | commands | ended at | note |
|---|---|---|---|
| 0 | 14 | `0x8052a5c5` (0x94) | stream end |
| 1 | 15 | `0x8052a5c5` (0x94) | stream end |
| 2 | 46 | `0x8052a990` (0xcb) | stream end — **contains 5 scene-slot commands** |
| 3 | 6 | `0x8052a9a2` (0xc9) | stream end |
| 4 | 2 | `0x8052a9be` (0xc3) | stream end |
| 5 | 2 | `0x8052a728` (0xb3) | stream end |

Every stop is again a byte ≥ 141 — stream ends, consistent with M104.

## 4. The five scene-slot commands, and what each actually does

First observation of `0x44` commands in a live stream. All five are 22 bytes, in **ctx2**:

```
0x8052a8ec  44 00 00 48 01 00 00 00 …   byte1=0  slot=72   gate=0xff
0x8052a928  44 00 01 1f 00 40 00 05 …   byte1=1  slot=31   gate=0x3e
0x8052a93e  44 00 02 1f 00 40 00 05 …   byte1=2  slot=31   gate=0x3f
0x8052a954  44 00 03 1f 00 40 00 05 …   byte1=3  slot=31   gate=0x40
0x8052a96a  44 00 04 1f 00 40 00 05 …   byte1=4  slot=31   gate=0x41
```

Byte 1 is a counter `0…4`, and byte 9 runs `0x3e…0x41` — the second command's onward is
`0x3d + byte1`. Resolving each against the dump:

| cmd | slot | gate | gate verdict | destination table | map byte | record loaded |
|---|---|---|---|---|---|---|
| `0x8052a8ec` | **72** | `0xff` | **skipped** | **`0x0`** | 0 | **none — early return** |
| `0x8052a928` | 31 | `0x3e` | PASS | `0x80161cf0` | 0 | record 0 (the marker) |
| `0x8052a93e` | 31 | `0x3f` | PASS | `0x80161cf0` | 0 | record 0 |
| `0x8052a954` | 31 | `0x40` | PASS | `0x80161cf0` | 0 | record 0 |
| `0x8052a96a` | 31 | `0x41` | PASS | `0x80161cf0` | 0 | record 0 |

**Two distinct benign outcomes, both now observed rather than argued:**

1. **slot 72 → early return.** Its destination-table entry at `0x800df6b0+0x1f40+4*56` is **zero**, so
   `FUN_8003287c`'s first test (`beq v0,zero,0x80032ae8`) fires and the loader returns before touching
   `cart_record` at all. This is the guard M101 hypothesised and then failed to find for slot 31 — it is
   real, it just guards *other* slots.
2. **slot 31 → nonsense record.** Destination `0x80161cf0` is non-zero, the map byte is 0, so
   `cart_record(0)` returns the `OVERLAYTABLENUMC` marker, branch 2 fires, and the inflate fails with
   its return discarded (M92).

**No real record — bank B or bank C — is loaded by any of the five.** Every path ends in either an
early return or a rejected marker.

## 5. What this forces about byte 3

Byte 3 carries 72 once and 31 four times, and **both values map to 0** — the map is a byte array whose
entries for those slots are zero. So on this evidence **byte 3 is not selecting records**: the loader is
being invoked with values that resolve to nothing.

That leaves two readings, and they are testable rather than speculative:

* these `0x44` commands are not "load a slot" commands at all — `0x80115284`'s descriptor (slot 31,
  gate `0x41`) and ctx2's four slot-31 commands with gates `0x3e…0x41` suggest a *request/slot*
  handshake whose byte 3 is a slot **id outside the map's range** (the map covers slots 16–63 at 0x…),
  and the load happens elsewhere;
* or the map is populated only after a different event, and this moment is before it — the map bytes
  would become non-zero later.

Both are settled by one more dump from a different moment, which is the same human action as before.

## 6. Tooling

`walk_stream.py` now prints, per context, the counter byte and its address, with the measured note that
it is a flag and not a bound — so the next reader does not repeat M104's hypothesis.
