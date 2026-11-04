# Repository archaeology — `re2-64-decomp`

What this document is: the measured state of the reference project, established by reading files and running
cartridge-free checks. It is the evidence base for every other document in `decomp-standard/`.

**Status of every statement below.** Three markers are used throughout:

- **MEASURED** — I ran a command and quote its output.
- **READ** — I read the file; the claim is about what the file says or contains. *Not* proof that the claim in
  the file is true.
- **INFERRED** — a conclusion drawn from the above, not itself verified.

The distinction matters more than usual here, because the repository's own thesis is that a claim is not
verified because it was written down. Applying that rule to the repository itself is the first act of this
document.

---

## 1. What was done, and what was deliberately not done

The environment has **no cartridge**. A dump exists elsewhere on this machine, and the mission forbids using
it, so it was not copied, opened or hashed into place. That decision has a precise consequence, stated in §4:
the 742 cartridge-gated cases are **UNAVAILABLE**, which is not the same as failed.

| action | result |
|---|---|
| `git clone` of `alemigav/decomp-stardard`, private, `admin` | tree at `141b644 Initial commit`; its tree hash equals the public `alemigav/re2-64-decomp` at `55296b0` — **the content is a verbatim snapshot of M303/M304 with history squashed** (MEASURED: identical `git rev-parse HEAD^{tree}`, and `comm` shows 0 files unique to either side out of 4020) |
| `python3 tools/verify.py --full` | **VERDICT PASS**, gate audit `39/39`, `0 vacuous`, `0 broken`, `107 skipped` (MEASURED) |
| `python3 tools/counts.py --derive` | 31 derived numbers (MEASURED; §2) |
| `python3 tools/counts.py --check` | `25/25` (MEASURED) |
| `python3 tools/check_markers.py` | `22/22` (MEASURED) |
| reading tools, docs, manifests, fixtures | 102 files under `tools/`, 229 notes under `docs/log/`, 30 manifests, 3590 `.c` files under `src/` |

The three-state consequence, using the project's own vocabulary:

- **PASS** — the repository-only tier, and the gate audit over the 39 audits that could run here.
- **SKIP** — 742 cases across 41 suites, plus 107 of 146 audit entries, unavailable for want of the cartridge.
- **Basis for the rest of this document** — *structural and methodological* claims only. No claim below
  depends on cartridge bytes. Where the project asserts a fact about RE2 itself, this document records that
  the project asserts it and by which procedure, and does not restate it as established.

---

## 2. The verified numbers, and the one that does not reconcile

Derived from `tools/counts.py --derive` (MEASURED). These are what the project's own registry says about
itself; they are quoted rather than recomputed where the derivation is the project's own.

| quantity | value | derived from |
|---|---|---|
| suites / cases | **73 / 1028** | `tools/acceptance.py` `SUITES` |
| runnable without the cartridge | **32 suites / 286 cases** | the `needs_rom=False` subset |
| gated on the cartridge | **41 suites / 742 cases** | the `needs_rom=True` subset |
| mutation-audit entries | **146** | `len(tools.audit_gates.AUDITS)` (MEASURED independently) |
| documentation marker cases | 22 | `tools/check_markers.py` |
| milestone numbers / with a row / gaps | 305 / 249 / 56 | log + `fixtures/milestones/gaps.json` |
| notes in `docs/log/` | 229 | the directory (MEASURED: `ls docs/log | wc -l`) |
| tools | 100 | non-recursive count of `.py`/`.sh`/`.c`/`.swift` in `tools/` |
| images | 36 | boot + stage-2 + 34 overlays |
| image bytes | 1 947 632 | `fixtures/decomp/images.json` |
| functions / ranges / switch-case bodies | 3416 / 3678 / 174 | `manifests/code_index.json`, `src/` |
| `.c` files under `src/` | 3590 | MEASURED (= 3416 + 174) |

Two denominator collisions are worth recording, because both are live in the documents:

**2.1 `tools/` is 100 or 102 depending on the path.** `find tools -type f` returns **102**; `counts.py`
returns **100** because it iterates `tools/` non-recursively and therefore excludes the two files under
`tools/toolchain/`. Both are correct under their own definition; neither file states the definition
(READ: `tools/counts.py:133`). This is harmless here and instructive for the standard — see
[`METRICS.md`](METRICS.md) §3.

**2.2 "Bytes inside a known function body" has two values, and the documents quote the larger.**
MEASURED, by summing the committed artefacts:

| source | value |
|---|---|
| `manifests/code_index.json` → Σ `covered_bytes` | **1 211 256** |
| `manifests/byte_map.json` → Σ class `function_body` | **1 210 600** |
| difference | **656 B** |

The README and handover quote 1 211 256 (`docs/handover.md:24`, gated by `tools/counts.py`). The
`classification` artefact — the one that partitions *every word of every image* — carries 1 210 600 and
`tools/classify_image.py` pins that number. The difference is explained by input, not by error: the
recovered-function extents in `fixtures/decomp/recovered.json` are applied on the `export_src.py` path and
not on the `export_ranges.py` path **(INFERRED from reading both call sites; consistent with the M289 and
M297 log rows, READ)**. Both numbers are internally pinned; the two definitions of one quantity are not
reconciled anywhere. No suite fails, because each number is asserted against its own input.

This is the single most useful defect the archaeology found: it is *not* a wrong number, it is a quantity
with two definitions, and the gate architecture — which binds each number to its own artefact — is
structurally incapable of noticing.

---

## 3. What the verification system actually is

Five tools, in dependency order. Everything else in the repository is analysis; these are the machinery that
decides whether analysis is admissible.

### 3.1 `tools/acceptance.py` — the registry (391 lines, READ)

A declarative list of 73 `(name, command, expected_case_count, needs_cartridge)` tuples. It runs each as a
subprocess, parses the **last** `N/M` line of its output, and accepts the suite only when
`exit == 0 and passed == total and total == expected`. One line per suite **in registry order**, which the
docstring states as a contract: "a run at JOBS=4 must print exactly what JOBS=1 prints, byte for byte".

Three design decisions that generalise:

1. **The expected count is pinned per suite**, so a fixture that silently loses cases fails.
2. **A suite that exits 0 without printing `N/M` is a FAIL**, not a pass. The code says why: a tool that
   asserts nothing must not read as green.
3. **Three skip states are distinguished**: `SKIP (needs the cartridge)` (unrun), `DEFERRED (graded by
   verify.py)` (handed off, not absent), and a suite that runs but prints no verdict (FAIL). The comment at
   `tools/acceptance.py:262` is explicit that conflating the first with the second is the error.

The audit-case count for the audit's own registration is **derived** by importing `audit_gates.AUDITS`
(`_audit_case_count()`), not typed. The comment records why: it was typed 107 against a real 109, then fixed
by typing 112 against a real 115 — the same defect twice, so it became a derivation.

### 3.2 `tools/audit_gates.py` — mutation audit (1136 lines, READ + one MEASURED count)

146 declarative mutations, each a `dict(name, tool, args, file, old, new)`. For each: build a throw-away
copy of the tree, **run the unmutated tool first as a positive control**, apply a single exact-string
replacement, run again, and require failure. Judged by exit status and the `N/M` line, never by the presence
of the word "FAIL" — the comment records that the string test made five audits unconditionally green.

Failure modes it reports, and the distinction is the point:

| outcome | meaning |
|---|---|
| **detected** | the check failed after its mechanism was disabled — the audit passes |
| **VACUOUS** | the check still passed with its mechanism disabled — it proves nothing |
| **BROKEN** | the unmutated tool already failed in the sandbox — nothing was judged |

`BROKEN` exists because of a measured defect: 49 of 132 mutations had been passing without ever running,
because the sandbox copied a hand-grown list of manifests and a tool died on `FileNotFoundError`, whose exit
code 1 read as "caught". The fix was a mechanism (the positive control), not another list entry.

Every mutation anchored on a source line is fragile, so `--lint` checks in **0.04 s** that each anchor exists,
is **unique**, and changes the text. That lint found a pre-existing anchor matching two places, where only the
first was ever replaced.

### 3.3 `tools/ratchet.py` — three invariants against a committed baseline (READ)

`fixtures/gates/ratchet.json` holds `{suites: {name: count}, src_tree: sha256}`.

| invariant | forbids |
|---|---|
| **match** | any difference between the registry and the baseline — added, deleted, raised **or lowered** |
| **decrease** | `--write` refusing to lower a count or drop a suite without an explicit `--allow-decrease` |
| **src** | any change to the hash of the `src/` tree |

The suite registry is obtained by **executing the source text**, not `importlib`, because a cached `.pyc`
would let the ratchet read a stale registry and report "monotone" about counts it never looked at.
`src_tree` skips dotfiles and `__pycache__`, because including them made the invariant environment-dependent
— a macOS baseline containing `src/.DS_Store` failed on every fresh clone.

`--self-test` (10 cases) breaks each invariant on a synthetic root and requires detection, because `--check`
on a healthy tree passes whether or not the comparisons are wired. Writing it found three defects in the file
itself, one of which was a vacuous case: the `src` case ran while the registry was still dirty from the
previous case, so it would have passed with the `src` comparison removed entirely.

### 3.4 `tools/counts.py` — documentation-as-assertion (353 lines, READ; `25/25` MEASURED)

Derives 31 values from the registry and the committed artefacts, then asserts each quoted number in
README/handover/CI against it. The subtlety that makes it more than a grep: **an expected occurrence count**.

If `README.md` must contain `**(N)-case verification suite**` exactly once, then *deleting the sentence is a
failure*, not a skip. The milestone log records this firing for real: deleting the phrase
`1022-case verification suite` produced `phrase found 0x, expected 1 — a deleted phrase is a failure`.

### 3.5 `tools/verify.py` — the adjudicator (READ)

Runs `ci.sh --no-audit`, `ratchet --check`, `counts --check`, then the audit **last**, and passes all four
through a pure function, `adjudicate()`, whose branch order is the whole doctrine:

```
audit absent                          -> INCONCLUSIVE
any vacuous or broken audit entry     -> INCONCLUSIVE    <- regardless of how green everything else is
audit itself did not fully pass       -> INCONCLUSIVE    (deliberately not FAIL)
a procedure exited non-zero           -> FAIL
a procedure printed fewer cases       -> FAIL
otherwise                             -> PASS
```

`--self-test` (8 cases) grades each branch by feeding it synthetic tuples, including the inadmissible one.
One case carries a comment recording that it had been *masked*: a tally of (2,3) also trips the
"fewer cases than it ran" branch, so the exit-status branch was never actually exercised until the case was
given a clean tally.

Two tiers exist. `--tier fast` withholds the four measured-expensive suites and does **not** run admission; its
verdict is `PASS-FAST` and the certificate records `admission: not-run`. Only `PASS` with a clean audit admits.

### 3.6 The certificate, and why a dirty flag was not enough (READ)

`tools/hook_cert.py` writes `build/verify-cert.json` holding a **content hash of the worktree**
(`git status --porcelain -z` + `git diff HEAD --binary`). `tools/pre-commit.sh` skips the suite only when the
certificate's hash equals the tree being committed, the verdict is `PASS`, and admission is clean. Three
earlier hash designs were wrong, each found by using the certificate rather than reading it: hashing
`git status` made staging invalidate it, and hashing the untracked list represented a new file two ways.

### 3.7 Tiers, by measured cost (READ)

| tier | runs | cost | what a pass means |
|---|---|---|---|
| 1 preflight | six file-reading checks | seconds | nothing structural is stale — **not admission** |
| 2 integration | every suite, no audit | ~1–2 min | suites and artefacts agree — **not admission** |
| 3 admission | tier 2 + audit + certificate | ~5–6 min | admissible |

The tiering is itself a measurement, not a preference: `tools/acceptance.py` names the four suites whose cost
dominates (`voice sweep` 46 s, `provenance acceptance` 19 s, `routine index bounds` 8 s, `file table` 4.3 s)
against a sub-second median for the other 63.

---

## 4. UNAVAILABLE versus FAILED — how the project distinguishes them

This distinction is the repository's most transferable single idea, and it is implemented rather than
described. Five states exist, and none substitutes for another:

| state | where it lives | meaning |
|---|---|---|
| **PASS** | acceptance, verify | ran, held, and its mechanism has been shown to fail when disabled |
| **SKIP** | acceptance | could not run here; any claim resting on it is `INCONCLUSIVE` |
| **DEFERRED** | acceptance | handed to another stage — a different fact from absence, and printed differently |
| **VACUOUS** | audit | ran and could not fail; asserts nothing |
| **BROKEN** | audit | the unmutated tool failed in the sandbox; nothing was judged |
| **INCONCLUSIVE** | verify | the verdict when admissibility is unestablished |

And a parallel vocabulary for *claims* rather than checks, used consistently in prose: `measured`,
`reading`, `inference`, `not established`, `open`, `unassigned`, `refused`, `superseded`, `hypothesis`.
The word `hypothesis` appears 9 times in `docs/format_notes.md`; `unresolved` / `not_claimed` / `refuses` /
`rsp_only` appear as **fields inside committed artefacts**, not just in prose — for example
`fixtures/scd/registry.json` carries `refuses`, `manifests/handler_region.json` carries `refuses`, and
`manifests/voice_descriptor.json` carries `rsp_only` with the note that it "names no field of the mixer and
asserts no behaviour of it" (READ).

**The consequence for this machine**: `verify.py --full` reported `PASS` while `coverage: partial`, with the
note that cartridge-gated suites SKIPped and "any claim that depends on them is INCONCLUSIVE here". The
repository states its own reduced authority in the same breath as its verdict. This is the behaviour the
standard should require, and it is the behaviour a naive CI would get wrong by reporting a green tick.

---

## 5. The evidence model as actually practised

### 5.1 Provenance is carried in the artefact, per function

Every one of the 3590 `.c` files opens with a machine-readable header (READ, e.g. `src/stage2/FUN_800243d0.c`):

```
/* FUN_800243d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800243d0  body 0x800243d0..0x80024557  size 392 B
 * body sha256 a221f5cd...
 * provider record sha256 74e54099...
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
```

Four fields together make a claim auditable: **where** (image + address + base), **how far** (body extent),
**what was derived** (body hash), and **what produced it** (provider + its record hash). The provider field is
a tool *and* a version. A corpus regenerated with a different decompiler would change the last line.

### 5.2 The status ladder separates rungs from axes, and the data refuted the first model

`manifests/analysis_status.json` publishes five numbers, not one (READ; totals MEASURED from the file):

| level | rule | value |
|---|---|---|
| **F0 indexed** | present in `manifests/code_index.json` | 3416 |
| **F1 decompiled** | `src/<image>/<name>.c` exists | 3416 |
| **F2 connected** | every call target in the body resolves | 3329 |
| **named** (axis) | the name comes from `config/symbols.tsv`, i.e. not `FUN_` | 33 |
| **validated** (axis) | a gate or executed experiment pins behaviour; curated, each citing its milestone | 12 |

The decisive published fact is in the rules block: **all 12 validated functions still carry `FUN_` names**
(`validated_unnamed: 12`). The first model made validation a rung above naming and returned 0 — the data
refuted the model, not the reverse. The lesson generalises: *naming is its own evidentiary act, and it is
orthogonal to behavioural validation.*

### 5.3 Retractions are a first-class artefact, and they are preserved rather than deleted

`docs/reverse_engineering_log.md` carries a 53-row table with the fixed columns
`| retracted | by | what changed |` (READ; the header row is itself a gated documentation anchor). Each row
quotes the withdrawn claim **verbatim with the milestone that made it**, names the milestone that corrects
it, and gives the number, address or code site that decides the question.

Three properties are worth extracting:

1. **The superseded value is often kept inside the gate.** `docs/log/M190-....md` records that the misaligned
   phase-16 figure was retained in the file-table suite "so the retraction is visible in the gate". The test
   carries the history, not just the current answer.
2. **Flip-flops are recorded as flip-flops.** `docs/log/M194-....md`: "M189 said 12, M193 said 16, M194 says
   12 again. The record shows all three because each was made on different evidence and the later one is not
   more flattering."
3. **A correction is not allowed to move the tally.** `docs/log/M219-....md`: "Count unchanged at 101 — a
   correction should not move the tally."

### 5.4 Pre-registered acceptance tests

Before the provenance work began, its acceptance criteria were written down
(`docs/format_notes.md`, "Experiments B and C") and then encoded as executable cases
(`tools/provenance.py --acceptance`, 3 cases). When the first run contradicted the expectation, the
*expectation* was corrected and the correction recorded: the argument is `unk`, not `ret(80001180)`, because
it is a byte loaded from the slot map, and "the earlier `ret(80001180)` was a labelling artifact" (READ).

Writing the criterion before the measurement is the mechanism that makes the later correction meaningful.
Without it, changing the expectation is indistinguishable from moving the goalposts.

### 5.5 Digest-addressed execution state

`checkpoint/` holds eight files produced by `tools/run_scheduler.py` (READ; contents MEASURED from the files):
per-thread CPU and FPU registers, a thread table, message queues, memory-region hashes, an execution trace,
the list of unresolved instructions (currently `[]` — a measured zero), and `run_digest.json`, a sha256 over
the other seven. Its stated purpose is reproducibility, not debugging: "given the same cartridge, the same
two images and the same initial state, this state must recur."

This is the strongest available form of behavioural evidence: a whole-machine state, addressed by content, so
determinism is one comparison. It also records a *negative* result rather than hiding it — the thread table
shows two threads blocked and a queue holding 20 messages with no waiter, which is the committed evidence
that the tick runs and nothing consumes it.

---

## 6. Contradictions between documentation and implementation

Fifteen numeric claims disagree with the registry. Each was re-verified against the file before being listed
here; each is a **READ** of both sides. None breaks a suite, because none is a quoting site that
`tools/counts.py` knows about — and the fifteenth is worse than that, because it lives inside an artefact.

| file:line | document says | registry says |
|---|---|---|
| `docs/handover.md:33` | indexes **all 178 milestones** | 305 |
| `docs/handover.md:36` | **50** milestone numbers have no row or note | 56 |
| `docs/handover.md:137` | `ci.sh`: **12 of 23 suites, 135 of 240 cases** | 32 of 73 suites, 286 of 1028 cases |
| `docs/handover.md:138`, `:139` | **all 23 suites / 240 cases** (×2) | 73 suites / 1028 cases |
| `docs/handover.md:167` | the **eleven** skipped suites | 41 |
| `docs/handover.md:181` | CI covers the other **135** cases | 286 |
| `docs/handover.md:183` | check_markers requires **16 anchors (12 handover sections)** | 22 cases (18 anchors + 4 structural) |
| `docs/handover.md:313` | counts.py derives **the seven numbers** … asserted in **twelve places** | 31 values; 25 cases |
| `docs/handover.md:316` | **Twelve** suites are cartridge-gated — then lists fourteen | 41 |
| `README.md:52` | **286 of 1 022** verification cases need no ROM | 1028 total |
| `README.md:337` | script VM: **17** lengths | 18 |
| `.github/workflows/acceptance.yml:12` | **The 109 skipped cases** | 742 |
| `.github/workflows/acceptance.yml:65` | silently skipped **11 suites** | 41 |
| `.github/workflows/acceptance.yml:76` | **109** skipped cases | 742 |
| `fixtures/sound/codec.json` → `mort_header_bytes` | **16** | 12 — the README says 12, and the retraction table records that M194 withdrew 16 in favour of 12 |

**The fifteenth is the most instructive, and it is not a documentation defect.** `fixtures/sound/codec.json` is
a committed artefact, written by `tools/file_table.py` and read by `tools/sound_fixtures.py`. Its
`mort_header_bytes` is **16**, a value the project's own retraction table marks as withdrawn by M194 ("back to
12 — `u32@+8` ends at +12 and `FirstBitPosition = 0x60` is 96 bits = the header"), and M197 independently
confirms the reader skips a 12-byte header. The README states 12 correctly.

Two gates look at this file and neither can catch it: `tools/file_table.py:965` asserts the fixture equals the
tool's `measured` dict, but that dict holds **literals** (`"mort_header_bytes": 16` is typed, not computed), so
the case proves only that the fixture agrees with the tool; and `tools/sound_fixtures.py:145` asserts only
`sample_count` and `codebook_bytes`.

The lesson for the standard is sharper than "update the number": **a gate that compares an artefact to a
hand-typed value verifies consistency, not correctness.** The reference project knows this — the comment at the
top of `codec.json` says the constants are asserted "against the cartridge" so "if a measurement moves, the
cartridge-gated case fails before any document can drift with it" — but the mechanism only delivers that for the
constants that are genuinely computed (`n_smp`, `n`, `rates`). A retracted literal survived a retraction while
sitting in the file that documents the retraction's subject.

**One candidate this document cannot settle.** `docs/handover.md:253` says "43 opcodes are named from the
MIT-licensed PlayStation table", while `fixtures/scd/opcodes.json` holds **45** opcode keys (and its own note
records that `0x26` carries two variants). Nothing states the counting rule, so 43 and 45 may both be right under
different definitions — exactly the §2-style denominator problem, one level down. It is recorded here as an
**unresolved candidate, not a finding**, and it is the reason [`SPECIFICATION.md`](SPECIFICATION.md) §6 quotes the
count from the artefact rather than from the prose. Resolving it needs only the counting rule, which no file
provides.

Three observations about *why* these survived, which bear directly on the standard:

1. **The gate binds phrases, not quantities.** `counts.py` does gate `.github/workflows/acceptance.yml`
   lines 6, 7 and 9 — the same file contains "the 109 skipped cases" at line 12, ungated. The pattern is on
   the correct sentence and not on the neighbouring wrong one.
2. **A stale number survives a corrected one.** The M301 note records that deleting the phrase
   `1022-case verification suite` correctly failed the gate and the phrase was restored. The integer `1 022`
   then survived eleven lines away in `README.md:52`.
3. **The file that makes CI run is the file CI cannot test.** The project states this as its own error class
   ("a file only a remote service parses is unverified", `docs/reverse_engineering_log.md`). It built
   `tools/workflow_lint.py` (14 cases) in response — and the workflow still carries two stale integers,
   because the lint checks *structure* (valid YAML, pinned actions, a skip guard) and not *content*.

The lesson for the standard is not "write fewer numbers". It is that a documentation gate must assert
**cross-site agreement for a named quantity**, not the presence of a phrase at one site.

---

## 7. What the repository has that most projects do not

Stated plainly, because the standard should preserve these rather than invent replacements:

1. **A registry that is simultaneously the runner, the metric source and the drift baseline.** One list
   (`SUITES`) drives execution, derives the published counts, and is hashed by the ratchet. Three consumers
   of one definition cannot disagree.
2. **Admissibility as a gate on the gates.** A passing check proves nothing until its mechanism has been
   shown to fail. Every gate is finished only when it has been demonstrated to fail.
3. **A positive control in the mutation harness**, so "the check failed" and "the check could not start" are
   distinguishable — a distinction that recovered 49 previously-fictional detections.
4. **Refusals as committed, gated artefacts.** Rather than omitting the unknown, the artefacts carry
   `refuses` / `unresolved` / `not_claimed` fields, and the refusals are themselves gated (a mutation asserts
   that a refusal filed under a kind with no work item fails).
5. **A published progress map generated from fixtures**, so a hand-drawn chart cannot drift — and a resolved
   fraction published as `226 of 229`, never rounded to 1.0.
6. **A retireable differential.** `tools/diff_unicorn.py` carries "RETIRED 2026-10-30 — kept for its host
   findings". Deleting a tool would delete the reason it could not be used.
7. **A named gaps list.** 56 milestone numbers with no note are *named*, not silently absent.

## 8. What the repository does not have

Honest limits, which the standard must not inherit as if they were features:

1. **No machine-readable evidence graph.** Claims, their dependencies and their retractions exist in prose
   and in per-artefact fields. There is no structure that answers "what depends on this observation?" — so a
   correction propagates by human diligence. §6 is the cost of that: 15 unpropagated figures.
2. **No cross-site quantity agreement check** (§6, observation 1).
3. **No formal epistemic state field.** The vocabulary of §4 is disciplined but it is prose. A machine cannot
   filter `docs/log/` for claims whose status is `INFERRED`.
4. **No portable target abstraction.** Every analysis tool hardcodes RE2/N64 constants. The *mechanisms*
   transfer; the *files* do not. This is the gap [`ARCHITECTURE.md`](ARCHITECTURE.md) addresses.
5. **Weakest gating on the earliest stage.** The identification and unpacking tools
   (`n64info.py`, `unpack_zlib.py`, `read_overlay_table.py`, `build_images.py`) have no `--check` mode; they
   are gated only indirectly, downstream. The earliest claims rest on the thinnest evidence.
6. **Two subsystems with no registered suite at all**: `tools/diff_rdram.py` and `tools/ares_rsp.py`. Both are
   documented as manual workflows.

Points 1–3 are precisely the three things [`EVIDENCE_MODEL.md`](EVIDENCE_MODEL.md) proposes to make
mechanical. Points 4–6 are candidates for the roadmap, not for immediate work.
