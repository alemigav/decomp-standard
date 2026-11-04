#!/usr/bin/env python3
"""Decode — or honestly fail to decode — the non-zlib container at cart 0xb6248.

28 records of the cart load table point into a contiguous run at cart 0xb6248..0xc8624 whose
bytes are not zlib. This tool establishes what can be established from the bytes and records
every hypothesis it rejects, because a negative result here is as useful as a positive one:
the alternative is a plausible-looking decoder that silently emits wrong data.

Structural facts this tool measures rather than assumes:

  * the payloads tile exactly (each starts where the previous ends), so the cart table is the
    directory and each payload is an independent stream — no headers between them;
  * every 4th byte of every payload is 0x00 (18 679 / 18 679 measured), so the stream is a
    record structure of 32-bit words whose low byte is unused;
  * the top byte of those words is 0x00 in 97.8 % of cases.

Those two invariants together are what a *bit-packer* produces when it stores 24 bits of stream
per 32-bit word and flushes: the low 8 bits are never written, and the high 8 bits are written
only when a code crosses the 24-bit window. An entropy coder cannot produce them at all, which
is why "zlib with different constants" is not a live hypothesis.

Acceptance test for any decoder: its output length must equal the table's `decompressed` field
exactly, for every payload it is applied to. A decoder that produces plausible bytes of the
wrong length has not decoded anything.

Subcommands:
  layout    the container's geometry and per-payload table
  probe     the decoder matrix, raw and bit-packed, with exact-length acceptance
  compare   byte-for-byte identity test against bank B's known plaintext
  dump      hexdump one payload, raw or bit-packed
"""
import argparse
import bz2
import json
import lzma
import math
import sys
import zlib
from pathlib import Path

BANK_C_DEST = 0x8016E880


def load(path: Path) -> dict:
    return json.loads(path.read_text())


def payloads(table: dict, rom: bytes) -> list:
    """The bank-C records, in cart order, with their bytes."""
    recs = sorted((r for r in table["records"]
                   if r["vram_start"] == BANK_C_DEST and r["stored"]),
                  key=lambda r: r["cart"])
    out = []
    for r in recs:
        out.append(dict(slot=r["slot"], cart=r["cart"], stored=r["stored"],
                        decompressed=r["decompressed"],
                        data=rom[r["cart"]:r["cart"] + r["stored"]]))
    return out


def unpack_bits(data: bytes) -> bytes:
    """Drop the unused low byte of every 32-bit word: 24 bits of stream per word."""
    if len(data) % 4:
        return b""
    out = bytearray()
    for i in range(0, len(data), 4):
        out += data[i:i + 3]
    return bytes(out)


def unpack_bits_hi(data: bytes) -> bytes:
    """Drop the unused *high* byte instead (the mirror hypothesis)."""
    if len(data) % 4:
        return b""
    out = bytearray()
    for i in range(0, len(data), 4):
        out += data[i + 1:i + 4]
    return bytes(out)


def transforms(data: bytes) -> dict:
    return {
        "raw": data,
        "pack24-lo": unpack_bits(data),
        "pack24-hi": unpack_bits_hi(data),
        "swap16": b"".join(data[i:i + 2][::-1] for i in range(0, len(data) - 1, 2)),
        "swap32": b"".join(data[i:i + 4][::-1] for i in range(0, len(data) - 3, 4)),
        "skip2": data[2:],
        "skip4": data[4:],
    }


def decoders(blob: bytes) -> dict:
    out = {}
    if not blob:
        return out
    for name, fn in (
        ("zlib15", lambda b: zlib.decompressobj(15).decompress(b)),
        ("deflate-15", lambda b: zlib.decompressobj(-15).decompress(b)),
        ("gzip31", lambda b: zlib.decompressobj(31).decompress(b)),
        ("lzma", lambda b: lzma.decompress(b)),
        ("lzma-raw", lambda b: lzma.LZMADecompressor(lzma.FORMAT_RAW,
                                                     filters=[{"id": lzma.FILTER_LZMA1,
                                                               "dict_size": 1 << 20}]).decompress(b)),
        ("bz2", lambda b: bz2.decompress(b)),
    ):
        try:
            v = fn(blob)
            out[name] = v
        except Exception:
            pass
    return out


def lz_probe(data: bytes, expected: int) -> dict:
    """Try 24-bit and 16-bit (length, offset) command streams.

    A classic LZ command stream packed into a fixed token width is the remaining structural
    candidate: the tokens are the records. Each split is tried and judged by exact length.
    """
    hits = {}
    for tok_bytes in (3, 2, 4):
        if tok_bytes == 3:
            toks = [int.from_bytes(data[i:i + 3], "big") for i in range(0, len(data) - 2, 4)]
        elif tok_bytes == 2:
            toks = [int.from_bytes(data[i + 1:i + 3], "big") for i in range(0, len(data) - 3, 4)]
        else:
            toks = [int.from_bytes(data[i:i + 4], "big") for i in range(0, len(data) - 3, 4)]
        for len_bits in (8, 9, 10, 11, 12, 16):
            if len_bits >= tok_bytes * 8:
                continue
            off_bits = tok_bytes * 8 - len_bits
            if off_bits > 20:
                continue
            out = bytearray()
            ok = True
            for t in toks:
                length = (t >> off_bits) + 3
                offset = (t & ((1 << off_bits) - 1)) + 1
                if offset > len(out):
                    ok = False
                    break
                for _ in range(length):
                    if len(out) > expected * 4:
                        ok = False
                        break
                    out.append(out[-offset])
                if not ok:
                    break
            if ok and len(out) == expected:
                hits[f"lz tok{tok_bytes} len{len_bits}"] = bytes(out)
    return hits


def is_record_family(p: dict) -> bool:
    """The 4-byte/24-bit grid. Slot 6 is a zlib member with the same destination and fails it."""
    return all(p["data"][i] == 0 for i in range(3, len(p["data"]), 4))


def bit_lz_probe(data: bytes, expected: int, offset_bits: int, len_bits: int,
                 lsb: bool) -> bytes:
    """Classic 1-bit-flag LZ over the 24-of-32 packed stream.

    flag 0 -> literal byte, flag 1 -> back reference of `len_bits` length and `offset_bits`
    distance. Both bit orders are tried because the packed stream gives no hint which one the
    original writer used. Judged only by exact output length.
    """
    packed = unpack_bits(data)
    if not packed:
        return b""
    total_bits = len(packed) * 8

    def bits(pos, n):
        v = 0
        for k in range(n):
            b = packed[(pos + k) >> 3]
            bit = (b >> ((pos + k) & 7)) & 1 if lsb else (b >> (7 - ((pos + k) & 7))) & 1
            v = (v << 1) | bit if not lsb else v | (bit << k)
        return v

    out = bytearray()
    pos = 0
    while pos + 1 <= total_bits and len(out) <= expected:
        flag = bits(pos, 1)
        pos += 1
        if flag == 0:
            if pos + 8 > total_bits:
                break
            out.append(bits(pos, 8))
            pos += 8
        else:
            if pos + offset_bits + len_bits > total_bits:
                break
            length = bits(pos, len_bits) + 3
            pos += len_bits
            offset = bits(pos, offset_bits) + 1
            pos += offset_bits
            if offset > len(out):
                return b""
            for _ in range(length):
                out.append(out[-offset])
    return bytes(out) if len(out) == expected else b""


def cmd_layout(a) -> None:
    rom = Path(a.rom).read_bytes()
    table = load(Path(a.table))
    ps = payloads(table, rom)
    print(f"{len(ps)} bank-C payloads at dest {BANK_C_DEST:#010x}")
    print(f"{'slot':>4} {'cart':>10} {'stored':>7} {'decomp':>8} {'ratio':>6} {'recs':>5} "
          f"{'b3==0':>6} {'b0==0':>6}  contiguous?")
    prev_end = None
    all_b3 = all_b0 = fam_recs = 0
    for p in ps:
        recs = len(p["data"]) // 4
        b3 = sum(1 for i in range(3, len(p["data"]), 4) if p["data"][i] == 0)
        b0 = sum(1 for i in range(0, len(p["data"]), 4) if p["data"][i] == 0)
        contig = "" if prev_end is None else ("yes" if p["cart"] == prev_end else
                                              f"GAP {p['cart'] - prev_end}")
        prev_end = p["cart"] + p["stored"]
        if is_record_family(p):
            all_b3 += b3
            all_b0 += b0
            fam_recs += recs
        print(f"{p['slot']:4d} {p['cart']:#10x} {p['stored']:7d} {p['decompressed']:8d} "
              f"{p['decompressed'] / p['stored']:6.2f} {recs:5d} "
              f"{100 * b3 / max(recs,1):5.1f}% {100 * b0 / max(recs,1):5.1f}%  {contig}")
    fam = [p for p in ps if is_record_family(p)]
    print(f"\n{len(fam)} of {len(ps)} payloads are in the 4-byte/24-bit record family. The predicate "
          f"is all-or-nothing (every record's byte 3 must be 0x00); the {len(ps) - len(fam)} "
          f"excluded payload is slot {[p['slot'] for p in ps if not is_record_family(p)]}, "
          f"the zlib member that shares this destination.")
    # Four-way agreement: the geometry claim is only as good as these four numbers agreeing, and
    # a hand-computed constant was wrong here once (81 852 is the 29-payload total, not this run).
    s0, s1 = fam[0]["cart"], fam[-1]["cart"] + fam[-1]["stored"]
    tot = sum(p["stored"] for p in fam)
    pairs = list(zip(fam, fam[1:]))
    nonzero = [(a["slot"], b["slot"], b["cart"] - (a["cart"] + a["stored"])) for a, b in pairs
               if b["cart"] != a["cart"] + a["stored"]]
    print(f"container: start {s0:#09x}  end {s1:#09x}  end-start {s1 - s0:,}  "
          f"sum(stored) {tot:,}  gaps {len(nonzero)}  "
          f"{'AGREE' if s1 - s0 == tot and not nonzero else 'DISAGREE'}")
    print(f"the 29-payload set including slot 6 spans {ps[0]['cart']:#09x}..{s1:#09x} "
          f"({s1 - ps[0]['cart']:,} B, sum {sum(p['stored'] for p in ps):,} B) — do not")
    print("quote that span as the container: it begins with 229 654 B of ordinary zlib members.")
    print(f"pooled over the family: byte 3 of every record is 0x00 in {all_b3}/{fam_recs} "
          f"({100 * all_b3 / fam_recs:.1f} %), byte 0 is 0x00 in {all_b0}/{fam_recs} "
          f"({100 * all_b0 / fam_recs:.1f} %)")


def cmd_probe(a) -> None:
    rom = Path(a.rom).read_bytes()
    table = load(Path(a.table))
    ps = [p for p in payloads(table, rom) if is_record_family(p)]
    names = ("raw", "pack24-lo", "pack24-hi", "swap16", "swap32", "skip2", "skip4")
    print("acceptance = output length equals the table's decompressed size exactly\n")
    print(f"{'transform':>10} {'decoder':>10} {'payloads tried':>15} {'exact':>6}  verdict")
    wins = []
    for tname in names:
        for dname in ("zlib15", "deflate-15", "gzip31", "lzma", "lzma-raw", "bz2"):
            tried = exact = 0
            for p in ps:
                blob = transforms(p["data"])[tname]
                got = decoders(blob).get(dname)
                if got is None:
                    continue
                tried += 1
                if len(got) == p["decompressed"]:
                    exact += 1
                    wins.append((tname, dname, p["slot"], got))
            print(f"{tname:>10} {dname:>10} {tried:15d} {exact:6d}  "
                  f"{'HIT' if exact else ('no output' if not tried else 'rejected')}")
    tried = exact = 0
    for p in ps:
        for k, v in lz_probe(p["data"], p["decompressed"]).items():
            tried += 1
            exact += 1
            wins.append((k, "lz", p["slot"], v))
    print(f"{'lz family':>10} {'command streams':>10} {tried:15d} {exact:6d}  "
          f"{'HIT' if exact else 'rejected'}")
    tried = exact = 0
    for p in ps:
        for ob in (8, 10, 12, 13, 14, 15, 16):
            for lb in (3, 4, 5, 8, 9):
                for lsb in (False, True):
                    tried += 1
                    got = bit_lz_probe(p["data"], p["decompressed"], ob, lb, lsb)
                    if got:
                        exact += 1
                        wins.append((f"bit-lz off{ob} len{lb} {'lsb' if lsb else 'msb'}",
                                     "bit", p["slot"], got))
    print(f"{'bit-lz':>10} {'1-bit flag LZ':>10} {tried:15d} {exact:6d}  "
          f"{'HIT' if exact else 'rejected'}")
    if wins:
        print(f"\n{wins[0][0]} / {wins[0][1]} produced the exact size for payload slot "
              f"{wins[0][2]} — verify across all 28 before believing it")
        Path(a.out).write_bytes(wins[0][3])
        print(f"wrote {a.out}")
    else:
        print("\nno hypothesis in the matrix reproduces the decompressed sizes.")
        print("negative result recorded — the container's codec is not in this family.")


def cmd_compare(a) -> None:
    rom = Path(a.rom).read_bytes()
    table = load(Path(a.table))
    ps = [p for p in payloads(table, rom) if is_record_family(p)]
    bank_b = sorted((r for r in table["records"]
                     if r["vram_start"] == 0x80161CF0 and r["stored"]), key=lambda r: r["cart"])
    members = {}
    for p in Path(a.unpacked).iterdir():
        parts = p.stem.split("_")
        if len(parts) == 3:
            members[int(parts[1], 16)] = p.read_bytes()
    print("Is bank C the same content as bank B? Bank B decompresses, so the plaintext is known.")
    print("A byte-aligned LZ would leave literal runs; the window sizes test that.\n")
    print(f"{'slotC':>5} {'slotB':>5} {'plain B':>8} {'paired 4B':>10} "
          f"{'best other 4B':>14}  reading")
    for p in ps:
        cand = [b for b in bank_b if b["decompressed"] == p["decompressed"]]
        if len(cand) != 1:
            print(f"{p['slot']:5d}     -  (no unique size-paired bank B record)")
            continue
        b = cand[0]
        P = members.get(b["cart"], b"")
        if not P:
            continue
        windows = list(range(0, len(p["data"]) - 4, 4))

        def score(plain):
            if not plain:
                return 0.0
            return 100.0 * sum(1 for i in windows if plain.find(p["data"][i:i + 4]) >= 0) / len(windows)

        paired = score(P)
        others = [score(members.get(o["cart"], b"")) for o in bank_b if o["slot"] != b["slot"]]
        best_other = max(others) if others else 0.0
        reading = ("no literal support" if paired <= best_other else "paired wins")
        print(f"{p['slot']:5d} {b['slot']:5d} {len(P):8d} {paired:9.2f}% "
              f"{best_other:13.2f}%  {reading}")
    print("\nThe control is the point: if the size-paired plaintext were the real source, its")
    print("4-byte match rate would beat every other room's. It does not, so the low rates are")
    print("chance, not evidence. Bank C is therefore not an LZ-with-byte-literals encoding of")
    print("bank B's plaintext. That does not prove the content differs either — a bit-level or")
    print("transform codec also scores at chance — so identity stays unestablished both ways.")


def cmd_dump(a) -> None:
    rom = Path(a.rom).read_bytes()
    table = load(Path(a.table))
    ps = {p["slot"]: p for p in payloads(table, rom)}
    p = ps[a.slot]
    blob = p["data"] if a.form == "raw" else (
        unpack_bits(p["data"]) if a.form == "pack24-lo" else unpack_bits_hi(p["data"]))
    print(f"slot {p['slot']} cart {p['cart']:#09x} stored {p['stored']} "
          f"decompressed {p['decompressed']} form {a.form} ({len(blob)} B)")
    for i in range(0, min(len(blob), a.limit), 16):
        chunk = blob[i:i + 16]
        print(f"  {i:05x}  {chunk.hex(' '):<48}  "
              f"{''.join(chr(c) if 32 <= c < 127 else '.' for c in chunk)}")


def cmd_entropy(a) -> None:
    rom = Path(a.rom).read_bytes()
    table = load(Path(a.table))
    ps = [p for p in payloads(table, rom) if is_record_family(p)]
    print(f"{'slot':>4} {'stored':>7} {'H(raw)':>7} {'H(pack24)':>10} {'packed bytes':>13}")

    def H(b):
        if not b:
            return 0.0
        c = {}
        for x in b:
            c[x] = c.get(x, 0) + 1
        n = len(b)
        return -sum((v / n) * math.log2(v / n) for v in c.values())

    for p in ps[:12]:
        packed = unpack_bits(p["data"])
        print(f"{p['slot']:4d} {p['stored']:7d} {H(p['data']):7.3f} {H(packed):10.3f} "
              f"{len(packed):13d}")


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("rom")
    ap.add_argument("--table", default="manifests/overlay_table.json")
    ap.add_argument("--unpacked", default="assets/unpacked")
    ap.add_argument("--out", default="build/r4-decoded.bin")
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("layout")
    sub.add_parser("probe")
    sub.add_parser("compare")
    sub.add_parser("entropy")
    d = sub.add_parser("dump")
    d.add_argument("--slot", type=int, default=51)
    d.add_argument("--form", default="raw",
                   choices=("raw", "pack24-lo", "pack24-hi"))
    d.add_argument("--limit", type=int, default=128)
    a = ap.parse_args()
    {"layout": cmd_layout, "probe": cmd_probe, "compare": cmd_compare,
     "dump": cmd_dump, "entropy": cmd_entropy}[a.cmd](a)


if __name__ == "__main__":
    main()
