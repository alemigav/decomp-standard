# M291 — the pool's sharing rule: the double is per use, the float is per value — and a reproducibility bug the patch had

The last remaining partial is now **137 of 139**, and the word it gained came from the *toolchain*, not the C. Getting
there also exposed a defect in how the toolchain patches were committed: **a fresh provision would not have built the
compiler the corpus was matched with.**

## 1. The rule, and why M267 could not express it

M267 scanned the image and found the same double stored at several pool slots (2^32 seven times inside
`FUN_800a3094`, at `0x800ba630..0x800ba660`), while `4.0f` is shared — and then found that removing deduplication
*uniformly* costs 46 words, because the float side floods the pool. It recorded the asymmetry and left the mechanism
open, concluding "no uniform setting of `force_const_mem` produces that".

It is not a uniform setting. It is a **mode test**, in two places:

```c
/* immed_double_const's chain search */            /* force_const_mem's pool hash */
    if (CONST_DOUBLE_LOW (r) == i0                     if (compare_constant_rtx (mode, x, desc)
        && CONST_DOUBLE_HIGH (r) == i1                     && mode != DFmode)
        && GET_MODE (r) == mode
        && mode != DFmode)                             /* M291 */
```

A double constant is then never *shared* — one pool slot per use, which is what the image shows — while a float
constant still is. Measured on the corpora:

| build | p6 | p7 | `0x8007e590` | **p8 `0x80024558`** |
|---|---|---|---|---|
| no mode test (before) | 98/98 | 84/84 | 226/229 | **136/139** — `$at`, duplicate entry, padding |
| **`mode != DFmode` (M291)** | 98/98 | 84/84 | 226/229 | **137/139** — `$at` and padding |

The duplicated-entry word is gone: our pool reference is now 16 bytes later, exactly where the image's is. Two words
remain and they are one thing — the pool address is built in `$at` in the image and in `$v0` in ours, the reload-scratch
versus allocated-register tie-break that M270 named.

## 2. The patch script could not have produced the compiler we tested

Committing the rule meant checking that `tools/toolchain/patch_gcc281_fp.py` reproduces the build tree, and it does not.
The script's guard was

```python
        # One-shot per file: the marker is written by the first edit, and a file that carries it is done.
        if MARKER in texts[p]:
            continue
```

so **only the first edit to `varasm.c` ever applied**. On a pristine tree the pool-writer edit
(`REAL_VALUE_FROM_CONST_DOUBLE (u.d, x)`) and both new anchors are skipped silently, and the message still says the
patch was applied. The compiler in `build/toolchain` was built before that guard mattered, so every measurement in this
project is valid — but `provision.sh` on a fresh clone would have produced a *different* cc1 and no gate would have
noticed. That is the class of defect M205 and M210 were about, one layer below where they looked.

Three fixes, each verified against the pristine tarball rather than against the already-patched tree:

1. **the guard is per edit, not per file** — only the M261 writer edit needs it, because its replacement re-states the
   lines it replaces (`True` as a fourth tuple element);
2. **a missing anchor means "already applied" only if the replacement is present**, otherwise it is still a hard
   error — so a second run is a no-op instead of a refusal;
3. **the anchors are taken from the pristine source**: the first one names `CONST_DOUBLE_LOW (r) == i0` because the
   bare tail matches `immed_real_const_1`'s loop as well (it matched **twice**), and the second is space-indented,
   not tab-indented (it matched **zero** times).

Validation: extract `varasm.c`, `real.h`, `config/mips/mips.c` and `config/mips/mips.h` from the tarball, run the
script, run it again, and diff against the build tree — **stable across runs** (identical md5) and identical to the
tested source except for the comments. Then the build tree was replaced with the script's own `varasm.c` and cc1 was
rebuilt from it, so the compiler that measures 137 of 139 *is* the one the recipe produces.

## 3. State

**Twelve of fourteen recovered functions are byte-exact**; the last two partials are now both single-issue:
`0x80024558` at **137 of 139** (the `$at`/`$v0` reload-scratch tie-break) and `0x8007e590` at **226 of 229** (a
`local_alloc` tie-break on one select). Corpus **43 cases, all passing**, suite unchanged, and the artefacts were
re-derived because a recovered function's published file changed: `src/`, `manifests/code_index.json`,
`manifests/analysis_status.json`, `manifests/call_graph.json`, the progress map and the toolchain chapter.

The transferable part is narrower than M290's and worth stating separately: **a toolchain recipe is code, and a guard
written to make one edit idempotent can silently disable the rest.** The check that catches it is cheap — apply the
script to a pristine tarball and diff against the tree you have been measuring with — and it had never been run,
because for thirty milestones the tree was always already patched.
