# M175 — the self-hosted tier: all 230 cases in CI without uploading the cartridge

The question was whether a repository secret could feed the ROM to CI so the last 103 cases run there. The
answer is **no**, and the measurement is the reason: GitHub caps an Actions secret at **48 KB**, and the
cartridge is **67 108 864 B** — **89 478 489 B** once base64-encoded, i.e. roughly **1 870 secrets** at the
cap. M130's `RE2_CART_B64` step could never have worked; it was written, verified only against a local
base64 in a scratch clone, and removed in `10f4dc3` (*"no ROM secret — keep the 51/54 split"*). The policy
objection stands too, and is unchanged: encrypted or chunked, a secret is still a copy of a copyrighted ROM
in someone else's infrastructure.

So the coverage comes from where the bytes already are.

## 1. A second job, on a runner that holds the cartridge

`.github/workflows/acceptance.yml` now has two jobs:

| job | runner | suites | cases |
|---|---|---|---|
| `ci` | `ubuntu-22.04` (GitHub-hosted) | 10 of 21 | 127 of 230 |
| `full` | `[self-hosted, re2-cartridge]` | **21 of 21** | **230 of 230** |

Nothing is uploaded, nothing is in a secret, and the hosted job still runs on every push, so a repo with no
runner online behaves exactly as before.

## 2. The two guards, because a self-hosted job fails differently

A self-hosted job would be quietly useless in two ways that a hosted one cannot be, so both are closed and
each was **verified to fire** rather than assumed:

1. **It would queue, not fail.** With `runs-on: [self-hosted]` and no runner online, every push leaves a job
   *queued* until the six-hour default. So the job is gated:
   ```yaml
   if: vars.SELF_HOSTED_RUNNER == 'true'
   ```
   Skipped is visible in the run list; queued is just yellow. Enabling is one command
   (`gh variable set SELF_HOSTED_RUNNER --body true`), and the label `re2-cartridge` means a stray runner
   cannot pick the job up.
2. **It would pass without the cartridge.** A runner with a stale checkout would run the *hosted* tier — 127
   cases, 11 suites SKIP — and report green. So the job fails if `rom/*.z64`, `build/elfs` or
   `assets/unpacked` is missing, and then fails again if the log contains a SKIP line:

   ```
   $ bash /tmp/g.sh        # with the cartridge:   all 21 runnable suite(s) pass (230 cases)   → exit 0
   $ bash /tmp/g.sh        # cartridge-less log:   the cartridge suites still skipped — …    → exit 1
   $ bash /tmp/full2.sh    # cartridge-less tree:  no cartridge at rom/*.z64 — …             → exit 1
   ```

Both properties are now **lint cases**, so an edit that removes either one fails `tools/workflow_lint.py`
(now **13 cases**): *a self-hosted job is gated by a repository variable* and *a self-hosted job refuses to
pass when suites were skipped*.

## 3. What the shipped file cannot prove

The `full` job has not run: no self-hosted runner is registered yet, and the job is therefore **skipped** on
every push — which is the intended state until someone enables it. What *is* verified is every part that can
be verified here: the YAML parses, the lint passes, both guard scripts were executed in both directions, and
the cartridge-present path was measured locally (21 suites / 230 cases, `ci: ok`).

## 4. The counts, once more, measured

Adding the two lint cases moved the totals, so every place that states them moved with it — this time by
reading the run, not by arithmetic:

* local, cartridge present: **21 suites / 230 cases**
* GitHub-hosted runner: **10 suites / 127 cases**, 11 suites / 103 cases SKIP

```
python3 tools/workflow_lint.py      # 13/13 — including the two self-hosted guards
sh tools/ci.sh                      # ci: ok, 21 suites / 230 cases
```

Enabling the tier is documented in `docs/handover.md` under *How "green" is enforced*: register the runner
with the `re2-cartridge` label against a checkout that has the cartridge, then set the variable.
