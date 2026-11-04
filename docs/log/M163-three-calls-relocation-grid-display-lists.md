# M163 — the three calls read: relocation, part filter, and a tile grid of *display lists*

Disassembling the three calls in `FUN_80055574` answered the question, corrected M162, and vindicated the
display-list hypothesis — for a different block kind than the one it was proposed for.

## 1. `FUN_800824b8` — a relocation pass, and `0x0141` is a version, not a magic

```c
if (p[1] == 0) {                                  /* the flag at offset 2 is clear */
    *(int *)(p + 4) = (int)p + *(int *)(p + 4);   /* offset 8: offset += block base */
    if (300 < *p) {                                /* **version > 300** */
        /* offsets at 12 and 16 likewise relocated, then a table of `count` ints at +20 */
```

Read against one of our blocks (id 5776):

```
version = 321 (0x0141)   flag = 0   word1 = 15   next-section offset = 0x4070   f12 = 0   f16 = 0   count = 11
version > 300? True  -> the newer relocation branch, which our blocks take
```

So the family's "magic" `0x01410000` is **format version 321**, and every block carries **self-relative offsets**
that the loader fixes up by adding the base — the same design as the PS1 room files, in a different structure.
That also re-reads `word2`: it is not a "payload length" but a **pointer to the next section**, relocated at load.
Its value happens to equal `filesize − 16·word1` on all 355 blocks — numerically exact (M159) and now
*semantically* reclassified: a forward pointer, not a length.

## 2. `FUN_80087868` — a per-type part filter

It walks the model's part array, reads a threshold from `u16[&DAT_801275c0 + type*2]`, and marks every part whose
field is ≤ the threshold with `0xffffffff` — i.e. it selects which parts of a model are live for a given object
type. No payload transformation.

## 3. `FUN_800874d4` — a **grid of texture tiles**, each a separately loaded block

This is the interesting one, and it is not a texture decoder:

```c
puVar7  = (param_1 + 3) & ~3;                       /* align past the model */
idx     = u16[&DAT_8010dbe0 + type*2];              /* descriptor index */
w       = u16[&DAT_801275c0 + idx*2];
h       = u16[&DAT_801275c0 + (idx+1)*2];
ids     = &DAT_801275c0 + (idx+2)*2;                /* w*h tile ids */
for each row, for each column:
    if (row 0) { dst = align(puVar9); iVar6 = func_0x80004cfc(*ids, dst, 1, "T64"); }
    else       { *puVar7 = puVar7[-w*k];  *puVar11 = puVar11[-w*k]; }   /* dedupe against a previous row */
```

So the model is followed by a **width × height grid of tile ids**; each *distinct* id is loaded on demand with the
tag **`T64`**, and repeated tiles are shared by copying a pointer from an earlier row (`psVar10[-uVar5*iVar6]`).
`0x1835` is special-cased into a global. That is a **texture atlas assembler**, and it explains the block layout
from the other side: the model and its atlas are separate resources joined by this table.

## 4. The vindication: `T64` blocks *are* display lists

The ids in those grid descriptors resolve to blocks whose first byte is:

| first byte | tile blocks |
|---|---|
| **`0xBE`** | **65 of 65 (100 %)** |

`0xBE` is **`G_MOVEMEM`**. So the display-list hypothesis, refuted for the `01 41` family in M161 **on its own
numerical test (0 of 1 355)**, is **confirmed for the `T64` tile kind that the grid loads**. The intuition was
right about the ecosystem and wrong about which block it applied to — which is exactly what a per-kind test can
settle and a corpus-wide one cannot.

## 5. Correction to M162

M162 called the family "the models' texture data". It is **the models**. The textures are the `T64` tiles the
grid references; the family's own payload is model geometry with self-relative pointers. The relational evidence
that produced M162's claim was right (EMD and TM3 reference the family) and the *inference from it* was one step
too long — a reminder that "which kind loads it" bounds the answer without settling it.

## 6. Gate

`01 41 container` is now **17 cases**, including two new ones: the grid descriptors reference a substantial set of
tiles, and **every one of those tiles begins with `0xBE`**. **171 cases across 17 fixtures**, `ci.sh: ok`,
18/18 marker checks, audit 15/15.

## 7. Where the pipeline now stands

```
room id ──► RDT block ──► section tags (RID FLR SCA RVD LIT SCD PR2 BLK MSG OMD EDT …)
                                  │
                                  ├─ SCD ──► 141-opcode VM, 149-opcode map, records, GoSub/0x1c
                                  └─ model kind (TM3/EMD, version 321)
                                        ├─ relocations at +8/+12/+16 and a table of `count` ints
                                        └─ grid descriptor ──► w×h tile ids ──► T64 display lists (0xBE …)
```

Every arrow in that sketch is now backed by a measurement in this session, and the two ends — the script VM and
the display lists — are both decoded far enough to be read.
