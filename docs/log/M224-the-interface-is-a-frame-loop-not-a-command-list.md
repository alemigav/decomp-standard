# M224 — the interface is a frame loop, not a command list

Step 2 of the RSP cycle. Step 1 (M223) decoded the mixer's ucode and stopped at the question this one
answers: **what do the twenty-odd things the program calls actually do with the block the CPU publishes?**
The answer is that there is no command interface at all. What there is: a frame loop, one register
primitive copied four times, two 0x50-byte parameter records in DMEM, and 173 words of code that nothing
reaches.

Five claims, and three retractions of M223's own wording. The register numbers are now named from a
**cited external source**, which is the first time this project has used one for hardware and it needed a
policy decision, stated in §2.

## 1. Control flow, closed: 173 words are reached by nothing

M223 listed 10 "gaps" totalling 216 words and described them honestly but vaguely — "reached by no jal
target and by no modelled fall-through". That framing came from the greedy body rule ("entry to the first
`jr`, capped at the next root"), so the gaps were partly an artefact of where the caps fell. Replaced by a
real successor function:

* delay slots modelled as their own step — a `j`/`jal`/`jr` at `a` goes to `a+4` only, and the delay slot
  then carries the jump's target;
* `beq zero,zero,T` read as an **unconditional jump** (the assembler emits that pair when the branch is
  out of range) and `bne zero,zero,T` as never taken — 1 site, at `0x2c0`, the halt spin;
* `jr ra`/`jr fp` given return edges to every call's return address, plus the one synthesized link.

Reachability from IMEM 0 then partitions the program: **803 of 976 words reachable, 173 not, in 12 runs**.
Every run begins immediately after a control-flow exit, so no fall-through enters one — that is a
mechanical statement about the word before each run, not a judgement. **172 of the 173 words are code**:
between them they hold 14 branches, 3 `jal`, 5 `jr` and 36 vector words. The last word is a `nop` fill.

Two things follow, and only the first is comfortable.

**The one synthesized link is exactly 0x0d8.** `0x290 ori ra,zero,4312` writes `ra = 0x10d8` and the
next instruction is `j 0x3f0` — a tail call with a hand-set continuation. `0x10d8` is **past the end of
the program** (976 words = 0xF40) until the 12-bit PC is applied: `0x10d8 & 0xFFF = 0x0d8`, which is
inside the frame loop. That both confirms the 12-bit-PC rule from the cited source and states what the
DMA-completion path re-enters: **0x0d8**, not a return.

**Every link-save in the program is unreachable.** There are four `or fp,zero,ra` — at `0x2c8`, `0x3d8`,
`0x87c`, `0xcac` — and all four sit in unreachable runs. There are three reachable `jr fp` exits
(`0x714`, `0x8f4`, `0xde8`), and **no other instruction in the program writes r30 at all**. So on every
path this model can find, the body returns through a register nothing writes. The economical reading is
that this blob's call displacements do not line up with its code — patched or relinked after assembly —
and the corroborations are independent: `jal 0xca4` targets a bare `jr ra`, `jal 0x38c` lands on the third
write of an 11-word sequence, and the four bodies whose heads save the link are entered at points that
skip the save. **That is a hypothesis, not a measurement.** What is measured is the mismatch, and what
would decide it is an execution trace or a second copy of this ucode.

## 2. The register map is external now, and that is a policy change

M223 recorded the SP register map as unavailable and said that naming them "would mean importing an
encoding table from another source, which is exactly what this project refuses to do". Too absolute. The
distinction that survives contact is **the one M223 already applied to libdragon and M142 to
OpenBiohazard2**: a table may be *used as a cited external source* for what it documents, provided it is
attributed, no text is reproduced, and every consequence is re-measured here. This milestone applies that
to the register map, and records the source the way `THIRD_PARTY.md` requires.

The local manual genuinely cannot supply it, and that is now **cited** rather than asserted. Page 115:
*"With the current software architecture, the application does not program the SP directly, and need not
concern itself with IMEM and DMEM accesses."* And the manual's own index lists the header it defers device
bit patterns to — `rcp.h` — against **pages 110 and 111 only**: DP, VI, AI and PI status. So the SP register
map is not merely missing from this repository's documents; the document says the application was not
expected to touch it.

The map, citing the N64brew Wiki's RSP interface page (revision 5376, CC BY-SA-4.0), facts restated not
copied:

| COP0 | name | what the cited page says it does |
|---|---|---|
| c0 | `SP_DMA_SPADDR` | IMEM/DMEM address; bit 12 picks the bank (0 = DMEM, 1 = IMEM), low 3 bits always 0 |
| c1 | `SP_DMA_RAMADDR` | RDRAM address, 24 bits, low 3 bits always 0 |
| c2 | `SP_DMA_RDLEN` | length, **and the write starts** a RDRAM → IMEM/DMEM transfer |
| c3 | `SP_DMA_WRLEN` | length, **and the write starts** a DMEM/IMEM → RDRAM transfer |
| c4 | `SP_STATUS` | status; a write sets and clears individual flags |
| c5 | `SP_DMA_FULL` | 1 while a second transfer is queued |
| c6 | `SP_DMA_BUSY` | 1 while a transfer is in progress |
| c7 | `SP_SEMAPHORE` | mutex bit: a read returns the old value and then sets it to 1 |

Two consequences are checked, not assumed:

* **the length rule holds on every value the program states.** The register holds *bytes − 1* and a
  transfer size is a multiple of 8; the four lengths this program writes as immediates are 127, 383, 407
  and 767, i.e. **128, 384, 408 and 768 bytes** — all multiples of 8, 4/4. Nine further length sites are
  computed and are published as computed, not counted.
* **the program reads a register that is not in the map.** Its first instruction is
  `mfc0 a2,<c11>` — and c11 is outside c0–c7. So the register M223 called "the RSP status register, name
  from outside this repository's authority" is **not** the documented status register: that is c4, and this
  program never reads c4. The artefact names c11 as `c11 (not in the cited map)` and a gate case fails if
  anyone quietly gives it a name.

## 3. The interface: 13 writes, five code points, one primitive

Every COP0 write in 976 words is in `0x350–0x3c0` plus one at `0x2ac`. Four overlapping copies of one
11-word sequence, and the halt path:

| entry | writes | trigger | direction | sites |
|---|---|---|---|---|
| `0x348` | c0←a1, c1←a2, c3←a3 | c3 `WRLEN` | **DMEM → RDRAM** | 4 |
| `0x38c` | c2←a3 only | c2 `RDLEN` | **RDRAM → DMEM** | 2 |
| `0x39c` | c7←0, c0←a2, c1←a1, c2←a3 | c2 `RDLEN` | **RDRAM → DMEM** | 2 |
| `0x3b8` | c1←a1, c2←a3 | c2 `RDLEN` | **RDRAM → DMEM** | 5 |
| `0x3f0` | none | — | field setup only | 7 |

The semaphore is real and measured: **three acquires** (`mfc0 c7` then `bne ...,zero,<back>`, which spins
until the mutex reads free — and a read that returns 0 *acquires* it) and **three releases**
(`mtc0 zero,c7`). The full entries bracket their transfer with it; `0x3b8` does not, because it only
restates the RDRAM address and the length for a transfer whose SP address is still in c0 — a streaming
continuation. `0x38c` writes a length it never computes and then **halts if that value is nonzero**
(`bne a3,zero,0x390` is a self-loop); it is reached with an `a3` that comes from outside the run.

**The open question, stated with its numbers.** Two of the four entries take `(c0←a1, c1←a2)` and two take
`(c0←a2, c1←a1)`. The frame loop calls `0x348` at `0x0dc` with `a1 = v0+36 = 0x284` and `a2 = 0xa00 − n`,
and one instruction later calls `0x39c` at `0x0e4` with *the same two registers* — so the value the first
call makes a DMEM address the second call makes an RDRAM address. The detector is mechanical (it compares
the resolved register values, not the arguments) and finds the crossover twice, in both arms of the loop.
Which side is which cannot be settled from the code, because **every value either side takes is under
0x1000**: the program's RDRAM addresses span `0x000–0xd60` and its DMEM addresses `0x000–0xfff`, so the
two spaces are indistinguishable by value and only the register assignment distinguishes them. Recorded as
`argument_order.measurement`; not resolved.

The halt path is clean and fully cited: `0x2a8 ori a1,zero,0x4000` → `0x2ac mtc0 a1,c4` → two `nop` →
`break`. On a *write*, bit 14 of `SP_STATUS` is **SET_SIG2**, so the ucode **raises signal bit 2 and stops
the RSP**. The CPU side of that handshake would be the handler installed at `*0x80143ff0`; stage-2
contains zero references to `0xa4040010`, so this image does not contain the other half.

## 4. The work list is one 0xa10-byte record per frame

M219's and M220's shape, one layer down. The entry reads the task block's pointer and count once
(`0x02c lw a0,48(at)`, `0x030 lw v1,52(at)`), and the loop body is three instructions:

```
0x274  addiu v1,v1,-1        # count
0x278  beq   v1,zero,0x294   # last frame -> halt path
0x27c  addiu a0,a0,2576      # pointer += 0xa10   (delay slot: always runs)
```

and **0xa10 is exactly what the CPU-side recipe computes for one unit**. That recipe is folded here from
the instructions, not quoted: `sll a1,a2,2 / addu a1,a1,a2 / sll a1,a1,5 / addu a1,a1,a2 / sll a1,a1,4`
with one unit gives **2576**. So the CPU flushes `count × 0xa10` bytes and the RSP walks it one
0xa10-byte record at a time. That is a record walk, not a command list.

The DMEM map is folded from base registers whose every write in the program is a constant form — two
qualify (`v0` = `{0x260, 0x2b0}`, `at` = `0x230`), which yields **98 absolute accesses and leaves 16
opaque**. It found the parameter structure without being told to look for it: **two records at 0x260 and
0x2b0, 0x50 bytes each, 21 fields each**, addressed through the one pointer register that holds exactly
those two values — a double buffer — plus 102 vector-unit accesses at `0x230–0x24e`, `0x600–0x608` and the
ucode's own globals at **`0xd58`** (a modulo-16 frame counter: `addiu t0,a3,1` then `andi a3,0x0f`),
**`0xd59`** (a 2-slot index, `xori a1,a1,1`) and **`0xd5c`** (the current record pointer).

## 5. The question the milestone was asked: no dispatch

**There is no command dispatch, and no table to find one in.** All 49 `j`/`jal` fields carry an absolute
IMEM target; there is no computed transfer anywhere (`jr` appears 17 times, every one through a saved
link); and no load in the program reaches a jump. So any "command" would have to be a compare chain on a
value loaded from the published block — and the measurement is that **13 loads feed a conditional branch
and not one of them selects a target**: they are added into buffer arithmetic (`lhu a3,64(v0)`), shifted
and masked (`lbu a1,62(v0)` → `srl` and `andi 0x1f`), or zero-tested to skip a stage (`lbu a3,60(v0)`).
The block is a **parameter record**, and it is the same shape M220 measured on the sound side: there the
"macros" were a class tag in the key; here the "commands" are record fields.

## 6. What this does not claim

* **The 254 vector words are still unnamed.** The cited source's VU table is *available* and is the next
  step — it would name them — but naming 254 words and their element/broadcast modifiers is its own
  milestone, and doing it in a hurry beside the register work is how a table gets misapplied. It is queued
  as step 3, not folded in here.
* **`lwc2`/`swc2` addressing is corrected but only partly folded.** M223 read bits 15:0 as a 16-bit signed
  displacement, found `0x2000` unreadable as one, and excluded all 125 transfers from the DMEM
  statistics. The split is base / vt / **row opcode (15:11)** / element (10:7) / **offset (6:0, scaled by
  the access size)**; corrected, they are ordinary DMEM accesses and 8 of the 125 fold against a
  constant base (`0x230–0x240`). The other 117 are addressed through registers holding runtime pointers,
  and are published with the reason. This **supersedes** `rsp_ucode.json`'s `dmem.excluded_cop2_transfers`;
  that field stays in M223's artefact until the decoder itself is corrected in step 3, and the note says so
  rather than leaving two artefacts disagreeing in silence.
* **The 173 unreachable words are listed, not explained.** Dead, patched, or reached by a mechanism
  outside this model — the model is the generous one, and its edge rules are stated in the artefact so a
  reader can disagree with a rule rather than with a result.
* **No claim that the mixer mixes.** Nothing here was executed.

## 7. Gates

`rsp interface (cartridge)`: **28 cases**, 1.4 s. Three mutations, each aimed at an outcome: the 12-bit
mask on the synthesized link (the case that names `0x10d8 → 0x0d8` fails), the two-value pointer that
produces the parameter records (the DMEM-fold case fails), and the bytes-1 rule (the length case fails).
All three were run before the commit in a throw-away copy, and the anchor lint passes 3/3 with all three
anchors unique.

**A defect the milestone found rather than introduced**: `acceptance.py` pinned the audit suite at **107**
cases while the audit actually ran **109** — M223 added two mutations and did not move the number. Nothing
noticed, because CI runs `ci.sh --no-audit` and defers the audit to `verify.py`, which grades it by its own
`112/112` summary line rather than by that pin; only a *full local* `acceptance.py` reaches the assertion,
and it failed the moment this milestone ran one. The pin is now **112**, `counts.py` re-derives the totals
from it (**820 cases, not 815**), and the two quoted `107/107` sites are corrected. The general lesson is
the one M216 already recorded about tiers, one level down: **an assertion that only one entry point
exercises is an assertion nobody exercises.**

Two of my own defects, caught by the cases rather than by review: `_write_form` classified `lwc2`/`swc2`
as writing a **GPR** when they write a vector register, which disqualified every base register and made
**all 106** scalar accesses opaque — the fold reported `0 folded / 106 opaque` on the first run; and
`const_sets` excluded register 0, so every `...(zero)` store (all seven ucode globals) fell out of the map.
Both are the same class of error: a table about *where a value goes* that was written from the shape of the
instruction rather than from what the instruction writes.
