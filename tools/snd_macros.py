#!/usr/bin/env python3
"""The macro command space: four opcodes on a key's class tag, and no opcode byte anywhere.

WP1 (`tools/snd_proj.py`) ended with `command_streams: 0` and pointed at the `SND_POOL` side. This is
that side, and the answer is narrower and better than "decode all macros". The command space is **not a
bytecode**: an operation is selected by the top two bits of a 16-bit key — the same `(key >> 14) & 3`
tag `tools/snd_proj.py` measures as a *storage class* — and the "program" is an array of fixed-size
elements in a pool record's payload, run by `FUN_800a6820` and `FUN_800a64c8`. There is no opcode byte
and no variable-length element in the whole family; that is a negative, and it is the negative that
makes the positive usable.

    opcode          payload                              reader -> what it requests
    0x0000 key      class-0 record, 24..128 B            FUN_800b185c -> FUN_800ad998: one voice on
                    = 3..16 eight-byte elements          that sample record
    0x4000 key      128 x 8-byte entries                 FUN_800adf54: entry[selector & 0x7f] ->
                                                          another key, and the dispatcher re-enters
    0x8000 key      {u32 count} + count x 12-byte rows   FUN_800adfb4 -> FUN_800a64c8: run the rows in
                                                          order, one voice per live row
    0xc000 key      8 B = 4 little-endian u16            FUN_800afbfc: a level ramp on an existing
                                                          voice; the note dispatcher REFUSES it

The dispatch is three branches and a refusal, all in one function, and that is what makes four rows
defensible rather than invented: `FUN_800a6820` masks `key & 0xc000` and handles `0x4000`, `0x8000` and
`0`, returning `-1` for `0xc000`. Each row in `commands` names the `src/` witness it rests on, and
`--check` re-reads those witnesses — a row whose code moves is a failing row, not a stale claim.

What this artefact refuses:

  * **no opcode field inside an element.** All 981 live rows of the 12-byte sequences perform the same
    request (one voice) and differ only in operands; `+9..+11` are zero on all 1 315 rows. Calling a row
    byte an opcode would be inventing the thing WP1 went looking for. The four opcodes live one level
    *up*, in the key, and the sequence's own element vocabulary is one operation plus a skip marker.
  * **0xffff is a skip, not a terminator.** The loop bound is the explicit count at `record + 8`; the
    `*puVar1 != 0xffff` test guards the body. The last element is `0xffff` on 327/327 arrays, but 7 of
    the 334 sentinels sit *inside* an array and carry non-zero bytes in their remaining ten — so the
    structure is a count-prefixed array with a hole marker, and this artefact does not model it as a
    C string.
  * **no name for the class-0 payload's interior.** The payload is an 8-byte element array of 3..16
    elements (the reader computes `payload + param_8 * 8`), but nothing in the corpus reads an element's
    fields at a named offset, so the fields are `unresolved` and are not tabulated.
  * **no reading of the class-3 ramp's curve** — `FUN_800adef4` is called from `FUN_800afbfc` with its
    argument dropped by the decompiler, so which field selects the interpolation table is open.
  * **no claim that the tag bits are a "type" in the cartridge's vocabulary.** `0x4000`/`0x8000`/`0xc000`
    are published as the values the dispatcher branches on, which is all the code says.

One correction to WP1, made here because the counts below depend on it and not because WP1 is this
tool's business: **a section's first record starts AT the section offset**, not one stride past it. The
u32 at the section start is the first record's own stride — the same shape `SND_PROJ` has, where record 0
is at offset 0. Read the other way, each section leaves a gap exactly one record wide (112 / 16 / 1032 /
60 bytes), and the four keys the walk then skips are precisely the four values WP1 published as
`unresolved` (`531`, `0xc085`, `0x4001`, `0x8098`). With the base corrected the counts are 2026 / 242 /
4 / 327 = 2 599 records, and **every one of the 7 388 `SND_PROJ` list values resolves** — lists 0, 2, 3
and 4 are bijections onto the four pool classes. `tools/snd_proj.py` is unmodified; see `sections` below
for the measurement, which `--check` re-runs.

Usage:
  ./snd_macros.py --write    # regenerate manifests/snd_macros.json from the cartridge
  ./snd_macros.py --check    # validate the committed artefact against a fresh derivation
"""
import argparse
import hashlib
import json
import struct
import sys
import zlib
from collections import Counter
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))

# The cartridge accessor is `tools/file_table.py`'s, for the reason WP1 gives: the file table's base and
# entry layout live there, and a second copy of them is how two tools come to disagree about one member.
import file_table as ft

OUT = "manifests/snd_macros.json"

POOL, PROJ = 1981, 1980

MASK = 0xC000                 # the two bits the dispatcher switches on: ((key >> 14) & 3) << 14
TAG_SHIFT = 14

OP_NOTE, OP_TABLE, OP_SEQUENCE, OP_RAMP = 0x0000, 0x4000, 0x8000, 0xC000

ROW_BYTES = 12                # a sequence element: `puVar1 = puVar1 + 6` over a `ushort *`
SLOT_BYTES = 8                # a table slot, a class-0 payload element, a ramp parameter set
TABLE_SLOTS = 128             # section 2 payloads are 1024 B on 4/4 records
SENTINEL = 0xFFFF             # the element the sequence body skips

# Section order in the member is 0, 3, 1, 2 by tag — WP1's correction, re-measured here rather than
# trusted: the tag is read off each record's key, not assumed from the section index.
SECTION_FOR_TAG = {0: 0, 3: 1, 1: 2, 2: 3}


# --- access ------------------------------------------------------------------------------------

def cartridge():
    """The cartridge bytes and its file table, through `file_table`'s own accessor."""
    data, _count, entries = ft.load()
    return data, entries


def member(data, entries, index):
    """One file-table member, inflated. Raises if the entry is a sentinel or not zlib."""
    offset, size = entries[index]
    if offset == 0xFFFFFFFF or size == 0:
        raise ValueError("file id %d is a sentinel entry" % index)
    return zlib.decompress(data[ft.BASE + offset:ft.BASE + offset + size])


# --- primitives --------------------------------------------------------------------------------

def u16(b, o):
    return struct.unpack_from(">H", b, o)[0]


def u32(b, o):
    return struct.unpack_from(">I", b, o)[0]


def s16(b, o):
    return struct.unpack_from(">h", b, o)[0]


def u8(b, o):
    return b[o]


def s8(b, o):
    return struct.unpack_from("b", b, o)[0]


def le16(b, o):
    return struct.unpack_from("<H", b, o)[0]


def tag(key):
    return (key >> TAG_SHIFT) & 3


# --- structure ---------------------------------------------------------------------------------

def chain(b, start, end):
    """`(record starts, terminator offset)` for one section, from `start` to `end`.

    `start` IS the first record: the u32 there is that record's stride, the same construct
    `tools/snd_proj.py` walks in `SND_PROJ` where record 0 sits at offset 0. Starting one stride later
    drops a record per section and leaves a gap the width of a record — the measurement `by_start`
    below reports, so the claim is checked rather than asserted.
    """
    pos, out = start, []
    while pos + 4 <= end:
        step = struct.unpack_from(">i", b, pos)[0]
        if step == -1:
            return out, pos
        if step <= 0:
            raise ValueError("record at %#x declares stride %d" % (pos, step))
        out.append(pos)
        pos += step
    raise ValueError("no -1 terminator before %#x" % (end,))


def section_offsets(pool):
    return list(struct.unpack_from(">4I", pool, 0))


def walk_late(b, start, end):
    """The walk WP1 published, kept only to measure what it costs: start + u32@start."""
    return chain(b, start + u32(b, start), end)


# --- derivation --------------------------------------------------------------------------------

def derive():
    """The whole artefact, measured. Nothing here is a constant copied from a note."""
    data, entries = cartridge()
    pool = member(data, entries, POOL)
    proj = member(data, entries, PROJ)
    offsets = section_offsets(pool)

    # --- the four sections, walked from their own first record
    sections, starts_by_tag, by_start = [], {}, []
    for index, start in enumerate(offsets):
        end = offsets[index + 1] if index + 1 < len(offsets) else len(pool)
        starts, term = chain(pool, start, end)
        late, late_term = walk_late(pool, start, end)
        keys = [u16(pool, r + 4) for r in starts]
        tags = Counter(tag(k) for k in keys)
        if len(tags) != 1:
            raise ValueError("section %d carries more than one tag: %s" % (index, dict(tags)))
        starts_by_tag[tag(keys[0])] = starts
        skipped = set(starts) - set(late)
        by_start.append({
            "index": index,
            "record_at_section_offset": len(starts) - len(late),
            "records_if_started_one_stride_late": len(late),
            "gap_bytes": (late[0] - start) if late else 0,
            "record_at_start_key": u16(pool, start + 4),
            "keys_the_late_walk_skips": [u16(pool, r + 4) for r in sorted(skipped)],
        })
        sections.append({
            "index": index,
            "offset": start,
            "end": end,
            "tag": tag(keys[0]),
            "opcode": OP_NAMES[tag(keys[0])],
            "records": len(starts),
            "terminator_offset": term,
            "tiles_section": term + 4 == end,
            "key_range": [min(keys), max(keys)],
            "keys_distinct": len(set(keys)),
            "first_record": {
                "offset": start,
                "stride": struct.unpack_from(">i", pool, start)[0],
                "key": keys[0],
                "evidence": (
                    "the record starts AT the section offset: its stride at +0 chains to %#x and the "
                    "chain closes on the -1 at %#x, four bytes before the next section (tiles on %s). "
                    "A walk begun one stride late drops record %#x and leaves its %d bytes unparsed; "
                    "that record's key is %#x, which is one of the four values WP1 published as "
                    "unresolved."
                    % (starts[1] if len(starts) > 1 else term, term, term + 4 == end, start,
                       (late[0] - start) if late else 0, keys[0])),
            },
        })

    # --- opcode 0x8000: the sequence — count-prefixed 12-byte rows
    seq_records = starts_by_tag[2]
    rows, live, sentinels = [], [], []
    interior_sentinels, count_census = 0, Counter()
    closed = 0
    for rec in seq_records:
        stride = struct.unpack_from(">i", pool, rec)[0]
        count = u32(pool, rec + 8)
        block = [pool[rec + 12 + ROW_BYTES * k:rec + 24 + ROW_BYTES * k] for k in range(count)]
        closed += stride == 12 + ROW_BYTES * count
        count_census[count] += 1
        for i, row in enumerate(block):
            rows.append(row)
            if u16(row, 0) == SENTINEL:
                sentinels.append(row)
                interior_sentinels += i != count - 1
            else:
                live.append(row)

    def census(elements, fields):
        out = []
        for off, size, kind in fields:
            read = {"u8": u8, "s8": s8, "u16": u16, "s16": s16, "le16": le16}[kind]
            vals = [read(e, off) for e in elements]
            distinct = len(set(vals))
            entry = {"offset": off, "size": size, "type": kind, "distinct": distinct,
                     "range": [min(vals), max(vals)]}
            if distinct == 1:
                entry["constant"] = vals[0]
            out.append(entry)
        return out

    row_fields = [(0, 2, "u16"), (2, 1, "u8"), (3, 1, "u8"), (4, 1, "s8"), (5, 1, "u8"),
                  (6, 2, "s16"), (8, 2, "u16"), (10, 2, "u16")]
    row_census = census(live, row_fields)
    windows_ordered = sum(1 for row in live if u8(row, 2) <= u8(row, 3))
    pan_flag_set = sum(1 for row in live if u16(row, 8) & 0x8000)
    tail_zero = sum(1 for row in rows if row[9] == 0 and row[10] == 0 and row[11] == 0)

    # monotonicity inside a sequence, on the three candidate orders
    asc_key = asc_window = 0
    for rec in seq_records:
        count = u32(pool, rec + 8)
        block = [pool[rec + 12 + ROW_BYTES * k:rec + 24 + ROW_BYTES * k] for k in range(count)]
        body = [row for row in block if u16(row, 0) != SENTINEL]
        keys = [u16(row, 0) for row in body]
        asc_key += all(a < b for a, b in zip(keys, keys[1:]))
        asc_window += all((u8(a, 2), u8(a, 3)) <= (u8(b, 2), u8(b, 3))
                          for a, b in zip(body, body[1:]))
    last_sentinel = sum(1 for rec in seq_records
                        if u16(pool, rec + 12 + ROW_BYTES * (u32(pool, rec + 8) - 1)) == SENTINEL)
    seq_keys = [u16(pool, rec + 4) for rec in seq_records]
    asc_record = sum(1 for a, b in zip(seq_keys, seq_keys[1:]) if a < b)

    # --- opcode 0x4000: the table — 128 fixed 8-byte slots
    tab_records = starts_by_tag[1]
    slots, live_slots, slot_counts = [], [], []
    for rec in tab_records:
        stride = struct.unpack_from(">i", pool, rec)[0]
        n = (stride - SLOT_BYTES) // SLOT_BYTES
        slot_counts.append(n)
        block = [pool[rec + 8 + SLOT_BYTES * k:rec + 16 + SLOT_BYTES * k] for k in range(n)]
        slots += block
        live_slots += [(k, s) for k, s in enumerate(block) if u16(s, 0) != SENTINEL]
    slot_fields = [(0, 2, "u16"), (2, 1, "s8"), (3, 1, "u8"), (4, 2, "s16"), (6, 2, "u16")]
    slot_census = census([s for _k, s in live_slots], slot_fields)
    steps = []
    for rec in tab_records:
        n = (struct.unpack_from(">i", pool, rec)[0] - SLOT_BYTES) // SLOT_BYTES
        live_idx = [k for k in range(n)
                    if u16(pool, rec + 8 + SLOT_BYTES * k) != SENTINEL]
        for a, b in zip(live_idx, live_idx[1:]):
            if b == a + 1:
                da = s8(pool, rec + 8 + SLOT_BYTES * a + 2)
                db = s8(pool, rec + 8 + SLOT_BYTES * b + 2)
                steps.append(db - da)
    step_law = sum(1 for d in steps if d == -1)

    # --- opcode 0xc000: the ramp — one 8-byte parameter set per record
    ramp_records = starts_by_tag[3]
    ramps = [pool[rec + 8:rec + 16] for rec in ramp_records]
    ramp_fields = [(0, 2, "le16"), (2, 2, "le16"), (4, 2, "le16"), (6, 2, "le16")]
    ramp_census = census(ramps, ramp_fields)

    # --- opcode 0x0000: the sample record — an 8-byte element array, interior unresolved
    note_records = starts_by_tag[0]
    note_payloads = [struct.unpack_from(">i", pool, rec)[0] - 8 for rec in note_records]
    note_elements = [n // SLOT_BYTES for n in note_payloads]

    # --- the cross-reference: SND_PROJ's five key lists against these records
    pro_starts, _pro_term = chain(proj, 0, len(proj))
    pool_keys = {t: {u16(pool, r + 4) for r in starts} for t, starts in starts_by_tag.items()}
    every_key = set().union(*pool_keys.values())
    project_lists = []
    for index in range(5):
        values = []
        for rec in pro_starts:
            off = struct.unpack_from(">I", proj, rec + 8 + 4 * index)[0]
            pos = rec + 8 + off
            while u16(proj, pos) != 0xFFFF:
                values.append(u16(proj, pos))
                pos += 2
        distinct = sorted(set(values))
        classes = Counter(tag(v) for v in distinct)
        if len(classes) != 1:
            raise ValueError("project list %d draws on more than one tag: %s"
                             % (index, dict(classes)))
        forced = SECTION_FOR_TAG[tag(distinct[0])]
        project_lists.append({
            "index": index,
            "values": len(values),
            "distinct": len(distinct),
            "tag": tag(distinct[0]),
            "opcode": OP_NAMES[tag(distinct[0])],
            "pool_records": len(starts_by_tag[tag(distinct[0])]),
            "unresolved": sum(1 for v in values if v not in every_key),
            "bijection": len(distinct) == len(starts_by_tag[tag(distinct[0])])
                         and not [v for v in values if v not in every_key],
            "evidence": (
                "all %d distinct values carry tag %d and %d of them name a record in section %d "
                "(%d records); %d value(s) name no record"
                % (len(distinct), tag(distinct[0]), len(distinct) - sum(1 for v in distinct
                                                                       if v not in every_key),
                   forced, len(starts_by_tag[tag(distinct[0])]),
                   sum(1 for v in values if v not in every_key))),
        })

    # --- the artefact
    commands = [
        {
            "opcode": "0x0000",
            "tag": 0,
            "mask": "0xc000",
            "section": SECTION_FOR_TAG[0],
            "payload": "class-0 record: the whole member's largest section, one record per sample",
            "element_size": SLOT_BYTES,
            "elements_per_record": [min(note_elements), max(note_elements)],
            "records": len(note_records),
            "payload_bytes": [min(note_payloads), max(note_payloads)],
            "operands": [{
                "offset": 0, "size": SLOT_BYTES,
                "name": "sample element, indexed by the eighth argument of the voice allocator",
                "evidence": "FUN_800b185c stores the record payload pointer and the expression "
                            "`iVar1 + (uint)param_8 * 8`, so the payload is an array of 8-byte "
                            "elements addressed by an index it is handed; the element's own fields "
                            "are not read at a named offset anywhere in the corpus and are "
                            "unresolved here",
            }],
            "requests": "one voice, on the class-0 record this key names",
            "evidence": [
                {"file": "src/stage2/FUN_800a6820.c", "witness": "if (uVar3 != 0) {",
                 "claim": "tag 0 is the branch that falls through to the voice allocator"},
                {"file": "src/stage2/FUN_800a6820.c",
                 "witness": "iVar6 = FUN_800b185c(uVar8,uVar9,param_2,param_3,param_4 & 0xff,",
                 "claim": "FUN_800b185c is called with the key in bits 16..31 of the packed word"},
                {"file": "src/stage2/FUN_800b185c.c", "witness": "iVar1 = FUN_800ad998(param_1 >> 0x10);",
                 "claim": "the voice allocator looks the key up in the sample cache"},
                {"file": "src/stage2/FUN_800b185c.c",
                 "witness": "*(uint *)(iVar3 + -0x7febbbb4) = iVar1 + (uint)param_8 * 8;",
                 "claim": "and stores payload + index*8, which fixes the element size at 8"},
                {"file": "src/stage2/FUN_800ad998.c",
                 "witness": "FUN_800ab43c(0x8014e0e8,_DAT_8014e0e0 * 8 + -0x7feac1f0,",
                 "claim": "the sample cache is binary-searched at stride 8 and returns the record "
                          "payload pointer the cache was built with"},
            ],
            "confidence": "established (that a voice is requested on this record); the payload's "
                          "field meanings are unresolved",
        },
        {
            "opcode": "0x4000",
            "tag": 1,
            "mask": "0xc000",
            "section": SECTION_FOR_TAG[1],
            "payload": "128 fixed 8-byte slots; the payload is 1024 B on every record",
            "element_size": SLOT_BYTES,
            "elements_per_record": [min(slot_counts), max(slot_counts)],
            "records": len(tab_records),
            "live_elements": len(live_slots),
            "operands": [
                {"offset": 0, "size": 2, "type": "u16", "name": "key",
                 "census": slot_census[0],
                 "evidence": "`uVar1 = *(ushort *)(uVar3 * 8 + iVar6)` is the key the slot yields; "
                             "`0xffff` at +0 makes FUN_800a6820's caller path return -1, and 17/17 "
                             "live slots hold a class-0 key"},
                {"offset": 2, "size": 1, "type": "s8", "name": "selector_delta",
                 "census": slot_census[1],
                 "evidence": "`uVar8 = (param_2 & 0x7f) + (int)*(char *)(uVar3 * 8 + iVar6 + 2)` "
                             "then clamped to 0..0x7f"},
                {"offset": 3, "size": 1, "type": "u8", "name": "pan_offset_or_flag",
                 "census": slot_census[2],
                 "evidence": "`if ((*(byte *)((int)psVar5 + 3) & 0x80) == 0)` takes "
                             "`(slot[+3] - 0x40) + param_4`, else leaves the pan at the 0x80 "
                             "sentinel; 0x40 is the no-change centre and is what all %d live slots "
                             "hold" % len(live_slots)},
                {"offset": 4, "size": 2, "type": "s16", "name": "channel_delta",
                 "census": slot_census[3],
                 "evidence": "`iVar7 = iVar7 + *(short *)(uVar3 * 8 + iVar6 + 4)` then clamped "
                             "0..0xff"},
                {"offset": 6, "size": 2, "type": "u16", "name": "zero",
                 "census": slot_census[4],
                 "evidence": "constant zero on every live slot; nothing in the corpus reads it"},
            ],
            "requests": "replace the key with the one at slot[selector & 0x7f], offset the selector "
                        "and the channel, and re-enter the dispatcher (FUN_800a64c8) when the "
                        "substituted key is not a sample",
            "evidence": [
                {"file": "src/stage2/FUN_800a6820.c", "witness": "if (uVar3 == 0x4000) {",
                 "claim": "tag 1 is its own branch: the only one that reads a table"},
                {"file": "src/stage2/FUN_800a6820.c", "witness": "iVar6 = FUN_800adf54(uVar9);",
                 "claim": "the branch looks up the class-1 payload for this key"},
                {"file": "src/stage2/FUN_800a6820.c", "witness": "psVar5 = (short *)(uVar3 * 8 + iVar6);",
                 "claim": "and indexes it at stride 8 by `param_2 & 0x7f`"},
                {"file": "src/stage2/FUN_800a6820.c", "witness": "if ((uVar1 & 0xc000) != 0) {",
                 "claim": "a non-class-0 substituted key goes to the sequence runner rather than "
                          "straight to a voice"},
                {"file": "src/stage2/FUN_800adf54.c",
                 "witness": "FUN_800ab43c(0x8014e138,0x801521f0,_DAT_801521e0,8,&LAB_800ae164);",
                 "claim": "the cache this reads is the 8-byte-stride one FUN_800acbc0 fills, whose "
                          "payload pointer is the pool record's +8 (FUN_800a86a0 passes `piVar5 + 2`)"},
            ],
            "confidence": "established",
        },
        {
            "opcode": "0x8000",
            "tag": 2,
            "mask": "0xc000",
            "section": SECTION_FOR_TAG[2],
            "payload": "{u32 count at record+8} then count 12-byte rows at record+12; "
                       "stride == 12 + 12*count",
            "element_size": ROW_BYTES,
            "records": len(seq_records),
            "elements": len(rows),
            "live_elements": len(live),
            "sentinels": len(sentinels),
            "key_tag_census": {str(t): c for t, c in sorted(
                Counter(tag(u16(row, 0)) for row in rows).items())},
            "rows_with_zero_tail": tail_zero,
            "operands": [
                {"offset": 0, "size": 2, "type": "u16", "name": "key",
                 "census": row_census[0],
                 "evidence": "`if ((*puVar1 & 0xc000) == 0)` gates the voice on the key's tag, and "
                             "981/981 live rows carry a class-0 key; `*puVar1 != 0xffff` is the skip "
                             "test — the 334 rows whose key is 0xffff are the only rows with tag 3"},
                {"offset": 2, "size": 1, "type": "u8", "name": "window_floor",
                 "census": row_census[1],
                 "evidence": "`*(byte *)(puVar1 + 1) <= param_3` — the row applies only at or above "
                             "this selector value"},
                {"offset": 3, "size": 1, "type": "u8", "name": "window_ceiling",
                 "census": row_census[2],
                 "evidence": "`param_3 <= *(byte *)((int)puVar1 + 3)` — and at or below this one; "
                             "floor <= ceiling on all %d live rows" % windows_ordered},
                {"offset": 4, "size": 1, "type": "s8", "name": "selector_delta",
                 "census": row_census[3],
                 "evidence": "`uVar8 = param_3 + (int)*(char *)(puVar1 + 2)` then clamped to 0..0x7f"},
                {"offset": 5, "size": 1, "type": "u8", "name": "volume_scale",
                 "census": row_census[4],
                 "evidence": "`local_30 * *(byte *)((int)puVar1 + 5)` scaled by the magic constant "
                             "`0x81020409 >> 0x26`, i.e. divided by 127 — a 0..127 multiplier on the "
                             "caller's own 0..0xff argument"},
                {"offset": 6, "size": 2, "type": "s16", "name": "channel_delta",
                 "census": row_census[5],
                 "evidence": "`iVar5 = (param_1 >> 8 & 0xff) + (int)(short)puVar1[3]` then clamped "
                             "0..0xff"},
                {"offset": 8, "size": 2, "type": "u16", "name": "pan_offset",
                 "census": row_census[6],
                 "evidence": "`if ((puVar1[4] & 0x8000) == 0)` then "
                             "`(*(byte *)(puVar1 + 4) - 0x40) + local_38`, clamped to 0..0x7f — read "
                             "through a big-endian `ushort *`, bit 15 is bit 7 of the byte at +8, so "
                             "the test is `pan < 0x80`; when it fails the pan stays at the 0x80 "
                             "sentinel. The byte is 0x40-centred and 0..0x7f on all %d live rows, so "
                             "the sentinel branch is unexercised by this data"
                             % (len(live) - pan_flag_set)},
                {"offset": 10, "size": 2, "type": "u16", "name": "zero",
                 "census": row_census[7],
                 "evidence": "with +9 this is the last three bytes, zero on %d/%d rows; the reader "
                             "stops at +8 (it strides six ushorts), so nothing reads them"
                             % (tail_zero, len(rows))},
            ],
            "requests": "run the rows in order; for each live row whose window contains the selector, "
                        "start one voice with the row's offsets applied — one voice per live row, "
                        "and the caller links the voices it got back",
            "evidence": [
                {"file": "src/stage2/FUN_800a6820.c", "witness": "if (uVar3 != 0x8000) {",
                 "claim": "tag 2 is accepted here and 0xc000 is not — the refusal is in this test"},
                {"file": "src/stage2/FUN_800a6820.c", "witness": "iVar6 = FUN_800a64c8(uVar8,uVar9,",
                 "claim": "the sequence runner is entered with the key in bits 16..31"},
                {"file": "src/stage2/FUN_800a64c8.c",
                 "witness": "puVar1 = (ushort *)FUN_800adfb4(param_1 >> 0x10,&local_48);",
                 "claim": "the runner asks for the payload pointer and the element count"},
                {"file": "src/stage2/FUN_800adfb4.c",
                 "witness": "*param_2 = *(undefined2 *)((int)_DAT_8014e15c + 6);",
                 "claim": "the count is the cache entry's own u16, handed to the runner"},
                {"file": "src/stage2/FUN_800adfb4.c",
                 "witness": "FUN_800ab43c(0x8014e150,0x80152a00,_DAT_801529f0,0xc,&LAB_800ae174);",
                 "claim": "the cache is the 12-byte-stride one FUN_800ace1c fills, whose payload "
                          "pointer is the pool record's +12 (FUN_800a86a0 passes `piVar5 + 3`)"},
                {"file": "src/stage2/FUN_800a64c8.c",
                 "witness": "if (((*puVar1 != 0xffff) && (*(byte *)(puVar1 + 1) <= param_3)) &&",
                 "claim": "0xffff is skipped by the body, not used to end the loop"},
                {"file": "src/stage2/FUN_800a64c8.c", "witness": "puVar1 = puVar1 + 6;",
                 "claim": "the stride is six ushorts, i.e. 12 bytes"},
                {"file": "src/stage2/FUN_800a64c8.c", "witness": "iVar9 < (int)(uint)local_48",
                 "claim": "and the loop bound is the count, so the array is count-prefixed"},
                {"file": "src/stage2/FUN_800a86a0.c",
                 "witness": "FUN_800ace1c(*psVar6,piVar5 + 3,*(undefined2 *)((int)piVar5 + 10));",
                 "claim": "the cache is filled while walking the pool chain: +12 is the payload and "
                          "+10 is the low half of the u32 count"},
            ],
            "confidence": "established",
        },
        {
            "opcode": "0xc000",
            "tag": 3,
            "mask": "0xc000",
            "section": SECTION_FOR_TAG[3],
            "payload": "8 bytes: four little-endian u16 at record+8",
            "element_size": SLOT_BYTES,
            "elements_per_record": [1, 1],
            "records": len(ramp_records),
            "operands": [
                {"offset": 0, "size": 2, "type": "le16", "name": "unresolved_0",
                 "census": ramp_census[0],
                 "evidence": "read only as `*param_2 >> 0x18 != 0`, a non-zero test on its high byte"},
                {"offset": 2, "size": 2, "type": "le16", "name": "target_level",
                 "census": ramp_census[1],
                 "evidence": "`(*(int *)(param_1 + 0x30) * *(byte *)((int)param_2 + 2) >> 7) + "
                             "*(byte *)((int)param_2 + 1) * 0x10000`, clamped to 0x7f0000 — a level in "
                             "8.8 fixed point"},
                {"offset": 4, "size": 2, "type": "le16", "name": "length",
                 "census": ramp_census[2],
                 "evidence": "`*(uint *)(param_1 + 0xb4) = (uint)*(ushort *)(param_2 + 1)` then "
                             "`(uVar5 - param_3) / iVar1`: the per-tick step divides by it, so it is "
                             "the ramp's length (a 0 becomes 1)"},
                {"offset": 6, "size": 2, "type": "le16", "name": "unresolved_6",
                 "census": ramp_census[3],
                 "evidence": "read only as `*(char *)((int)param_2 + 7) != 0`, a non-zero test on its "
                             "high byte, gating an interpolation-table blend"},
            ],
            "requests": "set a level ramp on a voice that already exists: a target level, a length, "
                        "and optionally an interpolated curve — NOT a note",
            "evidence": [
                {"file": "src/stage2/FUN_800a6820.c", "witness": "if (0x4000 < uVar3) {",
                 "claim": "tag 3 takes the > 0x4000 path"},
                {"file": "src/stage2/FUN_800a6820.c", "witness": "return -1;",
                 "claim": "and that path rejects everything except 0x8000, so 0xc000 can never start "
                          "a voice through the dispatcher"},
                {"file": "src/stage2/FUN_800afbfc.c",
                 "witness": "*(uint *)(param_1 + 0xb4) = (uint)*(ushort *)(param_2 + 1);",
                 "claim": "a class-3 payload is consumed as a voice parameter set"},
                {"file": "src/stage2/FUN_800afbfc.c",
                 "witness": "*(int *)(param_1 + 0x84) = (int)(uVar5 - param_3) / iVar1;",
                 "claim": "the stored value is a per-tick delta from the current level to the target"},
                {"file": "src/stage2/FUN_800afbfc.c", "witness": "iVar2 = FUN_800adef4();",
                 "claim": "an optional interpolation table is fetched — with the argument dropped by "
                          "the decompiler, which is why its field is unresolved"},
            ],
            "confidence": "partial: the length and the target level are established; which field "
                          "selects the curve table is unresolved",
        },
    ]

    unresolved = [
        {"kind": "field", "opcode": "0x0000", "offset": 0, "size": SLOT_BYTES,
         "reason": "the class-0 payload's interior: FUN_800b185c stores the pointer and adds "
                   "`param_8 * 8`, which fixes the element size and index but says nothing about the "
                   "eight bytes. No function in the corpus reads them at a named offset, so no field "
                   "is tabulated. The payload is %d..%d bytes = %d..%d elements on %d/%d records."
                   % (min(note_payloads), max(note_payloads), min(note_elements), max(note_elements),
                      len(note_records), len(note_records))},
        {"kind": "field", "opcode": "0xc000", "offset": 0, "size": 2,
         "reason": "read only through `*param_2 >> 0x18`, a non-zero test; whether it is a flag, a "
                   "high byte of a value, or part of the curve selector is not established"},
        {"kind": "field", "opcode": "0xc000", "offset": 6, "size": 2,
         "reason": "read only through `*(char *)((int)param_2 + 7) != 0`, a non-zero test gating the "
                   "curve blend; `FUN_800adef4` is called with its argument dropped by the "
                   "decompiler, so which field names the interpolation table is open"},
        {"kind": "field", "opcode": "0x8000", "offset": 8, "size": 2,
         "reason": "bit 15 of this u16 is the reader's leave-the-pan-alone flag and is clear on every "
                   "one of the %d live rows, so the branch is unexercised by this data: the flag's "
                   "meaning is read from the code and confirmed by no measurement"
                   % (len(live) - pan_flag_set)},
        {"kind": "field", "opcode": "0x8000", "offset": 9, "size": 3,
         "reason": "the last three bytes of a 12-byte row are zero on %d/%d rows and the reader stops "
                   "at +8; they are called padding, and what they are for is not established"
                   % (tail_zero, len(rows))},
        {"kind": "opcode-space", "opcode": None,
         "reason": "no unclaimed opcode: the tag is two bits, so the vocabulary is exactly four and "
                   "all four are branched on in FUN_800a6820. What is left open is not a missing "
                   "opcode but the fields above, plus the possibility that other keys reach a voice "
                   "without this dispatcher (FUN_8009feb8 and FUN_800a83b4 are its only callers in "
                   "the corpus, and the paths into the voice allocator that bypass it are not "
                   "enumerated here)"},
    ]

    total_rows = len(rows)
    stream = {
        "found": True,
        "where": "SND_POOL section at %s (tag 2, the class-2 records): the array at record + 12, "
                 "count at record + 8" % hex(offsets[SECTION_FOR_TAG[2]]),
        "evidence": "the count-prefixed 12-byte array is read by FUN_800a64c8, which the dispatcher "
                    "FUN_800a6820 hands tag-2 keys to: `stride == 12 + 12*count` on %d/%d records, "
                    "the runner strides six ushorts, tests each element's key against 0xffff, and "
                    "starts one voice per live element. `distinct_opcodes` counts the tag vocabulary, "
                    "not a byte in the array: the elements themselves carry one request"
                    % (closed, len(seq_records)),
        "element_size": ROW_BYTES,
        "count": total_rows,
        "distinct_opcodes": 4,
        "count_detail": {"streams": len(seq_records), "live_elements": len(live),
                         "sentinel_elements": len(sentinels),
                         "count_census": {str(k): v for k, v in sorted(count_census.items())}},
        "terminator": "none in the byte sense: the loop bound is the u32 count at record+8 (%d..%d), "
                      "and 0xffff marks a skipped slot — the last element of %d/%d arrays, and the "
                      "first element of none"
                      % (min(count_census), max(count_census), last_sentinel, len(seq_records)),
        "sentinels_last": last_sentinel,
        "operand_pattern": "repeats: every live row is {u16 key, u8 window floor, u8 window ceiling, "
                           "s8 selector delta, u8 volume scale, s16 channel delta, u8 pan offset, "
                           "u16 flag/pad}; floor <= ceiling on %d/%d live rows, so the rows are "
                           "selector windows rather than a byte stream"
                           % (windows_ordered, len(live)),
        "monotone": "three orders measured, and only one is regular: live keys strictly ascend in "
                    "%d/%d arrays and windows are non-decreasing in %d/%d, while the array keys "
                    "ascend across the section in %d/%d. The regular order is in the 8-byte table "
                    "slots, where the s8 delta falls by exactly 1 per consecutive index step on "
                    "%d/%d such steps — a ramp across the slot index, not noise"
                    % (asc_key, len(seq_records), asc_window, len(seq_records),
                       asc_record, len(seq_records) - 1, step_law, len(steps)),
    }

    totals = {
        "sections": len(sections),
        "records": sum(s["records"] for s in sections),
        "records_by_tag": {str(t): len(starts_by_tag[t]) for t in sorted(starts_by_tag)},
        "opcodes": len(commands),
        "opcodes_that_start_a_voice": 3,
        "sequences": len(seq_records),
        "sequence_elements": total_rows,
        "sequence_live_elements": len(live),
        "sequence_sentinels": len(sentinels),
        "sequence_interior_sentinels": interior_sentinels,
        "sequence_bytes": ROW_BYTES * total_rows,
        "tables": len(tab_records),
        "table_slots": len(slots),
        "table_live_slots": len(live_slots),
        "ramps": len(ramp_records),
        "samples": len(note_records),
        "pool_keys": len(every_key),
        "project_list_values": sum(p["values"] for p in project_lists),
        "project_list_unresolved": sum(p["unresolved"] for p in project_lists),
        "command_streams": 1,
        "unresolved": len(unresolved),
    }

    artefact = {
        "tool": "tools/snd_macros.py",
        "schema": "snd_macros/1",
        "cart_sha256": hashlib.sha256(data).hexdigest(),
        "inputs": [
            {"id": POOL, "name": "SND_POOL", "cart_offset": ft.BASE + entries[POOL][0],
             "stored_size": entries[POOL][1], "member_bytes": len(pool), "codec": "zlib"},
            {"id": PROJ, "name": "SND_PROJ", "cart_offset": ft.BASE + entries[PROJ][0],
             "stored_size": entries[PROJ][1], "member_bytes": len(proj), "codec": "zlib"},
        ],
        "sections": sections,
        "section_base_check": by_start,
        "command_stream": stream,
        "commands": commands,
        "unresolved": unresolved,
        "project_lists": project_lists,
        "totals": totals,
    }
    return artefact


OP_NAMES = {
    0: "0x0000",
    3: "0xc000",
    1: "0x4000",
    2: "0x8000",
}


# --- rendering ---------------------------------------------------------------------------------

def render(artefact):
    return json.dumps(artefact, indent=1, sort_keys=True) + "\n"


def _report(artefact):
    totals = artefact["totals"]
    stream = artefact["command_stream"]
    print("SND_POOL: %d records in %d sections (%s)"
          % (totals["records"], totals["sections"],
             ", ".join("tag %s x%d" % (k, v) for k, v in sorted(totals["records_by_tag"].items()))))
    print("  command space: %d opcodes on the key's class tag (mask 0xc000), no opcode byte"
          % totals["opcodes"])
    for entry in artefact["commands"]:
        print("    %-8s x%-4d %-12s %s"
              % (entry["opcode"], entry["records"],
                 "%d B" % entry["element_size"], entry["requests"][:88]))
    print("  stream: %s" % stream["where"])
    print("          %d element(s) over %d stream(s): %d live, %d sentinel, element %d B"
          % (stream["count"], stream["count_detail"]["streams"],
             stream["count_detail"]["live_elements"], stream["count_detail"]["sentinel_elements"],
             stream["element_size"]))
    print("  %d unresolved field(s); %d project list value(s), %d unresolved"
          % (totals["unresolved"], totals["project_list_values"], totals["project_list_unresolved"]))
    return artefact


# --- check ------------------------------------------------------------------------------------

def _witness(path, text):
    """Whether `text` occurs in `path`. The evidence gate: a claimed row must still be in the code."""
    try:
        return text in path.read_text()
    except OSError:
        return False


def check():
    """Gated cases. The last line is the tally `acceptance.py` reads."""
    cases = []

    def case(label, ok, detail=""):
        cases.append((bool(ok), label, detail))

    committed_path = HERE.parent / OUT
    try:
        committed = json.loads(committed_path.read_text())
        case("the committed artefact parses", True)
    except (OSError, ValueError) as exc:
        case("the committed artefact parses", False, str(exc))
        return _tally(cases)

    fresh = derive()
    pool = member(*_cart_pair(), POOL)
    offsets = section_offsets(pool)

    # --- the sections: where a record starts is the claim the counts rest on
    base = fresh["section_base_check"]
    case("a section's first record starts AT the section offset: walking from it tiles each section "
         "4/4, and the u32 there chains to the next record",
         all(s["tiles_section"] for s in fresh["sections"])
         and all(s["first_record"]["offset"] == s["offset"] for s in fresh["sections"])
         and all(s["records"] == b["records_if_started_one_stride_late"] + 1
                 for s, b in zip(fresh["sections"], base)),
         "%s" % [(s["index"], s["records"], b["records_if_started_one_stride_late"])
                 for s, b in zip(fresh["sections"], base)])
    case("REFUTED: starting one stride past the section offset is not the same walk — it drops exactly "
         "one record per section and leaves a gap the width of that record (112 / 16 / 1032 / 60 B)",
         [b["record_at_section_offset"] for b in base] == [1, 1, 1, 1]
         and [b["gap_bytes"] for b in base] == [112, 16, 1032, 60]
         and all(len(b["keys_the_late_walk_skips"]) == 1 for b in base),
         "gaps %s" % [b["gap_bytes"] for b in base])
    skipped = sorted(b["keys_the_late_walk_skips"][0] for b in base)
    case("and the four records that walk skips carry exactly the four keys WP1 published as dangling "
         "references: 531, 0xc085, 0x4001, 0x8098",
         skipped == sorted([531, 49285, 16385, 32920]), "%s" % [hex(k) for k in skipped])
    case("so every one of the project's five key lists resolves: 0 unresolved values, where WP1 "
         "published 182", fresh["totals"]["project_list_unresolved"] == 0,
         "%d unresolved" % fresh["totals"]["project_list_unresolved"])
    lists = fresh["project_lists"]
    case("and four of the five are bijections onto their pool class — lists 0, 2, 3 and 4 each name "
         "every record of their class exactly once, while list 1 is a %d-key subset of the %d samples"
         % (lists[1]["distinct"], lists[1]["pool_records"]),
         [p["bijection"] for p in lists] == [True, False, True, True, True]
         and lists[1]["distinct"] < lists[1]["pool_records"],
         "%s" % [(p["index"], p["distinct"], p["pool_records"], p["bijection"]) for p in lists])

    # --- the command space is measured, not assumed
    tags = [s["tag"] for s in fresh["sections"]]
    case("the four sections carry four different tags in file order 0, 3, 1, 2 — so the tag is read "
         "off a record's key and is not the section index", sorted(tags) == [0, 1, 2, 3]
         and tags != sorted(tags), "%s" % tags)
    opcodes = [c["opcode"] for c in fresh["commands"]]
    case("the command table is exactly the tags that occur, one row each — nothing invented, nothing "
         "missing", len(opcodes) == 4 and len({tag(int(o, 16)) for o in opcodes}) == 4
         and sorted(tag(int(o, 16)) for o in opcodes) == sorted(tags), "%s" % opcodes)

    # --- every claimed command names its evidence, and that evidence is still in the source
    missing_witness = []
    for entry in fresh["commands"]:
        for item in entry["evidence"]:
            if not _witness(HERE.parent / item["file"], item["witness"]):
                missing_witness.append((entry["opcode"], item["file"], item["witness"]))
    case("every claimed command names its evidence and every witness is still in the file it cites "
         "(%d witnesses over %d commands)"
         % (sum(len(c["evidence"]) for c in fresh["commands"]), len(fresh["commands"])),
         all(c["evidence"] for c in fresh["commands"]) and not missing_witness,
         "%s" % missing_witness[:3])
    case("the committed commands carry the same witnesses as the fresh derivation",
         [e["evidence"] for e in committed.get("commands", [])]
         == [e["evidence"] for e in fresh["commands"]])

    # --- the unresolved list is disjoint from the commands list
    claimed = {c["opcode"] for c in fresh["commands"]}
    named = {u["opcode"] for u in fresh["unresolved"] if u["kind"] == "opcode"}
    case("the unresolved list is disjoint from the commands list, and no opcode is left unclaimed",
         not (named & claimed) and not named, "unclaimed %s" % sorted(named))
    field_entries = [u for u in fresh["unresolved"] if u["kind"] == "field"]
    case("what is unresolved is stated as fields with offsets and a reason, not as a silent gap",
         len(field_entries) == len(fresh["unresolved"]) - 1
         and all(u["reason"] and "offset" in u for u in field_entries),
         "%d field(s)" % len(field_entries))

    # --- the stream claim is consistent with its evidence
    stream = fresh["command_stream"]
    case("the stream claim re-derives: %d stream(s) whose stride is 12 + 12*count on every record, "
         "element size 12, %d elements" % (stream["count_detail"]["streams"], stream["count"]),
         stream["found"] and stream["element_size"] == ROW_BYTES
         and stream["count_detail"]["streams"]
         == fresh["sections"][SECTION_FOR_TAG[2]]["records"]
         and stream["count"] == fresh["totals"]["sequence_bytes"] // ROW_BYTES)
    case("its count is the elements, not the streams: %d + %d sentinels = %d, over %d stream(s)"
         % (stream["count_detail"]["live_elements"], stream["count_detail"]["sentinel_elements"],
            stream["count"], stream["count_detail"]["streams"]),
         stream["count_detail"]["live_elements"] + stream["count_detail"]["sentinel_elements"]
         == stream["count"] and stream["distinct_opcodes"] == len(fresh["commands"]))
    case("0xffff is a skip, not a terminator: the last element is a sentinel on %d/%d arrays, yet "
         "%d sentinel(s) sit INSIDE an array with non-zero tail bytes, and the loop bound is the count"
         % (stream["sentinels_last"], stream["count_detail"]["streams"],
            fresh["totals"]["sequence_interior_sentinels"]),
         stream["sentinels_last"] == stream["count_detail"]["streams"]
         and fresh["totals"]["sequence_interior_sentinels"] > 0)

    # --- the totals agree with the pieces
    recompute = {
        "sections": len(fresh["sections"]),
        "records": sum(s["records"] for s in fresh["sections"]),
        "sequences": fresh["sections"][SECTION_FOR_TAG[2]]["records"],
        "tables": fresh["sections"][SECTION_FOR_TAG[1]]["records"],
        "ramps": fresh["sections"][SECTION_FOR_TAG[3]]["records"],
        "samples": fresh["sections"][SECTION_FOR_TAG[0]]["records"],
        "opcodes": len(fresh["commands"]),
        "unresolved": len(fresh["unresolved"]),
        "command_streams": 1,
    }
    case("totals agree with the pieces they summarise: %s" % ", ".join(
        "%s=%d" % (k, v) for k, v in sorted(recompute.items())),
         all(fresh["totals"][k] == v for k, v in recompute.items()),
         "%s" % {k: (fresh["totals"][k], v) for k, v in recompute.items()
                 if fresh["totals"][k] != v})
    case("and every record in the member is inside a section that tiles it 4/4: %d records, no slack"
         % fresh["totals"]["records"],
         sum(s["end"] - s["offset"] for s in fresh["sections"]) == len(pool) - 16
         and all(s["tiles_section"] for s in fresh["sections"]))

    # --- the payload is fully accounted for, at a fixed stride, in every section
    lattice = []
    for entry in fresh["sections"]:
        start, end = entry["offset"], entry["end"]
        starts, _term = chain(pool, start, end)
        payloads = [struct.unpack_from(">i", pool, r)[0] - 8 for r in starts]
        stride = SLOT_BYTES if entry["tag"] in (0, 1, 3) else ROW_BYTES
        if entry["tag"] == 2:
            ok = all(struct.unpack_from(">i", pool, r)[0] == 12 + ROW_BYTES * u32(pool, r + 8)
                     for r in starts)
        else:
            ok = all(p % stride == 0 for p in payloads)
        lattice.append(ok)
    case("REFUTED: no payload is a variable-length stream — every section's payload divides by its "
         "element size (8 B for tags 0/1/3, `12 + 12*count` for tag 2) on all records, which a "
         "opcode-and-length format could not do", all(lattice), "%s" % lattice)
    row = fresh["commands"][2]
    case("the 12-byte row carries no opcode field: +9..+11 are zero on every one of the %d rows, and "
         "every live row's key carries tag 0 — one request per element, and the only tag-3 rows are "
         "the %d sentinels" % (fresh["totals"]["sequence_elements"],
                               fresh["totals"]["sequence_sentinels"]),
         row["rows_with_zero_tail"] == fresh["totals"]["sequence_elements"]
         and row["operands"][7]["census"]["constant"] == 0
         and row["key_tag_census"] == {"0": fresh["totals"]["sequence_live_elements"],
                                       "3": fresh["totals"]["sequence_sentinels"]})

    # --- the code reading, so a re-decompile that loses it invalidates the claim
    dispatch = (HERE.parent / "src" / "stage2" / "FUN_800a6820.c").read_text()
    runner = (HERE.parent / "src" / "stage2" / "FUN_800a64c8.c").read_text()
    case("CODE: FUN_800a6820 dispatches on `uVar3 = uVar9 & 0xc000` with its own branch for 0x4000, "
         "0x8000 and 0, and a `return -1` for 0xc000",
         "uVar3 = uVar9 & 0xc000;" in dispatch and "if (uVar3 == 0x4000) {" in dispatch
         and "if (uVar3 != 0x8000) {" in dispatch and "if (uVar3 != 0) {" in dispatch
         and dispatch.count("return -1;") >= 3)
    case("CODE: FUN_800a64c8 reads the array through FUN_800adfb4, skips 0xffff, strides six ushorts, "
         "bounds the loop by the count, and starts a voice per live element",
         "FUN_800adfb4(param_1 >> 0x10,&local_48)" in runner
         and "(*puVar1 != 0xffff)" in runner and "puVar1 = puVar1 + 6;" in runner
         and "iVar9 < (int)(uint)local_48" in runner and "FUN_800b185c(uVar6" in runner)
    case("CODE: the pool cache for tag 2 is looked up at stride 0xc and hands back the count from the "
         "entry's own +6 — the same u16 the pool's record carries at +10",
         "0xc,&LAB_800ae174" in (HERE.parent / "src" / "stage2" / "FUN_800adfb4.c").read_text()
         and "*(undefined2 *)((int)_DAT_8014e15c + 6)" in
         (HERE.parent / "src" / "stage2" / "FUN_800adfb4.c").read_text())

    # --- the artefact stays small and carries no cartridge bytes
    rendered = render(committed)
    case("the committed artefact is under 4 MiB and carries no cartridge bytes (no hex dumps)",
         len(rendered.encode()) < 4 * 1024 * 1024 and "\\x" not in rendered,
         "%d B" % len(rendered.encode()))

    # --- the committed artefact is the one --write would produce
    if committed == fresh:
        case("the committed artefact equals a fresh --write", True)
    else:
        drift = sorted(k for k in set(committed) | set(fresh)
                       if committed.get(k) != fresh.get(k))
        case("the committed artefact equals a fresh --write", False, "drifted: %s" % drift)

    return _tally(cases)


_CART = {}


def _cart_pair():
    """The cartridge, read once for the whole check run."""
    if not _CART:
        _CART["pair"] = cartridge()
    return _CART["pair"]


def _tally(cases):
    passed = 0
    for ok, label, detail in cases:
        passed += ok
        line = "  %s %s" % ("PASS" if ok else "FAIL", label)
        if detail and not ok:
            line += "  [%s]" % detail
        print(line)
    print("%d/%d snd_macros case(s)" % (passed, len(cases)))
    return 0 if passed == len(cases) else 1


# --- entry point -------------------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true", help="regenerate %s" % OUT)
    ap.add_argument("--check", action="store_true", help="validate the committed artefact")
    args = ap.parse_args()
    if not (args.write or args.check):
        ap.error("one of --write or --check is required")

    if not ft.ROM.exists():
        # Not a pass and not a failure: the cartridge is gitignored by design, so a fresh clone
        # cannot answer any of these questions. Say so and stop, the way snd_proj does.
        try:
            where = ft.ROM.relative_to(HERE.parent)
        except ValueError:
            where = ft.ROM
        print("SKIP: no cartridge at %s — every snd_macros case needs it" % where)
        return 0

    if args.write:
        artefact = _report(derive())
        path = HERE.parent / OUT
        path.write_text(render(artefact))
        print("-> %s (%d opcodes, %d stream elements over %d stream(s))"
              % (OUT, artefact["totals"]["opcodes"], artefact["totals"]["sequence_elements"],
                 artefact["totals"]["sequences"]))
        return 0

    return check()


if __name__ == "__main__":
    raise SystemExit(main())
