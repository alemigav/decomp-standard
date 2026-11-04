# M177 — publication readiness: a frontpage, a licence, and a copyright audit that reads bytes

The repository is about to be shown to people, so three questions had to be answered with evidence rather
than confidence: *is anything copyrighted actually in here*, *is that verifiable by a stranger*, and *what
may they legally do with what they find*. This milestone answers all three and repairs what the answering
found.

## 1. The copyright audit, measured

| question | answer |
|---|---|
| ROM bytes in the working tree? | **none.** The only `.z64` is `fixtures/corpus/cart.z64` — 8 192 bytes of synthetic words (M129), beginning with zeros, not a cartridge header |
| ROM bytes anywhere in history? | **none.** 10 908 blobs / 41.6 MiB across 201 commits; filtering every historical path for `.z64/.n64/.bin/.pdf/.zip/.iso/.png/.jpg/.elf` and for `rom/`, `assets/`, `build/` returns that one 8 KiB fixture and nothing else |
| extracted assets, audio, video, code images? | **none tracked.** `assets/` (73 MB), `build/` (122 MB) and three Nintendo SDK PDFs (7.6 MB) are on disk and gitignored |
| largest tracked file | 1 663 139 B — `manifests/code_index.json`, a JSON of addresses |
| what *is* derived from the cartridge | `src/` (3 638 pseudocode files), `manifests/*` (offsets, sizes, hashes), `fixtures/decomp/ranges.json` (3 678 boundaries), `fixtures/scd/*` (opcode tables). No file contains a byte run from the ROM: every `src/` header carries a *hash*, not bytes |

That was true before this milestone. What was missing was any way for a reader to **check** it, and any
statement of what it means legally.

## 2. A guard that reads bytes instead of filenames

The existing scan in `tools/ci.sh` matches path prefixes and extensions. Two ordinary mistakes walk past it:
`git add -f rom/x.dat`, and anything at all under `fixtures/`, which was exempted wholesale so the synthetic
corpus fixture could be committed.

`tools/artefact_scan.py` replaces confidence with five content checks over every tracked file:

1. no file begins with an N64 cartridge header — `80 37 12 40`, `37 80 40 12` or `40 12 37 80`;
2. no file over 1 MiB hashes to `rom_sha256` from the committed `manifests/manifest.json` — name-independent,
   so a renamed or re-extensioned dump still fails;
3. no file exceeds 4 MiB (largest is 1.6 MB);
4. the `fixtures/` exemption is **one file, by name**, ≤1 MiB and magic-free — not a directory;
5. nothing under `rom/`, `assets/`, `build/`, and no `docs/*.pdf`.

It runs as a suite on every push *and* in the pre-commit hook, and its seven-case self-test proves each check
can fire: a magic under a `.dat` name, a byte-swapped magic, a file whose hash is the cartridge's, an
oversize file, a fixture that has itself acquired a magic, and a second file under `fixtures/` claiming the
exemption.

## 3. The licence: CC0-1.0 for what is ours, and an explicit carve-out for what is not

`LICENSE` carries the CC0-1.0 legal code verbatim (fetched from creativecommons.org, not retyped) behind a
short preamble. The choice follows the N64 decompilation convention — `n64decomp/sm64` and
`n64decomp/banjo-kazooie` are both CC0-1.0 — and it is the honest one here: CC0 **dedicates** the author's own
prose, tooling and fixtures, and makes no claim over Capcom's work.

The preamble and `THIRD_PARTY.md` therefore carve out three things that a repository-wide licence would have
overclaimed:

* **`src/`** — 3 638 Ghidra pseudocode files derived from a Capcom work. Published for study, no warranty, no
  endorsement, removed on request of the rights holder.
* **`fixtures/scd/opcodes.json`** — transcribed from MIT-licensed **OpenBiohazard2** (`fileio/rdt_scd.go`),
  whose copyright line `Copyright (c) 2020 Samuel Yuan` and full MIT text now live in `THIRD_PARTY.md`
  instead of only inside a JSON key.
* **read but not distributed** — `perfect_dark` (nothing ported), `bio2-ds` (not open source), the Nintendo
  PDFs (gitignored).

`README.md` carries a `## Legal and licence` section saying the same in five sentences, because that is the
place a visitor looks.

## 4. The frontpage, and the phase table over 178 milestones

`README.md` was 163 lines describing M0–M7 — its "next action" was still *"place your dump at `rom/re2.z64`"*
(M1) while the project stood at M176. It is replaced by a frontpage that leads with the four things that are
true: no ROM and no affiliation; what the project actually produced, measured; **how to verify it without the
cartridge** (the section this project has that other decompilations do not); and a ten-phase table over all
178 milestones.

The phase table is curated. [`docs/MILESTONES.md`](MILESTONES.md) is not: it is **generated** by
`tools/milestone_index.py` from the log, the 106 notes and a committed gap list, and `--check` fails when it
drifts — including when a table row appears anywhere but at the start of its line, which is the exact shape
of the M106/M107 corruption this milestone repaired. That mattered immediately, because the log is not machine-orderable by eye: 129 rows, M0–M9 ascending,
then **M30→M10 descending**, then M79, then M81→M176; M19 and M23 each appear twice.

The generator keeps duplicates as they are (marked `(i)`/`(ii)`) rather than renaming history, and it names
the **50 milestones that have no record at all** — 31–78, 80, 172 — instead of leaving holes. Four of them
(M48, M51, M78, M172) survive only as commit subjects and are quoted as such. Nothing was reconstructed: a
note written from guesswork would be indistinguishable from one written from measurement, which is the
distinction this whole project trades on.

## 5. What the audit found wrong, and fixed

1. **A corrupted log line.** `docs/reverse_engineering_log.md:172` had two complete table rows — M106 and M107
   — pasted *into the middle of error item 5*, splitting its sentence and duplicating content. 2 224 characters
   removed; no gate could have caught it, because `check_markers.py` checks anchors and headings, not the
   integrity of a cell.
2. **A stale corpus figure.** `docs/handover.md` said **3 292 functions / 61.3 %**; `src/INDEX.md` and
   `ls src/**/*.c` both say **3 638 / 62.3 %** (1 212 984 of 1 947 632 bytes). Fixed, citing `src/INDEX.md`.
3. **A stale provenance figure.** The handover quoted M111's *"1 293 of 81 067"*. The committed artifact
   `manifests/provenance.json` says **3 678 regions / 111 179 operands / 12 005 attributed (10.8 %)**, all in
   the `const` bucket. The artifact is what the tools read, so the handover now quotes it and says why.
4. **Four CI counts.** Three of them had drifted apart from each other; all now come from a run:
   **27 suites / 273 cases**, of which **16 suites / 164 cases** need no cartridge and **11 suites / 109
   cases** report SKIP.
5. **A fifth audit-environment gap.** Both audits of the new tools were vacuous at first — `docs/MILESTONES.md`
   was not copied into the audit's throw-away tree, so the mutated tool "failed" on a missing file. And the
   artefact-scan audits failed for two further wrong reasons before landing: emptying `MAGICS` made the
   self-test crash on an index error, and raising `FILE_MAX` made it try to allocate petabytes. Mutating the
   *comparison* rather than the constant is what made them honest. That is audit-environment failure number
   five in this arc, after `build/elfs`, `src`, `.github/` and the shell interpreter.

## 6. What is still the owner's call

Visibility. The repository is private; everything here is staged for a public flip, and this note deliberately
does not perform one. Before flipping: the CC0 `src/` carve-out is a legal position, not a technical fact, and
`src/` remains derivative work of a Capcom product. `docs/handover.md` carries the reviewer's checklist.

```
python3 tools/acceptance.py            # 27 suites / 273 cases (16 suites / 164 cases without the ROM)
python3 tools/audit_gates.py           # 26/26, 0 vacuous
python3 tools/milestone_index.py --check   # 8/8 — 178 milestones, 50 named gaps
python3 tools/artefact_scan.py         # 5/5 — no cartridge content tracked
python3 tools/check_markers.py         # 20/20
sh tools/ci.sh                         # ci: ok
```
