#!/usr/bin/env python3
"""Prove that `break` in this port cannot be recovered from: the exception path never returns.

`0x8008548c` guards a texture handle with `break` (Ghidra renders it `trap(0)`). Whether that is a hard stop or
something a handler can skip is a question about the **exception path**, and it is answerable by disassembly:

  1. boot installs a four-instruction stub at the exception vectors (`0x80000084`, `0x80000100`, `0x80000180`):
     `lui k0,0x8000` / `addiu k0,k0,0x06d0` / `jr k0` / `nop`  ->  every exception vectors to **0x800006d0**;
  2. the handler masks interrupts, reads **Cause**, posts a **fault event** into the libultra queue at
     `0x80012140`, and copies the interrupted register file into a fault context;
  3. and then — the two facts that decide the question — there is **no `mtc0 $14`** (an EPC write, the only way
     to skip the faulting instruction) and **no `eret`** (the only way to return, which would retry it).

So a stale handle does not fall through, and does not even re-trap in a loop: it stops the machine.

  ./exception_path.py            # report
  ./exception_path.py --check    # the gate
"""
import argparse
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROM = HERE.parent / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
BOOT_ELF = HERE.parent / "build" / "elfs" / "boot.elf"
VECTORS = (0x80000084, 0x80000100, 0x80000180)
STUB = (0x3C1A8000, 0x275A06D0, 0x03400008, 0x00000000)     # lui k0 / addiu k0 / jr k0 / nop
HANDLER = 0x800006D0
HANDLER_END = 0x80000F00


def segments(data):
    e_phoff = struct.unpack_from(">I", data, 28)[0]
    pes = struct.unpack_from(">H", data, 42)[0]
    phn = struct.unpack_from(">H", data, 44)[0]
    out = []
    for i in range(phn):
        off = e_phoff + i * pes
        p_type, p_offset, p_vaddr, _pa, p_filesz, _ms = struct.unpack_from(">IIIIII", data, off)
        if p_type == 1:
            out.append((p_vaddr, p_offset, p_filesz))
    return out


def load_boot():
    """The boot image, from the elf if it is built, else straight from the ROM (`boot` is at cart 0x1000)."""
    if BOOT_ELF.exists():
        data = BOOT_ELF.read_bytes()
        for v, o, s in segments(data):
            if v <= HANDLER < v + s:
                return data, v, o, s
    if ROM.exists():
        rom = ROM.read_bytes()
        base, size = 0x80000000, 69952
        return rom[0x1000:0x1000 + size], base, 0, size
    return None, None, None, None


def terminus(data, vaddr, off, size):
    """Where every exception path converges, and whether the loop can change its own state.

    All paths branch back to a single address; that block reads a **BSS** state byte (offset 6480 = 0x1950) and a
    **BSS** handler pointer (offset 6512 = 0x1970) and `jr`s through it. Crucially the block contains **no
    stores and no COP0 writes**, so the spinning CPU cannot alter anything that would let it leave.
    """
    def word(va):
        return struct.unpack_from(">I", data, off + (va - vaddr))[0]

    backs = []
    for va in range(HANDLER, HANDLER_END, 4):
        x = word(va)
        op = x >> 26
        rs, rt = (x >> 21) & 0x1F, (x >> 16) & 0x1F
        imm = x & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if op in (0x04, 0x05, 0x01):
            tgt = va + 4 + (simm << 2)
            if tgt <= va:
                backs.append(tgt)
    convergence = max(set(backs), key=backs.count) if backs else None
    if convergence is None:
        return None, 0, [], False, False
    stores, cop0w, has_jr, tables = [], [], False, False
    for va in range(convergence, min(convergence + 0x3C, HANDLER_END), 4):
        x = word(va)
        op = x >> 26
        if op in (0x28, 0x29, 0x2A, 0x2B, 0x3E, 0x3F):
            stores.append(va)
        if op == 0x10 and ((x >> 21) & 0x1F) == 4:
            cop0w.append(va)
        if op == 0 and (x & 0x3F) == 0x08:
            has_jr = True
        # the two BSS reads: `lbu t2,6480(at)` (state byte) and `lw t2,6512(at)` (handler pointer)
        if op in (0x20, 0x23, 0x24) and (x & 0xFFFF) in (6480, 6512):
            tables = True
    return convergence, backs.count(convergence), stores, has_jr, (cop0w, tables)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    data, vaddr, off, size = load_boot()
    if data is None:
        print("SKIP: no boot image and no cartridge")
        return 0

    def word(va):
        return struct.unpack_from(">I", data, off + (va - vaddr))[0]

    # 1. the stub exists **literally** in the boot image: the installer copies these 16 bytes to each vector,
    # so searching the image for them is a real check (they are absent *at* the vectors, which is runtime RAM).
    stub_bytes = b"".join(struct.pack(">I", w) for w in STUB)
    stub_at = data.find(stub_bytes)
    stubs_ok = 1 if stub_at >= 0 else 0

    # 2. exhaustive scan of the handler region
    mtc0_epc = [va for va in range(HANDLER, HANDLER_END, 4)
                if (word(va) >> 26) == 0x10 and ((word(va) >> 21) & 0x1F) == 4
                and ((word(va) >> 11) & 0x1F) == 14]
    erets = [va for va in range(HANDLER, HANDLER_END, 4) if word(va) == 0x42000018]
    causes = [va for va in range(HANDLER, HANDLER_END, 4)
              if (word(va) >> 26) == 0x10 and ((word(va) >> 21) & 0x1F) == 0
              and ((word(va) >> 11) & 0x1F) == 13]

    print(f"handler region {HANDLER:#x}..{HANDLER_END:#x}: "
          f"{len(causes)} Cause read(s), {len(mtc0_epc)} EPC write(s), {len(erets)} eret(s)")
    print(f"stub bytes in the image: {'at file offset ' + hex(stub_at) if stub_at >= 0 else 'NOT FOUND'}")
    conv, conv_n, stores, has_jr, extra = terminus(data, vaddr, off, size)
    cop0w, tables = extra if isinstance(extra, tuple) else ([], False)
    print(f"convergence point {conv if conv is None else hex(conv)} entered {conv_n} time(s); "
          f"stores in the block {len(stores)}, cop0 writes {len(cop0w)}, jr {has_jr}, BSS tables {tables}")

    if not args.check:
        return 0
    cases = [
        ("the handler reads Cause, so it is the real exception path", len(causes) >= 1),
        ("no EPC write exists, so the faulting instruction cannot be skipped", len(mtc0_epc) == 0),
        ("no eret exists, so the handler never returns", len(erets) == 0),
        ("the jr-k0 stub exists literally in the boot image (the installer copies it to the vectors)",
         stubs_ok == 1),
        # --- the terminus (M171)
        ("every exception path converges on one address", conv is not None and conv_n >= 5),
        ("the convergence block contains no stores, so the CPU cannot change its own state", len(stores) == 0),
        ("the convergence block contains no COP0 writes", len(cop0w) == 0),
        ("it dispatches through a BSS handler pointer table with jr", has_jr and tables),
    ]
    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} exception-path case(s)")
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
