#!/usr/bin/env python3
"""Emit MIPS big-endian test artefacts with known ground truth.

Two outputs, because they test different admissions:
  *.raw   - headerless MIPS III big-endian code (what an N64 ROM segment looks like)
  *.elf   - minimal ELF32 BE MIPS ET_EXEC (REA's admitted MIPS lane)

The code is a countdown loop summing 5+4+3+2+1 = 15 into $v0, so a decompiler
that recovers the loop proves it understood the instruction stream.

    addiu $t0, $zero, 5        # counter
    addu  $v0, $zero, $zero    # accumulator
loop:
    addu  $v0, $v0, $t0
    addiu $t0, $t0, -1
    bnez  $t0, loop
    nop                        # branch delay slot
    jr    $ra
    nop                        # delay slot
"""
import struct
import sys

WORDS = [
    0x24080005,  # addiu t0, zero, 5
    0x00001021,  # addu  v0, zero, zero
    0x00481021,  # addu  v0, v0, t0        <- loop @ +0x08
    0x2508FFFF,  # addiu t0, t0, -1
    0x1500FFFD,  # bnez  t0, loop          (offset -3 words)
    0x00000000,  # nop   (delay slot)
    0x03E00008,  # jr    ra
    0x00000000,  # nop   (delay slot)
]
TEXT = b"".join(struct.pack(">I", w) for w in WORDS)

VADDR = 0x80000400      # conventional N64 boot/KSEG0 address
OFFSET = 0x100          # raw code offset in the ELF


def elf32_be_mips(text: bytes, vaddr: int) -> bytes:
    ehdr = bytearray()
    ehdr += b"\x7fELF" + bytes([1, 2, 1, 0]) + bytes(8)   # 32-bit, big-endian, v1
    ehdr += struct.pack(">HHIIIIIHHHHHH",
                        2,        # ET_EXEC
                        8,        # EM_MIPS
                        1,        # version
                        vaddr,    # entry
                        52,       # phoff
                        0,        # shoff
                        0,        # flags: ARCH field zero + no ABI record
                                              #  -> REA's "recordless legacy" admission
                        52, 32, 1,   # ehsize, phentsize, phnum
                        0, 0, 0)     # shentsize, shnum, shstrndx
    assert len(ehdr) == 52, len(ehdr)

    phdr = struct.pack(">IIIIIIII",
                       1,        # PT_LOAD
                       OFFSET,
                       vaddr,
                       vaddr,
                       len(text),
                       len(text),
                       5,        # R+X
                       4)
    assert len(phdr) == 32

    out = bytearray(ehdr + phdr)
    out += bytes(OFFSET - len(out))
    out += text
    return bytes(out)


raw_path, elf_path = sys.argv[1], sys.argv[2]
open(raw_path, "wb").write(TEXT)
open(elf_path, "wb").write(elf32_be_mips(TEXT, VADDR))
print(f"raw: {raw_path} ({len(TEXT)} bytes, {len(WORDS)} instructions, entry 0x{VADDR:08x})")
print(f"elf: {elf_path} ({OFFSET + len(TEXT)} bytes, ELF32 BE MIPS ET_EXEC)")
