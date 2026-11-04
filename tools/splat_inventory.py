#!/usr/bin/env python3
"""Turn splat's asm output into a function inventory.

Reads <build_dir>/asm/*.s plus symbol_addrs.txt (for named symbols like
`entrypoint`/`main`) and writes <build_dir>/functions.csv with
address,name,size_bytes. Sizes come from spimdisasm's `nonmatching NAME, 0xN`
lines; a blank size means spimdisasm did not emit one.

Usage: ./splat_inventory.py ~/re2-build
"""
import re
import sys
from pathlib import Path

GLABEL = re.compile(r"^glabel\s+(\S+)")
NONMATCH = re.compile(r"^nonmatching\s+(\S+),\s*(0x[0-9A-Fa-f]+)")
SYM = re.compile(r"^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)")
FUNCNAME = re.compile(r"^func_([0-9A-Fa-f]{8})$")


def main() -> None:
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    build = Path(sys.argv[1])
    asm = build / "asm"
    if not asm.is_dir():
        sys.exit(f"no asm directory under {build}")

    named = {}
    symfile = build / "symbol_addrs.txt"
    if symfile.is_file():
        for line in symfile.read_text().splitlines():
            m = SYM.match(line)
            if m:
                named[m.group(1)] = int(m.group(2), 16)

    funcs, sizes = [], {}
    for f in sorted(asm.glob("*.s")):
        for line in f.read_text().splitlines():
            m = GLABEL.match(line)
            if m:
                name = m.group(1)
                if name in named:
                    funcs.append((named[name], name))
                elif FUNCNAME.match(name):
                    funcs.append((int(name[5:], 16), name))
                # other symbolic names have no address here; skipped deliberately
            m = NONMATCH.match(line)
            if m:
                sizes[m.group(1)] = int(m.group(2), 16)

    funcs.sort()
    rows = [(a, n, sizes.get(n)) for a, n in funcs]
    out = build / "functions.csv"
    with out.open("w") as fh:
        fh.write("address,name,size_bytes\n")
        for a, n, s in rows:
            fh.write("0x%08X,%s,%s\n" % (a, n, "" if s is None else s))

    sized = [r for r in rows if r[2]]
    print(f"functions: {len(rows)}   with explicit size: {len(sized)}")
    print(f"code span: 0x{rows[0][0]:08X} .. 0x{rows[-1][0]:08X}")
    if sized:
        total = sum(r[2] for r in sized)
        print(f"sized bytes: {total} ({total/1024:.1f} KB)")
        print("largest:")
        for a, n, s in sorted(sized, key=lambda r: -r[2])[:3]:
            print(f"  0x{a:08X} {n:<20} {s} bytes")
    print(f"wrote {out}")


if __name__ == "__main__":
    main()
