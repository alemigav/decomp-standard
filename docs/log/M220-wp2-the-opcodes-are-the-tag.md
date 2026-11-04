# M220 — WP2: the macro "opcodes" are the key's class tag, and the pool walk was one record late

The audio review's WP2 asked for a macro command interpreter. What the bytes support is narrower and more
interesting: **there is no bytecode**. An operation is selected by the top two bits of a 16-bit key — the same
`(key >> 14) & 3` this project has been using as a *storage class* since M200 — and the "program" is a typed array
of fixed-stride rows.

## 1. The command space

Dispatch is `FUN_800a6820`, which masks `key & 0xc000` and switches on it. The program is `SND_POOL`'s tag-2
section at `0x24004`: a `{u32 count}` then 12-byte rows, 327 arrays of 1 315 elements (981 live, 334 `0xffff`
skips), run by `FUN_800a64c8`.

| opcode | payload | count | what it requests |
|---|---|---|---|
| `0x0000` | class-0 record, 3–16 × 8 B | 2 026 | one voice (`FUN_800b185c` → `FUN_800ad998`) |
| `0x4000` | 128 × 8-byte slots | 4 | `slot[sel & 0x7f]` → a key, re-dispatched |
| `0x8000` | count × 12-byte rows | 327 | per live row: key, window lo/hi, `s8` δ, volume, `s16` channel, `u8` pan |
| `0xc000` | 8 B, four little-endian `u16` | 242 | a level ramp (`FUN_800afbfc`); the dispatcher returns −1 |

**Three negatives, measured not assumed:** no payload anywhere is variable-length (each divides exactly by its
element stride); **no row field is ever dereferenced**, so there is no pointer-in-a-row — WP1's
`{key, count, pointer}` is `FUN_800adb48`'s *bank entry* and points at the row array itself; and `0xffff` is a skip
that appears **seven times inside** arrays, never a terminator.

So the honest answer to "what are the macro commands": **four, they live in the key, and the operand layout is the
record's class**. Anything that looks like an opcode byte inside an element is a byte the cartridge reads as data,
and inventing one would be inventing the thing WP1 went looking for and did not find.

## 2. The correction: a pool section's first record is *at* its offset

WP2 set out to interpret commands and instead found a defect in how this project walks `SND_POOL`. Each section's
u32 at its own offset is **that record's stride**, not a pointer past it. `file_table.py` walked
`_chain(pool, st + stride, end)` — one record late — and skipped exactly **four** records in total: the first of each
section, whose keys are `531`, `-16251`, `16385`, `-32616`.

Those four keys are **precisely the set M186, M188 and M219 spent three milestones arguing about.**

| | claim | outcome |
|---|---|---|
| M186 | 834 prologue zeros + "exactly one dangling reference (531)" | prologue refuted by M219; the dangling reference is this off-by-one |
| M188 | "one hole at 531 in section 0, which the PROJ dangles on" | the hole was the skipped record |
| M219 | base corrected; "531 survives, as one of 4 unresolved" | half right: the base fix was real, the 4 were this bug |
| **M220** | **all seven thousand three hundred and eighty-eight list values resolve** | **0 unresolved** |

Corrected pool counts: **[2 026, 242, 4, 327] = 2 599** records, not `[2 025, 241, 3, 326] = 2 595`.

**This is the third flip on one fact, and the lesson is not "measure more" — it is "measure with the reader that
every other case uses".** My M219 correction came from a quick script that disagreed with the gate by four keys and
I trusted the script. The gate was wrong in the *same* place, which is why the disagreement looked like noise. WP2
found it by asking what the cartridge's own dispatcher reads, not by re-counting.

## 3. Gates

`sound macros (cartridge)`: **24 cases** — the dispatch mask, the four opcodes' witnesses (`src/` lines), the
no-variable-length and no-dereference negatives, the skip-not-terminator count, and the pool-cache lookup at stride
`0xc` returning the count from its own `+6`. `file table (cartridge)` stays **101** with two cases re-derived (the
section counts, and the unresolved set which is now empty).

Two mutations. The first attempt was **vacuous twice over**: `& 7` instead of `& 3` changes nothing because bits
12–13 are always zero, and moving the shift makes the tool *hang* rather than fail — a crash the audit would have
scored as detection. The mutation that survives that filter relabels `0x4000` as `0x8000`: counts stay right, labels
move, and the drift case catches it. The second mutation restores the `st + stride` walk, and the section-count case
fails loudly.
