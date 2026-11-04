# M113 — `CONSTBASE`, and what acceptance test 2 actually proves

The last gap in the provenance analyser was expressiveness, not analysis: an address that is **a known base
plus an unknown offset** collapsed to `unknown`, throwing away the part that is known. `CBASE` fixes that, and
re-running acceptance test 2 with it changes what the test says.

## The new value kind

```
CBASE = (base, bias)      reported as "800eb204+0+?"   meaning: reads base + bias + an offset we cannot name
```

Formed only when the constant half actually looks like an address (`>= 0x80000000`), so `0x18000 + ?` is
still reported as unknown rather than dressed up as structure. It is never counted as *attributed* — an
address with an unknown term is not an address.

Ordering mattered and the fixture caught it immediately: the first version put the "constant + unknown" rules
*before* the `addu rd,rs,zero` move idiom, so `addu v0,a0,zero` became a parameter-derived address instead of
a copy, and **L2 went red** (4/6). That is the fixture doing its job — a rule added for one case silently
changed another, and the regression was visible in one run instead of months later.

## Acceptance test 2, re-run

```
$ provenance.py --region 0x80032a5c --follow-pointers
A 800329e4  lw   base=const(800f0000)   off=-0x4d9c      -> 800eb264     the pointer slot
  800329ec  lbu  base=800eb204+0+?      off=-0x10                        bank B's map byte read
  80032a5c  lw   base=800eb264+0+?      off=+0x0                         load through the pointer table
```

Read with the instructions at the site (`lw v0,-0x4d9c(v1)`; `addu v0,s1,v0`; `lbu a0,-0x10(v0)`), this is
now a **structural** answer:

* `0x800eb264` holds the **bank-B** map pointer, and the byte read is `0x800eb204 + index - 0x10`;
* `0x80032a5c` reads a pointer from `0x800eb264 + 4·index` — i.e. a **two-entry pointer table** at
  `0x800eb264`/`0x800eb268`, which is exactly the structure M91 established by hand (`s4 = s0 << 2`,
  selecting between the two maps);
* the index is `s1`, set by a `li` **inside a `beql` delay slot** (M112), so which bank is read depends on a
  runtime comparison — `s0 < 32` — and a constant *cannot* be claimed for it.

So the test passes in the form that was always meaningful — the site is located, the base is named, the
structure is the documented one — and the one hop it does not resolve is a genuine runtime property, not a
failure of the instrument. Stated precisely: **the address is `map_table + 4·(slot < 32)`, and `slot` is a
runtime byte.**

## Census, after the loader fix and layer 2

```
122 902 memory operands over 36 images
  attributed (const, reached)  12 412   10.1%
  param                        22 040
  ret                          11 368
  cbase                         2 823
  paroff                          100
  load                          2 695
  unk                          41 946
  unreached                    27 507
  unreached+const               2 011
```

The nine buckets sum to 122 902 exactly, and `attributed == const`. Attribution went from **1 293 (1.6 %) to
12 412 (10.1 %)** — a 9.6× increase, most of which is layer 2 plus the fact that the images are now read from
the right place. `unreached` fell from 57 585 to 27 507 for the same reason: with correct image bytes the
region splitter finds 7 093 regions instead of 436.

## Fixtures

```
provenance.py --self-test    10/10     step 1, unchanged since M111
provenance.py --self-test2    6/6      L1 return-constant, L2 param-through-return, L3 unknown callee,
                                      L4 shifted param, L5 likely delay slot, L6 const base + unknown
```

## What is left in experiment B

* **jump-table edges**: 27 507 operands sit in blocks with no provable entry, and the biggest producer is
  `jr v0` with a table-computed target — `find_jump_tables.py` already recovers those tables, and wiring its
  output in as CFG edges is the next concrete gain;
* **`unk` at 41 946**: mostly bases that came from a load; `--follow-pointers` narrows them but is opt-in for
  soundness reasons, and the honest next step is to report *how many* of them become `cbase` under the flag
  rather than to turn it on by default;
* nothing here needs the emulator, and nothing here touches the closed bank-C question.

## Verify

```
python3 tools/provenance.py --self-test
python3 tools/provenance.py --self-test2
python3 tools/provenance.py --census                      # buckets must sum to the operand total
python3 tools/provenance.py --region 0x80032a5c --follow-pointers
```
