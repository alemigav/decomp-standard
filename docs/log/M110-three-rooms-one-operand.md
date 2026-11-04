# M110 — three rooms, one operand, and the scene-slot path is by design

Two things happened here. The owner reported ground truth that contradicts M104–M106, and measuring it found
the error was an **instrument**, not an arithmetic slip: the signal I used for "same room?" cannot see rooms
in this game at all.

## The owner's report

The playthrough behind the dumps passed through **two door-opening animations**, so at least **three rooms**
were visited. M104–M106 treated the captures as "five instants of one corridor". One of those is wrong, and
it is mine.

## The measurement

`tools/dump_fingerprint.py` reads every dump and prints, per capture, the script descriptor, the slot
descriptor and its first bytes, the two stream pointers at `descriptor+0x48`/`+0x4c`, a hash of the script
buffer, a hash of the resident overlay payload at `0x80161cf0`, and a hash of the two static slot maps as a
control.

| dump(s) | stream pointers | slot byte 3 | resident overlay |
|---|---|---|---|
| `130325`/`130332`/`130338` (byte-identical) | `0x8052a3c8` / `0x8052a630` | 31 | `e7370cc06a32` |
| `132514`, `132850`, `132924` | `0x8052a408` / `0x8052a450` | 31 | `e7370cc06a32` |
| `132952`, `141511` | `0x8052a320` / `0x8052a3e8` | 31 | `e7370cc06a32` |

* **The resident overlay is byte-identical in all eight room captures.** It is therefore **not** a room
  discriminator here — rooms evidently share one resident overlay and select their content from data. That
  is the instrument error: M104 compared *whole-file* hashes and this overlay hash and concluded "one
  corridor", which the signal could never have supported.
* **The stream pointers give three distinct pairs**, i.e. three distinct room scripts — matching the owner's
  two doors and three rooms exactly. The script descriptor itself is one fixed global (`0x80529d40`), so the
  pointers inside it are the discriminating field, not the pointer to it.
* The **script buffer hash varies within one stream pair** (`132514`, `132850`, `132924` are three different
  contents under the same pair), so buffer content is a *moment* signal and stream pointers are the *room*
  signal. `132952` and `141511` share a stream pair and differ in buffer content; so do `132850` and the
  scripted dump taken at 13:57.
* The **slot maps are identical in all twelve dumps** (`dcf489248f96`), which is the control that says every
  row is what it claims to be.

## What this closes

Across **three rooms**, the scene-slot command carries **byte 3 = 31** every time, the two 48-byte maps are
immutable `.rodata`, and slot 31's map entry is 0 — so the loader is handed `cart_record(0)` (the
`OVERLAYTABLENUM` marker), branch 2 fails its inflate, and the return is discarded. The destination is
unchanged and the game continues.

The owner's reading is the right one: **this is the design.** A per-room scene-slot command whose operand
selects nothing is not a defect to hunt down; the immutability of the maps (M106) plus a constant operand
across three rooms is exactly what an unreachable-in-this-build path looks like — the same shape M89 found
for bank C as a whole, whose map pointer `0x800eb268` is constructed nowhere in 36 images.

So the question *"does any room's script make the game load a bank-C record?"* is answered as far as the
evidence goes:

* **three rooms observed, all with slot 31, none loading anything** — the owner's playthrough, corroborated
  by three distinct room scripts in the dumps;
* **the map is static and slot 31's entry is 0**, so no capture in any room can select a real record with
  operand 31;
* **the discriminating case would be an operand in the 13 non-zero map slots** (16, 32–49, 51, 52, 54–56, 58,
  59, 62, 63). None appeared in three rooms. It is *not* proven absent from the remaining rooms — that proof
  would need a capture per room — but nothing in the code path gives a room a reason to vary it, and the
  bank-C map has no consumer at all (M89/M91).

## Decisions taken

* **No more ares dumps.** The debugger route is parked (M109: ares feeds the game `ff ff ff ff`, i.e. no
  controller), and the manual export route is retired too: the question it was going to answer is now closed
  by measurement plus the owner's playthrough, so producing more captures buys nothing.
* **The scene-slot path is recorded as intended behaviour**, not as an open anomaly. `room_probe.py` and
  `walk_stream.py` stay in the tree: they are how any future dump is read in one second.
* The emulator's settings are back to a normal, playable configuration (`Boot/Debugger=false`,
  `Boot/AwaitGDBClient=false`, `DebugServer/Enabled=false`).

## Errors this note earned

* **A signal that cannot discriminate is worse than no signal (M104/M106).** "Same resident overlay" and
  "byte-identical file" were both read as "same room"; the overlay is shared across rooms in this build, and
  whole-file identity only proves the same *moment* was exported twice. The room signal was in the dumps the
  whole time — the stream pointers — and it was already being read by `room_probe.py` without being used to
  settle this.
* **Ground truth from the owner outranks an inference from an artifact.** Two door animations took one
  sentence and refuted four notes' worth of framing; the correct response was to find the field that could
  express it, not to defend the framing.

## Still open

The two unidentified blobs (R3 `0xb73fb3`–`0x140ed84`, R4 `0x338fe1`–`0xb63106`) and the 28 non-zlib payloads
at `0xb6248`; experiment B (pointer provenance) and C (resource structures). None of them depends on the
emulator.

## Reproduce

```sh
python3 tools/dump_fingerprint.py "rom/Resident Evil 2 (USA) (Rev 1)-rdram-"*.bin
python3 tools/room_probe.py "rom/Resident Evil 2 (USA) (Rev 1)-rdram-20261031-141511.bin"
```
