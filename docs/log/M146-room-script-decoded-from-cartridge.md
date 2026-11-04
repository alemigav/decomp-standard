# M146 — the id resolves, and a real room script decodes out of the cartridge

The chain M145 named is now walked end to end, and the payoff is a decoded door script with no dump, no
emulator and no guesswork.

## 1. The id resolves: record `0x43` is a file table, not a broken payload

`format_notes` §2 has carried an open question since M81: the descriptor table declares 67 records, 66
validate, and **the 67th is "broken"** — cart pointer `0xb00c8624`, size `0xCDCDCDCD` (the only occurrence of
that word in the cartridge), two zero fields.

Its user explains it (`FUN_80004954`):

```c
_DAT_800128a8 = *cart_record(0x43);        /* 0xb00c8624 = ROM 0x0c8624 as a KSEG1 address */
read 0x28 bytes  ->  word 0 = 8091 entries, then "Tue Sep 28 02:31:44 1999"
_DAT_80012874 = table + 0x28;              /* 8-byte {offset, size}, offsets relative to 0xc8624 */
```

It is the **file table**. The two zero fields are not a defect: this record has no destination and no
decompressed size because it is not part of the boot load list at all. `FUN_80004cfc(id)` is the load-by-id
built on it, and ids come from `DAT_80131fa8[room]` in stage-2 — so **record 0x43 → 8091 files → room id →
file id** closes the route.

The 8-byte type word `FUN_80004cfc` reads after a block (`< 0x10` selects a decoder from a jump table) is
**not** what made these blocks readable: the blocks simply begin `68 de`, a zlib header, and decompress with
stock zlib. What that word is for is left open rather than invented.

## 2. The block is a script with a record table

File id **1881** (`DAT_80131fa8[0]`, the first `DOOR_SCD`) is 285 B compressed, **538 B decompressed**, and
its head is exactly the table M145 predicted:

```
u16 record offsets: 0x0012 0x002e 0x008e 0x0104 0x0118 0x012c 0x01a4 0x01d8 ...
record 0 at +0x12: 13 0c 00 16 | 14 00 00 04 00 00 | 18 01 ...
```

## 3. The decode

`tools/room_script.py --check` extracts the block, points the walker at record 0, and prints:

```
[ 0] 0x80400012: opcode 0x13 Switch len  4 -> 13 0c 00 16      cmd+22 / fall-through
[ 1] 0x80400016: opcode 0x14 SwitchCase len  6 -> 14 00 00 04 00 00
[ 2] 0x8040001c: opcode 0x18 GoSub len  2 -> 18 01             script record 1 (+0x2e)
[ 3] 0x8040002e: opcode 0x4d DoorModelSet len 22 -> 4d 00 00 00 01 00 0a a0
[ 4] 0x80400044: opcode 0x4d DoorModelSet len 22 -> 4d 01 00 e2 01 01 00 d0
[ 5] 0x8040005a: opcode 0x53 len  6 -> 53 00 02 07 fe 00
[ 6] 0x80400060: opcode 0x74 len  4 -> 74 00 1c 00
[ 7] 0x80400064: opcode 0x09 Sleep len  1 -> 09
[ 8] 0x80400065: opcode 0x0a len  3 -> 0a 00 46
[ 9] 0x80400068: opcode 0x18 GoSub len  2 -> 18 08             script record 8 (+0x204)
[10] 0x80400204: opcode 0x06 IfElseStart len  4 -> 06 00 00 10
[11] 0x80400208: opcode 0x23 Compare len  6 -> 23 00 0d 00 00 01
[12] 0x8040020e: opcode 0x02 len  1
[13] 0x8040020f: opcode 0x00 len  1
[14] 0x80400210: opcode 0x17 Goto len  6 -> 17 ff ff 00 ff f4     cmd-12 -> 0x80400204
```

A switch, a call, **two `DoorModelSet` commands with 22-byte operands** — a door script doing what a door
script does — then a call into a record that begins `IfElseStart` + `Compare` and ends with a `Goto` **back
to itself**, i.e. a spin loop waiting for the condition. That is the shape the owner's Phase 1 asked for
("`LOAD_ASSET(31); SET_FLAG(4); IF FLAG(4) THEN …`"), reached from cartridge bytes alone.

## 4. What had to be added for this to work

Three things, all in `walk_stream.py`, all small:

* **`--raw FILE --start OFF`** — places a block inside a synthetic 8 MiB RDRAM and points a context at it, so
  the *same* walk code runs on cartridge bytes. No second decoder.
* **Script-table resolution.** `GoSub` (`0x18`) and the script jump (`0x03`) were classed `dynamic` because
  they need `*(0x80114f2c)` + `u16[index]`. In `--raw` mode **the block is the base**, so both resolve. Before
  this, the walk stopped after three commands at `18 01`.
* **A return stack.** `0x18` pushes `cmd+2`; `0x19` — the opcode that loads the very slot `0x18` saves —
  pops it. With the stack, a call returns and the walk continues instead of ending.

The two un-named opcodes in the output (`0x53`, `0x74`, and `0x0a`) have known lengths but no PlayStation
name; they are now observable **in context**, which is better evidence than a shape scan.

## 5. Gate

New cartridge-gated suite `room script (cartridge)` — 4 cases: the head is a record table, record 0 calls
record 1, the called record sets two door models, and a later record loops back. On a machine without the ROM
it reports SKIP, exactly like `provenance acceptance`.

**121 cases across 12 fixtures**, `walk_stream --self-test` 20/20, `rdram_fixture` 7/7, `ci.sh: ok`,
18/18 marker checks.

## 6. What is left

* **All 8 091 entries, all rooms.** The route is now mechanical: `DAT_80131fa8[room]` → id → decode. A
  corpus pass would give a frequency profile of the 96 unnamed opcodes *in situ*.
* **Pseudocode, not opcode lines.** The decoder knows sizes and targets; naming `0x53`, `0x74`, `0x0a` and
  the rest is what turns the listing above into readable logic.
* The `format_notes` §2 table is corrected in place: the "broken 67th record" question is answered.

```
python3 tools/room_script.py --check       # 4/4, needs the cartridge
python3 tools/room_script.py --records     # the block's record offsets
python3 tools/acceptance.py                # 121 cases, 12 fixtures
```
