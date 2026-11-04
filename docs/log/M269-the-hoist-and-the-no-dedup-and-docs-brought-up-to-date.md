# M269 — the hoist and the no-dedup, tried together, and the docs brought up to date

Two instructions: hoist `4.0f` into a local so p8's source loads it once like the image, turn dedup off, and
re-measure; and update the README, which carries outdated information. The first is a measured negative with two
distinct causes; the second is larger than it looked — the README's phase table stopped at M199 and
`docs/TOOLCHAIN.md` was still describing the compiler as unavailable and the probe as a plan.

## 1. The experiment: both changes together, and p8 got worse

M268 established that the original's pool is **per use** (387 resolved pool loads, zero constants shared by two
loads, while 38 of 86 floats and 10 of 20 doubles sit at 2+ addresses) and that no-dedup is therefore the right
model, with M267's 46-word loss attributed to layout. So both changes were applied:

- **no dedup** on both paths (`immed_double_const`'s chain search and `force_const_mem`'s descriptor hash, for
  `SFmode`/`DFmode`);
- **`float k = 4.0f;`** hoisted into case 3/4's block, on the theory that the image loads the constant once and
  keeps it in `$f4`.

| build | p8 offset | p8 content | hunks |
|---|---|---|---|
| M268 state | **136 / 139** | 136 | 3 |
| hoist + no dedup | 115 / 139 | 134 | 6 |

**Two separate causes, both visible in the diff:**

1. **The pool's order flipped.** Ours became `[table][4.0f][2^32]`; the image is `[table][2^32][4.0f]`. Pool
   slots are emitted in the order the constants are *used*, and with the local hoisted the float is used first.
2. **The hoist made the load unconditional.** The image loads `4.0f` **after** the `bgez`, inside the fall-through
   path; with `k` declared at the top of the block, gcc emitted `lui %hi` + `lwc1` **before** the branch — three
   extra words, and the constant's register freed differently afterwards.

So the image's single `4.0f` slot comes from CSE, not from a hoisted local: the original source wrote the
multiplication twice and gcc loaded the constant once, *where the image loads it*. Our original source already did
that. Both changes were reverted; **p8 is back at 136/139** and the toolchain is at the M265 patch set again.

The lesson is the same one M264 and M265 taught: with a coupled pair, measure after each half — here the *second*
half (the hoist) was the one that broke, and it broke a layout property that the first half was supposed to fix.

## 2. The README's outdated parts

The phase table ran **P11 | M192–M199** and stopped, while the log is at M268 — 69 milestones with no row in the
one table a reader sees first. Added:

| phase | range | what happened |
|---|---|---|
| P12 | M200–M210 | the pool record's classes pinned from the data; two published corpus figures corrected |
| P13 | M211–M222 | the VM's opcode registry, a call graph whose edges carry evidence, verification split into tiers, `TYRANT` named as a codename, the three work packages that closed the sound family |
| P14 | M223–M230 | the RSP microcode decoded and deliberately not named; the vector unit named 252 of 254; the dispatch-head queue resolved |
| P15 | M231–M250 | **the toolchain identified** — the sound backlog closed, a verification prototype, splat's rehearsal, binutils 2.7 and IDO built natively, IDO refuted, gcc 2.7.2 then gcc 2.8.1 reproducing every probe |
| P16 | **M251–M268** | **whole functions reproduced from the image** — the probe corpus, three functions recovered, two byte-exact, and the build facts that made it possible |

And p8's row in *The matching build* was corrected to what M268 established: the differing pool entry is one the
original keeps **per use** where ours deduplicates — not "a duplicate the original emits", which was my
misreading.

## 3. `docs/TOOLCHAIN.md` was worse

Its section 2 was headed *"The compiler — named by the SDK's own makefiles, still not runnable here"* and section 4
*"The compile probe, ready to run"*, both written before either was true. Section 2's heading now says the compiler
is **runnable and proven**, and its conclusion distinguishes what the disc settled (which compiler) from what the
build settled (that it reproduces the cartridge). Section 4 is rewritten from plan to result, and it now also
records a real disagreement with the disc:

> The kit's makefile says `CC = gcc` with `CFLAGS = -c -O -G 0`, but **`-O2` is what reproduces the image** (`-O`
> misses by 10 words on the two byte-exact functions) — so either that makefile is the libraries' contract rather
> than the game's, or the game was built with different flags.

That is worth stating plainly because it is the kind of claim that gets quietly assumed: the SDK's own text is
evidence, but it is not a measurement of the game's build.

## 4. State

- **p6 byte-exact (98/98), p7 byte-exact (84/84), p8 136/139**, corpus **22 cases, all passing**, toolchain at the
  M265 patch set.
- Three documents now agree with the measurements: README (phases and the corrected p8 row), `docs/TOOLCHAIN.md`
  (compiler proven, probe run, the `-O` disagreement), and the log.
- Next for p8 is no longer "make the pool match": the pool's *order* is a consequence of use order in the source,
  and the image's order means its source wrote the 2^32 conversion before the multiply. Reconstructing case 3/4 in
  the image's statement order is the next concrete attempt.
