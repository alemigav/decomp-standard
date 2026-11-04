# M87 — the harness fixed under a fixture, the slot map found, and the codec hypothesis tested

## 1. Fixture first: the protocol, applied

`tools/test_harness.py` is new and encodes the architecture, not the harness's current behaviour.
Fifteen cases: six loads (`LB`/`LBU`/`LH`/`LHU` at both signs), eight unaligned stores (`SWL`/`SWR`
at byte offsets 0–3 over `0xAABBCCDD` with `rt = 0x11223344`), and the pre-existing countdown loop as
the guard for the branch the fix sits beside.

**Before the fix: 5 / 15.** The ten failures were:

```
LB  0xff   -> 0x000000ff   architecture 0xffffffff
LH  0xfffe -> 0x0000fffe   architecture 0xfffffffe
SWL k=0    -> 0x11bbccdd   architecture 0x11223344      SWR k=0 -> 0x44000000   0x44bbccdd
SWL k=1    -> 0x1122ccdd   architecture 0xaa112233      SWR k=1 -> 0x334400dd   0x3344ccdd
SWL k=2    -> 0x112233dd   architecture 0xaabb1122      SWR k=2 -> 0x2233ccdd   0x223344dd
SWL k=3    -> 0x11223344   architecture 0xaabbcc11      SWR k=3 -> 0x11bbccdd   0x11223344
```

`LB`/`LBU` and `LH`/`LHU` were literally the same instruction — `Memory.read` is `int.from_bytes`,
so no sign extension was possible on that path. `SWL`/`SWR` were derived from the little-endian
shape: in a big-endian word the byte at `al+k` is bits `[31-8k : 24-8k]`, `SWL` writes the word's
**low** `4-k` bytes, `SWR` its **high** `k+1` bytes. Both were wrong in all eight cases, not merely
swapped.

**After the fix: 15 / 15**, countdown included. The fix is four `elif` arms, none of which the old
fixture touched — which is why the "verified path" objection did not apply, as the audit argued.

A note for anyone extending this file: `Cpu.step(pc)` does **not** advance `self.pc`; only `Cpu.run()`
does, and it rezeros `r`. The first draft of the fixture hand-drove `step` and poked registers before
`run`, and both mistakes produced plausible-but-wrong failures. The fixture now drives `run()` and
passes values through its arguments.

## 2. The slot map — described before it is named

`0x800eb264` holds two pointers, and each points at a 48-byte array:

| address | bytes | values | distinct | max |
|---|---|---|---|---|
| `0x800eb204` | 48 | `11, 0×15, 12 13 … 38` (with 5 zeros inside) | 29 | 38 |
| `0x800eb234` | 48 | `39, 0×15, 40 41 … 66` (with 5 zeros inside) | 29 | 66 |

Both are **byte** arrays (one byte per slot, not words or halfwords), neither is monotone (each has
`0` holes where a slot is unused), and together they cover record indices **11–66** — the tail of the
cart table. Indexing is `byte[slot - 16]`, with one alias in the loader: **slot 57 remaps to 46**
(`beql s1,57` + `addiu s1,46` in the delay slot).

Worked examples: slot 16 → 11, slot 38 → 18, slot 46 → 26, slot 57 → 26 (via the alias),
slot 58 → 35, slot 64 → 39.

So the hop from M86 is **closed statically**: `FUN_8003287c(slot)` reaches
`cart_record(byte[slot-16])`, and record indices 38–65 — bank C's records — are reachable, through
the slots whose map entry lands in that range. What is *not* established is whether the game ever
selects those slots; the slot itself comes from scene state (§4).

## 3. The codec hypothesis: tested, and it does not hold

The audit proposed that `0x80004550` might be a **format dispatcher** rather than a zlib primitive,
which would explain why bank C takes the inflate branch and still does not inflate. Read from the
**boot bank** (not stage-2 — see §5), `FUN_80004550` is:

```
addiu sp,sp,-0x18 ; sw s0,0x10(sp) ; s0 = a0
sw zero,0x20(s0) ; sw zero,0x24(s0) ; jal 0x800013b0 ; sw zero,0x28(s0)
jal 0x800013d4 (a0 = 0x8000) ; sw v0,0x4c(s0) ; v0 = s0 ; return
```

It zeroes three state fields, allocates a `0x8000`-byte window, stores the pointer at state`+0x4c`,
and returns the state. **It reads no header and makes no decision** — it is an init routine, exactly
as `format_notes.md` §3 recorded. And the zlib error strings (`incorrect header check`,
`unknown compression method`, `invalid window size`) live in the same image, so `0x800045dc` is
stock inflate.

So the dispatcher hypothesis is **not supported**, and the paradox sharpens rather than resolves:
a record whose `stored` size is smaller than its span takes the inflate branch, and bank C's bytes
are not zlib. Two readings survive — bank C's records are never handed to this routine, or their
`stored` field does not mean what it means for the other 37 records. Neither is established.

Supporting measurement: across **all 66 records**, `stored == vram_end - vram_start` holds for
**zero** of them, and `stored == 0` for exactly three (slots 5, 7, 8). So branch 1 is dormant and
branch 0 is exercised exactly as M21 found.

## 4. One caller, and it takes the slot from scene state

`FUN_8003287c` has **one call site** in 36 images: stage-2 `0x80071ec0`, and the slot argument is

```
lw   v0, 0x5284(s1)      ; a structure hanging off s1
lbu  a0, 3(v0)           ; slot = byte 3 of that structure
jal  FUN_8003287c
```

So the loader is driven by a byte in a runtime scene structure, which is consistent with the whole
picture: a slot is chosen by game state, the slot yields a destination (the initializer's table) and
a record index (the 48-byte maps), and the record is inflated into the destination.

## 5. The fourth instance of one mistake, and the tool that ends it

I read `0x80004550` out of the **stage-2** image. It lives in the **boot bank**, so the offset was
negative and Python silently sliced the wrong end of the buffer — producing 32 zeros where there
were instructions. That is the fourth time in two sessions that a hand-composed address produced a
confident wrong answer:

| # | mistake | right answer |
|---|---|---|
| 1 | `lui 0x800c` + `addiu -23464` composed as `ori` | `0x800ba458`, not `0x800ca458` |
| 2 | `lw v0,-19868(0x800f0000)` composed as `+0xb264` | `0x800eb264`, not `0x800fb264` |
| 3 | same class, in the M83 arithmetic | 74 716 not 81 852 |
| 4 | `0x80004550` read from the stage-2 buffer | it is in the boot bank |

**`tools/vaddr.py` is the fix, because the fix is the tool and not the discipline.** It makes
`sext16` and `compose(hi, imm, mode)` explicit — `mode` has no default, since the default was the
bug — and `locate()` returns the image that contains an address and **refuses** when more than one
does, which is the twenty-overlays-share-`0x80161cf0` case. `--self-test` asserts all four historical
mistakes plus the ambiguity refusal:

```
addiu sign     got 0x800ba458 want 0x800ba458  ok
lw offset      got 0x800eb264 want 0x800eb264  ok
ori reading    got 0x800ca458 want 0x800ca458  ok
image choice   0x80004550 -> boot at +0x40d0  ok
ambiguity      refused to resolve a shared address  ok
named          0x80164cf4 in ovl_007fc12  ok
```

## 6. What is now established, and what is not

**Established:** the harness executes `LB`/`LH`/`LBU`/`LHU`/`SWL`/`SWR` per the architecture (15/15);
the slot→record map is two 48-byte arrays at `0x800eb204`/`0x800eb234` covering indices 11–66 with a
57→46 alias; the slot loader has one caller and takes the slot from scene state; the load contract is
three branches, of which branch 0 fires for three records and branch 1 for none; `FUN_80004550` is an
init, not a dispatcher.

**Not established:** whether bank C's records are ever loaded (nothing yet shows a slot whose map
entry is in 38–65 being *selected*), and therefore what bank C is. The codec question remains open —
now with a named candidate explanation retired rather than an unanswered one.

## 7. Next

1. **Watch slot selection, not the loader.** The question has moved to `0x80071eb8`–`0x80071ec0`:
   what writes byte 3 of the structure at `+0x5284`, and does it ever take a value whose map entry is
   in 38–65? That is a data-flow question about one byte, and the harness can now answer it.
2. Re-run the R4 probe matrix against a *correct* harness only where it reads signed fields — the
   matrix itself did not depend on loads, so the 1 176 negatives stand.
