#!/usr/bin/env python3
"""Extract container blocks from the cartridge without touching the input.

Format recovered by tools/scan_headers.py (see docs/format_notes.md):

    block := payload [pad] trailer
    trailer := u32 type, u32 payload_size      (big-endian)
    pad := 1 byte when payload_size is odd

The size is stored AFTER its payload, so a block cannot be walked forward by
reading its header — the walker would need the length before the data exists.
The parser therefore resolves each block *backwards* from its terminator: given a
payload start p, find a trailer at t whose declared size equals the distance back
to p (allowing one parity byte). That is a self-consistent test, not a guess: a
wrong t declares a size that does not match, and is rejected.

Extraction reads the ROM read-only, writes children into assets/ (gitignored) and
records every block in manifests/block_types.json + the extraction manifest.
"""
import argparse, hashlib, json, os, struct, sys

def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for c in iter(lambda: f.read(1 << 20), b""): h.update(c)
    return h.hexdigest()

def u32(d, p):
    return struct.unpack(">I", d[p:p+4])[0] if 0 <= p and p + 4 <= len(d) else None

def trailer_index(d, types, lo, hi):
    """Positions in [lo,hi) whose first trailer word is one of `types`."""
    out = []
    for t in types:
        pat = struct.pack(">I", t)
        i = lo
        while True:
            i = d.find(pat, i, hi)
            if i < 0: break
            out.append(i)
            i += 4
    return sorted(set(out))

def resolve(d, p, cands, max_span):
    """First candidate trailer at/after p whose declared size matches the distance."""
    for t in cands:
        if t < p + 4: continue
        if t - p > max_span: return None
        size = u32(d, t + 4)
        if size is None: continue
        dist = t - p
        if size == dist or size == dist - 1:      # -1 allows the odd-size parity byte
            return t, size
    return None

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("rom")
    ap.add_argument("--spec", default="manifests/block_types.json")
    ap.add_argument("--assets", default="assets")
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()

    before = sha256(a.rom)
    with open(a.rom, "rb") as f: d = f.read()
    spec = json.load(open(a.spec))
    types = [t["value"] for t in spec["trailer_types"]]
    max_span = spec.get("max_block_span", 0x400000)
    report = {"rom_sha256": before, "kinds": []}

    for kind in spec["kinds"]:
        lo, hi = (int(x, 0) if isinstance(x, str) else x for x in kind["region"])
        cands = trailer_index(d, types, lo, min(hi + max_span, len(d)))
        starts = []
        magic = kind.get("payload_magic")
        if magic:
            pat = bytes.fromhex(magic); i = lo
            while True:
                i = d.find(pat, i, hi)
                if i < 0: break
                starts.append(i); i += 1
        else:
            # trailer-terminated container: a payload starts right after a trailer
            starts = [t + 8 for t in cands if lo <= t + 8 < hi]
        resolved, unresolved, payload_bytes = [], 0, 0
        seen = set()
        for p in starts:
            if p in seen: continue
            seen.add(p)
            r = resolve(d, p, cands, max_span)
            if r is None:
                unresolved += 1; continue
            t, size = r
            payload = d[p:t - (1 if size == t - p - 1 else 0)]
            payload_bytes += len(payload)
            resolved.append({"start": p, "trailer": t, "type": u32(d, t), "size": size,
                             "payload_len": len(payload),
                             "sha1": hashlib.sha1(payload).hexdigest()})
        kinds_t = sorted({hex(r["type"]) for r in resolved})
        print(f"{kind['name']:22s} region {lo:#09x}..{hi:#09x}  starts {len(starts):>5}  "
              f"resolved {len(resolved):>5}  unresolved {unresolved:>4}  "
              f"payload {payload_bytes:,} B  turf {hi-lo:,} B "
              f"({payload_bytes/(hi-lo)*100:.1f}%)  types {kinds_t[:4]}")
        if resolved and not a.dry_run:
            outdir = os.path.join(a.assets, kind.get("out", "unknown"))
            os.makedirs(outdir, exist_ok=True)
            for k, r in enumerate(resolved):
                p, t = r["start"], r["trailer"]
                name = f"{k:05d}_{p:07x}.{kind.get('ext','bin')}"
                with open(os.path.join(outdir, name), "wb") as o:
                    o.write(d[p:t - (1 if r["size"] == t - p - 1 else 0)])
                r["file"] = os.path.join(kind.get("out", "unknown"), name)
        report["kinds"].append({"name": kind["name"], "region": [hex(lo), hex(hi)],
                                "starts": len(starts), "resolved": len(resolved),
                                "unresolved": unresolved, "payload_bytes": payload_bytes,
                                "blocks": resolved})

    os.makedirs("manifests", exist_ok=True)
    if not a.dry_run:
        json.dump(report, open("manifests/manifest.json", "w"), indent=1)
        print("wrote manifests/manifest.json")
    after = sha256(a.rom)
    print(f"\nROM sha256 {before[:16]}… -> {after[:16]}…  "
          f"{'UNCHANGED' if before == after else 'MODIFIED — INVESTIGATE'}")

if __name__ == "__main__":
    main()
