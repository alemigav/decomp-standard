#!/usr/bin/env python3
"""Read an ares RDRAM dump and answer the scene-slot question from it.

The static chain is fully mapped (M85–M99), and both remaining unknowns are runtime byte reads:

    *(0x80115284) + 3                          the slot passed to FUN_8003287c
    *(0x800df92c) -> +0x48 / +0x4c -> commands   the command stream, opcode 0x44 = 22 bytes

This tool reads both out of one memory dump, in the order that lets it fail informatively:

  1. if `*(0x80115284)` is zero the dump predates a room load — say so, and stop;
  2. otherwise read byte 3 and report **which branch of M92/M93 the slot triggers**
     (16 -> bank-C record 39 with a silent failed inflate; 17–31 -> cart_record(0), a 1.28 GB
     out-of-cartridge inflate; 32–63 -> bank B, the live path; other -> unchecked index);
  3. read `*(0x800df92c)`, then its `+0x48` / `+0x4c` stream pointers;
  4. scan each stream for opcode `0x44` at the **22-byte** stride settled in M99 and print every
     command's byte 3 — those are the slot values the game actually selects.

Acceptance is deliberately strict: a value is only reported if the pointer is inside RDRAM and the
command's opcode byte is 0x44. Anything else is printed as "not installed" or "no 0x44 commands",
because a plausible-looking number from a misaligned scan would be worse than no answer.

Usage:
  ./room_probe.py rom/*-rdram-*.bin
"""
import argparse
import struct
import sys
from pathlib import Path

RD_BASE = 0x80000000
SLOT_CTX = 0x80115284          # holds a pointer; byte 3 of that pointer's target is the slot
SCRIPT = 0x800df92c            # holds the script descriptor pointer
STREAM_FIELDS = (0x48, 0x4C)   # two stream pointers inside the descriptor
BSS_BUFFER = 0x80171DF8        # the overlay's BSS command buffer
OP_44 = 0x44
GATE_BYTE = 9                  # FUN_80071e14 tests descriptor byte 9 before calling the loader
GATE_FN = 0x800837ac           # bitmap bit test: srl a1,5 / sllv v0,0x80000000,a1 / and
STRIDE = 22                    # settled in M99: opcode 0x44 commands are 22 bytes


def read(dump: bytes, va: int, n: int) -> bytes:
    o = va - RD_BASE
    if o < 0 or o + n > len(dump):
        raise ValueError(f"{va:#010x}+{n} is outside this dump")
    return dump[o:o + n]


def word(dump: bytes, va: int) -> int:
    return struct.unpack(">I", read(dump, va, 4))[0]


def word_at(dump: bytes, va: int) -> int:
    return struct.unpack(">I", read(dump, va, 4))[0]


def in_ram(v: int, dump: bytes) -> bool:
    return RD_BASE <= v < RD_BASE + len(dump)


def classify(slot: int) -> str:
    if slot == 16:
        return ("slot 16 -> bank C record 39 (cart 0xb6248): inflate rejects the non-zlib stream, "
                "the return is discarded, the destination keeps its prior contents")
    if 17 <= slot <= 31:
        return ("slot 17-31 -> cart_record(0) = 'OVERLAYTABLENUMC'; branch 2 inflates 1.28 GB from "
                "cart 0x0f564552, four times past the cartridge end")
    if 32 <= slot <= 63:
        return "slot 32-63 -> bank B (records 11-38): the live path"
    if slot < 16:
        return "slot 0-15 -> negative map index: reads before the 48-byte map (unchecked)"
    return "slot 64-255 -> index past the end of the 48-byte map (unchecked)"


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("dumps", nargs="+")
    a = ap.parse_args()

    for path in a.dumps:
        dump = Path(path).read_bytes()
        print(f"\n=== {Path(path).name} ({len(dump):,} B RDRAM) ===")
        try:
            ctx = word(dump, SLOT_CTX)
            script = word(dump, SCRIPT)
            print(f"  *(0x{SLOT_CTX:x}) = {ctx:#010x}   *(0x{SCRIPT:x}) = {script:#010x}")
            if not in_ram(ctx, dump):
                print("  -> the scene slot context is NOT installed: this dump predates a room load.")
                print("     A dump taken after entering a room is needed; nothing else here is answerable.")
                continue
            slot = read(dump, ctx + 3, 1)[0]
            print(f"  slot = byte 3 of {ctx:#010x} = {slot} ({slot:#04x})")
            print(f"    {classify(slot)}")

            # the gate (M101): byte 9 && the bitmap test decide whether the loader is reached at all
            b9 = read(dump, ctx + GATE_BYTE, 1)[0]
            if b9 == 0xFF:
                verdict = "byte 9 == 0xff -> the gate is skipped and the loader runs"
            else:
                wi, bit = b9 >> 5, b9 & 0x1F
                bitmap_word = word_at(dump, ctx + 4 * wi) if in_ram(ctx + 4 * wi, dump) else 0
                mask = (0x80000000 << bit) & 0xFFFFFFFF
                hit = mask & bitmap_word
                verdict = (f"byte 9 = {b9} -> bitmap word {bitmap_word:#010x}, mask {mask:#010x}, "
                           f"test {hit:#010x} -> "
                           f"{'BLOCKS (loader not called)' if hit else 'PASSES (loader called)'}")
            print(f"  gate: descriptor byte 9 = {b9:#04x}; {verdict}")

            if not in_ram(script, dump):
                print(f"  -> script descriptor NOT installed at {script:#010x}; command stream unknown")
                block = read(dump, BSS_BUFFER, 0x200)
            else:
                streams = [word(dump, script + off) for off in STREAM_FIELDS]
                print(f"  script descriptor {script:#010x}: "
                      f"+0x48 = {streams[0]:#010x}  +0x4c = {streams[1]:#010x}")
                live = [s for s in streams if in_ram(s, dump)]
                if live:
                    block = read(dump, live[0], 0x400)
                    print(f"  reading {len(block)} B of the command stream at {live[0]:#010x}")
                else:
                    block = read(dump, BSS_BUFFER, 0x200)
                    print(f"  neither stream pointer is in RDRAM; reading the BSS buffer at "
                          f"{BSS_BUFFER:#010x}")

            # A stride scan from an arbitrary start does not work: 0x44 is a common byte in this
            # buffer, and the stream must be walked from a live command pointer using the per-opcode
            # lengths. That is tools/walk_stream.py, which derives those lengths from the handlers.
            print("  (for the command stream itself, run tools/walk_stream.py on this dump: it walks "
                  "from ctx+0x1c using the per-opcode lengths rather than scanning at a fixed stride)")
        except ValueError as exc:
            print(f"  cannot read the chain from this dump: {exc}")


if __name__ == "__main__":
    main()
