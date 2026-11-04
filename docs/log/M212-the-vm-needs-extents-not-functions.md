# M212 — the VM needs corrected extents, not new functions

M211 left one number that looked like a to-do list: **79 of 138 dispatch-table handlers are not inside any
function body**. The obvious reading — "the corpus is missing 79 functions" — is wrong, and this milestone is the
measurement that says so.

## 1. What the bytes say

`tools/handler_region.py` → `manifests/handler_region.json`, 138 distinct handler addresses for 141 table
entries:

| classification | handlers | meaning |
|---|---:|---|
| `function_body` | **59** | the handler lies inside a range `fixtures/decomp/ranges.json` already claims |
| `fragment` | **76** | ends at a `jr ra` + delay slot, but has **no frame setup** at the handler address: a dispatch target inside something larger |
| `code_outside_body` | **0** | a prologue whose delay slot restores it — none |
| `unresolved` | **3** | no `jr ra` in the window, or the extent would cross into a known body |
| **words recovered** | **4 238** | the extents of the 76 fragments, each ending at a verified `jr ra` |

And then the number that changes the plan: walking **backwards** from each fragment to the nearest frame setup,
bounded at 512 words, finds an entry for **all 76** — and they sit behind only **21 distinct prologues, all 21 of
which are already function starts in the corpus**. An out-of-body handler touches `sp` nowhere in its extent, so
"no prologue here" is the code's shape, not a mis-parse.

**So `future_function_entries` is 0, and that is the finding.** Ghidra found every function the VM needs; its
*extent* for 21 of them stops before the handler code. A corpus rebuild would gain nothing by seeding 79 new
functions and everything by correcting 21 boundaries. The artefact carries `region_entry` and
`region_entry_in_corpus` per fragment so the claim is inspectable rather than asserted.

## 2. The advances, from the stores

The registry's `advances` came from `walk_stream`'s dataflow; the bytes agree, and where they do not, the bytes
win:

| opcode | measured | instruction |
|---|---|---|
| `0x09` | **1** | `lw r2,0x1c(r4)` `0x8006dce0` → `addiu r2,r2,1` `0x8006dcec` → `sw r2,0x1c(r4)` `0x8006dcf4` |
| `0x26` | **6** | `lw` `0x8006e7a8` → `addiu r2,r2,6` `0x8006e7bc` → `sw` `0x8006e7c0` |
| `0x13` | **4**, or **14** | `lw r7,0x1c(r10)` `0x8006e280` → `+4` `0x8006e290` → (case scan) `+2` `0x8006e2f8`, `+6` `0x8006e310`, `+2` `0x8006e320` → `sw` `0x8006e32c` |
| `0x0d`, `0x1b` | **6**, plus a variable arm | `addiu r7,r7,6` `0x8006de50` / `0x8006df00`, with the loop-count arm folded elsewhere |

So M157's "`0x09` and `0x26` sizes unexplained" is retired — both have a store-reachable constant — and `0x13`'s
published 4 is the fall-through path while 14 is the case-table skip, which is why the registry models it as a
variable path rather than a constant.

**A measurement I threw away.** A forward scan *without* extents reported **103 handlers with more than one
advance value**, which would have been a spectacular finding and is an artefact: with no end bound the window
runs into the neighbouring handlers and collects their stores. Extents had to come first; they did.

## 3. The gate

Twelve cases: the artefact parses with no duplicate key; all 138 distinct handlers present exactly once; every
extent word-aligned, `jr ra`-terminated, and touching no stack pointer; every `code_outside_body` restores its
own frame and **no out-of-body handler has one**; every `unresolved` states why; every fragment names its frame
setup; and the 21 prologues equal the set the corpus already has. Plus: the committed file equals a fresh
derivation.

Two mutations, both at the **artefact** rather than the tool — mutating the tool only trips the staleness case,
which proves the file is old, not that the claim is load-bearing. Losing one fragment's `region_entry` fails
"every fragment names the frame setup behind it" (`1 without`); flipping a prologue used by exactly one fragment
fails the census (`20 prologue(s), and 21 known`) — a *shared* prologue would have changed nothing, which is why
the anchor is the single-use one.
