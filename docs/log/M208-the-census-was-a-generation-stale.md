# M208 — the census was a whole corpus generation stale, and the cull is a decision

M205 found `manifests/missed_functions.json` describing a corpus that no longer exists: 265 unclaimed runs and
**24 candidate functions**, against 437 runs and **1** candidate on the current index. M208 re-derives it,
evaluates the survivor, and puts a gate between the file and the next reader.

## 1. Re-derived

| | committed (M83 era) | now |
|---|---:|---:|
| unclaimed runs | 265 | **437** |
| candidate functions | 24 | **1** |
| code-like unclaimed runs | 16 | 1 |
| code-like bytes | 61 440 | **656** |

The extra runs are four-byte gaps the old `+4` arithmetic swallowed (M205). The file is regenerated so it
describes today's corpus.

## 2. The one candidate: `stage2:0x8008bb10`, 656 B

Evaluated against the criteria M83 set, plus one test it did not have:

* **well formed** — `27bdffe0` (`addiu sp,sp,-0x20`) at the start, `27bd0020` at the end, 16 `jal` and one
  `jr ra` inside; the length fits the run exactly;
* **no direct caller** — a scan of all 36 images for `jal 0x8008bb10` finds **none**;
* **five data references** — `0x8012be1c`, `0x8012be28`, `0x8012be34`, `0x8012be40`, `0x8012be4c`, a table of
  12-byte records at `0x8012be1c`. So it is a **table-dispatched callback**, which is exactly the class M83's
  discovery rule exists to find, and it is reachable only indirectly.

**Verdict: accepted as a function, not added in this cycle.** Adding it means a Ghidra run plus a corpus
regeneration outside this cycle's scope; the evidence is recorded here so the decision is not re-litigated.

## 3. The cull is a decision, and it is stated

`find_missed_functions.py` also writes `build/seeds_extra`, which `make_seeds.py` feeds to the corpus build.
Re-deriving cut **24 candidate seeds to 1**, so the next corpus build would seed *fewer* functions than the last
one did. That is not a numbers fix and is not treated as one: it is recorded, tied to the one candidate above,
and left for a deliberate re-seed.

## 4. The gate

`find_missed_functions.py --check` re-derives and compares with the committed census on all 36 images, and pins
the candidate set to `("stage2", "0x8008bb10", 656)`. `--check` writes nothing — the seeds included, which was a
bug in the first draft of the flag.

Mutation: restore the `+4` that M205 fixed → the fresh derivation disagrees and the drift case fires, which is
the property that would have caught the staleness a generation ago.
