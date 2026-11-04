#!/bin/sh
# Continuous integration, runnable locally: `sh tools/ci.sh`.
#
# Three checks, in the order that fails fastest and most informatively:
#   1. every fixture, via tools/acceptance.py (same suite the pre-commit hook runs)
#   2. nothing that must stay out of git is tracked (ROM, extracted assets, builds, binaries)
#   3. the cartridge, when present, still hashes to the value the manifests were built from
#
# The cartridge is gitignored by design, so a fresh clone cannot supply it: check 3 reports SKIP and the
# cartridge-dependent suites in check 1 report SKIP too. CI is therefore meaningful without the ROM —
# 32 of 73 suites, 286 of 1028 cases — and strictly stronger with it. Exit status is non-zero on any real
# failure. Both figures are asserted by `tools/counts.py`, which is why they are written on one line.
set -u

root=$(git rev-parse --show-toplevel 2>/dev/null) || {
	printf 'ci: not inside a git work tree\n' >&2
	exit 1
}
cd "$root" || exit 1
status=0

printf '== fixtures\n'
python3 tools/acceptance.py "$@" || status=1

printf '\n== tracked artefacts\n'
# `fixtures/` is exempt: fixtures/corpus/cart.z64 is a synthetic 8 KiB file committed so CI can run the corpus
# pipeline (M129), not cartridge data. Its size is bounded below so the exemption cannot smuggle a real ROM in.
bad=$(git ls-files | grep -E '^(rom|assets|build)/|\.(z64|n64|bin|elf)$' | grep -v '^fixtures/' || true)
if [ -n "$bad" ]; then
	printf 'FAIL these must not be tracked:\n%s\n' "$bad"
	status=1
else
	printf 'none (ok)\n'
fi

# That scan matches paths and extensions, so it cannot catch a renamed dump (`rom/x.dat`) or anything at all
# under `fixtures/`, which it exempts wholesale. The content scan reads bytes: an N64 header in any byte
# order, a file hashing to the cartridge, an oversized blob, or a second file claiming the fixture exemption.
python3 tools/artefact_scan.py || status=1

printf '\n== fixture size\n'
if [ -f fixtures/corpus/cart.z64 ]; then
	sz=$(wc -c < fixtures/corpus/cart.z64 | tr -d ' ')
	if [ "$sz" -gt 1048576 ]; then
		printf 'FAIL fixtures/corpus/cart.z64 is %s bytes — the synthetic fixture must stay tiny\n' "$sz"
		status=1
	else
		printf 'fixtures/corpus/cart.z64 %s bytes (synthetic, ok)\n' "$sz"
	fi
else
	printf 'FAIL fixtures/corpus/cart.z64 is missing\n'
	status=1
fi

printf '\n== cartridge integrity\n'
python3 - <<'PY' || status=1
import hashlib, json, sys
from pathlib import Path

rom = Path("rom/Resident Evil 2 (USA) (Rev 1).z64")
manifest = Path("build/elfs/images.json")
if not manifest.exists():
    print("SKIP no build/elfs/images.json in this checkout (build/ is gitignored)")
    sys.exit(0)
if not rom.exists():
    print("SKIP no cartridge in this checkout (gitignored by design)")
    sys.exit(0)
want = json.loads(manifest.read_text())["cart_sha256"]
got = hashlib.sha256(rom.read_bytes()).hexdigest()
print(("PASS " if got == want else "FAIL ") + "sha256 %s" % got)
print("     expected %s (build/elfs/images.json)" % want)
sys.exit(0 if got == want else 1)
PY

printf '\n'
if [ "$status" -eq 0 ]; then
	printf 'ci: ok\n'
else
	printf 'ci: FAILED\n'
fi
exit "$status"
