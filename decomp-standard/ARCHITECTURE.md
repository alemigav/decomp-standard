# ARCHITECTURE — generic core, target adapters, reference implementations

**Status.** A **proposal**, and the most speculative document in this set. The boundary below is drawn from
evidence about which parts of the reference implementation actually transfer (`EXTRACTION_MAP.md` classifies all
102 files), but no core exists, nothing has been built, and **the case for building a core at all is
deliberately weak** (§6).

The governing constraint, from the mission that produced this document:

> Do not introduce unnecessary abstraction. Do not rewrite working RE2 tooling simply to make it look generic.

---

## 1. The question this document answers

The reference project's methodology transfers; its files largely do not. Every analysis tool hardcodes this
target's constants — the mapping law `0x7FFFF480`, the handler table at `0x80113898`, the command pointer
`ctx+0x1c`, the stage-2 member's filename. The *mechanisms* are portable; the *code* is welded.

So the architectural question is narrow: **what is the smallest boundary that lets a second target reuse the
methodology without re-deriving it, and without forcing the first target's tools to be rewritten?**

The answer proposed here is deliberately conservative: **a data-and-contract boundary, not a plugin
architecture.**

---

## 2. The four layers

```
┌──────────────────────────────────────────────────────────────────┐
│  L4  project configuration        per-project; declarative        │
│      artifact ids, region inventory, suite registry,              │
│      metric identities, quoting sites                             │
├──────────────────────────────────────────────────────────────────┤
│  L3  target adapter               per-target; code + data         │
│      ISA or format semantics, address model, discovery,           │
│      named constants, boundary heuristics                         │
├──────────────────────────────────────────────────────────────────┤
│  L2  generic core                 target-neutral; small           │
│      adjudication, mutation harness, ratchet, metric derivation,  │
│      claim/evidence store, reporting                              │
├──────────────────────────────────────────────────────────────────┤
│  L1  evidence records             committed data; no code          │
│      claims, evidence refs, artefacts, run records                │
└──────────────────────────────────────────────────────────────────┘
```

The direction of dependency is downward only. **L2 knows nothing about L3's target**, and L3 knows nothing about
L4's project. A second target at L3 reuses L1 and L2 unchanged.

### 2.1 What is actually in L1 — and why it is the real deliverable

L1 is the part with the strongest evidence behind it, because it is mostly a formalisation of artefacts the
reference project already commits:

| L1 record | formalises | existing precedent |
|---|---|---|
| **artifact** | id, sha256, size, accepted representations, input hash for derived artefacts | `manifests/manifest.json` (`rom_sha256`), `fixtures/decomp/images.json` |
| **region inventory** | `[start, end, class, source]` ranges, overlaps, residual | `manifests/byte_map.json` |
| **census** | a table of same-shaped facts with one method (function extents, operand provenance) | `fixtures/decomp/ranges.json`, `manifests/provenance.json` |
| **claim** | statement, state, scope, `does_not_say`, `supported_by`, `supersedes` | prose in `docs/log/`, in fields today |
| **evidence ref** | `byte_range` / `tool_run` / `artifact` / `execution` / `source_reading` | the `.c` header's four-field provenance; `checkpoint/run_digest.json` |
| **run record** | tool id, version, argv, exit, verdict, coverage | `build/verify-report.json`, `build/verify-cert.json` |
| **refusal** | scope, reason, why currently undecidable | `refuses` / `unresolved` / `not_claimed` fields in six manifests |

**The single most important observation about L1:** the reference project's artefacts already carry most of these
fields *ad hoc*, and the fields that exist — `refuses`, `unresolved`, `not_claimed`, `rsp_only` — are the ones
that make its negative results reusable. Standardising them is a schema exercise with a demonstrated payoff, not
a speculative one.

### 2.2 What is in L2 — deliberately small

L2 is the machinery whose *logic* is target-neutral. Measured against the reference implementation, it is four
things and it should stay four things:

| L2 component | responsibility | why it is target-neutral |
|---|---|---|
| **adjudicator** | turn a set of procedure outcomes plus an audit state into one verdict, in a fixed branch order | the branch order is doctrine, not domain |
| **mutation harness** | build a throw-away tree, run a positive control, apply one exact replacement, require failure, report detected/vacuous/broken | the mechanism is disable-and-require-failure; only the anchors are target text |
| **ratchet** | bind a registry to a baseline; forbid silent change in either direction; hash a frozen subtree | any registry, any frozen population |
| **metric derivation + site assertion** | derive a number once from a registry, assert every quoting site, treat a deleted phrase as a failure | pure text-and-graph work |

Plus two smaller pieces with clear precedent:

- **report/coverage emitter** — the verdict *and* the coverage state, with skipped and blocked counted.
- **claim/evidence store** — the least proven component; see §6.

### 2.3 What is in L3 — the adapter

An adapter supplies exactly what the core cannot know. Proposed interface, and the discipline is that it is
**data-heavy and code-light**:

| the adapter provides | example value from the reference target |
|---|---|
| artifact identity rules | magic `80 37 12 40` and its two byte-swapped forms; expected sha256 |
| normalisation | byte order detection and conversion |
| address model | `vram = rom_offset + 0x7FFFF480`; images with base ranges; the rule that refuses an ambiguous address |
| region inventory method | the discovery signals, and what counts as a class |
| boundary heuristics | prologue shape; extent rules; and **their known failure modes** |
| format validators | per format, a two-directional validator |
| effect semantics | instruction or opcode semantics for any execution model |
| the constant corpus | named addresses, tables, offsets — as data, with provenance |
| the suite registry | each check: invocation, expected case count, artifact dependence |
| the mutation set | each mutation: target file, anchor, replacement, the case it must break |
| metric identities | the name of each quantity and which artefact derives it |

**The adapter is where every target-specific fact lives, and it should be inspectable as data.** A test for a
correct boundary: *could a knowledgeable person with no access to the core read the adapter and check it against
the artefact?* For the reference project, that is largely already true of `manifests/` and `fixtures/`.

### 2.4 What is in L4 — the project configuration

The per-project declarations that make a run reproducible: which artifact, which adapter version, which suites
are required versus optional in this context, and which documents quote which metrics. The reference project's
`fixtures/gates/ratchet.json` and `tools/counts.py`'s pattern list are L4 material today, embedded in code.

---

## 3. The boundary test

A component belongs in L2 if and only if **all three** hold:

1. Its logic contains no target-specific constant.
2. It has a **demonstrated second use** — either already used by two subsystems in the reference project, or with
   a concrete second target in view.
3. Its input can be expressed entirely in L1 records.

Criterion 2 is the one that keeps the core small, and it is meant to fail often. Applied honestly to the
reference implementation:

| candidate | verdict |
|---|---|
| adjudicator (`verify.py` `adjudicate()`) | **L2** — a pure function, branch order is doctrine, no domain constants |
| mutation harness (`audit_gates.py` `run_audit`) | **L2** — the sandbox/control/mutate/judge cycle has no domain content |
| ratchet invariants (`ratchet.py`) | **L2** — three invariants over a registry and a tree hash |
| metric derivation (`counts.py` `derive()`) | **L2 in shape, L3 in content** — the mechanism is generic; the 31 derivations are this target's |
| site assertion (`counts.py` `CHECKS`) | **L2 in shape, L3/L4 in content** — the patterns are target text |
| suite registry (`acceptance.py` `SUITES`) | **L4** — 73 entries of this project |
| mutation set (`audit_gates.py` `AUDITS`) | **L4** — 146 anchors into this project's source |
| preflight tier (`preflight.py`) | **L2** — "run the cheap checks first, and say a pass is not admission" |
| certificate (`hook_cert.py`) | **L2 as-is** — worktree content hash; nothing domain-specific |
| `patch_text.py` | **L2 as-is** — atomic exact-replacement, count-checked |
| `vaddr.py` | **L3** — the discipline is generic; `0x7FFFF480` is not |
| `provenance.py` | **L3** — the lattice is generic, the ISA tables are not |
| `classify_image.py` | **L2 rule / L3 signals** — the partition discipline is generic, the padding law is a parameter |
| `mips_harness.py` | **L3** — an ISA harness is the textbook adapter |
| `matching` tools (`compile_probe`, `match_diff`) | **L2 comparator contract / L3 toolchain profile** |

The right-hand column is the extraction map in miniature; the authoritative per-file classification is
[`EXTRACTION_MAP.md`](EXTRACTION_MAP.md).

---

## 4. What the core must not contain

Stated as prohibitions, because each is a mistake the reference project's shape invites:

1. **No architecture, ISA, console, format or vendor names.** Not even behind a flag.
2. **No path or filename conventions.** `rom/`, `assets/`, `build/` are L4.
3. **No tool invocations.** The core must not know that a check is `python3 tools/foo.py --check`; it must know
   that a check is *a command with an expected case count and a verdict line*.
4. **No verdict vocabulary beyond the six outcomes.** If a target needs a seventh, the model is wrong.
5. **No metric definitions.** Only the requirement that a metric have a definition, a denominator, and a
   non-entailment.
6. **No dependency on a decompiler, an emulator, or a disassembler.** All three are adapter choices.

A useful enforcement: the core's own test suite must be runnable with **no target artefact present at all**. The
reference project already achieves this for its repository-only tier (286 cases), which is the existence proof
that such a core is possible.

---

## 5. Where the reference implementation already *is* the architecture

Worth stating plainly, so the proposal is not mistaken for a redesign:

| architectural idea | already true of the reference project |
|---|---|
| one registry, three consumers | `SUITES` drives execution, metrics and the ratchet |
| evidence with the artefact | the four-field provenance header on 3590 `.c` files |
| refusals as first-class records | `refuses` / `unresolved` / `not_claimed` in six manifests |
| content-addressed state | `checkpoint/run_digest.json`, `build/verify-cert.json` |
| tiering by measured cost | preflight / integration / admission, with the four expensive suites named by measurement |
| a verifier tested against its own branches | `verify.py --self-test`, 8 cases, one per branch |
| generated documentation numbers | `counts.py` derive + assert |

The core abstraction would give these five things a shared vocabulary and a second consumer. It would not
change how the reference project does them.

---

## 6. The case against building the core

Recorded at the same weight as the case for, because it is currently the stronger case.

1. **One instance is not a boundary.** Every component proposed for L2 is defined by reference to a single
   implementation. The extraction map classifies 102 files and finds 9 that are reusable *as-is* — and most of
   those (a text patcher, a worktree hasher, an ELF wrapper, an OCR script) are peripheral to the methodology.
   The high-value components are exactly the ones welded to this project's content.

2. **The abstraction may cost more than it returns.** The reference project's discipline is 1136 lines of audit
   harness, 391 lines of registry, 353 lines of count derivation. A generic core would need interfaces,
   versioning, and its own mutation audit — and its consumers would number one.

3. **The transferable asset is documentation, not code.** The parts of this standard that a second project
   genuinely needs — the state vocabulary, the eight dimensions, the denominator rules, the retraction format —
   are prose and schema. A project can adopt them with no shared code at all.

4. **The failure mode of over-abstraction is specific and known here.** The reference project's own advice for
   anyone recovering code: "lay down new evidence, then run `--write` and let the count change show in the diff.
   Do not lower a number to make a run green." A generic core adopted before a second target exists would
   institutionalise exactly one target's accidents as though they were principles.

**The recommendation is therefore: build L1 and L4 as schema, keep L2 as a specification with the reference
implementation as its executable example, and defer L2 code and all of L3 until a second target exists.**

This is reflected in [`ROADMAP.md`](ROADMAP.md) and in the explicit "do not build yet" list in
[`EXECUTIVE_REPORT.md`](EXECUTIVE_REPORT.md).

---

## 7. If a second target arrives, the first three things to do

Not a plan — a test for whether the boundary is real. In order:

1. **Write the adapter for the second target as data only.** If it cannot be expressed as data, the boundary is
   in the wrong place, and the correct response is to move the boundary rather than to add code to the core.
2. **Run the reference implementation's mutation harness against the second target's registry, unchanged.** The
   harness is the most target-neutral component and therefore the sharpest test of the boundary.
3. **Attempt to state the second target's metrics in the same identities as the first.** If the identities do
   not transfer, they were target concepts wearing generic names — which is the failure the reference project
   itself caught when it discovered that "validated" was not a rung above "named" but an orthogonal axis.

If step 1 fails, stop: the conclusion is that this methodology is portable as *practice* and not as *code*, and
the standard should say so rather than grow an interface.
