#!/usr/bin/env python3
"""Materialise every code image as an ELF32 big-endian MIPS file for the decompiler.

The image list is not hardcoded: it comes from `manifests/code_census.json` (which members
contain code) crossed with `manifests/overlay_table.json` (what load address the cartridge
assigns each payload). The boot bank is the one image sourced from the ROM directly.

Load addresses are the cart table's `vram_start`, not a guess. A payload that the table
names more than once must agree with itself — the table uses a repeated cart offset to mean
"already resident" (`stored == 0`), so exactly one non-zero record may exist per payload.
The script refuses to run if that invariant breaks.

Why ELF: REA's Ghidra lane admits MIPS only as ELF, and its raw-binary loader has no `mips`
architecture value. `tools/wrap_mips_elf.py` is load-bearing here.

Usage:
  ./build_images.py rom/re2.z64 --out build/elfs
"""
import argparse
import hashlib
import json
import subprocess
import sys
from pathlib import Path

BOOT = dict(name="boot", rom=0x1000, length=0x11140, base=0x80000480)
WRAPPER = Path(__file__).with_name("wrap_mips_elf.py")


def load_images(table: Path, census: Path, unpacked: Path) -> list:
    """Cross the census (which members are code) with the table (their load addresses)."""
    code_roms = {int(r["rom"], 16) for r in json.loads(census.read_text())["code"]}
    by_cart = {}
    for r in json.loads(table.read_text())["records"]:
        if not r["stored"]:
            continue
        prev = by_cart.setdefault(r["cart"], r)
        if prev["vram_start"] != r["vram_start"]:
            sys.exit(f"payload {r['cart']:#09x} is loaded to two different destinations "
                     f"({prev['vram_start']:#010x} and {r['vram_start']:#010x}); "
                     f"that needs a decision, not a silent pick")
    images = []
    for cart, r in sorted(by_cart.items()):
        if cart not in code_roms:
            continue
        src = unpacked / f"{r['unpacked_member'].rsplit('_', 2)[0]}_{cart:07x}_{r['decompressed']}.bin"
        if not src.exists():
            sys.exit(f"census says cart {cart:#09x} is code but {src} is missing")
        role = "stage2" if cart == 0x14420 else "ovl"
        name = "stage2" if role == "stage2" else f"ovl_{cart:07x}"
        images.append(dict(name=name, role=role, cart=cart, base=r["vram_start"],
                           path=src, size=r["decompressed"], slots=[r["slot"]]))
    return images


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("rom")
    ap.add_argument("--table", default="manifests/overlay_table.json")
    ap.add_argument("--census", default="manifests/code_census.json")
    ap.add_argument("--unpacked", default="assets/unpacked")
    ap.add_argument("--out", default="build/elfs")
    a = ap.parse_args()

    rom = Path(a.rom).read_bytes()
    before = hashlib.sha256(rom).hexdigest()
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)

    images = load_images(Path(a.table), Path(a.census), Path(a.unpacked))
    manifest = [dict(name=BOOT["name"], role="boot", base=BOOT["base"],
                     size=BOOT["length"], source=f"ROM {BOOT['rom']:#07x}")]

    # boot bank comes straight out of the cartridge
    subprocess.run([sys.executable, str(WRAPPER),
                    "--input", a.rom, "--output", str(out / "boot.elf"),
                    "--base", hex(BOOT["base"]),
                    "--offset", hex(BOOT["rom"]), "--length", hex(BOOT["length"])],
                   check=True)

    for img in images:
        if img["size"] % 4:
            print(f"  skip {img['name']}: length {img['size']} is not a multiple of 4")
            continue
        subprocess.run([sys.executable, str(WRAPPER),
                        "--input", str(img["path"]), "--output", str(out / f"{img['name']}.elf"),
                        "--base", hex(img["base"])], check=True)
        manifest.append(dict(name=img["name"], role=img["role"], base=img["base"],
                             size=img["size"], cart=hex(img["cart"]),
                             source=str(img["path"])))

    after = hashlib.sha256(Path(a.rom).read_bytes()).hexdigest()
    print(f"\ncart sha256 {before}  {'UNCHANGED' if before == after else 'CHANGED — INVESTIGATE'}")
    total = sum(m["size"] for m in manifest)
    print(f"{len(manifest)} images, {total:,} B of code "
          f"({total / max(len(manifest), 1):,.0f} B mean)")
    print(f"{'image':>16} {'role':>7} {'base':>10} {'size':>9}")
    for m in manifest:
        print(f"{m['name']:>16} {m['role']:>7} {m['base']:#010x} {m['size']:9d}")
    Path(out / "images.json").write_text(json.dumps(
        dict(cart_sha256=before, cart_unchanged=before == after, images=manifest), indent=1) + "\n")
    print(f"\nwrote {out}/images.json and {len(manifest)} ELFs")


if __name__ == "__main__":
    main()
