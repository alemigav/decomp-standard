# M227 — the extent queue, audited: 16 extensions, 5 merges, and one that would eat a callable

M226 ended with a loose end it could only *state*: `0x36`'s `cmd+12` store sits outside its handler's Ghidra
body, and the fix "is queued" in `manifests/extent_corrections.json`. So this milestone asks the queue two
questions that its own note — *"21 functions whose extents must be extended so the Script VM's handlers fall
inside them"* — does not answer: **is it sufficient?** and **is it safe?**

Both answers are small, and one of them is a defect.

## 1. Sufficient — and needed for exactly three handlers

For each of the 138 distinct handlers, where does the `ctx+0x1c` write actually live? Attributed against
each handler's **own** extent as `handler_region.json` measured it:

| placement | handlers |
|---|---|
| inside the handler's own extent | **131** |
| only inside the extent a queued correction would give it | **3** — opcodes `0x01`, `0x0c`, **`0x36`** |
| no such store at all | **4** — opcode `0x03` plus M212's three `unresolved` |

So the queue **is** sufficient for the store dimension, and its necessity is tiny and enumerated: three
handlers out of 138. `0x36` is one of them, which is why M226 could measure its advance from the arms
instead and never need the correction. And the four absences are all explained: `0x03` writes no
`ctx+0x1c` because its destination comes from a record table through a `jal` (the one `dynamic` opcode
whose pc is a callee's return value), and the three `unresolved` handlers have no extent claimed for them at
all — a different state from "an extent that lacks the store", and now reported as one.

**The tool shipped a version of the answer that was wrong, and the note says so because it is instructive.**
The first version scanned forward from each handler to the end of its queued extent and attributed every
store it met, which made **74** handlers "own" a store belonging to a neighbour. That is M212's own recorded
defect — *"an unbounded forward scan reported 103 handlers with several advances — window leakage into the
neighbours"* — met a second time, by a tool written to audit the thing M212 produced. A window is not an
attribution. The second version attributes only against the handler's own extent, and a case asserts that
every "via correction" site lies **beyond** that extent's end.

## 2. Safe — except one entry, which would delete a callable function

A correction does not merely extend an extent. To reach its `last_end` it swallows every corpus function
start in between, so **16 of the 21 are plain extensions** (they swallow nothing) and **5 are merges**, 22
start addresses in all. Each swallowed start is then classified by how anything can reach it:

| how it is reached | count |
|---|---|
| `dispatch_arm` — no `jal` targets it, but it appears as a pointer in the image | 14 |
| `handler` — another opcode's handler; merging is the queue's stated intent | 3 |
| `jal_callable` — the target of a `jal` | **1** |
| `unreferenced` — no `jal` target and no pointer anywhere in this image | **1** |

`dispatch_arm` and `handler` merges are defensible: the piece is reachable only through a table, so folding
it into the function that owns the table is what the queue means. `jal_callable` is not — the entry
`0x80071744 → 0x80071b3b` would swallow **`0x800717a0`**, which is the target of a `jal` in this image
(there are 1 993 `jal` targets in stage-2). Applying that correction would delete a function other code
calls. So the queue is runnable **after an exclusion**, not as it stands:

* **20 of 21 may be applied**;
* **`0x80071744` needs a decision first** — either its `first_handler`/`last_end` is wrong, or `0x800717a0`
  is a genuine boundary inside a region the walk mistook for one function;
* and `0x8007188c`, in the same correction, is referenced **nowhere** in this image — no `jal`, no pointer.
  That is not a defect, but nothing here can say what it is, and the verdict says "apply with care" rather
  than pretending the question is settled.

## 3. What this changes

Nothing in the decoder: no advance moves, no count changes, `0x36` keeps the override M226 gave it (and now
the reason is sharper — the queue *would* reach its store, and it is one of the three where that matters).
What changes is that the queue now has a machine-readable verdict attached to every entry, published in
`manifests/extent_audit.json`, so the next Ghidra run can be scoped to the 20 entries that may be applied
and cannot silently merge a callable function.

The audit **consumes** `handler_region.json`'s classification rather than re-deriving it — 59 `function_body`
+ 76 `fragment` + 3 `unresolved` — which is the M220 rule (*measure with the reader every other case uses*)
and the reason a naive re-derivation would have reported a different fragment count: "no corpus body" and
"fragment" are different sets, and the fixture already had the right one.

## 4. What this does not claim

* **The corrected extents themselves.** Applying them needs a Ghidra run; this tool reads the queue and never
  writes it.
* **That a `dispatch_arm` merge is the best reading.** It is defensible — the piece is reachable only through
  a table — and it is not the same as proving one function owns it. The 5 merges remain a modelling choice.
* **What `0x8007188c` is.** No `jal` and no pointer in this image. The class exists so that the gap is named
  instead of counted as safe.
* **Anything about the 3 `unresolved` handlers' extents.** They have none claimed, which is M212's third
  class and not this milestone's to close.

## 5. Gates

`extent audit (cartridge)`: **12 cases**, new suite. Three mutations, each aimed at an outcome and each proven
in a throw-away copy: the word-grid alignment (whose absence is the tool's own first bug — revert it and the
store scan finds nothing), the attribution of a store found through a correction (call it the handler's own
and the "needed for exactly three" case fails), and the reference class (call a `jal`-callable function a
dispatch arm and the unsafe entry disappears).

One case had to be re-aimed after the first mutation run: *"the entries that would merge a jal-callable
function are named"* read from the committed file, so mutating the classifier only tripped the catch-all
equality case. It reads the fresh derivation now. That is the same defect M225 recorded — a case that reads
the artefact cannot see a change in how the artefact is derived.

`all 60 runnable suite(s) pass (855 cases)`; `gate audit 121/121`, 0 vacuous.
