# M282 — the gas flag ladder, and a correction to M281: `-O0` cannot work, `-O10` can

M281 recorded that `-g` stops the assembler's delay-slot swap and that "`-O0` sets `mips_optimize` to 1, not 0". The
second half is **wrong**, and the way it is wrong is worth one milestone because it is a one-character bug in the
pinned assembler that anyone re-deriving this build will hit.

## 1. The ladder, measured

`0x800701d8` (the 44-arm accessor dispatcher) is the discriminator: 28 of 141 words at 100 object words without the
fix, 141 of 141 at 144 words with it.

| assembler flags | object words | identical |
|---|---|---|
| none | 100 | 28 / 141 |
| `-O0` | 100 | 28 / 141 |
| `-O1` | 100 | 28 / 141 |
| `-O2` | 100 | 28 / 141 |
| **`-O10`** | **144** | **141 / 141** |
| **`-g`** | **144** | **141 / 141** |
| `--gdwarf2` | — | rejected by this as: `unrecognized option` |

## 2. Why `-O0` cannot work

From `binutils-2.7/gas/config/tc-mips.c`, the option handler:

```c
    case 'O':
      if (arg && arg[1] == '0')
	mips_optimize = 1;
      else
	mips_optimize = 2;
      break;
```

The test is `arg[1]`, not `arg[0]`. For `-O0` the argument text is `"0"`, so `arg[1]` is the NUL terminator and the
condition is false — `mips_optimize` stays at the default **2**, and the swap the whole question is about still runs.
`-O10` has `arg = "10"`, `arg[1] == '0'` → true → `mips_optimize = 1` → the swap stops. So the only `-O` spelling that
does the intended thing does it by accident.

The supported route is the other one in the same file:

```c
      if (mips_debug == 2)
	mips_optimize = 0;
```

i.e. **`-g`**, which is what M281 pinned and what `tools/compile_probe.py` now passes on all nine assembler calls. It
does not depend on the bug, and its `.mdebug` output is discarded by every link script in the corpus.

## 3. What this corrects, and what it does not

Corrected: M281's parenthetical claim that `-O0` lowers `mips_optimize`. It does not — the flag is inert in this
assembler, and the ladder above is the evidence. The M281 note is left as written and this row is the correction, which
is the project's rule (M262, M266, M270, M275 all follow it).

Unchanged: the pin itself, `-g`, and every number that depended on it. `0x800701d8` remains **141 of 141 byte-exact**
with jump table **44 of 44**, the corpus remains **34 cases, all passing**, seven of nine recovered functions remain
byte-exact (`46`, `53`, `84`, `98`, `141`, `167`, `206` words), and the suite remains **72 suites / 1003 cases** with
**723** needing the cartridge.

The generalisable part is small but sharp: **an assembler flag that looks like a no-op may be a misfeature, so measure
the ladder rather than reason from the manual** — and when a single `char` index decides whether a pipeline reproduces
the cartridge, the reproduction should use the spelling the tool documents, not the one that works by coincidence.
