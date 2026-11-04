# RE2-64 cartridge formats — what has been established, and how

Everything here is derived from the user's own dump plus code read out of it. Each claim names the
tool that produced it and the measurement that supports it. Anything not measured is marked
**hypothesis**.

```
vram = rom_offset + 0x7FFFF480            ROM 0x1000  <->  vram 0x80000480
```

Getting this wrong shifts every address by `0x480`; three independent tests recover it (see
`docs/log/M7-mapping-correction.md`). Recovery recipe, ~2 seconds:

```sh
python3 -c "…"   # score candidate bases by: fraction of jal targets landing on prologues,
                 # plus count of embedded-string addresses constructed as lui/addiu pairs
```

---

## 1. Cartridge layout (whole image, 67 108 864 B)

| region | bytes | content |
|---|---|---|
| `0x0`–`0x40` | 64 | header (entry `0x80000480`, `NREE`, rev 1, USA) |
| `0x40`–`0x1000` | 4 032 | IPL3 bootcode |
| `0x1000`–`0x12140` | **69 952** | boot bank — 243 splat functions, code only (69 184 was wrong; M81) |
| `0x12140`–`0x14420` | 8 928 | boot data, then the descriptor table at `0x12cd0` |
| `0x14420` → | ~8.7 MB | zlib members (4 761), contiguous from the boot set onward |
| see §4 | ~24.4 MB | MPEG-1 video, 271 container blocks |
| see §5 | ~15.8 MB | MJPEG frames, 1 227 container blocks |
| see §6 | ~17.6 MB | two unidentified blobs |

`splat` classifies 0.11 % of the cartridge as code and 99.89 % as unknown; the unknown is assets, not
unread code.

---

## 2. The cart descriptor table — `vram 0x80012150`, ROM `0x12cd0`

The table **names itself**: the 16 bytes at its base are ASCII `OVERLAYTABLENUM` followed by a count
byte `0x43` = **67** (measured M81, `tools/read_overlay_table.py`, which finds the marker instead of
trusting the address). Record 0 begins at vram `0x80012160`.

Producer, two instructions of code:

```c
int FUN_80001180(int index) { return index * 0x10 + 0x80012150; }
```

| offset | field |
|---|---|
| +0 | **direct cartridge pointer** `0xB0xxxxxx` (= KSEG1 cart window, offset `xxxxxx`); the boot DMA path masks it with `& 0x0FFFFFFF` because a PI register needs a physical address |
| +4 | stored (compressed) size |
| +8 | destination vram start |
| +12 | destination vram end (= start + decompressed size) |

**66 records validate; the declared 67th looked broken and is not** (corrected at M146). It sits at vram
`0x80012580` with a cart pointer (`0xb00c8624`), a size field of **`0xCDCDCDCD`** — the only occurrence of
that word in the whole cartridge — and two zero fields. M146 found its user: `FUN_80004954` reads
`cart_record(0x43)` and treats it as the **file table**, not as a payload to load —

```c
_DAT_800128a8 = *cart_record(0x43);              /* = 0xb00c8624, i.e. ROM 0x0c8624 as a KSEG1 address */
read 0x28 bytes -> word 0 = 8091 entries, then "Tue Sep 28 02:31:44 1999"
_DAT_80012874 = table + 0x28;                    /* 8-byte {offset, size} entries, offsets relative to 0xc8624 */
```

So the two zero fields are correct: this record has no destination and no decompressed size because it is
not part of the load list at all. `FUN_80004cfc(id)` is the load-by-id built on it, and `DAT_80131fa8[room]`
(stage-2) supplies the id — the route M146 used to decode a room script out of the cartridge.

Payload 737 779 B stored, destinations **four** rather than one per overlay:

| destination | records | reading |
|---|---|---|
| `0x80018a80` | 1 | stage-2 code image |
| `0x8017b410` | 6 | staging bank A |
| `0x80161cf0` | 28 | staging bank B |
| `0x8016e880` | 29 | staging bank C |

So this is a **fixed load list into three staging banks**; the nine-slot registry at `0x8010b2e0`
(§5b) is a subset of it. A whole-ROM sweep finds this table and no other
(`tools/find_cart_table.py`); every code payload in the cartridge is named by it (M81 census).
28 records of bank B have **identical decompressed sizes, in the same order**, as 28 of bank C's 29,
with different compressed sizes — an open question, not a claim.

Loader: `FUN_80000598` — record → `FUN_8000C870(0, cart & 0x0FFFFFFF, 0x8015B030, size)` (DMA to a
staging buffer) → `FUN_80004550/DC/94` (inflate).

---

## 3. Compression: stock zlib, 16 KB window

The three `FUN_80004*` calls are stock `inflate`: `0x8000` window allocated at state `+0x4c`, window
size `0x8000` at `+0x10`, `trap(0)` on error, and `inflate.c`'s error strings elsewhere in the image.

Streams begin `68 de`: `CMF 0x68` = deflate, `CINFO 6` = **16 KB window**, `(0x68*256+0xDE) % 31 == 0`.
**A scanner keyed on the common `0x78` header finds zero streams in this cartridge.**

`tools/unpack_zlib.py` walks the image sequentially with `decompressobj().unused_data`, so boundaries
are exact rather than guessed: **4 761 members, 8 748 242 B → 18 550 424 B in ~10 s**, output plus
`manifest` to `assets/unpacked/`. Cross-check: the walker and the code-derived descriptor table agree
on 35/40 boot records in both offset and decompressed size.

---

## 4. Media container — **discovered format, verified**

Blocks are stored **payload first, then an 8-byte trailer**:

```
block := payload [pad] trailer
trailer := u32 type, u32 payload_size        big-endian
pad     := 1 byte, present when payload_size is odd
```

Evidence, from 1 226 known frame transitions in the MJPEG region
(`tools/scan_headers.py derive --jpeg-region …`):

| measurement | result |
|---|---|
| field that explains anchor spacing | `u32` at **next-anchor − 4**, big-endian |
| residual `(anchor[k+1] − anchor[k]) − size` | **8** in 52.5 % of cases, **9** in 47.5 % — and 9 exactly when the size is odd |
| trailer type word across all frames | `0x00010000` in **1 226 / 1 226** |

Because the size sits *after* its payload, a block cannot be walked forward by reading its header —
the parser must resolve it backwards: given a payload start `p`, find a trailer at `t` whose declared
size equals `t − p` (or `t − p − 1` when one parity byte is present). A wrong `t` predicts a size that
does not match, so it is rejected rather than trusted. That is `tools/extract_blocks.py`.

### The critical experiment: one parser, four resource kinds

`tools/extract_blocks.py` with `manifests/block_types.json`, dry-run then real:

| kind | region | starts | resolved | payload | coverage |
|---|---|---|---|---|---|
| `mjpeg_frame` | `0x2bdefa9`–`0x3af17fe` | 1 227 | **1 227** | 15 794 094 B | **99.9 %** |
| `mpeg1_video` | `0x1440f30`–`0x2b7d8ea` | 271 | **271** | 24 363 189 B | **100.0 %** |
| `region_r3` | `0x0b73fb3`–`0x140ed84` | 1 479 | **0** | 0 B | **0.0 %** |
| `region_r4` | `0x0338fe1`–`0xb63106` | 1 | **0** | 0 B | **0.0 %** |

**Answer: yes for both media kinds, no for both unknown blobs.** The same parser, the same trailer
type and the same arithmetic resolve the known MPEG resource and all 1 227 JPEG frames without a
single failure — so the format is reusable within its class. The two unidentified blobs are a
*different* container, not a variant with different constants: 1 479 candidate starts in R3 and every
one fails the self-consistency test.

Independent confirmation that the boundaries are real, not just self-consistent: concatenating the
first ten MPEG blocks yields a stream `ffprobe` reads as `mpeg1video 240×120`, duration 18.89 s. A
wrong boundary would corrupt the stream.

---

## 5. Still unidentified — and what has been eliminated

| blob | size | measurements |
|---|---|---|
| `0x0b73fb3`–`0x140ed84` (R3) | 9 022 929 B | entropy **7.1893** (was stated 7.08); **0 x `00 00 01 B3`**; 214 x `00 00 01 00`, 133 x `ffd8ff`, 1 484 x `fffb`, 319 x `8000` |
| `0x0338fe1`–`0xb63106` (R4) | 8 560 933 B | entropy **7.9371** (was stated 7.34); 2 x `00 00 01 B3` at one identical spacing (coincidence), 1 x picture code, 29 x `fffb`, 735 x `8000` |

**M178 — both are single file-table entries, and the family is the sound system.** R3 is file id
**1983** (cart `0x0b73fbc`–`0x140ed7c`, **9 022 912 B**) and R4 is id **1979**
(`0x0338fea`–`0x0b630fe`, **8 560 916 B**): **17 583 828 B** together, and each boundary is **9 B** inside
the span above at the head and **8 B** at the tail — the spans were inverted from zlib coverage and are
that much too generous, which is the "preceding block's trailer" effect noted at the end of this
document. Between them sit **exactly** ids 1980, 1981 and 1982 — the files `FUN_800759d8` tags
`SND_PROJ`, `SND_POOL` and `SND_SMPDIR` — and both blobs are loaded by that same function. id 1979's own
format is decoded there: a `[u32 count][count x u32]` directory of **588** records, each beginning
`MORT` with a 16 000/8 000 Hz field. The codec of the 28-payload container below is still open, but it is
now a sub-problem of one file rather than an unidentified 8.6 MB. See
`docs/log/M178-file-table-and-the-sound-family.md`.

**M81 addendum — the first content identified inside R4.** The tail of R4 holds a **non-zlib
container** starting at cart `0xb6248` (immediately after a 519-byte zlib member plus its padding
byte): `02 23 18 00 00 03 ac …`, which inflates under no zlib variant. It carries **28 code
payloads** whose decompressed sizes match 28 of the 29 records in staging bank C one-for-one.
They are absent from the decompiled corpus until that container is decoded. Its geometry, its
structural invariants and the codec families that have been *rejected* are in
`docs/log/M82-r4-container-and-gaps.md`; their decoded content and their identity with bank C's
size-paired zlib payloads are both **unestablished**, not assumed. This also means R3 and
R4 are *not* interleaved with zlib members to the degree implied here: only 3 members overlap R3
(1.45 %, all in its first 20 475 B) and 1 overlaps R4 (0.19 %).

### Eliminated for R3 by the `00 00 01 B3` experiment

Command: `tools/scan_headers.py … derive --region 0x0b73fb3:0x140ed84 --magic 000001b3`,
with R1 as a positive control:

| region | `000001b3` anchors | parity-model score |
|---|---|---|
| R1 (known MPEG-1 container) | 271 | **100.0 %** (C = 8, the 9s all have odd sizes) |
| **R3 (unknown)** | **0** | not applicable — no sequence header exists |
| R4 (unknown) | 2 | one spacing only, i.e. coincidence |

So **R3 is not an MPEG-1 video container**: there is no sequence header anywhere in 9 MB. R4 has two,
at a single spacing, which is the signature of accidental byte matches rather than framing.

Two further rejections for R3, both with the same parser:

- media container with JPEG payloads: 134 anchors, **0 resolved**
- the general trailer rule: 1 479 candidate starts, **0 resolved**

A second attempt, using the trailer *type word* as the anchor (`--magic 00001000`, which `derive` now
supports via `--max-after`), reached only 33 % and is not evidence.

### Stride probe (M12) — R3 and R4 do **not** share a block stride

`tools/scan_headers.py stride` measures byte agreement at lag S over three 64 KB windows spread
through a region, then builds an **empirical null by shuffling the same bytes** (the histogram
survives, only order dies — exactly the property under test). The null is not optional: a negative
control on the zlib asset region (`0x20000`–`0x80000`, no block structure) already shows 2.1x-floor
spikes, so "2x over median" alone proves nothing.

Same lag set, both regions:

| lag | R3 agreement (z vs null) | R4 agreement (z vs null) |
|---|---|---|
| **40** | **4.067 % (z +43.7)** — R3's strongest | 0.668 % — **below R4's own median**, i.e. absent |
| 80 | 3.458 % (+25.7) | 0.668 % — below median |
| 16 | 2.975 % (+24.4) | 0.797 % |
| 24 | 2.816 % (+23.3) | 0.818 % |
| 144 | 2.102 % (+12.5) | 0.874 % |
| **72** | 1.794 % (+10.1) | **1.084 % (z +29.5)** — R4's second structure |
| **260** | 1.429 % (**z +4.4 — noise**) | **1.182 % (z +34.9)** — R4's strongest |
| 520 | 2.379 % (+15.0) | 1.002 % (+28.5) |
| 780 | 1.155 % (**z +0.7 — none**) | 0.846 % (+15.4) |

Medians: R3 2.379 %, R4 0.846 % (R3's byte distribution is skewed, hence the higher floor).

**Conclusion: no shared stride.** R3 is periodic at **40** (and 80 = 2x40); R4 at **260** (520 = 2x260)
and **72** (144 = 2x72). Each region's characteristic lag is near-absent in the other — R3 at 260 is
z +4.4, indistinguishable from noise, and R4 at 40 sits *below* its own median agreement.
`gcd(40, 260) = 20`, but lag 20 is not a peak in either region, so the common divisor is arithmetic,
not structure.

Two honest limits:

1. **Periodic is not the same as block stride.** A repeated inner field (a counter, a pointer, a
   per-record checksum) produces the same signature. The probe establishes a period, not a framing.
2. **The null is a shuffle null**, so any real local structure scores z > 0. The evidence is the
   *ranking within a region* and the *absence of the other region's lag*, not the z value alone.

What a 40-byte period means for R3 is still open. A 40-byte record with one changing field would
produce agreement ≈ (constant bytes)/40 + 1/256; the measured 4.07 % against a 1.08 % null implies
roughly **one to two repeating bytes per 40**, which is the weakest possible structure — consistent
with a per-record field that mostly changes (an offset, an index, a checksum).

### Phase sweep (M13) — the 40-byte period is diffuse, **not** a record field

`tools/scan_headers.py phase --region … --stride 40` measures, for each byte position
inside the period, how often that position repeats in the next record. Each phase is scored
against **its own** marginal distribution (`sum p^2` of that phase's values), so a merely skewed
position cannot pass — which matters, because the top-scoring positions are all odd and R3's odd
bytes are the high half of 16-bit samples.

R3, stride 40 (all 40 phases shown in the tool run; top 8 here):

| phase | agreement | vs own null | top byte | distinct values |
|---|---|---|---|---|
| 9 | 10.66 % | 9.39x | 0x00 (4.0 %) | 249 |
| 25 | 11.69 % | 8.95x | 0x00 (4.8 %) | 237 |
| 33 | 7.51 % | 8.10x | 0x00 (4.0 %) | 254 |
| 1 | 8.02 % | 7.59x | 0x00 (4.2 %) | 249 |
| 16 | 6.19 % | 6.82x | 0x00 (3.5 %) | 253 |
| 32 | 5.17 % | 5.06x | 0x00 (5.0 %) | 256 |
| 8 | 4.86 % | 4.80x | 0x00 (4.3 %) | 255 |
| 0 | 4.78 % | 4.55x | 0x00 (4.0 %) | 252 |

**Every one of the 40 phases is above its own null** (mean 3.54x, none at or below), and the
elevation is *uniform*: the lag-40 agreement of 4.07 % is exactly the average of the phases.

**So there is no repeating field.** A record structure with a header byte would put one or two
phases near 100 %; the maximum here is 11.7 %, with 237–256 distinct values at even the best phase, and
the modal byte (`0x00`, 4–6 %) is only the region's baseline skew, not a marker.

R4 at its 260 period behaves the same way, and weaker: mean ratio 2.06x, **38 of 260 phases at or
below their own null**, best phase 2.79 % with 237 distinct values.

### Consequence: M12's "R3 period 40" is demoted

A period with no position standing out is not evidence of records. The honest reading is that lag 40
is a **diffuse autocorrelation peak** — most likely from redundancy in the data itself (near-duplicate
blocks, or 16-bit samples whose high bytes are skewed) — and not a block stride. Nothing about R3's
container is established by it.

### Match-run length (M14) — the runs are **fills**, so the demotion is confirmed

The test that separates "approximate record repetition" from "byte-level artifact" is run length:
whole-record repetition produces multi-byte runs; skew produces isolated single matches. Added as
`scan_headers.py runs --stride N` (run histogram against a shuffle null, plus the distinct-value count
over each run's span, which is what tells a repeated record from a constant fill).

R3, lag 40, three 64 KB windows:

| run length | observed | shuffled null | ratio |
|---|---|---|---|
| 1 | 5 914 | 2 129.0 | 2.8x |
| 2 | 112 | 23.2 | 4.8x |
| 3 | 6 | ~0 | — |
| 4 | 15 | ~0 | — |
| 5 | 2 | ~0 | — |
| 6+ | 36 | ~0 | — |

59 runs of length ≥ 3, and the null produces essentially none — so there *is* multi-byte repetition.
But the span inspection says what it is:

| longest runs | offset | content |
|---|---|---|
| 482 B | `0x0b80582` | **all zeros** |
| 466 B | `0x0b7925b` | **all zeros** |
| 105 B | `0x0b740bc` | **all zeros** |
| 51 B | `0x0fc04b9` | **all zeros** |
| 42 B | `0x0fbb7fa` | **all zeros** |
| 41 B | `0x140437c` | `fff9fff9fff9fff9…` — a repeated 16-bit sample, not records |

Accounting over the analysed 192 KB: **10 of the 59 runs are constant fills and they carry 68 % of all
multi-byte matched bytes**; 13 more are the repeated-2-byte-sample shape; the remaining 49 non-fill runs
total only **582 bytes**, a few bytes each.

**A constant stretch matches at every lag**, so zero-fill inflates the lag-40 rate — and a shuffle null
cannot produce a 482-byte zero run, which is precisely why the null test alone looked like structure.

**Conclusion: R3 has no record structure at stride 40.** The period is fully explained by fills plus
per-byte skew. M12's "period 40" is retracted, not merely demoted.

### The general lesson, third instance

After "is it above the null?", the next question is **"what else would produce this?"**. A null tells
you the measurement is not chance; it does not tell you the measurement is what you named it. Fill
stretches, per-phase skew and a hardcoded `0x78` header all passed a statistical test and all meant
something other than the intended reading.

### What is left for R3

The head of the region is `… 64 fe 27 fe 74 ff 21 ff a0 ff e3 ff fe 00 05 00 05 06 b6 03 c8 01 a0 00`
— a run of `0xFF` high bytes, the shape of **16-bit samples that are mostly negative**, i.e. audio.
1 484 `fffb` frame syncs are too sparse (one per 6 KB) to be a dense MP3 stream, so that is not yet a
claim either. **Hypothesis, not finding:** R3 is audio (VADPCM/PCM) or a texture archive; R4 likewise.
Both regions were entered mid-block by the coverage pass, so the first bytes are cut points, not
headers — which is why their apparent "headers" disagree byte-for-byte with the verified ones.

## 5b. The scene-load path, and why no descriptor points into R3 (M15)

### Record 0 is the stage-2 code image

The boot loader `FUN_80000598` ends by calling `func_0x8004d344` — an address **outside** the boot bank
(`0x80000480`–`0x800120C0`). That was never a stray reference: boot table record 0 is

| | |
|---|---|
| cart offset | `0x14420` |
| stored | 385 519 B |
| decompressed to | `0x80018a80` … `0x80136d90` (**1 172 240 B**) |
| `0x8004d344` | inside it, at `+0x348c4`, where the word is `27bdffe0` = `addiu sp,sp,-0x20` |

So record 0 **is** the stage-2 image, decompressed into RAM and called. It is `assets/unpacked/00000_0014420_1172240.bin`,
and it is code: **1 240 prologues, 2 237 `jr ra`, 6 457 `jal`**, dense from `+0x8000` to `+0xA0000`, empty at
the tail. Its base is `0x80018a80`.

Wrapped at that base (`tools/wrap_mips_elf.py --base 0x80018a80`), the entry decompiles to a thread spawn:

```c
void FUN_8004d344(void) {
  func_0x80006d60(&DAT_8010b700, 7, FUN_8004d190, 0, &DAT_800c36a0, 0);   /* create, id 7 */
  func_0x8000db90(&DAT_8010b700);                                        /* start */
}
```

Note `func_0x80006d60` is at `0x80006d60` — back **inside the boot bank**. Stage 2 calls the boot bank and
the boot bank calls stage 2, so the two images are one program split across two load units.

### The stage-2 file registry (M16)

Decompiling the thread entry `FUN_8004d190` gave video/RAM setup, not file I/O — so the open was located
by scanning stage 2 for `jal` encodings of the known loader chain instead. Result: stage 2 has **two**
complete inflate chains (`0x80032824`, `0x8004CC1C`), and five calls to the descriptor-table producer
`FUN_80001180`. The file-open is:

```c
/* the open: inflate one descriptor into its destination */
undefined4 FUN_8004cbf4(undefined4 *desc) {
  if (desc[1] == 0) return 0;
  func_0x80004550(stack, DAT_8010b6fc);                    /* inflate init, window buffer */
  func_0x800045dc(stack, desc[0], desc[2], desc[1]);       /* src, dst, compressed length */
  func_0x80004594(stack, 2);                               /* free */
}

/* the call site: slot -> descriptor -> inflate -> per-slot handler */
void FUN_8004cc5c(int slot) {
  uVar1 = func_0x80001180((&DAT_8010b2e0)[slot * 8]);      /* boot table index for this slot */
  FUN_8004cbf4(uVar1);
  (**(code **)(&DAT_8010b2e4 + slot * 8))();               /* handler for this slot */
}
```

So the file system is a **9-entry, 8-byte-per-entry registry at `0x8010b2e0`** (corrected at M138 — the
"32-byte entry, six more words" reading was the adjacent entries, not padding): byte 0 = boot-descriptor
index, word 1 = post-load handler. `overlay_open(slot)` (`FUN_8004cc5c`) is the game's open, and there are
two variants that stash the handler instead of calling it: `overlay_slot_reader(a, slot)` (`FUN_8004cca8`)
via `FUN_8004cd54`, and `overlay_slot_reader_b(slot)` (`FUN_8004cd08`) via `FUN_8004ce40`.

`DAT_8010b6fc = 0x80189a00` is the inflate window, and it is set by the thread entry `FUN_8004d190` —
which ties the two functions together and confirms the entry is the stage-2 init.

### The file-open call, and why no static descriptor can be found (M18)

`FUN_8004d190` itself does no file I/O. It sets video mode and RAM layout (Expansion Pak test at
`< 0x400001`; 320×240 vs 640×480; framebuffer/buffer pointers), then calls four functions, two of which
spawn threads:

| call | what it is |
|---|---|
| `FUN_8008af6c` | one line: `DAT_8012bd84 = DAT_8010b6f0` (framebuffer pointer) |
| `FUN_80088910` | `osCreateThread(&DAT_8012bb00, 9, FUN_80088668, 0, &DAT_800c4ea0, 0x3c)` + `osStartThread` |
| `FUN_8006cb94` | controller/eeprom setup, then `osCreateThread(&DAT_80112a40, 1, FUN_8006c0d4, …)` + start |
| `func_0x80000518` | a boot-bank function |

`func_0x80006d60` = `osCreateThread(thread, id, entry, arg, stack, pri)` and `func_0x8000db90` =
`osStartThread`; `func_0x80006d30` / `func_0x8000c9e0` / `func_0x8000cb60` = `osCreateMesgQueue` /
`osRecvMesg` / `osSendMesg`. Thread 1 (`FUN_8006c0d4`) then spawns thread 2 (`FUN_800282e8`).

**The open is called exactly once in the whole stage-2 image**, at `0x800273e4`, inside `FUN_800271d4`:

```c
if (DAT_801344c0 == 1) DAT_801344c0 = 2;      /* earlier in the same function */
...
if (DAT_801344c0 == 2) {                       /* the state machine fires */
  FUN_8004cc5c(0);                             /* <-- open, ALWAYS slot 0 */
  FUN_80026a88();
  DAT_800c4f60 = 1;
  DAT_801344c0 = 0;                            /* reset */
  DAT_800c56f4 = DAT_8010b6e4 == 0;
}
```

`FUN_800271d4` is called from `0x800264e0` and `0x800264f8`, both inside `FUN_8002616c`, in the same
`0x8002xxxx` cluster as thread 2's entry. Proven edges: `FUN_8004d190` → `FUN_8006cb94` →
thread 1 → thread 2 → `0x8002xxxx` cluster → `FUN_8002616c` → `FUN_800271d4` → `FUN_8004cc5c(0)`.
The thread boundaries in the middle cannot be followed by `jal` scanning (a thread entry has no caller),
so that part of the chain is inference from adjacency, not proof.

### The registry is **read-only** in every analysed image (M19) — retracting "mutable slot"

Entry layout, now confirmed by a cross-reference scanner rather than by inference:

```c
struct OverlayEntry {   /* 8 bytes, table at 0x8010b2e0 */
  u8  descriptor;       /* +0 */
  u8  padding[3];       /* +1..3, always zero */
  u32 entry;            /* +4 */
};
```

`tools/xref_registry.py` does a bounded abstract interpretation (MIPS has no absolute store, so it tracks
constants per register through `lui`/`addiu`/`ori`/`addu`, invalidates on writes and on caller-saved
registers across `jal`, and follows pointers **stored into globals and reloaded** — the "pointer held in
another variable" case). Scanned: boot bank (69 KB), stage-2 (1.17 MB), and all six overlay blobs
(~210 KB), window `0x8010b2e0`..`0x8010b328`.

| image | references | **stores** |
|---|---|---|
| boot bank | 0 | **0** |
| stage-2 | 9 | **0** |
| all six overlays | 0 | **0** |

The 9 references are three reader functions (`0x8004cc5c`, `0x8004cca8`, `0x8004cd08`), each of which
constructs the base, reads `+0` with `lbu` (descriptor) and `+4` with `lw` (entry) — which independently
confirms the layout above.

**So the registry is never written, and my previous conclusion was wrong.** I claimed slot 0's index byte
was mutable and rewritten by the scene loader to select which record to open. There is no such write
anywhere in the analysed code. The correct reading is the opposite:

- `FUN_8004cc5c(0)` always opens **descriptor index 2** — cart `0x72610`, 17 022 B → `0x8017b410`,
  entry `0x80180cd0`. It is a **fixed overlay load**, not a dynamic file selector.
- The nine slots are a static resident-overlay table, indexed by constants at each call site.

Coverage limit worth stating: this rules out a write in code we have mapped. Code in regions we have not
mapped (further overlays, or RAM images loaded by paths not yet followed) could still write it.

### No stream walker exists in mapped code (M20) — and that is the answer to "its loop bound"

`tools/find_stream_walker.py` looks for a routine that walks the cartridge window: it classifies a
register as a cart pointer only when the value is **constructed** (`lui`/`addiu`/`ori` into
`0xB0000000`–`0xB3FFFFFF`), then reports every load through such a register plus the innermost enclosing
backward branch and the constant that branch compares against.

| image | result |
|---|---|
| stage-2 (1.17 MB) | **no register ever holds a constructed KSEG1 cart pointer** |
| boot bank (69 KB) | same |

So there is **no loop bound to report**, because there is no loop. Both known consumers read the cart
pointer out of memory and pass it once:

- boot loader `FUN_80000598`: `FUN_8000C870(0, desc[0] & 0x0FFFFFFF, 0x8015B030, desc[1])`
- registry reader `FUN_8004cbf4`: `inflate(state, desc[0], desc[2], desc[1])`

In both, `desc[0]` is loaded from the descriptor record (a `0xB0…` KSEG1 pointer) and used exactly once.
No increment, no comparison, no iteration.

**Limitation, stated because it is the honest edge of this result:** an increment applied to a pointer
that was *loaded* rather than constructed is invisible to this analysis — the value is not a constant, so
no register is classified. Ruling that out needs real data-flow (or a dynamic trace), not this scan.

### Static load-path table, cross-checked against the 4 761-member manifest

This is a **static reconstruction**, not an execution trace. Rows are known call paths evaluated with the
constants the code would use; "descriptor" is the boot-table index.

| iter | path | cart pointer | desc | compressed | destination |
|---|---|---|---|---|---|
| 0 | boot `FUN_80000598` | `0xb0014420` | 1 | 385 519 | `0x80018a80` |
| 1 | registry slot 0 | `0xb0072610` | 2 | 17 022 | `0x8017b410` |
| 2 | registry slot 1 | `0xb007688e` | 3 | 9 087 | `0x8015b030` |
| 3 | registry slot 2 | `0xb0078c0e` | 4 | 9 067 | `0x8017b410` |
| 4 | registry slot 3 | `0xb007e132` | 10 | 6 880 | `0x8017b410` |
| 5 | registry slot 4 | `0xb007af7a` | 5 | 5 592 | `0x8017b410` |
| 6 | registry slot 5 | `0xb007e132` | 8 | 0 | `0x8017b410` |
| 7 | registry slot 6 | `0xb007c552` | 7 | 7 136 | `0x8016e880` |
| 8 | registry slot 7 | `0xb007c552` | 6 | 0 | `0x8015b030` |
| 9 | registry slot 8 | `0xb007e132` | 9 | 0 | `0x8017b410` |

Seven distinct cart offsets (`0x14420`, `0x72610`, `0x7688e`, `0x78c0e`, `0x7af7a`, `0x7c552`,
`0x7e132`), and **every one is a zlib member in the manifest**. That is static agreement between the
code's own constants and the file inventory — not proof of runtime behaviour, and it does not by itself
show that the game ever walks the other 4 754 members.

### Partial CPU harness, and an executed load trace (M21)

`tools/mips_harness.py` executes the game's own instructions. Scope, stated so it cannot be mistaken for
a console emulator: integer/doubleword subset of MIPS III (32-bit view of 64-bit ops), no threads, no
interrupts, no video. What it does provide:

- RAM: 4 MB at `0x80000000`, holding the boot image (ROM `0x1000`–`0x14600`, i.e. **code plus the
  descriptor table at ROM `0x12cd0`**) at `0x80000480` and stage-2 at `0x80018a80`.
- Cartridge mapped at KSEG1 `0xB0000000`, so a `0xB0…` descriptor pointer resolves to real ROM bytes.
  Writes to ROM fault rather than silently succeed.
- The loader primitives are **host hooks**: `inflate` is Python's `zlib` reading emulated memory;
  `osCreateThread`/`osStartThread`/message-queue calls are stubs that are logged. Every run prints what
  was executed and what was stubbed.

**A bug worth recording**: the first run mapped only ROM `0x1000`–`0x12140`. The descriptor table lives at
ROM `0x12cd0`, past the code end, so every `desc[1]` read as zero and all nine slots took the early exit.
A clipped image produces a *plausible* result — nine "no inflate call" rows — rather than an error.

#### Executed trace: `FUN_8004cbf4(desc)` for each registry slot

| slot | desc idx | cart pointer | compressed | destination | decompressed | manifest |
|---|---|---|---|---|---|---|
| 0 | 2 | `0xb0072610` | 17 022 | `0x8017b410` | **49 312** | match |
| 1 | 3 | `0xb007688e` | 9 087 | `0x8015b030` | **27 840** | match |
| 2 | 4 | `0xb0078c0e` | 9 067 | `0x8017b410` | **58 848** | match |
| 3 | 10 | `0xb007e132` | 6 880 | `0x8017b410` | **13 568** | match |
| 4 | 5 | `0xb007af7a` | 5 592 | `0x8017b410` | **20 992** | match |
| 5 | 8 | — | 0 | — | — | early exit |
| 6 | 7 | `0xb007c552` | 7 136 | `0x8016e880` | **15 104** | match |
| 7 | 6 | — | 0 | — | — | early exit |
| 8 | 9 | — | 0 | — | — | early exit |

These rows are produced by *executing* the loader: the pointers, sizes and destinations come out of the
game's address arithmetic and descriptor field loads, not from reading the table. **All six non-zero
slots decompress to exactly the size in the 4 761-member manifest**, and the three zero-size slots reach
the early exit after 13 instructions — which confirms "stored == 0 means no load" by execution rather
than inference.

#### Run 1: `FUN_8004d190` executes and sets its globals

62 instructions with its four callees stubbed: `0x8010b6fc = 0x80189a00` (the inflate window that
`FUN_8004cbf4` later consumes), `0x801137f0 = 0x140`, `0x801137f4 = 0xf0` → 320×240, i.e. the
no-Expansion-Pak branch.

#### Run 2: the last call in `FUN_8004d190` is an idle loop, **not** a file open

`func_0x80000518` decodes to two instructions:

```
0x80000518  1000ffff   b .                  ; branch to itself
0x8000051c  64840001   daddiu a0, a0, 1     ; counter in the delay slot
```

Executed: **400 000 instructions, 2 distinct PCs, zero calls.** It never returns and opens nothing. So
`FUN_8004d190` ends by handing control to a permanent spin — the file open is reached from the thread
path (`FUN_800271d4` → `FUN_8004cc5c(0)`), as established in M18, and not from this function.

### Scheduler increment (M22): the thread graph runs, open(0) does **not** fire

`tools/run_scheduler.py` adds real thread and message-queue semantics on top of the harness:
`osCreateThread`/`osStartThread` build a thread table, `osCreateMesgQueue`/`osRecvMesg`/`osSendMesg` operate
on emulated memory with OS_MESG_BLOCK honored, and runnable threads are scheduled round-robin. Hardware
registers read as zero, so a thread polling one spins and the run reports it.

Starting from the boot chain entry `FUN_8004d344`, execution produces the real thread graph:

```
create thread 0  0x8004d344        (root: the boot chain)
create thread 7  0x8004d190        (stage-2 init)
create thread 9  0x80088668        (from FUN_80088910)
create thread 1  0x8006c0d4        (from FUN_8006cb94)
thread 9 blocks on mesg queue 0x8012bd30     <- real OS_MESG_BLOCK behaviour
```

**After adding COP1 (M23):** FP register file held as Python floats with explicit float32 rounding for
S-format, `mfc1`/`mtc1`/`cfc1`/`ctc1`, `bc1f`/`bc1t`, S/D arithmetic (`add`/`sub`/`mul`/`div`/`sqrt`/
`abs`/`mov`/`neg`, round/trunc/ceil/floor, `cvt.s/d/w/l`), `c.eq/c.lt/c.le`, `lwc1`/`ldc1`/`swc1`/`sdc1`,
correct `lwl`/`lwr`/`swl`/`swr`, `cache` as a no-op, the branch-likely family `0x14`–`0x17` **with delay-slot
nullification when not taken**, and `mfc0`/`mtc0`/`eret`. `ldl`/`ldr`/`sdl`/`sdr` remain **named faults** —
approximating a 64-bit unaligned access as an aligned one corrupts memory silently.

Result: **thread 7 gets past `0x8000ccf0` and runs to completion.**

| thread | state | detail |
|---|---|---|
| 0 (root) | done | boot chain returned |
| **7** | **done** | 3 slices, returned normally — the FPU blocker is gone |
| 9 | blocked | waiting on queue `0x8012bd30` (count 0, 1 waiter) |
| 1 | blocked | waiting on queue `0x8012bcf8` (count 0, 1 waiter) |

60 326 instructions; the run ends because **every thread is either done or blocked**, and nothing ever
posts to those two queues. `open(0)` still does not fire.

So the blocker has moved from *instructions* to *event sources*. The queues are posted by hardware
interrupts — VI retrace, PI/RSP completion, SI controller — all of which are stubs that return 0 and post
nothing. The next increment is therefore an event source: implement `osViSetEvent` (record the queue and
message), then post a retrace message once per simulated frame and let the driver thread wake.

Two opcodes were **mis-mapped during this increment and then removed rather than approximated**: `0x2D` is
`SDR`, not `daddu` (`daddu` is a SPECIAL function), and `0x3C`/`0x3D` are `SCD`/`SDC1`. An unaligned
dword store emulated as an aligned one corrupts memory silently and makes a run look successful — the
harness now raises a *named* fault instead (`NAMED_OPS`), so a stopped run says which feature is missing.

### Experiment A: `0x14420` is a plain concatenation boundary, not a structure

| observation | value |
|---|---|
| 48 bytes before `0x14420` | `…30 31 32 33 34 35 36 37 38 39 41 42 43 44 45 46…` = the ASCII table `0123456789ABCDEF`, then zeros |
| first 2 bytes of the member | `68 de` — valid zlib header, `%31 = 0` |
| member end | stored 385 519 → ends at ROM `0x7260f`; the next member begins immediately after |
| region `0x133b0`–`0x14420` (4 208 B) | 23 vram-pointer words, 48 % non-zero, mostly zeros — mixed boot data, no length table |

**Answer to A: isolated in the structural sense, not in the layout sense.** There is no per-member
metadata, directory, or size table around the member: it starts with a self-describing zlib header, ends
where zlib's own end marker says, and the next member follows. The container is a bare concatenation of
self-delimiting streams — which is why a sequential walker reproduces it (M9) and why no index is needed
(M15–M19).

### Experiments B and C: scoped, not done

- **B (pointer provenance)** — `tools/xref_registry.py` currently propagates constructed constants and
  follows pointers stored into globals and reloaded. Extending it through stack slots, arguments and
  return values is the natural next step, but note that M21/M22 make part of it unnecessary: for code the
  harness can execute, *running* it beats propagating types.
- **C (init sequence / resource structures)** — this is now directly observable rather than inferred: run
  `FUN_8004d344` under the scheduler and log every global the init threads write in the `0x8010Bxxx`
  range. That is the right way to find the resource structures, and it needs FPU support first.

### Frame tick built; the hypothesis it tested is falsified (M24)

Two FPU-model corrections first, both prompted by review:

1. **FPRs are now 32 x 64-bit raw bit patterns, not host floats.** An S-format value lives in the low 32
   bits and the high 32 bits are preserved; `LWC1`/`SWC1` touch only the low half, `LDC1`/`SDC1` the whole
   register, `MFC1`/`MTC1` move the low half. Storing a Python float per register conflated the two views.
2. Fixing the storage exposed a second bug: the arithmetic block still read `self.f[fs]` as a float, so
   `add.s` would have operated on raw bit patterns. Both are corrected; `cvt.s` now rounds on store.

The two stop points from M22 decode to **`CFC1`** (`0x8000ccf0`, `4442f800`) and **`BNEL`**
(`0x800887b8`, `54600001`) — not SDC1, and not a broad FPU suite. That matches the "implement the minimum
encountered" advice: the extra work was one FP control-register read and one branch-likely.

#### `osSetEventMesg` identified, and a frame tick built

Instrumenting every stub showed exactly one call receiving a queue address:

```
stub 0x8000cc90(event=4,  mq=0x80139f10, msg=0x1)     /* AI          */
stub 0x8000cc90(event=9,  mq=0x80139f10, msg=0x2)     /* SP_BREAK    */
stub 0x8000cc90(event=6,  mq=0x80139f10, msg=0xa)     /* PI          */
stub 0x8000cc90(event=14, mq=0x80139f10, msg=0x8)     /* RDB_PREPARE */
```

So `0x8000cc90` is `osSetEventMesg`, and `0x80139f10` is the hardware-interrupt inbox. The scheduler now
records those registrations and, whenever **every** thread is blocked, delivers the next one as a frame
tick. Posting was also unified, because the first version incremented a queue count without waking a
parked waiter — a silent bug that made the tick look inert.

#### Result: the tick runs, nothing consumes it

| queue | count after 20 ticks | waiters | consumer |
|---|---|---|---|
| `0x80139f10` (event inbox) | **20** | **0** | **none — no thread ever waits here** |
| `0x8012bcf8` | 0 | 1 (thread 1) | app-side |
| `0x8012bd30` | 0 | 1 (thread 9) | app-side |

`open(0)` still does not fire. The hypothesis is falsified rather than merely unproven: delivering 20
hardware events to the registered inbox wakes nobody, because **the thread that would drain that inbox is
not among the threads the boot chain creates** (0 root, 7, 1, 9). Thread 7 registers the events and then
returns; threads 1 and 9 park on two app queues that nothing posts to.

**Next, concretely:** scan the mapped images for the constant `0x80139f10` to find the drainer, and for
`0x8012bd30` to find its poster. Both are single-address searches, and whichever thread appears owns the
piece that is missing from the graph we can start.

### Constant scan: who owns the two queues (M25)

Scanning every mapped image (boot bank, stage-2, six overlays) for both addresses:

| constant | referenced by | reading |
|---|---|---|
| `0x80139f10` | **thread 1**'s entry `FUN_8006c0d4` (13 construct/arg sites) and `FUN_8006cb94` (5 arg sites = the four `osSetEventMesg` registrations) | the hardware-event **inbox**, drained by **thread 1** |
| `0x8012bd30` | **thread 9**'s entry `FUN_80088668` (create + receive) plus helpers `FUN_800885c0`, `FUN_80088764` | owned by **thread 9**; **no mapped code ever sends to it** |

This explains the M24 result precisely. The ticks arrived at the *right* queue — thread 1 is its consumer —
but by the time they were delivered thread 1 was already parked on `0x8012bcf8`, a queue that **thread 9**
fills, and thread 9 was parked on `0x8012bd30`, for which **every reference in mapped code is a
construction or a receive, never a send**. The missing edge is a *producer* for `0x8012bd30`: the game
expects one from a hardware handler or from an overlay this run never loads.

So the dependency chain the game needs is

```
(something) --> 0x8012bd30 --> thread 9 --> 0x8012bcf8 --> thread 1 --> drains 0x80139f10
```

and the first link is the one that does not exist in the code we can execute.

### Commit A / B / C status against the plan

| item | status |
|---|---|
| **A — COP1 foundation**: real FPR representation, observed loads/stores, arithmetic + comparisons, named faults for the rest | **done** — 32 × 64-bit raw, S in low half; named faults cover `ldl`/`ldr`/`sdl`/`sdr`/`lld`/`scd` |
| **B — thread execution**: re-run boot, compare thread creation, record first new boundaries | **done** — thread graph stable (0/7/1/9), thread 7 now *completes* (previously faulted at `0x8000ccf0`), threads 1/9 block on app queues |
| **C — resource access**: instrument cartridge reads, record decompression calls, compare with `manifest.json` | **done in M21** — six executed loads, every decompressed size matches the manifest |

### Execution checkpoints (M26)

`run_scheduler.py` now writes `checkpoint/` at the end of every run:

```
checkpoint/ cpu_registers.json  fpu_registers.json  thread_table.json
            message_queues.json  memory_regions.json  execution_trace.json
            unresolved_instructions.json  run_digest.json
```

`memory_regions.json` carries sha256 over the emulated RAM, the cartridge and the stage-2 image, so a run
is pinned to exact inputs. `run_digest.json` hashes every other file, which makes reproducibility a single
comparison. Two independent runs of the boot sequence produce the **same digest**
(`80436211b50d1229a2a1ef001e1d8ac2f0ec4d28ea404881aa36786abebde223`), so the claim is now
"same cartridge, same images, same initial state → same thread and memory behaviour", and it is checked
rather than asserted.

### Send-site census and event-delivery trace (M27): the producer is *indirect by design*

A constant scan for `0x8012bd30` could never find the producer, and the census shows why. Every
`osSendMesg` (`0x8000cb60`) call site in the mapped images — **51 of them** — classified by how the queue
argument is formed:

| how `a0` is formed | count | consequence |
|---|---|---|
| `loaded` from memory (`lw a0, off(reg)`) | 17 | queue pointer comes from a **table**, invisible to a constant scan |
| register + offset (`addiu a0, reg, imm`) | 21 | same, via a computed base |
| copied from another register (`addu a0, r, zero`) | 11 | same, via data flow |
| unknown | 1 | — |

Not one send site passes a literal queue address. So the phrasing must be **"no producer identified in
mapped code and execution coverage so far"**, not "the producer must be hardware or an unloaded overlay"
— an indirect dispatcher in already-mapped code is exactly the shape this census describes.

Where the hardware layer lives:

| image | `lui 0xA460` (PI) | `lui 0xA440` (VI) |
|---|---|---|
| boot bank | **82** | **19** |
| stage-2 | 1 | 1 |
| all six overlays | 0 | 0 |

The PI/VI handling is libultra in the boot bank, and the libultra send sites whose `a0` is *loaded*
(`0x8000c2b0`, `0x8000c2dc`, `0x8000c41c`, `0x8000c444`, `0x8000c454`, `0x8000e050`, `0x8000e71c`) are the
indirect-dispatch candidates — consistent with `osSetEventMesg` writing an `(mq, msg)` table that the
dispatcher later loads. **But the only queue registered in that table is `0x80139f10`**, so even the
indirect path posts there and not to `0x8012bd30`.

#### The trace, before the deadlock

Two message operations occur in the entire run, both receives on empty queues:

```
0x8000c9e0 recv q=0x8012bd30 msg=- before=0 flag=1 thread 9   <- blocking
0x8000c9e0 recv q=0x8012bcf8 msg=- before=0 flag=1 thread 1   <- blocking
```

**Zero sends occur before the system deadlocks**, so thread 1 never reaches the point where it drains
`0x80139f10`, and the 20 ticks it is sent land in a queue whose consumer is parked upstream.

#### Why the harness cannot observe the interrupt path yet

`mfc0` returns 0, so **CP0 Status reads as zero — interrupts are disabled in the emulated CPU**. No
interrupt can be recognised, so no dispatcher can run, no matter what is posted. That is a harness
limitation, not a property of the game, and it is the thing to fix next: model Status/Cause (at minimum
the interrupt-enable bit, the mask bits and the pending bits), raise an interrupt when a modelled source
asserts, and route it through the game's own exception vector at `0x80000000`.

### CP0 validated, then two mapping corrections, then the real interrupt path (M28/M29)

**Corrections accepted, both of which invalidate part of the M28 write-up:**

1. **`0x80000180` is RDRAM (physical `0x180`), not cartridge ROM.** My "ROM `0xd00`" was this harness's
   image-projection offset, not a hardware translation. Equally, `0xBFC00380` is **PIF boot ROM**
   (physical `0x1FC00380`, offset `0x380`) — a different component from the cartridge's IPL3.
2. **`Cause = 0x2000` is `CAUSE_IP6` (external interrupt level 6), not the N64 VI interrupt.** The RCP
   interrupt is **`CAUSE_IP3 = 0x400`**. M28's trace showed only that the CP0 model accepted a pending
   interrupt on whatever bit was asserted; it did not show a VI interrupt reaching the CPU.

**D1 — the VI path is now the real one.** `HwMemory` models `MI_INTR` (`0xA4300008`, per-device pending
bits) and `MI_INTR_MASK` (`0xA430000C`). A device sets its MI bit; the MI aggregate asserts `IP3` only when
`pending & mask`. Verified in a live run:

```
irq event: ('irq', pending=0x08, mask=0x08, rcp=0x400)
exception at 0x80088668   EPC 0x80088668   Cause 0x400 (IP3)   vector 0x80000180
```

The CPU never sees `0x08` or `0x2000`; it sees `IP3`, which is the layering the manual describes.

**D2 — the vector installation is real, and I was wrong about IPL3.** Write watchpoints on all four vector
addresses fire on the game's own init, from **both** entry points tried:

```
0x80000000 UT_VEC   <- 0x3c1a8000
0x80000080 XUT_VEC  <- 0x3c1a8000
0x80000100 ECC_VEC  <- 0x3c1a8000
0x80000180 E_VEC    <- 0x3c1a8000
```

`E_VEC` afterwards reads `3c1a8000 275a06d0 03400008 00000000` = `lui k0,0x8000 ; addiu k0,k0,0x6d0 ;
jr k0 ; nop`. **The general exception handler starts at `0x800006d0`.** So an empty vector at cold start
is expected — exactly the `osInitialize` behaviour — and there is no need to hunt for a handler in IPL3.

**D3 — dispatch works up to the handler, then stops on missing state.** With the MI path and IP3 enabled,
the interrupt is taken and execution reaches `0x800006d0`. It runs for about `0xa0` bytes and then faults:

```
thread 9 at 0x80000770: ff490020 = sd t1, 0x20(k0)      with k0 = 0
                        -> unmapped access at 0x00000020
thread 7 faulted at pc 0x0 (k0-derived base is zero)
```

So the chain *device → MI → IP3 → CP0 → `0x80000180` → preamble → `0x800006d0`* is demonstrated end to end,
and the handler's own first phase is what remains unemulated: `k0` is zero where the code expects a base
(the preamble sets it, so something between `0x6d0` and `0x770` clears or fails to save it — either state I
do not model, or an instruction whose effect I get wrong).

#### k0 trace: what "clears" it (M30)

A per-instruction trace from the vector to the fault (`TracingCpu` subclass, logging every write to `k0`):

| pc | instruction | k0 |
|---|---|---|
| `0x80000184` | `addiu k0, k0, 0x6d0` | `0x80000000` → `0x800006d0` |
| `0x800006d0` | `lui k0, 0x8001` | `0x800006d0` → `0x80010000` |
| `0x800006d4` | `addiu k0, k0, 0x5000` | `0x80010000` → **`0x80015000`** (handler work area) |
| `0x80000764` | `lui k0, 0x8001` | `0x80015000` → `0x80010000` |
| **`0x80000768`** | **`lw k0, 0x2950(k0)`** | `0x80010000` → **`0x0`** |

So nothing "clears" `k0` incorrectly: the handler **loads** it from **vram `0x80012950`** (ROM `0x134d0`),
and the word in the cartridge at that address is

```
0x80012950:  0x00000000 0x00000000 0x00000000 0x00000000 0x80017840 0x00000000
```

zero, with a plausible pointer in the neighbourhood. The handler therefore depends on a **runtime
initialised global** that no code path in this run writes — a watchpoint on `0x80012950` records **no
hits**. The subsequent `sd t1, 0x20(k0)` at `0x80000770` then faults at address `0x20`.

This is not an emulator bug and not a register-clobber bug: it is a **missing initialisation dependency**.
The handler's work area base `0x80015000` is written (with zero) during the run — one watchpoint hit — which
suggests the code that would populate `0x80012950` is the same init that owns that area.

Conclusion: `device → MI → IP3 → CP0 → vector → preamble → 0x800006d0` now runs entirely inside the
game's own instructions; what remains is the part of initialisation that fills `0x80012950`, which our entry
path never executes.

#### Who initialises `0x80012950` (M31)

Static scan of the table window `0x80012940`–`0x80012980` across all mapped images: 53 references, all in
the **boot bank**, and the writer is the boot loader itself:

| address | in function | kind |
|---|---|---|
| `0x80000cb0` / `0x80000cb8` | `FUN_80000598` | store to `0x80012948` / `0x80012954` |
| **`0x80000f70`** | **`FUN_80000598`** | **store to `0x80012950`** |
| `0x80000dd8` / `0x80000768` | `FUN_80000598` | reads of `0x80012950` |

So the global the exception handler dereferences is initialised by `FUN_80000598` — **the boot loader our
earlier runs skipped** by starting at `FUN_8004D344`. The rest of the window is libultra thread machinery
(`osCreateThread`, `osStartThread`, `osRecvMesg`, `osSendMesg` all read `0x80012948`–`0x80012960`).

Attempting to run that init did **not** yet succeed: starting at `FUN_80000598` ran 186 234 instructions
and then faulted at pc `0x0` (threads 0 and 7), never reaching the store. So the *writer is identified*,
but the path is not yet executed correctly — most likely in the DMA/inflate handoff that precedes the
table initialisation. That is the next thing to fix, and it must be fixed before any interrupt test is
meaningful.

#### MDU ops and scheduler-owned current thread (M32)

Two gaps closed:

1. **MDU instructions implemented** — `MFHI`/`MTHI`/`MFLO`/`MTLO`, `MULT`/`MULTU`, `DIV`/`DIVU` with
   proper signed division semantics and the divide-by-zero results the architecture defines. The handler
   previously stopped at `0x800007f8` on `SPECIAL 0x12` (MFLO); that fault is gone.
2. **The scheduler now maintains the guest's current-thread pointer itself.** Every thread records the
   `OSThread*` passed to `osCreateThread`, and each context switch writes it to `0x80012950` before
   restoring registers. Observed values across switches: `0x0` (boot thread), `0x0`, **`0x8010b700`**
   (thread 7's structure). `osCreateThread`'s 5th/6th arguments were also being read from the wrong stack
   slot (`0(sp)` instead of `16(sp)`); corrected.

This closes the semantic gap identified earlier: a host-side scheduler that starts interpreting at an entry
point while leaving `__osCurrentThread` stale lets threads *run* but leaves the guest's own view wrong —
which is exactly why the exception handler dereferenced a zero.

**Result of the honest re-run (no planted pointer):** the interrupt is taken
(`0x8004d190`, Cause `0x400`), the handler now gets **past** `0x80000770` — the `sd` that previously faulted
at address `0x20` — and fails later at `0x80000f2c` on an unmapped access at `0x00000004`, i.e. a
null-based pointer plus offset 4. So the current-thread identification is supported by the guest's own
behaviour, and the next null is identified with an address and an instruction rather than a symptom.

#### The null base at `0x80000f2c` is the guest's ready-list terminator (M33)

The faulting instruction and its register values, captured at the fault:

```
0x80000f14  lw t6, 0x4(t8)      t6 = node->priority        <- dispatch loop body
0x80000f18  slt ...             compare priorities
0x80000f1c  bne ...             exit if this node is not the best
0x80000f28  lw t8, 0x0(t8)      t8 = t8->next              <- advance
0x80000f2c  lw t6, 0x4(t8)      t8 = 0x0  -> fault at 0x4
```

State at the fault:

| global | value |
|---|---|
| `0x80012948` | `0x80012940` |
| `0x8001294c` | `0x80012940` |
| `0x80012950` | `0x8010b700` (current thread — now scheduler-owned) |
| **`0x80012954`** | **`0x0`** |

So this is libultra's **thread dispatch loop walking a ready queue**, and it dereferenced the priority field of
a node whose `next` was null. libultra keeps ready queues as **circular** lists whose terminator is the queue
head node itself — here the head is `0x80012940`, which is exactly what `0x80012948`/`0x8001294c` already
point at. What is missing is the linkage: the walk should have returned to the sentinel `0x80012940`, not
stepped into null, and `0x80012954` — written by the boot loader's init at `0x80000cb8` and still `0x0` here —
is part of that initialisation.

**So what should be at the null base is the guest's own ready-queue node/sentinel, not a host pointer.** This
is the same class of gap as `__osCurrentThread`: my scheduler maintains a Python thread table and selects
runnable threads itself, while the guest's dispatch routine walks a list that the host never builds. Writing
one pointer (`0x80012950`) was enough to get the handler past context save; it is not enough for the guest to
dispatch threads on its own.

#### Option 1: the host now maintains libultra's circular ready queues (M34)

Node layout taken from the dispatcher itself (`lw t6,0x4(t8)` priority, `lw t8,0x0(t8)` next):
`+0x00 next`, `+0x04 priority`, `+0x08 queue`, `+0x0C tlnext`, `+0x10 state`, `+0x14 id`,
`+0x18 fp`, `+0x20 context`. The sentinel is `0x80012940` (where `0x80012948`/`0x8001294c` point), and an
empty queue is that node pointing at itself.

The scheduler now: writes a real `OSThread` header at each `osCreateThread` address (next/priority/state/id),
initialises the sentinel as a circular empty list, inserts on `osStartThread` and on wake, unlinks on
switch/block/exit, sets state RUNNABLE/RUNNING/WAITING, and keeps `0x80012954` as the tail.

**Result: the `0x80000f2c` fault is gone.** After the run the guest list walks cleanly and circularly:

```
ready list: 0x8012bb00 (thread 9) -> 0x80112a40 (thread 1) -> 0x80012940 (sentinel)
0x80012950 (current) = 0x8010b700 (thread 7)     0x80012954 (tail) = 0x80112a40
threads: 0 done, 1/7/9 runnable     faults: none     exceptions: 2 x Cause 0x400 (IP3)
```

So the guest's own dispatch routine now walks a structure the host keeps coherent, instead of stepping into
null. Three threads are alive and the interrupt is being accepted — where previously the system either
deadlocked or faulted.

**Still not solved, and the honest gaps:**

- `msg log` is empty and `open(0)` has not fired; nothing has been posted to `0x8012bd30` or `0x8012bcf8`.
- Thread 7 now sits in the idle spin at `0x8000051c`, so "all threads runnable" partly means "all threads
  idle".
- **The dual-scheduler problem remains.** Threads that stay runnable are unlinked from the guest list at
  switch and only relinked when they block and are woken, and the host still *chooses* which thread runs.
  Option 1 makes the guest's structures coherent; option 2 — letting the guest's dispatcher choose — is what
  removes the duality rather than papering over it.

#### Phase 1 differential: the host scheduler ignores priority (M35)

Guest state words and priorities read straight out of the `OSThread` headers the scheduler writes, instead
of from the host's Python table:

| thread | `OSThread*` | priority | guest state | pc |
|---|---|---|---|---|
| 1 | `0x80112a40` | **40** | RUNNABLE | `0x8006c0d4` |
| 7 | `0x8010b700` | **0** | **RUNNING** | `0x8000051c` |
| 9 | `0x8012bb00` | **60** | RUNNABLE | `0x80088668` |

The earlier report that "1, 7 and 9 are runnable" was a host-table label, not guest state — corrected here.
**I1 passes**: exactly one thread is RUNNING and it equals `0x80012950` (`0x8010b700`).

Run queue order and priorities: `[... 0x8012bb00 (60), 0x80112a40 (40) ...]` — thread 7 (priority 0) is
running and therefore off the queue. Under libultra priority scheduling the next thread to run should be
**thread 9 (60)**, then thread 1 (40), then thread 7 (0).

**The differential, which is the point of Phase 1:**

```
12 of 15 dispatch points: guest highest-priority ready node != host choice
  step 60023: host chose 0x8010b700 (prio 0)   guest queue says 0x8012bb00 (prio 60)
  step 90023: same
  step 120023: same
```

So the host has been scheduling round-robin while the guest's own structure says thread 9 has the highest
priority. That is the dual-scheduler gap measured rather than argued — and it is exactly the discrepancy
Phase 1 exists to surface before removing host selection.

Note on thread 7: priority **0** (lowest) and resident in the `b .` spin at `0x8000051c` is *consistent*
with an idle thread, but consistency is not proof — the priority came from `osCreateThread`'s stack
argument, so a wrong stack read would also produce 0.

#### Phase 2 started: guest owns dispatch, and it cannot yet run (M36)

`tools/run_guest_sched.py` implements the target architecture, kept separate so the Phase-1 harness still
works:

- **One architectural CPU state.** PC, GPRs, HI/LO, CP0 and FPU live on the CPU; there is no host thread
  table and no per-thread register file. Suspended contexts exist only where the guest put them, in RDRAM.
- **No hooks on `osCreateThread`/`osStartThread`/`osCreateMesgQueue`/`osRecvMesg`/`osSendMesg`.** Those run
  as guest instructions and mutate the guest's own circular lists.
- The host models hardware only: cartridge reads, the inflate primitive, PI DMA, MI pending/mask, and
  register reads that would otherwise spin. It never writes `0x80012950` and never chooses a thread.
- Every guest write to `0x80012950` is logged as a context switch.

**Result: zero guest context switches, on every entry path tried.**

| entry | outcome |
|---|---|
| `FUN_80000598` (boot loader) | 148 324 instrs, PI DMA + inflate used, then fault at `0x80000f2c` (null at `0x4`) |
| `FUN_8004D344` (stage-2 entry) | **123 instrs**, then the same fault at `0x80000f2c` |
| `0x80000480` (real entrypoint) | 42 299 instrs, then pc `0x0` |
| `0x80000520` (`main`) | 21 321 instrs, then pc `0x0` |

In every case `0x80012950` is `0x0` and the ready-list sentinel at `0x80012940` still reads `0x0`, so the
guest dispatcher walks into null. The 123-instruction result for `FUN_8004D344` is diagnostic: the guest
reaches `osStartThread` almost immediately and dispatches into an **uninitialised** ready queue.

**So: the scheduler's own initialisation never runs on any path we can start.** Phase 1 kept working only
because the host wrote the sentinel and the current pointer itself — i.e. it was supplying the very state the
guest owns. Phase 2 removes that crutch and the missing initialisation becomes the fault.

**The digest does not reproduce, and no guest-controlled thread transition has been observed.** Recording
that as not-done: the remaining work is to find and execute libultra's scheduler initialisation (the code that
sets `0x80012940` circular and `0x80012950` to the boot thread) before any `osStartThread`, most likely by
starting where `osInitialize` runs rather than at the entry paths tested here.

#### Six-word comparison: the scheduler state IS statically initialised (M37)

Reference layout aliases exactly as documented, and the cartridge holds the reference initializer:

| address | field | cartridge | emulated RDRAM after the run |
|---|---|---|---|
| `0x80012940` | `__osThreadTail.next` | `0x00000000` | `0x00000000` |
| `0x80012944` | sentinel priority | `0xffffffff` | `0xffffffff` |
| `0x80012948` | `__osRunQueue` | `0x80012940` | **`0x80012940` (unchanged)** |
| `0x8001294c` | `__osActiveQueue` | `0x80012940` | **`0x8010b700` (thread 7)** |
| `0x80012950` | `__osRunningThread` | `0x00000000` | `0x00000000` |
| `0x80012954` | `__osFaultedThread` | `0x00000000` | `0x00000000` |

**Outcome: "both contain the expected initializer".** So the harness *is* reproducing the guest's initialised
data image, and the previous hypothesis — that Phase 2 removed the host crutch but the data image was wrong —
is disproved. There is no missing `osInitialize`-equivalent to hunt for: the state comes from static data at
ROM `0x134c0`.

What the RDRAM column localises instead is sharper: **`osCreateThread` ran and linked thread 7 into
`__osActiveQueue`, but `__osRunQueue` still points at the sentinel** — and the dispatcher, entered because
`__osRunningThread` is NULL, walks a run queue that contains no threads. Its first step
(`lw t8,0x0(t8)` from the sentinel, whose `next` is legitimately `0`) lands on `0x0` and the priority load at
`0x4` faults. So the missing operation is specifically **the run-queue enqueue that `osStartThread` performs**,
not the data image.

Correction to my own reporting: the earlier "no write watchpoints hit" line was meaningless because only
`0x80012950` was being watched. The `0x8001294c` write clearly happened, which is how thread 7 appears there.

#### Phase 2 works: the bug was my inverted `slt` (M38)

The decision-table trace put the fault **inside** the enqueue helper (`jal 0x80000f08` from
`0x8000dc34`), not before it, and the captured loop registers named the cause exactly:

```
0x80000f18  slt r1, t6, t7      t6 = 0xffffffff (sentinel priority), t7 = 0 (new thread)
            -> r1 must be 1       my emulator produced 0
```

**My `SLT` and `SLTI` were inverted** — they returned 1 when the comparison was false. Every priority
comparison in libultra therefore took the wrong branch, the ready-list walk stepped past the sentinel into
null, and the dispatcher faulted. Fixing both (one line each) unblocks Phase 2 entirely.

**Result — genuine guest-controlled scheduling, with the host choosing nothing:**

| entry | instructions | guest context switches |
|---|---|---|
| `FUN_8004D344` | 300 000 | **11** |
| `FUN_80000598` | 400 000 | **11** |

Every switch is a write to `0x80012950` **by guest code at `0x80000f74`** — inside libultra's dispatcher.
The observed order:

```
0x0 -> 0x8010b700 (thread 7) -> 0x800164b0 -> 0x8010b700
    -> 0x8012bb00 (thread 9)  -> 0x8010b700 -> 0x80017868 ...
```

Two thread structures appear that no earlier run ever created (`0x800164b0`, `0x80017868`) — the game's own
`osCreateThread` making threads the host never knew about. Final state: thread 7 `next = 0x80012940`
(linked to the sentinel), `priority 0`, `state 4` (RUNNING), no faults.

So the host now executes instructions and models hardware; the guest owns queue linkage, priority comparison,
context save/restore and the current-thread pointer. This is the first run where the answer to "which thread
runs next" comes from the game's own code.

Not yet established: two identical runs have not been compared as a checkpoint digest, `open(0)` has not
fired, and both message handoffs are still silent.

#### Comparison audit and a real VI through the guest path (M39)

**Audit, and a lesson in test hygiene.** Auditing `SLT`/`SLTU`/`SLTI`/`SLTIU` after the inversion bug took two
attempts because my *test* was wrong twice, both times silently:

1. first version compared `r5` against `r10` without ever setting `r10`, producing two false failures;
2. second version set the registers before `Cpu.run()`, which **resets all registers** — so every case
   compared 0 with 0, and the "expect 0" cases passed by accident.

Verified properly by calling `step()` directly instead of `run()`: **10/10 pass**, including
`sltu 0xFFFFFFFF,1 == 0`, `sltu 1,0xFFFFFFFF == 1`, `slti -1 < 0 == 1`. So only `SLT`/`SLTI` were inverted;
`SLTU`/`SLTIU` were always correct. The failure mode to remember is a test that passes because everything is
zero.

**A real VI interrupt through the guest path.** Hardware asserts VI (MI pending bit 3, mask enabled), the
guest has its own `Status` set, and nothing is injected into any queue:

```
VI asserted at instruction 60000;  Status = 0xff01  (IE=1, IM=0xff)
exception taken at 0x80000518 -> vector 0x80000180
max Status seen 0xff03;  1 exception;  no faults
```

The guest enabled interrupts itself (`IE=1`, all mask bits set), the CPU accepted IP3, and the vector was
taken into the guest's handler — with the host only modelling the device line.

**And the guest's own queue code then touched both wait queues:**

| write | value | meaning |
|---|---|---|
| `0x8012bd30 + 0` | `0x8012bb00` | thread 9's `OSThread*` linked as that queue's waiting list |
| `0x8012bcf8 + 0` | `0x80112a40` | thread 1's `OSThread*` linked as that queue's waiting list |

These are the two handoffs, now produced **by the game's own `osRecvMesg`** rather than by my host scheduler —
the first time the wait chains have appeared as guest-side behaviour rather than as host bookkeeping.

#### Tracing the handler: the vector is empty in Phase-2 runs (M40)

Two instrumentation errors of mine first, because they shaped the result:

1. In the first attempt I called `take_exception()` but **never assigned `cpu.pc` to the returned vector**, so
   the "handler path" I printed was the idle loop, not the handler — and of course no event was delivered.
2. After fixing that, the handler path is `0x80000180, 0x80000184, 0x80000188, …` — **99997 unique PCs,
   marching sequentially**. That is not a handler: it is execution sliding through *zeros*.

**So in Phase-2 runs the exception vector at `0x80000180` is uninitialised at interrupt time.** This is a real
difference from the Phase-1 harness, where watchpoints on `UT_VEC`/`XUT_VEC`/`ECC_VEC`/`E_VEC` fired and
`E_VEC` ended as `lui k0,0x8000 ; addiu k0,0x6d0 ; jr k0`. The vector installation evidently happens on a path
that Phase 1 reached with host assistance and that stand-alone guest scheduling does not reach before 60 000
instructions.

**What the queue trace *does* establish** (all guest code, no hooks):

| pc | write | meaning |
|---|---|---|
| `0x80006d38`–`0x80006d50` | three queues initialised: `+0/+4 = 0x80012940` (sentinel), `+8 validCount = 0`, `+0x10 msgCount`, `+0x14 msg buffer` | `osCreateMesgQueue`, guest |
| **`0x80000f44`** | `q9+0: 0x80012940 → 0x8012bb00` | thread 9 enqueued on its queue's **thread-wait** list (blocking receive) |
| **`0x80000f44`** | `q1+0: 0x80012940 → 0x80112a40` | thread 1 likewise |

Thread 9 and thread 1 both end in state `8` (WAITING). **No delivery occurred**: `validCount` is 0 on all three
queues and the event message buffer `0x80139ff0` is all zeros.

**Answering the five questions in order:**
1. Does the VI handler deliver its registered event to `0x80139f10`? **No — the handler never executed**, because
   the vector was zeros. Not "delivered to the wrong queue": never delivered.
2. Did any thread receive it? No.
3–5. Not reachable this run.

The blocker is now upstream of the queue question entirely: **the exception vector must be installed before the
first interrupt**, and in Phase-2 mode it is not.

#### Vector installation under uninterrupted guest scheduling: never happens (M41)

Phase 2 from `0x8004D344`, VI **never** asserted, 16 watchpoints armed over the four vectors
(`0x80000000`, `0x80000080`, `0x80000100`, `0x80000180`, four words each), 200 000 instructions:

```
vector writes: 0
UT_VEC / XUT_VEC / ECC_VEC / E_VEC:  all 16 bytes still 0x00000000
E_VEC matches the reference preamble (3c1a8000 275a06d0 03400008 00000000): False
```

**So the installation previously observed in the Phase-1 harness did not belong to this run's path.** Of the
three possibilities this experiment was designed to separate:

- *"the initializer is on a thread that becomes runnable later"* — **not supported**: 200 000 instructions is
  far beyond the last thread switch (all 11 occur inside the first ~2 500), so a late-but-runnable thread would
  have run;
- *"another initialization path is required"* / *"the earlier installation belonged to a different startup
  sequence"* — **the remaining candidates**.

The one structural difference between the two harnesses is that Phase 1 **hooked**
`osCreateThread`/`osStartThread`/`osRecvMesg`/`osSendMesg` and faked their success, while Phase 2 lets the
guest's real routines run. A guest routine that continues past a fabricated thread start, but blocks or takes
a different branch when the real queue/dispatch code runs, would explain the difference exactly. That is a
hypothesis, not a finding.

**Shortest next step:** re-run the *Phase-1* harness with the same 16 watchpoints **plus the writer PC**, capture
the PC that writes `E_VEC`, then check whether that PC appears anywhere in Phase 2's executed-PC set. If it
does, the branch that skips it is immediately adjacent; if it does not, the two harnesses diverge before it,
and the divergence is the thing to instrument.

Nothing in this result disturbs the queue findings: both message queues are initialised and both waiting
threads inserted by guest code, both threads WAITING, message buffers empty.

#### The installer is `0x800071b8`, and Phase 2 never reaches it (M42)

Writer-PC logging in the Phase-1 harness, both entries, 16 vector watchpoints:

| vector | writer PCs | preamble written |
|---|---|---|
| `UT_VEC` `0x80000000` | `0x80007140`, `…44`, `…48`, `…50` | `3c1a8000 275a06d0 03400008 00000000` |
| `XUT_VEC` `0x80000080` | `0x80007168`, `…6c`, `…70`, `…78` | same |
| **`E_VEC` `0x80000180`** | **`0x800071b8`** (identical from both entries) | same |

So the installer is a single routine in the boot bank spanning roughly `0x80007140`–`0x800071c0`, and it is not
path-dependent within Phase 1.

**Diff against Phase 2:** `0x800071b8` is **not** in Phase 2's executed-PC set, and neither is any address in
`0x80007140`–`0x800071c0`. Phase 2 executes only **1 478 distinct PCs** in 200 000 instructions, so it is
confined to a small region — the divergence happens *before* the installer, not inside it.

That makes the remaining question narrow and mechanical: which branch in Phase 1 leads into `0x80007140` that
Phase 2 does not take? The candidates are exactly the host hooks Phase 1 installs and Phase 2 does not
(`osCreateThread`, `osStartThread`, `osCreateMesgQueue`, `osRecvMesg`, `osSendMesg`) — the installer is plausibly
reached from an initialisation routine that Phase 1's fabricated thread-start lets continue and Phase 2's real
queue/dispatch path diverts or blocks. Hypothesis, not finding.

Nothing here disturbs the queue results: both queues initialised and both waiters inserted by guest code, both
WAITING, buffers empty.

#### Who installs the vectors, and when (M43)

Phase-1 run from `0x8004D344` with thread-id logging on the installer range
`0x80007140`–`0x800071c0`:

```
FIRST hit: instruction 42,271   thread 7 (entry 0x8004d190)   pc 0x80007140
LAST  hit: instruction 42,302   thread 7                      pc 0x800071bc
threads seen in range: {7: 32 hits}          E_VEC written at instruction 42,301
E_VEC afterwards: 3c1a8000 275a06d0 03400008 00000000
```

**Only thread 7 touches it. The installer is part of thread 7's own initialisation path**, executed about
42 000 instructions in — i.e. inside `FUN_8004D190`'s work, not on a late or separate thread.

Why Phase 2 never reaches it is now specific and explains itself: in Phase 1, `osCreateThread`/`osStartThread`
are **host hooks that return immediately**, so thread 7 continues straight through its init body and reaches the
callee containing `0x80007140`. In Phase 2 the real `osStartThread` **dispatches immediately** to the thread it
just started, so thread 7 is preempted mid-init; the remainder of its body — including the installer — is
deferred, and thread 7 later ends in the `b .` idle spin at `0x80000518` without having run it.

That is a coherent, evidence-backed explanation rather than a hypothesis about missing hardware: the difference
is *where the preemption point falls*, and Phase 1's stubs accidentally moved it.

**Implication for reconciliation:** Phase 2 is the faithful model, so the installer genuinely runs later than
Phase 1 shows — but Phase 2 also never gets back to it, because once thread 7 yields, the resumed thread never
restores thread 7 to a runnable state that continues past the yield point. The single question to answer next is
therefore: **after thread 7's real `osStartThread` preempts it, does anything put thread 7 back and resume it at
its saved PC, or does the game's own logic only resume a specific subset?** The saved-context word in thread 7's
`OSThread` (`+0x20`) answers that directly by comparison with its pre-yield PC.

#### Thread 7's saved context: the comparison I asked for was ill-posed (M44)

Phase 2, 150 000 instructions, 11 switches, thread 7 yields **4 times — all with the "yield PC" reading
`0x80000f70`**. That is a measurement artefact, not a finding: the switch happens *inside* the dispatcher, so
the last PC recorded for the outgoing thread is a dispatcher address by construction. Searching the context
block for that address therefore returns `NONE`, which says nothing about the game.

What the dump does show, at thread 7's `OSThread + 0x20`:

| offset | value | reading |
|---|---|---|
| `+0x118` | `0x0000ff02` | saved SR (`0xff02`: IE=0, EXL=1, ERL=1, IM=0xff — a dispatch-time state) |
| **`+0x11C`** | **`0x8000dc88`** | **saved PC — inside `osStartThread`, i.e. where thread 7 will resume after dispatch** |
| `+0x128` | `0x00000669` | — |
| `+0x12c` | `0x01000800` | — |

So the context machinery **is sound**: thread 7's resume address is a sane return into `osStartThread`
(`0x8000dc88` sits in the `0x8000dc5c`–`0x8000dc88` tail we disassembled), not a dispatcher address and not
zero.

The real observation is therefore different from the one I proposed: **thread 7 is saved correctly and is
re-selected four times, yet never reaches `0x80007140`.** It resumes, dispatches again quickly, and the installer
never comes up in its remaining work. So the question is not "is the context corrupt" (it is not) but "what does
thread 7 do between resuming at `0x8000dc88` and yielding again" — a handful of instructions to trace, and the
right next measurement is thread 7's own PC trajectory *between* switches, not its context block.

#### Thread 7's trajectory: the instrument was wrong a third time (M45)

Per-slice trace with the dispatcher excluded at `0x80000F00`–`0x80000F9F`:

| slice | starts | own instructions | first PC | last own PC |
|---|---|---|---|---|
| 1 | 141 | 665 | `0x80000fa0` | `0x80000efc` |
| 2 | 1058 | 272 | `0x80000fa0` | `0x80000efc` |
| 3 | 1611 | 845 | `0x80000fa0` | `0x80000efc` |
| 4 | 2717 | 455 | `0x80000fa0` | `0x80000efc` |
| 5 | 4363 | 145 626 | `0x80000fa0` | **`0x80000518`** (idle spin) |

Every slice resumes at `0x80000fa0` and ends at `0x80000efc` — both of which are **still dispatcher code**. My
exclusion window was too narrow: the dispatcher evidently extends past `0x80000F9F` in both directions, so the
"own instructions" I counted are dispatcher instructions, and thread 7's application-code trajectory is still
not visible. The saved PC at `+0x11c` (`0x8000dc88`) never appears as a resume point in what I captured, which
is consistent with the restore writing it into the CPU and the dispatcher's tail running before control reaches
it.

So this measurement does not answer the question either. **Three consecutive instruments have now been wrong**
(yield-PC at the switch, context-block search, and this exclusion window), while the emulator's own behaviour
has been consistent throughout: context saved sanely, four correct dispatches, then the idle spin.

The right instrument is different in kind: find the instruction that performs the **context restore and jump**
(the `jr` that consumes the restored PC), record the first PC *after* that jump per slice, and only then compare
with `+0x11c`. That is a disassembly question about `0x80000f60`–`0x8000100` before it is a tracing question.

#### The restore-and-jump is EPC + ERET, not `jr` (M46)

Disassembling the dispatcher tail `0x80000f60`–`0x80001160` gives the full context restore, and it explains why
three of my instruments failed to see a "jump":

| address | instruction | role |
|---|---|---|
| `0x80000f60` | `lui a0,0x8001` / `jal 0x80000f50` | pop next thread from the run queue |
| `0x80000f6c`–`70` | `sw v0, 0x2950(at)` | `__osRunningThread = v0` (the switch write I logged) |
| `0x80000f78` | `sh t0, 0x10(v0)` (t0=4) | state = RUNNING |
| `0x80000f80` | `lw k1, 0x118(k0)` | saved **SR** |
| `0x80000fac` | **`mtc0 k1, $12`** | restore **Status** |
| `0x80000fec`–`0x80001090` | `lw 0x18` + `ldc1 f2..f31` | restore FPU flag and FPRs |
| `0x80001094`–`0x800010b8` | `ld k1,0x108` … `ld at,0x20` … | restore **lo/hi** and GPRs at…ra |
| `0x8000110c`/`1114` | `ld sp,0xf0` / `ld ra,0x100` | restore `sp`, `ra` |
| **`0x80001118`** | **`lw k1, 0x11c(k0)`** | load the saved **PC** |
| **`0x8000111c`** | **`mtc0 k1, $14`** | write it to **EPC** |
| `0x80001148`–`0x80001154` | `lhu …` / `sw k1, 0(A430000C)` | restore **MI_INTR_MASK** |
| `0x80001160` | **`eret`** | resume at EPC — i.e. at `thread+0x11c` |

So the resume is delivered **through CP0 EPC + `eret`**, not a `jr` to a restored register. That single fact
invalidates the instrument I used for M45: I searched for the saved PC as an executed PC inside a window that
ends before `0x80001160`, and the transfer only happens at the `eret`. The saved PC **is** the resume point;
it just arrives via the exception return path.

It also shows the guest restores `MI_INTR_MASK` itself (`0x80001154`) on every context restore — i.e. the mask
is per-thread state in this implementation, which matters for the interrupt wiring: a thread switch can change
which RCP sources are enabled.

Correct next instrument: log the **first PC after `0x80001160`** per slice, which by construction equals
`thread+0x11c` at slice entry, and compare with the previous slice's saved PC. That is now a one-line change
rather than a boundary guess.

#### Resume point verified, and the MI mask is per-thread and clobbered (M47)

The one-line instrument — log the resumption at `0x80001168` (the `eret`) — run for 150 000 instructions,
11 resumptions:

| # | step | thread | resumed at (EPC) | thread+0x11c | MI mask |
|---|---|---|---|---|---|
| 1 | 217 | `0x8010b700` | `0x8004d190` | same | `0xaaa` |
| 2 | 934 | `0x800164b0` | `0x8000c0d0` | same | `0xaaa` |
| 3 | 1134 | `0x8010b700` | `0x8000ce98` | same | `0x999` |
| 4 | 1458 | `0x8012bb00` | `0x80088668` | same | `0xaaa` |
| 5 | 1687 | `0x8010b700` | `0x8000dc88` | same | **`0x696`** |
| 6 | 2584 | `0x80017868` | `0x8000e658` | same | `0xaaa` |
| 7 | 2793 | `0x8010b700` | `0x8000ce98` | same | `0x669` |
| 8 | 3300 | `0x80112a40` | `0x8006c0d4` | same | `0xaaa` |
| 9 | 3883 | `0x800164b0` | `0x8000ca44` | same | `0x999` |
| 10 | 4213 | `0x80112a40` | `0x8000dc88` | same | `0x999` |
| 11 | 4439 | `0x8010b700` | `0x8000dc88` | same | `0x996` |

**Half 1 — the restore path is confirmed: resumption equals `thread+0x11c` in 11/11 cases.** The dispatcher
behaves exactly as the disassembly of M46 predicts, and the earlier failures were instruments, not emulation.
(My table's EPC column was printed with a 17-character width, so it shows `0x00000008004d190`; that is a display
bug in the run, the values are 32-bit.)

**Half 2 — the MI interrupt mask is per-thread and is rewritten on every single resumption:** `0xaaa`, `0x999`,
`0x696`, `0x669`, `0x996`, `0xaaa`… Thread 7's own resumptions alternate between **VI enabled** (`0xaaa`, `0x999`,
`0x669` — bit `0x08` set) and **VI disabled** (`0x696`, `0x996` — bit `0x08` clear).

That is the mechanism behind the Phase-2 interrupt failure, and it is not a bug in the game: the guest restores
`MI_INTR_MASK` from the thread context at `0x80001154`, so **the mask belongs to whichever thread was just
scheduled**. A host-side `MI_INTR_MASK |= 0x08` therefore does not survive the next context restore — my earlier
Phase-2 VI assertions were being overwritten by the guest before a VI could be recognised. Phase 1 masked this
because its hooks never ran the real restore.

So the correct way to model VI is to leave the mask entirely to the guest (hardware asserts `MI_INTR` pending
bits; the mask is guest-owned), which is exactly the layering the manual describes and which this harness was
already built for — it just had one host write too many.

#### Guest-owned mask: VI lands only in `0xaaa` windows (M48)

Host no longer writes `MI_INTR_MASK` at all; hardware asserts `MI_INTR` bit 3 (VI) from step 0 and the guest
owns the mask. 150 000 instructions:

| step | thread | MI mask | VI bit | exception taken at | vector |
|---|---|---|---|---|---|
| 218 | `0x8010b700` | `0xaaa` | SET | `0x8004d190` | `0x80000180` |
| 42 710 | `0x8010b700` | `0xaaa` | SET | `0x8004d190` | `0x80000180` |
| 43 632 | `0x800164b0` | `0xaaa` | SET | `0x8000c0d0` | `0x80000180` |
| 44 349 | `0x8012bb00` | `0xaaa` | SET | `0x80088668` | `0x80000180` |
| 45 668 | `0x80017868` | `0xaaa` | SET | `0x8000e658` | `0x80000180` |
| 46 577 | `0x80112a40` | `0xaaa` | SET | `0x8006c0d4` | `0x80000180` |

**Six acceptances, every one inside a window whose restored mask is `0xaaa`** — bit `0x08` set. No acceptance
occurs in a `0x696`/`0x996`/`0x669` context, which is exactly the prediction recorded before the run. So VI
eligibility is thread-dependent and guest-controlled, and the host no longer determines it.

**A second observation that must be flagged rather than claimed:** the vector at `0x80000180` now reads
`3c1a8000 275a06d0 03400008 00000000` — installed. That differs from M41, where 200 000 instructions left it
zero. But the *first* acceptance here happened at step 218, **before** installation, and jumped into zeros. So
this run is the **hardware-timing variant** ("assert VI independently of guest readiness"), not the controlled
one, and the late installation cannot be attributed to correct ordering. It is evidence that the install happens
at all once the mask is guest-owned, not evidence that the ordering is safe.

The controlled variant is the experiment that matters next: hold VI until all 16 vector bytes match the
preamble, then assert, and observe whether the handler delivers an event to `0x80139f10`.

#### Controlled VI: the vectors are never installed on this path (M49) — M48 corrected

VI withheld until all 16 vector bytes match the preamble, mask guest-owned, 300 000 instructions:

```
vector installed at step: None
VI asserted at step:      None        (the precondition never became true)
exceptions:               0
queue writes:             20, all osCreateMesgQueue setup plus the two blocking
                          waiter inserts at 0x80000f44; validCount stays 0 everywhere
```

**This corrects M48.** There, the vector *did* end up holding the preamble — but only after an interrupt was
taken at step 218, **before** installation, which jumped into zeros. Execution sliding through that region
perturbed the run enough that installation later appeared. With the controlled ordering, installation never
happens at all in 300 000 instructions.

So the honest state of the vector question is the M41 one, now with a mechanism attached:

- **Phase 1** installs at instruction 42 271 because its `osCreateThread`/`osStartThread` hooks return
  immediately, letting thread 7 run straight through its init body into `0x80007140`.
- **Phase 2** preempts thread 7 at its first real `osStartThread`; the saved context is correct
  (`+0x11c = 0x8000dc88`, confirmed 11/11 resumptions in M47), thread 7 *is* resumed there — but it never
  progresses as far as the installer.

So the faithful harness and the stubbed one disagree about whether the game ever reaches its own vector
installation, and the faithful one currently says it does not. That is a statement about **thread 7's post-
preemption progress**, not about hardware, interrupts or the mask — all of which are now modelled and verified.

**Immediate next measurement** (bounded, and the direct continuation): thread 7's PC sequence between resuming
at `0x8000dc88` and its next yield. M45 tried this with an exclusion window that excluded the wrong range; with
the dispatcher now known to span `0x80000f08`–`0x80001168`, the same trace becomes meaningful — the question is
whether thread 7 walks forward out of `osStartThread`'s tail into its caller, or loops back into the dispatcher.

Nothing here disturbs the queue findings: both queues initialised and both waiters inserted by guest code,
`validCount` 0 on all three queues, event message buffer empty.

#### Thread 7's post-preemption path: it walks forward, then idles (M50)

Three captures of thread 7 resuming at `0x8000dc88` (the saved PC from `osStartThread`), Phase 2, VI not
asserted:

| capture | step | PCs until yield | path |
|---|---|---|---|
| 1 | 705 | 153 | `0x8000dc88` → `0x8000dc8c` → **`0x80007300`**…`0x80007318` → back to `0x8000dc90`…`0x8000dca4` → `0x8000bfb0` → `0x80007300` again → dispatcher |
| 2 | 1688 | 820 | same opening → `0x8000dc90`… → **`0x80088974`** → `0x8004d304` → **`0x8006cb94`** → … → dispatcher |
| 3 | 4440 | 145 560 | same opening → `0x8000dc90`… → **`0x8006cc40`** → `0x8004d30c` → **`0x80000518`** → idle spin for 145 560 instructions |

**Answer to the question: thread 7 does walk forward out of `osStartThread`'s tail into its caller** — it hits
the small helper at `0x80007300`, then its own remaining callees (`0x80088974`, `0x8006cb94` which spawns
thread 1, then `0x8006cc40` → `0x8004d30c`), and finally reaches the `b .` idle spin at `0x80000518`, where it
stays. **`0x80007140` is never on that path.**

**And that localises the Phase-1/Phase-2 divergence precisely.** `0x800072E0` and `0x80007300` are among the
functions the Phase-1 harness **stubs**; in Phase 2 they execute for real, and thread 7 calls them repeatedly on
exactly the stretch between resumption and idle. So the two harnesses differ in the very region thread 7
traverses here — which is where the vector installation must be being gained or lost, not in the dispatcher,
the mask, or the interrupt path (all of which are now verified).

That makes the next experiment narrow and cheap: un-stub `0x800072E0`/`0x80007300` in the Phase-1 harness (i.e.
run Phase 1 with only the thread/queue hooks, no helper stubs) and see whether the installer still runs at 42 271.
If it does not, the stubs were the cause and Phase 2 is right; if it does, the installer is genuinely reachable
and Phase 2 is losing it for a different reason.

Nothing here disturbs the queue findings: both queues initialised, both waiters inserted, `validCount` 0, buffers
empty.

#### Un-stubbing the helpers changes nothing: the installer still runs at 42 271 (M51)

Phase-1 harness with `0x800072E0` and `0x80007300` **un-stubbed** (guest code, only the thread/queue hooks
remain), 200 000 instructions:

| condition | installer hits | first | last | `E_VEC` |
|---|---|---|---|---|
| VI asserted | 32 | **step 42 271, thread 7, `0x80007140`** | 42 302 | **installed** |
| VI never asserted | 32 | step 51 091, thread 7 | 51 122 | **installed** |

**The stubs were not the cause.** With them un-stubbed the installer runs at exactly the same instruction,
42 271 (the later 51 091 in the no-VI run is just the interrupt's timing perturbation), by the same thread, and
`E_VEC` ends up holding the preamble in both cases.

That eliminates the last non-thread difference between the two harnesses. **The only remaining difference is the
five thread/queue hooks** — `osCreateThread`, `osStartThread`, `osCreateMesgQueue`, `osRecvMesg`, `osSendMesg` —
which Phase 1 fakes and Phase 2 executes for real. Since the installer sits at 42 271 in Phase 1 with everything
else genuine, the divergence is inside the real `osStartThread` path: Phase 2 resumes thread 7 at `0x8000dc88`
*inside* `osStartThread` and makes it execute that function's tail (`0x8000dc88`–`0x8000dca4`: dequeue from the
active queue and friends), which Phase 1 never runs because its hook returns immediately.

Also noted, unexamined: in the no-VI run thread 7 ends **faulted** at ~51 655 instructions with threads 1 and 9
blocked — so that path terminates early somewhere after installation. Worth a look, but it is not the current
question.

**Conclusion of this line:** the vector installation is not lost to emulation, not to stubs, and not to the
dispatcher. It is lost to the difference between a faked and a real `osStartThread`, i.e. to how thread 7's
initialisation is interleaved with the scheduler it is itself driving.

#### Thread 7's death: a jump to PC 0, not a memory fault (M52)

Same conditions as M51's no-VI run (Phase 1, helpers un-stubbed), thread-7-only PC ring:

```
thread 7: state=faulted  pc=0x0        fault event: unmapped access at 0x0
OSThread+0x11c (saved pc) = 0x0
```

So thread 7 dies by **transferring control to address 0**, and its saved-context PC slot is `0` at that moment.
This is the same signature as the very first Phase-2 runs (`pc=0x0`), which I had attributed to a bad return
address — the difference now is that it happens *after* the vectors are installed and after thread 7 has run
through its init.

Two readings are consistent with the data and I cannot separate them yet:

1. thread 7's context is re-saved with PC 0 (a save taken at a moment when the pending PC was zero, e.g. during a
   dispatch that cycled through the thread before it had a saved PC), and the restore then legally resumes at 0;
2. a `jr` with `ra = 0` inside the path thread 7 takes after `0x8000dc88`.

Both produce the identical symptom, and the discriminator is whether a `0x80001168` (`eret`) resumption for thread
7 reads `EPC = 0` — i.e. whether the zero arrives through the restore path or through a register. That is one
instrumented run away, and it is the first time this question has been genuinely well-posed, because the fault
now occurs with the scheduler, dispatcher and vector all verified.

#### Thread 7 dies at an `eret` with EPC = 0 (M53)

Refining M52 with the instruction decode of the final block. Thread 7's last PCs:

```
0x80007408 … 0x8000741c -> 0x800071e4 0x800071e8 -> 0x80007ef0 … 0x80007f28 -> 0x0
```

`0x800071e4` is `jal 0x80007ef0`, and `ra = 0x800071ec` — so this is a **call to a routine that never returns by
`jr`**. Its body is a CP0 sequence ending in a trampoline:

```
0x80007ef0  mfc0                     read SR
0x80007ef4  addiu t1, zero, 0x1f
0x80007ef8  mtc0                     write CP0
0x80007efc  mtc0
0x80007f04  lui t1, 0xc000
0x80007f08  mtc0
0x80007f0c  lui t1, 0x8000
0x80007f10  srl / or t2 (0x17)
0x80007f18  mtc0
0x80007f1c  addiu t1, zero, 1
0x80007f20  mtc0
0x80007f28  eret                     <-- jumps to EPC
```

**So the "jump to 0" is `eret` at `0x80007f28` with EPC = 0.** Thread 7's saved-PC slot reads `0` for the same
reason: EPC was zero when the trampoline ran.

This is a materially different failure from a bad return address, and it re-frames thread 7's death: the routine
at `0x80007ef0` is a **non-returning CP0 trampoline** (`jal` in, `eret` out) that expects EPC to carry the resume
address. In our run nothing had set EPC, so the trampoline legally resumed at 0.

**Hypothesis, explicitly not a finding:** in the real machine EPC at that point is set by the exception that
precedes this path (the trampoline writes several CP0 registers then returns through the exception mechanism), or
by one of the `mtc0`s whose register numbers my decoder reports as 0/0xA/2/3 and which should be re-checked
against the VR4300 CP0 numbering before any conclusion is drawn. Either way the observable is the same and it is
not an emulation fault in the dispatcher: **thread 7 reaches a legitimate `eret` with a zero EPC.**

#### The trampoline is a TLB write, not an `eret` — and that was my bug (M54)

**CP0 register numbering.** For COP0 instructions the target register is `(rs << 3) | rd`, not `rd` alone.
Re-decoding the trampoline at `0x80007ef0` with that rule:

| address | register written | value |
|---|---|---|
| `0x80007ef0` | `$10` EntryHi (`mfc0`) | read |
| `0x80007ef8` | **`$0` Index** | `0x1f` |
| `0x80007efc` | **`$10` EntryHi** | `0` |
| `0x80007f08` | **`$10` EntryHi** | `0xc0000000` |
| `0x80007f18` | **`$2` EntryLo0** | `0x02000017` |
| `0x80007f20` | **`$3` EntryLo1** | `1` |
| **`0x80007f28`** | **`42000002` = TLBWI**, funct `0x02` | — |

**So the instruction at `0x80007f28` is `TLBWI`, not `eret`.** `eret` is `0x42000018` (funct `0x18`); my decoder
labelled every `rs = 0x10` COP0 instruction as `eret`, and — worse — the harness *implemented* it that way, so
`TLBWI` executed as `eret` and jumped to `EPC = 0`. **Thread 7's "death at address 0" was an emulator bug of
mine, not a game behaviour and not a zero EPC in the guest.**

Fixed: only funct `0x18` is `ERET`; `TLBR`/`TLBWI`/`TLBWR`/`TLBP` are no-ops (there is no TLB model), and any
other funct raises a named fault rather than silently jumping.

**Thread 7 then continues, and the next failures are plain missing instructions**, each one surfaced in turn:
`SPECIAL 0x2d` (DADDU) at `0x80006100`, then `SPECIAL 0x6` (SRLV) at `0x80006150`. The 64-bit SPECIAL ops
(`DADD/DADDU/DSUB/DSUBU/DSLL/DSRL/DSRA/DSLL32/DSRL32/DSRA32`) and the variable shifts
(`SLLV/SRLV/SRAV/DSLLV/DSRLV/DSRAV`) are now implemented in the 32-bit view this harness keeps, with the
shift-by-32 forms yielding the correct low word.

Re-run after both additions: **installer still 32 hits, `E_VEC` installed, thread 7 progressing past
`0x80006150`** — and the queue `validCount`s remain `0/0/0`.

#### The `0x8000dc88` tail is a clean epilogue — M51's hypothesis is falsified (M55)

Static decode of the region:

```
0x8000dc80  jal 0x80000dd4        (different entry into the same block)
0x8000dc84  addiu a0, a0, 0x2948  (delay slot)
0x8000dc88  jal 0x80007300        <-- thread 7's saved resume point
0x8000dc8c  addu                  (delay slot)
0x8000dc90  lw ra, 0x1c(sp)
0x8000dc94  lw s2, 0x18(sp)
0x8000dc98  lw s1, 0x14(sp)
0x8000dc9c  lw s0, 0x10(sp)
0x8000dca0  jr ra                 <-- return to caller
0x8000dca4  addiu sp, sp, 0x20    (delay slot)
```

So `0x8000dc88` is **not a dispatch point**: it is a `jal` to the helper at `0x80007300`, followed by a normal
frame restore and `jr ra`. Thread 7's saved PC lands *on that call*, which is exactly what a preemption between
instructions looks like.

Observed, Phase 2, thread 7 in this window (3 visits):

```
visit 1: dc88 dc8c dc90 dc94 dc98 dc9c dca0 dca4
visit 2: dc80 dc84
visit 3: dc88 dc8c dc90 … dca4  dc88 dc8c dc90 … dca4      (twice in a row)
```

**Thread 7 executes the tail completely and correctly every time** — calls the helper, restores `s0`/`s1`/`s2`/`ra`,
returns through `jr ra`. There is no divergence, no corruption, no premature yield.

**So the M51 hypothesis — that the Phase-1/Phase-2 divergence lives in this tail — is falsified.** The tail was
the only place the two harnesses could still differ; it doesn't. What that leaves is narrower than before:
thread 7's path *after* the `jr ra` at `0x8000dca0`, i.e. its caller's continuation. In Phase 1 that continuation
reaches `0x80007140` by instruction 42 271; in Phase 2 the same resumption leads to the idle spin. The first
divergent PC after `0x8000dca0` is the thing to capture, and both harnesses can be logged in the same way.

#### Where thread 7 splits: at `0x8000dc88` itself (M56)

Same instrumentation in both harnesses, capturing thread 7's PCs after executing the `jr ra` at `0x8000dca0`:

| harness | PCs captured |
|---|---|
| Phase 1 | **0** |
| Phase 2 | 32 |

```
Phase 2: dca4 0x8000bfb0 f4 0x80007300 04 08 0c 10 14 18 0x8000bfb8 bc c0 c4 c8
         0x8000cdf0 f4 f8 fc 0x8000ce00 … 0x800072e0 …
```

**The comparison cannot be made, and that is the finding.** Phase 1 never executes `0x8000dc88`–`0x8000dca4` at
all, because `osStartThread` is a **hook** there — the whole call to `0x80007300`, the frame restore and the
`jr ra` are replaced by a `return 0`. So the split is not *after* `0x8000dca0`; the split is at `0x8000dc88`,
i.e. at the boundary of the function the host replaced.

Phase 2 runs that code for real and then continues into a different cluster entirely:

```
0x8000dca4 -> 0x8000bfb0/bfb4 -> 0x80007300 (helper) -> 0x8000bfb8..bfc8
          -> 0x8000cdf0.. -> 0x8000ce00.. -> 0x800072e0
```

`0x8000Bxxx`/`0x8000Cxxx` is libultra's queue/message-helper region, and **`0x8000cdf0` and `0x800072e0` are
themselves Phase-1 stubs**. So the two harnesses not only differ at `osStartThread`: Phase 1 additionally
short-circuits two helpers that Phase 2 executes on this very path. The divergence is therefore not a single
branch — it is the cumulative effect of three replaced functions, and it cannot be localised by comparing
trajectories that never share a prefix.

**That closes this line of inquiry honestly.** The Phase-1 harness cannot serve as the reference for where
thread 7's init goes, because it does not execute the code in question. The only faithful statement available
is Phase 2's: thread 7 resumes at `0x8000dc88`, calls `0x80007300`, returns, and then walks the
`0x8000Bxxx`/`0x8000Cxxx` helper cluster before reaching the idle spin — never `0x80007140`.

#### Phase 2 from the real boot loader: still no installer (M57)

Last untried combination — faithful Phase 2, no stubs removed, started at the **real boot loader**
`0x80000598`, 3 000 000 instructions:

```
fault:            None
installer hits:   0            (0x80007140 never reached)
E_VEC:            00 00 00 00  (zero)
guest switches:   11           0 -> thread7 -> 0x800164b0 -> thread7 -> thread9 -> thread7 -> 0x80017868 ...
queue validCounts 0/0/0
primitives used:  pi_dma, inflate, pi_dma      (the boot loader did run its DMA and inflate)
```

**Answer: no.** The boot loader executes correctly, the guest builds and switches its thread graph, and thread 7
still never reaches the vector installer. Starting from the real entry changes nothing.

**Consolidated conclusion of the whole line.** The installer routine *works* — Phase 1 executes it at instruction
42 271 and `E_VEC` ends up holding the reference preamble. Under faithful guest scheduling thread 7 instead
resumes at `0x8000dc88`, calls `0x80007300`, walks the `0x8000Bxxx`/`0x8000Cxxx` helper cluster and settles into
the idle spin at `0x80000518`, never approaching `0x80007140`.

Two readings remain, and they cannot be separated with the evidence in hand:

1. the game's real ordering reaches the installer through a path the harness still diverts, in which case some
   remaining emulation inaccuracy is responsible — and five of the last six failures in this project were mine
   (inverted `slt`, mis-numbered CP0 space, four missing instruction families, two instrumentation bugs), so this
   is the likelier candidate;
2. the installation genuinely happens later than 3 000 000 instructions on this path, i.e. after something the
   harness never provides.

**The responsible next step is no longer another harness.** It is a differential against a reference N64
emulator: run this same code path in a known-good emulator with the same images and compare the first divergent
PC. That separates "my CPU is still wrong" from "the game does what it does", which is the one question the
self-built harness can no longer answer about itself.

#### Differential against Unicorn: the tool works, first difference is a convention (M58)

No reference emulator existed on this host (no mupen64plus, retroarch, ares or qemu-mips), but PyPI is
reachable, so **Unicorn 2.1.4** (QEMU TCG, MIPS32 BE) was installed into a project-local `.venv`. It is a
genuinely independent instruction-set implementation, which is what the differential needs.

Two host facts had to be established by experiment:

1. **Unicorn's MIPS32 core translates KSEG0/KSEG1 PCs to physical addresses.** Executing at `0x80000000+`
   fails with `UC_ERR_FETCH_UNMAPPED` *even though `mem_map` and `mem_write` both succeeded*; the image must
   also be mapped at the physical mirror (`0x00000000` for kseg0, `0x10000000` for the cartridge). A one-word
   test at `0x1000` executes fine while the same word at `0x80000000` does not — that contrast is what
   identified the cause.
2. Single-stepping needs a code hook that stops on the **second** fetch; stopping on the first prevents the
   instruction from executing at all.

Result of the raw lockstep from `0x8004d344`:

```
compared 14 instructions
FIRST DIVERGENCE after 14 instructions at 0x8004d378  (0c001b58 = jal 0x80006d60)
  mine    next PC = 0x8004d37c      (the delay slot)
  unicorn next PC = 0x80006d60      (the branch target)
```

**That is a delay-slot convention, not a semantic divergence.** This harness tracks delay slots explicitly and
reports the delay-slot address after a jump; Unicorn reports the branch target and runs the delay slot inside
its own mechanism. Both are correct under their own models, so a raw PC-by-PC comparison will always diverge at
the first `jal`.

Everything up to that point matched, including 13 instructions of stack setup. The comparison therefore needs
normalising before it can find real divergences — compare the *visited-PC sequence*, or align on non-delay
boundaries — and `tools/diff_unicorn.py` is saved with that as its stated next step rather than pretending the
raw comparison is the answer.

#### Normalised differential: 158 instructions aligned, zero divergence (M59)

Comparing *visited-PC sequences* instead of per-step next-PC removes the delay-slot convention difference
entirely — both emulators execute the delay slot, so their address sequences should be identical.

```
mine: 213 PCs, unicorn: 158 PCs
ALIGNED for all 158 compared instruction addresses
```

**Yes — it stays aligned past `0x8004d378`, with no divergence anywhere in the comparable window.** The two
implementations execute the same instruction addresses in the same order for all 158 steps both completed.

Both then stopped, for the same underlying reason: **`0xa430000c` (MI_INTR_MASK) is unmapped.**

- mine: `unmapped access at 0xa430000c` at `0x80001154` (the dispatcher's per-thread mask restore)
- unicorn: `UC_ERR_EXCEPTION` at the same point

The differential script uses the plain `Memory` class, which — unlike `HwMemory` — has no hardware window, and
Unicorn has nothing mapped at `0xa4300000` either. So the comparison ended at a shared, understood boundary.

**What this proves and what it does not.** It clears my CPU of basic instruction-semantics error on this path:
a reference implementation of the MIPS32 instruction set agrees with it instruction-for-instruction. It does
**not** prove the CPU is right everywhere — 158 instructions is a short window, and the window ends precisely
where the interesting behaviour begins (the dispatcher's register/mask restore).

**Which sharpens the remaining suspicion.** Since the CPU matches, the reason thread 7 never reaches
`0x80007140` is unlikely to be instruction semantics and is more likely to be **hardware modelling**: the
`TLBWI`/`TLBP` operations I made no-ops, cache instructions treated as no-ops, or the MI register behaviour.
That is a materially different hypothesis from the one I have been testing for several arcs, and it is the first
time it has been supported by evidence rather than elimination.

Next step is mechanical: map `0xa0000000`–`0xc0000000` in **both** emulators (zero page for Unicorn, `HwMemory`
for mine) and re-run the normalised comparison for thousands of instructions. That extends the window past the
dispatcher and, if alignment holds, narrows the remaining candidates to the no-op TLB and cache behaviour.

#### Extended differential with the hardware window (M60)

Mapped `0xa4000000` (SP/VI/MI/PI/AI/SI/DP) **and its kseg1 physical mirror `0x04000000`** for Unicorn, and used
`HwMemory` for this harness. 3 000 steps from `0x8004d344`:

```
mine 3000 PCs, unicorn 158 PCs — unicorn stopped: UC_ERR_EXCEPTION
ALIGNED for all 158 compared addresses (0x8004d344 .. 0x80000fb4)
markers: 0x80001154 at index 2788, 0x80001168 at index 2793, 0x80007f28 never reached
```

**Still aligned for every address both emulators completed** — the mapping fix removed the earlier
`0xa430000c` stop, and the two now run together through the dispatcher's `mtc0 $12` at `0x80000fac`.

Unicorn then raises an uninformative `UC_ERR_EXCEPTION` at `0x80000fb4`/`0x80000fb8`, where this harness executes
without incident. I cannot yet say whether that is a Unicorn limitation in the COP0/TLB area or a real
difference — `UC_ERR_EXCEPTION` carries no cause code, and extracting it needs more instrumentation than one run.

**On TLBWI specifically: it is not exercised in this window at all.** From `0x8004d344`, 3 000 instructions
reach the dispatcher (markers at index 2788/2793) but never `0x80007f28`; in earlier runs that instruction only
appears around instruction 51 000, on the boot-loader path. So "try TLBWI first" cannot be answered from this
differential — the comparison would have to be run from `0x80000598` for ~60 000 steps, and Unicorn currently
cannot get that far without the exception above being explained.

**State of the differential as a tool:** it works, it is normalised correctly, it agrees with the reference for
the whole comparable window, and its blocker is now Unicorn-side rather than mine. That is the opposite of where
this investigation started.

#### Unicorn's exception at 0x80000fb4 is a mode limitation, not my bug (M61)

Bounded single-stepping (400 steps, two-fetch hook, no unmapped-memory hooks — those loop) caught it exactly:

```
step 138: unicorn exception at PC 0x80000fb4
  last 5 PCs: 0x80000fa4 0x80000fa8 0x80000fac 0x80000fb0 0x80000fb4
  0x80000fb4: 64212140
```

`0x64212140` has opcode **`0x19` = `DADDIU`** — a MIPS III / 64-bit instruction. **Unicorn was configured in
`UC_MODE_MIPS32`, which does not implement it, so it raises `UC_ERR_EXCEPTION`; this harness implements `0x19`
(added during the DADDU/SRLV round).** The VR4300 is a MIPS III core.

**So: not my bug.** It is the reference emulator refusing a legitimate VR4300 instruction because I put it in
32-bit mode — the third Unicorn-side configuration issue in this exercise, after KSEG0 PC translation (needing
physical mirrors) and the missing hardware-window mirror.

Re-running in `UC_MODE_MIPS64` as the fix: Unicorn then records **0 PCs** and raises immediately, so the 32-bit
mappings do not line up under 64-bit address semantics either. That needs its own mapping work (canonical /
sign-extended addresses) before the differential can be extended past 158 instructions.

**Verdict of the differential as it stands:** on every instruction both emulators could execute — 158 addresses
from `0x8004d344` through the dispatcher's `mtc0 $12` — an independent MIPS implementation agrees with this
harness instruction-for-instruction, with zero divergence. The comparison has never yet produced evidence
against my CPU; all three stopping points have been Unicorn configuration.

#### MIPS64 mapping attempt: Unicorn cannot run this code either way (M62)

Feasibility test with both mappings in place — sign-extended `0xFFFFFFFF80000000` **and** 32-bit `0x80000000`,
each 4 MB of the same RAM image:

```
mapped sign-extended RAM ok      mapped 32-bit RAM ok
PC after write: 0x8004d344
MIPS64 fetch failed: Unhandled CPU exception (UC_ERR_EXCEPTION)      (0 instructions executed)
```

So the two Unicorn modes fail in complementary ways:

| mode | behaviour |
|---|---|
| `UC_MODE_MIPS32` | executes correctly for 158 instructions, then raises at `0x80000fb4` on `DADDIU` (MIPS III) |
| `UC_MODE_MIPS64` | raises immediately at `0x8004d344`, executing **nothing**, with either mapping |

**Conclusion: this reference implementation cannot be extended past 158 instructions on this code as available.**
32-bit mode refuses the 64-bit instructions the VR4300 uses; 64-bit mode does not fetch at all. The differential
has therefore given its verdict on the window it can cover — **zero divergence across 158 instructions** — and
cannot answer anything further without a different reference.

**That is a decision point rather than a technical dead end.** The options are:

1. **mupen64plus** (or ares/retroarch) via Homebrew — a real N64 emulator with the right CPU, but a
   system-level install of a large native package, which this project's rules require the user to approve;
2. **QEMU system-mips** — likewise a substantial install, and it would need a machine definition for the N64
   memory map;
3. **Accept the differential's current verdict** and stop using it: 158 instructions agree with an independent
   implementation, and no evidence against the CPU has appeared at any point.

Recommendation: option 1 if the investigation continues, because the remaining question ("is my CPU still subtly
wrong on the 0x8000Bxxx path?") cannot be settled by a tool I configure myself, and 32-bit Unicorn has already
demonstrated it cannot even reach that region.

#### Decision: the differential is retired (M63)

Accepted on the user's instruction. `tools/diff_unicorn.py` is marked **RETIRED** in place and kept only for the
host findings it records (KSEG0/KSEG1 PC translation needing physical mirrors, the hardware-window mirror, the
two-fetch single-step idiom, and the MIPS32-vs-MIPS64 dead end). It is not part of the workflow.

**What it delivered before retirement:** zero divergence across the 158 instructions both implementations could
execute — an independent MIPS implementation agreeing with this harness instruction-for-instruction from
`0x8004d344` through the dispatcher's `mtc0 $12`. That is the strongest single statement the project owns about
its own CPU.

**What it could not deliver:** anything past instruction 158, hence nothing about the `0x8000Bxxx` cluster where
thread 7's initialisation actually goes wrong. A real N64 emulator would be needed, which is a system-level
install and a user decision; that decision is now "not now".

**Consequence for the remaining question.** "Is my CPU still subtly wrong on the `0x8000Bxxx` path?" is now
unanswerable with the current tooling, and is recorded as open rather than assumed in either direction. The
honest position is that the CPU agrees with a reference wherever both could run, and that the region where
thread 7 diverges has never been compared against anything.

#### ares emulator installed; the trace still needs a human (M64)

Install history, because two failures were mine before one succeeded:

1. `brew install ares` installed **`bee-san/Ares`** — a decryption tool. Name collision, uninstalled.
2. `brew install ares-emulator` produced **no output and installed nothing**; I reported forward without
   checking. The verbosed retry showed why: the first attempt had been sitting behind Homebrew's tap-trust
   banner and an aborted fetch — it was never going to succeed silently.
3. `brew install -v ares-emulator` → **success**: `ares 148`, `/Applications/ares.app`, a 46 MB universal binary.

Capabilities, measured from its own `--help`:

```
ares [OPTIONS]... game(s)
  --system name        (available systems include "Nintendo 64" and "Nintendo 64DD")
  --kiosk              minimal UI, implies --no-file-prompt
  --save-state slot / --setting name=value
```

**There is no breakpoint, trace or headless-execution flag.** ares ships a GUI debugger but exposes no CLI
interface to it, so the `0x8000Bxxx` differential cannot be automated with this tool either. mupen64plus was
likewise not installed (that attempt silently failed too, and was not verified at the time).

**What this means for the open question.** The comparison at `0x80007140` is now a **two-minute manual step**:
launch `/Applications/ares.app` with our dump, open Tools → Debugger, set a breakpoint at `0x80007140`, and see
whether it is ever hit. If it is hit, the game does install its vectors and my harness is wrong; if it is not, the
idle-spin conclusion stands. That single observation settles what four arcs of tooling could not.

#### GUI automation of ares: capability achieved, tool still insufficient (M65)

macOS Accessibility was granted for `mimo`, and ares is now drivable from the shell. The working recipe, kept
because it took several attempts to find:

```applescript
tell application "System Events" to tell process "ares"
  -- launch: open -na /Applications/ares.app --args --system "Nintendo 64" <rom>
  name of every window of process "ares"                    --> "Resident Evil 2 (USA) (Rev 1)"
  -- menus: Apple, ares, Edit, Load, Nintendo 64, Settings, Tools, Help
  click menu bar item 7 of menu bar 1                       -- Tools
  click menu item 13 of menu 1 of menu bar item 7 of menu bar 1   -- Memory
  -- pop-ups are not enumerable while closed; drive them by keyboard:
  click pop up button 1 of window "Tools"; key code 125; key code 36
  -- buttons/titles are readable: button 1 = "Export", button 2 = "Refresh"
  value of text field 1 of window "Tools"
end tell
```

**Confirmed:** ares v148 (Homebrew cask) **boots this dump** — the window is titled `Resident Evil 2 (USA)
(Rev 1)`.

**Also confirmed: the release build has no CPU debugger.** Complete menu inventory — Tools = Save/Load State,
Undo, Capture Screenshot, Pause Emulation, Frame Advance, Reload Game, Manifest, Cheats, **Memory**,
**Graphics**; Nintendo 64 = controller ports, Reset, Unload; Settings = Window Size, Output, Shader, Boot
Options, Mute, Status Bar, Video/Audio/Input/Hotkeys/Emulators/Options. There is no Debugger item and no CLI
breakpoint/trace flag, so the `0x80007140` breakpoint test **cannot** be performed in this build.

**And the substitute did not work headlessly.** Tools → Memory does offer a region pop-up (stepped to
**RDRAM**) and an **Export** button, which would have been enough — a dump's bytes at `0x180` would show
whether the real game installs its vector. But clicking Export through System Events produces no save sheet and
no file, and `screencapture` is still blocked (`could not create image from display`, Screen Recording not
granted), so the dialog cannot be seen or driven. Exporting the dump needs either Screen Recording, or a manual
click.

#### ares reaches the title screen, and RDRAM at 0x80000180 is ZERO (M66)

With Screen Recording granted, ares is now fully drivable and observable. **The real game boots to its title
screen** — `LOAD GAME / NEW GAME / OPTION`, `© CAPCOM U.S.A., INC. 1998,1999`, `[Nintendo] Nintendo 64 (NTSC)`,
60 VPS.

Tools → Memory Editor, region **RDRAM**, Goto `0x80000180`, read off the hex view:

```
0x80000120  24 26 25 02 83 05 04 0a 95 05 05 06 04 05 08 04
0x80000130  00 00 00 00 27 5a 06 d0 03 40 00 08 00 00 00 00
0x80000140  00 00 00 00 00 00 00 00 04 05 08 04 00 00 08 00
0x80000150  15 26 97 7f 25 05 04 02 00 04 00 25 26 12 12 04
0x80000160  45 10 e0 48 41 e0 10 44 01 40 01 41 04 04 03 04
0x80000170  00 00 00 c0 45 09 c0 c0 44 04 04 04 00 00 40 04
0x80000180  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
0x80000190  00 00 00 00 00 00 00 00 c4 44 04 04 10 04 c0 04
```

**The general exception vector at `0x80000180` is all zeros in the running game.** The standard libultra
preamble `3c 1a 80 00 / 27 5a 06 d0 / 03 40 00 08 / 00 00 00 00` is **not** installed there — and my Phase-1
harness reported exactly that preamble being written at `0x80007140`–`0x800071b8` and ending up at `E_VEC`.

**But something preamble-like is at `0x80000134`**: `27 5a 06 d0 03 40 00 08` — instructions 2 and 3 of that
preamble (`addiu k0,k0,0x6d0`, `jr k0`) — preceded by four zero bytes where `lui k0,0x8000` would be, and
followed by zeros. So the pattern exists in RDRAM at `0x80000134`, not at `0x80000180`.

**Two readings, both now testable and neither yet proven:**

1. RE2 (KMC compiler, non-standard entry `0x80000480`) does **not** use libultra's stock vector installation;
   its exception entry lives at a different address, and `0x80000134` is part of it.
2. The memory editor view is RDRAM but the vector the game installs is written later/elsewhere, and
   `0x80000180` genuinely stays zero because this build never takes that path.

**What this changes immediately:** Phase 2's conclusion ("thread 7 never installs the vectors") is now
**consistent with the real game**, and Phase 1's "installation at instruction 42 271" is very likely an
artefact of its faked `osStartThread`. My faithful harness was closer to the truth than the comparison harness
that contradicted it — the opposite of what the last several arcs assumed.

#### The remaining reads were not obtained: ares exited (M67)

After the `0x80000180` observation, ares stopped running (`pgrep` finds no process, no crash report in
`~/Library/Logs/DiagnosticReports`). The two remaining reads — the shape of the real exception entry around
`0x80000000` and the queue structures at `0x8012bcf0` — were therefore **not** taken.

Host facts learned in the attempt, worth keeping:

- **The desktop spans `y = -900 … 900`** (`bounds of window of desktop` → `0, -900, 3520, 900`; capture size
  3200×1800). `screencapture -R` with positive y silently fails with *"does not intersect any displays"* —
  crops need negative-y coordinates.
- **`set frontmost` / `AXRaise` on the ares process became unreliable** after the first successful run
  (`-10006 Can't set process ares to true`, then `-1728 Can't get process "ares"` once the app had exited).
  The working sequence, when it works, is: raise the window, `set value of text field 1`, `keystroke return`.
- **The Tools panel's text field is `Goto:` (an address), not an export path.** Writing a filename there does
  nothing; `Export` needs a real address in the field and a visible dialog.

**To finish the last question** (does the real game ever post to `0x8012bd30` / `0x8012bcf8`): relaunch ares with
the dump, Tools → Memory Editor, region RDRAM, Goto `0x8012bcf0`, and read six words per queue:
`mtqueue / fullqueue / validCount / first / msgCount / msg`. A non-zero `validCount` or a message in the buffer
means the game does post; `validCount = 0` with an empty buffer means it does not, and the two stalls are real.

#### ares RDRAM 0x80000000-0x80000180: the game installs preambles, but not at E_VEC (M68)

Second ares session, RDRAM region, after a failed `Goto` (the field truncated `0x8012bcf0` to `0x8012bc` and the
view stayed at the default base). What the base view shows is nonetheless the most informative memory dump in
this project:

```
0x80000000  3c 1a 80 00  27 5a 06 00  00 00 00 00  00 00 00 00    lui k0,0x8000 ; addiu k0,k0,0x600
0x80000010  3c 01 80 00  27 5a 06 d0  03 40 00 08  00 00 00 00
...
0x80000080  3c 1a 80 00  27 5a 06 d0  03 40 00 08  00 00 00 00    <- full preamble, jr k0
0x80000090  00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00
0x80000100  00 00 00 00  3c 1a 80 00  27 5a 06 d0  03 40 00 08    <- preamble at +4, not +0
0x80000110  00 00 00 00  00 00 00 00  12 12 24 42  00 01 80 48
0x80000120  24 26 25 02  83 05 04 0a  95 05 05 06  04 05 08 04
0x80000130  00 00 00 00  27 5a 06 d0  03 40 00 08  00 00 00 00    <- preamble tail at +4
0x80000180  00 00 00 00  00 00 00 00  00 00 00 00  00 00 00 00    <- E_VEC: all zero
```

**The running game does install libultra-style preambles — at `0x80000000` (target `0x80000600`) and at
`0x80000080` (full four words, `jr k0` to `0x800006d0`). `E_VEC` at `0x80000180` is all zeros.** Preamble-shaped
runs also appear at `0x80000104` and `0x80000130` — i.e. **+4 from a vector boundary — which is odd and needs a
re-read before any conclusion**, because instruction fetch requires 4-byte alignment and a vector at `+4` makes
no architectural sense.

**What this changes:** the M66 reading ("the real game has no standard vector") was too strong. The game *does*
install preambles at two of the four vector addresses, and not at `E_VEC`. So the honest statement is narrower:
**this build installs `UT_VEC` and `XUT_VEC` but not `E_VEC`**, and whatever entry it uses for real exceptions is
either one of those or the shifted copy at `0x80000104`.

**Still unanswered:** the queue structures. The `Goto` field needs its value typed with the field focused and
committed (truncation to 8 characters suggests the click landed mid-string); retry by clicking the field first,
then typing, then Return.

#### Driving ares' Goto field: text accepted, commit not triggerable (M69)

Third attempt, with Screen Recording and Accessibility both granted. What works and what does not, precisely:

| action | result |
|---|---|
| `set value of text field 1 to "0x8012bcf0"` | field shows a **truncated** value (`0x800001`) and reads back as `missing value` |
| `click text field 1` then `keystroke "…"` | **nothing lands** in the field |
| **double-click** the field then `keystroke "8012bcf0"` | **text lands correctly** (`8012bcf0` visible in the field) |
| `keystroke return` after the text lands | **does not commit** — the hex view stays at `0x80000000` |
| `perform action "AXConfirm"`, then `click button 2` (Refresh) | field cleared, no navigation |

So the panel accepts typed text but exposes no confirmable action through accessibility, and Return does not move
the view. Navigating from `0x80000000` to `0x8012bcf0` by scrolling is ~19 MB away and impractical.

**Therefore the queue read is a manual step.** It is three seconds of work in the already-open panel:

> **Memory Editor → region RDRAM → click the `Goto:` field, type `8012bcf0`, press Return** — then read the six
> words at `0x8012bcf8`, and repeat with `8012bd30`.

Reading guide: `mtqueue / fullqueue / validCount / first / msgCount / msg`. `validCount` non-zero, or a message in
the buffer, means the game **does** post to that queue; `validCount = 0` with an empty buffer means it **does
not**, and the two blocked threads are what the game genuinely does.

Also recorded: ares exited three times during these attempts with **no crash report and no `.ips` file**, so it
was quit rather than crashing; one earlier "empty desktop" capture was actually the emulator's dark scene, and I
misread it as the app being gone until `pgrep` corrected me.

#### BREAKTHROUGH: ares `Export` dumps RDRAM, and it settles three questions (M70)

The `Export` button in Tools → Memory Editor **does work** — it writes
`rom/Resident Evil 2 (USA) (Rev 1)-rdram-<timestamp>.bin`, an **8 MB** RDRAM image, next to the ROM. No `Goto`
is needed at all: that whole line of fiddling was unnecessary, and `Goto` never worked (field accepts text,
`keystroke return` does not commit; entering the virtual address lands past the end of the region because the
field wants an **offset**, and selecting a sidebar row other than *Memory* silently changes the address space).

Reading the dump at exact offsets:

**1. All four exception vectors ARE installed** — including `E_VEC`:

```
UT_VEC  0x80000000: 3c1a8000 275a06d0 03400008 00000000
XUT_VEC 0x80000080: 3c1a8000 275a06d0 03400008 00000000
ECC_VEC 0x80000100: 3c1a8000 275a06d0 03400008 00000000
E_VEC   0x80000180: 3c1a8000 275a06d0 03400008 00000000
```

So the real game installs the full stock preamble set, `jr k0` → `0x800006d0`. **M66 and M68 were wrong** — the
"E_VEC is zero" reading came from the memory editor's display, not from memory. Phase 1's *installation exists*
conclusion was right all along; Phase 2 never doing it is the genuine divergence.

**2. The two queues, exactly as this project predicted them:**

| queue | mtqueue | fullqueue | validCount | msgCount | msg buffer |
|---|---|---|---|---|---|
| `0x8012bcf8` (thread 1's) | `0x80012940` (empty sentinel) | `0x80012940` | **0** | 8 | `0x8012bd10` |
| `0x8012bd30` (thread 9's) | **`0x8012bb00` = thread 9's `OSThread*`** | `0x80012940` | **0** | 10 | `0x8012bd48` |

So **thread 9 really is parked on `0x8012bd30`** — its `mtqueue` is its own thread structure — and at the title
screen **no message has been posted**: `validCount = 0` on both. That is not a deadlock; it is a queue with no
work yet.

**3. The real scheduler, and threads this harness never created:**

```
current 0x80012950 = 0x80112a40   thread 1, priority 40, state 0x4 RUNNING
run queue 0x80012948 = 0x80112da0   <- a thread struct never seen here
active queue 0x8001294c = 0x8010b4f8 <- another one
thread 7 @0x8010b700  priority 0   state 0x2 RUNNABLE
thread 9 @0x8012bb00  priority 60  state 0x8 WAITING
sentinel 0x80012940 = 0
```

**What this means for the original question.** The queue handoffs are not missing — they are *empty*, with the
game's own scheduler running thread 1 and holding thread 9 parked exactly where this project said it was. The
harness's "deadlock" was a faithful snapshot of an idle moment; what it lacked was the game's later posting,
which never happens at the title screen because nothing has asked for those resources yet.

#### NEW GAME played, second dump, and the real thread graph (M71)

Down + Return on the title screen started a game — the intro cutscene runs at 59 VPS. Two RDRAM dumps ~3.5
minutes apart:

| | dump A (title) | dump B (intro) |
|---|---|---|
| current thread `0x80012950` | `0x80112a40` (thread 1) | **`0x80112da0`** |
| `0x8012bcf8` validCount | 0 | **0** |
| `0x8012bd30` validCount | 0 | **0** |
| `E_VEC` | installed | installed |
| 4 KB pages differing | — | **580 of 2048** (~1.16 MB changed) |

**So starting a game switches threads and moves 1.16 MB of RDRAM, and still posts nothing to either queue.**

**The real scheduler, walked out of dump B:**

```
current       0x80112da0   RUNNING
run queue     0x8010b700   thread 7, priority 0,  RUNNABLE  -> sentinel
active queue  0x8010b330   priority 21, STOPPED
              0x80112bf0   priority 20, WAITING  -> sentinel
sentinel      0x80012940 next = 0x00000000
thread 9      0x8012bb00   WAITING, parked on 0x8012bd30's mtqueue
```

**This is the concrete divergence, and it is not about queues at all.** The real game runs a thread graph with at
least six structures — `0x8010b700`, `0x8010b330`, `0x80112bf0`, `0x80112da0`, `0x80112a40`, `0x8012bb00` —
while this harness ever created four, and **thread 7 in the real game is a priority-0 RUNNABLE thread waiting its
turn, not a thread spinning in `b .`**. The harness's "thread 7 idles forever" was an artefact of it being the
*only* runnable thread: with the real graph, the game hands control to `0x80112da0` and thread 7 simply waits.

**What that means for the two blocked queues.** They are not the bottleneck at this stage: after a new game
starts, they are still empty, so the resources they gate are not needed for the intro. The harness's stall and
the game's state agree — `validCount = 0` in both — and the difference was never a missing producer, it was a
missing *thread graph*.

#### Pivot: ares is now an oracle, not a debugging target (M72)

No more GUI archaeology. The whole value of ares turned out to be **one button**, and it replaces the reference
emulator differential, the breakpoint hunt, and the memory-editor navigation all at once.

**The recipe (three clicks, ~2 seconds):**

1. ares running the dump (`open -na /Applications/ares.app --args --system "Nintendo 64" <rom>`).
2. **Tools → Memory Editor**; set the region pop-up to **RDRAM** (and pick the **Memory** row in the left list —
   selecting any other row silently changes the address space, which is what made an earlier reading look like
   zeros).
3. Click **Export**. It writes **`<rom-basename>-rdram-<YYYYMMDD-HHMMSS>.bin`** — an **8 MB** image — next to the
   ROM, i.e. `rom/` here (gitignored).

`Goto` is not needed and does not work reliably: the field accepts text but `keystroke return` does not commit,
the value must be an **offset** (0…0x7FFFFF) not a virtual address, and the field clips its display.

**Why this is better than every approach retired today:**

| approach | status |
|---|---|
| Unicorn instruction differential | retired (M63) — could not run past 158 instructions |
| ares CPU breakpoint at `0x80007140` | impossible — release build has no debugger |
| ares memory-editor navigation | unnecessary — `Export` gives the whole 8 MB |
| **ares RDRAM dump vs harness RDRAM** | **the working differential**: memory-level, whole-machine, no breakpoints |

**The comparison this enables** is stronger than the instruction-level one that failed: run the harness to a
comparable point, dump its emulated RDRAM, and diff against an ares dump page by page. That exercises the CPU,
the scheduler, the memory map and the loaders together, and the mismatch report points at the first divergent
page rather than the first divergent instruction.

#### `tools/diff_rdram.py` works, and it found the harness's missing IPL3 image (M73)

New tool: compares the harness's emulated RDRAM against an ares dump page by page, and **classifies** each
4 KB page, because a raw difference count is misleading — the harness only loads the boot bank and stage-2,
while ares has run the whole game:

| class | meaning | dump A |
|---|---|---|
| `same` | identical | 704 / 1024 |
| `harness-zero` | harness never loaded it — unexplored, not a bug | 286 |
| `ares-zero` | harness wrote something the real machine never did | **4** |
| `both-differ` | both hold data, and it disagrees | **30** |

Options: `--page <vaddr>` for a byte-level view of one page, `--top` for the worst pages, `--harness-file` to
compare two files instead of running the harness.

**First finding, from `--page 0x80000000`:** the real machine has code at `0x80000010`–`0x8000047f` that this
harness never loads at all — `3c 01 a4 60` (`lui at,0xA460`) among it, i.e. **PI register setup**. Searching the
cartridge for those bytes puts them at **ROM `0x4d0`**, which pins the mapping:

```
RDRAM 0x80000000  <->  ROM 0x4c0        (IPL3's resident tail, 0x480 bytes)
RDRAM 0x80000480  <->  ROM 0x1000       (the game image — already correct)
```

So the harness was starting with **`0x80000000`–`0x8000047f` zeroed**, missing IPL3's R4300 stub entirely.

**The fix is not yet right, and that is recorded rather than hidden.** Loading ROM `0x4c0..0x940` at
`0x80000000` makes page 0 substantially closer (382 bytes differ instead of 452, and the vector area now holds
real IPL3 code rather than zeros) — but it also changes execution drastically: the run now **faults after 3 407
instructions** at `0x80088554` on an access to `0x805ee000`, far outside RDRAM. So either only part of that
region belongs there, or IPL3's stub must not be entered this way. The mapping is established; the load is not.

#### IPL3 extent pinned, and why the harness must not load it yet (M74)

Two more ares frames plus the cartridge give the layout exactly:

- **`0x80000000`–`0x800003ff`** holds IPL3's R4300 stub, matching cartridge **ROM `0x4c0`** for the first
  ~`0x2b8` bytes and fragmenting after that (the game rewrites parts of it).
- **`0x80000400`–`0x8000047f` is zero** in the real machine. My earlier 0x480-byte load was overwriting that
  gap with the wrong ROM bytes — the correct load is **0x400 bytes**.
- **`0x80000480`** onwards is the game image, matching ROM `0x1000` ✓ (unchanged, already correct).
- **Page 0 is completely static** between the title-screen and post-NEW-GAME dumps: **0 bytes differed**. So
  nothing in that page is rewritten during play; it is image, not state.

**But loading it breaks the harness, and the extent is not the cause.** With either a 0x400- or a 0x480-byte
load the run now **faults after 3 407 instructions** at `0x80088554` on an access to `0x805ee000` — an address
~1.8 MB past the end of RDRAM — where without IPL3 it ran 300 000 instructions cleanly.

So the fault is not "the wrong bytes at the wrong length"; it is that **something in this harness executes the
IPL3 region**, which the real machine never does (IPL3 has already run; its stub is residue that only the
vector installation touches, and only its first 16 bytes). The load is therefore **opt-in and off by default**
(`build(..., with_ipl3=True)`), with the extent and the fault recorded next to it.

**Next diagnostic, bounded:** put a read/write watchpoint on `0x80000000`–`0x800003ff` and log the PC that first
touches it. That names the code path which illegally re-enters IPL3, and it is a single run.

#### Solved: the "IPL3 re-entry" was a clobbered boot variable (M75)

The watchpoint answered it, but not the way either of us expected: **execution never entered
`0x80000000`–`0x800003ff` and nothing wrote to it.** The region was being **read as data**, twice:

```
pc 0x8004d198  reads 0x80000318     <- inside FUN_8004D190 (thread 7's init)
pc 0x8000e3d4  reads 0x80000300
```

`FUN_8004D190` compares `0x80000318` against `0x400001` to choose the **4 MB or 8 MB video layout** — that
address is the **RDRAM size IPL3 detects and stores**, not code. An ares dump confirms it:

| address | ares | cartridge `ROM 0x4c0+off` (what I wrongly loaded) |
|---|---|---|
| `0x800002f0` | `0` | `0x0afab0024` |
| `0x80000300` | `1` | `0x0afaf0034` |
| **`0x80000318`** | **`0x00800000`** (8 MB, ares' default) | `0x0afb50054` |
| `0x8000031c` / `0x320` / `0x33c` | `0` | code bytes |

So loading IPL3's *code* over the *variables* fed the game a garbage "RDRAM size" of `0xafb50054`, it took the
8 MB branch, and its framebuffers landed at `0x805ee000` — **past the end of this 4 MB harness**. The fault was
never a re-entry into IPL3, and never an emulation error in the CPU.

**Fix: load IPL3's stub, then restore the boot variables for a 4 MB machine** (`0x80000318 = 0x00400000`,
`0x300/0x31c/0x320/0x33c = 0`). Result:

```
400,000 instructions   fault: none   installer hits: 0
current thread 0x8010b700 (thread 7)   queue validCounts 0/0
```

Clean execution with IPL3 present, exactly as the real machine has it.

**What remains open, now cleanly isolated:** the game still never installs the exception preambles in this
harness (`E_VEC` holds IPL3 code, where ares holds `3c1a8000 275a06d0 03400008`). So the divergence is not
IPL3, not the boot variables, not the CPU, not the queues — it is that **thread 7's init never reaches the
vector installer**, which is the same finding as M43 from the other direction.

#### RESOLVED: the installer belongs to `main`, and every earlier run skipped it (M76)

Static scan for callers of the installer function: **exactly one** —

```
jal 0x800070c0   <- 0x80000564, inside the function starting 0x80000520
```

and `0x80000520` is **`main`**. `0x80007140` is not a function start either (it is a `sw` mid-body), so the
"installer" was always `func_800070C0`, reached from `main`.

Every run in this project started at `FUN_8004D344` — which **`main` calls after installing the vectors**. So
the harness has been entering the boot chain *below* the code that installs them. Running from the real entries
instead:

| entry | instructions | installer hits | `E_VEC` |
|---|---|---|---|
| **`main` `0x80000520`** | 600 000 | **32** (first at 21 079) | **`3c1a8000 275a06d0 03400008 00000000`** — matches ares |
| **entrypoint `0x80000480`** | 600 000 | **32** (first at 42 057) | **same — matches ares** |

**Both runs install the preamble set and agree with the real machine's RDRAM byte for byte.** No faults.

**So the long-standing conclusion was an artefact of the starting point, not a property of the game or of the
emulation.** "Thread 7 never installs the vectors" (M43, M73, M75) is superseded: thread 7 was never the owner.
`main` installs them, and the harness simply never ran `main`. That also explains why Phase 1 "reached the
installer inside thread 7" only after booting through paths the host had faked — the entry point, not the
emulator, was doing the misleading.

#### The spin was my zeroed boot variable; boot from `main` now works (M77)

`main`'s body, disassembled at the point the harness sat still:

```
0x80000564  jal 0x800070c0        installs the vectors
0x8000056c  lui v0, 0x8000
0x80000570  lw  v0, 0x300(v0)     read 0x80000300
0x80000574  bne v0, zero, +0xc
0x80000578  addu
0x8000057c  beq v0, zero, -0x4   <-- spins on itself while that word is ZERO
0x80000584  jal 0x80000598        boot loader
```

`0x80000300` is another IPL3-written boot variable, and **the ares dump has `1` there**. My M75 "restore the
boot variables" step had explicitly **zeroed** it, so every run from `main` sat in that two-instruction loop —
1.5 M instructions with zero progress.

**With `0x80000300 = 1` and `0x80000318 = 0x00400000` (4 MB), booting from `main` now works end to end:**

```
1,500,000 instructions   faults: none   11 context switches
E_VEC = 3c1a8000 275a06d0 03400008 00000000     <- installed, matches ares
host primitives: pi_dma, inflate, pi_dma        <- boot loader ran, stage-2 loaded
current thread 0x8010b700 (thread 7), active queue 0x80112a40 (thread 1)
```

**RDRAM diff against the ares title-screen dump, before vs after the entry fix:**

| class | entry `FUN_8004D344` | entry `main` |
|---|---|---|
| `same` | 704 | **730** |
| `harness-zero` | 286 | **190** |
| `ares-zero` | 4 | 4 |
| `both-differ` | 30 | **100** |

More pages now match and far fewer are unloaded — but `both-differ` rose, because the harness is loading and
writing much more while the ares snapshot is from a **much later point in time** (title screen). Pages like
`0x8017c000` hold decompressed asset data in both, at different stages of the load. **The comparison is not
time-matched**, so the difference count is now dominated by schedule, not correctness.

**Next requirement, not a bug:** compare like with like — either run the harness much further (millions of
instructions to reach a title-screen-equivalent state) or capture an ares dump at an early point the harness can
reach. Time-matching is what makes the page diff a correctness measure rather than a progress measure.

#### Injecting interrupts breaks the boot chain's return path (M78)

The harness cannot be pushed to the title screen, and the reason is not time: it runs at **465 000 instr/s**
(3 M in 6 s), so a title-screen run would be minutes. After boot the system is **idle** —

```
thread 7 RUNNING at the 'b .' spin 0x8000051c   (99.9 % of all executed instructions)
thread 1 WAITING   thread 9 WAITING   run queue empty
```

— so what is missing is **hardware events**, exactly as on the console.

Injecting them through the MI model (any of VI/PI/AI/SP, with the mask guest-owned) produces:
**one exception taken, then a jump to address 0.** Tracing the handler shows the boot chain *unwinding* after
the interrupt:

```
0x80007300  (helper, jr ra)     0x8000dc90..dca4  (osStartThread epilogue)
0x8004d388..d394 (FUN_8004D344 epilogue)   0x800006a0..6b4 (FUN_80000598 epilogue)   -> 0x0
```

So the exception round-trip leaves the return chain with a null `ra` and execution falls off the end. The guest's
handler at `0x800006d0` is responsible for the full context save/restore; this harness models `EPC`/`EXL` but the
general-register round trip evidently depends on state it does not model.

Also established on the way: **VI is not a registered event** — the census found only AI(4), SP(9), PI(6), RDB(14)
on `0x80139f10` — so a VI interrupt would dispatch to a null handler even on real hardware. All four sources
crash identically, which is how the handler path (not the device) was identified as the culprit.

#### Interrupt context path scoped (M79)

Full scoping in `docs/log/M79-interrupt-scope.md`. The headline: **the guest handler does the context
save/restore itself** — `0x800006d0` builds `k0 = 0x80015000` and saves with `sd at,0x20(k0)`, `mfc0 k1,$12` →
`sw k1,0x118(k0)`, `sd t0/t1/t2`, `mfc0 $13`, `mfc0 $9`, then copies into `__osCurrentThread`. So the harness
must **not** implement context switching; it needs **CP0 fidelity good enough for the guest's round trip**.

Seven gaps identified, ranked. The one I would fix first is both the smallest and the most likely cause of the
M78 unwind:

**G1 — exception entry during a delay slot.** The idle spin (`0x80000518` branch / `0x8000051c` delay slot) is
exactly where the first interrupt lands, and `take_exception()` sets `EPC = pc` unconditionally instead of
`EPC = branch address` with `Cause.BD = 1`.

Then G2 (registers are 32-bit approximations, and the handler saves with `sd`/restores with `ld`), G3
(`Count`/`Compare`), G4 (interrupt taken while a host hook runs), G5 (multiple pending sources), G6/G7 lower
priority.

Acceptance criterion for the whole piece: *inject one PI completion at the idle spin and the guest's handler
runs, the event table is consulted, a message is delivered, a waiting thread wakes, and the boot chain does not
unwind to `0x0`.*

**Both queue handoffs remain unexplained and separate**, exactly as argued: the only registered event queue
is `0x80139f10`, while the blocked receives are at `0x8012bd30` (thread 9) and `0x8012bcf8` (thread 1).

### What is still not available

A full-game trace. The harness runs one function at a time with prepared state; it cannot follow the
thread scheduler, so it cannot observe the open as it actually fires at a scene transition. The load
trace above is real execution of the loader, replayed per slot, not a recording of the game's own
dispatch order.

### A genuine execution trace is not available here

No N64 emulator is installed and this project has no CPU harness, so a trace of the form
`iteration → pointer → descriptor → size → destination` cannot be produced by observation. It would need
either an emulator with a write/PC hook, or a partial CPU emulator driven from the wrapped ELF images.
Recording this as *not done* rather than reconstructing something that looks like a trace: a fabricated
trace would be the easiest possible way to make this architecture look finished.

### What this leaves for R3

R3 is referenced by nothing we can see: not statically (no record, no constructed address, no cart
pointer in any of 4 761 members) and not dynamically (the only loader path is the fixed 9-slot registry,
which maxes out at cart `0x7e132`). The 4 761 zlib members are therefore **not** loaded through this
registry at all — they must be reached by the sequential stream walk that §3 already demonstrates works,
or by a mechanism still outside the mapped code.

### No descriptor points into R3. Three independent tests:

| test | result |
|---|---|
| boot descriptor table (66 records, `0x80012150`) | cart offsets stop at `0xC85E8`; R3 starts at `0xB73FB3` — **0.82 MB vs 12 MB, no overlap** |
| stage-2 image: `0xB`-flagged records in the boot shape, and `lui`+`addiu` constructions landing in R3's range | **0 records**; 93 constructions, all masks (`0x00FFFFFF`, `0x01000800`, `0x014000F0`, …) |
| strict record shape (4 coordinated fields: flag+offset, size, vram, vram_end) across **all 4 761 unpacked members** | **0 records in 0 members** — the boot table is the only instance of this format in the cartridge's compressed content |

The exact value `0x00B73FB3` — plain and `0xB`-flagged — occurs **nowhere** in the ROM or in stage 2.

A tempting-looking test that must be rejected: scanning for words whose top nibble is `0xB` "finds" 24 059
cart offsets across 2 415 members, and 893 apparent pointers into R3. One sixteenth of all random words have
that nibble, so the flag alone is worthless. The boot table was identified by four fields agreeing over
consecutive records, and only that strict shape is evidence.

### The reframing this forces

**R3 is not a resource.** Its boundaries came from inverting zlib coverage — it is *everything in that span
that is not a zlib member*, so a descriptor for it need not exist, and its first bytes are a preceding
block's trailer rather than a header. Asking "which descriptor points into R3" is therefore ill-posed
until a **specific offset inside R3** is chosen. R1 and R2 escaped this because their spans happened to
contain real containers (media blocks with a verified trailer format); R3 and R4 did not.

**Superseded by M178, in the direction this paragraph was cautious about.** The caution was right that a
span inverted from zlib coverage need not be a resource, and the resolution is a measurement rather than a
reversal: R3 *is* exactly one file (id 1983) and R4 is id 1979, with each span 9 B / 8 B wider than its
file. So "which descriptor points into R3" has an answer — the file table entry at those two ids — and the
9 bytes at the head of the span are the preceding file's trailer, as predicted here.

## 6. Verification rules this document follows

1. **Two independent paths, or it is not established.** The descriptor table was decoded from
   pseudocode *and* confirmed by blind sequential inflation; the media format was derived from 1 226
   transitions *and* confirmed by a decodable concatenation.
2. **A null result implicates the filter first.** Three scans in this project returned zero because of
   an invented constant (`offset < 0x4000000`, adjacent `(rom, vram)` pairs, `CMF == 0x78`). Every
   later scan was tested against a known positive before being believed.
3. **The cartridge is immutable input.** `scan_headers.py` and `extract_blocks.py` print the ROM's
   sha256 before and after, and both runs show `UNCHANGED`.
4. **`assets/` is gitignored.** Every extracted byte is a derivative of the user's dump and is
   regenerable from the ROM plus these three tools in about twenty seconds.
