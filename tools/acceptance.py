#!/usr/bin/env python3
"""Run every suite in this repository and report one verdict.

Each tool owns its own fixture, which means five places to remember. This runs them all, checks the
**expected case count** (so a fixture that quietly loses cases fails), and exits non-zero on any failure.
Nothing here re-implements a check: it only invokes, parses and aggregates.

Suites:
  tools/provenance.py --self-test     the intra-procedural provenance fixture
  tools/provenance.py --self-test2    the interprocedural / summary / path fixture
  tools/provenance.py --acceptance    the two pre-registered experiment-B acceptance tests
  tools/pad_layout.py --self-test     the SI command-block / CHNL_ERR fixture
  tools/test_harness.py               the MIPS execution fixture (the verified CPU path)

Usage:
  ./acceptance.py            # all suites
  ./acceptance.py -v         # show each suite's own output
  ./acceptance.py --no-audit # defer the gate audit to verify.py, which grades it last
"""
import argparse
import importlib.util
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

HERE = Path(__file__).resolve().parent

CARTRIDGE = Path("rom/Resident Evil 2 (USA) (Rev 1).z64")


def _audit_case_count():
    """How many cases the gate audit has, read from its own list instead of pinned here.

    M224 found this number stale (a typed 107 against a real 109) and fixed it by typing 112 — then M225
    added three anchors and left the 112 behind, the same defect one milestone later. The number is a
    property of `audit_gates.AUDITS`, so it is derived: one audit is one case (`total = len(AUDITS) `
    `- skipped`), and with the cartridge present nothing skips. A pin that has to be remembered is not an
    assertion, it is a habit.
    """
    spec = importlib.util.spec_from_file_location("audit_gates", Path(__file__).resolve().parent / "audit_gates.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return len(mod.AUDITS)

# (name, command, expected case count, needs the cartridge). The cartridge is gitignored by design, so a
# fresh clone — and therefore any CI runner — cannot supply it. Suites that need it report SKIP rather than
# PASS or FAIL: pretending they ran would be the same class of error as a fixture that asserts nothing.
SUITES = [
    ("provenance self-test", [sys.executable, "tools/provenance.py", "--self-test"], 10, False),
    ("provenance self-test2", [sys.executable, "tools/provenance.py", "--self-test2"], 12, False),
    ("provenance acceptance", [sys.executable, "tools/provenance.py", "--acceptance"], 3, True),
    ("corpus pipeline (synthetic)", [sys.executable, "tools/provenance.py", "--corpus-self-test"], 6, False),
    ("pad_layout self-test", [sys.executable, "tools/pad_layout.py", "--self-test"], 8, False),
    ("patch_text self-test", [sys.executable, "tools/patch_text.py", "--self-test"], 8, False),
    ("doc markers (synthetic)", [sys.executable, "tools/check_markers.py", "--self-test"], 15, False),
    ("doc markers (repository)", [sys.executable, "tools/check_markers.py"], 22, False),
    ("walk_stream length map", [sys.executable, "tools/walk_stream.py", "--self-test"], 23, False),
    # `rdram_fixture.py` builds its bytes synthetically but walks them with `walk_stream.py`, which loads
    # the stage-2 image from `assets/unpacked/` — an unpacked cartridge member. Green locally, red on any
    # fresh clone, so it is cartridge-dependent in fact even though its input memory is synthetic (M174).
    ("synthetic-rdram walk", [sys.executable, "tools/rdram_fixture.py"], 7, True),
    ("room script (cartridge)", [sys.executable, "tools/room_script.py", "--check"], 4, True),
    ("script profile (cartridge)", [sys.executable, "tools/script_profile.py", "--check"], 5, True),
    ("cfg reachability (cartridge)", [sys.executable, "tools/cfg_reach.py", "--check"], 7, True),
    ("room scripts only (cartridge)", [sys.executable, "tools/cfg_reach.py", "--check-rooms"], 3, True),
    ("01 41 container (cartridge)", [sys.executable, "tools/container_0141.py", "--check"], 29, True),
    ("exception path (cartridge)", [sys.executable, "tools/exception_path.py", "--check"], 8, True),
    ("t64info (C header)", [sys.executable, "tools/t64_selftest.py"], 4, True),
    ("routine index bounds (cartridge)", [sys.executable, "tools/routine_index.py"], 14, True),
    # Derived, not pinned: M224 typed 107 against a real 109 and M225 typed 112 against a real 115, both
    # invisible in CI because `--no-audit` defers this suite to `verify.py`, which grades it by its own
    # summary line. See `_audit_case_count`.
    ("gate audit (mechanisms disabled)", [sys.executable, "tools/audit_gates.py"],
     _audit_case_count(), True),
    # CI cannot test the file that makes CI run: an invalid workflow is never scheduled, so nothing
    # reports it. This suite does — and it needs no cartridge, so a runner checks its own definition (M174).
    ("workflow lint", [sys.executable, "tools/workflow_lint.py"], 14, False),
    # The full tier's guard and the fetch verification are shell, but they are gates: both are tested in
    # both directions, and neither needs a cartridge, so a runner tests them too (M176).
    # The milestone index is generated: --check fails when it drifts from the log, the notes or the gaps.
    ("artefact scan (repository)", [sys.executable, "tools/artefact_scan.py"], 5, False),
    ("artefact scan (synthetic)", [sys.executable, "tools/artefact_scan.py", "--self-test"], 7, False),
    ("milestone index (repository)", [sys.executable, "tools/milestone_index.py", "--check"], 10, False),
    ("milestone index (synthetic)", [sys.executable, "tools/milestone_index.py", "--self-test"], 11, False),
    ("full-tier guard", ["sh", "tools/ci_full.sh", "--self-test"], 3, False),
    ("cartridge fetch", ["sh", "tools/cart_fetch.sh", "--self-test"], 4, False),
    ("mips harness", [sys.executable, "tools/test_harness.py"], 15, False),
    # The file table is the cartridge's whole file system, and it is mostly *not* zlib (M178). One
    # suite because the finding is one object: the census, the two files the 17.6 MB turned out to be,
    # the MORT record format, and the refutations that keep the unsolved field unsolved.
    ("byte map (repository)", [sys.executable, "tools/classify_image.py", "--check"], 6, False),
    ("hook certificate (repository)", [sys.executable, "tools/hook_cert.py", "--self-test"], 9, False),
    # M241: the generated Script-VM header must be exactly what the registry derives. It is the file a
    # matching reconstruction includes, so drift in it is drift in every future function signature.
    ("tyrant header (repository)", [sys.executable, "tools/tyrant_header.py", "--check"], 1, False),
    # M242: the matching comparator, proved on the real bytes -- an ELF against the member it was built
    # from, and a one-word perturbation located and attributed. Needs build/elfs and the assets.
    ("match diff (cartridge)", [sys.executable, "tools/match_diff.py", "--self-test"], 4, True),
    # M243: the splat dress rehearsal on the boot image -- the split tiles it, the map reassembles it, and
    # the built ELF still equals the cartridge. Needs the cartridge, build/elfs and assets/.
    ("splat rehearsal (cartridge)", [sys.executable, "tools/splat_boot.py", "--check"], 5, True),
    # M246: the compile-probe corpus -- IDO 5.3 and 7.1 are byte-identical, and both are refuted by the
    # cartridge move idiom (6560 addu, 0 or). Needs the unpacked image and build/toolchain.
    ("compile probes (cartridge)", [sys.executable, "tools/compile_probe.py", "--check"], 53, True),
    ("image inventory (cartridge)", [sys.executable, "tools/export_ranges.py", "--check-images"], 1, True),
    # M273: the README's progress map is generated from the fixtures, so it cannot drift from them, and every
    # function it claims as recovered must exist in the corpus. Repository-only: no cartridge needed.
    ("progress map (repository)", [sys.executable, "tools/progress_map.py", "--check"], 3, False),
    ("analysis status (repository)", [sys.executable, "tools/analysis_status.py", "--check"], 7, False),
    ("missed-function census (cartridge)", [sys.executable, "tools/find_missed_functions.py", "--check"], 2, True),
    ("byte map (cartridge)", [sys.executable, "tools/classify_image.py", "--check-cartridge"], 2, True),
    ("call graph (cartridge)", [sys.executable, "tools/call_graph.py", "--check"], 8, True),
    ("opcode registry (cartridge)", [sys.executable, "tools/opcode_registry.py", "--check"], 17, True),
    ("mutation anchors (repository)", [sys.executable, "tools/audit_gates.py", "--lint-self-test"], 4, False),
    # M299: the shape solver's pure half -- what it enumerates. Its scoring half needs the cartridge, so the
    # cases here are the enumeration only and the tool is otherwise exercised through the probe suites.
    ("shape solver (repository)", [sys.executable, "tools/shape_solver.py", "--self-test"], 6, False),
    ("preflight (repository)", [sys.executable, "tools/preflight.py", "--self-test"], 6, False),
    ("handler region (cartridge)", [sys.executable, "tools/handler_region.py", "--check"], 13, True),
    ("script vm decoder (cartridge)", [sys.executable, "tools/scd_vm.py", "--check"], 34, True),
    ("script vm refusals (cartridge)", [sys.executable, "tools/vm_refusals.py", "--check"], 9, True),
    ("script population (cartridge)", [sys.executable, "tools/script_population.py", "--check"], 13, True),
    ("sound project (cartridge)", [sys.executable, "tools/snd_proj.py", "--check"], 28, True),
    ("sound macros (cartridge)", [sys.executable, "tools/snd_macros.py", "--check"], 24, True),
    # M233: the six script commands that reach the sound subsystem, read from their handlers. Needs
    # stage-2 bytes and build/elfs/boot.elf -- the one call that leaves the image lands in boot.
    ("sound commands (cartridge)", [sys.executable, "tools/sound_ops.py", "--check"], 10, True),
    ("file table (cartridge)", [sys.executable, "tools/file_table.py", "--check"], 101, True),
    # M234: the record-table families -- two script ranges, one undecoded container, and the 48-record
    # claim answered negatively. Needs the cartridge: it decompresses every real entry.
    ("asset families (cartridge)", [sys.executable, "tools/asset_families.py", "--check"], 11, True),
    # M238: the SND_SMPDIR record and the 16-byte sample prefix. Needs the cartridge.
    ("smpdir record (cartridge)", [sys.executable, "tools/smpdir.py", "--check"], 10, True),
    # M235: the loop-discontinuity claim, measured and refuted. Gates a 5-clip stratum and reads the
    # whole-bank aggregates from the committed artefact, like voice_sweep.py.
    ("voice loops (cartridge)", [sys.executable, "tools/voice_loops.py", "--check"], 7, True),
    # M236: the per-scene voice lists in the image, and the rate bit that proves they index the clip
    # bank. Needs stage-2 bytes and the MORT bank.
    ("voice lists (cartridge)", [sys.executable, "tools/voice_lists.py", "--check"], 12, True),
    # The pool decoder, validated by the one discriminator that matters: the shared codebook decodes
    # audio and a per-sample book does not. Established with reference to re2studio (GPL-3.0, read as a
    # specification, no code copied); see THIRD_PARTY.md.
    ("sound decode (cartridge)", [sys.executable, "tools/sound_decode.py", "--check"], 7, True),
    # The voice bank, decoded by EXECUTING the cartridge's synthesis (M198). The synthesis routines take
    # their arguments in registers the pseudocode does not model, so there is nothing faithful to
    # transcribe from it; the tool runs the instructions instead and the cases report what came out. It
    # needs the cartridge and an emulator, and it says so loudly rather than skipping when the emulator is
    # missing — a suite that goes quiet when its engine is absent is the failure this repository audits.
    ("voice decode (cartridge)", [sys.executable, "tools/voice_decode.py", "--check"], 9, True),
    ("voice sweep (cartridge)", [sys.executable, "tools/voice_sweep.py", "--check"], 12, True),
    ("voice descriptor (cartridge)", [sys.executable, "tools/voice_descriptor.py", "--check"], 29, True),
    # The table opcode 0x36 dispatches through, resolved in M226. It needs the cartridge because every
    # claim is read out of the unpacked stage-2 member.
    ("callback table (cartridge)", [sys.executable, "tools/callback_table.py", "--check"], 9, True),
    # The extent-correction queue M212 left, audited before anyone spends a Ghidra run on it (M227).
    ("extent audit (cartridge)", [sys.executable, "tools/extent_audit.py", "--check"], 14, True),
    # The dispatch-head class the two extent questions turned out to share (M228).
    ("dispatch heads (cartridge)", [sys.executable, "tools/dispatch_heads.py", "--check"], 9, True),
    # What each head dispatches on — the index traced to its source (M230).
    ("head index (cartridge)", [sys.executable, "tools/head_index.py", "--check"], 9, True),
    ("rsp ucode (cartridge)", [sys.executable, "tools/rsp_decode.py", "--check"], 22, True),
    # The interface between the task block the CPU publishes and the code the RSP runs (M224). It needs
    # the cartridge because every claim in it is a measurement of the unpacked stage-2 member.
    ("rsp interface (cartridge)", [sys.executable, "tools/rsp_iface.py", "--check"], 28, True),
    ("sound fixtures (repository)", [sys.executable, "tools/sound_fixtures.py", "--check"], 10, False),
    ("sound fixtures self-test", [sys.executable, "tools/sound_fixtures.py", "--self-test"], 4, False),
    # The ratchet guards the registry itself. `--self-test` breaks each invariant on a synthetic root
    # (a lowered count, a deleted suite, an unbaselined addition, an edit to src/) and requires
    # detection; `--check` applies the same two invariants to this repository. Both are needed: without
    # the self-test `--check` passes on a healthy tree whether or not either invariant is wired.
    ("ratchet self-test", [sys.executable, "tools/ratchet.py", "--self-test"], 10, False),
    ("ratchet (repository)", [sys.executable, "tools/ratchet.py", "--check"], 4, False),
    # The counts are derived from this very list, so registering a suite changes them — and this suite
    # is the one that notices the docs no longer agree. It caught its own registration (M180).
    ("counts self-test", [sys.executable, "tools/counts.py", "--self-test"], 4, False),
    ("counts (repository)", [sys.executable, "tools/counts.py", "--check"], 25, False),
    # The pool that runs the rest of this list. Graded because a scheduler can lie in ways a plain
    # loop cannot: drop a result, reorder the report, or swallow a death. Its own `--self-test` does not
    # run SUITES, so registering it is not the recursion that `--check` would be.
    ("acceptance self-test", [sys.executable, "tools/acceptance.py", "--self-test"], 6, False),
    # The verifier's own rule, graded before anyone relies on it: a vacuous audit must force INCONCLUSIVE
    # rather than PASS. The full run is *not* registered here — it invokes `ci.sh`, which runs this list,
    # so registering it would recurse.
    ("verifier self-test", [sys.executable, "tools/verify.py", "--self-test"], 8, False),
]

# The one suite that can be handed off. `verify.py` runs this whole file and *then* runs the audit as
# its admission step, so running it here as well means the most expensive suite in the repository is paid
# for twice in every verified run (M196). Deferring is a hand-off, not a hole: the audit still runs in
# every full-tier path -- from verify.py, last, against the tree as it is at the end.
AUDIT_SUITE = "gate audit (mechanisms disabled)"

COUNT = re.compile(r"^(\d+)\s*/\s*(\d+)")


def run(cmd):
    proc = subprocess.run(cmd, cwd=str(HERE.parent), capture_output=True, text=True)
    return proc.returncode, proc.stdout + proc.stderr, proc.stdout.splitlines()


def tally(lines):
    """The last `N/M` line in a suite's output is its verdict."""
    for line in reversed(lines):
        m = COUNT.match(line.strip())
        if m:
            return int(m.group(1)), int(m.group(2))
    return None


# Four, not eight: `file_table.py --check` holds the 64 MiB cartridge plus its slices, so a worker costs
# a few hundred MiB. The default stays 1, and CI never sets it — the suite is a gate, not a benchmark.
MAX_JOBS = 4

# M240: the fast tier. Measured per suite on this machine: `voice sweep` **46 s** (it emulates the cartridge's
# own synthesis under Unicorn for five clips), `provenance acceptance` **19 s** (it hashes src/), `routine index
# bounds` **8 s**, `file table` **4.3 s** — against a sub-second median for the other 63. Those four are the
# whole difference between a 12-minute commit and a ~30-second one, so they are named here as a measurement,
# not a preference, and `--tier fast` drops exactly them.
# `--tier all` (the default) is unchanged, so no existing caller can accidentally get less than it asked for.
HEAVY_SUITES = ("voice sweep (cartridge)", "file table (cartridge)",
                "provenance acceptance", "routine index bounds (cartridge)")


def jobs_of(raw):
    """Clamp a JOBS value to 1..MAX_JOBS. An unparseable value is 1 — a pool with no workers would
    report a green run without running anything."""
    try:
        n = int(raw)
    except (TypeError, ValueError):
        return 1
    return max(1, min(n, MAX_JOBS))


def jobs_from_env():
    return jobs_of(os.environ.get("JOBS", "1"))


def judge(name, expected, code, text, lines):
    """-> (verdict line, failure or None, text). One suite's verdict, from its exit status and its tally."""
    got = tally(lines)
    if got is None:
        return ("%-24s %-10s FAIL (no N/M verdict; exit %d)" % (name, "-", code),
                (name, "no verdict, exit %d" % code), text)
    passed, total = got
    ok = code == 0 and passed == total and total == expected
    note = "" if total == expected else "  EXPECTED %d CASES, found %d" % (expected, total)
    return ("%-24s %-10s %s%s" % (name, "%d/%d" % (passed, total), "PASS" if ok else "FAIL", note),
            None if ok else (name, "%d/%d, exit %d" % (passed, total, code)), text)


def sweep(entries, jobs, have_cart, skip_audit, emit=None):
    """Run every suite, at most `jobs` at a time, and report one line per suite **in registry order**.

    Order is the contract, not a courtesy: a run at JOBS=4 must print exactly what JOBS=1 prints, byte for
    byte, so the pool may change how long the gate takes but never what it says. Skipped and deferred
    suites keep their own line in their own place instead of being hoisted to the top.
    """
    lines, failures, verbose, deferred, skipped = [], [], [], [], 0
    slots = []
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        for name, cmd, expected, needs_rom in entries:
            if skip_audit and name == AUDIT_SUITE:
                # NOT "SKIP (needs the cartridge)": that phrase means the cartridge is absent, is counted
                # as skipped, and is grepped for by ci_full.sh. This is a different fact.
                slots.append((name, expected, "DEFERRED", None))
            elif needs_rom and not have_cart:
                slots.append((name, expected, "SKIP", None))
            else:
                slots.append((name, expected, "RUN", pool.submit(run, cmd)))
        for name, expected, kind, fut in slots:
            if kind == "DEFERRED":
                line = "%-24s %-10s %s" % (name, "-", "DEFERRED (graded by verify.py)")
                deferred.append((name, expected))
            elif kind == "SKIP":
                line = "%-24s %-10s %s" % (name, "-", "SKIP (needs the cartridge)")
                skipped += 1
            else:
                code, text, out = fut.result()
                line, fail, text = judge(name, expected, code, text, out)
                if fail:
                    failures.append(fail)
                    verbose.append(text)
            lines.append(line)
            if emit:
                emit(line)
    return lines, failures, skipped, deferred, verbose


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("-v", "--verbose", action="store_true")
    ap.add_argument("--tier", choices=("all", "fast"), default="all",
                    help="`fast` drops the suites whose cost dominates the run (see HEAVY_SUITES)")
    ap.add_argument("--no-audit", action="store_true",
                    help="defer the gate audit to verify.py (which runs it last, as admission)")
    ap.add_argument("--self-test", action="store_true",
                    help="grade the pool: it may change the clock, never the verdict or the order")
    args = ap.parse_args()
    if args.self_test:
        return self_test()

    have_cart = (HERE.parent / CARTRIDGE).exists()
    suites = SUITES
    if args.tier == "fast":
        suites = [s for s in SUITES if s[0] not in HEAVY_SUITES]
        print("tier: fast — %d heavy suite(s) held back: %s" % (
            len(SUITES) - len(suites), ", ".join(HEAVY_SUITES)))
    print("cartridge: %s" % ("present" if have_cart else
                             "ABSENT — suites that need it will report SKIP"))
    print("%-24s %-10s %s" % ("suite", "cases", "verdict"))
    lines, failures, skipped, deferred, verbose = sweep(
        suites, jobs_from_env(), have_cart, args.no_audit, emit=print)
    if args.verbose:
        for text in verbose:
            print(text)

    print()
    if failures:
        for name, why in failures:
            print("FAIL %s: %s" % (name, why))
        return 1
    ran = [s for s in suites if not (s[3] and not have_cart)
           and not (args.no_audit and s[0] == AUDIT_SUITE)]
    tail = "" if not skipped else "; %d skipped for want of the cartridge" % skipped
    if deferred:
        tail += "; %d deferred to verify.py (%d cases graded there)" % (
            len(deferred), sum(e for _, e in deferred))
    print("all %d runnable suite(s) pass (%d cases)%s" % (
        len(ran), sum(e for _, _, e, _ in ran), tail))
    return 0


def self_test():
    """Grade the pool itself, because "it passed under a scheduler" is the failure this repo audits.

    Each case is aimed at one way a worker pool can lie: dropping a result, reordering the report,
    swallowing a death, or reporting green with no worker at all.
    """
    green = ["sh", "-c", "echo PASS; echo 2/2"]
    red = ["sh", "-c", "echo FAIL; echo 1/2"]
    silent = ["sh", "-c", "echo nothing to report"]        # exits 0 with no N/M line
    killed = ["sh", "-c", "exit 3"]                        # dies with no output
    cases = []

    def at(seq, i):
        """Guarded access: a case must *fail* when a result is missing, not raise. A crash in a self-test
        is indistinguishable from a caught mutation at the exit-code level, which is the loophole this
        whole file exists to avoid."""
        return seq[i] if i < len(seq) else ""

    three = [("a", green, 2, False), ("b", green, 2, False), ("c", green, 2, False)]
    l1, f1, _s1, _d1, _v1 = sweep(three, 1, True, False)
    l4, f4, _s4, _d4, _v4 = sweep(three, 4, True, False)
    cases.append(("three suites print three lines, in registry order, at one worker and at four",
                  len(l1) == 3 and l1 == l4 and not f1 and not f4
                  and at(l1, 0).startswith("a") and at(l1, 1).startswith("b")
                  and at(l1, 2).startswith("c")))

    l4, f4, _s, _d, _v = sweep([("bad", red, 2, False)], 4, True, False)
    cases.append(("a failing suite still fails under the pool, and the failure names it",
                  bool(f4) and at(f4, 0)[0] == "bad" and "FAIL" in at(l4, 0)))

    l4, f4, _s, _d, _v = sweep([("silent", silent, 1, False)], 4, True, False)
    cases.append(("a suite that exits 0 with no N/M verdict is a FAIL, not a silent drop",
                  bool(f4) and "no N/M verdict" in at(l4, 0)))

    l4, f4, _s, _d, _v = sweep([("killed", killed, 1, False)], 4, True, False)
    cases.append(("a suite that dies without a verdict is a FAIL under the pool", bool(f4)))

    l1, f1, _s, _d, _v = sweep([("mismatch", green, 3, False)], 1, True, False)
    l4, f4, _s, _d, _v = sweep([("mismatch", green, 3, False)], 4, True, False)
    cases.append(("an expected-count mismatch is caught at one worker and at four, identically",
                  bool(f1) and bool(f4) and l1 == l4 and "EXPECTED 3 CASES" in at(l4, 0)))

    cases.append(("JOBS clamps to 1..MAX_JOBS, so an empty or absurd pool cannot report a green run",
                  jobs_of("0") == 1 and jobs_of("-1") == 1 and jobs_of("abc") == 1
                  and jobs_of(None) == 1 and jobs_of("64") == MAX_JOBS and jobs_of("3") == 3))

    passed = 0
    for label, ok in cases:
        passed += ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d acceptance self-test case(s)" % (passed, len(cases)))
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
