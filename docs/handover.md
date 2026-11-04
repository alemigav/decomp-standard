# Handover — how to resume this project cold

Written 2026-10-31 at the end of a long session, so that a rebuilt session needs this file and not the
transcript. Everything here is either measured or points at the note that measured it.

## What this project is

Decompilation research on **Resident Evil 2 (N64, `NREE` rev 1 USA)** by the cartridge's owner, under
`~/projects/re2-64-decomp`. The ROM is user-supplied, gitignored, and never modified. The goals are
formats, decompression, executable structure, symbols and documented behaviour — **not** an emulator.
`/Applications/ares.app` (an N64 emulator) is an **optional external validator**, used only to produce
ground-truth RDRAM dumps. Nothing in the repo imports or requires it.

## Verified state, in numbers

| fact | value | note |
|---|---|---|
| cartridge | 67 108 864 B, header entry `0x80000480`, `NREE` rev 1 | `docs/log/M1-*.md` |
| ROM→vram | `vram = rom_offset + 0x7FFFF480` | M7, three independent tests |
| boot bank | ROM `0x1000`–`0x12140`, **69 952 B** | (69 184 was wrong) |
| cart table | vram `0x80012150`: 16-byte header `"OVERLAYTABLENUM"` + count `0x43`; records 1–66; record 67 = build-stamp descriptor; zlib tables from `0x80012590` | M81/M84/M92 |
| zlib members | **4 761**, 8 748 242 → 18 550 424 B; streams start `68 de` (16 KB window) | M9, `unpack_zlib.py` |
| code images | **36** (boot + stage-2 + 34 overlays), **1 947 632 B** | M81 census |
| decompiled corpus | **3 416 functions** over **3 678** ranges, **62.2 %** of the **1 947 632** image bytes inside a known body (**1 211 256 B**); the denominator is *image* bytes, not code — nothing here classifies code independently (M205). The function count **excludes the 174 `switchD_::caseD_` case bodies**, which are code (they are inside the 3 678 ranges and the byte total) but reachable only through their owner's table, and live under `src/<image>/switch/` (M288) | M81–M84, `src/INDEX.md` |
| the remaining image bytes | classified per word in `manifests/byte_map.json` (M207): **407 608 B padding**, **6 640 B** `DAT_`-named data, **964 B** jump tables, **321 820 B (16.5 %) unclassified**; precedence is fixed and its overlaps are counted | M207, `tools/classify_image.py` |
| media | 1 227 MJPEG frames, 271 MPEG-1 blocks (24.4 MB + 15.8 MB), all verified | M10 |
| the 17.6 MB | **identified — the sound family, ids 1979–1983**: id **1979** `0x0338fea`–`0x0b630fe` (8 560 916 B, a **588-record `MORT` bank** whose directory and record header are decoded) and id **1983** `0x0b73fbc`–`0x140ed7c` (9 022 912 B, **1 192 samples tiling it exactly**, order-2 ADPCM behind a 256-byte shared codebook); **17 583 828 B** together, both loaded by `FUN_800759d8` | M178, `tools/file_table.py` |
| file table | **8 091** entries: 113 sentinels, 7 978 real — 4 852 zlib and **3 126 raw (58 273 043 B: the media)**; it is the file system, not a zlib manifest | M178 |
| scripted ares control | GDB RSP over `DebugServer/Port`: 512 KiB in **0.4 s**, `Z0` → `OK`, stop → `S05`; live `0x80000480+0x1234f` is **74 575/74 575 byte-equal to the cartridge** | M108 |
| routine dispatch on `object+5` | **28** stage-2 sites, no mask and no compare; the class-1 table is 14 long, classes 2/3/4 are 4/2/27, and a class-1 writer stores **15** | M173, `tools/routine_index.py` |

`assets/` is gitignored and regenerable in ~20 s. The repo tip is the last documentation commit;
`docs/MILESTONES.md` indexes **all 178 milestones** — generated, and `--check`-gated against the log — and
`docs/reverse_engineering_log.md` carries every milestone one-liner **plus a retraction table** — read the
retraction table before believing any older note. The log's rows are not in file order (M30→M10 descend) and
50 milestone numbers have no row or note at all; the index names them.

## Tools, and how to run them

All plain Python 3 on the system interpreter. **Nothing needs compiling.**

```
python3 tools/n64info.py rom/re2.z64                              # identify the dump
python3 tools/unpack_zlib.py rom/*.z64 --out assets/unpacked      # 4 761 members
python3 tools/extract_blocks.py rom/*.z64                        # media blocks
python3 tools/read_overlay_table.py rom/*.z64                    # the cart table, self-validating
python3 tools/scan_code_members.py rom/*.z64                     # census: which members are code
python3 tools/build_images.py rom/*.z64                          # 36 ELFs into build/elfs/
python3 tools/make_seeds.py --extra build/seeds_extra --extra build/seeds_tables
python3 tools/run_corpus.py baseline|final|report                # the two-phase decompile
python3 tools/export_src.py                                      # build/decomp → src/
python3 tools/verify_corpus.py                                   # 7 checks, 4 hard
python3 tools/test_harness.py                                    # 15-case MIPS fixture (must be 15/15)
python3 tools/vaddr.py 0x80004550                                # resolve an address to its image
python3 tools/find_readers.py 0x80115284 0x80115288              # who touches an address window
python3 tools/find_jump_tables.py                                # recover dispatch targets
python3 tools/find_store_loops.py                                # table-fill initialisers
python3 tools/routine_index.py                                   # the object+5 index bounds (M173)
python3 tools/milestone_index.py --check                          # the index vs the log, notes and gaps
python3 tools/artefact_scan.py                                   # no tracked file is cartridge content
sh tools/ci_full.sh                                              # the full tier: fails if anything skipped
RE2_CART_URL=… sh tools/cart_fetch.sh                            # fetch+verify a cartridge from a URL (M176)
python3 tools/probe.py --reg 4@0x80071ebc --steps 2000000        # harness watch
python3 tools/walk_stream.py rom/*-rdram-20261031-*.bin          # walk a room's command stream
python3 tools/room_probe.py rom/*-rdram-*.bin                    # slot / gate / stream from a dump
python3 tools/acceptance.py                              # every fixture in one verdict (M126)
sh tools/ci.sh                                           # acceptance + hygiene + cartridge sha (M128)
sh tools/pre-commit.sh                                   # what the hook runs; install: ln -sf ../../tools/pre-commit.sh .git/hooks/pre-commit
python3 tools/pad_layout.py --rdram rom/*-rdram-*.bin   # decode an SI command block (M125)
python3 tools/ares_rsp.py launch --rom "rom/….z64"               # drive ares: listener on 9123 (M108)
python3 tools/ares_rsp.py probe                                  # qSupported, PacketSize=4096
python3 tools/ares_rsp.py --quiet dump out.bin                    # 8 MiB RDRAM, no GUI, ~7 s
python3 tools/ares_rsp.py --quiet until 0x80071eb0                # bp + continue, returns the stop + registers
```

## The ares dump workflow — now scripted (`tools/ares_rsp.py`, M108)

`python3 tools/ares_rsp.py launch --rom "rom/…z64"` starts ares with `DebugServer/Enabled`,
`DebugServer/Port=9123`, `DebugServer/UseIPv4` and `Boot/Debugger`; the tool's other subcommands then drive
it over GDB RSP: `probe`, `regs`, `regmap`, `read`, `dump`, `bp`, `until`, `cont`, `raw`. Measured: 512 KiB
in 0.4 s, `Z0` → `OK`, a stop replies `S05` with a 568-byte register block, and live memory is byte-exact
against the cartridge over the ROM-copied region (74 575/74 575).

**One protocol fact that costs an hour if forgotten:** the first byte ares reads on the socket **must be
`+`**, or `nall::TCPText::Server::onData` classifies the client as non-GDB and closes the connection. The
tool does this automatically; `--no-lead-ack` reproduces the M107 negative on demand.

The manual route still works and is still the way to produce a *state* worth keeping: `./run-rom.sh`,
then **Tools → Memory Editor → region `RDRAM` → the `Memory` row → `Export`**. Dumps land in `rom/` named
`<rom>-rdram-<YYYYMMDD-HHMMSS>.bin`, 8 388 608 B each.

Nine dumps exist: two pre-room (title / just after NEW GAME) and seven from rooms — five distinct states
(three of the earlier ones are byte-identical copies of one instant).

**What is still manual:** reaching a room. `Boot/AwaitGDBClient` and `Boot/Debugger` are separate switches
and only the second gates the listener, so ares boots and runs under GDB control — but nothing in the repo
can *play* the game. `--save-state slot(1-9)` + `Paths/Saves` is the untried route to reproducible fixtures
(Route B in `docs/log/M107-ares-control.md`); ares v148 ships no AppleScript dictionary (M107), and its
`Goto` field accepts text without committing (M69).

## The runtime question this session chased, and where it stands

The chain from a room script to the cartridge loader is now mapped end to end:

```
room overlay → BSS command buffer → *(0x800df92c) → context +0x145c → ctx+0x1c (current command)
  → byte 0 = opcode → 141-entry table at 0x80113898 → handler
  opcode 0x44 → FUN_80071e14: byte 9 gate → lbu a0,3(descriptor) = "slot"
  → FUN_8003287c(slot): destination entry (zero ⇒ early return) → byte[slot-16] → cart_record
  → FUN_800327ec: branch 0 (stored==0) / 1 (stored==span, unreachable) / 2 inflate → failures discarded
```

Measured conclusions:

* command lengths are **per opcode**: **141 of 141** table entries advance the pointer themselves, in
  **18 distinct lengths** from 1 to 40 (`0x44` and `0x4d` are the 22-byte family; M136 published 15, and the
  30/38-byte sizes arrived when M141 corrected `0x69`/`0x2d` against the PS1 table — M210). The 18 reported at M99
  counted idiom sites outside the table, including two backward jumps in loop code. Opcodes `0x0f` and `0x12`
  are 2-byte **block** commands: they advance past a `[opcode][span]` header and run the inner block through
  `FUN_8006e1bc`, the block runner that has no table entry of its own (`--lens` prints the whole map);
* **no code writes a context individually**; the ten contexts are driven generically (`s0 += 0x174`);
* the two 48-byte slot maps at `0x800eb204`/`0x800eb234` are **static `.rodata`**, identical in all five
  room dumps, and the entry for the only slots observed (31, 72) is **0 forever**;
* so the observed scene-slot commands are a **recurring no-op**: `cart_record(0)` = the marker, inflate
  fails, the return is discarded, the destination is unchanged;
* the descriptor's **byte 9 gate** passes for every observed command and is vacuous for the one tested.

**Closed in M110** — see "The bank-C question" below. Three rooms (the owner's two door animations, corroborated
by three distinct stream-pointer pairs) all carry byte 3 = 31, so the path is intended behaviour, not an anomaly.

## How "green" is enforced

| place | command | what it covers |
|---|---|---|
| pre-commit hook | `tools/pre-commit.sh` (symlinked into `.git/hooks`) | `tools/acceptance.py`, **~60 s** with the cartridge (measured), blocks the commit |
| local CI | `sh tools/ci.sh` | the same fixtures **plus** a tracked-artefact check, a fixture-size guard and the cartridge sha256 |
| runner CI (GitHub-hosted) | `.github/workflows/acceptance.yml`, job `ci` | the same `ci.sh`: **12 of 23 suites, 135 of 240 cases**; the 11 cartridge suites report SKIP |
| runner CI (self-hosted) | the same file, job `full` | **all 23 suites / 240 cases** — runs where the cartridge is, and fails if the cartridge suites skip |
| runner CI (fetched) | the same file, job `full-url` | **all 23 suites / 240 cases** — downloads the cartridge from a URL you host, verifies it, unpacks it, builds it |

**Two tiers cover the cartridge, and neither stores it on GitHub.** Both run `tools/ci_full.sh`, which fails
rather than passing when the cartridge suites skipped, and both are gated by a repository variable so a push
never sits *queued* while a machine is asleep.

*Self-hosted (`full`)* — the ROM stays on the machine running the runner; nothing is uploaded and no secret is
involved.

```sh
# Settings -> Actions -> Runners -> New self-hosted runner (add the label `re2-cartridge`),
# then point its work directory at a checkout that has rom/*.z64, assets/unpacked and build/elfs
gh variable set SELF_HOSTED_RUNNER --body true     # turn it on; unset it to turn it off
```

*Fetched (`full-url`, M176)* — the secret holds **access, not bytes**: GitHub caps a secret at 48 KB and the
cartridge is 89 478 489 B base64, so about 1 870 secrets would be needed to carry it. Instead the job
downloads it at run time and verifies the SHA-256 against `rom_sha256` in the committed
`manifests/manifest.json` **before** unpacking anything, so a wrong or truncated download fails loudly instead
of looking like a corrupt game.

```sh
gh variable set CARTRIDGE_URL --body true            # turn the fetched tier on
gh secret   set RE2_CART_URL   < url.txt             # where the cartridge lives (http(s):// or file://)
gh secret   set RE2_CART_TOKEN < token.txt           # optional, sent as an Authorization: Bearer header
```

**What CI cannot run is the important part**, and M174 replaced the old guess with a measurement: the
eleven skipped suites are the ones that assert facts about RE2 itself — the corpus checks (`FUN_800327ec`
at `0x800327ec`, the slot map at `0x800eb204`), the script VM, the model container, the T64 texture law, the
exception path and the routine-index bounds (M173). Running them needs the cartridge's **bytes**, which are
cartridge content and never committed. On a runner they print `SKIP (needs the cartridge)`, never PASS, and
each run's job summary lists them. **A green CI run does not vouch for those 742 cases.**

A route to close that gap *in a secret* was built and verified in M130 and then deliberately **not adopted**,
because it means a copyrighted cartridge living in a CI secret store. M175 measured why it also does not work:
GitHub caps a secret at **48 KB** and the cartridge is **67 108 864 B** (**89 478 489 B** as base64), so the
single `RE2_CART_B64` secret that M130's step assumed could never have held it. The self-hosted tier above is
the route that does work, because the bytes never leave the machine that already has them.

What that means in practice: those suites are enforced **wherever the cartridge exists** — locally with
`python3 tools/acceptance.py`, and on every commit through the hook. That is the enforcement that actually
covers them; CI covers the other 135 cases, including a lint of its own workflow file, which needs no ROM.

Documents are checked structurally too: `tools/check_markers.py` requires 16 anchors (12 handover sections
plus the log's retraction table, error list, working method and retractions heading), that **every level-2 heading is registered**, and that **every note in `docs/log/` is indexed by the milestone
table, titled `# M<n>`, and cited by its own row** — the rules that found M79 had no index row at all and that the
M2 row was missing its second note (M132/M133/M134/M135).

Two supporting pieces:

* `fixtures/corpus/` (9 KB, committed) is a **synthetic cartridge** that drives the whole corpus pipeline
  (`--corpus-self-test`, 6/6), so loading, region extraction, the fixpoint and the three checkers run on a
  runner without RE2 (M129);
* `fixtures/decomp/ranges.json` (101 KB) is the distilled function-boundary metadata (36 images, 3 678 ranges,
  `tools/export_ranges.py`, `--check` for drift). It is **load-bearing, not cosmetic**: with the prologue
  heuristic in place of the index, acceptance test 1b fails and revives the M117 artifact
  (`a0 = ret(80001180)` instead of `unk`), so a machine with the ROM but a stale index would report a failure
  that is not real (M130).

`provenance.py` also takes `--rom`, `--manifest` and `--decomp`, so it can be pointed at another cartridge.

## An external reference worth knowing about

`~/projects/perfect_dark` — a shallow clone of `n64decomp/perfect_dark`, suggested by a third-party audit and
assessed in M123/M124. It lives **outside this repo** and nothing was ported. Its transferable value is
`include/PR/` (the real 1998 libultra headers — `OSContPad` there independently confirmed the 4-byte SI response
layout derived in M109/M121, and it is what corrected three claims in M124), `stagetable.txt`/`ld`/`tools/mkrom`
for ROM-assembly conventions, and `docs/piracychecks.md` for the anti-tamper hazard class that does not apply here.
Its `src/` is Rare's engine and its `rarezip`/`inflate` solve Rare's compression — neither applies to Capcom's
stock-zlib banks (M88).

## Rules this project follows (they have all been earned)

1. **Read-only until proven.** The cartridge is immutable; tools print its sha256 before and after.
2. **Every claim gets a note** in `docs/log/` with the command, the output, and what it does *not* establish.
3. **Two independent paths, or it is not established.**
4. **Never compose an address by hand** — `tools/vaddr.py` and `tools/find_readers.py` exist because that
   error class struck seven times. A scanner output becomes a fact only after the instruction is read.
5. **Negative results are results** — record them, with the scan's matching rule.
6. **No ROM bytes, no extracted assets, no binaries in git.** `src/` (pseudocode) *is* tracked.
7. **A scripted edit must fail loudly.** `str.replace` on a drifted anchor returns the input unchanged, so a
   patch can "succeed", write the same bytes back, and land a commit whose message describes a change that is
   not there — this happened three times in one arc, twice in this very file. Every scripted edit now goes
   through `tools/patch_text.py` (exact-count match, atomic across files, verified after write), and a doc
   change is confirmed by grepping for its marker, not by trusting the write.

## The bank-C question: closed, with its scope stated

The chain from a room script to the cartridge loader is mapped (M85–M106) and the outcome is measured, not
inferred: across **three rooms** — the owner's two door animations, corroborated by three distinct
stream-pointer pairs in the dumps — the scene-slot command carries **byte 3 = 31** every time, the two 48-byte
slot maps are immutable `.rodata`, and slot 31's map entry is 0. So `FUN_8003287c(31)` always reaches
`cart_record(0)` (the `OVERLAYTABLENUM` marker), the inflate fails, the return is discarded, and the
destination is untouched. `FUN_800327ec` never checks that return. **That is the design**, and it matches the
finding that bank C has no consumer anywhere: its map pointer `0x800eb268` is constructed in none of the 36
images (M89/M91).

Scope, stated so it cannot be overclaimed later: three rooms were observed, not all rooms. The discriminating
case would be an operand in one of the **13 non-zero map slots** (16, 32–49, 51, 52, 54–56, 58, 59, 62, 63);
none appeared. Proving absence everywhere would need a capture per room, and nothing in the code path gives a
room a reason to vary the operand.

**No more ares dumps, and no more debugger work.** The manual export route is retired because the question it
was meant to answer is closed; the GDB route is parked because ares feeds the game `ff ff ff ff` on every
controller channel (M109) — the game reads no input, so no room can be reached under debug. ares stays what
this project always called it: an optional external validator that nothing depends on.

## Format reference: what is decoded

Everything below is measured and gated; the note in brackets is the argument, not a summary.

**The script VM** (`docs/log/M136-command-length-map.md`, `M141`, `M143`, `M159`)
141-entry opcode→handler table at `0x80113898`, every handler advancing `ctx+0x1c` itself: **18 distinct lengths**,
1–40 B (`re2_scd_length` in `include/re2_formats.h`). 43 opcodes are named from the MIT-licensed PlayStation
table; 17 more carry descriptor names this project inferred (`fixtures/scd/inferred_names.json`, printed with a
leading `~`). `0x44 SceEmSet` is 22 B and **byte 3 is the enemy Id** — the operand M94 measured and M110 tracked
as 31, which the port resolves through a map into a cartridge bank record. `0x0f` is a **block runner** of
4 B, not the 2 the first scan reported. `0x18 GoSub` is 2 B with table **stride 2** (settled structurally), and
`0x19` returns through the slot it saves. `0x0a` and `0x0e` are **blocking**: they leave the pointer untouched
until a counter expires.

**The room population** (`M156`, `M157`)
`DAT_80131fa8` is `256` entries (its index is a byte) mapping a room to a file id: **147 distinct ids**, of which
**50 are scripts** with the u16 record-table layout. The other 97 are other resource kinds — the table is a
scene→resource table, not a script table.

**The model container** (`M157`–`M163`)
`0x0141` is not a magic: it is **format version 321**, and `FUN_800824b8` relocates the block's self-relative
offsets (at `+8`, and for version > 300 at `+12`/`+16` plus a table of `count` ints). A model's texture grid is
`DAT_8010dbe0[type]` → an index into `DAT_801275c0` → `[w][h][tile ids]`, loaded per cell.

**T64 textures** (`M164`–`M167`)
`[0xBE1E][height][width][height·bpp/8][format][palette entries][0][0]`, then `entries` × RGBA5551, then
**raw** pixels — no compression anywhere. `format` 1 is **4 bpp** (two indices per byte, 16-entry palette), 2 is
**8 bpp** (256). `height` is the true height; the second height is `height·bpp/8`. Palettes are **per tile and
never shared** — the registry shares whole tiles by id equality, not palettes.

**The exception path** (`M168`–`M171`)
The handle guard is `break`; the exception vectors through a `jr k0` stub to `0x800006d0`, which reads `Cause`,
posts a fault event, and converges on the dispatch loop at **`0x8000098c`**. That loop contains **no stores and
no COP0 writes**, and there is **no `eret`** and **no EPC write** anywhere in the handler — so a stale handle is a
fatal, unrecoverable stop, and only a hardware reset leaves it.

The rebuild-facing form of all of this is **`include/re2_formats.h`**, with `tools/t64info.c` as its validator.

## How to rebuild

In order, and each step is what the project actually did. The **provisioning** half is recorded outside this repo
(the session's project memory), because it is machine state rather than source; the commands below are the ones
the tree itself provides:

```sh
# 1. provision (once): submodules, npm ci, build:cached, Ghidra 12.2 as the only analysis engine, rea wrapper
REA_ANALYSIS_PROVIDER=ghidra rea doctor            # Hopper is chmod -a-x; `auto` must never select it

# 2. data: the cartridge is the owner's, never fetched
python3 tools/unpack_zlib.py        # ROM -> assets/unpacked (4 761 zlib members + manifest)
python3 tools/build_images.py       # -> build/elfs/*.elf (36 images)

# 3. decompile: cached Ghidra output, then the readable projection
rea decompile_all                   # -> build/decomp/*/decompile-index.json
python3 tools/export_src.py         # -> src/ (per-image C)

# 4. fixtures that the gates need
python3 tools/export_ranges.py      # -> fixtures/decomp/ranges.json (function bounds, 103 792 B)
python3 tools/script_profile.py --json fixtures/scd/profile.json

# 5. gates
python3 tools/acceptance.py         # 73 suites, 1028 cases
sh tools/ci.sh                      # + tracked-artefact scan and cartridge sha256
python3 tools/audit_gates.py        # 146/146: every check must fail when its mechanism is disabled
python3 tools/ratchet.py --check    # the registry may not drift, and src/ may not move, silently
python3 tools/ratchet.py --write    # ...accept the current state (required after any count change)
python3 tools/counts.py --check     # the seven numbers, derived once and asserted in twelve places
```

**A green CI run does not vouch for everything.** Twelve suites are cartridge-gated and report `SKIP`
on a runner: `provenance acceptance`, `synthetic-rdram walk`, `room script`, `script profile`,
`cfg reachability`, `room scripts only`, `01 41 container`, `exception path`, `t64info`,
`routine index bounds`, `file table`, `voice decode`, `rsp interface` and the gate audit — **742 of 1028 cases**. Their enforcement is the
pre-commit hook and a local run, and the CI job summary lists them by name.

## 5b. Who verifies what, and the three edits that cannot happen silently

Verification is not owned by whoever recovers the structure. `tools/ratchet.py` holds the boundary, and its
three invariants are mechanical rather than advisory:

| invariant | what it forbids |
|---|---|
| **match** | `tools/acceptance.py` drifting from `fixtures/gates/ratchet.json` in any direction — a suite added, deleted, raised **or** lowered. Accepting a change is `--write`, which is a diff. |
| **decrease** | `--write` refusing to lower a count or drop a suite without `--allow-decrease`. The ordinary path cannot shrink the suite. |
| **src** | any change to the `src/` tree. A verifier may add cases; it may not edit the decompiled corpus to make them pass. |

This exists because the recurring defect here is not a wrong claim but a **gate that could not fail** — six
audit environments missing a directory, two mutations failing for the wrong reason, M178's 4 852/4 761 read
as a missing class when it was 126 aliased entries. An agent that owns the gates inherits that defect in a
new form, because "make the suite pass" is a one-line edit in three different places. Writing it found a
fourth: `audit_gates.py` graded a mutation as detected when its *output* contained the word `FAIL`, so a
suite that prints `FAIL` lines on purpose was green no matter what (M179).

Consequence for anyone recovering code: lay down new evidence, then run `--write` and let the count change
show in the diff. Do not lower a number to make a run green. If a case is wrong, fix the case and say why
in the milestone note.

The standing brief for whoever runs verification — what it may decide, what it may not, and how a gate is
finished — is **`docs/VERIFICATION.md`**. Its entry point is `python3 tools/verify.py`, which runs the four
procedures above and applies the one rule it may not reinterpret: a result is admissible only if the gate
audit is clean, so a vacuous audit forces `INCONCLUSIVE` rather than `PASS`.

The numbers those documents quote are not maintained by hand any more. `tools/counts.py` derives all seven
from the same `SUITES` list the runner executes and asserts them in twelve places across four files, and a
phrase that disappears counts as a failure — so a stale figure cannot survive, and neither can a deleted
line that used to carry one.

## The script VM has a codename: TYRANT

The reconstructed execution model — the decoder in `tools/scd_vm.py`, its registry and the semantic layer that will
sit above it — is called **TYRANT** in this project's documentation and tooling. It is *this project's* codename,
not a term Capcom or Angel Studios used; nothing in the cartridge names it. The three layers and what each may
claim are in `docs/log/M217-tyrant-is-a-codename-and-what-the-layers-may-claim.md`.

## Immediate next step

The emulator is no longer on the critical path. What is left is cartridge-side, and none of it needs ares:

* **what the sound family still does not settle** — the 17.6 MB is no longer unidentified (M178–M188): id 1979
  is a 588-record `MORT` bank, id 1983 is 1 192 samples tiling it to the byte, and the sample codec is MusyX
  ADPCM behind a **256-byte shared codebook** — the "16-byte prologue" was my reading of the first 16 bytes
  of that book, retracted in M193. **`u16@+4` is assigned**: it is the clip's block count at 160 samples per
  block (M193, refuted by M194's over-budget arithmetic and restored by M197, where 307 038 declared blocks
  parse to the end of all 588 records). The **2.42 %** tail was my own alignment error (M190), not a failure
  set. The **voice codec is transcribed and bit-exact** against the cartridge (M197–M199). What genuinely
  allows three of them to be **named, because the cartridge names them**: `SND_SMPDIR` (the sample
  directory, which indexes class 0 at **1191/1192**), `SND_PROJ` (the project a sequence plays) and
  `SND_POOL` (the container) — so *sample*, *project* and *pool* are its words, not mine. The 16-byte
  class-3 record stays **unnamed**: nothing in the file table, the loader or the handlers labels it, so it
  is described by its fields (rate `+10`, time `+8`, size `+12` ≤ 4096, level `+14`) and its role (the
  record that 142 samples pair with, keyed by key+rate) and no further. The 28-byte sample record's last two
  words are settled: **+20 is a loop start and +24 a loop length in decoded samples** (M203) — the mixer
  compares their **sum** with the play position, the record's length covers start + length + a remainder, and
  187 of 1 192 records name a loop (the other 1 005 carry a literal 2 at +20 and 0 at +24, which the mixer
  never reads). Note-off is what ends a loop: a held voice repeats, a released one plays the remainder out. Remains:
  and **why `SND_PROJ` has 418 song slots for 417 records** (M188). The 28-payload container at `0xb6248`
  has **no owning file-table entry** — it is not a file (M178);
* **experiment B, step 2** — pointer provenance across functions. Step 1 (`tools/provenance.py`) is
  done and 10/10 on its fixture (M111): intra-procedural values over a real CFG, with the
  interprocedural layer fenced off. The committed artifact `manifests/provenance.json` covers
  **3 678 regions / 111 179 memory operands** and records **12 005 attributed (10.8 %)** — all of them
  in the `const` bucket. Earlier notes quote other figures for other runs; the artifact is what the
  tools read, so it is the number quoted here. The residue is what step 2 eats: 21 623 `unk`, 25 467
  in unreached blocks, 26 097 stack offsets, 18 722 parameters, 2 490 loads, 2 431 constant bases.
  Its acceptance tests are fixed in advance: `FUN_800327ec`'s record fields attributed to
  `cart_record()`'s return at `0x80071ec0`, and the bank-C map reader `0x80032a5c` found without
  being told;
* **experiment C** — resource structures: what the 4 761 zlib members are, beyond the 36 code images and the
  verified media;
* `README.md` was rewritten in M177 as a frontpage (what is verified, how to run the gate without the
  ROM, the licence and the legal notice); `src/` holds **3 416 functions** over **3 678** ranges, **62.2 %** of the **1 947 632** image bytes inside a known body (**1 211 256 B**).

Reading any future dump, if one ever appears, is still one command per tool:

```sh
python3 tools/dump_fingerprint.py rom/*-rdram-*.bin    # same room or not — before anything else
python3 tools/room_probe.py rom/<dump>.bin             # slot, gate, branch, stream pointers
python3 tools/walk_stream.py rom/<dump>.bin            # the command stream, opcode by opcode
```
