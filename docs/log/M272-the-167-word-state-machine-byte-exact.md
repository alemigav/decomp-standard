# M272 — the 167-word state machine: byte-exact, and three shape levers that are discriminators

The next function from the dispatch-head queue after p9 was chosen by a different rule than the previous ones: not
the smallest, but the one that answers the question M271 left open — **does the `-mcpu=r4300` profile reproduce large
functions as reliably as it reproduced the 46-word one?** The candidate was `0x80059868`: **167 words, double p7**,
with a proper prologue, a `lbu 6(ctx)` index (the same index source p7 uses), bound 7, and seven arms whose sizes
are wildly uneven — 41 words against 6.

## 1. Result: 167 of 167

| region | words |
|---|---|
| head `0x80059868` | **14 / 14** |
| case 0 `0x800598a0` | **23 / 23** |
| case 1 `0x800598fc` | **41 / 41** |
| case 2 `0x800599a0` | **32 / 32** |
| case 3 `0x80059a20` | **19 / 19** |
| case 4 `0x80059a6c` | **6 / 6** |
| case 5 `0x80059a84` | **12 / 12** |
| case 6 + epilogue `0x80059ab4` | **20 / 20** |
| **whole function** | **167 / 167 by offset, 167 / 167 content-aligned** |
| **jump table `0x800b9040`** | **8 / 8**, and `.rodata` is 32 bytes — the table and nothing else |

The only difference is one `nop` **past the image's extent** — `as` pads `.text` to 16-byte alignment and
`--set-section-alignment .text=4` rewrites `sh_addralign` without shrinking the section, the fourth instance of that
residue class (p6, p8, p9, here). Independently re-measured after the recovery, not taken on report.

**This function contains no pool literal at all** — every constant is `lui`/`ori` or an immediate — so the pool
pathologies that dogged p6 and p8 cannot arise in it. That is worth noting: the residues are not uniformly
distributed, they cluster where the code shape gives the compiler a choice.

## 2. Three shape levers, each a measured discriminator

Every one of these was found by trying the alternative and watching the score collapse:

| lever | wrong shape scores | what the image pins |
|---|---|---|
| a word field and the bytes inside it are **one union member** | `u32 f1e8w; u8 f1e9; u8 f1ea;` → **136 / 167**, 25 hunks | sibling fields let gcc prove the byte reads disjoint from the word store and re-schedule the whole body |
| fields written with `lhu`/`sh` are **`u16` with an explicit `(s16)` cast in the predicates** | declaring them `s16` → **160 / 167** | the image pairs `lhu`/`addiu`/`sh` for `f -= k` with `lh` for the `< 0` test, i.e. the field is unsigned and only the predicates see it signed |
| a compound test is **nested `if`s**, not `&&` | flat chain → **157 / 167**, and 10 words lost in that arm alone | the pointer assignment *between* the tests is what stops the symbol's `lui/addiu` being kept live across the branch |
| the device pointer needs a **local** | `((struct Dev *)(D_800C76B0 + 0x18000))->f` directly → **40 / 167** | `dev = D_800C76B0;` then `dev + 0x18000` is what produces `lui $1,1; ori 0x8000; addu` instead of a folded symbol |

The union lever is the important one: it is the same *kind* of discriminator as p9's variable width and p7's
struct-vs-pointer rule — **an access-kind fact, not a statement-order fact** — and it is the first case where the fix
is about *struct decomposition* rather than struct-versus-pointer.

And M271's cheap test generalises: this function also has **no `default:` and no trailing `return`**, with the
out-of-range path falling to the epilogue on the `sltiu` result. A 167-word seven-case switch with an empty default
costs zero words here.

## 3. The method's coverage, which was the actual question

| function | words | result |
|---|---|---|
| `0x80070120` | 46 | exact |
| `0x80057e1c` | 84 | exact |
| `0x8004fd1c` | 98 | exact |
| `0x80024558` | 139 | 136, residue is allocation |
| **`0x80059868`** | **167** | **exact** |

Four of five exact, and the one failure is the *one* whose residue is a register-allocation tie-break rather than an
access-kind fact. So the answer to the question is yes, with a shape: **the profile scales; what does not scale is a
function whose reconstruction leaves the allocator free to choose.** That is a sharper statement than "big functions
are harder", and it is testable on the next candidate: prefer functions whose accesses pin the registers.

The probe now carries this function as a whole-function case plus a table case — corpus **26 cases, all passing**,
with the pin asserting `same_offset == 167` rather than a threshold.
