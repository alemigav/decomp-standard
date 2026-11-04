# M204 — there is no +28: the record ends at +27

The question was what `+28` and `+32` of the sample record mean. The measurement answers something else
first: **the record is 28 bytes, so it has no `+28`.** Those bytes belong to the next record — `+28` is its
`u16` index and `+32` is its byte offset — and after the last record, `+28` is the member's `ffffffff`
terminator. There is no field to name, and inventing one would have been the easiest mistake in this arc to
make and the hardest to detect later.

## 1. The addressing, measured

| record | `+0` index | `+4` offset | `+20` | `+24` | bytes at `+28` | bytes at `+32` |
|---|---|---|---|---|---|---|
| 0 | 1 | 0 | 2 | 0 | `00 02 00 00` → index **2** | `00 00 54 98` → offset **21 656** |
| 1 | 2 | 21 656 | 2 | 0 | `00 03 00 00` → index **3** | `00 00 c7 d0` → offset **51 152** |
| 1 189 | 1 190 | 8 986 864 | 2 | 0 | `04 a7 00 00` → index **1 191** | `00 89 35 00` → offset **8 992 000** |
| 1 190 | 1 191 | 8 992 000 | 2 | 0 | `04 a8 00 00` → index **1 192** | `00 89 8d f8` → offset **9 014 776** |
| 1 191 | 1 192 | 9 014 776 | 2 | 0 | `ff ff ff ff` — the terminator | — end of member — |

`record k`'s `+28` equals `record k+1`'s index on **1 191 / 1 191** adjacencies, and its `+32` equals that
record's offset on **1 191 / 1 191**. The member is 33 380 B = **1 192 × 28 + 4**, so the last record's `+28`
is the terminator and also the file's last byte. The `u16` at `+0` takes 1 192 distinct values, so there is no
wrap that could imitate a second layout.

## 2. Why no code can read a 29th byte

Three pieces of the cartridge, each checked in the source and (for the first) in the instructions:

* **The search** — `FUN_800ada34` calls `FUN_800ab43c(&DAT_8014e100, dir, count, 0x1c, &LAB_800ae154)`, and
  the `0x1c` is `_li a3, 0x1c` at `0x800adaa4`. It is a *record stride* in a binary search, so the walk never
  leaves a 28-byte grid.
* **The count walker** — `FUN_800ad330` steps `psVar5 = psVar5 + 0xe` (14 shorts) until a short reads `-1`, and
  zeroes `param_1[1]` — the refcount at `+2` — on the records it registers. Same grid, and its terminator is
  the same `ffffffff` at `+0`.
* **The reader's fields** — the highest load in `FUN_800ada34` is `lw v0, 0xc(v1)` with `v1 = record + 0xc`,
  i.e. `record + 0x18`, and a 32-bit load there ends at `+0x1b` = **byte 27**. The descriptor it fills is
  seven words, so the record's 28 bytes are exactly consumed: `+20` and `+24` (M203) are the last two.

## 3. Where those two addresses *do* exist

For completeness, because the numbers are not meaningless in this subsystem — they just belong to a different
structure. The **0x68-byte voice** (`_DAT_80143f0c`, one per channel) has real fields at `+0x1c` and `+0x20`:
`+0x1c` is one of four per-voice level words (`+0x18`, `+0x1a`, `+0x1c`, `+0x1e`) that `FUN_800a3bf4` scales by the
voice's gain and writes into the mixer command, and `+0x20` is the first of a four-field block set by `FUN_800a591c` (`u16`, `u16`,
`value / 4096` as a float, `u16`). That is sequencer voice state, not the sample directory. **It is named
here only to say where the addresses do exist; it is not measured in this milestone**, and no claim about
those four fields is made.

## 4. What this milestone is, and is not

It is a refutation of a framing, stated as addressing rather than as a new gap. Nothing is left open by it:
the record's size was fixed in M184 (1 192 × 28 + a terminator) and M203 placed the loop fields at `+20` and
`+24` as its last two words. What was worth *asserting* is the part that would break silently — that every
adjacency is 28 bytes, and that the terminator sits exactly where a 29th byte would be. A future reader who
adds a field at `+28` now fails a gate instead of shifting every record by four.

## 5. Gates

`file table (cartridge)` **106 → 109**: three cases — the adjacency on 1 191/1 191 for both the index and the
offset, the terminator sitting at EOF, and the cartridge's two strides (`0x1c` in the search, `0xe` shorts in
the walker) together with the reader's highest field load ending at `+0x1b`.

`gate audit (mechanisms disabled)` **65 → 69**, four mutations over those three cases: the adjacency read four
bytes too far into the next record, a 28-byte-count taken over 1 190 records instead of 1 191, a directory
taken as ending 12 bytes past the terminator, and the walker's stride read as 16 bytes.

One process note, because it is the kind of thing this project audits: the first attempt at the stride
mutation replaced 28 with **32** everywhere, which ran the read past the end of the member and raised
`struct.error` — the tool exited non-zero, and the audit would have scored the mutation as *detected*. That is
exactly the vacuous shape the audit exists to catch, so it was replaced with a mutation that keeps the read in
range and fails **with a message**, and both remaining adjacency mutations were verified by hand to fail the
case they target.

Repository is **36 suites / 495 cases**, of which **14 suites / 277 cases** are cartridge-gated, so the
runnable tier is **22 suites / 218 cases**.
