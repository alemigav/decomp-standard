# M260 — p8 recovered (116 of 139, best arm byte-exact) and two defects in our own toolchain

The third of M253's four heads: **`0x80024558`**, bound **6**, index a **global byte** (`DAT_800e923c`), table
`0x800b69b0`. Where p6 and p7 are state machines, p8's arms are **Gfx command packets** — `w0`/`w1` word pairs
written through a block-scoped temp pointer — so it exercises a different idiom on the same compiler.

## 1. The reconstruction: 116 of 139 words, and the best arm is exact

| region | words |
|---|---|
| case 0 (four packets: `0xE3001001`, `0xE200001C`, `0xE3000A01`, `0x0A000000`) | **27 / 27 byte-exact** |
| cases 3 and 4 (eight packets, incl. the `FF10`/`ED00`/`F700`/`F600` sequence) | 73 / 92 |
| epilogue | **5 / 5** |
| head + dispatch | 11 / 15 |
| **jump table** | **6 / 6 arm addresses, byte-identical** |
| **whole function** | **116 / 139 by offset**, 126 by content, 14 hunks |

That is the strongest reconstruction so far on the offset metric (p6 28/98, p7 74/84), and its most
characteristic arm is exact.

Three things had to be *read* rather than assumed, and each was a fork worth recording:

- **the block-scoped temp pointer.** `{ Gfx *_g = p; p = p + 1; _g->w0 = …; _g->w1 = …; }` is the idiom. In-place
  `g++` scored **0 of 139** — the image saves `s1` and advances the pointer while writing through a separate temp.
- **cases 1, 2 and 5 are empty** (all three table entries are the epilogue). With only `{0,3,4,5}` present gcc
  emitted a compare chain instead of a table (136 words), so at least five case *values* existed and `sltiu 6`
  forces a label at 5.
- **the cast is signed.** A bare `trunc.w.s` with no range check means the cast target is `s32`; writing `(u32)`
  emits the four-instruction check and 164 words instead of 140.

And M258's lesson applied again, in a different form: the **struct-pair** form of the packet writes gives
116/139, the plain `u32*` / `_g[0..1]` form gives **9/139** (it loses the `s1` save and moves the pointer from
`t6` to `t5`, shifting the whole function). Same-kind accesses are not just about dependence — they decide the
allocation.

## 2. `as` must be told `-mcpu=r4300`, and it is worth 71 words

The single largest lever found in this milestone, and it is a property of the **assembler**, not the C:

| `as` flags | words identical |
|---|---|
| `-EB -mips2` | 45 / 139 |
| `-EB -mips2 -mcpu=r4300` | **116 / 139** |

Without `-mcpu`, binutils 2.7 does not set `cop_interlocks` and inserts a hazard `nop` after every `mtc1` — this
function has enough FP moves that the spurious nops alone cost 71 words. **The whole probe pipeline now passes
`-mcpu=r4300`**, and re-running p6 and p7 with it changes nothing (neither has an `mtc1`), which is the check that
it is a fix and not a coincidence.

## 3. A defect in our own `cc1`: every constant-pool float is 0

Our `.rodata` for p8 vs the image's, eight words from `0x800b69b0`:

```
ours:   00000000 00000000 00000000 00000000 | 80024594 80024770 80024770 80024600
image:  80024594 80024770 80024770 80024600 | 41f00000 00000000
```

Two separate facts in that window:

1. **The pool is emitted before the function body** (`CONSTANT_POOL_BEFORE_FUNCTION` defaults to 1 and mips does
   not override it), so our `.rodata` is `[pool][table]` where the image is `[table][pool]`. The table still
   matches byte-for-byte, it lands 16 bytes late, and it costs exactly **one** code word.
2. **`cc1` writes every constant-pool FP literal as `0`.** This is a host-portability defect in our own build:
   `varasm.c` copies `CONST_DOUBLE_LOW (x)` with `sizeof u` of a 16-byte union on a 64-bit host, so the float's
   bits are taken from the wrong half. `.data` initialisers are unaffected; the pool is not. **Three words of the
   image's `.rodata` are therefore unreachable by comparison**, and any future FP function will compile with
   `0.0f` where its source had a real constant.

The pool also *gives something back*: the image's word after the table is **`41f00000` = 30.0f**, while the
recovered source multiplies by `4.0f`. That is a source fact sitting in plain sight, and it is a concrete lead for
the 19 remaining words in cases 3/4 — but it cannot be tested until defect (2) is fixed, because our pool holds 0.

## 4. The corpus extent for this function is wrong

`manifests/code_index.json` records `FUN_80024558` as **80 bytes** and resumes at `0x80024784`, while the body is
`0x80024558..0x80024780` — **139 words, 556 bytes**, with case 0 inline at `0x80024594` and the epilogue at
`0x80024770`. So `0x800245a8..0x80024780` is not attributed to this function at all. That data is a **tool output**
(`build_images.py` / `extent_audit.py`), not something to hand-edit, so it is recorded here as an extent-audit
follow-up: the head-plus-arms structure that M254 documented for p6 is *here one contiguous function*, and the
extent finder split it.

## 5. State

- Corpus **20 cases, all passing** (p8 whole function + p8 table added); pin moved to 20.
- Three whole functions are now recovered and re-compiled against the image: **p6 82/98 content, p7 74/84 offset
  with case 0 exact, p8 116/139 offset with case 0 and the epilogue exact**.
- **Two instrument defects are now named in the tool's docstring** so they are not re-debugged: the `-mcpu=r4300`
  requirement, and the zeroed FP pool. The second one is a *build* bug with a known cause and is the next thing to
  fix — it is the difference between probing FP code and not.
