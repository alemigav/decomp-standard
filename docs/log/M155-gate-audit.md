# M155 — the gate audited: three checks were vacuous, and two of my audit's own mutations were too

Three defects in three milestones had the same shape — a check that could not fail for the right reason — so the
gates are now audited mechanically. `tools/audit_gates.py` builds a throw-away copy of the tools, fixtures and
docs, **disables one mechanism**, runs the same command `acceptance.py` runs, and requires a failure. A check
that still passes is reported **VACUOUS**, and the audit exits non-zero.

## 1. First run: 3 of 10 audits reported VACUOUS

| vacuous check | why it could not fail | fix |
|---|---|---|
| `walk_stream`: *name follows the chosen size* | no case exercised the **single-advance** path against a second PlayStation variant: every naming case used the two-advance path, so the line could be deleted | a second synthetic table puts `0x26` with **one** advance of 4, which must be named `Calc2` — mutating the line now fails |
| `cfg_reach`: *block returns no longer stop the walk* | the check only counted blocks; the survey seeds every record start, so pops were irrelevant | see §3 — the case is now a **margin** that only the mechanism produces |
| `patch_text`: *a no-op replacement is accepted* | the self-test covered a missing anchor and a count mismatch, but never `old == new` — the guard was untested code | a case now applies an edit with identical old and new and requires the refusal |

## 2. …and two of my own audit mutations were vacuous, which the audit caught too

* **The pop mutation muted the wrong thing.** Disabling only the plain branch (`if False and st:`) left the
  *generous* branch firing, so the check still passed. The mechanism is `POPPERS`, so the audit now mutates
  `POPPERS = set()`.
* **The `patch_text` case accepted any `PatchError`.** With the guard disabled, a *later* verification raised
  instead, so the case passed for the wrong reason. It now asserts the message contains `identical` — i.e. the
  case names the guard it is testing.

Two vacuous mutations out of ten is a fair estimate of how often this class of mistake hides in test code
itself, and it is the reason the audit is worth keeping rather than doing once.

## 3. What measuring the mechanism revealed: pops do not affect plain entry reachability

With `POPPERS` emptied, entry-mode reach is **identical** — 1 117 starts either way:

| measurement | with pops | without |
|---|---|---|
| `--entry` (plain) | 1 117 / 5 738 = 19.5 % | 1 117 / 5 738 = 19.5 % |
| `--entry --generous` | 1 695 / 6 123 = **27.7 %** | 1 183 / 5 776 = **20.5 %** |

The explanation is structural: a pop returns to a continuation that **falling through the opener reaches
anyway**, so in a plain walk the mechanism adds nothing. It only matters when the stack is missing entirely —
which is exactly what the generous closure models. So the old claim *"block returns no longer stop the walk"*
was never meaningful, and the case now asserts that generous mode reaches **≥ 1.2× plain mode** — a margin only
the pop mechanism can produce (27.7 % vs 19.5 % passes; 20.5 % vs 19.5 % would fail).

## 4. The audit is now part of the gate

`acceptance.py` gained the suite **`gate audit (mechanisms disabled)`** — 10 cases, cartridge-gated because
five of the audited tools read the ROM. Cost measured: **26 s** for the whole gate, of which the audit is
~6 s, so the pre-commit hook stays usable.

**146 cases across 15 fixtures**, `ci.sh: ok`, 18/18 marker checks.

## 5. The ten mechanisms now proven load-bearing

| audit | mechanism disabled |
|---|---|
| walk_stream | cross-register advance fallback |
| walk_stream | advance scan replaced by a constant (lengths non-vacuous) |
| walk_stream | name from chosen size rather than list order |
| walk_stream | following an unconditional computed jump |
| walk_stream | GoSub table stride 2 |
| cfg_reach | block pops (`POPPERS`) |
| cfg_reach | reachability returning nothing |
| script_profile | the script heuristic's minimum command count |
| check_markers | a handover heading |
| patch_text | the `old == new` refusal |

## 6. What this changes about earlier conclusions

Nothing in the numbers, but a lot in their standing. The three defects that motivated this (M149's phantom
tail, M151's shared node budget, M152/M154's guard order) were all found by hand, late, after a headline number
had already been published. The equivalent failures are now found by running one command, before a commit.
The honest summary of this milestone is that **the gates were the least-tested part of the project**, and are
now the only part with a mechanical guarantee that they can fail.
