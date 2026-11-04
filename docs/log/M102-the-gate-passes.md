# M102 — the gate PASSES, and it is vacuous for this descriptor

## 1. The watch cannot be set — but the question is decidable without it

A `v0` watch at `0x80071eb0` needs a CPU debugger attached to a running emulator. Two facts rule that
out here and both are already recorded: ares' release build exposes **no CPU debugger** (the menu
inventory in the arc that installed it), and the harness **never reaches this PC** (M100: `a0` at
`0x80071ebc` unhit in 2 000 000 instructions, with a positive control proving the watch works).

So the gate was settled the other way: from the gate's own code plus the descriptor in your dump. That
is a stronger answer than a watch, because it holds for every command, not just one instant.

## 2. The verdict

```
descriptor 0x8052a614:  byte 9 = 0x28 = 40
bitmap index:           word = 40 >> 5 = 1   bit = 40 & 0x1f = 8
bitmap word:            *(0x8052a614 + 4)  = 0x10400001
mask:                   0x80000000 << 8    = 0x00000000
test:                   0x00000000 & 0x10400001 = 0x00000000
=> gate returns 0 -> `bne v0,zero,0x80072298` NOT taken -> the loader IS called
```

**PASSES.** The loader receives slot 31.

Two robustness checks, because one reading of the shift could be wrong:

* the alternative direction `0x80000000 >> 8 = 0x00800000`, **and**ed with `0x10400001`, is also `0` —
  the verdict does not depend on which operand is shifted;
* **no `byte9` value in 0…95 blocks this descriptor**: for `bit >= 1` the mask is always zero, and for
  `bit == 0` the tested word's most-significant bit is clear. So the gate is **vacuous here** — it
  cannot be the thing protecting the game.

That second point is the important one. M101 hypothesised the gate might explain the game's survival.
**It does not**: the gate passes, the loader runs, and the survival has to be explained downstream.

## 3. What actually happens, and why nothing breaks

With the gate passing and slot = 31:

1. `FUN_8003287c(31)`: `slot-16 = 15`; `sltiu 15,16` → `s0 = 1` → `s4 = 4` → **pointer #2**, array 2;
2. destination table entry `0x800e162c` = **`0x80161cf0`** (non-zero, from the dump) — so no early return;
3. `array2[15] = 0` → `cart_record(0)` → the `OVERLAYTABLENUMC` marker;
4. `FUN_800327ec`: `record[1] = 0x4c415954 ≠ 0`, span mismatch → **branch 2** →
   `inflate(0x4f564552 & 0x0FFFFFFF = 0x0f564552, dest, 0x4c415954)`;
5. the PI DMA source is four times past the cartridge, zlib rejects the garbage header, and
   **`FUN_800327ec` never checks the return** (M92) — it goes straight to `inflate_free` and returns.

So the destination keeps whatever it held (`0x80161cf0`, the bank B base) and the game does not notice.
**The prediction that slot 17–31 is "catastrophic" was wrong in one word: it is *silent*, not
catastrophic.** An out-of-range DMA plus a rejected header is a failed load, not a fault.

That closes the thread consistently: the gate passes, the loader runs with a nonsense record, the load
fails silently, and the game continues — which is exactly what your dump shows.

## 4. Tooling

`room_probe.py` now computes and prints the gate verdict itself, so one command answers the whole
question:

```
gate: descriptor byte 9 = 0x28; byte 9 = 40 -> bitmap word 0x10400001, mask 0x00000000,
      test 0x00000000 -> PASSES (loader called)
```

and it still refuses cleanly on the pre-room dumps ("the scene slot context is NOT installed").

## 5. What is settled, and the one thing that is not

**Settled:** the descriptor is a 22-byte opcode-`0x44` command (confirmed against live memory); byte 3
is the slot and it is **31**; the byte-9 gate **passes and is vacuous**; the loader therefore runs with
slot 31, reaches `cart_record(0)`, and the inflate **fails silently**; nothing is gated away, and the
game survives because the failure is invisible.

**Not settled, and it is now the only open item:** whether *any* command in a real room carries a slot
in **16 or 32–63**, i.e. whether a legitimate record is ever loaded through this path. The stream scan
found no `0x44` at the 22-byte stride in the first 1 KB from `+0x48`, and `0x44` is a common byte in
that buffer (it appears at many offsets), so a stride-aligned walk from an arbitrary start is not
enough. A walk that starts at the live command pointer and follows the per-opcode lengths would settle
it — that is a parsing job over the dumped buffer, not a disassembly job.

## 6. One caveat on the descriptor's identity

The 32 bytes at `0x8052a614` read as a command *and* as a bitmap-bearing structure: word 1
(`0x10400001`) was tested as the gate bitmap, and the same word is byte 4–7 of the "command". Both
readings are consistent with the disassembly, which is why the bitmap interpretation is offered as the
gate's mechanism while the gate's *verdict* (0, i.e. pass) is what the code computes. If a future
session finds that `0x800837ac`'s `a0` is a static bitmap rather than the descriptor, the verdict for
this data does not change — the mask is zero either way.
