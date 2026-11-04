# M253 — three more dispatch heads: bounds 5/6/7/7, four index sources, and two layout facts

M252 built the machinery for one head. This adds three more, chosen for **variety rather than convenience**:

| probe | bound | index source | table | table address |
|---|---|---|---|---|
| p6 | 5 | an incoming argument | `0x800b8bd0` | **at the image's address** |
| p7 | 7 | the byte at `ctx+6` | `0x800b8f78` | +8 (object `.rodata` pad) |
| p8 | 6 | a global byte | `0x800b69b0` | **at the image's address** |
| p9 | 7 | a command byte, `andi 0xff` | `0x800b96a8` | +8 (object `.rodata` pad) |

Each is compiled as a switch with that head's case count, assembled with binutils 2.7, `objcopy`-rewritten, and
linked with `.rodata` at that head's own table address.

## 1. What the four have in common, and what that means

All four dispatch blocks are the same shape — `sltiu <idx>,B`; `beq`; the table's `lui`/`addiu`; `sll idx,2`;
`addu`; `lw`; `jr`; `nop` — and the compiler reproduces the **bound** and the **shift** for every one of them.
That is the claim: the bounds are 5, 6, 7 and 7, and the index registers differ (`v1` twice, `a0` once, and one
reachable only after an `andi`), yet the construction gcc emits is the same and the numbers it puts in it are the
image's.

## 2. The delay slot absorbs an instruction, and which one depends on the head

| head | what the image puts in the slot |
|---|---|
| p6 | `addu a3,a0,zero` — the **arm prologue**, moving the first argument |
| p7 | `lui v0,0x800c` — the **table's first half** |
| p8 | `sw s0,0(sp)` — a **frame store** |
| p9 | `sll v1,v1,2` — the **index scale** |

Four heads, four different slot contents, and ours is always the `lui`. The slot is filled from whatever the
enclosing function has to put there, so comparing it compares the *arms*, not the compiler. The signature
therefore compares the bound, the shift and the table address, and says plainly that the op sequence is not
compared. The table above is why that is a finding rather than an excuse: it shows the slot is genuinely
function-specific.

## 3. Two layout facts that are not codegen

- **The image's tables are 8-byte aligned; a link lands them 8 bytes late.** `0x800b8f78` and `0x800b96a8` are
  8-aligned but not 16, and gcc's `.align 3` before the table is satisfied by *any* 16-aligned section start —
  so a script placing `.rodata` at an 8-aligned address gets the linker to round the section up to 16 and the
  table lands at +8. `ALIGN(8)` on the section fixes it for one head and not another, because what precedes the
  table inside `.rodata` differs; the artefact reports the pad rather than hiding it, and p6 and p8 land exactly.
- **The two PAD cases are layout, not codegen**: subtracting the pad gives the image's address in both.

## 4. What this does and does not establish

Established: for four heads with different bounds, different index sources and different table addresses, gcc
2.8.1 emits the same dispatch construction as the cartridge, with the same bound and the same `sll 2`, and with
the table address resolving to the image's own address wherever the object's layout allows it to be compared.

Not established: that any of these heads' *arms* are reproduced (they are not translated), that the index
*expressions* are compared (they are documented from `head_index.json`, not byte-compared — the load happens
before the `sltiu` and its position depends on the prologue), and that `-O` vs `-O2` differs here (both give the
same result on every probe so far).

The corpus is now **12 cases**: four byte-exact function probes, four structural head probes, the 6 560 : 0 move
census, the IDO refutation, and the three remaining refusals.
