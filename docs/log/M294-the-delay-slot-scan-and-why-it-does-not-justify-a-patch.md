# M294 — the delay-slot scan: 718 sites, and it does **not** justify a `local_alloc` change

M293 left one thread open and named it: a `local_alloc` change ("let a pseudo defined in a branch delay slot reuse a
register that dies at the branch") would be justified only by evidence that the original's compiler did this and ours
does not. The scan was run. **The evidence says the opposite, and the decisive measurement is a four-line synthetic.**

## 1. The scan

For every conditional branch in the image (`beq`, `bne`, `blez`, `bgtz`, their likely forms, and the `regimm` pair), take
the compared registers and classify what the **delay-slot** instruction writes:

| slot instruction kind | sites writing a compared register |
|---|---|
| load / `lui` / `slt(i/u)` | 1 112 |
| other ALU (register-register) | 724 |
| **`li` (`addiu`/`ori`/`xori` with `$0`)** | **718** |
| read-modify-write (`addiu rX,rX,±k` — the loop counter idiom) | 112 |
| shift | 53 |
| `mfhi`/`mflo` | 13 |
| **total** | **2 732** |

The `rmw` row is the do-while idiom and is not evidence of anything. The **718 `li` sites** are the interesting class:
a constant is materialised into a register the branch just compared, which means that register's old value died at the
branch — exactly the shape `0x8007e590` has, and it appears in **336 distinct functions**. On the count alone, that
looks like a systematic behaviour our compiler is missing.

## 2. The count is not the measurement — this is

Our own cc1, given the same shape in isolation:

```c
int sel(void)  { s[5] = (s[5] == 22) ? 4 : 5; return 0; }                 /* p8's expression */
int sel3(void) { unsigned t; t = s[5]; s[5] = (t == 22) ? 4 : 5; return 0; }
```

```
sel:                                      sel3:
	lbu	$3,5($5)                          lbu	$3,5($4)
	li	$2,22                             li	$2,22
	bne	$3,$2,$L2                         bnel	$3,$2,$L9
	li	$4,5        ← no reuse            li	$2,5        ← reuse of $2
	li	$4,4                              li	$2,4
$L2:	sb	$4,5($5)                  $L9:	sb	$2,5($4)
```

**Our compiler does reuse a dying compare operand in a delay slot.** It does it when the value is read into a named
temporary first, and in that shape it also *annuls* the branch (`bnel`), where the image has a plain `bne`. So the
behaviour is present and coupled to the expression shape — there is no missing rule to install.

## 3. And the shape that triggers it is not usable here

Putting that shape into case 4 — a `u8` (or `int`) temporary read inside the branch, then selected — costs far more
than the three words it would win, because the extra load/scheduling changes the surrounding block:

| source | result |
|---|---|
| current (direct select) | **226 / 229** |
| `u8 t = s->f5; s->f5 = (t == 22) ? 4 : 5;` inside the branch | 194 |
| the same with `int t` | 194 |
| `t = s->f5;` before the device test, select from `t` | 187 |

## 4. Answer

**No.** The scan does not justify a `local_alloc` change, and the reason is specific rather than a judgement call:

- the pattern is **not absent** from our compiler — it reproduces it, in the shapes that produce it, with the annul bit
  the image does not have;
- a patch would therefore be aiming at a behaviour we already have, and its justification would rest on a count
  (718 sites) that does not distinguish "the original's allocator allowed reuse" from "our allocator allows reuse in
  the same situations, and this site is one where a different tie-break won".

`0x8007e590` therefore stays at **226 of 229**: thirteen of fourteen recovered functions byte-exact, one partial with a
measured mechanism, and — as of this scan — no open thread at all. The next thing that could move it is not a rule but a
*site-specific* explanation: why, in this expression shape, our allocator's tie-break loses to the image's. That is a
question about `local_alloc`'s internals on one basic block, not something a patch should be written for blind.
