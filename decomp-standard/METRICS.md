# METRICS — measurable reconstruction coverage and assurance reporting

**Status.** The *dimensions* (§2) are **derived from a working implementation** — the reference project
publishes most of them today. The *requirements* (§1, §4) and the *anti-patterns* (§5) are a **proposal**,
motivated by named defects in that implementation. Every worked example below carries a measured value from
this machine; every proposed metric is marked as having no implementation.

The rule the whole document serves:

> **Do not create one misleading percentage that combines unrelated dimensions.**

---

## 1. Requirements on every metric

A number without all six of these is a slogan, not a metric.

| # | requirement | the question it answers |
|---|---|---|
| 1 | **precise definition** | what exactly is counted |
| 2 | **denominator** | counted over what population |
| 3 | **inclusion and exclusion policy** | what is in, what is out, and why |
| 4 | **reproducible calculation** | the command, or the artefact, that yields it |
| 5 | **what it does not measure** | the non-entailment |
| 6 | **derivation** | the number is computed from an artefact, never typed |

Requirement 6 is the one that separates a metric from a habit, and the reference project states the reason in
its own incident record: a coverage figure was quoted for **93 milestones** without being recomputed, while
the artefact underneath it was correct and the sentence above it was stale
(`ARCHAEOLOGY.md` §6). The fix it adopted — derive the number in one place and assert every quoting site
against it, with a deleted phrase counted as a failure — is requirement 6 plus a consistency check.

**Proposal:** requirement 6 should extend past "derived" to "derived *and* functionally defined". The failure
mode that survives derivation is two derivations of the same concept disagreeing. See §5.1.

---

## 2. The dimensions

Eleven dimensions. They are **not** commensurable and must never be summed. Each row states the reference
project's measured value where one exists.

### 2.1 Artifact inventory coverage

*What fraction of the artefact's bytes have been accounted for at all?*

| field | value |
|---|---|
| definition | bytes assigned to a named class by a total partition |
| denominator | every byte of every loadable image |
| exclusions | bytes outside the image set (e.g. inline media) — **stated, not silently dropped** |
| reference value | **1 947 632 / 1 947 632** image bytes partitioned into 5 classes (`manifests/byte_map.json`) |
| does not measure | whether the classification is *correct*; only that every word has a class |

The reference project's partition, measured: `function_body` 1 210 600 B, `padding` 407 608 B,
`unclassified` 321 820 B (16.5 %), `data_named` 6 640 B, `jump_table` 964 B. The classes sum exactly to the
denominator, and **overlaps are counted separately rather than hidden** (`overlaps.padding_in_body` etc.).

The important property is that the residual is *published*. A partition whose classes are
`{code, other}` would satisfy "coverage = 100 %" and say nothing. The reference project forbids renaming
`unclassified` to `data` on a hunch, and gates that prohibition with a mutation.

### 2.2 Executable classification coverage

*Which regions have been established as code, as data, or as neither — and on what evidence?*

| field | value |
|---|---|
| definition | regions classified per *class*, each class naming the evidence that put it there |
| denominator | the image bytes of §2.1 |
| reference value | 62.2 % inside a known function body; 16.5 % unclassified |
| does not measure | semantic understanding (§2.4), or whether the function bodies are correct |

**This is where the reference project's most instructive denominator defect lives.** Its headline figure is
*image* bytes inside a known body — not "code bytes", because nothing in the project classifies code
independently. The distinction was a correction: the earlier phrasing read as though the unmapped tail were
not code, "which is precisely the judgement the census refuses to make".

### 2.3 Function inventory coverage

*How many functions are known, out of what population?*

| field | value |
|---|---|
| definition | distinct functions with a recorded identity (image + address) and an extent |
| denominator | functions *in the target* — which is not directly observable, so it is bounded by an independent discovery method |
| reference value | **3416 functions over 3678 ranges**, plus **174** switch-case bodies counted separately |
| exclusions | the 174 provider-labelled case bodies — code, inside the ranges and the byte total, but reachable only through their owner's table |
| does not measure | completeness. The denominator is not known |

The honest form of this metric is a **census with a stated discovery method**, not a percentage. The reference
project runs a second discovery pass against the first (`find_missed_functions.py`) and publishes the residue:
265 runs / 24 candidates, revised to 437 runs / 1 candidate, and that one candidate is *evaluated and accepted,
not added*, with the reason recorded. It also publishes a **failed** heuristic rather than tuning it away:
`manifests/code_census.json` carries a self-test with 1 match out of 35, i.e. the base-derivation does not work
on this cartridge and the artefact says so.

> **A project with 100 % function inventory coverage must not automatically claim 100 % semantic
> understanding.** The reference project demonstrates the trap in its own ladder: 3416 functions indexed, 3416
> decompiled, 3329 with every call target resolved — and **33** with a name, **12** with behaviour pinned by
> evidence. Inventory is not understanding, and the gap between 3329 and 12 is the project's most useful
> published number.

### 2.4 Structural reconstruction coverage

*How much structure is known — call graph, CFG, extents, dispatch tables — and with what evidence per edge?*

| field | value |
|---|---|
| definition | structural facts published, each carrying its evidence class |
| reference value | call graph: 3416 nodes, 15 535 edges, each graded `jal` / `tail` / `jalr-resolved` / `table-dispatch` / `callback` |
| does not measure | that an edge exists in the original program — an edge may be a plausible mis-attribution |

The metric that matters here is not the edge count but the **refusal count**: how many sites the analysis
declined to resolve, and why. Measured from the committed artefact: **684 of 15 535 edges** carry `dst: null` with a
`why` rather than an invented table bound, and **250 of 517** recorded table bases carry `"bound": null,
"bound_src": "none"` rather than a guessed length (`manifests/call_graph.json`).

### 2.5 Format reconstruction coverage

*How many formats are decoded, and to what standard?*

| field | value |
|---|---|
| definition | per format: identified, law stated, law verified on N/N members, fields named vs unnamed |
| reference value | T64 texture: length law verified on 65/65 tiles; script VM: 141 opcodes with 18 distinct lengths; sample codec: 217 944/217 944 groups valid |
| does not measure | whether the *interpretation* of a field is right — a field may be correctly located and wrongly named |

The unit here is **per-format**, never an average over formats. Averaging "how decoded is this binary" across
a texture container, a script VM and an audio codec produces a number with no referent.

### 2.6 Behavioural verification coverage

*How much observed behaviour is pinned by execution, rather than by reading?*

| field | value |
|---|---|
| definition | functions or subsystems whose behaviour is pinned by an executed experiment, each citing its evidence |
| reference value | **12 of 3416** (`manifests/analysis_status.json` → `validated`) |
| does not measure | correctness of the 12; each is pinned by its own experiment with its own scope |

Note the reference project's discipline: all 12 are **still named `FUN_…`**, because naming is a separate
evidentiary act. Behaviour verified, name inferred — two dimensions, both published, neither promoted.

### 2.7 Evidence completeness

*Does every claim point at evidence?* **Proposed; no implementation.**

| field | value |
|---|---|
| definition | fraction of claims whose `evidence` is non-empty and whose `method` names a reproducible procedure |
| denominator | claims in the index |
| reference value | not computable — there is no claim index (`EVIDENCE_MODEL.md` §1) |
| does not measure | whether the evidence supports the claim |

The reference project achieves this *by convention* and it is largely true of its notes. The metric exists to
make the residue visible, and to stop a claim losing its evidence during a rewrite.

### 2.8 Verification coverage

*What fraction of claims are backed by a case that could fail?*

| field | value |
|---|---|
| definition | claims with a case, over claims |
| reference value | partially computable today: 73 suites / 1028 cases exist, but the mapping from *claim* to *case* is prose |
| does not measure | whether the cases are aimed at the claims they are attached to |

### 2.9 Mutation audit coverage

*What fraction of gates have been shown capable of failing?*

| field | value |
|---|---|
| definition | gates with a detected mutation, over gates |
| reference value | **146 mechanisms audited**; on this machine 39 detected, 107 skipped (no cartridge) |
| does not measure | whether the gates are the right gates — see `VERIFICATION_STANDARD.md` §5.2 |

Publish `vacuous` and `broken` alongside, never folded in. A mutation-coverage figure of 146/146 that includes
49 entries which never ran is the defect this metric exists to prevent, and the reference project published
exactly that number before discovering it.

### 2.10 Outstanding unknowns

*What is known not to be known?*

| field | value |
|---|---|
| definition | enumerated unknowns, each with a scope and why it is currently undecidable |
| reference value | e.g. `16.5 %` of image bytes unclassified; the 16-byte class-3 sound record unnamed; `u16@+4` unassigned for a period before it was decided |
| does not measure | anything about coverage — this is an inventory of questions |

This dimension is a **first-class metric**, not a footnote. The reference project ranks it highly: the
recording of what a measurement does *not* establish is what made its negative results reusable, and
`docs/log/M190-*.md` closes a field with the word "Unassigned" plus the reason it needs "a code path, the voice
codec, or an analogue, not another test".

### 2.11 Skipped and blocked tests

*What could not run here?*

| field | value |
|---|---|
| definition | cases and audits reported `SKIP` or `BLOCKED`, by reason |
| reference value | **742 cases / 41 suites** skipped; **107 of 146** audit entries skipped; `coverage: partial` |
| does not measure | anything about the target |

Non-negotiable: **this number must be reported with every verdict**, and a claim resting on a skipped case is
`INCONCLUSIVE`. The reference project emits it as a field of the report rather than a footnote.

---

## 3. Denominator policy

Four rules, each earned by a defect.

**3.1 State the denominator in the metric's name, not in a footnote.** "62.2 % of *image* bytes inside a known
body" is a metric. "62.2 % understood" is a claim wearing a metric's clothes, and this project corrected
exactly that phrasing.

**3.2 Different populations may legitimately give different counts of one noun.** Measured, on this machine:
`tools/` holds **102** files and `counts.py` reports **100** tools, because it counts non-recursively and
excludes two files under `tools/toolchain/`. Both are correct; neither the file nor the document states the
definition. **Publish the definition.** A reader who finds 102 and reads 100 has no way to tell which is wrong.

**3.3 A count of *kinds* must state its deduplication rule.** The reference project ships 229 note files, 228
distinct note numbers (M2 has two notes), and 227 note numbers cited by a milestone row — and three documents
quote three different figures for "notes", each correct under its own definition, with no file defining it.

**3.4 Exclusions are published, not applied silently.** The 174 switch-case bodies are excluded from the
function count *and* included in the byte total and the range count, and every document says so. An exclusion
that is not stated is a denominator defect.

---

## 4. Reporting requirements

### 4.1 Never one number

A single "reconstruction completion %" is forbidden. It cannot be defined, because the dimensions are
independent: a project can have 100 % inventory and 0.4 % matching (the reference project does: 3416/3416
indexed, 15 byte-exact).

### 4.2 Always with coverage

Every report carries its coverage state: `full`, `partial`, or `reduced`, plus the reason. The reference
project's report emits

```
verdict   PASS
coverage  partial
note      cartridge-gated suites SKIPped: any claim that depends on them is INCONCLUSIVE here
```

and its stored report records `admissible: true` alongside `skipped_no_cartridge: 107`. A verdict without a
coverage statement is non-conforming.

### 4.3 Residues are published as residues

Publish the fraction, never the ratio. The reference project publishes `226 of 229 words`, not 0.99, and
publishes `94/98` for a permuter plateau rather than calling it converged. Rounding a residue to 1.0 is the
cheapest available lie and the hardest to notice.

### 4.4 A negative result is a metric

Counts of *disproved* things — a refuted hypothesis, a decoder refusal, an unassigned field — belong in the
report. The reference project publishes: 86 dispatch heads of which 6 refuse; 256 rooms of which 57 refuse and
90 have no block; 0 of 588 clips showing a loop discontinuity. Each is a measurement, and each closes a
question that would otherwise be re-opened.

---

## 5. Anti-patterns, with instances

### 5.1 Two derivations of one quantity, unreconciled

**Measured on this machine.** "Bytes inside a known function body" has two committed values:

| artefact | value |
|---|---|
| `manifests/code_index.json` → Σ `covered_bytes` | 1 211 256 |
| `manifests/byte_map.json` → Σ `function_body` | 1 210 600 |
| difference | 656 B |

Both are internally pinned; the documents quote the larger. The cause is input divergence (recovered extents
applied on one path and not the other). **Neither number is wrong, so no gate fires** — the gate architecture
asserts each number against its own artefact, which is structurally incapable of noticing that one concept has
two values.

**Mitigation (proposal):** a metric has an identity, not just a derivation. If two artefacts claim to measure
the same metric identity, a check asserts they agree or that a documented transformation relates them.

### 5.2 A stale number inside a gated document

**Measured.** `tools/counts.py` gates `.github/workflows/acceptance.yml` lines 6, 7 and 9. The same file
carries "the 109 skipped cases" at line 12 (the registry says 742) and "silently skipped 11 suites" at line 65
(41). `README.md:52` says "286 of 1 022" while line 6 of the same file says 1028. Fourteen such documentation
figures exist — plus a fifteenth that is worse, because it is not documentation at all: `fixtures/sound/codec.json`
carries `mort_header_bytes: 16`, a value the retraction table marks as withdrawn in favour of 12, and the gate that
should catch it compares the fixture against a **hand-typed literal** (`"mort_header_bytes": 16` in
`tools/file_table.py`), so it verifies consistency rather than correctness. It is in the same file that documents
the retraction that withdrew the value.
the full table is `ARCHAEOLOGY.md` §6.

**Mitigation:** V11 in [`VERIFICATION_STANDARD.md`](VERIFICATION_STANDARD.md) — bind the *quantity*, asserting
every site, not the *phrase* at one site.

### 5.3 A percentage over incommensurable dimensions

Never publish "understanding %". If a composite is required for a dashboard, publish its components and let
the reader see them; the reference project's generated progress map does exactly this — one cell per function
group, shaded by one property (matched / recovered / pseudocode only), with the three-state legend printed
beneath it.

### 5.4 A denominator that is not the population

The reference project's `62.3 %` was "of *code* bytes" over a denominator that was image bytes, and neither
the project nor a reader could have known that from the sentence. Fixed by renaming the metric.

### 5.5 Completion inferred from silence

A dimension with no failing case is not complete; it is unmeasured. The reference project has two subsystems
with **no registered suite at all** (`tools/diff_rdram.py`, `tools/ares_rsp.py`). Reporting them as anything
better than unmeasured would be the defect of §5.5. They should appear in the report as `no coverage`.

---

## 6. Minimum viable reporting

If only part is built, build this, in this order:

1. **§2.11 with every verdict** — skipped and blocked, counted, with the coverage state. One field. It
   prevents the worst outcome, which is a green report over a subset.
2. **A denominator sentence per metric** — §3.1. Costs a sentence each; eliminates the most common misreading.
3. **§2.1 and §2.2 with a published residual** — the partition with its `unclassified` bucket. This is the
   cheapest honest coverage in the whole set.
4. **§2.3 as a census with its discovery method and its excluded class**, never as a percentage.
5. **§2.6 as a small curated list with per-entry evidence** — 12 entries is achievable on day one and is the
   only dimension that speaks to behaviour.
6. **§2.9 with `vacuous` and `broken` reported separately.**

Everything else can wait. Notably, the *numbers* are the cheap part; the expensive part is stating what each
number does not measure, and that is the part that makes the report defensible.
