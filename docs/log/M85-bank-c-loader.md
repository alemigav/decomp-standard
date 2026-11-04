# M85 — the bank-C loader: found as a call chain, with one hop still open

**The audit's prediction was right on both counts.** The loader is not a loop of constructed stores —
`find_store_loops.py` would have rejected every candidate by design, because the value being stored
comes from memory. It is a **call chain**, and it is now traced five hops deep with one hop
unresolved.

## 1. The instrument had to change first

`tools/find_bank_writers.py` inverts the store-loop question: it does not care how a value was
produced, only **where the store goes**. Bounds are the two installed bases, `0x80161cf0` and
`0x8016e880`, each with a 64 KB window (the largest payload is 52 112 B). It also reports calls to
the four loader primitives whose destination can be in a bank.

Corpus-wide: **720 stores into a staging bank and 11 calls to a loader primitive.** The stores are
mostly `sb`/`sh` of zero (structure initialisation) and `sw` of values loaded from memory — the
provenance column is what distinguishes them, and it says plainly that none of them is the loader.

The calls are what matter:

```
boot    0x80000610  jal pi_dma_raw          args {}
boot    0x80000638  jal inflate_init        args {a0: 0x803fff88}
stage2  0x80032824  jal inflate_init        args {a0: 0x8016e880}   <- bank C's own base
stage2  0x80032838  jal inflate             args {}
stage2  0x8004cc1c  jal inflate_init        args {a0: 0x80139b30, a2: 0x1}
```

`0x80032824` and `0x8004cc1c` are the two inflate chains M16 recorded; what was missing is that the
first one is reached from a slot loader.

## 2. The chain

**`FUN_800327ec(record, dest)` is a generic descriptor inflater.** It reads the 16-byte cart-table
record directly:

```c
int FUN_800327ec(u32 *record, void *unused_dest) {
  if (record[1] == 0) return 0;                 /* stored size 0: nothing to load          */
  if (record[1] == record[3] - record[2])       /* stored == decompressed: already plain   */
      return func_800888ec(record[0]);
  a1 = *(u32 *)0x8010b6f8;                       /* the shared 0x8000-byte inflate window  */
  inflate_init(stack_state, a1);
  inflate(stack_state, record[0], <dest>, record[1]);   /* cart ptr, dest, stored size     */
  inflate_free(stack_state, 2);
}
```

`record[0]` is the `0xB0xxxxxx` KSEG1 cart pointer and `record[3] - record[2]` is the decompressed
size — exactly the layout `docs/format_notes.md` §2 established from the other end. **This is the
function that turns a cart-table record into loaded bytes.**

**`FUN_8003287c(slot)` is the slot loader** and has exactly two call sites of the inflater
(`0x80032a04`, `0x80032a84`):

1. it computes a per-slot destination pointer from the initializer's table
   (`0x800df6b0 + 0x1f40 + 4*(slot-16)`, the store-run table M84 found), and returns early when the
   slot's pointer is zero;
2. it derives a cart-record index and calls `cart_record(index)` (`jal 0x80001180`);
3. it calls `FUN_800327ec(record, destination)`.

So the architecture is: **a per-slot destination table (installed by one initializer) plus a
per-slot record index, joined at load time.** That is why twenty overlays share `0x80161cf0` — the
destination is a property of the *slot*, not of the payload.

## 3. The hop that is still open, and the contradiction that names it

The record index is read as `lbu a0, -16(v0)` where `v0 = s1 + *(u32 *)0x800fb264`. In the image,
**the word at `0x800fb264` is `0x413f514e`** — not a pointer — and:

* **nothing in any of the 36 images constructs `0x800fb264`** as a `lui`+`ori`/`addiu` pair;
* **`0x800fb264` never appears as data** anywhere in the corpus.

Both facts cannot be true of a functioning loader, so one of these holds:

1. the pointer is written by code we have not mapped (the remaining 61 KB of code-like gap), which
   is the same shape as every other runtime-initialised structure in this cartridge; or
2. **my decode of that three-instruction window is wrong.** The sequence
   `lui v1,0x800f` / `lw v0,0xb264(v1)` / `addu v0,s1,v0` / `lbu a0,-16(v0)` computes an address from
   a non-pointer constant, which is the signature of a mis-decode rather than of a design. The
   instruction at `0x800329c0`–`0x800329d0` also reads as `lw`/`sw` through a twice-added base,
   which is unusual.

**Recorded as open, not resolved.** The honest statement is: the chain from slot to inflate is
established; the mapping from slot to cart-record index is not, and the contradiction above is the
place to resume. Guessing an index table now would be exactly the "plausible near-miss" failure this
project keeps finding.

## 4. What this changes for the R4 container

The container is not reached by slot: the loader's index comes from a table, and every cart offset
in the nine-slot registry stops at `0x7e132`. But the **inflater is now named and its calling
convention is known** (`record[0]`, `record[1]`, `record[3]-record[2]`), so the R4 question gets a
sharper form: *does `FUN_800327ec` ever receive a record whose cart offset is in
`0xb6248`–`0xc8624`?* That is a watchpoint on one argument, not a search for a codec.

## 5. The audits' remaining flags

| flag | resolution |
|---|---|
| the `addiu` bug is a class | **Correct.** Added to the errors list as the fourth instance and the first where the wrong constant was a *mode* (OR vs ADD). Corpus-wide re-check: **every tool that composes an address from an immediate now handles the sign** — `find_jump_tables`, `find_store_loops`, `find_bank_writers`, `find_missed_functions`, `find_stream_walker`, `xref_registry`, `mips_harness`, `scan_code_members` — and no tool contains an `(hi << 16) \| lo` composition any more. The bug survived in an ad-hoc shell command, which is the reason to keep consolidating experiments into tools |
| `find_store_loops` cannot find the loader | **Correct, and stated before running it.** That is why §1 uses a destination-based instrument. A negative from the store-loop class on this question would have been a tool mismatch |
| decompose the 41 claimants | **3 dispatchers + 11 + 12 + 15 = 41**, and every entry of all three tables is now a function: **A 11/11, B 12/12, C 15/15** |
| name the 4 unclaimed bytes | One word, at **`0x8009d014`** itself, bytes `00 00 00 00` — a **`nop`**, and specifically the delay slot of the `jr ra` at `0x8009d010`. So the residue is the *first* word of the region, not a hole in the middle. Region extent `0x8009d014`–`0x8009e580` is "where the unclaimed run began", not a semantic region: 99.9 % means *99.9 % of what was previously unknown* |
| promote the `sltiu` bound, with its assumption | **Promoted** to the log's working-method list. The assumption: `count == bound` holds when the table has **no default case**; a dispatcher with a default has `bound + 1` entries and would be wrongly truncated. The mechanism is a backward scan for the nearest `sltiu`/`slti` guarding the dispatch — which is why the 27 = 12 + 15 catch is evidence the mechanism worked *there*, not that it always works |
| `+346 / +1.0` needs its denominator and the `in_vN` row | Restated: **1 139 targets found corpus-wide, 366 applied** (stage-2 + boot). `in_vN = 0` after the fixes, which is what makes these 371 functions well-bounded rather than 371 more seeds. Net-new rate **32 %** (366 seeds → 371 functions including incidental splits) |
| "wholesale is measurably unclean" needs the number | **5.8 %** (44 of 757 overlay targets produced `in_v1`) against **0 %** for 366 stage-2/boot targets. Threshold statement in the config files: **any `in_v1` at all is a rejection for a table; ≥ 1 % is a rejection for a class** |
| rejection criteria are judgement | Now stated in the files: for a *table*, **7 of 7 entries in `in_v1`** (each entry's decompilation declares an undefined register) — falsifiable, not "looks wrong". For the overlays, the 44 `in_v1` functions were **never added** to the corpus: the seeds are rejected at generation, so there is no known defect in the tree, only a recorded exclusion |
| the shared base is by design | **Corrected in the log** (`M84` §2 carries the reframed paragraph). The initializer gives every slot the same staging base and overrides individuals; the seeding rule was still wrong (a boundary belongs to one image), but the earlier framing — "an address does not identify an image" as if that were a defect in the ROM — is replaced by "a slot has a destination, and twenty payloads can share one" |

## 6. `run-rom.sh`

Third session untracked, and the audit is right that this is now the most stale item in the project.
It is not mine to decide: the file is the owner's, it is untracked, and the standing instruction is
not to commit it. Two clean options, both one line of work once chosen:

* retitle the header from "the project's final objective" to "optional external validator" and track
  it — the file is correct in every other respect, including the ROM and app checks;
* delete it, since every other tool in the repo is a `python3 tools/…` invocation and this is the
  only shell script.

## 7. Next

1. **Resolve the `0x800fb264` contradiction.** Re-decode `FUN_8003287c` with the harness rather than
   by eye — it executes the guest's own instructions, so the address computation can be *observed*
   instead of inferred. That is the one tool this question has not been asked with.
2. **Then** ask whether `FUN_800327ec` ever sees a record pointing into R4.
