#!/usr/bin/env python3
"""Decode the `01 41` container: a 16-byte-per-unit prologue and a payload.

The family is 355 corpus blocks whose first word is `0x01410000`. What is **proven** about them, on every block:

    word0 = 0x01410000                      magic, constant across all 355
    word1 = N                               number of 16-byte units before the payload
    word2 = filesize - 16*N                 the payload length
    word3 = 0                               (always, in this family)

so the payload begins at `16*N`, and the header is `16*N` bytes — 16 for N=1 (238 blocks), 32 for N=2 (40), 48
for N=3 (11), up to 464 for N=29. The relation holds for **355 of 355** blocks across **21 distinct N**.

What is **refuted**: that the units are a section table. Entries 1..N-1 carry arbitrary data-like words
(`0x35f23763`, `0xd24b5bff`, `0xffc00000`) rather than ascending in-bounds offsets, in every block checked. So
this is a flat prologue, and what the extra units *contain* is unresolved — a palette or mask table is the
plausible reading, and it is stated as a candidate, not a finding.

  ./container_0141.py            # report the family and the law
  ./container_0141.py --check    # the gate
"""
import argparse
import struct
import sys
import zlib
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import script_profile as sp                                     # noqa: E402
import walk_stream as ws                                        # noqa: E402

HERE = Path(__file__).resolve().parent
ROM = HERE.parent / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
MAGIC = 0x01410000
UNIT = 16


def family(rom):
    out = []
    for idx in range(sp.ENTRY_COUNT):
        off, size = struct.unpack_from(">II", rom, sp.FILE_TABLE_ROM + sp.HEADER + 8 * idx)
        if off == 0xFFFFFFFF or size == 0:
            continue
        try:
            raw = zlib.decompress(rom[sp.FILE_TABLE_ROM + off:sp.FILE_TABLE_ROM + off + size])
        except zlib.error:
            continue
        if len(raw) >= 4 * UNIT and struct.unpack_from(">I", raw, 0)[0] == MAGIC:
            out.append((idx, raw))
    return out


def analyse(blocks):
    by = defaultdict(list)
    law = 0
    sections = 0
    for idx, raw in blocks:
        count = struct.unpack_from(">I", raw, 4)[0]
        declared = struct.unpack_from(">I", raw, 8)[0]
        by[count].append(len(raw))
        if count > 0 and declared == len(raw) - UNIT * count:
            law += 1
        # a section table would give ascending, in-bounds offsets in entries 1..count-1
        if count > 2:
            offs = [struct.unpack_from(">I", raw, UNIT * k + 8)[0] for k in range(1, count)]
            if all(a < b for a, b in zip(offs, offs[1:])) and offs[-1] < len(raw):
                sections += 1
    return by, law, sections


def payload_stats(blocks):
    """The correlation question: is N a bit depth, or the count of distinct payload values?"""
    maxbyte = []
    pairs = []                      # (N, distinct payload values) per block, kept paired
    divisible = 0
    for _idx, raw in blocks:
        n = struct.unpack_from(">I", raw, 4)[0]
        plen = struct.unpack_from(">I", raw, 8)[0]
        payload = raw[UNIT * n:UNIT * n + plen]
        if not payload:
            continue
        maxbyte.append(max(payload))
        pairs.append((n, len(set(payload))))
        if n and plen % n == 0:
            divisible += 1
    return maxbyte, pairs, divisible


def gbi_test(blocks):
    """Would a display-list reading survive its own test? Count records whose first word looks like a GBI
    opcode (G_* commands live in 0xE4-0xFF). Also report the 16-bit statistics a raw RGBA5551 texture would
    have to show."""
    heads = Counter()
    records = 0
    units = alpha = 0
    for _idx, raw in blocks:
        n = struct.unpack_from(">I", raw, 4)[0]
        if n > 200:
            continue
        for k in range(n):
            head = struct.unpack_from(">I", raw, UNIT * k)[0]
            heads[(head >> 24) & 0xFF] += 1
            records += 1
        plen = struct.unpack_from(">I", raw, 8)[0]
        payload = raw[UNIT * n:UNIT * n + plen]
        for i in range(len(payload) // 2):
            units += 1
            alpha += struct.unpack_from(">H", payload, 2 * i)[0] & 1
    gbi = sum(c for b, c in heads.items() if 0xE4 <= b <= 0xFF)
    return heads, records, gbi, units, alpha


# Loader tables indexed by the object-type byte, with the tag each call site passes to func_0x80004cfc.
# The tags are .rodata strings, read from the image: 0x800b8f64 "TM3", 0x800b867c "EMD", 0x800b8700 "EFF",
# 0x800b99cc "ITP", 0x800b9dcc "T64", 0x800b8934 "TIM".
LOADER_TABLES = {
    "TM3": 0x8010DBC0,
    "EMD": 0x80126C80,
    "EFF": 0x800EBB30,
    "ITP": 0x8012BEC0,
}


def loader_kinds(rom, sample=40):
    """Which resource kinds actually reference the family? Sample each loader table and report the magics."""
    words = ws.load_stage2()
    base = ws.STAGE2_BASE

    def u16(va):
        off = va - base
        w = off // 4
        if not (0 <= w < len(words)):
            return None
        return (words[w] >> 16) if off % 4 == 0 else (words[w] & 0xFFFF)

    blocks = {idx: raw for idx, raw in family(rom)}
    out = {}
    for tag, va in LOADER_TABLES.items():
        magics = Counter()
        n = 0
        for i in range(200):
            v = u16(va + 2 * i)
            if v is None or not (0 < v < 8091):
                continue
            raw = blocks.get(v)
            if raw is None or len(raw) < 4:
                continue
            magics[struct.unpack_from(">I", raw, 0)[0]] += 1
            n += 1
            if n >= sample:
                break
        out[tag] = (n, magics)
    return out


# The model's texture grid: DAT_8010dbe0[type] -> an index into DAT_801275c0, whose descriptor is
# [width][height][tile ids...]. FUN_800874d4 walks that grid and loads each distinct id with tag "T64".
GRID_INDEX = 0x8010DBE0
GRID_TABLE = 0x801275C0


def grid_tiles(rom, types=11, cap=64):
    """The distinct tile ids the model's grid descriptors reference, and what those blocks begin with."""
    words = ws.load_stage2()
    base = ws.STAGE2_BASE

    def u16(va):
        off = va - base
        w = off // 4
        if not (0 <= w < len(words)):
            return None
        return (words[w] >> 16) if off % 4 == 0 else (words[w] & 0xFFFF)

    tiles = set()
    for t in range(types):
        idx = u16(GRID_INDEX + 2 * t)
        if idx is None:
            continue
        w = u16(GRID_TABLE + 2 * idx) or 0
        h = u16(GRID_TABLE + 2 * (idx + 1)) or 0
        for k in range(min(w * h, cap)):
            v = u16(GRID_TABLE + 2 * (idx + 2 + k))
            if v:
                tiles.add(v)
    first = Counter()
    for fid in tiles:
        if not (0 <= fid < sp.ENTRY_COUNT):
            continue
        off, size = struct.unpack_from(">II", rom, sp.FILE_TABLE_ROM + sp.HEADER + 8 * fid)
        if off == 0xFFFFFFFF or size == 0:
            continue
        try:
            raw = zlib.decompress(rom[sp.FILE_TABLE_ROM + off:sp.FILE_TABLE_ROM + off + size])
        except zlib.error:
            continue
        if raw:
            first[raw[0]] += 1
    return tiles, first


def tile_headers(rom, tiles):
    """The tile blocks' first halfword, their second word, and whether any carries G_ENDDL where one would be."""
    magics, seconds, shares = [], [], []
    for fid in tiles:
        if not (0 <= fid < sp.ENTRY_COUNT):
            continue
        off, size = struct.unpack_from(">II", rom, sp.FILE_TABLE_ROM + sp.HEADER + 8 * fid)
        if off == 0xFFFFFFFF or size == 0:
            continue
        try:
            raw = zlib.decompress(rom[sp.FILE_TABLE_ROM + off:sp.FILE_TABLE_ROM + off + size])
        except zlib.error:
            continue
        if len(raw) < 8:
            continue
        magics.append(struct.unpack_from(">H", raw, 0)[0])
        seconds.append(struct.unpack_from(">I", raw, 4)[0])
        words = len(raw) // 8
        if words:
            hits = sum(1 for k in range(words) if raw[8 * k] >= 0xB8 or raw[8 * k] in (0x00, 0x01))
            shares.append(hits / words)
    return magics, seconds, shares


def tile_formats(rom, tiles):
    """The T64 law: 16-byte header, palette of `entries` RGBA5551 colours, then raw pixels.

    fmt=1 is 4 bpp (two indices per byte, 16-entry palette) and fmt=2 is 8 bpp (one index per byte,
    256-entry palette). So the data length is `entries*2 + w*h*bpp/8` with no compression anywhere.
    """
    law = small4 = big8 = both = 0
    for fid in tiles:
        if not (0 <= fid < sp.ENTRY_COUNT):
            continue
        off, size = struct.unpack_from(">II", rom, sp.FILE_TABLE_ROM + sp.HEADER + 8 * fid)
        if off == 0xFFFFFFFF or size == 0:
            continue
        try:
            raw = zlib.decompress(rom[sp.FILE_TABLE_ROM + off:sp.FILE_TABLE_ROM + off + size])
        except zlib.error:
            continue
        if len(raw) < 16:
            continue
        _h1, w, h, fmt, entries, _z1, _z2 = struct.unpack_from(">7H", raw, 2)
        pixels = raw[16 + entries * 2:]
        if len(raw) - 16 == entries * 2 + (w * h if fmt == 2 else w * h):
            law += 1
        if fmt == 1:
            both += 1
            nib = []
            for byte in pixels:
                nib += [byte >> 4, byte & 0xF]
            if nib and max(nib) <= 15 and len(nib) == 2 * w * h:
                small4 += 1
        elif fmt == 2:
            both += 1
            if pixels and max(pixels) <= 255 and len(pixels) == w * h:
                big8 += 1
    return law, small4, big8, both


def tile_geometry(rom, tiles):
    """`h1` (the field at offset 2) is the **true pixel height**; the field at offset 6 is its
    8-bit-equivalent, `h = h1*bpp/8`. Row-stride readings fit almost nothing, so they are refuted here too."""
    true_height = pixel_bytes = stride_bytes = stride_words = total = 0
    for fid in tiles:
        if not (0 <= fid < sp.ENTRY_COUNT):
            continue
        off, size = struct.unpack_from(">II", rom, sp.FILE_TABLE_ROM + sp.HEADER + 8 * fid)
        if off == 0xFFFFFFFF or size == 0:
            continue
        try:
            raw = zlib.decompress(rom[sp.FILE_TABLE_ROM + off:sp.FILE_TABLE_ROM + off + size])
        except zlib.error:
            continue
        if len(raw) < 16:
            continue
        h1, w, h, fmt, entries, _z1, _z2 = struct.unpack_from(">7H", raw, 2)
        bpp = 8 if fmt == 2 else 4
        px = len(raw) - 16 - entries * 2
        total += 1
        if h1 == h * 8 // bpp:
            true_height += 1
        if w * h1 * bpp // 8 == px:
            pixel_bytes += 1
        stride = w * bpp // 8
        if h1 == stride:
            stride_bytes += 1
        if h1 == stride // 8:
            stride_words += 1
    return true_height, pixel_bytes, stride_bytes, stride_words, total


def grid_pairs(rom):
    """Grids of height 2 register a **pair** of blocks per column when the two rows' ids differ, and a
    single block when they are equal (FUN_8008769c). So every id in those grids must resolve to a tile, and
    the columns where the ids differ must reference two *distinct* blocks."""
    words = ws.load_stage2()
    base = ws.STAGE2_BASE

    def u16(va):
        off = va - base
        w = off // 4
        if not (0 <= w < len(words)):
            return None
        return (words[w] >> 16) if off % 4 == 0 else (words[w] & 0xFFFF)

    def magic(fid):
        if not (0 <= fid < sp.ENTRY_COUNT):
            return None
        off, size = struct.unpack_from(">II", rom, sp.FILE_TABLE_ROM + sp.HEADER + 8 * fid)
        if off == 0xFFFFFFFF or size == 0:
            return None
        try:
            raw = zlib.decompress(rom[sp.FILE_TABLE_ROM + off:sp.FILE_TABLE_ROM + off + size])
        except zlib.error:
            return None
        return struct.unpack_from(">H", raw, 0)[0] if len(raw) >= 2 else None

    ids_ok = ids_total = 0
    pairs_same = pairs_diff = 0
    for t in range(11):
        idx = u16(GRID_INDEX + 2 * t)
        if idx is None:
            continue
        w = u16(GRID_TABLE + 2 * idx) or 0
        h = u16(GRID_TABLE + 2 * (idx + 1)) or 0
        if h != 2 or w == 0:
            continue
        row0 = [u16(GRID_TABLE + 2 * (idx + 2 + c)) for c in range(min(w, 32))]
        row1 = [u16(GRID_TABLE + 2 * (idx + 2 + w + c)) for c in range(min(w, 32))]
        for a, b in zip(row0, row1):
            for v in (a, b):
                if v:
                    ids_total += 1
                    ids_ok += (magic(v) == 0xBE1E)
            if a and b:
                if a == b:
                    pairs_same += 1
                else:
                    pairs_diff += 1
    return ids_ok, ids_total, pairs_same, pairs_diff


def constants_in_code():
    """The two shared record constants: are they code immediates, or only data?"""
    words = ws.load_stage2()
    packed = b"".join(struct.pack(">I", w) for w in words)
    return sum(packed.count(bytes.fromhex(h)) for h in ("b2b2b2ff", "7f7f7fff"))


def unit_template(blocks):
    """Does unit 1 carry a recurring template, i.e. are the units records rather than a directory?"""
    seen = Counter()
    for _idx, raw in blocks:
        n = struct.unpack_from(">I", raw, 4)[0]
        if n >= 2:
            seen[raw[UNIT:UNIT + UNIT].hex()] += 1
    top = seen.most_common(1)
    return (top[0][1] if top else 0), (top[0][0] if top else "")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    if not ROM.exists():
        print(f"SKIP: no cartridge at {ROM.relative_to(HERE.parent)}")
        return 0
    blocks = family(ROM.read_bytes())
    by, law, sections = analyse(blocks)
    print(f"01 41 family: {len(blocks)} block(s); unit counts {sorted(by)}")
    print(f"  word2 == filesize - 16*word1: {law}/{len(blocks)}")
    print(f"  blocks whose extra units look like a section table: {sections}")
    if not args.check:
        return 0
    maxbyte, pairs, divisible = payload_stats(blocks)
    heads, records, gbi, units, alpha = gbi_test(blocks)
    const_in_code = constants_in_code()
    kinds = loader_kinds(ROM.read_bytes())
    tiles, tile_first = grid_tiles(ROM.read_bytes())
    tile_magics, tile_second_words, gbi_share = tile_headers(ROM.read_bytes(), tiles)
    t_law, t_4bpp, t_8bpp, t_total = tile_formats(ROM.read_bytes(), tiles)
    g_true, g_px, g_stride, g_words, g_total = tile_geometry(ROM.read_bytes(), tiles)
    ids_ok, ids_total, pairs_same, pairs_diff = grid_pairs(ROM.read_bytes())
    template_hits, template = unit_template(blocks)
    cases = [
        ("the family is found and is large", len(blocks) > 200),
        ("every block satisfies word2 == filesize - 16*word1", law == len(blocks)),
        ("the unit counts span many values, so the law is not a special case",
         len(by) >= 10),
        ("the extra units are NOT a section table", sections == 0),
        # N is not a bit depth: a 1-bit payload could not contain a byte of 255, and N=1 blocks do.
        ("N is not a bit depth — full-range bytes appear even at N=1", max(maxbyte) == 255),
        # and N is not the distinct-value count either — computed, not asserted by construction.
        ("N is not the number of distinct payload values in any block",
         bool(pairs) and all(n != d for n, d in pairs)),
        ("a large share of payloads divides evenly by N", divisible > 0.7 * len(blocks)),
        # units are records with constants, not a directory of offsets.
        ("unit 1 recurs as a template across blocks", template_hits >= 10),
        # the display-list reading, tested and refuted (M161)
        ("no record begins with a GBI opcode (0xE4-0xFF), so these are not display lists", gbi == 0),
        ("the payload is not a clean RGBA5551 texture (alpha bit is neither all-set nor all-clear)",
         0.25 < alpha / max(1, units) < 0.75),
        ("the shared record constants occur nowhere in the stage-2 code image", const_in_code == 0),
        # --- relational: which loader kinds reference the family (M162)
        ("the EMD (enemy model) loader references family blocks",
         kinds["EMD"][1].get(MAGIC, 0) >= 10),
        ("the TM3 (model) loader references family blocks",
         kinds["TM3"][1].get(MAGIC, 0) >= 8),
        ("the ITP loader references a different kind entirely (no family blocks)",
         kinds["ITP"][1].get(MAGIC, 0) == 0),
        ("the EFF loader references a different kind entirely (no family blocks)",
         kinds["EFF"][1].get(MAGIC, 0) == 0),
        # --- the tiles the model grid references (M163, corrected M164)
        ("the model's grid descriptors reference a substantial set of tiles", len(tiles) >= 20),
        # M163 read the first byte 0xBE as G_MOVEMEM and called these display lists. The first *halfword*
        # is a constant across every tile (0xBE1E), and the second word is not a valid RDRAM pointer, so
        # the block is not a G_MOVEMEM command: it is a texture block with a constant magic.
        ("every tile begins with the constant halfword 0xBE1E, a magic rather than an opcode",
         all(m == 0xBE1E for m in tile_magics) and len(set(tile_magics)) == 1),
        ("no tile's second word is a valid RDRAM pointer, so it is not G_MOVEMEM",
         all(second < 0x80000000 for second in tile_second_words)),
        # A display list is nearly all opcodes: ~1.00 of its 8-byte-aligned words carry one. Raw colour
        # data cannot, so the share discriminates where a G_ENDDL scan does not (0xB8/0xDF occur in pixel
        # data by chance — that scan was written first and failed, which is what prompted this one).
        ("no tile's GBI-opcode share approaches a display list's (all are below 0.95)", max(gbi_share) < 0.95),
        # --- the T64 format itself (M165): no compression anywhere
        ("every tile's data length is exactly palette*2 + w*h*bpp/8", t_law == t_total),
        ("the 4 bpp tiles are consistent: nibbles <= 15 and exactly 2*w*h of them", t_4bpp >= 15),
        ("the 8 bpp tiles are consistent: one byte per pixel, w*h of them", t_8bpp >= 30),
        ("both texture formats are present, so the law is not one format's special case",
         t_4bpp > 0 and t_8bpp > 0),
        # --- what `h1` is (M166)
        ("h1 is the true pixel height: h1 == h*8/bpp on every tile", g_true == g_total),
        ("w*h1*bpp/8 equals the pixel byte count on every tile", g_px == g_total),
        ("h1 is NOT a row stride in bytes (that reading fits almost nothing)", g_stride <= 2),
        ("h1 is NOT a row stride in 8-byte words", g_words == 0),
        # --- the registry's pairing rule (M167)
        ("every id in a two-row grid resolves to a tile block", ids_total > 0 and ids_ok == ids_total),
        ("two-row grids contain both equal-id columns (one block) and differing ones (a pair)",
         pairs_same > 0 and pairs_diff > 0),
    ]
    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} 01-41 container case(s)")
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
