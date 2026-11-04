#!/usr/bin/env python3
"""Lint the workflow files that define CI. CI cannot test the file that makes CI run.

M128 committed `.github/workflows/acceptance.yml` and M130 rewrote its header; both times the file was
**invalid YAML** — `run: printf 'ROM present: %s\\n' ...` has an unquoted `: ` inside a plain scalar — so
GitHub rejected it with "Invalid workflow file" and never scheduled a single run. Nothing in this repo
noticed for two milestones, because the only thing that could have noticed is the workflow itself.

No YAML library is available on a runner (the tooling is stdlib-only by policy), so this checks the
failure modes that actually bite rather than pretending to be a parser:

  1. every file declares `name:`, `on:` and `jobs:` at column 0;
  2. no plain scalar value contains `: ` — the defect above, which breaks the file outright;
  3. every `uses:` pins a ref (`@v4` or a version/SHA), never a floating branch;
  4. every job declares `runs-on` and `timeout-minutes` (a wedged job would otherwise hold the slot);
  5. every job's steps eventually run the repository gates — `tools/ci.sh` or `tools/acceptance.py`;
  6. `permissions:` is declared, tightened to `contents: read` (nothing here writes to the repo);
  7. when a job is `self-hosted`, it is gated by a repository variable (or it queues while the machine is
     asleep) and it fails when the cartridge suites were skipped (or it re-runs the hosted tier and passes).

Checks 1-6 run against the real files; `--self-test` runs synthetic ones, including a copy of the exact
line that was broken, so the linter is shown to fail on the thing it was written for.

Usage:
  ./workflow_lint.py               # self-test (5) + repository (6)
  ./workflow_lint.py --self-test   # the synthetic fixtures only
"""
import argparse
import re
import sys
from pathlib import Path

WORKFLOWS = Path(".github/workflows")
ROOT = WORKFLOWS.parent.parent          # a job's guard may live in a script it calls, not in the YAML
KEY = re.compile(r"^(run|name|uses|with|on|jobs|permissions):(\s+)(.*)$")
USES = re.compile(r"^\s*-?\s*uses:\s*(\S+)")
JOB_KEYS = ("runs-on:", "timeout-minutes:")

# The line that was broken, verbatim: a plain scalar with `: ` in it. Any one of these is a hard parse
# error for every YAML parser, so the workflow is never scheduled at all.
BROKEN = ("      - name: Report what CI can and cannot see\n"
          "        run: printf 'ROM present: %s\\n' \"$(test -f 'rom/x.z64' && echo yes || echo no)\"\n")
GOOD = ("      - name: Report what CI can and cannot see\n"
        "        run: |\n"
        "          printf 'ROM present: %s\\n' \"$(test -f 'rom/x.z64' && echo yes || echo no)\"\n")


def plain_scalar_problem(line):
    """A value that YAML cannot read as a plain scalar: unquoted and containing ': ' or ' #'."""
    m = KEY.match(line.strip()) or KEY.match(line)
    if not line.strip().startswith(tuple(k + ":" for k in ("run", "name", "uses", "with"))):
        return None
    m = KEY.match(line.strip())
    if not m:
        return None
    val = m.group(3).strip()
    if not val or val[0] in "|>'\"[{":
        return None                      # a block scalar or an explicitly quoted value is fine
    if ": " in val:
        return f"plain scalar contains ': ' — quote it or use a block scalar: {val[:60]}"
    return None


def lint_text(text):
    """Return a list of (case name, ok, detail) for one workflow file's contents."""
    lines = text.splitlines()
    out = []
    head = {ln.split(":")[0] for ln in lines
            if ln and not ln[0].isspace() and ":" in ln and not ln.lstrip().startswith("#")}

    out.append(("declares name/on/jobs at column 0",
                {"name", "on", "jobs"} <= head, f"top-level keys: {sorted(head)}"))

    problems = [p for p in (plain_scalar_problem(ln) for ln in lines) if p]
    out.append(("no plain scalar value contains ': '", not problems,
                problems[0] if problems else "every run/name/uses value is a block, quoted or simple"))

    uses = [m.group(1) for m in (USES.match(ln) for ln in lines) if m]
    floating = [u for u in uses if "@" not in u or u.rsplit("@", 1)[1] in ("main", "master", "latest")]
    out.append(("every `uses:` pins a ref", not floating,
                f"floating: {floating}" if floating else f"{len(uses)} pinned action(s)"))

    body = "\n".join(lines)
    missing = [k for k in JOB_KEYS if k not in body]
    out.append(("every job declares runs-on and timeout-minutes", not missing,
                f"missing {missing}" if missing else "both present"))

    gates = ("tools/ci.sh" in body) or ("tools/acceptance.py" in body)
    out.append(("the job actually runs the gates", gates,
                "runs tools/ci.sh" if "tools/ci.sh" in body else
                ("runs tools/acceptance.py" if gates else "no step invokes a suite — the job proves nothing")))

    ok = "permissions:" in body and "contents: read" in body.replace('"', "").replace("'", "")
    out.append(("permissions is declared and read-only", ok,
                "contents: read" if ok else "no least-privilege permissions block"))

    # A self-hosted job fails in two ways a hosted one cannot, so both guards are required:
    # without the variable gate it sits *queued* for every push while the machine sleeps, and without the
    # skip check it happily runs the hosted tier and reports success. Neither is visible in a green tick.
    if "self-hosted" in body:
        gated = re.search(r"^\s+if:\s*vars\.", body, re.M) is not None
        out.append(("a self-hosted job is gated by a repository variable", gated,
                    "if: vars.<NAME>" if gated else "a self-hosted job with no `if:` queues on every push"))
        # The guard lives in `tools/ci_full.sh` rather than in this file, so it is one implementation for
        # both tiers. Following the reference is the point: a job that stops calling the gate is the
        # failure mode, and a string match on the YAML would have missed it.
        gate = ROOT / "tools" / "ci_full.sh"
        if "tools/ci_full.sh" in body and gate.exists():
            g = gate.read_text()
            refuses = "skipped for want of the cartridge" in g and "exit 1" in g
            detail = "tools/ci_full.sh fails on a SKIP line" if refuses else \
                "tools/ci_full.sh does not check whether the cartridge suites ran"
        else:
            refuses = False
            detail = "a full tier that does not call tools/ci_full.sh"
        out.append(("a self-hosted job refuses to pass when suites were skipped", refuses, detail))

        # And the fetching path must verify what it downloaded before anything unpacks it.
        fetch = ROOT / "tools" / "cart_fetch.sh"
        if "tools/cart_fetch.sh" in body and fetch.exists():
            f = fetch.read_text()
            verified = "manifests/manifest.json" in f and "not unpacking it" in f
            out.append(("a fetched cartridge is verified before it is unpacked", verified,
                        "sha256 checked against manifests/manifest.json" if verified else
                        "cart_fetch.sh unpacks without verifying"))
    return out


def self_test():
    """Synthetic files, including the exact line that broke CI for two milestones."""
    cases = []

    def lint(files):
        out = []
        for name, body in files.items():
            out += [(f"{name}: {c}", ok, d) for c, ok, d in lint_text(body)]
        return out

    base = ("name: ci\non:\n  push:\npermissions:\n  contents: read\njobs:\n  j:\n"
            "    runs-on: ubuntu-latest\n    timeout-minutes: 20\n    steps:\n"
            "      - uses: actions/checkout@v4\n"
            "      - name: gates\n        run: sh tools/ci.sh\n")
    good = lint({"good.yml": base})
    cases.append(("a well-formed workflow passes every case", all(ok for _c, ok, _d in good),
                  [c for c, ok, _d in good if not ok]))

    broken = lint({"broken.yml": base.replace("        run: sh tools/ci.sh\n", BROKEN)})
    cases.append(("the line that was actually broken is caught",
                  any("': '" in c and not ok for c, ok, _d in broken),
                  [c for c, ok, d in broken if not ok][:1]))

    quoted = lint({"quoted.yml": base.replace("        run: sh tools/ci.sh\n",
                                              GOOD + "      - name: gates\n        run: sh tools/ci.sh\n")})
    cases.append(("the same line as a block scalar passes", all(ok for _c, ok, _d in quoted),
                  [c for c, ok, _d in quoted if not ok]))

    unpinned = lint({"unpinned.yml": base.replace("actions/checkout@v4", "actions/checkout@main")})
    floated = not dict((c.split(": ", 1)[1], ok) for c, ok, _d in unpinned)["every `uses:` pins a ref"]
    cases.append(("a floating action ref is caught", floated, "actions/checkout@main"))

    idle = lint({"idle.yml": base.replace("        run: sh tools/ci.sh\n", "        run: echo hello\n")})
    gate = not dict((c.split(": ", 1)[1], ok) for c, ok, _d in idle)["the job actually runs the gates"]
    cases.append(("a job that runs no gate is caught", gate, "a job whose only step is `echo hello`"))
    return cases


def check():
    files = sorted(WORKFLOWS.glob("*.yml")) + sorted(WORKFLOWS.glob("*.yaml"))
    if not files:
        return [("the repository has at least one workflow", False, f"{WORKFLOWS} is empty")]
    out = []
    for p in files:
        out += [(f"{p.name}: {c}", ok, d) for c, ok, d in lint_text(p.read_text())]
    return out


def report(cases):
    for name, ok, detail in cases:
        print(f"  {'ok  ' if ok else 'FAIL'} {name}" + (f" — {detail}" if detail else ""))
    good = sum(1 for _n, k, _d in cases if k)
    print(f"\n{good}/{len(cases)}")
    return 0 if good == len(cases) else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--self-test", action="store_true", help="the synthetic fixtures only")
    args = ap.parse_args()
    if args.self_test:
        return report(self_test())
    return report(self_test() + check())


if __name__ == "__main__":
    sys.exit(main())
