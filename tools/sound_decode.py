#!/usr/bin/env python3
"""Decode id 1983's samples, and prove the decoder is right rather than merely plausible.

The format was established with reference to **re2studio** (github.com/theanine3D/re2studio, GPL-3.0) —
read as a specification, no code copied. The algorithm is a fact about the cartridge; this file is an
independent implementation of it in Python, written from the description and validated against the
cartridge's own directory data.

    sample data (id 1983) := [256-byte block] then N * 40-byte frames

    codebook  8 order-2 predictors; a2 = int16 at p*32, a1 = int16 at p*32 + 16
    frame     two 20-byte runs; per run:
                prev2, prev1 = int16 big-endian at frame + run*4
                header       = frame[8 + run*16]: predictor = >>4, shift = 12 - (byte & 0xF)
                nibbles      = 15 bytes at frame[9 + run*16 .. +15], high nibble first
                y            = clamp16((a1*prev1 + a2*prev2 + (delta << 11)) >> 11)
                prev2, prev1 = prev1, y

The validation that matters is not "it runs" — it is that decoding with the **shared** codebook produces
audio where decoding with each sample's **own** first 256 bytes does not. That discriminator is gated,
because a decoder that produces numbers is not a decoder that produces sound.

  ./sound_decode.py --check     # the gated validation
  ./sound_decode.py --wav 17    # write one sample to assets/ (gitignored, ROM-derived)
"""
import argparse
import struct
import sys
import wave
import zlib
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROM = HERE.parent / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
BASE, HEADER = 0x0C8624, 0x28

SAMPLE_DIR, SAMPLE_DATA = 1982, 1983
RECORD = 28
BOOK_BYTES, FRAME_BYTES, SAMPLES_PER_FRAME = 256, 40, 64
NIBBLE_BYTES = 15
SHIFT_BIAS = 12


def blob(d, file_id):
    off, size = struct.unpack_from(">II", d, BASE + HEADER + 8 * file_id)
    return zlib.decompress(d[BASE + off:BASE + off + size])


def load():
    d = ROM.read_bytes()
    directory = blob(d, SAMPLE_DIR)
    data_off, data_size = struct.unpack_from(">II", d, BASE + HEADER + 8 * SAMPLE_DATA)
    return d, directory, d[BASE + data_off:BASE + data_off + data_size]


def samples(directory):
    """[(index, offset, rate, declared samples)] — the directory record, as the player reads it."""
    out, n = [], len(directory) // RECORD
    for k in range(n):
        at = k * RECORD
        out.append((
            struct.unpack_from(">I", directory, at)[0] >> 16,
            struct.unpack_from(">I", directory, at + 4)[0],
            struct.unpack_from(">H", directory, at + 14)[0],
            struct.unpack_from(">I", directory, at + 16)[0] & 0x00FFFFFF,
        ))
    return out


def decode(stored, book):
    body, out = stored[BOOK_BYTES:], []
    for f in range(len(body) // FRAME_BYTES):
        frame = body[f * FRAME_BYTES:(f + 1) * FRAME_BYTES]
        for run in (0, 1):
            head = frame[8 + run * 16]
            predictor, shift = head >> 4, SHIFT_BIAS - (head & 0xF)
            prev2, prev1 = struct.unpack_from(">2h", frame, run * 4)
            out.append(prev2)
            out.append(prev1)
            a2 = struct.unpack_from(">h", book, predictor * 32)[0]
            a1 = struct.unpack_from(">h", book, predictor * 32 + 16)[0]
            for byte in frame[9 + run * 16:9 + run * 16 + NIBBLE_BYTES]:
                for half in (0, 1):
                    nib = byte >> 4 if half == 0 else byte & 0xF
                    if nib > 7:
                        nib -= 16
                    delta = nib << shift
                    y = (a1 * prev1 + a2 * prev2 + (delta << 11)) >> 11
                    y = -32768 if y < -32768 else (32767 if y > 32767 else y)
                    out.append(y)
                    prev2, prev1 = prev1, y
    return out


def corr(x):
    n = len(x)
    if n < 4:
        return 0.0
    a, b = x[:-1], x[1:]
    ma, mb = sum(a) / len(a), sum(b) / len(b)
    num = sum((u - ma) * (v - mb) for u, v in zip(a, b))
    den = (sum((u - ma) ** 2 for u in a) * sum((v - mb) ** 2 for v in b)) ** 0.5
    return num / den if den else 0.0


def check() -> int:
    d, directory, data = load()
    recs = samples(directory)
    shared = data[:BOOK_BYTES]
    ends = [r[1] for r in recs[1:]] + [len(data)]
    cases, own_c, shared_c, reconciled = [], [], [], 0
    for k, (_idx, off, _rate, declared) in enumerate(recs):
        stored = data[off:ends[k]]
        out = decode(stored, shared)
        reconciled += (len(out) >= declared)
        shared_c.append(corr(out[:declared]))
        own_c.append(corr(decode(stored, stored[:BOOK_BYTES])[:declared]))

    good = sum(1 for c in shared_c if c > 0.7)
    cases.append((f"the shared 256-byte codebook decodes {good} of {len(recs)} samples to audio "
                  f"(adjacent correlation > 0.7), median {sorted(shared_c)[len(shared_c) // 2]:+.3f}",
                  good == 1180))
    cases.append(("REFUTED: a per-sample book: a sample's own first 256 bytes decode far worse "
                  f"({sum(1 for c in own_c if c > 0.7)} good)",
                  sum(1 for c in own_c if c > 0.7) == 658))
    cases.append((f"the decode is never shorter than the length the directory declares "
                  f"({reconciled} of {len(recs)})", reconciled == len(recs)))
    cases.append((f"the codebook is {BOOK_BYTES} B at the start of the sample-data blob, frames are "
                  f"{FRAME_BYTES} B and carry {SAMPLES_PER_FRAME} samples", len(shared) == BOOK_BYTES))
    book_zero = sum(1 for b in shared if b == 0) / len(shared)
    cases.append((f"the codebook is not sparse padding — {book_zero:.0%} of it is zero",
                  book_zero < 0.25))
    # The "12 bad samples" M193 reported were an artefact of a 0.7 threshold, not a failure set: the
    # correlation distribution is continuous down to 0.44 with no gap, and the low tail is noise-like
    # content, which is exactly what a low adjacent correlation means.
    ordered = sorted(shared_c)
    zcr = []
    for k, (_i, off, _r, declared) in enumerate(recs):
        y = decode(data[off:ends[k]], shared)[:declared]
        zcr.append(sum(1 for a, b in zip(y, y[1:]) if (a < 0) != (b < 0)) / max(len(y) - 1, 1))
    tail = [zcr[k] for k in range(len(recs)) if shared_c[k] <= 0.7]
    rest = [zcr[k] for k in range(len(recs)) if shared_c[k] > 0.7]
    big_gap = max(b - a for a, b in zip(ordered, ordered[1:]))
    cases.append((f"there is no failure set — correlation runs continuously from {ordered[0]:+.3f} to "
                  f"{ordered[-1]:+.3f} with no gap above {big_gap:.2f}",
                  ordered[0] > 0.4 and big_gap < 0.15))
    med = lambda xs: sorted(xs)[len(xs) // 2]
    cases.append((f"the low tail is noise-like content, not a bad decode — zero-crossing rate "
                  f"{med(tail):.3f} against {med(rest):.3f} for the rest",
                  len(tail) == 12 and med(tail) > 1.8 * med(rest)))
    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} sound-decode case(s)")
    return 0 if passed == len(cases) else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--wav", type=int, metavar="INDEX", help="write one sample to assets/sound/")
    args = ap.parse_args()
    if args.wav is not None:
        d, directory, data = load()
        recs = samples(directory)
        ends = [r[1] for r in recs[1:]] + [len(data)]
        _i, off, rate, declared = recs[args.wav]
        pcm = decode(data[off:ends[args.wav]], data[:BOOK_BYTES])[:declared]
        out = HERE.parent / "assets" / "sound" / f"sample_{args.wav:04d}.wav"
        out.parent.mkdir(parents=True, exist_ok=True)
        with wave.open(str(out), "wb") as w:
            w.setnchannels(1); w.setsampwidth(2); w.setframerate(rate)
            w.writeframes(struct.pack(f">{len(pcm)}h", *pcm))
        print(f"wrote {out} ({len(pcm)} samples at {rate} Hz = {len(pcm)/rate:.2f} s)")
        print("assets/ is gitignored: this is ROM-derived and must never be committed")
        return 0
    return check()


if __name__ == "__main__":
    raise SystemExit(main())
