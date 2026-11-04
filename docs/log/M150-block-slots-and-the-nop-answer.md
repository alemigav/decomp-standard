# M150 — the block-return slots are modelled, the CFG walk is real, and the NOP answer flips

M149 ended by naming the missing piece: reachability could not be tested because the walk stopped at the five
dynamic opcodes. Those are the VM's **structured exits**, and their slots are now modelled. The CFG reaches
**99.0 %** of record starts, and the answer to the two-NOP question changed twice — including a retraction of
what M149 concluded.

## 1. What the slots are, read from the handlers

Every handler that touches the saved-slot arrays or the per-thread depth counters, found by scanning the
handlers for accesses to offsets `+4`, `+8`, `+32`, `+96`, `+160`:

| role | opcodes | detail |
|---|---|---|
| **push** (block/loop/switch opens) | `0x0d ForStart`, `0x11`, `0x13 Switch`, `0x1b` | write `sw …,32(thread)` and `sw …,96(thread)` and bump the depth byte at `ctx+thread+8` |
| **push** (if/else opens) | `0x06 IfElseStart` | bumps the *other* depth byte at `ctx+thread+4` |
| **push** (subroutine) | `0x18 GoSub` | saves `cmd+2` at `ctx+0x144 + idx*4`, depth at `+8` |
| **pop** | `0x10`, `0x12` → the `+0x20` array | `lw 32(thread)`, decrement depth |
| **pop** | `0x1a` → the `+0x60` array | `lw 96(thread)`, decrement depth |
| **pop** | `0x19` | the GoSub slot |
| **loop back** | `0x0e ~LoopWhile` | reloads `+0x20` while its u16 counter is non-zero |

The model used by `tools/cfg_reach.py`: an open records its own continuation, and a pop resumes there. That
**approximates the saved pointer by the opener's continuation** rather than reading a runtime slot, which
over-approximates reachability — the safe direction for "does this ever execute?".

## 2. The walk is now real

| | before (M149) | now |
|---|---|---|
| record starts reached | ~90 % and everything downstream dead | **7 146 / 7 216 = 99.0 %** |
| dynamic opcodes | stopped the walk | modelled as structured exits |

Two caveats stated in the tool: a stack-depth cap of 24 and a 40 000-node cap per block, so a pathological
block could be truncated. Neither bound is reached by the corpus as measured.

## 3. The NOP answer, corrected

Census at **reachable command starts**, per record, linear walk (so the denominator is comparable to the
decoder's, not to the profile's 8-record walk):

| opcode | decoded | reachable | share |
|---|---|---|---|
| `0x00` | 10 349 | 9 922 | **95.9 %** |
| `0x20` | 7 328 | 7 328 | **100.0 %** |
| `0x1e` | 158 | 158 | 100.0 % |
| `0x1f` | 112 | 112 | 100.0 % |

So **all four aliases are executed**, and `0x20`'s 564 runs (median 10, p90 31, max 62) are *entirely*
reachable. That means:

* **M149's `~Fill` reading is retracted.** It called `0x20` "long empty stretches", implying unexecuted
  filler, on the strength of a reachability test that had no power. `0x20` is an **executed run of no-ops** and
  is renamed `~NopRun`.
* `~Nop` (`0x00`) is also executed (95.9 %), mostly as single bytes and often followed by `Goto` — a pad
  before a jump, with ~4 % genuinely skipped (behind an unconditional jump).

**What is now settled and what is not.** The two opcodes are behaviourally identical — one handler, one length
— and both execute. The remaining question is *why the authoring tool emitted two distinct no-op opcodes for
runs versus singles*, and that is a **tooling/compiler question that the cartridge cannot answer**: no
interpreter can distinguish them, so no amount of decoding will. Recording that as the answer is more useful
than leaving a puzzle open.

## 4. Gate

New cartridge-gated suite `cfg reachability (cartridge)` — four cases: the structured walk reaches > 95 % of
record starts, block returns no longer stop it, `0x20`'s runs are reachable, and `0x00` reaches strictly less
than `0x20` (so the difference is not an artefact). **132 cases across 14 fixtures**, `ci.sh: ok`, 18/18 marker
checks.

## 5. What this unlocks

Reachability is now a usable primitive, not a broken test. Every positional question from here — "is this
byte row executed", "which opcodes only appear in dead code", "does this record's tail contain unused
commands" — can be answered with `cfg_reach.py` instead of guessed at, and the earlier failed framings
(M149's three) all reduce to this one missing model.

```
python3 tools/cfg_reach.py --check      # 4/4, needs the cartridge
python3 tools/walk_stream.py --lens     # 45 licensed + 17 inferred names
python3 tools/acceptance.py             # 132 cases, 14 fixtures
```
