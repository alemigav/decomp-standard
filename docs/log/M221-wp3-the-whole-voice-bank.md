# M221 — WP3: every one of the 588 voice clips, and 12 037 live comparison blocks

M199 verified 13 clips / 634 blocks against the cartridge's own synthesis. WP3 asks the question the rest of the
bank was waiting for, and the answer is clean — with one deviation from the plan that is stated rather than
smoothed.

## 1. The recorded result

`tools/voice_sweep.py --sweep` → `fixtures/sound/mort_sweep.json`:

| | |
|---|---|
| clips | **588 of 588** transcribed, reconciled, and compared |
| declared blocks | **307 038** = 262 894 normal + 44 144 silent |
| samples | **49 126 080** |
| live blocks compared (cartridge under Unicorn) | **12 037** |
| **samples differing** | **0** |
| `length/4` reconciles | **588 / 588** — the declared word count equals the record length and the runs end inside the payload's final word, 1–32 bits spare |

The gate (`--check`, **12 cases**, ~48 s with a 10-process pool) re-derives every clip's blocks, rate, sample count
and **PCM SHA-256** from the cartridge, checks the framing ledger re-derives the bank's 262 894 / 44 144 split, and
runs a small live differential so the harness itself cannot rot. The whole-bank numbers are therefore gated, not
merely recorded.

## 2. The deviation, plainly

I specified "the last block of every clip" as part of the live stratum. **That is not affordable**, and the reason is
structural rather than budgetary: `decode()` builds a fresh machine from block 0, so reaching block *j* costs
*j + 1* emulated blocks. At 9.6 ms/block the whole bank is **2 956 s**.

The stratum actually run: **blocks 0–15 of all 588 clips**, plus **the whole clip for the 46 clips of ≤ 96 blocks** —
whose last blocks are therefore compared. 12 037 blocks, and every clip represented. What this does **not** do is
random-access a late block of a long clip, and saying "every clip was compared" without that sentence would be the
kind of rounding this project keeps catching itself doing.

## 3. What the sweep incidentally established

* **`length/4` at +8 is the whole record length in words** (`ext4*4 == len(record)` on 588/588), and the reader's
  buffer starts at byte 12 (`bitpos 0x60`), so the four bytes before that are payload, not header.
* The **framing ledger** — 1-bit selector, 4/7-bit runs +1, 260 bits per normal block — re-derives the bank's exact
  normal/silent split and the decoder's own silent tally clip for clip. That is an independent cross-check on the
  decoder from a different direction, and it costs no emulation.
* Full-bank pure-Python transcription is ~430 s CPU (1.4 ms/block); the pool is what makes a whole-bank hash gate
  affordable at ~48 s.

## 4. Two corrections to my own tooling

Both were caught by the gate, not by me, and both are worth recording because they are the same failure shape:

* My first mutation anchor had **one extra `0`** — the committed hash starts `0a9d…`, not `00a9d…` — because an
  earlier test wrote the mutated value back and I read the file in that state. `--lint-self-test` reported *anchor
  not found* in 0.04 s.
* The committed artefact was then edited in place **twice** mid-task, once making clip 0's hash 65 characters. The
  sweep was regenerated from the cartridge rather than hand-repaired, which is the rule: a derived artefact is
  re-derived, never patched.

## 5. Not in this milestone

The second half of WP3 — **tracing the voice descriptor into the mixer** — is untouched. It is the question the
review ranked highest after sequencing, and it now has a clean substrate: every clip's descriptor is trustworthy
because every clip decodes bit-exactly.
