#!/usr/bin/env python3
"""Generate `include/tyrant.h`: the Script VM's context, handler signatures and opcode table, as C.

TYRANT is **this project's codename for the script VM**, not a Capcom term. Nothing here is a Capcom name.

Why a generated header. Every tool in this repository re-derives the same facts independently — the command
pointer is `ctx+0x1c` in `walk_stream`, `head_index`, `opcode_registry`, `extent_audit` and `scd_vm` alike, the
GoSub slots are `ctx+0x144+idx*4` in three of them, and the 141 opcodes' handlers, lengths and names live in
`fixtures/scd/registry.json`. For a *matching* decompilation those facts have to be **types**, because a
recompiled function matches only when its signature, struct offsets and field widths are the original ones.
One generated header turns "what type is this?" from a research question into an `#include`, and it cannot
drift from the registry because it is regenerated from it.

The rules this file obeys, in the order they bind:

  * **Only measured fields.** The context is not a struct anyone has read; it is a set of offsets that specific
    handlers were *observed* to read and write. Each field below carries the evidence that puts it there, and
    everything else is reserved bytes with the open question named. Nothing is invented to make the struct
    look complete, and `SCD_CTX_MEASURED` says how far the measurement goes -- `sizeof(ScdCtx)` is *not* a
    claim about the real object's size.
  * **Widths come from the instruction, not from the role.** A slot the handler reads with `lw` and writes
    with `sw` is `uint32_t`; one touched with `lb`/`sb` is `uint8_t`. Where both appear the wider one wins and
    the conflict is noted.
  * **Names are attributed.** An opcode name that came from the PlayStation table is marked as such; the
    unnamed ones keep a generated identifier. The distinction the plan calls for -- externally sourced versus
    independently inferred -- is in the file, per line.

Usage:
  ./tyrant_header.py --write    # regenerate include/tyrant.h
  ./tyrant_header.py --check    # fail if the committed header is not what the registry derives
"""
import argparse
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
OUT = Path("include") / "tyrant.h"
REGISTRY = ROOT / "fixtures" / "scd" / "registry.json"
REGION = ROOT / "manifests" / "handler_region.json"

# The context, field by field. Each entry is (offset, name, C type, evidence). Nothing goes in here without a
# line in this repository that measured it; `reserved` spans are the honest gaps.
FIELDS = [
    (0x1C, "cmd", "uint32_t",
     "the command pointer, as the 32-bit address it is: `sw rt,0x1c(ctx)` in every one of the 138 handler "
     "extents (extent_audit.py's CTX_CMDPTR; M145/M146), and the address every handler advances. Declared an "
     "integer rather than `uint8_t *` so the layout is identical on the N64 and on a 64-bit host -- a "
     "pointer type would be 8 bytes here and 4 there, and every offset below would shift."),
    (0x20, "block_start", "uint32_t",
     "the block-start slot. Opened by the block commands, read back by `lw v0,32(v0)` at 0x8006dfb8 and by "
     "0x10/0x1a (opcode_registry.py notes for 0x07, 0x10, 0x1a)."),
    (0x60, "block_end", "uint32_t",
     "the block-end slot. Written by 0x0d/0x0f/0x1b and returned from by 0x1a (opcode_registry.py notes)."),
    (0x140, "frame", "uint32_t",
     "the frame base 0x19 reloads (store at 0x8006e480). M104 called it a countdown and M105 refuted that -- "
     "it reads 0xff in every context measured -- so it is named for what the code does with it."),
]
GOSUB = (0x144, "gosub_slot0", "uint32_t",
         "the FIRST of the GoSub return slots: `ctx+0x144+idx*4` with `idx = cmd[2]`, saved by 0x18 and popped "
         "by 0x19 and by 0x01's first arm (cfg_reach.py SUBRET, walk_stream JUMP_FAMILY). Declared as one "
         "slot, not an array: the stride and the base are measured, the length is not -- use "
         "SCD_GOSUB_SLOT(ctx, idx) for the others.")
MEASURED_END = 0x148 + 0                       # 0x144 + 4, the last byte this project has placed


def registered():
    reg = json.loads(REGISTRY.read_text())
    rows = []
    for key, v in reg["opcodes"].items():
        num = v["number"]
        adv = v.get("advances") or []
        const = adv[0]["value"] if len(adv) == 1 and adv[0].get("kind") == "constant" else None
        rows.append({
            "number": num,
            "name": v.get("name"),
            "name_source": v.get("name_source"),
            "handler": v.get("handler"),
            "advance": const,
            "advances": adv,
            "control_flow": v.get("control_flow"),
        })
    rows.sort(key=lambda r: r["number"])
    return rows


def region():
    return json.loads(REGION.read_text())["handlers"]


def ident(row):
    if row["name"]:
        return "scd_%s" % re.sub(r"[^A-Za-z0-9]+", "_", row["name"]).strip("_").lower()
    return "scd_op_%02x" % row["number"]


def emit():
    rows = registered()
    handlers = region()
    L = []
    a = L.append
    a("/* tyrant.h — GENERATED by tools/tyrant_header.py from fixtures/scd/registry.json. Do not edit.")
    a(" *")
    a(" * TYRANT is this project's codename for the script VM; it is not a Capcom term.")
    a(" *")
    a(" * %d opcodes, %d distinct handlers, %d named from the PlayStation table and %d unnamed."
      % (len(rows), len({r["handler"] for r in rows}), sum(1 for r in rows if r["name"]),
         sum(1 for r in rows if not r["name"])))
    a(" * Only offsets this repository has measured appear as fields; the rest are reserved with the open")
    a(" * question named. `SCD_CTX_MEASURED` is the measured prefix of the object, NOT its size.")
    a(" */")
    a("#ifndef TYRANT_H")
    a("#define TYRANT_H")
    a("")
    a("#include <stddef.h>")
    a("#include <stdint.h>")
    a("")
    a("/* ------------------------------------------------------------------ the context */")
    a("")
    a("/*")
    a(" * The script VM's per-thread context. Fields are placed by measurement, not by reading a struct:")
    a(" * each one below is an offset that named handlers were observed to read or write, and the comment")
    a(" * carries the citation. Everything between fields is bytes nobody has placed yet.")
    a(" */")
    a("typedef struct ScdCtx {")
    prev = 0
    for off, name, ctype, why in FIELDS:
        if off > prev:
            a("    uint8_t  reserved_%03x[0x%x];   /* [0x%03x..0x%03x) not placed */"
              % (prev, off - prev, prev, off))
        emit_comment(a, why, "    ")
        a("    %-9s %s;" % (ctype, name))
        prev = off + 4
    off, name, ctype, why = GOSUB
    if off > prev:
        a("    uint8_t  reserved_%03x[0x%x];   /* [0x%03x..0x%03x) not placed */" % (prev, off - prev, prev, off))
    emit_comment(a, why, "    ")
    a("    %-9s %s;   /* [0x%03x..0x%03x) */" % (ctype, name, off, off + 4))
    a("} ScdCtx;")
    a("")
    a("#define SCD_CTX_MEASURED 0x%03x" % MEASURED_END)
    a("")
    a("/* The real object is larger than SCD_CTX_MEASURED and its size is NOT measured, so nothing here")
    a(" * depends on sizeof(ScdCtx): the GoSub array is reached by its measured stride instead. */")
    a("#define SCD_GOSUB_SLOT(ctx, idx) \\")
    a("    (*(uint32_t *)((uint8_t *)(ctx) + 0x144 + 4 * (uint32_t)(idx)))")
    a("")
    for off, name, _ctype, _why in FIELDS:
        a("_Static_assert(offsetof(ScdCtx, %s) == 0x%03x, \"ScdCtx.%s must be at +0x%03x\");"
          % (name, off, name, off))
    a("_Static_assert(offsetof(ScdCtx, %s) == 0x%03x, \"ScdCtx.%s must be at +0x%03x\");"
      % (GOSUB[1], GOSUB[0], GOSUB[1], GOSUB[0]))
    a("_Static_assert(sizeof(ScdCtx) == SCD_CTX_MEASURED, \"ScdCtx must have no padding\");")
    a("")
    a("/* ------------------------------------------------------------------ the handlers */")
    a("")
    a("/*")
    a(" * One signature for all 141: the C the decompiler produced for them is `undefined4 f(int ctx)`, and")
    a(" * every handler returns the dispatcher's status word (1 = continue, 2 = yield to the scheduler, and")
    a(" * the arms that return a saved block slot, which is not a constant -- see opcode_registry.py).")
    a(" * The context is passed as a pointer because each handler writes `ctx+0x1c` through it.")
    a(" */")
    a("typedef int32_t (*ScdHandler)(ScdCtx *ctx);")
    a("")
    a("enum { SCD_OPCODE_COUNT = %d };" % len(rows))
    a("")
    a("/* advance: the constant the handler adds to `ctx+0x1c`, or SCD_DYNAMIC when the pc comes from")
    a(" * somewhere else (a jump operand, a block slot, the record table, or a callback pointer). */")
    a("#define SCD_DYNAMIC (-1)")
    a("")
    seen = set()
    for r in rows:
        tag = []
        if r["name"]:
            tag.append("name: PlayStation table (M142)")
        else:
            tag.append("unnamed")
        if r["advance"] is None:
            tag.append("advance: dynamic")
        else:
            tag.append("advance: %d" % r["advance"])
        if r["handler"]:
            tag.append("handler 0x%s" % r["handler"][2:])
        a("/* 0x%02x  %s */" % (r["number"], "; ".join(tag)))
        proto = "int32_t %s(ScdCtx *ctx);" % ident(r)
        if ident(r) in seen:
            proto = "/* %s shares its handler with an earlier opcode */" % ident(r)
        seen.add(ident(r))
        a(proto)
    a("")
    a("/* The dispatch table the VM indexes. The image holds it; a reconstruction must define it in the")
    a(" * original order, which is what makes this list usable as a linker input rather than a comment. */")
    a("extern const ScdHandler scd_handlers[SCD_OPCODE_COUNT];")
    a("extern const int16_t     scd_advance[SCD_OPCODE_COUNT];")
    a("extern const char *const scd_names[SCD_OPCODE_COUNT];")
    a("")
    a("#endif /* TYRANT_H */")
    return "\n".join(L) + "\n"


def emit_comment(a, text, indent):
    """A wrapped C block comment. One `/*` and one `*/`, because three `/*` in a row is not a comment."""
    a(indent + "/*")
    for line in wrap(text, 92):
        a(indent + " * " + line)
    a(indent + " */")


def wrap(text, width):
    out, line = [], ""
    for word in text.split():
        if len(line) + len(word) + 1 > width:
            out.append(line)
            line = word
        else:
            line = (line + " " + word).strip()
    if line:
        out.append(line)
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    if not REGISTRY.exists():
        print("REFUSED: %s is missing" % REGISTRY.relative_to(ROOT))
        return 2
    text = emit()
    if args.write:
        OUT.parent.mkdir(parents=True, exist_ok=True)
        OUT.write_text(text)
        print("wrote %s — %d opcodes, %d fields, %d bytes measured"
              % (OUT, len(registered()), len(FIELDS) + 1, MEASURED_END))
        return 0
    if not args.check:
        ap.error("one of --write, --check is required")
    if not OUT.exists():
        print("FAIL %s does not exist — run --write" % OUT)
        return 1
    same = OUT.read_text() == text
    print("%s %s is exactly what the registry derives" % ("PASS" if same else "FAIL", OUT))
    if not same:
        print("     regenerate with tools/tyrant_header.py --write")
    print("1/1 tyrant-header case(s)")
    return 0 if same else 1


if __name__ == "__main__":
    raise SystemExit(main())
