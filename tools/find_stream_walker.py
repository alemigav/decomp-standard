#!/usr/bin/env python3
"""Find code that walks the cartridge window (KSEG1 0xB0000000-0xB3FFFFFF).

The boot chain hands `desc[0]` — a KSEG1 cart pointer like 0xB0074420 — straight to
inflate. If any routine walks successive cart pointers, it must: hold such a value
in a register, load through it, advance it, and compare against a bound. This
scanner classifies registers as "cart pointer" (a constructed constant in the
window, or derived from one by addiu/addu), then reports every load through such a
register together with the *enclosing backward branch* and the constant it compares
against — the loop bound.

Deliberately conservative: a value that came out of memory is never treated as a
cart pointer (only constructed constants are), because "loaded from RAM" is exactly
where this kind of analysis invents structure. A loop with no constant comparison
is reported with bound UNKNOWN rather than guessed.
"""
import argparse, hashlib, struct

LO, HI = 0xB0000000, 0xB4000000          # KSEG1 cartridge window
CALLER_SAVED = set(range(2, 16)) | {24, 25, 31}

def is_cart(v): return v is not None and LO <= v < HI

def analyse(buf, base, label):
    w = struct.unpack(f">{len(buf)//4}I", buf[:len(buf)//4*4])
    reg = {}          # reg -> constructed constant (only ever set from immediates)
    fn = None
    events = []
    branches = []     # (pc, target, bound_reg, bound_value)
    for i, x in enumerate(w):
        pc = base + i*4
        op = x >> 26; rs = (x >> 21) & 0x1F; rt = (x >> 16) & 0x1F
        rd = (x >> 11) & 0x1F; imm = x & 0xFFFF
        simm = imm - 0x10000 if imm >= 0x8000 else imm
        if op == 0x09 and rs == rt == 29 and simm < 0:
            fn = pc; reg.clear()
        elif op == 0x0F:
            reg[rt] = imm << 16
            continue
        elif op == 0x09 and rs in reg:
            reg[rt] = (reg[rs] + simm) & 0xFFFFFFFF
            if is_cart(reg[rt]) and is_cart(reg.get(rs)):
                events.append((pc, fn, "ADVANCE", rs, simm, reg[rt]))
            continue
        elif op == 0x0D and rs in reg:
            reg[rt] = reg[rs] | imm; continue
        elif op == 0 and (x & 0x3F) == 0x21:
            if rs in reg and rt in reg: reg[rd] = (reg[rs] + reg[rt]) & 0xFFFFFFFF
            elif rs in reg: reg[rd] = reg[rs]
            elif rt in reg: reg[rd] = reg[rt]
            else: reg.pop(rd, None)
            continue
        elif op in (0x20, 0x24, 0x23):
            if is_cart(reg.get(rs)):
                width = {0x20: 1, 0x24: 1, 0x23: 4}[op]
                events.append((pc, fn, f"LOAD{width*8}", rs, simm, reg[rs] + simm))
            reg.pop(rt, None); continue
        elif op in (0x28, 0x29, 0x2B):
            if is_cart(reg.get(rs)):
                events.append((pc, fn, "STORE_TO_CART", rs, simm, reg[rs] + simm))
            continue
        elif op in (0x04, 0x05, 0x06, 0x07):
            tgt = pc + 4 + (simm << 2)
            bound = None; breg = None
            if op in (0x04, 0x05):                  # beq / bne rs, rt
                if rt in reg: bound, breg = reg[rt], rt
                elif rs in reg: bound, breg = reg[rs], rs
            if tgt < pc:
                branches.append((pc, tgt, breg, bound))
            if op in (0x04, 0x05):
                for r in (rs, rt):
                    if r not in reg: pass
            continue
        if op == 0x03:
            for r in CALLER_SAVED: reg.pop(r, None)
            continue
        if op == 0 and (x & 0x3F) in (0x08, 0x09):
            for r in CALLER_SAVED: reg.pop(r, None)
            continue
        if rt: reg.pop(rt, None)
        if op == 0: reg.pop(rd, None)

    # attach each cart event to the innermost enclosing backward branch
    out = []
    for pc, fnx, kind, r, off, addr in events:
        loops = [b for b in branches if b[1] <= pc <= b[0]]
        best = min(loops, key=lambda b: b[0]-b[1]) if loops else None
        bound = ("UNKNOWN" if best is None or best[3] is None
                 else format(best[3], "#x"))
        loop = ("-" if best is None else f"{best[1]:#x}..{best[0]:#x}")
        out.append((pc, fnx, kind, r, off, addr if addr < 0x100000000 else 0, loop, bound))
    print(f"\n{label}  (base {base:#x}, {len(buf):,} B)")
    if not out:
        print("  no register ever holds a constructed KSEG1 cart pointer in this image")
        return out
    print(f"  {'at':>11} {'function':>11} {'event':>16} {'addr':>11} {'loop':>21} {'bound':>9}")
    for pc, fnx, kind, r, off, addr, loop, bound in out:
        print(f"  {pc:#011x} {(fnx or 0):#011x} {kind:>16} {addr:#011x} {loop:>21} {bound:>9}")
    return out

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image")
    ap.add_argument("--base", type=lambda s: int(s, 0), required=True)
    ap.add_argument("--offset", type=lambda s: int(s, 0), default=0)
    ap.add_argument("--length", type=lambda s: int(s, 0), default=0)
    ap.add_argument("--label", default="")
    a = ap.parse_args()
    h1 = hashlib.sha256(open(a.image, "rb").read()).hexdigest()
    with open(a.image, "rb") as f:
        f.seek(a.offset); buf = f.read(a.length) if a.length else f.read()
    analyse(buf, a.base + a.offset, a.label or a.image)
    assert h1 == hashlib.sha256(open(a.image, "rb").read()).hexdigest()

if __name__ == "__main__":
    main()
