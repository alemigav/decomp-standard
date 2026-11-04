# M215 — a call graph whose edges carry their evidence, and whose unknown targets stay unknown

`manifests/call_graph.json`: 3 638 nodes, 15 568 edges, 2.62 MiB, and one gate that reconciles the direct-call
slice exactly against the corpus's own `callees` on all 3 638 functions.

## 1. What it holds

| kind | edges | confidence |
|---|---:|---|
| `jal` (direct call) | 14 669 | 14 213 at 1.0; 456 at 0.5 — the site is outside every body, so the call is real and its owner unknown |
| `table-dispatch` | 400 | 98 at 0.7 (a table with an authoritative bound); 302 refused at 0.0 |
| `jalr-resolved` | 382 | 0.0 — the site is a `jalr`, the target is not statically determined |
| `callback` | 111 | 0.8 — a static function pointer in a data word |
| `tail` | 6 | 1.0 |

516 table bases: **266 bounded** (235 from `manifests/jump_tables.json`, 31 from `tools/routine_index.py`) and
**250 unbound**. An unbound table contributes one edge with `dst: null` and `confidence: 0.0` naming the base —
never a guessed list of entries.

**Node identity is `image:address`.** The corpus holds 3 638 functions at only 3 487 distinct addresses, because
28 overlays load at `0x80161cf0`; an address-keyed graph would merge their edges silently. That is the whole
reason the schema carries the image in the id, and it is one of the gate's cases.

## 2. Three findings from building it

* **`code_index.callees` is exact, but only over the provider's claimed range list.** 22 functions have a gap
  between body ranges; a contiguous `addr..addr+size` scan attributes calls to them wrongly. The graph therefore
  reads `body.ranges`, and that is what makes the reconciliation 3 638/3 638 instead of 3 616/3 638.
* **`jump_tables.json` and `routine_index.py` describe disjoint table sets.** The former's 241 `declared_cases`
  bound `lw`+`jr` *switch* blocks (case code inside one function); the latter bounds the `jalr` *call* tables.
  A graph that took either as the authority for both would bound the wrong thing — 9 bases appear in both, and
  no `jalr` base is bounded by `jump_tables.json`.
* **A pointer table cannot be bounded by shape here.** Walking `0x8011afb8` until the words stop looking like
  code addresses yields 46 entries where M173 established 14: past-the-end words are still valid code addresses.

## 3. The gate

Eight cases: ids unique and image-qualified; every edge carries a `site`; `dst` is null exactly when confidence
is 0.0; the `jal` slice equals `code_index.callees` for every node; every table's `entries` respect its cited
bound and every edge's table appears in the ledger; the artefact is under the repository's 4 MiB limit; and the
committed file equals a fresh derivation.

Two mutations, each verified to fail with its own message: empty the `callees` read (the reconciliation case
reports 3 638 mismatches), and drop the image qualifier from node ids (the artifact no longer reproduces, because
the colliding overlays merge).

## 4. Not claimed

`jalr` targets are not resolved. 250 of the 516 table bases have no authoritative bound, and the artifact says so
per base rather than padding the graph with plausible entries — the "no count inflation" rule applied to edges.
