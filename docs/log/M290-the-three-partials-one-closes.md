# M290 — the three partials: one closes, two are pinned where they are

The instruction was to take the three partials. One of them closed: **`0x8006e574` is 23 of 23 byte-exact**, up from
17. The other two did not move, and one of them gained a new refuted hypothesis rather than a new shape.

## 1. `0x8006e574` — closed, and the tell was an operand order I had already printed

M286 recorded this leaf at 17 of 23 with the residue as "one register and one schedule slot", and noted that the image
loads the table entry into `a0` where we use `v1`. What I had *also* printed, and did not act on, was the `addu`:

```
image: addu a0,a0,v0      table register + offset register
mine : addu v0,v0,v1      offset register + table register
```

That is the source's operand order showing through. The expression the image compiled is

```c
return ((*(u32 *)(D_80115090[a] + ((b >> 5) << 2)) & (0x80000000u >> (b & 31))) != 0) ^ (c == 0);
```

Two things were wrong, and either alone leaves the function short:

1. **the table pointer is the first addend** (`D_80115090[a] + off`, not `off + D_80115090[a]`) — which flips the
   `addu` and lets local-alloc put the table entry in the argument register `a0` that the cursor store had just freed;
2. **the offset is written as a shift** (`((b >> 5) << 2)`) rather than a multiply (`(b >> 5) * 4`) — a multiply makes
   cc1 fold the shift and the scale into one masked shift (`srl 7` + `andi 0x1fe`, the same fold M286 hit in
   `0x8006e68c`), while the source's explicit `<< 2` keeps `srl 8` + `sll 1`.

The scorer's history is a clean ladder, and the reversal alone was worth one word:

| source | score |
|---|---|
| `off + table`, `(b >> 5) * 4` (M286's best) | 17 / 23 |
| `table + off`, `(b >> 5) * 4` | 18 / 23 |
| `off + table`, `((b >> 5) << 2)` | 17 / 23 |
| **`table + off`, `((b >> 5) << 2)`** | **23 / 23** |

It enters the probe as an **exact** pin (and its builder no longer claims a jump table: this leaf has none of its own —
the seven-word table at `0x800b9540` belongs to its neighbour `0x8006e68c`).

## 2. `0x80024558` — unchanged at 136 of 139, and the assembler level is now ruled out

The residue is the two pool words: the image builds the pool base in **`$at`** (`lui $1,0x800b` + `lwc1 $f4,-0x6950($1)`)
where we build it in `$v0`, and its second pool entry is 8 bytes before ours.

M282's finding suggested a test that had not been run: `mips_optimize` gates *both* the branch swap (needs ≥ 2) and the
assembler's `lui`/`addiu` folding, and the only spelling that reaches level **1** — no swap, peepholes on — is `-O10`,
because the level-0 test is the `arg[1]` bug. If the original build had assembled at level 1, `$at` folding could be an
assembler artefact rather than a compiler register choice. Measured:

| assembler flags | `0x80024558` |
|---|---|
| none | 136 / 139 |
| `-g` (level 0) | 136 / 139 |
| **`-O10` (level 1)** | **136 / 139**, same three words |

So no: the `$at` base and the pool offset are `cc1`'s, which is what M268/M270 concluded from the other direction
(five hypotheses, including `-mno-split-addresses` at 95 words of collateral). This is a sixth, and it closes the
assembler as a suspect for this function the way M283 closed it for the others.

## 3. `0x8007e590` case 4 — unchanged at 226 of 229

The select's value register (`li v0,5` / `li v0,4` / `sb v0,5(s0)` in the image against our `a0`) survived three more
shapes in this pass, bringing the total to about twenty-five across M277/M283/M290. Nothing in that set moves it, and
with every surrounding instruction identical the live ranges are identical — `local_alloc`'s tie-break, the class M270
named and M283 re-confirmed. It stays pinned at `>= 226` with `case3 == 113`.

## 4. Coverage

**Twelve of the fourteen recovered functions are now byte-exact** (23, 41, 46, 53, 53, 84, 98, 98, 123, 141, 167, 206
words). The map reads **`3416 functions · █ 12 reproduced byte-for-byte · ▓ 2 recovered, residue itemised`**, and the two
remaining partials are the same three-word allocation residues as before, both itemised: `0x80024558` 136/139 and
`0x8007e590` 226/229. Corpus **43 cases, all passing**; the projection, the call graph and the status ladder were
re-derived (the leaf's `src/` file changed from pseudocode-with-residue to our reconstruction).

The generalisable part is the same one M281 produced, one layer down: **when a function is short by a handful of words
and everything around the residue matches, read the operand order.** `addu a0,a0,v0` against `addu v0,v0,v1` is not a
register difference, it is a *source* difference — and printing the instruction was enough to see it two milestones
before it was used.
