# M207 — the other 37.8 % is classified, not shrugged at

The corpus published one number for its coverage and one sentence for the remainder: "data, padding, or code
Ghidra did not identify — it is *not analysed*". That sentence is the gap the strategic plan's Track C names,
and it is now a partition, computed per word, from artifacts that already existed.

## 1. What the map says

`tools/classify_image.py` → `manifests/byte_map.json`, five classes, precedence fixed and overlaps counted:

| class | bytes | source of the label |
|---|---:|---|
| `function_body` | **1 210 600** | `fixtures/decomp/ranges.json` — the 3 678 body ranges |
| `padding` | **407 608** | runs of ≥ 16 identical `0x00`/`0xFF` bytes in the unpacked image |
| `data_named` | **6 640** | a `DAT_xxxxxxxx` the decompiler names in a `src/` body, landing inside the extent |
| `jump_table` | **964** | a table start named by `manifests/jump_tables.json` |
| `unclassified` | **321 820** | nothing names it — **16.5 %** of image bytes |

So the sentence becomes a measurement: **21 % of the image bytes are padding**, 16.5 % are unaccounted for, and
the rest is the code the project already publishes. 1 096 padding words fall *inside* a function body (alignment
inside functions) and are reported, not silently reassigned.

The map is metadata — addresses, classes and sources — like `fixtures/decomp/ranges.json`. No image bytes are
committed.

## 2. The invariants, and one that earns its keep

`--check` (CI, committed artifacts only): sorted and disjoint per image; exact cover of `[base, base+size)`;
body total exactly 1 210 600 B; every range names its source; the classes sum to 1 947 632 B; unclassified is
non-zero and published.

`--check-cartridge`: a rebuild from the unpacked images reproduces the committed map exactly, **and** every
padding range is a single value `0x00` or `0xFF`. The second one is what caught the tool's own first bug: the
scan rounded a run's start down to the word boundary and its end up, so 256 ranges contained bytes that were
neither — the class was right in spirit and wrong at 1 024 bytes. Rounding *inwards* fixed it.

A second self-inflicted bug is worth recording because it would have hung CI: the run scanner did `i = j` even
when `j == i` (a byte that is neither `0x00` nor `0xFF`), so `--write` never terminated. It ran past two minutes
before the profile found it.

**And a third, found by the repository's own size limit.** The range merge compared `end + 4 == next_start` when
`end` is inclusive, so it never merged: the first committed map was one range per word — **486 908 of them, a
47.5 MB file**, which `artefact_scan.py` refused at its 4 MiB limit. With the comparison fixed (`end + 1`) and
the padding label carrying its value (`run of 0x00` / `run of 0xff`, so a merge cannot span two values and the
padding law stays a single-value claim), the map is **3 885 ranges, 369 KB**. The 4 MiB rule is what caught it,
which is the rule doing exactly what it was written for.

## 3. Gates

Two suites: `byte map (repository)` (6 cases, CI) and `byte map (cartridge)` (2 cases). Three mutations — padding
allowed to overwrite a body, the unclassified bucket renamed to `data`, and the padding run rounded out to the
word boundary — each verified to fail the case it targets. The first two have to be aimed at the *rebuild*, not
at `--check`: `--check` validates the committed artifact and is deliberately insensitive to how it was made.

README and handover now publish the split instead of the sentence.
