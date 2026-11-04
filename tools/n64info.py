#!/usr/bin/env python3
"""Identify and validate an N64 ROM dump without modifying it.

Read-only. Detects byte order (z64/v64/n64), parses the header, reports the boot
entry point and the bootcode fingerprint. Deliberately does NOT claim a CRC
verdict: the N64 CRC algorithm needs the 256-entry table from n64crc, and
guessing hashes here would be worse than saying so.

Usage: ./n64info.py rom/whatever.z64 [--json]
"""
import argparse
import hashlib
import json
import struct
import sys

MAGICS = {
    b"\x80\x37\x12\x40": ("z64", "big-endian (native)", "z64"),
    b"\x37\x80\x40\x12": ("v64", "byteswapped (16-bit)", "v64"),
    b"\x40\x12\x37\x80": ("n64", "little-endian", "n64"),
}
COUNTRY = {0: "All/NTSC", 0x37: "Europe/PAL", 0x44: "Germany", 0x45: "USA",
           0x46: "France", 0x49: "Italy", 0x4A: "Japan", 0x53: "Spain",
           0x55: "Australia", 0x58: "Europe", 0x59: "Europe"}


def normalise(raw: bytes, order: str) -> bytes:
    """Return the ROM as big-endian z64 bytes."""
    if order == "z64":
        return raw
    if order == "v64":                      # byteswapped: swap each pair
        b = bytearray(raw)
        b[0::2], b[1::2] = raw[1::2], raw[0::2]
        return bytes(b)
    if order == "n64":                      # little-endian: reverse each word
        b = bytearray(raw)
        for i in range(0, len(b) - 3, 4):
            b[i:i + 4] = raw[i:i + 4][::-1]
        return bytes(b)
    raise ValueError(order)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("rom")
    ap.add_argument("--json", action="store_true")
    a = ap.parse_args()

    with open(a.rom, "rb") as f:
        raw = f.read()

    magic = raw[:4]
    if magic not in MAGICS:
        sys.exit(f"not an N64 ROM: first 4 bytes are {magic.hex()} "
                 f"(expected one of {', '.join(m.hex() for m in MAGICS)})")
    order, order_desc, ext = MAGICS[magic]
    rom = normalise(raw, order)

    (clock, entry, libultra, crc1, crc2) = struct.unpack(">IIIII", rom[0x04:0x18])
    name = rom[0x20:0x34].decode("ascii", "replace").strip("\x00 ")
    manufacturer = rom[0x38:0x3C].decode("ascii", "replace")
    cart_id = rom[0x3C:0x3E].decode("ascii", "replace")
    country = rom[0x3E]
    version = rom[0x3F]

    # The CIC bootcode is exactly [0x40, 0x1000) — 4032 bytes (0xFC0). The ROM
    # header ends at 0x40 and the first game segment starts at 0x1000, so ANY
    # bytes beyond 0x1000 belong to game code and make the fingerprint unusable
    # against a CIC table.
    bootcode = rom[0x40:0x1000]
    boot_sha1 = hashlib.sha1(bootcode).hexdigest()

    info = {
        "path": a.rom,
        "size_bytes": len(raw),
        "size_mbit": round(len(raw) * 8 / 1024 / 1024, 2),
        "byte_order": order,
        "byte_order_desc": order_desc,
        "normalised_ext": f".{ext}",
        "clock_rate_decimal": clock,
        "entry_point": f"0x{entry:08x}",
        "libultra_version": f"0x{libultra:08x}",
        "crc1": f"0x{crc1:08x}",
        "crc2": f"0x{crc2:08x}",
        "name": name,
        "manufacturer": manufacturer,
        "cart_id": cart_id,
        "country_code": f"0x{country:02x}",
        "country": COUNTRY.get(country, f"unknown(0x{country:02x})"),
        "version": version,
        "bootcode_bytes": len(bootcode),
        "bootcode_sha1_head": boot_sha1,
        "notes": [
            "CRC is not verified here: the N64 CRC algorithm needs n64crc's table.",
            "Compare bootcode_sha1_head against n64crc's CIC fingerprint table to name the CIC.",
            "Entry point is normally 0x80000400 for a standard libultra ROM.",
        ],
    }

    if a.json:
        print(json.dumps(info, indent=2))
        return

    w = max(len(k) for k in info)
    for k, v in info.items():
        if k == "notes":
            continue
        print(f"{k:<{w}}  {v}")
    print()
    for n in info["notes"]:
        print(f"note: {n}")


if __name__ == "__main__":
    main()
