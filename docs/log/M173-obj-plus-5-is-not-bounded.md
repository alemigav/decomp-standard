# M173 — `obj+5` is not bounded below 14, and 14 turns out not to be the bound

M140 left the bounds question open and said exactly what would settle it: *"find where `obj+5` is written
and check the range of values the writers can produce"*. That is done here. The answer is **no, and the
question was mis-framed**: `+5` is a *class-local state number*, and each object class has its **own**
state table, of a different length. Fourteen is class 1's number alone.

Everything below is asserted by `tools/routine_index.py` (**14/14**, cartridge-dependent) and three of the
assertions are mutation-audited in `tools/audit_gates.py` (**18/18, 0 vacuous**).

## 1. The class byte `+4` is the missing link, and `FUN_80079470` is the loop

`FUN_80079470` is the per-object update. It dispatches on **`+4`**, not on `+5`:

```c
(*(code *)(&PTR_FUN_8011a870)[*(byte *)(param_1 + 4)])(param_1, *(u32*)(param_1+0x1a4), *(u32*)(param_1+0x218));
...
(*(code *)(&PTR_LAB_8011a894)[*(byte *)(param_1 + 8) - 0x40])(param_1);      /* the 'E'/'O' routine */
```

`0x8011a870` holds `80079818, 8007bc10, 8007a6b0, 8007a6e4, 80080ef0` at indices 0–4, **nulls at 5 and
6**, then `8007a718, 8007ad70` at 7 and 8. Index **1 is `FUN_8007bc10`** — the function that routes on
`+8` and then dispatches on `+5`. So the objects whose `+5` is a routine index are exactly **class 1**,
and the class-1 writers are identifiable structurally: an initialiser that stores **`0x01000000` into
`+4..+7`** in one word (`lui r2,0x100` / `sw r2,4(rN)` — 47 such sites) sets class 1 and state 0 together.
The classes the image actually writes are `{1, 2, 3, 4, 7}` and every one of them has a handler.

## 2. One byte, five table lengths — the `+5` tables per class

| class `+4` | handler | state table | entries | how the length is known |
|---|---|---|---|---|
| 1 | `FUN_8007bc10` | `0x8011afb8` (+11 type tables) | **14** | sibling tables are `0x38` apart |
| 2 | `FUN_8007a6b0` | `0x8011a974` | **4** | the next table starts at `0x8011a984` |
| 3 | `FUN_8007a6e4` | `0x8011a984` | **2** | a zero word follows the second entry |
| 4 | `FUN_80080ef0` | `0x8011b6c0` | **27** | the run of code pointers ends there |
| — | `FUN_80055fa4` | `0x8010dc38` / `0x8010dc68` | **12 / 12** | next table `0x30` later; then a data word |

The `+5` census is **28 stage-2 sites**, all of the same shape, and this is where M140's framing needs
correcting: of those 28, **22** index the class-1 family (`0x8011af80`, `0x8011b2e4` and their 0x38
siblings) and **6** index the other classes' tables above. M140 pooled the bases from both class-1
families into one list and called the region "a family of 14-entry routine blocks"; the families are two
(the plain and the `'E'/'O'` one), they share **one** main table, and the other classes' tables are not
14 long at all.

So `+5 < 14` fails three separate ways: class 4's table has 27 entries, where 14+ is *legal*; class 3's
has 2, where 2+ leaves the table entirely; and class 1's is 14, where a writer stores 15.

## 3. No dispatch checks the index — and the tables abut, so nothing fails loudly

Instruction-level, at all 28 sites (`FUN_8007be18` shown):

```
0x8007be38  lbu   r2, 5(r16)        ; the index: the raw byte, unsigned
0x8007be3c  addiu r3, r0, 0xaff0    ; with lui r3,0x8012 → 0x8011aff0, this type's table
0x8007be40  sll   r2, r2, 2
0x8007be44  addu  r2, r2, r3
0x8007be48  lw    r2, 0(r2)
0x8007be4c  jalr  r2
```

No `andi`, no `sltiu`, no compare — the gate decodes all 28 prologues and requires the first writer of
the loaded byte to be `sll reg,reg,2`. With 12 rows of 14 laid end to end, indices **0..153 stay inside
the class-1 block** (`0x8011afb8 + 4·153 = 0x8011b21c`), so index 14..27 is a *silent* cross-type
dispatch, not a fault. Index 15 in particular resolves to `0x8007ccec`, which is `0x8011b028[1]` — the
second entry of the **next type's** table.

Only class 3 is short enough for the hardware to notice: its table is `[800804d4, 8007a74c]` followed by
a zero word, so `+5 >= 2` there calls address 0.

## 4. The writers: 0…13 then 15, and never 14

Enumerated across the 46 class-1 initialiser functions (47 store sites), the values stored into the state byte are

```
0 1 2 3 4 6 7 8 9 10 11 12 13 15          (14 never)
```

plus one writer that copies the type nibble: `*(byte *)(p + 5) = *(byte *)(p + 0x1ab) & 0xf` (0..15).
The 15 is instruction-verified, not decompiler-derived:

```
0x801623ec  lhu   r2, 0x1aa(r18)     ; the object's type word
0x801623f0  andi  r3, r2, 0xfff
0x801623f4  addiu r2, r0, 1
0x801623f8  bne   r3, r2, +3         ; only for type 1 …
0x801623fc  addiu r2, r0, 0xf
0x80162400  sb    r2, 5(r18)         ; … state = 15
```

and the same function sets the class in one word: `0x80162810  lui r2,0x100` /
`0x80162818  sw r2,4(r18)` — class 1. So the object does route through `FUN_8007bc10` → the `+5`
dispatch, with 15.

What that costs, stated plainly: another type's routine runs. Nothing crashes, nothing logs. Whether
that is an original-game bug or an intentional "one past" reuse of the neighbouring table cannot be
settled from this image — the *bound* question, however, is settled: **the tables do not bound the
index, and the writers do not keep it below 14 either.**

## 5. The same defect one field up: a mask wider than its table

The *type* index is `(+0x1aa & 0xf)`, masked to 0..15, and it selects from `0x8011af48` / `0x8011b2ac`.
Both tables hold **11** code pointers. The words after them are the per-type byte array (`0x8011af74`,
`0x8011b2d8`) and the 4-bit values are `0…0x0f`, so nibbles 11, 12 and 13 read `0x00000002`,
`0x02000002` and `0x0202020f` — jumping to those addresses, not calling a routine. The mask is a bound
that is four entries wider than the table it protects.

## 6. What changed in the gates

* `tools/routine_index.py` (new, **14 cases**): table shape (22 type tables + the shared main, every
  entry required to *point at* a real function start, `jr ra` stubs accepted), the `+5` census and the
  no-guard decode, the per-class lengths with their basis, the writer value set, where 15 lands, the
  class table's coverage, and the mask-vs-table width.
* `tools/audit_gates.py`: three new audits, one per leg of the answer — a table base shifted by one
  word, every index counted as masked, and the out-of-range writer values dropped. **18/18, 0 vacuous.**
* `tools/audit_gates.py` also now symlinks `build/elfs` and `src` into each audit's throw-away
  environment. Without them a mutated image-dependent tool failed on a *missing* `images.json`, which
  is the "fails for the wrong reason" defect this tool exists to catch.

```
python3 tools/routine_index.py        # 14/14 — the bounds question, answered
python3 tools/acceptance.py           # 20 suites, 214 cases
python3 tools/audit_gates.py          # 18/18, 0 vacuous
```
