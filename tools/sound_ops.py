#!/usr/bin/env python3
"""The sound commands, read from their handlers: six opcodes, one that plays nothing, and one dead operand.

The backlog's question was "which script events start a voice, and what do they pass". That needs the six
commands the licensed name table calls sound commands — `0x51 SceBgmControl`, `0x59 XaOn`, `0x84 SndMode`,
`0x85 SndPlay3D`, `0x86 SndBusy` — plus `0x83`, which has no name but sits **inside** the contiguous handler
run `0x80073410..0x8007358f`. Being framed by that run is a measurement; being unnamed is why it is listed
here rather than silently dropped.

For each command this tool derives, from bytes and nothing else:

  * its **extent** and whether the corpus carved it as a function (`function_body`) or a fragment of a larger
    body — three of the six are fragments, which is why they have no decompiled C of their own;
  * its **advance**, read from the `sw rt,0x1c(ctx)` store the handler performs, not from the registry, so the
    published advance is checked rather than assumed;
  * its **operand loads**, derived by tracking the command pointer from the `lw rt,0x1c(ctx)` that
    materialises it, through `addu rd,rs,zero` moves, and stopping the alias at any instruction that rewrites
    the register — the M231/M232 lesson applied to a register the code copies on purpose;
  * its **direct calls**, and the **closure** of those calls inside the same image.

Two readings the closure settles, and one it cannot:

`0x85 SndPlay3D` **starts no sound.** Its only callee is `0x8006ab40`, a zone-visibility test over the
room's 16-byte region list, and that callee makes **no call at all**, so nothing reachable from the command
reaches the sound engine. The `u16` it passes is tested as a **mask** against the region records; the byte
is an early-out flag. The name comes from the PS1 table and the bytes do not support it: whatever `SndPlay3D`
means on the PlayStation, here the command is "is this segment visible across zones, and stop at the first
one that is" — it returns the answer to the script, having played nothing.

`0x59 XaOn` **does** reach the engine, one image away: its callee `0x80004a6c` is in the **boot** image, it
indexes a `u16` table at `DAT_8011a718`, and it calls `0x800b3704`, which is a `stage2` function body
(`0x800b3704..0x800b398b`) — the entry point that starts a voice. And the byte the command passes is **dead**:
no instruction in the callee's extent reads register `a0`.

What the tool does **not** claim: that the `u16` indexes a room table (the table base is written at run time
by `FUN_800762b0` and is zero in the image), what each voice id means, or that `0x84`'s two flag words are the
sound engine's only mode state.

Usage:
  ./sound_ops.py --write     # regenerate manifests/sound_ops.json
  ./sound_ops.py --check     # validate the committed artefact against a fresh derivation
  ./sound_ops.py --list      # print the census
"""
import argparse
import importlib.util
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
OUT = Path("manifests") / "sound_ops.json"
SCHEMA = "sound-ops/1"

_spec = importlib.util.spec_from_file_location("rsp_decode", HERE / "rsp_decode.py")
rd = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(rd)

RANGES = ROOT / "fixtures" / "decomp" / "ranges.json"
REGISTRY = ROOT / "fixtures" / "scd" / "registry.json"
REGION = ROOT / "manifests" / "handler_region.json"
BOOT_ELF = ROOT / "build" / "elfs" / "boot.elf"

COMMANDS = ["0x51", "0x59", "0x83", "0x84", "0x85", "0x86"]
VOICE_START = 0x800B3704          # the function 0x59's callee calls with (id, rate, 0x7f, vol, 0x3f, 0, 0)
CMDPTR = 0x1C                     # ctx+0x1c: the byte stream pointer the CPU publishes for a handler
CLOSURE_DEPTH = 3

LOAD = {0x20: "lb", 0x21: "lh", 0x23: "lw", 0x24: "lbu", 0x25: "lhu"}
LUI, ADDIU, ORI, JAL, SW = 0x0F, 0x09, 0x0D, 0x03, 0x2B
SPECIAL = 0x00


def bits(x, hi, lo):
    return (x >> lo) & ((1 << (hi - lo + 1)) - 1)


def sx16(v):
    return v - 0x10000 if v & 0x8000 else v


def jal_target(at, w):
    return ((at + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)


def stage2_word(va):
    image = rd.stage2()
    if image is None:
        return None
    off = va - rd.STAGE2_BASE
    if off < 0 or off + 4 > len(image):
        return None
    return int.from_bytes(image[off:off + 4], "big")


def boot_segments():
    """The boot image's loadable bytes, from the ELF `build_images.py` produced.

    Boot is the one RAM image that is not an unpacked cartridge member: it comes from ROM 0x1000, so the
    only committable handle on it is the built ELF. Reading it here keeps this tool to two images and no
    second ROM reader.
    """
    if not BOOT_ELF.exists():
        return []
    data = BOOT_ELF.read_bytes()
    e_phoff = struct.unpack_from(">I", data, 28)[0]
    phentsize = struct.unpack_from(">H", data, 42)[0]
    phnum = struct.unpack_from(">H", data, 44)[0]
    out = []
    for i in range(phnum):
        off = e_phoff + i * phentsize
        p_type, p_offset, p_vaddr, _pa, p_filesz, _memsz = struct.unpack_from(">IIIIII", data, off)
        if p_type == 1 and p_filesz:                       # PT_LOAD
            out.append((p_vaddr, data[p_offset:p_offset + p_filesz]))
    return out


def boot_word(va):
    for vaddr, blob in boot_segments():
        if vaddr <= va < vaddr + len(blob) - 3:
            return int.from_bytes(blob[va - vaddr:va - vaddr + 4], "big")
    return None


def scan(lo, hi, word_at):
    """What a handler reads off the command pointer, and how far it advances the pointer.

    The alias set is the whole point: `0x51` copies `a0` into `s1`, loads the stream pointer into `s0`, and
    every operand read is off `s0`; `0x85` keeps it in `a3` and reloads it halfway through. A scan that holds
    one register name per handler gets both of them wrong -- and a scan that never *drops* an alias reads
    `0x83`'s `lhu v1,0x1c7e(v0)` as an operand after `v0` has been rebuilt as 0x800df6b0.
    """
    ctx, cmd = {4}, set()               # a0 is the context pointer on entry
    operands, advance = [], None
    for at in range(lo, hi + 1, 4):
        w = word_at(at)
        if w is None:
            return {"operands": operands, "advance": advance, "truncated": True}
        op, rs, rt, rdx = w >> 26, bits(w, 25, 21), bits(w, 20, 16), bits(w, 15, 11)
        fn, imm = bits(w, 5, 0), w & 0xFFFF
        written = set()
        if op in LOAD:
            written = {rt}
        elif op in (LUI, ADDIU, ORI):
            written = {rt}
        elif op in (SPECIAL, 0x1C) and op != SW:               # ALU / shift writes rd
            written = {rdx} if op == SPECIAL else {bits(w, 20, 16)}
        special = None
        if op in LOAD and rs in ctx and imm == CMDPTR:
            special = "cmdbase"
            cmd.add(rt)
        elif op == SPECIAL and fn in (0x21, 0x25) and rdx not in ctx:      # addu/or rd,rs,rt as a move
            if (rs in ctx and rt == 0) or (rt in ctx and rs == 0):
                special = "ctxmove"
                ctx.add(rdx)
            elif (rs in cmd and rt == 0) or (rt in cmd and rs == 0):
                special = "cmdmove"
                cmd.add(rdx)
        elif op == ADDIU and rs in cmd and sx16(imm) == 0:
            special = "cmdmove"
            cmd.add(rt)
        elif op == SW and rs in ctx and imm == CMDPTR:
            special = "advance"
            for back in range(at - 4, lo - 1, -4):
                wb = word_at(back)
                if wb is None:
                    break
                if (wb >> 26) == ADDIU and bits(wb, 20, 16) == rt:
                    advance = sx16(wb & 0xFFFF)
                    break
            cmd.discard(rt)
        if special is None:
            if op in LOAD and rs in cmd:
                operands.append({"load": LOAD[op], "offset": sx16(imm)})
            for r in written:
                if special is None:
                    cmd.discard(r)
                    if r != 4:
                        ctx.discard(r)
    return {"operands": operands, "advance": advance, "truncated": False}


def shifts_before(image_lo, word_at, at):
    """The shift amounts applied between the first operand load and the call, in order.

    `sll rd,rt,sa` is special-op 0 with `rs == 0`; the amount is bits 10:6. Reading `rs` from the wrong
    field (21:16 instead of 25:21) reported no shifts at all, which is how this function was caught.
    """
    out = []
    for va in range(image_lo, at, 4):
        w = word_at(va)
        if w is None:
            break
        if (w >> 26) == SPECIAL and bits(w, 5, 0) == 0x00 and bits(w, 25, 21) == 0:
            out.append(bits(w, 10, 6))
    return out


def argument_dead_on_entry(lo, hi, word_at, reg=4):
    """True when the first instruction that touches `reg` writes it, so the incoming value is unused.

    Counting *uses* is not the claim: `0x80004a6c` touches `a0` nine times, and the first one is
    `lw a0,-22760(v0)` -- a write before any read. Nine later touches of a dead argument are what a scratch
    register looks like, so the test has to be read-before-write and not a count.
    """
    for va in range(lo, hi + 1, 4):
        w = word_at(va)
        if w is None:
            return None
        op, rs, rt, rdx = w >> 26, bits(w, 25, 21), bits(w, 20, 16), bits(w, 15, 11)
        fn = bits(w, 5, 0)
        reads = writes = False
        if op in LOAD:
            reads, writes = rs == reg, rt == reg
        elif op in (0x28, 0x29, SW):
            reads = reg in (rs, rt)
        elif op in (0x0C, 0x0D, LUI):
            reads, writes = rs == reg, rt == reg
        elif op in (0x08, 0x09, 0x0A, 0x0B, 0x0E, 0x0F):
            reads, writes = rs == reg, rt == reg
        elif op == SPECIAL:
            if fn in (0x08, 0x0C, 0x0D):
                writes = rdx == reg
            elif fn in (0x00, 0x02, 0x03):
                reads, writes = rt == reg, rdx == reg
            else:
                reads, writes = reg in (rs, rt), rdx == reg
        elif 0x04 <= op <= 0x07 or 0x10 <= op <= 0x17:
            reads = reg in (rs, rt)
        else:
            reads = reg in (rs, rt)
        if reads:
            return False
        if writes:
            return True
    return None


def jals(lo, hi, word_at):
    out = []
    for va in range(lo, hi + 1, 4):
        w = word_at(va)
        if w is None:
            return out
        if (w >> 26) == JAL:
            out.append({"at": "0x%08x" % va, "target": "0x%08x" % jal_target(va, w)})
    return out


def closure(lo, hi, word_at, ranges, depth=CLOSURE_DEPTH, seen=None):
    """Every call reachable from an extent, within one image, to `depth` hops."""
    seen = set() if seen is None else seen
    out = []
    for j in jals(lo, hi, word_at):
        t = int(j["target"], 16)
        if t in seen:
            continue
        seen.add(t)
        out.append(j["target"])
        span = next(([a, b] for a, b in ranges if a <= t <= b), None)
        if span is not None and depth > 1:
            out.extend(closure(span[0], span[1], word_at, ranges, depth - 1, seen))
    return out


def derive():
    image = rd.stage2()
    reg = json.loads(REGISTRY.read_text())["opcodes"]
    region = json.loads(REGION.read_text())["handlers"]
    ranges = json.loads(RANGES.read_text())["images"]["stage2"]
    boot_ranges = json.loads(RANGES.read_text())["images"]["boot"]
    rows = []
    for opcode in COMMANDS:
        entry = reg[opcode]
        handler = int(entry["handler"], 16)
        found = region.get("0x%08x" % handler) or region.get(entry["handler"])
        lo, hi = int(found["start"], 16), int(found["end"], 16)
        sc = scan(lo, hi, stage2_word)
        calls = jals(lo, hi, stage2_word)
        out = {
            "opcode": opcode,
            "name": entry.get("name"),
            "handler": "0x%08x" % handler,
            "extent": ["0x%08x" % lo, "0x%08x" % hi],
            "bytes": hi - lo + 4,
            "carved_as": found["classification"],
            "published_advance": entry["advances"][0]["value"] if entry["advances"] else None,
            "advance": sc["advance"],
            "operands": sc["operands"],
            "calls": calls,
            "closure": closure(lo, hi, stage2_word, ranges),
        }
        # the one call that leaves this image
        for c in calls:
            t = int(c["target"], 16)
            if not any(a <= t <= b for a, b in ranges):
                span = next(([a, b] for a, b in boot_ranges if a <= t <= b), None)
                if span is not None:
                    out["outside_image"] = {"target": c["target"], "image": "boot"}
                    bcalls = jals(span[0], span[1], boot_word)
                    out["outside_image"]["calls"] = bcalls
                    out["outside_image"]["a0_dead_on_entry"] = argument_dead_on_entry(
                        span[0], span[1], boot_word, 4)
                    out["outside_image"]["a1_dead_on_entry"] = argument_dead_on_entry(
                        span[0], span[1], boot_word, 5)
                    out["outside_image"]["reaches_voice_start"] = any(
                        int(b["target"], 16) == VOICE_START for b in bcalls)
                    out["outside_image"]["extent"] = ["0x%08x" % span[0], "0x%08x" % span[1]]
        if opcode == "0x51":
            out["shift_ladder"] = shifts_before(lo, stage2_word, int(calls[0]["at"], 16))
        rows.append(out)
    runs = sorted({(int(r["extent"][0], 16), int(r["extent"][1], 16)) for r in rows
                   if r["opcode"] in ("0x83", "0x84", "0x85", "0x86")})
    contiguous = len(runs) == 4 and all(runs[i][1] + 1 == runs[i + 1][0] for i in range(3))
    return {
        "tool": "sound_ops.py",
        "schema": SCHEMA,
        "inputs": {
            "stage2": str(rd.IMAGE.relative_to(ROOT)),
            "boot": "build/elfs/boot.elf (PT_LOAD segments; boot is ROM 0x1000, not an unpacked member)",
            "registry": "fixtures/scd/registry.json (M142 names, M143-M145 advances)",
            "region": "manifests/handler_region.json (M212/M229 extents)",
            "rule": "the command pointer is tracked from `lw rt,0x1c(ctx)` through `addu/or rd,rs,zero` moves "
                    "and dropped at any instruction that rewrites the register; operands are `lb/lh/lw` off "
                    "that register, and the advance is the `addiu` that feeds the `sw rt,0x1c(ctx)` store",
        },
        "commands": rows,
        "contiguous_run": {"handlers": ["0x%08x" % a for a, _b in runs],
                           "contiguous": contiguous},
        "reading": "six commands touch the sound subsystem's state and only **two** call into it: `0x51` into "
                   "the BGM decoder (`0x800777d8`, a 40-bit `[4-bit channel][4-bit opcode][24-bit operand]` "
                   "assembled from five bytes) and `0x59` into the boot helper `0x80004a6c`, which indexes a "
                   "runtime-filled `u16` table and starts a voice at `0x800b3704`. `0x85`, named `SndPlay3D`, "
                   "**plays nothing**: its only callee is a zone-visibility test that makes no call at all. "
                   "`0x83`/`0x84`/`0x86` write state words and call nothing.",
        "not_claimed": [
            "that 0x59's u16 indexes a per-room table: the base at DAT_8011a718 is written at run time "
            "(FUN_800762b0 from a two-way table indexed by DAT_800e8ca8, and FUN_8017b530 with the literal "
            "0x80115440) and is zero in this image",
            "what a voice id means, or which clip a given id selects",
            "that 0x85's zone mask corresponds to rooms: it selects records in the list at *(0x800df92c+0x20), "
            "which is the scene region list, and the correspondence is not established here",
            "the semantics of 0x83, 0x84 and 0x86 beyond the words they write: they are fragments inside a "
            "larger body, so no decompiled C of their own exists to read",
        ],
    }


def check(committed):
    """Grade the **fresh derivation**, not the committed file.

    The first version of these cases read the committed artefact, which makes them tautologies: no change to
    how a value is derived can move a number that is then read back out of the file it was written to (the
    defect M227 recorded, met again). Only the artefact-equality case and `not_claimed` read `committed`.
    """
    fresh = derive()
    rows = {r["opcode"]: r for r in fresh["commands"]}
    cases = []

    cases.append((f"the six sound commands are all traced ({len(rows)} of {len(COMMANDS)})",
                  sorted(rows) == sorted(COMMANDS)
                  and json.dumps(committed, sort_keys=True) == json.dumps(fresh, sort_keys=True)))

    run = fresh["contiguous_run"]
    cases.append((f"0x83..0x86 are one contiguous handler run ({run['handlers'][0]}..{run['handlers'][-1]})",
                  run["contiguous"]
                  and all(rows[o]["carved_as"] in ("function_body", "fragment") for o in COMMANDS)))

    adv = {o: (rows[o]["advance"], rows[o]["published_advance"]) for o in COMMANDS}
    cases.append((f"every advance read from the image equals the published one ({adv})",
                  all(v[0] is not None and v[0] == v[1] for v in adv.values())))

    ops = {o: [(d["load"], d["offset"]) for d in rows[o]["operands"]] for o in COMMANDS}
    cases.append((f"the operands are loads off the command pointer, and they match the published layout ({ops})",
                  ops == {"0x51": [("lbu", 1), ("lbu", 2), ("lbu", 3), ("lbu", 4), ("lbu", 5)],
                          "0x59": [("lbu", 1), ("lhu", 2)],
                          "0x83": [],
                          "0x84": [("lbu", 1)],
                          "0x85": [("lbu", 1), ("lbu", 2), ("lhu", 4), ("lbu", 3)],
                          "0x86": []}))

    calls = {o: [c["target"] for c in rows[o]["calls"]] for o in COMMANDS}
    cases.append((f"three commands call out, and each call is the one named ({calls})",
                  calls == {"0x51": ["0x800777d8"], "0x59": ["0x80004a6c"], "0x83": [], "0x84": [],
                            "0x85": ["0x8006ab40"], "0x86": []}))

    stage2_ranges = json.loads(RANGES.read_text())["images"]["stage2"]
    play = rows["0x85"]
    silent = [c for c in play["closure"]
              if not jals(int(c, 16), next(b for a, b in stage2_ranges if a <= int(c, 16) <= b),
                          stage2_word)]
    cases.append((f"0x85 starts no sound: its whole call closure is {play['closure']}, and all "
                  f"{len(silent)} of those make no call of their own",
                  play["closure"] == ["0x8006ab40"] and silent == play["closure"]))

    out = rows["0x59"].get("outside_image", {})
    cases.append((f"0x59 reaches the voice starter across an image boundary ({out.get('target')} -> "
                  f"{[c['target'] for c in out.get('calls', [])]})",
                  out.get("image") == "boot" and out.get("reaches_voice_start") is True))

    cases.append((f"0x59's byte operand is dead: the boot callee writes a0 before reading it, and reads a1 "
                  f"first (a0 dead {out.get('a0_dead_on_entry')}, a1 dead {out.get('a1_dead_on_entry')})",
                  out.get("a0_dead_on_entry") is True and out.get("a1_dead_on_entry") is False))

    ladder = rows["0x51"].get("shift_ladder", [])
    cases.append((f"0x51 assembles a 40-bit operand from five bytes ({ladder} over "
                  f"{len(rows['0x51']['operands'])} reads)",
                  ladder == [28, 24, 16, 8] and len(rows["0x51"]["operands"]) == 5))

    cases.append(("every command says what is not claimed",
                  len(committed["not_claimed"]) >= 4))
    return cases


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--list", action="store_true")
    a = ap.parse_args()

    if rd.stage2() is None or not BOOT_ELF.exists():
        print("SKIP (needs the unpacked stage-2 image and build/elfs/boot.elf)")
        return 0

    if a.write:
        rep = derive()
        OUT.write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        calls = {r["opcode"]: [c["target"] for c in r["calls"]] for r in rep["commands"]}
        print("wrote %s — six commands, calls %s" % (OUT, calls))
        return 0

    if a.list:
        for r in derive()["commands"]:
            print("%-6s %-14s %s..%s %4d B %-13s adv %-2s operands %s calls %s" % (
                r["opcode"], r["name"] or "(unnamed)", r["extent"][0], r["extent"][1], r["bytes"],
                r["carved_as"], r["advance"],
                ",".join("%s@%d" % (d["load"], d["offset"]) for d in r["operands"]) or "-",
                ",".join(c["target"] for c in r["calls"]) or "-"))
        return 0

    if not a.check:
        ap.error("one of --write, --check, --list is required")
    committed = json.loads((ROOT / OUT).read_text())
    cases = check(committed)
    bad = 0
    for label, ok in cases:
        bad += not ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d sound-command case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
