#!/usr/bin/env python3
"""Cross-reference scanner for the overlay registry at 0x8010b2e0.

Why not an exact-address grep: MIPS has no absolute store. A write to the registry
is always built at runtime — `lui`+`addiu`/`ori` into a register, or an offset off
a register that already holds the base. So this scanner does a bounded abstract
interpretation: it tracks, per register, a known absolute constant, invalidating
on any write to that register and on caller-saved registers across a `jal`.

It reports four things per image:
  CONSTRUCT  the registry address is built in a register
  STORE      a store whose effective address lands in the registry window
  ARG        the constructed address is passed as an argument (block copy, memcpy)
  READ       a load from the window (who observes the current selection)

Every hit carries the containing function start, so a sequence can be reconstructed
by function. The cartridge image is opened read-only.
"""
import argparse, hashlib, struct, sys

CALLER_SAVED = set(range(2, 16)) | {24, 25, 31}   # v0-v1, a0-a3, t0-t9, ra

class Dec:
    def __init__(self, buf, base):
        self.w = struct.unpack(f">{len(buf)//4}I", buf[:len(buf)//4*4])
        self.base = base
    def __len__(self): return len(self.w)

def scan(buf, base, lo, hi, verbose=False):
    d = Dec(buf, base)
    reg = {}                 # register -> known 32-bit constant
    alias = {}               # global address -> value stored there (pointer aliasing)
    fn = None
    hits = []
    for i in range(len(d)):
        x = d.w[i]; pc = base + i*4
        op = x >> 26; rs = (x >> 21) & 0x1F; rt = (x >> 16) & 0x1F
        rd = (x >> 11) & 0x1F; imm = x & 0xFFFF
        simm = imm - 0x10000 if imm >= 0x8000 else imm
        # function boundary: addiu sp,sp,-N
        if op == 0x09 and rs == rt == 29 and simm < 0:
            fn = pc; reg.clear()
        if op == 0x0F:                                   # lui
            reg[rt] = imm << 16
            continue
        if op == 0x09 and rs in reg:                     # addiu
            reg[rt] = (reg[rs] + simm) & 0xFFFFFFFF
            _note(hits, lo, hi, pc, fn, "CONSTRUCT", reg[rt], None); continue
        if op == 0x0D and rs in reg:                     # ori
            reg[rt] = reg[rs] | imm
            _note(hits, lo, hi, pc, fn, "CONSTRUCT", reg[rt], None); continue
        if op == 0 and (x & 0x3F) == 0x21:               # addu rd, rs, rt
            if rs in reg and rt in reg: reg[rd] = (reg[rs] + reg[rt]) & 0xFFFFFFFF
            elif rs in reg: reg[rd] = reg[rs]
            elif rt in reg: reg[rd] = reg[rt]
            else: reg.pop(rd, None)
            continue
        if op in (0x28, 0x29, 0x2B):                     # sb / sh / sw
            if rs in reg:
                addr = (reg[rs] + simm) & 0xFFFFFFFF
                width = {0x28: 1, 0x29: 2, 0x2B: 4}[op]
                val = reg.get(rt)
                _note(hits, lo, hi, pc, fn, "STORE", addr, val, width)
                # a pointer to the window stored into a global becomes an alias,
                # so a later lw of that global resolves back to the window. This is
                # the "pointer held in another variable" case an exact-address grep
                # and plain constant tracking both miss.
                if val is not None and lo <= val < hi:
                    alias[addr] = val
            continue
        if op in (0x20, 0x24, 0x23):                     # lb / lbu / lw
            if rs in reg:
                addr = (reg[rs] + simm) & 0xFFFFFFFF
                _note(hits, lo, hi, pc, fn, "READ", addr, None, None)
                if op == 0x23 and addr in alias:
                    reg[rt] = alias[addr]                # pointer reloaded from a global
                    continue
            reg.pop(rt, None); continue
        if op == 0x03:                                   # jal: address often an arg
            for r in (4, 5, 6, 7):
                if r in reg:
                    _note(hits, lo, hi, pc, fn, "ARG", reg[r], None, None)
            for r in CALLER_SAVED: reg.pop(r, None)
            continue
        if op == 0 and (x & 0x3F) in (0x08, 0x09):       # jr / jalr
            for r in CALLER_SAVED: reg.pop(r, None)
            continue
        # any other instruction that writes rt invalidates it
        writes_rt = op in (0x08, 0x0A, 0x0B, 0x0C, 0x0E, 0x0F, 0x18, 0x19, 0x1A, 0x1C,
                           0x21, 0x22, 0x25, 0x26, 0x2A, 0x2E, 0x30, 0x32, 0x34, 0x35,
                           0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F) \
                   or (op == 0 and (x & 0x3F) not in (0x08, 0x09, 0x21))
        if writes_rt and rt: reg.pop(rt, None)
        if op == 0:
            reg.pop(rd, None)
    return hits

def _note(hits, lo, hi, pc, fn, kind, addr, value, width=None):
    if addr is not None and lo <= addr < hi:
        hits.append((pc, fn, kind, addr, value, width))

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image")
    ap.add_argument("--base", type=lambda s: int(s, 0), required=True)
    ap.add_argument("--offset", type=lambda s: int(s, 0), default=0)
    ap.add_argument("--length", type=lambda s: int(s, 0), default=0)
    ap.add_argument("--target", type=lambda s: int(s, 0), default=0x8010B2E0)
    ap.add_argument("--span", type=lambda s: int(s, 0), default=0x48,
                    help="registry window size (9 slots x 8 = 0x48)")
    ap.add_argument("--label", default="")
    a = ap.parse_args()

    before = hashlib.sha256(open(a.image, "rb").read()).hexdigest()
    with open(a.image, "rb") as f:
        f.seek(a.offset); buf = f.read(a.length) if a.length else f.read()
    hits = scan(buf, a.base + a.offset, a.target, a.target + a.span)
    print(f"{a.label or a.image}: base {a.base:#x} (+{a.offset:#x}), {len(buf):,} B, "
          f"window {a.target:#x}..{a.target+a.span:#x}")
    if not hits:
        print("  no construction, store, argument or read touching the window")
    else:
        print(f"  {'at':>11} {'in function':>11} {'kind':>9} {'address':>11} {'value':>11} {'w':>2}")
        for pc, fn, kind, addr, value, width in hits:
            vs = format(value, "#010x") if value is not None else "?"
            print(f"  {pc:#011x} {(fn if fn is not None else 0):#011x} {kind:>9} "
                  f"{addr:#011x} {vs:>11} {width if width else '':>2}")
    after = hashlib.sha256(open(a.image, "rb").read()).hexdigest()
    assert before == after, "image changed — investigate"

if __name__ == "__main__":
    main()
