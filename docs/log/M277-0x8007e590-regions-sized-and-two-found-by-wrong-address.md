# M277 — `0x8007e590`, second pass: every region now the right size, the default arm exact, and two errors that were reading, not reconstruction

M275 left this function at **95 of 229** words by offset with the 113-word arm at 21. This pass took it to **176 of
229 by offset**, **195 by content**, **19 hunks**, with **every region's size now exactly the image's** and the object
**3 words over, all of them the `as` alignment padding past the extent** — i.e. the body is 229 words and no word is
missing or extra. It is still not exact, and this note says exactly where the last 53 words are.

## 1. Where it stands

| region | words | M275 | now |
|---|---|---|---|
| head `0x8007e590` | 14 | 14 / 14 | **14 / 14** |
| case 0 `0x8007e5c8` | 21 | 21 / 21 | **21 / 21** |
| case 1 `0x8007e61c` | 30 | 27 / 30 | **30 / 30** |
| case 2 `0x8007e694` | 5 | 5 / 5 | **5 / 5** |
| case 3 `0x8007e6a8` | 113 | 21 / 113 | 74 / 113 |
| case 4 `0x8007e86c` | 22 | 6 / 22 | 18 / 22 |
| default `0x8007e8c4` | 24 | 1 / 24 | **24 / 24** |

The region *sizes* are the part worth trusting: case 3 measures 113, case 4 22 and the default 20 + a 4-word epilogue
in my object, against the same numbers in the image, so no statement is missing and none is invented. What differs is
where the allocator put things.

## 2. Two of the four errors were mine in the reading, not in the C

These are recorded first because they are cheap to repeat and expensive to hold.

**The device-window base must stay detached from the symbol.** I had written `*(u32 *)(D_800C76B0 + 0x18000 + 0x1a7a)`.
cc1 folds that into one `%hi`/`%lo` pair over `D_800C76B0+105082`, two words. The image instead builds `0x18000` in a
register (`lui $v1,0x1` / `ori $v1,$v1,0x8000`), builds the symbol separately (`lui $v0,0x800c` /
`addiu $v0,$v0,30384`) and `addu`s them — five words, and the field stays a **small displacement**. That is gcc's
`mips_add_large_offset_to_address`, which is reached only when the base is **already a register**; a
`symbol + constant` is never large-offset, it is just a bigger `%lo`. So the source must be

```c
u8 *dev = D_800C76B0;                    /* the symbol, unattached */
*(u16 *)(dev + 0x18000 + 0x1a7a) |= 4;   /* the offset added to a register */
```

and not the one-expression form. `build/p7/` already held this idiom from the exact `0x80057e1c`, which is where the
fix came from: **a matched function is the cheapest documentation of a shape rule in the repository.** This alone
took the default arm from 1/24 to 20/20 and added the 4 words it was short.

**The table is `0x8010BA78`, not `0x8011BA78`.** The image has `lui $v0,0x8011` / `addiu $v0,$v0,-17800`. Adding
those two as printed gives `0x8011BA78`, and that is what I had. They reassemble to **`0x8010BA78`**: `%hi` rounds
*up* when bit 15 of the low half is set, so `lui 0x8011` + `addiu 0xBA78` (= `-0x4588`) is
`0x80110000 - 0x4588`. The test is whether `(addr + 0x8000) >> 16` equals the printed `lui` — for `0x8010BA78` it is
`0x8011` and for `0x8011BA78` it is `0x8012`. **Read the printed `lui` as `%hi`, never as the address's high half.**

## 3. Two discriminator mechanisms, both measured

**`beql` is not a flag.** The image contains 1 381 branch-likely instructions, so I tested `-mbranch-likely` and this
cc1 answers `Invalid option`. gcc 2.8.1's `mips_branch_likely` (in `config/mips/mips.c`) is set from
`INSN_ANNULLED_BRANCH_P (insn)` in the branch patterns — the likely form appears when **reorg puts a store in an
annulled delay slot**, not when a flag is passed. In this function it appears exactly once, at `0x8007e898`
(`beql s0,v0,0x8007e8b8` with `sb zero,5(s0)` in the slot), and the source shape that produces it is the *inverted*
form:

```c
if (!((*(u32 *)(dev + 0x18000 + 0x1a5c) & 0x10000000)
      && s == (struct Ctx *)*(u32 *)(dev + 0x18000 + 0x1d3c)))
    s->f5 = (s->f5 == 22) ? 4 : 5;
else
    s->f5 = 0;
```

The natural form (`if (A && B) s->f5 = 0; else …`) compiles to `bne` + `j` and scores **10 of 22**; the inverted one
scores **18 of 22**. Same program, opposite branch, four words of difference.

**The mask is bit 28, not bit 12.** Case 4's test is `lui $v1,0x1000` followed by `and $v0,$v0,$v1`. I read that `lui`
as loading `0x1000` and wrote `& 0x1000`, which compiles to `andi $v0,$v0,0x1000` — one word, and wrong. The mask is
`0x10000000`; the reason the compiler materialises it at all is that it does not fit an immediate. **An `and` with a
`lui`-built operand is a mask above bit 15, always.**

## 4. The `f8` arms are not identical — M275 said they were

M275 recorded "case 3 duplicates an identical 47-word block in both arms of its `f8` test". The *field-copy* block is
duplicated, but the table read in front of it is not:

- then-branch (`0x8007e6ec`, 20 words): re-reads `s->f8` with `lbu`, `sltiu`s it, and carries
  `s->f1e8.b[2] = 0` in the `beqz` delay slot;
- else-branch (`0x8007e798`, 17 words): uses the `a0` still holding `f8` from the outer test (no `lbu`), and has
  **no `f1e8.b[2] = 0` at all**.

So the source reads `f8` into a local for the outer test and the else branch, and re-reads the field inside the then
branch. Written that way — `u8 c; … if (s->f1e8.b[1] == 17) {…} c = s->f8; if (c == 69 || c == 79) { …reads
s->f8… } else { …reads c… }` — the score went **95 → 174** in one edit; it is the single largest gain of the pass.
The same hoist, in the shape M275 tried it, scored 86. **That is a context fact, not a contradiction**: at 34 hunks
with the wrong table address and the wrong mask, moving one value's lifetime changed allocation everywhere and lost
words; with those fixed, it gains them.

Case 3's 47-word copy block also needs **chained assignment** for one load to feed two stores:

```c
s->f38 = s->f1b6 = s->f32;      /* lhu a0,50(s0) ; sh a0,438(s0) ; sh a0,56(s0) */
s->f34 = s->f1b4 = s->f2a;
```

as two separate statements cc1 emits an extra `move` per pair (**+2 words**, and it measured 232 words with the wrong
shuffle); the chained form plus **named temporaries** (`u16 p, q;` → `p = s->f32; s->f1b6 = p; s->f38 = p;`) is what
took the total from 174 to 176 and content from 169 to 195.

## 5. The 53 words that remain, and why they are not reachable from the C yet

Three clusters, all allocation or scheduling, none structural:

1. **31 words, the copy block, twice.** Mine issues the same 17 instructions in a different order — it hoists the
   `f32` and `f2a` loads above the `f2c` store, where the image issues loads in source order and lets only the *next*
   statement's load overtake a store. The image's registers are `a0`/`v1`/`a1` for `f32`/`f2a`/`half`; mine are
   `v1`/`v1`/`a0`.
2. **16 words, the table read, twice.** The base and index registers are swapped (`v0`/`v1` against my `v1`/`v0`),
   including the shared `lui` that the image parks in the `beqz` delay slot for the else arm.
3. **3 words, case 4's select.** The image's `li v0,22` / `li v0,5` / `li v0,4` reuse one register and store from it;
   mine puts `5`/`4` in `a0` and stores from that. `a0` is dead in both (it held the device base), so this is a pure
   tie-break — and case 3's register pressure is global, so it is likely to follow case 3 rather than lead it.

Everything else that differs is a branch offset that waits on these.

## 6. What is kept, and what is not claimed

Kept: the corrected table address, the detached device base, the bit-28 mask, the inverted if/else for the annulled
likely branch, the `c`/`p`/`q` temporaries, the chained field copies, and the per-region harness (`build/p7e590/`,
gitignored) that made all of the above measurable in ten seconds per edit.

Not claimed: the function is not exact, it is not in `compile_probe.py`, and the progress map still does not list it.
The probe corpus is unchanged at **30 cases, all passing**. The honest reading of the method's coverage is unchanged
too — **everything at or below 206 words has come out exact**, and the two failures are the two largest, `0x80024558`
at 136 of 139 (three words of allocation) and this one at **176 of 229** with sizes now correct and 53 words of
allocation and schedule left.
