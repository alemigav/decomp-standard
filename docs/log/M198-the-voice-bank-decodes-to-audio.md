# M198 — the voice bank decodes to audio, by running the cartridge's own synthesis

M197 ended with the stream understood and the synthesis named as the remaining work. This milestone closes
it: **588 clips, 49 126 080 samples, 51.2 minutes of audio**, decoded and written to WAV.

The one thing that is *not* done the way the milestone was framed: the synthesis is **executed, not
transcribed**, and §3 says exactly why and what that costs.

## 1. What the three routines do

`FUN_800b4a04` drives one block per call, producing **160 samples** (0x140 bytes); `FUN_800b53f4` parses one
block's fields and runs the synthesis. The structure, from the call sites and the arithmetic:

| routine | job |
|---|---|
| `FUN_800b62c0` | dequantise a group's 13 coefficients — `((c*0x2000 - 0x7000) * ((scale&7)*0x800 + 0x47ff) + 0x4000) >> 15`, plus a scale-dependent rounding term driven by a byte table at `0x800b63ac` (`-57,-41,-29,-25,-15,-13,-11,-9`) — then zero 40 shorts and **scatter the 13 at stride 3** from `table + phase` |
| `FUN_800b63b4` | the **long-term predictor**: latch the period (40…120) into `ctx+0x166`, slide the 160-short history down by 40, and append 39 samples of `((hist[120-lag+i] * gain + 0x4000) >> 15) + residual[i]`, `gain` from a four-entry table `0x0ccd, 0x2ccd, 0x5333, 0x7fff` |
| `FUN_800b4dc0` | eight coefficients from the eight scale fields through eight fixed-point affines, written into **one of two banks** at `ctx+0x168`/`ctx+0x178` with `ctx+0x188` toggling, then the mixer |
| `FUN_800b6634` | four sub-bands; per band `FUN_800b6788` mixes the two banks through one of four kernels (shapers at `0x800b682c/6844/6854/686c`) into eight lattice taps, and `FUN_800b6470` runs an 8-tap lattice over 12, 13, 12 and 119 samples with a shared accumulator |

The frame widths and the sub-band split are why a block costs 260 bits: 36 scale bits + 4 × (17 + 39).

## 2. What the decoder produces

`tools/voice_decode.py --audio <clip>` writes `assets/sound/mort_<clip>.wav` (gitignored). Two measurements,
both reproducible:

| clip | blocks | samples | duration | peak | rms | lag-1 |
|---|---|---|---|---|---|---|
| 27 | 26 | 4 160 | 0.26 s | 26 896 | 5 145 | +0.680 |
| 2 | 5 058 | 809 280 | 50.58 s | 30 768 | 2 608 | +0.882 |

And the properties that say *voice* rather than *numbers*, on clip 2: **zero samples at full scale**
(nothing railed), zero-crossing rate **median 0.125** with a 0.000–0.685 range, an envelope that varies
(113 loud and 129 near-silent 100 ms windows out of 505), and a first-difference energy ratio of **0.237** —
spectrally tilted down, where white noise sits at or above 1.0. **116 of its blocks are silent**, which is
the `memset` path, and they come out exactly zero rather than merely quiet.

The bank as a whole: **588 records, 49 126 080 samples, 3 070 s at 16 kHz**.

## 3. Why executed, not transcribed — and what that costs

`FUN_800b6634` calls `FUN_800b6788` and `FUN_800b6470` **through registers**: the pseudocode renders them as
`FUN_800b6788()` with no arguments, and the kernels as `(*in_t3)()` eight times, with the real inputs in
`t0`, `t1`, `t3`, `t6`–`t9` and `s0`–`s7`. There is no faithful transcription available from the pseudocode,
and writing one from inference is exactly the "guess that works on three quarters" M194 refused.

So the tool runs the instructions: stage-2's code under Unicorn, `ctx` handed over as a physical pointer,
the ring refilled by the host at the window the reader asks for (`(bitpos>>3) & ~0xFFF`), and
`memset` (`0x80006650`, in the boot image) supplied as a host primitive because the silent path's only work
is `memset(out, 0x140)`.

**What this does not establish**: that the output is sample-identical to a console, since there is no
reference recording to compare against. The bit reader, field layout, dequantisation, predictor, lattice and
mix are the cartridge's, and the numbers in §2 are measurements of what its own code produces — not of a
reimplementation. A Python transcription remains open work, and it now has an oracle to be graded against.

## 4. Three defects found in my own instrumentation

Each cost a wrong answer before it was caught, and they are worth recording because they are the shape of
"the harness lied":

1. **`bitpos` was never seeded.** `FUN_800b4a04` sets it to `0x60` when the first DMA completes; calling
   `FUN_800b53f4` directly without that reads the ring from bit 0 and decodes silence.
2. **The ring was 12 bytes out of phase.** `bitpos` counts from the *record* start, header included, so the
   ring must hold the record — not the payload. Feeding the payload shifted every field by 12 bytes, which
   sounded like loud clipped noise (34–40 % of samples railed).
3. **The step budget was cumulative.** A running total across 5 058 `emu_start` calls began aborting every
   block once the clip passed 4 M instructions; the first 50 seconds decoded fine and the rest was silence
   dressed as audio (lag-1 fell to +0.036). The budget is per block now.

The first two produced plausible-looking output. That is the argument for gating numbers rather than
listening.

## 5. State of the tree

`voice_decode.py --check` **7/7** (record count, block arithmetic, the silent blocks exactly zero, nothing
railed, lag-1, level, and the `memset` path taken) — and it fails **loudly** when no interpreter has the
emulator, rather than skipping. Counts: **36 suites / 452 cases**, of which 22 / 218 run without the
cartridge; audit **48/48, 0 vacuous**. The emulator is a development-only package: the tool re-executes
itself under `.venv` when the running interpreter lacks it, the same way `t64_selftest.py` looks for `cc`.
