#!/usr/bin/env python3
"""The verifier's entry point. One run, one verdict, and one rule it does not get to reinterpret.

The rule: **a result is only admissible if the gates that produced it have been shown to fail.** In this
repository that is `tools/audit_gates.py` — every check's mechanism is disabled in a throw-away copy and the
check must then fail. If the audit reports any vacuous or broken entry, then whatever else passed did so for
reasons nobody has established, and the verdict is `INCONCLUSIVE` **no matter how green everything else is**.
That is deliberately not a judgement call: it is the first branch of `adjudicate`, and `--self-test` proves
each branch by feeding it synthetic results.

So the verifier does not decide whether an artefact is correct, and it does not invent a procedure. It runs
the procedures the project already maintains, in a fixed order, and reports what they said:

    tools/ci.sh              acceptance (expected case counts), tracked artefacts, cartridge digest
    tools/ratchet.py         the registry has not drifted and src/ has not moved, silently
    tools/counts.py          the seven numbers quoted in four files still agree with the registry
    tools/audit_gates.py     every gate still fails when its own mechanism is disabled  <- admission

The first three are *evidence*. The fourth is *admissibility*, and it runs last so that it is graded against
the tree as it actually is at the end of the run.

  ./verify.py               # human-readable report
  ./verify.py --json        # the same, machine-readable, for the primary agent to read
  ./verify.py --self-test   # prove each branch of the verdict, including the inadmissible one
"""
import argparse
import json
import os
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import hook_cert  # noqa: E402  — the certificate writer the hook reads (M210)

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
CARTRIDGE = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
REPORT = ROOT / "build" / "verify-report.json"

# M240: two tiers, because one tier at the full price is why a commit cost twelve minutes.
#
#   fast (default)  the same procedures, minus the four suites whose cost dominates the run and minus
#                   admission. Measured end to end on this machine: **~19 s**. It does not admit anything --
#                   the verdict says PASS-FAST and the certificate records `admission: not-run`.
#   full (--full)   everything, admission included. The audit is parallel now (`--jobs`), so this is ~2-3 min
#                   rather than ~12.
#
# The rule is untouched: a result is only *admissible* when the gate audit passed. What changed is where that
# happens -- at push/nightly instead of on every commit -- and the word "admissible" is still the only thing
# that licenses a claim.
FAST = "--tier", "fast"
PROCEDURES = [
    # `--no-audit`: this run grades the audit itself, below and last, against the tree as it ends. Letting
    # the acceptance sweep run it too made the repository's most expensive check cost twice (M196).
    ("ci", ["sh", "tools/ci.sh", "--no-audit"], "acceptance, artefact scan and cartridge digest"),
    ("ratchet", [sys.executable, "tools/ratchet.py", "--check"], "registry drift and src/ freeze"),
    ("counts", [sys.executable, "tools/counts.py", "--check"], "documented numbers vs the registry"),
]
ADMISSION = ("audit", [sys.executable, "tools/audit_gates.py"], "every gate must fail when disabled")

COUNT = re.compile(r"^(\d+)\s*/\s*(\d+)")
AUDIT = re.compile(r"(\d+)/(\d+) audit case\(s\);\s*(\d+) vacuous,\s*(\d+) broken")
# "... 9 skipped (needs the cartridge)" — an unrun check, which is not the same as a broken one.
AUDIT_SKIP = re.compile(r"audit case\(s\);.*?,\s*(\d+) skipped")
SKIP = re.compile(r"Skipped for want of the cartridge|SKIP \(needs the cartridge\)")
# `ci.sh` ends with the artefact scan's own `5/5`, which is not what it covers. Its coverage is the
# acceptance summary, so that is what the report quotes for it — the verifier's report must not be the
# one place in this repository where a number means something other than what it says.
CI_SUMMARY = re.compile(r"all (\d+) runnable suite\(s\) pass \((\d+) cases\)")


def run(cmd, env=None):
    proc = subprocess.run(cmd, cwd=str(ROOT), capture_output=True, text=True, env=env)
    return proc.returncode, proc.stdout + proc.stderr


def verdict_of(text):
    """The last `N/M` line — the same rule `acceptance.py` uses, so a tool cannot pass by printing PASS."""
    for line in reversed(text.splitlines()):
        m = COUNT.match(line.strip())
        if m:
            return int(m.group(1)), int(m.group(2))
    return None


def _worktree_hash() -> str:
    """The hash `tools/hook_cert.py` writes into a certificate (M210).

    The report used to carry only a dirty *boolean*, which cannot answer "is the commit the tree that was
    graded?". `verify.py` now records the hash and writes the certificate the hook reads.
    """
    return hook_cert.worktree_hash()


def adjudicate(procedures, audit):
    """-> (verdict, why). Pure, so `--self-test` grades the rule rather than a subprocess.

    `procedures` is [(name, exit_code, (passed, total) or None)], `audit` is (passed, total, vacuous,
    broken) or None. Order matters: admissibility is checked before anything else.
    """
    if audit is None:
        return "INCONCLUSIVE", "the gate audit produced no N/M verdict, so no result can be admitted"
    ap, at, vac, brk = audit[:4]
    if vac or brk:
        return "INCONCLUSIVE", (f"the gate audit reports {vac} vacuous and {brk} broken — the checks that "
                                f"produced this evidence have not been shown to fail")
    if at == 0 or ap != at:
        return "INCONCLUSIVE", f"the gate audit itself did not pass ({ap}/{at})"
    failed = [(n, c) for n, c, _ in procedures if c != 0]
    if failed:
        return "FAIL", "procedures failed: " + ", ".join(f"{n} (exit {c})" for n, c in failed)
    partial = [n for n, _, v in procedures if v is not None and v[0] != v[1]]
    if partial:
        return "FAIL", "procedures reported fewer cases than they ran: " + ", ".join(partial)
    return "PASS", f"every procedure passed and the gate audit is {ap}/{at} with nothing vacuous"


def collect(tier="fast"):
    results, screens, details = [], {}, {}
    env = dict(os.environ)
    if tier == "fast":
        env["JOBS"] = "4"                      # measured: 29.6 s at JOBS=1 -> 15.7 s at JOBS=4
    for name, cmd, _why in PROCEDURES:
        if name == "ci" and tier == "fast":
            cmd = cmd + list(FAST)
        code, out = run(cmd, env=env)
        m = CI_SUMMARY.search(out)
        if name == "ci" and m:
            suites, cases = int(m.group(1)), int(m.group(2))
            results.append((name, code, (cases, cases)))
            details[name] = f"{suites} suites / {cases} cases"
        else:
            results.append((name, code, verdict_of(out)))
            v = verdict_of(out)
            details[name] = f"{v[0]}/{v[1]}" if v else "-"
        screens[name] = out
    if tier == "fast":
        # admission is not run at all here, and the report says so rather than implying a clean audit
        return results, screens, None, details
    code, out = run(ADMISSION[1])
    m = AUDIT.search(out)
    ms = AUDIT_SKIP.search(out)
    audit = (int(m.group(1)), int(m.group(2)), int(m.group(3)), int(m.group(4)),
             int(ms.group(1)) if ms else 0) if m else None
    results.append((ADMISSION[0], code, verdict_of(out)))
    screens[ADMISSION[0]] = out
    v = verdict_of(out)
    details[ADMISSION[0]] = f"{v[0]}/{v[1]}" if v else "-"
    return results, screens, audit, details


def report(as_json: bool, tier="fast") -> int:
    results, screens, audit, details = collect(tier)
    if tier == "fast":
        failed = [(n, c) for n, c, _ in results if c != 0]
        partial = [n for n, _, v in results if v is not None and v[0] != v[1]]
        verdict, why = (("FAIL", "procedures failed: " + ", ".join(f"{n} (exit {c})" for n, c in failed))
                        if failed else
                        ("FAIL", "procedures reported fewer cases than they ran: " + ", ".join(partial))
                        if partial else
                        ("PASS-FAST", "the fast tier passed; admission (the gate audit) was NOT run, so "
                                      "nothing here is admissible until `verify.py --full` passes"))
    else:
        verdict, why = adjudicate(results, audit)
    have_cart = CARTRIDGE.exists()
    skipped = bool(SKIP.search(screens["ci"]))
    sha = subprocess.run(["git", "rev-parse", "--short", "HEAD"], cwd=str(ROOT),
                         capture_output=True, text=True).stdout.strip()
    dirty = bool(subprocess.run(["git", "status", "--porcelain"], cwd=str(ROOT),
                                capture_output=True, text=True).stdout.strip())
    out = {
        "artifact": {"commit": sha or "(unknown)", "dirty": dirty, "cartridge": have_cart,
                     "worktree": _worktree_hash()},
        "procedures": [{"name": n, "exit": c, "detail": details[n]} for n, c, _v in results],
        "admission": {"gate_audit": f"{audit[0]}/{audit[1]}" if audit else None,
                      "vacuous": audit[2] if audit else None,
                      "broken": audit[3] if audit else None,
                      "skipped_no_cartridge": audit[4] if audit else None,
                      "admissible": verdict != "INCONCLUSIVE"},
        "verdict": verdict,
        "why": why,
        "coverage": ("fast" if tier == "fast" else
                     "partial" if (skipped or (audit and audit[4])) else "full"),
        "note": ("fast tier: four heavy suites held back and admission not run -- `--full` for the whole thing"
                 if tier == "fast" else
                 "cartridge-gated suites SKIPped: any claim that depends on them is INCONCLUSIVE here"
                 if (skipped or (audit and audit[4])) else "all suites ran"),
        "blocks_milestone": verdict != "PASS",
        "tier": tier,
    }
    REPORT.parent.mkdir(parents=True, exist_ok=True)
    REPORT.write_text(json.dumps(out, indent=1) + "\n")
    # M210: the certificate the pre-commit hook reads. Only a PASS with a clean admission is certifiable,
    # and only for the worktree this run graded -- `hook_cert.valid` re-checks the hash at commit time.
    cert = hook_cert.write("PASS" if verdict == "PASS" else verdict,
                           ("clean" if out["admission"]["admissible"] else "vacuous")
                           if tier == "full" else "not-run", commit=sha or "")
    out["certificate"] = cert
    if as_json:
        print(json.dumps(out, indent=1))
    else:
        print(f"verifier report — {out['artifact']['commit']}"
              f"{' (dirty tree)' if dirty else ''}, cartridge {'present' if have_cart else 'ABSENT'}")
        print(f"  {'procedure':10s} {'covers':>28s}  exit")
        for p in out["procedures"]:
            print(f"  {p['name']:10s} {p['detail']:>28s}  {p['exit']}")
        sk = out["admission"]["skipped_no_cartridge"] or 0
        print(f"  admission  gate audit {out['admission']['gate_audit'] or 'NOT RUN'}, "
              f"{out['admission']['vacuous'] if out['admission']['vacuous'] is not None else '-'} vacuous, "
              f"{out['admission']['broken'] if out['admission']['broken'] is not None else '-'} broken"
              + (f", {sk} skipped" if sk else ""))
        print(f"\nVERDICT {verdict} — {why}")
        print(f"coverage {out['coverage']}: {out['note']}")
        print(f"report written to {REPORT}")
    return 0 if verdict in ("PASS", "PASS-FAST") else 1


def self_test() -> int:
    clean = (44, 44, 0, 0, 0)
    allpass = [("a", 0, (10, 10)), ("b", 0, (4, 4))]
    cases = [
        ("a clean audit and every procedure passing is PASS",
         adjudicate(allpass, clean)[0] == "PASS"),
        # an audit that could not run is not an audit that could not fail: skipped must not block a clone,
        # which is what made verify.py report INCONCLUSIVE on every fresh checkout (M191)
        ("audits skipped for want of the cartridge do not make a run inadmissible",
         adjudicate(allpass, (35, 35, 0, 0, 9))[0] == "PASS"),
        # the rule the verifier is not allowed to reinterpret: vacuity outranks greenness
        ("one vacuous audit entry makes a fully green run INCONCLUSIVE, not PASS",
         adjudicate(allpass, (44, 44, 1, 0, 0))[0] == "INCONCLUSIVE"),
        ("one broken audit entry is INCONCLUSIVE too", adjudicate(allpass, (44, 44, 0, 1, 0))[0] == "INCONCLUSIVE"),
        ("an audit with no verdict is INCONCLUSIVE", adjudicate(allpass, None)[0] == "INCONCLUSIVE"),
        ("an audit that did not pass is INCONCLUSIVE, not FAIL",
         adjudicate(allpass, (43, 44, 0, 0, 0))[0] == "INCONCLUSIVE"),
        # The exit status must be the *only* defect here — a tally of (2, 3) would also trip the
        # "fewer cases than it ran" branch below, and this case was masked by it until the audit aimed at
        # the `failed` branch and found the case passing with that branch disabled (M181).
        ("a procedure exiting non-zero with a clean tally is FAIL when the audit is clean",
         adjudicate(allpass + [("c", 1, (3, 3))], clean)[0] == "FAIL"),
        ("a procedure reporting fewer cases than it ran is FAIL",
         adjudicate(allpass + [("c", 0, (2, 3))], clean)[0] == "FAIL"),
    ]
    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} verifier self-test case(s)")
    return 0 if passed == len(cases) else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--full", action="store_true",
                    help="run admission too (the gate audit) — pre-push/nightly, not every commit")
    ap.add_argument("--self-test", action="store_true")
    args = ap.parse_args()
    return self_test() if args.self_test else report(args.json, "full" if args.full else "fast")


if __name__ == "__main__":
    raise SystemExit(main())
