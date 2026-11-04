# M200 — the pool's classes, pinned from the data

Three sessions of prose about "the pool's four key classes" ended without a gate, so this milestone makes
the mapping a thing the suite checks rather than a thing the notes assert.

## The correction that made it possible

The class tag is `(key >> 14) & 3`, and **it is not the section index**: the four `SND_POOL` sections are
tagged **0, 3, 1, 2** in file order. "Four classes" and "four sections" had been used for each other since
M188, which is why the counts kept not lining up. The sections are storage — 2025 / 241 / 3 / 326 records,
shaped 32–56 / 16 / 3×1032 / 36–72 bytes — while the *roles* are the six lists a `SND_PROJ` record carries.

## What the gate pins

- **data:** the six lists hold `[2027, 169, 736, 290, 65, 566]` distinct keys and draw on tags
  `[[0], [0,3], [0], [0,3], [3], [0,1,2,3]]`. List `[2]` and `[4]` are sample-tagged only; list `[6]` is
  tag-3 only (the 241 fixed-16-byte records).
- **code:** `FUN_800a86a0` walks the pool chain (key at `record+4`, accumulating offset, `-1` terminator)
  and dispatches list `[4]` → the cache at `0x8014e1e0`, list `[5]` → `0x801521f0`, and list `[6]` →
  `0x80152a00`, the only one whose call also passes the `u16` at `+10` — **the rate**, not a length (corrected since).

## Two mutations, both vacuous first time

`& 7` is behaviour-identical to `& 3` for the tag values that occur, and deleting one of two needle checks
leaves the other satisfied — so both mutations left the suite green and the audit said **VACUOUS**, twice.
Re-aimed at the mechanism (a constant tag, a needle that cannot be in the source), the audit is
**50/50, 0 vacuous**. That is the second time in this arc that a mutation was aimed at the wrong thing and
the audit caught it; the rule is that a mutation must change the *outcome*, not the spelling.

## What is still not established

The *names*. Cache A is fed by sample keys and cache C by tag-3 keys with a length, which narrows them to
"the sample-keyed cache" and "the rate-keyed cache over the 16-byte class" — but nothing yet says what those
16-byte records are, and cache B is fed by a mixed list. No name is claimed here.

State: file table **91/91**, audit **50/50**, counts **36 suites / 458 cases** (22 / 218 runnable without the
cartridge), ratchet re-baselined.
