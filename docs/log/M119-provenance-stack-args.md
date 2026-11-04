# M119 — stack-argument propagation: the mechanism resolves 89.8 %, and buys seven addresses

M118 left one named gap: 5 815 frame-slot reads that no store in their own function explains. Those are
**incoming stack arguments** — the callee's view of the caller's outgoing argument area. They are now modelled,
resolved across the call boundary, and the result is a clean example of a mechanism that works and does not
pay.

## Mechanism

* A never-stored frame slot at bias **≥ 0** lies above the function's entry `sp`, i.e. in the caller's
  outgoing area: its value is `PARAMSTK(bias)` rather than unknown. Below zero it is a local read before being
  written, and stays unknown.
* A function's summary now carries `stk` — the biases it reads as incoming stack arguments — alongside `params`
  and `ret`, and `ret` may itself be a `PARAMSTK`.
* At a call site the caller supplies them: `args_stk[b] = state.slot[spbias + b]` — the callee's bias `b`
  relative to `sp` *at the call* is the caller's slot at the same byte distance.
* `resolve` substitutes them exactly as it substitutes register parameters, and **keeps the label** when the
  caller stored nothing, rather than inventing a value.

## Fixture L9, and the ordering bug it caught

The callee reads `0x10(sp)` and returns it; the caller stores a constant at `0x10(sp)` and dereferences the
return. It failed on the first run for a real reason: the `stk` set was computed **before** `ret` was known,
so a callee whose only contact with its stack argument is *returning* it declared no stack arguments at all.
Collecting `stk` after `ret` fixed it. (Third time in this arc that an ordering of summary fields was the
bug — it is where the logic is densest.)

## Measured

```
stack arguments: 2 540 asked for by a callee, 2 282 supplied by the caller (89.8 %)
base kinds: ... paramstk 168 ... const 13 574 ... unk 25 179 ...
3678 regions · 111 179 memory operands · 13 574 attributed (12.2 %)
```

* **89.8 % of stack arguments resolve at the call site.** The mechanism is complete as specified.
* It buys **+7 attributed addresses** (13 567 → 13 574) and removes 176 unknowns. Callers put non-address data
  in outgoing argument slots, or addresses that are themselves unknown-loaded, and most callees do not use a
  stack argument as a base.

So this step's value is not coverage:

1. **168 operands now carry `stkarg(b)` instead of `unk`** — a weaker claim, but a true one;
2. the residual category from M118 is now *named*, not merely counted: those reads are incoming arguments by
   construction;
3. the `stk` field is the input a **caller-side check** needs — "this callee reads a stack argument at bias
   `b`, and the caller stored nothing there" is a defect signature, and it is now expressible. That check is
   not written here.

## State of the arc

```
provenance.py --self-test    10/10
provenance.py --self-test2    9/9
provenance.py --acceptance    3/3
```

Attribution has sat at 12.2 % through the last four milestones while the analysis got more correct. That is the
honest shape of this work now: the remaining unknowns are *runtime* facts (a slot byte read from a map, a
pointer loaded from memory), not modelling gaps. Further static mileage would have to come from
`--follow-pointers` being sound enough to be default, or from path feasibility on the handful of branches that
decide which table is read — both are different projects from "add another value kind".

## Verify

```
python3 tools/provenance.py --self-test && python3 tools/provenance.py --self-test2
python3 tools/provenance.py --acceptance
python3 tools/provenance.py --census      # stack-argument line, coverage line, bucket identity
```
