#!/bin/sh
# The full tier: run every suite, and *fail* if any suite was skipped for want of the cartridge.
#
# Both ways of covering the cartridge in CI end here — the self-hosted runner that already holds it, and
# the hosted runner that fetched it from an owner-provided URL (`tools/cart_fetch.sh`). Keeping the guard
# in one script means the two cannot drift, and it means the guard is a file that can be run and tested
# rather than a snippet buried in YAML.
#
# Why it fails instead of passing with skips: a runner with a stale or missing checkout runs the *hosted*
# tier (127 of 230 cases, 11 suites SKIP) and would report green. That is the one result this tier must
# never produce, so a SKIP line is a failure.
#
# Usage:
#   ./ci_full.sh              # require, run, verify nothing skipped
#   ./ci_full.sh --self-test  # the guard, on synthetic logs
set -u

# The guard, factored out so `--self-test` can prove it fires in both directions. A log with a SKIP line is
# a failure; so is a log with no coverage line at all (the silent case: a crash that printed nothing).
verify_no_skips() {
	log=$1
	if grep -q 'skipped for want of the cartridge' "$log"; then
		return 1
	fi
	grep -qE '^all [0-9]+ runnable suite\(s\) pass' "$log"
}

if [ "${1:-}" = "--self-test" ]; then
	tmp=$(mktemp -d)
	trap 'rm -rf "$tmp"' EXIT
	pass=0
	total=0

	printf 'all 21 runnable suite(s) pass (230 cases)\n' > "$tmp/clean.log"
	total=$((total + 1))
	if verify_no_skips "$tmp/clean.log"; then
		printf 'PASS  a log with full coverage is accepted\n'
		pass=$((pass + 1))
	else
		printf 'FAIL  a log with full coverage is accepted\n'
	fi

	printf 'all 10 runnable suite(s) pass (127 cases); 11 skipped for want of the cartridge\n' > "$tmp/skipped.log"
	total=$((total + 1))
	if verify_no_skips "$tmp/skipped.log"; then
		printf 'FAIL  a log with skipped suites is refused\n'
	else
		printf 'PASS  a log with skipped suites is refused\n'
		pass=$((pass + 1))
	fi

	printf 'something unexpected happened\n' > "$tmp/silent.log"
	total=$((total + 1))
	if verify_no_skips "$tmp/silent.log"; then
		printf 'FAIL  a log with no coverage line is refused\n'
	else
		printf 'PASS  a log with no coverage line is refused\n'
		pass=$((pass + 1))
	fi

	printf '\n%d/%d full-tier case(s)\n' "$pass" "$total"
	[ "$pass" -eq "$total" ]
	exit $?
fi

root=$(git rev-parse --show-toplevel 2>/dev/null) || {
	printf 'ci_full: not inside a git work tree\n' >&2
	exit 1
}
cd "$root" || exit 1
status=0

printf '== the cartridge this tier exists to use\n'
rom=$(ls rom/*.z64 2>/dev/null | head -1)
if [ -z "$rom" ]; then
	printf 'FAIL no cartridge at rom/*.z64 — this tier needs it, and it is never committed.\n' >&2
	printf '     See docs/handover.md, "How to rebuild", or fetch it with tools/cart_fetch.sh.\n' >&2
	exit 1
fi
printf '%s (%s bytes)\n' "$rom" "$(wc -c < "$rom" | tr -d ' ')"

for need in build/elfs assets/unpacked; do
	if [ ! -d "$need" ]; then
		printf 'FAIL no %s — run the rebuild first (docs/handover.md), or use tools/cart_fetch.sh.\n' "$need" >&2
		exit 1
	fi
done

printf '\n== every suite\n'
log=$(mktemp)
if ! sh tools/ci.sh 2>&1 | tee "$log"; then
	printf 'ci_full: tools/ci.sh failed\n' >&2
	status=1
fi

printf '\n== nothing may have been skipped\n'
if grep -q 'skipped for want of the cartridge' "$log"; then
	printf 'FAIL the cartridge suites still skipped — this tier did not do its job:\n' >&2
	grep -E 'SKIP' "$log" >&2 || true
	status=1
elif ! verify_no_skips "$log"; then
	printf 'FAIL no coverage line in the log — cannot tell what ran\n' >&2
	status=1
else
	grep -E '^all [0-9]+ runnable suite\(s\) pass' "$log"
fi
rm -f "$log"

if [ "$status" -eq 0 ]; then
	printf '\nci_full: ok — every suite ran, none skipped\n'
else
	printf '\nci_full: FAILED\n'
fi
exit "$status"
