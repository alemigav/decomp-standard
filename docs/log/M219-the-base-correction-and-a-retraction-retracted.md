# M219 — the base correction lands, and one claim survives it that I had already retracted

M218 measured that the `SND_PROJ` lists live at `record + 8 + offset`. This milestone re-derives the six gate cases
that read them at `record + 0`, and the re-derivation corrected **me** as well: I had announced that the dangling
`531` reference was retracted. It is not.

## 1. The six cases, re-derived

| case | before (base `+0`) | now (base `+8`) |
|---|---|---|
| the cross-file link | 5 136 shorts, 4 301 pool keys (83.7 %) | **7 388 shorts in `[3 468, 3 316, 261, 4, 339]`, 7 369 pool keys (99.7 %)** |
| list census | six lists `[2027, 169, 736, 290, 65, 566]` | **five key lists `[2026, 1192, 242, 4, 327]`**, each drawing on **one** pool tag `[[0], [0], [3], [1], [2]]` |
| `[0, a, 0, b]` prologue, 834 zeros | structural | **retracted** — the lists open on class keys; the "zeros" were the record header |
| 531 dangles | one hole | **survives**, re-measured as **1 of 4** distinct unresolved keys (`-32616, -16251, 531, 16385`) |
| list[5] is the pairing | 142 sample + 148 tag-3 keys | **retracted**: reading list 5 as terminated `u16` yields **4 values in the whole file** (the flag-0 form ends `ffffffff`, the flag-1 form is count-prefixed). It is a 12-byte row array |
| list[2] holds 2 027 | the sample space | **2 026**, spanning 1…2026, containing all 1 192 directory keys |

Two new cases carry the evidence that made the correction necessary rather than asserted: the six spans **overlap
417/417 records at `+0` and 0/417 at `+8`**, and the unresolved set is asserted as an exact list so a future
"no unresolved shorts" claim cannot be made from a parse that disagrees.

## 2. The correction to my own M218 note

While landing M218 I wrote, on a quick script of my own, that "531 resolves, so M186/M188's dangling reference is
retracted". **That script's pool parse produced 2 599 keys; the gate's produces 2 595** — the number M185
published and the number the file-table suite has always asserted. Against the gate's parse, 19 of the 7 388
shorts do not resolve, over **4** distinct keys, and **531 is one of them**.

So the honest position is the reverse of what I published an hour earlier: the base error **did not** touch the
dangling-reference finding, only the arithmetic around it. The M218 note and the retraction row are corrected in
place rather than amended in a new commit, because the note is not yet a published artefact outside this
repository and a wrong retraction is worse than a corrected one.

**The process lesson, since the same mistake has now happened three times**: an ad-hoc parse is not evidence when a
gate already parses the same file. The gate's `pool_keys` is the authority — it is what every other case in that
suite is written against — and my script silently disagreed with it by four keys.

## 3. What is still open, and why it is not in this milestone

M188 also claimed "sections 1–3 are never referenced by any PROJ list". At the correct base the negative keys do
resolve, so that claim is retracted — but the *replacement* claim ("every pool key is referenced") would rest on
the same parse whose section walk I have just seen disagree by four keys. That needs the pool's own section walk
re-derived first. It is queued, and the case that would have asserted it is not written.

## 4. Gates

`file table (cartridge)` stays at **101 cases**: one case rewritten (the cross-file link), one replaced by the
base-refutation pair, two replaced by the retraction plus the measurable half, and one where the assertion changed
from "2027" to "2026". No count moved, which is the right shape for a correction: the suite says the same *kinds*
of things, about correct numbers.
