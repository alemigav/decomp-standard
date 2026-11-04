# M180 — the counts are derived, not hand-edited

Seven numbers describe the gate suite: total suites, total cases, the runnable pair, the
cartridge-gated pair, and the audit suite's own case count. They are quoted in **four files in twelve
phrasings**. Until now every milestone re-derived them by hand and edited each site, and in one arc that
produced three separate propagation errors:

* `273` still in the README after the suite had grown to 297;
* `129` written where the gated total was `133`;
* `177` written where the runnable tier was `178`.

None of those was a wrong claim about the cartridge. All three were clerical, and all three were caught
by reading output rather than by a gate.

## 1. What it does

`tools/counts.py` executes `tools/acceptance.py` — the same `SUITES` list the runner executes — and derives
the seven numbers. Then it checks all twelve quoting sites against them:

| file | sites |
|---|---|
| `README.md` | the `N-case verification suite` headline, the `X suites / Y of Z cases` command comment, `audit_gates.py  # N/N`, `N of M cases cannot run` |
| `docs/handover.md` | `# N suites, M cases`, `audit_gates.py  # N/N:`, `N of M cases**. Their enforcement`, `vouch for those N cases` |
| `tools/ci.sh` | `# N suites, X of M cases)` |
| `.github/workflows/acceptance.yml` | the `PASS` and `SKIP` summary pair, and `all N suites / M cases` ×3 |

The audit suite's own count is the seventh number and the one that actually drifts — `26 → 30 → 35 → 37 →
39` across five milestones — so it is derived on the same footing as the rest.

## 2. The rule that makes it a gate

**A phrase that disappears is a failure.** A checker that only compares numbers passes silently when the
line it was checking is deleted, which is this project's signature defect in its purest form. Every check
therefore requires its pattern to be present exactly the expected number of times; a missing phrase fails
with `phrase found 0x, expected 1 — a deleted phrase is a failure`.

`--self-test` proves it on a **copy of the real files** rather than a template, so the test cannot drift
from the phrasings it protects. Four cases: an untouched copy agrees; a wrong total in the README is
caught; a deleted phrase is caught; and **one wrong value among the three identical `all N suites / M
cases` lines in the workflow is caught**, which a `count == 1` check would have missed.

## 3. It paid for itself inside the milestone that added it

Registering the suite changed the totals, and the gate immediately failed eleven of twelve sites. Then the
counts were derived again after the audit suite grew `37 → 39`, which changed them a second time — the
exact mistake the tool exists to stop, made twice while building it, and caught both times by the tool.

That is the whole argument for it: the author of the gate made the same clerical error twice in twenty
minutes, and the gate caught it twice.

## 4. The seventh audit-environment gap

`tools/audit_gates.py` copies a fixed list of files into each audit's throw-away tree. `README.md` was not
on it, so the counts self-test raised `FileNotFoundError` inside the audit environment — and the audit
recorded that as a **detection**, because its verdict is an exit code. A missing input and a caught
mutation look identical from an exit code.

This is the sixth environment gap in this arc (`build/elfs`, `src`, `.github/`, the shell interpreter,
`docs/MILESTONES.md`, and now `README.md`) and the first that was *silently counted as a success*. Fixed by
adding it to `COPY_FILES`, and the two new audits were then hand-verified to fail on their intended case:
the derived-total mutation fails 7 of 12 checks, and the neutered-phrasectomy mutation fails exactly
`a phrase that disappears is caught` (3/4) — not an exception, not a missing file.

## 5. What it does not cover

* Numbers in the milestone notes are **historical and frozen**; the note for M178 says 297 cases because
  that was true at M178. Only the four living files are checked.
* It cannot tell whether a number is *right* — only that every site agrees with the registry. The registry
  is kept honest by the ratchet (`--write` required, and a decrease refused), and the suite's actual case
  counts by `acceptance.py` itself.

## 6. Gates

New suites `counts self-test` (**4**) and `counts (repository)` (**12**). Audit **37 → 39, 0 vacuous**. The
ratchet refused the increase until `--write`, as designed.

Repository is **32 suites / 344 cases**, of which **12 suites / 150 cases** are cartridge-gated, so the
runnable tier is **20 suites / 194 cases** — all seven numbers now derived, and asserted in twelve places.
