# M223 — the RSP ucode: decoded, and deliberately not named

Step 1 of the RSP cycle. The mixer's program is now disassembled, its entry and call graph are recovered, its host
task is mapped with ten defended fields — and **its identity is `unresolved` on purpose**.

## 1. Two measurements that changed the premise

**The "4 KiB RSP program" is not 4 KiB of program.** The audio task declares `0x1000` bytes at `0x800b2700`, but the
RSP code's last exit is `+0xf34 jr t0`, and at `+0xf40` the words are `00803821 3c028016` — **identical to
`FUN_800b3640`'s first two words**. So `[0xf40, 0x1000)` is the head of a *CPU* function, and the declared size is
IMEM's capacity, **overrunning the ucode by 0xC0 bytes**. Verified against the image, not inferred.

**The pointer is built, not stored.** No word in stage-2 contains `0x800b2700`; the task field `+0x10` is assembled
by `lui rt,0x800b` at `0x800a2e8c` and `addiu rt,rt,0x2700` at `0x800a2e90` — I confirmed both instructions and the
sum. A literal-word search would have reported "nothing points at the ucode".

## 2. The program

1 024 words: **976 RSP words** (722 scalar, 254 COP2 vector) plus the 48 CPU words above. **722 scalar words, 34
distinct mnemonics, 0 unreadable.** Entry `0x000`; **20 functions** (`0x000` plus 19 `jal` targets); 10 gaps
(216 words) listed and not assigned; 4 register-indirect exits (`jr r30` ×3, `jr r8`) listed as unresolved targets.

Entry `0x000–0x024` is a **status poll** — `mfc0`, `andi 1`, `andi 0x100`, spin — and at IMEM `0x02c/0x030` the code
reads DMEM `0x30/0x34`, i.e. the task block's work-list pointer and count. That is the task-header-in-DMEM
mechanism, seen in the instructions rather than assumed from a diagram.

**The address rule, measured:** `jal`/`j` target = `(instr_index << 2) & 0xFFF` — all 49 jump fields' raw targets
sit in one page and every one is outside a 4 KB IMEM unmasked. Branches are PC-relative.

## 3. What is *not* claimed

**`funct=0x2c` stays unnamed**, as do all 254 vector words: they are recorded as 31 field patterns with counts and
first addresses. The reason is a measured negative worth publishing — **the local NU6 Programming Manual has no
RSP/COP2/SP-register encoding tables**, checked against all 534 pages of its text layer. Naming them would mean
importing an encoding table from another source, which is exactly what this project refuses to do. Scalar
mnemonics are cited only as *family* (p44/p47), never as encodings.

**Identity: `unresolved`.** Three candidates with their evidence: Nintendo's libaudio `aspMain` ABI (**partly
refuted**: the pair the manual gives the boot-ucode role, at task `+0x08/+0x0c` = `0x80028a80/0xd0`, is not a
self-contained code object — it branches on a register nothing writes and its extent straddles an epilogue);
Factor 5/MusyX (no measurement here bears on it either way); cartridge-private ucode (the residual, not a name).
`deciding_measurement: null`, with three `what_would_decide` items.

## 4. The host side

Ten task fields defended, each re-folded from the writer instruction: `+0x00`=2, `+0x04`=0, `+0x08`=`0x80028a80`,
`+0x0c`=`0xd0`, `+0x10`=`0x800b2700`, `+0x14`=`0x1000`, `+0x18`=`0x80136b50`, `+0x1c`=`0x800`, `+0x30`/`+0x34` from
the sequencer's globals. The block is submitted at `0x800a2ee4` by `jalr v0` through the function pointer at
`*0x80143ff0` — **not** a named OS call — and `FUN_800b1fc0` installs that pointer.

Five `rsp_only` entries: the DMEM layout, the 254 vector words, the `0x800` bytes at `0x80136b50` that no CPU
instruction names (and which run `0x5c0` past the image end), the command format, and the standing one — this is
**not an understood mixer**.

## 5. The libdragon reference, used as intended

`src/audio/rsp_mixer.S` was read only to confirm **which instruction families real audio ucode uses** — scalar
load/store, `LWC2`/`SWC2` rows, COP2 ALU, COP0 DMA/clock. It named nothing here, and its `mixer.c` command
interface was not used as evidence about RE2. That is the distinction the plan set: conventions compared there,
facts measured here.

## 6. Gates

`rsp ucode (cartridge)`: **18 cases**, 0.24 s. Mutations aimed at the two constants the artefact turns on — the
IMEM mask (`0xFFF` → `0x7FF`, which breaks the entry/jal-target case) and the blob address (which breaks the
derivation comparison). 57 suites / 787 cases; admission 109/109, 0 vacuous.
