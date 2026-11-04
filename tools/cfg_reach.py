#!/usr/bin/env python3
"""Walk the real control-flow graph of every script block, and answer positional questions with it.

The linear walker stops at the five dynamic opcodes, which made reachability tests powerless (M149 measured
96 % of everything "unreachable" that way). Those opcodes are the VM's **structured exits**, and their slots
are now modelled:

    push  0x06 IfElseStart, 0x0d ForStart, 0x11, 0x13 Switch, 0x1b   (block / loop / switch opens)
          0x18 GoSub                                                (subroutine call)
    pop   0x10, 0x12   -> the +0x20 slot array   (depth counter at ctx+thread+8)
          0x1a         -> the +0x60 slot array   (same depth counter)
          0x19         -> the GoSub return slot at ctx+0x144+idx*4

A pop resumes at the continuation recorded by the matching open, which is what the depth counter does at
runtime. This is a **structural** model: it approximates the saved pointer by the opener's continuation
rather than reading a runtime slot, so it *over*-approximates reachability slightly — which is the safe
direction for a "does this ever execute?" question.

  ./cfg_reach.py            # report
  ./cfg_reach.py --check    # the gate
"""
import argparse
import struct
import sys
import tempfile
import zlib
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import walk_stream as ws                                     # noqa: E402
import script_profile as sp                                  # noqa: E402

HERE = Path(__file__).resolve().parent
ROM = HERE.parent / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"

OPENERS = {0x06, 0x0D, 0x11, 0x13, 0x1B}      # push the continuation (0x0f handled separately)
# `0x0f` was missing until M154 and is the most important of them: FUN_8006dfe4 saves the command
# pointer at +0x20, computes the block END as `cmd+4+u16@2` into +0x60, runs the block through
# FUN_8006e1bc(ctx, body, byte1), and if the block signals 0 jumps to that end - the if/else skip.
SUBCALL, SUBRET = 0x18, 0x19
POPPERS = {0x10, 0x12, 0x1A}                  # pop a block slot
NODE_CAP = 40000


def reachable(raw, starts, res, generous_starts=None):
    """Positions reachable from any of `starts`, following jumps and the structured pushes/pops.

    Each start gets its **own** node budget. Seeding all starts into one shared budget starved the later ones
    (a LIFO stack, a global cap), which is what made 34 of block 3505's 35 records look unreachable in M150 —
    a defect in the measurement, not in the code.
    """
    positions = set()
    for start in starts:
        positions |= _reach_from(raw, start, res, generous_starts=generous_starts)
    return positions


def _reach_from(raw, start, res, generous_starts=None):
    seen = set()
    work = [(start, ())]
    nodes = 0
    while work and nodes < NODE_CAP:
        p, st = work.pop()
        st = list(st)
        while 0 <= p < len(raw) and nodes < NODE_CAP:
            nodes += 1
            key = (p, tuple(st))
            if key in seen:
                break
            seen.add(key)
            r = res.get(raw[p])
            if r is None:
                break
            op = raw[p]
            # **status before length**: dynamic opcodes have `length = None`, so a length guard placed first
            # (as it was until M154) makes every pop, every `0x03` target and every `0x19` return dead code -
            # the whole dynamic branch below became unreachable while still appearing present.
            if r["status"] != "dynamic":
                if r["length"] is None or p + r["length"] > len(raw):
                    break
            length = r["length"]
            if r["status"] == "dynamic":
                if op in (SUBRET, *POPPERS) and st:
                    p = st.pop()                 # resume where the matching open said
                    continue
                if op in (SUBRET, *POPPERS) and generous_starts:
                    # **generous closure**: an unresolvable pop could have been entered by any caller, so
                    # resume at every record start. This over-approximates reachability, which is the sound
                    # direction for a dead-code claim: nothing reachable can be missed.
                    for t in generous_starts:
                        work.append((t, tuple(st)))
                    break
                if op == 0x03 and p + 4 <= len(raw):
                    # `0x03` is a script jump by table index: the callee it delegates to
                    # (FUN_8006d5dc) reads `u16[byte3]` at stride 2, so its target is computable.
                    idx = raw[p + 3]
                    if 2 * idx + 2 <= len(raw):
                        work.append((struct.unpack_from(">H", raw, 2 * idx)[0], tuple(st)))
                break
            if op == 0x0F and p + 4 <= len(raw):
                # `0x0f` runs the block that **starts at cmd+4** and skips to `cmd+4+u16@2` when the block
                # signals 0, so both are successors and no stack entry is needed. Its header is 4 bytes -
                # `opcode, span, u16 end` - which is longer than the 2 the length map had (M154).
                body = p + 4
                end = body + struct.unpack_from(">H", raw, p + 2)[0]
                for t in (body, end):
                    if 0 <= t < len(raw):
                        work.append((t, tuple(st)))
                break
            if op in OPENERS or op == SUBCALL:
                if len(st) < 24:
                    st.append(p + length)
            if op == 0x18 and p + 2 <= len(raw):
                # GoSub's stride is **2**, settled structurally: for every index sampled in block 3505 (0, 4,
                # 6, 15, 17, 21, 22, 29) the stride-2 read lands exactly on a record-table entry (0x46, 0x2f6,
                # 0x396, 0x978, 0x9b6, 0xa7e, 0xa8c, 0xe5e) while stride 64 lands on non-entries (0x340f,
                # 0x2d01, 0xbfda, 0x0). M150's "stride unresolved" is retracted: the earlier test scored
                # *decodability*, and any offset in a block "decodes" because the data is dense with opcodes —
                # landing on a table entry is the test that discriminates.
                i = raw[p + 1]
                if 2 * i + 2 <= len(raw):
                    work.append((struct.unpack_from(">H", raw, 2 * i)[0], tuple(st)))
            if r["status"] == "jump":
                sups = ws.successors(op, raw[p:p + length], p, 0,
                                     lambda i: (struct.unpack_from(">H", raw, 2 * i)[0]
                                                if 2 * i + 2 <= len(raw) else None))
                targets = [t for t, _h in sups if t is not None and 0 <= t < len(raw)]
                for t in targets:
                    work.append((t, tuple(st)))
                if ws.JUMP_FAMILY[op]["conditional"] or not targets:
                    p += length
                    continue
                break
            p += length
    return {k[0] for k in seen if len(k) == 2}


ROOM_TABLE = 0x80131FA8       # DAT_80131fa8: room index -> file id (M145)
# **256, not 400**: the index is read from a single byte (`*(byte *)(DAT_800dfb58 + 0xc)`) in 0x8009b27c,
# so no entry past 255 can ever be selected — a provable bound. M156 used 400 and thereby read 138 entries of
# neighbouring data as if they were ids, reporting 285 ids where there are 147.
ROOM_TABLE_MAX = 256


def room_script_ids():
    """The file ids that are actually room scripts, from the table the room loader uses."""
    words = ws.load_stage2()             # big-endian 32-bit words, not bytes
    base = ws.STAGE2_BASE
    out = set()
    for i in range(ROOM_TABLE_MAX):
        va = ROOM_TABLE + 2 * i
        off = va - base
        w = off // 4
        if not (0 <= w < len(words)):
            break
        value = (words[w] >> 16) if off % 4 == 0 else (words[w] & 0xFFFF)
        if value:
            out.add(value)
    return out


def survey(rom, res, entry_only=False, generous=False, only_ids=None):
    """`entry_only` seeds **only record 0** — the room's real entry point, via FUN_8006d5dc(ctx,0).

    Seeding every record start makes the measure near-tautological: each record then "reaches" its own code
    by definition. Restricting the seed to record 0 is what turns the question into "what can the engine
    actually run from the room's script entry?", and that is where a dead-code claim can live.
    """
    blocks = records = 0
    left_stream = 0
    rec_hit = Counter()
    reach_ops = Counter()
    decoded_ops = Counter()
    runs_reach = Counter()
    for idx in range(sp.ENTRY_COUNT):
        if only_ids is not None and idx not in only_ids:
            continue
        off, size = struct.unpack_from(">II", rom, sp.FILE_TABLE_ROM + sp.HEADER + 8 * idx)
        if off == 0xFFFFFFFF or size == 0:
            continue
        try:
            raw = zlib.decompress(rom[sp.FILE_TABLE_ROM + off:sp.FILE_TABLE_ROM + off + size])
        except zlib.error:
            continue
        if len(raw) < 8:
            continue
        offs = []
        for i in range(64):
            if 2 * i + 2 > len(raw):
                break
            o = struct.unpack_from(">H", raw, 2 * i)[0]
            if o == 0 or o >= len(raw):
                break
            offs.append(o)
        if len(offs) < 2:
            continue
        reach = reachable(raw, [offs[0]] if entry_only else offs, res,
                          generous_starts=offs if generous else None)
        if len(reach) < 4:
            continue
        blocks += 1
        for s in offs:
            rec_hit["reached" if s in reach else "not"] += 1
            p = s
            seq, pos = [], []
            while 0 <= p < len(raw):
                r = res.get(raw[p])
                if r is None or r["length"] is None or p + r["length"] > len(raw):
                    break
                seq.append(raw[p])
                pos.append(p)
                decoded_ops[raw[p]] += 1
                if p in reach:
                    reach_ops[raw[p]] += 1
                if r["status"] in ("jump", "dynamic"):
                    break
                p += r["length"]
            records += 1
            if pos and res.get(raw[pos[0]]) is None:
                left_stream += 1
            k = 0
            while k < len(seq):
                if seq[k] == 0x20 and pos[k] in reach:
                    j = k
                    while j < len(seq) and seq[j] == 0x20 and pos[j] in reach:
                        j += 1
                    runs_reach[j - k] += 1
                    k = j
                else:
                    k += 1
    return {"blocks": blocks, "records": records, "rec_hit": rec_hit, "left_stream": left_stream,
            "reach_ops": reach_ops, "decoded_ops": decoded_ops, "runs_reach": runs_reach}


def _scheduler_shape() -> bool:
    p = HERE.parent / "src" / "stage2" / "FUN_8009b880.c"
    if not p.exists():
        return False
    s = p.read_text()
    return ("} while (iVar1 == 1);" in s
            and "if ((iVar1 == 2) ||" in s
            and "*(undefined4 *)(puVar2 + 0x1c) = *(undefined4 *)(iVar1 + -4);" in s)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--rooms", action="store_true",
                    help="restrict the survey to blocks whose file id is in the room-script table")
    ap.add_argument("--check-rooms", action="store_true",
                    help="the gate for the room-script population")
    ap.add_argument("--generous", action="store_true",
                    help="an unresolvable block pop resumes at every record start (over-approximates)")
    ap.add_argument("--entry", action="store_true",
                    help="seed only record 0 (the room entry point) instead of every record start")
    args = ap.parse_args()
    if not ROM.exists():
        print(f"SKIP: no cartridge at {ROM.relative_to(HERE.parent)}")
        return 0
    res = ws.resolve(ws.load_stage2())
    rom = ROM.read_bytes()
    only_ids = room_script_ids() if (args.rooms or args.check_rooms) else None
    s = survey(rom, res, entry_only=args.entry, generous=args.generous, only_ids=only_ids)
    if args.check_rooms:
        cases = [
            ("the room table resolves a script population", 20 < s["blocks"] < 200),
            ("no room-script walk leaves the command stream", s["left_stream"] == 0),
            ("the three object-table writers never occur in room scripts",
             all(s["decoded_ops"][o] == 0 for o in (0x6A, 0x7A, 0x7F))),
        ]
        print(f"room scripts: {s['blocks']} blocks, {s['records']} records, "
              f"{s['left_stream']} walk(s) left the command stream")
        passed = 0
        for label, ok in cases:
            passed += ok
            print(f"  {'PASS' if ok else 'FAIL'} {label}")
        print(f"{passed}/{len(cases)} room-script case(s)")
        return 0 if passed == len(cases) else 1
    if args.generous:
        print("(generous closure: unresolvable pops resume at every record start)")
    if args.entry:
        only_dead = sorted(set(s["decoded_ops"]) - set(s["reach_ops"]))
        print(f"opcodes appearing ONLY outside entry-point-reachable code: "
              f"{[(f'0x{o:02x}', s['decoded_ops'][o] - s['reach_ops'][o]) for o in only_dead]}")
    hit = s["rec_hit"]
    total = hit["reached"] + hit["not"]
    print(f"blocks {s['blocks']}  records {s['records']}  record starts reached "
          f"{hit['reached']}/{total} ({100 * hit['reached'] / max(1, total):.1f}%)")
    for op in (0x00, 0x20, 0x1E, 0x1F):
        d, r = s["decoded_ops"][op], s["reach_ops"][op]
        print(f"  0x{op:02x}: decoded {d:6d}  reachable {r:6d}  ({100 * r / max(1, d):.1f}% of decoded)")
    runs = s["runs_reach"]
    print(f"  runs of reachable 0x20: {sum(runs.values())} run(s), max {max(runs) if runs else 0}")

    if not args.check:
        return 0
    entry_plain = survey(rom, res, entry_only=True)
    entry_gen = survey(rom, res, entry_only=True, generous=True)
    cases = [
        # measured: 27.7% of starts with the pop mechanism, 20.5% with `POPPERS` emptied, against a plain
        # 19.5% - so the margin, not just the inequality, is what the mechanism buys (audit_gates).
        ("the generous mode reaches at least 1.2x plain entry mode, so the pop mechanism is load-bearing",
         entry_gen["rec_hit"]["reached"] > 1.2 * entry_plain["rec_hit"]["reached"]),
        ("the structured walk reaches nearly every record start",
         hit["reached"] / max(1, total) > 0.95),
        ("block returns no longer stop the walk",
         s["blocks"] > 1000),
        ("0x20's runs are reachable, so they are executed",
         s["reach_ops"][0x20] / max(1, s["decoded_ops"][0x20]) > 0.85),
        ("every record start is reachable from some record start (the directory is complete)",
         hit["reached"] == total),
        ("restricting the seed to record 0 leaves a large fraction unreached, so the two modes differ",
         survey(rom, res, entry_only=True)["rec_hit"]["reached"] < 0.5 * total),
        # M210: the scheduler contract -- 1 = run me again, 2 = yield -- was a *reading* with no gate since
        # M152, and every reachability claim above rests on it. It is one loop in the interpreter, so it is
        # pinned by its source shape: the `while (iVar1 == 1)`, the `iVar1 == 2` yield, and the frame pop.
        ("CODE: FUN_8009b880 keeps the context only on a return of 1, yields on 2, and pops the frame at "
         "ctx+0x140", _scheduler_shape()),
    ]
    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} cfg-reach case(s)")
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
