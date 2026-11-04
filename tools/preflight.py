#!/usr/bin/env python3
"""The cheap tier: every gate defect that can be settled in seconds, settled in seconds.

The full run — `tools/ci.sh` and then the mutation audit — costs minutes, and it is paid for far too
often, because the defects that stop it are *integration* defects and they are cheap ones: a stale count
left in a document after the registry grew, an audit mutation whose source anchor a refactor moved away,
a milestone row whose note is missing. None of those needs an acceptance suite to find, and all of them
have instead been found at the most expensive stage — M207's padding label and M210's `<= CYCLE` were both
anchors that had moved, and each was reported as a BROKEN audit entry minutes into a run that had already
passed every suite.

So this tier runs only the checks that read files, in this order, one child process each:

  python3 tools/counts.py --check            the documented numbers agree with the registry
  python3 tools/check_markers.py             headings and note titles
  python3 tools/milestone_index.py --check   the generated index matches the log, notes and gaps
  python3 tools/ratchet.py --check           the registry has not drifted and `src/` has not moved
  python3 tools/audit_gates.py --lint        every mutation's source anchor still exists, and is unique
  python3 tools/counts.py --self-test        the count gate can still fail

## What this tier may claim, and what it may not

It may claim, and only claim, **that those six facts hold on this tree**. That is the whole of it.

* **A PASS here is NOT admission.** Nothing below decides whether a result is supported. Admission is
  `tools/verify.py` reporting `PASS` *with a clean gate audit* — every check shown to fail when its own
  mechanism is disabled. A green preflight says the cheap defects are absent; it says nothing whatsoever
  about whether any gate can fail. Reading it as evidence for a claim would be the substitution
  `docs/VERIFICATION.md` exists to forbid.
* `audit_gates.py --lint` is **not** the mutation audit. It shows an anchor exists, appears once, and
  changes the text when replaced. It cannot show the mutation still fails *for its intended reason*,
  because that requires running it against a mutated copy. A clean lint is a precondition, not a proof.
* No acceptance suite runs here, so no case count is re-derived from a run, and nothing that needs the
  cartridge is touched. Unexecuted evidence stays unexecuted.
* **A step that could not run is not a step that passed.** It is reported `SKIP` with the reason and it
  leaves the tally, on the same reasoning as the three states in `docs/VERIFICATION.md`. `--skip` removes
  a step from the tally for the same reason: a developer dropping a known-broken step must not be able to
  turn it into a green one.

A step passes only when its exit status is zero **and** its last `N/M` line is whole. The second half
matters: a tool that exits 0 without a verdict asserted nothing, which is the defect this repository
audits most often, and a wrapper that accepted it would be the `"FAIL" in output` of M181 again.

  ./preflight.py                          # every step, in this order
  ./preflight.py --quiet                  # failures and the tally only
  ./preflight.py --skip ratchet           # drop a step that is known-broken while working on it
  ./preflight.py --skip "audit anchors"   # names are matched loosely: audit-anchors works too
  ./preflight.py --self-test              # prove the wrapper cannot lie about a child
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

# (name, command, what it covers). The name is what `--skip` takes and what a report quotes, so it is
# the tool's job in a few words rather than the file it lives in.
STEPS = [
    ("counts", [sys.executable, "tools/counts.py", "--check"],
     "the numbers quoted in the docs still agree with the registry"),
    ("markers", [sys.executable, "tools/check_markers.py"],
     "headings and note titles"),
    ("milestone index", [sys.executable, "tools/milestone_index.py", "--check"],
     "the generated index matches the log, the notes and the gaps"),
    ("ratchet", [sys.executable, "tools/ratchet.py", "--check"],
     "the registry has not drifted and src/ has not moved"),
    ("audit anchors", [sys.executable, "tools/audit_gates.py", "--lint"],
     "every mutation's source anchor still exists and is unique"),
    ("counts self-test", [sys.executable, "tools/counts.py", "--self-test"],
     "the count gate can still fail"),
    ("sound fixtures", [sys.executable, "tools/sound_fixtures.py", "--check"],
     "the committed sound artefacts are internally consistent and unedited by hand"),
]

# The same rule `acceptance.py` and `verify.py` use: the last `N/M` line is a tool's verdict.
COUNT = re.compile(r"^(\d+)\s*/\s*(\d+)")
FAILMARK = re.compile(r"\bFAIL\b|\bVACUOUS\b|\bBROKEN\b|\bError\b|Traceback")
# A tool that has not grown the mode yet answers argparse, not a verdict, and exits 2. That is a fact
# about the tool rather than about the tree, so it is a SKIP with the flag named — never a pass.
NO_MODE = re.compile(r"unrecognized arguments|no such option|invalid choice")
FLAG = re.compile(r"--[a-z][\w-]*")


def key(name):
    """A step's name, normalised, so `--skip milestone-index` and `--skip "milestone index"` agree."""
    return re.sub(r"[^a-z0-9]+", "-", name.lower()).strip("-")


def verdict_of(text):
    """The last `N/M` line, or None — the same rule every tool in this repository prints by."""
    for line in reversed(text.splitlines()):
        m = COUNT.match(line.strip())
        if m:
            return int(m.group(1)), int(m.group(2))
    return None


def failing_line(text, code):
    """The first line that looks like the child's own failure, so the report quotes it rather than
    paraphrasing it. A child that printed nothing gets its exit status, because "died silently" is exactly
    the case a wrapper must not smooth over."""
    lines = [l.strip() for l in text.splitlines() if l.strip()]
    for line in lines:
        if FAILMARK.search(line):
            return line
    if lines:
        return lines[-1]
    return f"died with exit {code} and printed nothing"


def tool_of(cmd):
    """The tool a step runs, for messages that should name it rather than the interpreter."""
    for part in cmd:
        if str(part).endswith((".py", ".sh")):
            return Path(str(part)).name
    return Path(str(cmd[0])).name if cmd else "the tool"


def unsupported(cmd, text, code):
    """The reason this step's mode does not exist yet, or None.

    Deliberately narrow: the flag has to be the one this step passes *and* argparse has to be the one
    complaining. Any other exit 2 is a real failure and must not be excused as a SKIP.
    """
    if code != 2:
        return None
    hit = next((l.strip() for l in text.splitlines() if NO_MODE.search(l)), None)
    if hit is None:
        return None
    flag = next((a for a in cmd if str(a).startswith("--")), None)
    flag = flag or (FLAG.search(hit).group(0) if FLAG.search(hit) else "")
    if flag and flag not in hit:
        return None
    return f"{tool_of(cmd)} has no {flag or 'requested'} mode yet — {hit}"


def run_step(name, cmd, root):
    """-> (state, detail). One child, one verdict, in that order: PASS, FAIL, or SKIP with its reason."""
    proc = subprocess.run([str(c) for c in cmd], cwd=str(root), capture_output=True, text=True)
    text = (proc.stdout or "") + (proc.stderr or "")
    code = proc.returncode

    why = unsupported(cmd, text, code)
    if why is not None:
        return "SKIP", why

    if code != 0:
        return "FAIL", failing_line(text, code)

    got = verdict_of(text)
    if got is None:
        # not a pass: a check that printed no verdict has not been shown to have checked anything
        return "FAIL", "exited 0 with no N/M verdict, so it asserted nothing"
    passed, total = got
    if passed != total:
        return "FAIL", failing_line(text, code)
    return "PASS", f"{passed}/{total}"


def sweep(steps, root, dropped=()):
    """Run each step in order. -> (results, ran, skipped).

    `ran` is the tally's denominator: a step that was dropped or that could not run is not in it, because
    counting an unrun step as a step that passed is the error this file's contract forbids.
    """
    results, ran, skipped = [], 0, 0
    for name, cmd, _covers in steps:
        if key(name) in dropped:
            skipped += 1
            continue
        state, detail = run_step(name, cmd, root)
        results.append((name, state, detail))
        if state == "SKIP":
            skipped += 1
        else:
            ran += 1
    return results, ran, skipped


def report(results, ran, skipped, quiet=False):
    """-> (lines, status). Pure, so `--self-test` grades what would be printed instead of the printing."""
    lines = []
    bad = 0
    for name, state, detail in results:
        if state == "PASS":
            if not quiet:
                lines.append(f"PASS {name} ({detail})")
        elif state == "SKIP":
            if not quiet:
                lines.append(f"SKIP {name} — {detail}")
        else:
            bad += 1
            lines.append(f"FAIL {name} — {detail}")
    if ran == 0:
        # 0/0 is not a green run: with nothing left to run there is nothing that was checked.
        lines.append("no step ran — a preflight that checks nothing is not a pass, even with every step "
                     "skipped on purpose")
    tail = f", {skipped} skipped (not counted)" if skipped else ""
    lines.append(f"{ran - bad}/{ran} preflight step(s){tail}")
    return lines, (1 if bad or ran == 0 else 0)


def self_test() -> int:
    """Grade the wrapper on children of one line each, so it cannot lie in any of the three ways that
    matter: reporting a failing child PASS, passing a child that died silently, or counting a dropped step
    as one that passed. Nothing here touches the real tools, whose own state is not the question."""
    green = ["sh", "-c", "echo '  ok    a comparison held'; echo 2/2"]
    red = ["sh", "-c", "echo '  FAIL the comparison never ran'; echo 1/2"]
    dead = ["sh", "-c", "exit 3"]                      # dies with no output at all
    mute = ["sh", "-c", "echo nothing to report"]      # exits 0 having asserted nothing
    nomode = [sys.executable, "-c",
              "import sys; sys.stderr.write('error: unrecognized arguments: --lint\\n'); sys.exit(2)"]
    one = [("a", green, "")]
    two = [("a", green, ""), ("b", green, "")]
    tmp = Path(tempfile.mkdtemp())
    cases = []
    try:
        res, ran, sk = sweep(one, tmp)
        lines, status = report(res, ran, sk)
        cases.append(("a passing child is PASS, and the run exits 0",
                      res[0][1] == "PASS" and res[0][2] == "2/2" and status == 0
                      and lines[-1] == "1/1 preflight step(s)"))

        res, ran, sk = sweep([("a", green, ""), ("b", red, "")], tmp)
        lines, status = report(res, ran, sk)
        cases.append(("a failing child is FAIL, the report quotes the child's own failing line, and the "
                      "exit status changes",
                      res[1][1] == "FAIL" and "comparison never ran" in res[1][2] and status == 1
                      and any(l.startswith("FAIL b — ") for l in lines)
                      and lines[-1].startswith("1/2 preflight")))

        res, ran, sk = sweep([("a", dead, "")], tmp)
        lines, status = report(res, ran, sk)
        cases.append(("a child that dies without output is a FAIL, not a silent pass",
                      res[0][1] == "FAIL" and status == 1 and "printed nothing" in res[0][2]))

        res, ran, sk = sweep([("a", mute, "")], tmp)
        lines, status = report(res, ran, sk)
        cases.append(("a child that exits 0 without an N/M verdict is a FAIL, not a vacuous pass",
                      res[0][1] == "FAIL" and status == 1 and "asserted nothing" in res[0][2]))

        res, ran, sk = sweep(two, tmp, dropped={key("a")})
        lines, status = report(res, ran, sk)
        cases.append(("--skip removes the step from the tally rather than reporting it as passed",
                      sk == 1 and ran == 1 and status == 0
                      and not any(l.startswith("PASS a") for l in lines)
                      and lines[-1] == "1/1 preflight step(s), 1 skipped (not counted)"))

        res, ran, sk = sweep([("a", nomode, "")], tmp)
        lines, status = report(res, ran, sk)
        cases.append(("a mode the tool has not grown yet is SKIP with the flag named, and is not counted",
                      res[0][1] == "SKIP" and "--lint" in res[0][2] and sk == 1 and ran == 0 and status == 1
                      and lines[0].startswith("SKIP a — ")))
    finally:
        shutil.rmtree(tmp, ignore_errors=True)

    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} preflight self-test case(s)")
    return 0 if passed == len(cases) else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--quiet", action="store_true", help="only failures and the tally")
    ap.add_argument("--skip", action="append", default=[], metavar="NAME",
                    help="drop a step by name (repeatable); it leaves the tally rather than passing")
    ap.add_argument("--self-test", action="store_true")
    args = ap.parse_args()
    if args.self_test:
        return self_test()

    known = {key(n): n for n, _c, _w in STEPS}
    dropped = set()
    for raw in args.skip:
        k = key(raw)
        if k not in known:
            # a typo must not look like a skip: the step would run, and the developer would read the
            # failure as something they had already excused
            print(f"unknown --skip name {raw!r}; the steps are:", file=sys.stderr)
            for n, _c, w in STEPS:
                print(f"  {n:20s} {w}", file=sys.stderr)
            return 2
        dropped.add(k)

    results, ran, skipped = sweep(STEPS, ROOT, dropped)
    lines, status = report(results, ran, skipped, args.quiet)
    for line in lines:
        print(line)
    return status


if __name__ == "__main__":
    raise SystemExit(main())
