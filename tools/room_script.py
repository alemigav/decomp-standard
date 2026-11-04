#!/usr/bin/env python3
"""Decode a room's script straight out of the cartridge — no dump, no emulator.

The chain this walks was established by M145 and is entirely static:

    room byte -> DAT_80131fa8[room]                  (a u16 file id, in the stage-2 image)
              -> file table entry (cart record 0x43, 8-byte {offset, size} after a 0x28 header)
              -> zlib member -- same corpus `unpack_zlib.py` extracts
              -> u16[] record-offset table at the block's head
              -> walk_stream's decoder

Usage:
  ./room_script.py                    # record 0 of file id 1881, the first DOOR_SCD
  ./room_script.py --id 1881 --commands 40
  ./room_script.py --records          # list the block's record offsets
  ./room_script.py --check            # the gate: assert what this script must contain

The cartridge is the owner's own dump and is gitignored; without it this reports SKIP, like the other
cartridge-gated suites.
"""
import argparse
import struct
import subprocess
import sys
import tempfile
import zlib
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROM = HERE.parent / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
FILE_TABLE_ROM = 0x0C8624        # cart record 0x43: the loader's base, `0xb00c8624` masked
HEADER = 0x28                    # bytes before the first {offset, size} entry
FIRST_DOOR_SCD = 1881            # DAT_80131fa8[0], from 0x8009b27c


def block(rom: bytes, file_id: int) -> bytes:
    off, size = struct.unpack_from(">II", rom, FILE_TABLE_ROM + HEADER + 8 * file_id)
    if off == 0xFFFFFFFF or size == 0:
        raise SystemExit(f"file id {file_id}: empty entry")
    return zlib.decompress(rom[FILE_TABLE_ROM + off:FILE_TABLE_ROM + off + size])


def records(raw: bytes) -> list:
    """The u16 offset table at the block's head: FUN_8006d5dc reads `u16[index]` from exactly here."""
    out = []
    for i in range(64):
        if 2 * i + 2 > len(raw):
            break
        off = struct.unpack_from(">H", raw, 2 * i)[0]
        if off == 0 or off >= len(raw):
            break
        out.append(off)
    return out


def walk(raw: bytes, start: int, commands: int) -> str:
    with tempfile.TemporaryDirectory() as tmp:
        blob = Path(tmp) / "block.bin"
        blob.write_bytes(raw)
        proc = subprocess.run([sys.executable, str(HERE / "walk_stream.py"), "--raw", str(blob),
                               "--start", hex(start), "--ctx", "0", "--commands", str(commands)],
                              capture_output=True, text=True)
        return proc.stdout + proc.stderr


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--id", type=int, default=FIRST_DOOR_SCD, help="file id from the room table")
    ap.add_argument("--commands", type=int, default=24)
    ap.add_argument("--records", action="store_true", help="list the record offsets and exit")
    ap.add_argument("--check", action="store_true", help="assert the decode's shape (the gate)")
    args = ap.parse_args()

    if not ROM.exists():
        print(f"SKIP: no cartridge at {ROM.relative_to(HERE.parent)}")
        return 0
    rom = ROM.read_bytes()
    raw = block(rom, args.id)
    table = records(raw)
    print(f"file id {args.id}: {len(raw)} B decompressed, {len(table)} record(s) at "
          f"{[hex(o) for o in table[:8]]}{' ...' if len(table) > 8 else ''}")
    if args.records:
        return 0

    text = walk(raw, table[0], args.commands)
    print(text)

    if not args.check:
        return 0
    cases = [
        ("the block's head is a u16 record table", len(table) >= 2 and table[0] < len(raw)),
        ("record 0 calls into record 1", "script record 1" in text),
        ("the called record sets two door models", text.count("0x4d DoorModelSet") >= 2),
        ("a later record loops back on itself", "cmd-12" in text),
    ]
    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} room-script case(s)")
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
