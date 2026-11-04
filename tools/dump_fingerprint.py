#!/usr/bin/env python3
"""Fingerprint a set of RDRAM dumps so "same room?" becomes a measurement, not an impression.

M104–M106 treated the five room dumps as captures of one corridor, because they came from one session.
The owner reports seeing **two door animations**, which means at least three rooms were visited. A dump is
evidence about a *moment*; whether two moments are the same *room* has to be read out of the dump, and
three signals decide it:

  1. `*(0x800df92c)` — the script descriptor; a room installs its own, so a different pointer is a
     different script;
  2. the bytes at the resident **overlay destination** (`0x80161cf0`, the bank-B landing zone) — a
     different room is different code in the same place;
  3. the **slot struct** at `*(0x80115284)` and its first bytes (opcode + slot), i.e. whether the room's
     scene-slot command ran and with what operand.

Static regions are printed too, as a control: the two 48-byte slot maps at `0x800eb204`/`0x800eb234` are
`.rodata` and must hash identically in every dump (M106) — if they ever differ, the dump is not what it
claims to be and nothing else in the row should be believed.

Usage:
  ./dump_fingerprint.py rom/*-rdram-*.bin
"""
import argparse
import hashlib
import struct
from pathlib import Path

RD_BASE = 0x80000000
SCRIPT = 0x800DF92C          # -> the room's script descriptor
SLOT_CTX = 0x80115284        # -> the scene-slot command descriptor
OVERLAY_DEST = 0x80161CF0    # bank-B destination: where a room's overlay code lands
OVERLAY_BYTES = 0x8000       # enough to tell two overlays apart
MAP_A = 0x800EB204           # static .rodata slot maps (M106): the control
MAP_B = 0x800EB234
MAP_LEN = 0x30


def rd(dump, addr, length):
    off = addr - RD_BASE
    return dump[off:off + length]


def word(dump, addr):
    return struct.unpack(">I", rd(dump, addr, 4))[0]


def digest(data):
    return hashlib.sha256(data).hexdigest()[:12]


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("dumps", nargs="+")
    args = ap.parse_args()

    rows = []
    for path in sorted(args.dumps):
        dump = Path(path).read_bytes()
        if len(dump) != 0x800000:
            print("%s: %d bytes — not an 8 MiB RDRAM dump, skipped" % (Path(path).name, len(dump)))
            continue
        script = word(dump, SCRIPT)
        slot_ptr = word(dump, SLOT_CTX)
        desc = rd(dump, slot_ptr, 12) if RD_BASE <= slot_ptr < RD_BASE + 0x800000 else b""
        rows.append({
            "name": Path(path).name.replace("Resident Evil 2 (USA) (Rev 1)-rdram-", "").replace(".bin", ""),
            "file": digest(dump),
            "script": script,
            "slot_ptr": slot_ptr,
            "opcode": desc[0] if desc else None,
            "operand": desc[3] if len(desc) > 3 else None,
            "desc": desc.hex() if desc else "-",
            "overlay": digest(rd(dump, OVERLAY_DEST, OVERLAY_BYTES)),
            "streams": (word(dump, script + 0x48), word(dump, script + 0x4C)) if RD_BASE <= script < RD_BASE + 0x800000 else (0, 0),
            "script_buf": digest(rd(dump, 0x8052A000, 0x1000)),
            "maps": digest(rd(dump, MAP_A, MAP_LEN) + rd(dump, MAP_B, MAP_LEN)),
        })

    print("%-14s %-13s %-10s %-6s %-4s %-13s %-13s %s" % (
        "dump", "file", "slot", "op", "slot", "script_buf", "streams", "overlay/maps"))
    for r in rows:
        print("%-14s %-13s %08x   %-4s %-4s %-13s %08x/%08x %s/%s" % (
            r["name"], r["file"], r["slot_ptr"],
            "-" if r["opcode"] is None else "%02x" % r["opcode"],
            "-" if r["operand"] is None else "%d" % r["operand"],
            r["script_buf"], r["streams"][0], r["streams"][1], r["overlay"], r["maps"]))

    distinct_files = {r["file"] for r in rows}
    distinct_overlays = {r["overlay"] for r in rows}
    distinct_scripts = {r["script"] for r in rows}
    distinct_maps = {r["maps"] for r in rows}
    distinct_buf = {r["script_buf"] for r in rows}
    distinct_streams = {r["streams"] for r in rows}
    print("\n%d dump(s): %d distinct file states, %d distinct resident overlays, %d distinct script "
          "descriptors, %d distinct script-buffer contents, %d distinct stream pointer pairs, "
          "%d distinct slot maps" % (
              len(rows), len(distinct_files), len(distinct_overlays), len(distinct_scripts),
              len(distinct_buf), len(distinct_streams), len(distinct_maps)))
    if len(distinct_maps) > 1:
        print("WARNING: the slot maps differ between dumps — they are static .rodata (M106), so at least one "
              "dump is mislabelled and the rest of its row should not be trusted.")
    if len(distinct_overlays) > 1:
        print("=> NOT one room by the overlay signal: %d different overlay payloads are resident." % len(distinct_overlays))
    else:
        print("=> the overlay destination is identical in all dumps, so it is not a room discriminator here "
              "(rooms may share one resident overlay). The script buffer is the usable signal:")
    if len(distinct_buf) > 1:
        print("=> %d different script-buffer contents: these captures are different rooms or room states."
              % len(distinct_buf))
    else:
        print("=> one script-buffer content: these captures are the same room.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
