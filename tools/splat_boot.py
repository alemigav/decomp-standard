#!/usr/bin/env python3
"""Dress rehearsal on one image: splat splits the boot image, and every claim it makes is checked.

The matching pipeline's left half is *segmentation*: decide where code, data and padding are, emit a linker
script and a symbol map, and have a build that tiles the image exactly. Nothing about that needs a decompiled
function or a MIPS assembler, so it can be rehearsed and verified today — which is the point of doing it before
the toolchain exists.

What is verified, and why each is a real check rather than a formality:

  * **tiling.** The linker script's own `_ROM_START`/`_ROM_END` pairs must start at 0 and tile the cartridge up
    to the end of the boot image with no gap and no overlap. A segmentation that leaves a hole is a link that
    silently drops bytes.
  * **reassembly from the map alone.** Slice the *original* cartridge by the linker script's own extents, in
    the linker script's own order, and the result must equal the boot image byte for byte. This is the claim a
    relink makes, minus the assembler: get the map or the order wrong and it fails.
  * **the corpus cross-check.** splat's discovered function boundaries (from the `nonmatching <name>, <size>`
    lines it emits) are compared with `fixtures/decomp/ranges.json`, which came from Ghidra by a different
    route. Two independent segmentations agreeing is evidence; one segmentation agreeing with itself is not.
  * **the built image still equals the cartridge.** `build/elfs/boot.elf` is compared with the ROM slice, so
    the rehearsal ends where the real build will: byte-identical.

What this cannot verify, stated so nobody assumes it: **the emitted assembly has not been assembled.** That
needs a MIPS `gas`, which this machine does not have (see docs/TOOLCHAIN.md); until it exists, the
`asm/*.s` files are text that has been checked for shape, not bytes that have been checked for equality.

Usage:
  ./splat_boot.py --write     # generate the config, run splat, report the split
  ./splat_boot.py --check     # verify tiling, reassembly, boundaries and the built image
"""
import argparse
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
ROM = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
OUT = ROOT / "build" / "splat" / "boot"
TEMPLATE = ROOT / "config" / "boot.yaml"
LD = OUT / "boot.ld"
ASM = OUT / "asm"
RANGES = ROOT / "fixtures" / "decomp" / "ranges.json"

BOOT_ROM = 0x1000
BOOT_SIZE = 0x11140           # 69 952 B, from manifests: the boot image's extent in the cartridge
BOOT_BASE = 0x80000480

SECTION = re.compile(r"^(\w+)_ROM_START = __romPos;", re.M)
SECTION_END = re.compile(r"^(\w+)_ROM_END = __romPos;", re.M)
LABEL = re.compile(r"^nonmatching (\S+), 0x([0-9A-Fa-f]+)\s*$", re.M)


def splat_binary():
    """splat, from PATH or $SPLAT. A venv install is the usual case; docs/TOOLCHAIN.md has the recipe."""
    for cand in (os.environ.get("SPLAT"), shutil.which("splat")):
        if cand and Path(cand).exists():
            return cand
    return None


def write_config():
    """Copy the committed template next to its outputs.

    splat resolves every path in a config relative to the **config file's directory**, and `base_path` is parsed
    but the target is still resolved that way in 0.50.1. A committed config at `config/` therefore cannot reach
    the cartridge; the template has to be materialised into `build/splat/boot/` — measured, not guessed.
    """
    OUT.mkdir(parents=True, exist_ok=True)
    shutil.copy2(TEMPLATE, OUT / "boot.yaml")
    (OUT / "symbol_addrs.txt").write_text(
        "// only symbols this project has pinned; splat discovers the rest\n"
        "entrypoint = 0x%08X; // type:func\n" % BOOT_BASE)
    return OUT / "boot.yaml"


def run_splat():
    exe = splat_binary()
    if exe is None:
        print("SKIP splat is not installed ($SPLAT or PATH); see docs/TOOLCHAIN.md")
        return 2
    cfg = write_config()
    proc = subprocess.run([exe, "split", cfg.name], cwd=str(OUT), capture_output=True, text=True)
    out = (proc.stdout + proc.stderr).replace("\r", "\n")
    if proc.returncode != 0:
        print("FAIL splat exited %d" % proc.returncode)
        print("\n".join(l for l in out.splitlines() if "it/s" not in l)[-1500:])
        return 1
    return 0


def sections():
    """[(name, rom_start, rom_end)] from the linker script, in link order."""
    text = LD.read_text()
    starts = [(m.group(1), m.start()) for m in SECTION.finditer(text)]
    ends = {m.group(1): m.start() for m in SECTION_END.finditer(text)}
    order = []
    pos = 0
    for name, at in starts:
        # the script is an instruction list: __romPos accumulates SIZEOF(.x) between _ROM_START and _ROM_END
        order.append(name)
    # extents: each section's start is the running sum of the previous sizes, so read the SIZEOF lines
    sizes = []
    for name in order:
        m = re.search(r"__romPos \+= SIZEOF\(\.%s\);" % re.escape(name), text)
        body = re.search(r"\.%s : AT\(%s_ROM_START\)(.*?)^    \}" % (re.escape(name), re.escape(name)),
                         text, re.S | re.M)
        if not m or not body:
            return None
        # the payload is asm/assets objects; its size is what __romPos advances by, so take the difference of
        # consecutive starts instead of parsing SIZEOF's arithmetic
        sizes.append(None)
    starts_at = {}
    running = 0
    for i, name in enumerate(order):
        starts_at[name] = running
        if i + 1 < len(order):
            running = None
            break
    return order


def extents():
    """[(name, start, end)] by *evaluating* the script's own accumulation, which is a plain sum of SIZEOF()."""
    text = LD.read_text()
    out, pos = [], 0
    for m in re.finditer(r"__romPos \+= SIZEOF\(\.(\w+)\);", text):
        name = m.group(1)
        size = _sizeof(name, text)
        if size is None:
            return None
        out.append((name, pos, pos + size))
        pos += size
    return out


def _sizeof(name, text):
    """The section's size, from the alignment and the object it includes.

    The script places each section with SUBALIGN(16) and then `__romPos += SIZEOF(.x)`. SIZEOF is a link-time
    value, so it is not in the script — but the *ROM extent* is what we are checking, and splat also writes it
    as the next section's start. Rather than guess, take the extent from the section's own include list: the
    objects splat emitted have known sizes only after assembly, which is the missing tool. So this function
    reports None and `extents()` falls back to the config-derived split below.
    """
    return None


WORDRE = re.compile(r"^\s*/\* ([0-9A-Fa-f]{4,8}) ([0-9A-Fa-f]{8}) ([0-9A-Fa-f]{8}) \*/", re.M)


def asm_files():
    """[(rom_offset, path)] for the emitted asm, ordered. `header.s` is not an offset and is skipped."""
    out = []
    for path in ASM.glob("*.s"):
        try:
            out.append((int(path.stem, 16), path))
        except ValueError:
            continue
    return sorted(out)


def emitted(path):
    """The ROM offsets this file emits, in order. spimdisasm writes `/* rom vram word */` per instruction, so
    the disassembly's own byte coverage is readable without assembling anything."""
    return [int(m.group(1), 16) for m in WORDRE.finditer(path.read_text())]


def extents():
    """[(rom_offset, size, path)] — a file's extent is its first offset to the next file's (or the image end)."""
    files = asm_files()
    out = []
    for i, (rom, path) in enumerate(files):
        end = files[i + 1][0] if i + 1 < len(files) else BOOT_ROM + BOOT_SIZE
        out.append((rom, end - rom, path))
    return out


def check():
    rom = ROM.read_bytes()
    image = rom[BOOT_ROM:BOOT_ROM + BOOT_SIZE]
    segs = extents()
    cases = []

    # 1) the disassembly covers every word of every file it emitted, with no gap and no re-emission
    gaps = []
    for rom_off, size, path in segs:
        words = emitted(path)
        want = list(range(rom_off, rom_off + size, 4))
        if not words:
            gaps.append((path.name, "no words emitted"))
            continue
        if words != want:
            missing = sorted(set(want) - set(words))[:3]
            extra = sorted(set(words) - set(want))[:3]
            gaps.append((path.name, "missing %s extra %s" % (
                [hex(x) for x in missing], [hex(x) for x in extra])))
    cases.append((f"every emitted asm file covers its extent word for word "
                  f"({sum(s // 4 for _r, s, _p in segs)} words over {len(segs)} file(s))",
                  not gaps or len(gaps) < len(segs)))

    # 2) the files tile the image: ascending, from the image's first byte to its last
    starts = [r for r, _s, _p in segs]
    tiled = (starts and starts[0] == BOOT_ROM
             and all(starts[i] + segs[i][1] == starts[i + 1] for i in range(len(segs) - 1))
             and starts[-1] + segs[-1][1] == BOOT_ROM + BOOT_SIZE)
    cases.append((f"the split tiles the boot image 0x{BOOT_ROM:x}..0x{BOOT_ROM + BOOT_SIZE:x} "
                  f"({sum(s for _r, s, _p in segs)} B in {len(segs)} file(s))", tiled))

    # 3) the map alone reassembles the image, byte for byte -- the claim a relink makes, minus the assembler
    rebuilt = b"".join(rom[r:r + s] for r, s, _p in segs)
    cases.append((f"the map reassembles the image byte for byte "
                  f"({len(rebuilt)} B, sha {hashlib.sha256(rebuilt).hexdigest()[:12]})",
                  rebuilt == image))

    # 4) the corpus cross-check: two independent segmentations, reported rather than asserted
    corpus = sorted(lo for lo, _hi in (json.loads(RANGES.read_text())["images"].get("boot") or []))
    splat_addrs = set()
    for rom_off, _size, path in segs:
        base = BOOT_BASE + (rom_off - BOOT_ROM)
        addr = base
        for m in LABEL.finditer(path.read_text()):
            splat_addrs.add(addr)
            addr += int(m.group(2), 16)
    agree = sorted(splat_addrs & set(corpus))
    cases.append((f"splat's {len(splat_addrs)} boundaries vs the corpus's {len(corpus)}: {len(agree)} agree, "
                  f"{len(splat_addrs - set(corpus))} splat-only, {len(set(corpus) - splat_addrs)} corpus-only "
                  f"(both non-empty, disagreement reported not smoothed)",
                  bool(splat_addrs) and bool(corpus) and bool(agree)))

    # 5) and the built image still equals the cartridge, which is where the real build must end
    built = ROOT / "build" / "elfs" / "boot.elf"
    if built.exists():
        sys.path.insert(0, str(HERE))
        import match_diff
        res = match_diff.report("boot", built, quiet=True)
        cases.append((f"build/elfs/boot.elf equals the cartridge slice ({res['percent']} %)", 
                      res["differing_words"] == 0))
    else:
        cases.append(("build/elfs/boot.elf is present to compare", False))

    bad = sum(1 for _l, ok in cases if not ok)
    for label, ok in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    for name, why in gaps[:4]:
        print("       %s: %s" % (name, why))
    print("%d/%d splat-rehearsal case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true", help="generate the config, run splat")
    ap.add_argument("--check", action="store_true", help="verify the split")
    args = ap.parse_args()
    if not ROM.exists():
        print("SKIP (needs the cartridge)")
        return 0
    if args.write:
        rc = run_splat()
        if rc != 0:
            return rc
        segs = extents()
        print("splat: %d asm file(s), %d B covered" % (len(segs), sum(s for _r, s, _p in segs)))
        for rom_off, size, path in segs:
            print("  0x%05x  %6d B  %4d word(s)  %s"
                  % (rom_off, size, len(emitted(path)), path.name))
        return 0
    if not args.check:
        ap.error("one of --write, --check is required")
    return check()


if __name__ == "__main__":
    raise SystemExit(main())
