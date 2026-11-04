# M117 — Ghidra's function bounds replace my heuristic, and two layer-2 fabrications fall out

The boundaries were already on disk. `build/decomp/<image>/decompile-index.json` — produced by the Ghidra
corpus work (M81–M83) — carries, per function, `address` and `body.ranges` with an **inclusive** `end`. Using
it retires the prologue / post-`jr ra` heuristic that M112 had already caught skipping every leaf function.

## The switch

```
regions: 36 image(s) from the Ghidra index, 3678 range(s), 40 multi-range function(s),
         62.2% of image bytes inside a known function; fallback heuristic used for: none
```

Region count **7 093 → 3 678**, zero fallbacks, and 40 functions whose body is non-contiguous are analysed
range by range (each range gets its own entry state; that is an approximation and it is stated here).

| | heuristic | Ghidra bounds |
|---|---|---|
| regions | 7 093 | **3 678** |
| memory operands | 122 902 | **111 179** |
| attributed | 14 787 (12.0 %) | **13 567 (12.2 %)** |
| `unreached` | 22 896 | **16 005** |
| `ret` (unresolved callee) | 5 776 | **146** |
| call sites resolved | 12 942 / 22 790 (57 %) | **26 504 / 26 787 (99.0 %)** |

The operand total *fell* 9.5 % because overlapping regions were double-counting code: a function's tail sat
inside the neighbouring heuristic "region" and was analysed twice, once as that region's `unreached` remainder.
The attributed **count** therefore fell with the denominator while the **rate** rose — which is the number to
quote.

The coverage figure is new and belongs in the record: **62.2 % of image bytes lie inside a known function**.
The other 37.8 % is data, padding, or code Ghidra did not identify — it is *not analysed*, and the census
total should be read with that in mind.

## Two layer-2 bugs the switch exposed

Both had been **fabricating provenance**, and both were invisible while the heuristic produced wrong region
extents.

1. **After a call I wrote the callee's parameter summary back into the caller's `a0`–`a3`.** Those registers
   are caller-saved: they are *clobbered* by a call, and a callee's `params` summary describes what the callee
   does with its argument — not what the caller holds afterwards. The write invented argument values that then
   surfaced at *later* call sites in the same function.
2. **`resolve` did not substitute inside a `paroff`.** A callee whose summary returns
   `(its param k) << 4 + base` left that form unchanged, so the **callee's** parameter index appeared at the
   caller's site labelled `param(a0)` — reading as the caller's own argument. That is the whole origin of the
   earlier, too-good-to-be-true line `a0=ret(80001180)` / `param(a0)<<4+0x80012150`.

`resolve` now substitutes in `paroff` too: a constant argument folds to an address, the caller's own
parameter is kept, and anything else degrades rather than pretending.

## What that does to acceptance test 1 — stated plainly

Test 1 previously reported `a0=ret(80001180)` at both call sites, and I recorded that as a pass. With the two
fabrications gone it reads:

```
stage2  80032a04 in 8003287c   a0=unk   a1=unk   v0=const(00000000)
stage2  80032a84 in 8003287c   a0=unk   a1=unk   v0=const(00000000)
```

The *structure* still holds and is verified from the instructions: `addu a0,s2,zero` at `0x80032a00` and
`0x80032a80`, with `s2 = v0` taken in the delay slot of the `jal` at `0x800329f0` — so the record pointer
**is** `cart_record`'s return, and the field reads inside `FUN_800327ec` are still `param(a0)` at
`+0x0/+0x4/+0x8/+0xc`.

What does not hold, and never did, is the implied *address*: the argument is `lbu a0,-0x10(v0)` — a byte
loaded from the slot map at runtime — so the record pointer cannot be a constant, and the honest provenance is
`unk`. **The earlier pass was partly an artifact of bug 2**, and it is retracted here rather than quietly
upgraded.

Test 2 is unchanged: `0x800329ec lbu base=800eb204+0+?`, `0x80032a5c lw base=800eb264+0+?`.

## Fixtures

**10/10** and **8/8**, untouched by the boundary switch — they call `analyse` with synthetic word lists, which
is exactly the isolation a fixture is for.

## Verify

```
python3 tools/provenance.py --self-test && python3 tools/provenance.py --self-test2
python3 tools/provenance.py --census                       # coverage line + buckets summing exactly
python3 tools/provenance.py --callers 0x800327ec
python3 tools/provenance.py --region 0x80032a5c --follow-pointers
```
