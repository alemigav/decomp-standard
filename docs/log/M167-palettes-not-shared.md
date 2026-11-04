# M167 — palettes are not shared: the engine shares whole tiles

Tracing `FUN_800874d4`'s seven callers answered the question, and the answer is no at the palette level and yes at
the tile level — the distinction is visible in two nearly identical registration functions.

## 1. The registry

`FUN_80085164(block)` and `FUN_8008522c(blockA, blockB)` are the same function with **one extra store**:

```c
uVar1 = DAT_8012485c;                                  /* a free-list head */
DAT_8012486c[uVar1 >> 5] |= 1 << (uVar1 & 0x1f);        /* mark the slot busy */
DAT_80124880[uVar1 * 4] = param_1;                      /* block pointer A  */
*(DAT_80124888 + uVar1 * 0x10) = param_2;               /* block pointer B  <- only in 8522c */
DAT_8012487c[uVar1 * 4] = uVar1 | DAT_80124858 << 8;    /* handle = slot | generation */
```

So a registry slot is a **16-byte record holding one or two block pointers plus a packed handle**. `8522c` exists
solely to register a **pair** where `85164` registers a single block.

## 2. Who decides single versus pair

`FUN_8008769c`, the two-row driver:

```c
if (*(short *)(&DAT_801275c2 + param_4) != 2) { FUN_800874d4(...); return; }   /* height != 2: one row */
for each column:
    if (*psVar6 == *psVar7)  load ONE block,  FUN_80085164(block);              /* rows share the id */
    else { load block(psVar6); load block(psVar7); FUN_8008522c(a, b); }       /* register a PAIR */
```

And the general path `FUN_800874d4` dedupes *within* a walk: when an id matches one from an earlier row it copies
the earlier **pointer** (`*puVar7 = puVar7[-uVar4]`, M163) instead of loadng the block again.

## 3. The answer, stated precisely

* **Palettes are not shared.** There is no palette resource in this path at all: M165 measured that each `T64` block
  carries **its own palette inline** (16 or 256 RGBA5551 entries at the head of its data). Nothing in the loader
  compares or de-duplicates palettes, and there is no code that would — the two registration functions take
  *block pointers*, not palettes.
* **What is shared is whole tiles.** Sharing happens upstream, by **id equality**: equal ids in a repeated row
  reuse the already-loaded pointer; differing ids load two blocks and register them as a pair. That is why the
  registry needs a two-pointer variant at all.
* The **pair itself is not a palette**. Two different ids are two different texture blocks — the pair is two
  distinct tile images registered under one handle (near/far, two frames, or two halves of one sprite), not a
  pixels-plus-palette combination, which the file format makes unnecessary.

## 4. Why the format predicted this

This is the closing loop of M165: because the palette is *inside* the tile block, a pixels-plus-palette pair has
nothing to point at. The absence of palette sharing is not an oversight in the engine — it is impossible by the
format, and the registry's pair exists for a different reason. The data and the code agree, arriving from
opposite directions.

## 5. Gate

Two data-side consequences are now gated: **every id in a two-row grid resolves to a tile block** (so the pairing
path can always find both), and two-row grids **contain both equal-id columns and differing ones** — i.e. both
branches of the decision are exercised by real data, so the test is not about a degenerate case. `01 41
container` is **29 cases**; **183 cases across 17 fixtures**, `ci.sh: ok`, 18/18 marker checks, audit 15/15.

One honest note on scope: the pairing rule and the registry layout are **code readings** (§1–§3), not data laws.
The gated cases cover the data they operate on, not the code paths themselves — the distinction the project made
after the M149–M154 defects.
