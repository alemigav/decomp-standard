#!/usr/bin/env python3
"""Partial MIPS III harness: execute one function with the real images mapped.

Scope, stated plainly: this is not a console emulator. It implements the integer
subset these functions use, maps the two known RAM images (boot bank at
0x80000480, stage-2 at 0x80018a80), maps the cartridge at KSEG1 0xB0000000 so a
`0xB0…` descriptor pointer resolves to actual ROM bytes, and replaces the loader
primitives with host hooks — inflate is Python's zlib reading emulated memory.

What that buys: a load trace produced by *running* the game's own instructions
(address arithmetic, descriptor field loads, argument setup) with only the
compression primitive supplied by the host. No thread scheduler, no video, no
interrupts; calls into the OS are stubs that return 0 and are logged.

Every run prints HOST-HOOK and STUB call lists, so what was executed and what was
faked is visible in the output rather than buried in a docstring.
"""
import struct, sys, zlib

RAM_BASE, RAM_SIZE = 0x80000000, 0x00400000
CART_BASE, CART_MASK = 0xB0000000, 0x0FFFFFFF
SENTINEL = 0xDEADBEEF

class Memory:
    def __init__(self, ram, rom):
        self.ram, self.rom = bytearray(ram), rom
    def _loc(self, a, n):
        if RAM_BASE <= a and a + n <= RAM_BASE + len(self.ram): return self.ram, a - RAM_BASE
        if CART_BASE <= a < CART_BASE + 0x04000000:
            o = a & CART_MASK
            if o + n <= len(self.rom): return self.rom, o
        raise Fault(f"unmapped {'read' if False else 'access'} at {a:#010x}+{n}")
    def read(self, a, n):
        buf, o = self._loc(a, n)
        v = int.from_bytes(buf[o:o+n], "big")
        return v
    def write(self, a, n, v):
        buf, o = self._loc(a, n)
        if isinstance(buf, bytes): raise Fault(f"write to ROM at {a:#010x}")
        buf[o:o+n] = (v & ((1 << (8*n)) - 1)).to_bytes(n, "big")

class Fault(Exception): pass

# Named so the harness reports *which* missing feature stopped it, instead of a bare
# opcode number. These are deliberately not approximated: an unaligned dword store
# done as an aligned one silently corrupts memory and makes the run look plausible.
NAMED_OPS = {
    0x1A: "LDL (64-bit unaligned load)", 0x1B: "LDR (64-bit unaligned load)",
    0x2C: "SDL (64-bit unaligned store)", 0x2D: "SDR (64-bit unaligned store)",
    0x34: "LLD", 0x3C: "SCD",
}

class Cpu:
    def __init__(self, mem, hooks, steps=400000):
        self.m = mem; self.hooks = hooks; self.steps = steps
        self.r = [0]*32; self.delay = None; self.pc = 0
        # COP1 register file: 32 x 64-bit, held as raw bit patterns. An FPR is one
        # 64-bit register, not a host double: S-format values occupy the low 32 bits
        # and the high 32 bits are preserved, which is what the VR4300 does. Storing
        # a Python float per register silently conflates the two views.
        self.f = [0]*32
        self.nullify = False       # set by a not-taken branch-likely (0x14-0x17)
        # ---- CP0 architectural state (VR4300) -------------------------------
        self.status = 0            # bit0 IE, bit1 EXL, bit2 ERL, 8-15 IM, bit22 BEV
        self.cause = 0             # 2-6 ExcCode, 8-15 IP, 31 BD
        self.epc = 0
        self.badvaddr = 0
        self.hi = 0                 # HI/LO multiply-divide pair
        self.lo = 0
        self.count = 0
        self.compare = 0
        self.hw_pending = 0        # Cause bit positions (8-15) asserted until the device acks
        self.jump_now = None       # immediate jump (ERET has no delay slot)
        self.timer_pending = False
        self.exceptions = []       # (pc, epc, cause, vector) for the record
        self.fcr31 = 0             # FP control/status: we only use the compare bit
        self.calls = []          # (kind, target, args)
        self.trace = []
    def s32(self, v): return v - (1 << 32) if v & 0x80000000 else v
    @staticmethod
    def f32(x):
        """Round a Python float to IEEE single precision (N64 S-format semantics)."""
        import struct as _s
        return _s.unpack(">f", _s.pack(">f", x))[0]
    def fget_s(self, i):
        import struct as _s
        return _s.unpack(">f", (self.f[i] & 0xFFFFFFFF).to_bytes(4, "big"))[0]
    def fset_s(self, i, v):
        import struct as _s
        low = int.from_bytes(_s.pack(">f", self.f32(v)), "big")
        self.f[i] = (self.f[i] & ~0xFFFFFFFF) | low      # high half preserved
    def fget_d(self, i):
        import struct as _s
        return _s.unpack(">d", self.f[i].to_bytes(8, "big"))[0]
    def fset_d(self, i, v):
        import struct as _s
        self.f[i] = int.from_bytes(_s.pack(">d", v), "big")
    def run(self, entry, a0=0, a1=0, a2=0, a3=0, sp=0x803FF000):
        """Execute from `entry` until `pc == SENTINEL` (reached via `jr ra`).

        CONTRACT: `run` REZEROS `self.r` and sets `ra = SENTINEL`, so fixture state cannot be
        poked into registers beforehand — pass values through `a0..a3`, or set memory first.
        The correct entry point for whole-function tests; see `tools/test_harness.py`.
        """
        self.r = [0]*32; self.r[4], self.r[5], self.r[6], self.r[7] = a0, a1, a2, a3
        self.r[29] = sp; self.r[31] = SENTINEL
        self.pc, self.delay = entry, None
        n = 0
        while self.pc != SENTINEL and n < self.steps:
            if self.pc in self.hooks:
                fn = self.hooks[self.pc]
                self.calls.append((fn.__name__, self.pc, self.r[4:8]))
                ret = fn(self, self.r[4], self.r[5], self.r[6], self.r[7])
                self.r[2] = (ret or 0) & 0xFFFFFFFF
                self.pc = self.r[31]
                n += 1
                continue
            if self.nullify:
                self.nullify = False
                self.pc = self.delay if self.delay is not None else self.pc + 4
                self.delay = None
                n += 1
                continue
            self.count = (self.count + 1) & 0xFFFFFFFF
            if self.compare and self.count == self.compare:
                self.timer_pending = True
            if self.interrupt_pending():
                self.pc = self.interrupt_entry()
                self.delay = None
                n += 1
                continue
            cur, after = self.pc, self.delay
            self.delay = None
            self.step(cur)
            if self.jump_now is not None:
                self.pc, self.jump_now = self.jump_now, None
            else:
                self.pc = after if after is not None else cur + 4
            n += 1
        return n
    STATUS_IE, STATUS_EXL, STATUS_ERL = 0x1, 0x2, 0x4
    def _IM(self): return (self.status >> 8) & 0xFF
    def _IP(self): return (self.cause >> 8) & 0xFF
    def _refresh_ip(self):
        # hw_pending holds Cause bit positions (8-15), not a shifted field, so it
        # can be OR'd straight in; mixing the two conventions silently masks the
        # very bit you asked about.
        ip = self.hw_pending | (self.cause & 0x300)               # hardware | software IP0-1
        if self.timer_pending: ip |= 0x8000                        # Cause bit 15 = IP7 timer
        self.cause = (self.cause & ~0xFF00) | (ip & 0xFF00)
    def interrupt_enabled(self):
        return (self.status & self.STATUS_IE) and not (self.status & (self.STATUS_EXL | self.STATUS_ERL))
    def interrupt_pending(self):
        """(Cause.IP & Status.IM) != 0, with the VR4300 acceptance conditions."""
        self._refresh_ip()
        return self.interrupt_enabled() and (self._IP() & self._IM()) != 0
    def exception_vector(self):
        # BEV=0 -> general exception 0x80000180; BEV=1 -> 0xBFC00380.
        # 0x80000000 is the TLB-refill vector when EXL=0, NOT the general vector.
        return 0xBFC00380 if (self.status & 0x00400000) else 0x80000180
    def interrupt_entry(self):
        """Take an interrupt with delay-slot-correct EPC and Cause.BD.

        If an interrupt is accepted while a branch's delay slot is the next
        instruction, the architecture puts EPC at the BRANCH (not the delay slot) and
        sets Cause.BD. EPC therefore points at the branch, and both the branch and its
        delay slot re-execute after eret. Getting this wrong makes the handler return
        into the middle of a branch pair - which is what drove the boot chain off the
        end of its stack in M78.
        """
        in_delay = self.delay is not None
        self.delay = None
        self.jump_now = None
        return self.take_exception(self.pc, 0, in_delay)

    def take_exception(self, pc, code, bd=False):
        self.epc = (pc - 4) & 0xFFFFFFFF if bd else pc
        self.cause = (self.cause & ~0x7C) | ((code & 0x1F) << 2) | ((1 << 31) if bd else 0)
        self._refresh_ip()
        self.status |= self.STATUS_EXL
        v = self.exception_vector()
        self.exceptions.append((pc, self.epc, self.cause, v))
        return v

    def step(self, pc):
        """Execute the instruction at `pc`.

        CONTRACT: `step` does NOT advance `self.pc`. The caller owns the delay-slot and branch
        arithmetic, which `run()` does below. Use `run()` for whole-function tests; `step` exists
        for single-instruction probes, and both `step`-driven and `run`-driven fixtures that get
        this wrong produce plausible-looking wrong answers rather than errors.
        """
        w = self.m.read(pc, 4); r = self.r
        op = w >> 26; rs = (w >> 21) & 0x1F; rt = (w >> 16) & 0x1F
        rd = (w >> 11) & 0x1F; imm = w & 0xFFFF
        si = imm - 0x10000 if imm >= 0x8000 else imm
        if op == 0x0F: r[rt] = (imm << 16) & 0xFFFFFFFF
        elif op == 0x09: r[rt] = (r[rs] + si) & 0xFFFFFFFF
        elif op == 0x19: r[rt] = (r[rs] + si) & 0xFFFFFFFF     # daddiu (32-bit view)
        elif op == 0x18: r[rt] = (r[rs] + si) & 0xFFFFFFFF     # daddi
        elif op == 0x37: r[rt] = self.m.read((r[rs] + si) & 0xFFFFFFFF, 8) & 0xFFFFFFFF  # ld
        elif op == 0x3F: self.m.write((r[rs] + si) & 0xFFFFFFFF, 8, r[rt])               # sd
        elif op == 0x30: r[rt] = self.m.read((r[rs] + si) & 0xFFFFFFFF, 4)                    # ll
        elif op == 0x38: r[rt] = 1                                                            # sc
        elif op == 0x10:                                        # COP0
            if rs == 0x00:                                     # MFC0
                r[rt] = {8: self.badvaddr, 9: self.count, 11: self.compare,
                         12: self.status, 13: self.cause, 14: self.epc}.get(rd, 0)
            elif rs == 0x04:                                   # MTC0
                if rd == 12: self.status = r[rt]
                elif rd == 13: self.cause = (self.cause & ~0x300) | (r[rt] & 0x300)
                elif rd == 14: self.epc = r[rt]
                elif rd == 9: self.count = r[rt]
                elif rd == 11: self.compare = r[rt]; self.timer_pending = False
                elif rd == 8: self.badvaddr = r[rt]
            elif rs == 0x10:                                   # COP0 "C0" space
                # 0x4200000X: the funct field decides. Treating every rs=0x10 as
                # ERET (funct 0x18) makes TLBWI/TLBWR/TLBP jump to EPC, which is
                # what sent thread 7 to address 0. There is no TLB model here, so
                # the TLB ops are no-ops that fall through.
                fn = w & 0x3F
                if fn == 0x18:                                 # ERET
                    self.status &= ~self.STATUS_EXL
                    self.jump_now = self.epc                   # no delay slot
                elif fn in (0x01, 0x02, 0x06, 0x08):           # TLBR/TLBWI/TLBWR/TLBP
                    pass
                else: raise Fault(f"COP0 C0 funct {fn:#x} at {pc:#x}")
            else: raise Fault(f"COP0 rs={rs:#x} at {pc:#x}")

        elif op == 0x0D: r[rt] = r[rs] | imm
        elif op == 0x0C: r[rt] = r[rs] & imm
        elif op == 0x0E: r[rt] = r[rs] ^ imm
        elif op == 0x0A: r[rt] = (1 if self.s32(r[rs]) < si else 0)              # SLTI: 1 if rs<imm
        elif op == 0x0B: r[rt] = (1 if r[rs] < (imm & 0xFFFFFFFF) else 0)
        elif op == 0x08: r[rt] = (r[rs] + si) & 0xFFFFFFFF
        elif op == 0x23: r[rt] = self.m.read((r[rs] + si) & 0xFFFFFFFF, 4)
        elif op == 0x20:                                   # LB: sign-extend the byte
            v = self.m.read((r[rs] + si) & 0xFFFFFFFF, 1)
            r[rt] = (v | 0xFFFFFF00) if v & 0x80 else v
        elif op == 0x24: r[rt] = self.m.read((r[rs] + si) & 0xFFFFFFFF, 1)
        elif op == 0x21:                                   # LH: sign-extend the halfword
            v = self.m.read((r[rs] + si) & 0xFFFFFFFF, 2)
            r[rt] = (v | 0xFFFF0000) if v & 0x8000 else v
        elif op == 0x25: r[rt] = self.m.read((r[rs] + si) & 0xFFFFFFFF, 2)
        elif op == 0x2B: self.m.write((r[rs] + si) & 0xFFFFFFFF, 4, r[rt])
        elif op == 0x28: self.m.write((r[rs] + si) & 0xFFFFFFFF, 1, r[rt])
        elif op == 0x29: self.m.write((r[rs] + si) & 0xFFFFFFFF, 2, r[rt])
        elif op == 0x04:
            if r[rs] == r[rt]: self.delay = ((pc + 4) + (si << 2)) & 0xFFFFFFFF
        elif op == 0x05:
            if r[rs] != r[rt]: self.delay = ((pc + 4) + (si << 2)) & 0xFFFFFFFF
        elif op == 0x06:
            if self.s32(r[rs]) <= 0: self.delay = ((pc + 4) + (si << 2)) & 0xFFFFFFFF
        elif op == 0x07:
            if self.s32(r[rs]) > 0: self.delay = ((pc + 4) + (si << 2)) & 0xFFFFFFFF
        elif op in (0x14, 0x15, 0x16, 0x17):     # BEQL / BNEL / BLEZL / BGTZL
            if op == 0x14: taken = r[rs] == r[rt]
            elif op == 0x15: taken = r[rs] != r[rt]
            elif op == 0x16: taken = self.s32(r[rs]) <= 0
            else: taken = self.s32(r[rs]) > 0
            if taken:
                self.delay = ((pc + 4) + (si << 2)) & 0xFFFFFFFF
            else:
                # not taken: the delay slot is *nullified*, not executed
                self.delay = (pc + 8) & 0xFFFFFFFF
                self.nullify = True
        elif op == 0x01:
            kind = rt
            if kind in (0x00, 0x10) and self.s32(r[rs]) < 0: self.delay = ((pc+4)+(si<<2)) & 0xFFFFFFFF
            elif kind in (0x01, 0x11) and self.s32(r[rs]) >= 0: self.delay = ((pc+4)+(si<<2)) & 0xFFFFFFFF
            elif kind == 0x02 and self.s32(r[rs]) <= 0: self.delay = ((pc+4)+(si<<2)) & 0xFFFFFFFF
            elif kind == 0x03 and self.s32(r[rs]) > 0: self.delay = ((pc+4)+(si<<2)) & 0xFFFFFFFF
            else: r[31] = (pc + 8) & 0xFFFFFFFF
        elif op == 0x02: self.delay = ((pc + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
        elif op == 0x03:
            r[31] = (pc + 8) & 0xFFFFFFFF
            self.delay = ((pc + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
        elif op == 0:
            f = w & 0x3F
            if f == 0: r[rd] = (r[rt] << ((w >> 6) & 0x1F)) & 0xFFFFFFFF
            elif f == 2: r[rd] = r[rt] >> ((w >> 6) & 0x1F)
            elif f == 3: r[rd] = (self.s32(r[rt]) >> ((w >> 6) & 0x1F)) & 0xFFFFFFFF
            elif f == 0x21: r[rd] = (r[rs] + r[rt]) & 0xFFFFFFFF
            elif f == 0x23: r[rd] = (r[rs] - r[rt]) & 0xFFFFFFFF
            elif f == 0x24: r[rd] = r[rs] & r[rt]
            elif f == 0x25: r[rd] = r[rs] | r[rt]
            elif f == 0x26: r[rd] = r[rs] ^ r[rt]
            elif f == 0x27: r[rd] = (~(r[rs] | r[rt])) & 0xFFFFFFFF
            elif f == 0x2A: r[rd] = (1 if self.s32(r[rs]) < self.s32(r[rt]) else 0)   # SLT: 1 if rs<rt
            elif f == 0x2B: r[rd] = (1 if r[rs] < r[rt] else 0)
            # 64-bit SPECIAL ops, in the 32-bit view this harness keeps. The low
            # word is exact for add/sub; shift-by-32 forms yield 0 (or sign) because
            # the whole low word shifts out, which is what the low half would show.
            elif f == 0x04: r[rd] = (r[rt] << (r[rs] & 0x1F)) & 0xFFFFFFFF  # SLLV
            elif f == 0x06: r[rd] = r[rt] >> (r[rs] & 0x1F)                 # SRLV
            elif f == 0x07: r[rd] = (self.s32(r[rt]) >> (r[rs] & 0x1F)) & 0xFFFFFFFF  # SRAV
            elif f == 0x14: r[rd] = (r[rt] << (r[rs] & 0x3F)) & 0xFFFFFFFF  # DSLLV
            elif f == 0x16: r[rd] = r[rt] >> (r[rs] & 0x3F)                 # DSRLV
            elif f == 0x17: r[rd] = (self.s32(r[rt]) >> (r[rs] & 0x3F)) & 0xFFFFFFFF  # DSRAV
            elif f == 0x2C: r[rd] = (r[rs] + r[rt]) & 0xFFFFFFFF    # DADD
            elif f == 0x2D: r[rd] = (r[rs] + r[rt]) & 0xFFFFFFFF    # DADDU
            elif f == 0x2E: r[rd] = (r[rs] - r[rt]) & 0xFFFFFFFF    # DSUB
            elif f == 0x2F: r[rd] = (r[rs] - r[rt]) & 0xFFFFFFFF    # DSUBU
            elif f == 0x38: r[rd] = (r[rt] << ((w >> 6) & 0x1F)) & 0xFFFFFFFF   # DSLL
            elif f == 0x3A: r[rd] = r[rt] >> ((w >> 6) & 0x1F)                   # DSRL
            elif f == 0x3B: r[rd] = (self.s32(r[rt]) >> ((w >> 6) & 0x1F)) & 0xFFFFFFFF
            elif f == 0x3C: r[rd] = 0                                            # DSLL32
            elif f == 0x3E: r[rd] = 0                                            # DSRL32
            elif f == 0x3F: r[rd] = (0xFFFFFFFF if self.s32(r[rt]) < 0 else 0)   # DSRA32
            elif f == 0x10: r[rd] = self.hi                      # MFHI
            elif f == 0x11: self.hi = r[rs]                      # MTHI
            elif f == 0x12: r[rd] = self.lo                      # MFLO
            elif f == 0x13: self.lo = r[rs]                      # MTLO
            elif f == 0x18:                                      # MULT
                v = self.s32(r[rs]) * self.s32(r[rt])
                self.lo = v & 0xFFFFFFFF; self.hi = (v >> 32) & 0xFFFFFFFF
            elif f == 0x19:                                      # MULTU
                v = r[rs] * r[rt]
                self.lo = v & 0xFFFFFFFF; self.hi = (v >> 32) & 0xFFFFFFFF
            elif f == 0x1A:                                      # DIV
                a, b_ = self.s32(r[rs]), self.s32(r[rt])
                if b_ == 0:
                    self.lo = 0xFFFFFFFF if a >= 0 else 1; self.hi = a & 0xFFFFFFFF
                else:
                    q = int(a / b_)
                    self.lo = q & 0xFFFFFFFF; self.hi = (a - q * b_) & 0xFFFFFFFF
            elif f == 0x1B:                                      # DIVU
                a, b_ = r[rs], r[rt]
                if b_ == 0: self.lo = 0xFFFFFFFF; self.hi = a & 0xFFFFFFFF
                else: self.lo = (a // b_) & 0xFFFFFFFF; self.hi = (a % b_) & 0xFFFFFFFF
            elif f == 0x08: self.delay = r[rs]
            elif f == 0x09:
                t = r[rs]; r[rd] = (pc + 8) & 0xFFFFFFFF; self.delay = t
            else: raise Fault(f"unimplemented SPECIAL {f:#x} at {pc:#x}")
        elif op == 0x31:                                   # LWC1: low 32 bits only
            self.f[rt] = (self.f[rt] & ~0xFFFFFFFF) | self.m.read((r[rs] + si) & 0xFFFFFFFF, 4)
        elif op == 0x35:                                   # LDC1: whole register
            self.f[rt] = self.m.read((r[rs] + si) & 0xFFFFFFFF, 8)
        elif op == 0x39:                                   # SWC1: low 32 bits
            self.m.write((r[rs] + si) & 0xFFFFFFFF, 4, self.f[rt] & 0xFFFFFFFF)
        elif op == 0x3D:                                   # SDC1: whole register
            self.m.write((r[rs] + si) & 0xFFFFFFFF, 8, self.f[rt])
        elif op == 0x22:                                   # LWL
            a = (r[rs] + si) & 0xFFFFFFFF; sh = (3 - (a & 3)) * 8
            wv = self.m.read(a & ~3 & 0xFFFFFFFF, 4)
            r[rt] = (r[rt] & ((1 << sh) - 1)) | (wv << sh)
        elif op == 0x26:                                   # LWR
            a = (r[rs] + si) & 0xFFFFFFFF; sh = (a & 3) * 8
            wv = self.m.read(a & ~3 & 0xFFFFFFFF, 4)
            r[rt] = (r[rt] & ((1 << (32 - sh)) - 1) << sh) | (wv >> sh) if sh else wv
        elif op == 0x2A:                                   # SWL: big-endian, bytes k..3
            a = (r[rs] + si) & 0xFFFFFFFF; k = a & 3
            al = a & ~3 & 0xFFFFFFFF
            n = (4 - k) * 8                                # bits of the word SWL writes
            keep = (0xFFFFFFFF << n) & 0xFFFFFFFF if k else 0
            wv = self.m.read(al, 4)
            wv = (wv & keep) | ((r[rt] >> (k * 8)) & ((1 << n) - 1))
            self.m.write(al, 4, wv & 0xFFFFFFFF)
        elif op == 0x2F: pass                              # CACHE: no-op under emulation
        elif op == 0x2E:                                   # SWR: big-endian, bytes 0..k
            a = (r[rs] + si) & 0xFFFFFFFF; k = a & 3
            al = a & ~3 & 0xFFFFFFFF
            keep = (1 << ((3 - k) * 8)) - 1                # low bytes of the word survive
            wv = self.m.read(al, 4)
            wv = (wv & keep) | ((r[rt] & ((1 << ((k + 1) * 8)) - 1)) << ((3 - k) * 8))
            self.m.write(al, 4, wv & 0xFFFFFFFF)
        elif op == 0x11:                                   # COP1
            fs = (w >> 11) & 0x1F; fmt = rs; fn = w & 0x3F
            import struct as _s
            if fmt == 0x00: r[rt] = self.f[fs] & 0xFFFFFFFF          # MFC1: low half
            elif fmt == 0x02: r[rt] = self.fcr31           # CFC1
            elif fmt == 0x04:                              # MTC1: low half, high preserved
                self.f[fs] = (self.f[fs] & ~0xFFFFFFFF) | (r[rt] & 0xFFFFFFFF)
            elif fmt == 0x06: self.fcr31 = r[rt]           # CTC1
            elif fmt == 0x08:                              # BC1F / BC1T
                taken = bool(self.fcr31 & 0x800000)
                if (rt >> 2) & 1: taken = not taken
                if taken: self.delay = ((pc + 4) + (si << 2)) & 0xFFFFFFFF
            elif fmt in (0x10, 0x11, 0x14, 0x15):          # S/D/W/L arithmetic
                ft = (w >> 16) & 0x1F
                get = self.fget_s if fmt == 0x10 else self.fget_d
                a, b_ = get(fs), get(ft)
                if fn == 0x00: v = a + b_
                elif fn == 0x01: v = a - b_
                elif fn == 0x02: v = a * b_
                elif fn == 0x03: v = a / b_ if b_ else 0.0
                elif fn == 0x04: v = a ** 0.5 if a >= 0 else 0.0
                elif fn == 0x05: v = abs(a)
                elif fn == 0x06: v = a
                elif fn == 0x07: v = -a
                elif fn in (0x0C, 0x0D, 0x0E, 0x0F, 0x08, 0x09, 0x0A, 0x0B):
                    import math
                    v = {0x0C: round, 0x0D: math.trunc, 0x0E: math.ceil, 0x0F: math.floor,
                         0x08: round, 0x09: math.trunc, 0x0A: math.ceil, 0x0B: math.floor}[fn](a)
                elif fn == 0x20: v = a                    # cvt.s (rounded on store)
                elif fn == 0x21: v = float(a)             # cvt.d
                elif fn in (0x24, 0x25):                  # cvt.w / cvt.l
                    v = float(int(a)) if abs(a) < 2**31 else float(2**31 - 1)
                elif fn == 0x32 or fn == 0x3C or fn == 0x3E:   # c.eq / c.lt / c.le
                    cond = (a == b_) if fn == 0x32 else (a < b_) if fn == 0x3C else (a <= b_)
                    self.fcr31 = (self.fcr31 | 0x800000) if cond else (self.fcr31 & ~0x800000)
                    return
                else: raise Fault(f"COP1 fmt {fmt:#x} fn {fn:#x} unimplemented at {pc:#x}")
                if fmt == 0x10: self.fset_s((w >> 6) & 0x1F, v)     # S: low half, f32
                else:           self.fset_d((w >> 6) & 0x1F, v)     # D: whole register
            else: raise Fault(f"COP1 rs={fmt:#x} unimplemented at {pc:#x}")
        elif op in NAMED_OPS: raise Fault(f"{NAMED_OPS[op]} unimplemented at {pc:#x}")
        else: raise Fault(f"unimplemented op {op:#x} at {pc:#x}")

# ---------------------------------------------------------------- driver ----
BOOT_ROM, BOOT_VA = 0x1000, 0x80000480
STAGE2_VA = 0x80018A80
DESC_TABLE = 0x80012150
REGISTRY = 0x8010B2E0

class Harness:
    def __init__(self, rom, stage2):
        self.rom = rom
        ram = bytearray(RAM_SIZE)
        # copy code AND the boot data that follows it, because the descriptor table
        # lives at ROM 0x12cd0 (vram 0x80012150) — past the code end at 0x12140.
        # Clipping at the code end silently makes every descriptor read as zeros.
        boot_len = 0x14600 - 0x1000
        ram[BOOT_VA - RAM_BASE:BOOT_VA - RAM_BASE + boot_len] = rom[0x1000:0x14600]
        ram[STAGE2_VA - RAM_BASE:STAGE2_VA - RAM_BASE + len(stage2)] = stage2
        self.mem = Memory(ram, rom)
        self.trace = []
        self.hooks = {}
        self._install()
    # ---- hooks: the compression primitive is real, the OS is stubbed --------
    def _install(self):
        st = {}
        def inflate_init(cpu, a0, a1, a2, a3):
            st[a0] = a1; return 0
        def inflate_run(cpu, a0, a1, a2, a3):
            raw = bytes(cpu.m.read(a1 + i, 1) for i in range(a3))
            try: out = zlib.decompress(raw)
            except Exception as e:
                self.trace.append({"src": a1, "dst": a2, "csize": a3, "usize": -1,
                                   "err": str(e)[:40]}); return 1
            for i, b in enumerate(out): cpu.m.write(a2 + i, 1, b)
            self.trace.append({"src": a1, "dst": a2, "csize": a3, "usize": len(out)})
            return 0
        def inflate_free(cpu, a0, a1, a2, a3): return 0
        def raw_pi_dma(cpu, a0, a1, a2, a3):
            for i in range(a3): cpu.m.write(a2 + i, 1, self.rom[(a1 + i) & CART_MASK])
            self.trace.append({"dma_cart": a1, "dma_dst": a2, "len": a3})
            return 0
        def wait(cpu, *a): return 0
        self.hooks.update({
            0x80004550: inflate_init, 0x800045DC: inflate_run, 0x80004594: inflate_free,
            0x8000C870: raw_pi_dma, 0x8000BE50: wait, 0x8000BE60: wait,
            0x80006D60: wait, 0x8000DB90: wait, 0x80006D30: wait, 0x8000C9E0: wait,
            0x8000CB60: wait, 0x8000E920: wait, 0x8000CEC0: wait, 0x8000E350: wait,
            0x800072E0: wait, 0x80007300: wait, 0x8000CC90: wait, 0x8000E4C0: wait,
            0x8000E800: wait,
        })
    def run(self, entry, **kw):
        cpu = Cpu(self.mem, self.hooks)
        n = cpu.run(entry, **kw)
        return cpu, n
    def u32(self, va): return self.mem.read(va, 4)

def main():
    rom = open("rom/Resident Evil 2 (USA) (Rev 1).z64", "rb").read()
    stage2 = open("assets/unpacked/00000_0014420_1172240.bin", "rb").read()
    h = Harness(rom, stage2)

    print("=== run 1: FUN_8004d190 (stage-2 init), OS calls stubbed ===")
    h.hooks[0x8008AF6C] = lambda c, *a: 0
    h.hooks[0x80088910] = lambda c, *a: 0
    h.hooks[0x8006CB94] = lambda c, *a: 0
    h.hooks[0x80000518] = lambda c, *a: 0
    cpu, n = h.run(0x8004D190)
    print(f"  {n} instructions, {len(cpu.calls)} hook call(s): "
          f"{[c[0] for c in cpu.calls]}")
    for g, label in ((0x8010B6FC, "inflate window"), (0x801137F0, "screen w"), (0x801137F4, "screen h")):
        print(f"  {label:14} @{g:#010x} = {h.u32(g):#010x}")

    print("\n=== run 2: func_0x80000518 (the last call in FUN_8004d190, boot bank) ===")
    h.hooks.pop(0x80000518, None)   # run 1 stubbed it; remove so it actually executes
    cpu2, n2 = h.run(0x80000518)
    print(f"  {n2} instructions, hooks: "
          f"{[(c[0], format(c[1],'#010x'), [hex(x) for x in c[2]]) for c in cpu2.calls]}")
    print(f"  trace rows from this run: {len(h.trace)}")

    print("\n=== run 3: FUN_8004cbf4(desc) for every registry slot, inflate real ===")
    h.trace.clear()
    print(f"  {'slot':>4} {'desc idx':>8} {'src ptr':>11} {'csize':>9} {'dst':>11} {'usize':>9}  manifest")
    import json
    man = {m["rom_offset"]: m for m in json.load(open("assets/unpacked/manifest.json"))["members"]}
    for slot in range(9):
        idx = rom and h.mem.read(REGISTRY + slot*8, 1)
        dp = DESC_TABLE + idx*16
        before = len(h.trace)
        cpu3, n3 = h.run(0x8004CBF4, a0=dp)
        row = h.trace[before] if len(h.trace) > before else None
        if row and "src" in row:
            cartoff = row["src"] & CART_MASK
            m = man.get(cartoff)
            ok = "match" if m and m["uncompressed"] == row["usize"] else "CHECK"
            print(f"  {slot:>4} {idx:>8} {format(row['src'],'#010x')} {row['csize']:>9,} "
                  f"{format(row['dst'],'#010x')} {row['usize']:>9,}  {ok}")
        else:
            print(f"  {slot:>4} {idx:>8} — no inflate call ({n3} instructions)")
    print(f"\n  total inflate trace rows: {len(h.trace)}")

if __name__ == "__main__":
    main()
