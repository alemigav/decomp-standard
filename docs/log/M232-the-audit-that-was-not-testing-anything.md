# M232 — the audit was not testing anything: 49 of 132 mutations were never run

The task was small and concrete: M231 widened `head_index.py`'s constant fold in five ways (a bare `lui`, two
constants added, depth 3 → 6, `sp` as a base, `addu rd,rs,zero` as a move) and gave the widening **no mutation
anchors**, so `audit_gates.py` could not show those paths were load-bearing. Three older `head_index` anchors
still passed because the fold widened *underneath* them — a head that used to be `local` simply moved to
`global`, and each mutation kept failing for its original reason.

That is what I set out to fix. What I found is that **the `head_index` anchors were not failing for any
reason at all**, and neither were 46 others.

## 1. The five anchors, and the first one I tried to prove

Five anchors were written, one per widening, each aimed at the mechanism rather than the spelling. Before
trusting them I ran one through a throwaway copy by hand — and it failed with a `FileNotFoundError`, not a
`FAIL`:

```
FileNotFoundError: .../gate-audit.xxx/manifests/head_index.json
```

`build_env()` copies a **hand-grown list** of artefacts into the sandbox: `tools`, `fixtures`, `docs/log`,
`.github`, four documents, and five `manifests/*.json`. `manifests/head_index.json` is not on it. So
`head_index.py --check` died before reaching a single case, exit 1 read as "the mutation was caught", and
`run_audit` reported **PASS**. Measured: **all three** M230 anchors had been passing that way since the day
they were written.

## 2. The control that should have existed from the start

The lesson is not "add the file". The list had already been grown by hand seven times — each `COPY_FILES`
entry is one of them, and this file's own comments name the count — and it was wrong again each time. The
mechanism was missing, not the entry.

`run_audit` now runs the **unmutated** tool in the sandbox first. If that fails, the audit is reported
**BROKEN** ("the unmutated tool already fails in the sandbox, so nothing is judged") and no verdict is given.
A missing input and a caught mutation look identical from an exit code; the positive control is what tells
them apart, and it costs one extra run per audit.

My first version of the control ran *after* the mutation was written, so it graded the mutated tool and
reported **every single audit** BROKEN — 50 lines of it, which is how I noticed. Order matters: control,
then mutate.

## 3. What the control found

First run with the control in the right place: **117 of 132** passing, **13 broken**, **2 vacuous**.

| cause | audits | fix |
|---|---|---|
| `manifests/` not copied (only 5 of 26 artefacts were) | 39 | copy the **directory**, not a list |
| `build/decomp/` not linked (`census`, `call_graph`, `counts`) | 5 | added to `LINK` |
| `.venv` not linked (`voice_sweep` looks for `unicorn` in `./.venv/bin/python`) | 2 | added to `LINK` |
| derived counts drifted (`counts` asserts README/handover/ci.sh/workflow) | 8 | re-derived: 884 → 887 cases, 127 → 130 audits, 611 → 614 gated |

So the honest history is: **49 of the 132 audits that reported PASS had never run their mutation.** They span
M184–M231 -- the whole sound arc and the whole vector arc -- and every one of them reported green in the
milestone that added it. `127/127, 0 vacuous` was published in M230 and M231, in the README and in the
handover. It was wrong for exactly the reason the tool exists to catch.

The 8 `counts` failures were genuine and mine: five new anchors change `len(AUDITS)`, and `counts.py` derives
that number into twelve places.

## 4. Two mutations that were provably no-ops, and one dead branch

With the sandbox fixed, two audits came back **VACUOUS** — they pass with their mechanism disabled. Both were
claims that cannot be tested on this image, and one of them was a claim I made last milestone.

**`rsp_decode`, the `vt_elem`/`vd_elem` lane borrow.** Every one of this program's eight single-lane words
carries `vt_elem = 12`, so `msb = 3` and the rule reduces to `(((vd_elem >> 3) << 3) | (vt_elem & 7)) & 7` —
in which the trailing `& 7` masks away every bit the borrow could contribute. Neither half of the ternary can
change an answer. I re-aimed the mutation at the other half, and it was *still* a no-op; that is when the
arithmetic above made it obvious. M225's own case label already said the branch "is exercised by 0 of them, so
the gate does not prove it" — the anchor contradicted the case it was guarding. There is now no anchor for
that expression, and a comment saying why.

**`head_index`, `addu rd,rs,zero` move propagation.** M231 claimed "six of the last nine `local` heads are
exactly this — the head's base is a callee-saved copy of an argument". Instrumented, the branch is taken
**zero times** by all 86 heads, and deleting it leaves the classification *identical*: `local` 4,
`argument` 16, `global` 32, unchanged. So the six heads M231 credited to the move were resolved by the other
widenings, and the branch was dead code from the moment it was written. It is deleted rather than kept with a
comment, and the attribution is retracted.

Two rounds were needed to learn this (first I aimed at the commuted branch, `addu rd,zero,rs`, which this
image never emits). The positive control said VACUOUS on the first try; a hand-run would not have.

## 5. The result

```
130/130 audit case(s); 0 vacuous, 0 broken        (was 127/127 with 49 of them unrun)
```

- **+5 anchors** for M231's five widenings — bare `lui`, two constants, depth 6, `sp`, and (removed, see §4)
  the move.
- **+2 sandbox links** (`build/decomp`, `.venv`) and **one directory copy** in place of a five-file list.
- **−2 vacuous anchors**: one deleted with its dead branch, one replaced by a comment that states the
  arithmetic.
- Every one of the 130 is now proven to fail *for the reason it names*, on a sandbox where the same tool
  passes unmutated.

Cost: the run doubles, 3:20 → 6:54 on this machine. That is the price of the control, and it is the only
thing standing between "the check failed" and "the check could not start".

## What is still not claimed

- The positive control proves a tool *runs* in the sandbox; it does not prove the sandbox carries every
  input a mutation might need. A tool that silently degrades on a missing optional file would still pass.
- The `addu` move branch is gone, so `_base_origin` now refuses that shape outright. If a future image emits
  it, the refusal is correct and visible (`local`), not silently wrong.
- The two `unknown` heads M230 could not resolve are unchanged: their index is written before the head's own
  code, and that needs the enclosing function's dataflow.
