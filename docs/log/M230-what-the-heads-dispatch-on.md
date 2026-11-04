# M230 — what the eighty-three non-script heads dispatch on

M228 counted 86 dispatch heads and said only that they dispatch through a table. This answers the next
question per head: **what is the index, traced to its source.** 86 heads, of which 3 are Script VM handlers
(`0x6e`, `0x3e`, `0x36`) and **83 are the game's own** — and it is the 83 that were asked about.

(To be precise about a number I have quoted loosely: M228's *80* was "heads that are corpus function
starts". The non-script count is **83**; the two differ by the three handlers, which are corpus starts, and
by heads that are not.)

## 1. The answer, with the number that is missing

| source of the index | all 86 | the 83 non-script |
|---|---|---|
| a **field of the context** — `[ctx+0xoff]` | **19** | 19 |
| an **incoming argument register**, used directly | **16** | 15 |
| a **field of the command stream** — `u8/u16[cmd+k]` | **7** | 5 |
| a **constant** | **3** | 3 |
| a **global** — a `lui`-built absolute address | **2** | 2 |
| a field of a **pointer held in an argument** | **2** | 2 |
| `local` — the enclosing function set it, before the body boundary | **35** | 35 |
| `unknown` | **2** | 2 |

So **46 of the 83** name their source, and **37 refuse**. The refusals are not a shrug: 35 of them are
`local`, and the reason is structural and stated in each entry — the head is **inlined inside a larger
function**, so the register it indexes by was written before the corpus body boundary, and a trace that
started earlier would be attributing the *preceding* function's dataflow to this one. The two `unknown` are
traces that ran out of window. The count is published because a percentage that hides its refusals is worse
than a smaller number that does not.

The shape of the answer is informative in itself:

* **19 dispatch on the context.** These are table-dispatched state machines over a structure the function
  was handed, indexed by a field of it — a `switch` over a mode that lives in the object.
* **16 take an argument as the index.** That is what a C `switch` on a parameter compiles to when the cases
  are dense: no load, no mask, the caller's value straight into the table. The two bound-44 tables are the
  clearest examples — 44-entry tables indexed by `a1` on entry.
* **Only 5 of the 83 read the command stream** (`u8[cmd+k]`), versus 7 when the Script VM's two heads are
  included. So the command-stream shape M226/M229 found is *not* the common case: the game's private
  dispatch is mostly over its own state, not over a script.
* **2 read a global** and **3 are constant** — a constant index is a dispatch that could have been a direct
  call and was not, which is worth knowing exists.

## 2. The worked example is the validation

`0x36`'s own trace reproduces, mechanically, what M226 established by hand:

```
source: command_field, u16[cmd+4], width 2
transform: ["srl 8"]
```

That is `lhu a1,4(s0)` → `srl a0,a1,8` → `sltiu v0,a0,5` → the table at `0x800b98e0`. Getting that right
required the trace to *chase the base* (`s0` is `lw s0,0x1c(ctx)`, the command pointer) and to test the
context pointer **after** the def lookup — because `0x36` writes `srl a0,a1,8` and then tests `a0`, so `a0`
is no longer the context pointer at the point of the `sltiu`. The first version tested `ctx` first and called
`0x36` "an argument"; that bug is now one of the three mutations.

## 3. Three defects of my own, all as mutations

1. **The ctx test came before the def lookup** — so any head that reuses `a0` as its index was called "the
   context pointer used as an index". `0x36` is exactly that head.
2. **`lh` was missing from the load set** — so halfword reads fell to "unhandled form", which is how `0x36`
   read as `unknown` after the first fix. `0x36` *is* a halfword read.
3. **A widening that made it worse** — following the index into the 0x100 bytes behind the body start turned
   6 heads out of `argument` and resolved nothing, because a write to `a0` before the body belongs to the
   previous function. It was reverted, and the note says why rather than leaving the option untried.

And one mutation that had to be re-aimed: dropping `lh` from the width table alone makes the tool raise
`KeyError`, and a mutation that crashes proves only that the code is fragile — the M226 lesson, met again.
It is aimed at the load *set* now and fails cleanly.

## 4. What this does not claim

* **What an arm does.** This is the index, not the meaning. A `command_field` index is not proof of a script
  opcode: an opcode sub-field and a data byte read through the same pointer are identical here.
* **The 35 `local` heads.** Reported with their reason, not guessed. Resolving them needs the enclosing
  function's dataflow, which is a different tool with a different window rule.
* **That the classes are exhaustive.** The two `unknown` are traces that ran out of window; a longer window
  is the fix and it is deliberately not taken.

## 5. Gates

`head index (cartridge)`: **9 cases**, new suite. Three mutations, each proven in a throw-away copy: the base
chase removed (every pointer read becomes `local`), the ctx test ordered before the def lookup (`0x36` reads
as an argument), and `lh` out of the load set (halfword reads go unhandled). `dispatch heads` 9, `extent
audit` 14, `handler region` 13 — all unchanged.

`all 62 runnable suite(s) pass (881 cases)`; `gate audit 127/127`, 0 vacuous.
