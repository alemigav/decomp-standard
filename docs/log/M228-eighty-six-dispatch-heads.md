# M228 — eighty-six dispatch heads, and the queue entry that has no valid extension

M226 found a table dispatch by hand. M227 found that the extent queue wanted to merge such a region and called
one entry unsafe, guessing that it had swallowed "a leaf function the walk sailed past". Both questions have
the same answer, and it is a class, not two anecdotes.

## 1. The shape, scanned for

```
sltiu vX,vY,K      the bound
...  lui + addiu   the table's address, built with a sign-extended immediate
...  lw vZ,0(vW)
     jr vZ         the dispatch
```

Scanning stage-2 for that shape — complete shape required inside a 12-instruction window, and the `jr` must
not be a return through `ra`/`fp` — finds **86 heads with 86 distinct tables**:

| | |
|---|---|
| heads / tables | **86 / 86**, bounds from **1** to **114** |
| heads called by a `jal` | **37** |
| heads that are Script VM handlers | **3** — `0x6e` (`0x8006fc5c`), `0x3e` (`0x80070120`), `0x36` (`0x80071180`) |
| heads that are corpus function starts | **80** |
| tables not in this image | **1** — `0x8010b2bc`, bound 17, all entries zero (runtime-filled) |

So this is not a quirk of the script VM: **83 of the 86 are the game's own private dispatches**, and a fifth
of the function population ends in a `jr` through a table. Every "is this extent one function?" question
about them is really "is this region a head plus its arms?", which is why the same confusion produced M226's
"runtime-filled table" and M227's "unsafe merge".

The one BSS table is named rather than folded in: that head's arms are supplied at run time, and no extent
claim about them can come from this image. It is also the only place in this work where the *shape* of M226's
wrong inference is actually true — for a different head, at a different table.

## 2. The queue, decomposed

Every queued merge is now one of three things, and the census says which:

| entry | shape | swallows |
|---|---|---|
| `0x8006e534` | merge | **7 `table_arm`s** — exactly the 7 entries of table `0x800b9540` |
| `0x80071180` | merge | **5 `table_arm`s** — exactly `0x36`'s five arms at `0x800b98e0` |
| `0x80072acc` | merge | 2 handlers |
| `0x80073018` | merge | 1 handler |
| **`0x80071744`** | merge | **1 `dispatch_head` + its 5 arms + 1 `branch_target`** |
| the other 16 | **extension** | nothing |

Two arm-family merges and two handler merges are the queue doing what it says: folding a table's arms into
the function that owns the table. `0x80071744` is not.

## 3. The unsafe entry has nothing to extend

`0x80071744`'s corpus body already ends at **`0x8007179f`**, and the very next word is **`0x800717a0`** —
which is not a leaf the walk sailed past. It is:

* a **corpus function start** in its own right (`0x800717a0..0x800717db`),
* the target of **7 `jal`s** (`0x80071370`, `0x80071410`, `0x800714bc`, `0x8007157c`, `0x80071634`,
  `0x800716d8`, `0x80071764` — every one of them inside the function that precedes it),
* a **dispatch head** with its own table at **`0x800b98f8`**, five entries, immediately after `0x36`'s table
  with a zero word between them,
* and the code that branches to `0x8007188c` on bit 7 of its index.

So the correction's requested `last_end` of `0x80071b3b` is simply too far: **the function already ends
exactly where the next called head begins**, and there is no valid extension. The verdict is `drop`, and it is
the only one of the 21.

**M227's two readings of this entry are retracted, and both were mine.** "A leaf function the walk sailed
past" — it is a dispatch head that is also *called*, and the frame-setup criterion the queue uses could not
have seen it either way. And "`0x8007188c` is referenced nowhere in this image" — it is the target of
`bne v0,zero,0x8007188c` at `0x800717b0`. The `unreferenced` class was an artefact of an incomplete
reference set: M227's audit counted `jal` targets and 4-byte pointers, and not **branch targets**. Measured
with all three, the class is **empty across all 22 swallowed starts**; the 22 are 14 arms, 3 handlers, 1 head,
1 branch target, and the rest duplicates-by-count.

## 4. What this changes

* `extent_audit.json`'s reference classes are now `handler`, `dispatch_head`, `table_arm`, `branch_target`
  with an **orthogonal `jal_sites` count**, because safety turns on being *called*, not on how the address is
  named. Conflating the two is what produced the wrong label.
* Its verdicts become **20 `safe` + 1 `drop`** — a sharper statement than "20 safe + 1 unsafe", because the
  one entry is not a correction needing care; it is a correction with nothing to correct.
* `manifests/dispatch_heads.json` is the class, and it is the artefact to consult before any future extent
  claim: a start that appears in one of the 86 tables is an arm, and an arm belongs to the head that owns the
  table.

Nothing in the decoder moved. No advance, no count, no trace.

## 5. What this does not claim

* **What a head dispatches on.** The shape fixes the index; what the arms *mean* is each handler's own
  question, and the Script VM's were answered for one of them in M226.
* **That the shape is sufficient.** `sltiu`+`lui`+`jr` is a necessary condition: a head whose "arms" are data
  would look the same. The census reports what it found, and the 3-in-86 handler fraction is the check that
  it is not simply matching everything.
* **The 80 heads that are not script handlers.** They are counted and located, not explained — this
  milestone needed them only as a class boundary.
* **`0x8010b2bc`'s arms.** Zero in this image.

## 6. Gates

`dispatch heads (cartridge)`: **9 cases**, new suite. Three mutations, all proven in a throw-away copy: the
bound read one too large, the table address built with an **unsigned** immediate (the M226 error, as a
mutation), and the `jal`-site count discarded. `extent audit` is **13 cases** now, with its own mutation
re-aimed at the `jal_sites` count after M227's class names disappeared — the anchor lint caught that one in
0.04 s before any suite ran.

`all 61 runnable suite(s) pass (871 cases)`; `gate audit 124/124`, 0 vacuous.
