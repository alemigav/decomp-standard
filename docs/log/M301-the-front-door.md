# M301 — the front door: a hero, an audience line, a 60-second quickstart, and proof in bytes

A third-party review of the README landed with one verdict worth acting on: *"the substance of the README is
phenomenal, but its presentation is not — it currently rewards only those who already deeply care."* The review
named five missing elements. Four are now in, and the fifth is answered by a different route, stated below.

## What the review asked for, and what went in

| asked | shipped |
|---|---|
| a "TL;DR / hero" answering *what is this and why should I care* | the opening block: one plain-English paragraph, then three rows — **the result** (compiler pinned, 15 functions byte-exact), **the unusual part** (286 checks with no ROM), **the scale of what is left** (62.2 % of image bytes in a known body) |
| a true 3-step quickstart, near the top | `git clone` / `cd` / `python3 tools/verify.py` — with the honest expected verdict `PASS-FAST`, 286 cases run and 736 skipped |
| a "Project Highlights" list replacing the long dense section | five scannable bullets linking into the deep sections; the long list **stays** below as the full inventory, because it is derived and asserted and deleting it would delete claims |
| a "Who is this for?" line | its own short section, third sentence in |
| visual proof (a GIF, or something to *look at*) | **"Proof, in bytes"** — the cartridge's nine words of `osCreateMesgQueue` beside this repository's nine, identical, with the instruction gloss. Not a GIF: a GIF is not a measurement, and this is. The generated per-image progress map is linked from it and from the hero table |

**The fifth element — "assumes too much context" (REA, Ghidra, splat, IDO) — got a jargon table**, one line per term,
placed before the deep sections rather than in the references at the bottom.

## Two corrections the rewrite forced

Writing the hero surfaced two claims that were *not* true as phrased, and they are the reason this is a milestone
and not a cosmetic edit:

1. **"1 022 checks you can run with no ROM" is false.** 286 run without the cartridge; **736 need the dump and report
   `SKIP`, never `PASS`**. The hero now says exactly that, in both places it appears.
2. **"62.2 % of the code bytes are mapped" is the wrong denominator.** The figure is *image* bytes inside a known
   function body (1 211 256 of 1 947 632 B); 62.2 % of "the code" reads as if the unmapped tail were not code, which
   is precisely the judgement the census refuses to make. Reworded.

Also fixed while there: the hero said "16 functions … until they match byte for byte", which is one too many — the
sixteenth is `0x8007e590` at **226 of 229** and is published as such. Now "16 reconstructed, **15** matching".

## Why nothing else moved

No case was added, removed or re-aimed: every number the new sections quote is one `tools/counts.py` already derives
and asserts, so the rewrite had to *satisfy* the gates rather than restate them. Two did bite, both usefully:

- deleting the phrase `**1022-case verification suite**` from the opening paragraph failed `counts.py` with
  *"phrase found 0x, expected 1 — a deleted phrase is a failure"*, which is the gate doing exactly what it exists for.
  The phrase went back.
- the milestone counters had to move (301 → 302 numbers, 245 → 246 rows, 225 → 226 notes) before
  `milestone_index.py` and `counts.py` would both agree.

The emoji the review suggested for the highlights list were dropped: this README has never used them, and a bullet
list does not need them to be scannable.

## Numbers

- **README**: two new sections (Proof in bytes, The jargon), three new front sections (hero, audience, quickstart),
  one new highlights list; 427 lines (+63)
- cases, suites, tools, functions, fragments, coverage: **unchanged** — 73 suites / 1 022 cases, 100 tools,
  3 416 functions / 1 211 256 B
