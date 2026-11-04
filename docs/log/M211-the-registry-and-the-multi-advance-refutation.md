# M211 — the registry, and the multi-advance claim it disproved

Two artefacts came out of this milestone: a derived registry (`fixtures/scd/registry.json`, 141 opcodes) and a
refutation of the claim that motivated it. The refutation is the more valuable half.

## 1. "16 opcodes carry more than one advance constant" is wrong

M141 §3 said that, and every later note repeated it — mine included, as recently as M210's explanation of the
17 distinct lengths. Measured against the handlers:

| | |
|---|---|
| opcodes with exactly one constant advance | **130** |
| opcodes with **more than one** | **2** — `0x0d`, `0x1b` |
| opcodes with no constant advance | **9** |
| published advance not in its own constant set | **4** |

And the two that survive are not two constants at all. `0x0d` and `0x1b` each take one constant path (`6`) and
one **variable** path (`6 + s16[cmd+2]`, the loop count) — `tools/walk_stream.py:364` and the handler at
`0x8006d5dc`, whose store is `*(param_1 + 0x1c) = iVar2 + (uint)uVar1`. `advance_set()` folds those two arms
because its dataflow carries `a3 = cmd+6` out of one arm into the other; `12` is never a command length.

So M141's remaining rows were fixed-window over-reach into neighbouring handlers — exactly the defect M142's
`handler_extent()` was written to remove — and its own table lists **17** opcodes under a heading that says 16
while missing `0x1b`. Both are retraction rows in the log.

## 2. The finding that re-scoped the next milestone

**82 of the 141 entries point at a handler that is not inside any function body.** Measured against
`fixtures/decomp/ranges.json` and against the byte map from M207:

| | |
|---|---|
| distinct handler addresses | **138** (141 opcodes; three handler addresses serve four opcodes) |
| handlers inside a known function body | 59 |
| handlers in **unclassified** bytes | **79** |

So the corpus's 3 638 functions structurally cannot hold the Script VM: its dispatch table points into the
16.5 % of image bytes that no body claims, which is why 86 opcodes have no `src/` file and why the advance rule
had to be derived by scanning bytes in the first place. `walk_stream.py` was right for a reason nobody had
written down.

That is why the registry carries `in_function_body` per opcode: the artifact now says which handlers the corpus
can speak about and which it cannot, instead of leaving it to a note. It also re-scopes M212 from "read the
handlers" to "recover the region", which needs no Ghidra run — a byte-level extent analysis.

## 3. What the registry says, and what it refuses to say

`tools/opcode_registry.py --write` emits, per opcode: `number`, `name`, `name_source`, `handler`,
`in_function_body`, `published`, `control_flow`, `advances` (a list of `{"kind": "constant", "value": N}` or
`{"kind": "variable", "expression": …, "source": …, "store": …}`), `scheduler_effect` (uniformly `"unknown"` in
this milestone — M212 fills it or says why it cannot), and `evidence`.

It refuses to call a folded constant a constant, and it refuses to give a variable path a value. The
`--check` gate has **17 cases**: 141 entries; every profile opcode present exactly once; every constant matches
what `resolve()` measured; every variable entry names the line it was inferred from; `in_function_body` agrees
with the ranges and so does `evidence`; and the committed file is byte-identical to a fresh `--write`.

Two mutations, both verified to fail with their own message: fold the two-path opcodes back to a constant
(`opcode 0x00 claims constant …`), and report every handler as being in a body (`in_function_body matches the
corpus ranges …`).

## 4. Not claimed

`0x36`'s real advance (`cmd+12` at `0x800712cc`) sits **outside** its Ghidra body
`0x80071180..0x800711cb`, so `resolve()` cannot see it; the registry records that in a note and does not claim
the value. `walk_stream.DYNAMIC[0x01]` ("no pointer write at all") is incomplete — `0x8006db78` writes the slot
`0x18` pushes — and is recorded, not edited, because changing the walker's model is a milestone with its own
evidence.
