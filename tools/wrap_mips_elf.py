#!/usr/bin/env python3
"""Wrap a raw big-endian MIPS code segment in a minimal ELF32 header.

Why this exists: REA's Ghidra lane admits MIPS only as ELF, and its raw-binary
loader refuses `architecture: mips` outright (allowed: 6502, x86, x86_64, arm,
arm64, m68k). An N64 ROM is a raw image, so every code segment we want to
decompile has to be wrapped first. Verified end to end on 2026-10-30.

The header is deliberately the "recordless legacy" shape REA admits:
  ELF32, big-endian, ET_EXEC, EM_MIPS, e_flags = 0  (MIPS-I ISA field, no ABI record)
REA then pins `MIPS:BE:32:default` and records the o32 ABI as an *assumption*.

Usage:
  ./wrap_mips_elf.py --input code.bin --output code.elf --base 0x80000400
  ./wrap_mips_elf.py --input rom.z64 --output rom.elf --base 0x80000480 \\
                     --offset 0x1000 --length 0x11000

CAUTION — `--base` must be the segment's real vram, and for this cartridge
ROM 0x1000 loads at **0x80000480**, not 0x80000000. Getting this wrong shifts
every recovered address by 0x480 and silently poisons symbol names; see
notes/M7-mapping-correction.md for the three tests that recover the base.
"""
import argparse
import struct
import sys

ET_EXEC, EM_MIPS = 2, 8
HDR = 0x100  # code placed at this file offset


def build(text: bytes, base: int) -> bytes:
    ehdr = bytearray()
    ehdr += b"\x7fELF" + bytes([1, 2, 1, 0]) + bytes(8)  # 32-bit, big-endian
    ehdr += struct.pack(">HHIIIIIHHHHHH",
                        ET_EXEC, EM_MIPS, 1,
                        base,        # e_entry
                        52,          # e_phoff
                        0, 0,        # e_shoff, e_flags (ARCH_1, no ABI record)
                        52, 32, 1,   # ehsize, phentsize, phnum
                        0, 0, 0)
    assert len(ehdr) == 52

    phdr = struct.pack(">IIIIIIII",
                       1,           # PT_LOAD
                       HDR,
                       base, base,
                       len(text), len(text),
                       5,           # PF_R | PF_X
                       4)
    assert len(phdr) == 32

    out = bytearray(ehdr + phdr)
    if len(out) > HDR:
        sys.exit(f"header grew past 0x{HDR:x} — refusing to write a corrupt ELF")
    out += bytes(HDR - len(out))
    out += text
    return bytes(out)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--input", required=True)
    ap.add_argument("--output", required=True)
    ap.add_argument("--base", required=True, help="virtual address of the first byte, e.g. 0x80000400")
    ap.add_argument("--offset", default="0", help="byte offset into the input to start from")
    ap.add_argument("--length", default="0", help="byte count (0 = to end of input)")
    ap.add_argument("--align", default="4", help="refuse if length is not a multiple (0 disables)")
    a = ap.parse_args()

    base = int(a.base, 0)
    off = int(a.offset, 0)
    with open(a.input, "rb") as f:
        f.seek(off)
        text = f.read(int(a.length, 0) or -1)

    align = int(a.align, 0)
    if align and len(text) % align:
        sys.exit(f"length {len(text)} is not a multiple of {align}; MIPS instructions are 4 bytes")

    data = build(text, base)
    with open(a.output, "wb") as f:
        f.write(data)
    print(f"wrote {a.output}: {len(text)} bytes of code at 0x{base:08x} ({len(data)} byte ELF)")


if __name__ == "__main__":
    main()
