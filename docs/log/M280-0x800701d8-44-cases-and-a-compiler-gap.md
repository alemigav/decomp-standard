# M280 — `0x800701d8`: 44 cases written, 28 of 141, and a residual that is the compiler, not the C

The next target was the function the exact `0x80070120` calls — `FUN_800701d8(ctx->f154, cmd >> 8)`, **141 words**,
a **44-arm accessor dispatcher**. The 44 cases are written and measured, the head and the table's first two entries are
byte-exact, and the remaining 44 words turned out **not to be a reconstruction problem**: our `cc1` + `as` pair cannot
emit the arm shape this function has.

## 1. What came out exact

- The **9-word head** (`0x800701d8..0x800701f8`) is byte-identical in every build tried:
  `sltiu v0,a1,44` / `beqz v0,0x80070200` with `sll v1,a1,2` in the delay slot / `lui` + `addiu` to `0x800b96c8` /
  `addu` / `lw v0,0(v1)` / `jr v0` / `nop`.
- **The case 0/1 swap was predicted correctly.** In table order the source scores 27 of 141; with case 1 written
  before case 0 it scores **28**, and its `table[0] = 0x80070208`, `table[1] = 0x800701fc` are the image's own two
  entries. The reason is M278's fixture fact: cc1 emits case bodies in **source order**, so the image's source wrote
  case 1 first — the code order in the listing *is* the source order, and the table is what disagrees with it.
- The **field map is complete**: 44 distinct accesses with `lbu`, `lhu`, `lh` and `lw`, so the field *types* are pinned
  by the load opcode (M272's rule, now with signedness as the discriminator: `lh` arms are `s16` fields with no cast in
  the source). One overlap has to be a union: offset `0x1e0` is read as `u8` by case 27 and `s16` by case 28. The
  offsets are the same `Ctx` family as `0x8007e590` — `0x1a2`, `0x1b4`, `0x1b6`, `0x1e0`, `0x25e`, `0x26f` all recur —
  which independently corroborates p9's call site.

## 2. The residual, measured three ways

Every arm in the image is **3 words**: `load; jr ra; nop`, 44 × 3 = 132, plus the 9-word head = 141, exactly the
extent. Our build emits **2 words** per arm and the object is **100 words**.

1. **It is the assembler.** cc1 emits a bare `j $31` per arm; gas then moves the load into the delay slot. A four-line
   `.s` demonstrates it in isolation: `lhu $2,0($4)` / `j $31` / `lbu $2,4($4)` / `j $31` assembles to
   `jr ra; lhu; jr ra; lbu`. The same happens with **as 2.7 (the pinned `as.new`) and with binutils 2.42**, under
   `-mcpu=r4300`, `-mcpu=vr4300` and bare `-mips2`, and an explicit trailing `nop` does not stop it. Compaction is not
   even a miscompile: the slot executes before the jump, so a jump-table entry pointing at the load still works.
2. **Only `.set noreorder` stops it, and that reproduces the size.** Re-assembling the same cc1 output with
   `.set noreorder` forced around each `j $31` grows `.text` from **100 to 144 words** — one word per return, which is
   the size of the gap. So the image's arms were inside `.set noreorder`: its cc1 **scheduled each return's delay slot
   itself**. In gcc that is the `dslot` attribute, which is "yes" exactly when the final scheduler produced a
   `final_sequence` — and that is what wraps the jump.
3. **No source shape makes our cc1 do it.** Twelve variants all leave a bare `j $31`: return type `u32` and `int`;
   index `u32`, `int`, `u16`, `s16`; a `volatile` struct pointer; `(u16 *)((u8 *)p + off)` casts; a 3-case and a
   10-case switch (so neither the table nor the size is the trigger); `-fno-delayed-branch`; `-O1`; explicit
   `-fdelayed-branch`; and **gcc 2.7.2 as well as 2.8.1**. Reorg is running — the head's `beqz` is wrapped with `sll`
   in its slot — it simply does not fill these returns.

## 3. Why this is a finding rather than a failure

It is the first target where the blocker sits **upstream of the C**. The pipeline's identification (gcc 2.8.1 + as 2.7,
`-O2 -G 0 -mips2 -mcpu=r4300`) was established on functions whose returns are all compacted by gas, so it had never
been asked to produce a `noreorder` return — and the image has **365** `jr ra; nop` sequences and **1 381**
branch-likely instructions, both of which are delay-slot-filling artefacts. So the question is well posed and narrow:
*what makes this build's cc1 schedule a `return`'s delay slot?* It is not a question about the source, and no amount of
statement-ordering will answer it.

The three next experiments, in order of cost, are recorded in the handover: (a) re-run the already-exact sources with
`-fno-delayed-branch` and `-O1` to see whether the flag set is uniquely pinned at all; (b) find one function in the
image whose arm returns **are** compacted and one whose are not, and diff their surroundings, so the discriminator
becomes a local fact; (c) only then consider a second compiler build, since gcc 2.95.x emits `noreorder`-wrapped
returns by default.

## 4. The honest numbers

`0x800701d8` is **28 of 141 words**, its head is exact, its table's first two entries are exact, and its 44-row arm
table is on disk in `build/p701d8/ARMS.md` read straight from the image. It is **not** in the probe — a partial pinned
at 28 of 141 would assert a build fact that is really a toolchain gap, which is exactly the kind of claim M279's pin
was careful not to make. The corpus is unchanged at **32 cases, all passing**, the suite at **1001 cases**, and the
progress map does not list this function. `0x8007e590` remains the newest entry at 226 of 229.
