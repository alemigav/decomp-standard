# M115 — the `unk` bucket: measure the cause first, then fix the one that dominates

"Attack `unk`" is a wish, not a task. The bucket was 42 879 operands with no statement about *why* any of them
was unknown, so the first instrument built here is a **cause histogram**: every register now carries the
mnemonic of the instruction that made it unknown, the cause follows the value through joins, and each memory
operand inherits the cause of its base register.

```
provenance.py --unk-causes
48772 unknown-base operand(s), by the instruction that made the base unknown:
  addiu     31146  63.9%
  ?         11537  23.7%
  join       3745   7.7%
  addu       2169   4.4%
```

That is not a property of the game. **`addiu` at 63.9 % was a hole in my own model**: `addiu rt,rs,imm` from a
parameter, from a `paroff`, from a `cbase`, or from `sp` was thrown away as unknown, while the *identical*
operation expressed as `addu` was tracked. One instruction form, two behaviours.

## The fix

`addiu` now preserves structure instead of discarding it:

| source | result |
|---|---|
| `const` | folded constant (already) |
| `$zero` | the constant `imm` — `li` |
| `param(k)` | `paroff(k, 0, imm)` — **parameter-derived with a known bias** |
| `paroff` / `cbase` | same kind, bias adjusted |
| `sp` | `spoff(imm)` — the frame address of a local |
| `spoff` | `spoff(bias + imm)` |

`spoff` is new and does real work: a frame address used as a base now resolves to the **stack slot** it names,
so a value spilled earlier and reloaded through a computed frame address keeps its provenance instead of
becoming unknown.

## Measured

Same analysis mode, before and after:

```
                        before     after
unknown bases            42 879    14 812    -65 %
```

and re-running the cause histogram on what is left:

```
20629 unknown-base operand(s):
  ?        11362  55.1%     a caller-saved register across a call: genuinely unknown
  join      4065  19.7%     two predecessors disagreed
  addiu     2863  13.9%     built from a value that was ALREADY unknown
  addu      2164  10.5%     same
```

So the remaining bucket is no longer a modelling gap: 75 % of it is "we threw the value away at a call or a
join", which is correct behaviour, and the rest is arithmetic on already-unknown values.

## The honest limit of this result

Classification improved far more than **attribution**. Under the unified layer-2 census:

```
122 902 memory operands
  attributed (const)   14 787   12.0 %     (was 14 319; +468)
  spoff                27 413              frame-relative, newly classified — not addresses
  param                22 955
  unreached            22 896
  unk                  20 629
  ret  5 776 · cbase 3 050 · load 3 004 · unreached+const 1 384 · paroff 876 · jtent 132
```

The `unk` reduction was mostly a **reclassification** into `spoff`: 27 413 operands are now known to be
frame-relative instead of unknown, and only 468 of them became attributable addresses. That is still the right
outcome — "this reads the stack frame" is a fact, and it is now stated — but it must not be sold as a jump in
coverage.

## A consistency defect fixed on the way

`--census` was counting through the **intra-procedural** path while `--region`, `--callers` and
`--unk-causes` all used layer 2, so two commands reported different `unk` totals for the same corpus (14 812
vs 20 629) and neither was wrong — they were answering different questions under the same name. The census is
now routed through layer 2 as well; one analysis, one set of numbers.

## Acceptance tests, re-run as instructed

* **test 1 unchanged and passing**: both call sites still show `a0=ret(80001180)`, and `FUN_800327ec`'s return
  stays `const(0)`.
* **test 2 unchanged**: `0x800329ec lbu base=800eb204+0+?`, `0x80032a5c lw base=800eb264+0+?`.

Fixtures: **10/10** and **7/7**.

## Verify

```
python3 tools/provenance.py --self-test && python3 tools/provenance.py --self-test2
python3 tools/provenance.py --unk-causes         # the histogram, with causes
python3 tools/provenance.py --census             # layer-2 numbers; buckets sum to the operand total
```
