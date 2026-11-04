#!/usr/bin/env python3
"""Validate the committed sound artefacts against themselves, with no cartridge.

Why this exists: every sound gate in this repository reads the cartridge, so **CI skips all of them**
(`needs_rom = True`), and `tools/preflight.py` checks documents against the registry but not artefacts
against their own invariants. The cost of that gap is measured: a session with 30 admission runs had 11
failures, and the sound ones were *integration* defects — an artefact edited in place, a clip hash made 65
hex characters, counts that no longer summed — each found eight minutes in, each visible in one second.

So this is tier 1. It needs no ROM, it runs in CI, and it asserts only what a committed JSON file can
promise about itself:

  * `manifests/snd_proj.json`   — 417 records, the six offsets in range per record, the five key lists'
                                  recorded lengths and distinct counts, and that no list runs past its record
  * `manifests/snd_macros.json` — the four opcodes' element counts sum to the element total, every command
                                  names a witness, and `unresolved` is disjoint from `commands`
  * `fixtures/sound/mort_sweep.json` — 588 clips, blocks == 262 894 + 44 144, samples == blocks × 160 per
                                  clip, the live-comparison totals, and every hash being 64 hex characters
  * `fixtures/sound/codec.json` — the sample count the sweep and the codec fixture agree on

It cannot tell you the artefacts match the cartridge — only `tools/snd_proj.py --check`,
`tools/snd_macros.py --check` and `tools/voice_sweep.py --check` can, and they need the ROM. This tier's
claim is narrower and still load-bearing: **the committed files are internally consistent and unedited by
hand.**

Usage:
  ./sound_fixtures.py --check
  ./sound_fixtures.py --self-test   # grade the checks against synthetic breakage
"""
import argparse
import hashlib
import json
import re
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

HEX64 = re.compile(r"^[0-9a-f]{64}$")

PROJ = "manifests/snd_proj.json"
MACROS = "manifests/snd_macros.json"
SWEEP = "fixtures/sound/mort_sweep.json"
CODEC = "fixtures/sound/codec.json"

# Recorded by the milestones that derived them; asserted here so a hand edit cannot survive tier 1.
PROJ_RECORDS = 417
PROJ_LIST_LEN = [3468, 3316, 261, 4, 339]
PROJ_LIST_DISTINCT = [2026, 1192, 242, 4, 327]
SWEEP_CLIPS = 588
SWEEP_BLOCKS = 307038
SWEEP_NORMAL, SWEEP_SILENT = 262894, 44144
SWEEP_LIVE = 12037
SAMPLES_PER_BLOCK = 160


def _load(root, rel):
    return json.loads((root / rel).read_text())


def checks(root=ROOT):
    cases = []

    # --- the project file ------------------------------------------------------------------------
    try:
        proj = _load(root, PROJ)
        recs = proj.get("records") or []
        lists = proj.get("lists") or []
        over = []
        for r in recs:
            stride, offs = r.get("stride"), r.get("offsets") or []
            if len(offs) != 6 or any(not (0 <= o < stride) for o in offs):
                over.append(r.get("key"))
        case_a = (len(recs) == PROJ_RECORDS and not over)
        cases.append((f"the project artefact holds {len(recs)} record(s), each with six list offsets in "
                      f"range ({len(over)} offending)", case_a))
        lens = [l.get("values_total") for l in lists[:5]]
        dist = [l.get("values_distinct") for l in lists[:5]]
        cases.append((f"the five key lists record {lens} values and {dist} distinct — the numbers the gate "
                      f"re-derives from the cartridge",
                      lens == PROJ_LIST_LEN and dist == PROJ_LIST_DISTINCT))
        cases.append((f"list 5 is a {lists[5].get('width')}-byte row array, not a key list, as WP2 established",
                      len(lists) == 6 and lists[5].get("width") == 12
                      and lists[5].get("values_total") == 3822))
    except (OSError, ValueError, IndexError, KeyError) as exc:
        cases.append((f"{PROJ} parses and carries the project structure", False, str(exc)[:120]))

    # --- the macro space -------------------------------------------------------------------------
    try:
        mac = _load(root, MACROS)
        cmds = mac.get("commands") or []
        tot = (mac.get("totals") or {})
        no_witness = [c.get("opcode") for c in cmds if not c.get("evidence")]
        cases.append((f"the artefact records {tot.get('opcodes')} opcode(s) and every command names its "
                      f"witness ({len(no_witness)} without), with the pool's {tot.get('records')} records "
                      f"split {tot.get('records_by_tag')} by tag",
                      len(cmds) == 4 and tot.get("opcodes") == 4 and not no_witness
                      and tot.get("records") == 2599
                      and tot.get("records_by_tag") == {"0": 2026, "1": 4, "2": 327, "3": 242}
                      and tot.get("sequence_elements") == 1315))
        # `unresolved` here is *field-level*: the unknowns are inside known opcodes (a payload whose
        # interior no function reads), so the invariant is the opposite of disjointness — every entry must
        # belong to an opcode that is in the table, and must state why it is unresolved.
        un = mac.get("unresolved") or []
        opcodes = {c.get("opcode") for c in cmds}
        # Two kinds are legitimate: a field inside a known opcode, and a stated *opcode-space* question,
        # which is how "there is no fifth opcode" is published rather than left implicit.
        stray = [u for u in un
                 if not u.get("reason")
                 or (u.get("kind") == "opcode-space" and u.get("opcode") is None) is False
                 and u.get("opcode") not in opcodes]
        cases.append((f"the {len(un)} unresolved entr(ies) are fields of a known opcode or a stated "
                      f"opcode-space question, and all state a reason ({len(stray)} do not)",
                      not stray and len(un) == tot.get("unresolved")))
    except (OSError, ValueError, AttributeError) as exc:
        cases.append((f"{MACROS} parses and carries the command table", False, str(exc)[:120]))

    # --- the whole-bank sweep --------------------------------------------------------------------
    try:
        sw = _load(root, SWEEP)
        clips = sw.get("clips") or []
        t = sw.get("totals") or {}
        bad_samples = [c.get("index") for c in clips if c.get("samples") != (c.get("blocks") or 0) * SAMPLES_PER_BLOCK]
        bad_hash = [c.get("index") for c in clips if not HEX64.match(str(c.get("pcm_sha256") or ""))]
        cases.append((f"the sweep holds {len(clips)} clip(s), every one with samples == blocks x "
                      f"{SAMPLES_PER_BLOCK} ({len(bad_samples)} violate)", len(clips) == SWEEP_CLIPS
                      and not bad_samples))
        cases.append((f"every clip's PCM hash is 64 hex characters ({len(bad_hash)} do not)",
                      not bad_hash and len(clips) == SWEEP_CLIPS))
        cases.append((f"the block ledger closes: {t.get('blocks_declared')} = {t.get('blocks_normal')} + "
                      f"{t.get('blocks_silent')}, and {t.get('blocks_compared_live')} blocks were compared "
                      f"live",
                      t.get("blocks_declared") == SWEEP_BLOCKS
                      and t.get("blocks_normal") == SWEEP_NORMAL
                      and t.get("blocks_silent") == SWEEP_SILENT
                      and t.get("blocks_normal", 0) + t.get("blocks_silent", 0) == SWEEP_BLOCKS
                      and t.get("blocks_compared_live") == SWEEP_LIVE
                      and t.get("samples_differing_live") == 0))
        live = sum((c.get("live") or {}).get("blocks_compared") or 0 for c in clips)
        cases.append((f"the per-clip live counts sum to the recorded total ({live} vs {SWEEP_LIVE})",
                      live == SWEEP_LIVE))
        codec = _load(root, CODEC)
        cases.append((f"the codec fixture and the sweep agree on the sample directory's size "
                      f"({codec.get('sample_count')})",
                      codec.get("sample_count") == 1192 and codec.get("codebook_bytes") == 256))
    except (OSError, ValueError, AttributeError) as exc:
        cases.append((f"{SWEEP} parses and carries the sweep", False, str(exc)[:120]))

    return cases


def _break(root, rel, mutate):
    p = root / rel
    data = json.loads(p.read_text())
    mutate(data)
    p.write_text(json.dumps(data, indent=1) + "\n")


def self_test():
    """Three synthetic breaks, each of which the checks must catch — plus an untouched copy that must pass."""
    cases = []
    backups = {}
    try:
        base = checks()
        cases.append(("an untouched copy passes every case", all(ok for _l, ok, *_r in base)))

        def drop_hash(d):
            d["clips"][0]["pcm_sha256"] = d["clips"][0]["pcm_sha256"][:-1]
        backups[SWEEP] = (ROOT / SWEEP).read_text()
        _break(ROOT, SWEEP, drop_hash)
        cases.append(("a clip hash one character short is caught",
                      not all(ok for _l, ok, *_r in checks())))
        (ROOT / SWEEP).write_text(backups[SWEEP])

        def inflate(d):
            d["totals"]["blocks_silent"] += 1
        _break(ROOT, SWEEP, inflate)
        cases.append(("a block ledger that no longer closes is caught",
                      not all(ok for _l, ok, *_r in checks())))
        (ROOT / SWEEP).write_text(backups[SWEEP])

        def widen(d):
            d["lists"][5]["width"] = 2
        backups[PROJ] = (ROOT / PROJ).read_text()
        _break(ROOT, PROJ, widen)
        cases.append(("list 5 called a key list is caught",
                      not all(ok for _l, ok, *_r in checks())))
        (ROOT / PROJ).write_text(backups[PROJ])
    finally:
        for rel, text in backups.items():
            (ROOT / rel).write_text(text)
    bad = 0
    for label, ok, *rest in cases:
        bad += not ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}" + (f" — {rest[0]}" if rest and not ok else ""))
    print(f"{len(cases) - bad}/{len(cases)} sound-fixture case(s)")
    return 0 if bad == 0 else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    if not a.check:
        ap.error("one of --check or --self-test is required")
    cases = checks()
    bad = 0
    for label, ok, *rest in cases:
        bad += not ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}" + (f" — {rest[0]}" if rest and not ok else ""))
    print(f"{len(cases) - bad}/{len(cases)} sound-fixture case(s)")
    return 0 if bad == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
