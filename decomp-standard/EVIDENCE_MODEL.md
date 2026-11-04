# EVIDENCE_MODEL — claims, evidence, epistemic states, traceability

**Status.** This document is a **proposal**, with one exception marked in §2: the state vocabulary is
*reconstructed from* what the reference project already practises in prose (`decomp-standard/ARCHAEOLOGY.md`
§4–5). Everything normative below — the schema, the transition table, the invalidation mechanism — is proposed
and has **no implementation**. Nothing here has been executed. It is a specification to be validated, not a
description of working code.

The governing rule, taken verbatim from the reference project's `docs/VERIFICATION.md`:

> A result is admissible only if the gates that produced it have been shown to fail.

---

## 1. The problem this model solves

The reference project demonstrates that a rigorous individual can keep an evidence chain honest through 305
milestones and 53 recorded retractions. It also demonstrates the limit of doing so by discipline:
`decomp-standard/ARCHAEOLOGY.md` §6 lists **15 numeric claims that contradict the registry**,
every one of them surviving because the gate that guards that family of numbers was pointed at a different
sentence. The project has a retraction table; it does not have a *dependency graph*. A correction propagates
only as far as a human remembers to propagate it.

An evidence model is worth building only if it makes three things mechanical:

1. **State is a field, not a writing style.** A machine must be able to ask "which claims in this project are
   `INFERRED`?" and get an answer.
2. **Verification has a referent.** A claim becomes `VERIFIED` only by pointing at a reproducible procedure and
   its result — not by being described confidently.
3. **Invalidation is a query.** When an observation is corrected, the set of dependent claims must be
   computable, not recalled.

---

## 2. Epistemic states

Seven states are proposed. The first six are **derived from the project's existing prose vocabulary**, which is
worth stating because it means the model is a formalisation rather than an import:

| state | the project's existing word | meaning |
|---|---|---|
| `OBSERVED` | "measured", "read from the bytes" | a direct reading of the artefact or of a tool's output, recorded with enough context to repeat it |
| `DERIVED` | "derived" | a value computed from `OBSERVED` inputs by a stated, repeatable procedure |
| `INFERRED` | "reading", "inference" | an interpretation not entailed by the observation — a name, a role, a purpose |
| `HYPOTHESIZED` | "hypothesis", "candidate" | a falsifiable proposition with a named test not yet run |
| `VERIFIED` | — (the project says "gated", "pinned by a case") | a claim admitted by a passing procedure **whose mechanism has been shown to fail** |
| `CONTRADICTED` | "retracted", "superseded", "wrong" | a claim whose evidence was shown to be insufficient or incorrect |
| `UNKNOWN` | "unresolved", "not established", "unassigned", "refused" | the project has decided that the current evidence does not decide the question |

Two states the reference project uses that are **not** epistemic states and should not be modelled as such:

- `UNRUN` / `UNAVAILABLE` — a property of a *procedure*, not a claim (see
  [`VERIFICATION_STANDARD.md`](VERIFICATION_STANDARD.md) §4). A claim resting on an unrun procedure inherits
  `HYPOTHESIZED` or `UNKNOWN`, never `VERIFIED`.
- `SKIP` — a printed outcome of a suite, which is evidence that something did not run, not evidence about the
  target.

### 2.1 Why seven and not three

A minimal model would have *known / unknown / wrong*. That model cannot express the two distinctions the
reference project leans on hardest:

- **`INFERRED` vs `VERIFIED`.** The project's own ladder shows why this matters: 12 functions have their
  behaviour pinned by an executed experiment, and all 12 are *still* named `FUN_…`
  (`manifests/analysis_status.json`, `validated_unnamed: 12`). Behaviour is verified; the name is an inference.
  A three-state model collapses these into one and loses the project's most careful claim.
- **`CONTRADICTED` vs `UNKNOWN`.** `UNKNOWN` means "not decided". `CONTRADICTED` means "a position was held and
  is now withdrawn". The reference project keeps both, and keeps the withdrawn claim on record — including
  flip-flops where the same value was retracted twice in opposite directions
  (`docs/log/M194-*.md`, quoted in `ARCHAEOLOGY.md` §5.3).

A `HYPOTHESIZED` state is included because it is what makes pre-registration possible: a claim with a named
test and a stated expectation, published *before* the test runs, so that changing the expectation afterwards
is visible.

---

## 3. Claims and evidence

### 3.1 A claim

A claim is the atomic unit: one assertion about the target, with one state.

```
claim:
  id            stable identifier, never reused
  statement     the assertion, in a form that could be false
  subject       what it is about (artifact id, address/region, or a named entity)
  state         OBSERVED | DERIVED | INFERRED | HYPOTHESIZED | VERIFIED | CONTRADICTED | UNKNOWN
  evidence      [evidence-ref]        -- may be empty only for UNKNOWN
  method        how the state was reached (tool + version + arguments, or a human reading)
  scope         what population this is claimed over, stated as a bound
  does_not_say  explicit non-entailments
  superseded_by claim-id | null
  supersedes    [claim-id]
```

Two fields are load-bearing and are usually missing from such schemas:

- **`scope`** — the reference project states bounds explicitly and this is why its negative results are
  reusable: "three rooms were observed, not all rooms … Proving absence everywhere would need a capture per
  room" (`docs/handover.md`). A claim without a scope is a claim about everything.
- **`does_not_say`** — several notes carry a "What this does not say" section as a matter of course. Encoding
  non-entailment is what stops `A` from being silently promoted to `A and B`.

### 3.2 Evidence

Evidence is what a claim points at. Five kinds cover everything observed in the reference project:

| kind | payload | example in the reference project |
|---|---|---|
| `byte_range` | artefact id, offset, length, sha256 of the slice | a function body at `0x800243d0..0x80024557` |
| `tool_run` | tool id, version, argv, environment, exit status, stdout/stdout hash | `python3 tools/verify.py --full` → `PASS` |
| `artifact` | committed file, sha256, the producing tool | `manifests/byte_map.json` |
| `execution` | harness id, input state digest, output state digest, what was stubbed | `checkpoint/run_digest.json` |
| `source_reading` | a human reading: file, line span, the quoted text | a pseudocode body in `src/` |

The fifth kind is unavoidable and must be **named as the weakest**, not hidden. The reference project does
exactly this: "Do not mark anything verified without executable evidence. A code reading that cannot be
executed is labelled a reading, and pinned by source-shape cases if it is claimed"
(`docs/VERIFICATION.md`). `source_reading` evidence can support `INFERRED`; it can support `VERIFIED` only
when a case pins the shape it relies on.

### 3.3 What counts as verification

A claim reaches `VERIFIED` only when all five hold:

1. There is a **procedure**: an executable check, committed, with a stable invocation.
2. The procedure has a **case aimed at this claim**, not at a neighbouring one.
3. The procedure **ran and passed**, in a recorded run with the inputs identified by hash.
4. The procedure's mechanism has been **shown to fail** when disabled — the mutation requirement, without
   which a passing check is worthless (`VERIFICATION_STANDARD.md` §5).
5. The record states what the case does **not** cover.

Clause 2 is where most "verified" claims in the wild fail. The reference project has a named instance: a
suite whose mutation graded a check by searching its output for the word `FAIL`, so a check that printed
`FAIL` on purpose was green no matter what — five audits unconditionally passing while one caught nothing.

---

## 4. Transition rules

State changes only along these edges. Anything else is an error, not a judgement call.

| from | to | condition |
|---|---|---|
| `HYPOTHESIZED` | `OBSERVED` / `DERIVED` | the named test ran; record the result as new evidence |
| `HYPOTHESIZED` | `CONTRADICTED` | the pre-registered test ran and failed — **the hypothesis is not edited to fit** |
| `OBSERVED` / `DERIVED` | `VERIFIED` | a gated case passes and its mutation is detected |
| `OBSERVED` / `DERIVED` / `INFERRED` / `VERIFIED` | `CONTRADICTED` | new evidence defeats it; record which evidence, and keep the old claim |
| `INFERRED` | `VERIFIED` | only via a case that pins the inference, never by repetition or by confidence |
| `INFERRED` | `UNKNOWN` | the interpretation is withdrawn without a replacement — a legitimate and undervalued move |
| `CONTRADICTED` | `VERIFIED` | only as a **new claim** that supersedes the old one; the old claim stays `CONTRADICTED` |
| any | `UNKNOWN` | the evidence is found not to bear on the question |

Forbidden, and each is forbidden because the reference project caught it happening:

| forbidden edge | the instance |
|---|---|
| `INFERRED` → `VERIFIED` by documentation | the project's rule: naming needs evidence of its own; 12 validated functions stay unnamed |
| `HYPOTHESIZED` → `VERIFIED` by a passing test with no mutation | 49 mutations that never ran, and an audit that matched the word "FAIL" |
| `CONTRADICTED` → deleted | retractions are preserved, including flip-flops |
| `OBSERVED` → `OBSERVED` with a changed value | a value may change only through `CONTRADICTED` + a superseding claim, so the change is visible |
| `HYPOTHESIZED` expectation edited after the result | pre-registration exists precisely to make this visible |

### 4.1 The expectation-freeze rule

When a claim is registered `HYPOTHESIZED`, its stated expectation and its test are immutable. If the test
contradicts the expectation, the expectation is **not** corrected in place; the hypothesis becomes
`CONTRADICTED` and a new claim carries the corrected expectation.

The reference project does this well enough to be the worked example, and one of its notes records the exact
value: the provenance acceptance test's expectation was corrected from `ret(80001180)` to `unk` with the
reason recorded, and the earlier value is described as "a labelling artifact"
(`docs/format_notes.md`; `tools/provenance.py --acceptance`). Whether that edit was *visible at the time* is
not established from the files — which is itself the argument for making it mechanical.

---

## 5. Traceability and invalidation

This is the part with no counterpart in the reference project, and therefore the part most in need of
scepticism.

### 5.1 The dependency edge

Claims depend on claims and on evidence. Both edges are needed:

```
claim A --depends_on--> claim B          A is only as good as B
claim A --supported_by--> evidence E     E is what A points at
```

A claim's effective state is the **minimum** over its dependencies, where the ordering is

```
CONTRADICTED < UNKNOWN < HYPOTHESIZED < INFERRED < OBSERVED < DERIVED < VERIFIED
```

with one override: if any dependency is `CONTRADICTED`, the dependent claim is at most `UNKNOWN` — it cannot
remain `VERIFIED` on the strength of a defeated input.

This ordering is a **proposal**, and it is the least certain element in this document. Two objections are
real and should be recorded rather than resolved:

- `OBSERVED` below `DERIVED` is arguable. A direct reading is not obviously weaker than a computation from
  readings.
- A total order over states may be the wrong shape entirely. `VERIFIED` is not "more true" than `OBSERVED`;
  it is *differently supported*. A partial order (a lattice with `CONTRADICTED` as bottom and no single top)
  is probably more honest. This is listed as open question **Q2** in [`OPEN_QUESTIONS.md`](OPEN_QUESTIONS.md).

### 5.2 Invalidation is a closure query

When an observation is corrected:

1. Mark the original claim `CONTRADICTED` and record the correcting evidence.
2. Compute the transitive closure of `depends_on` edges **reversed** — everything that rested on it.
3. Demote each dependent claim per §5.1, and mark it "needs re-derivation".
4. Create a new claim for the corrected value, and link it with `supersedes`.
5. Regenerate every artefact that was `DERIVED` from the old value.

Step 5 is where the reference project's incidents live. Two worked cases from its own record:

- A coverage figure was one 4-byte word too high per function body, quoted from M84 to M177 and in the
  README — **93 milestones** — because nothing recomputed it. When it was finally corrected, the same `+4`
  was found in 3638 `.c` headers and in two other tools.
- The published instruction-length count was 15 while the committed profile held 17 "all along"; the
  published figure was "the count of advances it published, not the count in the code".

In both cases the artefact was right and the derived claim was stale. A closure query over `DERIVED` edges
finds these mechanically, which is the entire argument for the model.

### 5.3 What invalidation must not do

- It must not delete the superseded claim (the reference project's most disciplined habit).
- It must not silently change a published value. A changed value appears as `CONTRADICTED` + supersession, so
  a diff shows both.
- It must not lower a gate's expected count as a side effect. In the reference project this is a separate,
  explicit act with its own flag, and the reason is recorded: "Do not lower a number to make a run green."

---

## 6. Corpus-scale practicalities

The reference project has 3416 functions and 111 179 recorded memory operands. A per-claim JSON object for
every one is neither necessary nor useful. Three granularities are proposed, and the model should state which
is in use:

| granularity | unit | when |
|---|---|---|
| **claim** | one assertion | anything published, retracted, or depended upon |
| **census** | a table of same-shaped facts with one method | per-function facts whose method is shared, e.g. "every body extent came from the provider index" |
| **aggregate** | a derived count over a census | every published number |

The reference project already works this way in effect: `manifests/analysis_status.json` is an aggregate over
a census, with the *rules* published alongside the totals. The proposal is to make the census explicit and to
give the aggregate a dependency on it, so that a correction to one function's extent flags the aggregate
rather than waiting for someone to notice.

**Scale estimate, so the cost is not hand-waved:** at the reference project's size, the claims that would
need individual objects are the ones in the milestone record that carry a number — approximately 250
milestone findings plus the 53 retractions. That is a small graph. The 3416 function bodies and 111 179
operands stay as censuses. **This estimate is INFERRED from counting rows, not from building the graph.**

---

## 7. What this model deliberately does not do

- **It does not infer truth from agreement.** Two tools agreeing is evidence, not proof; the reference
  project's own rule is "two independent paths, or it is not established", which is a *requirement for
  independence*, not a vote count.
- **It does not encode confidence numerically.** The reference project grades call-graph edge confidence on a
  six-value scale (1.0/0.9/0.8/0.7/0.5/0.0) and that is appropriate *within an artefact*, where the scale has
  a documented meaning per value. A global numeric confidence invites arithmetic that means nothing.
- **It does not replace prose notes.** The notes carry the argument; the model carries the index. A project
  that replaced its notes with a graph would lose the thing that makes the reference project readable.
- **It does not require the target to be a game, a console, or a binary.** See
  [`SPECIFICATION.md`](SPECIFICATION.md) §1 for what a reconstruction project is.

---

## 8. Minimum viable form

If only part of this is built, build the part that pays for itself first. **Proposal**, ordered by
value-per-effort, with the evidence for the ordering:

1. **`scope` and `does_not_say` as required fields.** The reference project already writes both, by hand,
   everywhere. Making them required costs nothing and is the highest-value change.
2. **A machine-readable claim index** covering published numbers only (~250–300 objects). This is what catches
   §3.2's 15 contradictions, because each becomes a claim with a `supported_by` edge to one artefact, and two
   claims over one quantity with two values is detectable.
3. **A cross-site consistency check per named quantity.** Cheaper than the graph, and it directly addresses
   the measured failure: one quantity, one value, every quoting site asserted against it. The reference
   project's `tools/counts.py` is 90 % of this; it needs the missing "every site" rule, not a new design.
4. **The dependency graph and closure query.** Highest ceiling, highest cost, and the only part with no
   working precedent to copy. Do this last, and only after 1–3 have run for a while.

Items 1–3 are the recommendation. Item 4 is deliberately deferred — see
[`ROADMAP.md`](ROADMAP.md) and the "do not build yet" list in [`EXECUTIVE_REPORT.md`](EXECUTIVE_REPORT.md).
