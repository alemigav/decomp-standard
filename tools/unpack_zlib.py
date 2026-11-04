#!/usr/bin/env python3
"""Sequentially unpack the zlib streams in an N64 cartridge.

Why sequential: the records in the boot descriptor table (vram 0x80012150) are
contiguous, so the cartridge looks like a concatenation of zlib members. Walking
from a known start and using `decompressobj.unused_data` gives exact stream
boundaries without guessing sizes, which is what makes a whole-ROM unpack both
fast and verifiable.

Header note: these streams use CMF 0x68 (deflate, 16 KB window), not the common
0x78 (32 KB). A scanner keyed on 0x78 finds zero streams.
"""
import argparse, hashlib, json, os, struct, sys, zlib

ROM_VA_BASE, ROM_OFF_BASE = 0x80000480, 0x1000

def valid_header(d, p):
    if p + 2 > len(d): return False
    cmf, flg = d[p], d[p+1]
    return (cmf & 0x0F) == 8 and (cmf >> 4) <= 7 and (cmf * 256 + flg) % 31 == 0 and not (flg & 0x20)

def inflate_at(d, p, cap=64 << 20):
    """Inflate one zlib member starting at p. Returns (out, consumed) or None."""
    if not valid_header(d, p): return None
    o = zlib.decompressobj()
    step = 1 << 16
    fed = 0
    out = bytearray()
    while fed < cap:
        end = min(p + fed + step, len(d))
        chunk = d[p + fed:end]
        if not chunk: return None
        try:
            out += o.decompress(chunk)
        except zlib.error:
            return None
        fed += len(chunk)
        if o.eof:
            consumed = fed - len(o.unused_data)
            return bytes(out) + o.flush(), consumed
        step = min(step * 2, 8 << 20)
    return None

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("rom")
    ap.add_argument("--start", type=lambda s: int(s, 0), default=0x14420,
                    help="first candidate offset (default 0x14420: the end of the boot "
                         "descriptor table, where the first zlib member begins)")
    ap.add_argument("--out", help="directory to write members into (omit for a dry run)")
    ap.add_argument("--limit", type=int, default=0, help="stop after N members (0 = all)")
    ap.add_argument("--skip", type=int, default=0, help="skip the first N members")
    a = ap.parse_args()

    d = open(a.rom, "rb").read()
    if a.out: os.makedirs(a.out, exist_ok=True)

    members, gaps, n = [], [], 0
    p = a.start
    while p < len(d) - 8:
        r = inflate_at(d, p)
        if r is None:
            q = p + 1
            while q < len(d) - 8 and not valid_header(d, q): q += 1
            gaps.append((p, q))
            p = q
            continue
        out, consumed = r
        sha = hashlib.sha1(out).hexdigest()
        members.append({"index": len(members), "rom_offset": p, "compressed": consumed,
                        "uncompressed": len(out), "sha1": sha})
        if a.out and len(members) > a.skip:
            name = f"{len(members)-1:05d}_{p:07x}_{len(out)}.bin"
            open(os.path.join(a.out, name), "wb").write(out)
            members[-1]["file"] = name
        p += consumed
        n += 1
        if a.limit and n >= a.limit: break

    cs = sum(m["compressed"] for m in members)
    us = sum(m["uncompressed"] for m in members)
    gs = sum(b - a_ for a_, b in gaps)
    print(f"members {len(members)}   compressed {cs:,} B   uncompressed {us:,} B "
          f"({us/1048576:.1f} MB)   ratio {us/cs if cs else 0:.2f}")
    print(f"gap bytes {gs:,} in {len(gaps)} gap(s)")
    big = sorted(gaps, key=lambda g: g[0] - g[1])[:8]
    for s, e in sorted(big):
        print(f"  gap rom {s:#09x}..{e:#09x}  {e-s:,} B")
    if a.out:
        json.dump({"rom": os.path.basename(a.rom), "members": members,
                   "gaps": [{"start": s, "end": e} for s, e in gaps]},
                  open(os.path.join(a.out, "manifest.json"), "w"), indent=1)
        print(f"wrote {len(members)} members + manifest.json to {a.out}")

if __name__ == "__main__":
    main()
