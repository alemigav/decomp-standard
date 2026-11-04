# M252 — the linked switch head: the dispatch sequence is exact, and the one differing instruction is the arms'

Route 2 from M251: take a real dispatch head, compile a `switch`, **place the jump table at the image's own table
address**, and compare. The head is `0x8004fd1c` — bound 5, index an incoming argument, no transform.

## 1. What the head is

```
0x8004fd1c  sltiu v0,a2,5        ; the bound, on the third argument
0x8004fd20  beq   v0,zero,+94    ; to the default arm
0x8004fd24  addu  a3,a0,zero     ; delay slot: the arm prologue
0x8004fd28  lui   v0,0x800c      ; the table ...
0x8004fd2c  addiu v0,v0,-29744   ; ... at 0x800b8bd0
0x8004fd30  sll   v1,a2,2
0x8004fd34  addu  v1,v1,v0
0x8004fd38  lw    v0,0(v1)
0x8004fd3c  jr    v0
0x8004fd40  nop
```

and the table holds five arm addresses (`0x8004fd44`, `…d54`, `…da0`, `…df4`, `…e50`).

## 2. The comparison, and what it can and cannot cover

The C is a five-case switch on the third argument. It is compiled with gcc 2.8.1, assembled with binutils 2.7,
rewritten by `objcopy` (2.7's `.symtab`), and linked with `.text` at `0x8004fd1c` **and `.rodata` at
`0x800b8bd0`** — placing the table at the image's table address is what makes the `lui`/`addiu` pair comparable.

Two of the head's ten instructions **cannot** be compared, and the tool says which:

| word | image | ours | why |
|---|---|---|---|
| 1 — `beq` offset | `1040005e` | `10400011` | it is the distance to the default arm, i.e. the arms' total size |
| 2 — delay slot | **`00803821`** `addu a3,a0,zero` | **`3c02800c`** `lui v0,0x800c` | the image schedules the **arm prologue** into the slot; ours had nothing to fill it with, so the `lui` took the slot |

Everything else is byte-identical, and as a *sequence*:

```
image:  2cc20005 1040005e 00803821 | 3c02800c 24428bd0 00061880 00621821 8c620000 00400008 00000000
ours:   2cc20005 10400011 3c02800c | 24428bd0 00061880 00621821 8c620000 00400008 00000000
        ^bound check^  ^slot^       ^ --------- seven-word table dispatch, identical --------- ^
```

So the compiler reproduces, exactly: the `sltiu` bound and the register it tests, the `lui`/`addiu` split of the
table address, the `sll` scale, the `addu` index, the `lw`, the `jr` and its `nop`. The one instruction that
differs is the one whose content is the *arms'* business.

## 3. Why this is a result and not a near-miss

The delay slot is not noise: it is evidence about the arms. `addu a3,a0,zero` means the arm bodies read the first
argument out of `a3`, so the original compiler had a use for it and the register allocator kept it there. My
five-case switch returns `a`, `b`, `a+b`, `a-b`, `a^b` — small bodies that keep `a0` in place, so there is no
move to schedule. Recovering *those* arms is source reconstruction; the head itself is now measured and matched.

## 4. Where the corpus stands

| probe | class | result |
|---|---|---|
| p1…p4 | empty, argument move, linked global store, delayed loop | **byte-exact** under gcc 2.8.1 |
| **p6 (this)** | **linked switch head**, table at its real address | **bound check + 7-word dispatch exact**; delay slot is the arms' |
| struct copy, integer divide, floating point | — | refused with a reason (M251) |

`tools/compile_probe.py` grew `switch_head()` and one case: the remaining refusals dropped from four to three,
because the switch class is now probed rather than refused. The link script, the `objcopy` step and the
fixed-word comparison are all in the tool, so the next head costs a table entry.
