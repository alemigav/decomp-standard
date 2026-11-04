# M114 — jump-table edges: 4 142 new edges, and the `unreached` bucket finally moves

`jr v0` was a dead end for the dataflow: no edge, so every block behind a table was `unreached`. The table is
only visible *after* the load that indexes it resolves, so the CFG and the dataflow now iterate together.

## Mechanism

1. A new value kind `JTENT(table)` — a word loaded through a **known base + unknown index** is *one entry of
   the table at that address*. That is what `cbase` was missing: the load's address is unknown, but which
   table it reads from is not.
2. At an indirect jump (`jr`/`jalr`) whose register is `JTENT(table)`, the table is walked: up to 512 entries,
   stopped at the first non-address word after at least one valid entry (so a case table of plain constants
   yields nothing rather than a wrong edge).
3. Those entries become **CFG edges** — and, this was the bug, **block leaders**. Edges pointing at indices
   that are not block starts are silently dropped, which is exactly what happened first: 951 tables walked,
   zero edges in effect.
4. CFG and dataflow are iterated up to four rounds until a round discovers nothing new.

## Measurement, before and after

```
                                before      after
unreached                       27 507     22 896     -4 611
attributed (const, reached)     12 412     14 319     +1 907   (11.7 % of operands)
total memory operands          122 902    122 902     (unchanged — the identity still holds)

indirect jumps through a table      2 853
tables walked                       1 237
entries inside the region           4 142   -> usable as CFG edges
entries outside the region         25 749   -> handlers that are their own region, already analysed
unresolvable tables                   610
```

The 25 749 cross-region entries are the honest reason `unreached` did not collapse: most tables in this
cartridge dispatch to **other functions**, which are analysed as their own regions anyway. What those edges
buy is a table-driven call graph, not intra-region reachability. The 4 142 in-region entries are the ones that
paid off.

## Acceptance tests, re-run as instructed

* **test 1 passes**, and gained a fact: the caller-side `a0`/`a1` at both call sites is still
  `ret(80001180)`, and `FUN_800327ec`'s own return now resolves to **`const(0)`** — consistent with M85/M86's
  "the inflate return is never checked"; the failure path returns 0.
* **test 2 unchanged**: `0x800329ec lbu base=800eb204+0+?` and `0x80032a5c lw base=800eb264+0+?`. The bank
  selection is still `slot < 32`, a runtime byte.

## Bugs found this step

* **Discovered targets were not made block leaders.** `build_cfg` links successors only to indices that are
  block starts, so every table edge pointed at a non-existent block and was discarded — the mechanism ran,
  counted 951 tables, and changed nothing. Found by fixture **L7** (three handlers reachable only through a
  table), which failed while its three handler accesses were individually attributed but marked `unreached`:
  the signature of "the edge exists and reaches nothing".
* **The census path never populated the image bytes.** `--region` resolved tables and `--census` did not, so
  the first measurement read `951 tables, 0 entries, 951 unresolvable`. That looked like "the tables are
  runtime-built" (which would have been a plausible, wrong conclusion) and was a missing initialisation in one
  of two code paths. Now one `load_image_bytes()` serves both.
* **`--callers` filtered on the callee's resolved return value** instead of on the call's target, so it went
  silent the moment the return resolved. `Access` now carries `call_target` and the filter uses it — a report
  about *where a call goes* must not depend on what it computes.

## Fixtures

```
provenance.py --self-test    10/10
provenance.py --self-test2    7/7      L1 return-constant, L2 param-through-return, L3 no summary,
                                       L4 shifted param, L5 likely delay slot, L6 const base + unknown,
                                       L7 jump-table handlers reachable
```

## What remains

`unk` at 42 879 and `param` at 22 916 are now the two largest buckets, both meaning "a base whose origin is
outside what this analysis follows" — parameters that no caller pins to a value, and bases loaded from memory
without `--follow-pointers`. Neither is a bug; both are the boundary of static provenance on this code.

## Verify

```
python3 tools/provenance.py --self-test && python3 tools/provenance.py --self-test2
python3 tools/provenance.py --census                      # jump-table line + the 9 buckets summing exactly
python3 tools/provenance.py --callers 0x800327ec          # test 1
python3 tools/provenance.py --region 0x80032a5c --follow-pointers   # test 2
```
