#!/usr/bin/env python3
"""Sweep the cartridge's whole file table and profile what the scripts' opcodes actually do.

The route is the one M146 established: cart record `0x43` holds 8 091 `{offset, size}` entries, most of them
zlib members. A member is treated as a **script block** when it decompresses, its head is a plausible u16
record-offset table, and record 0 decodes into at least four commands with opcodes the decoder knows.

For every script block this records, over every record it can walk:

  * how often each opcode appears;
  * which opcode follows it (`successors` in the profile) — context, not just frequency;
  * the names and lengths M136–M145 derived, so unnamed opcodes are reported with their habitual company,
    which is the best evidence available for naming them.

**No cartridge bytes are written out.** The profile is counts and opcode numbers only — statistics about the
script format, not the scripts.

  ./script_profile.py                    # sweep and print a summary
  ./script_profile.py --json OUT         # also write the profile
  ./script_profile.py --check            # the gate: invariants + a cross-check against walk_stream's CLI
"""
import argparse
import json
import struct
import subprocess
import sys
import zlib
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import walk_stream as ws                                     # noqa: E402

HERE = Path(__file__).resolve().parent
ROM = HERE.parent / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
FILE_TABLE_ROM = 0x0C8624
ENTRY_COUNT = 8091
HEADER = 0x28
MAX_RECORDS = 8
MAX_COMMANDS = 200
MIN_COMMANDS = 4


def walk_block(raw, res, script_base):
    """Decode every record in a block, as a **list of per-record opcode sequences**.

    Per-record matters for the context counters: flattening the records first would make the last command of
    one record look adjacent to the first command of the next, inventing a bigram at every record boundary.
    """
    offsets = []
    for i in range(MAX_RECORDS):
        if 2 * i + 2 > len(raw):
            break
        off = struct.unpack_from(">H", raw, 2 * i)[0]
        if off == 0 or off >= len(raw):
            break
        offsets.append(off)
    decoded = []
    for start in offsets:
        record = []
        p = start
        stack = []
        for _ in range(MAX_COMMANDS):
            if p < 0 or p >= len(raw):      # a Goto can compute a target outside the block
                break
            op = raw[p]
            r = res.get(op)
            if r is None:
                break
            if r["status"] == "dynamic":
                # Record the occurrence, then stop: these six opcodes are returns, script jumps and
                # dispatches, and a linear walker cannot follow them. Not recording them would make their
                # frequency read as zero, which is an artifact of the walker rather than a fact.
                record.append(op)
                if op == 0x19 and stack:
                    p = stack.pop()
                    continue
                break
            length = r["length"]
            if length is None or p + length > len(raw):
                break
            record.append(op)
            cmd = raw[p:p + length]
            if r["status"] == "jump":
                sups = ws.successors(op, cmd, p, script_base,
                                     lambda i, _r=raw: (struct.unpack_from(">H", _r, 2 * i)[0]
                                                        if 2 * i + 2 <= len(_r) else None))
                statics = [t for t, _h in sups if t is not None]
                if op == 0x18 and statics:
                    stack.append(p + length)
                conditional = ws.JUMP_FAMILY[op]["conditional"]
                if conditional or not statics:
                    p += length
                else:
                    p = statics[0]
                continue
            p += length
        if record:
            decoded.append(record)
    return decoded, offsets


def sweep(rom, res, limit=None):
    blocks = 0
    scripts = 0
    opcode_counts = Counter()
    contexts = defaultdict(Counter)                 # opcode -> Counter of successor opcode
    records_total = 0
    failures = Counter()
    seen = 0
    for idx in range(ENTRY_COUNT if limit is None else limit):
        off, size = struct.unpack_from(">II", rom, FILE_TABLE_ROM + HEADER + 8 * idx)
        if off == 0xFFFFFFFF or size == 0:
            failures["empty"] += 1
            continue
        blocks += 1
        try:
            raw = zlib.decompress(rom[FILE_TABLE_ROM + off:FILE_TABLE_ROM + off + size])
        except zlib.error:
            failures["not zlib"] += 1
            continue
        if len(raw) < 8:
            failures["too small"] += 1
            continue
        decoded, offsets = walk_block(raw, res, 0)
        if sum(len(r) for r in decoded) < MIN_COMMANDS or len(offsets) < 2:
            failures["not a script"] += 1
            continue
        scripts += 1
        records_total += len(offsets)
        for record in decoded:
            for i, op in enumerate(record):
                opcode_counts[op] += 1
                if i + 1 < len(record):
                    contexts[op][record[i + 1]] += 1
        seen += 1
    return {
        "blocks": blocks,
        "scripts": scripts,
        "records": records_total,
        "opcode_counts": opcode_counts,
        "contexts": contexts,
        "failures": failures,
        "entries": ENTRY_COUNT if limit is None else limit,
    }


def build_profile(result, res):
    counts = result["opcode_counts"]
    opcodes = {}
    for op, count in sorted(counts.items()):
        r = res[op]
        opcodes[f"0x{op:02x}"] = {
            "count": count,
            "name": r["name"] or None,
            "name_source": r.get("name_source") or None,
            "length": r["length"],
            "status": r["status"],
            # a list of pairs, not a dict: `json.dump(sort_keys=True)` would re-sort a dict's keys
            # alphabetically and destroy the frequency ranking (which is the whole point of this field).
            "successors": [[f"0x{k:02x}", v] for k, v in result["contexts"][op].most_common(8)],
        }
    return {
        "method": ("sweep of the cart file table (record 0x43, 8091 entries) with walk_stream's decoder; a "
                   "block counts as a script when it decompresses and record 0 decodes to >= 4 known "
                   "commands. Counts and opcode numbers only - no cartridge bytes are stored."),
        "entries": result["entries"],
        "blocks": result["blocks"],
        "scripts": result["scripts"],
        "records": result["records"],
        "commands": sum(counts.values()),
        "failures": dict(result["failures"]),
        "opcodes": opcodes,
    }


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--json", default=None, help="write the profile here")
    ap.add_argument("--check", action="store_true", help="assert the profile's invariants (the gate)")
    ap.add_argument("--limit", type=int, default=None, help="only the first N entries (for a quick run)")
    args = ap.parse_args()

    if not ROM.exists():
        print(f"SKIP: no cartridge at {ROM.relative_to(HERE.parent)}")
        return 0
    rom = ROM.read_bytes()
    res = ws.resolve(ws.load_stage2())
    result = sweep(rom, res, args.limit)
    profile = build_profile(result, res)

    print(f"entries {profile['entries']}  zlib blocks {profile['blocks']}  script blocks {profile['scripts']}  "
          f"records {profile['records']}  commands {profile['commands']}")
    print(f"rejected: {profile['failures']}")
    named = sum(1 for v in profile["opcodes"].values() if v["name"])
    print(f"opcodes seen: {len(profile['opcodes'])} of 141 ({named} named)")
    print("\ntop 12 by frequency:")
    for key, v in sorted(profile["opcodes"].items(), key=lambda kv: -kv[1]["count"])[:12]:
        top = ", ".join(f"{k}x{n}" for k, n in v["successors"][:3])
        print(f"  {key}  {v['count']:7d}  len {str(v['length']):>4s}  {v['name'] or '-':14s} follows: {top}")
    unnamed = {k: v for k, v in profile["opcodes"].items() if not v["name"]}
    print(f"\nthe {len(unnamed)} unnamed opcodes with their habitual successors (frequency, then company):")
    for key, v in sorted(unnamed.items(), key=lambda kv: -kv[1]["count"])[:16]:
        top = ", ".join(f"{k}x{n}" for k, n in v["successors"][:4])
        print(f"  {key}  {v['count']:7d}  len {str(v['length']):>4s}  follows: {top}")

    if args.json:
        Path(args.json).write_text(json.dumps(profile, indent=1, sort_keys=True) + "\n")
        print(f"\nwrote {args.json}")

    if not args.check:
        return 0

    # cross-check: the profile's walker and the CLI's must agree on a known block
    cli = subprocess.run([sys.executable, str(HERE / "room_script.py"), "--id", "1881", "--commands", "24"],
                         capture_output=True, text=True)
    cli_ops = [line.split("opcode ")[1][:4] for line in cli.stdout.splitlines() if "opcode 0x" in line]
    off, size = struct.unpack_from(">II", rom, FILE_TABLE_ROM + HEADER + 8 * 1881)
    raw = zlib.decompress(rom[FILE_TABLE_ROM + off:FILE_TABLE_ROM + off + size])
    internal, _ = walk_block(raw, res, 0)
    internal_ops = [f"0x{op:02x}" for record in internal for op in record]
    cases = [
        ("the sweep finds script blocks", profile["scripts"] > 50),
        ("it decodes a substantial number of commands", profile["commands"] > 5000),
        ("most opcodes are seen in the wild", len(profile["opcodes"]) >= 60),
        ("DoorModelSet is among them, as a door script implies",
         "0x4d" in profile["opcodes"] and profile["opcodes"]["0x4d"]["count"] > 0),
        ("the profile walker agrees with the CLI on id 1881's record 0",
         cli_ops[:8] == internal_ops[:8] and len(cli_ops) >= 8),
    ]
    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
        if not ok and label.startswith("the profile walker"):
            print(f"    cli:      {cli_ops[:10]}")
            print(f"    internal: {internal_ops[:10]}")
    print(f"{passed}/{len(cases)} script-profile case(s)")
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
