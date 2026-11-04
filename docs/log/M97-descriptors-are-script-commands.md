# M97 — descriptors are script commands; no code writes their bytes 0 and 3

The question was "where do descriptors get built, and who writes bytes 0 and 3". The answer is that
**they are not built**: the object at `ctx+0x1c` is a **pointer into a command stream**, and bytes 0 and
3 are stream data that every reader interprets. What follows is the evidence, then what this changes.

## 1. `ctx+0x140` is a frame pointer inside the context, not a descriptor stack

The dispatcher's "pop" is:

```
0x8006daa0  lw   v1,320(s0)      ; v1 = *(ctx+0x140)
0x8006daa4  addiu v0,v1,-4
0x8006daa8  sw   v0,320(s0)      ; ctx+0x140 -= 4
0x8006daac  lw   v0,-4(v1)       ; read the word just below
0x8006dab8  sw   v0,28(s0)       ; ctx+0x1c = that word  <- the "descriptor"
```

and the writers of `ctx+0x140` compute it **from the context itself**:

```
0x8006e404  sll   v0,a1,5
0x8006e408  addiu v0,v0,0xC0
0x8006e40c  addu  v0,a0,v0       ; ctx + (n<<5) + 0xC0
0x8006e410  sw    v0,320(a0)     ; ctx+0x140 = frame pointer, frames of 0x20
```

So `ctx+0x140` walks a **frame area inside the context block**, 0x20 bytes per frame starting at
`ctx+0xC0`. Five sites write it: `0x8006d604`, `0x8006db80`, `0x8006e3c0`, `0x8006e410`, `0x8006e480`.

## 2. `ctx+0x1c` is the current command pointer, and it advances by 2

```
0x8006e14c  lw    a1,0x1c(s1)    ; a1 = current command pointer
0x8006e150  addiu a1,a1,2        ; advance
0x8006e154  sw    a1,0x1c(s1)    ; store back
0x8006e158  lbu   a2,-1(a1)      ; read a byte relative to it
```

and it is set straight from a stream argument in `FUN_8006e1bc`:

```
0x8006e3bc  addu  a1,a1,t0       ; a1 = stream + offset
0x8006e3d0  sw    a1,28(a0)      ; ctx+0x1c = that pointer
```

**So the "descriptor" is a command in a byte stream**: byte 0 is the opcode (dispatcher: `lbu v0,0(desc)`
→ table index), byte 3 is an operand (handler: `lbu a0,3(desc)` → the slot).

## 3. Consequences — the answer to the question

* **No code writes descriptor bytes 0 or 3.** Every site that touches a descriptor *reads* it at a fixed
  offset; the bytes come from the stream. There is no constructor to find, and the earlier plan of
  "find who writes byte 0 and byte 3" was malformed: it assumed a record being filled in.
* **The slot values are therefore stream content**, which is why none could be enumerated: they are
  whichever operand the script carries on a command whose opcode is `0x44`.
* **`FUN_8006dfe4`** — the function that advances the command pointer and sets `ctx+0x1c` — has **no
  `jal` caller** and appears in the same 141-entry table (at `0x801138d4`). It is itself an opcode
  handler, which is consistent: the interpreter is self-hosting, with handlers that mutate the
  command pointer.
* **The interpreter's shape is now complete**: a 141-entry opcode→handler table at `0x80113898`, ten
  contexts of `0x174` bytes at `0x80113ad0`, a `0x20`-byte frame area at `ctx+0xC0`, and a command
  pointer at `ctx+0x1c` advanced per command.

## 4. One inconsistency to record, not smooth over

One path advances the command pointer by **2** (`0x8006e150`), yet the dispatcher and the handler read
bytes **0 and 3 of the same pointer**. A 2-byte command cannot have a meaningful byte 3. So either
* that advance belongs to a different command family (2-byte commands whose handlers read only bytes
  0–1), and the 4-byte family that reaches `FUN_80071e14` advances differently; or
* the pointer stored at `ctx+0x1c` is not the command base but a sub-pointer, and offsets 0 and 3 index
  across command boundaries.

Distinguishing these needs the stream itself, which is the next artefact to find — and it is **data**,
not code: a room script, presumably in a loaded overlay or a `zlib` member.

## 5. Where this leaves bank C

Everything downstream of the slot stayed as M92/M93 left it: if a command carries opcode `0x44` and its
byte 3 is 16, bank C's first record is selected and the inflate fails silently; if byte 3 is 17–31,
`cart_record(0)` is inflated from four times past the cartridge end; if 32–63, bank B loads. **Which of
those happens is now a question about script data, not about code**, and that is a materially different
kind of question — it needs the room's command stream, not more disassembly.

## 6. Next

1. **Locate a command stream**: follow `ctx+0x1c` upward from an initialiser, or scan a loaded overlay
   for command-shaped records whose byte 0 indexes the handler table (`0x44` in particular).
2. Then the slot values are enumerable — by reading the stream, not by reading code.
