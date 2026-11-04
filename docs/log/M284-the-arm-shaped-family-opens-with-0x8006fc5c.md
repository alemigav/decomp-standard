# M284 — the arm-shaped family opens with `0x8006fc5c`: 53 of 53, on the second measurement

Both partials are parked as pins (`0x80024558` at `>= 136`, `0x8007e590` at `>= 226` with `case3 == 113`), and the
next target was chosen by a rule rather than by taste: **the family `-g` unlocked, smallest first.** `FUN_8006fc5c` is
**53 of 53 words byte-exact** with its **7-word jump table 7 of 7**, on the second compile.

## 1. Finding the family, and the smallest member of it

A scan for the dispatch idiom (`sltiu` bound, `lui`/`addiu` table, `lw v0,0(v1)`, `jr v0`) over the whole image
returns **five** sites, and three of them are the same shape `0x800701d8` has:

| head | extent | bound | what it is |
|---|---|---|---|
| `0x8006e6b8` | 29 words to the last arm | 7 | **not a function start** — embedded, and the enclosing code is in an index gap |
| `0x8006fc5c` | **53 words** | 7 | `FUN_8006fc5c`, and `0x8006fca0`'s dispatch is inside it — **smallest** |
| `0x8006fca0` | 35 words of arms | 7 | the dispatch itself, inside the function above |
| `0x8006ff48` | 98 words | 44 | function start, next in the family |
| `0x800704e0` | 123 words | 44 | function start, next in the family |

So the smallest real member is `0x8006fc5c` at 53 words, and it is a *different* arm shape from `0x800701d8`: 0x800701d8's
arms are loads that return a field, this one's arms are **stores**. Both are in the family the assembler fix opened.

## 2. What it does

```c
int FUN_8006fc5c(struct Ctx *ctx)
{
    p   = ctx->f1c;                        /* lw 28(r17)                    */
    a   = *(s8 *)(p + 2);                  /* lb  2(p)  -- signed           */
    idx = *(s8 *)(p + 3);                  /* lb  3(p)  -- the dispatch key */
    v   = *(u16 *)(p + 4);                 /* lhu 4(p)                      */
    rec = (u8 *)(*(u32 *)(ctx->f154 + 0x234) + a * 376);
    switch (idx) { ... }                   /* seven stores into rec         */
    ctx->f1c += 6;
    return 1;
}
```

The seven arms, read from the table rather than guessed: `rec+0x60` and `rec+0xcc` (the second is the return of
`FUN_800844cc((s16)v)`, with the sign extension visible as `sll`/`sra`), `rec+0x62` and `rec+0xce` as *bytes*,
then `rec+2`, `rec+0`, `rec+0x58`, `rec+0x5a`, `rec+0x5c` as halfwords. The `a * 376` is visible as
`(a*3)<<4 - a` then `<<3`, i.e. `a*47` then `*8` — gcc's multiply expansion, and a reminder that a constant's *shape* is
readable from the instruction sequence.

## 3. The one thing that was wrong, and why it is worth naming

First compile: **41 of 53**, three hunks, every mismatch inside the arm block. The arms were in *ascending* case order,
which is what a human writes. The image's arm addresses say the source wrote them as **2, 3, 0, 1, 4, 5, 6** — the
table maps index to arm, so the arm order in memory *is* the source order (M278's fixture: cc1 emits case bodies in
source order). Reordering the seven `case` blocks to that sequence is the whole fix, and it took the score from 41 to
**53 of 53**.

This is the third instance of the same lever and now the cleanest: **the arm order in the image is a fact about the
source, not about the compiler**, and it can be read straight off the jump table — `table[k]` addresses, sorted, are
the source's case order. Ascending is merely the most common case order, not the default.

## 4. Coverage

`0x8006fc5c` enters the probe as two pins at **exact** — the 53-word function and the 7-word table — so the corpus is
**36 cases, all passing**, the suite **72 suites / 1005 cases** with **725** needing the cartridge.

Recovered functions are now **ten**, of which **eight are byte-exact**: 46, 53, 53, 84, 98, 141, 167, 206 words. The two
partials stay at `136 of 139` and `226 of 229`, both allocation residue, both pinned.

The family still has three unmapped members — `0x8006ff48` (98 words, bound 44), `0x800704e0` (123, bound 44), and the
embedded `0x8006e6b8` (which needs its enclosing function found first) — so the next two targets are already sized and
identified, which is the point of doing this by rule.
