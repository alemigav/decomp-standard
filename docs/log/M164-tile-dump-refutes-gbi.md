# M164 — dumping the tile: there is no GBI in it, and M163 was wrong

You asked for a tile dumped as GBI text. The dump says there is nothing to dump: after the 16-byte header the block
is value data, not a command stream. That refutes M163's "65 of 65 begin with 0xBE = G_MOVEMEM" — and it refutes
it on the operand, not on taste.

## 1. The dump

Tile id 5922 (2 576 B), first words:

```
+0000: 0xbe1e0020 0x00400020     <- header
+0008: 0x00020100 0x00000000
+0010: 0x84617bdf 0x7bdf73df     <- from here on: 16-bit values
+0018: 0x739d6b9b 0x6b9d635b       0x7bdf = R15 G15 B14 A1
+0020: 0x635b6319 0x63196317       values descend like an RGB555 gradient
```

No `G_ENDDL`, no `G_SETTIMG`, no second command: **the whole block is a header plus 2 560 bytes of 16-bit units.**

## 2. Why `0xBE` is not `G_MOVEMEM`

Three independent reasons, and the second is decisive:

* the first **halfword** is `0xBE1E` in **all 65 tiles** — a GBI opcode word would vary with its index/length
  fields across tiles, and this does not;
* `G_MOVEMEM`'s second word is a **pointer to the data it moves**, and `0x00400020` is not a valid RDRAM address
  in any layout this port uses (KSEG0/KSEG1 both start at `0x80000000`). A command whose operand cannot be an
  address is not that command;
* the bytes after the header have no command structure at all (§1).

So the tile is a **texture block with a constant magic `0xBE1E`**, and M163's display-list claim is retracted.

## 3. The GBI-share test, which is the discriminating one

A display list is nearly *all* opcodes: close to 1.00 of its 8-byte-aligned words carry a GBI opcode. Measured over
the 65 tiles:

```
share of 8-byte-aligned words with a GBI-opcode high byte:  min 0.12  median 0.38  max 0.84
tiles above 0.95: 0
```

Zero of 65 approach a command stream. That is the test the claim should have been held to in M163.

**And the first version of this test was wrong too**: I scanned for `G_ENDDL` (`0xB8`/`0xDF`) at 8-byte
boundaries and it *failed* — those bytes occur in colour data by chance. A value scan cannot distinguish a command
stream from pixel data; a **share** can. Same failure mode as the earlier vacuous checks, in a new costume, and
caught by the gate rather than by review.

## 4. What the header does say

| field | values across 65 tiles |
|---|---|
| `0xBE1E` (halfword 0) | constant — magic |
| halfword @2 | 32 (38×), 64 (26×), 128 (1×) |
| halfword @4 | 64 (56×), 32 (9×) |
| halfword @6 | 32, 64 |
| halfword @8 | 1 or 2 |

Data length does **not** match `w·h·2`, `w·h/2` or `w·h/4` for any tile, so those fields are not a plain
width/height/packing triple — or the data is compressed. Stated as open rather than guessed: what is settled is
that the block is a **texture with a 16-byte header**, and that the header is not a display list.

## 5. Gate

`01 41 container` is now **19 cases**, three of them about the tiles: the grid references a substantial set, every
tile begins with the constant magic `0xBE1E`, no tile's second word is a valid RDRAM pointer, and no tile's
GBI-opcode share approaches 1.0. **173 cases across 17 fixtures**, `ci.sh: ok`, 18/18 marker checks, audit 15/15.

## 6. The tally on this thread, stated plainly

* M161 **refuted** the display-list reading for the `01 41` family — correctly, on its own numerical test.
* M163 **revived** it for the `T64` tiles — **wrongly**, on one byte.
* M164 **refutes the revival** — on the operand and on the opcode share.

Three claims, two of them mine, all settled by measurement rather than by argument. The lesson that keeps repeating
here is narrow enough to be useful: **a constant in the first byte is not an opcode, and a scan for a value is not a
test for a structure.**
