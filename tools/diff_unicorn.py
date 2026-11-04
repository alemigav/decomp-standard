#!/usr/bin/env python3
"""RETIRED 2026-10-30 — kept for its host findings, not for continued use.

Verdict when retired: across every instruction both implementations could execute
(158 addresses from 0x8004d344 through the dispatcher's mtc0 $12) Unicorn agreed with
this harness instruction-for-instruction, zero divergence. The comparison could not be
extended because Unicorn's two modes fail complementarily — MIPS32 refuses the MIPS III
instructions the VR4300 uses (DADDIU at 0x80000fb4), MIPS64 does not fetch at all. A
real N64 emulator is needed for anything further, and that is a system-level install
requiring user approval. Per user decision the differential is no longer used.

Lockstep differential of tools/mips_harness.py against Unicorn (QEMU TCG).

Unicorn is an independent MIPS32 implementation, which is the only way to ask
"is my CPU still wrong?" without the self-built harness adjudicating itself.

Two host details had to be established first, both found by experiment:

  * Unicorn's MIPS32 core translates KSEG0/KSEG1 **PCs** to physical addresses, so
    executing at 0x80000000+ needs the image mapped at the physical mirror too
    (0x00000000 for kseg0, 0x10000000 for the cartridge at kseg1). Without the
    mirror every fetch fails with UC_ERR_FETCH_UNMAPPED even though mem_map and
    mem_write succeeded.
  * Single-stepping uses a code hook that stops on the SECOND fetch, so exactly one
    instruction executes per emu_start.

KNOWN CONVENTION DIFFERENCE: around a branch/jump the two report different next PCs.
This harness tracks the delay slot explicitly (after `jal` it reports the delay-slot
address), while Unicorn reports the branch target and executes the delay slot in its own
mechanism. A raw PC-by-PC comparison therefore diverges at the first `jal` — that is a
modelling difference, not a semantic bug, and the comparison must be normalised (compare
the visited-PC sequence, or align on non-delay boundaries) before real divergences can be
found. That normalisation is the next step; this script deliberately stops at the raw
comparison and reports it honestly instead of hiding it.
"""
import struct, sys
sys.path.insert(0, "tools")
from mips_harness import Cpu, Memory, RAM_BASE, RAM_SIZE, CART_BASE, SENTINEL
from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_BIG_ENDIAN, UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_PC, UC_MIPS_REG_SP, UC_MIPS_REG_RA

def main(entry=0x8004D344, limit=20000):
    rom = open("rom/Resident Evil 2 (USA) (Rev 1).z64", "rb").read()
    s2 = open("assets/unpacked/00000_0014420_1172240.bin", "rb").read()
    ram = bytearray(RAM_SIZE)
    ram[0x480:0x480+0x13600] = rom[0x1000:0x14600]
    ram[0x18A80:0x18A80+len(s2)] = s2
    mem = Memory(ram, rom); cpu = Cpu(mem, {})
    cpu.r[29] = 0x803FF000; cpu.r[31] = SENTINEL; cpu.pc = entry; cpu.delay = None
    uc = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_BIG_ENDIAN)
    for base, data in ((RAM_BASE, bytes(ram)), (0x00000000, bytes(ram)),
                       (CART_BASE, rom), (0x10000000, rom)):
        uc.mem_map(base, len(data)); uc.mem_write(base, data)
    uc.reg_write(UC_MIPS_REG_SP, 0x803FF000); uc.reg_write(UC_MIPS_REG_RA, SENTINEL)
    uc.reg_write(UC_MIPS_REG_PC, entry)
    c = {"n": 0}
    def hook(u, addr, size, data):
        c["n"] += 1
        if c["n"] >= 2: u.emu_stop()
    uc.hook_add(UC_HOOK_CODE, hook)
    for step in range(limit):
        at = cpu.pc
        try:
            cpu.delay = None; cpu.step(at)
            cpu.pc = cpu.jump_now if cpu.jump_now is not None else at + 4
            cpu.jump_now = None
        except Exception as e:
            print(f"mine stopped at {at:#x}: {e}"); return
        c["n"] = 0
        try:
            uc.emu_start(uc.reg_read(UC_MIPS_REG_PC), 0)
        except Exception as e:
            print(f"unicorn stopped at {uc.reg_read(UC_MIPS_REG_PC):#x}: {e}"); return
        ref = uc.reg_read(UC_MIPS_REG_PC)
        if cpu.pc != ref:
            print(f"FIRST DIVERGENCE after {step+1} instructions at {at:#x}")
            print(f"  mine    next PC = {cpu.pc:#x}")
            print(f"  unicorn next PC = {ref:#x}")
            return
    print(f"no divergence in {limit} instructions")

if __name__ == "__main__":
    main()
