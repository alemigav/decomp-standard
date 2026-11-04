# M196 — the suite was slow because it recomputed, not because it was Python

The question put to me was whether the verification suite had outgrown Python and should partly move to a
compiled language. The answer turned out to be no, and the reason is worth writing down precisely, because
the instinct was reasonable and the measurement that answers it took one command.

Before: `tools/verify.py` could not finish inside a single interactive turn (the same command was killed
at ~7 minutes, twice), `tools/acceptance.py` took ~5 minutes, `tools/audit_gates.py` 3 m 37 s, and
`tools/file_table.py --check` ~31 s.

After, measured on the same machine: **`verify.py` 1 m 53 s**, acceptance **1 m 55 s** (1 m 07 s at
`JOBS=4`), the audit **58 s**, `file_table.py --check` **3.8 s**.

None of that came from a faster language. It came from two facts, both measured.

## 1. The profile, before anything was changed

`python3 -m cProfile -s tottime tools/file_table.py --check`, 35.6 s of wall clock:

| symbol | tottime | calls |
|---|---|---|
| `get`, the per-bit closure in `_parse` | **26.26 s (87.9 %)** | 37 795 369 |
| `len(payload)`, evaluated per bit inside it | 2.6 s | **130 564 153** |
| the `Counter` family | 2.25 s | 30 |
| `struct.unpack_from` | 0.06 s | 809 343 |
| zlib, four inflates | 0.001 s | 4 |

One function, added in M195, was 88 % of the most expensive gate in the repository. So the honest
description of the problem was never "Python is slow" — it was **130 million iterations of a loop that reads
one bit at a time in order to throw it away**.

## 2. The bit reader did not need to read the bits

`_parse` returns a bit *position*; the two cases it feeds assert how many clips overrun and how many land
within 8 bits of the end. Every field value it extracts is discarded. And the widths are constants, so a
block's length is known before any of its bits are read:

- selector `1` → 5 bits, no sample bits, up to 16 samples;
- selector `0` → 8 header bits, then 260 bits for each of `min(run, want - done)` samples.

So the cursor can advance arithmetically — **O(1) per block instead of O(260)** — reading only the 1, 7 and
4 header bits. The restatement is exact, and exactness has four requirements, each of which is a way to be
silently wrong:

1. the readable limit is `min(guard + 1, 8 * len(payload))` — the original raises when `p > guard`;
2. the body consumes `260 * min(run, want - done)`, **not** `260 * run`;
3. clamping to the end instead of raising would turn every overrun into a landing;
4. the two bit orders differ only in header extraction, never in bit counts — which is why one fast path
   serves both.

The proof that the restatement is faithful is the two numbers it has to reproduce, and they came out
identical: **362/588** clips overrun and 3 land (MSB-first), **339/588** overrun and 0 land (LSB-first).
`file_table.py --check` went from 31 s to **3.8 s**, 87/87.

I had the rule wrong when I first wrote it down: I said "8 header bits then 260 per sample" for both
branches, which is true only for selector 0. A review of my own plan caught it before any code was written,
which is the argument for writing the equivalence down before writing the implementation.

## 3. It was also being computed thirteen times

Read from the source, not measured: `verify.py` ran `ci.sh` (→ `acceptance.py` → `audit_gates.py`, 217 s)
and then ran `audit_gates.py` **again** as its admission step. `file_table.py --check` was therefore invoked
**13 times** per verified run — once as a suite, once per audit mutation (six of them), twice over. Roughly
6 m 43 s of the ~9-minute run was the same deterministic scan of the same cartridge.

The audit still has to be graded last — that is the rule in `verify.py`'s own header, and it stays. What
changed is that `verify.py` now hands `--no-audit` through `ci.sh` to `acceptance.py`, which prints
`DEFERRED (graded by verify.py)` and skips that one suite. Deliberately **not** `SKIP (needs the
cartridge)`: that string means the cartridge is absent, it is counted as skipped in the summary, and
`ci_full.sh` greps for it to fail the full tier. A hand-off and a hole must not look alike.

## 4. The pool, and the gate that stops it lying

`JOBS` (default 1, capped at 4) runs the suites concurrently. The contract is that a run at `JOBS=4` prints
byte-identically to `JOBS=1` — order is not a courtesy, it is what makes the pooled run the same gate.

A scheduler can lie in ways a plain loop cannot, so `acceptance.py --self-test` grades the pool itself, six
cases: three lines for three suites **in registry order** (so a dropped result and a reordering are both
caught), a failing suite still named, exit-0-with-no-verdict is a FAIL, a death without a verdict is a
FAIL, an expected-count mismatch caught identically at one worker and four, and `JOBS` clamped so a pool
with no workers cannot report a green run. Three mutations in the audit aim at the three lies, and each was
probed directly rather than trusted to the exit code: dropped → 4 cases fail, reordered → 1, swallowed → 2,
**none of them by crashing**.

That last clause is not pedantry. My first version of the self-test indexed `l4[0]` unguarded, so the
"dropped result" mutation produced an `IndexError` — which the audit records as a detection, because it
judges by exit status. A crash and a caught mutation look identical from outside, so the cases now access
results through a guarded helper and fail as cases.

## 5. What became of the compiled-language question

Measured on this machine, 64 MiB in memory: a per-byte Python loop runs at **48 MB/s**; `bytes.count`,
`sha256` and `zlib` — C underneath — run at 3 243, 2 770 and 445 MB/s. So a compiled rewrite of a
Python-level byte loop can honestly buy 50-70×. That number is real and it is not what this milestone
needed, because the winning change removed the iterations instead of accelerating them.

It stays as a documented fallback, reopened only if all three hold: a single `file_table.py --check` is
still over 5 s, the profile puts the time inside a bit/byte loop rather than I/O or file globbing, and CI is
shown to have a compiler. It would be **C**, not Rust or Zig: `counts.py` already counts `.py/.sh/.c/.swift`
under `tools/`, and `t64info.c` + `t64_selftest.py` are the precedent (with the caveat that a gate which
SKIPs for want of a compiler is a gate that can be off by accident, and would have to say so loudly).

Three things would have to be paid for, and none of them is labour: `audit_gates.py` mutates the tools'
**source text** at literal anchors, so a compiled gate needs a rebuild step inside the audit;
`counts.py` and `ratchet.py` `exec()` `tools/acceptance.py` to read the registry; and `README.md` promises
"plain Python 3, stdlib only, nothing to compile".

## 6. The M195 case had no audit, which was the wrong way round

The suite's most expensive case was also the only one of its kind with no mutation aimed at it: all six
`file_table.py` mutations predate M195. Making it fast would have made the milestone's biggest case its
least-audited one. The mutation added here removes the block body (`p += SAMPLE_BITS * m` → `p += 0`) and
moves both pinned verdicts; probed directly, the mutant scores 85/87 with the MSB count at 45/588 and the
LSB count at 47/588. Aiming at the guard instead would have been **vacuous** — no clip is over 512 KiB, so
the guard never binds and removing it changes nothing.

## 7. One defect found while measuring

`tools/ci.sh` said "10 of 34 suites, 212 of 433 cases". The case count was right and the suite count was
not: a clone runs **21** suites, and it now says 22 of 35. The reason it survived is mechanical — the
figure sat across a line break, so `counts.py`'s pattern matched the case numbers on the continuation line
and never saw the suite number. The sentence is now on one line and the pattern pins all four figures
(`22 of 35 suites, 218 of 443 cases`), which is why the comment says so.

## 8. State of the tree

`file_table.py --check` 87/87 in 3.8 s; acceptance 35 suites / 443 cases; **audit 48/48, 0 vacuous, 0
broken**; `JOBS=4` byte-identical to `JOBS=1`; counts derived (22 suites / 218 cases run without the
cartridge, 13 / 225 need it); ratchet re-baselined. Landed through `verify.py`: PASS with admission 48/48.
