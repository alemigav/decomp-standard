# M184 — id 1983 is parsed at the container level, and its codec is a named gap

M182 left id 1983 as "located but unparsed": 9 022 912 B in one file-table entry, no `MORT` records, no
count structure, word 0 read as a count absurd. This milestone closes the container question and records
the codec as a **named gap** rather than leaving it as an adjective.

## 1. The pointer route ends in an address translator

Chasing the same way that cracked id 1979: `DAT_8011a704` (where `FUN_800759d8` stores id 1983) is read
only by `FUN_800752dc` and `FUN_80075608`, both of which pass it as **`param_3`** to `FUN_800a86a0` —
the call that takes all five sound arrays at once:

```c
FUN_800a86a0(DAT_8011a700, uVar1, DAT_8011a704, DAT_8011a708, DAT_8011a70c);
/*            SND_PROJ      song   id 1983       SND_SMPDIR    SND_POOL      */
```

`param_3` has exactly one consumer, `FUN_800a5c98(param_3)`, and that function is **71 bytes of address
translation**:

```c
if (((param_1 & 0xff000000) != 0x80000000) && ((param_1 & 0xff000000) != 0xb0000000))
    param_1 = (*_DAT_80144004)();
```

So the CPU converts id 1983's cartridge address to a physical address and hands it on. **No MIPS code
parses its interior** — the same conclusion class as M182's second reading, now established for this file
by following the pointer to its end.

## 2. But the directory frames it, exactly

The consumer's other argument is `SND_SMPDIR` (id 1982), and `FUN_800ad330` walks it as **28-byte records
terminated by a `-1` short**. That is a real framing, and it decodes:

| | |
|---|---|
| `SND_SMPDIR` (id 1982) | 33 380 B = **1 192 × 28** + `ff ff ff ff` |
| `u16` at +0 | sequential index **1..1192** |
| `u32` at +4 | a **strictly ascending byte offset into id 1983**, first = 0, last = 9 014 776 |
| `u16` at +14 | a **sample rate**, **15 distinct** values, all canonical: 16000 ×601, 11025 ×308, 14000 ×192, 22050, 18000, 12000, 9800, 8800, 6800, 20000, 38000, 33075, 14400, 20200, 22058 |

and the decisive measurement: **the 1 192 lengths sum to 9 022 912, exactly the file size.** id 1983 is
**the concatenation of 1 192 samples with no gap, no overlap and no padding between them**, each 4-byte
aligned (all 1 192 lengths divisible by 4, minimum 336 B).

That is the container parsed. The odd rates are the giveaway that this is a *sampler* bank: 33 075 is
1.5 × 22 050 and 22 058 is a pitch-shifted 22 050 — exactly what a per-sample base rate looks like once a
sound has been transposed.

## 3. The codec is a named gap, kept open by measurement

Knowing the byte boundaries is not knowing the encoding, and the negatives are gated so the gap cannot
quietly turn into an assumption:

* **not plain 16-bit PCM** — the even-byte ("high") plane has entropy **7.006** against the odd plane's
  **7.309**, and `0x00`/`0xFF` together are only **8.1 %** of it. Real 16-bit speech PCM concentrates the
  high plane far harder; this is a packed or residual code.
* **not MORT-framed** — zero records (M178's law, still required to hold).
* **the length is not in the record** — five candidate laws from the two varying fields (`f18·3/2`, `f18·2`,
  `f18`, `f6·2`, `f6`, each 4-byte aligned) fit **at most 2 of 1 192** samples.

So the gap has a precise name: **the per-sample codec of id 1983, given 1 192 byte-ranges and their rates.**
It is answerable — every sample's extent and rate is known — but not by any field in the directory, and not
by CPU code, because §1 shows there is none.

## 4. Where the 17.6 MB stands

| | |
|---|---|
| id 1979, 8 560 916 B | **container decoded**: 588-record `MORT` bank, directory and 10-byte record header proven; `u16@+4` unassigned |
| id 1983, 9 022 912 B | **container decoded**: 1 192 samples, exactly tiled, per-sample rates; **codec open** |
| the idle 69 310 B between them | not padding — ids 1980–1982, `SND_PROJ`/`SND_POOL`/`SND_SMPDIR` |

Both blobs are now framed end to end. What remains in either is a *codec*, not a container.

## 5. Gates

`file table (cartridge)` **35 → 43**: the directory's size and terminator, the sequential index, the
ascending in-range offsets, the exact tiling, the 15 rates, the 4-byte alignment, and the two refutations
that keep the codec open. Audit **44/44, 0 vacuous**; ratchet refused `35 → 43` until `--write`; counts
derived and asserted in twelve places.

Repository is **33 suites / 375 cases**, of which **12 suites / 170 cases** are cartridge-gated, so the
runnable tier is **21 suites / 205 cases**.
