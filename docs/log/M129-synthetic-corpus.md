# M129 — a 9 KB synthetic cartridge, so the corpus pipeline runs in CI

CI covered every synthetic fixture and skipped the corpus ones, because the real cartridge is gitignored. The
corpus *machinery* — the part where the whole-corpus crashes lived — therefore had no CI at all. A tiny
committed cartridge fixes that, with a scope stated up front.

## What a synthetic cartridge can and cannot do

It **cannot** re-test the two pre-registered acceptance findings: those are assertions about RE2's own addresses
(`FUN_800327ec` at `0x800327ec`, the map at `0x800eb204`), and a fixture that invented them would be asserting
fiction.

It **can** exercise everything around them, which is where the regressions have actually been:

* manifest + cartridge loading, including the sha256 refusal (M112's loader bug lived here);
* Ghidra-index region extraction, including the inclusive-`end` arithmetic;
* the interprocedural fixpoint over a real region set;
* the census identity, `--callers`, `--stk-check` and `--arg-check` — the whole-corpus paths that broke in M115
  (a stale `SLOT_STATS` key crashed `--census` for several runs) and in M119/M120 (state threaded through
  `transfer` without being a parameter, twice).

## The fixture

`fixtures/corpus/`, **9 047 bytes total**:

| file | what it is |
|---|---|
| `cart.z64` | 8 192 bytes, 16 synthetic words at ROM `0x1000`: a `lui`+`lw` that reaches an address, a frame store/reload, a `jal` between two regions, and a callee that dereferences `a0` |
| `images.json` | the real schema — `cart_sha256`, one image `boot` at `0x80000480`, size `0x40`, `source: ROM 0x1000` |
| `decomp/boot/decompile-index.json` | three function ranges, so region extraction is exercised rather than bypassed |

The tool needed a way to be pointed elsewhere: `--rom`, `--manifest`, `--decomp`, defaulting to the real paths.
That is worth having on its own — it makes the analyser usable against another cartridge without editing code.

## `--corpus-self-test` — 6/6

```
PASS  one synthetic image, three regions taken from the fixture's index     1 image(s), 3 region(s)
PASS  the census identity holds: every bucket accounted for                 5 operand(s) in
      {'const': 1, 'param': 1, 'spoff': 2, 'unk': 1}
PASS  attribution equals the const bucket, and finds the fixture's one address   attributed 1, const 1
PASS  the jal resolves to the fixture's third region                        sites ['0x800004a0']
PASS  the stack-argument checker runs and finds nothing to flag             0 finding(s)
PASS  the register-argument checker runs, and the caller passes a derived value
      deref 6, derived 6, flagged 0
```

The last two assert a **non-vacuity condition** as well as zero findings (`deref > 0`, `derived > 0`): a checker
that never fires because it never looked is the failure mode M121 spent a milestone discovering.

## The bug this step produced

My first patch anchored its dispatch insertion on a line that exists in a *different* tool, so
`--corpus-self-test` parsed but was never called — the run silently fell through to the default census and
printed the **real** 36-image numbers. Nothing errored; only reading the output showed it. A flag that parses and
does nothing is invisible unless you check what it actually did, which is the same lesson as M118's `grep`-hidden
traceback in a different costume.

## CI now

```
provenance self-test          10/10
provenance self-test2         12/12
provenance acceptance          3/3     needs the cartridge
corpus pipeline (synthetic)    6/6     new — runs anywhere
pad_layout self-test           8/8
mips harness                  15/15

all 6 runnable suite(s) pass (54 cases)
```

So a runner sees **51 of 54** cases, and the only thing that stays local is the three pre-registered checks over
the real images — which the hook runs on every commit anyway.

## Reproduce

```
python3 tools/provenance.py --corpus-self-test
python3 tools/acceptance.py
git clone . /tmp/x && cd /tmp/x && sh tools/ci.sh     # the runner's view
```
