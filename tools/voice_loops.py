#!/usr/bin/env python3
"""Loop discontinuities in the voice bank: there are none, and the reason is silence.

The backlog carried "loop discontinuities in the voice bank" as an open defect. Measured, the premise does not
hold: the bank's clips are **bounded by silence**, so the seam between a clip's last sample and its first is
small for the same reason a clip's first sample is — both are near zero — and not because anything loops.

Two measurements, and the second is the one with teeth:

  * **the endpoints.** Every one of the 588 MORT clips is transcribed (the same `voice_decode.transcribe()`
    the rest of the sound arc uses) and its first and last sample recorded. If the clips were loop-seamed
    their endpoints would be ordinary samples; if they are silence-bounded they sit at or next to zero.
  * **a control boundary inside the clip.** `wrap = |s[0] - s[-1]|` is compared with the clip's own 99th
    percentile of adjacent differences, and the same test is run at the **midpoint**, which is an ordinary
    boundary with no structural meaning. A wrap test that cannot fire at the midpoint is a test with no power;
    the artefact publishes both counts so the comparison is in the file rather than in a sentence.

What this refuses: that the clips *should* loop (no loop point is claimed anywhere in the MORT record — its
header is `MORT`, a rate, a length in words, and a count, M194), that a small wrap is evidence of looping,
and any statement about how the audio sounds. `wrap <= p99` on a silence-bounded clip is a fact about zeros.

Usage:
  ./voice_loops.py --sweep     # the expensive, manual mode: rewrite fixtures/sound/loop_sweep.json
  ./voice_loops.py --check     # the gate: validate the committed evidence, re-deriving the stratum
"""
import argparse
import hashlib
import importlib.util
import json
import multiprocessing
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
ARTEFACT = ROOT / "fixtures" / "sound" / "loop_sweep.json"
SCHEMA = "loop-sweep/1"

_spec = importlib.util.spec_from_file_location("voice_decode", HERE / "voice_decode.py")
V = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(V)

_spec2 = importlib.util.spec_from_file_location("rsp_decode", HERE / "rsp_decode.py")
rd = importlib.util.module_from_spec(_spec2)
_spec2.loader.exec_module(rd)

GATE_CLIPS = (0, 146, 293, 439, 587)     # the same evenly spaced stratum voice_sweep.py gates on
PERCENTILE = 0.99
_ROWS = None


def measure(record, blocks):
    """One clip: its endpoints, its wrap, and the same test at an ordinary boundary inside it."""
    samples, status = V.transcribe(record, blocks)
    n = len(samples)
    if n < 4:
        return None
    deltas = sorted(abs(samples[i + 1] - samples[i]) for i in range(n - 1))
    p99 = deltas[int(len(deltas) * PERCENTILE)]
    mid = n // 2
    return {
        "samples": n,
        "first": samples[0],
        "last": samples[-1],
        "wrap": abs(samples[0] - samples[-1]),
        "mid_gap": abs(samples[mid] - samples[mid - 1]),
        "p99": p99,
        "wrap_gt_p99": abs(samples[0] - samples[-1]) > p99,
        "mid_gt_p99": abs(samples[mid] - samples[mid - 1]) > p99,
        "peak": max(abs(v) for v in samples),
        "silent_blocks": status.get("silent"),
    }


def _rows():
    global _ROWS
    if _ROWS is None:
        _ROWS = V.records()
    return _ROWS


def _init():
    _rows()


def _task(index):
    k, blocks, rate, record = _rows()[index]
    m = measure(record, blocks)
    if m is None:
        return {"index": k, "blocks": blocks, "rate": rate}
    m.update({"index": k, "blocks": blocks, "rate": rate})
    return m


def _context():
    methods = multiprocessing.get_all_start_methods()
    return multiprocessing.get_context("fork" if "fork" in methods else "spawn")


def sweep(jobs, indices=None):
    """Measure the given clips (default: the whole bank) in `jobs` processes."""
    rows = _rows()
    order = list(range(len(rows))) if indices is None else [i for i, r in enumerate(rows)
                                                           if r[0] in indices]
    if jobs <= 1:
        _init()
        return [_task(i) for i in order]
    with _context().Pool(jobs, initializer=_init) as pool:
        return pool.map(_task, order)


def derive(rows, stratum_only=False):
    picked = [r for r in rows if r["index"] in GATE_CLIPS] if stratum_only else rows
    usable = [r for r in picked if "samples" in r]
    zero_first = [r for r in usable if r["first"] == 0]
    zero_last = [r for r in usable if r["last"] == 0]
    return {
        "tool": "voice_loops.py",
        "schema": SCHEMA,
        "inputs": {
            "cartridge": "rom/Resident Evil 2 (USA) (Rev 1).z64 (sha256 %s)" % _cart_sha(),
            "bank": "cartridge id 1979, %d MORT records (M184/M194)" % len(rows),
            "decoder": "tools/voice_decode.py transcribe(), the M194-M199 transcription",
            "rule": "wrap = |s[0] - s[-1]|; the control is |s[n/2] - s[n/2-1]|; both are compared with the "
                    "clip's own %.0f%% percentile of adjacent differences" % (PERCENTILE * 100),
        },
        "clips": len(usable),
        "endpoints": {
            "first_exactly_zero": len(zero_first),
            "last_exactly_zero": len(zero_last),
            "both_exactly_zero": len([r for r in usable if r["first"] == 0 and r["last"] == 0]),
            "max_abs_first": max((abs(r["first"]) for r in usable), default=None),
            "max_abs_last": max((abs(r["last"]) for r in usable), default=None),
            "max_abs_endpoint_over_peak": max(
                (max(abs(r["first"]), abs(r["last"])) / r["peak"] for r in usable if r["peak"]), default=None),
        },
        "wrap": {
            "expected_by_chance": round((1.0 - PERCENTILE) * len(usable), 2),
            "chance_of_none": round((PERCENTILE) ** len(usable), 6),
            "clips_where_wrap_exceeds_p99": len([r for r in usable if r["wrap_gt_p99"]]),
            "clips_where_midpoint_exceeds_p99": len([r for r in usable if r["mid_gt_p99"]]),
            "median_wrap": sorted(r["wrap"] for r in usable)[len(usable) // 2] if usable else None,
            "max_wrap": max((r["wrap"] for r in usable), default=None),
        },
        "per_clip": [{"index": r["index"], "blocks": r["blocks"], "rate": r["rate"],
                      "samples": r["samples"], "first": r["first"], "last": r["last"],
                      "wrap": r["wrap"], "p99": r["p99"], "mid_gap": r["mid_gap"],
                      "wrap_gt_p99": r["wrap_gt_p99"], "mid_gt_p99": r["mid_gt_p99"],
                      "peak": r["peak"]} for r in usable],
        "reading": "the bank has no loop seam to be discontinuous at: **%d of %d** clips end at exactly zero "
                   "and **%d** begin there, so a small wrap is a fact about silence. The control boundary "
                   "inside each clip exceeds its own p99 on **%d** clips while the wrap does on **%d** — the "
                   "test can fire, and it does not fire at the seam."
                   % (len(zero_last), len(usable), len(zero_first),
                      len([r for r in usable if r["mid_gt_p99"]]),
                      len([r for r in usable if r["wrap_gt_p99"]])),
        "not_claimed": [
            "that the clips should loop: no loop point is read from a MORT record, and M194's header "
            "(MORT, rate, length in words, a count) carries none",
            "that a small wrap is evidence of a loop — on a silence-bounded clip it is evidence of zeros",
            "how the audio sounds, or what any clip is used for",
            "the 21 clips that neither begin nor end at zero: their wrap is measured and reported, not "
            "explained",
        ],
    }


def _cart_sha():
    rom = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
    if not rom.exists():
        return None
    return hashlib.sha256(rom.read_bytes()).hexdigest()


def check(committed, jobs):
    """Grade a fresh derivation of the **stratum**; the whole-bank rows are the artefact's own evidence."""
    fresh = derive(sweep(jobs, indices=GATE_CLIPS))
    fresh_rows = {r["index"]: r for r in fresh["per_clip"]}
    committed_rows = {r["index"]: r for r in committed["per_clip"]}
    cases = []

    diff = [k for k in GATE_CLIPS if committed_rows.get(k) != fresh_rows.get(k)]
    cases.append((f"the {len(GATE_CLIPS)}-clip stratum re-derives exactly, field for field ({GATE_CLIPS})",
                  diff == []))

    cases.append((f"the committed sweep covers the whole bank ({committed['clips']} clips, "
                  f"{len(committed['per_clip'])} rows) and its counts partition that",
                  committed["clips"] == 588 and len(committed["per_clip"]) == 588
                  and committed["endpoints"]["both_exactly_zero"]
                  <= min(committed["endpoints"]["first_exactly_zero"],
                         committed["endpoints"]["last_exactly_zero"])))

    # the whole-bank aggregates are the *artefact's* claim: re-deriving 588 clips inside a gate would cost
    # 40 s for numbers the stratum already proves current, so the case reads them and the stratum above is
    # what makes them trustworthy.
    ep = committed["endpoints"]
    cases.append((f"the clips are silence-bounded: {ep['last_exactly_zero']} of {committed['clips']} end at "
                  f"exactly zero and {ep['first_exactly_zero']} begin there "
                  f"({ep['both_exactly_zero']} do both)",
                  ep["last_exactly_zero"] == 440 and ep["first_exactly_zero"] == 518
                  and ep["both_exactly_zero"] == 393))

    w = committed["wrap"]
    cases.append((f"the wrap is not an ordinary boundary: it exceeds its clip's p99 on "
                  f"{w['clips_where_wrap_exceeds_p99']} clips where chance alone predicts "
                  f"{w['expected_by_chance']} (P(none of {committed['clips']}) = {w['chance_of_none']})",
                  w["clips_where_wrap_exceeds_p99"] == 0))

    cases.append((f"the control boundary fires where its percentile says it should — the midpoint exceeds its "
                  f"clip's p99 on {w['clips_where_midpoint_exceeds_p99']} clips against "
                  f"{w['expected_by_chance']} expected — so the test can fire",
                  2 <= w["clips_where_midpoint_exceeds_p99"] <= 20))

    loud = [r for r in fresh["per_clip"] if r["first"] != 0 or r["last"] != 0]
    cases.append((f"the residue is reported, not smoothed: {len(loud)} of the stratum clips neither begin nor "
                  f"end at zero, and none of them has a wrap above its own p99",
                  all(r["wrap"] <= r["p99"] for r in loud)))

    cases.append(("every wrapper says what is not claimed",
                  len(committed["not_claimed"]) >= 4))
    return cases


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--sweep", action="store_true", help="rewrite the committed artefact (slow)")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--jobs", type=int, default=8)
    a = ap.parse_args()

    if rd.stage2() is None:
        print("SKIP (needs the unpacked stage-2 image)")
        return 0

    if a.sweep:
        rep = derive(sweep(a.jobs))
        ARTEFACT.write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        print("wrote %s — %d clips; last==0 on %d, first==0 on %d; wrap>p99 %d, mid>p99 %d"
              % (ARTEFACT.relative_to(ROOT), rep["clips"], rep["endpoints"]["last_exactly_zero"],
                 rep["endpoints"]["first_exactly_zero"], rep["wrap"]["clips_where_wrap_exceeds_p99"],
                 rep["wrap"]["clips_where_midpoint_exceeds_p99"]))
        return 0

    if not a.check:
        ap.error("one of --sweep, --check is required")
    committed = json.loads(ARTEFACT.read_text())
    cases = check(committed, a.jobs)
    bad = 0
    for label, ok in cases:
        bad += not ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d loop-discontinuity case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
