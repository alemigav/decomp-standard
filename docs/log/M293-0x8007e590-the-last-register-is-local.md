# M293 — `0x8007e590` at 226 of 229: the toolchain is ruled out, and the last register is local

The instruction was to close this one out. It is **not closed**, and this note says precisely what stops it — because
the two attempts before this one both ended up *being* the toolchain, and the first job here was to find out whether
this residue is the same.

## 1. The M292 lens, applied first: who emitted the instruction?

`0x8007e590`'s three words are one register — the value of case 4's select:

```
image: li v0,22 ; bne v1,v0,L ; li v0,5 ; li v0,4 ; L: sb v0,5(s0)
ours : li v0,22 ; bne v1,v0,L ; li a0,5 ; li a0,4 ; L: sb a0,5(s0)
```

Our own `.s` answers the "who" question directly:

```
	lbu	$3,5($16)
	li	$2,22
	bne	$3,$2,$L27        ← $2 is live up to here
	li	$4,5              ← and the delay slot writes $4, not $2
	li	$4,4
$L27:
	sb	$4,5($16)
```

So the register is in **cc1's output**, not the assembler's — unlike M291 (the pool's sharing rule) and M292 (the
float-address split), which were both gas-side. And the two behaviours the toolchain patches touch (pool sharing,
address splitting) do not involve register allocation at all, so the toolchain is ruled out rather than merely
untested.

## 2. What the residue actually is: one *reuse*, not three words

Written as a register lifetime, the image does something ours does not:

```
image: $2 holds 22 → dies at the bne → $2 is *reused* for the select's value in the bne's delay slot
ours : $2 holds 22 → dies at the bne → the select's value goes to $4
```

Both are legal (the comparison is evaluated at the branch, so overwriting the operand in the delay slot is fine), and
local-alloc tries registers in ascending order, so `$2` *should* be the first choice in both builds. It is not, which
means our liveness says `$2` is still live at the slot insn. That is the whole difference: **one reuse decision inside
`local_alloc`**, three words of encoding.

## 3. Thirteen more shapes this pass, and the evidence that stops the obvious patch

Tried and measured (each on the current source, where the other 226 words are exact, so anything that moved the
register would read 229):

| shape | result |
|---|---|
| case-scope `u8 tv;` with `tv = sel; s->f5 = tv;` | 226 |
| function-scope `u8 tv;`, same two statements | 226 |
| case-scope `int tv;` | 226 |
| the select inside a nested `{ }` block | 226 |
| `register u8 *dev` on the device pointer | 226 |
| `(int)(s->f5 == 22) ? 4 : 5` | 226 |
| the device base written inline instead of through `dev` | 178 |

That brings the total across M277, M283, M290 and this pass to about thirty shapes, and every one lands on 226.

The tempting next move is a `local_alloc` patch — "let a pseudo defined in a branch delay slot reuse the register of an
operand that dies at the branch". Before considering it I scanned the image for the behaviour it would licence: a
conditional branch whose delay slot writes one of the compared registers. There are **2 687** such sites — but they are
dominated by the do-while idiom (`blez` with the counter decremented in the slot) and by stores, which gcc reaches
without any special rule. That count cannot distinguish "the original's allocator allowed reuse over a dying compare"
from "these are ordinary loop and store slots", so patching on it would be **over-fitting**: it would be a change
justified by one function's three words and by a statistic that does not measure what it appears to.

## 4. Where that leaves the function, and the arc

`0x8007e590` stays at **226 of 229**, pinned at `>= 226` with `case3 == 113`, and the progress map keeps it as the one
`▓`: **`3416 functions · █ 13 reproduced byte-for-byte · ▓ 1 recovered, residue itemised`**.

The overall result of the closing arc is worth stating plainly, because it inverts twice. Both residues that had been
recorded as "allocation tie-breaks" — `0x80024558`'s `$at`/`$v0` and this one — were assumed to be the same class.
One of them turned out to be **two toolchain facts** (the pool's per-use double, M291; the unsplit float address,
M292) and closed completely. This one, checked the same way, is **genuinely allocation**, and the check that
distinguishes them costs one `cc1` invocation and a look at the `.s`: *if the offending register appears in the
compiler's output, the assembler is innocent; if it does not, the compiler chose it.* M292's reflex — ask who emitted
the instruction — is what rules this one out, and that is a better outcome than a lucky patch: thirteen exact, one
residue with a named mechanism and a measured reason it is not steerable from the source.

What would close it, stated so the next pass does not re-derive it: a `local_alloc` change justified by evidence that
does not exist yet — a set of image functions where a delay slot provably reuses a *dying compare operand* and where
gcc's ordinary loop-counter idiom cannot explain it. Finding that set is a scan of its own, and it is the only open
thread this function has.
