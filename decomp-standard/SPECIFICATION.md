# SPECIFICATION — the eight dimensions of a reconstruction project

**Status.** A **proposal**. The dimension set is new as a specification; its content is assembled from what the
reference project actually does, with each requirement pointing at the practice it formalises or the gap it
closes. Nothing here is implemented as software. Where the reference project demonstrates a dimension, it is
cited; where it does not, the requirement is marked as unbacked.

---

## 0. Scope, and the four objectives that must not be confused

### 0.1 What a reconstruction project is

A **reconstruction project** is an effort to produce an account of an existing executable artefact that is
complete, auditable and reproducible, from the artefact itself, without access to its original source.

The description is deliberately platform-neutral. The artefact may be a console cartridge, a firmware image, a
stripped userland binary, a bytecode container, a network protocol's implementation, or a compiled asset
pipeline. What makes the work a *reconstruction* rather than an *analysis* is the commitment to a defensible
account: every claim traceable to evidence, every step repeatable by a third party.

### 0.2 The four objectives

These are **separate projects with separate completion criteria**. A project may pursue any one, and must not
claim another. This is the specification's most important structural requirement, because the four are
routinely conflated in public claims.

| objective | question answered | completion criterion |
|---|---|---|
| **Discovery** | what is here? | every region of the artefact is inventoried and classified, with the residual published |
| **Reconstruction** | what does it mean? | the structures, formats and behaviours are described, each with evidence and stated scope |
| **Matching decompilation** | what source reproduces these exact bytes? | functions compile to byte-identical code through an identified toolchain |
| **Native porting** | what does it do, re-expressed for another host? | behaviour is reproduced on a new host, with equivalence demonstrated, not asserted |

**A project must publish which of the four it is pursuing, and its completion is measured only against that
objective's criterion.**

The reference project is an unusually clear case of a project doing all four *partially and honestly labelled*:

| objective | its state, measured |
|---|---|
| Discovery | 36 images fully partitioned into 5 byte classes; 16.5 % residual published as unclassified |
| Reconstruction | formats decoded with N/N laws; 3329 of 3416 functions with all call targets resolved; 33 named; 12 behaviourally pinned |
| Matching decompilation | toolchain identified (gcc 2.8.1, binutils 2.7); **15 of 3416 functions byte-exact**; one at 226/229 published as a fraction |
| Native porting | not attempted, and stated as out of scope for the script VM's layer 3 |

The `15 of 3416` figure is the whole argument for separating the objectives. A reader who takes "3416 functions
decompiled" as progress toward a matching build is off by two orders of magnitude, and the project says so in
its own front page: "This is not a matching build — of the whole cartridge."

### 0.3 Non-objectives

A reconstruction project does **not** need to: run the artefact (an emulator is a validator, not a dependency);
reproduce the build environment byte-for-byte (a profile suffices, if pinned); or achieve completeness. It
**does** need to publish what it has not done.

---

## 1. Artifact identity and provenance

**Objective.** Establish that the artefact under study is a specific, unmodified thing, and that every
derived result names which thing it came from.

**Required inputs.** The artefact itself, supplied by its owner; a stable identifier for it.

**Expected outputs.**
- A content hash of the whole artefact, published in a committed file, with the size and any header identity.
- A statement of accepted alternative representations (byte orders, containers) and the normalisation rule.
- For every derived artefact, the hash of the input it was derived from.

**Evidence requirements.**
1. The hash is computed on the artefact as supplied, and published **before** any processing.
2. Tools that read the artefact print its hash before and after, and the run shows it unchanged — the
   reference project does this and its own rules list it first: "the cartridge is immutable; tools print its
   sha256 before and after".
3. Derived artefacts that are committed carry the input hash, so a stale derivation is detectable.

**Verification requirements.**
- The hash is asserted by a case, not merely recorded. If a supplied artefact's hash differs, the case fails and
  the run says which artefact is wrong — rather than looking like a corrupt target.
- The acceptance procedure **verifies the hash before unpacking anything**, so a truncated or wrong input fails
  loudly at the boundary.

**Failure conditions.** An artefact identified by filename or size rather than content; a derived artefact with
no recorded input hash; a normalisation step that mutates the input in place.

**Completion criterion.** The artefact's identity is reproducible from the artefact alone, and every committed
artefact names its input by hash.

**Unknown and incomplete states.** The artefact is unavailable → everything downstream is `SKIP`; the identity
is unavailable → nothing may be claimed about the specific artefact, only about its family.

**Reference practice.** The reference project hashes the cartridge and publishes it in
`manifests/manifest.json`; the fetch path verifies before unpacking; `artefact_scan.py` refuses to let the
artefact's content enter version control at all, using the hash and the format's magic as the test.

**Gap it does not close.** The identification tools themselves have no `--check` mode; the earliest claims in
the project rest on the thinnest gating (`ARCHAEOLOGY.md` §8.5).

---

## 2. Executable and data inventory

**Objective.** Partition the artefact completely, so that "we have not looked" and "we looked and found
padding" are distinguishable.

**Required inputs.** The identified artefact; a discovery method.

**Expected outputs.** A total partition of every addressable byte into a small closed set of classes, each
class naming the evidence that assigned it, with overlaps counted separately and a residual class that is never
renamed on a hunch.

**Evidence requirements.**
- Every classified range names its source artefact (`[start, end, class, source]`).
- The classes sum exactly to the denominator.
- The residual is published as a count and a percentage.

**Verification requirements.**
- Sorted, disjoint, exact cover — per region and in total.
- Each class total asserted.
- A mutation that renames the residual class fails, and one that lets a coarse class overwrite a fine one
  fails.

**Failure conditions.** A partition whose classes do not sum to the denominator; a residual folded into a named
class; a class assigned without naming evidence.

**Completion criterion.** Every byte has a class and every class has a source; the residual is published.

**Unknown and incomplete states.** `unclassified` is a *legitimate terminal state*. The reference project
forbids the shortcut of calling it `data`, and gates that prohibition.

**Reference practice.** Five classes over 36 images, summing exactly to 1 947 632 B, with `unclassified` at
16.5 % published rather than absorbed; overlaps (`padding_in_body`) counted separately rather than reassigned.

**Note.** The two most valuable numbers in this dimension are the residual and the overlap count. A partition
reporting only its successful classes is not an inventory.

---

## 3. Structural reconstruction

**Objective.** Recover the artefact's internal structure: which byte ranges are code, where a function begins
and ends, who calls whom, and what mechanism governs control transfer.

**Required inputs.** The inventory (§2); a disassembler or decoder; a boundary hypothesis.

**Expected outputs.** A function census with identity and extent; a call graph whose edges carry their evidence
kind; tables and dispatch structures with declared bounds; a per-function provenance record.

**Evidence requirements.**
- Identity is `region:address`, not bare address — aliased load addresses make bare addresses ambiguous.
- Each edge states *how* it was derived (direct call, tail, resolved indirect, table dispatch, callback).
- An unbounded table is recorded as unbounded, with a reason, rather than assigned a guessed length.
- A function's extent names what determined it.

**Verification requirements.**
- Call closure: every direct call target lands on a known entry.
- A second, independent segmentation agrees, at least on a sample — the reference project's rule: "two
  independent segmentations agreeing is evidence; one segmentation agreeing with itself is not".
- Reproducibility: re-running the discovery reproduces the same extents from a content hash.

**Failure conditions.** Edges invented where a bound was unknown; extents inherited from a heuristic that
cannot fail; a census that reports a count without a discovery method.

**Completion criterion.** Every function has identity, extent and provenance; every unresolved call site is
recorded as unresolved with a reason; the unresolved set is published.

**Unknown and incomplete states.** "No caller found" is a common and *usually wrong* result — the reference
project's error list names three separate instances where a scan's matching rule, not the data, produced a
null. A null result must implicate the filter first.

**Reference practice.** 3416 nodes / 15 535 evidence-carrying edges; 684 edges left with `dst: null` and a named
obstacle rather than a guessed target, and 250 of 517 table bases left with `bound: null`; a missed-function
census that publishes a *refuted* heuristic (1 match in 35) instead of tuning it silently.

---

## 4. Format and resource reconstruction

**Objective.** Decode the artefact's data formats and containers well enough that the law is stated and
falsifiable.

**Required inputs.** Container membership; field hypotheses; a validator.

**Expected outputs.** For each format: an identifier rule, a field layout with types and offsets, a verification
law with its coverage, and an explicit list of fields whose meaning is not established.

**Evidence requirements.**
- The law is verified on **all** members of the family, and the count is published as `N/N`.
- Coverage is stated across the *distinct parameter values* the law depends on, not just the member count.
- Unnamed fields are named `unknown_*` and left alone.

**Verification requirements.**
- A validator that runs in **both directions**: it accepts a real instance and rejects a corrupted one. A
  validator only ever run on good input is unverified.
- The law is codified in a form the rebuild path can include — a header, a schema — so a later reconstruction
  cannot drift from it.
- A tempting structural reading is explicitly refuted, with the measurement that refutes it.

**Failure conditions.** A law verified on a subset; a field named from a plausible reading with no discriminator;
a container described as "format" with no length or membership law.

**Completion criterion.** Every format has a law with total coverage and a two-directional validator; every
unnamed field is listed.

**Unknown and incomplete states.** An undecoded container in a family of decoded ones is a normal state. The
reference project names one: a 28-payload container whose codec is unresolved, bounded precisely enough to be a
sub-problem of one file rather than an unidentified 8.6 MB.

**Reference practice.** A texture container's length law verified on 65/65 tiles; a model container identified as
format version 321 rather than a magic; a codec verified on 217 944/217 944 groups with the discriminator that a
*shared* codebook produces audio where a per-sample one does not.

---

## 5. Behavioural reconstruction

**Objective.** Establish what the artefact *does* when it runs, for the parts that matter, with execution as
the evidence.

**Required inputs.** An execution model — an emulator, a partial harness, or the real hardware — and a way to
observe state.

**Expected outputs.** Execution traces; state snapshots addressed by content; a differential against an
independent reference where one exists; a transcription of behaviour that is graded against execution.

**Evidence requirements.**
- The harness **names what it stubs**. Every run prints the host hooks it substituted, so what was faked is
  visible in the output rather than in a document.
- A state snapshot is addressed by a digest over its own contents, so determinism is one comparison.
- A differential states which page or region classes are *not* evidence. The reference project classifies pages
  into `same` / `harness-zero` / `ares-zero` / `both-differ` and says only the last two are evidence — because a
  page that is zero on both sides proves nothing.

**Verification requirements.**
- ISA or instruction semantics tested against the architecture, not against the harness's current behaviour.
  "Verified path" was true of the whole and false of the parts in this project's own history.
- A transcription is graded **sample for sample** against execution, and the stratum is stated.
- A retired differential keeps its findings, so the reason it could not be used survives.

**Failure conditions.** A harness that silently approximates an unimplemented instruction; a differential over
a region that is zero on both sides; a claim of behavioural equivalence from a code reading alone.

**Completion criterion.** Each behavioural claim cites an execution whose inputs and outputs are identified by
hash, with the stubbed surface named.

**Unknown and incomplete states.** A harness may legitimately implement a subset, provided the subset is
declared and the unimplemented cases are faults rather than approximations.

**Reference practice.** A partial ISA harness with a named fault list; an 8-file state snapshot digested as one
value; 12 037 blocks compared against emulation with 0 samples differing; and a differential retired with its
host findings kept.

---

## 6. Semantic verification

**Objective.** Show that an *interpretation* — a name, a role, a purpose — is supported, rather than merely
plausible.

**Required inputs.** The structural and format facts (§3, §4); a discriminator that separates the proposed
interpretation from its plausible alternatives.

**Expected outputs.** Interpretations each carrying an attributed source, and an explicit separation between
what was measured and what was read.

**Evidence requirements.**
- An interpretation must be **attributed**: transcription from a citable source, inference from observed
  behaviour, or measurement by this project. The reference project's opcode names carry exactly this split: 45
  opcode keys transcribed from an MIT-licensed table, with the source, file and method recorded in the artefact's
  own `attribution` block (`fixtures/scd/opcodes.json`), and 17 further names inferred by this project and printed
  with a marker prefix (`fixtures/scd/inferred_names.json`). **The count is quoted from the artefact, not from the
  prose** — the handover says 43, and no file states the counting rule that would reconcile 43 with 45 (recorded
  as an unresolved candidate in [`ARCHAEOLOGY.md`](ARCHAEOLOGY.md) §6).
- A discriminator, not a consistency check. "The decoder produces audio" is weak; "the *shared* codebook
  produces audio where a per-sample codebook does not" discriminates.
- Cross-prediction where possible: one independently parsed field predicting another across many samples. The
  reference project's strongest semantic result is of this form — a flag bit predicting a clip's declared rate
  on 673 of 674 entries.

**Verification requirements.**
- A source-shape case pinning the interpretation where the interpretation rests on code shape.
- A refusal recorded in the artefact where no discriminator exists.

**Failure conditions.** A name adopted because it is conventional; an interpretation promoted from a description
rather than measured; a role asserted without an alternative excluded.

**Completion criterion.** Every interpretation is attributed and, where claimed, discriminated; the rest are
recorded as unresolved.

**Unknown and incomplete states.** "The cartridge never labels it" is a valid terminal state, and the reference
project uses it: a 16-byte parameter record has its fields and role measured but stays unnamed because nothing
in the artefact names it.

**Reference practice.** All 12 behaviourally-pinned functions remain `FUN_…`; 17 opcode names are printed with a
marker showing they are inferred; one field is closed as "Unassigned" with the reason it needs "a code path, the
voice codec, or an analogue, not another test".

---

## 7. Reconstruction equivalence

**Objective.** Demonstrate that a produced artefact is equivalent to the original — byte-identical where that
is the goal, behaviourally indistinguishable where it is not.

**Required inputs.** A candidate artefact; the original region; a comparator that is itself verified.

**Expected outputs.** A per-region match report naming the **first** differing unit, not a hash; a residue
published as a fraction; and a statement of which equivalence standard was applied.

**Evidence requirements.**
- The comparator is proved in two directions before it is trusted: a self-compare must reach 100.000 %, and a
  one-unit perturbation must be located. The reference project requires both and states why the self-compare is
  "not a tautology, because the two sides are read by different code paths".
- Equivalence is reported at the granularity that is claimed. Byte equality, instruction equality and
  behavioural equality are three different claims.
- A residue is published as `N of M`, never as a percentage rounded to one.

**Verification requirements.**
- The first difference is located and attributed, not merely counted.
- A partial equivalence states which parts are covered and which are not.
- The build that produced the candidate is pinned: toolchain identity, version, flags, and the fact that the
  toolchain itself was shown to reproduce the target's idioms.

**Failure conditions.** A hash comparison with no located difference; a percentage that rounds a residue to
complete; a comparator never shown to detect a perturbation.

**Completion criterion.** For matching decompilation: every function either matches or is published with its
residue and the attributed cause. For behavioural equivalence: an equivalence relation stated and tested.

**Unknown and incomplete states.** "Recovered, not exact, and why" is a completion state for one function. The
reference project publishes one at 226 of 229 words with the three differing words decoded and the reason the
remainder is unreachable from source shape.

**Reference practice.** 15 functions byte-exact; one at 226/229 with the residue decoded; a comparator proved by
self-compare and perturbation; a toolchain identified by *refuting* the alternatives against a codegen census
rather than by preference.

---

## 8. Native portability

**Objective.** Re-express the reconstructed semantics for another host, with equivalence demonstrated rather
than asserted.

**Required inputs.** A semantic model that does not depend on the original memory layout; a target host; an
equivalence test.

**Expected outputs.** A port, plus a statement of which layers port and which do not.

**Evidence requirements.**
- Layering is declared, and each layer's claims are bounded. The reference project's three-layer split is the
  model: a decoder that claims instruction boundaries and successors and **no gameplay effect**; a semantic
  interpreter that claims effects on an explicit state model and **nothing about the original's memory layout**;
  a host layer that is out of scope.
- A refusal class distinct from an unknown encoding: a *known* instruction whose effect is unknown must raise a
  distinct refusal, never become a no-op. The reference project states this as a rule because it caught the
  opposite twice in its own tooling.

**Verification requirements.**
- The port's behaviour is compared against the original's measured behaviour, not against the reconstruction's
  prose.
- Any state the port invents is declared.

**Failure conditions.** A port that silently treats an unimplemented effect as a no-op; a semantic layer that
claims fidelity to the original's layout; behavioural equivalence asserted from a shared code ancestry.

**Completion criterion.** An equivalence relation defined and tested for the declared layer; broader layers
declared out of scope.

**Unknown and incomplete states.** This dimension is the least exercised in the reference project — it declined
the third layer explicitly rather than half-doing it — so its requirements here are the weakest-supported in
this document and should be treated as the most provisional.

---

## 9. How the dimensions interact, and what may not be inferred

```
identity (§1)  →  inventory (§2)  →  structure (§3)
                        ↓                  ↓
                    formats (§4)  →  semantics (§6)
                        ↓                  ↓
                  behaviour (§5)  →  equivalence (§7)  →  portability (§8)
```

Three non-entailments, each of which the reference project has to state explicitly because the opposite is the
natural reading:

1. **Inventory ≠ understanding.** 3416/3416 indexed and 33 named.
2. **Structure ≠ semantics.** 3329 functions with every call target resolved and 12 with behaviour pinned.
3. **Equivalence ≠ portability.** A byte-exact function does not imply a portable model of it; the port needs
   an explicit state model, which the matching build does not produce.

A report should state, per objective (§0.2), which dimensions are being claimed. A project pursuing discovery
claims §1 and §2 and may publish §3 as a by-product; it must not present §6 as achieved on the strength of §3.
