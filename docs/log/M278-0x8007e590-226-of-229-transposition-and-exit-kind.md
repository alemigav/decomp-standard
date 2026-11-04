# M278 — `0x8007e590` at 226 of 229: the copy block, both table reads, and a switch with no `default`

M277 left this function at **176 of 229** with 19 hunks. This pass took it to **226 of 229**, **226 by content**, and
**one real hunk** — the three words of case 4's select that are a register-allocation tie-break, plus the usual `as`
alignment padding past the extent. The object is 232 words of which the last 3 are padding, so the body is 229 and, for
the first time, every region matches both in size *and* nearly in content.

| region | words | M277 | now |
|---|---|---|---|
| head `0x8007e590` | 14 | 14/14 | **14/14** |
| case 0 `0x8007e5c8` | 21 | 21/21 | **21/21** |
| case 1 `0x8007e61c` | 30 | 30/30 | **30/30** |
| case 2 `0x8007e694` | 5 | 5/5 | **5/5** |
| case 3 `0x8007e6a8` | 113 | 74/113 | **113/113** |
| case 4 `0x8007e86c` | 22 | 18/22 | 19/22 |
| tail `0x8007e8c4` | 24 | 24/24 | **24/24** |

## 1. The copy block: the source order is the *reverse* of the emitted order

The 17-word field-copy block is duplicated in both `f8` arms and is now **17 of 17 in both**. Two things were needed.

**Chained assignment**, so one load feeds two stores: `s->f38 = s->f1b6 = s->f32` emits
`lhu a0,50(s0); sh a0,438(s0); sh a0,56(s0)` where two separate statements emit an extra `move` per pair (+2 words).

**Then the statement order, which is not what the code looks like.** The image's emitted order is
`f2c`, `f25e`, `f32-pair`, `f1a2++`, `f2a-pair`, `f36`, so that is the order I had been writing. It scores 4/17.
The source that reproduces it is:

```c
s->f2c -= 1800;
s->f25e -= 1800;
s->f1a2 = s->f1a2 + 1;          /* the counter first ...                */
s->f34 = s->f1b4 = s->f2a;      /* ... then the f2a pair ...            */
s->f38 = s->f1b6 = s->f32;      /* ... then the f32 pair                */
s->f36 = *(u16 *)((u8 *)s + 0x2e);
```

i.e. the two pairs swapped relative to their emitted order — the scheduler hoists `f32`'s load above `f2a`'s once the
increment is out of the way, so **source order and emitted order disagree by one transposition and only the source
matters**. Taking the emitted order as the source order is what kept 31 words wrong: 4/17 → **17/17**, and the total
jumped 194 → 206.

## 2. The table read wants two statements, not a ternary

`s->f1e0 = (s->f8 < 16) ? D_8010BA78[s->f8 + 16] : D_8010BA78[s->f8 - 64];` scores 206; the same expression as an
`if`/`else` with two assignments scores **220**. With the ternary cc1 keeps the symbol address in **one** register and
computes only the index conditionally, so the arms each carry one `addiu` (mine swapped `v0`/`v1` against the image's
`lui v0` + `lbu v1`). As two statements each arm materialises the base itself, which is what the image shows: `lui` +
`lbu` + `addiu` per arm, and in the else copy the `lui` even lands in the `beqz` delay slot to serve both arms.

**The else copy is not a copy.** Its test uses the `c` local (`sltiu v0,a0,16`) while its index arms re-read
`s->f8` (`lbu v1,8(s0)` twice), and it has no `s->f1e8.b[2] = 0;` — the then copy has all three of those differently.
Writing `c` into the index as well scored 212; leaving the `b[2] = 0` in scored 124. Both had to go, together: 220 →
**225**.

## 3. The switch has no `default:`, and each arm's exit is `break` or `return`

This was the last structural discovery and it is worth stating as a mechanism, because it is invisible in the C.

The image's three exits from the arms are not the same:

| exit | target | words |
|---|---|---|
| case 1, three of them (`0x8007e660`, `0x8007e678`, `0x8007e68c`) | `0x8007e914` epilogue | `bnez`/`beqz`/`j` |
| case 3 (`0x8007e864`) | `0x8007e8c4` **tail** | `j` |
| case 4 (`0x8007e8bc`) | `0x8007e914` epilogue | `j` |
| dispatch out-of-range (`0x8007e5a8`) | `0x8007e8c4` **tail** | `beqz` |

The dispatch's out-of-range path reaching the tail is the tell: **there is no `default:` label at all**, so the
table's out-of-range slot falls out of the dispatch to the statements *after* the switch — and those statements are the
device-update tail. Then:

- case 3 ends with `break;` → the tail, so case 3 runs the device update;
- case 1's three exits and case 4's exit are **`return;`** → the epilogue, skipping the tail;
- case 0 falls through into case 1, as M275 established, and inherits case 1's `return`s.

Two intermediate states pin the mechanism. Keeping `default:` inside the switch (M277's source) sends case 3's `break`
to the epilogue: 3 words wrong at `0x8007e864`. Removing the `default:` but leaving case 1's exits as `break` sends
*those* three to the tail: 3 words wrong at `0x8007e660`, `0x8007e678`, `0x8007e68c` (223). Only making all four exits
`return;` is exact (226). **In a `void` function, `break` and `return` are the same behaviour and different code, and
which arms use which is decidable from `j` targets — one word each.**

A related fact, measured with a four-line fixture rather than guessed: **cc1 emits case bodies in source order**, not in
jump-table order. A switch with `default:` between `case 0` and `case 1` emits `A`, `D`, `B`, `C`. So the image's block
layout (`case 3`, `case 4`, tail) *is* the source order of the arms, and the arrangement that would put `default:`
between case 3 and case 4 is refuted by the layout alone.

## 4. What is left: three words, one register, and it did not move

Case 4's select is the only remaining hunk:

```
image: lbu v1,5(s0) ; li v0,22 ; bne v1,v0,L ; li v0,5 ; li v0,4 ; L: sb v0,5(s0)
mine : lbu v1,5(s0) ; li v0,22 ; bne v1,v0,L ; li a0,5 ; li a0,4 ; L: sb a0,5(s0)
```

The image reuses `v0` — the register that held `22` — for `5` and `4` and stores from it; mine puts the value in `a0`,
which is dead on both sides (it held the device base). Fifteen variants were measured and **none moved it**: commuted
operands (`22 == s->f5`), `0x16`, `4U`/`5U`, `(u8)` casts on the arms, `u8`/`u32` temporaries with and without braces,
`(u32)` on the condition, a `u8` local holding `s->f5`, `+ 4` arithmetic (225), character literals, double parentheses,
and `if`/`else` assignment (194 — two stores, so the value-select is confirmed). With the rest of the function exact,
the liveness at that point is identical, so this is the allocator's ordering alone: the same class as
`0x80024558`'s three words, and M270's finding holds — **a tie-break that survives fifteen shapes is not steerable
from the source.**

## 5. What this changes about the method

The two levers that did the work here are both *"the emitted order is not the source order"* facts, and they now have
concrete instances: a transposition inside a block (the copy block's pairs), and a choice of exit kind
(`break` vs `return`). Together they mean the last mile in a long function is not "more archaeology" but **reading the
branch targets as statements**: every `j` to the epilogue is a `return`, every `j` to the falling-out label is a
`break`, and a block's emitted order can be one transposition away from its source.

The probe corpus is unchanged at **30 cases, all passing**, and `0x8007e590` is still not in it — 226 of 229 is not
exact. The honest coverage reading is unchanged as well: everything at or below 206 words has come out byte-exact, and
both remaining failures are the two largest functions, each with a three-word allocation residue
(`0x80024558` 136/139, `0x8007e590` 226/229).
