# M86 — the loader's contract, and two bugs in the instrument I was about to trust

Three results, in order of how much they change:

1. **`FUN_800327ec` defines the cartridge's load contract in three branches**, and one of those
   branches — "stored size equals the vram span" — is the test that would mark a payload
   uncompressed. **No record in this cartridge passes it**, which is a sharper result than the
   audit's reading and it re-opens rather than closes the R4 question.
2. **The `0x800fb264` contradiction dissolves** — I made the sign-extension error a *third* time,
   in the ad-hoc dump rather than in a tool. The pointer is valid and the array is real; what it
   indexes is still unproven.
3. **Two bugs in the harness are confirmed empirically**: `LB`/`LH` do not sign-extend, and
   `SWL`/`SWR` are swapped. The harness must not be the next instrument until the first is fixed.

## 1. The load contract, and why it does not close the codec question

`FUN_800327ec(record, arg)` reads the 16-byte cart record directly:

```c
if (record[1] == 0) return 0;                            /* branch 0: nothing stored          */
if (record[1] == record[3] - record[2])                  /* branch 1: stored == vram span     */
    return func_800888ec(record[0], ...);                /*           -> the "already plain" path */
inflate_init(state, *(u32 *)0x8010b6f8);                 /* branch 2: otherwise inflate        */
inflate(state, record[0], <dest>, record[1]);
inflate_free(state, 2);
```

So the contract is: `record[0]` cart pointer, `record[1]` stored size, `record[2]` vram start,
`record[3]` vram end, and the **decision between plain and compressed is
`record[1] == record[3] - record[2]`** — a derivable test, not a magic byte. That is a real
identification and it retires "the loader's compression scheme is unknown".

**But it does not resolve bank C**, and stating why is more useful than accepting the framing:

| bank | stored | vram span | branch taken |
|---|---|---|---|
| B, slot 10 | 21 579 | 52 112 | **2 — inflate** |
| C, slot 38 | 7 640 | 52 112 | **2 — inflate** |

**No record in the cartridge takes branch 1.** Every stored size is smaller than its span, so the
"plain" branch never fires; it is there for the general case, not for this data. Since bank C's
bytes are demonstrably not zlib, either the records 38–65 are never handed to this routine, or the
`stored` field means something else for them. The codec question for R4 is therefore **open and
better posed**, not closed.

Supporting evidence that branch 1 is dormant rather than mis-read: the routine is generic
(`record[1] == 0` and the plain path are both dead for this data), which is what a loader shared
across builds looks like.

## 2. `0x800eb264`, and the third instance of one mistake

The hop I left open last time was a contradiction: `lbu a0,-16(v0)` with `v0 = slot + *(0x800fb264)`,
where the word at `0x800fb264` is `0x413f514e` — not a pointer — and nothing in 36 images refers to
that address.

**The address was wrong.** `lw v0,-19868(v1)` has a *sign-extended* offset, so with
`v1 = 0x800f0000` it reads `0x800f0000 - 0x4d9c = 0x800eb264`. I composed it as
`0x800f0000 + 0xb264 = 0x800fb264` in an ad-hoc dump — OR again, one session after writing the
`addiu` bug into the errors list. The tools were right; the throwaway arithmetic was wrong. That is
the same lesson twice: **the ad-hoc command is where the errors live, and it is the thing to
replace with a tool.**

At the correct address the word is **`0x800eb204`** — a valid KSEG0 pointer — and the array it points
at is real:

```
0x800eb204:  11  0  0 ...  12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
             28 29  0 30 31  0 32 33 34  0 35 36  0  0 37 38
             39  0  0 ...                                   (bytes = slot - 16)
```

So the contradiction was mine, and the hop is a **sparse slot→ID map**.

**Retracted (M88):** the reading below — "a 40-byte array… 30 distinct values, only 2 in 38–65" —
is superseded. The structure is **two 48-byte arrays** at `0x800eb204` and `0x800eb234`, indexed
`byte[slot−16]`, covering record indices 11–38 and 39–66. The earlier numbers came from reading the
first pointer's target as if it were the whole map. It is *not* yet the
slot→cart-record map: only two of its 40 entries fall in 38–65, and 30 distinct values across 40
slots is too few for 66 records. Recorded as a real, located structure whose meaning is unproven —
which is a much better starting point than a contradiction.

## 3. Two confirmed bugs in the harness — do not trust it for this question yet

The audit named them and they reproduce. `mips_harness.py` lines 224–227 map `LB`/`LBU` to the same
zero-extending read, and `LH`/`LHU` likewise; `Memory.read` is `int.from_bytes`, so no sign
extension is possible on that path. Measured:

| instruction | harness | architecture |
|---|---|---|
| `LB` of `0xFF` | `0x000000ff` | `0xffffffff` |
| `LBU` of `0xFF` | `0x000000ff` | `0x000000ff` |
| `LH` of `0xFFFE` | `0x0000fffe` | `0xfffffffe` |
| `LHU` of `0xFFFE` | `0x0000fffe` | `0x0000fffe` |

and `SWL`/`SWR` are swapped, writing the wrong bytes as well as the wrong direction:

| instruction | harness | architecture |
|---|---|---|
| `SWL` rt=`0x11223344` at word+1 over `0xAABBCCDD` | `0x1122ccdd` | `0xaa112233` |
| `SWR` same | `0x334400dd` | `0x3344ccdd` |

**This matters directly for the open question**: the loader derives the record index with `lbu`
(not `lb`, so this one is safe) but `FUN_8003287c` also reads `lhu` fields and `0x800888ec` is
called with a cart pointer it may adjust with signed offsets. A harness answer computed with
zero-extended loads is not a trustworthy answer.

**Not fixed here.** The standing instruction is that the verified MIPS execution path is not
modified without approval, and these are four instructions in that path. They are one-liners
(sign-extend after the read; swap the two store implementations) plus a regression test using the
table above — which is the form the project already used for CP0, where the model was validated
(`CP0 validated 5/5`) before being trusted.

Also recorded, unverified by me but consistent with the code: `run_guest_sched.build` defaults
`with_ipl3=False` while `diff_rdram.load_ares` uses `with_ipl3=True`, so the harness and the ground
truth are two different boots; and `BC1F`/`BC1T` test bit 2 of `rt` rather than bit 0.

## 4. The scan's own numbers, decomposed

`find_bank_writers.py` reports 720 stores and 11 loader calls. Decomposed, because the audit
correctly suspected the total:

* **673 distinct store PCs**, 362 distinct 64-byte windows — so it is not one repeated initializer;
* by image: `ovl_007af7a` 143, `ovl_007c552` 142, `ovl_007e132` 80, then a long tail;
* by opcode: `sb` 295, `sh` 277, `sw` 147, `sd` 1 — structure initialisation, not data movement;
* by provenance: **from memory 341, zero 218, constructed 161** — the 161 constructed ones are the
  table fills M84 found, and the 341 "from memory" ones are copies whose source the scan cannot name.

The **11 loader calls**, in full, because "one of them is the loader" should be checkable:

| image | pc | target | a0 | a1 | a2 | dest in bank |
|---|---|---|---|---|---|---|
| boot | `0x80000610` | `pi_dma_raw` | – | – | – | |
| boot | `0x80000638` | `inflate_init` | `0x803fff88` | – | – | |
| boot | `0x8000064c` | `inflate` | `0x803fff88` | – | – | |
| boot | `0x80004e8c` | `inflate` | – | – | – | |
| boot | `0x80007804` | `pi_dma_programmer` | – | `0x1` | `0xa4600010` | |
| boot | `0x8000799c` | `pi_dma_programmer` | – | `0x100401` | `0x5000400` | |
| boot | `0x80007a54` | `pi_dma_programmer` | – | – | – | |
| stage2 | `0x80032824` | `inflate_init` | **`0x8016e880`** | – | – | **yes** |
| stage2 | `0x80032838` | `inflate` | – | – | – | |
| stage2 | `0x8004cc1c` | `inflate_init` | `0x80139b30` | – | `0x1` | |
| stage2 | `0x8004cc30` | `inflate` | – | – | – | |

Exactly one has a bank destination, and it is the one already traced. Both `jal 0x800327ec` sites
(`0x80032a04`, `0x80032a84`) are inside `FUN_8003287c`, so the inflater has a single caller and it
is the slot loader.

**Chain, counted correctly (four hops, the open one second):**

```
1  FUN_8003287c(slot) -> destination lookup           complete
2  -> slot->ID map at 0x800eb264 -> 0x800eb204        LOCATED, meaning unproven   <-- open
3  -> cart_record(index)  jal 0x80001180              complete
4  -> FUN_800327ec(record, dest) -> inflate/copy      complete
```

## 5. `run-rom.sh` — decided and tracked

Retitled and committed as an **optional external validator**: `diff_rdram.py` already documents
`--ares` and tells the reader to export RDRAM from the Memory panel, so deleting the launcher would
have made a documented workflow undocumentable. Tracking it records the decision instead of leaving
it to be rediscovered, which is what four sessions of "untracked, untouched" had become.

## 6. Next, in order

1. **Fix `LB`/`LH` sign extension and `SWL`/`SWR`**, with the four-row table above as the regression
   test. This needs approval because it edits the verified path.
2. **Then** ask the harness what `0x800eb204` is indexed by, with a known-good execution model.
3. Only then return to whether any record points into R4.
