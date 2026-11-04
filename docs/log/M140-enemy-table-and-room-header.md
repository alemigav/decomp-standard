# M140 — the enemy routine table is found; the room header is runtime data, and that closes the static route

Two results, one of them a correction I owe the owner.

## 1. Correction: there **is** an open-source RE2, and I said there wasn't

M137 recorded "there is no open-source RE2 PS1" on the strength of a GitHub search for
*decompilation* terms. That was too strong. **`OpenBiohazard2/OpenBiohazard2`** is **MIT-licensed**, 303★,
written in **Go**, described as an *"Open source re-implementation of the original Resident Evil 2 /
Biohazard 2"*, created 2020, default branch `master`.

The distinction that matters is **decompilation vs re-implementation**, and it is not cosmetic:

| | `bio2-ds` (M137/M138) | `OpenBiohazard2` (this milestone) |
|---|---|---|
| kind | disassembly/decompilation of the PS1 binary | engine re-implemented from scratch, in Go |
| licence | **none** — Capcom/Sony copyright stated | **MIT** |
| what we may do | reference only; hypotheses, never code | **read as code**; MIT permits reuse |
| provenance risk | binary-derived (prototype `MAIN.SYM`) | independent code, describing observed behaviour |

So the earlier "reference-only, nothing copied" posture was correct **for `bio2-ds`** and is **not required**
for `OpenBiohazard2`. It has not been inspected yet — that is the obvious next read, and the question to ask
of it is specific: does it implement the room file (RDT) and the room-script bytecode, and if so with what
naming? If it does, it is the first source on this project that can be *used* rather than merely consulted,
and it may name the 141 opcodes that M136 could only measure.

## 2. The enemy routine table — a family of 14-entry blocks, indexed by `object+5`

The reference's `pEnemy[Id + 0x12]` was **not** the right shape for our port: `0x800e13ec` is a
**pointer array** whose slots hold `ENEMY_WORK*` (all set to `0x800e8620` at room load, M138), so an index
of `Id + 0x12` would collide with the slots themselves. Dispatching by shape failed, so this was found by
census instead: counting every `(*(code *)(&PTR_FUN_x)[...])()` in the 36 decompiled images gives

```
 22  PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)
  9  PTR_FUN_80111078)[(*(ushort *)(...+0x1aa) & 0xfff) - 1]
  5  PTR_FUN_800eb9b0)[bVar1]
  4  PTR_FUN_80166830)[*(byte *)(param_1 + 6)      (and …667a8, same shape)
```

and the tables themselves are spaced **0x38 = 14 words** apart — `0x8011af80`, `0x8011afb8`, `0x8011b434`,
`0x8011b46c`, `0x8011b4a4`, `0x8011b4dc`, `0x8011b514`, `0x8011b6c0`. So the region is a **family of
14-entry routine tables, one per group**, and the dispatcher is:

```c
void FUN_8007bd9c(int obj, undefined4 a, undefined4 b) {
  (*(code *)(&PTR_FUN_8011af80)[*(byte *)(obj + 5)])();        /* phase / pre-call */
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(obj + 5)])(obj, a, b);
}
```

**Why `obj + 5` is the right field**: the reference packs an object's routine state as four bytes,
`Routine_0..Routine_3`, written with a single word store, and computes the motion index as
`((Timer0 & 0xff00) - 0x100) | 4` — i.e. `Routine_1` is the routine number. An index at `obj+5` is
`Routine_1`, and the selector is a **byte**, exactly as found.

Measured detail, so the next session does not have to re-derive it: the block at `0x8011afb8` is followed
by **154 consecutive stage-2 code pointers** (then a zero word), and the duplicate pattern has period
**14** — entries `i` and `i+14` are frequently the same function, which is what a family of 14-entry tables
laid end to end looks like.

**What is *not* established**, stated plainly: which base belongs to which group; whether the byte is
guaranteed `< 14` (if not, an out-of-range index silently runs into the next block — a hazard, not a
finding); and which table the *enemy type* selection uses, as opposed to the motion/state selection.
The next test for the bounds question is cheap: find where `obj+5` is written and check the range of values
the writers can produce.

## 3. The room header is runtime data — the static search is closed, not merely exhausted

`stage2/0x800258d8.c:48`:

```c
DAT_800c52d8 = FUN_8008af80(0xaf800);      /* heap allocation, 718 848 bytes */
```

`DAT_800c52d8` is therefore **not** a cartridge buffer and not a member: it is a **heap allocation**, and
`0x80064ff0` sets `DAT_800df930 = DAT_800c52d8` while `0x8009c660` composes scene blocks inside it
(sub-bases at the base and at `base + 0x52c38`, loading ids `0x15b9`/`0x15ba`/`0x15bb`, and computing
remaining space as `end - ptr`, e.g. `DAT_801124d0 = DAT_800c52d8 - (DAT_800df934 + -0xaf800)`).

That single fact explains M137's twelve unvalidated candidates and makes the test the owner asked for a
**negative with a reason**: the room header cannot be found statically because it does not exist in any
image — it is written into a heap region at room load.

The test was run anyway, properly bounded: the reference's shape (8 count bytes, then 23 self-relative
offsets that are ordered and span the file) was scanned across **all 36 images**, giving **0 hits** — and a
byte-shuffle control (12 images × 3 shuffles, same bytes, order destroyed) also gave **0 hits**. A test with
no power on the data is **inconclusive**, not evidence of absence, so it is recorded as inconclusive and
nothing is concluded from it.

The route that survives is the one the heap fact creates: follow the **block ids** `0x15b9`/`0x15ba`/`0x15bb`
into the descriptor table (`FUN_80001180` and the boot table), which is exactly how the nine registry
members were tied to their members in M19. That names the room data's own source, and the header layout
then comes from the code that writes it into the heap — anchored in this port's code, not in the
reference's shape.

## 4. Order of work from here

1. **`OpenBiohazard2`** — MIT, so read it as code. First question: does it implement RDT + the script
   bytecode, and does its naming match our 141 opcodes (M136) and our 14-entry routine tables (above)?
2. **The block ids** `0x15b9`/`0x15ba`/`0x15bb` → descriptors → the members that carry room data.
3. **`obj + 5` writers** — bound the routine index, which decides whether the 14-entry tables are safe.

```
python3 tools/acceptance.py                     # 98 cases, 10 fixtures — unchanged
```
