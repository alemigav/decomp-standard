# M205 — the coverage figure was one word per function body too high

The strategic plan's first priority was "reproduce the headline numbers". I reproduced the hardest one and it
came out **wrong in the tool that computed it**, not in the arithmetic of a reader. `62.3 % of code bytes
claimed (1 212 984 of 1 947 632 B)` had been quoted since M84, restated in M177, and carried into the README
and the handover — and no tool recomputed it, so nothing noticed that the number was one 4-byte word past
every function body. Three artifacts carried the same `+4`, in three tools.

## 1. The bug, and its tell

`tools/export_src.py` builds coverage as a set of 4-byte words:

```python
covered.update(range(s, t + 4, 4))     # t = the body's inclusive last byte
```

For a body of two instructions (`s = 0`, `t = 7`) that set is `{0, 4, 8}` — **eight bytes of body, twelve
bytes claimed**. The tool's own docstring says what was intended: "the union of function body ranges against
the image extent". The union absorbs most of the over-claim, because the extra word usually belongs to the
next function — which is why the error survived: it nets **+2 384 B**, not the +11 034 B the per-range
arithmetic suggests.

The tell is a single row of `src/INDEX.md`: **`ovl_009d282` claimed 468 B of a 464 B image.** A function
body cannot be larger than the image that contains it. Nothing was asserting that.

The same `+4` appeared twice more, both in the per-function projection:

* every `.c` header: `size 2415 B` for `FUN_800a3bf4`, whose body `0x800a3bf4..0x800a455f` is **2 412 B** —
  so all **3 638** headers were 3 B per range too high;
* two other tools, `tools/find_missed_functions.py` and `tools/run_corpus.py`, built the same word set for
  the same purpose.

## 2. What the numbers are now

| | before | now |
|---|---|---|
| functions | 3 638 | **3 638** |
| body ranges | 3 678 (not published) | **3 678** |
| covered bytes | 1 212 984 | **1 210 600** |
| image bytes | 1 947 632 | **1 947 632** |
| coverage | 62.3 % of "code bytes" | **62.2 % of image bytes** |
| `ovl_009d282` | 468 of 464 B | **464 of 464 B** |

The label changed with the number, and that is the plan's point rather than a flourish: the denominator is
**image** bytes. Nothing in this project independently classifies code bytes, so "of code bytes" was not a
measurement — it was a word doing the work of one. `62.2 % of the 1 947 632 image bytes lie inside a known
function body` is the claim, and it is the only one the artifacts support.

## 3. A second finding: the census artifact is stale by a corpus generation

`manifests/missed_functions.json` is committed, cited by M83, and describes a corpus that no longer exists.
Re-derived on the current index:

| | committed (M83 era) | old arithmetic, current index | fixed arithmetic, current index |
|---|---|---|---|
| unclaimed runs | 265 | 246 | **437** |
| candidate functions | 24 | **0** | **1** |
| code-like runs | 16 | 0 | 1 |
| code-like bytes | 61 440 | 0 | **656** |

So the artefact's 24 candidates and 61 KB of "code-like unclaimed runs" are not current facts: on today's
corpus the same tool with the old arithmetic finds *nothing*, and with the corrected arithmetic it finds one
candidate of 656 B. The extra 172 runs in the last column are the four-byte gaps the `+4` used to swallow.

**I did not regenerate it**, and that is deliberate. It is M83's discovery record, and `find_missed_functions`
also writes `build/seeds_extra`, which `tools/make_seeds.py` feeds to the corpus build: re-deriving would cut
24 candidate seeds to 1, and whether to re-seed the corpus is a research decision, not a side effect of a
numbers fix. The measurement is recorded here so the file cannot be quoted as current in the meantime.

## 4. What recomputes it now

* **`fixtures/decomp/images.json`** — the 36-image inventory (name, role, base, size, ROM origin). Layout
  metadata, no cartridge bytes; `fixtures/decomp/ranges.json` set the precedent, and the build-side copy
  (`build/elfs/images.json`) is gitignored, so before this the denominator could not be recomputed in CI at
  all — the plan's "reproducible from a clean checkout" was false for the headline number.
* **`tools/counts.py`** derives `images`, `image_bytes`, `functions`, `ranges`, `covered_bytes`,
  `coverage_whole`/`coverage_dec` **from committed fixtures only**, and two new patterns assert the sentence
  in `README.md` and (twice) in `docs/handover.md`. A deleted or edited phrase fails; a wrong digit fails.
* **Two structural cases** tie the *generated* artifacts to the derivation, which is what quoting alone
  cannot do: `src/INDEX.md`'s headline must equal the derived corpus, and the sum of all 3 638 header sizes
  must equal the union — 1 210 600 B, "which is the union and not 1 212 984".

**One self-inflicted error, kept as a mutation.** My first draft of the union used a single global set across
images. Twenty overlays load at `0x80161cf0`, so that collapses their body ranges and reports **732 468 B
(37.6 %)** — a figure the new README assertion rejected immediately. The fix is per-image union, then sum, and
"the per-image union is not reset between images" is now one of the audit mutations.

## 5. Gates

`counts (repository)` **17 → 21** cases: two document assertions and two structural ones.
`gate audit (mechanisms disabled)` **69 → 74**, five mutations, each verified to fail its own case with a
message rather than by crashing: an exclusive end one word too far, the per-image union not reset, a function
count that stops matching source files, a header sum allowed 3 B per range too high, and the index case's own
parse broken in place.

`fixtures/gates/ratchet.json` was re-baselined twice, and both are the ratchet doing its job: the registry
changed (two suites' counts), and `src/` changed (3 638 headers, one line each — verified that nothing but the
size line moved). Its purpose is to force a decision, and the decision here is a correction.

## 6. Three defects in the gates themselves, all found by running them

Recorded because they are the same class of failure this milestone is *about*, one level up.

1. **The audit wrote through a symlink into the live tree.** The fifth mutation was meant to rewrite
   `src/INDEX.md` — the literal state the tree had been in for thirty milestones — but `audit_gates.py`
   **links** `src/` into its sandbox instead of copying it, so the mutation landed on the real file, left the
   worktree at 1 212 984, and failed the audit run on its own damage (73/74). Fixed by a guard in
   `run_audit` that refuses any mutation whose resolved path leaves the sandbox, and the mutation was moved
   into `counts.py`. It is the fourth time in this arc that an audit *environment* produced a false verdict,
   and the first time it produced one by changing the tree it was auditing.
2. **`counts.py --self-test` failed on a missing input, again.** Its synthetic root did not carry the new
   fixtures, so the untouched copy disagreed for reasons that had nothing to do with a wrong digit — the
   third occurrence of the same self-test gap. `src/` is now symlinked there too, read-only.
3. **I truncated this note.** A one-line edit opened the file for writing and then read it back, which
   returns empty: the file was destroyed and rewritten from the conversation. Three hundred lines of context
   are cheaper than a `cp`.

`docs/announcement-v1.0.md` still says 62.3 %, and stays that way: it is a dated publication, not a live
claim, and the retraction is recorded in the log's table rather than retro-edited into an announcement.

Repository is **36 suites / 504 cases**, of which **14 suites / 282 cases** are cartridge-gated, so the
runnable tier is **22 suites / 222 cases**.
