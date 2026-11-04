# M179 — `u16@+4` refuted three ways, and the directory becomes a reading

M178 left one field unassigned and one correlation standing. This milestone tests the field against the
readings that were on the table, and converts the correlation into a **reading** by finding the code that
consumes it. It also lands the first piece of verification infrastructure that is not about the
cartridge at all.

## 1. `u16@+4` — three refutations, one doubtful, still unassigned

Field range 26–7 647 over 588 records, payload 690–239 902 B. Against the 588 records:

| reading | result |
|---|---|
| **MIDI base note** (0–127) | **REFUTED** — 503/588 are above 127 |
| **duration in ms**, 16-bit mono at the stated rate | **REFUTED** — exact on **8/588**; field/ms spans 0.49–3.66 |
| **sample count** (`payload/2`, `payload/4`) | **REFUTED** — **0/588** both |
| **loop point**, as a byte offset | in range 588/588, but **doubtful** |

The loop-point reading is the interesting one, because it survives the test it was expected to fail and
then fails a test nobody proposed. `field < payload` holds on **588/588**, so nothing is out of bounds.
But `field/payload` lies in **[0.0307, 0.1143]** — every value in the first decile, mean 0.0398. A real
loop-point population has mass at 0 (no loop, or loop from the start) and mass near 1 (loop the sustain);
this has neither, and **no sound in the bank loops past 11.5 % of its own length**. That distribution is
what kills the reading, not the bounds check.

Parity is a coin flip — **272/588 odd** — which refutes a byte offset *in two-byte units* specifically and
is **neutral about everything else**: random parity is what a count or an index looks like. Recording it
as anything stronger would be the "sounds like a gate" pattern.

So the honest description is: `u16@+4` is **proportional to payload length with a 3.7× spread** — a
length-like quantity with no constant of proportionality found. A description, not an assignment.

## 2. The yield is elsewhere: the directory word is now a reading

M178 measured that the directory's top byte is clear on 23 offsets and that those 23 are set-identical to
the 23 records at 8 000 Hz. That was a **correlation of two measurements**. Following the record pointer
from `FUN_800b3f54` found the player, and it is not a correlation any more:

```c
/* src/stage2/FUN_800b3704.c, 0x800b3704 */
if ((DAT_80136d80 != '\0') && (iVar5 = 0, param_1 < _DAT_8015af80)) {        /* 588, the directory count */
  if ((param_2 == 0) && (param_2 = 16000,
      *(char *)(param_1 * 4 + _DAT_8015af7c) == '\0'))                       /* the word's top byte */
    param_2 = 8000;
  ...
  FUN_800b4930(..., (*(uint *)(param_1 * 4 + _DAT_8015af7c) & 0xffffff) + _DAT_8015af78, ...);
```

Every element of M178's measurement is read by this function: `_DAT_8015af80` is the 588 count and
`_DAT_8015af7c` the 588-entry table (both set by `FUN_800b3f54`), the **top byte chooses 8000 over
16000**, and **`& 0xFFFFFF` plus `_DAT_8015af78` is the record address**. So the word is
`[rate byte][u24 offset]`, established by code rather than by two numbers agreeing.

A second, independent instance of the same idiom is in the sequence path: `FUN_80004a6c` reads a `u16`
where **bit `0x8000` selects 8 000 Hz and `& 0x7fff` is the index**. Two independent sites, one
convention.

Three cases pin the three expressions, so a re-decompile that loses them **invalidates the claim instead
of silently keeping it** — and the ratchet (§3) freezes `src/`, so they cannot drift unnoticed.

## 3. The ratchet, and the first customer being this milestone

The recurring defect in this project is not a wrong claim. It is a **gate that could not fail**: six audit
environments missing a directory, two mutations that failed for the wrong reason, and M178's
`4 852 vs 4 761` read as a missing class when it was 126 aliased entries. A verifier that owns the gates
inherits that in a new form — it can make its own suite pass by lowering an expected count, deleting a
suite, or editing the output it is checking.

`tools/ratchet.py` makes those three edits mechanical failures:

| invariant | rule |
|---|---|
| **match** | `tools/acceptance.py` must register exactly the baselined suites at exactly the baselined counts. Any difference — added, deleted, raised **or** lowered — fails, so no change is silent; accepting it is `--write`, which is a diff. |
| **decrease** | `--write` **refuses** to lower a count or drop a suite unless `--allow-decrease` is passed. The ordinary path cannot shrink the suite. |
| **src** | the hash of the whole `src/` tree must match. A verifier may add cases; it may not touch the decompiled corpus to make them pass. |

`--check` on a healthy repository passes whether or not those comparisons are wired, so the invariants are
graded by `--self-test`, which breaks each one **on a synthetic root, in isolation**. That self-test found
three defects in the ratchet while it was being written, and all three are the class the tool exists to
prevent:

1. `importlib` can serve a cached `.pyc`, so the ratchet **read a stale registry** and reported "monotone"
   about counts it never looked at. It now compiles the source text directly.
2. The `src/` case was **vacuous** — it ran while the registry was still dirty from the previous case, so
   it failed for the *other* reason and would have reported detection with the `src/` comparison deleted
   entirely. Every case now restores the baselined state first.
3. A **raised** count passed `--check` silently, so "requires `--write`" was never enforced.

And the audit found one in `tools/audit_gates.py`, which matters more than either: its verdict was
`returncode != 0 or "FAIL" in out`. The ratchet's self-test *deliberately prints* `FAIL` lines as its
detection mechanism, so all five ratchet audits were "detected" no matter what — one of them caught
nothing and was reported PASS. The verdict now uses the `N/M` line and the exit status, the same rule
`acceptance.py` uses. **A gate whose output legitimately contains the word FAIL cannot be graded by
grepping for it.**

The ratchet's first customer is this milestone. M179's increase — `file table (cartridge)` 20 → 28 and
`gate audit` 35 → 37 — was **refused until `--write`** and is recorded in `fixtures/gates/ratchet.json`.

## 4. Three denominators reconciled

The reviewer's arithmetic challenge was right to be asked and resolves in the project's favour:

* **126 is not a typo for 91.** 4 852 entries resolve to **4 726** distinct offsets, so 126 entries are
  repeats over 67 shared offsets; and **91 = 126 − 35**, where 35 is the members the walker finds that the
  table does not name. 4 852 − 126 + 35 = 4 761. Two different sets; the note now states the chain.
* **26 vs 30 vs 35 vs 37 is not a contradiction** — the audit suite grew at each milestone (26 → 30 at
  M178, → 37 here). The `26/26` in a transcript was the *expected count* failing before it was updated,
  which is the gate doing its job.
* **Parity** is worded as above: it refutes a byte offset in two-byte units and nothing else.

## 5. What this does not change

* M5 is untouched, and `u16@+4` remains **one open field** in one decoded container.
* id 1983 remains **located but unparsed** — 9 022 912 B, still the largest open object.
* The decompilation itself did not advance: this milestone converted one correlation into a reading and
  killed four readings cleanly. The structural facts it lands — the file table fully enumerated, the
  sound family bounded, the directory word read — are what a matching build needs before it can lay bytes
  out.

## 6. Gates

`file table (cartridge)` **20 → 28 cases**: the four readings of `u16@+4` (three refutations and the band
that makes the loop point doubtful), the parity sentence, and three source-pinning cases for the code
reading. New suites `ratchet self-test` (**9**) and `ratchet (repository)` (**4**). Audit **37/37, 0
vacuous**, up from 35: five mutations on the ratchet — one per invariant and one per forbidden write —
plus two for the new claim classes, aimed at the *needle* (a needle that is not in the source fails a wired
case and passes a vacuous one) and at the measured band from the inside. Every new mutation was
hand-verified to fail on its intended case.

Repository is **30 suites / 326 cases**, of which **12 suites / 148 cases** are cartridge-gated, so the
runnable tier is **18 suites / 178 cases**.
