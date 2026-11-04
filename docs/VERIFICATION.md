# The verifier's contract

This is the standing brief for whoever runs verification on this project — a sub-agent, a session, or a
person. It exists so that the work of deciding *whether a claim is supported* does not sit inside the work
of *recovering the structure*, and so that the boundary between them is not renegotiated each time.

## Mission

Execute the verification the project already maintains, and report what it says. Do not recover code, and do
not design a new check unless a claim genuinely arrives in a class no existing check covers.

## The one rule it may not reinterpret

> **A result is admissible only if the gates that produced it have been shown to fail.**

`tools/audit_gates.py` is that demonstration: it disables each check's mechanism in a throw-away copy and
requires the check to fail. If the audit reports **any** vacuous or broken entry, the verdict is
**`INCONCLUSIVE`** — regardless of how much else passed. This is the first branch of `adjudicate()` in
`tools/verify.py`, and `--self-test` grades each branch by feeding it synthetic results, including the
inadmissible one.

The rule exists because the defect this project keeps finding is not a wrong claim. It is a **gate that
could not fail**: six audit environments missing a directory, two mutations that failed for the wrong
reason, a `4 852 vs 4 761` miscount read as a missing class when it was 126 aliased entries, and an audit
whose verdict was `"FAIL" in output` — which made five audits green no matter what.

## Responsibilities

1. Run `python3 tools/verify.py` (or `--json`) and report the verdict. Nothing else is required to answer
   "is this supported".
2. Report the seven fields, verbatim: `artifact`, `procedures`, `admission`, `verdict`, `why`, `coverage`,
   `blocks_milestone`.
3. Say `INCONCLUSIVE` when the audit is dirty, when a procedure printed no `N/M` verdict, or when the
   cartridge is absent and the claim depends on a gated suite. Reduced coverage is **not** a pass.
4. When a check fails, report the failing label and its evidence line. Do not summarise what "probably"
   went wrong without reading the output.
5. When a claim arrives in a class no existing check covers, add the check **and** its mutation audit —
   see "Changing the gates" below.

## Skipped is not vacuous, and neither is a pass

Three states, and the difference is the whole point:

| state | meaning |
|---|---|
| **PASS** | the check ran and held, and its mechanism has been shown to fail when disabled |
| **SKIP** | the check could not run here — no cartridge — so it is *unrun*, and any claim resting on it is `INCONCLUSIVE` |
| **VACUOUS** | the check ran and could not fail, so whatever it asserted proves nothing |

`audit_gates.py` skips the audits whose tools are cartridge-gated when there is no cartridge, and says so;
`verify.py` admits a run whose skips are accounted for while still treating vacuous or broken entries as
`INCONCLUSIVE`. Conflating skip with vacuous made the entry point report `INCONCLUSIVE` on every fresh clone,
which was wrong in the direction that matters least but is wrong nonetheless.

## Restrictions

- **Do not edit `src/`.** It is hashed by the ratchet; a verifier that edits the corpus to make a check pass
  is the failure mode the ratchet was built for.
- **Do not lower an expected count**, and do not accept a count change without `tools/ratchet.py --write`.
  `--write` is a deliberate act and shows up as a diff. Shrinking the suite additionally requires
  `--allow-decrease`, which should essentially never appear in a verification commit.
- **Do not commit.** Report; the primary agent commits.
- **Do not mark anything verified without executable evidence.** A code reading that cannot be executed is
  labelled a reading, and pinned by source-shape cases if it is claimed (see `FUN_800b3704` in M179).
- **Do not invent a mechanism when one exists.** But this is the *weak* restriction: the strong rule is the
  inverse — a new claim class needs a new check, and every check needs a mutation audit.

## Changing the gates

A gate is not finished when it passes. It is finished when it has been **shown to fail**:

1. Add the case to a registered suite and raise its expected count in `tools/acceptance.py`.
2. Add a mutation to `tools/audit_gates.py` aimed at the **comparison or the derived value**, not at a
   constant (emptying a constant has produced `IndexError`, and raising a ceiling a petabyte allocation —
   both "fail", neither for the reason under audit).
3. Run `tools/audit_gates.py` and require `0 vacuous, 0 broken`.
4. Hand-verify that the mutation fails on its *intended* case, not by exception and not on a missing file.
5. `python3 tools/ratchet.py --write`, and let the count change appear in the diff.
6. `python3 tools/counts.py --check` — the documented numbers follow from the registry, so this is the
   only step that needs the docs to be right.

## Landing a cycle

**A cycle is the landing unit, not a milestone** (M210). A cycle is 4–6 milestones; each one keeps its own
note and log row, but the expensive verification happens once, on the tree that the single cycle commit
carries. The reason is cost, stated plainly: the audit alone is minutes, the hook re-runs the whole suite, and
a milestone that turns out wrong inside a cycle is corrected in situ rather than by a new commit.

A cycle is not landed until all four of these are true, in this order:

1. **`tools/ratchet.py --write`** recorded the count change, so the new numbers are in
   `fixtures/gates/ratchet.json` and a later shrink is refused. M179 was the first customer: its
   `file table` 20 → 28 and `gate audit` 35 → 37 were refused until this step.
2. **`tools/counts.py --check`** is clean, so the documents quote the numbers the registry now holds.
3. **`python3 tools/verify.py`** reports `PASS` with a clean admission. Its report records the **worktree
   hash** it graded, not merely a dirty flag, and writes `build/verify-cert.json`.
4. **The commit's hook sees that certificate.** `tools/pre-commit.sh` skips the suite only when the
   certificate's worktree hash equals the tree being committed, the verdict is `PASS` and the admission is
   clean. Edit one byte after verification and the hook runs the suite again — which is the point.

### The order is load-bearing, and getting it wrong has cost three re-runs

Steps 1→3 are in that order **because each one changes the tree the next one hashes**:

* `ratchet.py --write` rewrites `fixtures/gates/ratchet.json`, so running it *after* `counts.py --check` means the
  counts were checked against a baseline that no longer exists, and running it after `verify.py` means the
  certificate describes a different tree and the hook re-runs the whole suite — five to eight minutes, twice, for
  nothing. It happened in M221 and M219 for exactly this reason.
* `counts.py --check` only reads, so it can run anywhere between them, but it must come **before** `verify.py`:
  a stale number that verify discovers costs a full admission run to find a typo.
* Anything that *writes* — regenerating a fixture, `ratchet --write`, re-seeding the milestone index — belongs in
  steps 1–2. **A derived artefact is regenerated from its source, never hand-patched** (M221's commitment edited the
  voice sweep twice mid-task; the fix was `--sweep`, not an edit).

So the per-cycle sequence, in order, is:

```sh
python3 tools/preflight.py            # tier 1: counts, markers, index, ratchet drift, anchor lint  (seconds)
python3 tools/ratchet.py --write      # accept the count change; the diff shows it
python3 tools/counts.py --check       # the documents now quote the registry
python3 tools/milestone_index.py --check && python3 tools/check_markers.py
python3 tools/verify.py               # admission; writes the certificate for THIS tree
git commit                            # the hook sees a matching certificate and skips the suite
```

Per *milestone*, the evidence is cheaper and still mandatory: the gate for the tool it touched, and a
mutation that makes that gate fail for its intended reason. What is batched is the re-running of everything,
never the proving of anything.

The two guards are deliberately two-sided, and neither is sufficient alone:

* `acceptance.py` binds each expected count to **reality** — it fails when a suite runs a different number
  of cases than registered, so a wrong count cannot be baked in.
* `ratchet.py` binds it to **history** — it fails when the number moves without `--write`, so a correct
  count cannot be quietly lowered.

`--write` accepts whatever the registry says. That is why step 1 is worthless without `acceptance.py`
having passed: `--write` will happily record a wrong number, and after that the ratchet defends the wrong
number. The pair is the guarantee; either one alone is a filing system.

## Three tiers, and what each may claim (M216)

The expensive tier was being run for cheap defects: a stale count in a document, an audit mutation whose source
anchor a refactor had moved, a milestone row without its note. Each of those is visible in seconds, and each was
instead discovered after minutes. So the work is split by cost, and only the last tier may admit a landing.

| tier | what runs | cost | what a pass means |
|---|---|---|---|
| **1 — preflight** | `tools/preflight.py`: counts, markers, milestone index, ratchet, the mutation-anchor lint, the counts self-test | **seconds** | nothing structural is stale. **Not admission.** |
| **2 — integration** | `sh tools/ci.sh --no-audit`: every suite, the artefact scan, the cartridge digest, with the 88-mutation audit deferred | **~1–2 min** | the suites and the artefacts agree. Still **not** admission. |
| **3 — admission** | `python3 tools/verify.py`: tier 2, then the gate audit as the last step, then the worktree certificate | **~5–6 min** | **admissible**: a result only counts if the gates that produced it have been shown to fail |

Two rules follow from that table and they are the whole point of it:

* **Run tier 1 after every edit.** It is cheaper than reading the diff carefully and it catches exactly the
  defects that otherwise surface at tier 3.
* **Run tier 3 once, on the tree that will be committed.** The certificate records the content hash of that
  tree, so staging does not invalidate it and editing one byte does. That is what lets 4–6 milestones land as a
  single commit without re-running anything.

### The mutation-anchor lint

Mutation testing is the most expensive thing this project does — each entry copies the tree and runs a tool — and
it is also the most brittle, because a mutation anchors on an exact source line. `tools/audit_gates.py --lint`
checks, in **under 0.1 s**, that every anchor still exists, that it is **unique** (an anchor matching two places
is a mutation that is half-applied and never says so), and that it actually changes the text. It found a
pre-existing duplicate on its first run. Run it in tier 1, and a refactor that breaks a mutation costs seconds
instead of a whole verification cycle.

## What each procedure answers

| procedure | question |
|---|---|
| `tools/ci.sh` | does every suite pass, with the expected case counts; are any cartridge-derived artefacts tracked; is the cartridge the expected one |
| `tools/ratchet.py` | has the registry drifted, or has `src/` moved, without a deliberate `--write` |
| `tools/counts.py` | do the numbers quoted in the docs still agree with the registry |
| `tools/audit_gates.py` | **can each check fail at all** — this is admissibility, and it runs last |

## Priority

Preserve correctness and do not overclaim. A fast `INCONCLUSIVE` is worth more than a slow `PASS`: the
project's credibility rests on every published number having been re-derivable, and on retracting plainly
when it was not.
