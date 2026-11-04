# M285 — `0x8006e6b8`'s enclosing function found, and `0x8006ff48` byte-exact at 98 of 98

Two jobs, in the order asked. The embedded dispatch `0x8006e6b8` is inside **`FUN_8006e68c`, a 41-word leaf**, and the
next whole target, `FUN_8006ff48`, is **98 of 98 words byte-exact** with its **44-word jump table 44 of 44** — on the
second compile, for the same reason as the last two.

## 1. `0x8006e6b8`'s enclosing function: `FUN_8006e68c`, 41 words

The dispatch sat in an **index gap**, and the reason turned out to be interesting: the index contains entries at
`0x8006e6e0`, `0x8006e6ec`, `0x8006e6f4`, `0x8006e700`, `0x8006e708`, `0x8006e714` and `0x8006e720` — **the seven arms,
each indexed as if it were a function**, because they are jump-table targets. So the gap was not missing code; it was
one function chopped into its arms plus a head the index never named.

Walking back from the arms to the nearest prologue-free leaf start, and stopping at the previous function's `jr ra` +
delay slot, gives the real extent: **`0x8006e68c .. 0x8006e72c`, 41 words**, and the previous function ends exactly at
`0x8006e68c`. What it is:

```c
int FUN_8006e68c(struct Ctx *ctx)              /* leaf: no frame, no prologue */
{
    p   = ctx->f1c;                            /* lw 28(a0)                       */
    w   = *(u16 *)(p + 2);                     /* lhu 2(p)  -- operator + value   */
    v   = *(s16 *)(p + 4);                     /* lh  4(p)  -- signed operand     */
    ctx->f1c += 6;
    u   = *(s16 *)(0x800e8c78 + (w >> 8) * 2); /* table lookup, signed            */
    switch (w & 0xff) { ... }                  /* seven comparisons of u and v    */
}
```

The seven arms, from the table at `0x800b9540`: `u == v` (`xor` + `sltiu ...,1`), `v < u`, `!(u < v)` (`xori` with 1),
`u < v`, `!(v < u)`, `u != v` (`xor` + `sltu $0,..`), and `(u & v) != 0` — **the same seven-operator set as the exact
`0x80070120`**, which is a useful corroboration: this cartridge's "predicate dispatcher" idiom is the same shape
wherever it appears, and the arms here are 2–3 words each with the final comparison in the `jr ra` delay slot.

Not reconstructed yet: it is the natural *next* family member at 41 words, and its arms are comparisons (a third arm
shape, after loads in `0x800701d8` and stores here).

## 2. `0x8006ff48`: 98 of 98, and it is the accessor pair's write half

The head is the same idiom as the getter (`sltiu a1,44`, `lui`/`addiu` to `0x800b95f8`, `sll`, `addu`, `lw`, `jr v0`,
`nop`), but the arm shape is different: **each arm is a single store**, and only **2 words** — `jr ra` with the store in
its delay slot, so 9 + 43×2 + 1 + 2 = **98**, not the 141 a 3-word arm would give.

The 44 arms are the *same offsets as `0x800701d8`*, in the same index order — `2`, `0`, then `4`, `5`, `6`, `7`, `8`,
`10`, `11`, `16`, `40`, `44`, `48`, `100`, `102`, `104`, `418`, `426`, `496`, `606`, `608`, `610`, `616`, `624`, `626`,
`628`, `630`, `480` **as a byte**, `480` **as a halfword**, `482`, `484`, `490`, `304`, `308`, `306`, `310`, `314`,
`312`, `634`, `436`, `438`, `692`, `694`, `623` — with widths `u16`/`u8`/`u32` fixed by the opcode (`sh`/`sb`/`sw`).
So this is the **write half of the pair whose read half is `0x800701d8`**, and the two together are now both byte-exact,
which is the strongest evidence yet that the field map was read correctly: two independent functions, 88 arms, no
contradiction in any offset or width.

**The one thing wrong on the first compile (96 of 98) was again the arm order**: ascending scores 96 with exactly two
arms transposed, and writing `case 1` before `case 0` — the same transposition the getter needs — is the whole fix.
That is now the fourth instance of this lever, and the rule is settled: **sort the jump table's entries by address and
you have the source's case order**; ascending is the usual case, not the rule.

## 3. Coverage

`0x8006ff48` enters the probe as two **exact** pins — the 98-word function and the 44-word table — so the corpus is
**38 cases, all passing**, the suite **72 suites / 1007 cases** with **727** needing the cartridge.

Recovered functions are now **eleven**, of which **nine are byte-exact**: 46, 53, 53, 84, 98, 98, 141, 167, 206 words.
The two partials are unchanged and pinned (`136 of 139`, `226 of 229`), and the family still holds `0x800704e0`
(123 words, bound 44), the newly identified `0x8006e68c` (41 words, comparisons), and `0x8006fc5c`'s neighbour at
`0x8006e574` (23 words).
