# M106 — the maps never populate, and the scene-slot path is a per-execution no-op

Three dumps from a later moment, and this time they are **three different states** — the earlier triple was
byte-identical, these are not:

```
20261031-132850  sha e0bc2b98c44a
20261031-132924  sha d3e84fd888d9
20261031-132952  sha 226532819cf5
```

## 1. M105's open question, answered: the map is static

M105 left two readings: either the `0x44` commands are not load commands, or **the map is populated
later**. The second is now **refuted by measurement** — the maps are byte-identical across **all five**
room dumps, spanning `130338` to `132952`:

| quantity | 130338 | 132514 | 132850 | 132924 | 132952 |
|---|---|---|---|---|---|
| array 1 nonzero | 28 | 28 | 28 | 28 | 28 |
| array 2 nonzero | 28 | 28 | 28 | 28 | 28 |
| destination table nonzero | 44/48 | 44/48 | 44/48 | 44/48 | 44/48 |
| **map entry for slot 31** | **0** | **0** | **0** | **0** | **0** |
| **destination entry for slot 72** (index 56) | **0** | **0** | **0** | **0** | **0** |

The arrays are **static `.rodata`**, matching the cartridge image byte for byte, and nothing ever writes
them. That is consistent with the earlier finding that no code writes a descriptor (M97) — the two byte
arrays are simply not mutable state.

So the slot values these commands carry resolve to **0 forever**: slot 31 → index 15 → `0`; slot 72 →
index 56 → `0`.

## 2. The three new moments: the `0x44` command is always behind the live pointers

| dump | current command `*(0x80115284)` | slot | gate |
|---|---|---|---|
| 132850 | `0x8052a896` | 31 | `0x41` → passes |
| 132924 | `0x8052a896` | 31 | `0x41` → passes |
| 132952 | `0x8052a3ca` | 31 | `0x37` → passes |

Walking all six contexts on each of the three finds **no `0x44` command in any forward range** — while
the *last-executed* one is always an `0x44` with slot 31. The streams are active and differ per moment
(10–20 distinct opcodes, 4–18 commands per context), but every capture lands **after** the `0x44`
command has run.

That is now five dumps in a row, across three distinct states, with the same pattern: **the `0x44`
command executes early, stores itself in `0x80115284`, and resolves to descriptor 0.**

## 3. What the path actually is

Putting the measurements together, the scene-slot path in this room is a **recurring no-op**:

```
opcode 0x44 (22 bytes, byte 3 = 31, constant across five captures)
  → FUN_80071e14: gate on byte 9 → passes
  → FUN_8003287c(31): destination entry index 15 = 0x80161cf0 (non-zero, so no early return)
  → map byte index 15 = 0  (permanently — static .rodata)
  → cart_record(0) = the "OVERLAYTABLENUMC" marker
  → branch 2 → inflate(cart 0x0f564552, len 0x4c415954) → fails, return discarded
  → destination keeps 0x80161cf0; nothing observed changes
```

Two guards are now both *measured*, not argued:

* **slot 72 → early return** because its destination entry (index 56) is **zero**;
* **slot 31 → nonsense record** because its destination entry is non-zero but its map byte is zero.

And `byte 3 = 31` is **constant across five captures at three different moments**, which is what a
parameter looks like, not a selector.

## 4. So: does any room ever select a bank-C record?

Not on this evidence, and the reason is now sharper than "not observed": **the map is immutable**, so a
slot only selects a real record if its *static* map byte is non-zero. Bytes are non-zero for slots
**16 and 32–49, 51, 52, 54–56, 58, 59, 62, 63** (M92/M105). None of those values has appeared; the only
slot values observed are 31 and 72, both zero.

That converts the question into a **static** one about which slots select which records, plus a
remaining **dynamic** question: does the game ever execute an `0x44` command whose byte 3 is one of
those 13 live values? Five captures say no; the honest scope is "in this room, in these five moments".

## 5. Next, and it needs a different room

The map lookup is by *slot*, and this room's commands only use zero slots. So the discriminating dump is
**a different room** — the map is the same 48-byte table for all of them, but a different room's script
would carry different byte-3 values. One dump per room, same procedure:

1. enter a room (ideally a different one from this corridor),
2. Tools → Memory Editor → region `RDRAM` → `Memory` row → `Export`,
3. `python3 tools/walk_stream.py "rom/<dump>.bin"`.

If any walk shows an `0x44` whose byte 3 is 16 or 32–63, that slot selects a real record and the
question is finally answered in the affirmative; if a spread of rooms shows only zeros, then the
scene-slot command is a no-op by design in this build and the record loading happens elsewhere.
