# M222 — WP3b: the voice descriptor, and the correction to my own `+0x1a4`

The second half of WP3: trace the descriptor from the MORT header into the CPU→engine handoff. It lands with a
structure, 37 slot fields, six things the RSP alone could tell us, and **one hop published as untraced** — plus a
correction to a claim I made in M197 and repeated in the brief for this work.

## 1. The structure

**Base `0x80158b20`, stride `0x1228`, two slots.** The count is not assumed: the region ends exactly on
`_DAT_8015af70`, the sound system's first global (`0x80158b20 + 2 × 0x1228 = 0x8015af70`, checked arithmetically
and against the symbol). A slot holds 37 fields; the artefact records 72 offsets in four groups (slot, command
block, engine voice, handle, task), and **53 of them are re-derived by decoding the writer instruction out of the
cartridge** rather than by reading a statement that names the offset.

Representative fields, each with its writer:

| offset | name | writer |
|---|---|---|
| `+0x190` | `dma_callback` | `FUN_800b4930.c:18` |
| `+0x194` | `source_rom` | `FUN_800b4930.c:14` |
| `+0x19c` | `pcm_units` | `FUN_800b4930.c:16` |
| `+0x11a0` | `blocks_remaining` | `FUN_800b4a04.c:25` |
| `+0x11a4` | `record_words_remaining` | `FUN_800b4a04.c:27` |
| `+0x11c8` | `bit_cursor` (seed `0x60`) | `FUN_800b4a04.c:24` |
| `+0x1208` | `rate` | `FUN_800b3704.c:36` |
| `+0x120c` | `engine_handle` | `func_800b3b9c.c:52` |
| `+0x1224` | `voice_id` | `FUN_800b3640.c:27` |

The handoff itself is three more structures: the engine voice at `0x80143f0c` stride `0x68` (`+0x04` pitch,
`+0x2c` PCM base, `+0x18..0x1e` current gains and `+0x40..0x46` target gains), the handle table at `0x801481e0`
stride `0x18`, and the audio task block at `0x80143c60`.

## 2. My correction: `+0x1a4`/`+0x1a8` are ring bytes, not stream state

M197 recorded "stream state at `+0x1a4`/`+0x1a8`", and I repeated it in this milestone's brief. It is wrong, and the
arithmetic shows why in one line: the ring starts at `ctx+0x1a0` and is 4 KiB, so it spans `0x1a0…0x119f`, which
makes `+0x1a4`/`+0x1a8` **ring bytes 4–11** — the MORT header, read once while `rom_offset == 0`. The real stream
state begins at `+0x11a0`. The artefact carries the corrected map and the note is in the log's retraction table.

## 3. The hop that is not traced

**Nothing in stage-2 reads the MORT record's rate halfword.** The artefact says so as a counted negative: only two
`0x1a6`-class displacements exist in the image and both are `sp`-relative stack accesses. The slot's `rate` comes
from the **caller's argument** — 16 000 by default, 8 000 when the bank's flag byte is zero. So clip 0's `+6`
value (16 000) *agrees* with `+0x1208`, and that agreement is a coincidence of the default until something reads
the header. Published as `unresolved`, not as a trace.

## 4. Clip 0, end to end

`MORT+4` blocks `2598` → `+0x11a0`; `MORT+8` words `20106` → `+0x11a4` (`×4 = 80424` = the record length);
79 chunks of `0x400` with the tail derived as `(20106 − 0x100·78)·4 = 552` — which is the real remainder, not a
rounded one; rate `16000` → `+0x1208` (hop untraced); → `+0x1214` capacity
`((16000·8)/30 + 0x9f)/0xa0·0xa0 = 4320` samples → `+0x19c`; allocation `(4320+4)·2 = 8648 = 0x21e8`, while
`0x10e0` is what the sound init hard-codes.

## 5. What only the RSP could answer

Six entries, each with a reason rather than a name: command-record semantics; per-sample gain application and
channel roles; resampling; loop-end choice; the `0x80136b50` output buffer; and the `0x800b2700` microcode blob.
The last is locatable — the audio task points at it with size `0x1000` — but **its extent does not close**: the
corpus has no body between `0x800b2694` and `0x800b3640`, and that range overruns `FUN_800b3640` by `0xc0` bytes,
so it is not a clean hole and is not claimed as one.

## 6. Gates

`voice descriptor (cartridge)`: **29 cases**, 0.20 s. The mutations are aimed at the tool's constants rather than
the artefact's strings — my first two anchors spanned multi-line JSON and did not match, which the lint caught in
0.04 s — so moving the slot stride or the ring size changes what every derived offset means and the derivation
comparison names it.

Also landing: `tools/sound_fixtures.py`, the tier-1 validator described in the previous commit, and the
`VERIFICATION.md` ordering fix. 56 suites / 767 cases; admission 105/105, 0 vacuous.
