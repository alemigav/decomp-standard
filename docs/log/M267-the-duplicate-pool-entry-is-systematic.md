# M267 — the duplicate pool entry is systematic, and removing dedup is not how to match it

M266 left one open question: p8's pool holds the same 2^32 double twice, ours dedups to one, and the image also
dedups its single-precision `4.0f`. The third-function test was meant to say whether the duplication is systematic.
It is. Applying it is not the same as matching it, though, and this milestone records both halves.

## 1. The test: duplication is systematic, not a p8 accident

A scan of the image for `lui R,HI` followed by an `lwc1`/`ldc1` whose base is `R` resolves **430 float pool
loads**. Grouping them by (function, value loaded) and keeping the cases with **two or more distinct addresses**:

| function | value | distinct pool addresses |
|---|---|---|
| `FUN_800a3094` | 2^32 (double) | **7** — `0x800ba630, 638, 640, 648, 650, 658, 660` |
| `FUN_800a5da0` | 2^32 (double) | 6 |
| `FUN_8009ef50` | 2^32 (double) | 5 |
| `FUN_80047298`, `FUN_80044fdc`, `FUN_80046208` | `4f000000` (float, 2^31) | 9, 9, 8 |
| `FUN_80047d70` | `45800000` (float, 4096.0) | 5 |
| *(unowned — the region around p8's own pool)* | 2^32 (double) | `0x800b69c8, 0x800b69d8, 0x800b69f8, 0x800b6a08` |

So the original build stores the same constant at several pool slots, repeatedly, across many functions — and p8's
two copies are an ordinary instance of it, not an oddity. **The duplicate should be reproduced** if byte-exactness
is the goal; the question was only *how*.

## 2. Applying it wholesale is wrong, and the measurement is decisive

The obvious implementation is to stop deduplicating float constants on both paths that do it —
`immed_double_const`'s `const_double_chain` search and `force_const_mem`'s descriptor hash. Applied and rebuilt:

| build | p6 | p7 | **p8** |
|---|---|---|---|
| dedup as-is | **98 / 98** | **84 / 84** | **136 / 139** (3 hunks) |
| float constants never dedup | 98 / 98 | 84 / 84 | **90 / 139** (11 hunks, and the jump table is no longer found in `.rodata`) |

Worse by **46 words**. The reason is in the same scan: the image *does* dedup `4.0f` (both uses in p8 share one
slot), and it *does not* dedup the 2^32 double. Removing dedup uniformly floods the pool with a fresh `4.0f` per use,
which shifts every `%lo` immediate after it — the same coupling that made "pool everything" alone worse in M264.

**So the original's behaviour is mode-asymmetric**: one shared entry for the single-precision constant and several
for the double. `force_const_mem` has a single hash and a single comparison, so no uniform setting of it produces
that — which means my model of *why* the original duplicated is still wrong, and it is not "the comparison was
broken" (that would duplicate the float too).

The experiment was reverted and is recorded rather than pinned: **p8 stays at 136 of 139**, its three differing
words being the `$at`/`$v0` allocation tie-break (unaffected by the pool change, which rules out "the pool grew and
the allocator moved"), the duplicated entry, and one padding word.

## 3. README

The headline sentence *"This is not a matching build"* was true when it was written and is now incomplete: it is
still true **of the whole cartridge**, but the compiler has been identified and two whole functions are reproduced
to the byte. The README now says exactly that, and gained a **The matching build** section stating the identified
profile (compiler, assembler, the cpu flag that matters on both, and the two patched behaviours), the three
reconstructed functions with their results in a table, and pointers to the tool and the build recipes. It is
deliberately prose: no new number in it is gated, and `counts.py` stays green at 25 of 25.

## 4. State

- **p6 byte-exact, p7 byte-exact, p8 136/139**; corpus **22 cases, all passing**; the toolchain is back to the
  M265 patch set (the M267 experiment is not in the tree).
- Open, and now well specified: the pool's mode-asymmetric duplication. The next test is a function that uses **one
  double constant twice** and **one float constant twice**: if its double is duplicated and its float is not, the
  asymmetry is a property of the original compiler's comparison and can be characterised exactly; if not, p8's
  duplicate comes from its own expression tree after all.
