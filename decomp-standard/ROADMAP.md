# ROADMAP — incremental implementation

**Status.** A **proposal**, ordered by value per unit of effort. Every step names the measured defect or
demonstrated practice that justifies it. No step has been started.

The governing constraint, from the evidence: **only 9 of 102 files in the reference implementation are reusable
as code, and none of them is a high-value methodological component**
([`EXTRACTION_MAP.md`](EXTRACTION_MAP.md) §11). The roadmap is therefore weighted toward **schema, checks and
documentation**, and away from building a framework.

---

## 0. Sequencing principle

Three rules, each earned by a specific failure:

1. **Fix a measured defect before generalising anything.** The reference project has 15 claims that contradict its
   own registry (14 in documents, one inside a committed artefact) and two committed values for one quantity.
   Generalising an unreconciled metric would institutionalise the defect.
2. **A new check is not landed until its mutation is detected.** The alternative produces gates that cannot
   fail, which is the reference project's most expensive recurring defect (six documented instances, one of them
   49 mutations that never ran).
3. **Do not build the dependency graph first.** It is the highest-ceiling component and the only one with no
   working precedent; steps 1–3 deliver most of its value at a fraction of the cost.

---

## Phase 0 — Reconcile, before proposing anything

**Effort: small. Value: highest, because everything after this step is built on numbers that currently disagree
with themselves.**

| # | step | why | done when |
|---|---|---|---|
| 0.1 | **Give every published quantity an identity**, and one derivation. Where two artefacts measure the same concept (the 656 B case), either reconcile them or record the documented transformation between them. | measured: two committed values for "bytes inside a known function body"; no gate can notice | one identity, one value, the transformation documented or the difference eliminated |
| 0.2 | **Extend the documentation gate from phrases to quantities.** For each named quantity, assert **every** quoting site. | measured: 14 stale figures, including two in the file that makes CI run, one eleven lines from a gated number | a stale figure anywhere fails the gate |
| 0.3 | **State each denominator and each deduplication rule in the document that quotes it.** | measured: `tools/` is 100 or 102 depending on whether the count is recursive; `docs/log/` holds 229 files, 228 note numbers, 227 cited | every count that can be read two ways says which one it is |
| 0.4 | **Fix the docstring/import drift** (`tools/recovered.py` claims a consumer that does not import it). | read: the claim is false of the code | the docstring and the code agree |

Phase 0 touches no new abstraction. It is repair work on a project that is otherwise in good order, and it is a
precondition for asking anyone to adopt a metric standard from it.

---

## Phase 1 — Make the record machine-readable enough to query

**Effort: small–medium. Value: high. This is the step that delivers most of what the dependency graph promises.**

| # | step | deliverable |
|---|---|---|
| 1.1 | **A claim index** for published numbers only — approximately 250–300 objects, not 3416. Fields per [`EVIDENCE_MODEL.md`](EVIDENCE_MODEL.md) §3.1. | one JSON file |
| 1.2 | **`scope` and `does_not_say` as required fields.** The project already writes both by hand, everywhere. | schema + backfill |
| 1.3 | **A `state` field** using the seven proposed states, backfilled from the prose vocabulary the notes already use (`measured`, `reading`, `inference`, `not established`, `unassigned`, `refused`, `superseded`). | schema + backfill |
| 1.4 | **A refusal census** — collect the `refuses` / `unresolved` / `not_claimed` / `rsp_only` fields already present in six manifests into one view. | one derived report |
| 1.5 | **A check that the index and the artefacts agree**: every claim's `supported_by` resolves; every derived value matches its artefact. | one gate + one mutation |

**Why the index is small on purpose:** at this project's size, the claims that need individual objects are the
ones carrying a number in the milestone record. The 3416 function extents and 111 179 operands stay as censuses.
**This estimate is inferred from counting rows, not from building the graph** — and step 1.1 should be
time-boxed to falsify it cheaply.

**Explicitly not in Phase 1:** dependency edges and closure queries. See §6.

---

## Phase 2 — Extract the reusable contracts as schema

**Effort: medium. Value: high. The deliverable is documentation and JSON Schema, not code.**

| # | step | deliverable | evidence it formalises |
|---|---|---|---|
| 2.1 | **Schema for the seven L1 records** — artifact, region inventory, census, claim, evidence ref, run record, refusal | JSON Schema + a worked instance each from the reference project | `EXTRACTION_MAP.md` Part 10; the existing manifests |
| 2.2 | **Schema for the provenance header** on a corpus file | schema + the 3590 existing headers as instances | the four-field `.c` header |
| 2.3 | **Schema for a checkpoint** — state snapshot + digest over its own contents | schema + `checkpoint/` as the instance | `checkpoint/run_digest.json` |
| 2.4 | **A conformance checklist** for V1–V14, each item naming the artifact that would demonstrate it | one page | [`VERIFICATION_STANDARD.md`](VERIFICATION_STANDARD.md) §6 |
| 2.5 | **A metric-identity registry format** — id, definition, denominator, exclusions, derivation, non-entailment | schema + 11 instances | the eleven dimensions |

**What Phase 2 does *not* do:** write a core. See [`ARCHITECTURE.md`](ARCHITECTURE.md) §6 for why the case
against building one is currently the stronger case.

---

## Phase 3 — Extract the two mechanisms with the strongest evidence

**Effort: medium. Value: high, and it is the only Phase where code is justified — because these two components
are the most target-neutral in the project and they are cheap to lift.**

| # | step | why this one | risk |
|---|---|---|---|
| 3.1 | **Lift the mutation harness** (`run_audit`): sandbox, positive control, exact replacement, judge by exit status **and** verdict tally, report detected/vacuous/broken | it has no domain content; it is the sharpest test of any boundary | anchors are target text, so the harness must be parameterised by a mutation *set*, not contain one |
| 3.2 | **Lift the adjudicator** (`adjudicate()`): the branch order, as a pure function with its self-test | pure, small, and the doctrine in executable form | must not acquire a procedure list; procedures are configuration |
| 3.3 | **Lift the worktree certificate** (`hook_cert.py`) | already generic; two-call API | none identified |
| 3.4 | **Give each lifted component the reference project's own self-test**, unchanged, as its acceptance criterion | the self-tests encode the failure modes, which is the valuable part | a self-test that references the target must be rewritten, not copied |

Phase 3 is complete when the harness can audit a **second, synthetic** mutation set that has nothing to do with
RE2 — for example mutations into a small format validator. **That is the boundary test from
[`ARCHITECTURE.md`](ARCHITECTURE.md) §7 step 2**, and it should be run before anything is announced as reusable.

---

## Phase 4 — Only if a second target exists

Gated on a real second target, not on a plan for one.

| # | step |
|---|---|
| 4.1 | Write the adapter for the second target **as data only**. If it cannot be, move the boundary rather than adding core code |
| 4.2 | Attempt to state the second target's metrics in the same identities as the first. If they do not transfer, they were target concepts wearing generic names |
| 4.3 | Run the Phase-3 harness against the second registry, unchanged |
| 4.4 | Only then decide whether a core is warranted, and with two instances to justify each interface |

The trigger for Phase 4 is another project's decision, not this roadmap's.

---

## Prioritised order, one table

| rank | step | effort | why now |
|---|---|---|---|
| 1 | 0.2 quantities at every site | small | 15 measured contradictions; cheapest fix with the widest reach |
| 2 | 0.1 one identity per quantity | small | preconditions every metric; the 656 B case |
| 3 | 1.2 + 1.3 `scope`, `does_not_say`, `state` fields | small | the project already writes all three; making them fields is nearly free |
| 4 | 2.1 L1 schema | medium | the four records everything else depends on |
| 5 | 1.5 index-vs-artefact check | small | turns the index into a gate instead of a document |
| 6 | 0.3 denominators stated | small | prevents the most common misreading of any metric |
| 7 | 2.4 conformance checklist | small | makes the standard adoptable without code |
| 8 | 3.1 mutation harness | medium | highest-value reusable code; bounded risk |
| 9 | 1.1 claim index | medium | the substrate for everything above; time-box it |
| 10 | 3.2 adjudicator | small | cheap once 3.4 is in place |
| 11 | 2.2 / 2.3 provenance and checkpoint schema | small | already-existing instances |
| 12 | 0.4 docstring repair | trivial | honesty |
| — | 4.x second target | large | **blocked**: no second target |

---

## What each phase may claim when it is done

Stated because the standard's own rule applies to its implementation:

| after | may claim | may **not** claim |
|---|---|---|
| Phase 0 | the documented numbers agree with the artefacts, at every site | that the artefacts are correct |
| Phase 1 | published claims have a state, a scope and an evidence pointer, and the index agrees with the artefacts | that the claims are supported, or that corrections propagate |
| Phase 2 | the records and contracts are specified and instance-checked against a complete implementation | that the implementation conforms — nothing has been audited against the checklist |
| Phase 3 | two target-neutral mechanisms audit an unrelated mutation set | that the methodology is portable — one lifted harness is not a port |
| Phase 4 | the boundary has been exercised by a second target | anything about a third |

---

## Explicit non-goals for now

Repeated here so they can be refused politely when proposed:

1. **A plugin system.** No demonstrated need; one implementation.
2. **A new language or runtime.** The reference implementation is Python 3 stdlib plus four shell scripts. There
   is no evidence a different language is necessary, and the constraints (no dependencies, runs on a bare
   interpreter) are a feature.
3. **A generic ELF/PE/Mach-O loader, or a generic decompiler wrapper.** These are commodity and would couple the
   standard to tools that already have their own ecosystems.
4. **A hosted service, database or graph store.** The whole corpus is text and JSON under version control; that
   is what makes it auditable.
5. **Rewriting the reference project's tools to fit the abstraction.** Explicitly forbidden by the mission, and
   unjustified: the tools work, the gates are green, and the abstraction has no second consumer.
6. **Any metric that combines dimensions into one number.** [`METRICS.md`](METRICS.md) §1.
7. **Marking anything in this proposal as established.** Nothing in Phase 1–4 has been executed.
