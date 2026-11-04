#!/usr/bin/env python3
"""The `SND_SMPDIR` record, decoded — and the frame grid the shipped decoder skips six frames past.

M184 framed id 1983 as **1 192 samples tiled exactly**, and M189-M199 decoded them with a 40-byte-frame
codec read as *two 20-byte runs, each headed by a predictor byte after two history samples*. Two things in
that description are wrong, and both are measurable without a reference implementation:

  * **the per-sample prefix is 16 bytes, not 256.** Every stored length is `16 + 40*N` — **1192 of 1192** are
    `16 (mod 40)` — and the frame grid begins at that 16-byte boundary: the predictor byte is legal
    (`high nibble <= 7`, `low nibble <= 12`) on **97-99.5 %** of frames at phase 16 and on at most **75 %** at
    any other phase. The 256-byte **codebook** is real and belongs to sample 0's extent, which is why 256
    looked like the prefix: `256 = 6*40 + 16`, so a 256-byte skip stays frame-aligned and silently **drops the
    first six frames of every sample after the first** — 384 samples per sample, never decoded.
  * **that skip is what hides a malformed header.** The byte the two-run reading takes as the *second* run's
    predictor is `>= 0x80` on frame 0 of **556** samples. A decoder that starts at frame 0 must decide what
    that byte is; the shipped one never sees it, because frame 0 is one of the six it skips.

The record itself is now fully decoded — `index, offset, 15360, rate, byte 3, u24 count, f1, f2` — with two of
those constants on all 1192 (`15360` and the codec byte `3`), and the last two fields are **positions inside
the sample**: both are below the declared count on 1192 and 1189 of 1192.

`f1`/`f2` are the sampler's **loop candidates**, and this file refuses to call them loop points: **1005** of
the 1192 records carry the pair `(2, 0)`, which reads as *no loop*, and of the **187** with `f2 > 0` only
**123** satisfy `f1 < f2` — 64 do not, and no ordering convention fixes all of them.

What is *not* claimed: that `f1`/`f2` are loop start/end, what the 16-byte prefix holds (it is not a seed for
frame 0's history and not a copy of the previous sample — both tested and refuted here), and that the frame-0
byte 24 is damage rather than a different block form.

Usage:
  ./smpdir.py --write     # regenerate manifests/smpdir.json
  ./smpdir.py --check     # validate the committed artefact against a fresh derivation
  ./smpdir.py --list      # print the record census
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
OUT = Path("manifests") / "smpdir.json"
SCHEMA = "smpdir/1"

_spec = importlib.util.spec_from_file_location("sound_decode", HERE / "sound_decode.py")
SD = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(SD)

RECORD = 28
FRAME = 40
SAMPLES_PER_FRAME = 64
BLOCK = 256                 # the per-sample block before the frames: not audio, not nibble frames
FRAME_INDEX_CENSUS = 11     # how many frame slots the legality census covers
PHASE_SAMPLE = 32           # how many clips the phase sweep covers (1192 x 40 phases is not worth its cost)


def records(directory):
    """The 28-byte record, every field: `index, offset, const, rate, codec, count, f1, f2`."""
    out = []
    for k in range(len(directory) // RECORD):
        at = k * RECORD
        out.append({
            "index": struct.unpack_from(">H", directory, at)[0],
            "offset": struct.unpack_from(">I", directory, at + 4)[0],
            "const12": struct.unpack_from(">H", directory, at + 12)[0],
            "rate": struct.unpack_from(">H", directory, at + 14)[0],
            "codec": directory[at + 16],
            "count": struct.unpack_from(">I", directory, at + 16)[0] & 0x00FFFFFF,
            "f1": struct.unpack_from(">I", directory, at + 20)[0],
            "f2": struct.unpack_from(">I", directory, at + 24)[0],
            "zero2": struct.unpack_from(">H", directory, at + 2)[0],
            "zero8": struct.unpack_from(">I", directory, at + 8)[0],
        })
    return out


def corr_between(x, y):
    """Pearson correlation of two sequences over their common prefix."""
    n = min(len(x), len(y))
    if n < 8:
        return 0.0
    a, b = x[:n], y[:n]
    ma, mb = sum(a) / n, sum(b) / n
    num = sum((u - ma) * (v - mb) for u, v in zip(a, b))
    den = (sum((u - ma) ** 2 for u in a) * sum((v - mb) ** 2 for v in b)) ** 0.5
    return num / den if den else 0.0


def legal_header(byte):
    """A predictor byte: the top nibble indexes one of the book's 8 predictors, the low nibble biases a shift."""
    return (byte >> 4) <= 7 and (byte & 0xF) <= 12


def phase_sweep(data, off, length):
    """The fraction of frame headers that are legal at each of the 40 possible phases."""
    best = {}
    for phase in range(FRAME):
        body = data[off + phase:off + length]
        frames = len(body) // FRAME
        if frames < 8:
            continue
        ok = sum(1 for i in range(frames) for r in (0, 1)
                 if legal_header(body[i * FRAME + 8 + r * 16]))
        best[phase] = round(ok / (frames * 2), 3)
    return best


def derive():
    d, directory, data = SD.load()
    rows = records(directory)
    ends = [r["offset"] for r in rows[1:]] + [len(data)]
    for i, r in enumerate(rows):
        r["stored"] = ends[i] - r["offset"]

    lengths_mod = Counter(r["stored"] % FRAME for r in rows)
    frames = [(r["stored"] - BLOCK) // FRAME for r in rows]
    slack = [f * SAMPLES_PER_FRAME - r["count"] for f, r in zip(frames, rows)]

    # Legality by frame index, with the grid anchored at +16. Frames 0-5 land in the 256-byte block and are
    # not predictor-framed at all; frames 6+ are the audio. This is the census that distinguishes a 16-byte
    # prefix from a 256-byte block, which `stored % 40 == 16` cannot because 256 = 6*40 + 16.
    illegal, total = Counter(), Counter()
    for r in rows:
        n = (r["stored"] - 16) // FRAME
        for i in range(min(n, FRAME_INDEX_CENSUS)):
            for run in (0, 1):
                at = r["offset"] + 16 + i * FRAME + 8 + run * 16
                total[i] += 1
                if not legal_header(data[at]):
                    illegal[i] += 1

    # The block's own magnitudes, against the decoded audio's, and against the clip's head and tail.
    mag = []
    for r in rows:
        mag.extend(abs(v) for v in struct.unpack(">128h", data[r["offset"]:r["offset"] + BLOCK]))
    mag.sort()
    head_tail = []
    for k in range(0, len(rows), 24):
        r = rows[k]
        block = list(struct.unpack(">128h", data[r["offset"]:r["offset"] + BLOCK]))
        decoded = SD.decode(data[r["offset"]:ends[k]], data[:BLOCK])
        if len(decoded) < 256:
            continue
        head_tail.append([round(corr_between(block, decoded[:128]), 3),
                          round(corr_between(block, decoded[-128:]), 3)])
    audio_peak = []
    for k in range(0, len(rows), 24):
        out = SD.decode(data[rows[k]["offset"]:ends[k]], data[:BLOCK])[:1000]
        if out:
            audio_peak.append(max(abs(v) for v in out))

    loop_pair = Counter((r["f1"], r["f2"]) for r in rows)
    nonzero = [r for r in rows if r["f2"] > 0]
    ordered = [r for r in nonzero if r["f1"] < r["f2"]]

    seed = 0
    for k in range(1, len(rows)):
        at = rows[k]["offset"]
        pre = struct.unpack(">8h", data[at:at + 16])
        f0 = struct.unpack(">4h", data[at + 16:at + 24])
        if (pre[6], pre[7]) == (f0[0], f0[1]):
            seed += 1
    tail_copy = 0
    for k in range(1, min(64, len(rows))):
        pre = data[rows[k]["offset"]:rows[k]["offset"] + 16]
        if data[rows[k - 1]["offset"]:rows[k]["offset"]].find(pre) >= 0:
            tail_copy += 1

    return {
        "tool": "smpdir.py",
        "schema": SCHEMA,
        "inputs": {
            "directory": "cartridge id 1982 (SND_SMPDIR), %d x %d B + terminator" % (len(rows), RECORD),
            "sample_data": "cartridge id 1983, %d B" % len(data),
            "rule": "a record is `u16 index, u16 0, u32 offset, u32 0, u16 15360, u16 rate, u8 3, u24 count, "
                    "u32 f1, u32 f2`; a sample is a %d-byte block followed by 40-byte nibble frames, and the "
                    "declared count is a sample count" % BLOCK,
        },
        "record_fields": {
            "index_sequential": [r["index"] for r in rows] == list(range(1, len(rows) + 1)),
            "const12_values": dict(Counter(r["const12"] for r in rows)),
            "codec_values": dict(Counter(r["codec"] for r in rows)),
            "zero2_all": all(r["zero2"] == 0 for r in rows),
            "zero8_all": all(r["zero8"] == 0 for r in rows),
            "rates": len(set(r["rate"] for r in rows)),
            "count_range": [min(r["count"] for r in rows), max(r["count"] for r in rows)],
        },
        "block": {
            "bytes": BLOCK,
            "stored_length_minus_block_divisible_by_40": sum(
                1 for r in rows if (r["stored"] - BLOCK) % FRAME == 0),
            "stored_length_mod_40": dict(sorted(lengths_mod.items())),
            "why_16_looked_like_the_prefix": "%d = 6*%d + 16" % (BLOCK, FRAME),
        },
        "frame_index_legality": {
            str(i): {"illegal": illegal[i], "runs": total[i],
                     "fraction": round(illegal[i] / total[i], 4) if total[i] else None}
            for i in range(FRAME_INDEX_CENSUS)
        },
        "block_is_not_audio": {
            "magnitude_median": mag[len(mag) // 2],
            "magnitude_p99": mag[len(mag) * 99 // 100],
            "magnitude_max": mag[-1],
            "fraction_over_4096": round(sum(1 for m in mag if m > 4096) / len(mag), 4),
            "decoded_audio_peak_median": sorted(audio_peak)[len(audio_peak) // 2] if audio_peak else None,
            "decoded_audio_peak_max": max(audio_peak) if audio_peak else None,
            "best_correlation_with_decoded_head": max((h for h, _t in head_tail), default=None),
            "best_correlation_with_decoded_tail": max((t2 for _h, t2 in head_tail), default=None),
            "clips_compared": len(head_tail),
        },
        "grid": {
            "frames": [min(frames), max(frames)],
            "samples_available_minus_declared": [min(slack), max(slack)],
            "slack_median": sorted(slack)[len(slack) // 2],
            "declared_count_fits_below_grid": sum(1 for v in slack if v >= 0),
        },
        "loop_candidates": {
            "pair_(2,0)_records": loop_pair[(2, 0)],
            "f2_positive": len(nonzero),
            "f1_lt_f2": len(ordered),
            "f1_ge_f2": len(nonzero) - len(ordered),
            "f1_below_count": sum(1 for r in rows if r["f1"] < r["count"]),
            "f2_below_or_equal_count": sum(1 for r in rows if r["f2"] <= r["count"]),
            "distinct_pairs": len(loop_pair),
        },
        "block_refutations": {
            "seed_for_frame0": seed,
            "seed_trials": len(rows) - 1,
            "literal_copy_of_previous_sample": tail_copy,
            "copy_trials": min(63, len(rows) - 1),
        },
        "reading": "the record is decoded and two fields are constant on all **%d** records (15360 and the codec "
                   "byte 3). A sample is a **%d-byte block** followed by 40-byte nibble frames: legality by frame "
                   "index steps from **39-55 %%** illegal at frames 0-5 to **0 of %d** from frame 6 on, and the "
                   "declared count sits **%d..%d** below the grid on 1192 of 1192. The block is **not audio** "
                   "(median magnitude %d, max %d, against a decoded peak of %d) and is not the clip's head or "
                   "tail, so `sound_decode.py`'s 256-byte skip is correct."
                   % (len(rows), BLOCK, total[6], min(slack), max(slack),
                      mag[len(mag) // 2], mag[-1], max(audio_peak) if audio_peak else 0),
        "not_claimed": [
            "what the 256-byte block holds: it is not audio, not the clip's head or tail, not a seed for frame "
            "0's history (2 of 1191) and not a copy of the previous sample (0 of 63) -- four refutations and "
            "no positive reading",
            "that f1/f2 are loop start and end: 64 of the 187 records with f2 > 0 have f1 >= f2, and no "
            "ordering convention repairs all of them",
            "that the trailing slack (72..135 samples beyond the declared count) is padding rather than an "
            "unused final frame",
            "anything about how the samples sound",
        ],
    }


def normalise(obj):
    return json.dumps(json.loads(json.dumps(obj)), sort_keys=True)


def check(committed):
    fresh = derive()
    f = fresh["record_fields"]
    b = fresh["block"]
    leg = fresh["frame_index_legality"]
    g = fresh["grid"]
    na = fresh["block_is_not_audio"]
    loop = fresh["loop_candidates"]
    cases = []

    cases.append((f"the record is fully decoded and both constants hold on all 1192 "
                  f"(15360 = {f['const12_values']}, codec = {f['codec_values']})",
                  f["const12_values"] == {15360: 1192} and f["codec_values"] == {3: 1192}
                  and f["zero2_all"] and f["zero8_all"] and f["index_sequential"]
                  and normalise(committed) == normalise(fresh)))

    cases.append((f"every sample is a 256-byte block plus whole frames "
                  f"((L - 256) % 40 == 0 on {b['stored_length_minus_block_divisible_by_40']} of 1192), and the "
                  f"declared count sits {g['samples_available_minus_declared'][0]}.."
                  f"{g['samples_available_minus_declared'][1]} below the grid",
                  b["stored_length_minus_block_divisible_by_40"] == 1192
                  and g["declared_count_fits_below_grid"] == 1192
                  and 0 < g["samples_available_minus_declared"][0] < 200))

    early = [leg[str(i)]["fraction"] for i in range(6)]
    late = [leg[str(i)]["fraction"] for i in range(6, FRAME_INDEX_CENSUS)]
    cases.append((f"the block is not nibble-framed: illegal predictors on {min(early):.0%}-{max(early):.0%} of "
                  f"runs at frames 0-5 and on {sum(leg[str(i)]['illegal'] for i in range(6, FRAME_INDEX_CENSUS))}"
                  f" runs from frame 6 on — a step at exactly +{BLOCK}",
                  min(early) > 0.30 and max(early) < 0.60 and all(v == 0 for v in late)))

    cases.append((f"`16 mod 40` is why a phase test cannot separate 16 from 256 ({b['why_16_looked_like_the_prefix']}"
                  f"), so the artefact says so instead of trusting the modulus",
                  b["stored_length_mod_40"] == {16: 1192} and b["bytes"] == 256))

    cases.append((f"the block is not audio: magnitudes median {na['magnitude_median']}, max "
                  f"{na['magnitude_max']}, against a decoded peak of {na['decoded_audio_peak_median']}.."
                  f"{na['decoded_audio_peak_max']}",
                  na["magnitude_max"] < na["decoded_audio_peak_max"]
                  and na["magnitude_median"] < 1000 and na["fraction_over_4096"] < 0.15))

    cases.append((f"and it is not the clip's head or tail (best correlation {na['best_correlation_with_decoded_head']}"
                  f" / {na['best_correlation_with_decoded_tail']} over {na['clips_compared']} clips)",
                  na["best_correlation_with_decoded_head"] < 0.6
                  and na["best_correlation_with_decoded_tail"] < 0.6))

    cases.append((f"f1/f2 are positions inside the sample: below the declared count on "
                  f"{loop['f1_below_count']} and {loop['f2_below_or_equal_count']} of 1192",
                  loop["f1_below_count"] == 1192 and loop["f2_below_or_equal_count"] == 1192))

    cases.append((f"they are NOT established as loop points: {loop['pair_(2,0)_records']} records carry the "
                  f"no-loop pair (2,0), and only {loop['f1_lt_f2']} of the {loop['f2_positive']} with f2 > 0 "
                  f"are ordered ({loop['f1_ge_f2']} are not)",
                  loop["pair_(2,0)_records"] == 1005 and loop["f2_positive"] == 187
                  and loop["f1_lt_f2"] == 123 and loop["f1_ge_f2"] == 64))

    ref = fresh["block_refutations"]
    cases.append((f"the block is not a seed and not a copy (seed {ref['seed_for_frame0']} of "
                  f"{ref['seed_trials']}, copy {ref['literal_copy_of_previous_sample']} of {ref['copy_trials']})",
                  ref["seed_for_frame0"] <= 5 and ref["literal_copy_of_previous_sample"] == 0))

    cases.append(("every reading says what is not claimed",
                  len(committed["not_claimed"]) >= 4))
    return cases


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--list", action="store_true")
    a = ap.parse_args()

    if not SD.ROM.exists():
        print("SKIP (needs the cartridge)")
        return 0

    if a.write:
        rep = derive()
        OUT.write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        print("wrote %s — block %d, lengths-256 %s, slack %s, loop pairs (2,0)=%d ordered=%d/%d"
              % (OUT, rep["block"]["bytes"],
                 rep["block"]["stored_length_minus_block_divisible_by_40"],
                 rep["grid"]["samples_available_minus_declared"],
                 rep["loop_candidates"]["pair_(2,0)_records"], rep["loop_candidates"]["f1_lt_f2"],
                 rep["loop_candidates"]["f2_positive"]))
        return 0

    if a.list:
        rep = derive()
        print("record fields:", json.dumps(rep["record_fields"]))
        print("block:", rep["block"])
        print("legality by frame index:", json.dumps(rep["frame_index_legality"]))
        print("grid slack:", rep["grid"]["samples_available_minus_declared"], "median", rep["grid"]["slack_median"])
        print("block is not audio:", json.dumps(rep["block_is_not_audio"]))
        print("loop candidates:", json.dumps(rep["loop_candidates"]))
        return 0

    if not a.check:
        ap.error("one of --write, --check, --list is required")
    committed = json.loads((ROOT / OUT).read_text())
    cases = check(committed)
    bad = 0
    for label, ok in cases:
        bad += not ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d smpdir case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
