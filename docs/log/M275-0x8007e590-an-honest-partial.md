# M275 — 0x8007e590, an honest partial: three regions exact, the 113-word arm still open

This one did not come out. It is recorded because the *map* is now exact even though the code is not, and because two
subagent attempts died before writing a line — the second with an internal error — so the recovery was taken over
directly.

## 1. Where it stands

**95 of 229 words by offset**, 139 by content, 34 hunks, and my object is **5 words short** (224 against 229). Per
region, measured at the image's own addresses:

| region | words | identical |
|---|---|---|
| head `0x8007e590` | 14 | **14 / 14** |
| case 0 `0x8007e5c8` | 21 | **21 / 21** |
| case 1 `0x8007e61c` | 30 | 27 / 30 |
| case 2 `0x8007e694` | 5 | **5 / 5** |
| **case 3 `0x8007e6a8`** | **113** | **21 / 113** |
| case 4 `0x8007e86c` | 22 | 6 / 22 |
| default `0x8007e8c4` | 24 | 1 / 24 |

So the dispatch, the first arm (which the compiler made into a single block), and the five-word arm are **byte-exact**,
and the difficulty is entirely in three places: the 113-word arm, the 22-word arm, and the 24-word default. Naming
them per region is what makes the next pass cheap — a total of 95/229 says nothing about *where*.

## 2. What is pinned, and it is worth keeping

- **The struct is solved.** Every field offset came from the image's own accesses and is verified by a host
  `offsetof` check: `f0` 0, `f5`/`f6`/`f7`/`f8` at 5/6/7/8, `f2a` 0x2a, `f2c` 0x2c, `f32` 0x32, `f34` 0x34,
  `f36` 0x36, `f38` 0x38, `f66` 0x66, `f1a2` 0x1a2, `f1b4` 0x1b4, `f1b6` 0x1b6, `f1e0` 0x1e0, the `f1e8`
  union at 0x1e8, `f214` 0x214, `f21c` 0x21c, `f220` 0x220, `f22c` 0x22c, `f230` 0x230, `f25e` 0x25e,
  `f26f` 0x26f, `f2b0` 0x2b0.
- **One access is not a field.** The image reads a *halfword at 0x2e*, which lies **inside** the word at 0x2c, so that
  read has to be a cast (`*(u16 *)((u8 *)s + 0x2e)`) — declaring a field at 0x2e shifts every later offset by two and
  cost a whole iteration to find.
- **The control flow is resolved**: `switch (s->f7)` with bound 5; **case 0 falls through into case 1** and **case 2
  falls through into case 3**; case 3 duplicates an identical 47-word block in both arms of its `f8` test (the
  compiler emitted it twice, so the source has the statements twice); the default is a *real* 24-word block with a
  device-window test, a pointer comparison against a device register, and a `FUN_80077f30(b, b * 3 + 4, s)` call
  whose multiplier is visible in the `sllv`/`addu` pair.
- The measuring harness measures **per region**, which is the only reason §1's table exists.

## 3. What is *not* pinned

- The shape of the 47-word duplicated block: the field copies (`f1b6`/`f38` from `f32`, `f1b4`/`f34` from `f2a`,
  `f36` from the halfword at 0x2e), the two `-= 1800` decrements, and the `f1a2 + 1` counter are all identified, but
  their order and the exact local widths are not yet right — that is where 92 of the 113 missing words are.
- Case 4's nested device test: whether the source is `if (a && b)` or two nested `if`s. The image nests (M272's
  lever), and my first attempt at one nested form still reads 6 of 22.
- The default block's `if` structure around the pointer comparison.

## 4. Why this is recorded rather than parked

The project's precedent is M254, which landed a reconstruction at 27 of 98 "said in those words rather than rounded
up". The same applies here: the *map* is a durable artifact (the struct, the fall-throughs, the duplicate block, the
per-region diagnostic), and the missing part is one arm's statement order plus two small blocks. Nothing claims
otherwise: the probe corpus is untouched at **28 cases**, and the progress map does not list this function.

Two process notes worth keeping: a subagent was cancelled mid-run and its replacement died with an internal error at
nine turns, both before writing any C — so on a target this size the failure mode to plan for is *the agent never
starts*, not *the agent gets it wrong*, and a direct takeover with a per-region harness is the fallback that worked.
