# M203 — +20 and +24 are a loop start and a loop *length*

M193 named these two words "loop start" and "loop end" from a third-party description. That reading was never
measured, and it is wrong in the way that matters: the second word is a **length**, not an end. The
cartridge's own code settles it, and the 1 192 records confirm the arithmetic on every record that has a
loop. This milestone is one word, one arithmetic sign, and three ways to falsify it.

## 1. What the player does with them

The chain that reaches a sample starts at the sequencer's command handler `FUN_800b03cc`, case `0x10`, and
it is short:

```
0x800b03cc  case 0x10:            the sequence dispatcher's "play a sample" command
0x800af700  → FUN_800ada34        binary-search the directory (stride 0x1c) for the key
0x800a54ec                        copy the found record into the voice's fields
0x800a3bf4                        per-voice mixer feed: split the block at the loop end
0x800a6c04  → FUN_800a59d0        note-off: clear the per-voice byte that keeps the loop running
```

**The reader** (`FUN_800ada34`, body `0x800ada34`–`0x800adb47`) is six lines of interest, and Ghidra's types
hide the width question, so they were read at the instruction level:

```
0x800adab4  lw  v0, 0xc(v1) ; sw v0, 0x0(s2)    param_2[0] = *(u32 *)(record + 0x0c)
0x800adabc  lw  v0, 0x8(v1) ; sw v0, 0x4(s2)    param_2[1] = *(u32 *)(record + 0x08)
0x800adac0  addiu v1, v1, 0xc                    v1 = record + 0x0c from here
0x800adacc  lw  v0, 0x8(v1) ; sw v0, 0x10(s2)   param_2[4] = *(u32 *)(record + 0x14)  <- 32-bit
0x800adad8  lw  v0, 0x4(v1)                      param_2[3] = the length word ...
0x800adae0  and v0, v0, a0                       ... masked with (lui 0xff ; ori 0xffff) = 24 bits
0x800adae8  lw  v0, 0xc(v1) ; sw v0, 0x14(s2)   param_2[5] = *(u32 *)(record + 0x18)  <- 32-bit
0x800adaf4  lbu v1, 0x4(v1) ; sb v1, 0x18(s2)   param_2[6] = the codec byte (3)
```

**The voice setup** (`FUN_800a54ec`, `0x800a54ec`–`0x800a5677`) copies the descriptor into a 0x68-byte voice
and then computes one derived field:

```
0x800a55dc  lw v0, 0xc(a1) ; sw v0, 0x30(a2)   voice+0x30 = declared length (samples)
0x800a55e4  lw v0, 0x10(a1); sw v0, 0x34(a2)   voice+0x34 = record +20
0x800a55ec  lw v0, 0x14(a1); sw v0, 0x38(a2)   voice+0x38 = record +24
0x800a5604  lw a3, 0x38(a2)                    if +0x38 == 0, +0x3c = 0
0x800a5610  lw v1, 0x34(a2)
0x800a5614  lw v0, 0x30(a2)
0x800a5618  addu v1, v1, a3                    v1 = word20 + word24
0x800a561c  subu v0, v0, v1                    v0 = length - (word20 + word24)
0x800a5620  sw v0, 0x3c(a2)                    the remainder after the loop
0x800a5624  sltiu v0, v0, 0xa ; bnel ...       below 10 it is rounded to 0
```

**The mixer feed** (`FUN_800a3bf4`, `0x800a3bf4`–`0x800a455f`) is where the two words are *used*, and it is
unambiguous — the sum is the loop end, and after the wrap the block continues at `word20` for
`word24 − (position − word20)` more samples:

```
0x800a3cec  lw v0, 0x38(s2)                    a3 = word24
0x800a3cf8  beq a3, zero, <no loop>            no loop length, no loop
0x800a3cfc  addu v1, v1, v0                    v1 = word20 + word24   = the loop end
0x800a3d20  sltu v0, v1, <pos + n>             does this block cross the end?
0x800a3d4c  subu v0, word20, pos               after the wrap: start - position
0x800a3d50  addu v0, v0, word24                + length -> the second segment's length
0x800a3d64  subu s5, word20, pos               the loop start's offset behind the position, kept for the wrap
```

So the record's last two words are **`+20` = loop start, in decoded samples from the beginning of the
sample** and **`+24` = loop length, in samples**. The loop end is their **sum**, and the record's declared
length covers start + length + remainder. A start/end pair would not be *added* anywhere.

**When it stops.** `voice+1` is set to 1 when the sample is started (`FUN_800a54ec`), and `FUN_800a59d0` —
the whole function is `voice[param_1 * 0x68 + 1] = 0` — clears it from the sequencer tick (`FUN_800a6c04`),
when bit `0x80` of the voice's flag word is set and bit `0x40000000` is clear. So the byte is 1 from the
start and is cleared once on that branch, which makes it a gate; the mixer tests it beside the remainder
(`(param_1[1] == '\0' && (*(int *)(param_1 + 0x3c) != 0))`). While it is set the voice loops, and once it is
cleared, **if there is a remainder, the loop is abandoned and the sample plays out to its end**. That is what
the remainder is for, and it is why a loop need not end at the last sample.

## 2. What the data says

| | |
|---|---|
| records with a loop (`+24` non-zero) | **187** of 1 192 |
| records without one | **1 005**, and every one of them carries **exactly 2** at `+20` |
| loop start | 0 … 57 422 (4 records start at 0) |
| loop length | 56 … 117 141 |
| start + length ≤ declared length | **187 / 187** |
| start + length == declared length | **112** (median remainder 0) |
| remainder | 0 … 8 185 samples, at most **32.6 %** of its sample |
| start + length ≤ decoded samples (`frames × 64`) | **187 / 187** |
| start + length ≤ the sample's **byte** count | **4 / 187** — the unit is not a byte |

Two consequences worth stating separately.

**The 1 005 records without a loop carry a filler.** All of them have `+20 == 2`, one constant, and the mixer
never reads it: the first branch is `if (word24 == 0)`, so `+20` is inert wherever `+24` is 0. Reading a
meaning into that 2 would be reading noise.

**The declared length is 24 bits, and that bit me.** `+16` is not a `u16` pair: byte `+16` is the codec (3) and
bytes `+17..+19` are the length. Ten records have a length above 65 535. While working this out I first read
the length as the `u16` at `+18`, which produced **four violations** of the first law above and a
"start beyond the length" case at record 314; with the 24-bit field there are **zero** violations. The
cartridge masks with `0xffffff`, which is the same statement from the code side. The retraction is carried in
§4.

## 3. The three falsifications, each gated

A "start and length" claim can fail arithmetic in three independent ways, and all three are asserted:

| falsification | what it would require | what the cartridge says |
|---|---|---|
| `+24` is a **loop end** | `start < end` on every looped record | holds on **123 of 187** — 64 records have start ≥ end |
| `+24` is a **16-bit** field | length ≤ 65 535 | three lengths are **117 141, 73 630, 65 836**; truncated to 16 bits one remainder becomes **99.3 %** of its sample against a 32.6 % maximum |
| the unit is a **byte** | start + length within the sample's byte count | it fits on **187/187** as samples and on only **4/187** as bytes — the unit is a decoded sample |

## 4. What this does not say, and what was wrong

* **M193's "+24 = loop end" is retracted.** It came from a description, not from the cartridge, and the
  cartridge adds the two words.
* **My own 16-bit reading of the length is retracted**, mid-investigation, and it is the reason the first
  version of this analysis showed four "violations". The field is 24 bits and the violations do not exist.
* **The waveform gives no independent confirmation.** Decoding the looped samples (183 of the 187 have their
  start inside the stream and their end before its last sample) and measuring the jump across the seam (`|x[start] − x[start+length−1]|` divided by the loop region's RMS) gives a **median 0.306**,
  against **0.198** for an ordinary interior step and 0.221 for the natural continuation. So the loop points
  are *not* tuned to this decode: they are structural metadata, and the naming rests on the code and the
  arithmetic, not on the sound. This is a negative result and it is reported as one.
* **What the middleware calls the field is still not established.** The class-3 16-byte record remains
  unnamed for the same reason (M202); `+20` and `+24` are described by their role, not given a label the
  cartridge does not have.
* **The `+8` word is still zero in all 1 192 records** and lands in the voice's sample-base slot
  (`voice+0x2c`), so something patches it at load time; the patch site is *not* established here, and the loop
  words do not depend on it.

## 5. Gates

`file table (cartridge)` **97 → 106**: five data cases (the 187/1 005 split with the filler constant, the
start + length laws, the end-reading refutation, the 32-bit width with its 16-bit counterfactual, and the
sample unit against the byte unit) and four code cases (the reader's 32-bit loads and 24-bit mask, the
remainder arithmetic, the mixer's post-wrap segment, and the note-off byte the mixer consults).

`gate audit (mechanisms disabled)` **56 → 65**, nine mutations, one per case, and each was checked to fail
*its own* case rather than merely making the tool exit non-zero: the loop word ignored, the length read as 16
bits, the start/end comparison inverted, the loop length truncated to its low half, the decoded frame taken
as 32 samples, and each of the four code needles broken in place.

Repository is **36 suites / 488 cases**, of which **14 suites / 270 cases** are cartridge-gated, so the
runnable tier is **22 suites / 218 cases**.
