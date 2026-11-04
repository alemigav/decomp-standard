# M95 — the table at `0x80113898`: three readers, and entry 68 is selected by a byte

## 1. What the table is

`0x80113898`–`0x80113ac8` is **141 consecutive in-image function pointers**, terminated by a zero word
at `0x80113acc`. Every word is in the stage-2 code range, 55 of them point at a prologue, and the run
ends cleanly at a zero — not a heuristic boundary this time:

```
0x80113894  0x00000000        (word before the array)
0x80113898  0x8006db14        entry 0
   …
0x801139a8  0x80071e14        entry 68   <- the caller of FUN_8003287c
   …
0x80113ac8  0x80073658        entry 140
0x80113acc  0x00000000        terminator
```

`0x801139a8 = 0x80113898 + 68*4`, so **entry 68 is offset `0x110` from the table base**.

## 2. Three readers — every site that constructs the base

| site | base register | index comes from | then |
|---|---|---|---|
| `0x8006da28` in `FUN_8006da14` | `s2` | `lbu v0,0(*(0x80113ad0 + 0x1c))` — a byte in a per-object structure | `sll 2; addu s2; lw; jalr ra` |
| `0x8006e1e8` in `FUN_8006e1c0`… | `s0` | `lbu v0,0(a1)` — a byte from the **caller's pointer** | `sll 2; addu s0; lw; jalr ra` |
| `0x8009b89c` | `s3` | a byte from an object in the loop at `0x80113ad0` (stride `0xE88`), read after the base is set | loop over objects |

The first is the one that matters here, in full:

```
0x8006da1c  addu  s1,zero,zero
0x8006da20  lui   v0,0x8011
0x8006da28  addiu s2,v0,14488        ; s2 = 0x80113898   <- the table base
0x8006da2c  lui   v0,0x8011
0x8006da34  addiu s0,v0,15056        ; s0 = 0x80113ad0   <- the object base
0x8006da48  lw    v0,28(s0)          ; v0 = *(object + 0x1c)
0x8006da5c  lbu   v0,0(v0)           ; v0 = *(* (object+0x1c))[0]   <- THE INDEX, one byte
0x8006da60  sll   v0,v0,2            ; * 4
0x8006da64  addu  v0,v0,s2           ; + 0x80113898
0x8006da68  lw    v0,0(v0)           ; the function pointer
0x8006da6c  jalr  ra,v0              ; call it, a0 = the object (delay slot)
```

**So entry 68 (`FUN_80071e14`) is selected when that byte is `0x44` = 68.** The index is a
one-byte field, not a literal and not a computed constant, in all three readers.

## 3. The chain, complete as far as statics reach

```
byte 68 at *(*(0x80113ad0+0x1c))    (runtime)
  → table[68] = 0x801139a8 = FUN_80071e14        (static)
  → slot = byte 3 of *(0x80115284)               (runtime, M90/M92)
  → FUN_8003287c(slot) → byte[slot-16] → cart_record → FUN_800327ec   (static)
  → inflate / stale destination                  (M92/M93)
```

Two of the five links are runtime byte reads with no static provenance: the dispatcher index and the
slot. Everything between them is now traced and measured.

## 4. A scanner bug this exposed, and it is the same class

`find_readers.py` reported **167 "base+register" near-misses** around the table. Nearly all were
noise, and the cause was a rule bug: the constant-tracking pass excluded memory instructions from its
update, so **a load never invalidated its destination register**. A stale constant therefore survived
across `lw`s — `t4` kept the value `0x80113a34` after being overwritten by loads, and every access
through it was reported as if it were an access through that constant.

Fixed (loads now invalidate, only branches/jumps are exempt), and the table's genuine reader appeared
immediately: `0x8006da68 lw base+reg where base=0x80113898`.

That is the same lesson as `addiu`/`ori` and base+register, a third time and one level deeper: **the
analysis rule — not just the arithmetic — defines what the scan can see.** A rule that under-invalidates
manufactures structure; a rule that under-matches hides it. Both are invisible until a known answer is
checked against them, which is why the three known table entries were used as the acceptance test.

## 5. What this does not establish

* **The index byte's provenance.** `*(object+0x1c)` points at a structure whose first byte is the
  index; the object at `0x80113ad0` is zero-filled in the image, so that pointer is built at runtime.
* **Whether byte 68 ever occurs.** That is the same runtime question as the slot byte, one level up,
  and the harness or a post-room dump answers it.
