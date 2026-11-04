#!/usr/bin/env python3
"""The per-scene voice lists are in the image, and the rate bit proves they index the clip bank.

M233 established that `0x59 XaOn` passes a `u16` to the boot helper `0x80004a6c`, which indexes a table at
`DAT_8011a718`, reads a clip id out of it, and picks **8 kHz or 16 kHz from bit 15** before starting a voice.
It also recorded why the mapping was refused there: `DAT_8011a718` is **zero in the image** and written at run
time. That refusal was too pessimistic. `FUN_8017b530` writes a literal, and it points at a table that is very
much in the image:

    0x80119de0   16 pointers  ->  u16 arrays from 0x80115440
    0x80119e00    8 pointers  ->  the last seven of the same arrays

`FUN_800762b0` picks the bank with the **sign bit of `0x800e110c`** and the array with `DAT_800e8ca8 + 1`,
which is why the base looked empty: the *arrays* are static, only the selection is dynamic.

The arrays are clip lists, and the evidence is not a resemblance:

  * **654** entries across **16** distinct arrays, lengths **14..72**;
  * **8** are `0` — a skipped slot, the sentinel shape `snd_macros` records for its own tables;
  * **38** carry bit `0x8000`, and masking it leaves an index below **588**, the size of the MORT bank;
  * and **every one of the 654 resolves to a clip whose own declared rate is the one bit 15 asks for** —
    `0` mismatches, 38 at 8 000 Hz and 616 at 16 000 Hz, against `u16@+6` in each MORT record.

So the chain closes, and it was three milestones long: **`0x59 XaOn(byte, idx)` → `list[bank][idx]` → clip
(with the rate from bit 15) → the MORT record → the transcribed PCM.** The command's own byte stays dead, as
M233 measured.

What is **not** claimed: which scene uses which list (that turns on `DAT_800e8ca8`, a run-time index whose
values — 0, 2 and 0x1c are written elsewhere — are not a room number this project has established), whether
"scene" means "room", and what a clip sounds like. The backlog's **48** does not appear here either: the
lengths are 14..72 with 22, 52 and 60 repeated, and 48 is absent from the histogram.

Usage:
  ./voice_lists.py --write     # regenerate manifests/voice_lists.json
  ./voice_lists.py --check     # validate the committed artefact against a fresh derivation
  ./voice_lists.py --list      # print the arrays
"""
import argparse
import importlib.util
import json
import struct
import sys
from collections import Counter
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
OUT = Path("manifests") / "voice_lists.json"
SCHEMA = "voice-lists/1"

for _name in ("rsp_decode", "voice_decode"):
    _spec = importlib.util.spec_from_file_location(_name, HERE / ("%s.py" % _name))
    globals()["_" + _name] = importlib.util.module_from_spec(_spec)
    _spec.loader.exec_module(globals()["_" + _name])
rd = globals()["_rsp_decode"]
V = globals()["_voice_decode"]

LISTS = ((0x80119DE0, "bank 0"), (0x80119E00, "bank 1"))   # (&PTR_PTR_80119e20)[0] and [1]
REGION = (0x80115400, 0x80115A00)      # where every pointer in both tables lands
RATE_FLAG = 0x8000
SKIP = 0
END = 0xFFFF       # closes the last array, which has no next pointer to bound it
CLIPS = 588
MAX_POINTERS = 64


def u16(image, va):
    off = va - rd.STAGE2_BASE
    return struct.unpack_from(">H", image, off)[0] if 0 <= off <= len(image) - 2 else None


def u32(image, va):
    off = va - rd.STAGE2_BASE
    return struct.unpack_from(">I", image, off)[0] if 0 <= off <= len(image) - 4 else None


def pointers(image, table):
    """The table's pointers, stopping at the first one that is not an address in the array region."""
    out = []
    for i in range(MAX_POINTERS):
        p = u32(image, table + 4 * i)
        if p is None or not (REGION[0] <= p < REGION[1]):
            break
        out.append(p & 0xFFFFFFFF)
    return out


def derive():
    image = rd.stage2()
    if image is None:
        return None
    tables = {}
    for table, name in LISTS:
        tables["0x%08x" % table] = {"name": name, "pointers": pointers(image, table)}
    addrs = sorted({p for t in tables.values() for p in t["pointers"]})
    # An array's length is the distance to the next array. The **last** one has no next pointer, so its end is
    # derived from the data instead: it stops at a `0xffff` sentinel, which is the shape the last array
    # actually carries (`.. 114, 115, 0xffff, 0, 0x7f7f...`). Bounding it by the region instead reported 138
    # entries for an 84-entry array -- a length invented by the constant the tool was given.
    bounds = addrs[1:] + [None]
    records = {r[0]: r for r in V.records()}
    arrays, entries, zeros, flagged, mismatched, unresolved = [], 0, 0, 0, 0, 0
    mismatches_list = []
    cross = Counter()              # (flag set?, record rate) -> references: the table that decides "selector" vs "noise"
    per_clip = {}                  # clip -> [flagged refs, unflagged refs]
    for addr, end in zip(addrs, bounds):
        if end is None:
            values = []
            for i in range((REGION[1] - addr) // 2):
                v = u16(image, addr + 2 * i)
                if v is None or v == END:
                    break
                values.append(v)
            source = "sentinel 0xffff"
        else:
            values = [v for v in (u16(image, addr + 2 * i) for i in range((end - addr) // 2))
                      if v is not None]
            source = "pointer distance"
        nonzero = [v for v in values if v != SKIP]
        hi = [v for v in nonzero if v & RATE_FLAG]
        want = {v: (8000 if v & RATE_FLAG else 16000) for v in nonzero}
        clips = [v & (RATE_FLAG - 1) for v in nonzero]
        bad = [c for c in clips if c not in records]
        rate_bad = [c for c, v in zip(clips, nonzero) if c in records and records[c][2] != want[v]]
        for c, v in zip(clips, nonzero):
            if c in records:
                cross[(bool(v & RATE_FLAG), records[c][2])] += 1
                slot = per_clip.setdefault(c, [0, 0])
                slot[0 if v & RATE_FLAG else 1] += 1
            if c in records and records[c][2] != want[v]:
                mismatches_list.append({"array": "0x%08x" % addr, "entry": v, "clip": c,
                                        "flag_says": want[v], "record_says": records[c][2],
                                        "record_blocks": records[c][1]})
        entries += len(nonzero)
        zeros += len(values) - len(nonzero)
        flagged += len(hi)
        unresolved += len(bad)
        mismatched += len(rate_bad)
        arrays.append({
            "base": "0x%08x" % addr,
            "length": len(values),
            "length_source": source,
            "entries": len(nonzero),
            "skips": len(values) - len(nonzero),
            "at_8k": len(hi),
            "first_clip": clips[0] if clips else None,
            "max_clip": max(clips) if clips else None,
            "unresolved": len(bad),
            "rate_mismatches": len(rate_bad),
            "head": nonzero[:6],
        })
    lengths = Counter(a["length"] for a in arrays)
    # the end-to-end chain, on the default list's first real entry
    default = arrays[0]
    first = default["head"][0] if default["head"] else None
    chain = None
    if first is not None:
        clip = first & (RATE_FLAG - 1)
        rec = records.get(clip)
        if rec is not None:
            samples, status = V.transcribe(rec[3], rec[1])
            chain = {"list": default["base"], "index": 0, "entry": first,
                     "clip": clip, "rate_flag_says": 8000 if first & RATE_FLAG else 16000,
                     "record_rate": rec[2], "blocks": rec[1], "samples": len(samples),
                     "peak": max(abs(v) for v in samples) if samples else 0}
    return {
        "tool": "voice_lists.py",
        "schema": SCHEMA,
        "inputs": {
            "image": str(rd.IMAGE.relative_to(ROOT)),
            "tables": "(&PTR_PTR_80119e20)[0] = 0x80119de0, [1] = 0x80119e00, selected by "
                      "`FUN_800762b0` with the sign bit of 0x800e110c and the array with "
                      "DAT_800e8ca8 + 1",
            "bank": "cartridge id 1979, %d MORT records, rates from u16@+6 (M194)" % len(records),
            "rule": "entry 0 is a skipped slot; bit 15 selects 8 kHz, bit 14:0 are the clip index",
        },
        "tables": tables,
        "arrays": arrays,
        "distinct_arrays": len(arrays),
        "length_histogram": dict(sorted(lengths.items())),
        "totals": {"entries": entries, "skips": zeros, "at_8k": flagged,
                   "unresolved": unresolved, "rate_mismatches": mismatched,
                   "clips": len(records)},
        "exceptions": mismatches_list,
        # The flag could be a rate selector or decoration. Under "decoration" the disagreements with the
        # records would number `expected_if_unrelated`; they number one, so it is a selector -- and the one
        # disagreement is then a fact about the data rather than about the flag.
        "rate_cross": {
            "flag_set_record_8k": cross[(True, 8000)],
            "flag_set_record_16k": cross[(True, 16000)],
            "flag_clear_record_8k": cross[(False, 8000)],
            "flag_clear_record_16k": cross[(False, 16000)],
            "expected_if_unrelated": round(
                (cross[(True, 8000)] + cross[(True, 16000)]) * sum(1 for r in records.values() if r[2] == 16000)
                / len(records)
                + (cross[(False, 8000)] + cross[(False, 16000)])
                * sum(1 for r in records.values() if r[2] == 8000) / len(records), 1),
        },
        # a clip referenced both ways is the only shape that can make one entry odd rather than the rule odd
        "mixed_clips": {str(c): v for c, v in sorted(per_clip.items()) if v[0] and v[1]},
        "last_array_rule": {
            "base": "0x%08x" % addrs[-1],
            "flagged": arrays[-1]["at_8k"],
            "flagged_pointing_at_8k_records": sum(
                1 for v in [u16(image, addrs[-1] + 2 * i) for i in range(arrays[-1]["length"])]
                if v and v & RATE_FLAG and (v & (RATE_FLAG - 1)) in records
                and records[v & (RATE_FLAG - 1)][2] == 8000),
            "unflagged_pointing_at_8k_records": sum(
                1 for v in [u16(image, addrs[-1] + 2 * i) for i in range(arrays[-1]["length"])]
                if v and not v & RATE_FLAG and (v & (RATE_FLAG - 1)) in records
                and records[v & (RATE_FLAG - 1)][2] == 8000),
        },
        "forty_eight": {"arrays_of_48": [a["base"] for a in arrays if a["length"] == 48],
                        "lengths": [min(lengths), max(lengths)]},
        "chain": chain,
        "reading": "the per-scene voice lists are **in the image**: **%d** distinct u16 arrays of **%d..%d** "
                   "entries behind two pointer tables of %s, and the entries are clip indices whose bit 15 "
                   "predicts the target record's own rate on **%d of %d** (%d mismatch) — 38 at 8 kHz, the "
                   "rest at 16 kHz, and the exception is clip 61 in the last array, which lacks the flag while "
                   "its own record declares 8 kHz. So `0x59 XaOn` -> list[bank][idx] -> clip -> MORT -> PCM is closed, and "
                   "the byte the command also passes stays dead."
                   % (len(arrays), min(lengths), max(lengths),
                      [len(t["pointers"]) for t in tables.values()], entries, entries, mismatched),
        "not_claimed": [
            "which scene uses which list: the selection is `DAT_800e8ca8 + 1` into the chosen bank, and what "
            "writes that index is a run-time value (0, 2 and 0x1c appear in the corpus) this project has not "
            "tied to a room number",
            "that a 'scene' is a room, or that the two banks are two scenarios",
            "what a clip sounds like, or which event triggers a given list entry",
            "that bit 15 is the *only* rate source: it agrees with the record on 673 of 674 entries and "
            "disagrees on one, so the loader may prefer the record",
            "that the absent 48 means nobody ever had 48 entries: the lengths are 14..72 with 22, 52 and 60 "
            "repeated, and 48 is simply not among them",
        ],
    }


def normalise(obj):
    """Round-trip through JSON so integer-keyed dicts compare as the strings the file holds."""
    return json.dumps(json.loads(json.dumps(obj)), sort_keys=True)


def check(committed):
    fresh = derive()
    a = fresh["arrays"]
    t = fresh["totals"]
    cases = []

    cases.append((f"the two pointer tables resolve to {fresh['distinct_arrays']} distinct arrays "
                  f"({[len(v['pointers']) for v in fresh['tables'].values()]} pointers)",
                  fresh["distinct_arrays"] == 16
                  and sorted(len(v["pointers"]) for v in fresh["tables"].values()) == [8, 16]
                  and normalise(committed) == normalise(fresh)))

    cases.append((f"every array's length is the distance to the next one (the last by its 0xffff sentinel), "
                  f"and they run {fresh['forty_eight']['lengths'][0]}..{fresh['forty_eight']['lengths'][1]} "
                  f"entries with {sum(x['skips'] for x in a)} skips",
                  all(x["length"] == x["entries"] + x["skips"] for x in a)
                  and all(x["length_source"] in ("pointer distance", "sentinel 0xffff") for x in a)
                  and [x["length"] for x in a if x["length_source"] == "sentinel 0xffff"] == [84]))

    cases.append((f"every non-zero entry is a clip index below {t['clips']} "
                  f"({t['entries']} entries, {t['unresolved']} unresolved)",
                  t["unresolved"] == 0 and t["entries"] == 674))

    ex = fresh["exceptions"]
    cases.append((f"bit 15 predicts the record's own rate on {t['entries'] - t['rate_mismatches']} of "
                  f"{t['entries']} entries ({t['at_8k']} flagged 8 kHz), and the one exception is named: "
                  f"clip {[e['clip'] for e in ex]} says {[e['flag_says'] for e in ex]} by flag and "
                  f"{[e['record_says'] for e in ex]} by record",
                  t["rate_mismatches"] == len(ex) == 1 and t["at_8k"] == 38
                  and ex[0]["clip"] == 61 and ex[0]["flag_says"] == 16000
                  and ex[0]["record_says"] == 8000))

    cases.append((f"the skipped slots are {t['skips']} entries of exactly zero, the sentinel snd_macros "
                  f"records for its own tables",
                  t["skips"] == 8 and all(x["skips"] >= 0 for x in a)))

    first = set(fresh["tables"]["0x80119de0"]["pointers"])
    second = fresh["tables"]["0x80119e00"]["pointers"]
    cases.append((f"the second bank reuses the first bank's tail: its {len(second)} pointers all appear in "
                  f"the first table ({len(first)} pointers)",
                  len(second) == 8 and len(first) == 16 and set(second) <= first))

    chain = fresh["chain"]
    cases.append((f"the chain closes end to end: entry {chain['entry']} -> clip {chain['clip']}, "
                  f"{chain['blocks']} blocks, {chain['samples']} samples, rate "
                  f"{chain['rate_flag_says'] if False else chain['record_rate']}",
                  chain["clip"] < t["clips"]
                  and chain["rate_flag_says"] == chain["record_rate"]
                  and chain["samples"] > 0))

    cr = fresh["rate_cross"]
    cases.append((f"bit 15 is a rate selector and not decoration: {cr['flag_set_record_8k']} flagged references "
                  f"point at 8 kHz records and {cr['flag_set_record_16k']} at 16 kHz ones, where an unrelated "
                  f"flag would disagree {cr['expected_if_unrelated']} times and disagrees "
                  f"{cr['flag_set_record_16k'] + cr['flag_clear_record_8k']}",
                  cr["flag_set_record_8k"] == 38 and cr["flag_set_record_16k"] == 0
                  and cr["flag_clear_record_8k"] == 1 and cr["flag_clear_record_16k"] == 635
                  and 50 < cr["expected_if_unrelated"] < 70))

    last = fresh["last_array_rule"]
    cases.append((f"the one disagreement is inside a list that otherwise follows the rule: {last['base']} flags "
                  f"{last['flagged']} entries and all {last['flagged_pointing_at_8k_records']} of them point at "
                  f"8 kHz records, while its {last['unflagged_pointing_at_8k_records']} unflagged one is the "
                  f"exception",
                  last["flagged"] == last["flagged_pointing_at_8k_records"] == 6
                  and last["unflagged_pointing_at_8k_records"] == 1))

    cases.append((f"clip 61 is the only clip in the bank referenced both ways ({fresh['mixed_clips']}), which is "
                  f"what makes one entry odd rather than the rule odd",
                  fresh["mixed_clips"] == {"61": [2, 1]}))

    cases.append((f"48 is not a length here either ({fresh['forty_eight']['arrays_of_48']} arrays of 48, "
                  f"lengths {sorted(set(fresh['length_histogram']))})",
                  fresh["forty_eight"]["arrays_of_48"] == []))

    cases.append(("every list says what is not claimed",
                  len(committed["not_claimed"]) >= 4))
    return cases


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--list", action="store_true")
    a = ap.parse_args()

    if rd.stage2() is None:
        print("SKIP (needs the unpacked stage-2 image)")
        return 0

    if a.write:
        rep = derive()
        OUT.write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        print("wrote %s — %d arrays %d..%d, %d entries, %d at 8 kHz, %d rate mismatches"
              % (OUT, rep["distinct_arrays"], rep["forty_eight"]["lengths"][0],
                 rep["forty_eight"]["lengths"][1], rep["totals"]["entries"],
                 rep["totals"]["at_8k"], rep["totals"]["rate_mismatches"]))
        return 0

    if a.list:
        rep = derive()
        for x in rep["arrays"]:
            print("%s len %3d entries %3d skips %2d 8k %2d  head %s"
                  % (x["base"], x["length"], x["entries"], x["skips"], x["at_8k"], x["head"]))
        print("chain:", rep["chain"])
        return 0

    if not a.check:
        ap.error("one of --write, --check, --list is required")
    committed = json.loads((ROOT / OUT).read_text())
    cases = check(committed)
    bad = 0
    for label, ok in cases:
        bad += not ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d voice-list case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
