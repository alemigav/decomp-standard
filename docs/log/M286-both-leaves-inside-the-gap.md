# M286 — both leaves inside the gap: `0x8006e68c` byte-exact at 41, `0x8006e574` at 17 of 23

Both targets taken in the order asked. The first is exact on the fourth shape; the second stops six words short, and the
residue is one register plus one schedule slot. A third finding fell out of the second one: **the progress map cannot
show either function, because `manifests/code_index.json` does not contain their addresses.**

## 1. `FUN_8006e68c` — 41 of 41, and the shape that made it exact

The first three compiles scored 12, 28 and 39 of 41, and each miss was a *type* decision rather than a statement order:

| source | score | what the compiler did |
|---|---|---|
| `u16 w`, `s16 u`, `s16 v` | 12 / 41 | loaded `lhu` and sign-extended **late**, once per arm (`sll`/`sra` in each) |
| `u16 w`, `int u`, `int v` | 28 / 41 | `lh` correct, but hoisted the table's `lui`/`addiu` above the loads |
| `u32 w`, `int u`, `int v`, plain `D[w >> 8]` | 28 / 41 | same hoist |
| `u32 w`, `int u/v`, `*(s16 *)&D[w >> 8]` | 39 / 41 | everything right except the index arithmetic |
| `u32 w` + the address-of load, index written plainly | **41 / 41** | — |

Two levers are worth naming. **`int`, not `s16`, for the two signed operands**: an `s16` local makes cc1 keep an
HImode pseudo and re-extend at every use, which is five extra instructions across seven arms; the load opcode
(`lh` against `lhu`) is the tell. And **`u32`, not `u16`, for the dispatched word**: with a `u16` `w`, cc1 folds
`(w >> 8) * 2` into `srl 7` + `andi 0x1fe`, which is two instructions where the image has `srl 8` + `sll 1`. Widening
the local blocks the fold. The address-of cast on the table read (`*(s16 *)&D_800E8C78[w >> 8]`) is the remaining
piece: without it cc1 keeps the value in HImode and extends late again.

What it is: a leaf that reads `p = ctx->f1c`, `w = *(u16 *)(p + 2)`, `v = *(s16 *)(p + 4)`, advances the cursor by 6,
loads `u = *(s16 *)&D_800E8C78[w >> 8]` and returns one of seven comparisons of `u` and `v` — `==`, `>`, `>=`, `<`,
`<=`, `!=`, `(u & v) != 0`. The out-of-range path falls out of the switch to `jr ra` with v0 still 0, the same
no-`default:` shape as M278. **Its operator set is identical to the exact `0x80070120`**, which is the second
independent sighting of this cartridge's predicate-dispatcher idiom.

## 2. `FUN_8006e574` — 17 of 23, and what the six words are

The bit-test leaf: `p = ctx->f1c`, `a = p[1]`, `b = p[2]`, `c = p[3]`, cursor += 4, and

```c
return ((*(u32 *)(D_80115090[a] + (b >> 5) * 4) & (0x80000000u >> (b & 31))) != 0) ^ (c == 0);
```

`lbu` loads with `sra` on `b` are only consistent if `a`/`b`/`c` are `int` (a signed shift of a zero-extended byte), and
that part reproduces exactly. The remaining six words are:

```
image: lw a0,0(v1) ; lui v1,0x8000 ; srlv v1,v1,a1 ; addu a0,a0,v0 ; lw v0,0(a0) ; sltiu a2,a2,1 ; and ; sltu
mine : lw v1,0(v1) ; sltiu a2,a2,1 ; addu v0,v0,v1 ; lui v1,0x8000 ; lw v0,0(v0) ; srlv v1,v1,a1 ; and ; sltu
```

So it is **one register** — the image loads the table entry into `a0`, the argument register the cursor store has just
freed, where ours uses `v1` — and **one schedule slot**, where the `c == 0` test sits (`sltiu` late in the image, early
in ours). Ten shapes were measured and none of them moved either: array indexing (`t[b >> 5]`), a `u32 *` local, a
`u8 *` local with byte arithmetic, pointer-array typing (`u32 *D[]`), inline reads with no `p` local, a `mask` local
computed before the load, a `z = (c == 0)` local, `^ !c`, `^ (c < 1)`, `^ (0 == c)`, and `(c != 0) != bit`. That is the
`0x80024558` / `0x8007e590` class again, at 6 of 23 words — recorded as a **partial pin at `>= 17`**, with the residue
named in the case text rather than a threshold nobody can read.

## 3. The progress map cannot show these two, and that is an index defect

`tools/progress_map.py --check` refuses a `MATCHED` entry whose address is not in `manifests/code_index.json`, and it
was right to: **the index does not contain `0x8006e68c` or `0x8006e574` at all.** It contains seven entries at the arm
addresses — `0x8006e6e0`, `e6ec`, `e6f4`, `e700`, `e708`, `e714`, `e720` — precisely because the arms are jump-table
targets, and it never names the enclosing leaf. That is the same defect M285 found from the other direction, and it has
two consequences worth stating rather than hiding:

- the map's summary line reads **9 byte-for-byte and 2 recovered**, against the prose's **ten exact and three
  partial**, and the README's P16 row now says which two functions are invisible to it and why;
- so **the map currently under-reports progress**, which is the opposite of its purpose but the honest direction to err
  in: it cannot invent a function the index does not have.

Fixing it means regenerating `manifests/code_index.json` with the arm-target heuristic replaced by a real boundary
walk, which moves the "3 638 functions" claim and every derived byte count — a milestone of its own, not a footnote to
this one.

## 4. Coverage

The corpus is **41 cases, all passing**: `0x8006e68c` enters as two **exact** pins (the 41-word function and its
7-word table), `0x8006e574` as one partial pin at `>= 17`. Suite **72 suites / 1010 cases**, **730** needing the
cartridge. Recovered functions are **thirteen**, of which **ten are byte-exact** (41, 46, 53, 53, 84, 98, 98, 141, 167,
206 words); the three partials are `136 of 139`, `226 of 229` and `17 of 23`, all allocation residue with the mechanism
named. The family's remaining sized target is `0x800704e0` (123 words, bound 44).
