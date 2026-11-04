# M96 — `FUN_8003287c`'s callers and their slot values, enumerated

M94 established this and M95 did not restate it; both are corrected here, and re-deriving it produced
one structural fact that makes the answer better than "runtime value".

## 1. Callers — four independent forms checked

| how a call could exist | result |
|---|---|
| direct `jal` | **1** — stage-2 `0x80071ec0`, inside `FUN_80071e14` |
| address built by `lui`+imm then `jalr` | **none** in 36 images |
| `0x8003287c` present as a 32-bit word | **none** |
| branch/jump into the body `0x8003287c..0x80032910` from outside | **none** (only its own internal `beq`/`regimm`) |

So: **one caller, entering at the function start, and it passes no literal.**

## 2. The slot values it passes

```
0x80071eb8  lw   v0, 0x5284(s5)      ; v0 = *(0x80113ad0 + 0x1c)   — the current descriptor
0x80071ebc  lbu  a0, 3(v0)           ; slot = descriptor byte 3
0x80071ec0  jal  FUN_8003287c
```

**No slot value can be listed statically**, and the reason is now precise rather than a shrug: the
byte is `descriptor[3]`, and the descriptor is supplied at runtime. Here is the mechanism, from the
dispatcher's own loop:

```
0x8006da34  addiu s0,v0,15056        ; s0 = 0x80113ad0 — context 0
0x8006da48  lw    v0,28(s0)          ; v0 = ctx->descriptor (at ctx+0x1c)
0x8006da5c  lbu   v0,0(v0)           ; descriptor byte 0  -> handler index
0x8006da68  lw    v0,0(s2 + v0*4)    ; table[byte0]
0x8006da6c  jalr  ra,v0              ; call it (a0 = ctx)
   …
0x8006dad4  addiu s0,s0,372          ; next context, stride 0x174
0x8006dacc  sltiu v0,s1,10           ; at most 10 contexts
```

and the context array is `0x80113ad0 + i*0x174`, `i < 10`, ending at `0x80114958` — which the *other*
table reader computes independently as `0x80113ad0 + 3720` (`0x8009b8b4`). Two independent sites agree
on the geometry.

## 3. The finding that comes out of re-deriving it

**The table index and the slot are two fields of the same descriptor.**

| consumer | field | meaning |
|---|---|---|
| dispatcher (`0x8006da5c`) | **byte 0** | handler index into the 141-entry table at `0x80113898`; `0x44` = 68 selects `FUN_80071e14` |
| handler `FUN_80071e14` (`0x80071ebc`) | **byte 3** | the slot passed to `FUN_8003287c` |

So the two runtime unknowns of M94/M95 are **one unknown**: for any descriptor whose byte 0 is `0x44`,
the slot is that same descriptor's byte 3. Nothing can be enumerated without the descriptor, but the
question is now "what is descriptor byte 3 when byte 0 is 0x44", which is a single field relation
rather than two independent byte hunts.

A corollary worth stating: because the slot only exists for descriptors that select *this* handler,
**the slot's domain is the set of byte-3 values among descriptors with byte 0 = 0x44** — so the
0–15 / 17–31 / 64–255 pathologies of M93 §2 are reachable only if such a descriptor carries them.

## 4. What is still not determinable, and where it would come from

The descriptor pointer itself: `ctx+0x1c` is written at `0x8006dab8` from a pointer popped off a list at
`ctx+0x140` (`lw v1,320(s0)` / `lw v0,-4(v1)` / `sw v0,28(s0)`), and that list is built at runtime. So
the descriptor stream is a runtime artefact — consistent with everything else in this path, and the
reason the two ares dumps (which predate the contexts being populated) cannot answer it.

## 5. Status of the whole chain

| link | state |
|---|---|
| context array `0x80113ad0 + i*0x174`, 10 slots | **static, two independent sites agree** |
| pointer table `0x80113898`, 141 entries, zero-terminated | **static** |
| index = descriptor byte 0 | **static** |
| `0x44` → `FUN_80071e14` → `FUN_8003287c` | **static** |
| slot = descriptor byte 3 | **static expression, runtime value** |
| descriptor source (list at `ctx+0x140`) | **runtime** |

So the statically determinable part of this path is complete, and exactly one runtime byte remains:
descriptor byte 3, obtained from a descriptor whose byte 0 is `0x44`.
