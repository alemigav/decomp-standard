# M209 — "3 638 decompiled" is one claim; here are the four that are not it

The corpus publishes a single number and the plan's Track B says why that is not enough: a function can be
indexed, decompiled, mechanically connected, named and behaviourally validated, and those are five different
facts. `tools/analysis_status.py` publishes them — and the data immediately disproved the first model I built.

## 1. The model, and the thing it got wrong

First draft: a single ladder F0 → F4, each rung requiring the one below. It produced **F4 = 0**, because F4
required F3 (a curated name) and every function this project has *executed* is still called `FUN_…`. The model
was wrong, not the data: the plan itself says name, types and behaviour carry separate confidence, and the
project's own rule is that a name needs evidence of its own.

So: **ladder** (cumulative, same kind of evidence) plus **two independent axes**:

| | rule | count |
|---|---|---:|
| F0 indexed | in `manifests/code_index.json` | **3 638** |
| F1 decompiled | `src/<image>/<name>.c` exists, provider says `written` | **3 638** |
| F2 connected | every call target in its body resolves in corpus | **3 551** |
| named | the name is curated (`config/symbols.tsv`), not `FUN_`/`func_` | **34** |
| validated | a gate or an executed experiment pins its behaviour | **12** |

And the number that is the point of the whole milestone: **all 12 validated functions are unnamed.** The project
has executed the voice synthesis, the sample loader, the chain walkers and the loop arithmetic against the
cartridge, and not one of them carries a name, because naming is a separate evidentiary act.

## 2. What the residue is

* **87** functions still have at least one unresolved call target — the frontier where a table, a callback or a
  register-computed target has not been traced;
* **3 604** are unnamed;
* **12** are validated but unnamed.

None of those is a failure; each is a queue with a size, which is what the plan asked for instead of one
percentage.

## 3. The gate

Seven cases: F0 = 3 638; the ladder monotone; every F2 has zero unresolved targets; every named function has a
curated name; validated is non-empty and each entry names its evidence; the residue is published; and the
committed manifest equals a fresh derivation.

The rules are graded against the **fresh** derivation, not the committed file, so a mutation to a rule fails
with that rule's own label instead of being shadowed by the drift case — a shadowing that happened on the first
run and is now structural. Mutations: every function counts as named (the curated-name case fails, 3 604
violations); the validated axis never set (the evidence case fails).

README carries one derived sentence quoting all three numbers, asserted by `counts.py`.
