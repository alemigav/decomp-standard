# M186 — the 835 unresolved shorts are 834 zeros and one dangling reference

M185 left a remainder it refused to round up: of the **5 136** shorts in `SND_PROJ`'s lists, **4 301**
resolved to `SND_POOL` keys and **835** did not. This chases the 835, and they are not a second object
class.

## 1. 834 of them are structural

**834 of the 835 are the constant `0`**, and they sit at **positions 0 and 2 of every one of the 417
lists**. So every list opens

```
[0, a, 0, b, key, key, key, ...]      terminated by -1
```

`a` takes **55** distinct values and `b` takes **54** — small numbers (40, 48, 44, …), the shape of two
parameter fields stored as `u32`s whose high half is zero, not of pool references.

## 2. One is a real dangling reference — and the pool agrees

Exactly **one** non-zero short fails to resolve: **`531`**, in the list of the **first** record, at position
4.

That value does not exist anywhere in the pool. And `SND_POOL`'s section 0 has **exactly one hole** in its
key range:

```
section 0: 2025 keys, 1..2026, holes [531]
```

So the two facts close each other. The project names a pool entry that is absent, and the pool is absent
*precisely that entry*. This is a **dangling reference in the shipped data**, not a decoding failure on
either side — and it only became visible because both structures were decoded.

## 3. The accounting is now total

| | |
|---|---|
| shorts in the 417 lists | **5 136** |
| resolve to `POOL` keys | **4 301** |
| prologue zeros (positions 0, 2 of every list) | **834** |
| dangling reference to key `531` | **1** |
| **sum** | **5 136** |

Every short is accounted for, and the case asserts the identity so the remainder cannot quietly reappear.

Two holes now sit next to each other in the record: the `PROJ`'s own key set is a bijection onto 0..417
**less `11`** (M185), and the `POOL`'s section 0 is 1..2026 **less `531`**. Both are single holes in
otherwise contiguous key spaces, and neither is explained. They are the same *kind* of anomaly, which is
worth noting even though nothing yet connects them.

## 4. Gates

`file table (cartridge)` **48 → 53**: the 834 prologue zeros and their positions, the `[0, a, 0, b]` shape
with its 55/54 distinct parameters, the single stray `531`, the pool's single hole `[531]`, and the total
accounting identity. Audit **44/44, 0 vacuous**; ratchet refused `48 → 53` until `--write`; counts derived
and asserted in twelve places.

Repository is **33 suites / 385 cases**, of which **12 suites / 180 cases** are cartridge-gated, so the
runnable tier is **21 suites / 205 cases**.
