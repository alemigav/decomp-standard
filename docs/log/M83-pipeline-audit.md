# M83 — the pipeline audit, and what the differential actually measures

**This note exists because two claims from M82 did not survive measurement.** Both were mine, both
were the same class as the `0x480` base error the log already warns about — a constant that quietly
defined what the experiment could see — and both are corrected in M82 in place, not rewritten away.

Three parts:

1. **the audit's arithmetic and provenance flags**, resolved;
2. **four defects in the corpus pipeline**, three of which produced plausible-looking output;
3. **the honest differential**: baseline 3 267 functions / 61.1 % → final 3 292 / 61.3 %, with the
   contaminated 4 184 / 59.5 % explained and discarded.

## 1. The flags

| flag | resolution |
|---|---|
| geometry does not close (81 852 vs 74 716) | **Correct.** 81 852 was the 29-payload total including slot 6 (7 136 B); the 28-payload run is `0xb6248`–`0xc8624` = **74 716 B = sum(stored)**, gaps 0 across 27 pairs. `decode_r4_container.py layout` now prints start, end, `end−start` and `sum(stored)` on one line and refuses the claim unless they agree |
| retraction not in the log | **Correct.** `reverse_engineering_log.md` gains M81/M82/M83 rows carrying `[retracted]` markers — the log is the document, and a commit message is not discoverable from it |
| denominator moved 311 506 → 74 716 | **Correct.** The container starts at `0xb6248`; the 229 654 B "gaps" were the ordinary zlib members between slot 6 and the run. M82 now says this explicitly |
| "exact-length acceptance" semantics | **Correct to require.** The expected length is the table's `decompressed` field (52 112 for payload 38), never the stored size (7 640), so the test is not trivially satisfiable. The five `pack24-hi` × `deflate-15` cases emitted the wrong number of bytes and are rejections, not near-misses |
| `is_record_family` status | **All-or-nothing**, exactly one named exclusion (slot 6, the zlib member). Stated in M82 |
| minors | bit-level probes are 7 offset widths × 5 length widths × 2 bit orders = 70 per payload × 28 = 1 960; the 432-entry dictionary is the distinct values of the 16-bit field at bytes 1–2 across payload 38's 1 910 records |

One flag's premise does not apply, and it is checkable: **the ELFs cannot carry discovery forward.**
`wrap_mips_elf.py` emits `ehdr` + one `PT_LOAD`; measured on `build/elfs/boot.elf`: `e_shoff = 0`,
`e_shnum = 0`, `e_entry = base`, `phnum = 1`, payload byte-identical to the ROM slice, and
re-wrapping from ROM + base reproduces the file's sha256 exactly. Nothing but
`REA_GHIDRA_SEED_FILE` seeds a run.

## 2. Four pipeline defects, three of them silent

### D1 — a cancelled run leaves output that looks complete (worst)

A cancelled `decompile-all` returns `{"code":"cancelled"}` and **keeps the partial directory**. On
`ovl_0090698` that left **34 of 103 functions with `failed: 0`** and a valid `decompile-index.json`.
Any pipeline that trusts exit status or "the index exists" measures the cancellation, not the image.

**Guard:** `tools/run_corpus.py` requires `normalized_result` in the reply, deletes the directory
otherwise, and is the only way the phases are now run.

### D2 — the index can report `written` for files that do not exist

`ovl_0095446` shipped an index with **36 of 93 entries marked `written` whose `.c` files were
absent**; the export crashed on the first one. **Guard:** the same runner verifies that every
`written` entry's file exists before believing the count.

### D3 — a seed address does not identify an image

Twenty overlays load at `0x80161cf0`. `make_seeds.py` filtered symbols by address range, so the 60
candidates discovered in `ovl_0090698` were written into **every** co-located overlay, decorating
each with 60 functions that belong to different bytes. **105 mis-bounded functions** followed.
**Guard:** discovered boundaries are applied to their own image only (`seeds_extra/<image>.tsv`),
and a curated name must fall inside exactly one image.

**Applied set:** the discovery pass found **84 candidates**; **24** are in the corpus — 22 in
stage-2 and 2 in the boot bank. The 60 from `ovl_0090698` were rejected as a block because every one
of them produced an `in_vN` function (105 in total once broadcast), and because the 60 s
`manifests/missed_functions.json` record stands as the discovery output, not as the applied set.

### D4 — `in_vN` is the signature of a mis-placed boundary

Seeding a prologue whose argument preload was hoisted above the frame setup decompiles to
`undefined4 in_v1`. This is the cheapest available detector, and it is now
`verify_corpus.py` check 7: **0 unexplained functions** may read an incoming register, with two
documented exceptions (`entrypoint`, whose caller does not exist, and one pre-existing provider
boundary in `ovl_007c552`).

## 3. The differential, measured against a true null

Two phases, same ELFs, different seed files only:

| axis | baseline (curated 33) | final (curated + discovered) | reading |
|---|---|---|---|
| functions | **3 267** | **3 292** (+25) | discovery added boundaries; 24 candidates bought 25 functions |
| named | 33 seeded + provider defaults | +24 discovered names | the seed-file differential |
| failed | 0 | 0 | discovery resolved **no** decompile failures |
| coverage | **61.1 %** | **61.3 %** (+0.2) | 4 468 B newly attributed |

And the discarded measurement, kept because the reason it was wrong is instructive: the first
"final" run reported **4 184 functions and 59.5 %** coverage — more functions, *less* coverage. That
run was contaminated by D3, and the extra 917 functions were 105 `in_vN` defects plus their
neighbours. A rise in function count with a fall in coverage is a signature worth recognising.

## 4. The bank-C loader: what the search established

The loader was not found, and the negatives are specific:

* **No code in the corpus references cart `0xb6248`** — no `lui`+`addiu`/`ori` construction lands in
  `0xb6248`–`0xc8624` anywhere in 36 images.
* The search did find both staging destinations, in **one contiguous stage-2 region,
  `0x800324c8`–`0x800327dc`**, and it is a *pointer-table initializer*, not a decoder: it stores
  `0x80161cf0` into 48 consecutive words and `0x8016e880` into the next 48, all relative to
  `0x800c76b0 + 0x18000`. So the two banks are installed as per-slot defaults and something else
  overwrites entries later.
* That initializer is itself in an **unclaimed** run with **no prologue and no `jal`** — pure store
  loops — which is precisely the shape `find_missed_functions.py` declines to seed, and why the
  loader was invisible to the discovery pass.

**Consequence:** decoding the container needs the routine that *reads* record 38–65, and that
routine is either in the 61 KB of remaining code-like gap or reached through a runtime-built table.

## 5. `0x8009d020`'s indirect caller: the answer is "there is no static caller"

* **Zero direct control transfers** into `0x8009d020`, `0x8009d880`, `0x8009de58` from anywhere in
  stage-2 — no `jal`, no `j`, no branch.
* **The addresses appear nowhere** in any of the 36 decompressed images, as data or as a
  `lui`+`addiu` construction.
* The functions are **switch dispatchers**, and their case blocks are reached through a table.
  **Corrected (M84):** that table is at `0x800ba458`, not `0x800ca458` — `addiu` takes a *signed*
  immediate — and it is **statically populated** with 11 entries. Nothing fills it at runtime.
* The real entries are `prologue − 8`, where `lui v0,0x8013` / `lhu v1,0x272e(v0)` loads the
  dispatch index. With those entries the three functions are 60/56/60 B and declare no incoming
  register; the region's honest coverage is **5.3 %**, and the case blocks remain unattributed
  because static analysis has no way to see a table that does not exist until boot.

So the "indirect caller" question resolves to: **the caller is a table entry created at runtime**,
and finding the code that fills `0x800ca458` is the same kind of search that would find the bank-C
loader. One read may answer both.

## 6. Next

1. **Find what writes `0x800ca458`.** It gives the case-block addresses (recovering the 5 484-byte
   region properly) and it is the same shape of initializer as the bank-C pointer table.
2. **Scan for constructions of `0x800ca458` and its neighbours** the way the staging destinations
   were scanned — with the caveat that an initializer with no prologue and no calls is invisible to
   the current candidate rules, so the rule set needs a third class: *store-loops into RDRAM tables*.
3. **Do not trust coverage as a quality metric.** It rose when boundaries were wrong (99.6 % on a
   region that is really 5.3 %). Function count, `failed`, `in_vN` and coverage must be read
   together, and the differential must name its baseline.
