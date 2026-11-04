# M188 — the two holes: 531 is a stale index, 11 is an unused slot

M185 and M186 each ended with a single hole in an otherwise contiguous key space, sitting side by side and
unexplained: the `SND_PROJ`'s own keys are a bijection onto 0..417 **less 11**, and `SND_POOL`'s section 0
is 1..2026 **less 531**. They are the same *kind* of anomaly and **not the same fact**.

## 1. 531 closes completely

The proj's lists are not just *some* pool references — they cover the slot range **completely**:

| | |
|---|---|
| distinct values at key positions (index ≥ 4) | **2 026**, min **1**, max **2 026** |
| of those, present in the pool | **2 025** — exactly section 0's record count |
| of those, absent | **{531}** — exactly the one hole |

So the proj speaks for **every** slot in 1..2026 and the pool supplies all but one. The dangling reference
and the hole are the *same fact seen from two sides*: a proj list still names a sample that the builder
removed. Nothing about it is ambiguous, and the case asserts the identity `2 026 = 2 025 + 1` rather than
the coincidence of a matching number.

## 2. 11 does not close, and that is the finding

Key `11` exists **in the pool**. It is also a live reference: the value `11` appears at key positions in
**two** proj lists, belonging to the records keyed **6** and **51**.

So the proj's missing record is **not** a dangling target — nothing in the pool is orphaned by it, and the
value it names is healthy. What is missing is the **proj slot itself**: 418 possible song keys (0..417),
417 records, slot 11 empty. Nothing in the pool or the directory refers to proj keys, so there is no second
artefact of its absence.

Stated plainly: **531 is a stale index; 11 is an unused slot.** Different causes, only one of which is
explainable from the data. Why there are 418 slots for 417 records is **open**.

I flagged earlier that pool section 1 has exactly **11** holes and the proj's hole is at **11** — that is a
coincidence, and worth recording *as* one so it does not get promoted later.

## 3. The hole census, per section

The pool's four sections are not uniform, and only now is that visible:

| section | records | key range | holes |
|---|---|---|---|
| 0 | 2 025 | `0x0001`–`0x07ea` | **1** — `0x213` (531) |
| 1 | 241 | `0xc001`–`0xc0fc` | **11** — `0xc008, 0xc038, 0xc03b, 0xc05f, 0xc068, 0xc075, 0xc07e, 0xc085, 0xc08c, 0xc09c, 0xc0b9` |
| 2 | 3 | `0x4002`–`0x4004` | **0** |
| 3 | 326 | `0x8002`–`0x8148` | **1** — `0x8098` |

The keys are now legible as `[class][index]` — `0x0…`, `0x4…`, `0xC…`, `0x8…` are four separate spaces, which
is why section 1's negative-looking keys are not an anomaly but a class. That reading is stated as a
*reading*: the class structure is visible in the hex, and nothing yet establishes what each class means.

## 4. Sections 1–3 are never referenced

The proj reaches **only** section 0. Sections 1, 2 and 3 hold **241 + 3 + 326 = 570** records, and **570** is
exactly the count of pool keys no proj list names. So an entire population — 22 % of the pool — is dead as
far as this project is concerned, and the sections' holes are therefore harmless: nothing can dangle on them.

That is worth knowing before anyone spends time on the codec of a sample in section 3.

## 5. One small new law

The two prologue parameters of every proj list are **multiples of 4 throughout** — all 834 values. That
narrows what they can be: an offset or a length in bytes, not an arbitrary id.

## 6. Gates

`file table (cartridge)` **59 → 65**: the complete slot coverage with its `2 026 = 2 025 + 1` identity, the
570-record unreferenced population, the per-section hole census, the unused-slot-vs-live-value distinction
with the two lists that name `11`, and the multiples-of-4 law.

The section-3 comparison had to be masked (`h & 0xFFFF`) because the keys are read signed — sections 1 and 3
carry negative ranges — and the unmasked assertion failed on `0x8098` arriving as `-32616`. That is
recorded because the sign is a property of the *reading*, not of the format.

Audit **44/44, 0 vacuous**; ratchet refused `59 → 65` until `--write`; counts derived and asserted in twelve
places.

Repository is **33 suites / 397 cases**, of which **12 suites / 192 cases** are cartridge-gated, so the
runnable tier is **21 suites / 205 cases**.
