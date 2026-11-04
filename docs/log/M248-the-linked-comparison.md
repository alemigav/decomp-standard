# M248 — the linked comparison: p3 resolves and the residue is two words, in the assembler

M247 left p3 as "unfalsifiable until linked", because an object holds **relocations, not addresses**. This runs
it: `cc1` → `as` → **`ld` with a script placing `.text` at `0x80025D60`** → compare with the image. The link
works, and what remains is a two-word window whose cause is now identified.

## 1. The pipeline

```
cc1 -quiet -O2 -G 0 -mips2 p3.c -o p3.s      # the compiler
as -EB -mips2 -G 0 -o p3.o p3.s              # the assembler (its own -G 0 matters)
ld -T p3.ld -o p3.elf p3.o                   # .text at 0x80025D60
```

The linker script is **generated from the symbol names**, because this project already names globals by address
(`D_801314CC`): every undefined `D_XXXXXXXX` symbol becomes `D_XXXXXXXX = 0xXXXXXXXX;`. A name that does not carry
an address makes the link fail rather than place the symbol at zero — the script cannot silently guess.

Two things had to be got right, both measured:

- **`as` needs `-G 0` as well as `cc1`.** Without it the assembler puts the definition in `.sbss` and emits
  `R_MIPS_GPREL16`, and the link dies with *"small-data section too large"*. The compiler flag alone is not the
  contract; both tools take a `-G`.
- **The source condition is inverted from my first guess.** The image branches `beq v0,zero,+3` — *skip the store
  when zero* — so the C is `if (D_801314CC != 0) D_801344C0 = 1;`, not `== 0`. A byte diff cannot tell a wrong
  branch polarity from a wrong compiler; the linked comparison plus reading the branch target did.

## 2. The result: 6 of 8 words, and the two that differ are the same three instructions

```
want: 3c028013 8c4214cc 10400003 | 3c038013 24020001 ac6244c0 | 03e00008 00000000
got : 3c028013 8c4214cc 10400003 | 24020001 3c018013 ac2244c0 | 03e00008 00000000
                                     ^^^^^^^^ delay slot      ^^^^^^^^ register
```

Both sides do the same three operations — materialise `0x801344C0`, set `v0 = 1`, store — but the image hoists
the address `lui v1` **into the `beq` delay slot** and stores through `v1`, while ours puts the `addiu` in the
slot and stores through the assembler temp `$at`. That is the **assembler's expansion of `sw rt,symbol` plus its
delay-slot fill**, the same class as M247's `move` → `or`/`addu` finding: the 1998 `as` expanded and scheduled
differently from binutils 2.42.

Not a compiler difference, and not fixable in the C. Two ways forward, both cheap: build the SDK-era `as`
(binutils ~2.6) and re-link, or model the two expansion rules explicitly the way the corpus already models
`move`. The first is the more faithful and is now the only missing piece of the toolchain.

## 3. What the corpus reports now

| probe | class | gcc 2.7.2 (linked) | IDO |
|---|---|---|---|
| p1 empty | no code | **MATCH** | MATCH |
| p2 return an argument | move idiom | **MATCH** | differ (homes args) |
| p3 conditional global store | **linked** | 6 of 8 words; residue = store expansion + delay slot | differ |
| p4 byte-copy loop | delayed branch | **MATCH** | differ |

Three exact, one with a two-word window attributed to the assembler. The corpus grew from 5 to 6 cases: the last
one asserts that p3 is *compared after linking* — the point being that its verdict now means something, not that
it passes.
