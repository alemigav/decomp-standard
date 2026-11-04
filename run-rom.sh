#!/bin/sh
# Launch the cartridge in an external emulator: an OPTIONAL VALIDATOR, not a runtime dependency.
#
# Nothing in this repository imports, launches or requires ares. It is here because
# tools/diff_rdram.py needs ground-truth RDRAM dumps, and the only way to produce one is to run
# the game in a real emulator and export memory (Tools -> Memory Editor -> region RDRAM ->
# Memory row -> Export). That is the workflow this script documents; `diff_rdram.py --ares`
# points at the dump it produces.
#
# The decomposition research does not depend on it: tools/mips_harness.py executes the game's own
# instructions, and the corpus in src/ is built from the cartridge alone.
#
# Usage:
#   ./run-rom.sh            # windowed, normal UI (Tools menu available)
#   ./run-rom.sh --kiosk    # borderless, minimal UI
#
# The ROM is user-supplied and gitignored; it must be at the path below.
set -eu

HERE=$(cd "$(dirname "$0")" && pwd)
ROM="$HERE/rom/Resident Evil 2 (USA) (Rev 1).z64"
ARES="${ARES_APP:-/Applications/ares.app}"

[ -f "$ROM" ] || { echo "ROM not found: $ROM" >&2; exit 1; }
[ -d "$ARES" ] || { echo "ares not found: $ARES (brew install ares-emulator)" >&2; exit 1; }

case "${1:-}" in
  --kiosk) exec open -na "$ARES" --args --system "Nintendo 64" --kiosk "$ROM" ;;
  "")      exec open -na "$ARES" --args --system "Nintendo 64" "$ROM" ;;
  *)       echo "usage: $0 [--kiosk]" >&2; exit 2 ;;
esac
