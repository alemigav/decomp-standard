# VERIFICATION_STANDARD — categories, outcomes, gates, mutation audits

**Status.** The three test categories (§3) and the outcome vocabulary (§4) are **formalised from a working
implementation** — the reference project ships all of this and runs it. The *conformance requirements* (§6)
and the *portability boundary* (§7) are **proposed**. Where a requirement has no implementation, it says so.

The standard has one rule, and everything else in this document is machinery for it:

> **A result is admissible only if the gates that produced it have been shown to fail.**

Read that as a constraint on the *verifier*, not on the target. A green suite establishes nothing on its own;
it establishes something once the suite has been demonstrated capable of reporting red.

---

## 1. Why this rule, in the reference project's own history

The rule is not a philosophical preference. It was earned by a recurring defect the project names explicitly:
**the gate that could not fail.** Documented instances, each of which had been reporting PASS:

| instance | what was wrong |
|---|---|
| six audit environments missing a directory | the tool died before reaching a case; exit 1 read as "caught the mutation" |
| two mutations failing for the wrong reason | an exception, not the check |
| an audit grading by `"FAIL" in output` | five audits were green no matter what, because one of them printed `FAIL` by design |
| **49 of 132 mutations never ran** | all three sound-arc anchors and the entire vector arc had never executed; the sandbox copied a hand-grown manifest list and the tools died on `FileNotFoundError` |
| a ratchet case that was vacuous | it ran while the registry was still dirty from the previous case, so it would have passed with the comparison removed |
| a `verify.py` self-test case masked by an earlier branch | a tally of (2,3) also tripped "fewer cases than it ran", so the exit-status branch was never exercised |

Six instances across one project. The pattern is not carelessness; it is that *a check that cannot fail looks
exactly like a check that passes*, and the difference is invisible without deliberate effort. Hence the rule.

---

## 2. What verification is for

Verification answers one question: **is this claim supported by a procedure that could have told us
otherwise?** It does not answer "is the reconstruction correct", "is the codec right", or "is the compiler
identified". Those are claims, verified individually, each by its own case.

This separation of *verification* from *recovery* is itself a requirement. The reference project writes it as
a standing brief for a separate role: "Execute the verification the project already maintains, and report what
it says. Do not recover code, and do not design a new check unless a claim genuinely arrives in a class no
existing check covers" (`docs/VERIFICATION.md`). The reason is that "make the suite pass" is a one-line edit
in three different places, and the person best placed to make that edit is the person who wants the claim.

---

## 3. Three test categories

### A. Artifact-independent tests

Synthetic or constructed inputs. No target bytes required.

| property | reference-project instance |
|---|---|
| a parser accepts its format and rejects a corrupted variant | `tools/t64info.c` compiled and run both ways (`tools/t64_selftest.py`, 4 cases) |
| an address calculation is right, including the historical wrong answers | `tools/vaddr.py --self-test`, replaying three named mistakes |
| an instruction decoder's semantics | `tools/test_harness.py`, 15 cases, ground truth from the ISA not from the harness |
| a script-VM decoder's traces | `fixtures/scd/trace_fixture.json`, 16 literal byte-string cases |
| a manifest's internal invariants | `tools/sound_fixtures.py`, 10 cases — counts sum, hashes are 64 hex, lists in range |
| a full pipeline runs on a synthetic miniature | `fixtures/corpus/cart.z64`, 8 KiB, `provenance.py --corpus-self-test`, 6 cases |
| the verifier's own verdict logic | `tools/verify.py --self-test`, 8 cases, one per branch |
| the gate registry cannot silently drift | `tools/ratchet.py --self-test`, 10 cases |
| the CI guard fires in both directions | `tools/ci_full.sh --self-test`, 3 cases on synthetic logs |

**Measured, this machine:** 32 suites / 286 cases run without the cartridge, and the gate audit runs 39 of its
146 entries. This is the entire evidence base available to a fresh clone.

**Why the category matters more than it looks.** An artifact-independent test is the only kind a third party
can reproduce without acquiring the target. The reference project's most-checked structural claim — the
mapping law — is asserted by a self-test that replays its own errors, and anyone can run it in under 100 ms.

### B. Artifact-dependent tests

Requiring original bytes, or a reference execution.

| property | reference-project instance |
|---|---|
| a decoder reproduces a committed artefact from the bytes | `file_table.py --check`, 101 cases |
| a format law holds on all members of a family | `container_0141.py --check`, 355/355 blocks, 29 cases |
| a reconstruction compiles to the same bytes | `compile_probe.py --check`, 53 cases |
| an emulated execution matches an external emulator | `diff_rdram.py`, page-classified |
| a transcription matches the code being executed | `voice_sweep.py`, 12 037 blocks compared, 0 samples differing |
| a boundary set tiles an image | `classify_image.py --check-cartridge`, 2 cases |
| a segmentation reassembles the original | `splat_boot.py --check`, 5 cases |

**Measured, this machine:** 41 suites / 742 cases are unavailable — **SKIP, never PASS**. An audit entry whose
tool is artifact-dependent is likewise skipped (107 of 146).

### C. Verification-system audits

Deliberate defect injection, to establish that the acceptance gates detect it.

This category is **the one the standard exists to require**, and it is the category most projects omit.

| injected defect | must be detected by |
|---|---|
| a function is removed from the corpus | the coverage/tiling case |
| a hash is corrupted | the artefact-vs-source comparison |
| an address is shifted by one word | the format or extent case |
| provenance is dropped from a `.c` header | the header-sum case |
| a format field's endianness is flipped | the field-decoding case |
| an opcode's advance is recorded as a constant where it is variable | the registry's refusal case |
| a required documentation anchor is broken | the marker check |
| an invalid corpus entry is admitted | the corpus self-test |
| a padding run overwrites a function body | the byte-map precedence case |
| the unclassified bucket is renamed `data` | the byte-map class case |
| a refusal is filed under a kind with no work item | the refusals census |
| the CI skip-guard is removed | the guard's own self-test |

**Measured, this machine:** 146 audit entries in the registry; 39 run and are detected; 107 skipped for want of
the cartridge. `0 vacuous`, `0 broken` — the state the standard calls admissible.

---

## 4. Standardised outcomes

Six outcomes are required. The distinctions are not cosmetic; each pair below is one the reference project
has been burned by conflating.

| outcome | meaning | who may print it |
|---|---|---|
| `PASS` | ran, held, and its mechanism has been shown to fail | a check, after its mutation is detected |
| `FAIL` | ran and did not hold | a check |
| `SKIP` | could not run here — a required input is absent. **Never counts as passing** | a check |
| `BLOCKED` | could run, but a prerequisite is broken — the tool failed to start, an anchor went missing, the sandbox is wrong | a harness, about a check |
| `VACUOUS` | ran and could not fail; asserts nothing | an audit, about a check |
| `INCONCLUSIVE` | the aggregate verdict when admissibility is not established | the adjudicator, about the run |

### 4.1 The three rules that follow

1. **A skipped test must never be counted as a passing test.** Stated in the standard as a hard requirement
   because the alternative is invisible: a suite list that reports "all green" over a subset is the single most
   common way a verification system lies. The reference project prints `SKIP (needs the cartridge)`, counts it,
   greps for it in the full tier, and **fails the full tier if any skip appears** — the guard exists so that a
   runner with a stale checkout cannot report green.

2. **`BLOCKED` is not `PASS` and not `FAIL`.** The reference project's `BROKEN` outcome exists because "the
   check failed" and "the check could not start" are indistinguishable from an exit code. Reporting the second
   as the first manufactures a detection that never happened — which is exactly what 49 of 132 mutations were
   doing.

3. **A mutation audit passes only when the injected defect is detected.** Not when the tool exits non-zero.
   Not when the output contains a failure word. The audit must judge by the same rule the suite is judged by:
   exit status **and** a whole verdict tally.

### 4.2 `VACUOUS` versus `SKIP`, which is the subtle one

These are not the same and the difference decides admissibility.

- `SKIP` — the check could not run. Nothing was claimed.
- `VACUOUS` — the check ran and could not fail. Something *was* claimed, and the claim is unsupported.

The reference project reports `VACUOUS` as inadmissible and `SKIP` as merely unavailable, and it took a
correction to get there: conflating them "made the entry point report `INCONCLUSIVE` on every fresh clone,
which was wrong in the direction that matters least but is wrong nonetheless" (`docs/VERIFICATION.md`).

**Proposal:** the standard should state this explicitly because the natural instinct is to treat both as
"didn't really run", which would make a fresh clone unverifiable *and* make a vacuous gate invisible.

---

## 5. Mutation audits

### 5.1 Requirements

A mutation audit entry must satisfy all of:

1. **It disables a mechanism, not a constant.** Emptying a lookup table or raising a limit produces failures
   for the wrong reason (an `IndexError`, a petabyte allocation). The reference project records both.
2. **It targets the comparison or the derived value**, i.e. the thing whose removal should make the check
   blind — not the value the check compares against.
3. **The unmutated tool runs first, in the same sandbox, and must succeed.** This is the positive control, and
   it is mandatory: without it, a sandbox defect is reported as a detection.
4. **The mutation is judged by exit status plus a whole verdict tally**, never by text matching.
5. **The anchor is verified to exist, to be unique, and to change the text.**
6. **The mutation lands inside the sandbox.** The reference project records an incident where a mutation aimed
   at a linked path wrote through into the live tree and was then judged on its own damage.

### 5.2 Mutation coverage is not correctness

State this in every report. A mutation audit establishes that *each gate can fail*. It establishes nothing
about whether the gates are the right gates, whether the claim set is complete, or whether an untested claim is
true. The reference project's own numbers show the gap plainly: 146 mechanisms audited, against 3416 functions
of which 15 are reconstructed to the byte.

### 5.3 The anchor fragility problem, and the cheap mitigation

Mutations anchor on exact source text, so every refactor breaks them silently. Two mitigations, both measured
in the reference project:

- **A lint, run every time, costing 0.04 s** for 88–146 anchors: exists, unique, changes the text. It found a
  pre-existing duplicate anchor on its first run, where only the first occurrence was ever replaced and half
  the mutation had never been applied.
- **A freshness or invalidation policy** — *proposal*, not implemented: an anchor that has not been re-verified
  since the file it targets last changed should be reported as `BLOCKED`, not silently trusted.

---

## 6. Conformance requirements

What a project must satisfy to claim it follows this standard. Marked **(impl)** when the reference project
already does it, **(prop)** when this is new.

**V1 — a registry with pinned expected counts. (impl)**
Every check is registered with its expected case count. Running a different number of cases than registered is
a failure, in both directions.

**V2 — no silent green. (impl)**
A check that exits zero without printing a whole verdict tally is `FAIL`, not `PASS`.

**V3 — skip is not pass. (impl)**
An unrun check reports `SKIP`, is counted as skipped, and any claim resting on it is at most `HYPOTHESIZED`.

**V4 — every gate has a mutation. (impl)**
A gate is not finished when it passes; it is finished when it has been shown to fail. The reference project's
own phrasing: "a gate is not finished when it passes — it is finished when it has been shown to fail."

**V5 — mutations have a positive control. (impl)**
The unmutated tool must succeed in the audit sandbox before the mutation is judged.

**V6 — the aggregate verdict checks admissibility first. (impl)**
Order: audit absent → `INCONCLUSIVE`; any vacuous or broken → `INCONCLUSIVE`; audit not fully passing →
`INCONCLUSIVE`; procedure failed → `FAIL`; otherwise `PASS`.

**V7 — the adjudicator is itself tested against each branch. (impl)**
Including the branch that must return `INCONCLUSIVE` on an otherwise fully green run.

**V8 — the registry's history is pinned. (impl)**
A ratchet forbids a count change in either direction without a deliberate, diff-visible act, and forbids the
verified corpus from being edited to make a check pass.

**V9 — published numbers are derived, and a deleted phrase is a failure. (impl)**
Each number has one derivation and every quoting site is asserted against it, with an expected occurrence
count.

**V10 — unavailable verification is reported as unavailable, in the same breath as the verdict. (impl)**
The reference project's report emits `coverage: partial` with the note that any claim depending on the skipped
suites is `INCONCLUSIVE` here. A green summary with no coverage statement does not conform.

**V11 — one quantity has one definition, asserted at every site. (prop)**
*New, and directly motivated by a measured defect*: two committed artefacts disagree about "bytes inside a
known function body" by 656 B, and 15 numeric claims contradict the registry
(`ARCHAEOLOGY.md` §2.2, §6). The existing gate binds phrases; this requirement binds quantities.

**V12 — the gate that makes CI run is tested without CI. (impl)**
A workflow file parsed only by a remote service is unverified. Lint it locally, structurally.

**V13 — every claim's evidence names the procedure and its result. (prop)**
The link from claim to case is presently prose. See [`EVIDENCE_MODEL.md`](EVIDENCE_MODEL.md) §3.3.

**V14 — a correction propagates. (prop)**
The dependency closure of a corrected observation is recomputed, and every artefact derived from it is
regenerated. Not implemented anywhere in the reference project; see [`EVIDENCE_MODEL.md`](EVIDENCE_MODEL.md) §5.

---

## 7. What does not transfer

The reference project's verification machinery is largely reusable as *design*. Four things are not
reusable as code, and pretending otherwise would produce an abstraction with one instance:

1. **The suite registry contents.** 73 entries naming this project's tools, each with a hand-measured expected
   count. Re-instantiate, do not import.
2. **The 146 mutation anchors.** Each quotes this project's source text. Only the *shape* — disable one
   mechanism, require failure — transfers.
3. **The `needs_rom` notion.** It generalises to `needs_artifact`, but the specific gates and their
   distribution (41 gated suites, 742 cases) are this target's.
4. **The seven derived numbers' patterns.** The regular expressions are written against this project's
   sentences.

The transferable asset is the *doctrine plus the shape of the tools*. [`EXTRACTION_MAP.md`](EXTRACTION_MAP.md)
classifies all 102 files individually; [`ARCHITECTURE.md`](ARCHITECTURE.md) proposes the boundary.

---

## 8. The one thing a reader should take away

A verification system's own failure mode is identical in shape to the failure mode it is meant to catch. Every
requirement above exists because the reference project found, in its own machinery, the same defect it audits
for: something that looked green and could not have looked red. The rule in §0 is the only defence, and it
must be applied to the verifier itself — which is why `V7` requires the adjudicator to be fed a synthetic
inadmissible run, and why `V5` requires the audit's own sandbox to be proved functional before any mutation is
judged.
