#!/usr/bin/env python3
"""Audit the gates: disable each check's mechanism and require that the check fails.

Three defects in three milestones (M149's phantom tail, M151's shared node budget, M152/M154's guard order)
had the same shape: a check that could not fail for the right reason. A passing check therefore proves
nothing until it has been shown to fail. This tool does that mechanically.

For each audit it builds a throw-away copy of the tools, fixtures and docs, **mutates one mechanism** in that
copy, runs the same command `acceptance.py` runs, and requires a failure. A check that still passes with its
mechanism disabled is reported as **VACUOUS**, and the tool exits non-zero.

Cartridge-dependent audits get `rom/` and `assets/` **symlinked**, never copied.

  ./audit_gates.py            # run every audit
  ./audit_gates.py --list     # what each audit disables
"""
import argparse
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
CARTRIDGE = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"

AUDITS = [
    # --- walk_stream: the length scan's own mechanisms
    dict(name="walk_stream: cross-register fallback disabled",
         tool="walk_stream.py", args=["--self-test"],
         file="tools/walk_stream.py",
         old="        if length is None:\n            length = cross(h)",
         new="        if False:\n            length = cross(h)"),
    dict(name="walk_stream: advance scan returns a constant (vacuous lengths)",
         tool="walk_stream.py", args=["--self-test"],
         file="tools/walk_stream.py",
         old="    return sorted(out)\n\n\nDYNAMIC = {",
         new="    return [4]\n\n\nDYNAMIC = {"),
    dict(name="walk_stream: name taken from list order instead of the chosen size",
         tool="walk_stream.py", args=["--self-test"],
         file="tools/walk_stream.py",
         # M216: this anchor was the bare `same = [...]` line, which appears twice in the file --
         # `run_audit` replaces only the first occurrence, so half the mutation was never applied
         # and nothing noticed. It now carries the branch it belongs to; `--lint` enforces that.
         old="""            same = [v for v in variants if v[1] == chosen]
            if same:
                name = same[0][0]
        elif not advances:""",
         new="""            same = []
            if same:
                name = same[0][0]
        elif not advances:"""),
    # --- the walk itself
    dict(name="walk_stream: unconditional jump is not followed",
         tool="rdram_fixture.py", args=[],
         file="tools/walk_stream.py",
         old="                if not near_conditional(op, sups):",
         new="                if True:"),
    dict(name="walk_stream: GoSub table stride changed 2 -> 64",
         tool="room_script.py", args=["--check"],
         file="tools/walk_stream.py",
         old='RAW_SCRIPT_TABLE = lambda idx: (struct.unpack_from(">H", blob, 2 * idx)[0]',
         new='RAW_SCRIPT_TABLE = lambda idx: (struct.unpack_from(">H", blob, 64 * idx)[0]'),
    # --- reachability
    dict(name="cfg_reach: block pops are ignored",
         tool="cfg_reach.py", args=["--check"],
         file="tools/cfg_reach.py",
         # disable the mechanism, not one branch of it: with only the plain branch muted the generous
         # branch still fires and the check passes, which is how this audit was itself vacuous at first.
         old="POPPERS = {0x10, 0x12, 0x1A}                  # pop a block slot",
         new="POPPERS = set()                              # pop a block slot"),
    dict(name="cfg_reach: reachability returns nothing",
         tool="cfg_reach.py", args=["--check"],
         file="tools/cfg_reach.py",
         old="    positions = set()\n    for start in starts:",
         new="    return set()\n    for start in starts:"),
    dict(name="cfg_reach: the room-script filter is disabled",
         tool="cfg_reach.py", args=["--check-rooms"],
         file="tools/cfg_reach.py",
         old="    only_ids = room_script_ids() if (args.rooms or args.check_rooms) else None",
         new="    only_ids = None"),
    dict(name="container_0141: the unit size is wrong (32 not 16)",
         tool="container_0141.py", args=["--check"],
         file="tools/container_0141.py",
         old="UNIT = 16",
         new="UNIT = 32"),
    dict(name="container_0141: N forced equal to the distinct-value count",
         tool="container_0141.py", args=["--check"],
         file="tools/container_0141.py",
         old="        pairs.append((n, len(set(payload))))",
         new="        pairs.append((n, n))"),
    dict(name="container_0141: the GBI opcode window is widened to everything",
         tool="container_0141.py", args=["--check"],
         file="tools/container_0141.py",
         old="    gbi = sum(c for b, c in heads.items() if 0xE4 <= b <= 0xFF)",
         new="    gbi = sum(c for b, c in heads.items())"),
    dict(name="container_0141: the ITP loader table is swapped for the TM3 one",
         tool="container_0141.py", args=["--check"],
         file="tools/container_0141.py",
         old='    "ITP": 0x8012BEC0,',
         new='    "ITP": 0x8010DBC0,'),
    # --- the corpus profiler
    dict(name="script_profile: the script heuristic admits nothing",
         tool="script_profile.py", args=["--check"],
         file="tools/script_profile.py",
         old="MIN_COMMANDS = 4",
         new="MIN_COMMANDS = 10**9"),
    # --- the doc gates
    dict(name="check_markers: a handover heading disappears",
         tool="check_markers.py", args=[],
         file="docs/handover.md",
         old="## Immediate next step",
         new="## Immediate next step (renamed by the audit)"),
    # --- the routine-index bounds question: one audit per leg of its answer, so that no single
    # disabled mechanism can leave the answer standing.
    dict(name="routine_index: a table base shifted by one word",
         tool="routine_index.py", args=[],
         file="tools/routine_index.py",
         old="CLASS_A = [0x8011AF80,",
         new="CLASS_A = [0x8011AF84,"),
    dict(name="routine_index: every +5 index counted as masked",
         tool="routine_index.py", args=[],
         file="tools/routine_index.py",
         old='                       and ((b["w"] >> 6) & 0x1F) == 2)        # sll reg,reg,2',
         new='                       and ((b["w"] >> 6) & 0x1F) == 3)        # sll reg,reg,2'),
    dict(name="routine_index: the out-of-range writer values are dropped",
         tool="routine_index.py", args=[],
         file="tools/routine_index.py",
         old="                out.append((v, p.name, expr))",
         new="                out.append((v, p.name, expr)) if v < ROW else None"),
    dict(name="workflow_lint: the broken-plain-scalar check never fires",
         tool="workflow_lint.py", args=[],
         file="tools/workflow_lint.py",
         old='    if ": " in val:',
         new="    if False:"),
    dict(name="patch_text: an edit drops the file mode",
         tool="patch_text.py", args=["--self-test"],
         file="tools/patch_text.py",
         old="        shutil.copymode(path, tmp)",
         new="        pass"),
    # --- the artefact scan: the two ways a content guard silently stops guarding
    # Mutate the *comparison*, not the constant: emptying `MAGICS` makes the self-test crash on an
    # index error, and raising `FILE_MAX` makes it try to allocate petabytes — both "fail", neither for
    # the reason under audit. That was this audit's second attempt; the first was vacuous.
    dict(name="artefact_scan: the cartridge magics are never compared",
         tool="artefact_scan.py", args=["--self-test"],
         file="tools/artefact_scan.py",
         old="        if head in MAGICS:",
         new="        if False:"),
    dict(name="artefact_scan: the size ceiling is never applied",
         tool="artefact_scan.py", args=["--self-test"],
         file="tools/artefact_scan.py",
         old="        if size > FILE_MAX:",
         new="        if False:"),
    # --- the milestone index: the two ways it could stop following the record
    dict(name="milestone_index: note titles ignored (the index stops following the notes)",
         tool="milestone_index.py", args=["--check"],
         file="tools/milestone_index.py",
         old="            note = note_for(num, row)",
         new="            note = None"),
    dict(name="milestone_index: the gap list is ignored",
         tool="milestone_index.py", args=["--check"],
         file="tools/milestone_index.py",
         old="    gaps = load_gaps(root) if gaps is None else gaps\n    rows = parse_log(log_text)",
         new="    gaps = [] if gaps is None else gaps\n    rows = parse_log(log_text)"),
    # --- the commit-subject gate (M183). Two-sided, and each leg is aimed at its own comparison: the
    # accounting leg is graded by a synthetic bed (a real record has nothing unaccounted, so disabling the
    # comparison there would be invisible), the freshness leg by a bed whose fixture is deliberately stale.
    dict(name="milestone_index: a commit subject with no record is accepted",
         tool="milestone_index.py", args=["--self-test"],
         file="tools/milestone_index.py",
         old="                  not unaccounted_commits,",
         new="                  True,"),
    dict(name="milestone_index: a stale commit fixture is accepted",
         tool="milestone_index.py", args=["--self-test"],
         file="tools/milestone_index.py",
         old="    fresh = fixture.exists() and bool(committed) and highest - top <= CYCLE",
         new="    fresh = True"),
    # --- the full CI tier: one mutation per leg, so neither the skip guard nor the digest check can rot
    dict(name="ci_full: the skip guard never fires",
         tool="ci_full.sh", args=["--self-test"], interp="sh",
         file="tools/ci_full.sh",
         old="	if grep -q 'skipped for want of the cartridge' \"$log\"; then\n\t\treturn 1",
         new="	if false; then\n\t\treturn 1"),
    dict(name="cart_fetch: the digest comparison always passes",
         tool="cart_fetch.sh", args=["--self-test"], interp="sh",
         file="tools/cart_fetch.sh",
         old="\t[ \"$(sha_of \"$1\")\" = \"$2\" ]",
         new="\ttrue"),
    dict(name="patch_text: a no-op replacement is accepted",
         tool="patch_text.py", args=["--self-test"],
         file="tools/patch_text.py",
         old="        if old == new:",
         new="        if False:"),
    # --- the file table (M178): one mutation per leg, including the exact bug this tool had on its
    # first run — the entry offsets are relative to the table base, and slicing the cartridge with one
    # double-counts it. That mutation reads a plausible file out of the wrong place and still looks sane.
    dict(name="file_table: the directory is read one word early (the count taken as an offset)",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old='    vals = struct.unpack_from(">" + str(count) + "I", r4, 4)',
         new='    vals = struct.unpack_from(">" + str(count) + "I", r4, 0)'),
    dict(name="file_table: no offset is ever seen without the top byte",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old='    noflag = {k for k, v in enumerate(vals) if v >> 24 == 0}',
         new='    noflag = set()'),
    dict(name="file_table: every entry counted as a walked member",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old='    named = {BASE + o for _, o, _ in zl}',
         new='    named = {BASE + o for _, o, _ in real}'),
    dict(name="file_table: id 1983 sliced with the relative offset",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old='    r3 = d[OTHER_CART:OTHER_CART + OTHER_SIZE]',
         new='    r3 = d[OTHER_REL:OTHER_REL + OTHER_SIZE]'),
    # --- the ratchet (M179): one mutation per invariant, plus the "make it disappear" route. Each is
    # aimed at the comparison, and each is caught by `--self-test` rather than `--check`, because on a
    # healthy repository `--check` passes whether or not these comparisons are wired at all — which is
    # the whole reason the self-test exists.
    dict(name="ratchet: a lowered expected count is accepted",
         tool="ratchet.py", args=["--self-test"],
         file="tools/ratchet.py",
         old="    lowered = sorted(n for n in was if n in now and now[n] < was[n])",
         new="    lowered = []"),
    dict(name="ratchet: a deleted suite is not noticed",
         tool="ratchet.py", args=["--self-test"],
         file="tools/ratchet.py",
         old="    deleted = sorted(set(was) - set(now))",
         new="    deleted = []"),
    dict(name="ratchet: registry drift (a raised count) is accepted without --write",
         tool="ratchet.py", args=["--self-test"],
         file="tools/ratchet.py",
         old='("the registry matches the baseline (any change needs --write)", not drift,',
         new='("the registry matches the baseline (any change needs --write)", True,'),
    dict(name="ratchet: --write lowers a count without --allow-decrease",
         tool="ratchet.py", args=["--self-test"],
         file="tools/ratchet.py",
         old="        if (lowered or deleted) and not allow_decrease:",
         new="        if False:"),
    # --- the M179 claim classes. A *code reading* is gated by pinning the expressions that make it a
    # reading, so the audit aims at the needle: with a needle that is not in the source, a wired case fails
    # and a vacuous one still passes — which is exactly the discrimination the audit is for. The measured
    # band is aimed at from the inside, by narrowing it until real records violate it.
    dict(name="file_table: the rate-byte reading looks for an expression that is not there",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old='and "param_2 = 16000" in f3704 and "param_2 = 8000;" in f3704',
         new='and "param_2 = 32000" in f3704 and "param_2 = 8000;" in f3704'),
    dict(name="file_table: the +4 band is narrowed until real records violate it",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old="all(0.03 < field[k] / pay[k] < 0.115 for k in range(n))",
         new="all(0.05 < field[k] / pay[k] < 0.115 for k in range(n))"),
    # --- the M195 bit-stream walk (M196). It used to be the suite's most expensive case and the only one
    # with no audit entry, which is the wrong way round. The mutation removes the block's 260-bit body,
    # which is the mechanism the case turns on: the cursor then stops at the header, nothing ever overruns,
    # and both pinned verdicts move from 362/588 and 339/588 to 0. Aiming at `lim` instead would be
    # vacuous — no clip is over 512 KiB, so the guard never binds and removing it changes nothing.
    dict(name="file_table: a normal block consumes no sample bits",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old="                p += SAMPLE_BITS * m",
         new="                p += 0"),
    # --- the pool (M196). One mutation per lie a scheduler can tell: a result that never reaches the
    # report, a report assembled in completion order, and a failing suite that is judged a pass. Each is
    # aimed at the acceptance self-test, which is the only thing that looks at the pool rather than through
    # it -- `--check` on a healthy tree passes whether or not any of this is wired.
    dict(name="acceptance: a worker's result never reaches the report",
         tool="acceptance.py", args=["--self-test"],
         file="tools/acceptance.py",
         old="            lines.append(line)",
         new="            pass"),
    dict(name="acceptance: the report is assembled in completion order, not registry order",
         tool="acceptance.py", args=["--self-test"],
         file="tools/acceptance.py",
         old="    return lines, failures, skipped, deferred, verbose",
         new="    return lines[::-1], failures, skipped, deferred, verbose"),
    dict(name="acceptance: a suite is a pass regardless of its exit status or tally",
         tool="acceptance.py", args=["--self-test"],
         file="tools/acceptance.py",
         old="    ok = code == 0 and passed == total and total == expected",
         new="    ok = True"),
    # --- the M200 class mapping. The tag is `(key >> 14) & 3`; widening the mask mixes the sections
    # and the data case must fail. The second mutation drops the length argument from the resolver's
    # reading, which is the only thing distinguishing cache C.
    dict(name="file_table: the pool class tag is not masked to two bits",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old="    _tag = lambda k: (k >> 14) & 3",
         new="    _tag = lambda k: 0"),
    dict(name="file_table: the resolver's length-bearing dispatch is no longer read",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='(int)piVar5 + 10" in _res',
         new='(int)piVar5 + 99" in _res'),
    dict(name="file_table: the class-3 parameters are read big-endian",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    _sw = lambda v: ((v & 0xFF) << 8) | (v >> 8)',
         new='    _sw = lambda v: v'),
    dict(name="file_table: the +12 parameter is read big-endian",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    _p12 = Counter(_sw(struct.unpack_from(">H", pool, _r + 12)[0]) for _r in _recs16)',
         new='    _p12 = Counter(struct.unpack_from(">H", pool, _r + 12)[0] for _r in _recs16)'),
    # M219 re-aimed both of these: the old anchors asserted the pre-correction numbers (290 / 2027) and were
    # retired with them. The list-5 mutation now claims the row array *is* a key list; the list-2 mutation lets
    # the sample space lose a key.
    dict(name="file_table: list[5] is read as a key list again",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old="                  len(_k5) == 4 and len(_s5) == 4))",
         new="                  len(_k5) == 4 and len(_s5) == 3533))"),
    dict(name="file_table: cache C's rate argument is no longer read",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='                  "FUN_800ace1c(*psVar6,piVar5+3,*(undefined2*)((int)piVar5+10));" in _resn))',
         new='                  "FUN_800ace1c(*psVar6,piVar5+3,*(undefined2*)((int)piVar5+99));" in _resn))'),
    dict(name="file_table: list[2] is allowed to lose a key of the sample space",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old="                  len(_s2b) == 2026 and min(_s2b) == 1 and max(_s2b) == 2026 and _dkeys <= _s2b))",
         new="                  len(_s2b) == 2025 and min(_s2b) == 1 and max(_s2b) == 2026 and _dkeys <= _s2b))"),
    dict(name="file_table: list[2]'s handler is not checked for cache tables",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='                  not any(g in _h2 for g in ("8014e1d0", "801521e0", "801529f0"))))',
         new='                  any(g in _h2 for g in ("8014e1d0", "801521e0", "801529f0"))))'),
    # --- the M203 loop fields. One mutation per falsification the case turns on: the loop word ignored
    # (so no record is looped), the length read as 16 bits (so four loop regions no longer fit), the
    # start/end comparison inverted, the loop word truncated to 16 bits, and the decoded frame read as 32
    # samples instead of 64. Aiming at the prose instead would be vacuous — the case asserts numbers.
    dict(name="file_table: the loop word at +24 is ignored",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    _w24 = lambda r: struct.unpack_from(">I", r, 24)[0]',
         new='    _w24 = lambda r: 1'),
    dict(name="file_table: the declared length is read as 16 bits",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    _wlen = lambda r: struct.unpack_from(">I", r, 16)[0] & 0xFFFFFF',
         new='    _wlen = lambda r: struct.unpack_from(">I", r, 16)[0] & 0xFFFF'),
    dict(name="file_table: the start/end comparison is inverted",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='                  sum(1 for _k, a, b, l in loops if a < b) == 123))',
         new='                  sum(1 for _k, a, b, l in loops if a > b) == 123))'),
    dict(name="file_table: the loop length is truncated to its low 16 bits",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    loop_len = [_w24(r) for r in srec[:n_smp]]',
         new='    loop_len = [struct.unpack_from(">H", r, 26)[0] for r in srec[:n_smp]]'),
    dict(name="file_table: a decoded frame is taken as 32 samples, not 64",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    stream_len = [((len(smp) - 256) // 40) * 64 for smp in smp_blobs]',
         new='    stream_len = [((len(smp) - 256) // 40) * 32 for smp in smp_blobs]'),
    dict(name="file_table: the reader's +0x14 load is no longer read",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='"param_2[4] = *(undefined4 *)(iVar1 + 0x14);" in s_dir',
         new='"param_2[4] = *(undefined4 *)(iVar1 + 0x15);" in s_dir'),
    dict(name="file_table: the remainder arithmetic is read as length - (start - length)",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='"uVar3 = *(int *)(iVar1 + 0x30) - (*(int *)(iVar1 + 0x34) + *(int *)(iVar1 + 0x38));"',
         new='"uVar3 = *(int *)(iVar1 + 0x30) - (*(int *)(iVar1 + 0x34) - *(int *)(iVar1 + 0x38));"'),
    dict(name="file_table: the mixer's post-wrap segment is no longer read",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='and "local_40 = (*(int *)(param_1 + 0x34) - local_48) + *(int *)(param_1 + 0x38);" in s_mix',
         new='and "local_40 = (*(int *)(param_1 + 0x38) - local_48) + *(int *)(param_1 + 0x34);" in s_mix'),
    dict(name="file_table: the note-off no longer clears the per-voice flag byte",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='"_DAT_80143f0c + 1) = 0;" in s_off',
         new='"_DAT_80143f0c + 2) = 0;" in s_off'),
    # --- M210: the hook certificate. The mutation inverts the hash comparison, which must break the
    # "a matching certificate validates" case -- otherwise the hook would skip the suite for any tree.
    dict(name="hook_cert: the worktree hash comparison is inverted",
         tool="hook_cert.py", args=["--self-test"], file="tools/hook_cert.py",
         old='    if cert.get("worktree") != want_hash:', new='    if cert.get("worktree") == want_hash:'),
    # --- M210: the scheduler contract, pinned by source shape after M152 left it ungated. The mutation
    # changes the needle, so the case must report that the loop is not the one it claims.
    dict(name="cfg_reach: the scheduler's return convention is no longer read",
         tool="cfg_reach.py", args=["--check"], file="tools/cfg_reach.py",
         old='    return ("} while (iVar1 == 1);" in s', new='    return ("} while (iVar1 == 2);" in s'),
    # --- M210: the image inventory that had no producer. Mutating the committed fixture (not the tool) is
    # the honest target: the case compares the fixture with a fresh distillation, so a hand-edited extent --
    # the drift the missing generator allowed for a milestone -- must fail it.
    dict(name="image inventory: a committed extent is edited by hand",
         tool="export_ranges.py", args=["--check-images"], file="fixtures/decomp/images.json",
         old='"size": 69952', new='"size": 69960'),
    dict(name="handler_region: the extent queue drops one correction",
         tool="handler_region.py", args=["--check"], file="manifests/extent_corrections.json",
         old='"entry": "0x8006da14",', new='"entry": "0x8006da18",'),
    # --- WP3: the whole-bank sweep. One mutation at the recorded evidence (a clip's PCM hash) and one at the
    # block arithmetic, because those are the two things the gate turns on.
    dict(name="voice_sweep: one clip's recorded PCM hash is wrong",
         tool="voice_sweep.py", args=["--check"], file="fixtures/sound/mort_sweep.json",
         # anchored on clip 0's own hash line, because `"pcm_sha256"` appears 588 times
         old='"pcm_sha256": "0a9d82150d63ba49214f8', new='"pcm_sha256": "ff9d82150d63ba49214f8'),
    dict(name="voice_sweep: the silent-block count no longer closes",
         tool="voice_sweep.py", args=["--check"], file="fixtures/sound/mort_sweep.json",
         old='"blocks_silent": 44144', new='"blocks_silent": 44143'),
    # --- WP2: the four opcodes. The claim is that the opcode IS the key's class tag and that the dispatcher
    # reads the top two bits, so both mutations attack that reading rather than the numbers.
    dict(name="snd_macros: the opcode mask is widened past the top two bits",
         tool="snd_macros.py", args=["--check"], file="tools/snd_macros.py",
         # `& 7` instead of `& 3` is vacuous on this data (bits 12-13 are always zero), and moving the shift
         # makes the tool hang rather than fail. This mutation relabels the opcodes instead: the counts stay
         # right and the labels move, which is exactly what a naming gate must catch.
         old="    1: \"0x4000\",", new="    1: \"0x8000\","),
    dict(name="file_table: a pool section's first record is skipped again",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old="        recs, termpos, ok = _chain(pool, st, end)",
         new="        recs, termpos, ok = _chain(pool, st + struct.unpack_from(\">I\", pool, st)[0], end)"),
    # --- WP1: the sound project. Two claims worth attacking: the record-array width (12, not a key width) and
    # the negative answer on command streams, which is what sends the macro search to the pool.
    # Aimed at the tool, not the artefact: editing the committed JSON only trips the staleness case (and an
    # extra key it does not read is not even that), which is how the first attempt came out VACUOUS. This
    # mutation changes the derivation, so the row array really is read as u16 keys.
    dict(name="snd_proj: the row array is derived as u16 keys",
         tool="snd_proj.py", args=["--check"], file="tools/snd_proj.py",
         old='        return {"width": 12, "count": count, "pad": pad, "closed": pos + 4 + 12 * count == end,',
         new='        return {"width": 2, "count": count, "pad": pad, "closed": pos + 4 + 12 * count == end,'),
    dict(name="snd_proj: a command stream is claimed where there is none",
         tool="snd_proj.py", args=["--check"], file="manifests/snd_proj.json",
         old='"command_streams": 0', new='"command_streams": 1'),
    # --- M214: the population partition. Two claims: the room-table category is exactly the rooms' file ids,
    # and the "not a script" bucket is not a dumping ground.
    dict(name="script_population: one room-table entry is not a room's file id",
         tool="script_population.py", args=["--check"], file="manifests/script_population.json",
         old='"room_table": 50,', new='"room_table": 49,'),
    dict(name="script_population: a not-a-script entry is promoted to a heuristic candidate",
         tool="script_population.py", args=["--check"], file="manifests/script_population.json",
         # re-aimed in M226: resolving 0x36 moved one candidate out of this category (514 -> 513), so the
         # anchor moved with it rather than being left pointing at a number the artefact no longer carries
         old='"not_a_script": 513,', new='"not_a_script": 512,'),
    # --- Cycle E step 1: the RSP decoder. Aimed at the two constants the whole artefact turns on: the IMEM
    # address rule and the boundary between the ucode and the CPU code that follows it.
    dict(name="rsp_decode: the jump target is masked to 11 bits instead of IMEM's 12",
         tool="rsp_decode.py", args=["--check"], file="tools/rsp_decode.py",
         old="    return raw, raw & 0xFFF", new="    return raw, raw & 0x7FF"),
    # --- M225: naming the vector unit. Two anchors, each aimed at an outcome: the row/offset split that
    # replaced M223's 16-bit displacement, and the access size that scales a transfer's address.
    # There is deliberately **no** anchor for the `vt_elem`/`vd_elem` lane rule, and the reason is arithmetic:
    # every one of this program's eight single-lane words carries `vt_elem = 12`, so `msb = 3` and the rule
    # reduces to `(((vd_elem >> 3) << 3) | (vt_elem & 7)) & 7`, in which the last `& 7` masks away every bit
    # the borrow could contribute. Neither half of the ternary can change an answer here -- M232 tried both
    # and the positive control reported both VACUOUS. The rule stays implemented from the cited page and the
    # case publishes that it is exercised by zero words.
    dict(name="rsp_decode: a vector transfer's offset is read as a 16-bit displacement again",
         tool="rsp_decode.py", args=["--check"], file="tools/rsp_decode.py",
         old="                                    bits(word, 10, 7), bits(word, 6, 0))",
         new="                                    bits(word, 10, 7), sx16(word & 0xFFFF))"),
    dict(name="rsp_decode: a transfer row loses its access size, so the address stops being scaled",
         tool="rsp_decode.py", args=["--check"], file="tools/rsp_decode.py",
         old='    0x00: ("lbv", "sbv", 1), 0x01: ("lsv", "ssv", 2), 0x02: ("llv", "slv", 4),',
         new='    0x00: ("lbv", "sbv", 1), 0x01: ("lsv", "ssv", 1), 0x02: ("llv", "slv", 4),'),
    dict(name="rsp_decode: the ucode/CPU boundary moves four bytes",
         tool="rsp_decode.py", args=["--check"], file="manifests/rsp_ucode.json",
         old='"addr": "0x800b2700",', new='"addr": "0x800b2704",'),
    # --- M222: the voice descriptor. Aimed at the tool's constants rather than the artefact's strings,
    # because the artefact's field lines are multi-line JSON and an anchor spanning them is fragile: both of
    # my first attempts failed to match, and the lint caught it. Moving the slot stride and the ring size
    # changes what every derived offset means, and the derivation comparison names it.
    dict(name="voice_descriptor: the slot stride is off by four",
         tool="voice_descriptor.py", args=["--check"], file="tools/voice_descriptor.py",
         old="SLOT_BASE, SLOT_STRIDE, SLOT_COUNT, SLOT_END = 0x80158B20, 0x1228, 2, 0x8015AF70",
         new="SLOT_BASE, SLOT_STRIDE, SLOT_COUNT, SLOT_END = 0x80158B20, 0x122C, 2, 0x8015AF70"),
    dict(name="voice_descriptor: the DMA ring is a chunk short",
         tool="voice_descriptor.py", args=["--check"], file="tools/voice_descriptor.py",
         old="RING_OFF, RING_SIZE, CHUNK, FETCH_MASK, READ_MASK = 0x1A0, 0x1000, 0x400, 0xFF8, 0xFFC",
         new="RING_OFF, RING_SIZE, CHUNK, FETCH_MASK, READ_MASK = 0x1A0, 0x0FFC, 0x400, 0xFF8, 0xFFC"),
    # --- M221b: the fixture-only validator. Its whole point is catching a hand-edited artefact without the
    # cartridge, so both mutations are exactly that: a clipped hash and a block ledger that stops closing.
    dict(name="sound_fixtures: a clip hash is clipped by one character",
         tool="sound_fixtures.py", args=["--check"], file="fixtures/sound/mort_sweep.json",
         old='"pcm_sha256": "0a9d82150d63ba49214f8', new='"pcm_sha256": "0a9d82150d63ba49214f'),
    dict(name="sound_fixtures: the block ledger stops closing",
         tool="sound_fixtures.py", args=["--check"], file="fixtures/sound/mort_sweep.json",
         old='"blocks_silent": 44144', new='"blocks_silent": 44145'),
    # --- M213b: the refusal work list. The claim is that every refusal is classified and every one lands in a
    # work item, so both mutations attack that link rather than the numbers.
    dict(name="vm_refusals: one refusal is filed under a kind with no work item",
         tool="vm_refusals.py", args=["--check"], file="manifests/vm_refusals.json",
         old='"room": 56,\n   "file_id": 1931,\n   "kind": "record_start_not_code"',
         new='"room": 56,\n   "file_id": 1931,\n   "kind": "record_start_not_codes"'),
    dict(name="vm_refusals: the refused total no longer matches the rows",
         tool="vm_refusals.py", args=["--check"], file="manifests/vm_refusals.json",
         old='"refused": 57,', new='"refused": 56,'),
    # --- M213: the decoder. The mutation that matters is the one the milestone forbids: a byte the table
    # does not know must raise, never be skipped as one byte.
    # M226 re-aimed this: it used to attack the `unresolved` raise for 0x36, and once 0x36 became a constant
    # advance *no opcode is unresolved any more*, so the mutation had nothing to act on and the audit reported
    # it vacuous -- which is exactly what the audit is for. The property it was protecting is unchanged and
    # still load-bearing, so it is aimed at the raise that still exists: an opcode that is not in the
    # 141-entry table at all.
    # The mutation has to fail *with a message*, not crash: removing the raise alone makes the next line index
    # a None and raises TypeError, which the audit would count as a failure while proving nothing about the
    # refusal. Silently substituting Nop makes the fixture case fail on its own terms instead.
    # Both "remove the raise" and "substitute Nop" make the next line crash, and a mutation that raises proves
    # only that the code is fragile. Conflating the *kind* is the mutation that fails cleanly: the refusal still
    # happens, under the wrong name, and the fixture case says so.
    dict(name="scd_vm: an unknown opcode is refused as a truncated instruction",
         tool="scd_vm.py", args=["--check"], file="tools/scd_vm.py",
         old="        raise UnknownOpcode(pc, op)",
         new="        raise TruncatedInstruction(pc, op, 1)"),
    # --- M212: the handler-region artefact. The two claims worth attacking are the region-entry walk (which
    # turns "79 handlers outside the corpus" into "21 prologues, all known") and its corpus test.
    # These two mutate the *artefact*, because mutating the tool only trips the "committed file equals a
    # fresh derivation" case -- which proves the file is stale, not that the region-entry claim is load-bearing.
    dict(name="handler_region: one fragment loses the frame setup behind it",
         tool="handler_region.py", args=["--check"], file="manifests/handler_region.json",
         old='"region_entry": "0x8006ecc0",', new='"region_entry": null,'),
    dict(name="handler_region: one fragment's frame setup is claimed to be outside the corpus",
         tool="handler_region.py", args=["--check"], file="manifests/handler_region.json",
         # anchored on a prologue used by exactly one fragment, so flipping it removes that prologue from the
         # "already a function start" set and the claim fails; flipping a shared one would change nothing.
         old='"region_entry": "0x8006ebec",', new='"region_entry_in_corpus_false_marker": "0x8006ebec",'),
    # --- M230: the index provenance. Three anchors: the chase that turns a "local" into a command
    # field, the ctx test ordered after the def lookup (the bug that mis-called 0x36 an argument), and
    # the width table that makes a byte and a halfword distinguishable.
    dict(name="head_index: a load's base is not chased, so every pointer read becomes local",
         tool="head_index.py", args=["--check"], file="tools/head_index.py",
         old="            origin = _base_origin(image, rs, va, table, ctxs, 0)",
         new="            origin = None"),
    dict(name="head_index: the ctx test runs before the def lookup, so a redefined a0 reads as the "
         "context pointer",
         tool="head_index.py", args=["--check"], file="tools/head_index.py",
         old="        if cur in ctxs and not earlier:",
         new="        if cur in ctxs:"),
    # aimed at the *guard*, not the width table: dropping the entry alone raises KeyError, and a mutation that
    # crashes proves only that the code is fragile (M226's lesson, met again here)
    dict(name="head_index: lh leaves the load set, so halfword reads go unhandled",
         tool="head_index.py", args=["--check"], file="tools/head_index.py",
         old="        if op in (0x20, 0x21, 0x23, 0x24, 0x25):               # lb/lh/lw/lbu/lhu",
         new="        if op in (0x20, 0x23, 0x24, 0x25):                     # lb/lh/lw/lbu/lhu"),
    # --- M231: the fold's five widenings. The three anchors above were written for M230's *narrow* fold and
    # still passed after M231 widened it, because widening happens underneath them: a head that used to be
    # `local` simply moved to `global`, and each mutation kept failing for its original reason. Every anchor
    # below closes one widening M231 added, so if one is removed the count that widening explains must fall.
    dict(name="head_index: a bare `lui` is not a complete base, so a global built in two instructions is "
         "refused",
         tool="head_index.py", args=["--check"], file="tools/head_index.py",
         old='    if op == 0x0F:                                     # lui: a constant, possibly completed later\n'
             '        return {"kind": "const", "value": (w & 0xFFFF) << 16}',
         new='    if op == 0x0F:                                     # lui: a constant, possibly completed later\n'
             '        return None'),
    dict(name="head_index: the fold does not add two constants, so a `lui`+`lui`+`addu` base is refused",
         tool="head_index.py", args=["--check"], file="tools/head_index.py",
         old='        if a and b and a["kind"] == "const" and b["kind"] == "const":\n'
             '            return {"kind": "const", "value": (a["value"] + b["value"]) & 0xFFFFFFFF}',
         new='        if a and b and a["kind"] == "const" and b["kind"] == "const":\n'
             '            return None'),
    # There is deliberately **no** anchor for `addu rd,rs,zero` move propagation. M231 claimed six heads came
    # from it; M232 instrumented the branch and it is taken zero times by all 86 heads, so it was dead code
    # and has been deleted. A guard over a branch that no input reaches can only ever be vacuous -- the two
    # rounds it took to learn that (a mutation on the commuted half, then on the real half, both no-ops) are
    # the reason the positive control now exists: it said VACUOUS instead of PASS on the first try.
    dict(name="head_index: the chase depth goes back to 3, so a four-link chain is refused",
         tool="head_index.py", args=["--check"], file="tools/head_index.py",
         old="    if depth > 6:\n        return None",
         new="    if depth > 3:\n        return None"),
    dict(name="head_index: `sp` is not named as a stack base, so a frame slot is refused",
         tool="head_index.py", args=["--check"], file="tools/head_index.py",
         old='    if reg == SP:\n        return {"kind": "stack", "register": "sp"}\n'
             "    earlier = [v for v in table.get(reg, []) if v < at]",
         new="    earlier = [v for v in table.get(reg, []) if v < at]"),
    # --- M233: the sound-command census. Three anchors, each closing one step of the dataflow the six
    # operand layouts rest on: the context pointer copied into a callee-saved register (`s1 = a0`), the
    # invalidation that stops an alias at the instruction which rewrites it (0x83 rebuilds v0 as 0x800df6b0
    # and then reads 0x1c7e(v0)), and the advance read off the store rather than off the registry.
    dict(name="sound_ops: the context pointer is not followed through a move, so no command pointer is found",
         tool="sound_ops.py", args=["--check"], file="tools/sound_ops.py",
         old='                special = "ctxmove"\n                ctx.add(rdx)',
         new='                special = None\n                ctx.add(rdx)'),
    # the invalidation anchor was twice a no-op here, so this one closes the load set instead: `lhu` is the
    # halfword form 0x59's `u16` operand and 0x85's region mask are both read with, and dropping it loses two
    # operand layouts at once. (The invalidation itself cannot be isolated: the advance branch discards the
    # register on its own, so disarming the general rule leaves 0x83's rebuilt base invisible anyway.)
    dict(name="sound_ops: lhu leaves the load set, so a halfword operand disappears",
         tool="sound_ops.py", args=["--check"], file="tools/sound_ops.py",
         old='LOAD = {0x20: "lb", 0x21: "lh", 0x23: "lw", 0x24: "lbu", 0x25: "lhu"}',
         new='LOAD = {0x20: "lb", 0x21: "lh", 0x23: "lw", 0x24: "lbu"}'),
    dict(name="sound_ops: the advance is taken from the registry instead of from the store",
         tool="sound_ops.py", args=["--check"], file="tools/sound_ops.py",
         old="                    advance = sx16(wb & 0xFFFF)",
         new="                    advance = None"),
    # --- M234: the asset-family census. Three anchors, each a mechanism the two script ranges rest on: the
    # count rule (the table's first entry *is* its size, so `end/2` is the count and `end/2 - 1` reads the
    # same table one entry short -- the error this file made first), the first-entry invariant that makes the
    # shape self-describing, and the opcode ceiling that turns "these bytes look like offsets" into "these
    # record entries are script opcodes".
    dict(name="asset_families: the record count is read one low, so every table loses its first entry",
         tool="asset_families.py", args=["--check"], file="tools/asset_families.py",
         old="    count = end // 2", new="    count = end // 2 - 1"),
    # the first-entry invariant cannot be mutated *loosely* -- every accepted member already satisfies
    # `offsets[0] == end`, so relaxing it to `<` admits nothing and changes nothing (a no-op on this data,
    # which is why the third anchor closes the threshold instead: at a floor of 1 the signature stops being
    # specific, 416 members with 164 outside the two ranges).
    dict(name="asset_families: the record floor goes to 1, so the signature stops being specific",
         tool="asset_families.py", args=["--check"], file="tools/asset_families.py",
         old="def record_table(block, floor=3):", new="def record_table(block, floor=1):"),
    dict(name="asset_families: the opcode ceiling drops to 64, so real record entries fail the test",
         tool="asset_families.py", args=["--check"], file="tools/asset_families.py",
         old="OPCODE_SPACE = 141                 # walk_stream.py refuses a first byte at or above this",
         new="OPCODE_SPACE = 64                  # walk_stream.py refuses a first byte at or above this"),
    # --- M235: the loop-discontinuity sweep. Three anchors, each a number the stratum case re-derives: the
    # control boundary (which has to be a *different* boundary from the wrap, or the test grades itself), the
    # percentile the comparison is made against, and the last sample itself.
    dict(name="voice_loops: the control boundary is the wrap, so the test grades itself",
         tool="voice_loops.py", args=["--check"], file="tools/voice_loops.py",
         old='        "mid_gap": abs(samples[mid] - samples[mid - 1]),',
         new='        "mid_gap": abs(samples[0] - samples[-1]),'),
    dict(name="voice_loops: the comparison percentile drops to the median, so every wrap is an outlier",
         tool="voice_loops.py", args=["--check"], file="tools/voice_loops.py",
         old="PERCENTILE = 0.99", new="PERCENTILE = 0.50"),
    dict(name="voice_loops: the last sample is read as the first, so every clip looks silence-bounded",
         tool="voice_loops.py", args=["--check"], file="tools/voice_loops.py",
         old='        "last": samples[-1],', new='        "last": samples[0],'),
    # --- M236: the per-scene voice lists. Three anchors, each a mechanism the resolution rests on: the rate
    # bit and the index mask that together turn a `u16` into (clip, rate), and the sentinel that bounds the
    # last array -- which has no next pointer to bound it, so the region constant did it and reported 138
    # entries for an 84-entry array.
    dict(name="voice_lists: bit 15 stops selecting the rate, so the flag agrees with nothing",
         tool="voice_lists.py", args=["--check"], file="tools/voice_lists.py",
         old="RATE_FLAG = 0x8000", new="RATE_FLAG = 0x4000"),
    dict(name="voice_lists: the flag is tabulated as always clear, so it stops being a selector",
         tool="voice_lists.py", args=["--check"], file="tools/voice_lists.py",
         old="                cross[(bool(v & RATE_FLAG), records[c][2])] += 1",
         new="                cross[(False, records[c][2])] += 1"),
    dict(name="voice_lists: the index mask widens, so entries stop being clip indices",
         tool="voice_lists.py", args=["--check"], file="tools/voice_lists.py",
         old="        clips = [v & (RATE_FLAG - 1) for v in nonzero]",
         new="        clips = [v for v in nonzero]"),
    dict(name="voice_lists: the last array is bounded by the region instead of its sentinel",
         tool="voice_lists.py", args=["--check"], file="tools/voice_lists.py",
         old="                if v is None or v == END:", new="                if v is None:"),
    # --- M238: the SND_SMPDIR record and the sample prefix. Three anchors, each a mechanism a published
    # number rests on: the 16-byte prefix (the shipped value, 256, is the mutation), the low nibble bound
    # that makes a predictor byte legal, and the 24-bit count.
    # aimed at the arithmetic, not the constant: mutating `BLOCK` itself crashes the 128-int16 magnitude read,
    # and a mutation that crashes proves only that the code is fragile (M226's lesson, met again here)
    dict(name="smpdir: the grid is counted from 16 bytes, the model M238 retracted",
         tool="smpdir.py", args=["--check"], file="tools/smpdir.py",
         old='    frames = [(r["stored"] - BLOCK) // FRAME for r in rows]',
         new='    frames = [(r["stored"] - 16) // FRAME for r in rows]'),
    dict(name="smpdir: the legality census is anchored at the block, so the non-framed region disappears",
         tool="smpdir.py", args=["--check"], file="tools/smpdir.py",
         old="                at = r[\"offset\"] + 16 + i * FRAME + 8 + run * 16",
         new="                at = r[\"offset\"] + BLOCK + i * FRAME + 8 + run * 16"),
    dict(name="smpdir: the count is read as 16 bits, so every long sample's declared length truncates",
         tool="smpdir.py", args=["--check"], file="tools/smpdir.py",
         old='            "count": struct.unpack_from(">I", directory, at + 16)[0] & 0x00FFFFFF,',
         new='            "count": struct.unpack_from(">I", directory, at + 16)[0] & 0x0000FFFF,'),
    # --- M228: the dispatch-head census. Three anchors: the bound that sets the entry count, the
    # sign-extended immediate that puts a table 0x10000 off (the M226 error, as a mutation), and the
    # jal-site count that decides whether a head is a function boundary.
    dict(name="dispatch_heads: every bound is read one too large",
         tool="dispatch_heads.py", args=["--check"], file="tools/dispatch_heads.py",
         old="                bound = wb & 0xFFFF",
         new="                bound = (wb & 0xFFFF) + 1"),
    dict(name="dispatch_heads: the table address is built with an unsigned immediate",
         tool="dispatch_heads.py", args=["--check"], file="tools/dispatch_heads.py",
         old="base = (hi + (sx16(wc & 0xFFFF) if opc == ADDIU else (wc & 0xFFFF))) & 0xFFFFFFFF",
         new="base = (hi + (wc & 0xFFFF)) & 0xFFFFFFFF"),
    dict(name="dispatch_heads: a head's jal call sites are not recorded",
         tool="dispatch_heads.py", args=["--check"], file="tools/dispatch_heads.py",
         old="            jal_sites.setdefault(((va + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2), []).append(va)",
         new="            jal_sites.setdefault(0, []).append(va)"),
    # --- M227: the extent-correction queue. Three anchors aimed at its own outcomes: the word-grid
    # alignment (whose absence is the bug this tool actually shipped first), the attribution of a store
    # to its own handler, and the reference class that makes one queued correction unsafe.
    dict(name="extent_audit: the scan starts on a byte boundary instead of the word grid",
         tool="extent_audit.py", args=["--check"], file="tools/extent_audit.py",
         old="    lo = (lo + 3) & ~3",
         new="    lo = lo + 1"),
    dict(name="extent_audit: a store found through the correction is filed as the handler's own",
         tool="extent_audit.py", args=["--check"], file="tools/extent_audit.py",
         old='        kind = sites[0]["where"] if sites else "none"',
         new='        kind = "own_extent" if sites else "none"'),
    # re-aimed in M228: M227's classes were "jal_callable"/"dispatch_arm"/"unreferenced", and the head census
    # replaced them with "dispatch_head"/"table_arm"/"branch_target" plus an orthogonal jal-site count. The
    # mutation now attacks the count, because that is what decides safety.
    dict(name="extent_audit: a swallowed function's jal call sites are not counted",
         tool="extent_audit.py", args=["--check"], file="tools/extent_audit.py",
         old='                "jal_sites": jal.get(s, 0),',
         new='                "jal_sites": 0,'),
    # --- M226: the 0x36 dispatch table. Three anchors aimed at the artefact's own outcomes: the sign
    # extension that puts the table at 0x800b98e0 rather than 0x800c98e0, the bounds check that makes
    # five the entry count, and the shared tail that makes the advance 12.
    dict(name="callback_table: the addiu immediate is read unsigned, moving the table 0x10000",
         tool="callback_table.py", args=["--check"], file="tools/callback_table.py",
         old="    imm = sx16(addiu & 0xFFFF)",
         new="    imm = addiu & 0xFFFF"),
    dict(name="callback_table: the index bound is not the cited five",
         tool="callback_table.py", args=["--check"], file="tools/callback_table.py",
         old="ENTRIES = 5                   # `sltiu v0,a0,5`",
         new="ENTRIES = 4                   # `sltiu v0,a0,5`"),
    dict(name="callback_table: the tail advance is not read off the tail",
         tool="callback_table.py", args=["--check"], file="tools/callback_table.py",
         old="        \"advance\": 12 if adv and store else None,",
         new="        \"advance\": 8 if adv and store else None,"),
    # --- M224: the RSP interface. Three anchors, each aimed at an outcome the artefact turns on: the
    # 12-bit mask that puts the one synthesized link back inside the program, the two-value pointer
    # that produces the parameter records, and the bytes-1 rule the cited register map states.
    dict(name="rsp_iface: the synthesized link is not masked to IMEM's 12 bits",
         tool="rsp_iface.py", args=["--check"], file="tools/rsp_iface.py",
         old="            out.add(raw & 0xFFF)",
         new="            out.add(raw)"),
    dict(name="rsp_iface: the two-value pointer no longer yields parameter records",
         tool="rsp_iface.py", args=["--check"], file="tools/rsp_iface.py",
         old="        if len(vals) != 2 or reg == 0:",
         new="        if True:"),
    dict(name="rsp_iface: a DMA length is recorded as bytes instead of bytes-1",
         tool="rsp_iface.py", args=["--check"], file="tools/rsp_iface.py",
         old='                                        "bytes": val + 1,',
         new='                                        "bytes": val,'),
    # --- M216: the anchor lint. Disabling the uniqueness check must fail the lint's own self-test, because
    # an anchor that matches two places is a mutation that is half-applied and never says so.
    dict(name="audit lint: a duplicated anchor is no longer reported",
         tool="audit_gates.py", args=["--lint-self-test"], file="tools/audit_gates.py",
         old='        elif n > ' '1:', new='        elif False:'),
    # --- M211/M215: the two derived artefacts this cycle adds. Each mutation attacks the property that makes
    # the artefact worth having: the registry's refusal to call a variable path a constant, and the graph's
    # refusal to invent a target.
    dict(name="opcode_registry: the folded 12 is recorded as a constant advance",
         tool="opcode_registry.py", args=["--check"], file="tools/opcode_registry.py",
         old='        constant, variable = CONSTANT_PATH.get(number), VARIABLE_PATH.get(number)',
         new='        constant, variable = (CONSTANT_PATH.get(number) or 0) + 6, None'),
    dict(name="opcode_registry: an unclassified handler is counted as being in a function body",
         tool="opcode_registry.py", args=["--check"], file="tools/opcode_registry.py",
         old='    return any(start <= handler < end for start, end in bodies)', new='    return True'),
    dict(name="call_graph: the callees reconciliation reads no callees",
         tool="call_graph.py", args=["--check"], file="tools/call_graph.py",
         old='            callees[f"{img[\'name\']}:{f[\'address\']}"] = {int(x, 16) for x in f["callees"]}',
         new='            callees[f"{img[\'name\']}:{f[\'address\']}"] = set()'),
    dict(name="call_graph: node identity drops the image qualifier",
         tool="call_graph.py", args=["--check"], file="tools/call_graph.py",
         old='node = dict(id=f"{img[\'name\']}:{f[\'address\']}"',
         new='node = dict(id=f"{f[\'address\']}"'),
    # --- M209: the analysis-status index. Two ways it could flatter the corpus: the naming axis counted
    # without the curated-name rule, and the validated axis made free by an empty rule.
    dict(name="analysis_status: every function counts as named",
         tool="analysis_status.py", args=["--check"], file="tools/analysis_status.py",
         old='            named = not f["name"].startswith(("FUN_", "func_"))',
         new='            named = True'),
    dict(name="analysis_status: the validated axis is never set",
         tool="analysis_status.py", args=["--check"], file="tools/analysis_status.py",
         old='            validated = fid in F4', new='            validated = False'),
    # --- M208: the census that was a corpus generation stale. The mutation restores the `+4` that M205
    # fixed, so the fresh derivation disagrees with the committed census and the drift case must fire.
    dict(name="census: the covered set claims a word past every body again",
         tool="find_missed_functions.py", args=["--check"], file="tools/find_missed_functions.py",
         old='                    covered.update(range(int(r["start"], 16), int(r["end"], 16) + 1, 4))',
         new='                    covered.update(range(int(r["start"], 16), int(r["end"], 16) + 4, 4))'),
    # --- M207: the per-image byte map. Each mutation is a way the partition could lie: padding allowed to
    # overwrite a function body (so the body total moves), the unclassified bucket renamed to data (so the
    # hole disappears), and the padding run rounded out to the word boundary (so it stops being 0x00/0xFF).
    dict(name="byte_map: padding overwrites a function body",
         tool="classify_image.py", args=["--check-cartridge"], file="tools/classify_image.py",
         old='            claimed.setdefault(w, ("padding", f"run of 0x{value:02x} in the unpacked image"))',
         new='            claimed[w] = ("padding", f"run of 0x{value:02x} in the unpacked image")'),
    dict(name="byte_map: the unclassified bucket is renamed to data",
         tool="classify_image.py", args=["--check-cartridge"], file="tools/classify_image.py",
         old='            cls, src = claimed.get(w, ("unclassified", "no artifact names it"))',
         new='            cls, src = claimed.get(w, ("data_named", "no artifact names it"))'),
    dict(name="byte_map: a padding run is rounded out to the word boundary",
         tool="classify_image.py", args=["--check-cartridge"], file="tools/classify_image.py",
         old='            start = i + (-i % 4)',
         new='            start = i'),
    # --- M206: the manifest that published a word count as `covered_bytes`. The mutation restores the
    # word count, which the tiling case catches because covered + unclaimed then falls short of the image.
    dict(name="counts: code_index's covered_bytes is a word count again",
         tool="counts.py", args=["--check"], file="manifests/code_index.json",
         old='"covered_bytes": 57640', new='"covered_bytes": 14410'),
    # --- the M205 coverage arithmetic. The published figure was one 4-byte word per function body too
    # high; these four mutations are the ways to reintroduce it or to undermine the derivation that now
    # catches it: an exclusive end one word too far, a union taken across images instead of within one
    # (twenty overlays share a base, so that collapses 478 132 B), a function count that stops counting,
    # and a header sum allowed one word per range too high.
    dict(name="counts: the coverage union uses an exclusive end one word too far",
         tool="counts.py", args=["--check"], file="tools/counts.py",
         old='            words.update(range(int(s), int(e) + 1))',
         new='            words.update(range(int(s), int(e) + 4))'),
    dict(name="counts: the per-image union is not reset between images",
         tool="counts.py", args=["--check"], file="tools/counts.py",
         old='    for name, pairs in ranges.items():\n        words = set()',
         new='    words = set()\n    for name, pairs in ranges.items():'),
    dict(name="counts: the function count stops matching source files",
         tool="counts.py", args=["--check"], file="tools/counts.py",
         old='        "functions": len(list((root / "src").glob("*/*.c"))),',
         new='        "functions": len(list((root / "src").glob("*.c"))),'),
    dict(name="counts: the header sum is allowed one word per range too high",
         tool="counts.py", args=["--check"], file="tools/counts.py",
         old='    ok = len(sizes) == vals["functions"] + vals["fragments"] and total == vals["covered_bytes"]',
         new='    ok = len(sizes) == vals["functions"] + vals["fragments"] and total == vals["covered_bytes"] + 3 * vals["ranges"]'),
    dict(name="counts: the generated index headline is no longer parsed",
         tool="counts.py", args=["--check"], file="tools/counts.py",
         old='(\\d+) images, (\\d[\\d,]*) of',
         new='(\\d+) imagez, (\\d[\\d,]*) of'),
    # --- the M204 addressing cases. The claim is that nothing exists past byte 27, so the mutations are
    # the two ways a record could be wider than it is: a stride of 32 bytes instead of 28, and a member
    # that ends 8 bytes after the terminator. The third breaks the walker's own stride.
    dict(name="file_table: the adjacency is checked four bytes too far into the next record",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='                  if struct.unpack_from(">H", sdir, 28 * k + 28)[0] == smp_idx[k + 1])',
         new='                  if struct.unpack_from(">H", sdir, 28 * k + 32)[0] == smp_idx[k + 1])'),
    dict(name="file_table: the record stride is taken as 32 bytes, not 28",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    nxt_idx = sum(1 for k in range(n_smp - 1)',
         new='    nxt_idx = sum(1 for k in range(n_smp - 2)'),
    dict(name="file_table: the directory is taken as ending 8 bytes after the terminator",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='                  sdir[28 * n_smp:] == b"\\xff\\xff\\xff\\xff" and len(sdir) == 28 * n_smp + 4))',
         new='                  sdir[28 * n_smp:] == b"\\xff\\xff\\xff\\xff" and len(sdir) == 28 * n_smp + 12))'),
    dict(name="file_table: the count walker's stride is read as 16 bytes",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='                  and "psVar5 = psVar5 + 0xe;" in s_count and "param_1 = param_1 + 0xe;" in s_count',
         new='                  and "psVar5 = psVar5 + 0x10;" in s_count and "param_1 = param_1 + 0xe;" in s_count'),
    # --- the counts gate (M180). Its `--check` runs on a repository that is by definition consistent, so
    # aiming at the comparison is invisible; the mutation is aimed at the *derived* number instead. The
    # second audit disables the phrasectomy in the self-test, so the "a deleted phrase is caught" case
    # becomes the vacuous case it is meant to prevent.
    dict(name="counts: the derived total is off by one",
         tool="counts.py", args=["--check"],
         file="tools/counts.py",
         old='        "total_cases": sum(s[2] for s in suites),',
         new='        "total_cases": sum(s[2] for s in suites) + 1,'),
    dict(name="counts: the self-test stops deleting the phrase it checks for",
         tool="counts.py", args=["--self-test"],
         file="tools/counts.py",
         old='re.sub(r"vouch for those \\d+ cases", "vouch for those cases", ho)',
         new='re.sub(r"vouch for those \\d+ cases", lambda m: m.group(0), ho)'),
    # --- the verifier (M181). One mutation per branch of `adjudicate`, because the whole point of that
    # function is that admissibility outranks greenness, and a branch that stops firing turns the entry
    # point into a tool that reports PASS on evidence nobody has shown can fail.
    dict(name="verifier: vacuity no longer outranks greenness",
         tool="verify.py", args=["--self-test"],
         file="tools/verify.py",
         old="    if vac or brk:",
         new="    if False:"),
    dict(name="verifier: an audit that did not pass is admitted",
         tool="verify.py", args=["--self-test"],
         file="tools/verify.py",
         old="    if at == 0 or ap != at:",
         new="    if at == 0:"),
    dict(name="verifier: a failing procedure is reported as PASS",
         tool="verify.py", args=["--self-test"],
         file="tools/verify.py",
         old="    if failed:",
         new="    if False:"),
    dict(name="ratchet: src/ changes are never compared",
         tool="ratchet.py", args=["--self-test"],
         file="tools/ratchet.py",
         old='("src/ is byte-identical to the baseline", tree_now == tree_was,',
         new='("src/ is byte-identical to the baseline", True,'),
]

# things a mutated tool must be able to read; the heavy ones are symlinked
# `.github` is copied rather than linked because the workflow lint reads it — an audit of that lint that
# runs in an environment with no workflows passes for the wrong reason, which is how this list grew (M174).
COPY = ["tools", "fixtures", "docs/log", ".github", "manifests"]
# `manifests/` is a *directory* here, and that is the M232 fix. It used to be a hand-grown list of five
# artefacts, added one per milestone as each was missed — and the list was wrong again every time: the
# positive control added in M232 found **49 of 132 audits** had been passing because the tool under audit
# could not read its own artefact in the sandbox and exited non-zero *before any mutation was tested*. The
# whole sound and vector arcs (M184-M231) were in that set. Enumerating the sixth, seventh and eighth file
# would have been the third round of the same mistake; copying the directory is the same cost (0.05 s) and
# cannot drift. The positive control below stays, because a directory can still be the wrong one.
# `docs/MILESTONES.md` is here because a check of it runs: without the file, every audit of
# `milestone_index.py` "detects" a missing output and proves nothing (fifth environment gap in this arc,
# after build/elfs, src, .github/ and the shell interpreter).
# `README.md` is here because the counts gate reads it: the sixth environment gap in this arc if it is
# missing, and the failure it produced was a FileNotFoundError inside a *different* tool's self-test, which
# the audit then recorded as a detection (M180). A missing input and a caught mutation look identical from
# an exit code — which is the whole reason the positive control exists.
COPY_FILES = ["docs/handover.md", "docs/reverse_engineering_log.md", "docs/MILESTONES.md", "README.md"]
# `build/elfs` holds the built images and `src/` the decompiled corpus; both are read-only for every
# audit, and a copy is 18 MB per audit for nothing. Not linking them was invisible until an image-
# dependent tool was audited: the mutated copy failed on a missing `images.json`, not on its mutation.
# `build/decomp` and `.venv` are M232 additions found by the positive control: `census`/`call_graph` read the
# Ghidra decompile index, and `voice_sweep` looks for `unicorn` in `./.venv/bin/python` and reports no
# interpreter when the sandbox has no `.venv` — a missing toolchain that read, through an exit code, as a
# caught mutation. `.venv` is only ever *run*, never written, so a link is enough.
LINK = ["rom", "assets", "build/elfs", "build/decomp", "src", ".venv"]


def build_env(dst: Path) -> None:
    for item in COPY:
        src = ROOT / item
        if src.is_dir():
            shutil.copytree(src, dst / item)
    for item in COPY_FILES:
        src = ROOT / item
        if src.exists():
            (dst / item).parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(src, dst / item)
    for item in LINK:
        src = ROOT / item
        if src.exists():
            (dst / item).parent.mkdir(parents=True, exist_ok=True)   # build/elfs has no build/ yet
            (dst / item).symlink_to(src)


COUNT = re.compile(r"^(\d+)\s*/\s*(\d+)")


def verdict(out: str):
    """The last `N/M` line in a tool's own output, or None — the same rule `acceptance.py` uses."""
    for line in reversed(out.splitlines()):
        m = COUNT.match(line.strip())
        if m:
            return int(m.group(1)), int(m.group(2))
    return None


def run_audit(audit, keep: Path = None) -> tuple:
    """Returns (detected, detail). `detected` is True when the mutated check failed, as it must."""
    tmp = Path(tempfile.mkdtemp(prefix="gate-audit."))
    try:
        build_env(tmp)
        target = tmp / audit["file"]
        if not target.exists():
            # Sixth occurrence of the same environment gap: a new mutation targets a file the sandbox does not
            # copy (`manifests/handler_region.json` was the fifth), and the audit reports BROKEN for a reason
            # that has nothing to do with the mutation. Rather than growing COPY_FILES one entry per
            # milestone, seed any missing mutation target from the repository -- it is one file, read-only for
            # the tool being run, and the mutation is written into the sandbox copy.
            src = ROOT / audit["file"]
            if not src.exists():
                return None, f"mutation target does not exist in the repository: {audit['file']}"
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(src, target)
        # `build_env` *links* src, build/elfs, rom and assets instead of copying them, so a mutation
        # aimed at a path under one of those edits the live repository. M205 did exactly that: an
        # audit of `src/INDEX.md` wrote through the link, left the worktree mutated and was then
        # judged on its own damage. A mutation must land inside the sandbox or not at all.
        if not str(target.resolve()).startswith(str(tmp.resolve()) + "/"):
            return None, f"mutation target resolves outside the sandbox: {audit['file']}"
        text = target.read_text()
        if audit["old"] not in text:
            return None, f"mutation anchor not found in {audit['file']}"
        mutated = text.replace(audit["old"], audit["new"], 1)
        if mutated == text:
            return None, "mutation changed nothing"
        # `interp` defaults to Python, but a gate written in shell must be run by shell: with the wrong
        # interpreter the mutated copy fails on a `SyntaxError` and the audit reports a detection that has
        # nothing to do with the mutation. Both M176 gates are shell, and both were vacuous until this
        # default existed. (Fourth time in this arc that an audit environment was wrong for the tool.)
        interp = audit.get("interp", sys.executable)
        # The positive control, and it must run *before* the mutation is written -- the first version of it
        # ran after, so it graded the mutated tool and reported every single audit BROKEN, which is how this
        # comment got written. The point: a mutation can only be judged in a sandbox where the tool *works*.
        # That gap was patched by hand seven times in this file's history (each `COPY_FILES` entry above is
        # one) and M232 found it had silently swallowed **every** `head_index` audit, whose artefact was
        # never copied: the mutated tool died on `FileNotFoundError` before reaching a case, and exit 1 read
        # as a caught mutation. Growing the list an eighth time would not fix the class, so the pristine run
        # is now a mechanism. It costs one extra run per audit and it names the sandbox, not the mutation.
        control = subprocess.run([interp, str(tmp / "tools" / audit["tool"])] + audit["args"],
                                 capture_output=True, text=True, cwd=str(tmp))
        if control.returncode != 0:
            lines = (control.stdout + control.stderr).splitlines()
            why = next((l for l in reversed(lines) if l.strip()), "")
            return None, f"the unmutated tool already fails in the sandbox, so nothing is judged: {why[:120]}"
        target.write_text(mutated)
        proc = subprocess.run([interp, str(tmp / "tools" / audit["tool"])] + audit["args"],
                              capture_output=True, text=True, cwd=str(tmp))
        out = proc.stdout + proc.stderr
        # Judge the mutation the way `acceptance.py` judges a suite: by exit status and the `N/M` verdict
        # line, never by the presence of the word "FAIL". That fallback was itself the loophole this
        # audit exists to find — a gate whose *output* legitimately contains "FAIL" (the ratchet's
        # self-test prints one per deliberately broken invariant) read as "detected" no matter what, so
        # its three audits were unconditionally green while one of them caught nothing at all.
        detected = proc.returncode != 0 or (verdict(out) not in (None, (1, 1)) and verdict(out)[0] != verdict(out)[1])
        tail = [l for l in out.splitlines() if "FAIL" in l or "PASS" in l][-1:] or out.splitlines()[-1:]
        return detected, f"exit {proc.returncode}; {tail[0][:90] if tail else ''}"
    finally:
        if keep:
            shutil.move(str(tmp), str(keep))
        else:
            shutil.rmtree(tmp, ignore_errors=True)


def gated_tools() -> set:
    """The tools whose suites are registered as needing the cartridge, read from `acceptance.py`.

    Without this, an audit of a cartridge-gated tool reports VACUOUS on a machine with no cartridge: the
    mutated copy fails for want of the ROM, which acceptance reports as SKIP, and a mutation that cannot
    demonstrate anything was being counted as a check that cannot fail. Those are different things — a skip
    is an unrun check, a vacuous one is a broken check — and conflating them made `verify.py` report
    INCONCLUSIVE on every fresh clone, including the one the release notes tell a stranger to run.
    """
    ns = {"__file__": str(HERE / "acceptance.py"), "__name__": "_acceptance"}
    try:
        exec(compile((HERE / "acceptance.py").read_text(), "acceptance.py", "exec"), ns)
    except OSError:
        return set()
    out = set()
    for _name, cmd, _cases, needs_rom in ns["SUITES"]:
        if not needs_rom:
            continue
        for part in cmd:
            if isinstance(part, str) and part.startswith("tools/") and part.endswith(".py"):
                out.add(Path(part).name)
    return out


def lint(audits=None, root: Path = ROOT):
    """Check every mutation's anchor *without running anything*: seconds, not minutes (M216).

    A refactor that moves the source line a mutation anchors on turns that mutation into a BROKEN entry, which
    is only discovered at the most expensive stage -- that happened twice in one cycle (M207's padding label,
    M210's `<= CYCLE`). The property is cheap and total: the anchor still exists, it is unique, and the
    replacement changes the text. Uniqueness matters because `run_audit` replaces only the first occurrence, so
    a duplicated anchor is a mutation that is half-applied and never says so.
    """
    audits = AUDITS if audits is None else audits
    missing, dup, noop = [], [], []
    for a in audits:
        p = root / a["file"]
        if not p.exists():
            missing.append((a["name"], f"{a['file']} is gone"))
            continue
        n = p.read_text().count(a["old"])
        if n == 0:
            missing.append((a["name"], f"anchor not found in {a['file']}"))
        elif n > 1:
            dup.append((a["name"], f"anchor appears {n}x in {a['file']}"))
        elif a["old"] == a["new"]:
            noop.append((a["name"], "mutation changes nothing"))
    return [("every mutation's anchor still exists in the file it mutates", not missing, missing[:3]),
            ("every anchor is unique, because run_audit replaces only the first occurrence", not dup, dup[:3]),
            ("no mutation is a no-op", not noop, noop[:3])]


def lint_self_test() -> int:
    """The lint must report a missing anchor, a duplicated anchor and a no-op -- on synthetic entries."""
    tmp = Path(tempfile.mkdtemp())
    try:
        (tmp / "f.txt").write_text("alpha\nbeta\ngamma\ndup dup\n")
        synthetic = [dict(name="missing", file="f.txt", old="absent", new="x"),
                     dict(name="duplicate", file="f.txt", old="dup", new="dap"),
                     dict(name="noop", file="f.txt", old="alpha", new="alpha"),
                     dict(name="good", file="f.txt", old="beta", new="BETA")]
        got = {label: ok for label, ok, _d in lint(synthetic, root=tmp)}
        cases = [("a missing anchor is reported", not got["every mutation's anchor still exists in the file it mutates"]),
                 ("a duplicated anchor is reported", not got["every anchor is unique, because run_audit replaces only the first occurrence"]),
                 ("a no-op mutation is reported", not got["no mutation is a no-op"])]
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    real = lint()
    cases.append(("the repository's own mutations all lint clean", all(ok for _l, ok, _d in real)))
    bad = 0
    for label, ok in cases:
        bad += not ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    for label, ok, detail in real:
        if not ok:
            print(f"       {label}: {detail}")
    print(f"{len(cases) - bad}/{len(cases)} mutation-anchor case(s)")
    return 1 if bad else 0


def _one(audit):
    """Run one audit in a worker. Module-level so `multiprocessing` can pickle it by name."""
    return audit["name"], run_audit(audit)


def run_all(audits, jobs):
    """Every audit, `jobs` at a time, returned **in registry order**.

    The audits are independent by construction — each builds its own sandbox and mutates its own copy — so
    the order they finish in is not a fact about anything. Collecting by index keeps the report identical to
    a serial run, which is the same contract `acceptance.py` states for its pool (M240).
    """
    if jobs <= 1 or len(audits) <= 1:
        return [_one(a) for a in audits]
    import multiprocessing
    methods = multiprocessing.get_all_start_methods()
    ctx = multiprocessing.get_context("fork" if "fork" in methods else "spawn")
    with ctx.Pool(jobs) as pool:
        return pool.map(_one, audits)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--list", action="store_true", help="describe each audit and exit")
    ap.add_argument("--lint", action="store_true",
                    help="check every mutation's anchor exists and is unique, running nothing")
    ap.add_argument("--lint-self-test", action="store_true", help="grade the lint itself")
    ap.add_argument("--jobs", type=int, default=4,
                    help="audits run concurrently; the report is identical at any value (default 4)")
    args = ap.parse_args()

    if args.lint_self_test:
        return lint_self_test()
    if args.lint:
        cases = lint()
        bad = 0
        for label, ok, detail in cases:
            bad += not ok
            print(f"  {'PASS' if ok else 'FAIL'} {label}" + (f" -- {detail}" if not ok else ""))
        print(f"{len(cases) - bad}/{len(cases)} mutation-anchor case(s)")
        return 1 if bad else 0

    if args.list:
        for a in AUDITS:
            print(f"  {a['name']}\n      {a['tool']} {' '.join(a['args'])}  <- mutation in {a['file']}")
        return 0

    skipped = []
    gated = gated_tools() if not CARTRIDGE.exists() else set()
    passed = 0
    vacuous = []
    broken = []
    runnable = [a for a in AUDITS if a["tool"] not in gated]
    for a in AUDITS:
        if a["tool"] in gated:
            skipped.append(a["name"])
            print(f"  SKIP     {a['name']} — needs the cartridge, so its mutation cannot be demonstrated here")
    outcomes = dict(run_all(runnable, max(1, args.jobs)))
    for a in runnable:
        detected, detail = outcomes[a["name"]]
        if detected is None:
            broken.append((a["name"], detail))
            print(f"  BROKEN   {a['name']}: {detail}")
            continue
        if detected:
            passed += 1
            print(f"  PASS     {a['name']}  ({detail})")
        else:
            vacuous.append(a["name"])
            print(f"  VACUOUS  {a['name']}  ({detail}) — the check passed with its mechanism disabled")
    total = len(AUDITS) - len(skipped)
    print(f"\n{passed}/{total} audit case(s); {len(vacuous)} vacuous, {len(broken)} broken"
          + (f", {len(skipped)} skipped (needs the cartridge)" if skipped else ""))
    if vacuous:
        print("VACUOUS checks (they cannot fail for the right reason):")
        for name in vacuous:
            print(f"  - {name}")
    return 0 if passed == total else 1


if __name__ == "__main__":
    raise SystemExit(main())
