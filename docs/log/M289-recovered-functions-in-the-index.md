# M289 — the recovered functions are in the index: 14 pinned, the map shows all of them

M288 left one thing undone and named it: the two functions proved byte-exact were still invisible to the index, because
the provider never split them. This milestone adds the evidence class M288 called for — a committed record of what we
have reconstructed — and applies it in the projection.

## 1. The fixture

`fixtures/decomp/recovered.json` lists **14 functions**, each with its measured extent, its verdict, the probe case
that pins it, and the name of the constant in `tools/compile_probe.py` that holds the reconstruction:

```json
{"image": "stage2", "address": "0x8007e590", "words": 229,
 "verdict": "partial: 226 of 229, three words of allocation",
 "probe": "p7e590: 226 of 229", "source": "P7E590_SOURCE"}
```

`tools/recovered.py` is the single reader. That matters because **four** consumers have to agree about where a
recovered function ends — `export_src.py` (publishes `src/` and the index), `counts.py` (recomputes coverage in CI from
committed fixtures), `call_graph.py` (attributes `jal` sites to owners) — and a second hand-kept copy of those numbers
is exactly the drift M205 and M210 were about.

## 2. What applying it changed

| | before | after |
|---|---|---|
| functions | 3 414 | **3 416** (`0x8006e68c` and `0x8006e574` now exist as functions) |
| switch-case fragments | 224 | **174** (50 absorbed into the owners whose extents now cover them) |
| covered bytes | 1 210 600 | **1 211 252** |
| ranges (provider's) | 3 678 | 3 678 (**unchanged**) |
| extents corrected | — | **7**: `0x8004fd1c` 10 → 98 words, `0x80070120` 23 → 46, `0x80059868` 14 → 167, `0x80059530` 15 → 206, `0x800acae4` 25 → 53, `0x8007e590` 14 → 229, `0x80024558` 20 → 139 |

The +652 B is itemisable, which is the point of measuring it: **476 B** from `0x80024558` (previously the largest
unclaimed region of a function we had recovered), **92 B** for `0x8006e574`, and **84 B** for `0x8006e68c` (the other
80 B of its extent was already claimed by one of its arms). Every other recovered function's extent was already covered
exactly — which is an independent check that the measured extents are the provider's extents plus its arms, not
something invented.

`src/<image>/<name>.c` for these 14 now publishes **our reconstruction** rather than the provider's head-only
pseudocode, and says so in the header:

```
 * recovered partial: 226 of 229, three words of allocation (p7e590: 226 of 229)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in
   tools/compile_probe.py as P7E590_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
```

## 3. Two design decisions, one of them made by breaking things first

**The provider's range fixture stays authoritative.** The first attempt applied the recovered extents inside
`export_ranges.py`, which regenerates `fixtures/decomp/ranges.json`. That broke **six** analyses at once — byte map,
handler region, extent audit, dispatch heads, call graph and the opcode registry — because they classify bytes *from
that fixture* and their own committed manifests were derived against the old boundaries; `handler_region` even failed
semantically (`0x80070120: extent … is not the covering range …`). Reverted: the provider's ranges are unchanged, and
the recovery is merged where *coverage* is computed instead, with the excess stated as coming from the fixture.

**The call graph had to learn the fixture.** With the provider's ranges, the `jal`s inside a recovered function's arms
had no owner, so their edges carried `src: None` — four nodes disagreed with their own `code_index` callees. Its
`body_ranges()` now unions the fixture in, which is the same rule the exporters use.

## 4. What the map says now, and what is left

**`3416 functions · █ 11 reproduced byte-for-byte · ▓ 3 recovered`** — and
`progress_map.py --check` reports **all 14 functions claimed as recovered are in the corpus**, which it had refused for
two milestones. The count moved from ten-of-twelve visible to **fourteen of fourteen**, with the eleven byte-exact
listed individually and the three partials named with their residues (`136 of 139`, `226 of 229`, `17 of 23`).

Three gates caught drift on the way, all by mechanism rather than by my editing a number: the byte-sum case
(3590 headers must equal coverage), `audit_gates.py --lint-self-test` **twice** (two mutation anchors pointed at lines
that moved in `counts.py`), and the ratchet (`src/`'s tree hash changed when 50 case-body files were absorbed).
`analysis_status.py` re-derived to `F0` 3 416 / `F1` 3 402 / `F2` 3 315, and the call graph to 3 416 nodes and 15 535
edges.

Nothing of this class is left open: every function this project has reconstructed is now a function in the index, at its
measured extent, with its reconstruction published and its pin named. The three partials stay partial, and their
residues are the allocation tie-breaks M283 recorded.
