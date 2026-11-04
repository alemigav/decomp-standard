# M90 — the slot-byte writers are not statically derivable, and six audit flags resolved

## 1. The question: every writer of `*(0x80115284) + 3`

**Answer: it cannot be enumerated from the corpus, and I can say exactly why.** Four measurements:

1. **One installer.** `*(0x80115284)` is written by exactly one instruction — `0x80071e5c`,
   `sw a0, 0x5284(v1)`, guarded by `counter < 3`, with `a0 = arg0->0x1c`.
2. **The installer's host has no caller.** `FUN_80071e14` has **zero `jal` sites** in 36 images, so
   it is reached through a function pointer, and the provenance of `arg0` — and therefore of the
   struct — is not statically visible.
3. **No capture covers the object's lifetime.** Both ares RDRAM dumps in `rom/` have
   `*(0x80115284) == 0`. At the title screen and immediately after NEW GAME the struct is not yet
   installed, so nothing observed so far contains its bytes.
4. **A byte-offset scan is structurally too narrow.** There are 115 `sb rt,3(base)` sites in stage-2 —
   far too many to be the answer — and worse, the writer need not be byte-granular: a
   `sh rt,2(base)` writes byte 3 as well and is invisible to a scan keyed on offset 3. That is a
   limit of the instrument, not of the data.

I tried to close it by struct layout (the object's fields appear at 0, 2, 3, 4, 6–10, 0x10, 0x12,
0x14) and **the match was a false positive**, checked and discarded: the best candidate,
`FUN_8009e584`, writes offsets 1, 3, 5, 6, 7, 9, 0xb, 0xd, 0xe, 0xf, 0x11, 0x13, 0x15, 0x16 — a
different struct with odd-offset fields. Reporting it as the populator would have been the
plausible-near-miss this project keeps finding.

**What would answer it:** a dump taken *after a room loads* (the two we have predate the object), or
the harness with the struct installed. The question is now purely a runtime one, and the fixed
harness is the instrument.

## 2. Bank C's records point at bank C's payloads — all 28

The audit's one loop, run: **every one of records 39–66 has its cart offset inside
`0xb6248`–`0xc8624`** (39 → `0xb6248`, 66 → `0xc85e8`). So the records point at payloads that the
only reachable loader would reject for lacking `CM == 8`. **Bank C is dead data** in the strongest
sense: the records are well-formed, they point at real bytes, and the pointer to the map that would
select them is never read (M89).

## 3. Branch 1 is unreachable, not merely unfired

The delta histogram — `(vram_end − vram_start) − stored` over all 66 records:

| delta | records |
|---|---|
| `0` | **3** — records 6, 8, 9 |
| `1..64` | 0 |
| `> 64` | 63 (compression ratios ~5–10×) |
| negative | 0 |

So `stored == span` **does** hold for three records — and they are exactly the three with
`stored == 0`, which branch 0 catches first. Branch 1 is therefore **unreachable at all**, which is a
sharper statement than M86's "0 of 66": the test fires, but never first.

That also retires the audit's question about `0x800888ec` for practical purposes. For the record it
is a six-instruction adapter: it saves `a0` in `s0`, reassigns `a0 ← a1`, `a1 ← a2`, and calls
`0x80088764`; as read, the original `a0` (the cart pointer) is not forwarded. Whether `0x80088764`
takes its source from elsewhere is **open**, and moot while the branch cannot be reached.

## 4. The map asymmetry dissolves: 28 slots each

| map | nonzero slots | values | distinct | gaps |
|---|---|---|---|---|
| `0x800eb204` | **28** | 11 … 38 | 28 | none |
| `0x800eb234` | **28** | 39 … 66 | 28 | none |

One slot per record, no aliases beyond the known 57→46, and each map covers exactly one bank:
11–38 is bank B's 28 records, 39–66 is bank C's 28. Both maps carry the same zero pattern
(indices 1–15 and 34, 37, 41, 44, 45 empty), so slots 17–31, 50, 53, 57, 60, 61 are simply unmapped.

**The "27 slots" of M87/M88 was my own filter error** — I counted values in 38…65 inside a map that
runs 39…66, which drops 66 and adds 38. The alignment is exact, and now the arithmetic says so.

## 5. `find_readers.py`'s matching rule, stated

The audit was right that this had to be specified. The tool scans **all 36 images**, and it matches on
**effective address**: it runs a forward abstract pass, tracks registers holding constructed constants
(`lui`+`ori`/`addiu` with signed immediate, `addu`/`or` of two knowns, `li`), and computes
`base + sext16(offset)` for every memory instruction. So any base reaching the window counts, not just
the `-19868(v1)` pattern. It also reports how many memory instructions in the scanned images use a
base that came from memory (38 161) — those addresses are outside its reach, which is why the
word-occurrence check in M89 mattered: it closes that gap, because a value that is never stored can
never be loaded.

One correction to M89's reasoning: "no `+4` derivation at the one site" was the wrong argument. The
right one is that `+4` from the **array base** `0x800eb204` lands at `0x800eb208`, which is still
inside the byte array — not at `0x800eb268`. The pointer word is closed off by the separate fact that
`0x800eb268` appears nowhere as data.

## 6. Table extent and the last record

Indices **1–66 are valid = 66 records**; index 0 is the `OVERLAYTABLENUM` header; index 67 is the
first invalid slot (`stored = 0xCDCDCDCD`). The last record (66) is `0xc85e8`, `stored` 60,
`span` 880 — and `0xc85e8 + 60 = 0xc8624`, which is the container's end, so the 28-record run closes
on its own arithmetic with no padding.

## 7. "Identical decompressed sizes", stated precisely

What is pairwise equal between the banks is their **spans** (`vram_end − vram_start`): record 11 and
record 39 both have 52 112, and so on down the list. **RETRACTED (M91): bank C is not compressed at all.** At `H = 3.59` bits/byte no lossless code can
exceed `8/H ≈ 2.2×`, so its stored bytes cannot be compressed output; the 6.8 figure is
`span / stored`, i.e. destination range over input size. Bank C is low-entropy **structured** data,
and nothing in the loader uses `span` as a length. The audit's reading of "identical decompressed
sizes" was the natural one; mine was wrong.

That also weakens (correctly) an earlier claim: the M82 compare test put bank C's **stored bytes**
against bank B's **decompressed bytes**, so it compared compressed data with plaintext. Its negative
("no 6- or 8-byte literal windows") legitimately rules out byte-aligned LZ with literal runs; it says
nothing about whether bank C's *decompressed* content equals bank B's, which remains unknown and
would need the codec. The pairing itself was right (record 11+N against 39+N, matched by span), so
the measurement stands and only the interpretation narrows.

## 8. Two boundary constants, reconciled

`vaddr.py` uses ROM `0x1000..0x14420`; `mips_harness.py` / `run_guest_sched.py` /
`run_scheduler.py` / `diff_unicorn.py` load `0x1000..0x14600`. **0x14420 is canonical** — the first
zlib member starts there (`68 de`), which `unpack_zlib.py` already defaults to. The harness's extra
`0x1E0` is **480 bytes of that first member** loaded into RDRAM as if it were image bytes; harmless
unless read, and now documented rather than left as a discrepancy between files.

## 9. The off-by-one, as a single retraction

One row in `reverse_engineering_log.md` now carries it, naming what it revises: **M81's "bank C is
slots 38–65" is records 39–66; M82's "bank B is slots 10–37" is records 11–38; M85/M86/M88's map
values are 11–38 and 39–66.** It went unnoticed because the two maps only *align* with the two banks
once the offset is applied, and a misalignment looks like a wrong reading rather than an off-by-one.

## 10. Next

1. **Get a dump after a room loads**, and read `*(0x80115284)` and then its byte 3. One `xxd` each.
   That is the writers question answered by observation rather than reconstruction.
2. If the pointer is still null there, the answer is "the scene path is not exercised in a normal
   boot" — a larger finding than any codec question.
3. The harness follows only for *what the loader does with a known slot*, not for whether the slot
   takes a value.
