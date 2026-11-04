#!/usr/bin/env python3
"""Put the walk path in the gate: build a synthetic RDRAM, walk it, and check what came out.

The walk in `walk_stream.py` needs a memory dump, and the project has none to commit — an RDRAM image is
8 MiB and, more to the point, any real one is derived from the cartridge. So this fixture **builds** the
dump instead of committing it: eight megabytes of zeroes with five short command streams planted in it, one
per context, each exercising a different branch of the decoder.

The dump is written to a temporary directory, never to the repository.

Cases, one per behaviour that used to be exercised only by hand:

  1. the walk starts where `ctx+0x1c` points;
  2. `Goto` computes its target from `s16@4` and prints the derivation;
  3. `Goto` is actually **followed** — the next command is at the target, not the fall-through;
  4. `ElseStart` prints both successors and takes the **fall-through**;
  5. a `dynamic` opcode (`0x03`, a script jump) stops the walk and says why;
  6. `PlcDest` (`0x40`), unverified until M145, now advances by its confirmed 8 bytes;
  7. the `SceEmSet` command prints its `Id` field (byte 3) — the operand M94 measured.

Usage:
  ./rdram_fixture.py            # run the fixture
  ./rdram_fixture.py --keep DIR # also leave the built dump in DIR for inspection
"""
import argparse
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
RD_BASE = 0x80000000
CTX_BASE = 0x80113AD0
CTX_STRIDE = 0x174


def build(path: Path) -> None:
    dump = bytearray(8 * 1024 * 1024)

    def put(va, data):
        dump[va - RD_BASE:va - RD_BASE + len(data)] = data

    streams = {
        0: (0x80200000, bytes([0x17, 0x00, 0x00, 0x00, 0x00, 0x10])),          # Goto +0x10
        1: (0x80200100, bytes([0x07, 0x00, 0x00, 0x10])),                      # ElseStart +0x10
        2: (0x80200200, bytes([0x03, 0x00, 0x00, 0x07])),                      # script jump, dynamic
        3: (0x80200300, bytes([0x40] + [0x00] * 7)),                           # PlcDest: advances 8
        4: (0x80200400, bytes([0x44, 0x00, 0x00, 0x1F]) + bytes(18)),          # SceEmSet, Id = 31
    }
    for ctx, (addr, data) in streams.items():
        put(addr, data)
        put(addr + len(data), bytes(6))            # trailing NOPs so nothing runs off the planted data
        put(addr + len(data) + 6, bytes(6))
        base = CTX_BASE + ctx * CTX_STRIDE
        put(base + 0x1C, struct.pack(">I", addr))
        put(base + 2, bytes([0]))                  # the thread byte the dispatcher reads
    path.write_bytes(bytes(dump))


def walk(dump: Path, ctx: int, commands: int = 4) -> str:
    proc = subprocess.run([sys.executable, str(HERE / "walk_stream.py"), str(dump),
                           "--ctx", str(ctx), "--commands", str(commands)],
                          capture_output=True, text=True)
    return proc.stdout + proc.stderr


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--keep", default=None, help="directory to leave the built dump in")
    args = ap.parse_args()

    keep = Path(args.keep) if args.keep else None
    if keep:
        keep.mkdir(parents=True, exist_ok=True)
        dump = keep / "synthetic_rdram.bin"
        build(dump)
        tmp = None
    else:
        tmp = tempfile.TemporaryDirectory()
        dump = Path(tmp.name) / "synthetic_rdram.bin"
        build(dump)

    out = {ctx: walk(dump, ctx) for ctx in range(5)}
    cases = [
        ("the walk starts where ctx0 points", "walking from ctx0 = 0x80200000" in out[0]),
        ("Goto derives its target from s16 at byte 4", "cmd+16" in out[0] and "0x80200010" in out[0]),
        ("Goto is followed, not fallen through", "[ 1] 0x80200010:" in out[0]),
        ("ElseStart offers both successors and takes the fall-through",
         "fall-through" in out[1] and "0x80200110" in out[1] and "[ 1] 0x80200104:" in out[1]),
        ("a dynamic opcode stops the walk and says why",
         "STOP: destination is dynamic" in out[2] and "script jump" in out[2]),
        ("a formerly unverified opcode now advances by its confirmed size",
         "[ 1] 0x80200308:" in out[3] and "PlcDest len  8" in out[3]),
        ("SceEmSet prints its Id field", "Id(byte3)=31" in out[4]),
    ]
    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
        if not ok:
            print("    ---- walk output ----")
            print("\n".join("    " + line for line in out[0].splitlines()[-14:]))
    print(f"{passed}/{len(cases)} synthetic-rdram walk case(s)")
    if tmp is not None:
        tmp.cleanup()
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
