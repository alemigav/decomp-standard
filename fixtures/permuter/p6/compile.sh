#!/bin/bash
# decomp-permuter build hook: compile.sh <in.c> -o <out.o>
#
# Paths are resolved from this script's location, not from the caller's cwd, so the harness runs from a
# fresh clone once `tools/provision.sh` has built the toolchain.
set -e
here=$(cd "$(dirname "$0")" && pwd)
root=$(cd "$here/../../.." && pwd)
TC="$root/build/toolchain"
in="$1"; out="$3"
tmp=$(mktemp /tmp/perm.XXXXXX.s)
trap 'rm -f "$tmp"' EXIT
"$TC/mips-gcc-2.8.1/bin/cc1" -quiet -O2 -G 0 -mips2 -mcpu=r4300 "$in" -o "$tmp"
if [ -x "$TC/src/bu27-build/gas/as.new" ]; then
    "$TC/src/bu27-build/gas/as.new" -EB -mips2 -G 0 -o "$out" "$tmp"
else
    "$TC/binutils/bin/mips-linux-gnu-as" -EB -mips2 -G 0 -o "$out" "$tmp"
fi
