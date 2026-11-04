# DECOMP-STANDARD

A proposed standard for **evidence-driven executable reconstruction**: how a reverse-engineering project states
what it knows, how it demonstrates that knowing, and how it measures what it has not done.

Extracted from, and demonstrated by, a complete reference implementation — a Resident Evil 2 (N64) decompilation
research project at [alemigav/re2-64-decomp](https://github.com/alemigav/re2-64-decomp).

> **A result is admissible only if the gates that produced it have been shown to fail.**

That one rule is the standard's centre. Everything else in the document set is machinery for it — an evidence
model, a verification standard, a measurement standard, and a specification of what a reconstruction project must
produce.

---

## Start here

**[`decomp-standard/README.md`](decomp-standard/README.md)** — the introduction, the reading order, and the three
claims worth checking first.

This root README is deliberately a signpost rather than a second introduction. Duplicating an introduction
creates two sources of truth that drift apart, which is the precise defect the standard documents in its own
reference project (a coverage figure quoted for ninety-odd milestones while the artefact beneath it was right).
One introduction, one place.

---

## What is in the document set

Thirteen documents plus the introduction above, all under [`decomp-standard/`](decomp-standard/):

| | |
|---|---|
| [`ARCHAEOLOGY.md`](decomp-standard/ARCHAEOLOGY.md) | the measured state of the reference project, including its defects |
| [`VISION.md`](decomp-standard/VISION.md) | the problem, and what this is not |
| [`SPECIFICATION.md`](decomp-standard/SPECIFICATION.md) | eight dimensions; four separable objectives |
| [`EVIDENCE_MODEL.md`](decomp-standard/EVIDENCE_MODEL.md) | claims, evidence, epistemic states, invalidation |
| [`VERIFICATION_STANDARD.md`](decomp-standard/VERIFICATION_STANDARD.md) | test categories, outcomes, mutation audits, conformance |
| [`METRICS.md`](decomp-standard/METRICS.md) | eleven coverage dimensions with denominators |
| [`ARCHITECTURE.md`](decomp-standard/ARCHITECTURE.md) | generic core vs target adapter — and the case against building it |
| [`REFERENCE_IMPLEMENTATION.md`](decomp-standard/REFERENCE_IMPLEMENTATION.md) | how the reference project demonstrates each part |
| [`EXTRACTION_MAP.md`](decomp-standard/EXTRACTION_MAP.md) | all 102 tools and 237 documents classified |
| [`ROADMAP.md`](decomp-standard/ROADMAP.md) | prioritised steps |
| [`OPEN_QUESTIONS.md`](decomp-standard/OPEN_QUESTIONS.md) | twelve questions this work could not settle |
| [`PRESERVED_SYSTEMS.md`](decomp-standard/PRESERVED_SYSTEMS.md) | what must not be modified, and why |
| [`EXECUTIVE_REPORT.md`](decomp-standard/EXECUTIVE_REPORT.md) | the six answers, for a reader with ten minutes |

---

## Status: this is a proposal, not a product

Nothing here is software. There is no framework to install, no CLI, and no schema implementation.

Every document marks its own status. Where a requirement is already implemented by the reference project it says
so and cites the file; where it is proposed it says that instead. The distinction is not decorative — it is the
standard applied to itself, and a reader should treat any normative-sounding sentence as unverified until it
carries a citation.

The set is also derived from **one** implementation, and its own `OPEN_QUESTIONS.md` (Q10) names that as its
largest weakness: a standard tested against the project it was read off will fit, because it was read off.

---

## Repository history

This repository once held the reference implementation. It was removed in `7c616e3` so that this repository is the
standard and nothing else. The implementation is preserved in two places:

- **[alemigav/re2-64-decomp](https://github.com/alemigav/re2-64-decomp)** — the upstream project, public, identical
  tree (`55296b0`, milestones M303/M304)
- **tag `pre-decomp-standard`** — this repository's initial commit, holding the complete 4020-file tree

Restore it in full with:

```sh
git checkout pre-decomp-standard -- .
```

A consequence worth knowing: removing that content also removed this repository's ability to verify itself. The
gate suite — 73 suites, 1028 cases, 146 mutation-audited mechanisms, a ratchet and a derived-numbers check — was
run on this tree before the removal and returned `VERDICT PASS` with the gate audit at 39/39, 0 vacuous and 0
broken. That result is a fact about the tree at `141b644`; it is recorded in the commit message rather than being
re-runnable here. To re-run it, use the upstream repository.

---

## Licence

The documentation in this repository is licensed under
**[Creative Commons Attribution 4.0 International (CC BY 4.0)](LICENSE)**. You may share and adapt it, including
commercially, provided you give appropriate credit, link to the licence, and indicate any changes.

The licence covers this documentation only. It does not extend to the reference implementation or to any
third-party work the documentation describes; that project's own licence and provenance are separate, and
`decomp-standard/REFERENCE_IMPLEMENTATION.md` records the evidential status of every figure quoted from it.

If you reuse this material, the attribution notice to retain is in the [`LICENSE`](LICENSE) file.
