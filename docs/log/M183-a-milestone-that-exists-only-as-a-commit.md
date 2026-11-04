# M183 — a milestone that exists only as a commit is refused

While landing M182 I needed the `M181` row as an anchor and found there wasn't one. The verifier had been
committed with a contract, a tool, a suite and three audits — and **no record of itself**. Nothing noticed,
and the reason is structural: `milestone_index` requires every number **from 0 to the highest** to be a row,
a note or a named gap, so a milestone *at or above* the highest number is invisible to it. A trailing
milestone with no record cannot fail a check that only looks backwards from the highest.

That is the failure mode this gate closes.

## 1. What it checks, and why it is two-sided

Every milestone number that appears in a **commit subject** must be a row, a note, or a named gap. Two
cases, and they catch opposite mistakes:

| case | catches |
|---|---|
| every `M<n>` in a commit subject is a row, a note or a named gap | a milestone landed as a commit with no record — **the M181 shape** |
| the commit fixture is within one milestone of the record | a record that grew without the commit list being re-seeded, i.e. the gate asleep |

The second exists because the first is only as good as its input. If the fixture silently stops being
regenerated, the accounting case keeps passing over an ever-older list — a gate that cannot fail, which is
the defect this project keeps finding.

## 2. Committed, never read from git at check time

`fixtures/milestones/commits.json` holds the commit subjects that name a milestone. It is a fixture for the
same reason `fixtures/milestones/gaps.json` is one, and the reason was already written down in this tool:

> never read from git at check time, because a CI clone is shallow.

A check that shelled out to `git log` would fail on a runner for an environmental reason and prove nothing
about the record. `--seed-gaps` now rebuilds both fixtures; the check is pure file I/O.

**The one-milestone lag is deliberate and stated.** A milestone's row is written *before* its commit exists,
so the fixture is legitimately one behind while a milestone is being landed — requiring equality would fail
on every milestone in progress. The cost, named rather than hidden: a landing that skips the re-seed is
caught at the **next** milestone, not the same one.

## 3. What it contains, measured

**109** distinct milestone numbers across **210** commit subjects, highest **182**, and **none
unaccounted** — so the gate passes on the current record, and it would have failed on M181 when it landed,
because `M181` was in a commit subject and in no row.

Live check with a fabricated commit: injecting `M9999: a milestone landed with no record` produced

```
FAIL every M<n> in a commit subject is a row, a note or a named gap (110 numbers, max 9999)
     — commits with no record: [9999]
FAIL the commit fixture is within one milestone of the record (commits reach 9999, the record reaches 182)
```

Both legs fire, and the accounting case names the number rather than reporting a count.

## 4. The bug I put in it first

The freshness case originally required `max(committed) == highest`. That fails on **every milestone in
progress**, because the row is added before the commit — it would have blocked this very landing. Recorded
here rather than quietly fixed: a gate whose first act is to fail on the normal workflow gets disabled by
the next person, and then it is not a gate.

A second, smaller self-inflicted error: renaming the case label broke the self-test's own lookup
(`verdict(check(d), "the commit fixture is current")`), which is the self-test catching a refactor that
would have silently disabled a case.

## 5. Gates

`milestone index (repository)` **8 → 10**, `milestone index (synthetic)` **9 → 11** — two new cases each,
and the synthetic beds are the two shapes: a commit with no record (M181) and a fixture two landings stale.
Audit **42 → 44, 0 vacuous**: the accounting leg is aimed at a synthetic bed because a real record has
nothing unaccounted, and the freshness leg at a bed whose fixture is deliberately stale. Both fail on their
intended case and name it.

Ratchet refused `42 → 44` and the two milestone-index counts until `--write`; counts derived and asserted in
twelve places. Landed through the verifier: PASS, admission **44/44**, 0 vacuous.

Repository is **33 suites / 367 cases**, of which **12 suites / 162 cases** are cartridge-gated, so the
runnable tier is **21 suites / 205 cases**.
