#!/usr/bin/env python3
"""Compile tools/t64info.c and check it against a real T64 block and a corrupted one.

The C header is the rebuild-facing artifact; this proves it agrees with the cartridge *and* that its
checks can fail — the same non-vacuity rule the Python gates follow.
"""
import shutil
import struct
import subprocess
import sys
import tempfile
import zlib
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROM = HERE.parent / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
TBL, HDR, CI8_TILE = 0x0C8624, 0x28, 5922          # a known 8 bpp tile (M165)


def block(fid):
    rom = ROM.read_bytes()
    off, size = struct.unpack_from(">II", rom, TBL + HDR + 8 * fid)
    return zlib.decompress(rom[TBL + off:TBL + off + size])


def main() -> int:
    if not ROM.exists():
        print(f"SKIP: no cartridge at {ROM.relative_to(HERE.parent)}")
        return 0
    cc = shutil.which("cc") or shutil.which("clang") or shutil.which("gcc")
    if not cc:
        print("SKIP: no C compiler")
        return 0
    tmp = Path(tempfile.mkdtemp(prefix="t64."))
    exe = tmp / "t64info"
    proc = subprocess.run([cc, "-O2", "-Wall", "-o", str(exe), str(HERE / "t64info.c")],
                          capture_output=True, text=True)
    if proc.returncode != 0:
        print("compile failed:\n" + proc.stderr)
        return 1

    good = tmp / "good.bin"
    good.write_bytes(block(CI8_TILE))
    ok = subprocess.run([str(exe), str(good)], capture_output=True, text=True)

    bad = tmp / "bad.bin"
    data = bytearray(block(CI8_TILE))
    data[4] = (data[4] + 1) & 0xFF                     # corrupt the width -> the length law must fail
    bad.write_bytes(bytes(data))
    broken = subprocess.run([str(exe), str(bad)], capture_output=True, text=True)

    cases = [
        ("the header compiles against a real T64 block", ok.returncode == 0),
        ("it validates the block's laws", "6/6 t64info check(s)" in ok.stdout),
        ("a corrupted width makes the length law fail", broken.returncode == 1),
        ("and the tool reports which check failed", "FAIL block length" in broken.stdout),
    ]
    passed = 0
    for label, cond in cases:
        passed += cond
        print(f"  {'PASS' if cond else 'FAIL'} {label}")
        if not cond:
            print("    " + (ok.stdout + broken.stdout).replace("\n", "\n    ")[:800])
    print(f"{passed}/{len(cases)} t64info case(s)")
    shutil.rmtree(tmp, ignore_errors=True)
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
