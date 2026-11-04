# Milestones

Every milestone this project recorded, in numeric order, with the evidence behind it.

**This file is generated** by `tools/milestone_index.py`; do not edit it by hand. `--check` fails when it
and `docs/reverse_engineering_log.md` disagree, so the two cannot drift. The *record* is that log (one line
per milestone, plus a retraction table) and `docs/log/M<n>-*.md` (one note per milestone); this is the index
to them, and the frontpage carries a curated [phase table](../README.md#milestones) over the same ground.

305 milestones are indexed. 227 of them have a note; the rest are rows in the log that cite
`docs/format_notes.md` instead. **56 have no record at all** — 24, 31–78, 80, 172, 240–244 — and they appear in place, marked
*(no row, no note)*: an index that hides its gaps is worse than one that names them. Why they are empty is
at the foot of this file.

| # | milestone | evidence |
|---|---|---|
| 0 | **M0** — MIPS big-endian decompiles through REA→Ghidra at all | `tools/mkmips.py` known-truth fixture |
| 1 | **M1** — ROM identification | `docs/log/M1-rom-identification.md` |
| 2 | **M2** — real ROM code reaches the decompiler | `docs/log/M2-boot-code-decompiles.md` |
| 3 | **M3** — libultra naming, and what other N64 decomps do differently | `docs/log/M3-libultra-naming-and-research.md` |
| 4 | **M4** — ROM structure without disassembly | `docs/log/M4-bank-structure.md` |
| 5 | **M5** — the PI DMA loader routines | `docs/log/M5-pi-loader-found.md` |
| 6 | **M6** — the ROM→VRAM mapping is not a stored table (three hypotheses eliminated) | `docs/log/M6-mapping-not-a-table.md` |
| 7 | **M7** — The ROM→VRAM mapping was wrong, and it invalidated every address so far | `docs/log/M7-mapping-correction.md` |
| 8 | **M8** — The ROM→VRAM map found: a 16-byte cart descriptor table at vram 0x80012150 | `docs/log/M8-file-table-found.md` |
| 9 | **M9** — The cartridge unpacked: 4 761 zlib members, 1 227 JPEG frames, an MPEG-1 movie | `docs/log/M9-unpacked.md` |
| 10 | **M10** — media container format recovered and verified; one parser resolves both media kinds, neit… | this file, §4 of `format_notes.md` |
| 11 | **M11** — R3 is not video | `format_notes.md` §5 |
| 12 | **M12** — Stride probe with a shuffle null | `format_notes.md` §5 |
| 13 | **M13** — Phase sweep | `format_notes.md` §5 |
| 14 | **M14** — Match-run length | `format_notes.md` §5 |
| 15 | **M15** — Boot record 0 is the stage-2 code image (`0x80018a80`, 1.17 MB, entry spawns thread id 7)… | `format_notes.md` §5b |
| 16 | **M16** — Stage-2 file open found | `format_notes.md` §5b |
| 17 | **M17** — Registry at `0x8010b2e0` enumerated | `format_notes.md` §5b |
| 18 | **M18** — File-open located | `format_notes.md` §5b |
| 19 | **M19** (i) — Registry cross-ref (`tools/xref_registry.py`, with pointer aliasing) | `format_notes.md` §5b |
| 19 | **M19** (ii) — Overlay scan | `format_notes.md` §5b |
| 20 | **M20** — Stream-walker scan | `format_notes.md` §5b |
| 21 | **M21** — Partial CPU harness built and run (`tools/mips_harness.py`) | `format_notes.md` §5b |
| 22 | **M22** — Scheduler increment | `format_notes.md` §5b |
| 23 | **M23** (i) — COP1/FPU added (float32 rounding, mfc1/mtc1, bc1, S/D arithmetic, cvt, compares, lwc1/ldc… | `format_notes.md` §5b |
| 23 | **M23** (ii) — Experiment A | `format_notes.md` §5b |
| 24 | **M24** — *(no row, no note)* | no evidence in the tree |
| 25 | **M25** — Constant scan | `format_notes.md` §5b |
| 26 | **M26** — Execution checkpoints | `format_notes.md` §5b |
| 27 | **M27** — Send-site census | `format_notes.md` §5b |
| 28 | **M28** — CP0 implemented and validated 5/5 (BadVAddr/Count/Compare/Status/Cause/EPC; acceptance IE… | `format_notes.md` §5b |
| 29 | **M29** — Two mapping corrections applied | `format_notes.md` §5b |
| 30 | **M30** — k0 trace from the vector to the fault | `format_notes.md` §5b |
| 31 | **M31** — *(no row, no note)* | no evidence in the tree |
| 32 | **M32** — *(no row, no note)* | no evidence in the tree |
| 33 | **M33** — *(no row, no note)* | no evidence in the tree |
| 34 | **M34** — *(no row, no note)* | no evidence in the tree |
| 35 | **M35** — *(no row, no note)* | no evidence in the tree |
| 36 | **M36** — *(no row, no note)* | no evidence in the tree |
| 37 | **M37** — *(no row, no note)* | no evidence in the tree |
| 38 | **M38** — *(no row, no note)* | no evidence in the tree |
| 39 | **M39** — *(no row, no note)* | no evidence in the tree |
| 40 | **M40** — *(no row, no note)* | no evidence in the tree |
| 41 | **M41** — *(no row, no note)* | no evidence in the tree |
| 42 | **M42** — *(no row, no note)* | no evidence in the tree |
| 43 | **M43** — *(no row, no note)* | no evidence in the tree |
| 44 | **M44** — *(no row, no note)* | no evidence in the tree |
| 45 | **M45** — *(no row, no note)* | no evidence in the tree |
| 46 | **M46** — *(no row, no note)* | no evidence in the tree |
| 47 | **M47** — *(no row, no note)* | no evidence in the tree |
| 48 | **M48** — *(no row, no note)* | commit only: `4e1aa63` “controlled VI: vectors never installed on this path - correcting M48” |
| 49 | **M49** — *(no row, no note)* | no evidence in the tree |
| 50 | **M50** — *(no row, no note)* | no evidence in the tree |
| 51 | **M51** — *(no row, no note)* | commit only: `b6483df` “the 0x8000dc88 tail is a clean epilogue - M51 hypothesis falsified” |
| 52 | **M52** — *(no row, no note)* | no evidence in the tree |
| 53 | **M53** — *(no row, no note)* | no evidence in the tree |
| 54 | **M54** — *(no row, no note)* | no evidence in the tree |
| 55 | **M55** — *(no row, no note)* | no evidence in the tree |
| 56 | **M56** — *(no row, no note)* | no evidence in the tree |
| 57 | **M57** — *(no row, no note)* | no evidence in the tree |
| 58 | **M58** — *(no row, no note)* | no evidence in the tree |
| 59 | **M59** — *(no row, no note)* | no evidence in the tree |
| 60 | **M60** — *(no row, no note)* | no evidence in the tree |
| 61 | **M61** — *(no row, no note)* | no evidence in the tree |
| 62 | **M62** — *(no row, no note)* | no evidence in the tree |
| 63 | **M63** — *(no row, no note)* | no evidence in the tree |
| 64 | **M64** — *(no row, no note)* | no evidence in the tree |
| 65 | **M65** — *(no row, no note)* | no evidence in the tree |
| 66 | **M66** — *(no row, no note)* | no evidence in the tree |
| 67 | **M67** — *(no row, no note)* | no evidence in the tree |
| 68 | **M68** — *(no row, no note)* | no evidence in the tree |
| 69 | **M69** — *(no row, no note)* | no evidence in the tree |
| 70 | **M70** — *(no row, no note)* | no evidence in the tree |
| 71 | **M71** — *(no row, no note)* | no evidence in the tree |
| 72 | **M72** — *(no row, no note)* | no evidence in the tree |
| 73 | **M73** — *(no row, no note)* | no evidence in the tree |
| 74 | **M74** — *(no row, no note)* | no evidence in the tree |
| 75 | **M75** — *(no row, no note)* | no evidence in the tree |
| 76 | **M76** — *(no row, no note)* | no evidence in the tree |
| 77 | **M77** — *(no row, no note)* | no evidence in the tree |
| 78 | **M78** — *(no row, no note)* | commit only: `2edfb1f` “S1 done: delay-slot-correct interrupt entry fixes the M78 crash” |
| 79 | **M79** — Scoping the interrupt context path | `docs/log/M79-interrupt-scope.md` |
| 80 | **M80** — *(no row, no note)* | no evidence in the tree |
| 81 | **M81** — the code corpus | `docs/log/M81-code-corpus.md` |
| 82 | **M82** — the R4 container, and the stage-2 gaps | `docs/log/M82-r4-container-and-gaps.md` |
| 83 | **M83** — the pipeline audit, and what the differential actually measures | `docs/log/M83-pipeline-audit.md` |
| 84 | **M84** — the static tables: store-runs, jump tables, and the address I had wrong | `docs/log/M84-static-tables.md` |
| 85 | **M85** — the bank-C loader: found as a call chain, with one hop still open | `docs/log/M85-bank-c-loader.md` |
| 86 | **M86** — the loader's contract, and two bugs in the instrument I was about to trust | `docs/log/M86-load-contract-and-harness-bugs.md` |
| 87 | **M87** — the harness fixed under a fixture, the slot map found, and the codec hypothesis tested | `docs/log/M87-harness-fixture-and-slot-map.md` |
| 88 | **M88** — the codec is zlib after all, and the scene slot traces to a heap object | `docs/log/M88-codec-is-zlib-and-scene-slot.md` |
| 89 | **M89** — there is no bank-C caller | `docs/log/M89-no-bank-c-caller.md` |
| 90 | **M90** — the slot-byte writers are not statically derivable, and six audit flags resolved | `docs/log/M90-slot-byte-writers-and-audit-close.md` |
| 91 | **M91** — the bank-C map *is* read, and bank C is not compressed | `docs/log/M91-bank-c-map-is-read.md` |
| 92 | **M92** — one caller, the s0 direction corrected, and index 67 is a build stamp | `docs/log/M92-callers-s0-direction-and-index-67.md` |
| 93 | **M93** — the slot condition fully traced, `cart_record(0)` is a *crash* path, and the build question | `docs/log/M93-slot-condition-and-build-question.md` |
| 94 | **M94** — callers of `FUN_8003287c`, enumerated, and the slot values they pass | `docs/log/M94-callers-enumerated.md` |
| 95 | **M95** — the table at `0x80113898`: three readers, and entry 68 is selected by a byte | `docs/log/M95-table-readers-and-index-68.md` |
| 96 | **M96** — `FUN_8003287c`'s callers and their slot values, enumerated | `docs/log/M96-slot-values-enumerated.md` |
| 97 | **M97** — descriptors are script commands; no code writes their bytes 0 and 3 | `docs/log/M97-descriptors-are-script-commands.md` |
| 98 | **M98** — where the stream comes from: a runtime buffer inside the room overlay | `docs/log/M98-stream-source.md` |
| 99 | **M99** — the stride is settled: a variable-length bytecode, and opcode 0x44 is 22 bytes | `docs/log/M99-stride-settled.md` |
| 100 | **M100** — the watch is set and the probe is built; the one input needed cannot be made here | `docs/log/M100-watch-and-dump-probe.md` |
| 101 | **M101** — the room dump arrived, and it corrects the model: the loader is gated | `docs/log/M101-room-dump-and-the-gate.md` |
| 102 | **M102** — the gate PASSES, and it is vacuous for this descriptor | `docs/log/M102-the-gate-passes.md` |
| 103 | **M103** — the walk: 174 commands, no scene-slot command pending, and slot 31 selects *nothing* | `docs/log/M103-the-walk.md` |
| 104 | **M104** — no other rooms available, and the six "desyncs" are stream ends | `docs/log/M104-no-other-rooms-and-the-six-stops.md` |
| 105 | **M105** — the counter is a flag, and the first real scene-slot commands are found | `docs/log/M105-counter-is-a-flag-and-the-first-slot-commands.md` |
| 106 | **M106** — the maps never populate, and the scene-slot path is a per-execution no-op | `docs/log/M106-maps-never-populate.md` |
| 107 | **M107** — controlling ares directly (design) | `docs/log/M107-ares-control.md` |
| 108 | **M108** — the ares handshake: one byte, and then the whole machine | `docs/log/M108-ares-handshake.md` |
| 109 | **M109** — driving the game through the debugger: the transport works, the input layer doesn't | `docs/log/M109-ares-injection-attempt.md` |
| 110 | **M110** — three rooms, one operand, and the scene-slot path is by design | `docs/log/M110-three-rooms-one-operand.md` |
| 111 | **M111** — experiment B, step 1: a provenance core that survives its own fixture | `docs/log/M111-provenance-step1.md` |
| 112 | **M112** — experiment B, step 2: summaries resolve the record chain, and the map reader stays out of reach | `docs/log/M112-provenance-step2.md` |
| 113 | **M113** — `CONSTBASE`, and what acceptance test 2 actually proves | `docs/log/M113-provenance-cbase.md` |
| 114 | **M114** — jump-table edges: 4 142 new edges, and the `unreached` bucket finally moves | `docs/log/M114-provenance-jump-tables.md` |
| 115 | **M115** — the `unk` bucket: measure the cause first, then fix the one that dominates | `docs/log/M115-provenance-unk-cause.md` |
| 116 | **M116** — frame slots: entry-relative keys, and proof that `spoff` is not an unresolved bucket | `docs/log/M116-provenance-slotkeys.md` |
| 117 | **M117** — Ghidra's function bounds replace my heuristic, and two layer-2 fabrications fall out | `docs/log/M117-ghidra-bounds.md` |
| 118 | **M118** — frame slots are 98.5 % resolved; the residual is stack arguments, and the tests are now executable | `docs/log/M118-provenance-slot-misses.md` |
| 119 | **M119** — stack-argument propagation: the mechanism resolves 89.8 %, and buys seven addresses | `docs/log/M119-provenance-stack-args.md` |
| 120 | **M120** — the caller-side check: 7 sites out of 14 371, and one of them read from the instructions | `docs/log/M120-provenance-stk-check.md` |
| 121 | **M121** — reading the callee: seven confident flags, all mine | `docs/log/M121-provenance-stk-verdict.md` |
| 122 | **M122** — the register-argument check: same method, different question, and it needed four calibrations | `docs/log/M122-provenance-arg-check.md` |
| 123 | **M123** — path sensitivity clears the polymorphic sites, and what perfect_dark is actually good for | `docs/log/M123-path-sensitivity-and-perfect-dark.md` |
| 124 | **M124** — the controller layout, diffed against perfect_dark's libultra | `docs/log/M124-controller-layout-diff.md` |
| 125 | **M125** — the CHNL_ERR path, made executable | `docs/log/M125-chnl-err-made-executable.md` |
| 126 | **M126** — `pad_layout` in the acceptance suite, and a mixed-errno fixture that changed a behaviour | `docs/log/M126-acceptance-suite.md` |
| 127 | **M127** — a pre-commit hook that runs the acceptance suite | `docs/log/M127-pre-commit-hook.md` |
| 128 | **M128** — CI: the same acceptance run, locally and on a runner | `docs/log/M128-ci.md` |
| 129 | **M129** — a 9 KB synthetic cartridge, so the corpus pipeline runs in CI | `docs/log/M129-synthetic-corpus.md` |
| 130 | **M130** — can the last three checks run in CI? Two blockers, one of them removable | `docs/log/M130-corpus-checks-in-ci.md` |
| 131 | **M131** — a scripted edit now fails loudly instead of doing nothing | `docs/log/M131-loud-patches.md` |
| 132 | **M132** — the marker check: the loop M131 left open | `docs/log/M132-marker-check.md` |
| 133 | **M133** — the marker check now runs in both directions | `docs/log/M133-marker-reverse-check.md` |
| 134 | **M134** — the registration check extended to the notes themselves | `docs/log/M134-note-registration.md` |
| 135 | **M135** — being registered is not the same as being registered correctly | `docs/log/M135-index-consistency.md` |
| 136 | **M136** — the 141 handlers, mapped: every opcode advances the stream by its own N | `docs/log/M136-command-length-map.md` |
| 137 | **M137** — Phase 2 starts from a reference, and its fingerprints do not yet fire on our data | `docs/log/M137-phase2-reference-and-negative-tests.md` |
| 138 | **M138** — the registry route pays: nine 8-byte entries, the room's own entry point, and two confirmed structures | `docs/log/M138-registry-route.md` |
| 139 | **M139** — S2DEX is searchable: OCR with the OS, no installs | `docs/log/M139-s2dex-ocr.md` |
| 140 | **M140** — the enemy routine table is found; the room header is runtime data, and that closes the static route | `docs/log/M140-enemy-table-and-room-header.md` |
| 141 | **M141** — OpenBiohazard2 names the opcodes, and it breaks the "one length per opcode" claim | `docs/log/M141-openbiohazard2-names-the-opcodes.md` |
| 142 | **M142** — the licensed table is imported, the walk refuses to guess, and M141's own correction was wrong | `docs/log/M142-licensed-table-and-a-walk-that-refuses.md` |
| 143 | **M143** — the jump family decodes, and `0x32 Poset` was never missing a length, only a window | `docs/log/M143-jump-decoder-and-poset.md` |
| 144 | **M144** — `0x03` is a script jump, the advance scan becomes a dataflow, and the walk is in the gate | `docs/log/M144-script-jump-dataflow-and-walk-gate.md` |
| 145 | **M145** — all 141 opcodes classified, and the script base turns out to be a cartridge block | `docs/log/M145-all-opcodes-classified-and-the-script-base.md` |
| 146 | **M146** — the id resolves, and a real room script decodes out of the cartridge | `docs/log/M146-room-script-decoded-from-cartridge.md` |
| 147 | **M147** — the whole file table swept: 102 673 commands, every opcode seen, and the shape of a scenario | `docs/log/M147-opcode-profile.md` |
| 148 | **M148** — a dozen opcode reads, and a second naming source that cannot be confused with the first | `docs/log/M148-twelve-opcode-reads.md` |
| 149 | **M149** — the two-NOP question, and three more reads (one of them a random number generator) | `docs/log/M149-two-nops-and-three-more-reads.md` |
| 150 | **M150** — the block-return slots are modelled, the CFG walk is real, and the NOP answer flips | `docs/log/M150-block-slots-and-the-nop-answer.md` |
| 151 | **M151** — the 1 % was my own defect, the GoSub stride settles, and the dead-code list exists but is not proof | `docs/log/M151-orphans-stride-and-dead-code.md` |
| 152 | **M152** — the callback theory is refuted by the code, and the interpreter loop is now read | `docs/log/M152-callback-theory-refuted.md` |
| 153 | **M153** — both leads closed: the dead-only list falls from 8 to 2, and the stream exits were right | `docs/log/M153-both-leads-closed.md` |
| 154 | **M154** — no direct starter exists, `0x0f` was mis-sized, and a guard-order bug made my own model inert | `docs/log/M154-no-direct-starter-and-a-guard-order-bug.md` |
| 155 | **M155** — the gate audited: three checks were vacuous, and two of my audit's own mutations were too | `docs/log/M155-gate-audit.md` |
| 156 | **M156** — both leads closed, by asking a smaller question | `docs/log/M156-room-population-closes-both-leads.md` |
| 157 | **M157** — the rule applied backwards: every earlier population, audited | `docs/log/M157-population-audit-retrospective.md` |
| 158 | **M158** — the section-table hypothesis is refuted, and the room table turns out to be a resource table | `docs/log/M158-section-table-refuted-resource-table.md` |
| 159 | **M159** — the `01 41` count field is decoded: 16 bytes per unit, proven on 355 of 355 | `docs/log/M159-container-count-decoded.md` |
| 160 | **M160** — the correlation run: N is neither a bit depth nor a value count | `docs/log/M160-correlation-refutes-bit-depth.md` |
| 161 | **M161** — the display-list reading, tested and refuted | `docs/log/M161-display-list-reading-refuted.md` |
| 162 | **M162** — relational: the family is what the *model* loaders load | `docs/log/M162-relational-loader-kinds.md` |
| 163 | **M163** — the three calls read: relocation, part filter, and a tile grid of *display lists* | `docs/log/M163-three-calls-relocation-grid-display-lists.md` |
| 164 | **M164** — dumping the tile: there is no GBI in it, and M163 was wrong | `docs/log/M164-tile-dump-refutes-gbi.md` |
| 165 | **M165** — the T64 tiles decoded: no compression, a palette and raw indices | `docs/log/M165-t64-format-no-compression.md` |
| 166 | **M166** — `h1` is the true height, not a stride | `docs/log/M166-h1-is-the-height.md` |
| 167 | **M167** — palettes are not shared: the engine shares whole tiles | `docs/log/M167-palettes-not-shared.md` |
| 168 | **M168** — the handle's high byte is a global allocation counter, not a per-slot generation | `docs/log/M168-registry-handle-generation.md` |
| 169 | **M169** — nothing else writes the handle, and the use path doesn't just compare: it traps | `docs/log/M169-handle-writers-and-the-trap.md` |
| 170 | **M170** — `trap(0)` is `break`, and the exception path never returns | `docs/log/M170-break-halts.md` |
| 171 | **M171** — where it stops, and why nothing software can do will restart it | `docs/log/M171-where-it-stops.md` |
| 172 | **M172** — *(no row, no note)* | commit only: `cc1673b` “M172: drop a citation to a file the repo does not have”, `c26d44a` “M172: consolidate for a rebuild — the format header, its C validator, and the start-here doc” |
| 173 | **M173** — `obj+5` is not bounded below 14, and 14 turns out not to be the bound | `docs/log/M173-obj-plus-5-is-not-bounded.md` |
| 174 | **M174** — the runner CI that never ran, the suite that would have gone red, and the two mistakes I made finding them | `docs/log/M174-the-ci-that-never-ran.md` |
| 175 | **M175** — the self-hosted tier: all 230 cases in CI without uploading the cartridge | `docs/log/M175-the-self-hosted-tier.md` |
| 176 | **M176** — the secret holds access, not bytes: CI fetches the cartridge | `docs/log/M176-the-secret-holds-access.md` |
| 177 | **M177** — publication readiness: a frontpage, a licence, and a copyright audit that reads bytes | `docs/log/M177-publication-readiness.md` |
| 178 | **M178** — the file table is the file system, and the 17.6 MB is the sound family | `docs/log/M178-file-table-and-the-sound-family.md` |
| 179 | **M179** — `u16@+4` refuted three ways, and the directory becomes a reading | `docs/log/M179-u16-at-plus-4-refuted-and-the-directory-read.md` |
| 180 | **M180** — the counts are derived, not hand-edited | `docs/log/M180-counts-derived-and-asserted.md` |
| 181 | **M181** — the verifier | `docs/VERIFICATION.md`, `tools/verify.py`, `tools/audit_gates.py` |
| 182 | **M182** — nothing in the corpus reads the record header | `docs/log/M182-nothing-in-the-corpus-reads-the-record-header.md` |
| 183 | **M183** — a milestone that exists only as a commit is refused | `docs/log/M183-a-milestone-that-exists-only-as-a-commit.md` |
| 184 | **M184** — id 1983 is parsed at the container level, and its codec is a named gap | `docs/log/M184-id-1983-framed-and-its-codec-named.md` |
| 185 | **M185** — the sound family is framed: proj and pool are chained section tables | `docs/log/M185-the-sound-family-framed.md` |
| 186 | **M186** — the 835 unresolved shorts are 834 zeros and one dangling reference | `docs/log/M186-the-835-resolved.md` |
| 187 | **M187** — the codec is identified: MusyX ADPCM, with a 16-byte prologue | `docs/log/M187-the-codec-identified.md` |
| 188 | **M188** — the two holes: 531 is a stale index, 11 is an unused slot | `docs/log/M188-the-two-holes.md` |
| 189 | **M189** — id 1979 is a second codec, its header is 12 bytes, and the 418 is a rotation | `docs/log/M189-a-second-codec-and-the-rotation.md` |
| 190 | **M190** — the 2.42 % was my alignment error, and `u16@+4` stays unassigned | `docs/log/M190-the-residual-was-mine.md` |
| 191 | **M191** — `u16@+4` closed as unassignable, the codebook fields confirmed, and the README fixed | `docs/log/M191-u16-closed-codebook-confirmed-readme-fixed.md` |
| 192 | **M192** — the codec's header fields are understood, and `u16@+4` is closed with its reason | `docs/log/M192-codec-fields-understood-u16-closed.md` |
| 193 | **M193** — `u16@+4` is the block count, and the pool codec is decoded | `docs/log/M193-u16-is-the-block-count-and-the-codec-is-decoded.md` |
| 194 | **M194** — the voice decoder is not implemented, and the description does not fit this cartridge | `docs/log/M194-the-voice-decoder-does-not-reconcile.md` |
| 195 | **M195** — `FUN_800b53f4` transcribed field by field, and why the decode still does not run | `docs/log/M195-the-voice-stream-transcribed-and-the-ring.md` |
| 196 | **M196** — the suite was slow because it recomputed, not because it was Python | `docs/log/M196-the-suite-was-recomputing.md` |
| 197 | **M197** — the ring does nothing to the bytes, and the reader reverses them | `docs/log/M197-the-ring-does-nothing-and-the-reader-reverses.md` |
| 198 | **M198** — the voice bank decodes to audio, by running the cartridge's own synthesis | `docs/log/M198-the-voice-bank-decodes-to-audio.md` |
| 199 | **M199** — the voice synthesis is transcribed, and it agrees with the cartridge sample for sample | `docs/log/M199-the-synthesis-is-transcribed.md` |
| 200 | **M200** — the pool's classes, pinned from the data | `docs/log/M200-the-pools-classes-pinned.md` |
| 201 | **M201** — the 16-byte records, and the encoding hiding in them | `docs/log/M201-the-16-byte-records-are-little-endian.md` |
| 202 | **M202** — the four parameters named, and what feeds cache B | `docs/log/M202-the-parameters-and-the-pairing.md` |
| 203 | **M203** — +20 and +24 are a loop start and a loop *length* | `docs/log/M203-loop-start-and-loop-length.md` |
| 204 | **M204** — there is no +28: the record ends at +27 | `docs/log/M204-there-is-no-plus-28.md` |
| 205 | **M205** — the coverage figure was one word per function body too high | `docs/log/M205-the-coverage-figure-was-one-word-high.md` |
| 206 | **M206** — the manifest published a word count as `covered_bytes` | `docs/log/M206-the-manifest-published-words-as-bytes.md` |
| 207 | **M207** — the other 37.8 % is classified, not shrugged at | `docs/log/M207-the-rest-of-the-image-bytes-classified.md` |
| 208 | **M208** — the census was a whole corpus generation stale, and the cull is a decision | `docs/log/M208-the-census-was-a-generation-stale.md` |
| 209 | **M209** — "3 638 decompiled" is one claim; here are the four that are not it | `docs/log/M209-the-ladder-and-the-two-axes.md` |
| 210 | **M210** — three published claims corrected, and the landing unit becomes a cycle | `docs/log/M210-three-claims-and-the-cycle-contract.md` |
| 211 | **M211** — the registry, and the multi-advance claim it disproved | `docs/log/M211-the-registry-and-the-multi-advance-refutation.md` |
| 212 | **M212** — the VM needs corrected extents, not new functions | `docs/log/M212-the-vm-needs-extents-not-functions.md` |
| 213 | **M213** (i) — a decoder that refuses | `docs/log/M213-a-decoder-that-refuses.md` |
| 213 | **M213** (ii) — a decoder that refuses | `docs/log/M213-a-decoder-that-refuses.md` |
| 214 | **M214** — 50 of 1 049 are room scripts, and the other 999 now have names for what they are | `docs/log/M214-fifty-of-a-thousand-and-forty-nine.md` |
| 215 | **M215** — a call graph whose edges carry their evidence, and whose unknown targets stay unknown | `docs/log/M215-a-call-graph-that-carries-its-evidence.md` |
| 216 | **M216** — verification was costing more than the work, so it now has three tiers | `docs/log/M216-three-tiers-so-verification-stops-eating-the-work.md` |
| 217 | **M217** — TYRANT is a codename, and what each layer may claim | `docs/log/M217-tyrant-is-a-codename-and-what-the-layers-may-claim.md` |
| 218 | **M218** — WP1: the six project lists are named by their consumers, and the macro opcodes are not here | `docs/log/M218-the-six-project-lists-and-no-macros.md` |
| 219 | **M219** — the base correction lands, and one claim survives it that I had already retracted | `docs/log/M219-the-base-correction-and-a-retraction-retracted.md` |
| 220 | **M220** — WP2: the macro "opcodes" are the key's class tag, and the pool walk was one record late | `docs/log/M220-wp2-the-opcodes-are-the-tag.md` |
| 221 | **M221** — WP3: every one of the 588 voice clips, and 12 037 live comparison blocks | `docs/log/M221-wp3-the-whole-voice-bank.md` |
| 222 | **M222** — WP3b: the voice descriptor, and the correction to my own `+0x1a4` | `docs/log/M222-wp3b-the-voice-descriptor.md` |
| 223 | **M223** — the RSP ucode: decoded, and deliberately not named | `docs/log/M223-the-rsp-ucode-decoded-but-not-named.md` |
| 224 | **M224** — the interface is a frame loop, not a command list | `docs/log/M224-the-interface-is-a-frame-loop-not-a-command-list.md` |
| 225 | **M225** — the vector unit, named: 252 of 254, and the two that stayed refused | `docs/log/M225-the-vector-unit-named.md` |
| 226 | **M226** — the 0x36 table: five entries, and an address that was 0x10000 wrong | `docs/log/M226-the-0x36-table-and-an-address-0x10000-wrong.md` |
| 227 | **M227** — the extent queue, audited: 16 extensions, 5 merges, and one that would eat a callable | `docs/log/M227-the-extent-queue-audited.md` |
| 228 | **M228** — eighty-six dispatch heads, and the queue entry that has no valid extension | `docs/log/M228-eighty-six-dispatch-heads.md` |
| 229 | **M229** — the last three unresolved handlers, and the rule that was missing | `docs/log/M229-the-last-three-unresolved-handlers.md` |
| 230 | **M230** — what the eighty-three non-script heads dispatch on | `docs/log/M230-what-the-heads-dispatch-on.md` |
| 231 | **M231** — the window was never the problem: 35 `local` heads, and a fold that was too narrow | `docs/log/M231-the-window-was-never-the-problem.md` |
| 232 | **M232** — the audit was not testing anything: 49 of 132 mutations were never run | `docs/log/M232-the-audit-that-was-not-testing-anything.md` |
| 233 | **M233** — the sound commands: six opcodes, one that plays nothing, and one dead operand | `docs/log/M233-the-sound-commands.md` |
| 234 | **M234** — the record-table families: two script ranges, one undecoded container, and no 48 | `docs/log/M234-the-record-table-families.md` |
| 235 | **M235** — loop discontinuities: there are none, and the reason is silence | `docs/log/M235-loop-discontinuities.md` |
| 236 | **M236** — the per-scene voice lists are in the image, and bit 15 proves it | `docs/log/M236-the-per-scene-voice-lists.md` |
| 237 | **M237** — the clip-61 rate exception: real in the data, and not a reading error | `docs/log/M237-the-clip-61-rate-exception.md` |
| 238 | **M238** — the sampler record decoded, and the six frames the decoder never sees | `docs/log/M238-the-sampler-record-and-the-six-skipped-frames.md` |
| 239 | **M239** — the prefix is 256 after all: M238's central claim was wrong, and the patch it implied must not be made | `docs/log/M239-the-prefix-is-256.md` |
| 240 | **M240** — *(no row, no note)* | commit only: `a5a76ad` “M240: a verification prototype that discovers inputs and caches on content” |
| 241 | **M241** — *(no row, no note)* | commit only: `4f48acb` “M241: include/tyrant.h -- the Script VM as types, generated from the registry” |
| 242 | **M242** — *(no row, no note)* | commit only: `95fe500` “M242: match_diff.py -- name the first differing instruction, proved both ways” |
| 243 | **M243** — *(no row, no note)* | commit only: `8323b0e` “M243: the splat dress rehearsal on the boot image -- map verified, assembler absent” |
| 244 | **M244** — *(no row, no note)* | no evidence in the tree |
| 245 | **M245** — both toolchains run: IDO 5.3 and 7.1 native, GNU as/ld for mips | `docs/log/M245-both-toolchains-run.md` |
| 246 | **M246** — the compile-probe corpus: IDO is refuted, and 5.3 and 7.1 are the same compiler | `docs/log/M246-the-compile-probe-corpus.md` |
| 247 | **M247** — gcc 2.7.2 matches: three of four probes byte-for-byte, against IDO's one | `docs/log/M247-gcc-272-matches.md` |
| 248 | **M248** — the linked comparison: p3 resolves and the residue is two words, in the assembler | `docs/log/M248-the-linked-comparison.md` |
| 249 | **M249** — the SDK-era assembler: `move` explained, and p3's residue is not the assembler | `docs/log/M249-the-sdk-era-assembler.md` |
| 250 | **M250** — gcc 2.8.1: four of four probes byte-exact, and the compiler is identified | `docs/log/M250-gcc-281-four-of-four.md` |
| 251 | **M251** — the four extra classes: the cartridge has no cheap probe for any of them | `docs/log/M251-the-four-classes-refused.md` |
| 252 | **M252** — the linked switch head: the dispatch sequence is exact, and the one differing instruction is the arms' | `docs/log/M252-the-linked-switch-head.md` |
| 253 | **M253** — three more dispatch heads: bounds 5/6/7/7, four index sources, and two layout facts | `docs/log/M253-three-more-dispatch-heads.md` |
| 254 | **M254** — p6's arms recovered: the delay slot matched, and the rest is a reconstruction in progress | `docs/log/M254-recovering-p6s-arms.md` |
| 255 | **M255** — arms 2–4: the order was already right, and the region comparison was not | `docs/log/M255-p6-arms-the-order-was-already-right.md` |
| 256 | **M256** — the permuter plateaued at 1 900; the fix it could not find was one operand order | `docs/log/M256-the-permuter-plateau-and-the-operand-that-moved.md` |
| 257 | **M257** — p7 recovered: 60 of 84 words, a table that matches 8 of 8, and the toolchain fact that blocks stage 5 | `docs/log/M257-p7-recovered-and-the-toolchain-fact-that-blocks-stage-5.md` |
| 258 | **M258** — the rule that sinks that store is not in mips.c, and it is a dependence gcc drops | `docs/log/M258-the-rule-that-sinks-that-store.md` |
| 259 | **M259** — the permuter's 1 780 is not a matching improvement: its score and the byte diff disagree | `docs/log/M259-the-permuters-1780-moves-no-words.md` |
| 260 | **M260** — p8 recovered (116 of 139, best arm byte-exact) and two defects in our own toolchain | `docs/log/M260-p8-recovered-and-two-defects-in-our-own-toolchain.md` |
| 261 | **M261** — the FP pool bug is a 64-bit-host bug, and fixing it changed *codegen*, not just data | `docs/log/M261-the-fp-pool-fix-and-its-second-symptom.md` |
| 262 | **M262** — the last p7 hunk is unreachable from the source: five variants, one object | `docs/log/M262-the-last-p7-hunk-is-unreachable-from-the-source.md` |
| 263 | **M263** — `-mcpu=r4300`: p7 is byte-exact, and the "unreachable" residues were a build flag | `docs/log/M263-mcpu-r4300-p7-byte-exact.md` |
| 264 | **M264** — re-read under the r4300 cost model: p6 is byte-exact too, and p8's last difference is a placement | `docs/log/M264-reread-p6-exact-p8-is-a-placement.md` |
| 265 | **M265** — both patches together: the pool lands where the image's does, and p8's residue changes kind | `docs/log/M265-both-patches-the-pool-lands-where-the-images-does.md` |
| 266 | **M266** — `-msplit-addresses` is refuted, and case 3/4 is an unsigned conversion | `docs/log/M266-split-addresses-refuted-and-case34-is-unsigned.md` |
| 267 | **M267** — the duplicate pool entry is systematic, and removing dedup is not how to match it | `docs/log/M267-the-duplicate-pool-entry-is-systematic.md` |
| 268 | **M268** — the mixed-constant test: duplication is uniform, and "the image dedups floats" was wrong | `docs/log/M268-the-mixed-constant-test-and-two-withdrawals.md` |
| 269 | **M269** — the hoist and the no-dedup, tried together, and the docs brought up to date | `docs/log/M269-the-hoist-and-the-no-dedup-and-docs-brought-up-to-date.md` |
| 270 | **M270** — case 3/4 in the image's statement order: measured, and the current expression is the best of the family | `docs/log/M270-case34-statement-order-measured-and-refuted.md` |
| 271 | **M271** — p9 recovered byte-exact on the second attempt, and the shape facts that made it so | `docs/log/M271-p9-byte-exact-predicate-dispatcher.md` |
| 272 | **M272** — the 167-word state machine: byte-exact, and three shape levers that are discriminators | `docs/log/M272-the-167-word-state-machine-byte-exact.md` |
| 273 | **M273** — the progress map: generated, gated, and honest about being mostly empty | `docs/log/M273-the-progress-map-generated-and-gated.md` |
| 274 | **M274** — the 206-word twelve-arm machine: the widest dispatch, byte-exact, and four single-word discriminators | `docs/log/M274-the-206-word-twelve-arm-machine.md` |
| 275 | **M275** — 0x8007e590, an honest partial: three regions exact, the 113-word arm still open | `docs/log/M275-0x8007e590-an-honest-partial.md` |
| 276 | **M276** — 0x800acae4: the streak held, and four shape facts a 53-word function can pin | `docs/log/M276-0x800acae4-clamp-then-dispatch.md` |
| 277 | **M277** — `0x8007e590`, second pass: every region now the right size, the default arm exact, and two errors that were reading, not reconstruction | `docs/log/M277-0x8007e590-regions-sized-and-two-found-by-wrong-address.md` |
| 278 | **M278** — `0x8007e590` at 226 of 229: the copy block, both table reads, and a switch with no `default` | `docs/log/M278-0x8007e590-226-of-229-transposition-and-exit-kind.md` |
| 279 | **M279** — `0x8007e590` enters the probe at 226 of 229, as a *partial* pin with a regional assertion | `docs/log/M279-0x8007e590-in-the-probe-at-226-of-229.md` |
| 280 | **M280** — `0x800701d8`: 44 cases written, 28 of 141, and a residual that is the compiler, not the C | `docs/log/M280-0x800701d8-44-cases-and-a-compiler-gap.md` |
| 281 | **M281** — `as -g`: the missing assembler flag, and `0x800701d8` byte-exact at 141 of 141 | `docs/log/M281-as-g-the-missing-assembler-flag.md` |
| 282 | **M282** — the gas flag ladder, and a correction to M281: `-O0` cannot work, `-O10` can | `docs/log/M282-the-gas-flag-ladder-and-a-correction.md` |
| 283 | **M283** — re-measured under `-g`: both partials are untouched, and case 4 is still one register | `docs/log/M283-re-measured-under-g-both-partials-untouched.md` |
| 284 | **M284** — the arm-shaped family opens with `0x8006fc5c`: 53 of 53, on the second measurement | `docs/log/M284-the-arm-shaped-family-opens-with-0x8006fc5c.md` |
| 285 | **M285** — `0x8006e6b8`'s enclosing function found, and `0x8006ff48` byte-exact at 98 of 98 | `docs/log/M285-0x8006e68c-identified-and-0x8006ff48-byte-exact.md` |
| 286 | **M286** — both leaves inside the gap: `0x8006e68c` byte-exact at 41, `0x8006e574` at 17 of 23 | `docs/log/M286-both-leaves-inside-the-gap.md` |
| 287 | **M287** — `0x800704e0` byte-exact at 123: the accessor family is now three of three | `docs/log/M287-0x800704e0-the-accessor-trio-complete.md` |
| 288 | **M288** — the index regenerated: 224 "functions" were the provider's own switch cases | `docs/log/M288-the-index-regenerated-224-switch-cases.md` |
| 289 | **M289** — the recovered functions are in the index: 14 pinned, the map shows all of them | `docs/log/M289-recovered-functions-in-the-index.md` |
| 290 | **M290** — the three partials: one closes, two are pinned where they are | `docs/log/M290-the-three-partials-one-closes.md` |
| 291 | **M291** — the pool's sharing rule: the double is per use, the float is per value — and a reproducibility bug the patch had | `docs/log/M291-the-pools-sharing-rule-and-a-patch-bug.md` |
| 292 | **M292** — the `$at`/`$v0` partial closes: the image splits no float address, and `0x80024558` is 139 of 139 | `docs/log/M292-the-float-address-split-and-0x80024558.md` |
| 293 | **M293** — `0x8007e590` at 226 of 229: the toolchain is ruled out, and the last register is local | `docs/log/M293-0x8007e590-the-last-register-is-local.md` |
| 294 | **M294** — the delay-slot scan: 718 sites, and it does **not** justify a `local_alloc` change | `docs/log/M294-the-delay-slot-scan-and-why-it-does-not-justify-a-patch.md` |
| 295 | **M295** — why the register is lost: a conflict, not a tie-break, and not `local_alloc` at all | `docs/log/M295-why-the-register-is-lost-a-conflict-not-a-tie-break.md` |
| 296 | **M296** — the reference-decompilation experiment: `osCreateMesgQueue` byte-exact, and OoT is a *later* libultra | `docs/log/M296-the-reference-decompilation-experiment.md` |
| 297 | **M297** — bracketing the libultra revision, and the second runtime function | `docs/log/M297-bracketing-the-libultra-revision.md` |
| 298 | **M298** — `osCreateThread`: the `OSThread` layout for this revision, 23 of 52, and why CI was queued | `docs/log/M298-oscreatethread-layout-and-why-ci-waited.md` |
| 299 | **M299** — the re-score: M259's verdict was measured against a base that no longer exists, and the solver that follows | `docs/log/M299-the-re-score-and-the-shape-solver.md` |
| 300 | **M300** — the permuter re-run: its ceiling is 94/98 under both weightings, and its objective was never the ROM | `docs/log/M300-the-permuter-rerun-and-its-proxy-objective.md` |
| 301 | **M301** — the front door: a hero, an audience line, a 60-second quickstart, and proof in bytes | `docs/log/M301-the-front-door.md` |
| 302 | **M302** — the permuter, pointed at the image, closes the function: 94/98 was the objective, not the tool | `docs/log/M302-the-permuter-pointed-at-the-image.md` |
| 303 | **M303** — `osCreateThread` under the permuter: a negative result, the shape/allocation boundary, and an inert setting | `docs/log/M303-oscreatethread-under-the-permuter.md` |
| 304 | **M304** — the case-4 select register, decoded: a dead store, a `global_alloc` tie-break, and 32 spellings that change nothing | `docs/log/M304-the-case-4-select-register-decoded.md` |

## The gaps, and why they are empty

**56** milestone numbers have neither a row in `docs/reverse_engineering_log.md` nor a note in `docs/log/`. The project did not keep a note for every number it used: much of the middle work was recorded in `docs/format_notes.md` and in commit messages instead, and the log's own numbering runs M10–M30 in that style before resuming per-milestone notes at M81.

* **M48, M51, M78, M172, M240, M241, M242, M243** survive only as commit subjects, quoted above. Nothing further is known about them, so nothing further is written.
* **24, 31–47, 49–50, 52–77, 80, 244** have no evidence in the tree at all — no row, no note, no commit that names them.

None of these gaps is reconstructed after the fact. A note written from guesswork would be indistinguishable from a note written from measurement, and this project's whole claim is that the difference is visible.
