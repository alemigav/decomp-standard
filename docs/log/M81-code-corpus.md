# M81 — the code corpus

**Question:** how much code does this cartridge contain, and can all of it be decompiled into a
source tree we can read and version?

**Answer:** **36 code images, 1 947 632 B, 3 267 functions, 61.1 % of the bytes claimed, 0 failed
decompilations, 100 % of in-code `jal` targets resolving to a function entry.** The tree is
`src/`, indexed in `src/INDEX.md` and `manifests/code_index.json`, regenerable in ~4 minutes.

Before this milestone the project had decompiled source for **no** function — 20 functions were
named and their bodies existed only inside `format_notes.md` prose.

## 1. The inventory was an assumption; now it is a census

The old code list was the boot bank plus the seven payloads the cart table names — 8 images. A scan
of all 4 761 decompressed members on code-specific signals (prologue `addiu sp,sp,-N`, `sw ra,N(sp)`
frame saves, `jr ra`, `jal`, `lui`+`addiu` RDRAM pointer construction) finds **35 members holding
code plus the boot bank = 36**.

| measurement | value |
|---|---|
| members scanned | 4 761 (18 550 424 B decompressed) |
| classified code | 35 + boot bank = **36** |
| code bytes | **1 947 632** |
| code images the cart table names | 35 of 35 — **no code exists outside the table** |
| non-code members | 4 726 (16 672 744 B decompressed) |

So code discovery at the member level is **closed**: every code payload is named by the cartridge's
own load table, and the table is the code index. What was missing was not discovery but the work of
decompiling what it names — which is what the rest of this milestone does.

**The classifier's floors earned their keep:** a `jal`-only filter would have accepted member 3178
(2 576 B, 510 `jal`-shaped words, **zero** `jr ra`, **zero** prologues) at a score of 202.7 — 15×
the boot bank's 13.97. Requiring both a return and a frame rejects that whole class of data. Three
small real code stubs (464 / 672 / 880 B) were initially rejected by a flat `jal >= 10` floor and
are now included; the documented floors are `jr ra >= 3`, `prologue >= 1`, `jal + jr ra >= 6`, plus
density.

## 2. The load table names itself — three corrections to §2 of `format_notes.md`

`tools/read_overlay_table.py` finds the table by searching for its own marker instead of trusting a
hardcoded address, and validates every record on four simultaneous constraints (pointer in the cart
window, stored size inside the cartridge, `vram_end >= vram_start`, decompressed size equal to the
unpacked member when one exists).

1. **The table is self-describing.** The 16 bytes at vram `0x80012150` (ROM `0x12cd0`) are ASCII
   `OVERLAYTABLENUM` followed by a count byte **`0x43` = 67**.
2. **66 records validate, not 67.** The 67th slot at vram `0x80012580` has a cart pointer
   (`0xb00c8624`) and a size field of **`0xCDCDCDCD`** — the only occurrence of that word in the
   entire 64 MB cartridge. Three of its four fields are zero, so it is a reserved slot whose size
   was never written; the value is a build-time fill pattern, not a size.
3. **Four destinations, not "overlays".** Records target `0x80018a80` (stage-2), `0x8017b410`
   (6 records), `0x80161cf0` (28), `0x8016e880` (29). That is a fixed load list into three staging
   banks, and the nine-slot registry at `0x8010b2e0` is a *subset* of it.

Also corrected: the boot bank is `0x12140 - 0x1000` = **69 952 B**, not the 69 184 B that
`format_notes.md:27` states. And the bytes after the table (vram `0x80012590`) are zlib's own
static inflate tables (`lbase`/`lext`/`dbase`/`dext`), so the "second-stage file index" is **not**
there — candidate eliminated.

## 3. A new open question the table exposes

28 records of the `0x80161cf0` group have **identical decompressed sizes, in the same order**, as
28 of the 29 records in the `0x8016e880` group, with different compressed sizes. Their payloads are
real, they are code, and they are **not zlib**: the group starts at cart `0xb6248` (immediately
after a 519-byte stream plus its odd-length pad byte) with `02 23 18 00 00 03 ac …`, which inflates
under no zlib variant. They cannot be extracted yet, so they are **not** in the corpus.

Consequence for R4 (`0x0338fe1`–`0xb63106`): its tail holds a **non-zlib container of 28
payloads**, which is the first concrete content ever identified inside that region. **Correction
(M82):** an earlier version of this note called them "code by every signal available" — that was an
inference from their sizes matching bank B, and M82 refutes it at the literal level while leaving
identity unestablished. Their decoded content is **unknown**. R4's entropy
also does not reproduce — measured **7.9371**, not the 7.34 in `format_notes.md` §5. R3 measures
**7.1893**, not 7.08. Both figures need correcting.

## 4. What the corpus is

| step | tool | output |
|---|---|---|
| census | `tools/scan_code_members.py` | `manifests/code_census.json` |
| table | `tools/read_overlay_table.py` | `manifests/overlay_table.json` |
| ELF wrap | `tools/build_images.py` → `tools/wrap_mips_elf.py` | `build/elfs/*.elf` (36) |
| seeds | `config/symbols.tsv` → `tools/make_seeds.py` | `build/seeds/*.tsv` |
| decompile | `rea decompile-all … --provider ghidra` | `build/decomp/*/` (journals) |
| export | `tools/export_src.py` | `src/` + `manifests/code_index.json` |
| verify | `tools/verify_corpus.py` | six checks, four of them hard failures |

Decompiling is cheap: **the boot bank's 210 functions took 12.4 s**, all 36 images under a minute
each, 0 failures of 3 267. Wall-clock was never the constraint — which is the point.

Two projections that make the tree readable rather than merely present:

- **Cross-image names propagate.** Each image is analysed alone, so `0x80006d60` is `osCreateThread`
  in the boot bank but appears as `func_0x80006d60` inside stage-2. The exporter rewrites known
  references from `config/symbols.tsv`. `stage2_entry` now reads
  `osCreateThread(&DAT_8010b700, 7, stage2_init, 0, &DAT_800c36a0, 0)` — M15's finding, reproduced
  from the bytes.
- **Provider artefacts are demoted.** `wrap_mips_elf.py` sets `e_entry` to the image base, so Ghidra
  labels each overlay's first function `entry`. That is our wrapper, not a game symbol, so the
  exporter renames it `func_XXXXXXXX`. A name still needs evidence.

## 5. Verification, and what it says

| check | result |
|---|---|
| seeds placed | **33 / 33** |
| call closure **inside claimed code** | **6 493 / 6 493 = 100.00 %** |
| call closure over the whole image | 7 061 / 7 088 = 99.62 % — the 27 misses are `jal`-shaped words in data (`0x80043008` = `addiu a2,sp,0x10`), not calls |
| second opinion on the boot bank | splat **243** vs Ghidra **210**; 208 agree, 35 splat-only, 2 Ghidra-only |
| byte coverage | 1 189 484 / 1 947 632 = **61.1 %** claimed |
| named functions regress | `cart_record` still `param_1 * 0x10 + -0x7ffedeb0`; `stage2_entry` still spawns thread 7; `overlay_open` still calls `0x8004cc…` |
| reproducibility | re-decompiling `ovl_00b5e64` gives **3/3 identical body sha256** |

Two notes on the numbers:

- **The 35 splat-only entries are not lost code.** Only **1 of 35** starts with a prologue; their
  sizes are 4–1 572 B and they are call sites and fragments splat split where Ghidra merged them
  into the enclosing function. Conversely the **2 Ghidra-only functions are ours** — `0x800006d0`
  (the exception handler) and `0x80000c68` (the thread dispatcher), i.e. exactly the interrupt path
  that arcs 58–61 kept failing to reach. Seeding found what splat never split.
- **Coverage is 61.1 %, and that is not 61.1 % of code.** Stage-2 claims 46.0 % only because a
  521 344 B run at image offset `0x09ddb0` is the empty tail (32 B claimed beyond `+0xA0000`), and
  the first 47 428 B is data below the dense region. The informative gaps are the small ones —
  5 488 B at `0x8009d014`, 4 148 B at `0x8008f4c4`, 3 968 B at `0x800b26c0` — which are jump
  tables, literals, or functions the provider did not find.

## 6. What this does not establish

- **Not byte-matching, and not original source.** This is Ghidra pseudocode through REA's
  `elf32-exec-mips1-legacy-pinned-v1` lane, which states that **MIPS-I conformance is not
  established** from a header with `e_flags = 0`. Treat decoded output as plausible, not
  authoritative; the known-truth fixture (`tools/mkmips.py`) remains the control.
- **No callee graph from the index.** `decompile-index.json` carries no edges, so the corpus derives
  them from a `jal` scan — exact for direct calls, blind to indirect ones. M27 already showed the
  message sends are indirect (51 sites, no literal queue argument), so **the call graph does not
  answer where `0x8012bd30` is posted from**. That question stays open.
- **The 28 non-zlib payloads are absent** (§3). Their decoded content is unknown — see
  `docs/log/M82-r4-container-and-gaps.md` §1 for the codec negatives and the identity control.
- **Discovery at the member level being closed does not mean discovery is finished**: a code image
  could still live inside a non-code member as a sub-range, and the unclaimed runs in §5 are
  exactly where to look next.

## 7. Next

1. Decode the non-zlib container at cart `0xb6248` — 28 code payloads, identical decompressed sizes
   to the zlib group, first structured content ever found in R4.
2. Read the unclaimed runs inside stage-2 as data-vs-missed-function, starting with `0x8009d014`.
3. Correct §2 and §5 of `format_notes.md` with §2 and §3 above.
