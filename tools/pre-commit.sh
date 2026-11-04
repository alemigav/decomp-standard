#!/bin/sh
# Pre-commit hook: block a commit unless every fixture passes.
#
# Versioned here rather than living only in .git/hooks (which git does not track, so a fresh clone would
# silently have no hook). Install it once, per clone:
#
#     ln -sf ../../tools/pre-commit.sh .git/hooks/pre-commit
#
# A symlink is used so that editing this file takes effect immediately, with no reinstall.
#
# Cost: ~5 min as measured at M195 — the gate audit alone is 3m37s, because six of its cases each
# re-run the 31 s `file_table.py --check`. The suite is run with `-u` so the commit streams its
# progress instead of showing nothing for five minutes. To skip it in an emergency,
# `git commit --no-verify` — and say why in the commit message when you do.
set -u

root=$(git rev-parse --show-toplevel 2>/dev/null) || {
	printf 'pre-commit: not inside a git work tree\n' >&2
	exit 1
}
cd "$root" || exit 1

if ! command -v python3 >/dev/null 2>&1; then
	printf 'pre-commit: python3 not found; cannot run the acceptance suite\n' >&2
	exit 1
fi

# M210 policy: a certificate from `verify.py` for *this exact worktree* means the suite has just been run
# on the tree being committed, so re-running it would only cost five minutes. Anything else -- no
# certificate, a different tree, a FAIL, a vacuous admission -- runs the suite as before.
if python3 tools/hook_cert.py --valid >/dev/null 2>&1; then
	python3 tools/hook_cert.py --valid
	printf 'pre-commit: certified by tools/verify.py on this worktree — suite not re-run.\n'
	exit 0
fi

if ! python3 -u tools/acceptance.py; then
	printf '\n'
	printf 'pre-commit: acceptance suite FAILED — commit blocked.\n'
	printf '  Every fixture must pass before a commit lands (see tools/acceptance.py).\n'
	printf '  Deliberate bypass, not recommended: git commit --no-verify\n'
	exit 1
fi

exit 0
