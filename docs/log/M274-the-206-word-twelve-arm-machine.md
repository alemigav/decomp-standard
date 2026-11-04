# M274 — the 206-word twelve-arm machine: the widest dispatch, byte-exact, and four single-word discriminators

The next candidate was chosen to test a shape nothing else had: **`0x80059530`**, a **twelve-arm** dispatch of
**206 words** — the widest and the largest yet. It also turns out to be the state machine that runs *immediately
before* `0x80059868`, the 167-word function M272 recovered: this one's last word is `0x80059864`, the other begins at
`0x80059868`. So the two share a `Ctx` layout and a device idiom, and the recovery reused them.

## 1. Result: 206 of 206

| region | words | region | words |
|---|---|---|---|
| head `0x80059530` | **15 / 15** | case 6 | **9 / 9** |
| case 0 | **23 / 23** | case 7 | **32 / 32** |
| case 1 | **20 / 20** | case 8 | **19 / 19** |
| case 2 | **9 / 9** | case 9 | **6 / 6** |
| case 3 | **18 / 18** | case 10 | **12 / 12** |
| case 4 | **9 / 9** | case 11 | **9 / 9** |
| case 5 | **20 / 20** | tail `0x80059854` | **5 / 5** |
| **whole function** | **206 / 206 by offset, 206 / 206 content** | **jump table `0x800b9010`** | **12 / 12** |

`.rodata` is 48 bytes — the table and nothing else. The only difference is two zero words past the extent (the `as`
alignment padding class, now its fifth instance). Independently re-measured, not taken on report.

**And the extent was one word bigger than I said.** I computed 205 words from the head and arm list; `0x80059868 −
0x80059530 = 824 B = 206 words`, and the missing word is the epilogue's `addiu sp,sp,32` — the `jr ra` delay slot,
which a `nop`-terminated arm list hides. The arm list summed to 206 only because arm 11's size already contained the
shared tail. Worth recording as a method note: **derive the word count from two addresses, not from a sum of parts**
— a sum of parts cannot tell you it has double-counted a tail.

## 2. Four discriminators, each worth a single word

| discriminator | wrong shape | what decides it |
|---|---|---|
| a negative constant stored into a `u16` field must arrive **signed** | `s->f1e0 = -800;` on a `u16` emits `ori rt,zero,0xfce0` and scores 205 / 206 with 2 hunks | the image has `addiu rt,zero,-800`; a signed RHS (`*(s16 *)&f1e0 = -800`) reproduces it. Check the opcode, never the printed value |
| two structurally identical clamps need **opposite** comparisons | assuming both clamp the same way | case 3 is `blez` (`> 0`) and case 8 is `bgez` (`< 0`), eight cases apart. A clamp's direction is a per-arm fact |
| a `* k` is visible in the **shamt** of its `sll` | copying the neighbour's multiplier | `sll` by 4 (`* 5` after `addu`) here, where `0x80059868` has `* 3`. Two adjacent functions, different constants |
| **a call is a scheduling barrier** | hoisting the argument materialisation by hand | to keep the `jal` after a group of stores, the stores must *precede* the call in the source; the `lui`/`ori` of the arguments is the scheduler's job |

The first one is the sharpest: `-800` written as a `u16` field assignment and `-800` written as a signed store are
the same *value* and different *instructions*, and only the `addiu`-versus-`ori` bit tells you which the source had.

## 3. Coverage now

| function | words | result |
|---|---|---|
| `0x80070120` | 46 | exact |
| `0x80057e1c` | 84 | exact |
| `0x8004fd1c` | 98 | exact |
| `0x80024558` | 139 | 136, residue is allocation |
| `0x80059868` | 167 | exact |
| **`0x80059530`** | **206** | **exact** |

**Five of six exact**, and the single failure remains the one whose residue is a register-allocation tie-break. The
profile now has direct evidence at 46, 84, 98, 167 and 206 words, on dispatch bounds 5, 6, 7, 7, 12 and 12. The
method's remaining limit is unchanged and specific: a function whose accesses leave the allocator free.

## 4. The map, which is now the cheap part

Registering this function needed **one entry** in `progress_map.py`'s table plus a regeneration: the README's block
re-rendered with a fifth bright cell, the gate passed, and the phase row moved to M251–M274. That is the whole point
of having generated it — a milestone now costs one table line and a `--write`, instead of hand-editing a chart that
would then have to be trusted.

Corpus is **28 cases, all passing**, with the pin asserting `same_offset == 206`.
