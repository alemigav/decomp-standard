# M262 — the last p7 hunk is unreachable from the source: five variants, one object

The instruction re-issued two earlier asks — "find the `mips.c` rule that sinks that store in case 0, then run
decomp-permuter against those 392 bytes". Both are already committed, and rather than redo them this records the
answers with their commits, then takes the piece that is actually still open: **p7's case 2**, the one hunk left in
that function, which is the same question one access pair further on.

## 1. Both re-issued asks, with their commits

- **"find the mips.c rule" → `14a33d2` (M258).** The first finding is negative: `config/mips/mips.c` has **no
  scheduler hook** — no `adjust_cost`, no issue rate, no DFA; every grep hit is `.set noreorder` emission. The
  port's contribution is three lines of `mips.md` (store READY-DELAY **1**, load **2** on R4300), and the decision
  is `sched.c`'s `priority()`, `prev_priority = priority (x) + insn_cost (x, prev, insn) - 1`, plus the dependence
  exemption shared by `true_dependence`/`anti_dependence`/`output_dependence`: **a struct-member access next to a
  non-struct access loses its dependence**, which lets the load be hoisted past the stores. Making the device
  window a struct member restored the dependence and took **case 0 to 14 of 14 words, byte-exact** (p7 60 → 74 of
  84).
- **"run decomp-permuter against those 392 bytes" → `a7a9cb9` (M259), and `6f5b4f5` (M256) before it.** Two runs,
  **242 202 iterations** total. The second ran against the improved base (1 980) and reached **1 780** with 20
  improvements — and the best two candidates score **28/98 offset, 82/98 content, 12 hunks, identical to the base
  in every column**. A 10 % gain in the permuter's penalty that moved **zero words**: it counts register numbers
  and operand order; the matching question counts instructions.

## 2. The open hunk: case 2, `lw 6752` above `sw 6748`

The image's case 2 ends

```
lw  v1,6748(v0)     # read the first device word
ori v1,v1,0x8000
sw  v1,6748(v0)     # RMW it back
lw  v0,6752(v0)     # THEN read the second word
sw  v0,68(a1)
```

and ours reads **both words back to back** before the RMW. The two accesses are the same base with provably
disjoint constant offsets (6748 against 6752), so the scheduler batches them and the store — latency 1, no
priority — drifts behind. M258's mechanism exactly, one pair further on.

Five sources were compiled through the real pipeline and scored against the image:

| variant | what it changes | offset | case 2 |
|---|---|---|---|
| v0 current | — | 74 / 84 | 10 / 20 |
| v1 second pointer | `dev2 = D_800C76B0` for the second read, so pre-reload RTL has two base pseudos | 74 / 84 | 10 / 20 |
| v2 plain load | the second read as `*(u32 *)(dev + 0x18000 + 0x1a60)` — **mixed kinds**, i.e. M258's lever applied in reverse | 74 / 84 | 10 / 20 |
| v3 store first | `D_80131780[0] = 1` moved above the RMW, matching where the image's `sb` lands | 74 / 84 | 10 / 20 |
| v4 q before rmw | `q = D_80131780` assigned before the RMW | 74 / 84 | 10 / 20 |

**All five produce byte-identical `.text`** (same 84 words, and the case-2 region is the same 20 words in every
one). That is a stronger statement than "the hunk did not move": the two loads are emitted adjacently whatever the
statement order, the number of base pointers, or the access kinds, because at RTL they are two independent loads
from one base with provably disjoint constant offsets — the data flow is the same in all five and only the
scheduler's batching rule decides the order.

## 3. What that implies

- **The source cannot reach this hunk**, so editing the C further is wasted effort and so is a permuter run: a
  mutator of expressions cannot find a difference that five different expressions do not produce. That is worth
  recording precisely because it is the boundary of the method, not a failure of it — M257's case 0 *was* reachable
  (one struct declaration, 14 words), and this one is not.
- The remaining explanations are all **build-side**, and both are testable next rather than guessable: either the
  image's compiler did not batch disjoint loads (a scheduling flag or a different `-O` setting — but `-O` is
  already refuted on both whole functions, and `-fno-schedule-insns` is a wash), or the two accesses in the
  original source were **not at provably disjoint offsets** at RTL time, which would mean my reconstruction of the
  offsets is right for the *compiled* output and wrong for the *source* (e.g. the original indexed a struct array
  rather than naming `reg`/`reg2`).
- p6's residue is the same shape and the same verdict (M255's `lbu` before the `mult`), so **both open functions
  are now blocked on the same build-side question**, not on reconstruction. That is the queue item to attack next,
  together with the one M261 left open: why the image's build chose a pool load where ours emits `li.s`.

## 4. State

No tool change, no reinterpretation of earlier numbers: **p7 74/84 offset with case 0 byte-exact**, **p8 118/139**,
**p6 82/98 content**, corpus **21 cases, all passing**. The only change this milestone makes is to the map: two of
the three open residues are now known to be unreachable from the C, which reorders the remaining work from
"reconstruct harder" to "identify the build".
