#!/usr/bin/env python3
"""Resolve a virtual address to the image that actually contains it — and refuse to guess.

Three of this project's last four wrong numbers came from the same place: an ad-hoc command
composing an address by hand.

  1. `lui 0x800c` + `addiu -23464` composed as `ori`, giving `0x800ca458` instead of `0x800ba458`
     — the case tables looked empty and a runtime writer was hunted for two sessions;
  2. `lw v0,-19868(0x800f0000)` composed as `+ 0xb264`, giving `0x800fb264` instead of
     `0x800eb264` — where a valid pointer had been sitting all along;
  3. `0x80004550` read out of the *stage-2* image, when it lives in the **boot bank** (the negative
     offset silently sliced from the wrong end of the buffer).

All three are one mistake: the address was computed in the head instead of by a tool that knows the
address space. So this tool does three things and refuses to do a fourth:

  * `sext16(imm)` and `compose(hi, imm, mode)` make the sign explicit — `mode` is `add` or `or`, and
    there is no default, because the default is what went wrong;
  * `locate(vaddr)` returns every image whose load range contains the address **plus** the offset in
    that image's bytes, and raises when more than one image matches unless the caller names one
    (twenty overlays share `0x80161cf0`, so a bare address genuinely does not identify an image);
  * `read(vaddr, n)` reads through `locate`, so the offset is never typed by hand.

Usage:
  ./vaddr.py 0x80004550            # which image, what offset, first words
  ./vaddr.py --self-test           # the three historical mistakes, as assertions
"""
import argparse
import struct
import sys
from pathlib import Path

ROM_GLOB = "rom/*.z64"
UNPACKED = "assets/unpacked"
IMAGES = "build/elfs/images.json"
ROM_TO_VRAM = 0x7FFFF480          # linear map for the boot bank only


def sext16(imm: int) -> int:
    """The 16-bit immediate as the CPU sees it: signed."""
    imm &= 0xFFFF
    return imm - 0x10000 if imm & 0x8000 else imm


def compose(hi: int, imm: int, mode: str) -> int:
    """`lui` high half plus a 16-bit immediate. `mode` is required and must be 'add' or 'or'."""
    if mode == "add":
        return ((hi & 0xFFFF) << 16) + sext16(imm)
    if mode == "or":
        return ((hi & 0xFFFF) << 16) | (imm & 0xFFFF)
    raise ValueError(f"mode must be 'add' or 'or', not {mode!r} — the default is the bug")


def sources() -> dict:
    """Every byte range that maps at a vaddr: the boot bank (via ROM) and each built image."""
    out = []
    rom = Path(sorted(Path().glob(ROM_GLOB))[0]).read_bytes()
    # the boot bank AND the boot data that follows it: ROM 0x1000..0x14420 is all mapped
    # linearly, and stopping at the code end (0x800115C0) hid the .rodata the code reads —
    # 0x80011860 among others. A tool boundary that is too narrow fails the same way as a
    # hand-computed constant: quietly, with a plausible answer.
    out.append(dict(name="boot", lo=0x80000480, hi=0x80000480 + 0x13420,
                    data=rom[0x1000:0x14420],
                    note="ROM 0x1000..0x14420, linear via +0x7FFFF480; 0x14420 is canonical "
                         "(the first zlib member starts there, see unpack_zlib.py). The harness "
                         "loads to 0x14600, i.e. 480 B of that member as padding."))
    if Path(IMAGES).exists():
        import json
        for img in json.loads(Path(IMAGES).read_text())["images"]:
            if img["name"] == "boot":
                continue
            p = Path("build/elfs") / f"{img['name']}.elf"
            if not p.exists():
                continue
            out.append(dict(name=img["name"], lo=img["base"], hi=img["base"] + img["size"],
                            data=p.read_bytes()[0x100:0x100 + img["size"]],
                            note=f"built ELF at {img['base']:#010x}"))
    return out


def locate(vaddr: int, name: str = None) -> dict:
    hits = [s for s in sources() if s["lo"] <= vaddr < s["hi"]]
    if name:
        hits = [h for h in hits if h["name"] == name]
    if not hits:
        raise LookupError(f"{vaddr:#010x} is in no image (unpacked overlays are only reachable by "
                          f"the ELF that holds them)")
    if len(hits) > 1:
        raise LookupError(f"{vaddr:#010x} is in {len(hits)} images "
                          f"({', '.join(h['name'] for h in hits[:6])}…) — name one; an address "
                          f"does not identify an image when images share a load address")
    return hits[0]


def read(vaddr: int, n: int = 4, name: str = None) -> bytes:
    s = locate(vaddr, name)
    o = vaddr - s["lo"]
    return s["data"][o:o + n]


def word(vaddr: int, name: str = None) -> int:
    return struct.unpack(">I", read(vaddr, 4, name))[0]


def self_test() -> int:
    """The three mistakes, as assertions. If any of these fails the tool is not worth using."""
    bad = 0
    cases = [
        # (label, what was computed, what is right)
        ("addiu sign", compose(0x800C, 0xA458, "add"), 0x800BA458),
        ("lw offset",  0x800F0000 + sext16(0xB264),    0x800EB264),
        ("ori reading", compose(0x800C, 0xA458, "or"), 0x800CA458),
    ]
    for label, got, want in cases:
        ok = got == want
        print(f"  {label:14s} got {got:#010x} want {want:#010x}  {'ok' if ok else 'FAIL'}")
        bad += 0 if ok else 1
    # the third mistake: the boot bank is not in the stage-2 image
    try:
        s = locate(0x80004550)
        ok = s["name"] == "boot"
        print(f"  image choice   0x80004550 -> {s['name']} at +{0x80004550 - s['lo']:#x}  "
              f"{'ok' if ok else 'FAIL'}")
        bad += 0 if ok else 1
    except LookupError as exc:
        print(f"  image choice   FAIL {exc}")
        bad += 1
    # an address shared by many overlays must refuse to resolve
    try:
        locate(0x80161CF0 + 0x1000)
        print("  ambiguity      FAIL: resolved a shared address without being told which image")
        bad += 1
    except LookupError:
        print("  ambiguity      refused to resolve a shared address  ok")
    # and must resolve when told
    try:
        s = locate(0x80164CF4, name="ovl_007fc12")
        print(f"  named          0x80164cf4 in {s['name']}  ok")
    except LookupError as exc:
        print(f"  named          FAIL {exc}")
        bad += 1
    return bad


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("vaddr", nargs="?", help="address to resolve, e.g. 0x80004550")
    ap.add_argument("--image", default=None, help="disambiguate when images share a base")
    ap.add_argument("--words", type=int, default=8)
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()

    if a.self_test:
        sys.exit(1 if self_test() else 0)
    if not a.vaddr:
        ap.error("give an address or --self-test")
    vaddr = int(a.vaddr, 0)
    s = locate(vaddr, a.image)
    off = vaddr - s["lo"]
    print(f"{vaddr:#010x} -> {s['name']} at offset +{off:#x} ({s['note']})")
    for i in range(a.words):
        try:
            w = word(vaddr + 4 * i, s["name"])
        except Exception:
            break
        print(f"  {vaddr + 4 * i:#010x}  {w:08x}")


if __name__ == "__main__":
    main()
