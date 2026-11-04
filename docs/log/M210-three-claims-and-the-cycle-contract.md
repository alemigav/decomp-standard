# M210 — three published claims corrected, and the landing unit becomes a cycle

Three small corrections, each of a different kind: a count that disagreed with its own artifact, a reading with
no gate, and a fixture with no producer — plus the policy change that makes batching admissible.

## 1. "15 distinct instruction lengths" was 17

`fixtures/scd/profile.json` has held **17** distinct advances (1, 2, 3, 4, 5, 6, 8, 10, 14, 16, 20, 22, 28, 30,
32, 38, 40) while README and both handover passages said **15**. The two missing values are **30 and 38**, and
they are not new knowledge: they are the *other* advances inside the handlers that take more than one, which M141
found (its own table lists `0x4e` with advances 2/22/30/38 and `0x2d` with 3/16/38). So M136's 15 was the count
of advances it published, not the count in the code.

Published as 17, with the reason; the retraction row is in the log's table; and `counts.py` now derives the
number from the profile and asserts the phrase in README and both handover sites, so it cannot drift again.

**That reason was wrong when first written and is corrected here.** I wrote that the 30- and 38-byte advances
"belong to the handlers that take more than one" — M141's claim, which M211 then measured and refuted: only
`0x0d` and `0x1b` carry more than one constant, and both are really `6` plus a variable. The two sizes arrived
because M141 corrected `0x69 ItemAotSet4p` (2 → 30) and `0x2d ObjModelSet` (3 → 38) against the PS1 table,
which is a different mechanism and the one the artifact supports.

## 2. The scheduler contract was a reading with no gate

Since M152 the project has said "a handler returning 1 runs again, 2 yields", and every reachability claim rests
on it. It had no case. It has one now, pinned by the interpreter's own shape in `src/stage2/FUN_8009b880.c`:
`} while (iVar1 == 1);`, `if ((iVar1 == 2) || …) break;`, and the frame pop
`*(undefined4 *)(puVar2 + 0x1c) = *(undefined4 *)(iVar1 + -4);`. Mutation: change the needle so the case can no
longer find the loop → it fails, which is what "the reading is still there" means mechanically.

## 3. `fixtures/decomp/images.json` had no producer

M205 committed the 36-image inventory by hand, which made it the only fixture in the tree with no generator —
exactly the artifact class that drifts silently, and the one the strategic plan's M0.2 asks for. `export_ranges.py`
gained `--write-images` / `--check-images`; the fixture is regenerated from `build/elfs/images.json` and a
cartridge-gated case requires the two to agree. Mutation: edit one extent in the committed fixture → the check
fails.

## 4. The landing unit is a cycle (policy)

`docs/VERIFICATION.md` said a milestone is not landed until ratchet/counts/verify are clean **on the commit that
carries it**. With 4–6 milestones per cycle that rule costs the same five minutes five times, for evidence that
was already established on the same code. The contract now says: **a cycle lands as one commit**, the three
checks run once on the tree that commit carries, and each milestone still owes its own gate and its own mutation
— what is batched is the re-running of everything, never the proving of anything.

For that to be admissible rather than convenient, the tree the verifier graded has to be identifiable:
**One flaw in that certificate, found by the first attempt to use it.** The hash included `git status` and
`git diff --cached`, so *staging the cycle's files invalidated the certificate* — the hook re-ran the full
suite on the one commit the certificate existed for, and the commit was still running when the turn ended. The
hash now covers content only (`git diff HEAD` plus each untracked file's bytes), which is invariant under
`git add` because content is what is being committed. The lesson is the project's own: a gate that is not
exercised in anger is not a gate, and this one failed on its first real use rather than in production.

`verify.py` now records a **worktree hash** (it recorded only a dirty boolean, which cannot distinguish "this
tree" from "some tree") and writes `build/verify-cert.json`. `tools/pre-commit.sh` skips the suite only when the
certificate's hash equals the worktree being committed, the verdict is `PASS` and the admission is clean; any
edit after verification re-runs the suite. `tools/hook_cert.py --self-test` grades the rule in six cases (no
cert, wrong hash, FAIL verdict, vacuous admission, missing cert, and a dirty-but-matching tree, which *must*
validate), and a mutation inverts the hash comparison to show the rule can fail.

## 5. Gates

`counts (repository)` gained the length assertion (two patterns); `cfg reachability` 6 → 7 (the scheduler
shape); `image inventory (cartridge)` 1 case; `hook certificate (repository)` 6 cases. Four mutations, each
verified to fail its own case. The cycle's count propagation is in the cycle commit, as the contract now says.
