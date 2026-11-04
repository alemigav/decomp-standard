# EXTRACTION_MAP — every component, classified

Maps the reference implementation to the proposed DECOMP-STANDARD components. One row per file or coherent
group. 102 files under `tools/`, 30 manifests, 6 fixture families, 5 headers, 8 checkpoint files, 4 config files.

**Classification** (the four categories the mission defines):

| | meaning |
|---|---|
| **A** | **Generic methodology** — the *idea* transfers to almost any reconstruction project |
| **B** | **Generic implementation** — the *code* transfers with little or no change |
| **C** | **Target adapter** — the methodology is reusable; the implementation is bound to an architecture, console, executable format or platform |
| **D** | **Target-specific research** — the finding or tool makes sense only for this target |

A file can be **A+C**: a generic method expressed through a target-specific implementation. That combination is
the most common and the most misread — a generic *idea* is not a generic *implementation*.

**Columns:** path · current responsibility · class · reuse potential · known limitation · future work.

---

## Part 1 — Verification and gate infrastructure (20 files)

This is the most reusable cluster in the project and the least reusable as code.

| path | responsibility | class | reuse potential | known limitation | future work |
|---|---|---|---|---|---|
| `tools/verify.py` | entry point; runs procedures, then admission; one verdict via `adjudicate()` | **A** | **highest** — the branch order is the doctrine | hardcodes the four procedures and the artifact path | lift `adjudicate()` verbatim into L2; procedures become L4 config |
| `tools/acceptance.py` | suite registry, subprocess runner, expected-count enforcement, ordered reporting | **A** (mechanism) + **D** (the 73 entries) | high for the mechanism | expected counts typed per suite; the SKIP/DEFERRED distinction is bespoke to "cartridge" | registry moves to L4; the runner and the three-state logic stay |
| `tools/audit_gates.py` | 146 mutations; sandbox, positive control, mutate, require failure | **A** (mechanism) + **D** (anchors) | **highest of any file** — disable-and-require-failure is fully general | every anchor quotes this project's source text; anchors break on refactor (mitigated by `--lint`) | extract `run_audit()` to L2; anchors are L4 data; add the freshness policy (§5.3 of VERIFICATION_STANDARD) |
| `tools/ratchet.py` | three invariants over registry + tree hash | **A** + **B** | high — nearly target-neutral | baseline holds this project's 73 suite names; `src/` is a project-specific subject | L2 with the subject path as config |
| `tools/counts.py` | derives 31 values; asserts every quoting site; deleted phrase = failure | **A** (mechanism) + **D** (the 31 derivations, 20 patterns) | high for the mechanism | **binds phrases, not quantities** — the measured defect (14 stale figures) | add metric *identity* + cross-site agreement (METRICS §5.1, V11) |
| `tools/preflight.py` | cheap tier; six file-reading checks; explicitly not admission | **A** + **B** | high | step list is hardcoded | L2 with the step list as config |
| `tools/hook_cert.py` | worktree content hash; certificate a hook validates | **B** | **as-is** | none for this purpose; three earlier hash designs were wrong | L2 as-is |
| `tools/pre-commit.sh` | consults the certificate; runs the suite otherwise | **B** | high | shell; the `--no-verify` escape is documented | L2 template |
| `tools/ci.sh` | acceptance + tracked-artifact scan + artifact hash | **A** + **C** | medium | path patterns and the 1 MiB fixture cap are this project's | keep as L4 |
| `tools/ci_full.sh` | full tier; **fails if anything skipped** | **A** | **high** — the guard pattern is directly portable | greps this project's literal skip phrase | L2 template with the phrase as config |
| `tools/cart_fetch.sh` | materialise the artifact from a URL, verify hash before unpacking | **A** + **C** | high for the mechanism | this project's destination path and expected hash | L2 with L4 identity rules |
| `tools/artefact_scan.py` | refuse target content by bytes: magic, hash, size, path | **A** + **C** | medium-high | three N64 magics, this project's `rom_sha256` | L2 with the magic set as adapter data |
| `tools/check_markers.py` | documentation anchors + structural rules (note registration, index consistency) | **A** + **D** | high for the mechanism | the 18 anchors are this project's prose; anchors are literal strings by design | L2 with anchors as L4 data |
| `tools/workflow_lint.py` | lints the CI workflow that makes CI run, without CI | **A** + **C** | high | rules 5 and 7 name this project's scripts and skip phrase | L2 with rules parameterised |
| `tools/milestone_index.py` | generates the milestone index; names the gaps; `--check` on drift | **A** + **D** | medium — the *named gaps* idea is the transferable part | log/note paths; `(i)`/`(ii)` duplicate convention is local | L2 as a "record index with named gaps" component |
| `tools/progress_map.py` | renders a progress map from fixtures into the README; `--check` on drift | **D** | low | `MATCHED` is 16 hardcoded addresses with hand-written descriptions | keep; the *idea* (generated, drift-gated) is A |
| `tools/analysis_status.py` | the F0/F1/F2 ladder + `named`/`validated` axes | **A** (the ladder) + **D** (the rules) | **high as an idea** — rungs vs axes is the transferable insight | rules are `code_index.json` + `FUN_` prefixes | schema it as an L1 census + aggregate |
| `tools/verify_proto.py` | caching verifier keyed on discovered input hashes | **A** + **B** | high, unexploited | prototype; the artifact hash enters every key | candidate for L2 once a second target exists |
| `tools/patch_text.py` | atomic exact-replacement editor, count-checked, all-or-nothing | **B** | **as-is** | none | L2 as-is |
| `tools/sound_fixtures.py` | tier-1 validation of committed artifacts with **no target bytes** | **A** (the tier) + **D** (the invariants) | high | invariants are 417/588/262 894+44 144/×160 | the *pattern* belongs in L2 as "validate committed artifacts against their own invariants" |

**Summary of this cluster:** the mechanism is A, the content is D, and separating them is most of the
standard's work. Two files are B as-is (`hook_cert.py`, `patch_text.py`) and one more is a strong B
(`preflight.py`).

---

## Part 2 — Artifact identification, unpacking, inventory (16 files)

| path | responsibility | class | reuse potential | known limitation | future work |
|---|---|---|---|---|---|
| `tools/n64info.py` | identify a dump by magic; byte order; header; refuse a CRC verdict | **C** | high within one platform family | N64-specific magics and header | adapter: artifact identity rules |
| `tools/unpack_zlib.py` | inflate concatenated zlib members using `unused_data` for exact boundaries | **A** + **C** | high — the *method* (self-delimiting walk, no size table) is fully general | default start offset; CMF `0x68` note is this compressor's | adapter: container membership |
| `tools/build_images.py` | materialise each code image as ELF32 BE MIPS | **C** | medium | boot extents are literals; ELF wrapping is REA's requirement | adapter: image model |
| `tools/read_overlay_table.py` | find the load table by its self-naming marker; validate on four constraints | **A** + **D** | **high as a method** — "find by self-naming marker, emit only if N constraints hold" | `OVERLAYTABLENUM`, `0xCDCDCDCD` sentinel | adapter with the marker and constraints as data |
| `tools/extract_blocks.py` | extract `payload [pad] trailer` blocks resolved backwards from the trailer | **A** + **D** | medium | trailer type list is this container's | adapter |
| `tools/find_cart_table.py` | sweep for 16-byte descriptor records | **D** | low | record layout is this cartridge's | keep |
| `tools/scan_headers.py` | container format discovery: window / compare / derive / chain | **A** (derive-by-scoring) + **D** | medium | JPEG anchors; frame region | the *derive* subcommand is the transferable part |
| `tools/scan_code_members.py` | measure how much of the container is code, by code signals not entropy | **A** (never entropy) + **C** | medium-high | signal set and RAM window are N64/RE2-tuned; **its own self-test fails 34 of 35** | adapter; publish the refuted heuristic as it already does |
| `tools/scan_banks.py` | cheap structural discovery: code density, pointer runs | **C** | high within N64 | two MIPS fingerprints | adapter |
| `tools/classify_image.py` | total partition of every word into 5 classes with fixed precedence | **A** (the discipline) + **D** (the sources) | **high** — the partition rules are portable verbatim | `DAT_` regex is one decompiler's naming; 16-byte padding law | L2 rule + adapter signals |
| `tools/file_table.py` | the file system census; 101 cases; MORT record format | **D** | low | entirely this cartridge's table | keep |
| `tools/asset_families.py` | classify record-table families; answer the "48 records" question negatively | **D** | low | id ranges are this target's | keep |
| `tools/decode_r4_container.py` | attempt and record every rejected hypothesis for one container | **A** (record refutations) + **D** | medium as a method | one container | keep as a worked example |
| `tools/wrap_mips_elf.py` | wrap a raw BE MIPS segment in a minimal ELF header | **B** | **as-is** | needs `--base` | L2/L3 utility |
| `tools/mkmips.py` | emit MIPS test artifacts with hand-computed ground truth | **B** | **as-is** | one fixed program | L3 test utility |
| `tools/splats_inventory.py` → `tools/splat_inventory.py` | turn splat asm output into a function inventory | **B** | **as-is** for any splat project | none | L2 utility |

**Note on the weakest link.** None of `n64info`, `unpack_zlib`, `read_overlay_table`, `build_images` has a
`--check` mode. The earliest claims in the project — what the artifact is, what it contains — rest on the
thinnest gating (`ARCHAEOLOGY.md` §8.5). **This is the highest-priority gap in the reference project itself**,
independent of the standard.

---

## Part 3 — Address model and cross-referencing (7 files)

| path | responsibility | class | reuse potential | known limitation | future work |
|---|---|---|---|---|---|
| `tools/vaddr.py` | address-space authority: `sext16`, `compose(hi,imm,**mode**)`, `locate()` refusing ambiguity | **A** (the discipline) + **C** (the map) | **very high as a pattern** — "the default is the bug"; refuse an ambiguous address | `0x7FFFF480` is this build's law; image table from `build/` | adapter: address model; the API shape is reusable |
| `tools/find_readers.py` | who touches an address window, with enclosing function | **A** (engine) + **C** (defaults) | high | MIPS opcode table; memory-sourced bases invisible | adapter: ISA |
| `tools/xref_registry.py` | bounded abstract interpretation for cross-references | **A** + **C** | high | `CALLER_SAVED` set is MIPS | adapter |
| `tools/find_store_loops.py` | find store runs filling a table with a constructed constant | **A** + **D** | medium | target addresses baked in | adapter |
| `tools/find_bank_writers.py` | inverse: where stores go, ignoring how the value was made | **D** | low | two bank addresses | keep |
| `tools/find_stream_walker.py` | classify registers as artifact pointers; report loads and their loop bounds | **A** + **C** | high | `0xB0000000..0xB4000000` window | adapter |
| `tools/find_jump_tables.py` | recover dispatch targets; structural acceptance per entry | **A** + **C** | high | plausible-first-instruction whitelist | adapter |

The recurring pattern: **the abstract-interpretation engines are A; their opcode tables and default addresses
are C.** Every one of these files mixes the two, which is why none is B.

---

## Part 4 — Corpus, provenance, call graph (10 files)

| path | responsibility | class | reuse potential | known limitation | future work |
|---|---|---|---|---|---|
| `tools/export_src.py` | project the decompiler journal into a committed source tree with provenance headers | **A** (projection, not second source of truth) + **C** | high | header format names this project's fields; recovered-fixture coupling | schema the provenance header as L1 |
| `tools/export_ranges.py` | distil a 9.5 MB journal into a ~104 KB committed boundary fixture | **A** | **high** — "shrink the input so CI can recompute the claim" | `IMAGE_FIELDS` local | L2 utility |
| `tools/provenance.py` | intra-procedural abstract interpretation; pre-registered acceptance tests; synthetic-corpus self-test | **A** (lattice, merge, invalidate-on-load, pre-registration) + **C** | **highest in this cluster** | 1663 lines; ISA tables; target examples | adapter: ISA; keep the four fixtures as the pattern |
| `tools/call_graph.py` | call graph with per-edge evidence kind and confidence | **A** (evidence-carrying edges, `dst:null` + why, image-qualified identity) + **D** (bound sources) | **high as a design** | 31 checked bases are RE2 artifacts | L1 record shape is the reusable asset |
| `tools/cfg_reach.py` | script-VM CFG with structured exits; states its over-approximation | **A** (state the safe direction) + **D** | medium | opcode sets are this VM's | adapter |
| `tools/find_missed_functions.py` | second discovery pass; publishes its residue; never names | **A** + **D** | medium | calibrated thresholds | adapter |
| `tools/verify_corpus.py` | six corpus checks, each with a way to fail | **A** (six check shapes) + **D** | medium | `REGRESSION` dict is this project's | L4 |
| `tools/recovered.py` | single reader for the recovered-function fixture | **A** (one reader, no disagreement) + **D** | medium | docstring claims a consumer that does not import it | fix the docstring or the import (ARCHAEOLOGY §2) |
| `tools/analysis_status.py` | (see Part 1) | A+D | — | — | — |
| `tools/exception_path.py` | prove an exception path is unrecoverable by design | **A** (prove a negative structurally) + **D** | medium as a method | stub words and addresses | keep as a worked example |

---

## Part 5 — Script VM / TYRANT (18 files)

Every file here is **D for content** and **A for method**. Listed together because the methodological content is
one thing repeated.

| path | responsibility | class | reuse potential | known limitation |
|---|---|---|---|---|
| `tools/walk_stream.py` | first decoder; extent rule = nearest independent boundary | **A** (nearest-boundary rule) + **D** | medium-high | 141-entry table at a fixed address |
| `tools/opcode_registry.py` | one record per opcode: advance with provenance, control flow, handler, refusals | **A** (evidence-carrying registry with a refusal slot) + **D** | **high as a schema** | content is this VM |
| `tools/scd_vm.py` | reference decoder + trace format; **refuses rather than guesses** | **A** (refusal discipline) + **D** | high as a pattern | content is this VM |
| `tools/handler_region.py` | recover each handler's extent; three refusal labels | **A** + **D** | medium | content |
| `tools/vm_refusals.py` | sweep all instances; classify every refusal by exception class into a work list | **A** (refusal → work list) + **D** | **high** | content |
| `tools/script_population.py` | replace a refuted population claim with a 5-category partition, each carrying evidence | **A** + **D** | high as a method | content |
| `tools/script_profile.py` | profile every candidate block; publish counts and opcode numbers only, no bytes | **A** (no target bytes in the artefact) + **D** | medium | content |
| `tools/cfg_reach.py` | (see Part 4) | A+D | — | — |
| `tools/container_0141.py` | prove a law on a family and **refute** the tempting structural reading | **A** + **D** | high as a method | content |
| `tools/callback_table.py` | settle a dispatch; correct a published address by 0x10000 | **D** | low | one table |
| `tools/dispatch_heads.py` | census a dispatch-head class; name the one BSS table | **A** (class census) + **D** | medium | content |
| `tools/head_index.py` | trace what each head dispatches on, through a chain of transforms | **A** + **D** | medium | content |
| `tools/extent_audit.py` | audit a correction queue for sufficiency *and* safety before running it | **A** (audit a queue before applying it) + **D** | **high as a method** | content |
| `tools/routine_index.py` | answer an index-bound question structurally; find 14 is not the bound | **D** | low | five class tables |
| `tools/room_script.py` | decode a room's script from the artifact with no dump and no emulator | **D** | low | one path |
| `tools/tyrant_header.py` | generate types from measured offsets; `MEASURED` constant, not a fake `sizeof` | **A** (generate the types from measurements) + **D** | high as a pattern | content |
| `tools/sound_ops.py` | six sound commands derived from bytes; find one plays nothing, one operand dead | **D** | low | content |
| `tools/room_probe.py`, `tools/walk_stream.py` dump readers | read a memory dump in a fixed order that fails informatively | **A** (report order = failure informativeness) + **D** | medium | content |

**The transferable schema, stated once:** an opcode/instruction registry whose record has a field for the
advance, how it was obtained, its control-flow class, its handler, whether its handler is in the corpus, and a
**refusal slot**. Sixteen of these eighteen files are instances of that one idea.

---

## Part 6 — Sound and RSP (18 files)

| path | responsibility | class | reuse potential | known limitation |
|---|---|---|---|---|
| `tools/snd_proj.py` | decode a chained record table; **prove a base by disjointness across all records** | **A** (disjointness proof) + **D** | high as a method | content |
| `tools/snd_macros.py` | answer "the command space" with a negative that makes the positive usable | **A** + **D** | high as a method | content |
| `tools/sound_decode.py` | decode a codec; validate by a **discriminator** (shared book vs per-sample) | **A** + **D** | high as a method | content |
| `tools/voice_decode.py` | decode by **executing the target's own synthesis**; plus a transcription | **A** (execute when reading is unfaithful) + **D** | high as a method | content |
| `tools/voice_sweep.py` | whole-bank transcription verification with a stated live stratum | **A** + **D** | high | content |
| `tools/voice_loops.py` | refute a claim using a **control boundary that could have fired** | **A** (control boundary) + **D** | **high** | content |
| `tools/voice_lists.py` | cross-predict one parsed field against another across samples | **A** (cross-prediction) + **D** | **high** | content |
| `tools/voice_descriptor.py` | descriptor fields each cited to the statement that writes them | **A** (cite the writer) + **D** | high | content |
| `tools/smpdir.py` | decode a record; publish `not_claimed` for fields it refuses to name | **A** + **D** | high | content |
| `tools/rsp_decode.py` | decode a coprocessor program; name what the cited table supports, refuse the rest | **A** + **D** | medium | content; 2 words remain refused |
| `tools/rsp_iface.py` | build a real successor function; find unreachable words | **A** + **D** | medium | content |
| `tools/file_table.py` | (Part 2) | D | — | — |
| `tools/sound_fixtures.py` | (Part 1) | A+D | — | — |
| `tools/find_bank_writers.py` | (Part 3) | D | — | — |
| remaining 5 (smpdir adjacents, sweep helpers) | supporting decoders | **D** | low | content |

**Five transferable methods in this cluster**, worth naming separately because they are the project's most
sophisticated reasoning: the **disjointness proof** of a record base; the **discriminator** as validation; the
**control boundary** that could have fired; **cross-prediction** between independently parsed fields; and
**citing the writer** for every field named.

---

## Part 7 — Execution, differential, checkpoint (11 files)

| path | responsibility | class | reuse potential | known limitation |
|---|---|---|---|---|
| `tools/mips_harness.py` | partial ISA interpreter that **names its faults** and prints what it stubbed | **A** (name the stubs) + **C** | **very high as a pattern** | MIPS-specific; libultra stubs |
| `tools/test_harness.py` | ISA semantics tested against the architecture, not the harness | **B** + **C** | high | MIPS III only |
| `tools/run_scheduler.py` | cooperative scheduler; writes the 8-file checkpoint + digest | **A** (digest-addressed state) + **C** | high | host-side thread semantics by design |
| `tools/run_guest_sched.py` | phase 2: the guest owns scheduling; no hooks | **A** + **C** | medium | MIPS/libultra |
| `tools/probe.py` | interrupt injection; two hard-won host rules recorded | **A** + **C** | medium | content |
| `tools/diff_rdram.py` | memory differential; **page classes, two of which are not evidence** | **A** | **very high** | needs an external emulator |
| `tools/diff_unicorn.py` | **RETIRED**, kept for its host findings | **A** (retire but preserve) | medium as a pattern | retired |
| `tools/ares_rsp.py` | drive an external emulator over a debug protocol; distinguish CLOSED from NO REPLY | **A** (CLOSED vs NO REPLY) + **C** | medium | one emulator's protocol |
| `tools/rdram_fixture.py` | synthetic memory dump for the walk path | **A** + **D** | medium | depends on the walker, so artifact-dependent in fact |
| `tools/dump_fingerprint.py` | make "same state?" a measurement with static controls | **A** (static control) + **D** | medium | content |
| `tools/pad_layout.py` | decode an SI command block; correct a published misinterpretation | **C** (N64-wide) + **D** | medium | controller layout is N64 |

`checkpoint/` (8 files) is **A** as a record shape — a state snapshot plus a digest over its own contents — and
**D** in content.

---

## Part 8 — Matching / build side (12 files)

| path | responsibility | class | reuse potential | known limitation |
|---|---|---|---|---|
| `tools/compile_probe.py` | compiler-profile enumeration + byte diff + **independent codegen census** | **A** + **C** (profiles) | **very high as a method** | 2963 lines; corpus is RE2's |
| `tools/match_diff.py` | comparator proved by self-compare + one-word perturbation; names the first difference | **A** | **very high** | image table local |
| `tools/splat_boot.py` | segmentation dress rehearsal: tiling, reassembly, cross-segmentation agreement | **A** (four proofs) + **D** | **high** | one image |
| `tools/shape_solver.py` | enumerate shape variants; score by words identical to the image | **A** + **C** | high | defaults local |
| `tools/make_seeds.py` | symbol table → per-image seed files, cross-checked against the manifest | **A** + **D** | medium | TSV contract |
| `tools/run_corpus.py` | two-phase corpus runner; **a cancelled run is not a failure** | **A** | high | decompiler-specific |
| `tools/toolchain/provision.sh` | build the toolchain natively; doctor mode; never fetch proprietary binaries | **A** (the provisioning discipline) + **C** | medium | this toolchain |
| `tools/toolchain/patch_gcc281_fp.py` | patch the compiler; every anchor must match exactly once; idempotent | **A** (anchor-assertion discipline) + **C** | medium | this compiler |
| `fixtures/permuter/p6/` | the **proxy-vs-real objective** lesson made committable | **A** | **high** | content |
| `fixtures/permuter/d60/` | a **negative** permuter result with the boundary named | **A** | high | content |
| `tools/splat_inventory.py` | (Part 2) | B | — | — |
| `tools/recovered.py` | (Part 4) | A+D | — | — |

`target-draft.o` deserves its own line in the standard: **committing the wrong objective is a methodological
act.** It makes a retraction reproducible after the inputs that produced it have been destroyed, and it is the
reason the project could later say "the plateau was the objective, not the tool".

---

## Part 9 — Documentation corpus (237 files)

| group | responsibility | class | reuse potential | limitation |
|---|---|---|---|---|
| `README.md` | front page: claim, quickstart, proof, jargon, inventory | **A** (the *shape*: measurable claim, no-ROM quickstart, proof-in-bytes) + **D** | high as a template | 14 stale figures present |
| `docs/handover.md` | cold-start resume: verified state as a table, tools, rules, next step | **A** | **very high as a template** | 9 stale figures present |
| `docs/VERIFICATION.md` | the verifier's standing brief; the three states; the cycle contract | **A** | **very high** — the doctrine, stated | — |
| `docs/TOOLCHAIN.md` | what is proven, what is hypothesised, what the owner must supply | **A** | high | this toolchain's obstacles |
| `docs/format_notes.md` (2523 lines) | the format reference; each claim names its tool and measurement; `hypothesis` marked | **A** (structure) + **D** (content) | high as a structure | §5 "still unidentified" is partly superseded in place |
| `docs/reverse_engineering_log.md` (457 KB) | milestone rows + retraction table + error list + working method | **A** | **very high** | rows not chronological; one malformed row; two duplicate ids |
| `docs/log/` (229 notes) | one note per milestone; template with "what this does not say" and "Gates" | **A** | **very high as a template** | no machine-readable state field |
| `docs/MILESTONES.md` | generated index; **56 gaps named** | **A** | high | — |
| `docs/announcement-v1.0.md`, `v1.1.md` | published snapshots, left as published | **D** | low | superseded figures deliberately not edited |

---

## Part 10 — Data: manifests, fixtures, headers, config (49 files)

| group | responsibility | class | reuse potential | limitation |
|---|---|---|---|---|
| `manifests/byte_map.json` | total partition of image bytes | **A** (record shape) + **D** | high | 1 210 600 vs `code_index` 1 211 256 (656 B, unreconciled) |
| `manifests/code_index.json` | per-function identity, extents, callees, coverage | **A** + **D** | high | — |
| `manifests/analysis_status.json` | the ladder + axes, with the rules published | **A** | **high** | — |
| `manifests/call_graph.json` | evidence-carrying graph | **A** + **D** | high | 15 535 edges |
| `manifests/provenance.json` | operand census with a `kinds` histogram that sums to the total | **A** + **D** | high | — |
| `manifests/{snd_*,voice_*,smpdir,sound_ops}.json` (7) | sound-family decodings with `refuses`/`not_claimed` fields | **D** | low | content |
| `manifests/{dispatch_heads,head_index,extent_audit,callback_table,handler_region,jump_tables,store_loops,bank_writers}.json` | structural decodings | **D** | low | content |
| `manifests/{manifest,overlay_table,code_census,block_types,asset_families,missed_functions,extent_corrections,script_population,vm_refusals,scratch}.json` | cartridge/container/structure facts | **D** | low | content |
| `fixtures/gates/ratchet.json` | the drift baseline (registry + tree hash) | **A** + **D** | **high** | — |
| `fixtures/decomp/{ranges,images,recovered}.json` | committed boundaries, inventory, recovered extents | **A** (shrink-to-fixture) + **D** | high | recovered extents applied on one path only |
| `fixtures/scd/*` (5) | opcode tables, names with attribution, profile, registry with refusals, trace cases | **A** (schema) + **D** (content) | high | — |
| `fixtures/sound/{codec,mort_sweep,loop_sweep}.json` | codec constants, per-clip sweep, loop control | **A** + **D** | high | — |
| `fixtures/corpus/cart.z64` (8 KiB) + `fixtures/corpus/decomp/` | **synthetic target** so the whole pipeline runs without the real one | **A** | **very high** | synthetic; cannot reproduce the target's addresses |
| `fixtures/permuter/*` | proxy objective, candidates, negative result | **A** + **D** | high | — |
| `fixtures/milestones/{commits,gaps}.json` | the record's own index and named gaps | **A** | high | — |
| `include/re2_formats.h`, `include/tyrant.h` | laws and types as includable C; `MEASURED`, not `sizeof` | **A** (codify the law for the rebuild) + **D** | high | content |
| `include/{include_asm,labels,macro}.inc` | splat support | **C** | low | splat-specific |
| `config/{symbols.tsv,functions.csv,symbol_addrs*.txt}` | seed and symbol data | **D** | low | content |
| `config/{boot,residentevilii}.yaml` | splat config | **C** | low | splat + this target |
| `config/rejected_*.txt` | **rejected seeds and tables, kept** | **A** (record rejections) | high as a practice | content |
| `src/` (3590 `.c` + `INDEX.md`) | the corpus; provenance header per file | **A** (header schema) + **D** (content) | header high, content none | derivative work; licence stated |
| `checkpoint/` (8 files) | digest-addressed execution state | **A** (record shape) + **D** | high | not regenerated by CI |
| `THIRD_PARTY.md`, `LICENSE` | attribution and licence separation | **A** | high as a practice | — |

---

## Part 11 — Counts, so the map is falsifiable

| class | files (of 102 in `tools/`) | note |
|---|---|---|
| **B** (generic implementation, ~as-is) | **9** — `wrap_mips_elf`, `mkmips`, `splat_inventory`, `patch_text`, `hook_cert`, `preflight`, `n64info` (within N64), `scan_banks` (within N64), `ocr_pdf.swift` | peripheral to the methodology |
| **A** (generic mechanism, target content) | **~45** | the methodology's home |
| **A+C / A+D** (mixed — the majority) | counted in the A row where the mechanism dominates | this mixing is the central finding |
| **C** (target adapter) | **~18** | the natural adapter surface |
| **D** (target-specific research) | **~30** | content, not method |

**The finding that matters:** only **9 of 102** files are reusable as code, and none of those nine is a
high-value methodological component. **Every high-value component is A+D or A+C** — a generic idea welded to
this target's constants. That is the empirical case for the boundary in
[`ARCHITECTURE.md`](ARCHITECTURE.md) §2: standardise the **records and contracts**, not the code.

`ocr_pdf.swift` is included for completeness and is genuinely B — it renders and OCRs any PDF — while being
irrelevant to reconstruction methodology. It is a good illustration that "reusable" and "valuable" are
different axes.
