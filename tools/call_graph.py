#!/usr/bin/env python3
"""Publish the corpus's call graph — every edge carrying the evidence that produced it, and no edge
whose target nothing in the corpus can name.

The corpus already states its direct calls: `manifests/code_index.json` lists `callees` per function.
What it does not state is *how* each callee was found, what the code does where it finds none, and
what the addresses it cannot resolve are. This tool publishes that, per call site:

    kind              `jal`; `tail` (a `j`, or a `jr` through a constant, that leaves the body);
                      `jalr-resolved` (a register call traced to one constant); `table-dispatch` (a
                      call or tail dispatch through a jump table); `callback` (a function address
                      stored into memory)
    confidence        1.0  a directly decoded transfer to a corpus function (`jal`, or `j` leaving
                           the body)
                      0.9  a register target that traces to a `lui`+`addiu` constant
                      0.8  a function address stored into memory — a static function pointer
                      0.7  one member of a dispatch table with an authoritative bound
                      0.5  decoded, but the target is not a corpus function, or no claimed body owns
                           the site — the target is known and the *edge* is not
                      0.0  the target is not statically determined: `dst` is null and `why` names
                           what was in the way (a table base, a memory slot, an unwritten register)
    tables            each base a dispatch site indexes, with its bound and where the bound came from

Four things it refuses, because each one would be a guess:

  1. **A bound nobody declared.** A table walked until its entries stop looking like code is a value
     scan, and M173 already showed that walk running to 46 entries where the class table holds 14
     (`tools/routine_index.py`). Only two sources may bound a table here: the 31 bases whose lengths
     `routine_index.py` checks against the image gate by gate, and the `declared_cases` a dispatcher
     states with its own `sltiu`/`slti` guard (`manifests/jump_tables.json`). Every other base is
     recorded with `bound: null`, and its sites carry `dst: null` — 302 sites name a base instead of
     a target rather than inventing fourteen.
  2. **A `jr`-indexed table treated as a call.** A `lw` + `jr` switch jumps to case blocks *inside*
     the dispatching function: 189 of the 240 such tables have no entry that leaves the body at all.
     Where an entry does leave the body it is recorded, and nowhere else.
  3. **An edge with no owner.** A call site no claimed body covers is `src: null` at 0.5. It is kept —
     a call from unclaimed bytes to a real function is evidence that the corpus is missing a function
     — but attributing it to a neighbour by proximity would be invention.
  4. **A target rounded to the nearest function.** A `jal` whose target is not a function start stays
     a bare address at 0.5 (158 sites). It is never snapped forward or back.

Node identity is `image:address`, not address. 3 638 functions hold 3 487 distinct addresses: 28
overlays load at `0x80161cf0` and 112 addresses name more than one function, so an address-keyed
graph would merge 151 functions' edges. Table keys are image-qualified for the same reason: 15 of the
516 traced base addresses are shared by two or three overlays (`0x80166608` by three), so a bare
`addr` key would hand one overlay's bound and entries to another's dispatch site.

Nothing is stored as a count. Degree, per-image totals and edges-per-kind are derivable, so they live
in `--write`'s output and in `--check`'s labels, never in the file. A call target is a function
*start*, not an address inside a function: `code_index.callees` follows that rule and `--check` holds
this artefact to it exactly — for every node, the addresses its `jal` edges reach must equal its
`callees`, or the case names the node.

A body is its claimed ranges, not `addr..addr+size`: 22 functions have a gap in the middle, and a
scan of `size` bytes from the start then reads a neighbour's `jal` and reports a callee the provider
never had. Reading the ranges is what makes the `jal` reconciliation exact.

Usage:
  ./call_graph.py --write    # manifests/call_graph.json
  ./call_graph.py --check    # identity, edge shape, the callees reconciliation, table bounds, size
"""
import argparse
import bisect
import json
import struct
import sys
from pathlib import Path

import recovered

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
sys.path.insert(0, str(HERE))
import routine_index  # noqa: E402  — the 31 table bounds that gate verifies against the image

OUT = "manifests/call_graph.json"
CODE_INDEX = "manifests/code_index.json"
JUMP_TABLES = "manifests/jump_tables.json"
IMAGES = "build/elfs/images.json"
ELFS = "build/elfs"
DECOMP = "build/decomp"

FILE_MAX = 4 << 20                 # the ceiling `tools/artefact_scan.py` refuses to track
RD_LO = 0x80000000

# The fixed meanings. An edge may use no other value, and `--check` holds it to this table.
CONFIDENCE = {1.0: "directly decoded transfer to a corpus function",
              0.9: "register target traced to a lui+addiu constant",
              0.8: "function address stored into memory",
              0.7: "member of a dispatch table with an authoritative bound",
              0.5: "decoded, but the target is not a corpus function or no body owns the site",
              0.0: "target not statically determined; dst is null"}
KINDS = ("jal", "tail", "jalr-resolved", "table-dispatch", "callback")

JAL_OP, J_OP, SW_OP, LW_OP, LUI_OP = 3, 2, 0x2B, 0x23, 0x0F
ADDIU_OP, ORI_OP = 0x09, 0x0D
JR_FUNCT, JALR_FUNCT, ADDU_FUNCT = 8, 9, 0x21
RET_REG = 31

# How far back a register's definition is followed. Measured: widening the first window from 10 to 16
# changes the traced-table site count by under 1%, and every extra hit is a coincidental match.
DEF_WINDOW = 10
SUB_WINDOW = 8


def hexaddr(a: int) -> str:
    return f"0x{a:08x}"


# ------------------------------------------------------------------ decoding
def sext16(v: int) -> int:
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def writes(w: int):
    """The register `w` writes, or None. Deliberately narrow: only ops that write a GPR."""
    op = w >> 26
    if op == 0:
        return None if (w & 0x3F) in (0x08, 0x09, 0x0C, 0x0D) else (w >> 11) & 31
    if op in (0x23, 0x24, 0x25, 0x20, 0x21, 0x22, 0x26, 0x09, 0x0C, 0x0B, 0x0A, 0x0D, 0x0E, 0x0F):
        return (w >> 16) & 31
    return None


def def_index(ws, i: int, reg: int, window: int = DEF_WINDOW):
    """Index of the nearest instruction before `i` that writes `reg`, within `window` words."""
    for j in range(i - 1, max(-1, i - 1 - window), -1):
        if writes(ws[j]) == reg:
            return j
    return None


def static_value(ws, j: int):
    """The constant `ws[j]` writes when it is a `lui`, or a `lui`+`addiu`/`ori` pair. An address built
    from anything else returns None — that is the whole point of the helper."""
    w = ws[j]
    if (w >> 26) == LUI_OP:
        return (w & 0xFFFF) << 16
    if (w >> 26) in (ADDIU_OP, ORI_OP) and ((w >> 16) & 31) == ((w >> 21) & 31):
        k = def_index(ws, j, (w >> 21) & 31, SUB_WINDOW)
        if k is not None and (ws[k] >> 26) == LUI_OP:
            hi = (ws[k] & 0xFFFF) << 16
            return hi | (w & 0xFFFF) if (w >> 26) == ORI_OP else hi + sext16(w & 0xFFFF)
    return None


def trace_register(ws, i: int, reg: int) -> dict:
    """Where the value in `reg` at word `i` came from. One of:

      constant  value=   a `lui`+`addiu`/`ori` constant
      table     base=    an indexed load: `lw rt,off(rb)` with `rb = base + 4*index`
      slot      slot=    a load from a fixed address (`rb` is a constant, no index)
      base               a load whose base register is not a static constant
      nowrite            the register is written nowhere in the window (an incoming parameter)
      other              written by something that is neither a load nor a constant
    """
    j = def_index(ws, i, reg)
    if j is None:
        return dict(kind="nowrite")
    w = ws[j]
    value = static_value(ws, j)
    if value is not None:
        return dict(kind="constant", value=value)
    if (w >> 26) != LW_OP or ((w >> 16) & 31) != reg:
        return dict(kind="other")
    rb = (w >> 21) & 31
    k = def_index(ws, j, rb, SUB_WINDOW)
    if k is None:
        return dict(kind="base")
    kw = ws[k]
    if (kw >> 26) == 0 and (kw & 0x3F) == ADDU_FUNCT:
        for r in ((kw >> 21) & 31, (kw >> 16) & 31):
            kk = def_index(ws, k, r, SUB_WINDOW)
            if kk is not None:
                base = static_value(ws, kk)
                if base is not None:
                    return dict(kind="table", base=base)
        return dict(kind="base")
    base = static_value(ws, k)
    if base is None:
        return dict(kind="base")
    return dict(kind="slot", slot=base + sext16(w & 0xFFFF))


# ------------------------------------------------------------------ corpus
def image_bytes(name: str, size: int) -> bytes:
    """The convention `export_src.py` and `find_missed_functions.py` read images with."""
    return (ROOT / ELFS / f"{name}.elf").read_bytes()[0x100:0x100 + size]


def routine_bounds() -> dict:
    """The 31 bases whose lengths `routine_index.py` checks against the image, with those lengths.

    Imported, not copied: the gate owns these numbers and a second transcription is exactly the drift
    this repository has paid for before.
    """
    bounds = {}
    for base in routine_index.CLASS_A + routine_index.CLASS_B:
        bounds[base] = routine_index.ROW
    bounds[routine_index.MAIN] = routine_index.ROW
    for base in routine_index.TYPE_TABLES:
        bounds[base] = 11
    bounds[routine_index.CLASS_TABLE] = 9
    for _name, base, entries, _basis, _sibling in routine_index.SIBLINGS:
        bounds[base] = entries
    return bounds


def jump_table_bounds() -> dict:
    """-> {(image, base): declared_cases} for every dispatcher that states its own case count."""
    out = {}
    for img in json.loads((ROOT / JUMP_TABLES).read_text())["images"]:
        for t in img["tables"]:
            if t.get("declared_cases"):
                out[(img["name"], int(t["table"], 16))] = t["declared_cases"]
    return out


def body_ranges(name: str) -> list:
    """[(lo, hi, function_address)] — the instructions the provider claims, plus the recovered extents.

    M289: a recovered function's provider body covers only its dispatch head, so without the fixture's measured
    extent every `jal` inside its arms would be attributed to no owner and the edge would lose its source. The
    fixture is the same one the two exporters read, so the call graph cannot disagree with the code index about
    where a function ends.
    """
    index = json.loads((ROOT / DECOMP / name / "decompile-index.json").read_text())
    out = []
    for f in index["functions"]:
        if f["body"]["available"]:
            for r in f["body"]["ranges"]:
                out.append((int(r["start"], 16), int(r["end"], 16), f["address"]))
    rec = recovered.load().get(name, [])
    if rec:
        out = [r for r in out if not any(e["start"] <= r[0] <= e["end"] for e in rec)]
        out.extend((e["start"], e["end"], "0x%08x" % e["start"]) for e in rec)
    out.sort()
    return out


class Corpus:
    """Function starts, body ranges and image bytes, indexed the ways the scan needs them."""

    def __init__(self):
        manifest = json.loads((ROOT / IMAGES).read_text())
        self.cart_sha256 = manifest["cart_sha256"]
        self.base, self.bytes = {}, {}
        for img in manifest["images"]:
            self.base[img["name"]] = img["base"]
            self.bytes[img["name"]] = image_bytes(img["name"], img["size"])
        self.nodes, self.by_image, self.by_addr = [], {}, {}
        for img in json.loads((ROOT / CODE_INDEX).read_text())["images"]:
            for f in img["functions_list"]:
                addr = int(f["address"], 16)
                node = dict(id=f"{img['name']}:{f['address']}", image=img["name"],
                            addr=f["address"], name=f["name"], file=f["file"],
                            size=f["size"], status=f["status"])
                self.nodes.append(node)
                self.by_image.setdefault(img["name"], {}).setdefault(addr, []).append(node)
                self.by_addr.setdefault(addr, []).append(node["id"])
        self.nodes.sort(key=lambda n: (n["image"], int(n["addr"], 16)))
        self._ranges, self._starts = {}, {}

    def ranges(self, image: str) -> list:
        if image not in self._ranges:
            self._ranges[image] = body_ranges(image)
            self._starts[image] = [r[0] for r in self._ranges[image]]
        return self._ranges[image]

    def owner(self, image: str, site: int):
        """The claimed function whose body contains `site`, or None. Claimed ranges do not overlap."""
        ranges = self.ranges(image)
        i = bisect.bisect_right(self._starts[image], site) - 1
        if i >= 0 and ranges[i][0] <= site <= ranges[i][1]:
            return ranges[i][2]
        return None

    def in_body(self, image: str, func: str, addr: int) -> bool:
        return any(lo <= addr <= hi for lo, hi, f in self.ranges(image) if f == func)

    def resolve(self, image: str, addr: int):
        """-> (node_id, None) when one function owns the address; (None, why) when none does.

        Same image first: an overlay's call to `0x80161cf0` is the overlay's own function, which is
        why node identity is image-qualified in the first place.
        """
        local = self.by_image.get(image, {}).get(addr)
        if local and len(local) == 1:
            return local[0]["id"], None
        owners = self.by_addr.get(addr) or []
        if not owners:
            return None, f"{hexaddr(addr)} is not a function start in any image"
        if len(owners) == 1:
            return owners[0], None
        return None, (f"{hexaddr(addr)} is a function start in {len(owners)} images "
                      f"({', '.join(o.split(':', 1)[0] for o in owners[:3])}…) — the address alone "
                      f"does not name one")

    def table_entries(self, image: str, base: int, bound: int) -> list:
        """The first `bound` words that name a corpus function start, deduplicated, in table order.

        Reading past an authoritative bound is the mistake M173 caught; reading *within* it is the
        only licence this tool takes. A word that names no function start is dropped, not rounded.
        """
        offset = base - self.base[image]
        data = self.bytes[image]
        if offset < 0 or offset + 4 * bound > len(data):
            return []
        out = []
        for w in struct.unpack(f">{bound}I", data[offset:offset + 4 * bound]):
            if w in self.by_addr and w not in out:
                out.append(w)
        return [hexaddr(a) for a in out]


# ------------------------------------------------------------------ derivation
def derive():
    corpus = Corpus()
    routine, declared = routine_bounds(), jump_table_bounds()
    edges, tables = [], {}

    def edge(src, site, kind, dst, confidence, why, **extra):
        obj = dict(src=src, site=hexaddr(site), kind=kind, dst=dst)
        obj.update(extra)
        obj["confidence"] = confidence
        obj["why"] = why
        edges.append(obj)

    def table_for(image, base):
        """The ledger entry for a base, resolved once: bound, where the bound came from, entries."""
        key = f"{image}:{hexaddr(base)}"
        if key not in tables:
            bound, source = None, "none"
            if base in routine:
                bound, source = routine[base], "routine_index.py"
            elif (image, base) in declared:
                bound, source = declared[(image, base)], "jump_tables.json"
            tables[key] = dict(image=image, bound=bound, bound_src=source,
                               entries=[] if bound is None
                               else corpus.table_entries(image, base, bound))
        return tables[key]

    for image in corpus.base:
        base = corpus.base[image]
        data = corpus.bytes[image]
        n = len(data) // 4
        ws = struct.unpack(f">{n}I", data[:n * 4])
        for i, w in enumerate(ws):
            site = base + 4 * i
            op = w >> 26
            if op == JAL_OP:
                target = ((w & 0x03FFFFFF) << 2) | ((site + 4) & 0xF0000000)
                owner = corpus.owner(image, site)
                dst, why = corpus.resolve(image, target)
                if owner is None:
                    if dst is None:
                        continue      # a jal-shaped word with no owner and no real target is data
                    edge(None, site, "jal", dst, 0.5,
                         "no claimed body covers the site; the word reaches a corpus function")
                    continue
                if dst is None:
                    edge(f"{image}:{owner}", site, "jal", hexaddr(target), 0.5, why)
                else:
                    edge(f"{image}:{owner}", site, "jal", dst, 1.0, "direct jal")
            elif op == J_OP:
                target = ((w & 0x03FFFFFF) << 2) | ((site + 4) & 0xF0000000)
                owner = corpus.owner(image, site)
                if owner is None or target not in corpus.by_addr:
                    continue
                if corpus.in_body(image, owner, target):
                    continue          # a jump inside its own body is not a call
                dst, _why = corpus.resolve(image, target)
                if dst is not None:
                    edge(f"{image}:{owner}", site, "tail", dst, 1.0,
                         "direct j to a function start outside the body")
            elif op == 0 and (w & 0x3F) == JALR_FUNCT:
                _indirect(edges, corpus, table_for, image, site, i, ws, "call")
            elif op == 0 and (w & 0x3F) == JR_FUNCT:
                _indirect(edges, corpus, table_for, image, site, i, ws, "jump")
            elif op == SW_OP:
                _stored_pointer(edges, corpus, image, site, i, ws)

    edges.sort(key=lambda e: ((e["src"] or ""), int(e["site"], 16), e["kind"],
                              json.dumps(e["dst"])))
    return dict(tool="call_graph.py", schema=1, cart_sha256=corpus.cart_sha256,
                nodes=corpus.nodes, edges=edges, tables=tables)


def _indirect(edges, corpus, table_for, image, site, i, ws, flavour):
    """A `jalr` (a call) or a `jr` (a jump): resolved to a table, to a constant, or to a refusal."""
    reg = (ws[i] >> 21) & 31
    if reg == RET_REG:
        return
    owner = corpus.owner(image, site)
    if owner is None:
        return
    src = f"{image}:{owner}"
    traced = trace_register(ws, i, reg)

    def push(kind, dst, confidence, why, **extra):
        obj = dict(src=src, site=hexaddr(site), kind=kind, dst=dst)
        obj.update(extra)
        obj["confidence"] = confidence
        obj["why"] = why
        edges.append(obj)

    if traced["kind"] == "table":
        table = table_for(image, traced["base"])
        base = hexaddr(traced["base"])
        if table["bound"] is None:
            if flavour == "jump":
                return                # an unbounded switch is a switch, not a call and not a claim
            push("table-dispatch", None, 0.0,
                 f"table {base} has no authoritative bound; its contents are not walked", table=base)
            return
        entries = table["entries"]
        if flavour == "jump":
            entries = [e for e in entries if not corpus.in_body(image, owner, int(e, 16))]
            if not entries:
                return                # every entry is a case block inside this function
        if not entries:
            if flavour == "jump":
                return
            push("table-dispatch", None, 0.0,
                 f"table {base} is bounded ({table['bound']}, {table['bound_src']}) but no entry "
                 f"names a corpus function", table=base)
            return
        dsts = []
        for e in entries:
            dst, _why = corpus.resolve(image, int(e, 16))
            if dst is not None and dst not in dsts:
                dsts.append(dst)
        if not dsts:
            return
        note = "" if flavour == "call" else "; the site is a jr, so it is a tail dispatch"
        push("table-dispatch", dsts, 0.7,
             f"member of table {base} (bound {table['bound']}, {table['bound_src']}){note}",
             table=base)
        return
    if traced["kind"] == "constant":
        if flavour == "call":
            dst, why = corpus.resolve(image, traced["value"])
            if dst is None:
                push("jalr-resolved", hexaddr(traced["value"]), 0.5, why)
            else:
                push("jalr-resolved", dst, 0.9,
                     f"target register holds the constant {hexaddr(traced['value'])}")
        else:
            dst, _why = corpus.resolve(image, traced["value"])
            if dst is not None and not corpus.in_body(image, owner, traced["value"]):
                push("tail", dst, 0.9,
                     f"jr through the constant {hexaddr(traced['value'])}, leaving the body")
        return
    if flavour != "call":
        return
    why = {"slot": lambda: (f"the target is read from memory at {hexaddr(traced['slot'])}; its value "
                            f"is not static"),
           "base": lambda: ("the target is loaded through a base register that is not a static "
                            "constant"),
           "nowrite": lambda: (f"the target register is written nowhere in the {DEF_WINDOW} words "
                               f"before the site — it is an incoming parameter"),
           }.get(traced["kind"], lambda: "the target register is neither a table entry nor a constant")
    push("jalr-resolved", None, 0.0, why())


def _stored_pointer(edges, corpus, image, site, i, ws):
    """A `sw` of a function address: a static function pointer, i.e. a callback being registered."""
    owner = corpus.owner(image, site)
    if owner is None:
        return
    value_at = def_index(ws, i, (ws[i] >> 16) & 31)
    if value_at is None:
        return
    value = static_value(ws, value_at)
    if value is None:
        return
    dst, why = corpus.resolve(image, value)
    if dst is None and value not in corpus.by_addr:
        return              # a constant that is not a function start is a data pointer, not a callback
    obj = dict(src=f"{image}:{owner}", site=hexaddr(site), kind="callback",
               dst=dst if dst is not None else hexaddr(value))
    slot_at = def_index(ws, value_at, (ws[i] >> 21) & 31, SUB_WINDOW)
    slot = None
    if slot_at is not None:
        slot_base = static_value(ws, slot_at)
        if slot_base is not None:
            slot = slot_base + sext16(ws[i] & 0xFFFF)
            obj["slot"] = hexaddr(slot)
    if dst is None:
        obj["confidence"] = 0.5
        obj["why"] = f"{why}; the address is stored as a callback"
    else:
        obj["confidence"] = 0.8
        obj["why"] = (f"function address stored at {hexaddr(slot)}" if slot is not None else
                      "function address stored; the slot's own address is not a static constant")
    edges.append(obj)


# ------------------------------------------------------------------ rendering
def render(rep) -> str:
    """One node, edge and table per line. `indent=1` would triple a 15 000-edge file, and a line per
    edge still diffs cleanly."""
    lines = ["{"]
    for key in ("tool", "schema", "cart_sha256"):
        lines.append(f' "{key}": {json.dumps(rep[key])},')
    for key in ("nodes", "edges"):
        lines.append(f' "{key}": [')
        lines.append(",\n".join("  " + json.dumps(x, separators=(",", ":")) for x in rep[key]))
        lines.append(" ],")
    lines.append(' "tables": {')
    lines.append(",\n".join(f"  {json.dumps(k)}:{json.dumps(v, separators=(',', ':'))}"
                            for k, v in rep["tables"].items()))
    lines.append(" }")
    lines.append("}")
    return "\n".join(lines) + "\n"


def summarise(rep) -> str:
    kinds = {}
    for e in rep["edges"]:
        kinds[e["kind"]] = kinds.get(e["kind"], 0) + 1
    sources = {}
    for t in rep["tables"].values():
        sources[t["bound_src"]] = sources.get(t["bound_src"], 0) + 1
    bounded = sum(1 for t in rep["tables"].values() if t["bound"] is not None)
    return (f"{len(rep['nodes'])} nodes, {len(rep['edges'])} edges ("
            + ", ".join(f"{k} {v}" for k, v in sorted(kinds.items()))
            + f"), {len(rep['tables'])} tables — {bounded} bounded ("
            + ", ".join(f"{k} {v}" for k, v in sorted(sources.items()) if k != "none")
            + f"), {sources.get('none', 0)} unbound; {len(render(rep)) / 1048576:.2f} MiB")


# ------------------------------------------------------------------ the checks
def as_list(dst) -> list:
    return dst if isinstance(dst, list) else [dst]


def names_node(dst) -> bool:
    """A node id is `image:address`; a bare address is the second colon-free form."""
    return all(isinstance(d, str) and d.count(":") == 1 for d in as_list(dst))


def check(rep, committed: str):
    cases = []
    nodes, edges, tables = rep["nodes"], rep["edges"], rep["tables"]

    ids = [n["id"] for n in nodes]
    shaped = [n for n in nodes if n["id"] != f"{n['image']}:{n['addr']}"
              or ":" not in n["id"] or int(n["addr"], 16) < RD_LO]
    cases.append((f"every node id is `image:address` and unique — {len(set(ids))} ids for "
                  f"{len(nodes)} functions, {len(nodes) - len(set(ids))} collisions, "
                  f"{len(shaped)} malformed",
                  len(set(ids)) == len(nodes) and not shaped))

    no_site = [e for e in edges if not e.get("site")]
    cases.append((f"every edge carries the instruction address that produced it — {len(edges)} "
                  f"edges, {len(no_site)} without a site", not no_site and bool(edges)))

    bad_null = [e for e in edges if (e.get("dst") is None) != (e.get("confidence") == 0.0)]
    cases.append((f"dst is null exactly when the target is not determined — "
                  f"{sum(1 for e in edges if e['dst'] is None)} of {len(edges)} edges name no target, "
                  f"all at 0.0; {len(bad_null)} violate", not bad_null))

    bad_conf = [e for e in edges if e.get("confidence") not in CONFIDENCE or e["kind"] not in KINDS]
    overclaimed = [e for e in edges if e["confidence"] > 0.5 and not names_node(e["dst"])]
    cases.append((f"every confidence is one of the five fixed values ({len(bad_conf)} violate) and "
                  f"nothing above 0.5 names anything but a corpus node ({len(overclaimed)} violate)",
                  not bad_conf and not overclaimed))

    starts = {int(n["addr"], 16) for n in nodes}
    callees = {}
    for img in json.loads((ROOT / CODE_INDEX).read_text())["images"]:
        for f in img["functions_list"]:
            callees[f"{img['name']}:{f['address']}"] = {int(x, 16) for x in f["callees"]}
    reached = {}
    for e in edges:
        if e["kind"] != "jal" or e["src"] is None:
            continue
        bucket = reached.setdefault(e["src"], set())
        for d in as_list(e["dst"]):
            if not isinstance(d, str):
                continue
            addr = int(d.split(":", 1)[1] if ":" in d else d, 16)
            if addr in starts:
                bucket.add(addr)
    disagree = sorted(nid for nid, want in callees.items() if reached.get(nid, set()) != want)
    cases.append((f"for every node the addresses its `jal` edges reach equal its code_index callees "
                  f"— {len(callees)} nodes compared, {len(disagree)} disagree"
                  + (f": {', '.join(disagree[:4])}" if disagree else ""), not disagree))

    routine, declared = routine_bounds(), jump_table_bounds()
    bad_bound, violated, unbound = [], [], 0
    for key, t in tables.items():
        base = int(key.split(":", 1)[1], 16)
        if t["bound"] is None:
            unbound += 1
            if t["entries"] or t["bound_src"] != "none":
                violated.append(key)
            continue
        want = routine.get(base) if t["bound_src"] == "routine_index.py" else \
            declared.get((t["image"], base))
        if t["bound_src"] not in ("routine_index.py", "jump_tables.json") or want != t["bound"] \
                or t["bound"] < 1:
            bad_bound.append(key)
        if len(t["entries"]) > t["bound"] or len(set(t["entries"])) != len(t["entries"]):
            violated.append(key)
        if any(int(e, 16) not in starts for e in t["entries"]):
            violated.append(key)      # an entry that names no function start is not a target
        if key.split(":", 1)[0] != t["image"]:
            bad_bound.append(key)
    cited = {(e["src"].split(":", 1)[0], e["table"]) for e in edges
             if e.get("table") and e.get("src")}
    unknown = sorted(f"{img}:{tbl}" for img, tbl in cited
                     if f"{img}:{tbl}" not in tables)
    cases.append((f"every table bound is the one its cited source states, no table holds more entries "
                  f"than its bound, every entry names a function start and every edge's table is in "
                  f"the ledger — {len(tables)} tables, {len(tables) - unbound} bounded, {unbound} "
                  f"refused as unbound, {len(cited)} tables cited by an edge; "
                  f"{len(set(bad_bound) | set(violated)) + len(unknown)} violate",
                  bool(tables) and not bad_bound and not violated and not unknown))

    size = len(committed.encode())
    cases.append((f"the artefact is {size / 1048576:.2f} MiB — under the {FILE_MAX >> 20} MiB this "
                  f"repository refuses to track", size < FILE_MAX))

    cases.append(("the committed artefact matches a fresh derivation", committed == render(derive())))
    return cases


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    if not (ROOT / IMAGES).exists():
        print(f"{IMAGES} is absent — run the rebuild first (docs/handover.md)")
        return 2
    path = ROOT / OUT
    if args.write:
        rep = derive()
        path.write_text(render(rep))
        print(f"wrote {OUT} — {summarise(rep)}")
        return 0
    if args.check:
        if not path.exists():
            print(f"{OUT} is absent — run --write")
            return 2
        committed = path.read_text()
        cases = check(json.loads(committed), committed)
        bad = 0
        for label, ok in cases:
            bad += not ok
            print(f"  {'PASS' if ok else 'FAIL'} {label}")
        print(f"{len(cases) - bad}/{len(cases)} call-graph case(s)")
        return 1 if bad else 0
    print(__doc__.strip().splitlines()[-1])
    return 2


if __name__ == "__main__":
    raise SystemExit(main())
