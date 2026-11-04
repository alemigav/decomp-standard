# M281 — `as -g`: the missing assembler flag, and `0x800701d8` byte-exact at 141 of 141

The two experiments M280 asked for were run, in the order it asked. The first says the compiler flags are uniquely
pinned. The second does not produce a local discriminator at all — it produces a *global* one: **the original build
assembled with gas's delay-slot swap off**, which is what `-g` does to gas. With `-g` on the assembler,
`0x800701d8` is **141 of 141 words, byte-exact**, jump table included, and every previously exact function is
unchanged.

## 1. (a) The compiler flag set is uniquely pinned

Each recovered source was rebuilt with `-O1`, with `-fno-delayed-branch`, and with both, under the canonical assembler.
Nothing survives:

| function | canonical | `-O1` | `-fno-delayed-branch` | both |
|---|---|---|---|---|
| `0x8004fd1c` (98) | **98** | 26 | 0 | 2 |
| `0x80059868` (167) | **167** | 48 | 6 | 5 |
| `0x80059530` (206) | **206** | 36 | 8 | 13 |
| `0x800acae4` (53) | **53** | 7 | 3 | 2 |
| `0x8007e590` (229) | **226** | 31 | 7 | 3 |

So hypothesis (a) is closed: `-O2` with the delayed-branch pass *on* is the only setting that reproduces anything, and
the arm shape is not reachable by relaxing a compiler flag. (The generator is not idle trivia either: `-fno-delayed-branch`
makes every function *bigger*, because cc1 then emits its own delay-slot `nop`s instead of leaving them to the
assembler — the same words the assembler was adding in `0x800701d8`, which is what pointed at the assembler.)

## 2. (b) The discriminator is the assembler, and it is image-wide

M280's framing was "the image's cc1 scheduled each return". That was wrong, and the scan that refutes it is one line:
**of the 2 237 `jr ra` instructions in the image, not one has a load in its delay slot.** The population is
`addiu sp,sp,N` 1 371, `nop` 365, stores 265, alu 160, `jr` 160, and the rest scattered. A load never appears — so the
image's assembler **never** swapped a branch with the preceding instruction, in 1.9 MB of code.

That is not a property of a function, it is a property of the tools, and binutils 2.7's `tc-mips.c` states the rule
outright. In `md_apply_fix`/`mips_ip`'s branch handling:

```c
if (mips_optimize < 2
    /* If we have seen .set volatile or .set nomove, don't optimize.  */
    || mips_nomove != 0
    /* If we had to emit any NOP instructions, then we already know we can not swap.  */
    || nops != 0
    ...
    /* If the branch is itself the target of a branch, we can not swap.
       We cheat on this; all we check for is whether there is a label on this instruction. */
    || insn_label != NULL
    ...
```

Two facts follow. `mips_optimize` **defaults to 2**, and the only things that lower it are gas's own `-g` (0) and
`-O0` (1 — note `-O0` sets it to 1, not 0). And the swap is what our pipeline was silently getting: `cc1` emits a bare
`j $31` per arm, which is correct, and gas then moves the preceding load into the slot. Because the slot executes
before the jump the result is still *correct* — which is why this survived 30 probe cases and seven exact functions —
it is simply one word shorter per arm than the image.

`-g` sets `mips_optimize = 0` and the swap stops. Measured on the one function that can tell:

| assembler flags | `0x800701d8` offset | object words |
|---|---|---|
| none / `-O0` / `-O1` | 28 / 141 | 100 |
| **`-g`** | **141 / 141** | 144 (141 + the usual alignment padding) |

## 3. `-g` on every assembler call, and nothing else changes

All nine assembler invocations in `tools/compile_probe.py` now pass `-EB -mips2 -mcpu=r4300 -g -G 0`. The seven
previously exact functions were re-measured under `-g` and are **unchanged** (`98/98`, `84/84`, `46/46`, `167/167`,
`206/206`, `53/53`, and `0x8007e590` still `226/229`), because none of them contains a `load; return` arm for the swap
to fire on. The `.mdebug` section `-g` also asks for is already discarded by every link script in the corpus, so it
never reaches a comparison.

Coverage is now **seven byte-exact of nine recovered** (46, 53, 84, 98, 141, 167, 206 words) with the two failures
unchanged and both allocation-residue: `0x80024558` 136/139 and `0x8007e590` 226/229. `0x800701d8` enters the probe as
two cases — the 141-word function and its 44-word table, both pinned at **exact**, not at a threshold — so the corpus
is **34 cases, all passing**, the suite **72 suites / 1003 cases**, of which **723** need the cartridge.

## 4. What this changes about the method

Two things, and the second is the one worth keeping.

The **flag set is now complete in a way it was not this morning**: compiler `-O2 -G 0 -mips2 -mcpu=r4300`, assembler
`-EB -mips2 -mcpu=r4300 -g -G 0`. The `-g` was invisible for thirty probe cases because it only matters when a
function's arm is a `load` followed by a `return`, and the corpus had no such arm until this target.

And the **diagnostic ladder that found it is the reusable artifact**: when a function is short by exactly one word per
arm, the question is not "which statement is wrong" but "who emitted the missing word" — the compiler (visible in the
`.s`) or the assembler (visible only in the object). Dumping the `.s` answered it in one look: `lhu; j $31` was
already right, so the loss was downstream. That check costs seconds and it took a milestone to think of, because every
previous failure in this project had been a compiler failure.

M280's own conclusion — "the residual is the compiler, not the C" — was half right: it was not the C, but it was not
the compiler either. The correction is recorded here rather than edited into M280, and M280's handover note is updated
with the outcome.
