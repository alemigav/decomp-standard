# Resident Evil 2 (N64) v1.1 — the 17.6 MB is the audio system, and the gate now refuses to grade itself

v1.1 of a black-box decompilation of **Resident Evil 2 (Nintendo 64, NREE rev 1 USA)**:
https://github.com/alemigav/re2-64-decomp

v1.0 was the corpus: formats decoded, 3 638 functions of Ghidra pseudocode, and a verification suite you could
run without the cartridge. v1.1 closes the biggest hole in it and rebuilds the part that decides whether any
of it is true.

Two things changed, and only one of them is about the game.

## 1. The 17.6 MB nobody had identified is the audio system

The file table was read as a **zlib manifest** for eleven milestones, because the first files decoded through
it happened to be zlib members. It is not. It is the whole file system, and **3 126 of its 7 978 real entries
are stored raw** — 58 270 043 B of uncompressed media. The evidence is in the entries' own heads: `ffd8ffe0`
×1 257 (JPEG) and `000001b3` ×271 (MPEG-1), reproducing the counts the media region had been carved into
independently.

That reframes the "two unidentified blobs". They are **two files**, and they are the sound system:

| | |
|---|---|
| id **1979**, 8 560 916 B | a **588-record `MORT` bank**, 16 000/8 000 Hz |
| id **1983**, 9 022 912 B | **1 192 samples that tile it to the byte**, 15 canonical rates |
| ids 1980–1982 | `SND_PROJ`, `SND_POOL`, `SND_SMPDIR` — the 69 310 bytes that were called "padding" |

Both are loaded by the sound initialiser, and the three files between them are the ones it tags on the way in.

**The sample codec is identified.** It is MusyX's ADPCM — the middleware's own scheme, not Nintendo's VADPCM —
and the format is now measured rather than attributed:

```
sample := [256 bytes = 128 raw big-endian int16 samples]  then  N × 40-byte groups
group  := [A.raw 4][B.raw 4][A.nib 16][B.nib 16]           two 20-byte frames, 32 samples each
```

`(len − 256) % 40 == 0` on **1 192 of 1 192** samples, and at that alignment **0 of 217 944 groups** violate
the two-codebook constraint — **100.00 %**, against 25 % by chance.

The chain containers are framed the same way: `SND_PROJ` is 417 records whose keys are a bijection onto
0..417 less one hole, chained in a rotation from key 118; `SND_POOL` is four chained sections holding 2 595
records whose 2 026 key slots are referenced by the project except one, and that one is a **dangling
reference**: the project names it, the pool does not have it, and the pool's single hole is exactly it.

`id 1979` is a **different codec** — high-entropy (7.937 bits/byte in both byte planes), which is why the PCM
test that failed there was never going to succeed.

## 2. What I got wrong, and how it was caught

v1.0's release notes said the suite was worth reviewing. Two of this cycle's findings were my own errors, and
both are in the log with retractions rather than quietly fixed:

- **"a 16-byte prologue, 97.58 % of groups pass, 2.42 % unexplained."** The prologue is **256 bytes**, the
  structure is **100.00 %**, and the 2.42 % was six groups per sample that my 16-byte phase put *inside* the
  prologue. I had fixed the phase from a prefix instead of from the structural boundary. The check that
  catches this class is not a better percentage — it is *asking where the failures are*, which is now a gated
  positional bound.
- **Every push since v1.0 failed CI, and I did not notice.** The ratchet hashed every file under `src/`,
  including a macOS `.DS_Store`. The baseline was written on my tree, so the hash matched here and nowhere
  else — a fresh clone has no `.DS_Store`, so the check failed 3/4 on every runner while passing locally.
  That is the environment-dependent-check defect this project keeps finding, and **only CI could see it**.

## 3. The gate now refuses to grade itself

The verification system is no longer a suite you run; it is a system with a stated admissibility rule:

- **44 mutation audits.** Every check's mechanism is disabled in a throw-away copy and the check must fail.
  Writing these found checks that could not fail — including one whose verdict was `"FAIL" in output`, which
  made five audits green unconditionally.
- **A ratchet.** Expected counts may not be lowered, suites may not be deleted, and `src/` may not move —
  each needs a deliberate `--write` that shows up as a diff.
- **Derived numbers.** Every figure quoted in the README and handover is computed from the registry and
  asserted in **seventeen** places. A phrase that *disappears* is a failure, so deleting a stale line cannot
  help. That mechanism caught its own author making the same clerical error twice in twenty minutes.
- **One verifier entry point** that will not report `PASS` unless the gate audit is clean: a vacuous audit
  forces `INCONCLUSIVE` regardless of how green everything else is. The rule is the first branch of the
  code, and its self-test proves each branch, including the inadmissible one.
- **Every milestone commit must have a record**, enforced against the commit subjects — added after a
  milestone landed with a tool, a suite, three audits and no note of itself.

## 4. Check it without the cartridge

```sh
git clone https://github.com/alemigav/re2-64-decomp && cd re2-64-decomp
python3 tools/acceptance.py      # 21 suites / 212 of 433 cases run; the other 13 suites SKIP
python3 tools/audit_gates.py     # 25/25, 19 skipped — every gate demonstrable here must fail when disabled
python3 tools/ratchet.py --check # the registry has not drifted, and src/ has not moved, silently
python3 tools/counts.py --check  # 16 asserted numbers; deleting a sentence is a failure
python3 tools/verify.py          # all of the above, adjudicated into one verdict
```

The 200 cases that need the cartridge print `SKIP (needs the cartridge)` — **never PASS**. A suite that cannot
run and reports success is the same error as a test that asserts nothing.

## 5. Still not known

- **`u16@+4`** in the `MORT` record: refuted as a duration two independent ways, refuted as a bitrate ladder,
  consistent with a frame count at 2.2–8.1 bits/sample — and **unassigned**, because no code path reads it.
- **The `MORT` bank's codec**, which is not the pool's and not PCM.
- **What the pool's four key classes mean** — the keys read as `[class][index]`, and nothing yet says what a
  class is.
- **Why key `11` is absent** from `SND_PROJ`, and **why its order starts at 118**. Single facts about one
  file; guessing at them would produce exactly the unfalsifiable story this project keeps refusing.

## Where the tag and this text differ

`v1.1` points at commit `5f9cd9e`. **This description matches the tree as it stands now**, and one thing
landed after the tag, so a reader who checks out `v1.1` will see two differences:

* the counts read **411** cases (**211** without the cartridge) and the gate asserts **sixteen** numbers,
  against 414 / 212 / seventeen here — nothing retracted, just a milestone later;
* **the README at the tag still carries the two figures M190 retracted** — a "16-byte prologue" and
  "97.58 %". The substance was already correct in the release body you are reading, because it was written
  after the retraction, but the front page inside the tag was not fixed until the next commit. That is the
  honest reason this paragraph exists rather than a silently edited release page: a tag is immutable, so the
  fix went forward, not backward.

## Provenance

No cartridge data is in this repository and none ever will be: no ROM bytes, no extracted assets, no audio, no
video. The author's text, tools and fixtures are **CC0-1.0**; `src/` is Ghidra pseudocode derived from a
Capcom work and is carved out of that dedication. Third-party material is credited in `THIRD_PARTY.md`.

Not affiliated with, endorsed by or sponsored by Capcom or Nintendo.
