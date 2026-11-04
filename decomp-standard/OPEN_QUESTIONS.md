# OPEN_QUESTIONS — unresolved architectural and methodological questions

Twelve questions this work could not settle. Each records what is known, why it is not settled, what would settle
it, and — where a leaning exists — the leaning and its confidence. **No question here is answered by this
document set**, and a reader should treat any leaning as an opinion, not a finding.

They are ordered by how much they constrain the rest of the standard.

---

## Q1 — Is a standard the right shape at all?

**Known.** One project demonstrates the methodology, in full, with measured success. Its discipline is carried by
one author across 305 milestones; its machinery is real; its residues are published. It also carries 14
documentation contradictions that its own gates cannot see.

**Why unsettled.** The inference from "one project needed this discipline" to "a standard should codify it" is
exactly the sample-size-of-one problem the standard itself warns about. A standard can also do harm: codified
practice becomes a compliance exercise, and a project can satisfy V1–V14 while understanding nothing.

**What would settle it.** A second project adopting at least Phase 0 and Phase 1 and reporting whether the
overhead was repaid. Nothing less.

**Leaning (low confidence):** a *documentation-and-schema* standard is justified, because the transferable asset
is demonstrably documentation (9 of 102 files are reusable as code). A *tooling* standard is not yet justified.

---

## Q2 — Is epistemic state a total order or a lattice?

**Known.** [`EVIDENCE_MODEL.md`](EVIDENCE_MODEL.md) §5.1 proposes a total order
`CONTRADICTED < UNKNOWN < HYPOTHESIZED < INFERRED < OBSERVED < DERIVED < VERIFIED` so that a dependent claim's
state is the minimum over its dependencies.

**Why unsettled.** Two objections are real. First, `OBSERVED` below `DERIVED` is questionable: a direct reading is
not obviously weaker than a computation from readings, and in this project the most expensive errors were
*computed* values (a hand-composed address) defeating *observed* ones. Second, `VERIFIED` is not "more true" than
`OBSERVED` — it is differently supported. A partial order with `CONTRADICTED` as bottom and **no single top** is
probably more honest, but then "the minimum over dependencies" no longer yields a state, and the invalidation rule
of §5.2 loses its mechanical form.

**What would settle it.** Encode both and run them over the reference project's 53 retractions. If the partial
order fails to propagate a correction the total order catches, the total order is a useful approximation; if it
propagates corrections that are not warranted, it is wrong.

**Leaning (moderate confidence):** a lattice is correct and a total order is a pragmatic stand-in. Build the
lattice if the graph is built at all.

---

## Q3 — At what granularity does a claim live?

**Known.** The reference project has 3416 functions, 111 179 recorded operands, ~250 numeric milestone findings,
53 retractions. [`EVIDENCE_MODEL.md`](EVIDENCE_MODEL.md) §6 proposes three granularities: claim, census,
aggregate.

**Why unsettled.** The boundary is a judgement, and the estimate that "~250–300 claim objects suffice" is
**inferred from counting rows, not from building the graph**. A finer grain catches more, at a cost that grows
faster than linearly in a project with a digitiser whose findings are per-instruction.

**What would settle it.** Time-box a claim index for the reference project's numeric findings and measure how
often a correction reaches a claim that had no object. Every such case is a granularity failure with a cost.

**Leaning (moderate confidence):** claim objects for published numbers, censuses for per-function facts. The
per-function provenance header is already a sufficient census record.

---

## Q4 — How does a claim index avoid becoming a second source of truth?

**Known.** The reference project has an explicit rule against exactly this: the source tree is "a projection, not
a second source of truth", regenerated from a journal every run so it cannot drift. Its boundary fixture is
distilled from the same journal and `--check`ed for drift.

**Why unsettled.** A claim index is not obviously a projection of anything — claims are authored, not derived. The
moment the index and the prose notes disagree, there are two records, and the project has demonstrated what
happens when two artefacts measure one quantity ([`METRICS.md`](METRICS.md) §5.1).

**What would settle it.** Decide, for each claim field, whether it is authored or derived, and make every derived
field regenerate from its source. Authored fields must be few, and must not restate anything a note says.

**Leaning (moderate confidence):** the index should hold only what the prose cannot conveniently express —
`state`, `scope`, `does_not_say`, `supported_by`, `supersedes`. The argument stays in the note, and the note is
the authority.

---

## Q5 — Can invalidation be automated without a dependency graph?

**Known.** Phase 0.2 of [`ROADMAP.md`](ROADMAP.md) catches the measured failure class — a quantity asserted at
every quoting site — without any graph, because a quantity identity plus site enumeration is enough.

**Why unsettled.** It catches *restatements* of a value. It does not catch *reasoning built on* a value: a claim
that a format's field is a length, because an earlier claim established the record's stride, when the stride
turns out wrong. The reference project has such chains — a base-address correction in one milestone propagated
through count-carrying claims in three later ones, and the propagation there was manual.

**What would settle it.** Measure, over the 53 retractions, how many dependents would have been found by
site-matching alone. If the answer is "most", the graph is a luxury.

**Leaning (low confidence):** site-matching catches the majority of this project's actual propagation failures,
because they are restatements of numbers rather than chains of reasoning. That is a fact about *this* project's
retraction record and may not generalise.

---

## Q6 — What makes a mutation set adequate?

**Known.** The reference project has 146 mutations and a rule that a gate is not finished until its mutation is
detected. It also discovered that 49 of 132 had never run, and that an audit grading by text was green
unconditionally.

**Why unsettled.** Every mutation is chosen by a human who already knows what the check does. The set is
therefore a sample of *conceivable* defects, drawn by someone with a model of the code, and there is no measure of
what it misses. `audit_gates` establishes that 146 specific mechanisms can fail; it establishes nothing about
mechanism 147.

**What would settle it.** An adversarial process: a party who did not write the checks attempts to make a check
pass while its mechanism is broken, and each success becomes a mutation. The reference project did this once by
accident — its own `--lint` found a duplicate anchor, and the positive control found 49 dead entries — both times
by looking rather than by being attacked.

**Leaning (moderate confidence):** mutation coverage should be reported as a count with the caveat, never as a
percentage, and the standard should require an adversarial pass before any claim of adequacy
([`VERIFICATION_STANDARD.md`](VERIFICATION_STANDARD.md) §5.2).

---

## Q7 — How does an adapter boundary survive a target whose instruction set is unknown?

**Known.** The adapter interface in [`ARCHITECTURE.md`](ARCHITECTURE.md) §2.3 assumes the adapter can supply
effect semantics. The reference project hit a case where it could not: a coprocessor's vector instruction encodings
had no citable table in the documentation the project held, and 2 of 254 words remain refused *by policy* — the
project declined to import an encoding table from the internet.

**Why unsettled.** An adapter with missing semantics is not an adapter; it is a partial adapter, and the boundary
has no vocabulary for "this target's semantics are partly unknown". That is a normal state in reconstruction, and
the standard currently has no field for it.

**What would settle it.** A `semantics_coverage` field on the adapter, with the refusal class per instruction
group, and a rule that an unknown effect must be a distinct refusal rather than a no-op — the reference project
states this rule because it caught the opposite twice in its own tooling.

**Leaning (high confidence):** this is a real gap in the proposed architecture, and it should be closed in the
schema before any adapter is written. The reference project's `refuses` field is the model.

---

## Q8 — Is "one quantity, one identity" achievable when derivations legitimately differ?

**Known.** The measured case: 1 211 256 and 1 210 600 for "bytes inside a known function body", differing by
656 B because two consumers apply different inputs — recovered-function extents on one path, not the other.

**Why unsettled.** Both numbers are correct for their input. Reconciling them means either changing one input or
introducing a documented transformation, and both have costs. A general rule that "two artefacts measuring one
quantity must agree" would, applied naively, force one of them to be wrong.

**What would settle it.** A definition of a metric identity that admits *parameters* — the same identity measured
over different populations is not a contradiction, but it must declare its population, and a reader must be able
to tell that the two values differ in population rather than in correctness.

**Leaning (moderate confidence):** identity plus explicit population. The failure is not that two values exist;
it is that nothing in either artefact says they are measured over different inputs.

---

## Q9 — What is the minimal evidence for a name?

**Known.** The reference project's most disciplined position: 12 functions have behaviour pinned by executed
experiments, and **all 12 still carry `FUN_` names**, because naming is a separate evidentiary act. It also names
three things "because the cartridge names them", and refuses to name a fourth because nothing does.

**Why unsettled.** The rule works when the artifact names things and when an external source names them. It does
not say what would license a name derived by this project. The project's own ladder returns 0 for such a rung,
which the data refuted as a *model*, not as a prohibition.

**What would settle it.** A case where a project establishes a name by measurement — a discriminator that
separates its interpretation from alternatives, plus a cross-prediction. The standard could then say a name
requires a discriminator, not a convention.

**Leaning (moderate confidence):** a name requires a discriminator. "It fits" is not evidence; "it predicts
another independently parsed field on 673 of 674 entries" is.

---

## Q10 — How do you verify a verification standard with one instance?

**Known.** This document set's entire empirical basis is one project. Its requirements are generalisations of one
project's failures.

**Why unsettled.** A standard tested against the project it was extracted from is circular: the requirements will
fit, because they were read off. The reference project's own error list contains the relevant warning — a check
that is defined by what the current code does is a check that cannot fail
([`VERIFICATION_STANDARD.md`](VERIFICATION_STANDARD.md) §1).

**What would settle it.** A project that adopts the standard and *fails* an item for a reason the standard did not
anticipate. Until then, every requirement should be read as "this project needed it", not "every project needs
it".

**Leaning (high confidence):** this is the standard's largest weakness and it cannot be fixed from here. Stated
plainly in [`REFERENCE_IMPLEMENTATION.md`](REFERENCE_IMPLEMENTATION.md) §11.

---

## Q11 — Where is the boundary of derivative work in a published corpus?

**Known.** The reference project publishes 3590 decompiled function bodies, states that they are "derivative of
that work", dedicates only its own text and tools to CC0, and keeps third-party material in a separate file with
its licence reproduced.

**Why unsettled.** For the standard this is not a legal question but a methodological one: a corpus whose
provenance and licence status are unclear cannot be an evidence artefact, because a third party cannot legally
reproduce the checks that depend on it. This is also why 742 of 1028 cases cannot run on a runner.

**What would settle it.** Not resolvable here. Recorded because a standard that encourages publishing corpora
must say something about a corpus that cannot legally be shared, and this document does not.

**Leaning:** the standard should require that the *checks* be separable from the *corpus* so a third party can
verify the method without the derivative content. The reference project does this accidentally well — 286 cases
need no artifact — and deliberately badly: no case exercises a published function body's content, so the corpus
is largely unverified as content.

---

## Q12 — Does the standard apply when the artifact is unavailable to most readers?

**Known.** The reference project's situation: the artifact is copyrighted, absent from the repository, and
required for 742 of 1028 cases. Its mitigation is a tier split (286 cases need nothing) and a synthetic mini-target
so the pipeline runs without the real one.

**Why unsettled.** This is not an edge case; it is the normal condition of reconstruction research. A standard
whose verification is unreproducible by its audience is a standard whose claims cannot be checked, which defeats
its purpose.

**What would settle it.** Evidence that the synthetic-fixture approach scales: the reference project's synthetic
target is 8 KiB and drives six pipeline cases. It exercises code paths; it cannot reproduce any target-specific
finding. Whether a structural core can be verified this way while the target-specific claims remain honestly
labelled `INCONCLUSIVE` is the open question, and the reference project's answer — publish the split, name the
skipped suites, refuse the green tick — is the strongest available position rather than a solution.

**Leaning (high confidence):** the tier split plus a published coverage state should be a hard requirement
(V3, V10), and a project that cannot supply a no-artifact tier should say so at the top of its report.

---

## Questions deliberately not asked

Recorded so their absence is a decision rather than an oversight:

- **"Which decompiler is best?"** Not this standard's concern; the reference project treats the decompiler as a
  provider whose identity and version must be recorded, nothing more.
- **"How do we finish the decompilation?"** Not a standard's question. The reference project's own answer is that
  64 MB is a community-scale effort and every stage should ship as it lands.
- **"Should this be a foundation / an organisation / a specification body?"** Out of scope, and premature: there
  is one implementation and one target.
- **"What about machine learning assistance?"** No evidence bearing on it in the reference project. The one
  relevant datum is its permuter experiments, whose finding is that a randomiser closes *shape* residues and does
  not touch *allocation* residues — a scope limit, not an endorsement.
