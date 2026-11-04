# M101 — the room dump arrived, and it corrects the model: the loader is gated

## 1. Your dumps, and where they were

Three exports from today, all in the repository's `rom/` (gitignored):

```
rom/…-rdram-20261031-130325.bin
rom/…-rdram-20261031-130332.bin
rom/…-rdram-20261031-130338.bin
```

ares writes them beside the ROM. All three are identical in the fields that matter, so they captured
one instant. `tools/room_probe.py` read them without modification:

```
*(0x80115284) = 0x8052a614     *(0x800df92c) = 0x80529d40
slot = byte 3 of 0x8052a614 = 31
```

**This is the first dump in the project where the scene-slot context is installed** — the two from
yesterday were zero. The runtime question finally has data.

## 2. What the descriptor actually is

```
0x8052a614:  44 00 05 1f 10 40 00 01  00 28 e3 44 00 00 f8 b3 …
             │  │  │  │
             │  │  │  └─ byte 3 = 0x1f = 31   ← the "slot"
             │  │  └──── byte 2 = 0x05
             │  └─────── byte 1 = 0x00
             └────────── byte 0 = 0x44 = 68 → table[68] = FUN_80071e14  ✔
```

Byte 0 is `0x44` and table[68] is `FUN_80071e14`: **the static trace is confirmed against live memory**,
exactly as M92/M95/M96 predicted. Slot = **31**.

## 3. The correction: byte 9 gates the loader, and that is why the game survives

M92/M93 said slot 31 → `cart_record(0)` → branch 2 → a 1.28 GB inflate from cart `0x0f564552`. The game
is running, so the model was missing a step. Here it is, straight from `FUN_80071e14`:

```
0x80071e94  lw   a1, 0x5284(s1)      ; a1 = *(0x80115284) = the descriptor
0x80071e98  lbu  v1, 9(a1)           ; v1 = descriptor byte 9     (ours = 0x28 = 40)
0x80071e9c  li   v0, 0xff
0x80071ea0  beq  v1, v0, 0x80071eb8  ; byte 9 == 0xff -> go straight to the loader
0x80071ea8  jal  0x800837ac          ; otherwise ask a bitmap test about byte 9
0x80071eb0  bne  v0, zero, 0x80072298 ; non-zero -> exit (advance +22), loader NOT called
0x80071eb8  lw   v0, 0x5284(s1)
0x80071ebc  lbu  a0, 3(v0)           ; the slot — only reached when the gate passes
0x80071ec0  jal  FUN_8003287c
```

**So the slot is not used unconditionally.** A command only reaches the loader when byte 9 is `0xff`,
or when the bitmap test returns 0. Our descriptor has byte 9 = 40, i.e. not `0xff`, so the gate decides
— and the game surviving is evidence the gate returned 0 or the loader was never reached for this
command. Every "slot 17–31 → catastrophe" statement in M92/M93 needs this qualifier: **it applies only
to a command whose byte-9 gate passes.**

The gate itself, `0x800837ac`, is a bitmap bit test:

```
0x800837ac  srl   v1,a1,5        ; word index
0x800837b0  sll   v1,v1,2
0x800837b4  addu  v1,v1,a0       ; + bitmap base
0x800837b8  andi  a1,a1,0x1f     ; bit index
0x800837bc  lui   v0,0x8000
0x800837c0  lw    v1,0(v1)
0x800837c4  sllv  v0,v0,a1       ; 0x80000000 << bit
0x800837c8  jr    ra
0x800837cc  and   v0,v0,v1       ; test that bit
```

**Open, and stated as open:** on a 32-bit view `0x80000000 << 8` is zero, so the test would return 0 for
any bit index ≥ 1 — which would make the gate almost vacuous. On a 64-bit R4300 view the shifted word
still has zeros in its low 32 bits, so the same conclusion follows. Either my reading of which operand
is shifted is wrong, or the bitmap is only meaningful for bit 0. **I could not settle it by reading**,
and the empirical fact (a live game, a slot value of 31 in the descriptor, no crash) is consistent with
the gate returning 0. A watch on `v0` at `0x80071eb0` in a live emulator would settle it in one hit.

## 4. The `ctx+0x1c` writers across all ten contexts

| measurement | value |
|---|---|
| writes to **offset `0x1c`** anywhere in stage-2 | **843** (most are unrelated structs) |
| of those, inside the interpreter area `0x8006c000`–`0x8006f000` | **68**, across **21 functions** |
| writes that target a **specific** context by constructed base | **3**, all in the dispatcher `FUN_8006da14`, all on **ctx0** |
| contexts reached individually by any writer | **none** |

The answer to "who writes it across all ten" is therefore: **no code writes a particular context.**
Every writer is generic — `lw v,0x1c(ctx)` → `addiu v,v,N` → `sw v,0x1c(ctx)` where `ctx` is whatever
pointer the handler was handed:

* the dispatcher `FUN_8006da14` **pops** into `ctx+0x1c` (`lw v1,0x140(ctx)` / `v1-=4` / `lw v0,-4(v1)` /
  `sw v0,0x1c(ctx)`) and iterates the ten contexts with `s0 += 0x174`;
* the initialisers set it from a stream pointer (`addu a1,a1,t0` / `sw a1,0x1c(a0)`);
* every other handler advances it by its own command length.

Biggest writer groups in the cluster: `FUN_8006dbc0` (15), `FUN_8006e1bc` (11), `FUN_8006da14` (6),
`FUN_8006e534` (6), `FUN_8006dfe4` (5).

**Stride census refined, and one earlier number corrected:** within that cluster there are **8** distinct
advances (`1,2,3,4,6,20,28,32`); the **18** in M99 came from all of stage-2, and the extra sizes
(`+5,+8,+10,+14,+16,+22,+38,+40`) belong to handlers *outside* the cluster — `FUN_80071e14`'s `+22` is at
`0x80071e14`, well outside `0x8006f000`. So the handler set is not a tidy block; it is spread across
`0x8006d000`–`0x80073xxx` and beyond.

## 5. Where this leaves the thread

| link | state |
|---|---|
| descriptor is an opcode-`0x44` command of 22 bytes | **confirmed against live memory** |
| byte 3 is the slot; ours is **31** | **measured** |
| byte 9 gates whether the loader is called | **new, static, and it explains the survival** |
| gate's return semantics | **open** (bitmap test; needs one watch on `v0` at `0x80071eb0`) |
| contexts written generically, never per-context | established |
| which commands the game actually runs (a full stream walk) | not done — one dump gives one instant |

The next single measurement is small and cheap: in the emulator, watch `v0` at `0x80071eb0` for a few
seconds in this room. That one value decides whether the gate blocks or passes, and therefore whether
slot 31 ever reaches `cart_record(0)`.
