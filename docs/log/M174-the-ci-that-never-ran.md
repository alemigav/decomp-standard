# M174 — the runner CI that never ran, the suite that would have gone red, and the two mistakes I made finding them

The ask was "add a CI workflow that runs the test suite on every push". The repo already had one — since
M128 — and it had **never been scheduled a single time**, for two independent reasons. This note records
the repair, the two defects that repair uncovered, and the two things I got wrong on the way.

## 1. The workflow was invalid YAML, so GitHub never accepted it

`.github/workflows/acceptance.yml` carried this line:

```yaml
      - name: Report what CI can and cannot see
        run: printf 'ROM present: %s\n' "$(test -f 'rom/…' && echo yes || echo no)"
```

`run:` takes a **plain scalar** here, and a plain scalar cannot contain `: `. Every YAML parser rejects the
file at that line — `psych` reports *"mapping values are not allowed in this context at line 32 column 33"*.
GitHub answers such a push with **"Invalid workflow file"** and schedules nothing, so the workflow's own
header claims ("51 of the 54 cases") were never exercised, and M130's rewrite of the same header inherited
the claim. A file whose only reader is a remote service is **unverified** until something local parses it;
that is the whole finding, one line of YAML wide.

Fixed with a block scalar. The file now parses (`ruby -ryaml`, 5 steps, `runs-on: ubuntu-latest`,
`timeout-minutes: 20`), and got `permissions: contents: read`, a `concurrency` group, and a pinned
interpreter (`3.9`, the one the suites are verified on) rather than a floating `3.x`.

## 2. The suite labelled "synthetic" was not cartridge-free, so the first push would have been red

`tools/acceptance.py` marked `synthetic-rdram walk` as `needs_cart=False`. It runs
`tools/rdram_fixture.py`, which builds its memory synthetically but then **shells out to `walk_stream.py`,
which loads `assets/unpacked/00000_0014420_1172240.bin`** — an unpacked cartridge member:

```
FileNotFoundError: … 'assets/unpacked/00000_0014420_1172240.bin'
0/7 synthetic-rdram walk case(s)
```

Green locally, red on any fresh clone. It is measured, not argued: a tracked-files-only tree
(`git archive HEAD | tar -x`) reproduces the runner exactly, and before the fix `sh tools/ci.sh` there
ended `ci: FAILED`. The flag is now `True`, so the suite reports SKIP like the other cartridge suites.

That measurement also replaced every estimated number in the CI prose — locally and on a runner:

| where | suites | cases |
|---|---|---|
| local, cartridge present | **21 / 21** | **230 / 230** |
| runner, no cartridge | **10 / 21 run** | **127 / 230**, 11 suites / 103 cases SKIP |

Both figures are asserted by `tools/acceptance.py`'s expected counts, so the prose goes stale loudly. The
job summary now prints the split too, because a green run that silently skipped 11 suites is a misleading
green.

## 3. CI cannot test the file that makes CI run — so `tools/workflow_lint.py` does

This is the general form of §1: an invalid workflow is *never scheduled*, so the failure has no reporter.
The new suite needs no cartridge, which means **a runner checks its own definition on the next push**:

| case | what it stops |
|---|---|
| `name`/`on`/`jobs` at column 0 | a file that is not a workflow |
| no plain scalar contains `': '` | **the exact defect above** |
| every `uses:` pins a ref | a floating `@main` that changes under you |
| `runs-on` and `timeout-minutes` | a job that can hold the slot for hours |
| a step runs `tools/ci.sh` or `tools/acceptance.py` | a workflow that proves nothing |
| `permissions: contents: read` | a token wider than its job |

Five synthetic fixtures prove the linter can fail, one of them a verbatim copy of the broken line. It is a
gate, so it is audited: `audit_gates.py` is now **20/20, 0 vacuous**.

## 4. Two mistakes of mine, recorded rather than tidied away

1. **I wrote a duplicate workflow.** Asked for "a CI workflow", I wrote `.github/workflows/ci.yml` without
   looking — and my earlier `ls` of the repo root had hidden `.github`, because it is a dotfile. The
   workflow has existed since M128. I deleted mine. The mistake is worth more than an apology: the check
   is `git ls-files .github` or `find .github -type f`, not `ls`.
2. **My first audit of the new linter was vacuous.** `audit_gates.py` builds a throw-away environment from
   `tools/`, `fixtures/`, `docs/log/` — **not** `.github/` — so the mutated linter failed on a *missing
   directory*, not on its mutation. The detail line in the audit output gave it away
   (`FAIL the repository has at least one workflow — .github/workflows is empty`). `.github` is copied in
   now, and the audit fails for the right reason (`FAIL the line that was actually broken is caught`). This
   is the third time this arc that an audit environment omitted a dependency — `build/elfs` and `src` were
   the first two.

## 5. What a green run still does not cover

The 11 skipped suites are the ones that assert facts about RE2 itself: the corpus checks, the script VM,
the model container, the T64 texture law, the exception path, the routine-index bounds (M173). They run
wherever the cartridge exists — locally, and in the pre-commit hook — and M130's ROM-as-secret route stays
deliberately unadopted. **A green CI run does not vouch for those 103 cases**, and the handover now says so
with the measured numbers instead of the old `51 of 54`.

## 6. The first real run failed, on the interpreter — which is the check working

The workflow was scheduled for the first time in this project's history and failed in 9 s:

```
##[error]The version '3.9' with architecture 'x64' was not found for Ubuntu 26.04.
```

`ubuntu-latest` had moved to **26.04**, which carries no Python 3.9 build. The pin was right and the *image*
was not: `runs-on` is now **`ubuntu-22.04`**, chosen because 3.9.6 is the only interpreter installed on the
machine the suites are verified on, and an interpreter nobody ran is not one to claim. This is the argument
for having the workflow at all: two milestones of prose asserted a runner run that had never happened, and
the first real one found a break in nine seconds.

## 7. Addendum: the sanctioned edit path was dropping file modes

Committing this milestone turned up a defect in the tool every edit in this repo goes through.
`tools/patch_text.py` writes each file by writing a **new** temporary file and calling `replace()` — which
installs a *new inode*, so the original's mode goes with the old one. The commit recorded it plainly:

```
mode change 100755 => 100644 tools/ci.sh
```

Harmless for `ci.sh` (always run as `sh tools/ci.sh`), and **not** harmless for `tools/pre-commit.sh`,
which the hook executes directly: one patch to it and the commit hook silently stops running. The fix is
one line (`shutil.copymode`), the self-test grew a case that patches an executable file and requires the
bit to survive (**8/8**), and that case is audited — removing the `copymode` call fails it, so
`audit_gates.py` is now **20/20, 0 vacuous**.

The general form is worth keeping: *a tool that rewrites a file is responsible for everything about the
file that is not its text.*

```
python3 tools/workflow_lint.py        # 11/11 — CI checking its own definition
python3 tools/acceptance.py           # 21 suites, 230 cases
python3 tools/audit_gates.py          # 20/20, 0 vacuous
sh tools/ci.sh                        # ci: ok
```
