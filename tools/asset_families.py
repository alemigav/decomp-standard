#!/usr/bin/env python3
"""The cartridge's record-table families: two script ranges, one undecoded family, and no 48 of anything.

The audio backlog left three questions open: which file-table records the `DOOR_SCD` name actually covers,
what the id families at 3379+n and 3504+n are, and whether a per-room **48-record** sound table exists. The
first two turn out to be one question about a **container shape**; the third turns out to be answerable and
negative.

The shape, and why it is not a guess. A block whose head is a `u16` offset table is self-describing, because
its first entry is the table's own size:

    u16 end      == 2 * count, so the table ends exactly where it says it does
    u16[count]   offsets, `offsets[0] == end`, strictly ascending, all inside the block

That makes `count` a **derived** number rather than a stored one, and it is the rule `walk_stream.py` already
started at: M146's tool walks id 1881 from `0x80400018`, and `offsets[0]` for 1881 is `0x12`. Getting the
count one low (`end/2 - 1`) reads the same table with one entry missing, which is the error this file made
first and the mutation list keeps as a case.

Scanning every real entry of the file table for that shape finds **two** ranges and nothing else:

    id 1881..1927   47 members   record 0 is `0x13 Switch` on **47 of 47**
    id 3504..3708  198 members   record 0 varies (0x06 ×88, 0x18 ×59, 0x2c ×13, ...)

Every record entry in both families begins with a byte below **141**, the size of the opcode space the
`walk_stream` decoder accepts — **462 of 462** in the first range and **3158 of 3158** in the second. If those
bytes were uniform the chance is `(141/256)^3158 ~ 10^-827`, so the second range is the same kind of object
as the first: a block of script records. What it is *for* is not established, and neither is what selects it:
**no room-table id points into 3504..3708**.

The third range is a different container entirely:

    id 3379..3503   71 members   one 8-byte head `0002 3b00 0131 0000`, undecoded here

The `DOOR_SCD` half of the question resolves like this: `DAT_80131fa8` holds **147** distinct ids, of which
**47** are record-table members (all of 1881..1927) and **100** are not — and the ones sampled are not broken
scripts but a different object, the `01 41` container (`0x01410000` head) or a two-record stub. So the name
covers the room table's ids, and only the first 47 of them are script blocks of this shape.

And the 48: the record counts across the 245 members run **2..54** with 9 the mode, and **48 is not among
them**. No sound artefact publishes 48 either (`snd_proj` 6 lists / 417 records, `snd_macros` 327 sequences of
2..13 elements, `voice_descriptor` 2 slots). The "per-room 48-record sound table" is not a thing this
cartridge has, in any structure measured so far — stated as a refusal, not a correction of whoever wrote it.

Usage:
  ./asset_families.py --write     # regenerate manifests/asset_families.json
  ./asset_families.py --check     # validate the committed artefact against a fresh derivation
  ./asset_families.py --list      # print the census
"""
import argparse
import hashlib
import importlib.util
import json
import struct
import sys
import zlib
from collections import Counter
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
OUT = Path("manifests") / "asset_families.json"
SCHEMA = "asset-families/1"

_spec = importlib.util.spec_from_file_location("rsp_decode", HERE / "rsp_decode.py")
rd = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(rd)

_spec2 = importlib.util.spec_from_file_location("cfg_reach", HERE / "cfg_reach.py")
cfg = importlib.util.module_from_spec(_spec2)
_spec2.loader.exec_module(cfg)

ROM = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
BASE, HEADER = 0x0C8624, 0x28
OPCODE_SPACE = 141                 # walk_stream.py refuses a first byte at or above this
ZERO_REGION_HEAD = bytes.fromhex("00023b0001310000")
CONTAINER_0141 = bytes.fromhex("0141")


def entries():
    d = ROM.read_bytes()
    count = struct.unpack_from(">I", d, BASE)[0]
    return d, [struct.unpack_from(">II", d, BASE + HEADER + 8 * i) for i in range(count)]


def payload(d, entry):
    """The block, decompressed. `None` for a sentinel or a member that does not inflate cleanly."""
    off, size = entry
    if off == 0xFFFFFFFF or not size:
        return None
    raw = d[BASE + off:BASE + off + size]
    if raw[:2] == b"\x68\xde":
        try:
            block = zlib.decompress(raw)
        except zlib.error:
            return None
        return None if block[:2] == b"\x68\xde" else block
    return raw


def record_table(block, floor=3):
    """`[u16 end][offsets...]` with `end == 2*count`; returns (count, offsets) or None.

    `floor` is a **threshold**, not part of the shape: at 2 the signature admits 11 more members and 4 of
    them lie outside the two ranges, at 3 it admits none outside. Both numbers are in the artefact, because
    the specificity of a signature is a measurement and not a definition.
    """
    if block is None or len(block) < 6:
        return None
    end = struct.unpack_from(">H", block, 0)[0]
    if end < 2 * floor or end % 2 or end > len(block):
        return None
    count = end // 2
    offsets = list(struct.unpack_from(">" + str(count) + "H", block, 0))
    if offsets[0] != end:
        return None
    if any(offsets[i] >= offsets[i + 1] for i in range(count - 1)):
        return None
    if offsets[-1] >= len(block):
        return None
    return count, offsets


def runs(ids):
    ids = sorted(ids)
    if not ids:
        return []
    out, start, prev = [], ids[0], ids[0]
    for v in ids[1:]:
        if v == prev + 1:
            prev = v
            continue
        out.append([start, prev])
        start = prev = v
    out.append([start, prev])
    return out


def derive():
    d, table = entries()
    blocks, members, zero_region = {}, {}, []
    for i, e in enumerate(table):
        b = payload(d, e)
        if b is None:
            continue
        blocks[i] = b
        shape = record_table(b)
        if shape:
            members[i] = shape
        if b[:8] == ZERO_REGION_HEAD:
            zero_region.append(i)

    bounds = [[1881, 1927], [3504, 3708]]
    outside = sorted(i for i in members if not any(a <= i <= c for a, c in bounds))

    floors = {}
    for floor in (2, 3, 4):
        hit = {}
        for i, b in blocks.items():
            shape = record_table(b, floor)
            if shape:
                hit[i] = shape
        floors[str(floor)] = {
            "members": len(hit),
            "outside_the_two_ranges": len([i for i in hit if not any(a <= i <= c for a, c in bounds)]),
            "outside_ids": sorted(i for i in hit if not any(a <= i <= c for a, c in bounds)),
        }

    families = []
    for a, c in bounds:
        ids = sorted(i for i in members if a <= i <= c)
        entry_bytes, first_bytes, counts = Counter(), Counter(), Counter()
        for i in ids:
            block = blocks[i]
            count, offsets = members[i]
            counts[count] += 1
            for k, off in enumerate(offsets):
                if off >= len(block):
                    continue
                entry_bytes[block[off]] += 1
                if k == 0:
                    first_bytes[block[off]] += 1
        families.append({
            "range": [a, c],
            "members": len(ids),
            "records": sum(counts[c2] * c2 for c2 in counts),
            "record_counts": dict(sorted(counts.items())),
            "record0_bytes": dict(sorted(first_bytes.items())),
            "entry_bytes": dict(sorted(entry_bytes.items())),
            "valid_entry_bytes": sum(v for k, v in entry_bytes.items() if k < OPCODE_SPACE),
            "entry_bytes_total": sum(entry_bytes.values()),
            "ids_sample": ids[:8],
        })

    room_ids = sorted(cfg.room_script_ids())
    room_members = [i for i in room_ids if i in members]
    room_not = [i for i in room_ids if i not in members]
    not_sample = {}
    for i in room_not[:8]:
        b = blocks.get(i)
        not_sample[i] = (b[:2].hex() if b else None)

    return {
        "tool": "asset_families.py",
        "schema": SCHEMA,
        "inputs": {
            "cartridge": "rom/Resident Evil 2 (USA) (Rev 1).z64 (sha256 %s)" % hashlib.sha256(d).hexdigest(),
            "file_table": "cart 0x%06x, %d entries" % (BASE, len(table)),
            "room_table": "DAT_80131fa8, 256 slots -> %d distinct ids (M145/M156)" % len(room_ids),
            "rule": "a record table is `[u16 end][end/2 offsets]` with end == 2*count, offsets[0] == end, "
                    "strictly ascending, all inside the block; the entry byte at each offset must be below "
                    "%d, the opcode space walk_stream.py accepts" % OPCODE_SPACE,
        },
        "trials": {"real_entries": len(blocks), "sentinel_or_bad": len(table) - len(blocks)},
        "members_total": len(members),
        "families": families,
        "runs": runs(members),
        "outside_the_two_ranges": outside,
        "floor_sensitivity": floors,
        "record_count_histogram": dict(sorted(Counter(c for c, _o in members.values()).items())),
        "forty_eight": {"members_with_48_records": [i for i, (c, _o) in members.items() if c == 48],
                        "counts_seen": [min(c for c, _o in members.values()),
                                        max(c for c, _o in members.values())]},
        "zero_region_family": {
            "members": len(zero_region),
            "ids": zero_region,
            "runs": runs(zero_region),
            "head": ZERO_REGION_HEAD.hex(),
            "head_matches": sum(1 for i in zero_region if blocks[i][:8] == ZERO_REGION_HEAD),
        },
        "room_table": {
            "ids": len(room_ids),
            "record_table_members": len(room_members),
            "not_members": len(room_not),
            "members_are_all_of_1881_1927": sorted(room_members) == list(range(1881, 1928)),
            "not_member_samples": not_sample,
            "container_0141_heads": sum(1 for i in room_not
                                        if blocks.get(i, b"")[:2] == CONTAINER_0141),
        },
        "reading": "the record-table shape identifies **two** script ranges and nothing else: **47** blocks at "
                   "1881..1927, whose record 0 is `0x13 Switch` on 47 of 47, and **198** at 3504..3708, whose "
                   "record 0 varies. Every record entry in both begins below %d (462/462 and 3158/3158), which "
                   "is what makes the second range a script family and not a look-alike. No room-table id points "
                   "into 3504..3708. The ids at 3379..3503 are a third, undecoded container." % OPCODE_SPACE,
        "not_claimed": [
            "what selects the 3504..3708 family: no room-table id, no roster in the image, and nothing in the "
            "corpus names those ids, so 'who reads them' is open",
            "what the 3379..3503 family is beyond its head `0002 3b00 0131 0000` and its 71 members",
            "that a record table means script bytes for *every* member: the entry-byte test is evidence over "
            "245 blocks and 3620 records, not a decode of each",
            "45 records is the largest count seen here, so '48' is refuted for this shape only -- a sound table "
            "of another shape is not excluded by this test",
        ],
    }


def normalise(obj):
    """Round-trip through JSON so integer-keyed dicts compare as the strings the file holds.

    Without this the artefact-equality case fails on *key order alone*: `json.dumps` sorts integer keys
    numerically and string keys lexicographically, so a manifest that is byte-identical in content compares
    unequal to its own derivation. The sorted-ness of a dict is not a fact about the cartridge.
    """
    return json.dumps(json.loads(json.dumps(obj)), sort_keys=True)


def check(committed):
    """Grade the fresh derivation; only the artefact-equality case and the refusals read `committed`."""
    fresh = derive()
    fam = fresh["families"]
    cases = []

    cases.append((f"every real entry is tested and {fresh['members_total']} carry a record table "
                  f"({fresh['trials']['real_entries']} blocks, {fresh['trials']['sentinel_or_bad']} skipped)",
                  fresh["members_total"] == 245
                  and fresh["trials"]["real_entries"] + fresh["trials"]["sentinel_or_bad"] == 8091
                  and normalise(committed) == normalise(fresh)))

    cases.append((f"the members fall into exactly two id ranges, with {len(fresh['outside_the_two_ranges'])} "
                  f"outside them ({[f['range'] for f in fam]})",
                  len(fam) == 2 and fresh["outside_the_two_ranges"] == []
                  and [f["members"] for f in fam] == [47, 198]))

    cases.append((f"the shape is specific at a floor of 3: floor 2 admits "
                  f"{fresh['floor_sensitivity']['2']['members']} members and "
                  f"{fresh['floor_sensitivity']['2']['outside_the_two_ranges']} outside, floor 3 admits "
                  f"{fresh['floor_sensitivity']['3']['outside_the_two_ranges']} outside",
                  fresh["floor_sensitivity"]["3"]["outside_the_two_ranges"] == 0
                  and fresh["floor_sensitivity"]["2"]["outside_ids"] == [1928, 1929, 1930, 3462]))

    for f in fam:
        cases.append((f"every record entry in {f['range'][0]}..{f['range'][1]} begins below "
                      f"{OPCODE_SPACE} ({f['valid_entry_bytes']}/{f['entry_bytes_total']} over "
                      f"{f['records']} records)",
                      f["valid_entry_bytes"] == f["entry_bytes_total"] and f["entry_bytes_total"] >= f["records"]))

    a, b = fam
    cases.append((f"the first range is the room-entry family: record 0 is 0x13 Switch on "
                  f"{a['record0_bytes'].get(str(19)) or a['record0_bytes'].get(19, 0)} of {a['members']}",
                  a["record0_bytes"].get(19, a["record0_bytes"].get("19")) == a["members"]))

    cases.append((f"the second range is not: its record 0 spans "
                  f"{len(b['record0_bytes'])} distinct opcodes and 0x13 is not among them",
                  len(b["record0_bytes"]) >= 8
                  and b["record0_bytes"].get(19, b["record0_bytes"].get("19")) is None))

    zero = fresh["zero_region_family"]
    cases.append((f"the third family is one 8-byte head on {zero['head_matches']} of {zero['members']} "
                  f"members, ids {zero['runs'][0][0]}..{zero['runs'][-1][1]}",
                  zero["head_matches"] == zero["members"] == 71
                  and zero["runs"][0][0] == 3379 and zero["runs"][-1][1] == 3503))

    room = fresh["room_table"]
    cases.append((f"the room table names {room['ids']} ids, of which {room['record_table_members']} are "
                  f"record tables and all of those are 1881..1927",
                  room["members_are_all_of_1881_1927"] and room["record_table_members"] == 47
                  and room["not_members"] == 100))

    four = fresh["forty_eight"]
    cases.append((f"no member has 48 records (counts {four['counts_seen'][0]}..{four['counts_seen'][1]}, "
                  f"{four['members_with_48_records']} with 48)",
                  four["members_with_48_records"] == []))

    cases.append(("every family says what is not claimed",
                  len(committed["not_claimed"]) >= 4))
    return cases


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--list", action="store_true")
    a = ap.parse_args()

    if not ROM.exists():
        print("SKIP (needs the cartridge: %s)" % ROM.relative_to(ROOT))
        return 0

    if a.write:
        rep = derive()
        OUT.write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        print("wrote %s — %d members in %d range(s): %s; zero-region %d; 48-records %s"
              % (OUT, rep["members_total"], len(rep["families"]),
                 [(f["range"], f["members"]) for f in rep["families"]],
                 rep["zero_region_family"]["members"], rep["forty_eight"]["members_with_48_records"]))
        return 0

    if a.list:
        rep = derive()
        for f in rep["families"]:
            print("range %d..%d  %3d members  %5d records  record0 %s"
                  % (f["range"][0], f["range"][1], f["members"], f["records"],
                     sorted(f["record0_bytes"].items(), key=lambda kv: -kv[1])[:4]))
        z = rep["zero_region_family"]
        print("3379-family  %3d members, head %s, runs %s" % (z["members"], z["head"], z["runs"]))
        print("floor sensitivity:", {k: (v["members"], v["outside_ids"]) for k, v in
                                     sorted(rep["floor_sensitivity"].items())})
        return 0

    if not a.check:
        ap.error("one of --write, --check, --list is required")
    committed = json.loads((ROOT / OUT).read_text())
    cases = check(committed)
    bad = 0
    for label, ok in cases:
        bad += not ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d asset-family case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
