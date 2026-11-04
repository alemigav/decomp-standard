# M127 — a pre-commit hook that runs the acceptance suite

"Keep fixtures green" has been a promise made in commit messages. It is now enforced.

## The hook

`tools/pre-commit.sh`, **versioned in the repository** and installed as a symlink:

```sh
ln -sf ../../tools/pre-commit.sh .git/hooks/pre-commit
```

Versioned because `.git/hooks` is not tracked: a hook that lives only there leaves every fresh clone silently
unprotected, which is worse than no hook because nobody notices. Symlinked so an edit to the tracked file takes
effect immediately, with no reinstall step to forget.

It resolves the repository root with `git rev-parse --show-toplevel` (so it works from any subdirectory), fails
loudly if `python3` is missing, runs `tools/acceptance.py`, and blocks the commit on a non-zero exit while naming
the bypass:

```
pre-commit: acceptance suite FAILED — commit blocked.
  Every fixture must pass before a commit lands (see tools/acceptance.py).
  Deliberate bypass, not recommended: git commit --no-verify
```

Cost is ~20 s — the whole-corpus provenance fixpoint is the slow part, and it is the part worth running.

## Verified end-to-end, not assumed

Temporarily setting the expected case count for the `pad_layout` fixture to 99 and attempting a real commit:

```
pad_layout self-test     8/8        FAIL  EXPECTED 99 CASES, found 8
FAIL pad_layout self-test: 8/8, exit 0

pre-commit: acceptance suite FAILED — commit blocked.
--- HEAD unchanged?
bb7590b M126: pad_layout in a single acceptance suite, and a mixed-errno fixture
```

The commit did not land. With the count restored, the same commit passes and lands. That is the whole chain
exercised: hook → acceptance → suite → git's abort.

## What this does and does not guarantee

* It guarantees that **no commit lands with a red fixture**, including the case-count guard from M126 (a fixture
  that quietly loses cases fails the count, not just the pass/total).
* It does **not** guarantee the tests are good — a fixture that asserts nothing still passes. The guard against
  that is the notes, which record what each case is *for*.
* `--no-verify` exists and is documented. It is the right tool when committing a knowingly-red intermediate
  state; the note asks that the reason be in the commit message.

## State

```
python3 tools/acceptance.py     # 48 cases across 5 fixtures, ~20 s
sh tools/pre-commit.sh          # what the hook runs; exit 0
```

All suites green.
