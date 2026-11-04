# M168 — the handle's high byte is a global allocation counter, not a per-slot generation

The release path is `FUN_80085300`. It touches four fields, and `DAT_80124858` is not one of them. The
"generation" in M167's `slot | generation << 8` was a **misnomer**: it is a single global counter that bumps on
every *allocation*.

## 1. Allocation versus release, field by field

| field | `FUN_80085164` / `FUN_8008522c` (allocate) | `FUN_80085300` (release) |
|---|---|---|
| `DAT_8012485c` — free-list head | popped: `head = free[head*4]` | **pushed**: `free[slot*4] = head; head = slot` |
| `DAT_8012487c[slot]` — the handle | **minted**: `slot \| DAT_80124858 << 8` | compared, then left alone |
| `DAT_8012486c` — busy bitmap | bit **set** | bit **cleared** |
| `DAT_80124868` — live count | `+1` | `-1` |
| **`DAT_80124858`** | **`+1`** | **untouched** |

```c
/* FUN_80085300(handle) — the release */
uVar2 = param_1 & 0x7f;                              /* slot from the handle's low 7 bits */
if (DAT_8012487c[uVar2 * 4] == param_1) {            /* stale-handle guard */
    DAT_8012486c[uVar2 >> 5] &= ~(1 << (DAT_8012487c[uVar2 * 4] & 0x1f));
    DAT_80124880[uVar2 * 4] = DAT_8012485c;          /* push */
    DAT_80124868 = DAT_80124868 - 1;
    DAT_8012485c = uVar2;                            /* head = this slot */
}
/* no store to DAT_80124858 anywhere in this function */
```

So: **no, the generation does not bump on free.** It is bumped on allocate, by both allocators, and reset to 0 by
the pool initialiser `FUN_800850e0` (which also builds the 128-slot free list `1 → 2 → … → 0x7f`, sets
`DAT_8012485c = 1` and `DAT_80124868 = 0`).

## 2. Why stale handles are still rejected

Not because of per-slot generation bumping, but by two weaker mechanisms that happen to compose:

* **monotonicity**: `DAT_80124858` only ever increases, and a slot reissued later is stamped with a *higher*
  value than the handle that named it before. Since reissuing a slot *is* an allocation, the counter always
  advances between the two handles for that slot — so the old handle's high byte cannot match the new one;
* **equality guard**: `FUN_80085300` acts only when `DAT_8012487c[slot] == handle`, so a release presented with a
  stale handle is **silently ignored** rather than freeing someone else's slot. That is a double-free guard, and
  it is the only thing standing between the design and a reissued slot being freed by an old owner.

## 3. The two caveats that follow from it being global

* **The counter is never masked.** `uVar1 | DAT_80124858 << 8` has no wrap handling, so after 2^24 allocations the
  high byte overlaps the slot field. That is unreachable in practice (a session would have to allocate 16.7 M
  tiles) but it is a real property of the code rather than an assumption — and it exists *because* the counter is
  global; a per-slot 24-bit generation could not corrupt the slot field.
* **A slot's handle history is not per-slot state**, so nothing prevents the same slot from being minted twice
  with counters that differ by exactly 1 — the guard is *value* inequality, not depth. A design that bumped a
  per-slot generation would carry the same weakness, so this is a note on the mechanism, not a defect.

## 4. The bulk path is the same story

`FUN_80085398(lo, hi)` releases by **address range**: it walks the busy slots, and for each whose block pointer
lies in `[lo, hi)` it sets the pointer field to `0xffffffff`, ORs `0xff` into the **stored handle** — making it
unequal to any handle a caller could present — and clears the busy bit. So the range-release invalidates handles
by corrupting their stored value, and again never touches `DAT_80124858`.

## 5. Scope: this is a code reading, not a measurement

M167 gated the *data* consequences of the pairing rule; this milestone's claims are about **code**, verified by
reading four functions and comparing their field updates line by line (§1), which is falsifiable but not gated.
The registry arrays live in a 128-slot table the game builds at runtime, so there is no cartridge data to assert
against. Stated plainly rather than dressed as a check.

**183 cases across 17 fixtures**, `ci.sh: ok`, 18/18 marker checks, audit 15/15 — unchanged, because nothing here
is a fixture.
