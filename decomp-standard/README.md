# DECOMP-STANDARD

A proposed standard for **evidence-driven executable reconstruction**: how a reverse-engineering project states
what it knows, how it demonstrates that knowing, and how it measures what it has not done.

Extracted from, and demonstrated by, a complete reference implementation:
[`alemigav/re2-64-decomp`](https://github.com/alemigav/re2-64-decomp) — a Resident Evil 2 (N64) decompilation
research project with 3416 catalogued functions, 73 verification suites, 1028 cases, and 146 mutation-audited
gates.

---

## What this is, in one paragraph

Reverse engineering produces knowledge faster than it can be audited, and almost nothing in the field's tooling
distinguishes a measured fact from a plausible inference. This standard defines the vocabulary and the mechanical
checks that make the difference a first-class object: an evidence model with explicit epistemic states, a
verification standard in which **a gate is not finished until it has been shown to fail**, a measurement standard
that forbids the single composite percentage, and a specification of the eight dimensions a reconstruction project
must produce — with discovery, reconstruction, matching decompilation and native porting as four objectives that
must not be confused.

## What this is not

Not a decompiler, not a disassembler, not a binary-analysis framework, not a matching-decompilation project, and
not a completeness programme. It provides *warrant*, not *capability*. See [`VISION.md`](VISION.md) §3.

---

## Read in this order

| # | document | what it gives you | status |
|---|---|---|---|
| 1 | [`ARCHAEOLOGY.md`](ARCHAEOLOGY.md) | the measured state of the reference project — including **15 claims that contradict its own registry** and one quantity with two values | measured |
| 2 | [`VISION.md`](VISION.md) | the problem, and the six adjacent things this is not | argument |
| 3 | [`SPECIFICATION.md`](SPECIFICATION.md) | eight dimensions; four separable objectives | **proposal** |
| 4 | [`EVIDENCE_MODEL.md`](EVIDENCE_MODEL.md) | claims, evidence kinds, seven epistemic states, transition rules, invalidation | **proposal** (states derived from practice) |
| 5 | [`VERIFICATION_STANDARD.md`](VERIFICATION_STANDARD.md) | three test categories, six outcomes, mutation audits, V1–V14 conformance | mixed: 11 requirements already implemented by the reference project, 3 new |
| 6 | [`METRICS.md`](METRICS.md) | eleven coverage dimensions, each with a denominator and a non-entailment | mixed |
| 7 | [`ARCHITECTURE.md`](ARCHITECTURE.md) | generic core vs target adapter — **and the case against building the core** | **proposal, weakest** |
| 8 | [`REFERENCE_IMPLEMENTATION.md`](REFERENCE_IMPLEMENTATION.md) | how the RE2 project demonstrates each part | descriptive |
| 9 | [`EXTRACTION_MAP.md`](EXTRACTION_MAP.md) | all 102 tools, 30 manifests, 237 documents classified A/B/C/D | measured |
| 10 | [`ROADMAP.md`](ROADMAP.md) | prioritised steps, and what each may claim when done | **proposal** |
| 11 | [`OPEN_QUESTIONS.md`](OPEN_QUESTIONS.md) | twelve questions this work could not settle, with leanings and confidences | open |
| 12 | [`PRESERVED_SYSTEMS.md`](PRESERVED_SYSTEMS.md) | what must not be modified, with the cost of violating it | constraint |
| — | [`EXECUTIVE_REPORT.md`](EXECUTIVE_REPORT.md) | the six answers, for a reader with ten minutes | summary |

**Every document marks its own status.** A claim marked **proposal** has no implementation and has not been
executed. Do not read a normative-sounding sentence as a description of working software.

---

## The principles, and where each one is made mechanical

Ten principles motivated this standard. Each is listed with the document that operationalises it — a principle
with no mechanism is a preference.

| principle | mechanism |
|---|---|
| Evidence over assertion | [`EVIDENCE_MODEL.md`](EVIDENCE_MODEL.md) §3 — a `VERIFIED` claim points at a procedure and its result |
| Reproducibility over undocumented procedure | [`VERIFICATION_STANDARD.md`](VERIFICATION_STANDARD.md) V1, V10 — pinned counts, recorded runs, coverage stated with the verdict |
| Explicit uncertainty over unjustified confidence | [`EVIDENCE_MODEL.md`](EVIDENCE_MODEL.md) §2 — seven states including `UNKNOWN` and `CONTRADICTED` as first-class |
| Measurable coverage over subjective estimates | [`METRICS.md`](METRICS.md) §1 — six requirements per metric, and §1's ban on the composite percentage |
| Independent verification over self-report | [`PRESERVED_SYSTEMS.md`](PRESERVED_SYSTEMS.md) §10 — the verifier is a separate role and may not edit the corpus |
| Adversarial testing of verification mechanisms | [`VERIFICATION_STANDARD.md`](VERIFICATION_STANDARD.md) §5 — every gate must be shown to fail |
| Separation of generic methodology from target implementation | [`EXTRACTION_MAP.md`](EXTRACTION_MAP.md) + [`ARCHITECTURE.md`](ARCHITECTURE.md) |
| Preservation of artefacts and provenance | [`PRESERVED_SYSTEMS.md`](PRESERVED_SYSTEMS.md) + the four-field `.c` header |
| Traceability from observation to verification | [`EVIDENCE_MODEL.md`](EVIDENCE_MODEL.md) §5 — **and it is the one principle not yet mechanical** |
| Honest reporting of unknowns, skips and incompleteness | [`METRICS.md`](METRICS.md) §2.10, §2.11 — the residual and the skip count are first-class metrics |

The ninth is the gap. Traceability exists as a discipline in the reference project and as a schema in this set; it
does not exist as a mechanism anywhere. That is why [`ROADMAP.md`](ROADMAP.md) puts a small claim index before any
dependency graph, and why [`OPEN_QUESTIONS.md`](OPEN_QUESTIONS.md) Q5 asks whether the graph is needed at all.

---

## The three claims worth checking first

If you only verify three things about this work, verify these, because the rest depends on them.

**1. The reference project's verification genuinely passes, and honestly reports its limits.**

```
$ python3 tools/verify.py --full
VERDICT PASS — every procedure passed and the gate audit is 39/39 with nothing vacuous
coverage partial: cartridge-gated suites SKIPped: any claim that depends on them is INCONCLUSIVE here
```

That output is reproducible on any machine, with no game cartridge. The `39/39` is out of 146 audit entries — 107
were skipped. Both numbers are in the report.

**2. The methodology is mostly *not* extractable as code.**

Of 102 files under `tools/`, **9 are reusable as-is** — and none of them is a high-value methodological component.
Every high-value component is a generic idea welded to this target's constants. Measured in
[`EXTRACTION_MAP.md`](EXTRACTION_MAP.md) §11. This finding is the reason the standard is documentation-shaped and
the roadmap is code-light.

**3. The reference project's own gates cannot see its own documentation drift.**

`tools/counts.py` asserts 25 quoting sites across four files and passes. Fifteen figures contradict the registry
— fourteen in the same documents, including two inside the file that makes CI run and one eleven lines from a
number the gate does check, and one inside a committed artefact the project treats as evidence. Measured in
[`ARCHAEOLOGY.md`](ARCHAEOLOGY.md) §6.

Claim 3 is the standard's reason to exist. Claims 1 and 2 are why it should be built on this project rather than
from scratch.

---

## Evidential status of the numbers in this set

Applying the standard's own rule to this documentation, the figures split three ways, and a reader should know
which is which.

| status | figures | how to check |
|---|---|---|
| **measured here**, on this machine, with no target artifact | suite/case counts (73 / 1028 / 32 / 286 / 41 / 742), audit entries (146; 39 run, 107 skipped), marker and count cases (22, 25), milestone numbers (305 / 249 / 56), notes (229), tools (100), corpus (3416 functions / 3678 ranges / 174 bodies / 3590 files), image bytes (1 947 632), coverage values (1 211 256 and 1 210 600), call graph (3416 nodes / 15 535 edges / 684 null targets / 517 tables of which 250 unbounded), provenance (3678 regions / 111 179 operands / 12 005 attributed), the status ladder (3416 / 3416 / 3329 / 33 / 12), every contradiction in §6 | `python3 tools/verify.py --full`, `python3 tools/counts.py --derive`, or the named artefact |
| **read from a committed artefact**, whose derivation needed the target | codec constants (256-byte codebook, 217 944 groups, 1 180 of 1 192 samples), the voice sweep (12 037 blocks compared, 0 samples differing), the opcode tables (45 keys, 17 inferred), recovered functions (15 byte-exact, one at 226 of 229) | the artefact is committed and citable; the *measurement behind it* is cartridge-gated and was **not** re-run here |
| **quoted from the project's prose and not re-verified** — including several "reference practice" figures | texture law on 65/65 tiles, the `01 41` family on 355/355 blocks, 588/588 clips reconciling, `addu` 8 501 against `or` 0, 2 of 254 RSP words unnamed | **UNVERIFIED here.** These rest on the 742 cartridge-gated cases, which reported `SKIP` |

Nothing in this documentation set was produced using the target artifact. Where a figure is in the third row it is
presented as *the project's claim by the procedure it names*, not as an established fact — which is the distinction
the whole standard is about.

---

## Scope, and a warning about the sample

This standard was extracted from **one** implementation, by one author, for one target. That is a sample size of
one, and the standard's own Q10 says so: a standard tested against the project it was read off will fit, because
it was read off.

Concretely, three things are asserted with less confidence than their tone suggests:

- **The architecture** ([`ARCHITECTURE.md`](ARCHITECTURE.md)) proposes a boundary with no second instance to test
  it against, and §6 argues against building the core yet.
- **Native portability** (specification §8) has no demonstration: the reference project declined its third layer
  rather than half-build it.
- **The dependency graph** in [`EVIDENCE_MODEL.md`](EVIDENCE_MODEL.md) §5 has no precedent anywhere. It is the
  highest-ceiling part of the proposal and the least supported.

Everything else is grounded in a file path or a measured value.

---

## On the reference project's target

The reference project studies a copyrighted commercial game. Its artifact is **not** in its repository and never
will be; 742 of its 1028 cases cannot run without the reader's own legally dumped copy, and they report `SKIP`,
never `PASS`. Nothing in this documentation set reproduces copyrighted content, and no verification reported here
used the artifact.

This matters to the standard, not just to that project: a reconstruction standard aimed at commercial binaries must
assume the artifact is unavailable to most readers, and must therefore require a verification tier that runs
without it ([`VERIFICATION_STANDARD.md`](VERIFICATION_STANDARD.md) V3, V10; [`OPEN_QUESTIONS.md`](OPEN_QUESTIONS.md)
Q12).

---

## Where to start if you want to act

[`ROADMAP.md`](ROADMAP.md) Phase 0, item 0.2: make the documentation gate bind *quantities* rather than *phrases*.

It is small, it fixes a measured defect, it touches no abstraction, and it is the cheapest demonstration that
this standard's requirements are worth more than the defects they describe.

---

## Licence

This document set is licensed under [CC BY 4.0](../LICENSE) — share and adapt freely, including commercially,
with attribution, a link to the licence, and an indication of any changes. The licence covers this documentation
only, not the reference implementation it describes.
