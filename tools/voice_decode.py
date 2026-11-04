#!/usr/bin/env python3
"""Decode the `MORT` voice bank to audio by executing the cartridge's own synthesis.

Why the audio is produced by emulation rather than by a transcription: `FUN_800b6634` calls
`FUN_800b6788` and `FUN_800b6470` through registers Ghidra does not model — the pseudocode renders them as
`FUN_800b6788()` with no arguments and `(*in_t3)()` eight times, and their real inputs are `t0`, `t1`, `t3`
and `t6`–`t9` plus `s0`–`s7`. There is nothing faithful to transcribe from the pseudocode alone. So this
tool runs the instructions: `stage2.elf`'s code under Unicorn, with the DMA ring filled by the host the way
`FUN_800b4a04` fills it, and the 0x140-byte output captured per block.

What is host-supplied, stated plainly:
  * the band's record bytes, placed in the ring at the window the reader asks for (`(bitpos>>3) & ~0xFFF`);
  * `memset` (`0x80006650`, in the boot image) as a host primitive, because the silent block's only work is
    `memset(out, 0x140)` and emulating libultra's implementation buys no information.

Everything else — the bit reader, the field layout, the dequantisation, the pitch predictor, the lattice,
the polyphase mix — is the cartridge's own code. `--check` reports what came out, and the numbers are the
cartridge's, not a claim about a reimplementation.

  ./voice_decode.py --check                 # the gated cases
  ./voice_decode.py --audio <clip>          # write assets/sound/mort_<clip>.wav
  ./voice_decode.py --clips                 # the bank census
"""
import argparse
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

ROM = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
STAGE2 = ROOT / "assets" / "unpacked" / "00000_0014420_1172240.bin"
WAVDIR = ROOT / "assets" / "sound"

BASE, HEADER = 0x0C8624, 0x28
BANK_CART, BANK_SIZE = 0x0338FEA, 8560916
MORT = b"MORT"

# The synthesis, as addresses. `CODE` is FUN_800b53f4: one 160-sample block per call.
CODE = 0x800B53F4
MEMSET = 0x80006650
SENT = 0x80300000
CTX, OUT, PAY = 0x00180000, 0x00190000, 0x001A0000
RING, BLOCK_BYTES, BLOCK_SAMPLES = 0x1A0, 0x140, 160
STAGE2_MIRROR = 0x18A80          # KSEG0 0x80018a80, seen through the physical mirror


def records():
    """The 588 `MORT` records of id 1979, as (index, blocks, rate, record bytes)."""
    d = ROM.read_bytes()
    r4 = d[BANK_CART:BANK_CART + BANK_SIZE]
    n = struct.unpack_from(">I", r4, 0)[0]
    vals = struct.unpack_from(">" + str(n) + "I", r4, 4)
    offs = [v & 0xFFFFFF for v in vals] + [len(r4)]
    out = []
    for k in range(n):
        rec = r4[offs[k]:offs[k + 1]]
        if rec[:4] == MORT:
            blocks, rate, _extent4 = struct.unpack_from(">HHI", rec, 4)
            out.append((k, blocks, rate, rec))
    return out


ENGINE = "unicorn"


def _unicorn():
    try:
        from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_BIG_ENDIAN, UC_HOOK_CODE
        from unicorn.mips_const import (UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3,
                                        UC_MIPS_REG_PC, UC_MIPS_REG_RA, UC_MIPS_REG_SP)
    except ImportError:
        return None
    return (Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_BIG_ENDIAN, UC_HOOK_CODE,
            UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3,
            UC_MIPS_REG_PC, UC_MIPS_REG_RA, UC_MIPS_REG_SP)


def ensure_engine(argv=None):
    """Re-run under the project's venv when this interpreter has no emulator.

    The gates are stdlib-only and run under `sys.executable`; the emulator is a development-only package
    (`.venv`, not a dependency of any other gate). So the tool looks for one the way `t64_selftest.py`
    looks for a C compiler: try, then a known location, then say so out loud. It never quietly passes.
    """
    if _unicorn() is not None:
        return True
    venv = ROOT / ".venv"
    venv_py = venv / "bin" / "python"
    # Compare `sys.prefix`, not the executables: a venv's `bin/python` is usually a symlink to the system
    # interpreter, so resolving paths makes the two indistinguishable while the *site-packages* differ.
    if venv_py.exists() and Path(sys.prefix).resolve() != venv.resolve():
        import os
        os.execv(str(venv_py), [str(venv_py), str(Path(__file__).resolve())]
                 + (argv if argv is not None else sys.argv[1:]))
    return False


def _session(record, uc_mod):
    """A mapped 4 MiB machine with the stage-2 image, the boot `memset`, and this record's bytes."""
    (Uc, ARCH, MODE32, BE, HOOK, R_A0, R_A1, R_A2, R_A3, R_PC, R_RA, R_SP) = uc_mod
    ram = bytearray(0x400000)
    s2 = STAGE2.read_bytes()
    ram[STAGE2_MIRROR:STAGE2_MIRROR + len(s2)] = s2
    ram[0x480:0x480 + len(ROM.read_bytes()[0x1000:0x14600])] = ROM.read_bytes()[0x1000:0x14600]
    ram[PAY:PAY + len(record)] = record
    uc = Uc(ARCH, MODE32 | BE)
    uc.mem_map(0x0, len(ram))
    uc.mem_write(0x0, bytes(ram))
    uc.mem_write(CTX + 0x11C8, struct.pack(">I", 0x60))     # the reader starts at byte 12: the header
    stats = {"steps": 0, "memset": 0}
    uc.mem_write(CTX + 0x11C8, struct.pack(">I", 0x60))

    def hook(u, addr, size, data):
        # Per-block budget, not cumulative: `emu_start` is called once per block, so a running total would
        # start cutting blocks off once the clip as a whole passed the limit.
        stats["block_steps"] = stats.get("block_steps", 0) + 1
        stats["steps"] += 1
        if stats["block_steps"] > 400000:
            u.emu_stop()
        if addr == MEMSET:
            u.mem_write(u.reg_read(R_A0), bytes(u.reg_read(R_A1)))
            stats["memset"] += 1
            u.reg_write(R_PC, u.reg_read(R_RA))

    uc.hook_add(HOOK, hook)
    return uc, ram, stats


def decode(record, blocks, uc_mod, verbose=False):
    """Run the cartridge's synthesis for `blocks` blocks; returns (samples, stats)."""
    (Uc, ARCH, MODE32, BE, HOOK, R_A0, R_A1, R_A2, R_A3, R_PC, R_RA, R_SP) = uc_mod
    uc, ram, stats = _session(record, uc_mod)
    samples, silent = [], 0
    for bi in range(blocks):
        bitpos = struct.unpack(">I", uc.mem_read(CTX + 0x11C8, 4))[0]
        win = (bitpos >> 3) & ~0xFFF
        chunk = bytes(ram[PAY + win:PAY + win + 0x1000])
        uc.mem_write(CTX + RING, chunk + bytes(0x1000 - len(chunk)))
        uc.reg_write(R_SP, 0x003FF000)
        uc.reg_write(R_RA, SENT)
        uc.reg_write(R_A0, CTX)
        uc.reg_write(R_A1, OUT)
        uc.reg_write(R_A2, 0)
        uc.reg_write(R_A3, 0)
        stats["block_steps"] = 0
        uc.emu_start(CODE, SENT, count=4000000)
        blk = struct.unpack(">160h", uc.mem_read(OUT, BLOCK_BYTES))
        if not any(blk):
            silent += 1
        samples.extend(blk)
        if verbose:
            print("  block %3d  bitpos 0x%05x  peak %5d" % (bi, struct.unpack(">I", uc.mem_read(
                CTX + 0x11C8, 4))[0], max(map(abs, blk))))
    stats["silent"] = silent
    return samples, stats


def stats_of(s):
    n = len(s)
    mean = sum(s) / n
    den = sum((x - mean) ** 2 for x in s)
    r1 = (sum((s[i] - mean) * (s[i + 1] - mean) for i in range(n - 1)) / den) if den else 0.0
    return {"samples": n, "peak": max(map(abs, s)), "rms": (sum(x * x for x in s) / n) ** 0.5,
            "clipped": sum(1 for x in s if abs(x) >= 32767), "lag1": r1,
            "zero": sum(1 for x in s if x == 0)}


def write_wav(path, samples, rate):
    import wave
    path.parent.mkdir(parents=True, exist_ok=True)
    with wave.open(str(path), "wb") as w:
        w.setnchannels(1)
        w.setsampwidth(2)
        w.setframerate(rate)
        w.writeframes(struct.pack("<%dh" % len(samples), *samples))


CLIP = 27            # 26 blocks, 0.26 s: short enough to run in the suite, long enough to have a frame


def check():
    cases = []
    rows = records()
    cases.append(("588 `MORT` records in id 1979", len(rows) == 588))
    mod = _unicorn()
    if mod is None:
        # A loud failure, not a skip: a suite that goes quiet when its engine is missing is the failure
        # mode this repository audits. `--check` re-executes under `.venv` when it can (see
        # `ensure_engine`), so reaching here means no interpreter on this machine has the emulator.
        print("  FAIL no interpreter has %s: `.venv/bin/python` is absent and this python cannot import it"
              % ENGINE)
        print("       the audio cases need it; `python3 -m pip install unicorn` or a project venv")
        print("\n1/7 voice-decode case(s)")
        return 1
    rec = [r for r in rows if r[0] == CLIP][0]
    samples, st = decode(rec[3], rec[1], mod)
    s = stats_of(samples)
    cases.append(("clip %d decodes to %d blocks x %d samples = %d" % (CLIP, rec[1], BLOCK_SAMPLES,
                                                                    len(samples)),
                  len(samples) == rec[1] * BLOCK_SAMPLES))
    cases.append(("the synthesis ran: the silent blocks are exactly zero and the rest are not (%d/%d silent)"
                  % (st["silent"], rec[1]), 0 < st["silent"] < rec[1]))
    cases.append(("nothing is railed: %d samples at full scale, peak %d" % (s["clipped"], s["peak"]),
                  s["clipped"] == 0 and 0 < s["peak"] < 32767))
    cases.append(("it is voiced, not noise: lag-1 correlation %+.3f" % s["lag1"], s["lag1"] > 0.5))
    cases.append(("the level is a level: rms %.0f inside (0, peak]" % s["rms"],
                  0 < s["rms"] <= s["peak"]))
    cases.append(("the `memset` path was taken %d time(s), i.e. a silent run was decoded" % st["memset"],
                  st["memset"] > 0))
    # --- the differential: the transcription must agree with the cartridge sample for sample.
    # Two clips, chosen for depth (5058 blocks) and for having an early frame: 634 blocks across 13
    # clips agreed when this landed, but the gate pins two of them so a regression fails here.
    for cid, nblk in ((27, 26), (2, 40)):
        crec = [r for r in rows if r[0] == cid][0]
        ref, _st = decode(crec[3], nblk, mod)
        mine, _ms = transcribe(crec[3], nblk)
        bad = sum(1 for x, y in zip(ref, mine) if x != y)
        cases.append(("the transcription reproduces clip %d block for block: %d samples, %d differ"
                      % (cid, len(ref), bad),
                      len(ref) == len(mine) and bad == 0))
    passed = sum(1 for _l, ok in cases if ok)
    for label, ok in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("\n%d/%d voice-decode case(s)" % (passed, len(cases)))
    return 0 if passed == len(cases) else 1


# --------------------------------------------------------------------------- the transcription
# Everything below reimplements the cartridge's synthesis in Python. It is graded against the emulator
# (see the two differential cases in `check`) rather than trusted: 13 clips / 634 blocks agree sample for
# sample. Semantics that are easy to get wrong, all of them established by breakpoint, are marked.

S16 = lambda v: ((int(v) + 0x8000) & 0xFFFF) - 0x8000      # a halfword store truncates, never saturates
S32 = lambda v: ((int(v) + 0x80000000) & 0xFFFFFFFF) - 0x80000000

SCALE_TABLE = bytes([0xC7, 0xD7, 0xE3, 0xE7, 0xF1, 0xF3, 0xF5, 0xF7])   # signed bytes at 0x800b63ac
GAIN_TABLE = (0x0CCD, 0x2CCD, 0x5333, 0x7FFF)                           # u16 at 0x800b6468
SCALE_W = (6, 6, 5, 5, 4, 4, 3, 3)
GROUP_W = (7, 2, 2, 6)


def _kernel(which, a, b):
    """The four bank-mix kernels at 0x800b682c / 6844 / 6854 / 686c, with the shared shaper.

    The shaper is THREE segments. It was two in my first reading, and the knee was at the wrong place:
    probed off K4 directly, 11060 -> 22119 (= a + 11059), 20070 -> 31129, 25000 -> 32362
    (= (a>>2) + 26112). Below 11059 it is a plain doubling.
    """
    t = ((a >> 2) + (b >> 1) + (b >> 2) if which == 0 else
         (a >> 1) + (b >> 1) if which == 1 else
         (a >> 1) + (a >> 2) + (b >> 2) if which == 2 else a)
    neg = t < 0
    if neg:
        t = -t
    if t <= 11059:
        t = t * 2
    elif t <= 20070:
        t = t + 11059
    else:
        t = (t >> 2) + 26112
    if t > 32767:
        t = 32767
    if neg:
        t = -t
    return t & 0xFFFF


def _dequant(D, phase, coefs):
    """FUN_800b62c0: 13 coefficients in place, then scattered into a 40-short table at stride 3."""
    if D <= 7:
        byte = SCALE_TABLE[D]
        b = byte - 256 if byte & 0x80 else byte
        r, k = b >> 4, b & 7
    else:
        r, k = (D - 8) >> 3, D & 7
    rate = k * 0x800 + 0x47FF
    rd, n = 1 << ((5 - r) & 31), (6 - r) & 31
    tab = [0] * 40
    for i, c in enumerate(coefs):
        v = S32(S32(S32(c) * 0x2000 - 0x7000) * rate)
        v = S32(v + 0x4000) >> 15
        v = (S32(v + rd) >> n) if n else S32(v + rd)
        tab[phase + 3 * i] = S16(v)
    return tab


def _predict(hist, period, A, B, table):
    """FUN_800b63b4: latch the period, shift the history down by 40, append 40 predicted+residual samples.

    The window is read AFTER the shift (`hist[120-lag+i]` of the shifted array) — verified against the
    cartridge on frame 2, where the pre-shift reading is wrong on 26..40 of 40 samples.
    """
    if 40 <= A <= 120:
        period = A
    gain = GAIN_TABLE[B & 3]
    for i in range(0x78):
        hist[i] = hist[i + 40]
    for i in range(0x28):                       # 40, not 39: `bgtz` tests the pre-decrement counter
        src = hist[0x78 - period + i]
        pred = (S32(S16(src) * gain) + 0x4000) >> 15
        hist[0x78 + i] = S16(pred + table[i])
    return period


def _coefficients(scales):
    """FUN_800b4dc0's eight affines, each `(x*0x400 + C) * M + 0x4000 >> 15 << 1` with 32-bit wrap."""
    s = scales

    def aff(x, c, m):
        return S16(S16((S32((x * 0x400 + c) * m) + 0x4000) >> 15) << 1)

    def lin(x, c, m):
        return S16(S16((S32((x + c) * m) + 0x4000) >> 15) << 1)

    return [lin(s[0], -0x20, 0xCCCC00), lin(s[1], -0x20, 0xCCCC00),
            aff(s[2], -0x5000, 0x3333), aff(s[3], -0x2C00, 0x3333),
            aff(s[4], -0x20BC, 0x4B17), aff(s[5], -0x1200, 0x4444),
            aff(s[6] - 4, 0x2AA, 0x7ADE), aff(s[7], -0x710, 0x740C)]


def _lattice(res, out, base, count, taps, state, acc):
    """FUN_800b6470: 8 subtractions, then 7 updates from the PRE-update neighbours, then the shaper.

    The updates are interleaved with the subtractions and each uses `t2` as it stands at that point, so
    they are spelled out rather than looped: `s_k <- (c_(k-1)*t2 + 0x4000)>>15 + s_(k-1)`.
    """
    s = state
    f = lambda c, v: (S32(c * v) + 0x4000) >> 15
    for k in range(count):
        t2 = S16(res[base + k])
        t2 = S32(t2 - f(s[7], taps[7])); t2 = S32(t2 - f(s[6], taps[6])); n7 = S32(f(taps[6], t2) + s[6])
        t2 = S32(t2 - f(s[5], taps[5])); n6 = S32(f(taps[5], t2) + s[5])
        t2 = S32(t2 - f(s[4], taps[4])); n5 = S32(f(taps[4], t2) + s[4])
        t2 = S32(t2 - f(s[3], taps[3])); n4 = S32(f(taps[3], t2) + s[3])
        t2 = S32(t2 - f(s[2], taps[2])); n3 = S32(f(taps[2], t2) + s[2])
        t2 = S32(t2 - f(s[1], taps[1])); n2 = S32(f(taps[1], t2) + s[1])
        t2 = S32(t2 - f(s[0], taps[0])); n1 = S32(f(taps[0], t2) + s[0])
        s[7], s[6], s[5], s[4], s[3], s[2], s[1], s[0] = n7, n6, n5, n4, n3, n2, n1, S32(t2)
        acc = S32(t2 + ((S32(acc * 0x6E14) + 0x4000) >> 15))
        y = S32(acc << 1)
        m = ((S32(y) >> 15) + 1) >> 1
        v = S16(y) if m == 0 else (-0x8000 if m < 0 else 0x7FFF)
        out[base + k] = S16(v & 0xFFF8)         # `andi` keeps the sign bits; the halfword store re-signs
    return acc


def _new_ctx():
    return {"hist": [0] * 200, "s": [0] * 8, "acc": 0, "period": 0,
            "bank0": [0] * 8, "bank1": [0] * 8, "toggle": 0, "out": [0] * 160}


def _block(ctx, scales, groups):
    """One 160-sample block: four groups' tables, four predictions, then the mixer."""
    tables = [_dequant(D, C, cf) for (A, B, C, D, cf) in groups]
    for g, (A, B, C, D, cf) in enumerate(groups):
        ctx["period"] = _predict(ctx["hist"], ctx["period"], A, B, tables[g])
    coef = _coefficients(scales)
    # FUN_800b4dc0 writes the bank selected by ctx+0x188, runs the mixer, and only THEN flips 0x188 —
    # so `cur` is the bank just written. Pinned by probe: first frame tap = K1(2458, 0), not K1(0, 2458).
    idx = ctx["toggle"]
    ctx["bank0" if idx == 0 else "bank1"] = coef
    cur = ctx["bank0"] if idx == 0 else ctx["bank1"]
    prev = ctx["bank1"] if idx == 0 else ctx["bank0"]
    for g in range(4):
        # The kernel returns `t & 0xFFFF`; the cartridge unpacks with `sra`, a SIGNED halfword. Without
        # S16 a negative tap enters as 65126 instead of -410 — invisible while every tap is positive.
        taps = [S16(_kernel(g, S16(cur[j]), S16(prev[j]))) for j in range(8)]
        base = (0, 13, 27, 40)[g]
        count = (13, 14, 13, 120)[g]            # t3+1: `bgtz` reads the counter before the delay slot
        ctx["acc"] = _lattice(ctx["hist"], ctx["out"], base, count, taps, ctx["s"], ctx["acc"])
    ctx["toggle"] ^= 1
    ctx["acc"] = S16(ctx["acc"])                # one halfword store per block, after all four bands
    return ctx["out"]


def transcribe(record, blocks):
    """Decode `blocks` blocks of a MORT record with no emulator. Returns (samples, stats)."""
    total, rate = struct.unpack_from(">HH", record, 4)
    want = min(blocks, total)
    buf = record[12:]
    p, run_n, run_s = 0, 0, 0
    samples, silent = [], 0

    def get(k):
        nonlocal p
        v = 0
        for i in range(k):
            q = p
            if q >> 3 >= len(buf):
                raise EOFError
            word = int.from_bytes(buf[(q >> 5) * 4:(q >> 5) * 4 + 4], "big")
            v |= ((word >> (q & 31)) & 1) << i
            p += 1
        return v

    ctx = _new_ctx()
    for _ in range(want):
        if run_n == 0 and run_s == 0:
            if get(1):
                run_s = get(4) + 1
            else:
                run_n = get(7) + 1
        if run_s:
            run_s -= 1
            ctx["out"] = [0] * 160
            silent += 1
        else:
            scales = [get(w) for w in SCALE_W]
            groups = []
            for _g in range(4):
                A, B, C, D = (get(GROUP_W[0]), get(GROUP_W[1]), get(GROUP_W[2]), get(GROUP_W[3]))
                groups.append((A, B, C, D, [get(3) for _ in range(13)]))
            run_n -= 1
            _block(ctx, scales, groups)
        samples.extend(ctx["out"])
    return samples, {"silent": silent, "steps": 0, "memset": silent, "blocks": want}


def _compare(rec, blocks, mod):
    """The differential: emulator samples against transcribed samples, block by block."""
    total = min(blocks, rec[1])
    ref, _ = decode(rec[3], total, mod)
    mine, _ = transcribe(rec[3], total)
    bad = [(i, a, b) for i, (a, b) in enumerate(zip(ref, mine)) if a != b]
    blks = sorted({i // BLOCK_SAMPLES for i, _a, _b in bad})
    return ref, mine, bad, blks


def _band_dump(rec, want_block, mod):
    """Print the cartridge's four band-entry states for one block, and the hand-off after it.

    This is the dump the transcription was debugged with: the lattice's state hand-offs between bands.
    It reports the CARTRIDGE's own sequence, which is what made an earlier one-band mislabel in my probe
    show up as a phantom "phase offset" — the numbers were right, the labels were not. Pair it with
    `--diff` to see the samples themselves.
    """
    from unicorn import UC_HOOK_CODE
    from unicorn.mips_const import (UC_MIPS_REG_S0, UC_MIPS_REG_S1, UC_MIPS_REG_S2, UC_MIPS_REG_S3,
                                    UC_MIPS_REG_S4, UC_MIPS_REG_S5, UC_MIPS_REG_S6, UC_MIPS_REG_S7)
    (Uc, ARCH, MODE32, BE, HOOK, R_A0, R_A1, R_A2, R_A3, R_PC, R_RA, R_SP) = mod
    sg = lambda v: v - (1 << 32) if v >= (1 << 31) else v
    sregs = (UC_MIPS_REG_S0, UC_MIPS_REG_S1, UC_MIPS_REG_S2, UC_MIPS_REG_S3,
             UC_MIPS_REG_S4, UC_MIPS_REG_S5, UC_MIPS_REG_S6, UC_MIPS_REG_S7)
    calls = {0x800b66b4: 0, 0x800b66d8: 1, 0x800b66fc: 2, 0x800b6720: 3}
    uc, ram, _st = _session(rec[3], mod)
    cur, prev, seen = {"bi": -1}, {"a": None}, {}

    def hook(u, a, s, d):
        if a == 0x800B6470 and prev["a"] in calls and cur["bi"] >= 0:
            seen.setdefault(cur["bi"], []).append(
                (calls[prev["a"]], [sg(u.reg_read(r)) for r in sregs], sg(u.reg_read(R_A3))))
        prev["a"] = a

    uc.hook_add(UC_HOOK_CODE, hook)
    for bi in range(min(want_block + 2, rec[1])):
        cur["bi"] = bi
        bp = struct.unpack(">I", uc.mem_read(CTX + 0x11C8, 4))[0]
        win = (bp >> 3) & ~0xFFF
        chunk = bytes(ram[PAY + win:PAY + win + 0x1000])
        uc.mem_write(CTX + RING, chunk + bytes(0x1000 - len(chunk)))
        for r, v in ((R_SP, 0x003FF000), (R_RA, SENT), (R_A0, CTX), (R_A1, OUT), (R_A2, 0), (R_A3, 0)):
            uc.reg_write(r, v)
        uc.emu_start(CODE, SENT, count=4000000)
    print("clip %d, block %d (rate %d): cartridge band-entry states" % (rec[0], want_block, rec[2]))
    for band, s, acc in seen.get(want_block, []):
        print("  band %d entry  s=%-46s acc=%d" % (band, str(s), acc))
    nxt = seen.get(want_block + 1, [])
    if nxt:
        print("  hand-off into block %d: s=%-40s acc=%d" % (want_block + 1, str(nxt[0][1]), nxt[0][2]))
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true", help="the gated cases")
    ap.add_argument("--clips", action="store_true", help="the bank census")
    ap.add_argument("--audio", type=int, metavar="CLIP", help="decode one clip to assets/sound/")
    ap.add_argument("--verbose", action="store_true")
    # The differential harness: `--diff` compares samples, `--dumps` prints the state hand-offs
    # that were used to debug the transcription. Both are reproducible from a command, which the
    # M199 appendix needs in order to be checkable rather than reproduced from memory.
    ap.add_argument("--diff", type=int, metavar="CLIP",
                    help="compare the transcription against the emulator for one clip")
    ap.add_argument("--blocks", type=int, default=40, help="blocks to compare (default 40)")
    ap.add_argument("--dumps", type=int, metavar="CLIP",
                    help="print the cartridge band-entry states for one clip")
    ap.add_argument("--block", type=int, default=13, help="which block to dump (default 13)")
    args = ap.parse_args()

    if not ROM.exists():
        sys.exit("cartridge not found: %s" % ROM)
    if not ensure_engine():
        sys.exit("no interpreter has %s; run under `.venv/bin/python`" % ENGINE)

    if args.check:
        return check()
    if args.dumps is not None:
        drec = [r for r in records() if r[0] == args.dumps]
        if not drec:
            sys.exit("no MORT record with index %d" % args.dumps)
        _band_dump(drec[0], args.block, _unicorn())
        return 0
    if args.diff is not None:
        crec = [r for r in records() if r[0] == args.diff]
        if not crec:
            sys.exit("no MORT record with index %d" % args.diff)
        ref, mine, bad, blks = _compare(crec[0], args.blocks, _unicorn())
        print("clip %d: %d blocks, %d samples; %d differ%s"
              % (crec[0][0], min(args.blocks, crec[0][1]), len(ref), len(bad),
                 "" if not blks else "  (blocks %s)" % blks[:12]))
        for i, a, b in bad[:6]:
            print("  sample %d: cartridge %d, transcription %d" % (i, a, b))
        return 0 if not bad else 1
    rows = records()
    if args.clips:
        print("%d records; blocks %d..%d, total %d samples (%.1f s at 16000 Hz)"
              % (len(rows), min(r[1] for r in rows), max(r[1] for r in rows),
                 sum(r[1] for r in rows) * BLOCK_SAMPLES,
                 sum(r[1] for r in rows) * BLOCK_SAMPLES / 16000))
        return 0
    if args.audio is None:
        ap.error("one of --check, --clips, --audio N")
    rec = [r for r in rows if r[0] == args.audio]
    if not rec:
        sys.exit("no MORT record with index %d" % args.audio)
    k, blocks, rate, record = rec[0]
    mod = _unicorn()
    if mod is None:
        sys.exit("the emulator (unicorn) is not importable")
    samples, st = decode(record, blocks, mod, verbose=args.verbose)
    out = WAVDIR / ("mort_%d.wav" % k)
    write_wav(out, samples, rate)
    s = stats_of(samples)
    print("clip %3d: %5d blocks -> %6d samples (%.2f s) @ %d Hz  peak %5d rms %6.0f lag1 %+.3f"
          % (k, blocks, s["samples"], s["samples"] / rate, rate, s["peak"], s["rms"], s["lag1"]))
    print("  silent blocks %d, clipped %d, steps %d, memset %d"
          % (st["silent"], s["clipped"], st["steps"], st["memset"]))
    print("  wrote %s" % out.relative_to(ROOT))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
