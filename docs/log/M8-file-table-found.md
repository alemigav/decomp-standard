# M8 — The ROM→VRAM map found: a 16-byte cart descriptor table at vram 0x80012150

**Status:** found and decoded. This closes the question M4–M7 were circling, and corrects why M6's
scans returned zero. All addresses below use the corrected mapping
(`vram = rom_offset + 0x7FFFF480`, see `M7-mapping-correction.md`).

## How it was found

Reading the boot initialiser `FUN_80000598` (vram `0x80000598`, called once from `main`) at the
*correct* base gave readable pseudocode:

```c
puVar1 = (uint *)FUN_80001180(1);              /* -> descriptor record #1 */
...
while (FUN_8000BE50() & 7) ;                   /* PI idle wait */
FUN_8000C870(0, *puVar1 & 0x0FFFFFFF, 0x8015B030, puVar1[1] + (puVar1[1] & 1));
while (FUN_8000BE50() & 7) ;
FUN_80004550(auStack_68, (iVar4 + 0x8015B037) & ~7);
FUN_800045DC(auStack_68, 0x8015B030, puVar1[2], puVar1[1]);
FUN_80004594(auStack_68, 2);
```

and the table provider is two instructions:

```c
int FUN_80001180(int index) { return index * 0x10 + 0x80012150; }
```

**`0x80012150` is `0x10` bytes past the code end (`0x12140`)** — the table starts exactly where
splat's code segment stops.

## Record format (16 bytes)

| field | meaning |
|---|---|
| +0 | cart offset **OR'd with `0xB0000000`**; the real offset is `& 0x0FFFFFFF` |
| +4 | stored size in bytes (0 = empty slot, legal) |
| +8 | destination vram (start) |
| +12 | destination vram (end) |

## The table

- **66 records** with the `0xB` flag, 63 of them non-empty; 1 072 bytes of table.
- Cart offsets **ascending**, `0x14420` … `0xC85E8`; payload **737 779 B (0.70 MB)**.
- Destinations `0x80018A80` … `0x801899F0` — the top half of RDRAM.
- `0x12140`–`0x14420` (just under 9 KB) sits between the code end and the first file: more boot data.

So this is the **boot-time load set**, not an index of all 64 MB: it covers 1.1 % of the cartridge.
That is consistent with a game that loads a *second* stage and then per-scene files.

## Why M6 concluded "not a table"

Both of M6's filters rejected real records:

1. **The `0xB` top nibble.** The offsets are `0xB0074420`, not `0x00074420`, so any
   `offset < 0x4000000` test discards every record. The mask `& 0x0FFFFFFF` is applied by the
   *code*, in the DMA call's delay slot — not present in the data.
2. **The vram fields are at +8/+12, not adjacent to the offset.** M6 looked for `(offset, vram)`
   pairs at stride 2 starting at +0; the real record is `(offset, size, vram, vram_end)` at stride 4.

The lesson is the general one: **a null result from a shape scan is a statement about the filter,
not about the ROM.** Every filter constant here (`< 0x4000000`, adjacent pair) was invented from
how other ROMs look.

## The two PI DMA functions, now decompiled rather than shape-matched

`FUN_8000C870(dir, cart, dram, len)` — **raw PI DMA start**:

```c
do { } while ((_DAT_a4600010 & 3) != 0);                  /* PI_STATUS busy wait */
_DAT_a4600000 = FUN_8000E800(dram);                        /* PI_DRAM_ADDR = KSEG1(dram) */
_DAT_a4600004 = (_DAT_80000308 | cart) & 0x1FFFFFFF;       /* PI_CART_ADDR |= base */
len reg = (dir == 0) ? 0xA460000C : 0xA4600008;            /* WR_LEN : RD_LEN */
*lenreg = len - 1;  return 0;
```

`FUN_80007C20(device, …)` — **the same transfer plus per-domain timing**, i.e. the `EPi` variant:
it indexes a **device table at `0x80012910`** with `*(byte *)(device + 9)`, compares the device's
bytes 5/6/7/8 (latency, pulse, page size, release) against the cached entry and writes the changed
ones to `0xA4600014`/`0x1C`/`0x20` for domain 0 or `0xA4600024`/`0x2C`/`0x30` for domain 1. Both are
still **behaviour-named** — no libultra symbol table exists for this build — but the behaviour is now
read from pseudocode, not inferred from `sw` offsets.

## Open, and where the next hour goes

- **`FUN_80004550` / `FUN_800045DC` / `FUN_80004594`** are the consumer of the staging buffer
  `0x8015B030`; the runtime region already contains a zlib `inflate` (M7), so this is very likely a
  three-call decompression context (init / inflate / finish). Confirming that converts the descriptors
  from "sizes" into "compressed sizes" and gives the entry point for unpacking the 67 MB.
- **`FUN_8000E800`** is the vram→physical converter (what fills `0x0FFFFFFF`-style addresses), and
  **`DAT_80000308`** is a PI base the boot code sets up. Together they define the address space the
  loader works in.
- **The 66 records are start-up only.** The per-scene index is either a second table or built by the
  code that follows the first stage; searching for other `0xB`-flagged records ROM-wide is now a
  two-line change to the scan rather than a research question.
