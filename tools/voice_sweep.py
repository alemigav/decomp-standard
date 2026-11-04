#!/usr/bin/env python3
"""Verify the MORT transcription across all 588 clips, not the 13 clips M199 checked.

**What this claims.**

  * a **whole-bank transcription**. For every clip of cartridge id 1979, `voice_decode.transcribe()` decodes
    the clip to its declared end. Recorded per clip: the declared block count, the sample count it produced,
    a SHA-256 of the decoded PCM (samples packed little-endian `int16`), the rate, and whether the record's
    declared `length/4` reconciles.
  * a **block arithmetic that is not the transcription's own**. `ledger()` is a second reading of the stream's
    *framing* — the 1-bit silent flag, the 4-bit / 7-bit run lengths biased by one, 260 bits per normal block
    — and the runs it reads must consume the payload exactly once: `length_words_reconciles` is true when the
    declared word count equals the record's own length **and** the runs end inside the payload's final 32-bit
    word. Runs left over leave more than a word unread; a run short of the declared count overruns the buffer.
    Either makes the flag false, so the flag says the declared count and the run structure agree to the bit.
  * a **live differential that covers every clip**. `voice_decode.decode()` — the cartridge's own synthesis
    under Unicorn — compared sample for sample with the transcription on a stated stratum:

        every clip            blocks 0..15 (a 16-block prefix)                  588 clips, 9 408 blocks
        clips of <= 96 blocks the whole clip, so its last block is compared      46 clips, 3 365 blocks

    12 037 blocks against the cartridge, where M199 compared 634 across 13 clips.

**What this refuses.**

  * **no claim of a whole-clip live comparison.** `decode()` compares a *prefix*, so the live column is a
    stratum: 16 blocks of a long clip, the whole of a short one. `method` carries the measurement that forces
    this — reaching block j costs j+1 emulated blocks — and 542 of the 588 clips are in the first group, so a
    divergence that begins after block 16 of a clip longer than 96 blocks is invisible here.
  * **no claim that the hashes are evidence about the cartridge.** `pcm_sha256` is the transcription's own
    output: it catches a change in the transcription or in the bank between two sweeps, and says nothing about
    the cartridge. Only the live column is compared against the cartridge.
  * **no second decoder.** `ledger()` never reads a field the synthesis uses: it says where the runs end,
    never what the samples are. A wrong width *inside* a normal block (as opposed to the block's total size)
    is invisible to it, which is exactly what the live differential is for.
  * **no claim that `length_words_reconciles` is evidence about the synthesis.** The declared word count
    equals the record's own length, which the bank's loader already guarantees; all 588 agree. It is a fact
    about the records. The bit-exact consumption behind it is the part with teeth.
  * **no claim about the audio's meaning.** Nothing here maps a clip to a game event or a room, and a zero
    difference says only that the two agree on the compared blocks — not that either is the right take.

Usage:
  ./voice_sweep.py --sweep          # the expensive, manual mode: rewrite fixtures/sound/mort_sweep.json
  ./voice_sweep.py --check          # the gate: validate the committed evidence; 5 clips x 16 blocks live
"""
import argparse
import hashlib
import json
import multiprocessing
import os
import struct
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

import voice_decode as V                                              # noqa: E402

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

ARTEFACT = ROOT / "fixtures" / "sound" / "mort_sweep.json"
SCHEMA = "mort-sweep/1"
MAX_BYTES = 4 << 20            # the repository tracks no file larger than this, so neither does this tool

# The live stratum, as constants the gate re-derives rather than trusts: a row whose `blocks_compared` is
# not `plan(blocks)` is a sweep made under a different rule than the one this file states.
PREFIX = 16                    # blocks 0..15 of every clip
FULL_MAX = 96                  # every clip this short is compared whole, last block included
GATE_CLIPS = (0, 146, 293, 439, 587)   # evenly spaced over 0..587, so the gate spans the bank
GATE_BLOCKS = 16

# `transcribe()` reads, per normal block: SCALE_W for the eight scales, then four groups of GROUP_W plus
# 13 three-bit coefficients. Derived rather than written as 260, so the ledger cannot drift from the tables.
COEFS = 13
NORMAL_BITS = sum(V.SCALE_W) + 4 * (sum(V.GROUP_W) + 3 * COEFS)


def plan(blocks):
    """How many blocks of this clip the live differential compares: the whole clip, or a 16-block prefix."""
    return blocks if blocks <= FULL_MAX else min(PREFIX, blocks)


def _rel(path):
    """A path for a message: relative to the repository when it is inside it, absolute when it is not."""
    try:
        return path.relative_to(ROOT)
    except ValueError:
        return path


# --------------------------------------------------------------------------- the run-length ledger
def _bit(buf, q):
    """Bit `q` of the reader's 32-bit-word stream: big-endian words, bit 31 first, LSB within the word."""
    w = (q >> 5) * 4
    return (int.from_bytes(buf[w:w + 4], "big") >> (q & 31)) & 1


def _bits(buf, q, k):
    v = 0
    for i in range(k):
        v |= _bit(buf, q + i) << i
    return v


def ledger(record):
    """Read the record's framing only: how many blocks the runs declare, and where the last one ends.

    The stream is the reader's buffer (`record[12:]`, because the cartridge seeds `bitpos` to 0x60 = byte
    12), so the four header bytes after the extent are part of it. A run header is a 1-bit flag: set means a
    4-bit count of silent blocks, clear a 7-bit count of normal ones, both biased by one. A normal block then
    costs NORMAL_BITS and a silent one costs nothing.
    """
    total, rate, extent4 = struct.unpack_from(">HHI", record, 4)
    buf = record[12:]
    capacity = len(buf) * 8
    p, normal, silent = 0, 0, 0
    run_n = run_s = 0
    while normal + silent < total:
        if run_n == 0 and run_s == 0:
            if _bit(buf, p):
                p += 1
                run_s = _bits(buf, p, 4) + 1
                p += 4
            else:
                p += 1
                run_n = _bits(buf, p, 7) + 1
                p += 7
        if run_s:
            run_s -= 1
            silent += 1
        else:
            run_n -= 1
            normal += 1
            p += NORMAL_BITS
    return {"blocks": total, "bits": p, "capacity": capacity, "normal": normal, "silent": silent,
            # The declared length is the whole record in words, and the runs end inside the payload's last
            # word: 0 < capacity - p <= 32 is "left no more than the final word unread, and did not overrun".
            "reconciles": extent4 * 4 == len(record) and 0 < capacity - p <= 32}


# --------------------------------------------------------------------------- one clip, in a worker
_ROWS = None                   # the bank, inherited under `fork` and loaded lazily under `spawn`
_LIVE = False
_MOD = None


def _init(live):
    global _LIVE
    _LIVE = live


def _rows():
    global _ROWS
    if _ROWS is None:
        _ROWS = V.records()
    return _ROWS


def _task(index):
    """Transcribe one clip, hash it, ledger it, and (if asked) compare the plan's blocks with the cartridge."""
    global _MOD
    k, blocks, rate, record = _rows()[index]
    samples, st = V.transcribe(record, blocks)
    pcm = struct.pack("<%dh" % len(samples), *samples)
    led = ledger(record)
    row = {"index": k, "blocks": blocks, "rate": rate, "samples": len(samples),
           "pcm_sha256": hashlib.sha256(pcm).hexdigest(),
           "length_words_reconciles": led["reconciles"],
           "live": None,
           # Kept out of the fixture: the gate re-derives these to cross the ledger against the decoder.
           "ledger": {"blocks": led["blocks"], "normal": led["normal"], "silent": led["silent"],
                      "bits": led["bits"], "capacity": led["capacity"]},
           "decoder_silent": st["silent"]}
    if _LIVE:
        if _MOD is None:
            _MOD = V._unicorn()
        n = plan(blocks)
        ref, _st = V.decode(record, n, _MOD)
        mine = samples[:n * V.BLOCK_SAMPLES]
        differs = sum(1 for a, b in zip(ref, mine) if a != b)
        row["live"] = {"blocks_compared": n, "samples_differing": differs,
                       "samples_compared": min(len(ref), len(mine))}
    return row


def _context():
    """A `fork` context when the platform has one: the bank is then shared instead of re-read per worker."""
    methods = multiprocessing.get_all_start_methods()
    return multiprocessing.get_context("fork" if "fork" in methods else "spawn")


def _decode_all(jobs, live, limit=None):
    """Every clip through `_task`, in `jobs` processes (`jobs == 1` runs in this one, for debugging).

    The bank is loaded here, in the parent, before the pool exists: under `fork` the workers then inherit it
    instead of each re-reading the 64 MiB cartridge, which is most of a worker's start-up cost. Tasks go out
    longest clip first — a worker that picks up the 7 647-block clip last is the whole tail of the run — and
    the rows come back in index order, which is the order the artefact is written in.
    """
    available = len(_rows())
    want = list(range(available if limit is None else min(limit, available)))
    if jobs <= 1:
        _init(live)
        return [_task(i) for i in want]
    t0 = time.time()
    order = sorted(want, key=lambda i: -_rows()[i][1])
    with _context().Pool(jobs, initializer=_init, initargs=(live,)) as pool:
        # chunksize 1: the clips run from 26 to 7 647 blocks, so a chunk of four can hold the longest.
        out = list(pool.imap(_task, order, chunksize=1))
    out.sort(key=lambda row: row["index"])
    print("  %d clip(s) in %.1f s (%d process(es))" % (len(out), time.time() - t0, jobs))
    return out


# --------------------------------------------------------------------------- the sweep
def document(results, cart_sha):
    """The artefact: what was recorded, in the one shape `--check` reads."""
    clips = [{"index": r["index"], "blocks": r["blocks"], "samples": r["samples"],
              "pcm_sha256": r["pcm_sha256"], "rate": r["rate"],
              "length_words_reconciles": r["length_words_reconciles"],
              "live": {"blocks_compared": r["live"]["blocks_compared"],
                       "samples_differing": r["live"]["samples_differing"]}}
             for r in results]
    totals = {
        "clips": len(clips),
        "blocks_declared": sum(r["blocks"] for r in results),
        "blocks_normal": sum(r["ledger"]["normal"] for r in results),
        "blocks_silent": sum(r["ledger"]["silent"] for r in results),
        "samples": sum(r["samples"] for r in results),
        "clips_agreeing": sum(1 for r in results if r["live"]["samples_differing"] == 0),
        "blocks_compared_live": sum(r["live"]["blocks_compared"] for r in results),
        "samples_differing_live": sum(r["live"]["samples_differing"] for r in results),
    }
    return {"tool": "tools/voice_sweep.py", "schema": SCHEMA, "cart_sha256": cart_sha, "totals": totals,
            "clips": clips, "method": METHOD, "refusals": REFUSALS}


METHOD = [
    "the bank is cartridge id 1979 at 0x0338FEA: a u32 count, 588 u32 offsets (0x01000000|offset), each "
    "record `MORT`, u16 block count at +4, u16 rate at +6, u32 length/4 at +8, bit stream from +16 with the "
    "reader's bitpos seeded to 0x60.",
    "transcription: voice_decode.transcribe() over the whole clip. `samples` is what it returned and "
    "`pcm_sha256` is the SHA-256 of those samples packed little-endian int16 — the transcription's own "
    "output, so the hash is evidence about the transcription, not about the cartridge.",
    "block arithmetic: voice_sweep.ledger() reads the stream's framing independently of the synthesis — a "
    "1-bit silent flag, a 4-bit or 7-bit run length biased by one, 260 bits per normal block — and "
    "`length_words_reconciles` is true when the declared length/4 equals the record's own length in words "
    "and the runs end inside the payload's last 32-bit word (0 < capacity - bits <= 32: no more than the "
    "final word is left unread, and the buffer is never overrun).",
    "live differential: voice_decode.decode() (the cartridge's synthesis under Unicorn) is compared sample "
    "for sample with the transcription, over blocks 0..15 of every clip and over the whole clip for every "
    "clip of 96 blocks or fewer (46 clips, whose last blocks are therefore compared). 12 037 blocks in all.",
    "the stratum is a prefix because decode() compares prefixes: the machine is built fresh and run from "
    "block 0, so reaching block j costs j+1 emulated blocks. At the measured 9.6 ms/block the last block of "
    "every clip would be the whole 307 038-block differential, 2 956 s, which is the run this artefact "
    "replaces.",
    "the gate re-decodes every clip in python and re-reads its framing (no emulator), then compares 5 clips "
    "x 16 blocks with the cartridge, those clips being indices 0, 146, 293, 439 and 587 — evenly spaced over "
    "the bank, and the only part of `--check` that needs Unicorn.",
]

REFUSALS = [
    "only 12 037 of the bank's 307 038 blocks (3.9%) are compared against the cartridge. Every block of every "
    "clip is transcribed and hashed, but a divergence that begins after block 16 of a clip longer than 96 "
    "blocks would not be seen here: 542 of the 588 clips are compared on 16 blocks of a clip that can run to "
    "7 647. M199's deepest live comparison was 40 blocks; this sweep's is 96, a clip compared whole.",
    "`pcm_sha256` is the transcription's own output: it detects a change in the transcription or in the bank "
    "between two sweeps and says nothing about whether the cartridge agrees.",
    "`ledger()` is a second reading of the framing, not a second decoder: it never reads a field the synthesis "
    "uses, so a wrong width inside a normal block — as opposed to the block's total size — is invisible to it. "
    "That is what the live differential is for.",
    "`length_words_reconciles` is true for all 588 clips, and it has to be: the declared word count equals "
    "the record's own length, which is how the bank's loader finds the next record. The bit-exact "
    "consumption behind the flag is the part that could have failed.",
    "no claim about the audio's meaning. Nothing here maps a clip to a room, a sound or a game event, and "
    "zero differing samples says the two agree — not that either is the right take.",
]


def sweep(jobs, limit=None):
    """Rebuild the artefact from the cartridge. `--limit` prints a sample and writes nothing."""
    if not V.ROM.exists():
        sys.exit("cartridge not found: %s" % V.ROM)
    if V._unicorn() is None:
        sys.exit("no interpreter has %s; the live stratum needs it — run under `.venv/bin/python`"
                 % V.ENGINE)
    t0 = time.time()
    cart_sha = hashlib.sha256(V.ROM.read_bytes()).hexdigest()
    print("cartridge sha256 %s" % cart_sha)
    results = _decode_all(jobs, live=True, limit=limit)
    doc = document(results, cart_sha)
    totals = doc["totals"]
    print("%d clip(s): %d blocks (%d normal, %d silent), %d samples"
          % (totals["clips"], totals["blocks_declared"], totals["blocks_normal"], totals["blocks_silent"],
             totals["samples"]))
    print("  live: %d block(s) compared, %d sample(s) differing in %d clip(s)"
          % (totals["blocks_compared_live"], totals["samples_differing_live"],
             totals["clips"] - totals["clips_agreeing"]))
    print("  length/4 reconciles in %d of %d clip(s)"
          % (sum(1 for r in results if r["length_words_reconciles"]), len(results)))
    for r in results:
        if r["live"]["samples_differing"]:
            print("  DIFFERS clip %d: %d of %d samples differ over %d block(s)"
                  % (r["index"], r["live"]["samples_differing"], r["live"]["samples_compared"],
                     r["live"]["blocks_compared"]))
    if limit is not None:
        print("--limit %d: a sample, nothing written" % limit)
        return 0
    text = json.dumps(doc, indent=1, sort_keys=True) + "\n"
    size = len(text.encode())
    if size >= MAX_BYTES:
        print("refusing to write %d B: the repository tracks no file over %d B" % (size, MAX_BYTES))
        return 1
    ARTEFACT.write_text(text)
    print("wrote %s (%d B) in %.1f s"
          % (ARTEFACT.relative_to(ROOT), size, time.time() - t0))
    return 0 if totals["samples_differing_live"] == 0 else 1


# --------------------------------------------------------------------------- the gate
def check(jobs):
    """Validate the committed evidence; the cartridge last, and only the small stratum in the emulator."""
    since = time.time()
    try:
        doc = json.loads(ARTEFACT.read_text())
    except (OSError, ValueError) as exc:
        return report([("%s parses as JSON" % ARTEFACT.name, False, str(exc))])
    totals = doc.get("totals") or {}
    clips = doc.get("clips") or []
    cases = []

    cases.append(("the artefact names this tool and the schema this tool writes",
                  doc.get("tool") == "tools/voice_sweep.py" and doc.get("schema") == SCHEMA
                  and isinstance(doc.get("cart_sha256"), str) and len(doc["cart_sha256"]) == 64
                  and all(c in "0123456789abcdef" for c in doc["cart_sha256"]),
                  "got %r / %r / %s" % (doc.get("tool"), doc.get("schema"),
                                        str(doc.get("cart_sha256"))[:12])))

    indices = [row.get("index") for row in clips]
    cases.append(("all 588 clips are recorded once each, in order",
                  indices == list(range(588)),
                  "%d row(s), first %s, last %s" % (len(clips), indices[:4], indices[-4:])))

    def row_ok(row):
        blocks, samples = row.get("blocks"), row.get("samples")
        return (isinstance(blocks, int) and blocks > 0 and isinstance(samples, int)
                and samples == blocks * V.BLOCK_SAMPLES and row.get("rate") in (8000, 16000)
                and isinstance(row.get("pcm_sha256"), str) and len(row["pcm_sha256"]) == 64)

    bad = next((row.get("index") for row in clips if not row_ok(row)), None)
    cases.append(("every row's samples are its blocks x %d, and its rate one of the bank's two"
                  % V.BLOCK_SAMPLES, bad is None, "row %s" % bad))

    parts = (totals.get("blocks_normal"), totals.get("blocks_silent"))
    cases.append(("the totals close: normal + silent = declared = the rows' sum, and samples = 160 x declared",
                  all(isinstance(p, int) for p in parts)
                  and totals.get("clips") == len(clips) == 588
                  and totals.get("blocks_declared") == sum(row.get("blocks") or 0 for row in clips)
                  and sum(parts) == totals.get("blocks_declared")
                  and totals.get("samples") == sum(row.get("samples") or 0 for row in clips)
                  and totals.get("samples") == V.BLOCK_SAMPLES * (totals.get("blocks_declared") or 0),
                  "normal/silent %s against declared %s, rows %d"
                  % (parts, totals.get("blocks_declared"), len(clips))))

    off_plan = [(row.get("index"), (row.get("live") or {}).get("blocks_compared"), plan(row.get("blocks") or 0))
                for row in clips
                if (row.get("live") or {}).get("blocks_compared") != plan(row.get("blocks") or 0)]
    cases.append(("every clip is covered by the live stratum, at the size this tool's plan prescribes",
                  not off_plan and all((row.get("live") or {}).get("blocks_compared", 0) > 0 for row in clips),
                  "%d clip(s) off plan, first %s" % (len(off_plan), off_plan[:3])))

    live = [row.get("live") or {} for row in clips]
    differing = [row.get("index") for row in clips if (row.get("live") or {}).get("samples_differing")]
    cases.append(("the live totals add up and no compared sample differs",
                  totals.get("blocks_compared_live") == sum(x.get("blocks_compared") or 0 for x in live)
                  and totals.get("samples_differing_live") == sum(x.get("samples_differing") or 0 for x in live)
                  and totals.get("samples_differing_live") == 0
                  and totals.get("clips_agreeing") == sum(1 for x in live if x.get("samples_differing") == 0)
                  and totals.get("clips_agreeing") == len(clips),
                  "%s block(s), %s sample(s) differing, %s clip(s) agreeing%s"
                  % (totals.get("blocks_compared_live"), totals.get("samples_differing_live"),
                     totals.get("clips_agreeing"),
                     "" if not differing else "; clips that differ: %s" % differing[:8])))

    broken = [row.get("index") for row in clips if row.get("length_words_reconciles") is not True]
    cases.append(("every clip's declared length/4 reconciles with its own run structure",
                  not broken, "%d clip(s) do not, first %s" % (len(broken), broken[:3])))

    size = ARTEFACT.stat().st_size
    cases.append(("the artefact fits the repository's %d MiB track limit" % (MAX_BYTES >> 20),
                  size < MAX_BYTES, "%d B" % size))

    cases += cartridge_cases(doc, jobs)
    return report(cases, "%d clip(s) re-derived in %.1f s, %d process(es)"
                  % (len(clips), time.time() - since, jobs))


def cartridge_cases(doc, jobs):
    """The four cases that need the cartridge: three re-derivations in python, one 5-clip live differential.

    The bulk is python only. The emulator is confined to `GATE_CLIPS x GATE_BLOCKS`, which is what proves
    the harness has not rotted — and it fails, rather than skips, when the cartridge is here but no
    interpreter has Unicorn: a suite that goes quiet when its engine is absent is the failure mode this
    repository audits (voice_decode.py says the same in its own `--check`).
    """
    if not V.ROM.exists():
        why = "no cartridge at %s" % _rel(V.ROM)
        return [("the transcription re-derives every clip's declared blocks, rate, sample count and PCM hash",
                 None, why),
                ("the ledger re-derives every clip's length/4 and the recorded normal/silent split", None, why),
                ("the decoder's own silent tally agrees with the ledger, clip for clip", None, why),
                ("a %d-clip x %d-block live differential still agrees with the transcription"
                 % (len(GATE_CLIPS), GATE_BLOCKS), None, why)]

    rows = {r[0]: r for r in _rows()}
    fresh = _decode_all(jobs, live=False)

    def hash_case():
        for got in fresh:
            row = next((r for r in doc.get("clips") or [] if r.get("index") == got["index"]), None)
            k, blocks, rate, _rec = rows[got["index"]]
            if row is None:
                return (False, "clip %d is not in the artefact" % got["index"])
            for field, mine in (("blocks", blocks), ("rate", rate), ("samples", got["samples"]),
                                ("pcm_sha256", got["pcm_sha256"])):
                if row.get(field) != mine:
                    return (False, "clip %d: %s recorded %r, re-derived %r"
                            % (got["index"], field, row.get(field), mine))
        return (True, "%d clip(s), %d sample(s) re-hashed"
                % (len(fresh), sum(g["samples"] for g in fresh)))

    def ledger_case():
        recorded = doc["totals"]
        mine = {"blocks_declared": sum(g["ledger"]["blocks"] for g in fresh),
                "blocks_normal": sum(g["ledger"]["normal"] for g in fresh),
                "blocks_silent": sum(g["ledger"]["silent"] for g in fresh)}
        for field, got in mine.items():
            if recorded.get(field) != got:
                return (False, "%s recorded %r, re-read %r" % (field, recorded.get(field), got))
        flag = {r["index"]: r.get("length_words_reconciles") for r in doc.get("clips") or []}
        wrong = [g["index"] for g in fresh if flag.get(g["index"]) is not g["length_words_reconciles"]]
        if wrong:
            return (False, "%d clip(s) changed their length/4 verdict, first %s" % (len(wrong), wrong[:3]))
        slack = [g["ledger"]["capacity"] - g["ledger"]["bits"] for g in fresh]
        return (True, "%d normal + %d silent = %d, %d..%d bits of payload left over"
                % (mine["blocks_normal"], mine["blocks_silent"], mine["blocks_declared"],
                   min(slack), max(slack)))

    def silent_case():
        disagree = [(g["index"], g["ledger"]["silent"], g["decoder_silent"]) for g in fresh
                    if g["ledger"]["silent"] != g["decoder_silent"]]
        if disagree:
            return (False, "%d clip(s) disagree, first %s" % (len(disagree), disagree[:3]))
        total = sum(g["decoder_silent"] for g in fresh)
        return (total == doc["totals"].get("blocks_silent"),
                "%d silent block(s) from the decoder against %s recorded"
                % (total, doc["totals"].get("blocks_silent")))

    def live_case():
        mod = V._unicorn()
        if mod is None:
            return (False, "no interpreter has %s; run under `.venv/bin/python`" % V.ENGINE)
        recorded = {r.get("index"): (r.get("live") or {}) for r in doc.get("clips") or []}
        compared = differ = 0
        for k in GATE_CLIPS:
            _k, blocks, _rate, record = rows[k]
            n = min(GATE_BLOCKS, blocks)
            ref, _st = V.decode(record, n, mod)
            mine, _ms = V.transcribe(record, n)
            bad = sum(1 for a, b in zip(ref, mine) if a != b)
            if bad or len(ref) != len(mine):
                return (False, "clip %d differs in %d of %d sample(s)" % (k, bad, len(ref)))
            if recorded.get(k, {}).get("samples_differing") != 0:
                return (False, "clip %d is recorded with %r differing sample(s)"
                        % (k, recorded.get(k, {}).get("samples_differing")))
            compared += n
            differ += bad
        return (True, "%d block(s) compared over clips %s, %d sample(s) differ"
                % (compared, list(GATE_CLIPS), differ))

    return [("the transcription re-derives every clip's declared blocks, rate, sample count and PCM hash",
             ) + hash_case(),
            ("the ledger re-derives every clip's length/4 and the recorded normal/silent split",)
            + ledger_case(),
            ("the decoder's own silent tally agrees with the ledger, clip for clip",) + silent_case(),
            ("a %d-clip x %d-block live differential still agrees with the transcription"
             % (len(GATE_CLIPS), GATE_BLOCKS),) + live_case()]


def report(cases, note=""):
    """Print the cases and the tally line the gate suite keys on.

    A case may report `ok is None`, which is a SKIP: printed where it stands and counted in the tally,
    because the cartridge it needs is gitignored and no clone can supply it — the rule `acceptance.py`
    applies to a whole cartridge suite. The line still says SKIP, so nobody reads the tally as its evidence.
    """
    passed = 0
    for label, ok, extra in cases:
        if ok is None:
            passed += 1
            print("  SKIP %s: %s" % (label, extra))
            continue
        passed += bool(ok)
        print("  %s %s%s" % ("PASS" if ok else "FAIL", label, "" if ok else ": %s" % extra))
    if note:
        print("  %s" % note)
    print("\n%d/%d voice-sweep case(s)" % (passed, len(cases)))
    return 0 if passed == len(cases) else 1


# --------------------------------------------------------------------------- entry
def ensure_engine(argv):
    """Re-run under the project's venv when this interpreter has no emulator.

    Not `voice_decode.ensure_engine()`: that re-executes `voice_decode.py` itself with these arguments, which
    would land `--sweep` in another tool's parser. The comparison is `sys.prefix`, not the executables —
    a venv's `bin/python` is usually a symlink, so resolving the two paths makes them indistinguishable while
    their site-packages differ.
    """
    if V._unicorn() is not None:
        return True
    venv = ROOT / ".venv"
    venv_py = venv / "bin" / "python"
    if venv_py.exists() and Path(sys.prefix).resolve() != venv.resolve():
        os.execv(str(venv_py), [str(venv_py), str(Path(__file__).resolve())] + argv)
    return False


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0],
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--sweep", action="store_true",
                    help="re-transcribe the bank and rewrite fixtures/sound/mort_sweep.json")
    ap.add_argument("--check", action="store_true", help="validate the committed evidence")
    ap.add_argument("--jobs", type=int, default=0,
                    help="processes (default: one per cpu, capped at 10; 1 runs in this one)")
    ap.add_argument("--limit", type=int, metavar="CLIPS",
                    help="with --sweep: a sample of the bank, printed and not written (a development aid)")
    args = ap.parse_args()
    jobs = args.jobs or max(1, min(10, os.cpu_count() or 1))

    for flag in ("limit",):
        if getattr(args, flag) is not None and not args.sweep:
            ap.error("--%s is only meaningful with --sweep" % flag)
    if args.sweep == args.check:
        ap.error("exactly one of --sweep or --check is required")

    ensure_engine(sys.argv[1:])
    if args.sweep:
        return sweep(jobs, args.limit)
    return check(jobs)


if __name__ == "__main__":
    raise SystemExit(main())
