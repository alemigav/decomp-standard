# VISION — the problem, and what this is not

**Status.** An **argument**, not a specification. It states a position and the evidence for it. The
requirements it motivates are in [`SPECIFICATION.md`](SPECIFICATION.md) and
[`VERIFICATION_STANDARD.md`](VERIFICATION_STANDARD.md).

---

## 1. The problem

Reverse engineering produces knowledge, and almost nothing in the field's tooling checks whether knowledge is
warranted. A disassembler will tell you a function starts at an address. A decompiler will emit C. A graph tool
will draw call edges. None of them will tell you which of its outputs are measured, which are inferred from a
convention, and which are guesses wearing a confident font.

The consequence is a familiar and expensive failure: a project publishes a claim, the claim is repeated, the
claim turns out to be wrong, and unwinding it costs more than making it did. The knowledge was produced faster
than it could be audited, and nothing in the toolchain made the difference between *established* and *plausible*
a first-class object.

The reference project for this standard is the strongest counter-example I have examined, and it is instructive
precisely because it is not a tool — it is **a discipline, carried by one person, over 305 milestones, with 53
recorded retractions.** Its front page promises that "every claim here is either measured by one of those cases
or explicitly labelled a reading of the code". That promise is kept. It is kept by *effort*: 229 notes, a
retraction table, a mutation audit, fourteen separate documentation gates.

And it still ships fourteen present-tense numeric claims that contradict its own registry
(`decomp-standard/ARCHAEOLOGY.md` §6), because the discipline has no machinery behind it. A correction propagates
only as far as someone remembers to propagate it. This is the gap DECOMP-STANDARD addresses.

---

## 2. What DECOMP-STANDARD is

A **standard for evidence-driven executable reconstruction**, comprising:

1. **An evidence model** — epistemic states, evidence kinds, and the rules for moving between them, so that
   "verified" is a field rather than an adjective ([`EVIDENCE_MODEL.md`](EVIDENCE_MODEL.md)).
2. **A verification standard** — test categories, outcomes, acceptance gates, and the requirement that every
   gate be shown to fail ([`VERIFICATION_STANDARD.md`](VERIFICATION_STANDARD.md)).
3. **A measurement standard** — dimensions of coverage, each with a denominator and an explicit statement of
   what it does not measure, and an absolute prohibition on the single composite percentage
   ([`METRICS.md`](METRICS.md)).
4. **A specification of what a reconstruction project must produce**, for eight dimensions and four separable
   objectives ([`SPECIFICATION.md`](SPECIFICATION.md)).
5. **An architecture** separating the reusable core from target-specific adapters
   ([`ARCHITECTURE.md`](ARCHITECTURE.md)).

It is a **conformance standard with a reference implementation**, not a framework to adopt. The reference
implementation is a complete, working, 4020-file project whose methodology is documented, measured and largely
reproducible without its target.

---

## 3. What this is not

The distinctions matter, because the field is full of adjacent things and the differences are where the value
sits.

### 3.1 Not a decompiler

A decompiler converts machine code to a higher-level representation. It answers *"what might this be?"*

DECOMP-STANDARD is indifferent to the representation and concerned with *"what do we know, and how?"* It does
not compete with Ghidra, IDA, Binary Ninja or RetDec — it consumes their output and asks what that output
warrants. The reference project's entire corpus came from a decompiler, and the standard's contribution is that
3416 decompiled functions are labelled as *inventory*, not as understanding.

### 3.2 Not a disassembler

A disassembler answers "what instruction is at this address?" That is an `OBSERVED` fact and it is the wrong
granularity for the problem. The reference project's most expensive recurring error is not a mis-decoded
instruction — it is *an address composed by hand*, and its mitigation is a tool plus a rule, not a better
disassembler.

### 3.3 Not a binary-analysis framework

Frameworks (angr, radare2/rizin, Ghidra's API) provide *capability*: they can propagate values, build graphs,
emulate. DECOMP-STANDARD provides *warrant*: it says what a propagation, a graph or an emulation run establishes,
and what it does not.

This is not a small distinction. The reference project contains a 1663-line abstract interpreter, and the thing
that makes it trustworthy is not its analysis but its four fixtures and its pre-registered acceptance tests.
The analysis is commodity; the warrant is not.

### 3.4 Not a matching-decompilation project

Matching decompilation (the sm64/oot/perfect_dark lineage) is one of the four objectives, with the strictest
completion criterion. DECOMP-STANDARD treats it as **one objective among four**, deliberately separable — and
its requirement that projects declare which objective they pursue exists because the conflation is so common.
"A decompilation" can mean four different things with four different completion states.

### 3.5 Not a completeness programme

The standard does not ask projects to finish. It asks them to be honest about where they stopped. The reference
project's most valuable published facts are its residues: 16.5 % unclassified, 15 of 3416 matched,
`226 of 229`, and 56 milestone numbers with no note. A standard that only rewarded completeness would have
produced none of them.

### 3.6 Not a proof system

Nothing here produces formal guarantees. The reference project's own framing is right: a claim is supported by
"an appropriate, reproducible procedure and its result". That is engineering assurance, not mathematics, and
overstating it would be the same error the standard exists to prevent.

---

## 4. The three ideas worth the most

If the standard is remembered for three things, these are the candidates, ranked by how much they changed
outcomes in the reference implementation.

### 4.1 A gate is not finished when it passes

It is finished when it has been **shown to fail**. The reference project's recurring defect is not a wrong
claim but a **gate that could not fail** — six audit environments missing a directory, two mutations failing for
the wrong reason, an audit grading by the presence of the word "FAIL", and one discovery that **49 of 132
mutations had never executed at all**.

Every one of those looked green. The standard's central requirement — that a passing check proves nothing until
its mechanism has been demonstrated to fail — is the only defence, and it must be applied to the verifier itself.

### 4.2 Unavailable is not failed, and neither is passing

Three states: a check **ran and held**, a check **could not run**, and a check **ran and could not fail**. A
verification system that conflates them is broken in the direction that matters: it reports a green tick over a
population it never examined.

The reference project implements this and its verdict carries the caveat in the same breath — `PASS` with
`coverage: partial` and the note that any claim depending on the skipped suites is `INCONCLUSIVE` here. That
sentence is the template a naive CI gets wrong.

### 4.3 One definition, many consumers

The reference project's registry of checks is simultaneously the runner, the source of every published count,
and the baseline a ratchet defends. Three consumers of one definition cannot disagree.

**And this is where the standard goes further than its reference.** The project binds *phrases*, so a number is
correct where the gate looks and stale eleven lines away. The standard binds *quantities*: if two artefacts
claim to measure the same thing, a check asserts they agree. The measured motivation is small and concrete —
656 bytes, two committed values, no gate capable of noticing
([`METRICS.md`](METRICS.md) §5.1).

---

## 5. Who this is for

- **A reconstruction project past its first hundred findings**, where the notes have become the risk.
- **A team inheriting a corpus** it did not produce, which needs to know which of 3416 functions are actually
  understood. Per the reference project: 33 have names and 12 have behaviour pinned.
- **A reviewer or funder** asking whether a decompilation's claims hold, who currently has no vocabulary for the
  question beyond trust.
- **A project whose target is not a binary at all.** Nothing in the evidence model, the verification standard or
  the metrics is specific to machine code. The eight dimensions name a *file format* and a *behaviour*, not a
  CPU.

It is **not** for a project that wants a faster decompiler, or a first-pass analysis, or a tool to hand to a
model. The overhead of this standard is real — the reference project spends most of its engineering effort on
gates — and it is justified only where being wrong is expensive and being right is contested.

---

## 6. The long-term ambition, stated honestly

The ambition is that a reconstruction's quality claim becomes a **checkable object**: that "we have decoded this
format and verified the law on all 65 members, and its validator rejects a corrupted instance" can be audited by
a third party without re-doing the work, and that "we understand 62 % of this binary" stops being a thing anyone
says.

The near-term ambition is much smaller and is the one that matters: **make the reference project's discipline
survive the loss of the person who holds it in their head.** That is a documentation, schema and small-tooling
problem, not a platform problem — and the roadmap reflects it
([`ROADMAP.md`](ROADMAP.md)).

The standard should be judged by whether an engineer who has never seen the reference project can read its
retraction table and understand not only *what* was wrong but *which procedure failed to catch it*, and whether
the same class of failure is now mechanically impossible.
