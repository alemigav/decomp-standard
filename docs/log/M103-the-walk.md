# M103 — the walk: 174 commands, no scene-slot command pending, and slot 31 selects *nothing*

## 1. The decoder

`tools/walk_stream.py` derives the opcode→length table the way the code defines it — one length per
table entry, read out of each handler's own advance idiom:

```
opcode -> command length, derived from 140 handlers with an advance idiom
  lengths in use: [1, 2, 3, 4, 5, 6, 8, 10, 14, 16, 20, 22, 28, 32, 40]
  opcode 0x44 (the scene-slot command) -> (0x80071e14, 22)
```

140 of the 141 table entries carry a derived length; the missing one has no advance idiom and the walk
treats it as a stop rather than a guess.

## 2. The dump has six live contexts

```
ctx0 …  = 0x8052a6a4    ctx1 = 0x8052a650    ctx2 = 0x8052a7ed
ctx3 …  = 0x8052a83f    ctx4 = 0x8052a858    ctx5 = 0x8052a723
ctx6–9  = 0
```

Six contexts running at the captured instant, four idle. Walking 300 commands from each:

| ctx | commands walked | ended at |
|---|---|---|
| 0 | 56 | `0x8052a728` |
| 1 | 84 | `0x8052a728` |
| 2 | 4 | `0x8052a7f8` |
| 3 | 18 | `0x8052a874` |
| 4 | 10 | `0x8052a874` |
| 5 | 2 | `0x8052a728` |

**174 commands total, 30 distinct opcodes, 6 desync stops.** The distribution is plausible bytecode —
`0x00` ×55 (a NOP-like opcode of length 1), `0x22` ×14, `0x06` ×11, `0x21` ×11, `0x01` ×7 … — and
several streams converge on the same end address, which is what a script waiting at a common yield
point looks like. A wrong length table would have produced garbage opcodes almost immediately; it
doesn't.

## 3. The answer to the question this thread has been chasing

**Zero opcode-`0x44` commands in the walked window**, and here is why that is not a contradiction with
`*(0x80115284)` pointing at one:

* the handler **stores the current command into `0x80115284` when it runs**, so that pointer records
  the **last** `0x44` command, not the next one;
* every live context pointer (`0x8052a650` … `0x8052a858`) is **past** `0x8052a614`, the command the
  dump holds.

So the `0x44` command at `0x8052a614` **did execute**, with slot **31**, with the gate **passing** —
and the walk shows nothing of its kind pending now.

And what slot 31 selects is the part that closes the thread:

```
slot 31 → slot-16 = 15 → s0 = 1 → pointer #2 (array 2) → array2[15] = 0
        → cart_record(0) = the "OVERLAYTABLENUMC" marker
        → branch 2 → inflate(cart 0x0f564552, len 0x4c415954) → fails, return discarded
```

**Slot 31 selects no record at all.** It degrades to descriptor 0, which is the table's own header. So
the scene-slot command that ran in this room did **not** load bank C, did not load bank B, and did not
crash: it asked for a nonsense record and the loader's silently-discarded failure absorbed it.

That is the end of the question as originally posed. **No bank-C record is selected in this room** —
not because the map entry is guarded, but because the slot value (31) lands on a zero map entry, and
zero means "descriptor 0", which the loader rejects without complaint.

## 4. What this does and does not establish

| claim | status |
|---|---|
| scene-slot commands run, and one is captured as the last-executed | **measured** (`0x8052a614`, slot 31) |
| the gate passes for it | **measured** (M102) |
| slot 31 selects descriptor 0, i.e. nothing | **derived and consistent** |
| no bank-C record is loaded in this room | **holds for this slot value**; a slot in 16 or 32–63 would select a real record and none was observed in 174 commands |
| the walk is globally correct | **plausible, not proven** — 6 desync stops and one table entry without a length; a wrong length would desync, and the opcode distribution looks like real bytecode, but "looks right" is not a proof |

The honest residue: the walk covers **one instant** in **one room**. A slot in the live range
(16, 32–63) has not been observed; it has also not been excluded for other rooms or other moments. The
tool now makes that a one-command check per dump.

## 5. Tooling

`room_probe.py` no longer pretends a fixed-stride scan works — it reported "no opcode-0x44 command at
the 22-byte stride", which was true but meaningless, since 0x44 is a common byte and the stream has to
be walked from a live pointer. It now says so and points at `walk_stream.py`.
