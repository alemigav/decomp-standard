# EXECUTIVE REPORT

For a reader with ten minutes. Every figure is measured on this machine or read from a named file; the supporting
work is in [`ARCHAEOLOGY.md`](ARCHAEOLOGY.md) and [`EXTRACTION_MAP.md`](EXTRACTION_MAP.md).

**What was done:** the reference implementation was reconstructed from its files, its cartridge-free verification
was run (`VERDICT PASS`, gate audit 39/39, 0 vacuous, 0 broken, 107 skipped), 102 tools / 30 manifests / 237
documents were classified, and its methodology was formalised into twelve documents. **No game cartridge was
used, and no file of the reference project was modified.**

---

## 1. What has already been built that is genuinely reusable?

**The doctrine is reusable; the code mostly is not.** This is the single most important finding, and it is
measured rather than asserted.

Of **102 files** under `tools/`, **9 are reusable as code** — an ELF wrapper, a MIPS test generator, a splat
inventory reader, a text patcher, a worktree hasher, a preflight runner, two N64 utilities and an OCR script.
**None of the nine is a high-value methodological component.** Every high-value component is a generic idea welded
to this target's constants: the address authority hardcodes this build's mapping law, the abstract interpreter
carries this ISA's opcode tables, the evidence graph is built from this project's bound sources
([`EXTRACTION_MAP.md`](EXTRACTION_MAP.md) §11).

What *is* genuinely reusable, in decreasing order of value:

| reusable asset | form | why it transfers |
|---|---|---|
| **the gate doctrine** — a check is not finished until it has been shown to fail | specification + one working harness | no domain content whatsoever |
| **the three-state distinction** — PASS / SKIP / VACUOUS, with `INCONCLUSIVE` as a verdict | doctrine + 8 self-tests | the failure it prevents is universal |
| **one registry, three consumers** — execution, metrics, drift baseline from one list | data pattern | any project with a checklist |
| **refusals as committed artefacts** — `refuses` / `unresolved` / `not_claimed` fields in six manifests | schema | the only mechanism found that makes negative results reusable |
| **the denominator discipline** — name the population in the metric's name | rules | cheap, and it prevents the most common misreading |
| **the retraction format** — quote the withdrawn claim, name the corrector, give the decider | table schema | preserves flip-flops and dated statements |
| **the pre-registered acceptance test** — write the expectation before the measurement | practice + 3 executable cases | makes a later correction meaningful |

## 2. What is currently unique to RE2?

Three tiers, and the middle one is the surprise.

**Irreducibly specific** — the 141-entry opcode table at a fixed address, the T64 texture law, the `MORT` voice
header, the codec constants, `vram = rom_offset + 0x7FFFF480`, the 36-image load table, the toolchain answer
(gcc 2.8.1, binutils 2.7, `-mcpu=r4300`, `-g` on the assembler). None of this transfers and none of it should be
abstracted.

**Generic method, welded implementation** — the larger category, and the reason the standard is
documentation-shaped. Function inventory, byte partition, provenance propagation, call-graph evidence, format
laws, execution harnesses, mutation auditing: the *ideas* are portable and every *file* mixes a generic mechanism
with this target's constants. Roughly 45 of 102 files are in this class.

**Genuinely generic already** — 9 files. Plus the schema-shaped assets in the table above, which are data
patterns rather than code.

## 3. What are the strongest innovations in the existing verification methodology?

Five, in order of how much they changed outcomes.

**3.1 Admissibility is a gate on the gates.** A passing check proves nothing until its mechanism has been
demonstrated to fail. 146 mechanisms are disabled one at a time in a throw-away copy and the check must then fail.
This is the standard's central rule and it is fully implemented.

**3.2 A positive control inside the mutation harness.** Before judging a mutation, the *unmutated* tool must
succeed in the same sandbox. Without it, "the check failed" and "the check could not start" are indistinguishable
from an exit code — and the project discovered that **49 of 132 mutations had never executed at all**, across two
entire research arcs. This single mechanism recovered them.

**3.3 Skip is not pass, and neither is vacuous.** Three states, an `INCONCLUSIVE` verdict that outranks greenness,
and a report that emits `PASS` with `coverage: partial` and the caveat in the same breath. Conflating skip with
vacuous had made the entry point unverifiable on every fresh clone.

**3.4 Verification tiered by measured cost.** Four suites account for the entire gap between a 30-second and a
12-minute run (46 s, 19 s, 8 s, 4.3 s against a sub-second median for the other 63). Named as a measurement, not a
preference. A content-hashed certificate lets a 4–6-milestone cycle land with one verification run, and editing
one byte invalidates it.

**3.5 A ratchet plus a derivation, as two sides of one guarantee.** `acceptance.py` binds each expected count to
reality; `ratchet.py` binds it to history. Either alone is a filing system. Together they make it impossible to
lower a count quietly, and `--write` forces every change to appear as a diff.

## 4. What is missing before this can be considered a credible standard?

Five things, and the first is fatal until it is fixed.

**4.1 The standard has a sample size of one.** It was extracted from one project, by one author, for one target.
Its requirements are generalisations of that project's failures, so they fit it by construction. `Q10` in
[`OPEN_QUESTIONS.md`](OPEN_QUESTIONS.md) states this plainly and it cannot be fixed from here. The honest framing
is "this project needed these", not "every project needs these".

**4.2 The reference project cannot yet demonstrate the standard's own measurement rule.** It carries **15 claims
that contradict its registry** — fourteen in its documents, including two inside the file that makes CI run, and
one inside a committed artefact the project treats as evidence — and **one quantity with two committed values**
(1 211 256 vs 1 210 600 bytes, differing by 656 B). Its gate binds *phrases*, not *quantities*; and its artefact
gates compare a fixture to a hand-typed constant, which verifies consistency rather than correctness. A standard
that requires "one definition, every site" from others while its own exemplar fails that requirement has no
standing. Fixing it is Phase 0.

**4.3 Traceability is a principle with no mechanism.** Claims, evidence and retractions exist as prose and as
per-artefact fields. There is no structure answering "what depends on this observation?", so a correction
propagates by diligence — which is exactly how 4.2's 15 figures survived.

**4.4 The architecture has no second instance.** The core/adapter boundary is proposed from a classification of
one project's files. It has never been tested against a second target, and the extraction map's finding (9 of 102
files reusable, none of them methodological) argues the boundary may be in the wrong place.

**4.5 Native portability is unspecified in practice.** The reference project declined its third layer rather than
half-build it, so the eighth dimension has no worked example anywhere.

## 5. What should the next engineering agent implement?

Ordered. The first item is deliberately small and is not a new abstraction.

| # | step | effort | why first |
|---|---|---|---|
| 1 | **Bind each documented quantity, not each phrase.** For every derived number, assert every quoting site; a stale figure anywhere fails. | small | fixes 15 measured contradictions; no new concepts |
| 2 | **Give every published quantity an identity and one derivation.** Where two artefacts measure one concept, reconcile them or document the transformation between them. | small | the 656 B case; precondition for every metric |
| 3 | **Make `scope`, `does_not_say` and `state` required fields** on a claim index of published numbers only (~250–300 objects, not 3416). | small–medium | the project already writes all three by hand everywhere; making them fields is nearly free |
| 4 | **Schema the four L1 records** — artifact, region inventory, census, evidence ref — with a worked instance from the existing manifests. | medium | the substrate; documentation, not code |
| 5 | **Lift the mutation harness**, parameterised by a mutation *set*, with its positive control and its `detected`/`vacuous`/`broken` outcomes. | medium | the most target-neutral component; the sharpest test of any boundary |
| 6 | **Lift the adjudicator** (`adjudicate()`), with its 8-case self-test unchanged. | small | the doctrine in executable form, pure, ~40 lines |
| 7 | **Run the lifted harness against a synthetic mutation set unrelated to RE2.** | small | the boundary test; if it fails, stop and report that the methodology is portable as practice, not as code |

Steps 1–3 repay their cost in the reference project alone, regardless of whether the standard is ever adopted.

## 6. What should explicitly NOT be implemented yet?

Seven things, each with the reason it should be refused if proposed.

1. **The dependency graph and invalidation closure.** Highest ceiling, no precedent anywhere, and steps 1–2 catch
   the measured failure class without it. Build it only after the cheap version has run for a while — and note
   that the reference project's actual propagation failures are *restatements of numbers*, which site-checking
   catches.
2. **A plugin system or target-adapter framework.** One implementation. The extraction map finds 9 reusable files;
   a framework for one consumer is a liability.
3. **A rewrite of the reference project's tools to fit an abstraction.** Explicitly forbidden, and unjustified:
   the tools work, the gates are green, and no second consumer exists.
4. **A new language or runtime.** Python 3 stdlib plus four shell scripts, no dependencies, runs on a bare
   interpreter. The constraint is a feature — it is why 286 cases run without the artifact on any machine.
5. **Any composite "completion" percentage.** It cannot be defined: the dimensions are independent, and this
   project is 100 % inventoried at 0.44 % matched.
6. **A generic loader, decompiler wrapper, or disassembler.** Commodity, and coupling the standard to tools that
   have their own ecosystems would make it a client of them.
7. **Any statement in this document set marked proposal, presented as established.** Nothing in Phases 1–4 has
   been executed.

---

## The one-sentence summary

The reference project proves that rigorous, evidence-driven reconstruction is possible at scale by one person, and
demonstrates precisely where discipline alone stops working — at the point where 305 milestones of careful prose
outrun the ability to propagate a correction — and the standard's job is to make that specific failure mechanical,
not to make the project generic.
