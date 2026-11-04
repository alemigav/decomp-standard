# M229 — the last three unresolved handlers, and the rule that was missing

M212 left three handlers `unresolved` and said why in one line each: *"the extent from `X` would cross into the
Ghidra body `Y` before its `jr ra`."* They have been the only hole in the handler census for sixteen
milestones. M228's head census showed what they were, and this milestone is the rule:

> **a dispatch ends the extent.**

`handler_region.py` looked for the first `jr ra` from the handler and took that as the end. For a handler that
dispatches through a table, the `jr` it *actually* exits through is `jr v0` — and the `jr ra` the scan was
looking for sits **inside arm 0**, because arm 0 is laid out immediately after the dispatch and falls through
into the shared epilogue. So the extent ran into a body the corpus correctly attributes to an arm, and the
classifier refused rather than guess. Correctly — it just had the wrong terminator.

## 1. The three, and the two it also fixed

| opcode | handler | extent (words) | dispatch | table | bound |
|---|---|---|---|---|---|
| `0x23` | `0x8006e68c` | `0x8006e68c..0x8006e6df` | `jr v0` @ `0x8006e6d8` | `0x800b9540` | 7 |
| `0x2e` | `0x8006fb48` | `0x8006fb48..0x8006fba3` | `jr v0` @ `0x8006fb9c` | `0x800b95c0` | 5 |
| `0x40` | `0x8007199c` | `0x8007199c..0x80071a03` | `jr v0` @ `0x800719fc` | `0x800b9910` | 15 |
| `0x41` | `0x80071b94` | `0x80071b94..0x80071be7` | `jr v0` @ `0x80071be0` | `0x800b9990` | 7 |
| `0x81` | `0x800727b0` | `0x800727b0..0x80072823` | `jr v0` @ `0x8007281c` | `0x800b99b0` | 7 |

Two of the five (`0x40`, `0x41`) were not `unresolved` at all — they were **fragments**, and the rule reclassifies
them because their first `jr` is a dispatch too. So the census moves from *59 / 76 / 3 unresolved* to
**59 `function_body` / 74 `fragment` / 5 `dispatch_head` / 0 `unresolved`**, and 138 handlers are accounted for
with no hole.

Each of the five is a head with a bound, and four of them read their index out of the command stream in a
different way from `0x36` — `0x2e` uses `u8[cmd+1] - 1` (a **1-based** sub-opcode, so its six arms fill slots of
a five-bound table plus one), `0x81` and `0x41` use `u8[cmd+1]` with bounds 7, and `0x23` uses the **low byte**
of `u16[cmd+2]` after using its high byte to index a *halfword* table at `0x800f8c78` first. That variety is
what M230 is for; here it only matters that the head is a head.

## 2. Downstream: the store partition closes

`extent_audit.json` asked where each handler's `ctx+0x1c` store lives, and M227 reported four handlers with
none — `0x03` plus "M212's three unresolved". With the extents resolved, the partition is complete:

| placement | handlers |
|---|---|
| inside the handler's own extent | **132** |
| only through a queued extent correction | **3** — `0x01`, `0x0c`, `0x36` |
| **inside one of its own table's arms** — new class | **2** — `0x40`, `0x41` |
| no store anywhere | **1** — `0x03` |

The new class is the honest consequence of the rule: a dispatch head's extent now stops *before* the arms, so
its advance is written somewhere the head does not contain, and calling that "no store" was wrong. And the
last `none` is the one handler whose destination really does come from elsewhere — `0x03` reads its pc out of a
record table through a `jal` — so the class is now exactly the case it describes.

## 3. A window is not an attribution — twice in one milestone

Finding `0x40`'s store was easy (it is inside the first arm, `0x80071a04`). Finding **`0x41`'s** was not: its
seven arms all `j` to a shared continuation at `0x80071c3c`, and the store is at **`0x80071c94`** — 0x5c bytes
past the last arm. My first attempt scanned a fixed `target + 0x40` window and found nothing, which would have
been reported as "0x41 has no store" — a wrong answer produced by a number I chose.

So the arm scan **follows control flow** now (fall-through, branch, `j`, into `jal` return sites), and 0x41's
store is found with 27 reachable words. This is the second time in two milestones that a fixed window produced
a false negative or a false positive — M227's version scanned forward and made 74 handlers "own" a neighbour's
store — and the same one-line moral applies both times. The difference is that this time the tool says which
arm the store is in, so the claim is checkable.

## 4. What this changes

* `manifests/handler_region.json`: **0 unresolved**, a fifth class, and a `dispatch_jr` field on every head so
  a consumer can join it to its table.
* `manifests/extent_corrections.json`: regenerated — still **21 entries, 74 handlers, 14 063 bytes**. The two
  reclassified handlers were not in the queue's handler set, so the queue is unchanged, and its one `drop`
  verdict from M228 stands.
* `manifests/extent_audit.json`: the store partition above, with the new `store_in_arm` class.
* Nothing in the decoder: no advance, no count, no trace moved.

## 5. What this does not claim

* **That the rule is right in general.** It says a `jr` through a register that is not `ra`/`fp` ends the
  handler. For the five heads here that is measured against their own tables; a handler that `jr`s through a
  register for another reason would need its own argument.
* **The arms' extents.** They are corpus functions already; this milestone does not re-measure them.
* **`0x2e`'s six arms in a five-bound table.** The bound is 5 and the index is `u8[cmd+1] - 1`, so the table has
  five entries; whether a sixth value is reachable is a question about the *commands*, not the code, and the
  refusal is not resolved here.

## 6. Gates

`handler region`: **13 cases**, unchanged in shape — the class totals case now sees five classes, the
`unresolved` case sees none, and the queue case sees 74 handlers instead of 76. `extent audit`: **13 → 14**,
with the new arm case asserting that both `store_in_arm` handlers name their arm and their table.
`dispatch heads`: 9, unchanged. Both mutation sets still pass, and no anchor moved.

`all 61 runnable suite(s) pass (872 cases)`; `gate audit 124/124`, 0 vacuous.
