# M288 — the index regenerated: 224 "functions" were the provider's own switch cases

The instruction was to regenerate `manifests/code_index.json` after the family work. Doing it turned up the *cause* of
the defect M285/M286 found from two directions, and it is not a heuristic failure — the provider had been labelling these
bodies correctly all along and the projection was overriding it.

## 1. The defect, quantified

`build/decomp/*/decompile-index.json` names a jump table's case bodies

```
switchD_80036ff0::caseD_0 … switchD_80036ff0::caseD_5      (and ::default, and caseD_a/caseD_b for >9)
```

**224 of the corpus's 3 638 entries** carry that label, all in stage-2. They are reachable only through the table their
owner dispatches on. Two things then promoted them to functions:

1. `build/seeds/<image>.tsv` names **0x8006e6e0** as `FUN_8006e6e0`, and
2. `export_src.py` preferred the seed name over the provider's: `name = seeds.get(addr) or e["name"]`.

So a naming aid silently outranked the provider's statement about *kind*. The seeds were not wrong to contain the
address — a seed is a name, not a classification — but the projection had no way to keep the two apart.

## 2. The fix, in the projection rather than in the artefact

`export_src.py` now classifies from the provider's label, before the seed override:

```python
FRAGMENT = re.compile(r"^switchD_([0-9a-f]{8})::(?:caseD_[0-9a-z]+|default)$")
```

A match is a **switch-case fragment**: its pseudocode is still written — under `src/<image>/switch/`, with its body,
size, sha256 and provenance unchanged — but it is not a function. It is not in `functions_list`, not in the function
count, not namable by a seed. Concretely:

| | before | after |
|---|---|---|
| functions | 3 638 | **3 414** |
| switch-case fragments | (counted as functions) | **224**, under `src/<image>/switch/` |
| body ranges | 3 678 | 3 678 (unchanged) |
| covered bytes | 1 210 600 | **1 210 600** (unchanged — a case body is code) |
| coverage | 62.2 % | 62.2 % |
| `F0` / `F1` / `F2` / named / validated | 3638 / 3638 / 3551 / 34 / 12 | **3414 / 3414 / 3327 / 33 / 12** |
| call graph | 3 638 nodes | **3 414 nodes**, 15 535 edges |

The split matters for the same reason M286 gave: the map, the coverage figure and the analysis ladder are three
different claims, and a case body is code that is neither a function nor unclaimed. Keeping the fragments in the tree
and in the byte totals, while removing them from the function list, is the only arrangement where all three stay true.

## 3. What the regeneration pulled with it

Four derived artefacts had to move, and each one is a gate that caught the change rather than a number I edited by hand:

- `src/INDEX.md` — rewritten by the projection (3 414 functions);
- `manifests/analysis_status.json` — re-derived (`F0` 3 414 … `F2` 3 327);
- `manifests/call_graph.json` — re-derived from the new node set;
- `tools/counts.py` — the byte-sum case now reads **functions + fragments** (its glob covers `src/*/switch/*.c`), and
  a new `fragments` metric comes from the index, because excluding case bodies from the sum would have under-reported
  coverage by exactly their bytes;
- `tools/analysis_status.py` — the hardcoded `== 3638` became a derivation from the index, so the same regeneration
  cannot need a code edit next time;
- `tools/audit_gates.py` — one mutation's anchor pointed at the line in `counts.py` that changed; the lint-self-test
  caught it (`anchor not found`), which is the mechanism working;
- `fixtures/gates/ratchet.json` — re-baselined, because `src/`'s tree hash changed when 224 files moved. The ratchet
  refused to lower any suite count (none did), so this was a `--write` and not a `--allow-decrease`.

Final state: **`VERDICT PASS-FAST`**, counts 25/25, markers 22/22, ratchet 4/4, analysis status 7/7, call graph 8/8,
audit lint 4/4.

## 4. What this does *not* fix, and the next step

`0x8006e68c` and `0x8006e574` — both proved byte-exact — are **still invisible to the index**, and now for a cleaner
reason than before: the provider never split them at all, so removing the seven arm entries that *were* indexed leaves
that region entirely unclaimed. The index cannot invent a boundary the provider never drew, and the honest fix is not a
heuristic inside the projection but a **committed record of what we have proved**: a
`fixtures/decomp/recovered.json` naming each recovered function's address, extent and the probe case that pins it, which
the projection adds as functions the provider missed. Every entry there would be backed by a byte-exact reconstruction,
which is stronger evidence than any boundary walk — and it would let the progress map show twelve of twelve instead of
ten.

That is the next milestone. It is deliberately not folded in here: this one was about the artefact being wrong about
224 bodies the provider had already labelled, and mixing in a new evidence class would make it impossible to say which
change moved which number.
