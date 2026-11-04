# M84 — the static tables: store-runs, jump tables, and the address I had wrong

**Headline:** the question "who writes `0x800ca458`" had no answer because there is no writer — and
no such address. `addiu v0,v0,-23464` is **signed**, so it builds `0x800ba458`, where a fully
populated 11-entry jump table sits in `.rodata`. Reading it back turns an indirect dispatch into a
list of concrete case blocks: the 5 484-byte region at `0x8009d014` goes from **5.3 % → 99.9 %**
claimed, `stage2` from 1 565 → **1 911** functions, corpus coverage **61.3 % → 62.3 %**, with
`failed 0` throughout and **0 mis-bounded functions**.

That is the third time in this project that a hand-computed constant decided what the measurement
could see. The first was the `0x480` base error; the second was `81 852` for a 28-payload run; this
one is an *unsigned* reading of a signed immediate.

## 1. The address error, and what it reveals

`func_8009d018`'s dispatch decodes to:

```
0x8009d038  3c02800c  lui   v0,0x800c
0x8009d03c  2442a458  addiu v0,v0,-23464     <- SIGNED: 0x800c0000 - 0x5ba8 = 0x800ba458
```

My own disassembler printed `-23464` correctly; the *constant scanner* beside it used
`(hi << 16) | lo`, which is `ori` semantics, and reported `0x800ca458`. Everything downstream
inherited it: the table looked zero-filled, so I concluded it was built at runtime, and then went
looking for the code that fills it. The tables are in fact **static**, at `0x800ba458`,
`0x800ba488`, `0x800ba4b8`.

| dispatcher | table | declared cases | entries recovered |
|---|---|---|---|
| `func_8009d018` | `0x800ba458` | 11 (`sltiu v1,0xb`) | **11** |
| `func_8009d878` | `0x800ba488` | 12 (`sltiu v1,0xc`) | **12** |
| `func_8009de50` | `0x800ba4b8` | 15 (`sltiu v1,0xf`) | **15** |

Each table's entry count matches the case bound the dispatcher itself declares — an acceptance test
that fails loudly if the walk over-reads. It did at first: table B walked 27 entries, straight
through the padding into table C.

So `0x8009d020`'s "indirect caller" **is** the table, and the table is data: no caller code exists
to find. The earlier M83 conclusion — "the case blocks remain unattributed because static analysis
has no way to see a table that does not exist until boot" — was wrong on both halves, and is
corrected there.

## 2. Store runs: the class that explains the shared load address

`tools/find_store_loops.py` finds reads of a table-initialisation shape: consecutive stores of
**constructed constants** into **consecutive addresses** off a **constructed RDRAM base**.

The guards matter more than the pattern, because memcpy loops, stack fills and framebuffer clears
look identical:

1. the stored value must be built by `lui`/`ori`/`addiu`/`addu` in the instruction stream — a value
   loaded from memory is never treated as a constant;
2. the base must be constructed and land in RDRAM;
3. addresses must step by a constant stride of 1–16 bytes;
4. the run ends at the first store that breaks the stride, a branch, a jump, or a store through a
   different base; runs shorter than `--min-run` are discarded.

Corpus-wide that yields **3** runs, all in stage-2:

| table | entries | stride | distinct values | what it is |
|---|---|---|---|---|
| `0x800e15f0` | 34 | 4 | 5 (`0x80161cf0`, `0x80162c1c`, `0x80163264`, …) | per-slot pointers for staging bank B |
| `0x800e1770` | 30 | 4 | 3 (`0x8016e880`, `0x80171198`, `0x80171224`) | the same for bank C |
| `0x800e1530` | 27 | 4 | 1 (`0x80079470`) | one default handler repeated |

**This is the mechanism behind the twenty-overlays-at-`0x80161cf0` fact.** The initializer hands
every slot the *same* staging-bank base and then overrides individual slots with specific overlay
functions.

**Reframed (M85):** that is a **design feature, not a defect in the ROM**. The earlier phrasing —
"an address does not identify an image" — described a real bug in the *seeding rule* (a boundary
belongs to one image, and the rule was broadcasting it) and wrongly implied the sharing was a ROM
quirk. The accurate statement is: **a slot has a destination**, the destination table is installed
once, and twenty payloads can legitimately share one base because they are loaded one at a time.
The seeding rule stays image-scoped; the reason changes from "the ROM is odd" to "the architecture
gives slots, not payloads, their addresses".

Two details worth keeping: the run is emitted by the compiler as repeated `lui`+`addiu` for the
value, so the 48-store sequence arrives as three chunks; and the table extent (48 × 4 = 192 B) must
not be confused with the code extent of the initializer (`0x800324a8`–`0x800327e4`, 828 B).

## 3. Jump tables: recovering bodies, not just boundaries

`tools/find_jump_tables.py` scans for `lui`+`addiu` → RDRAM base followed by a loaded register and
`jr` through it, then reads the table. Acceptance is the table's own structure: entries must land
**inside the image**, be **4-byte aligned**, be **strictly increasing**, span **under 64 KB**, and
not exceed the dispatcher's declared `sltiu`/`slti` bound.

Corpus-wide: **245 dispatch sites, 1 139 recovered targets.**

Applied to **stage-2 and the boot bank only** (402 seeds: 14 curated, 22 boundary candidates, 366
table targets):

| axis | baseline | final | Δ |
|---|---|---|---|
| functions | 3 267 | **3 638** | **+371** |
| coverage | 61.1 % | **62.3 %** | **+1.2** |
| failed | 0 | 0 | 0 |
| unexplained `in_vN` | 0 | **0** | 0 |

Region `0x8009d014`–`0x8009e580`: **5 480 of 5 484 B = 99.9 %**, 41 claimants, and all 11 of table
A's entries now exist as functions.

### The two rejections, both measured

Applied wholesale, the class is not clean everywhere, and the rejections are recorded as data:

* **Overlay images — rejected as a class** (`config/rejected_seeds.txt`): 757 targets produced **44
  functions reading an undefined register (5.8 %)** and one target never created. The same class on
  stage-2 produced 0.
* **One stage-2 table — rejected by address** (`config/rejected_tables.txt`): `0x800b90e0`, whose
  **7 of 7** entries decompile with `in_v1` — those are fragments of a dispatcher's body, not
  function entries.

Both deny-lists state the measurement, so a future session can overturn them by re-measuring rather
than re-arguing. `make_seeds.py` honours them, including wildcards.

## 4. The audits' arithmetic, reconciled

| flag | resolution |
|---|---|
| 176 B vs 288 B vs 5.3 % | The three dispatchers are **non-contiguous**: each has a preamble *and* a tail block (`func_8009d018` claims `0x8009d018`–`0x8009d053` **and** `0x8009d854`–`0x8009d877`). Six ranges, **291 B by inclusive extent / 288 B by 4-byte cells**, so 5.3 % is right and 176 B counted only the preambles |
| region start is entry − 0xC | It is not a derived constant: `0x8009d014` is where the unclaimed run began in the M82 index. Nothing claims `0x8009d010`–`0x8009d017` in the current index, so the principled bound is the first entry. The denominator is only used for this note's before/after and is stated with the region |
| +25 from 24 candidates | 22 stage-2 + 2 boot candidates → 25 functions: `boot` gained **one incidental split** (`0x800115b0`) because a seeded boundary changed the analysis flow there. Nothing was lost on either side (`lost: []`) |
| `failed 0 → 0` is the headline | Agreed, and it was the reason to stop pushing boundary discovery: the missed-function class bought **+25 functions and +0.2 points**, i.e. boundaries without bodies. The jump-table class bought **+346 stage-2 functions and +1.0 point** because it recovers *bodies* |
| determinism | Confirmed on a previously-disputed image: `ovl_00a43b6` gives **47 / 47 / 47** across three runs, so the earlier +59 was the broadcast seed file, not REA variance |
| overlay count | Three different numbers were in play: "six overlays" (M19/M20) were the six *payloads the registry loads*; 16 files are code payloads in the 36-image corpus; **20** share load address `0x80161cf0`. They are different questions and the log's M81 row now says which is which |

## 5. What this does not establish

* **The bank-C codec is still not decoded**, and nothing here changes that. What changed is the
  search space: the loader would read cart `0xb6248`–`0xc8624`, no construction of any address in
  that range exists in 36 images, and the two staging banks are installed by a table initializer
  rather than by per-record loads. The remaining route is code we have not mapped — now 61 KB, down
  from 63 KB, and the store-run class is the tool that reads a store-only initializer.
* **Some jump-table targets are fragments.** The rejection lists what is known to be; the class as a
  whole is not proven clean on images other than stage-2 and boot.
* **Coverage is not quality.** It rose 1.2 points this time because *bodies* were recovered; last
  time it rose 0.5 points because a boundary was wrong. The two are indistinguishable from the
  number alone, so the corpus reports `failed` and `in_vN` beside it.

## 6. Next

1. **Understand `0x800b90e0`.** Seven case blocks that each read an incoming register are a dispatch
   shape, not an accident; reading the dispatcher at `0x8005fd8c` may show a second dispatch
   convention the corpus should model rather than reject.
2. **The overlay tables.** 5.8 % of targets are fragments; the other 94 % may be as valuable as
   stage-2's. Sorting one overlay's tables by hand would give a rule for the rest.
3. **The bank-C loader, third attempt.** With the store-run class available, scan for a routine that
   *reads* cart offsets rather than writes a table: a `lw` from the descriptor table followed by a
   store into one of the two staging bases.
