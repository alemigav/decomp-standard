#!/usr/bin/env python3
"""SND_PROJ's group headers and its six lists — and why not one of them is a macro.

`SND_PROJ` (file id 1980, reached through `tools/file_table.py`) is a chain of 417 records: each
record's first u32 is the stride to the next, `-1` closes the chain, and the strides plus that
terminator tile the 102 148-byte member exactly (102 144 + 4).

A record is a 0x28-byte header of list offsets:

    +0     u32  stride to the next record
    +4     u16  key — the 417 keys are a bijection onto 0..417 less the hole 11
    +6     u16  **0 or 1, not a constant** (130 records carry 0, 287 carry 1)
    +8     six u32 list offsets = the player's param_1[2..7], **relative to record + 8**
    +0x20  two more u32 offsets, in the 8 bytes between the offset table and the first list —
           i.e. exactly in the records where the flag at +6 is 0 — addressing the record's two
           further 8-byte row tables (the chain closes on 130/130 flag-0 records)

The +8 base is not a style choice; it is measured twice. `FUN_800a86a0` reads every list as
`(short *)((int)param_1 + param_1[k] + 8)` and steps it by one short, and of the two candidate
bases only `record + 8` yields disjoint spans: based at `record + 0` the six spans overlap in
417/417 records, based at `record + 8` they overlap in 0/417 and tile the record with at most two
bytes of alignment padding after each terminator in 417/417. Consequence, published here rather than
acted on elsewhere: the "two-parameter prologue `[0, a, 0, b]`" that earlier milestones read at the
head of every list is header bytes misread — in the 130 records that have the +0x20 extension it is
those two u32, and in the other 287 it is the last two offset fields, whose `a` and `b` are the
offsets themselves and whose high halves are zero because no record is longer than 65 535 bytes.

With the base settled, the widths are not a guess either:

  * lists 0-4 are u16 runs closed by `0xffff`. Each one draws on exactly ONE pool class and every
    value in it has that class: list 0 and 1 class 0 (sample keys), list 2 class 3 (the 16-byte
    parameter records), list 3 class 1, list 4 class 2. Read as u32 the same bytes decode as no key
    at all, which is what refutes the alternative width.
  * list 5 is not a key list. When the flag at +6 is 1 it is `{u16 count, u16 0}` followed by
    `count` 12-byte rows, and `4 + 12 * count` closes the record exactly on 287/287 records. When
    the flag is 0 it is 8-byte rows closed by `0xffffffff`, followed by two more tables of the
    same shape whose offsets are the two extra u32 at +0x20.

What this artefact refuses:

  * **no list is called a "program" or a "macro" until its elements decode as commands, and none of
    them does.** A command stream needs an opcode — a byte whose value selects the meaning of the
    rest — and a length that varies with it. List 5's rows have neither: three columns are constant
    on all 3 068 rows (0xff, 0x0a, 0x40), the last three bytes are zero, and the only mutable fields
    are an ascending index, a class-0 sample key and two small parameter bytes. The row size is also
    fixed by the reader: `FUN_800ae034` hands the array to `FUN_800ab43c`, a **binary search** at
    stride 0xc through a comparison callback, and a variable-length command stream cannot be
    binary-searched. Lists 0-4 hold keys and nothing else; a key is not an opcode.
  * no meaning for the flag bits beyond what is measured: the flag is named `flag`, not "kind" or
    "mode", because all that is known is that `FUN_800adb48` is reached only when it is 1 and that
    its value coincides with the header extension in 417/417 records.
  * no reading of the 8-byte rows' `0xff00 | index` and `0x40XX` fields, no loop points, volumes or
    durations, and no name for any list: `class 0` .. `class 3` is the pool tag `(key >> 14) & 3`,
    which is a storage class, not a role the cartridge states.

Where the macro opcodes are **not**: nothing in `SND_PROJ` is a candidate, and the pointer to where
they would have to live is `SND_POOL`'s class-2 section — 326 records of
`{u32 size, u16 key, u16 0, u32 count, count x 12-byte rows}` with `size == 12 + 12 * count` on
326/326. That is the only container in the family outside `SND_PROJ` that declares an element count
separately from its bytes; but its rows are key pairs (a class-0 sample key with a class-3 parameter key) with
six constant columns, so they are a pairing table, not commands, and this tool does not call them a
macro either.

Usage:
  ./snd_proj.py --write    # regenerate manifests/snd_proj.json from the cartridge
  ./snd_proj.py --check    # validate the committed artefact against a fresh derivation
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

# The cartridge accessor is `tools/file_table.py`'s, not a second copy of it: the file table's base,
# header size and entry layout live there, and re-deriving them here is how two tools begin to
# disagree about the same member.
import file_table as ft

OUT = "manifests/snd_proj.json"

PROJ, POOL, SMPDIR = 1980, 1981, 1982

LIST_BASE = 8                 # list offsets are relative to record + 8 (FUN_800a86a0)
LIST_OFFSETS = (8, 12, 16, 20, 24, 28)   # = param_1[2..7]
EXT_OFFSET = 0x20             # two more u32, in the gap only flag-0 records have
FLAG = 6                      # u16 at +6: 0 or 1, gated by FUN_800a86a0

TERM16 = 0xFFFF
TERM32 = 0xFFFFFFFF
KEY_LISTS = 5                 # lists 0-4 are u16 key runs; list 5 is a row array

CLASSES = {0: "0", 1: "1", 2: "2", 3: "3"}


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


# --- structure ---------------------------------------------------------------------------------

def chain(b, start=0, end=None):
    """`(record starts, terminator offset)`. A u32 stride chain, `-1` closing it.

    `tools/file_table.py` walks the same shape inside its `check()`; this one takes an end bound so
    SND_POOL's four sections can be walked without the recursion into the next section.
    """
    end = len(b) if end is None else end
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


def pool_classes(pool):
    """`{tag: set(keys)}` — SND_POOL's four sections, classified by `(key >> 14) & 3`."""
    sections = list(struct.unpack_from(">4I", pool, 0))
    out = {}
    for i, start in enumerate(sections):
        end = sections[i + 1] if i + 1 < len(sections) else len(pool)
        starts, _term = chain(pool, start + struct.unpack_from(">I", pool, start)[0], end)
        for rec in starts:
            key = struct.unpack_from(">H", pool, rec + 4)[0]
            out.setdefault((key >> 14) & 3, set()).add(key)
    return out


def key_list(b, rec, off):
    """A `0xffff`-terminated u16 run at `record + 8 + off`. -> (values, terminator offset)."""
    pos = rec + LIST_BASE + off
    vals = []
    while True:
        value = struct.unpack_from(">H", b, pos)[0]
        if value == TERM16:
            return vals, pos
        vals.append(value)
        pos += 2


def tail_rows(b, rec, stride, off, flag):
    """List 5's elements. Two shapes, gated by the flag, and neither is a u16 key run."""
    pos = rec + LIST_BASE + off
    end = rec + stride
    if flag == 1:
        count = struct.unpack_from(">H", b, pos)[0]
        pad = struct.unpack_from(">H", b, pos + 2)[0]
        rows = [b[pos + 4 + 12 * k:pos + 16 + 12 * k] for k in range(count)]
        return {"width": 12, "count": count, "pad": pad, "closed": pos + 4 + 12 * count == end,
                "rows": rows, "end": pos + 4 + 12 * count}
    rows, at = [], pos
    while at + 8 <= end and b[at:at + 4] != b"\xff\xff\xff\xff":
        rows.append(b[at:at + 8])
        at += 8
    return {"width": 8, "count": len(rows), "pad": None, "closed": b[at:at + 4] == b"\xff\xff\xff\xff",
            "rows": rows, "end": at + 4}


def row_key(row, width):
    """The pool key a row names: `+2` when the rows are 12 bytes, `+0` when they are 8."""
    return struct.unpack_from(">H", row, 2 if width == 12 else 0)[0]


# --- derivation --------------------------------------------------------------------------------

def derive():
    """The whole artefact, measured. Nothing here is a constant copied from a note."""
    data, entries = cartridge()
    pro = member(data, entries, PROJ)
    pool = member(data, entries, POOL)

    starts, term = chain(pro)
    classes = pool_classes(pool)
    every_key = set().union(*classes.values())

    records, min_offsets, flags = [], Counter(), Counter()
    for rec in starts:
        stride = struct.unpack_from(">i", pro, rec)[0]
        key = struct.unpack_from(">H", pro, rec + 4)[0]
        flag = struct.unpack_from(">H", pro, rec + FLAG)[0]
        offsets = list(struct.unpack_from(">6I", pro, rec + LIST_OFFSETS[0]))
        records.append({"key": key, "stride": stride, "offsets": offsets, "flag": flag})
        min_offsets[min(offsets)] += 1
        flags[flag] += 1

    # --- the base, measured both ways, and recorded because the rest depends on it
    spans_overlap = {}
    for base in (0, LIST_BASE):
        overlapping = 0
        for rec, row in zip(starts, records):
            spans = []
            for off in row["offsets"]:
                pos = rec + base + off
                while struct.unpack_from(">H", pro, pos)[0] != TERM16:
                    pos += 2
                spans.append((base + off, pos - rec + 2))
            spans.sort()
            if any(spans[i][1] > spans[i + 1][0] for i in range(len(spans) - 1)):
                overlapping += 1
        spans_overlap[base] = overlapping

    tiled = 0
    for rec, row in zip(starts, records):
        spans = []
        for off in row["offsets"]:
            vals, at = key_list(pro, rec, off)
            spans.append((LIST_BASE + off, at - rec + 2))
        spans.sort()
        if all((spans[i][1] + 3) // 4 * 4 == spans[i + 1][0] for i in range(len(spans) - 1)):
            tiled += 1

    # --- lists 0-4: u16 key runs
    lists = []
    for index in range(KEY_LISTS):
        values, past_record, ends = [], 0, 0
        for rec, row in zip(starts, records):
            vals, at = key_list(pro, rec, row["offsets"][index])
            values += vals
            past_record += (at - rec + 2) > row["stride"]
            ends += (at - rec + 2) <= row["stride"]
        dist = Counter((v >> 14) & 3 for v in values)
        missing = Counter(v for v in values if v not in every_key)

        # the refuted alternative: the same bytes read as u32
        wide, wide_resolved = 0, 0
        for rec, row in zip(starts, records):
            pos = rec + LIST_BASE + row["offsets"][index]
            while struct.unpack_from(">H", pro, pos)[0] != TERM16 and pos + 4 <= rec + row["stride"]:
                wide += 1
                wide_resolved += struct.unpack_from(">I", pro, pos)[0] in every_key
                pos += 4

        tags = sorted(dist)
        evidence = (
            "u16 run at record+8+%#x closed by 0xffff, inside the record on %d/%d records and "
            "4-byte aligned with the next list's start on %d/%d; every value decodes as a "
            "class-%s pool key (%d/%d exist in SND_POOL; the rest are %s), spanning %d..%d in "
            "%d distinct values; read as u32 the same bytes give %d values of which %d is a pool "
            "key, which refutes the 4-byte width"
            % (LIST_OFFSETS[index], ends, len(starts), tiled, len(starts),
               "/".join(CLASSES[t] for t in tags), len(values) - sum(missing.values()), len(values),
               ", ".join("%d x%d" % (v, c) for v, c in sorted(missing.items())) or "none",
               min(values), max(values), len(set(values)), wide, wide_resolved))

        lists.append({
            "index": index,
            "offset_field": LIST_OFFSETS[index],
            "width": 2,
            "width_evidence": evidence,
            "terminator": "0xffff",
            "values_total": len(values),
            "values_distinct": len(set(values)),
            "value_range": [min(values), max(values)],
            "class_distribution": {CLASSES[t]: dist[t] for t in tags},
            "values_resolved": len(values) - sum(missing.values()),
            "unresolved": [{"value": v, "hex": hex(v), "count": c}
                           for v, c in sorted(missing.items())],
            "role": ROLES[index],
            "unresolved_reason": None if not missing else
                                 "%d value(s) name no record in SND_POOL — a dangling reference, not "
                                 "a width problem: every one of them is a hole in the class this "
                                 "list draws on" % sum(missing.values()),
            "spans_past_record": past_record,
        })

    # --- list 5: a row array, in two shapes
    rows_by_flag, closes, keys5 = {}, Counter(), []
    for rec, row in zip(starts, records):
        rowset = tail_rows(pro, rec, row["stride"], row["offsets"][5], row["flag"])
        rows_by_flag.setdefault(rowset["width"], []).append(rowset)
        closes[(row["flag"], rowset["closed"])] += 1
        keys5 += [row_key(r, rowset["width"]) for r in rowset["rows"]]
    elements = sum(len(r["rows"]) for rowsets in rows_by_flag.values() for r in rowsets)
    dist5 = Counter((k >> 14) & 3 for k in keys5)
    missing5 = Counter(k for k in keys5 if k not in every_key)

    # the u16 reading, refuted
    u16_past = 0
    for rec, row in zip(starts, records):
        pos = rec + LIST_BASE + row["offsets"][5]
        while pos + 2 <= rec + row["stride"] and struct.unpack_from(">H", pro, pos)[0] != TERM16:
            pos += 2
        u16_past += pos > rec + row["stride"] - 2

    # the two extra u32 of a flag-0 record are offsets: each one starts the next 8-byte row table in
    # the record's tail, one terminator (+ its 4 bytes of padding) past the previous table's end.
    def tail_end(at, end):
        while at + 8 <= end and pro[at:at + 4] != b"\xff\xff\xff\xff":
            at += 8
        return at + 8

    tail_chain = 0
    for rec, row in zip(starts, records):
        if row["flag"] != 0:
            continue
        end = rec + row["stride"]
        first, second = (rec + LIST_BASE + off
                         for off in struct.unpack_from(">2I", pro, rec + EXT_OFFSET))
        after_list = tail_end(rec + LIST_BASE + row["offsets"][5], end)
        tail_chain += (first == after_list and second == tail_end(first, end)
                       and pro[end - 4:end] == b"\xff\xff\xff\xff")

    # constant columns of the 12-byte rows, and the 8-byte rows' own layout
    rows12 = [x for rowset in rows_by_flag.get(12, []) for x in rowset["rows"]]
    rows8 = [x for rowset in rows_by_flag.get(8, []) for x in rowset["rows"]]
    columns = [Counter(r[c] for r in rows12) for c in range(12)]
    columns8 = [Counter(r[c] for r in rows8) for c in range(8)]

    ascends = sum(1 for rowset in rows_by_flag.get(12, [])
                  if all(struct.unpack_from(">H", b, 0)[0] < struct.unpack_from(">H", a, 0)[0]
                         for a, b in zip(rowset["rows"], rowset["rows"][1:])))

    lists.append({
        "index": 5,
        "offset_field": LIST_OFFSETS[5],
        "width": 12,
        "width_when_flag_0": 8,
        "width_evidence": (
            "not a u16 key run: read as u16 the walk runs past the record end on %d/%d records. "
            "With the u16 at +6 == 1 (287 records) the field is {u16 count, u16 0} followed by "
            "count 12-byte rows, and 4 + 12*count closes the record exactly on %d/%d; those rows "
            "have constant columns (+4 = 0xff on %d/%d, +5 = 0x0a on %d/%d, +7 = 0x40 on %d/%d, "
            "+9..+11 zero on %d/%d) and their u16 at +0 strictly ascends on %d/%d arrays, which is "
            "what FUN_800ab43c binary-searches. With the flag == 0 (130 records) the field is "
            "8-byte rows closed by 0xffffffff (closed on %d/%d), with columns +4 = 0xff and "
            "+6/+7 zero on %d/%d rows, and the two u32 at record+0x20 address the two further "
            "8-byte row tables that close the record's tail (%d/%d records chain exactly)."
            % (u16_past, len(starts), closes[(1, True)], flags[1],
               columns[4][0xff], len(rows12), columns[5][0x0a], len(rows12),
               columns[7][0x40], len(rows12), columns[9][0] + columns[10][0] + columns[11][0],
               3 * len(rows12), ascends, len(rows_by_flag.get(12, [])),
               closes[(0, True)], flags[0], columns8[4][0xff], len(rows8),
               tail_chain, flags[0])),
        "terminator": "0xffffffff when the flag is 0; the flag 1 form is count-prefixed and has none",
        "values_total": elements,
        "values_distinct": len(set(keys5)),
        "value_range": [min(keys5), max(keys5)],
        "class_distribution": {CLASSES[t]: dist5[t] for t in sorted(dist5)},
        "values_resolved": len(keys5) - sum(missing5.values()),
        "unresolved": [{"value": v, "hex": hex(v), "count": c} for v, c in sorted(missing5.items())],
        "role": ROLES[5],
        "unresolved_reason": (
            "what the rows mean is unresolved: three columns are constant, the mutable ones are an "
            "ascending index, a class-0 sample key and two parameter bytes. The only row byte the "
            "corpus writes is +9 (FUN_800adb48), and the comparison that picks a row lives in "
            "`LAB_800ae184`, a label with no decompiled body — so which fields the search compares, "
            "and what the parameters mean, are not established. Row array plus sorted index is all "
            "this artefact asserts. (The keys that resolve to no pool record are not "
            "dangling references but the sentinels either side of a class range: 0 below the "
            "class-0 floor, 2027 one above its ceiling, 0x8149 one above class 2's.)"),
        "spans_past_record": u16_past,
    })

    listed = {}
    for index, entry in enumerate(lists):
        listed[str(index)] = entry["values_total"]

    unresolved_total = sum(sum(u["count"] for u in e["unresolved"]) for e in lists)

    fields = [
        {"offset": 0, "size": 4, "name": "stride",
         "evidence": "the chain walks it: %d strides plus the 4-byte -1 terminator tile the %d-byte "
                     "member exactly (%d distinct strides, %d..%d)"
                     % (len(starts), len(pro), len({r["stride"] for r in records}),
                        min(r["stride"] for r in records), max(r["stride"] for r in records))},
        {"offset": 4, "size": 2, "name": "key",
         "evidence": "a bijection onto 0..%d less %s (%d distinct over %d records)"
                     % (max(r["key"] for r in records),
                        sorted(set(range(0, max(r["key"] for r in records) + 1))
                               - {r["key"] for r in records}), len({r["key"] for r in records}),
                        len(records))},
        {"offset": FLAG, "size": 2, "name": "flag",
         "evidence": "NOT constant: 0 on %d records and 1 on %d. FUN_800a86a0 reaches FUN_800adb48 "
                     "only when it is 1, and the value coincides with the header extension on %d/%d "
                     "records (flag 1 -> first list at offset 24, flag 0 -> at 32)"
                     % (flags[0], flags[1], flags[0] + flags[1], len(records))},
        {"offset": 8, "size": 24, "name": "list offsets",
         "evidence": "six u32, the player's param_1[2..7], relative to record + 8: based at record "
                     "+ 0 the six spans overlap in %d/%d records, based at record + 8 they overlap in "
                     "%d/%d and tile the record on %d/%d"
                     % (spans_overlap[0], len(starts), spans_overlap[LIST_BASE], len(starts),
                        tiled, len(starts))},
        {"offset": EXT_OFFSET, "size": 8, "name": "offsets_extra",
         "evidence": "two u32 that exist only where the first list offset is 32 (%d records; the "
                     "other %d start at 24 and use these 8 bytes as list data). They behave as "
                     "offsets in the same record+%d base: on %d/%d flag-0 records the first starts "
                     "the next 8-byte row table exactly one terminator past the sixth list's own, "
                     "the second starts the table after that one, and the third table's 0xffffffff "
                     "ends 4 bytes before the record does. No function in the corpus reads either "
                     "field, so they are published as the tail tables' offsets and nothing more"
                     % (flags[0], flags[1], LIST_BASE, tail_chain, flags[0])},
    ]

    artefact = {
        "tool": "tools/snd_proj.py",
        "schema": "snd_proj/1",
        "cart_sha256": hashlib.sha256(data).hexdigest(),
        "inputs": [
            {"id": PROJ, "name": "SND_PROJ", "cart_offset": ft.BASE + entries[PROJ][0],
             "stored_size": entries[PROJ][1], "member_bytes": len(pro), "codec": "zlib"},
            {"id": POOL, "name": "SND_POOL", "cart_offset": ft.BASE + entries[POOL][0],
             "stored_size": entries[POOL][1], "member_bytes": len(pool), "codec": "zlib"},
            {"id": SMPDIR, "name": "SND_SMPDIR", "cart_offset": ft.BASE + entries[SMPDIR][0],
             "stored_size": entries[SMPDIR][1], "codec": "zlib"},
        ],
        "header": {
            "record_count": len(starts),
            "chain_end": term,
            "member_bytes": len(pro),
            "list_base": LIST_BASE,
            "min_offset_census": {str(k): v for k, v in sorted(min_offsets.items())},
            "tail_chain_records": tail_chain,
            "flag_census": {str(k): v for k, v in sorted(flags.items())},
            "fields": fields,
        },
        "lists": lists,
        "records": records,
        "totals": {
            "records": len(starts),
            "chain_bytes": term,
            "member_bytes": len(pro),
            "list_values": listed,
            "list_values_total": sum(listed.values()),
            "unresolved_values": unresolved_total,
            "pool_keys_total": len(every_key),
            "pool_keys_by_class": {CLASSES[t]: len(v) for t, v in sorted(classes.items())},
            "command_streams": 0,
            "command_stream_candidates": [],
        },
    }
    return artefact


ROLES = {
    0: "u16 keys, all class 0: FUN_800ad62c per key against the pool chain — the project's sample "
       "binding, the one feed of the six that touches no cache table",
    1: "u16 keys, all class 0: FUN_800add28 per key, walking a 12-byte-stride registry at "
       "0x8014e170 (reached only when FUN_800ad330 passes)",
    2: "u16 keys, all class 3: FUN_800ad0c0 — inserted into the key-sorted cache at 0x8014e1e0",
    3: "u16 keys, all class 1: FUN_800acbc0 — inserted into the key-sorted cache at 0x801521f0",
    4: "u16 keys, all class 2: FUN_800ace1c — cache at 0x80152a00, keyed by key AND rate",
    5: "record array, not keys: FUN_800adb48 stores {key, count, pointer} in the bank at 0x80157e20 "
       "when the flag is 1, and FUN_800ae034 hands the array to FUN_800ab43c, a binary search at "
       "stride 0xc through a comparison callback — a row array with a sorted index, not a program",
}


# --- rendering ---------------------------------------------------------------------------------

def render(artefact):
    return json.dumps(artefact, indent=1, sort_keys=True) + "\n"


def _report(artefact):
    lists = artefact["lists"]
    header = artefact["header"]
    print("SND_PROJ: %d records, %d B chained + %d B terminator = %d B member"
          % (header["record_count"], header["chain_end"],
             header["member_bytes"] - header["chain_end"], header["member_bytes"]))
    print("  header: stride, key, flag (0 x%d / 1 x%d), six offsets at record+%d, two more at %#x "
          "for the flag-0 records"
          % (header["flag_census"]["0"], header["flag_census"]["1"], header["list_base"], EXT_OFFSET))
    for entry in lists:
        dist = ", ".join("class %s x%d" % (k, v) for k, v in sorted(entry["class_distribution"].items()))
        width = ("%d" % entry["width"]) if entry["index"] != 5 else \
                "12 (flag 1) / 8 (flag 0)"
        print("  list %d @+%d  width %-20s %6d value(s)  %s"
              % (entry["index"], entry["offset_field"], width, entry["values_total"], dist))
    totals = artefact["totals"]
    print("  %d unresolved value(s) over all six lists; %d command stream(s): none in SND_PROJ — the "
          "only count-prefixed container in the family is SND_POOL class 2"
          % (totals["unresolved_values"], totals["command_streams"]))
    return artefact


# --- check ------------------------------------------------------------------------------------

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
    pro_recs, term = chain(member(*_cart_pair(), PROJ))

    # --- the chain
    case("417 records whose strides plus the 4-byte terminator tile the 102 148-byte member",
         len(pro_recs) == 417 and term == 102144
         and term + 4 == fresh["header"]["member_bytes"],
         "%d records, terminator at %d, member %d"
         % (len(pro_recs), term, fresh["header"]["member_bytes"]))
    keys = [r["key"] for r in fresh["records"]]
    holes = sorted(set(range(min(keys), max(keys) + 1)) - set(keys))
    case("the u16 at +4 is a bijection onto 0..417 less the hole 11",
         len(set(keys)) == 417 and min(keys) == 0 and max(keys) == 417 and holes == [11],
         "holes %s" % holes)

    # --- the flag is not constant, and this is why it is called a flag
    flags = Counter(r["flag"] for r in fresh["records"])
    mins = Counter(min(r["offsets"]) for r in fresh["records"])
    case("REFUTED: the u16 at +6 is not the constant 0 — 0 on 130 records, 1 on 287, and the value "
         "is exactly what decides whether the first list starts at offset 24 or 32",
         flags[0] == 130 and flags[1] == 287 and mins[24] == 287 and mins[32] == 130
         and sum(flags.values()) == 417 and not (set(flags) - {0, 1}),
         "flag census %s, min-offset census %s" % (dict(flags), dict(mins)))

    # --- the base: measured twice, and only one of the two readings can be true
    overlap0 = overlap8 = tiled = 0
    for rec, row in zip(pro_recs, fresh["records"]):
        for base in (0, LIST_BASE):
            spans = []
            for off in row["offsets"]:
                pos = rec + base + off
                while struct.unpack_from(">H", fresh_pro(), pos)[0] != TERM16:
                    pos += 2
                spans.append((base + off, pos - rec + 2))
            spans.sort()
            if any(spans[i][1] > spans[i + 1][0] for i in range(len(spans) - 1)):
                if base == 0:
                    overlap0 += 1
                else:
                    overlap8 += 1
        spans = []
        for off in row["offsets"]:
            _vals, at = key_list(fresh_pro(), rec, off)
            spans.append((LIST_BASE + off, at - rec + 2))
        spans.sort()
        tiled += all((spans[i][1] + 3) // 4 * 4 == spans[i + 1][0] for i in range(len(spans) - 1))
    case("REFUTED: the list offsets are not relative to record + 0 — read that way the six spans "
         "overlap in 417/417 records",
         overlap0 == 417, "%d/417 overlap" % overlap0)
    case("relative to record + 8 — the base FUN_800a86a0 adds — they overlap in 0/417 and tile each "
         "record with 4-byte alignment on 417/417",
         overlap8 == 0 and tiled == 417, "%d overlap, %d tiled" % (overlap8, tiled))

    # --- every key list parses to its declared terminator, inside its own record
    for entry in fresh["lists"][:KEY_LISTS]:
        case("list %d parses to its 0xffff terminator inside the record on 417/417 records"
             % entry["index"], entry["spans_past_record"] == 0,
             "%d past the record" % entry["spans_past_record"])

    # --- the classes: one per list position, which is what makes the u16 width evidence
    want = {0: {0: 3468}, 1: {0: 3316}, 2: {3: 261}, 3: {1: 4}, 4: {2: 339}}
    got = [{int(k): v for k, v in e["class_distribution"].items()} for e in fresh["lists"][:KEY_LISTS]]
    case("each of lists 0-4 draws on exactly one pool class, and it is a different one each time: "
         "0 and 1 class 0 (%d, %d values), 2 class 3 (%d), 3 class 1 (%d), 4 class 2 (%d)"
         % (got[0][0], got[1][0], got[2][3], got[3][1], got[4][2]),
         got == [want[i] for i in range(KEY_LISTS)], "%s" % got)

    # --- the widths, re-derived, per list position
    widths = {e["index"]: e["width"] for e in fresh["lists"]}
    case("the per-list widths re-derive as 2,2,2,2,2 for the five key lists and 12 for the sixth "
         "(8 in its flag-0 form)", widths == {0: 2, 1: 2, 2: 2, 3: 2, 4: 2, 5: 12}
         and fresh["lists"][5]["width_when_flag_0"] == 8, "%s" % widths)
    case("the committed per-list widths and class distributions are the fresh ones",
         [e["width"] for e in committed.get("lists", [])] == [e["width"] for e in fresh["lists"]]
         and [e["class_distribution"] for e in committed.get("lists", [])]
         == [e["class_distribution"] for e in fresh["lists"]])

    # --- list 5 is not a key list
    case("REFUTED: list 5 is not a u16 key run — read as u16 its walk runs past the record end on "
         "the 287 flag-1 records and stops only on a byte that is not a terminator",
         fresh["lists"][5]["spans_past_record"] == 287,
         "%d/417 past the record" % fresh["lists"][5]["spans_past_record"])
    closes = Counter()
    elements = 0
    for rec, row in zip(pro_recs, fresh["records"]):
        got5 = tail_rows(fresh_pro(), rec, row["stride"], row["offsets"][5], row["flag"])
        closes[(row["flag"], got5["closed"])] += 1
        elements += got5["count"]
    case("list 5's terminator differs by flag and each form closes the record exactly: flag 1 is "
         "{u16 count, u16 0} + count x 12 bytes with 4 + 12*count at the record end (287/287), flag "
         "0 is 8-byte rows closed by 0xffffffff (130/130) — %d rows over both forms"
         % elements,
         closes[(1, True)] == 287 and closes[(0, True)] == 130 and elements == 3822,
         "closed by flag: %s" % {(k[0], k[1]): v for k, v in closes.items()})
    case("the two extra u32 of a flag-0 record are the offsets of the record's two tail tables: the "
         "chain list 5 -> first -> second ends 4 bytes before the record does on 130/130",
         fresh["header"]["tail_chain_records"] == 130,
         "%d/130 chain" % fresh["header"]["tail_chain_records"])

    # --- the widths are not the same claim as "these are keys": say what list 5 holds
    rows12 = []
    for rec, row in zip(pro_recs, fresh["records"]):
        if row["flag"] == 1:
            rows12 += tail_rows(fresh_pro(), rec, row["stride"], row["offsets"][5], 1)["rows"]
    const = [len({r[c] for r in rows12}) for c in range(12)]
    case("list 5's 12-byte rows are a record, not a command: columns +4, +5, +7 and +9..+11 are "
         "constant on all %d rows, so no byte in the row is an opcode with a vocabulary"
         % len(rows12),
         const[4] == 1 and const[5] == 1 and const[7] == 1 and const[9] == 1 and const[10] == 1
         and const[11] == 1 and const[0] == 12 and len(rows12) == 3068, "%s distinct per column" % const)
    ascend = all(
        all(struct.unpack_from(">H", b, 0)[0] > struct.unpack_from(">H", a, 0)[0]
            for a, b in zip(rs["rows"], rs["rows"][1:]))
        for rec, row in zip(pro_recs, fresh["records"]) if row["flag"] == 1
        for rs in [tail_rows(fresh_pro(), rec, row["stride"], row["offsets"][5], 1)])
    case("and its u16 at +0 strictly ascends inside every array — the index FUN_800ab43c binary "
         "searches at stride 0xc, which a variable-length command stream could not be", ascend)

    # --- the cross-reference, and what it refuses to resolve
    unresolved = [len(e["unresolved"]) for e in fresh["lists"]]
    missing = sum(u["count"] for e in fresh["lists"] for u in e["unresolved"])
    dangles = [(u["value"], u["count"]) for e in fresh["lists"][:KEY_LISTS] for u in e["unresolved"]]
    case("the class distributions sum to the value counts in every list, in the committed file too",
         all(sum(e["class_distribution"].values()) == e["values_total"] for e in fresh["lists"])
         and all(sum(e["class_distribution"].values()) == e["values_total"]
                 for e in committed["lists"]))
    case("the dangling references in lists 0-4 are holes in the class each list draws on, not a "
         "width problem: 531 (the class-0 hole) x16, 0xc085 one below class 3's floor, 0x4001 one "
         "below class 1's floor, 0x8098 the class-2 hole",
         dangles == [(531, 1), (531, 15), (49285, 1), (16385, 1), (32920, 1)]
         and unresolved[:KEY_LISTS] == [1, 1, 1, 1, 1]
         and missing == 182, "%d unresolved value(s): %s" % (missing, dangles))

    # --- where the macro opcodes are not
    case("no command stream was found in SND_PROJ, and the artefact says so as a count rather than a "
         "silence", fresh["totals"]["command_streams"] == 0
         and fresh["totals"]["command_stream_candidates"] == []
         and committed["totals"] == fresh["totals"])
    pool = member(*_cart_pair(), POOL)
    sections = list(struct.unpack_from(">4I", pool, 0))
    class2 = chain(pool, sections[3] + struct.unpack_from(">I", pool, sections[3])[0], len(pool))[0]
    law = sum(1 for r in class2
              if struct.unpack_from(">i", pool, r)[0] == 12 + 12 * struct.unpack_from(">I", pool, r + 8)[0])
    cols2 = [len({pool[r + 12 + 12 * k + c] for r in class2
                  for k in range(struct.unpack_from(">I", pool, r + 8)[0])}) for c in range(12)]
    case("the pointer to where macros would have to live: SND_POOL class 2, %d records with "
         "size == 12 + 12*count on %d/%d — but its rows have %d, %d, %d, %d constant columns too, so "
         "they are a pairing table and this tool does not call them macros"
         % (len(class2), law, len(class2), cols2[6], cols2[9], cols2[10], cols2[11]),
         len(class2) == 326 and law == 326
         and cols2[6] == 1 and cols2[9] == 1 and cols2[10] == 1 and cols2[11] == 1)

    # --- the code reading, so a re-decompile that loses it invalidates the claim
    src = HERE.parent / "src" / "stage2"
    resolver = (src / "FUN_800a86a0.c").read_text()
    case("CODE: FUN_800a86a0 bases the five walked lists on record + 8 and walks them as shorts "
         "(param_1[2] .. param_1[6]), and reads param_1[7] at +8 and +12 as a count and a pointer",
         all("(short *)((int)param_1 + param_1[%d] + 8)" % k in resolver for k in range(2, 7))
         and "*(undefined2 *)((int)param_1 + param_1[7] + 8)" in resolver
         and "(int)param_1 + param_1[7] + 0xc" in resolver
         and "psVar6 = psVar6 + 1;" in resolver)
    bank = (src / "FUN_800adb48.c").read_text()
    case("CODE: FUN_800adb48 takes the u16 at +0 as a count and the pointer at +4, and stamps 0x1f "
         "at +9 of each 12-byte row",
         "*(undefined1 *)(param_2 + 9) = 0x1f;" in bank and "param_2 = param_2 + 0xc;" in bank)
    case("CODE: the flag gate is `*(short *)((int)param_1 + 6) == 1`, i.e. the u16 at +6",
         "*(short *)((int)param_1 + 6) == 1" in resolver)
    search = (src / "FUN_800ae034.c").read_text()
    walker = (src / "FUN_800ab43c.c").read_text()
    case("CODE: FUN_800ae034 walks the row array at stride 0xc, and FUN_800ab43c is a binary search",
         ",0xc" in search.replace(" ", "") and "(iVar1 >> 1)" in walker
         and "param_2 + param_4 * iVar4" in walker)

    # --- the committed artefact is the one --write would produce
    same = committed == fresh
    if not same:
        drift = sorted(k for k in committed if committed.get(k) != fresh.get(k))
        case("the committed artefact equals a fresh --write", False, "drifted: %s" % drift)
    else:
        case("the committed artefact equals a fresh --write", True)

    return _tally(cases)


_CART = {}


def _cart_pair():
    """The cartridge, read once for the whole check run."""
    if not _CART:
        _CART["pair"] = cartridge()
    return _CART["pair"]


def fresh_pro():
    """SND_PROJ, inflated once."""
    if "pro" not in _CART:
        _cart_pair()
        _CART["pro"] = member(_CART["pair"][0], _CART["pair"][1], PROJ)
    return _CART["pro"]


def _tally(cases):
    passed = 0
    for ok, label, detail in cases:
        passed += ok
        line = "  %s %s" % ("PASS" if ok else "FAIL", label)
        if detail and not ok:
            line += "  [%s]" % detail
        print(line)
    print("%d/%d snd_proj case(s)" % (passed, len(cases)))
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
        # cannot answer any of these questions. Say so and stop, the way cfg_reach does.
        try:
            where = ft.ROM.relative_to(HERE.parent)
        except ValueError:
            where = ft.ROM
        print("SKIP: no cartridge at %s — every snd_proj case needs it" % where)
        return 0

    if args.write:
        artefact = _report(derive())
        path = HERE.parent / OUT
        path.write_text(render(artefact))
        print("-> %s (%d records, %d list values)"
              % (OUT, len(artefact["records"]), artefact["totals"]["list_values_total"]))
        return 0

    return check()


if __name__ == "__main__":
    raise SystemExit(main())
