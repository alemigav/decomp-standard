# M123 — path sensitivity clears the polymorphic sites, and what perfect_dark is actually good for

Two things landed together: the analyser got the ability to prune paths with a caller's value, and the
third-party audit's suggestion (`n64decomp/perfect_dark`) was followed and assessed.

## Part 1 — path sensitivity

Three pieces, each small:

1. **Decided branches now have one successor.** When both sides of a `beq`/`bne`/`beql`/`bnel` are known
   constants, `_walk` reports the single feasible successor instead of both, and `_fixpoint` uses that instead
   of the static edge set. Without this, no caller value could ever prune a callee's paths.
2. **`analyse(..., seed=...)`** seeds registers at entry, so a function can be analysed *as if* it were called
   with particular argument values — one level of context sensitivity.
3. **`deref_reachable(words, start, k, value)`** asks the only question that matters for a flag: with
   `a_k = value`, is the callee's dereference of `a_k` still reachable?

Callee resolution needed a rule, because **overlays share vaddrs** (M122). A target inside `boot`/`stage2` is
unambiguous — those images are resident and map disjoint ranges — so they are preferred; otherwise the caller's
own image; otherwise every candidate.

### Result

```
13 flagged site(s): 11 cleared by path pruning, 2 kept
  KEPT  ovl_008505e 80162be8 -> 800653d0   a1 = 00000000   (deref still reachable in stage2)
  KEPT  ovl_008505e 80163de4 -> 800653d0   a1 = 00000000   (deref still reachable in stage2)
```

Eleven of the polymorphic sites — small ids `0x0a`…`0x32` passed to dispatch-shaped callees — are cleared:
with the id seeded, the pointer path is unreachable. That is the mechanism working as intended.

The last two are `a1 = 0`, and reading them changed the *question* rather than the answer: **on N64, address 0
is the RDRAM mirror**. A constant of 0 is a readable address, so "cannot be a pointer" is not something this
hardware lets you conclude from a value. The classification was wrong, not the analysis: the meaningful split is
**mapped vs unmapped**, so the plausibility window now covers the RDRAM mirror (`0x0..0x7FFFFF`), KSEG0 RDRAM,
PIF ROM, cartridge KSEG1 and the uncached RDRAM mirror. The only constants that can be condemned by shape alone
are the ones outside every mapped range — exactly the `0x0f564552` class M92/M93 found being inflated from.

```
14 371 call sites · 43 293 dereferenced register arguments
  4 181 passed a mapped constant · 0 passed an unmapped one
  26 002 derived · 13 110 unknown
0 flagged site(s)
```

So: **11 cleared by path sensitivity, 3 cleared by correcting the classification.** Both are stated because
either alone would be a misleading claim of "the analyser fixed it".

Fixtures: **10/10**, **12/12** (L11 now uses `0x0f564552`, the only shape this hardware lets us condemn;
L12 asserts an id-valued caller is pruned while an unsafe one is not), acceptance **3/3**.

## Part 2 — `perfect_dark` (the audit's suggestion)

Cloned shallow to `~/projects/perfect_dark` — **outside this repository**, 1.0 GB, 2 217 files.

### What is genuinely transferable

* **`include/PR/`** — the real 1998 Nintendo/SGI libultra headers (`os_cont.h`, `os_vi.h`, `os_si.h`, `gbi.h`,
  `gu.h`, …). These are an *authoritative, engine-independent* reference for N64 OS structures, and one of them
  directly confirms work in this log:

  ```c
  typedef struct { u16 button; s8 stick_x; s8 stick_y; u8 errno; } OSContPad;
  ```
  That is the 4-byte response (buttons high, buttons low, stick X, stick Y) plus a status byte — precisely the
  layout derived *empirically* from the live SI buffer in M109/M121 (`ff | 01 04 01 | <4 bytes>` per channel).
  Two independent paths to the same structure, which is this project's standard for "established".
* **`stagetable.txt`, `ld/`, `tools/mkrom`** — how a fully-matched N64 ROM is assembled from stages, as a
  reference for ROM-layout conventions. Useful contrast with RE2's overlay table (`OVERLAYTABLENUM`, 66 records).
* **`docs/piracychecks.md`** — a hazard class worth knowing about: Perfect Dark's own anti-tamper checks corrupt
  functions in memory if the binary looks modified. RE2's cart-table build stamp (M92) is the same *kind* of
  "is this the expected build" mechanism but purely informational, and this project never modifies the
  cartridge — so the hazard is real for a *matching* project and absent here.

### What is not

* **`src/` (1 GB)** is Rare's engine decompiled. RE2 is Capcom's engine; there is no structure to borrow.
* **`tools/rarezip`, `rarezip`, `src/inflate`** solve Rare's compression. RE2's banks are stock zlib, established
  in M88 by reading `0x800045dc`'s version check and `sizeof(z_stream) = 56` — nothing to gain.
* The decomp build machinery (splat configs, matching, asm-differ) answers a question this project does not ask:
  we document formats, we do not produce a byte-matching binary.

**Assessment:** worth keeping as a reference for *OS-level* semantics — that is where the audit's advice has
traction — and not as a source of game-format answers. Nothing was ported; nothing was added to the repo.

## Reproduce

```
python3 tools/provenance.py --self-test && python3 tools/provenance.py --self-test2
python3 tools/provenance.py --acceptance
python3 tools/provenance.py --arg-check        # 0 flagged, with the pruning/classification split
```
