# M263 — `-mcpu=r4300`: p7 is byte-exact, and the "unreachable" residues were a build flag

M262 concluded that p7's last hunk was unreachable from the source, and that the remaining explanation had to be
build-side. It was — and the flag is the one the console's own CPU names. With `-mcpu=r4300` on **`cc1`** (not just
on `as`, where M260 already put it):

| function | before | after `-mcpu=r4300` |
|---|---|---|
| **p7** `0x80057e1c` (84 words) | 74 / 84, 2 hunks | **84 / 84, 0 hunks — byte-for-byte** |
| **p6** `0x8004fd1c` (98 words) | 76 / 98 offset, 82 content, 12 hunks | **86 / 98 offset, 90 content, 8 hunks** |
| **p8** `0x80024558` (139 words) | 118 / 139, 12 hunks | **136 / 139, 3 hunks** |

**p7 is the first whole function in this project reproduced byte-for-byte from reconstructed C.** Not a probe, not
a fragment: 336 bytes of real game code, head, seven arms and two fall-throughs, matching word for word.

## 1. How the indexed-struct-array experiment actually went

The instruction was to test whether an indexed struct array stops the two device loads batching. It does not — and
the way it fails is what produced the answer. Six constant-offset forms, every one compiled through the real
pipeline:

| form | case 2 |
|---|---|
| struct fields `->reg` / `->reg2` (current) | 10 / 20 |
| `->w[0]` / `->w[1]` — the two words as an **array inside the struct** | 10 / 20 |
| `((struct Pair *)(dev + 0x18000 + 0x1a5c))->a` / `->b` — a **pair struct** | 10 / 20 |
| `u32 *w = (u32 *)(dev + 0x18000); w[0x1a5c/4]` / `w[0x1a60/4]` | 10 / 20 |
| second base pointer (`dev2 = D_800C76B0`) *(M262)* | 10 / 20 |
| second read as plain `*(u32 *)` *(M262)* | 10 / 20 |
| **control**: `w[i]` / `w[j]` with **variable** indices | **2 / 20** — the batching stops |

So the mechanism is now pinned by a control rather than inferred: **gcc batches the two loads exactly when it can
prove the offsets disjoint, and any constant-offset spelling proves it.** A variable index stops the batching — but
it also adds `sll`/`addu` index arithmetic that the image's case 2 does not contain, so the image's source had
constant offsets. Same source shape, different schedule: the difference had to be in the build.

## 2. The rule, and why the cpu is the lever

M258 already quoted the mechanism; this says which input was wrong. `config/mips/mips.md` assigns the `memory`
unit's READY-DELAY per cpu:

```
147: (define_function_unit "memory" 1 0
       (and (eq_attr "type" "load")
            (eq_attr "cpu" "!r3000,r3900,r4600,r4650,r4100,r4300,r5000")) 3 0)
152: (define_function_unit "memory" 1 0
       (and (eq_attr "type" "load")
            (eq_attr "cpu" "r3000,r3900,r4600,r4650,r4100,r4300,r5000"))  2 0)
```

Without `-mcpu`, `PROCESSOR_DEFAULT` is not in the R4300 group, so a load costs **3**; with `-mcpu=r4300` it costs
**2**. That number is the only thing the MIPS port hands `sched.c`'s `priority()`
(`prev_priority = priority (x) + insn_cost (x, prev, insn) - 1`), so it decides how much every dependent
instruction is worth and therefore which order the list scheduler emits. A smaller load latency means less
incentive to hoist a second load early — which is exactly the two hunks that resisted six source rewrites.

Two things this explains that nothing else did:

- **why the four generic probes never saw it**: they are 8–36 bytes and have no scheduling slack, so both cpu
  defaults reproduce them (M250's 4/4 stands, and still holds with the flag);
- **why the residues clustered in the two biggest functions**: only code with enough independent instructions has
  a schedule the cost model can reorder.

And it closes the two "unreachable" claims honestly: they were **not** unreachable in principle, they were
unreachable *with the profile I had*. M262's table of five identical objects remains true and remains useful — it
proves the source cannot express the difference — but the conclusion drawn from it ("build-side, unknown") is now
replaced by a named flag.

## 3. Where the flag now lives

- **`cc1`**: the two `gcc2.8.1` profiles in `tools/compile_probe.py` carry `-mcpu=r4300`, and so do the three
  whole-function probes.
- **`as`**: already there since M260 (without it, binutils 2.7 inserts hazard `nop`s after every `mtc1`).
- **`mips-gcc-2.7.2` rejects the value outright** (`bad value for -mcpu=`), which is consistent with 2.7.2 being
  refuted for this target anyway — but it also means the flag is not portable across the two gccs and is applied
  only where it is accepted.

The pins moved with the measurements: p7 now asserts **84/84 with zero hunks**, p6 **≥90 content**, p8 **≥136
offset**, plus a new case that states the byte-exactness claim itself so a future compiler change cannot silently
break it.

## 4. State

- **Corpus 22 cases, all passing.** Three functions recovered and re-compiled: **p7 exact**, p6 90/98 content,
  p8 136/139 with case 0 and the epilogue exact and the table at the image's address.
- The next measurement is now obvious and cheap: **re-run p6 and p8's remaining hunks against the corrected
  profile** — p6 is down to 8 hunks and p8 to 3, and neither has been re-read with the cost model the image
  actually used. If the pattern holds, `-mcpu=r4300` is the last profile fact and the remaining work is arithmetic.
- The FP instrumentation from M261 is unaffected; the `li.s`-versus-pool question is still open, and it is a
  different question (a *predicate*, not a cost).
