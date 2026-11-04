# Resident Evil 2 (N64) — 3 638 decompiled functions, and a gate you can run without the ROM

I've published v1.0 of a black-box decompilation of **Resident Evil 2 (Nintendo 64, NREE rev 1 USA)**:
https://github.com/alemigav/re2-64-decomp/releases/tag/v1.0

**First, what it is not.** It is not a matching decompilation. There is no byte-matching build, no `make`, and
no playable game at the end. Splat reports the compiler as **KMC**, so the community matching toolchain does
not transfer, and a 64 MB cartridge is not a one-person matching effort. What it is instead: formats decoded
from the cartridge's own behaviour, 3 638 functions of Ghidra pseudocode, and — the part I think is worth your
time — **a verification suite that a stranger can run with no cartridge at all**.

## What is actually established

- **ROM→VRAM mapping**: `vram = rom_offset + 0x7FFFF480`, after the first version of it was wrong by `0x480`
  and had silently invalidated every address in the project.
- **Container**: 4 761 zlib members, 8 748 242 → 18 550 424 B, plus 1 227 MJPEG frames and 271 MPEG-1
  blocks, all verified byte-for-byte.
- **Code corpus**: 36 images (boot + stage-2 + 34 overlays, 1 947 632 B) censused from the cart's own load
  table; 3 638 functions decompiled, **62.3 %** of code bytes claimed.
- **Script VM**: a 141-entry handler table with **15 distinct instruction lengths**, 1–40 bytes, decoded from
  the handlers' own behaviour — including one instruction (`0x0f`) that is 4 bytes and three earlier readings
  that said otherwise.
- **Room population**: 256 table entries → 147 ids → 50 room scripts, where the population was proven
  *before* anything was modelled on it.
- **Textures (T64)**: palette plus raw 4/8-bpp indices, no compression;
  `len = 16 + entries·2 + w·h·bpp/8` verified on **65 of 65** tiles.
- **Exception path**: `break` → vector stub → dispatch loop at `0x8000098c`, with no `eret` and no EPC write.
  Fatal; only a hardware reset leaves it.

## The part I'd actually like reviewed

A decompilation's findings usually can't be checked without the ROM — so they're taken on trust. Here 109 of
273 cases need the cartridge, and the other **16 suites / 164 cases run with nothing but a Python
interpreter**:

```sh
python3 tools/acceptance.py     # 164 of 273 cases; the rest SKIP, never PASS
python3 tools/audit_gates.py    # 26/26 — it disables each check's mechanism and requires failure
python3 tools/artefact_scan.py  # 5/5 — no tracked file is cartridge content
```

The audit is the one I'd point at: it mutates each gate to prove the gate can fail, and reports **0 vacuous**.
It has caught several checks in this project that could not fail for the right reason — and five separate
times its own test environment was silently wrong, which is the same defect wearing a lab coat.

## What is not solved

- Two blobs, ~17.6 MB total, unidentified; one holds a 28-payload non-zlib container whose codec is unsolved.
- **37.7 %** of code bytes remain unclaimed (734 648 of 1 947 632).
- **81 of the script VM's 141 opcodes remain unnamed**: 43 come from the MIT-licensed reference table, 17
  carry `~`-marked names this project inferred, the rest are still handler addresses.
- 50 milestone numbers in my own log have no note at all (M31–M78); the index names them instead of
  pretending otherwise.

## Legal

No cartridge data anywhere in the repository — not in the tree, not in any of its 203 commits (10 908 blobs,
41.6 MiB, the only `.z64` an 8 KiB synthetic fixture), and no extracted assets, audio or video. You need your
own dump for anything that reads the ROM. The author's prose, tools and fixtures are **CC0-1.0**; `src/` is
Ghidra pseudocode derived from Capcom's work, published for study, and is explicitly *not* something I claim
to license. Not affiliated with Capcom or Nintendo.

Every function carries its provider record and body hash rather than any ROM bytes, and the retraction table
in `docs/reverse_engineering_log.md` lists the project's own wrong turns — three of which changed headline
numbers.

Feedback on the formats, the gate, or anything above that you think is wrong: very welcome. Refutations are
the most useful kind.
