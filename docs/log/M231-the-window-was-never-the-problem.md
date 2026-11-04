# M231 — the window was never the problem: 35 `local` heads, and a fold that was too narrow

M230 left 35 of 83 non-script heads as `local`, with a stated reason: the head is inlined inside a larger
function, so its index was set before the corpus body boundary, and resolving it needs the enclosing
function's dataflow. The plan for this milestone was therefore to extend the window rule.

**That premise was wrong, and one measurement settled it before any code changed.** For the first fourteen
`local` heads, the index register's nearest definition is *inside the body already* — delta from the body
start between −4 and −244 bytes, and **zero function starts between the definition and the use**, 14 of 14.
The window was never too small. What was too small was the set of **forms** the fold accepted: it handled
`lui` + one `ori`/`addiu`, and the game builds its globals three other ways.

## 1. What was actually missing

| form | example | heads |
|---|---|---|
| a **bare `lui`** as a complete base, low half from the displacement | `lui v0,0x800f` then `lbu v1,-28100(v0)` = `0x800e923c` | 13 |
| **two constants added**: `lui`+`addiu` then a second `lui` + `addu` | `lui v0,0x800c` `addiu v0,v0,30384` `lui v1,0x0002` `addu v0,v0,v1` then `lbu` | 15 |
| a chain **four links deep** — my guard was `depth > 3` | `s2 ← addiu s2,v0,7826`, `v0 ← …`, `lui` | 2 |
| base of **`sp`** — a stack slot, and it always has a definition (the frame adjustment), so it could not wait for the "never written" test | `lbu v1,0x20(sp)` | 1 |

After the fold: **`local` 35 → 4**, plus one new class (`stack_field`) and `global` **2 → 32**.

| source | all 86 | the 83 non-script |
|---|---|---|
| a **global** | **32** | 32 |
| a field of the **context** | 19 | 19 |
| an **incoming argument** register | 16 | 15 |
| a field of the **command stream** | 7 | 5 |
| a **constant** | 3 | 3 |
| a field of a **pointer held in an argument** | 2 | 2 |
| a **stack slot** | 1 | 1 |
| `local` | **4** | 4 |
| `unknown` | 2 | 2 |

**80 of 86 named, 6 refused** — against 49 and 37 last milestone.

## 2. The answer changes shape, which is the point

M230 concluded that "the game's private dispatch is mostly over its own state, not over a script". With the
fold fixed, the dominant source is a **global**: 32 of 83 heads index a table by a byte read out of a
module-level array (`0x800e8609`, `0x800e860a`, `0x800e861d`, `0x800e8ca8`, `0x800e9182` … many of them
adjacent, i.e. fields of the same few structures). So the game's dispatch is mostly over **global state** —
a mode or state byte in a module's own data — with a context field second at 19 and a caller's argument third
at 15. The command stream, at 5, is the rarest of the named sources.

That is a materially different characterisation from the one last milestone published, and the correction is
the substance of this one.

## 3. The six that still refuse

* **4 `local`** — three index off `a2` or `s2` whose definitions are `lw` chains through a base this trace
  cannot resolve, and one off `v1` at `+0x1818`; each names its register and offset.
* **2 `unknown`** — the index register is written before the head's own code (`v0`, `s2`), so the trace
  refuses rather than reaching into the preceding function.

They are published with their reasons. Six out of 86 is a small enough residue to be read individually, which
is the standard this milestone set: **a percentage that hides its refusals is worse than a smaller number that
does not.**

## 4. What this does not claim

* **That an index class is a meaning.** A `global` index is a byte in a module's data; *which* byte and what
  the arms do is unchanged by this milestone.
* **The 6 refusals.** Not guessed, and the two `unknown` would need the enclosing function's dataflow — the
  work the plan for this milestone originally described, and now correctly scoped to 2 heads instead of 35.
* **That the fold is complete.** Four new forms were added here because 35 heads needed them; a fifth form
  could exist, and the `local`/`unknown` counts are how a reader would notice.

## 5. Gates

`head index (cartridge)`: **9 cases**, unchanged in shape — the partition case, the `command_field` offsets,
the 0x36 worked example, and the two refusal buckets, all re-derived. The mutation set is unchanged and still
passes: the base chase removed, the ctx test ordered before the def lookup, `lh` out of the load set. No
anchor moved, because no *behaviour* the mutations attack changed — the fold widened underneath them.

`all 62 runnable suite(s) pass`, `gate audit 127/127`, 0 vacuous.
