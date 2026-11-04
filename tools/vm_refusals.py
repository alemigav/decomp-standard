#!/usr/bin/env python3
"""Every room the decoder refuses, classified: the work list `scd_vm.py --decode` leaves behind.

**What this claims.**

  * a **sweep of all 256 rooms**, 0..255. The index is read from a single byte in `0x8009b27c`, so no entry
    past 255 can be selected (`cfg_reach.ROOM_TABLE_MAX`). Each room takes the route `scd_vm.decode_room()`
    walks, room by room: room -> `DAT_80131fa8[room]` -> file id -> file-table record 0x43 -> zlib member ->
    the `u16[]` record table at the block's head -> one span per record start (`start` to the next start, or
    to the end of the block).
  * **no second decoder.** The decode is `scd_vm.trace_record()` on `scd_vm.Reader` and `scd_vm.OffsetTable`,
    and the span rule is `decode_room()`'s. This tool changes exactly one thing: it passes `strict=True`, so
    that a refusal arrives as **the decoder's own exception** with its own `.offset` and `.opcode` instead of
    the stop string `decode_room()` otherwise turns it into.
  * a **classification**, each kind named for the exception that produces it:

        unresolved_advance      scd_vm.UnresolvedAdvance: the opcode has no constant advance, no jump spec and
                                no slot or table supplies its destination. `0x36` is the only one today.
        record_start_not_code   scd_vm.UnknownOpcode at the record's **own start**: the record table names an
                                address whose first byte is not in the 141-entry table, so the record's start
                                address does not decode as a known command at all.
        truncated               scd_vm.TruncatedInstruction: an instruction would read past the record's bytes.
        unknown_opcode          scd_vm.UnknownOpcode **after** the record's first instruction: the record
                                start did decode, and the walk reached a byte that is not in the table.
        other                   anything else, with the exception class and its message verbatim.

    (`record_start_not_code` and `unknown_opcode` are one exception class, split at the one place the decoder
    already distinguishes them: the record's own start, which is where a *record table* can be wrong rather
    than a *walk*. `UnresolvedAdvance` is `unresolved_advance` wherever it lands: `0x36` **is** a table
    entry, so the record start did decode.)
  * **one row per room**: its first refusal, with the file id, the block's decompressed size, the index of
    the record it landed in (`records_decoded`), the pc, the opcode, the exception and its message.
  * **work items**, one per kind that observed a refusal, each saying what would settle it.

**What this refuses.**

  * **no claim that a room has no script.** `no_block` means `DAT_80131fa8[room] == 0` and nothing more.
    `no_block` is not `empty`, and an empty entry is a fact about the room table, not about the room.
  * **no claim that a `clean` room is understood.** Clean means the decoder raised nothing on any record
    start. A block whose head is `0` rather than a `u16[]` record table decodes zero records and is clean by
    this measure — it is the decoder's silence, not evidence of a decoded script, and `clean` is therefore
    not a count of scripts that decoded.
  * **no complete account of a block.** The sweep stops at a room's first refusal, so a block that refuses
    twice is one row and the second refusal is not in the artefact.
  * **no game-level claim.** A refusal says where the registry's length map, the record table or the walk
    runs out of evidence. It does not say the cartridge cannot run the room: the VM in the cartridge is the
    authority on that and this tool never runs it.
  * **no fix.** It adds no opcode to the registry, invents no length and patches no byte.
  * **no claim that a kind with no rows cannot happen.** `truncated` is 0 here because no record was observed
    short of its instruction; that is a fact about this sweep, not about the format.

Usage:
  ./vm_refusals.py --write     # regenerate manifests/vm_refusals.json
  ./vm_refusals.py --check     # validate the committed artefact (re-sweeps when the cartridge is present)
"""
import argparse
import json
import sys
import zlib
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import room_script                                              # noqa: E402
import scd_vm                                                   # noqa: E402

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

ARTEFACT = ROOT / "manifests" / "vm_refusals.json"
SCHEMA = "vm-refusals/1"
MAX_BYTES = 4 << 20            # the repository tracks no file larger than this, so neither does this tool

# The five kinds, reported in this order. Alphabetical, so a re-sweep that only moves rooms between kinds
# reorders nothing, and a diff reads as the rooms that moved.
KINDS = ("other", "record_start_not_code", "truncated", "unknown_opcode", "unresolved_advance")

# The exception each kind is a classification of, and the words `scd_vm`'s own message begins with — so a
# kind that no longer matches the decoder it came from is caught without the cartridge.
PROVENANCE = {
    "record_start_not_code": ("UnknownOpcode", "unknown opcode"),
    "truncated": ("TruncatedInstruction", "truncated instruction"),
    "unknown_opcode": ("UnknownOpcode", "unknown opcode"),
    "unresolved_advance": ("UnresolvedAdvance", "unresolved advance"),
}
# The three subclasses whose class decides a kind. Anything else — `DecodeError` itself, or an exception from
# outside the decoder such as `zlib.error` — is `other`.
KIND_CLASSES = tuple(cls for cls, _says in PROVENANCE.values())

# What would settle a kind. Stable prose, one per kind: the rooms are the sweep's, the sentence is this
# tool's judgement about what evidence would end the item.
NEXT_STEP = {
    "record_start_not_code":
        "the block is an `01 41` container, not a script: word0 is 0x01410000 (tools/container_0141.py), so "
        "`room_script.records()` reads the magic's low halfword 0x0141 as u16[0] and seeds the decode at "
        "0x141, which is inside the payload (the payload begins at 16*N = 32). Settle it by deciding whether "
        "the room table names a script for these rooms at all: either the room loader at 0x8009b27c selects "
        "a sub-entry of the container, or these rooms have no script, which is a fact about "
        "DAT_80131fa8 and not about the decoder.",
    "truncated":
        "an instruction reads past the record's own end: the registry's published length for the opcode and "
        "the record table's span disagree. Settle it by reading the handler's own advance for that opcode "
        "(fixtures/scd/registry.json `advances`, tools/handler_region.py) and deciding which of the two "
        "numbers is wrong, since a short span from an off-by-one record offset looks exactly like a long "
        "instruction.",
    "unknown_opcode":
        "the same `01 41` population as record_start_not_code, one byte further in: at 0x141 the payload "
        "happens to start with a table opcode, so the walk misaligns inside container data instead of "
        "refusing at the seed. The byte is the container's, not an unregistered command, so this settles "
        "with the container question; do not add 0xff or 0x94 to the registry on the strength of these "
        "rows.",
    "unresolved_advance":
        "0x36 dispatches through a pointer rather than an address (`jr <*(0x800c98e0 + (s16[cmd+4] >> 8)*4)>`). "
        "Resolve the table at 0x800c98e0 for the operand these records carry and decide whether the target is "
        "a command at all; if it is not, the record's `blocked` state is final and 0x36 needs no registry "
        "entry.",
    "other":
        "the file-table entry does not inflate: the member is a 17-33 byte ASCII label (\"Police Memorandum\", "
        "\"OPERATION REPORT\", \"MAIL TO THE CHIEF\", ...), so DAT_80131fa8 names a text resource for these "
        "rooms, not a zlib script block. Settle it by identifying that resource kind in the file-table census "
        "(tools/file_table.py) and what the room loader does with such an entry, rather than treating the "
        "member as a damaged script.",
}

INPUTS = {
    "cartridge": "rom/Resident Evil 2 (USA) (Rev 1).z64 (gitignored: the owner's own dump)",
    "rooms": "0..255 of DAT_80131fa8 (cfg_reach.ROOM_TABLE), one u16 file id per room",
    "route": "room -> file id -> file-table record 0x43 {offset, size} -> zlib member -> u16[] record table "
             "at the block's head (tools/room_script.py block()/records())",
    "decoder": "tools/scd_vm.py: Reader, OffsetTable and trace_record(strict=True): the refusal is the "
               "decoder's own exception with its own .offset and .opcode, not a string this tool recognised",
    "kinds": {
        "other": "any other refusal, with the exception class and its message verbatim",
        "record_start_not_code": "scd_vm.UnknownOpcode at the record's own start: the record table names an "
                                 "address that is not a command",
        "truncated": "scd_vm.TruncatedInstruction: an instruction would read past the record's bytes",
        "unknown_opcode": "scd_vm.UnknownOpcode after the record's first instruction: a byte that is not in "
                          "the 141-entry table",
        "unresolved_advance": "scd_vm.UnresolvedAdvance: opcode 0x36, whose advance is a callback pointer "
                              "rather than a command address",
    },
    "per_refusal": "room, file_id, kind, pc, opcode, records_decoded (the index of the record that refused: "
                   "how many record starts this sweep decoded before it), bytes (the block's decompressed "
                   "size, null when the member did not inflate), exception, message",
}


def classify(exc, start=None):
    """Which kind this refusal is: the decoder's exception class, and where it landed in the record.

    `start` is the record's own start address. It is the one thing that separates the two meanings of
    `UnknownOpcode`: a byte that is not in the table **at a record's start** (a record table pointing at
    something that is not code) and one **after** the first instruction (a walk that misaligned). Nothing
    here re-reads a byte the decoder already read, so a kind cannot contradict the exception it is a kind of.
    """
    if isinstance(exc, scd_vm.UnresolvedAdvance):
        return "unresolved_advance"
    if isinstance(exc, scd_vm.TruncatedInstruction):
        return "truncated"
    if isinstance(exc, scd_vm.UnknownOpcode):
        return "record_start_not_code" if start is not None and exc.offset == start else "unknown_opcode"
    return "other"


def exception_name(exc):
    """The exception's name. The decoder's own classes are unambiguous by name; anything else is qualified,
    because `zlib.error`'s class name is the bare word `error`."""
    cls = type(exc)
    if cls.__module__ in ("builtins", scd_vm.__name__):
        return cls.__name__
    return f"{cls.__module__}.{cls.__name__}"


def refusal_row(room, file_id, size, kind, exc, index):
    """One refusal, as the artefact carries it: what refused, where, and in its own words."""
    return {"room": room, "file_id": file_id, "kind": kind,
            "pc": getattr(exc, "offset", None), "opcode": getattr(exc, "opcode", None),
            "records_decoded": index, "bytes": size,
            "exception": exception_name(exc), "message": str(exc)}


def sweep_room(rom, image, room):
    """One room -> `no_block`, `clean`, or the first refusal its records make.

    The route and the record span rule are `scd_vm.decode_room()`'s, verbatim, including which record a
    record's bytes stop at; the difference is `strict=True`, because a refusal is the answer here and not a
    reason to keep the steps before it.
    """
    file_id = scd_vm.room_file_id(image, room)
    if not file_id:
        return {"room": room, "status": "no_block"}
    try:
        raw = room_script.block(rom, file_id)
    except (SystemExit, zlib.error) as exc:
        # room_script's own two refusals: a file-table entry with no bytes (SystemExit), and a member that is
        # not a zlib stream (zlib.error). Neither happened before the decoder ran, so there is no pc and no
        # decompressed size to report.
        return {"room": room, "status": "refused",
                "refusal": refusal_row(room, file_id, None, classify(exc), exc, 0)}
    table = room_script.records(raw)
    for i, start in enumerate(table):
        end = table[i + 1] if i + 1 < len(table) else len(raw)
        try:
            scd_vm.trace_record(scd_vm.Reader(raw, start, end), start,
                                table=scd_vm.OffsetTable(table), strict=True)
        except scd_vm.DecodeError as exc:
            return {"room": room, "status": "refused",
                    "refusal": refusal_row(room, file_id, len(raw), classify(exc, start), exc, i)}
    return {"room": room, "status": "clean"}


def sweep():
    """All 256 rooms, in room order. Deterministic: the same cartridge gives the same rows."""
    rom = scd_vm.ROM.read_bytes()
    image = scd_vm.stage2_image(rom)
    return [sweep_room(rom, image, room) for room in range(scd_vm.ROOM_TABLE_MAX)]


def work_items(refusals):
    """One item per kind that observed a refusal: its rooms, and what would settle it.

    Grouped by kind because the kind is the decoder's own distinction and the exception is what a researcher
    acts on. A kind with no refusal is not a work item — an empty item would be a to-do with nothing to do.
    """
    grouped = {}
    for row in refusals:
        grouped.setdefault(row["kind"], []).append(row["room"])
    return [{"kind": kind, "rooms": sorted(grouped[kind]), "count": len(grouped[kind]),
             "next_step": NEXT_STEP[kind]}
            for kind in KINDS if kind in grouped]


def document(rows):
    """The artefact: the totals, one row per refusal, the no-block rooms, and the work items."""
    refusals = sorted((row["refusal"] for row in rows if row["status"] == "refused"),
                      key=lambda r: r["room"])
    no_block = sorted(row["room"] for row in rows if row["status"] == "no_block")
    counts = Counter(row["kind"] for row in refusals)
    totals = {"rooms_swept": len(rows),
              "clean": sum(1 for row in rows if row["status"] == "clean"),
              "refused": len(refusals),
              "no_block": len(no_block),
              "by_kind": {kind: counts.get(kind, 0) for kind in KINDS}}
    return {"tool": "tools/vm_refusals.py", "schema": SCHEMA, "inputs": INPUTS, "totals": totals,
            "refusals": refusals, "no_block_rooms": no_block, "work": work_items(refusals)}


def write():
    """Regenerate the artefact, and refuse to write one the repository could not track."""
    doc = document(sweep())
    text = json.dumps(doc, indent=1) + "\n"
    size = len(text.encode())
    if size >= MAX_BYTES:
        print(f"refusing to write {size} B: the repository tracks no file over {MAX_BYTES} B")
        return 1
    ARTEFACT.write_text(text)
    totals = doc["totals"]
    print(f"{ARTEFACT.relative_to(ROOT)}: {totals['rooms_swept']} room(s) swept, {totals['clean']} clean, "
          f"{totals['refused']} refused, {totals['no_block']} no block")
    for kind in KINDS:
        print(f"  {kind:22s} {totals['by_kind'][kind]:3d}")
    for item in doc["work"]:
        print(f"  work {item['kind']:22s} {item['count']:3d} room(s)")
    print(f"{size} B")
    return 0


def resweep_case(doc):
    """The one case that needs the cartridge: today's decoder must still make the committed kinds and words.

    Two routes on purpose. The strict sweep is the route this tool writes with; `scd_vm.decode_room()` is the
    non-strict route the refusal counts were measured with, and a refusal is the same refusal there as the
    stop string `refused at <pc>: <message>` — so the committed pc **and** message have to appear in it.
    """
    if not scd_vm.ROM.exists():
        return ("a re-sweep reproduces every room's kind, pc and message", None,
                f"no cartridge at {scd_vm.ROM.relative_to(ROOT)}, so the re-sweep cannot run")
    rows = sweep()
    fresh = {row["room"]: row["refusal"]["kind"] for row in rows if row["status"] == "refused"}
    committed = {row.get("room"): row.get("kind") for row in doc.get("refusals") or []}
    if fresh != committed:
        moved = sorted(set(fresh.items()) ^ set(committed.items()))
        return ("a re-sweep reproduces every room's kind, pc and message", False,
                f"{len(moved)} room(s) differ, first {moved}")
    no_block = sorted(row["room"] for row in rows if row["status"] == "no_block")
    if no_block != sorted(doc.get("no_block_rooms") or []):
        return ("a re-sweep reproduces every room's kind, pc and message", False,
                "the no-block rooms differ")

    disagree = []
    for row in doc.get("refusals") or []:
        if row.get("kind") == "other" or not isinstance(row.get("pc"), int):
            continue                       # the block never inflated: decode_room() raises where this classifies
        try:
            got = scd_vm.decode_room(row["room"])
        except (SystemExit, zlib.error, ValueError) as exc:
            disagree.append((row["room"], type(exc).__name__))
            continue
        want = f"refused at {row['pc']:#x}: {row['message']}"
        if not any(rec["trace"]["stop"] == want for rec in got["records"]):
            disagree.append((row["room"], "no matching stop"))
    return ("a re-sweep reproduces every room's kind, pc and message",
            not disagree, f"{len(disagree)} room(s) disagree, first {disagree[:3]}")


def check():
    """Validate the committed artefact. Arithmetic and vocabulary first, the cartridge last."""
    try:
        doc = json.loads(ARTEFACT.read_text())
    except (OSError, ValueError) as exc:
        return report([(f"{ARTEFACT.name} parses as JSON", False, str(exc))])
    totals = doc.get("totals") or {}
    refusals = doc.get("refusals") or []
    no_block = doc.get("no_block_rooms") or []
    work = doc.get("work") or []
    rooms = [row.get("room") for row in refusals]
    cases = []

    cases.append(("the artefact names this tool and the schema this tool writes",
                  doc.get("tool") == "tools/vm_refusals.py" and doc.get("schema") == SCHEMA,
                  f"got {doc.get('tool')!r} / {doc.get('schema')!r}"))

    parts = (totals.get("clean"), totals.get("refused"), totals.get("no_block"))
    cases.append((f"the sweep partitions every room: clean + refused + no_block = rooms_swept = "
                  f"{scd_vm.ROOM_TABLE_MAX}",
                  all(isinstance(p, int) for p in parts)
                  and totals.get("rooms_swept") == scd_vm.ROOM_TABLE_MAX
                  and sum(parts) == scd_vm.ROOM_TABLE_MAX,
                  f"got {parts} against {totals.get('rooms_swept')}"))

    counts = Counter(row.get("kind") for row in refusals)
    by_kind = totals.get("by_kind") or {}
    cases.append(("refused is one row per refusal, and by_kind counts those rows kind for kind",
                  totals.get("refused") == len(refusals) and set(by_kind) == set(KINDS)
                  and all(by_kind.get(k, -1) == counts.get(k, 0) for k in KINDS)
                  and sum(by_kind.values()) == len(refusals),
                  f"{len(refusals)} row(s) against {by_kind}"))

    cases.append(("no room appears twice, and the refusals are in room order",
                  all(isinstance(x, int) for x in rooms) and len(set(rooms)) == len(rooms)
                  and rooms == sorted(rooms),
                  f"{len(rooms)} row(s), {len(set(rooms))} distinct, {rooms[:6]}"))

    def agrees(row):
        """The kind must be the one this row's exception and message name, at this row's own pc."""
        kind, name, message = row.get("kind"), row.get("exception"), row.get("message")
        if kind not in KINDS or not isinstance(name, str) or not isinstance(message, str) or not message:
            return False
        if kind == "other":
            return name not in KIND_CLASSES
        cls, says = PROVENANCE[kind]
        pc = row.get("pc")
        return (name == cls and message.startswith(says) and isinstance(pc, int)
                and f"at {pc:#x}" in message and isinstance(row.get("opcode"), int))

    bad = next((row for row in refusals if not agrees(row)), None)
    cases.append(("every refusal's kind is the one its own exception and message name, at its own pc",
                  bad is None, f"room {bad.get('room')}: {bad.get('kind')}/{bad.get('exception')}"
                  if bad else ""))

    ids = [x for x in no_block if isinstance(x, int)]
    cases.append(("no_block_rooms is sorted, unique, as long as its total, and holds no refused room",
                  len(ids) == len(no_block) and ids == sorted(set(ids))
                  and totals.get("no_block") == len(ids) and not (set(ids) & set(rooms)),
                  f"{len(ids)} room(s)"))

    def work_ok():
        """Every refusal in exactly one item, under its own kind, with the item's count equal to its rooms."""
        kind_of = {row.get("room"): row.get("kind") for row in refusals}
        seen = []
        for item in work:
            if item.get("kind") not in KINDS or not item.get("rooms"):
                return False
            listed = item["rooms"]
            if item.get("count") != len(listed) or listed != sorted(listed):
                return False
            if not isinstance(item.get("next_step"), str) or len(item["next_step"]) < 40:
                return False
            if any(kind_of.get(x) != item["kind"] for x in listed):
                return False
            seen += listed
        return len(seen) == len(set(seen)) and set(seen) == set(kind_of)

    cases.append(("every refusal is in exactly one work item, under its own kind, and the counts agree",
                  work_ok(), f"{len(work)} item(s)"))

    size = ARTEFACT.stat().st_size
    cases.append((f"the artefact fits the repository's {MAX_BYTES >> 20} MiB track limit",
                  size < MAX_BYTES, f"{size} B"))

    cases.append(resweep_case(doc))
    return report(cases)


def report(cases):
    """Print the cases and the tally line the gate suite keys on.

    A case may report `ok is None`, which is a SKIP: it is printed where it stands and counted in the tally,
    because the cartridge it needs is gitignored and no clone can supply it — the same rule `acceptance.py`
    applies to a whole cartridge suite. The line still says SKIP, so nobody reads the tally as its evidence.
    """
    passed = 0
    for label, ok, extra in cases:
        if ok is None:
            passed += 1
            print(f"  SKIP {label}" + (f": {extra}" if extra else ""))
            continue
        passed += bool(ok)
        print(f"  {'PASS' if ok else 'FAIL'} {label}" + ("" if ok else f": {extra}"))
    print(f"{passed}/{len(cases)} refusal case(s)")
    return 0 if passed == len(cases) else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true", help="regenerate the artefact from the cartridge")
    ap.add_argument("--check", action="store_true", help="validate the committed artefact")
    args = ap.parse_args()

    if args.write:
        return write()
    if args.check:
        return check()
    ap.error("one of --write or --check is required")


if __name__ == "__main__":
    raise SystemExit(main())
