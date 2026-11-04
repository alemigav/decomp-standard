#!/usr/bin/env python3
"""Find code that writes into the two staging banks, regardless of where the value came from.

`find_store_loops.py` requires the *stored value* to be constructed in the instruction stream,
because it is hunting table initialisers. That guard makes it the wrong instrument for the bank-C
loader: a loader reads a cart offset or a descriptor field — the value arrives from memory, so every
candidate it produces would be rejected, and the "negative" would be a tool mismatch rather than a
finding.

This tool inverts the question. It does not care how the value was produced; it asks **where the
store goes**. The destination is what identifies a loader:

  * the two installed bases are `0x80161cf0` (bank B) and `0x8016e880` (bank C);
  * each payload is at most 52 112 B, so a window of 64 KB from each base covers every legitimate
    write into either bank;
  * a store inside that window is reported with its value's provenance — constructed constant,
    loaded from memory, or unknown — so a copy loop and a table fill are told apart by data, not by
    the shape of the code.

It also reports **calls to the known loader primitives** whose destination argument points into a
bank, because the loader may never store directly: `inflate` (`0x800045dc`), `inflate_init`
(`0x80004550`), the PI DMA starter (`0x8000c870`) and the DMA programmer (`0x80007c20`) all take a
destination, and the harness already hooks them.

Usage:
  ./find_bank_writers.py --images build/elfs/images.json --out manifests/bank_writers.json
"""
import argparse
import json
import struct
from pathlib import Path

BANK_B, BANK_C = 0x80161CF0, 0x8016E880
WINDOW = 0x10000                                  # 64 KB covers the largest payload (52 112 B)
BANKS = {"bankB": (BANK_B, BANK_B + WINDOW), "bankC": (BANK_C, BANK_C + WINDOW)}
STORES = {0x2B: "sw", 0x29: "sh", 0x28: "sb", 0x3F: "sd", 0x2C: "sdl", 0x2E: "sdr",
          0x2A: "swl", 0x3A: "swr"}
LOADER_CALLS = {0x800045DC: "inflate", 0x80004550: "inflate_init",
                0x8000C870: "pi_dma_raw", 0x80007C20: "pi_dma_programmer"}
ARG_REGS = [4, 5, 6]                              # a0, a1, a2


def image_bytes(elf: Path, size: int) -> bytes:
    return elf.read_bytes()[0x100:0x100 + size]


def constants(words: list) -> list:
    """Forward pass: what constructed constant each register holds before each instruction.

    Same discipline as find_store_loops: `lui` + `ori`/`addiu` (signed), `addu`/`or` of two knowns,
    `li rt,imm`; anything else that writes a register clears it. A value that came from memory is
    never treated as a constant — here that matters only for *reporting provenance*, not for
    accepting a store.
    """
    out, pending = [], {}
    for w in words:
        op = w >> 26
        rd = (w >> 11) & 0x1F if op == 0 else (w >> 16) & 0x1F
        rs, rt = (w >> 21) & 0x1F, (w >> 16) & 0x1F
        val = None
        if op == 0x0F:
            val = (w & 0xFFFF) << 16
        elif op in (0x0D, 0x09) and rs in pending:
            val = pending[rs] | (w & 0xFFFF) if op == 0x0D else pending[rs] + (
                (w & 0xFFFF) - 0x10000 if w & 0x8000 else (w & 0xFFFF))
        elif op == 0x09 and rs == 0:
            val = w & 0xFFFF
        elif op == 0 and (w & 63) == 0x21 and rs in pending and rt in pending:
            val = pending[rs] + pending[rt]
        elif op == 0 and (w & 63) == 0x25 and rs in pending and rt in pending:
            val = pending[rs] | pending[rt]
        out.append(dict(pending))
        if op not in (0x2B, 0x29, 0x28, 0x3F, 0x2C, 0x2E, 0x2A, 0x3A,
                      0x04, 0x05, 0x06, 0x07, 0x01, 0x02, 0x03):
            if val is not None:
                pending[rd] = val
            else:
                pending.pop(rd, None)
    return out


def provenance(state: dict, reg: int) -> str:
    if reg in state:
        return f"constructed {state[reg]:#010x}"
    if reg == 0:
        return "zero"
    return "from memory or unknown"


def scan(code: bytes, base: int) -> dict:
    n = len(code) // 4
    words = list(struct.unpack(f">{n}I", code[:n * 4]))
    state = constants(words)
    stores, calls = [], []
    for i, w in enumerate(words):
        op = w >> 26
        pc = base + i * 4
        s = state[i - 1] if i else {}
        if op in STORES:
            rs, rt, off = (w >> 21) & 0x1F, (w >> 16) & 0x1F, w & 0xFFFF
            if rs not in s:
                continue
            addr = s[rs] + (off - 0x10000 if off & 0x8000 else off)
            for bank, (lo, hi) in BANKS.items():
                if lo <= addr < hi:
                    stores.append(dict(pc=hex(pc), bank=bank, addr=hex(addr),
                                       op=STORES[op], source=provenance(s, rt)))
        elif op == 0x03:
            tgt = (pc & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            if tgt in LOADER_CALLS:
                # the destination argument will be in a0/a1/a2 from the last ~6 instructions
                args = {r: s.get(r) for r in ARG_REGS if r in s}
                in_bank = {r: v for r, v in args.items()
                           if any(lo <= v < hi for lo, hi in BANKS.values())}
                calls.append(dict(pc=hex(pc), target=hex(tgt), primitive=LOADER_CALLS[tgt],
                                  args={f"a{i}": hex(v) for i, v in zip(
                                      [0, 1, 2], (args.get(4), args.get(5), args.get(6)))
                                      if v is not None},
                                  destination_in_bank=bool(in_bank)))
    return dict(stores=stores, calls=calls)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--images", default="build/elfs/images.json")
    ap.add_argument("--elfs", default="build/elfs")
    ap.add_argument("--out", default="manifests/bank_writers.json")
    a = ap.parse_args()

    images = json.loads(Path(a.images).read_text())["images"]
    report, totals = {"tool": "find_bank_writers.py",
                      "banks": {k: [hex(v[0]), hex(v[1])] for k, v in BANKS.items()},
                      "images": []}, [0, 0]
    for img in images:
        code = image_bytes(Path(a.elfs) / f"{img['name']}.elf", img["size"])
        got = scan(code, img["base"])
        if not (got["stores"] or got["calls"]):
            continue
        report["images"].append(dict(name=img["name"], **got))
        totals[0] += len(got["stores"])
        totals[1] += len(got["calls"])

    Path(a.out).write_text(json.dumps(report, indent=1) + "\n")
    print(f"{totals[0]} stores into a staging bank, {totals[1]} calls to a loader primitive")
    for i in report["images"]:
        for s in i["stores"][:8]:
            print(f"  {i['name']:>16} {s['pc']} {s['op']:>3} -> {s['addr']} ({s['bank']})  "
                  f"value {s['source']}")
        for c in i["calls"][:8]:
            flag = "DESTINATION IN BANK" if c["destination_in_bank"] else ""
            print(f"  {i['name']:>16} {c['pc']} jal {c['primitive']} args {c['args']} {flag}")
    print(f"\nwrote {a.out}")


if __name__ == "__main__":
    main()
