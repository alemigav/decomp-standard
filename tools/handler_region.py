#!/usr/bin/env python3
"""M212: where each Script VM handler's code starts and ends, read out of the stage-2 image bytes.

`fixtures/scd/registry.json` (M211) settles where each of the 141 dispatch slots sends the command pointer.
It does not settle **where the handler's code lives**, and that is what the corpus is missing: the table at
`0x80113898` resolves to 138 distinct handler addresses, 79 of which are not inside any Ghidra function body
in `fixtures/decomp/ranges.json`, so no `src/stage2/FUN_<handler>.c` exists for them and the 3 638 functions
in the corpus structurally cannot hold the VM. No Ghidra run is available, so this tool recovers what the
bytes alone prove, one record per distinct address:

  * a handler **inside** a Ghidra body takes that body's range verbatim — no second opinion about a boundary
    that a decompiler already committed to;
  * otherwise the extent is decoded forward from the handler address, word by word, to the first `jr ra` and
    its delay slot, inside a 4 096-word window that stops at the image end. The delay slot is the extent's
    last instruction, so `end` is that instruction's last byte (the same convention as
    `fixtures/decomp/ranges.json`, whose ends are inclusive) and `words` counts the pair.

An **extent is evidence, not a Ghidra function**, and `fragment` is not an entry. The three labels refuse:

  * `code_outside_body` — a frame setup at the handler address (`addiu sp,sp,-N`, N > 0), a `jr ra`, and a
    delay slot that restores that same N. Only this label could seed a new function entry in a rebuild.
  * `fragment` — a `jr ra` with no frame setup at the handler address. The extent is real; the *entry* is not
    proved, because nothing in these bytes separates a frameless dispatch arm from an interior branch target
    of the arm laid out in front of it. A fragment must not be seeded as `FUN_<address>`.
  * `unresolved` — no `jr ra` in the window, or the extent would cross into a known Ghidra body, or it would
    run past the image end. `end` stays null: this tool never invents one.

Rule 3 is read strictly, including where its own clauses collide. A handler with **no** frame setup at all is
a `fragment`, not a `code_outside_body`: "the function uses no frame" would make the label mean *every*
dispatch arm, and then the prologue would be doing no work — the one thing the classification exists to test.
The consequence is measured rather than assumed: of the 79 handlers outside every Ghidra body, **none** carries
a frame setup at its start, so `future_function_entries` is **0**. Ghidra found exactly the 59 prologue-led
handlers (each one at a body start, which is why the VM looks half-decomposed); the 79 it did not are frameless
arms reachable only through the dispatch table, invisible to a call-graph-driven discovery by construction.
What a rebuild can take from this artefact is 76 extents in which each arm's code provably starts and ends —
**regions, not functions** — and each of those extents touches no `sp` operand, so the missing prologue is the
code's shape and not a mis-parse.

Beside each fragment the artefact records two further measured facts, and neither is a claim of ownership:
`region_entry`, the nearest frame setup *behind* the arm (a bounded backward walk of at most 512 words), and
`region_entry_in_corpus`, whether `fixtures/decomp/ranges.json` already starts a function at that address. All
76 arms sit behind just **21** distinct frame setups, each within 1 280 B of its arm, and **all 21** are
addresses the corpus already starts a function at. So no fragment forces a new entry: what a rebuild needs is
longer extents for 21 functions it already has. Which of the 21 a given arm belongs to is precisely what these
bytes do not settle, and the artefact therefore states the bound and not an owner.

What it also refuses: a name for any handler (`fixtures/scd/opcodes.json` and `inferred_names.json` own
naming, M211); an extent under a `jr ra` that is not the *first* one, since a later return belongs to a
neighbour; a command length, control-flow class or scheduler effect (M211's subject); and an end for the
three handlers whose first `jr ra` sits beyond a Ghidra body boundary — the address at which they end is
exactly the open question, and a `jr ra` inside the next function is not this handler's return.

Usage:
  ./handler_region.py --write      # regenerate manifests/handler_region.json from the image and fixtures
  ./handler_region.py --check      # validate the committed artefact (byte cases SKIP without the image)
"""
import argparse
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import walk_stream

OUT = "manifests/handler_region.json"
RANGES = "fixtures/decomp/ranges.json"
INVENTORY = "fixtures/decomp/images.json"
REGISTRY = "fixtures/scd/registry.json"
WALK = "tools/walk_stream.py"
IMAGE_NAME = "stage2"

BASE = walk_stream.STAGE2_BASE
TABLE_ENTRIES = walk_stream.TABLE_ENTRIES

WINDOW_WORDS = 4096            # per-handler decode window; it can only ever shorten at the image end
JR_RA = 0x03E00008
OP_ADDIU = 0x09
SP = 29

CLASSES = ("code_outside_body", "dispatch_head", "fragment", "function_body", "unresolved")
ADDRESS = re.compile(r"0x[0-9a-f]{8}")
OPCODE = re.compile(r"0x[0-9a-f]{2}")


def _hex(addr):
    return "0x%08x" % addr


def _simm(word):
    value = word & 0xFFFF
    return value - 0x10000 if value & 0x8000 else value


def _frame_setup(word):
    """`addiu sp,sp,-N` -> N, for N > 0. The only prologue shape this image uses."""
    if (word >> 26) != OP_ADDIU or ((word >> 21) & 0x1F) != SP or ((word >> 16) & 0x1F) != SP:
        return None
    value = _simm(word)
    return -value if value < 0 else None


def _frame_restore(word):
    """`addiu sp,sp,+N` -> N, for N > 0."""
    if (word >> 26) != OP_ADDIU or ((word >> 21) & 0x1F) != SP or ((word >> 16) & 0x1F) != SP:
        return None
    value = _simm(word)
    return value if value > 0 else None


def _at(words, addr):
    """The instruction word whose bytes contain `addr`, or None outside the image.

    Extent ends are inclusive last bytes (they sit at `...3 mod 4`), so this is also the lookup for the last
    instruction of an extent.
    """
    index = (addr - BASE) // 4
    return words[index] if 0 <= index < len(words) else None


# --- inputs --------------------------------------------------------------------------------------------
def _bodies():
    """[(start, end)] of the Ghidra function bodies in stage-2, ends inclusive, ascending."""
    raw = json.loads(Path(RANGES).read_text())["images"][IMAGE_NAME]
    out = []
    for form in raw:
        start, end = ((form["start"], form["end"]) if isinstance(form, dict) else (form[0], form[1]))
        out.append((start, end))
    return sorted(out)


def _covering(addr, bodies):
    """The Ghidra body whose bytes contain `addr`, or None. Bodies are disjoint in this fixture."""
    for start, end in bodies:
        if start <= addr <= end:
            return (start, end)
        if start > addr:
            break
    return None


def _image(words):
    """The image block, cross-checked against `fixtures/decomp/images.json` rather than restated here."""
    row = [i for i in json.loads(Path(INVENTORY).read_text())["images"] if i["name"] == IMAGE_NAME]
    if not row:
        raise SystemExit("%s has no %r image" % (INVENTORY, IMAGE_NAME))
    row = row[0]
    if row["base"] != BASE or row["size"] != 4 * len(words):
        raise SystemExit("%s says %s is %d bytes at %s, the bytes are %d at %s"
                         % (INVENTORY, IMAGE_NAME, row["size"], _hex(row["base"]),
                            4 * len(words), _hex(BASE)))
    return {"name": IMAGE_NAME, "base": _hex(BASE), "size_bytes": 4 * len(words), "words": len(words)}


def _dispatch(words):
    """address -> [opcode numbers], from the table the dispatcher reads (M211's `walk_stream.resolve`)."""
    resolved = walk_stream.resolve(words)
    owners = {}
    for number, entry in resolved.items():
        owners.setdefault(entry["handler"], []).append(number)
    return {addr: sorted(numbers) for addr, numbers in owners.items()}


# --- derivation ----------------------------------------------------------------------------------------
def _terminator(handler, words):
    """(jr ra address, delay slot address, reason) — the first `jr ra` from `handler` and the slot after it."""
    start = (handler - BASE) // 4
    stop = min(start + WINDOW_WORDS, len(words))
    for index in range(start, stop):
        if words[index] != JR_RA:
            continue
        if index + 1 >= len(words):
            return None, None, ("the jr ra at %s is the last word of the image, so it has no delay slot"
                                % _hex(BASE + 4 * index))
        return BASE + 4 * index, BASE + 4 * (index + 1), None
    return None, None, ("no jr ra within %d words of %s (the window ends at %s%s)"
                        % (WINDOW_WORDS, _hex(handler), _hex(BASE + 4 * (stop - 1)),
                           ", which is the image end" if stop == len(words) else ""))


def _first_jr(handler, words):
    """(address, delay slot, kind, reason): the first `jr` of *any* kind from the handler.

    M229: `_terminator` looked only for `jr ra`, so a handler that dispatches through a table had its extent
    run past its own `jr v0` and into the first table arm — arm 0 is laid out immediately after the dispatch,
    and it *falls through into* the `jr ra` the scan was looking for. The extent of a dispatch head ends at
    the dispatch, because the arms are other functions; the `jr ra` beyond it belongs to an arm.
    """
    start = (handler - BASE) // 4
    stop = min(start + WINDOW_WORDS, len(words))
    for index in range(start, stop):
        word = words[index]
        if (word >> 26) != 0 or (word & 0x3F) != 0x08:
            continue
        if index + 1 >= len(words):
            return None, None, None, ("the jr at %s is the last word of the image, so it has no delay slot"
                                      % _hex(BASE + 4 * index))
        target = (word >> 21) & 0x1F
        kind = "return" if target in (31, 30) else "dispatch"
        return BASE + 4 * index, BASE + 4 * (index + 1), kind, None
    return None, None, None, ("no jr within %d words of %s (the window ends at %s%s)"
                              % (WINDOW_WORDS, _hex(handler), _hex(BASE + 4 * (stop - 1)),
                                 ", which is the image end" if stop == len(words) else ""))


def _unresolved(handler, reason, prologue, opcodes):
    return {"classification": "unresolved", "start": _hex(handler), "end": None, "words": None,
            "prologue": prologue, "restore_matches": None, "in_body": None,
            "opcodes": opcodes, "evidence": reason}


def _region_entry(handler, words, bodies, limit=512):
    """The nearest frame setup behind a prologue-less handler, and whether the corpus knows that address.

    M212 measurement: the 76 `fragment`s sit behind only **21** distinct frame setups, each within 1 280 B
    (320 words) of the arm, and all 21 of those addresses are already Ghidra function starts. So the arms do
    not force a single new entry — a rebuild needs *longer extents* for 21 functions it already has.

    This is a bound, not an ownership claim: any function that contains the arm must begin at or before the
    nearest preceding frame setup, and which of the candidates owns it is exactly what these bytes do not
    say. The walk is bounded, and returning None is how it refuses rather than reaching into a far region.
    """
    for k in range(1, limit + 1):
        if (handler - BASE) // 4 - k < 0:
            return None, False
        addr = handler - 4 * k
        if _frame_setup(_at(words, addr)) is not None:
            return _hex(addr), any(b[0] == addr for b in bodies)
    return None, False


def _record(handler, words, bodies, numbers):
    """One handler: the body that covers it, the extent the bytes prove, or why neither is claimable."""
    opcodes = ["0x%02x" % n for n in numbers]
    prologue = _frame_setup(_at(words, handler))
    body = _covering(handler, bodies)
    if body:
        return {"classification": "function_body", "start": _hex(body[0]), "end": _hex(body[1]),
                "words": (body[1] - body[0] + 1) // 4, "prologue": prologue, "restore_matches": None,
                "in_body": {"start": _hex(body[0]), "end": _hex(body[1])},
                "opcodes": opcodes, "evidence": RANGES}

    jr, delay, kind, reason = _first_jr(handler, words)
    if jr is None:
        return _unresolved(handler, reason, prologue, opcodes)
    if kind == "dispatch":
        # the arms are laid out after the dispatch and are separate functions; the extent is the dispatch
        end = delay + 3
        return {"classification": "dispatch_head", "start": _hex(handler), "end": _hex(end),
                "words": (end - handler) // 4 + 1, "prologue": prologue, "restore_matches": None,
                "in_body": None, "opcodes": opcodes,
                # the dispatch site, so a consumer can join this head to its table (M229). The store that
                # decides the advance is in an *arm* for these handlers, not in the head.
                "dispatch_jr": _hex(jr),
                "evidence": "bytes: the handler dispatches through a table -- `jr` at %s, not `jr ra` -- so "
                            "the extent ends at its delay slot. Any `jr ra` beyond it belongs to a table arm, "
                            "which the corpus records as its own function" % _hex(jr)}
    crossed = [b for b in bodies if handler < b[0] <= delay]
    if crossed:
        return _unresolved(handler, ("the extent from %s would cross into the Ghidra body %s..%s before its "
                                     "jr ra at %s" % (_hex(handler), _hex(crossed[0][0]),
                                                      _hex(crossed[0][1]), _hex(jr))),
                           prologue, opcodes)

    slot = _at(words, delay)
    end = delay + 3
    words_long = (end - handler) // 4 + 1
    if prologue is None:
        entry, known = _region_entry(handler, words, bodies)
        return {"classification": "fragment", "start": _hex(handler), "end": _hex(end), "words": words_long,
                "prologue": None, "restore_matches": None, "in_body": None, "opcodes": opcodes,
                "region_entry": entry, "region_entry_in_corpus": known,
                "evidence": "bytes: jr ra at %s, delay slot %s = %s, no addiu sp,sp at %s; nearest frame setup "
                            "behind it %s%s"
                            % (_hex(jr), _hex(delay), _hex(slot), _hex(handler), entry or "(none in window)",
                               ", already a function start" if known else "")}
    restore = _frame_restore(slot)
    if restore != prologue:
        return _unresolved(handler, ("the frame setup addiu sp,sp,-%d at %s is not restored by the delay slot "
                                     "%s = %s, so the recovered pair is not one function"
                                     % (prologue, _hex(handler), _hex(delay), _hex(slot))), prologue, opcodes)
    return {"classification": "code_outside_body", "start": _hex(handler), "end": _hex(end),
            "words": words_long, "prologue": prologue, "restore_matches": True, "in_body": None,
            "opcodes": opcodes,
            "evidence": "bytes: addiu sp,sp,-%d at %s, jr ra at %s, addiu sp,sp,+%d in the delay slot at %s"
                        % (prologue, _hex(handler), _hex(jr), prologue, _hex(delay))}


def _totals(entries):
    counts = {name: 0 for name in CLASSES}
    for entry in entries.values():
        label = entry.get("classification")
        counts[label] = counts.get(label, 0) + 1
    return {"handlers": len(entries),
            "table_entries": TABLE_ENTRIES,
            "classification": counts,
            "future_function_entries": counts["code_outside_body"],
            "in_function_body": counts["function_body"],
            "outside_function_body": len(entries) - counts["function_body"],
            "prologue_at_start": sum(1 for e in entries.values() if e.get("prologue") is not None),
            "words_recovered": sum(e["words"] for e in entries.values() if isinstance(e.get("words"), int)),
            # The actionable number. The 79 out-of-body handlers are not 79 missing functions: the 76
            # fragments sit behind 21 frame setups, every one of them a body start the corpus already has.
            "fragment_region_entries": len({e.get("region_entry") for e in entries.values()
                                            if e.get("classification") == "fragment"
                                            and e.get("region_entry")}),
            "fragment_region_entries_in_corpus": len({e.get("region_entry") for e in entries.values()
                                                      if e.get("classification") == "fragment"
                                                      and e.get("region_entry_in_corpus")}),
            "fragments_without_entry": sum(1 for e in entries.values()
                                           if e.get("classification") == "fragment"
                                           and not e.get("region_entry"))}


def derive():
    """The whole artefact, from the image bytes and the committed fixtures."""
    words = walk_stream.load_stage2()
    bodies, dispatch = _bodies(), _dispatch(words)
    entries = {_hex(addr): _record(addr, words, bodies, dispatch[addr]) for addr in sorted(dispatch)}
    return {"tool": "handler_region.py",
            "schema": 1,
            "milestone": "M212",
            "answers": "where each distinct Script VM handler's code starts and ends, and whether the bytes "
                       "prove it is a function entry",
            "refuses": "an extent as a Ghidra function, a fragment as an entry, an invented end, and any "
                       "claim about a name, a command length or a scheduler effect",
            "inputs": {"image": walk_stream.STAGE2_FILE, "image_inventory": INVENTORY,
                       "function_bodies": RANGES, "opcode_registry": REGISTRY,
                       "dispatch_table": "%s (TABLE=%s, %d entries, resolve())"
                                         % (WALK, _hex(walk_stream.TABLE), TABLE_ENTRIES)},
            "image": _image(words),
            "window_words": WINDOW_WORDS,
            "totals": _totals(entries),
            "handlers": entries}


def render(artefact):
    return json.dumps(artefact, indent=1, sort_keys=True) + "\n"


# --- check ---------------------------------------------------------------------------------------------
def _pairs(pairs):
    seen = {}
    for key, value in pairs:
        if key in seen:
            raise ValueError("duplicate key %r" % key)
        seen[key] = value
    return seen


def _references_sp(words, first, last):
    """True when any instruction of the extent names the stack pointer in an immediate or memory form.

    A frame-less arm that touched `sp` would be a frame this tool failed to see; none of the 76 does, which
    is what makes "no prologue at the handler address" the code's shape rather than a mis-parse.
    """
    for index in range(first, last + 1):
        word = words[index]
        op = word >> 26
        if op not in (OP_ADDIU, 0x0F, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2A, 0x2B):
            continue
        if ((word >> 21) & 0x1F) == SP or ((word >> 16) & 0x1F) == SP:
            return True
    return False


def check():
    cases = []

    def case(label, ok, detail=""):
        cases.append(("PASS" if ok else "FAIL", label, detail))

    def skip(label, reason):
        cases.append(("SKIP", label, reason))

    try:
        committed = json.loads(Path(OUT).read_text(), object_pairs_hook=_pairs)
        case("the committed artefact parses, with no duplicate handler key", True)
    except (OSError, ValueError) as exc:
        case("the committed artefact parses, with no duplicate handler key", False, str(exc))
        return _report(cases)
    entries = committed.get("handlers") or {}

    # The region-entry fact. A fragment owns no prologue, so the only honest thing to publish beside it is the
    # nearest frame setup *behind* it — a bound on where any function containing it must begin — and whether
    # the corpus already knows that address. It is not an ownership claim, and the case label says only what
    # the bytes and `fixtures/decomp/ranges.json` agree on.
    frags = [e for e in entries.values() if e.get("classification") == "fragment"]
    no_entry = [k for k, e in entries.items()
                if e.get("classification") == "fragment" and not e.get("region_entry")]
    ents = {e.get("region_entry") for e in frags if e.get("region_entry")}
    known = {e.get("region_entry") for e in frags if e.get("region_entry_in_corpus")}
    case("every fragment names the frame setup behind it, within the bounded walk (%d fragment(s), %d without)"
         % (len(frags), len(no_entry)), not no_entry and bool(frags), ", ".join(no_entry[:3]))
    case("every frame setup behind a fragment is an address the corpus already starts a function at "
         "(%d distinct, %d already function starts)" % (len(ents), len(known)),
         bool(ents) and known == ents,
         "not a function start: %s" % sorted(ents - known)[:3])

    shape, claimed = [], {}
    for key, entry in entries.items():
        def wrong(why):
            shape.append("%s: %s" % (key, why))

        cls = entry.get("classification")
        if not ADDRESS.fullmatch(key):
            wrong("key is not an 8-digit hex address")
        if cls not in CLASSES:
            wrong("classification %r" % (cls,))
            continue
        if entry.get("start") != key:
            wrong("start %r is not the handler address" % (entry.get("start"),))
        start, end, count = entry.get("start"), entry.get("end"), entry.get("words")
        if not (isinstance(start, str) and ADDRESS.fullmatch(start) and int(start, 16) % 4 == 0):
            wrong("start %r is not a word-aligned address" % (start,))
            continue
        if cls == "unresolved":
            if end is not None or count is not None:
                wrong("an unresolved extent carries end %r, words %r" % (end, count))
            if not entry.get("evidence"):
                wrong("unresolved with no reason")
        else:
            if not (isinstance(end, str) and ADDRESS.fullmatch(end) and int(end, 16) % 4 == 3):
                wrong("end %r is not an inclusive last byte" % (end,))
            elif count != (int(end, 16) - int(start, 16)) // 4 + 1:
                wrong("words %r does not match start/end" % (count,))
        prologue = entry.get("prologue")
        if prologue is not None and not (isinstance(prologue, int) and prologue > 0):
            wrong("prologue %r is not a positive frame size" % (prologue,))
        if entry.get("restore_matches") is not None and cls != "code_outside_body":
            wrong("restore_matches %r outside code_outside_body" % (entry.get("restore_matches"),))
        if cls == "code_outside_body" and entry.get("restore_matches") is not True:
            wrong("code_outside_body without a verified frame restore")
        if cls == "code_outside_body" and (prologue is None or not isinstance(prologue, int)):
            wrong("code_outside_body without a frame setup at the handler address")
        if cls == "fragment" and prologue is not None:
            wrong("a fragment carries the prologue %r" % (prologue,))
        region = entry.get("region_entry")
        if cls == "fragment":
            if region is not None and not (isinstance(region, str) and ADDRESS.fullmatch(region)):
                wrong("region_entry %r is not an address" % (region,))
            if not isinstance(entry.get("region_entry_in_corpus"), bool):
                wrong("region_entry_in_corpus %r is not a boolean"
                      % (entry.get("region_entry_in_corpus"),))
        elif "region_entry" in entry:
            wrong("a %s carries a region_entry" % cls)
        if not entry.get("evidence"):
            wrong("no evidence")
        opcodes = entry.get("opcodes") or []
        if not opcodes:
            wrong("no opcode maps to this handler")
        for op in opcodes:
            if not OPCODE.fullmatch(str(op)):
                wrong("opcode %r is not 0xNN" % (op,))
            elif op in claimed:
                wrong("opcode %s is also claimed by %s" % (op, claimed[op]))
            else:
                claimed[op] = key
    case("every entry is well-formed: one label, a word-aligned inclusive extent and one owner per opcode",
         not shape, "; ".join(shape[:4]))

    bodies = _bodies()
    extents, at_start, in_body = [], 0, 0
    for key, entry in entries.items():
        cover = _covering(int(key, 16), bodies)
        if entry.get("classification") == "function_body":
            in_body += 1
            if cover is None:
                extents.append("%s: no Ghidra body covers it" % key)
                continue
            want = {"start": _hex(cover[0]), "end": _hex(cover[1])}
            if [entry.get("in_body"), entry.get("start"), entry.get("end")] != \
                    [want, want["start"], want["end"]]:
                extents.append("%s: extent %s..%s is not the covering range %s..%s"
                               % (key, entry.get("start"), entry.get("end"), want["start"], want["end"]))
            at_start += int(key, 16) == cover[0]
        elif cover is not None:
            extents.append("%s: inside the Ghidra body %s..%s but classified %r"
                           % (key, _hex(cover[0]), _hex(cover[1]), entry.get("classification")))
    case("every function_body extent is exactly the body range that covers it (%d of %d start exactly at a "
         "body start), and no other entry is inside one" % (at_start, in_body),
         not extents, "; ".join(extents[:4]))

    unresolved = [e for e in entries.values() if e.get("classification") == "unresolved"]
    silent = [e.get("start") for e in unresolved
              if len(str(e.get("evidence") or "")) < 24 or "0x" not in str(e.get("evidence"))]
    case("every unresolved entry states its reason — an address or the window — and leaves end null (%d)"
         % len(unresolved), not silent, "silent: %s" % silent[:4])

    totals = committed.get("totals") or {}
    case("the classification totals match the entries, and the future-entry count is the code_outside_body one",
         totals == _totals(entries), "committed %r, recomputed %r" % (totals, _totals(entries)))

    try:
        registry = json.loads(Path(REGISTRY).read_text())["opcodes"]
    except (OSError, KeyError, ValueError):
        registry = None
    if registry is None:
        skip("the opcode -> handler mapping is the one fixtures/scd/registry.json (M211) records",
             "%s does not record one" % REGISTRY)
    else:
        want = {}
        for number, entry in registry.items():
            want.setdefault(entry.get("handler"), []).append(number)
        drift = sorted(k for k in set(want) | set(entries)
                       if sorted(want.get(k) or []) != sorted((entries.get(k) or {}).get("opcodes") or []))
        case("the opcode -> handler mapping is the one fixtures/scd/registry.json (M211) records",
             not drift, "differs for %s" % drift[:4])

    present = Path(walk_stream.STAGE2_FILE).exists()
    if not present:
        reason = ("%s is not present — unpack the cartridge first (tools/build_images.py)"
                  % walk_stream.STAGE2_FILE)
        for label in ("all distinct dispatch-table handlers are present exactly once",
                      "every recovered extent ends with jr ra + its delay slot, and none references sp",
                      "every code_outside_body starts with a prologue its delay slot restores, and no "
                      "out-of-body handler has one",
                      "the committed file is exactly what --write produces"):
            skip(label, reason)
        return _report(cases)

    words = walk_stream.load_stage2()
    fresh = derive()
    derived = fresh["handlers"]

    missing = sorted(set(derived) - set(entries))
    extra = sorted(set(entries) - set(derived))
    diff = sorted(k for k in set(entries) & set(derived) if entries[k].get("opcodes") != derived[k]["opcodes"])
    case("all %d distinct dispatch-table handlers are present exactly once" % len(derived),
         not missing and not extra and not diff,
         "missing %s, extra %s, opcode drift %s" % (missing[:3], extra[:3], diff[:3]))

    forensic, sp_hits = [], 0
    for key, entry in entries.items():
        if entry.get("classification") not in ("fragment", "code_outside_body"):
            continue
        if not (isinstance(entry.get("end"), str) and ADDRESS.fullmatch(entry["end"])):
            forensic.append("%s: no inclusive extent to verify" % key)
            continue
        start, end = int(entry["start"], 16), int(entry["end"], 16)
        if _at(words, start) is None:
            forensic.append("%s: the handler address is outside the image" % key)
            continue
        if _at(words, end) is None:
            forensic.append("%s: the delay slot at %s is outside the image" % (key, _hex(end)))
            continue
        if _at(words, end - 4) != JR_RA:
            forensic.append("%s: no jr ra at %s" % (key, _hex(end - 4)))
        if _references_sp(words, (start - BASE) // 4, (end - BASE) // 4):
            sp_hits += 1
    case("every recovered extent ends with jr ra + its delay slot, and none references sp",
         not forensic and not sp_hits,
         "%s; %d extent(s) reference sp" % ("; ".join(forensic[:4]), sp_hits))

    frames = []
    outside_frame = 0
    for key, entry in entries.items():
        word = _at(words, int(entry["start"], 16))
        cls = entry.get("classification")
        if word is None:
            frames.append("%s: the handler address is outside the image" % key)
            continue
        first = _frame_setup(word)
        if cls == "code_outside_body":
            if first != entry.get("prologue") or entry.get("restore_matches") is not True:
                frames.append("%s: prologue %r, bytes say %r" % (key, entry.get("prologue"), first))
        elif cls == "function_body":
            if first != entry.get("prologue"):
                frames.append("%s: prologue %r, bytes say %r" % (key, entry.get("prologue"), first))
        elif first is not None:
            outside_frame += 1
            frames.append("%s: a frame setup at the handler address, classified %r" % (key, cls))
    case("every code_outside_body starts with a prologue its delay slot restores, and no out-of-body handler "
         "has one", not frames and outside_frame == 0,
         "%s; %d frame setup(s) outside a body" % ("; ".join(frames[:4]), outside_frame))

    # M212 queue: the extent corrections must be the artefact's own fragments, and every entry must already be
    # a function start -- that is what makes "extend these 21" different from "seed 79 new functions".
    ext_path = Path(EXTENTS)
    if not ext_path.exists():
        case("the next Ghidra run's queue (%s) exists" % EXTENTS, False, "missing -- run --write-extents")
    else:
        queue = json.loads(ext_path.read_text())
        rows = queue.get("corrections") or []
        qentries = {r["entry"] for r in rows}
        covered = sum(r["handlers"] for r in rows)
        frag_entries = {e.get("region_entry") for e in entries.values()
                        if e.get("classification") == "fragment" and e.get("region_entry")}
        frag_count = sum(1 for e in entries.values() if e.get("classification") == "fragment")
        case("the queue names %d extent correction(s) covering all %d fragment handler(s), and every entry is "
             "already a function start" % (len(rows), frag_count),
             qentries == frag_entries and covered == frag_count,
             "%d entries, %d handler(s)" % (len(qentries), covered))
    case("the committed file is exactly what --write produces",
         render(fresh) == Path(OUT).read_text(), "run --write")

    return _report(cases)


def _report(cases):
    passed = sum(1 for verdict, _label, _detail in cases if verdict == "PASS")
    skipped = [reason for verdict, _label, reason in cases if verdict == "SKIP"]
    for verdict, label, detail in cases:
        print("  %s %s%s" % (verdict, label, "" if verdict == "PASS" else ": " + detail))
    if skipped:
        print("  %d case(s) skipped: %s" % (len(skipped), skipped[0]))
    print("%d/%d handler-region case(s)" % (passed, len(cases)))
    return 1 if any(verdict == "FAIL" for verdict, _label, _detail in cases) else 0


def corrections(artefact):
    """The queue for the next Ghidra run: the 21 functions whose extent must grow to contain the VM handlers.

    M212 established that the 76 prologue-less handlers sit behind 21 frame setups that are **already**
    function starts. So the corpus does not need seeds; it needs those 21 extents extended to the last handler
    behind each one. This turns the finding into a machine-readable work item, small enough to read.
    """
    handlers = artefact["handlers"]
    frags = {k: v for k, v in handlers.items() if v["classification"] == "fragment"}
    by_entry = {}
    for key, entry in frags.items():
        by_entry.setdefault(entry["region_entry"], []).append((key, entry))
    rows = []
    for prologue, members in sorted(by_entry.items()):
        last = max(int(e["end"], 16) for _k, e in members)
        rows.append({"entry": prologue, "handlers": len(members),
                     "first_handler": min(k for k, _e in members),
                     "last_end": _hex(last),
                     "extent_bytes": last - int(prologue, 16) + 4,
                     "opcodes": sorted({o for _k, e in members for o in e["opcodes"]})})
    return {"tool": "handler_region.py",
            "note": ("M212, queued for the next Ghidra run: 21 functions whose extents must be extended so the "
                     "Script VM's handlers fall inside them. No new seeds -- every entry address here is "
                     "already a function in the corpus. Regenerate with handler_region.py --write-extents."),
            "corrections": rows}


EXTENTS = "manifests/extent_corrections.json"


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true", help="regenerate %s" % OUT)
    ap.add_argument("--check", action="store_true", help="validate the committed artefact")
    ap.add_argument("--write-extents", action="store_true",
                    help="regenerate %s -- the next Ghidra run's queue" % EXTENTS)
    args = ap.parse_args()
    if not (args.write or args.check or args.write_extents):
        ap.error("one of --write, --write-extents or --check is required")

    if args.write_extents:
        rows = corrections(derive())["corrections"]
        Path(EXTENTS).write_text(json.dumps(corrections(derive()), indent=1, sort_keys=True) + "\n")
        print("%d extent correction(s) -> %s  (%d handler(s), %d byte(s) of extent)"
              % (len(rows), EXTENTS, sum(r["handlers"] for r in rows), sum(r["extent_bytes"] for r in rows)))
        return 0

    if args.write:
        artefact = derive()
        Path(OUT).write_text(render(artefact))
        totals = artefact["totals"]
        counts = totals["classification"]
        print("handlers: %d distinct addresses for %d table entries — %d function_body, %d code_outside_body, "
              "%d fragment, %d unresolved; %d word(s) recovered"
              % (totals["handlers"], totals["table_entries"], counts["function_body"],
                 counts["code_outside_body"], counts["fragment"], counts["unresolved"],
                 totals["words_recovered"]))
        print("%d new function entr%s a corpus rebuild would gain -> %s"
              % (totals["future_function_entries"],
                 "y" if totals["future_function_entries"] == 1 else "ies", OUT))
        print("the %d fragment(s) sit behind %d frame setup(s), %d of them already function starts in the "
              "corpus: what is missing is extents, not entries"
              % (counts["fragment"], totals["fragment_region_entries"],
                 totals["fragment_region_entries_in_corpus"]))
        return 0

    sys.exit(check())


if __name__ == "__main__":
    main()
