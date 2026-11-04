# M99 — the stride is settled: a variable-length bytecode, and opcode 0x44 is 22 bytes

## 1. The stride

The dispatcher never advances the command pointer — it reads byte 0 and jumps. **Each handler advances by
its own command size.** Scanning stage-2 for the idiom `lw v,0x1c(ctx)` → `addiu v,v,N` →
`sw v,0x1c(ctx)` gives **18 distinct lengths**:

```
+1 ×20   +2 ×21   +3 ×11   +4 ×18   +5 ×2   +6 ×10   +8 ×5   +10 ×1
+14 ×2   +16 ×2   +20 ×1   +22 ×1   +28 ×1  +32 ×1   +38 ×1  +40 ×1
(plus two negative advances, −38 and −256, i.e. backward jumps)
```

So the command stream is a **variable-length bytecode**, one length per opcode. And the handler this
investigation cares about, `FUN_80071e14` — the one selected by opcode **`0x44`** at table entry 68 —
ends:

```
0x80072298  lw    v1,0x1c(s5)     ; the command pointer
0x8007229c  addiu v1,v1,22        ; +22
0x800722a0  sw    v1,0x1c(s5)     ; advance
```

**Commands with opcode `0x44` are 22 bytes long.** Byte 3 is therefore a legitimate operand field well
inside the command, not a cross-boundary read.

## 2. That resolves M97's "inconsistency" — it was never one

M97 recorded: "one path advances by 2, yet readers use offsets 0 and 3 on the same pointer — a 2-byte
command cannot have a meaningful byte 3." With per-opcode lengths the two facts belong to different
command classes: `FUN_8006e138` is a **2-byte** command family (`lbu a2,-1(a1)` reads its byte 1), while
opcode `0x44`'s family is **22-byte**. No contradiction, and no sub-pointer hypothesis needed.

## 3. Retraction: `FUN_80170104` and `FUN_801708a4` are not the command writer

M98 §3 said the overlay's own code fills the buffer, naming `FUN_80170104` and `FUN_801708a4`. **Wrong**,
and the reading is unambiguous:

* `FUN_80170104` does float arithmetic (`46245001`, `46201000`, …), a division by 10 via the
  `0xCCCCCCCD` magic, and a **nibble pack** at `s2+0x1962` (`lbu` → `andi 0x0f` → `or a0<<4` → `sb`);
* `FUN_801708a4` is the same family — float math, `÷10`, per-object bitfields.

Both are gameplay code. and `FUN_80170104` is in fact **called after** the copy loop (`jal 0x80170104`
at `0x8016eb44`), not during the fill.

**What actually fills the buffer** is a 16-byte block copy in `FUN_8016e8d0`:

```
0x8016eae4  lw t0,0(a0) ; lw t1,4(a0) ; lw t2,8(a0) ; lw t3,12(a0)
0x8016eaf4  sw t0,0(a1) ; sw t1,4(a1) ; sw t2,8(a1) ; sw t3,12(a1)
0x8016eb04  addiu a0,a0,16
0x8016eb08  bne  a0,?,loop
0x8016eb0c  addiu a1,a1,16
```

The 23 constructed-base writers into `0x80171df8..0x80172400` decompose as: this copy loop (8 stores),
a 4-store init (`0x80171e90..0x80171e98`), and a **20-byte trailer at the overlay's end**
(`0x8017236c..0x80172380`) written byte-wise. No command stream is written directly.

This is the third time this session that a `find_readers` **near-miss list** was treated as evidence
without reading the site (`0x80113a34`, then `0x80171e80`). The lesson is now twice learned and still
worth repeating: a near-miss is a *candidate*, and only the disassembly makes it a fact.

## 4. What this settles, and what it leaves

**Settled:** the stride — per opcode, `0x44` = 22 bytes; byte 3 is an interior operand; the "2-byte
contradiction" is resolved; and the buffer is filled by a block copy from a runtime pointer
(`a0`, whose value comes from `*(0x800df934)` — zero in the image, so runtime).

**Left:** the command *contents*. They live in a block that is copied at runtime from a pointer the
cartridge does not carry. Reading them needs a dump of `*(0x800df934)` after a room load, or a
watch on `a0` at `0x80071ebc`.

**Why this is the end of the static line, stated once more now that it is measured:** every step from
`FUN_8003287c` up to its data has been read — handler table, dispatcher, context array, command
pointer, per-opcode advance, and the block copy. The one thing that is not in the cartridge is the
block itself, and it is absent by construction (a zeroed BSS region plus a runtime source pointer), not
by our inability to find it.
