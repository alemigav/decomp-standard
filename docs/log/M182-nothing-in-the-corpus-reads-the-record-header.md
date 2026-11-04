# M182 — nothing in the corpus reads the record header

M179 left `u16@+4` unassigned and named the next route: not more statistics, but the code that reads it.
This is what that search found. It found no reader, and the shape of the absence is specific enough to be
worth more than another hypothesis.

## 1. Three negatives, each pinned to a measurement

| question | answer |
|---|---|
| does any built image or unpacked member contain the literal `MORT`? | **no** — 4 798 files scanned, none with it (and the bank itself is not among them: id 1979 is stored raw, so it is not an unpacked zlib member) |
| is the audio cluster decompiled? | **yes, completely** — 26 functions in `0x800b3000`–`0x800b6000`, **0** missing |
| does any decompiled function write a field at literal `+0x1a4`? | **4 writes in the whole corpus**, and **none** is in the audio family (`FUN_800b*`/`func_800b*`) |

The third is the load-bearing one, and it *should* be surprising: `FUN_800b4a04`, which streams the record
to the audio interface, reads `+0x1a4` and `+0x1a8` on its first pass to initialise the stream state:

```c
*(undefined2 *)(param_1 + 0x11a0) = *(undefined2 *)(param_1 + 0x1a4);
*(short *)(param_1 + 0x11a2)     = (short)*(undefined4 *)(param_1 + 0x1a4);
*(uint *)(param_1 + 0x11a4)      = *(uint *)(param_1 + 0x1a8) & 0xffffff;
```

So the reader exists, is decompiled, and consumes two fields of the voice struct that **nothing in the
corpus writes**. The corpus census is 3 678 function ranges across 36 images with **74** lacking a `src`
file, and `0` of those 74 gaps lie in the audio range `0x800b0000`–`0x800bffff` — so the writer is not a
missing function in the obvious place either.

## 2. What that combination means

Two readings, and they are not equally likely:

* **The header is copied, not parsed.** No code validates `MORT`, so the ten-byte header is skipped at a
  **fixed offset**. If the header is copied into the voice struct (or DMA'd with it), then `+0x1a4` holds
  `[u16 field][u16 rate]` as one word — which is exactly what `FUN_800b4a04` does with it: it takes a
  `u16` from `+0x1a4` and a *`short`* from the same address as a `u32`, which is the signature of reading
  two adjacent halves. Under this reading `u16@+4` lands in the high half and the rate in the low, and the
  rate being in the low half is consistent with `(short)` of it yielding 16 000/8 000.
* **The field is consumed by the RSP, not the CPU.** If nothing on the CPU side reads it, the audio
  microcode might, in which case no further MIPS reading will ever assign it.

Both are **stated as readings, not findings**. Neither is gated, because neither is a measurement.

## 3. The honest limit of the third negative

`0x1a4` is a *literal offset* in Ghidra's rendering. The same struct field can be reached through a
different base expression (`iVar + 0x54` where `iVar = voice + 0x150`), in which case a write exists and
this search cannot see it. So the accurate claim is:

> no decompiled function writes the voice struct's `+0x1a4` **at that literal offset**

and not "nothing writes the field". The gate is written to that weaker, true statement. This is the same
distinction as M179's parity sentence: a refutation of one encoding is not a refutation of a quantity.

## 4. What this buys

* The ten-byte skip is **by fixed offset, with no sentinel check** — so a matching build can lay out the
  header without a magic comparison, and a wrong assumption about its size will not be caught at runtime
  by a tag check. That is a real constraint on any reimplementation.
* `u16@+4` is now known to be **unassignable from the decompiled corpus at its literal offset**. Searching
  further in the same way is not a plan; the two remaining routes are a different base expression, or the
  microcode.
* The `+0x1a4` half-word structure is a **testable prediction** for whoever finds the writer: if the
  fifteen-high-bit `field` appears at `+0x1a4` and the rate at `+0x1a6`, the copy reading is right.

## 5. Gates

`file table (cartridge)` **28 → 35 cases**, seven of them these negatives:

* no built image or unpacked member contains `MORT` (4 798 files scanned);
* the corpus census is 3 678 ranges with 74 gaps;
* the audio cluster is 26/26 decompiled;
* none of the 74 gaps is in `0x800b0000`–`0x800bffff`;
* exactly 4 writes to a literal `+0x1a4` exist, none in the audio family;
* no decompiled function addresses `0x80158c`–`0x80158e`;
* `FUN_800b4a04` still reads `+0x1a4`/`+0x1a8` as stream state (source-pinned).

A negative that is not pinned to a measurement decays into a belief, which is why all seven are gated. Audit
**42/42, 0 vacuous**; ratchet refused the `28 → 35` increase until `--write`; counts derived and asserted in
twelve places.

Repository is **33 suites / 361 cases**, of which **12 suites / 160 cases** are cartridge-gated, so the
runnable tier is **21 suites / 201 cases**.
