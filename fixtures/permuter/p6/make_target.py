#!/usr/bin/env python3
"""Build `target.o` — the permuter's objective — from the image's own words.

decomp-permuter needs a relocatable object to diff candidates against. Until M302 this directory shipped a
`target-draft.o`: 116 instructions compiled from an earlier draft of the function, which is a *proxy* — the
function in the image is 98 instructions. This script builds the real thing instead: it reads the function's
words straight out of the stage-2 image, assembles them, and verifies that the object's `.text` is
byte-identical to the image before writing it.

The result is deliberately **not committed**: it is 392 bytes of the cartridge's own code, and this repository
commits no cartridge content (`*.o` is ignored for the same reason). Regenerate it with the ROM present:

    python3 fixtures/permuter/p6/make_target.py            # -> fixtures/permuter/p6/target.o
    python3 fixtures/permuter/p6/make_target.py --check    # verify an existing target.o, write nothing

Two details worth knowing:

- The words go through `.word` directives rather than a disassembly round-trip, so the assembler cannot
  "improve" anything: the bytes are the image's by construction.
- The image's pool reference (`lui v0,0x800c` / `addiu v0,-29744` = `0x800B8BD0`, the switch table) is
  therefore *resolved*, while a candidate object carries `R_MIPS_HI16`/`R_MIPS_LO16` against its own local
  table label. That is a real asymmetry of any extracted target, and it is why the word metric — which links
  both sides — stays the verdict and the permuter's score is a search signal.
"""
from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent.parent
TC = ROOT / "build" / "toolchain"
IMAGE = ROOT / "assets" / "unpacked" / "00000_0014420_1172240.bin"
BASE = 0x80018A80
ADDR = 0x8004FD1C
WORDS = 98


def object_bytes(path: Path) -> bytes:
    out = path.with_suffix(".text.bin")
    subprocess.run([str(TC / "binutils" / "bin" / "mips-linux-gnu-objcopy"), "-O", "binary",
                    "--only-section=.text", str(path), str(out)], check=True)
    blob = out.read_bytes()
    out.unlink()
    return blob


def main(argv: list[str]) -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--addr", default=hex(ADDR))
    ap.add_argument("--words", type=int, default=WORDS)
    ap.add_argument("--base", default=hex(BASE))
    ap.add_argument("--image", default=str(IMAGE))
    ap.add_argument("--image-offset", default="0",
                    help="byte offset of the image inside --image; boot needs 0x1000 (rom at 0x1000)")
    ap.add_argument("--out", default=str(HERE / "target.o"))
    ap.add_argument("--symbol", default="f", help="name to give the function in the object")
    ap.add_argument("--check", action="store_true", help="verify the existing target.o, write nothing")
    a = ap.parse_args(argv)

    image, addr, base = Path(a.image), int(a.addr, 16), int(a.base, 16)
    ioff = int(a.image_offset, 16)
    if not image.exists():
        print("no image at %s — this needs your own dump (see README)" % image, file=sys.stderr)
        return 2
    want = image.read_bytes()[ioff + addr - base:ioff + addr - base + 4 * a.words]
    if len(want) != 4 * a.words:
        print("address 0x%x is outside the image" % addr, file=sys.stderr)
        return 2

    out = Path(a.out)
    if a.check:
        if not out.exists():
            print("FAIL no %s to check" % out.name)
            return 1
        got = object_bytes(out)
        ok = got == want
        print("%s %s .text is %d B and identical to the image" % ("PASS" if ok else "FAIL", out.name, len(got))
              if ok else "FAIL %s .text is %d B, image is %d B" % (out.name, len(got), len(want)))
        return 0 if ok else 1

    s = out.with_suffix(".s")
    sym = a.symbol
    s.write_text(".text\n\t.globl\t%s\n\t.ent\t%s\n%s:\n" % (sym, sym, sym)
                 + "".join("\t.word\t0x%08x\n" % int.from_bytes(want[4 * i:4 * i + 4], "big")
                           for i in range(a.words))
                 + "\t.end\t%s\n" % sym)
    as27 = TC / "src" / "bu27-build" / "gas" / "as.new"
    gas = as27 if as27.exists() else TC / "binutils" / "bin" / "mips-linux-gnu-as"
    raw = out.with_suffix(".raw.o")
    sect = out.with_suffix(".section.bin")
    sect.write_bytes(want)
    subprocess.run([str(gas), "-EB", "-mips2", "-G", "0", "-o", str(raw), str(s)], check=True)
    # the object needs valid ELF arch flags (a raw `objcopy -I binary` object does not disassemble), and it
    # must be trimmed back to exactly the function: `as` pads .text out to its 16-byte section alignment.
    subprocess.run([str(TC / "binutils" / "bin" / "mips-linux-gnu-objcopy"),
                    "--update-section=.text=%s" % sect,
                    "--set-section-alignment", ".text=4", str(raw), str(out)], check=True)
    for tmp in (raw, s, sect):
        tmp.unlink(missing_ok=True)

    got = object_bytes(out)
    if got != want:
        print("FAIL assembled .text is %d B, image is %d B" % (len(got), len(want)), file=sys.stderr)
        return 1
    print("wrote %s — %d words, %d B, byte-identical to the image at %s"
          % (out, a.words, len(got), a.addr))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
