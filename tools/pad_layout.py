#!/usr/bin/env python3
"""Decode an N64 SI command block: the controller read, its error bits, and its payload.

M124 diffed our empirically derived pad layout against the libultra that builds it
(`perfect_dark/src/lib/ultra/io/controller.h`). The decisive detail is that a channel's **error is not in
the payload**: it is bits 6-7 of `rxsize`,

    CHNL_ERR(format) = (format.rxsize & 0xC0) >> 4

with the payload only meaningful when that is zero. That single fact retires a claim this project published
in M109 — that ares handing the game `ff 01 04 01 ff ff ff ff` meant "no controller". Under the real rule
that block is `errno = 0` with `button = 0xffff`, `stick_x = -1`, `stick_y = -1`: a pad reporting **every
button held**. This tool exists so that reading is executable and cannot drift back.

Block layout, 8 bytes per channel, `__OSContReadFormat`:

    +0 dummy   CONT_CMD_NOP (0xff)
    +1 txsize  CONT_CMD_READ_BUTTON_TX (1)
    +2 rxsize  CONT_CMD_READ_BUTTON_RX (4); bits 6-7 are the channel error
    +3 cmd     CONT_CMD_READ_BUTTON (1)
    +4 button  big-endian u16
    +6 stick_x signed byte
    +7 stick_y signed byte

The channel list ends where a byte is `CONT_CMD_END` (0xfe).

Usage:
  ./pad_layout.py --self-test
  ./pad_layout.py --rdram "rom/…-rdram-20261031-132952.bin"            # default 0x80014fa0
  ./pad_layout.py --rdram … --addr 0x80016470                          # the Controller Pak buffer
  ./pad_layout.py --hex "ff 01 04 01 ff ff ff ff"
"""
import argparse
import sys
from pathlib import Path

RD_BASE = 0x80000000
READ_BUFFER = 0x80014FA0        # the button-read block (M124)
PAK_BUFFER = 0x80016470         # the Controller Pak write block (M124)

CHNL_ERR_MASK = 0xC0            # rcp.h: bits 6-7 of rxsize carry the channel error
BLOCK = 8                       # sizeof(__OSContReadFormat)

CMD = {0x00: "REQUEST_STATUS", 0x01: "READ_BUTTON", 0x02: "READ_MEMPACK",
       0x03: "WRITE_MEMPACK", 0x04: "READ_EEPROM", 0x05: "WRITE_EEPROM", 0xFF: "RESET"}
END = 0xFE                      # CONT_CMD_END
NOP = 0xFF                      # CONT_CMD_NOP

BUTTONS = [(0x8000, "A"), (0x4000, "B"), (0x2000, "Z"), (0x1000, "Start"),
           (0x0800, "D-Up"), (0x0400, "D-Down"), (0x0200, "D-Left"), (0x0100, "D-Right"),
           (0x0020, "L"), (0x0010, "R"), (0x0008, "C-Up"), (0x0004, "C-Down"),
           (0x0002, "C-Left"), (0x0001, "C-Right")]


def channel_error(rxsize):
    """CHNL_ERR: the error is in rxsize, never in the payload."""
    return (rxsize & CHNL_ERR_MASK) >> 4


def button_names(word):
    return [name for bit, name in BUTTONS if word & bit] or []


def decode(block, index=0):
    """Decode one 8-byte channel block into a dict, applying the real error rule."""
    dummy, txsize, rxsize, cmd = block[0], block[1], block[2], block[3]
    err = channel_error(rxsize)
    out = {"channel": index, "dummy": dummy, "txsize": txsize, "rxsize": rxsize,
           "cmd": cmd, "cmd_name": CMD.get(cmd, "UNKNOWN(0x%02x)" % cmd), "errno": err,
           "valid": err == 0}
    if cmd == 0x01 and len(block) >= 8:
        if err != 0:
            # libultra's `osContGetReadData` only assigns the pad fields when errno == 0; the bytes are
            # present but must not be read as a pad state. Exposing them invites exactly the M109 misread.
            out["meaning"] = ("channel error %d: payload present but not a pad reading, "
                              "as libultra leaves the pad fields untouched" % err)
            return out
        button = (block[4] << 8) | block[5]
        x = block[6] - 256 if block[6] >= 0x80 else block[6]
        y = block[7] - 256 if block[7] >= 0x80 else block[7]
        out.update({"button": button, "buttons": button_names(button), "stick_x": x, "stick_y": y})
        if button == 0xFFFF and x == -1 and y == -1:
            out["meaning"] = "every button held, sticks at minimum (a pad state, NOT 'no controller')"
        elif button == 0 and x == 0 and y == 0:
            out["meaning"] = "idle: no buttons, sticks centred"
        else:
            out["meaning"] = "%s" % (", ".join(out["buttons"]) or "no buttons")
    else:
        out["meaning"] = "%s command, payload is not a pad reading" % out["cmd_name"]
    return out


def decode_block(mem):
    """Walk the channel list until CONT_CMD_END."""
    channels, i = [], 0
    while i + BLOCK <= len(mem):
        block = mem[i:i + BLOCK]
        if mem[i] == END:
            break
        if not any(block):              # a zeroed tail is not a channel (buffer zeroed, only partly filled)
            break
        channels.append(decode(mem[i:i + BLOCK], len(channels)))
        i += BLOCK
    return channels, (mem[i] if i < len(mem) else None)


def show(mem, label, addr=None):
    channels, term = decode_block(mem)
    print("%s%s" % (label, "" if addr is None else " at %08x" % addr))
    for c in channels:
        if "button" in c:
            print("  ch%d  %-14s tx=%-3d rx=0x%02x errno=%d  button=0x%04x %-28s "
                  "stick=(%d,%d)" % (c["channel"], c["cmd_name"], c["txsize"], c["rxsize"],
                                     c["errno"], c["button"], ",".join(c["buttons"]) or "-",
                                     c["stick_x"], c["stick_y"]))
        else:
            print("  ch%d  %-14s tx=%-3d rx=0x%02x errno=%d" % (
                c["channel"], c["cmd_name"], c["txsize"], c["rxsize"], c["errno"]))
        print("        -> %s" % c["meaning"])
    print("  terminator: %s" % ("none" if term is None else
                                "0x%02x %s" % (term, "CONT_CMD_END" if term == END else "(not END)")))
    return channels, term


# ------------------------------------------------------------------------------------------- fixture
IDLE = bytes([0xFF, 0x01, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00])
ARES_ALL = bytes([0xFF, 0x01, 0x04, 0x01, 0xFF, 0xFF, 0xFF, 0xFF])
NO_PAD = bytes([0xFF, 0x01, 0x84, 0x01, 0xFF, 0xFF, 0xFF, 0xFF])
PAK = bytes([0xFF, 0x23, 0x01, 0x03, 0xC0, 0x1B, 0x00, 0x00])
START = bytes([0xFF, 0x01, 0x04, 0x01, 0x10, 0x00, 0x00, 0x00])
R_BTN = bytes([0xFF, 0x01, 0x04, 0x01, 0x00, 0x10, 0x00, 0x00])


def self_test():
    cases = []

    c = decode(IDLE)
    cases.append(("idle pad: errno 0, no buttons, sticks centred",
                  c["errno"] == 0 and c["button"] == 0 and c["stick_x"] == 0 and c["meaning"].startswith("idle")))

    c = decode(ARES_ALL)
    cases.append(("the ares all-ones payload is errno 0 WITH every button held, not 'no controller'",
                  c["errno"] == 0 and c["valid"] and c["button"] == 0xFFFF
                  and c["stick_x"] == -1 and c["stick_y"] == -1
                  and len(c["buttons"]) == 14 and "NOT 'no controller'" in c["meaning"]))

    c = decode(NO_PAD)
    cases.append(("a real channel error comes from rxsize bits 6-7, and invalidates the payload",
                  c["errno"] == 8 and not c["valid"] and "not a pad reading" in c["meaning"]
                  and "button" not in c["meaning"]))

    c = decode(PAK)
    cases.append(("the pak-write block is a command, not a pad reading",
                  c["cmd_name"] == "WRITE_MEMPACK" and c["txsize"] == 0x23 and c["rxsize"] == 1
                  and "not a pad reading" in c["meaning"]))

    mem = IDLE * 4 + bytes([0xFE])
    chans, term = decode_block(mem)
    cases.append(("four channel blocks then CONT_CMD_END, as the dump holds",
                  len(chans) == 4 and term == END and all(ch["errno"] == 0 for ch in chans)))

    mem = IDLE + NO_PAD + START + bytes([0xFE])
    chans, term = decode_block(mem)
    cases.append(("mixed errno: a bad channel is invalidated while its neighbours still read",
                  len(chans) == 3 and [c["errno"] for c in chans] == [0, 8, 0]
                  and "button" not in chans[1] and chans[2]["buttons"] == ["Start"]
                  and term == END))

    mem = PAK + bytes(8) + bytes([0xFE])
    chans, term = decode_block(mem)
    cases.append(("a zeroed tail ends the list — and is not CONT_CMD_END (the pak buffer's real shape)",
                  len(chans) == 1 and chans[0]["cmd_name"] == "WRITE_MEMPACK" and term == 0x00))

    cases.append(("button bits: 0x1000 is Start and 0x0010 is R",
                  decode(START)["buttons"] == ["Start"] and decode(R_BTN)["buttons"] == ["R"]))

    passed = 0
    for name, ok in cases:
        print("%s  %s" % ("PASS" if ok else "FAIL", name))
        passed += 1 if ok else 0
    print("\n%d/%d" % (passed, len(cases)))
    return 0 if passed == len(cases) else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--rdram")
    ap.add_argument("--addr", type=lambda s: int(s, 0), default=READ_BUFFER)
    ap.add_argument("--len", type=lambda s: int(s, 0), default=0x40)
    ap.add_argument("--hex")
    args = ap.parse_args()

    if args.self_test:
        return self_test()
    if args.hex:
        show(bytes.fromhex(args.hex.replace(",", " ").replace("0x", "")), "literal")
        return 0
    if not args.rdram:
        ap.error("give --self-test, --hex or --rdram")
    mem = Path(args.rdram).read_bytes()
    if len(mem) != 0x800000:
        sys.exit("%s is not an 8 MiB RDRAM dump" % args.rdram)
    off = args.addr - RD_BASE
    show(mem[off:off + args.len], Path(args.rdram).name, args.addr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
