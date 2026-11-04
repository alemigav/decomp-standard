# M197 — the ring does nothing to the bytes, and the reader reverses them

M195 named the blocker as "the decoder does not read the record's bytes — it reads a 4 KiB ring, and
nothing has established what that copy does". Both halves of that sentence turn out to be wrong in a way
that is now measured: the copy is a **verbatim DMA**, and the reason the parse failed was that I had the
**bit order** wrong. With the reader's own order the voice stream reconciles on **588 of 588** clips.

## 1. What the ring fill does: nothing

`FUN_800b4a04`, from our decompilation:

```
if state in (1,2,3) and (ding - dref) < 0xc01:
    n = 0x400, or (bytes_remaining << 2) when fewer than 0x101 remain
    (**(code **)(ctx + 0x190))(base + writepos,          ctx + 0x1a0 + (writepos & 0xff8),  n,
                                ctx + 0x11ac)             ; callback, then an OS message poll
    writepos += 0x400
```

- `ctx+0x190` is a **function pointer** — the PI/DMA read routine, not a local loop;
- the destination is `ctx + 0x1a0 + (writepos & 0xFF8)`, i.e. the buffer at **`ctx+0x1a0`, wrapped at 4 KiB**.
  The state struct starts at `ctx+0x11a0`, and `0x1a0 + 0x1000 = 0x11a0` — the ring ends exactly where the
  state begins, which is why its size was never ambiguous;
- completion is polled with `func_0x8000c9e0(ctx+0x11ac, 0, 0)` (an OS message receive), so this is an
  asynchronous DMA with a message queue, and the bytes land as read.

There is no swap, no halfword shuffle and no re-layout. The ring is a double buffer, and the stream the
decoder sees **is** the record's payload.

## 2. What the reader does: reverses each 4-byte group

`FUN_800b53f4`, at instruction level (`0x800b5428`):

```
lw   s1, 0x11c8(ctx)          ; bitpos
sra  v0, s1, 3                ; bitpos >> 3
andi v0, v0, 0xffc            ; 4-byte aligned, wrapped to the 4 KiB ring
addu v0, v0, ring
lw   a0, 0(v0)                ; a big-endian 32-bit load
andi v1, s1, 0x1f             ; bitpos & 31
srlv a0, a0, v1               ; >>> LSB-first inside that word
```

So bit *p* of the stream is **bit `p & 31` of the big-endian word at `p >> 5`**, counted from the least
significant bit. In a big-endian word the most significant byte comes first, so bit 0 is the *low* bit of
the **last** byte of the group: the four bytes of every 4-byte group are consumed **in reverse order**, each
one low bit first.

That is a third order, and neither of the two M195 tried:

| order | result |
|---|---|
| MSB-first, file order | **362/588** overrun, 3 land within 8 bits |
| LSB-first, file order | **339/588** overrun, 0 land |
| **LSB-first in big-endian words** (the reader) | **0/588 overrun, all 588 end within 32 bits** (min 1) |

The two M195 numbers reproduce exactly, which is what makes this a correction rather than a story: the
orders M195 ruled out really do fail, and the one it did not try really does work.

Two details fall out for free. The bit position starts at **`0x60` = 96 bits = byte 12**, written in the
same function when the first chunk arrives (`writepos == 0`) — so the 12-byte `MORT` header is skipped by
the reader, not by an offset in the format. And after each block the cursor is committed as
`(word_start + 32) - bits_left`, i.e. only the bits actually consumed, which is what lets a block end
mid-word.

## 3. The arithmetic closes, which is a second, independent check

Parsing every clip to its declared block count (`u16@+4`) with the reader's order:

| | |
|---|---|
| blocks emitted | **307 038** (the sum of `u16@+4` over all 588 records) |
| normal blocks (260-bit frames) | **262 894 = 85.6 %** |
| silent blocks (a 4-bit run, no body) | **44 144 = 14.4 %** |
| implied bits per block | 0.856 × 260 = **222.6** |
| payload bits per declared block | **222.8** |

The payload and the declared block count agree to 0.1 %, and every stream ends within one word of its
record. This also explains the number that derailed M194: `260 / 222.8 = 1.17`, exactly the "1.17× over
budget" it used to refute the block count. It was an upper bound that assumed every block carries a frame;
14.4 % of them carry silence.

## 4. Retractions

- **M195's blocker is withdrawn.** The ring does not transform the bytes, and the format was not
  bit-incompatible with the reader — my two candidate orders were.
- **`u16@+4` is the block count after all.** M193 said so, M194 withdrew it as "not established", and the
  measurement now supports it: 307 038 declared blocks parse to the end of all 588 records. That is a
  flip-flop (`is` → `not established` → `is`), recorded as one. The withdrawal was not careless — M194's
  arithmetic was sound but its premise (260 bits for *every* block) was an over-estimate, and the band
  3.1–11.4 % that M179 measured was already the compression range a mixed normal/silent coder produces.

## 5. What is still missing: the synthesis, not the stream

The stream now decodes to fields. Turning fields into samples needs three functions, none of them
transcribed yet:

- `FUN_800b62c0(scale, phase, coefs[13], table[42])` — dequantise the 13 coefficients in place
  (`((c*0x2000 - 0x7000) * ((scale & 7)*0x800 + 0x47ff) + 0x4000) >> 15`, plus a scale-dependent rounding
  term), zero a 40-entry table, then scatter the 13 at **stride 3** from `table + phase`. Four calls per
  block, one per side group, each with its own phase.
- `FUN_800b4dc0(ctx, scales[8], table, msg)` — map the eight scale fields through eight fixed-point
  affine transforms into `ctx + ctx[0x188]*0x10 + 0x168` and toggle `ctx[0x188]`: two alternating banks.
- `FUN_800b6634` — the mixer that turns those banks into output samples.

That is a polyphase filterbank, and it is a decoder milestone of its own. **No audio is decoded**, and this
note does not claim any.

## 6. State of the tree

`file_table.py --check` **89/89** in 4.3 s, now including all three bit orders in one case pair (the two
refutations and the reconciliation) and the 307 038-block arithmetic; audit **48/48, 0 vacuous**; counts
derived (35 suites / 445 cases, 22 / 218 runnable without the cartridge); ratchet re-baselined.
