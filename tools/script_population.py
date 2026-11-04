#!/usr/bin/env python3
"""M214: every one of the 1049 "script blocks" in exactly one category, with the evidence that put it there.

`fixtures/scd/profile.json` counts **1049 scripts**: a cart-file-table member that inflates, whose head is a
`u16` record table, whose records decode to at least four known commands (`tools/script_profile.py`, M146).
M156/M157 **refuted that as a population** — of these 1049 only **50** are named by the room table
`DAT_80131fa8`, so ~95 % of what M151–M154 analysed is not a room script. This tool replaces the refuted claim
with a partition: every candidate gets exactly one category, and the artefact records *which evidence fired*
so a reviewer can check any single line.

The categories, in the order they are tested — the first one whose evidence holds wins:

    room_table        the block IS a file id `DAT_80131fa8` names (`cfg_reach.room_script_ids()`), and the
                      artefact lists the room indices that name it. Strongest: the room loader reads exactly
                      this table.
    code_referenced   the id is materialised as a constant into an argument register of a call to the
                      cartridge's **file-table accessor**, and the instruction address is recorded. The
                      accessor is derived, not hardcoded: a routine counts when a call passes it one of the
                      five sound-family ids `tools/file_table.py` establishes are named in code (1979–1983)
                      *and* its body contains an 8-byte stride (`sll rD,rS,3`) — the width of a
                      `{offset, size}` entry.
    script_referenced reached as a script-table reference from a block already classified 1 or 2. **Empty, and
                      by mechanism**: this VM's script table is the block's own `u16[]` record table, and the
                      three opcodes that index it carry a **u8** index (`walk_stream.JUMP_FAMILY`: `0x18`
                      GoSub's operand is `u8` at byte 1), which cannot name a file id in 1..8090.
    heuristic_only    the decoder yields at least the admitting criterion's four instructions for the whole
                      block, and nothing references it.
    not_a_script      the M213 decoder (`tools/scd_vm.py`) yields fewer than the admitting criterion's four
                      instructions for the whole block, or refuses at its first byte. `first_refusal` carries
                      the decoder's own message.

**What this claims.**  A partition of the 1049 with the evidence for each, and the population numbers the
gate pins: **50 room_table, 0 code_referenced, 0 script_referenced, 485 heuristic_only, 514 not_a_script**.

**What this refuses to claim.**

  * **`heuristic_only` is not "not used".** It is "no reference found yet", under exactly three searches: the
    room table, a constant argument to the derived accessor, and the script-table operands this VM actually
    has. A reference through a data table this tool does not model would land outside all three, and the
    block would still read `heuristic_only`. The label states what was searched, not what is.
  * **`code_referenced` is not "the game loads this block".** It says a failable test found a constant with
    this value reaching the file-table accessor. A bare "the value appears as an immediate in code" scan is
    *not* used: it matches 18 of the 1049, and their contexts are a coordinate, a struct field, a draw-call
    argument or an address inside the RSP microcode the stage-2 image carries (`notes` records the addresses,
    `refused` the ids and counts). Anchoring on the accessor removes that class of error, and its five anchor
    ids are an independent result.
  * **`not_a_script` does not retract the admitting criterion.** The 1049 are still what `script_profile.py`
    admits; this tool applies the *same threshold* with the decoder that refuses instead of guessing, so a
    block can be admitted and then fail. Both command totals are in the artefact (102 673 walker, 34 375
    decoder) and neither replaces the other.
  * **No claim about what a block is.** A `heuristic_only` block is not thereby an unidentified format, and a
    `not_a_script` block is not thereby data: M158 already read the room table as a scene → resource table.
  * **No bytes.** The artefact stores file ids, addresses, counts and refusal messages — statistics about the
    population, never the scripts.

Usage:
  ./script_population.py                 # the report, for a human
  ./script_population.py --write         # derive and write manifests/script_population.json
  ./script_population.py --check         # the gate: the committed artefact against a fresh derivation

The cartridge is the owner's own dump and is gitignored; without it this reports SKIP, like the other
cartridge-gated suites.
"""
import argparse
import hashlib
import json
import struct
import sys
import zlib
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import build_images                                          # noqa: E402  the boot bank's extent, one place
import cfg_reach                                             # noqa: E402
import scd_vm                                                # noqa: E402
import script_profile as sp                                  # noqa: E402
import walk_stream as ws                                     # noqa: E402

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
ROM = sp.ROM                                                 # the same cartridge path as the other suites
OVERLAY_TABLE = ROOT / "manifests" / "overlay_table.json"    # what load address the table assigns
CODE_CENSUS = ROOT / "manifests" / "code_census.json"        # which members contain code
PROFILE = ROOT / "fixtures" / "scd" / "profile.json"         # the claim this artefact replaces
OUT = ROOT / "manifests" / "script_population.json"

SCHEMA = "script-population/1"
TOOL = "tools/script_population.py"
CATEGORIES = ("room_table", "code_referenced", "script_referenced", "heuristic_only", "not_a_script")

ARG_REGS = (4, 5, 6, 7)          # a0..a3: where a call's constant arguments are materialised
SETUP_WINDOW = 8                 # instructions before a call whose writes may still be that call's argument
STRIDE_SHIFT = 3                 # a file-table entry is {offset, size}, so the accessor scales the id by 8
BODY_WINDOW = 0x80               # words of an accessor's body searched for that stride
# The five ids `tools/file_table.py:24-27` establishes are named in code: `SND_PROJ`/`POOL`/`SMPDIR` =
# 1980/1981/1982, framed by the two files they tile (1979, 1983). This is the anchor the accessor derivation
# rests on, and it is an *independent* result — nothing here derives it, and nothing here may re-derive it.
ANCHOR_IDS = (1979, 1980, 1981, 1982, 1983)
SIZE_LIMIT = 4 << 20             # the artefact must stay reviewable


# ----------------------------------------------------------------------------------------------------------
# the candidates: script_profile's criterion, re-applied


def candidates(rom: bytes, res: dict) -> dict:
    """file id -> {raw, offsets, walker_commands} for exactly the blocks `script_profile.py` calls scripts.

    The test is `script_profile.sweep`'s, unchanged and restated in one place: the entry is not a sentinel, its
    payload inflates, the block is at least 8 B, and `walk_block` decodes at least `MIN_COMMANDS` commands over
    at least two record offsets. Importing that walker rather than re-implementing it is the point — this tool
    must not drift from the criterion it classifies, so `--check` asserts the count and the walker's command
    total against the committed profile.
    """
    out = {}
    for idx in range(sp.ENTRY_COUNT):
        off, size = struct.unpack_from(">II", rom, sp.FILE_TABLE_ROM + sp.HEADER + 8 * idx)
        if off == 0xFFFFFFFF or size == 0:
            continue
        try:
            raw = zlib.decompress(rom[sp.FILE_TABLE_ROM + off:sp.FILE_TABLE_ROM + off + size])
        except zlib.error:
            continue
        if len(raw) < 8:
            continue
        decoded, offsets = sp.walk_block(raw, res, 0)
        if sum(len(r) for r in decoded) < sp.MIN_COMMANDS or len(offsets) < 2:
            continue
        out[idx] = {"raw": raw, "offsets": offsets, "walker_commands": sum(len(r) for r in decoded)}
    return out


def decode(block: dict, reg: dict) -> dict:
    """The M213 decoder over the block's record table -> commands, first refusal, stop histogram.

    Each record is decoded in its own window (its start to the next record's start), which is the decoder's
    honest difference from the linear walker: a command that runs off its record is a truncated instruction,
    not a read into the neighbour. `strict=False` is the real-room mode — a refusal ends *that record* and the
    steps before it are kept, so one byte the table cannot explain does not hide the other records.
    """
    table = scd_vm.OffsetTable(block["offsets"])
    commands, first = 0, None
    stops = Counter()
    for i, start in enumerate(block["offsets"]):
        end = block["offsets"][i + 1] if i + 1 < len(block["offsets"]) else len(block["raw"])
        trace = scd_vm.trace_record(scd_vm.Reader(block["raw"], start, end), start,
                                    reg=reg, table=table, strict=False)
        commands += len(trace["steps"])
        stops[stop_kind(trace["stop"])] += 1
        if first is None and trace["stop"].startswith("refused at "):
            first = trace["stop"].split(": ", 1)[1]          # the decoder's message, without its prefix
    return {"commands": commands, "first_refusal": first, "stops": stops}


def stop_kind(stop: str) -> str:
    """"refused at 0x140: truncated instruction at 0x140: …" -> "refused:truncated"; "yield: …" -> "yield"."""
    if stop.startswith("refused at "):
        return "refused:" + stop.split(": ", 1)[1].split(" ")[0]
    return stop.split(":")[0]


# ----------------------------------------------------------------------------------------------------------
# the room table, read from the cartridge


def room_table(rom: bytes) -> list:
    """`DAT_80131fa8[room]` for all 256 entries, through the M213 decoder's own route to the stage-2 image.

    The bound is 256 because the index is a single byte (`M157`, `*(byte *)(DAT_800dfb58 + 0xc)`), so no entry
    past 255 can ever be selected. This route needs only the cartridge; `cfg_reach.room_script_ids()` reads
    the same table out of `assets/unpacked/`, and `--check` asserts the two agree — two routes, one table.
    """
    image = scd_vm.stage2_image(rom)
    return [scd_vm.room_file_id(image, room) for room in range(cfg_reach.ROOM_TABLE_MAX)]


# ----------------------------------------------------------------------------------------------------------
# the code images, and the file-table accessor they are searched for


def code_images(rom: bytes) -> list:
    """Every image that holds code: the boot bank from ROM, then each census member at its cart load address.

    The list is the committed pair `manifests/code_census.json` × `manifests/overlay_table.json` — the cross
    `build_images.py` uses, so this scan and the ELFs the decompiler sees cannot disagree about what counts as
    code. The bytes come from the cartridge, so no generated directory is needed.
    """
    code_roms = {int(r["rom"], 16) for r in json.loads(CODE_CENSUS.read_text())["code"]}
    boot = build_images.BOOT
    images = [{"name": boot["name"], "base": boot["base"],
               "words": words_of(rom[boot["rom"]:boot["rom"] + boot["length"]])}]
    seen = set()
    for record in json.loads(OVERLAY_TABLE.read_text())["records"]:
        if not record["stored"] or record["cart"] not in code_roms or record["cart"] in seen:
            continue
        seen.add(record["cart"])
        d = zlib.decompressobj()
        data = d.decompress(rom[record["cart"]:record["cart"] + (8 << 20)]) + d.flush()
        if not d.eof:
            raise ValueError(f"cart {record['cart']:#09x}: no complete zlib member")
        images.append({"name": f"ovl_{record['cart']:07x}", "base": record["vram_start"],
                       "words": words_of(data[:record["decompressed"]])})
    return images


def words_of(data: bytes) -> tuple:
    n = len(data) // 4
    return struct.unpack(f">{n}I", data[:n * 4])


def written_reg(word: int):
    """The general-purpose register an instruction writes, or None.

    Only what the argument scan needs: R-type writes `rd` (except `jr`/`jalr`/`syscall`/`break`, which leave
    the register alone), stores and branches write no register, and the coprocessor formats address a
    different register file. A miss here costs precision, not correctness: an unnoticed write can only make
    the scan attribute an older constant to a call.
    """
    op = word >> 26
    if op == 0:
        if (word & 0x3F) in (0x08, 0x09, 0x0C, 0x0D):
            return None
        return (word >> 11) & 0x1F
    if op in (0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x28, 0x29, 0x2B, 0x2F):
        return None
    if op in (0x10, 0x11, 0x12):
        return None
    return (word >> 16) & 0x1F


def constant_materialised(word: int):
    """`li rt, N` -> N, or None: `addiu`/`ori` from `$zero` with a non-negative 16-bit immediate."""
    if (word >> 26) not in (0x09, 0x0D) or ((word >> 21) & 0x1F) != 0:
        return None
    imm = word & 0xFFFF
    return None if imm & 0x8000 else imm


def argument_constants(image: dict, index: int) -> dict:
    """The constants the call at `index` receives in a0..a3, by walking each register back to its last write.

    A call's arguments are what those registers held at the branch, so the value is the *last* write — searched
    in the delay slot first (it executes before the callee reads the register) and then backwards. The scan
    stops at that write: an earlier `li` into the same register is not this call's argument.
    """
    words, base, found = image["words"], image["base"], {}
    for reg in ARG_REGS:
        for step in [index + 1] + [index - k for k in range(1, SETUP_WINDOW + 1)]:
            if not 0 <= step < len(words):
                continue
            word = words[step]
            if written_reg(word) != reg:
                continue
            value = constant_materialised(word)
            if value is not None:
                found[reg] = {"value": value, "pc": base + 4 * step}
            break
    return found


def call_sites(images: list) -> list:
    """Every call whose argument register provably holds a constant.

    -> [{callee, call, image, pc, register, value}], where `pc` is the materialisation the argument scan found.
    """
    sites = []
    for image in images:
        words, base = image["words"], image["base"]
        for index, word in enumerate(words):
            if word >> 26 != 0x03:                       # jal
                continue
            callee = ((word & 0x3FFFFFF) << 2) | 0x80000000
            for reg, const in argument_constants(image, index).items():
                sites.append({"callee": callee, "call": base + 4 * index, "image": image["name"],
                              "pc": const["pc"], "register": f"a{reg - 4}", "value": const["value"]})
    return sites


def stride_in_body(images: list, entry: int):
    """(image, address) of the first `sll rD,rS,3` in the routine at `entry`, or (None, None)."""
    for image in images:
        base, words = image["base"], image["words"]
        if not base <= entry < base + 4 * len(words):
            continue
        start = (entry - base) // 4
        for index in range(start, min(len(words), start + BODY_WINDOW)):
            word = words[index]
            if word >> 26 == 0 and (word & 0x3F) == 0x00 and ((word >> 6) & 0x1F) == STRIDE_SHIFT:
                return image["name"], base + 4 * index
        return image["name"], None
    return None, None


def archive_accessors(images: list, sites: list) -> dict:
    """The routines that index the cartridge file table — derived, not hardcoded.

    A callee counts only if (a) some call passes it one of `ANCHOR_IDS`, the five ids `file_table.py`
    establishes are named in code, and (b) its own body scales an index by 8, the width of a `{offset, size}`
    entry. Both halves matter: the anchors say *which* routine family the sound init hands file ids to, and
    the stride says the routine reads that table rather than drawing with the number.

    Corroboration a reviewer can check by hand, not part of the test: the function at `0x80004954` — the one
    behind the first accessor — calls `FUN_80001180` with `a0 = 0x43`, then stores `count*8 + 0x28` into
    `0x80012874`, the global the accessor loads as its table base. Record `0x43` and a `0x28` header are
    exactly the file table `script_profile.py` walks. The anchors also arrive in `a0` up to six instructions
    before their `jal`, which is why the setup window is eight and not two.

    A fourth accessor that no anchor id ever reaches would not be recognised. That limit is real, and it is
    why `heuristic_only` means "no reference found yet" — see the module docstring.
    """
    out = {}
    for site in sites:
        if site["value"] not in ANCHOR_IDS:
            continue
        name, stride = stride_in_body(images, site["callee"])
        if stride is None:
            continue
        entry = out.setdefault(site["callee"], {"image": name, "stride": stride, "anchors": []})
        if site["value"] not in entry["anchors"]:
            entry["anchors"].append(site["value"])
    for entry in out.values():
        entry["anchors"].sort()
    return dict(sorted(out.items()))


def code_references(sites: list, accessors: dict) -> dict:
    """id -> the sites that pass it to an accessor, so the artefact can carry the instruction address."""
    out = {}
    for site in sites:
        if site["callee"] in accessors:
            out.setdefault(site["value"], []).append(site)
    for value in out:
        out[value].sort(key=lambda s: (s["image"], s["pc"]))
    return out


# ----------------------------------------------------------------------------------------------------------
# the refused alternative, kept as a measurement rather than an argument


def immediate_sites(images: list, ids: set) -> dict:
    """id -> the instructions that materialise it as a constant, anywhere in code.

    This is the scan category 2 **does not** use, kept because refusing it is the whole argument for the
    accessor anchor: it cannot tell a file id from a coordinate, and `--check` proves the anchor filters.
    """
    out = {}
    for image in images:
        for index, word in enumerate(image["words"]):
            value = constant_materialised(word)
            if value in ids:
                out.setdefault(value, []).append((image["name"], image["base"] + 4 * index))
    return out


def raw_word_matches(blocks: dict, classified: list, candidate_ids: set) -> Counter:
    """Every byte-aligned `u16` of the classified blocks that equals another candidate's file id.

    This is the appeal of "the id appears as a word in script data", measured so that refusing it is a number
    instead of a shrug. It is **not** used to classify: the registry has no field map for 129 of its 141
    opcodes (`scd_vm.decode_one`'s refusal), so nothing here can tell an operand that names a resource from the
    coordinate, angle or mask that shares its bits.
    """
    hits = Counter()
    for file_id in classified:
        raw = blocks[file_id]["raw"]
        for pc in range(len(raw) - 1):
            value = struct.unpack_from(">H", raw, pc)[0]
            if value in candidate_ids and value != file_id:
                hits[value] += 1
    return hits


def script_references() -> dict:
    """Inter-file script-table references: none can exist, and the reason is a constant of the VM.

    This VM's script table is the block's **own** `u16[]` record table — `FUN_8006d5dc(ctx, index)` reads
    `u16[index]` from the block it was handed — and the three opcodes that index it carry a one-byte index
    (`walk_stream.JUMP_FAMILY`: `0x18` GoSub's operand is `u8` at byte 1; `0x03`'s index is byte 3; `0x19`
    pops the slot `0x18` saved at `ctx+0x144`). A `u8` cannot name a file id in 1..8090, so the mechanism
    cannot express a reference to another block, and this search returns nothing *for a reason `--check`
    asserts*: widen GoSub's operand and the case fails, which is when this category has to be re-derived.
    """
    return {}


# ----------------------------------------------------------------------------------------------------------
# the derivation


def derive(rom: bytes) -> dict:
    """The artefact alone. `analyse` carries the intermediates the gate asserts against."""
    return analyse(rom)[0]


def analyse(rom: bytes) -> tuple:
    """(the artefact, the intermediates it was built from).

    The gate needs both: the document is checked against the same derivation it came from (internal
    consistency) *and* against independent routes (the room table read out of the cartridge versus
    `cfg_reach.room_script_ids()` out of the unpacked asset), so `--check` derives once and asserts twice.
    """
    res = ws.resolve(ws.load_stage2())
    reg = scd_vm.registry()
    profile = json.loads(PROFILE.read_text())

    blocks = candidates(rom, res)
    table = room_table(rom)
    rooms = cfg_reach.room_script_ids()
    images = code_images(rom)
    sites = call_sites(images)
    accessors = archive_accessors(images, sites)
    references = code_references(sites, accessors)
    script_refs = script_references()
    instructions = sum(len(i["words"]) for i in images)
    # The blocks that were classified before `heuristic_only` is reached: the search space of category 3.
    seeds = len(set(blocks) & (set(rooms) | set(references)))

    population, stops = [], Counter()
    for file_id in sorted(blocks):
        block = blocks[file_id]
        decoded = decode(block, reg)
        stops.update(decoded["stops"])
        row = {"file_id": file_id, "records": len(block["offsets"]), "commands": decoded["commands"],
               "first_refusal": decoded["first_refusal"]}
        if file_id in rooms:
            row["category"] = "room_table"
            row["evidence"] = {"table": "DAT_80131fa8", "table_va": f"{cfg_reach.ROOM_TABLE:#010x}",
                               "rooms": [i for i, value in enumerate(table) if value == file_id],
                               "source": "tools/cfg_reach.py:room_script_ids()"}
        elif file_id in references:
            row["category"] = "code_referenced"
            row["evidence"] = {"sites": [{"image": s["image"], "materialisation": f"{s['pc']:#010x}",
                                          "value": s["value"], "register": s["register"],
                                          "call": f"{s['call']:#010x}",
                                          "accessor": f"{s['callee']:#010x}",
                                          "accessor_stride": f"{accessors[s['callee']]['stride']:#010x}"}
                                         for s in references[file_id]]}
        elif file_id in script_refs:
            row["category"] = "script_referenced"
            row["evidence"] = script_refs[file_id]
        elif decoded["commands"] >= sp.MIN_COMMANDS:
            row["category"] = "heuristic_only"
            row["evidence"] = {"room_table_entries": len(table), "code_images": len(images),
                               "code_instructions": instructions, "classified_blocks": seeds,
                               "found": "none"}
        else:
            row["category"] = "not_a_script"
            row["evidence"] = {"decoder": "tools/scd_vm.py", "threshold": sp.MIN_COMMANDS,
                               "decoded": decoded["commands"],
                               "raised_at_first_byte": decoded["commands"] == 0}
        population.append(row)

    by_category = Counter(row["category"] for row in population)
    matched = raw_word_matches(blocks, [r["file_id"] for r in population if r["category"] == "room_table"],
                               set(blocks))
    bare = immediate_sites(images, set(blocks))
    doc = {
        "tool": TOOL,
        "schema": SCHEMA,
        "criterion": criterion(),
        "inputs": inputs(rom, profile, table, images, accessors, sites, res),
        "totals": {
            "candidates": len(population),
            "by_category": {name: by_category.get(name, 0) for name in CATEGORIES},
            "records": sum(row["records"] for row in population),
            "commands": sum(row["commands"] for row in population),
        },
        "decoder": {"refusals": {k.split(":", 1)[1]: v for k, v in sorted(stops.items())
                                 if k.startswith("refused:")},
                    "stops": {k: v for k, v in sorted(stops.items()) if not k.startswith("refused:")},
                    "blocks_with_a_refusal": sum(1 for row in population if row["first_refusal"])},
        "refused": {"script_referenced_by_raw_u16": {
                        "matched_ids": len(matched),
                        "matches": sum(matched.values()),
                        "top": [[value, count] for value, count in matched.most_common(4)],
                        "why": ("a u16 equal to a file id inside script data is not a reference: the registry "
                                "has no field map for 129 of its 141 opcodes, so an operand that names a "
                                "resource cannot be told from a coordinate, angle or mask that shares its "
                                "bits. Room-table blocks, byte-aligned u16s.")},
                    "code_referenced_by_bare_immediate": {
                        "matched_ids": len(bare),
                        "instructions": sum(len(v) for v in bare.values()),
                        "ids": [[value, len(v)] for value, v in sorted(bare.items())],
                        "why": ("the value appearing as a constant in code is not a reference: every one of "
                                "these reads as a coordinate, a struct field, a draw-call argument or an "
                                "address inside the RSP microcode the stage-2 image carries. Only a constant "
                                "that reaches the derived file-table accessor is accepted, which is why this "
                                "scan is recorded and not used.")}},
        "population": population,
        "notes": notes(sites, accessors, rooms, blocks, bare),
        "unresolved_notes": unresolved(by_category),
    }
    return doc, {"blocks": blocks, "table": table, "rooms": rooms, "images": images, "sites": sites,
                 "accessors": accessors, "references": references, "profile": profile, "bare": bare}


def criterion() -> dict:
    return {
        "candidates": ("the 1049 blocks `tools/script_profile.py` admits (M146): among the 8091 {offset,size} "
                       "entries at cart 0x0c8624 + 0x28, a member that inflates, is at least 8 B, whose head is "
                       "a u16 record table of at least two entries, and whose records decode to at least "
                       "MIN_COMMANDS (4) known commands. Reproduced here by importing script_profile.walk_block "
                       "and applying that test unchanged; fixtures/scd/profile.json is the citation, and "
                       "--check asserts the reproduction (1049 scripts, 5111 records, 102673 walker commands)."),
        "order": list(CATEGORIES),
        "order_rule": ("the first category whose evidence holds wins, in the order above. A block named by the "
                       "room table is therefore room_table even if the decoder then refuses part of it; that "
                       "refusal is still recorded in its first_refusal."),
        "categories": {
            "room_table": ("the file id is an entry of DAT_80131fa8, the table the room loader reads; the "
                           "artefact lists the room indices that name it."),
            "code_referenced": ("the id is materialised as a constant into an argument register of a call to "
                                "the cartridge's file-table accessor, derived from file_table.py's five "
                                "sound-family ids plus an 8-byte stride in the accessor's body. The "
                                "instruction address is recorded."),
            "script_referenced": ("a script-table reference from a block already classified 1 or 2. Empty by "
                                  "mechanism: the index is u8 into the block's own u16[] record table."),
            "heuristic_only": "the block decodes to >= 4 instructions and no search found a reference to it.",
            "not_a_script": ("the M213 decoder yields fewer than 4 instructions for the whole block, or refuses "
                             "at its first byte; first_refusal carries the decoder's own message."),
        },
        "counts": ("records = u16 record-table entries per block (the admitting criterion's own enumeration, so "
                   "the total is the profile's 5111). commands = instructions the M213 decoder actually decoded, "
                   "fewer than the linear walker's 102673 because every record is bounded by its own end and a "
                   "refusal ends a record instead of guessing past it."),
    }


def inputs(rom: bytes, profile: dict, table: list, images: list, accessors: dict, sites: list,
           res: dict) -> dict:
    return {
        "cartridge": {"path": str(ROM.relative_to(ROOT)), "bytes": len(rom),
                      "sha256": hashlib.sha256(rom).hexdigest()},
        "profile": {"path": str(PROFILE.relative_to(ROOT)), "scripts": profile["scripts"],
                    "records": profile["records"], "commands": profile["commands"],
                    "note": "the claim M156/M157 refuted as a population; this artefact classifies it"},
        "room_table": {"table_va": f"{cfg_reach.ROOM_TABLE:#010x}", "entries": len(table),
                       "distinct_ids": len({v for v in table if v}),
                       "source": "tools/cfg_reach.py:room_script_ids(), scd_vm.room_file_id()"},
        "decoder": {"tool": "tools/scd_vm.py", "registry": "fixtures/scd/registry.json",
                    "threshold": sp.MIN_COMMANDS, "opcodes": len(scd_vm.registry())},
        "script_profile": {"tool": "tools/script_profile.py", "walker": "tools/walk_stream.py",
                           "opcodes_resolved": len(res)},
        "code": {"census": str(CODE_CENSUS.relative_to(ROOT)),
                 "overlay_table": str(OVERLAY_TABLE.relative_to(ROOT)),
                 "images": len(images), "instructions": sum(len(i["words"]) for i in images),
                 "constant_argument_calls": len(sites)},
        "accessor_derivation": {"anchors": list(ANCHOR_IDS), "anchor_source": "tools/file_table.py:24-27",
                                "stride_shift": STRIDE_SHIFT, "body_window": BODY_WINDOW,
                                "found": [{"entry": f"{entry:#010x}", "image": a["image"],
                                           "stride": f"{a['stride']:#010x}", "anchors": a["anchors"]}
                                          for entry, a in accessors.items()]},
    }


def notes(sites: list, accessors: dict, rooms: set, blocks: dict, bare: dict) -> list:
    """Everything a reviewer needs in order not to over-read the categories."""
    reached = [s for s in sites if s["value"] in blocks]
    return [
        "heuristic_only is not 'not used'; it is 'no reference found yet'. The three searches are the room "
        "table (256 entries), a constant argument to a derived file-table accessor, and the script-table "
        "operands this VM has. A reference through a data table this tool does not model lands outside all "
        "three and still reads heuristic_only.",
        "The accessor set is derived, not hardcoded: %s. Each was accepted because a call passes it one of the "
        "five sound-family ids file_table.py established AND its body contains the 8-byte stride that indexes "
        "a {offset,size} entry. Corroboration, not part of the test: the init behind the first accessor "
        "(0x80004954) reads cart record 0x43 and stores count*8 + 0x28 into the global that accessor loads as "
        "its table base - this population's own table. A fourth accessor that no anchor id reaches would not "
        "be recognised."
        % ", ".join(f"{entry:#010x} (anchors {a['anchors']}, stride {a['stride']:#010x})"
                    for entry, a in accessors.items()),
        "A bare 'the value appears as a constant in code' scan was run and REFUSED as evidence: %d of the 1049 "
        "have such an immediate, in %d instruction(s), and their contexts are coordinates, struct fields, "
        "draw-call arguments or RSP microcode data - 1900 is stored by `sh v0,368(s0)` beside 950 and 3000 at "
        "0x801621e4 (and 1900 is a room id, so this coincidence would have been invisible), 7120 and 7096 are "
        "coordinates loaded into a0 at 0x8016cdb0 and 0x80166a84 beside stack arrays of positions, 7520 is "
        "added to a struct pointer as a byte offset at 0x8016228c, and 3512/3552 sit in a stage-2 region whose "
        "`jal` targets are 0x84xxxxxx - RSP instruction memory, not MIPS code. Their ids and counts are in "
        "refused.code_referenced_by_bare_immediate, and --check asserts the anchor filters."
        % (len(bare), sum(len(v) for v in bare.values())),
        "%d of the 1049 reach some call's argument register, across %d call site(s): %s. None reaches an "
        "accessor, so each stays heuristic_only with the call recorded here rather than promoted on an "
        "adjacency."
        % (len({s['value'] for s in reached}), len(reached),
           "; ".join(f"{s['value']} -> {s['callee']:#010x} from {s['image']}@{s['pc']:#010x}" for s in
                     sorted(reached, key=lambda s: (s["value"], s["call"], s["image"])))
           if reached else "none"),
        "The room table names %d distinct ids and %d of them are among the 1049. The rest cannot appear here at "
        "all: M158 read 48 as the 32-byte `01 41` container family, 43 as other resources and 6 as not zlib — "
        "which is why the room-script population is 50 and not 147."
        % (len(rooms), len(rooms & set(blocks))),
        "totals.commands is the M213 decoder's count over the same 5111 records; it is smaller than the "
        "profile's 102673 because the decoder bounds every record by its own end and stops at a refusal, where "
        "the linear walker keeps advancing through the block. The difference is the decoder's honesty, "
        "itemised per block in first_refusal and in decoder.refusals.",
        "script_referenced is an empty category, not an unfilled one: no search result could have put a block "
        "there, because the index is a u8 into the block's own u16[] record table (`--check` asserts exactly "
        "that). The measurement a looser rule would have produced is in `refused`, so the empty category is "
        "reviewable rather than merely empty.",
    ]


def unresolved(by_category: Counter) -> list:
    return [
        "No candidate is unclassified: all %d have exactly one category. What is unresolved is the reference "
        "question for the %d heuristic_only blocks — their evidence is the absence of a reference under three "
        "searches, which is not a proof of disuse."
        % (sum(by_category.values()), by_category.get("heuristic_only", 0)),
        "A reference by DATA rather than by code is not modelled. The `01 41` container's payload is a "
        "scene -> resource list (M158) and is not parsed here; a candidate id listed in one would be a real "
        "reference this tool would miss, and the block would still read heuristic_only.",
        "script_referenced is empty for a mechanical reason (a u8 index into the block's own u16[] table), "
        "which --check asserts. If `walk_stream.JUMP_FAMILY`'s GoSub operand ever widens, that case fails and "
        "the category must be re-derived: it is not an empirical zero that can be trusted forever.",
        "The accessor derivation is anchored on five ids from a sound-init reading (M178). An accessor reached "
        "only by ids outside that family would be invisible to it, so code_referenced is a lower bound: 0 is "
        "'none found by this test', not 'none exists'.",
    ]


def render(doc: dict) -> str:
    """The artefact's bytes. Sorted keys so two runs cannot differ in key order; population stays id-ordered."""
    return json.dumps(doc, indent=1, sort_keys=True) + "\n"


# ----------------------------------------------------------------------------------------------------------
# the gate


def check() -> int:
    if not ROM.exists():
        print(f"SKIP: no cartridge at {ROM.relative_to(ROOT)}")
        return 0
    try:
        doc, ctx = analyse(ROM.read_bytes())
    except (OSError, ValueError, KeyError) as exc:
        print(f"  FAIL the derivation runs: {exc}")
        print("0/1 population case(s)")
        return 1

    profile, blocks, rooms = ctx["profile"], ctx["blocks"], ctx["rooms"]
    table, accessors, references = ctx["table"], ctx["accessors"], ctx["references"]
    population = doc["population"]
    by_category = doc["totals"]["by_category"]
    counts = Counter(row["category"] for row in population)
    carved = [row for row in population if row["category"] == "not_a_script"]
    walker = sum(block["walker_commands"] for block in blocks.values())
    sampled = sum(len(block["offsets"]) for block in blocks.values())

    cases = []

    def case(label, ok, detail=""):
        cases.append(("PASS" if ok else "FAIL", label, detail))

    def skip(label, reason):
        cases.append(("SKIP", label, reason))

    # 1. the admitting criterion, reproduced rather than trusted
    case("the admitting criterion reproduces fixtures/scd/profile.json: %d candidates, %d records, "
         "%d walker commands" % (len(blocks), sampled, walker),
         (len(blocks), sampled, walker, len(population), doc["totals"]["records"])
         == (profile["scripts"], profile["records"], profile["commands"], profile["scripts"],
             profile["records"]),
         "got %d candidates / %d records / %d commands, profile says %d / %d / %d"
         % (len(blocks), sampled, walker, profile["scripts"], profile["records"], profile["commands"]))

    # 2. exactly one category per candidate
    ids = [row["file_id"] for row in population]
    case("every candidate appears exactly once, with one category from the ladder",
         len(ids) == len(set(ids)) == len(blocks) and set(ids) == set(blocks)
         and all(row["category"] in CATEGORIES for row in population),
         "%d rows, %d unique, %d candidates" % (len(ids), len(set(ids)), len(blocks)))

    # 3. the lists and the counts agree. (Key order in the file is alphabetical — `render` sorts keys so two
    #    runs cannot differ — so the ladder's own order is `criterion.order`, asserted as a set here.)
    case("each by_category count matches the population list, over exactly the five categories",
         {name: counts.get(name, 0) for name in CATEGORIES} == by_category
         and sum(by_category.values()) == doc["totals"]["candidates"]
         and set(by_category) == set(CATEGORIES) == set(doc["criterion"]["order"]),
         f"list {dict(counts)} vs totals {by_category}")

    # 4. category 1 is what the room table says, by two routes
    named = {row["file_id"] for row in population if row["category"] == "room_table"}
    case("room_table is a subset of room_script_ids(), and it is the 50 M156/M158 established",
         named <= rooms and len(named) == 50
         and {v for v in table if v} == rooms,
         "%d named, %d room ids, table-vs-cfg_reach %s"
         % (len(named), len(rooms), "agree" if {v for v in table if v} == rooms else "DISAGREE"))

    # 5. every room_table row carries the indices that name it
    case("every room_table entry carries the room indices that name it, read from the cartridge",
         all(row["evidence"]["rooms"] and all(table[i] == row["file_id"] for i in row["evidence"]["rooms"])
             for row in population if row["category"] == "room_table"),
         "a listed room index does not hold its entry's file id")

    # 6. code_referenced carries instruction addresses, and re-derives
    code_rows = [row for row in population if row["category"] == "code_referenced"]
    case("every code_referenced entry carries an instruction address that re-derives from the scan "
         "(%d entry/entries)" % len(code_rows),
         all(site["materialisation"].startswith("0x") and site["accessor"] in
             {f"{entry:#010x}" for entry in accessors}
             and row["file_id"] in references for row in code_rows for site in row["evidence"]["sites"])
         and {row["file_id"] for row in code_rows} == set(references) & set(blocks),
         "a code_referenced row lacks an address, names no accessor, or was not detected")

    # 7. the scan that produces category 2 is not blind
    case("the code scan is not blind: the five sound ids file_table.py named reach accessors %s, each with "
         "an 8-byte stride" % ", ".join(f"{entry:#010x}" for entry in accessors),
         len(accessors) == 3 and sorted(ANCHOR_IDS) == sorted(
             {a for entry in accessors.values() for a in entry["anchors"]})
         and all(entry["stride"] for entry in accessors.values()),
         f"{len(accessors)} accessor(s), anchors "
         f"{sorted({a for entry in accessors.values() for a in entry['anchors']})}")

    # 8. category 3 is empty by mechanism, and the mechanism is asserted
    gosub = ws.JUMP_FAMILY[cfg_reach.SUBCALL]["operand"]
    case("script_referenced is empty and stays empty by mechanism: GoSub's script-table index is %s at byte "
         "%d, and %#04x returns through the slot it saved"
         % (gosub[0], gosub[1], cfg_reach.SUBRET),
         all(row["category"] != "script_referenced" for row in population)
         and gosub[0] == "u8" and cfg_reach.SUBCALL == 0x18 and cfg_reach.SUBRET == 0x19,
         f"GoSub operand is {gosub}, subcall {cfg_reach.SUBCALL:#04x}")

    # 9. category 5 is the decoder's own verdict, and it is always reported with its reason
    case("every not_a_script entry decodes fewer than %d instructions AND carries the decoder's own refusal "
         "(%d raise at the first byte)" % (sp.MIN_COMMANDS, sum(1 for row in carved
                                                               if row["evidence"]["raised_at_first_byte"])),
         carved and all(row["commands"] < sp.MIN_COMMANDS and row["first_refusal"] and
                        row["evidence"]["threshold"] == sp.MIN_COMMANDS for row in carved)
         and sum(1 for row in carved if row["evidence"]["raised_at_first_byte"]) ==
         sum(1 for row in carved if row["commands"] == 0),
         f"{len(carved)} entry/entries")

    # 10. the two decoders' totals are both present and ordered
    case("the decoder decodes strictly fewer commands than the linear walker over the same records, and both "
         "totals are recorded",
         doc["totals"]["commands"] < profile["commands"] and doc["totals"]["records"] == profile["records"]
         and doc["inputs"]["profile"]["commands"] == profile["commands"],
         "decoder %d vs walker %d" % (doc["totals"]["commands"], profile["commands"]))

    # 11. the threshold is script_profile's, not a second number
    case("the not_a_script threshold is script_profile.MIN_COMMANDS (%d), not a second constant"
         % sp.MIN_COMMANDS,
         doc["criterion"]["categories"] and doc["inputs"]["decoder"]["threshold"] == sp.MIN_COMMANDS
         and len({row["evidence"].get("threshold", sp.MIN_COMMANDS) for row in carved}) == 1,
         "threshold disagree with script_profile")

    # 12. the anchor is load-bearing: the scan it replaces matches strictly more ids, and the accessor test
    #     is what removes them. Without this the accessor could be decoration and category 2 empty for free.
    bare = ctx["bare"]
    reaching = {s["value"] for s in ctx["sites"] if s["value"] in ctx["blocks"]}
    case("the accessor anchor is load-bearing: the refused bare-immediate scan matches %d ids, %d reach a call "
         "argument, and %d reach an accessor" % (len(bare), len(reaching),
                                                len(set(ctx["references"]) & set(ctx["blocks"]))),
         len(bare) > 0 and len(reaching) < len(bare)
         and set(ctx["references"]) & set(ctx["blocks"]) <= reaching,
         f"bare {len(bare)}, via call {len(reaching)}")

    # 13. the committed artefact is a fresh derivation, byte for byte
    fresh = render(doc)
    try:
        committed = OUT.read_text()
    except OSError as exc:
        skip("the committed artefact equals a fresh derivation", f"{OUT.name} is absent: {exc}")
    else:
        case("the committed artefact equals a fresh derivation, byte for byte, and stays under 4 MiB",
             committed == fresh and len(committed) < SIZE_LIMIT,
             f"committed {len(committed)} B, fresh {len(fresh)} B"
             + ("" if committed == fresh else ", and they differ — run --write"))

    return _report(cases)


def _report(cases: list) -> int:
    """Print the cases and the tally line the gate suite keys on."""
    passed = sum(1 for verdict, _label, _detail in cases if verdict == "PASS")
    skipped = [reason for verdict, _label, reason in cases if verdict == "SKIP"]
    for verdict, label, detail in cases:
        print("  %s %s%s" % (verdict, label, "" if verdict == "PASS" else ": " + detail))
    if skipped:
        print("  %d case(s) skipped: %s" % (len(skipped), skipped[0]))
    print("%d/%d population case(s)" % (passed, len(cases)))
    return 1 if any(verdict == "FAIL" for verdict, _label, _detail in cases) else 0


# ----------------------------------------------------------------------------------------------------------
# the report for a human


def report(doc: dict) -> None:
    totals = doc["totals"]
    print(f"candidates {totals['candidates']}  records {totals['records']}  "
          f"decoded commands {totals['commands']}")
    print("categories: " + "  ".join(f"{name} {count}" for name, count in totals["by_category"].items()))
    print(f"\nthe room table names {doc['inputs']['room_table']['distinct_ids']} ids, of which "
          f"{totals['by_category']['room_table']} are script blocks — M156's ~95 % stands: "
          f"{100 * (1 - totals['by_category']['room_table'] / max(1, totals['candidates'])):.1f} % of this "
          f"population is not a room script")
    print(f"\nfile-table accessors derived: "
          + ", ".join(f"{row['entry']} (anchors {row['anchors']}, stride {row['stride']})"
                      for row in doc["inputs"]["accessor_derivation"]["found"]))
    print(f"decoder refusals: " + (", ".join(f"{k} {v}" for k, v in doc["decoder"]["refusals"].items())
                                    or "none"))
    print(f"decoder stops: " + ", ".join(f"{k} {v}" for k, v in doc["decoder"]["stops"].items()))
    refused = doc["refused"]["script_referenced_by_raw_u16"]
    bare = doc["refused"]["code_referenced_by_bare_immediate"]
    print(f"\nrefused as evidence: {refused['matched_ids']} id(s) matched by a raw u16 scan of the room "
          f"scripts ({refused['matches']} matches, top {refused['top']}), and "
          f"{bare['matched_ids']} by a bare immediate scan of the code ({bare['instructions']} instruction(s))")
    print("\nnotes:")
    for note in doc["notes"]:
        print(f"  * {note}")
    print("unresolved:")
    for note in doc["unresolved_notes"]:
        print(f"  * {note}")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true", help=f"write {OUT.relative_to(ROOT)}")
    ap.add_argument("--check", action="store_true", help="validate the committed artefact (the gate)")
    args = ap.parse_args()

    if args.check:
        return check()
    if not ROM.exists():
        print(f"SKIP: no cartridge at {ROM.relative_to(ROOT)}")
        return 0
    doc = derive(ROM.read_bytes())
    report(doc)
    if args.write:
        OUT.write_text(render(doc))
        print(f"\nwrote {OUT.relative_to(ROOT)} ({OUT.stat().st_size:,} B)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
