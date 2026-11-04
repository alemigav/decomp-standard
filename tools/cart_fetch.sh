#!/bin/sh
# Materialise the cartridge on a hosted runner, from a URL the owner provides.
#
# GitHub caps an Actions secret at 48 KB (docs: "Secrets are limited to 48 KB in size"), and the cartridge
# is 67 108 864 B — 89 478 489 B base64 — so no secret can carry it. What a secret *can* carry is access:
# this script takes `RE2_CART_URL` (and an optional `RE2_CART_TOKEN`) and leaves the bytes where they are
# until a run needs them. Nothing is committed and nothing is stored on GitHub.
#
# Safety, in order: download to a temporary name, verify the SHA-256 against the committed
# `manifests/manifest.json` → `rom_sha256`, and only then move it into place. A truncated or wrong file
# fails before anything unpacks it, so a bad secret cannot look like a corrupt game.
#
# Environment:
#   RE2_CART_URL    required; http(s):// (bearer token applied) or file:// (local test)
#   RE2_CART_TOKEN  optional; sent as `Authorization: Bearer …`
#   RE2_CART_DEST   optional; defaults to the cartridge path the suites expect
#
# Usage:
#   RE2_CART_URL=… ./cart_fetch.sh            # download, verify, unpack, build images
#   ./cart_fetch.sh --self-test               # the verification logic, on synthetic bytes
set -u

DEST_DEFAULT="rom/Resident Evil 2 (USA) (Rev 1).z64"

sha_of() {
	python3 - "$1" <<'PY'
import hashlib, sys
h = hashlib.sha256()
with open(sys.argv[1], "rb") as f:
    for chunk in iter(lambda: f.read(1 << 20), b""):
        h.update(chunk)
print(h.hexdigest())
PY
}

# The verification, factored out so `--self-test` exercises the same code the fetch path uses. A self-test
# that re-implements the comparison proves nothing about the comparison.
verify_matches() {
	[ "$(sha_of "$1")" = "$2" ]
}

expected_sha() {
	python3 - <<'PY'
import json, sys
from pathlib import Path
print(json.loads(Path("manifests/manifest.json").read_text())["rom_sha256"])
PY
}

self_test() {
	tmp=$(mktemp -d)
	trap 'rm -rf "$tmp"' EXIT
	printf 'synthetic-cartridge-bytes' > "$tmp/good.z64"
	want=$(sha_of "$tmp/good.z64")
	pass=0
	total=0

	total=$((total + 1))
	if verify_matches "$tmp/good.z64" "$want"; then
		printf 'PASS  an intact file matches its own digest\n'
		pass=$((pass + 1))
	else
		printf 'FAIL  an intact file matches its own digest\n'
	fi

	printf 'synthetic-cartridge-byteS' > "$tmp/bad.z64"          # one byte differs
	total=$((total + 1))
	if verify_matches "$tmp/bad.z64" "$want"; then
		printf 'FAIL  a single changed byte is detected\n'
	else
		printf 'PASS  a single changed byte is detected\n'
		pass=$((pass + 1))
	fi

	: > "$tmp/empty.z64"
	total=$((total + 1))
	if verify_matches "$tmp/empty.z64" "$want"; then
		printf 'FAIL  a truncated file is detected\n'
	else
		printf 'PASS  a truncated file is detected\n'
		pass=$((pass + 1))
	fi

	total=$((total + 1))
	if [ "$(expected_sha)" = "71f3f779613bf1f0e2050bfa600425385d2c257a647d2e40f63be1a7986e9aac" ]; then
		printf 'PASS  the committed manifest states the expected cartridge\n'
		pass=$((pass + 1))
	else
		printf 'FAIL  the committed manifest states the expected cartridge\n'
	fi

	printf '\n%d/%d cart-fetch case(s)\n' "$pass" "$total"
	[ "$pass" -eq "$total" ]
}

if [ "${1:-}" = "--self-test" ]; then
	self_test
	exit $?
fi

: "${RE2_CART_URL:?RE2_CART_URL is not set — refusing to guess where the cartridge lives}"
dest=${RE2_CART_DEST:-$DEST_DEFAULT}
mkdir -p "$(dirname "$dest")"

printf 'fetching %s\n' "$RE2_CART_URL"
if [ -n "${RE2_CART_TOKEN:-}" ]; then
	# The token goes in a config file, not the command line: `ps` shows arguments, including on a runner.
	cfg=$(mktemp)
	trap 'rm -f "$cfg" "$dest.part"' EXIT
	printf 'header = "Authorization: Bearer %s"\n' "$RE2_CART_TOKEN" > "$cfg"
	curl -fsSL --retry 3 --retry-delay 2 --max-time 600 -K "$cfg" -o "$dest.part" "$RE2_CART_URL"
else
	trap 'rm -f "$dest.part"' EXIT
	curl -fsSL --retry 3 --retry-delay 2 --max-time 600 -o "$dest.part" "$RE2_CART_URL"
fi

want=$(expected_sha)
if ! verify_matches "$dest.part" "$want"; then
	printf 'FAIL sha256 %s\n' "$(sha_of "$dest.part")" >&2
	printf '     expected %s (manifests/manifest.json)\n' "$want" >&2
	printf '     the download is not the cartridge these suites were built against — not unpacking it\n' >&2
	exit 1
fi
printf 'verified sha256 %s\n' "$want"
mv "$dest.part" "$dest"

printf '\nunpacking the zlib members\n'
python3 tools/unpack_zlib.py "$dest" --out assets/unpacked

printf '\nbuilding the code images\n'
python3 tools/build_images.py "$dest"

printf '\ncart_fetch: %s is in place and built\n' "$dest"
