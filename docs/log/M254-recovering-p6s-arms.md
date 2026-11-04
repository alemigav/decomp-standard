# M254 — p6's arms recovered: the delay slot matched, and the rest is a reconstruction in progress

M253 showed each head puts a different instruction in the branch delay slot, and argued the slot is the *arms'*
business. This tests that by recovering p6's arms and re-compiling the whole function.

## 1. The function, from its instructions

`0x8004fd1c`, 392 B across six pieces: a 40-byte head and five arms at `0x8004fd44`, `…d54`, `…da0`, `…df4`,
`…e50` — every one of them a separate range in the corpus, which is the head-plus-arms structure M228 found.

Read from the disassembly, the arms are a four-byte state machine: `s[0]` a mode byte, `s[1..3]` a counter and its
two limits, `a1` a `short *` output, `a2` the switch index.

| arm | what it does |
|---|---|
| 0 | `*p = s[3] << 4` |
| 1 | `*p = (s[1]/s[2]) << 4`; if `s[1] == s[2]*s[3] - 1` return; `s[1]++` |
| 2 | `*p = (s[1]/s[2]) << 4`; `s[1]++`; if `(u8)s[1] != s[2]*s[3]` return; `s[1] = 0` |
| 3 | same, then `s[1] -= s[2]` and `s[0] = 132` |
| 4 | `s[1]--`; `*p = (s[1]/s[2]) << 4`; if `s[1] == 0` then `s[0] = 131` and `s[1] += s[2]` |
| default | return |

The divisions are `divu` with gcc's zero check — that is where the `break`/`0x0007000d` pairs come from, and they
appear in four of the five arms, which is why they dominate the byte count.

## 2. The result: the delay slot matches, and it is the last thing to match

| region | image | words identical | first difference |
|---|---|---|---|
| **head** | 40 B | **9 of 10** | `0x8004fd20` — the `beq` offset |
| **arm0** | 16 B | **4 of 4** | — |
| arm1 | 76 B | 13 of 19 | `0x8004fd78` — the multiply's operands |
| arm2 | 84 B | 1 of 21 | `0x8004fda0` |
| arm3 | 92 B | 0 of 23 | `0x8004fdf4` |
| arm4 | 84 B | 0 of 21 | `0x8004fe50` |
| total | 392 B | **27 of 98** | compiled 416 B (+24) |

**The delay slot matched.** My compiled head contains `addu a3,a0,zero` exactly as the image does, because the
recovered arms read the pointer through `a3` and gcc's allocator put it there. Before the arms existed there was
nothing to fill the slot with and the `lui` took it (M252). So M253's claim holds in the strongest available form:
the slot is a consequence of the arms, and it becomes comparable only when they are right.

The head's one remaining difference is the **branch offset** — `0x5e` against `0x62` — which is not a codegen
difference at all: it is the distance to the default arm, i.e. the arms' total size, and mine is 24 bytes too
large because arms 2–4 are not yet right.

## 3. Where the reconstruction stands, stated as numbers

- **arm0 is exact** and **arm1 is two thirds right** (13 of 19 words) — its first difference is the operand order
  of the `mult` that computes `s[2]*s[3]`, which suggests the original expression multiplies in the other order
  or through a different temporary.
- **arms 2–4 are wrong**, and the first difference in each is telling: the image loads (`lbu v0,1(a3)`) where
  mine stores (`sb v0,1(a3)`, `a0e20001` at `0x8004fda0`). My C increments the counter *before* the division; the
  original divides first and increments after, so the whole block is scheduled differently.
- 27 of 98 words with the function 24 bytes too large. That is a **reconstruction in progress**, and the artefact
  says so in exactly those words rather than rounding it up.

## 4. What this establishes

Stage 3 is not a formality: the head and one arm came out byte-exact from a disassembly reading, and three arms
did not. The corpus now carries the whole function as a probe, so each iteration on the C is measured against all
392 bytes and attributed to a region — which is the loop that makes the remaining work tractable, and the reason
`decomp-permuter` (672★ on the m2c side) exists.

The delay-slot question is closed. The question it leaves is the ordinary one: writing the arms' C with the
original's *order of operations*, which is what the 71 remaining words cost.
