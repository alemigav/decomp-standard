# M249 — the SDK-era assembler: `move` explained, and p3's residue is not the assembler

M248 ended with two candidate explanations for p3's two-word residue: the assembler's expansion of `sw rt,symbol`,
or something on the compiler side. This builds the SDK-era assembler and settles it.

## 1. binutils 2.7 (1996) builds, and it is the `move` answer

| tool | `int f(int a){return a;}` | the cartridge |
|---|---|---|
| **binutils 2.7 `as`** | `00801021` **`addu`** | `addu` |
| binutils 2.42 `as` | `00801025` `or` | — |
| IDO's `as1` | `00801025` `or` | — |

So the `move` → `addu` rewrite the corpus had been performing by hand is **what the real tool does**. With the 2.7
assembler wired in, the corpus no longer rewrites anything, and p1, p2 and p4 are byte-exact on their own.

## 2. It does not close p3, and that is the useful part

Re-linked through the SDK-era `as` at `0x80025D60`:

```
want: 3c028013 8c4214cc 10400003 | 3c038013 24020001 ac6244c0 | 03e00008 00000000
got : 3c028013 8c4214cc 10400003 | 24020001 3c018013 ac2244c0 | 03e00008 00000000
```

**Identical to the 2.42 result.** Both gas versions expand `sw $2,symbol` into `lui $at` + `sw $2,lo($at)` and both
fill the `beq` delay slot with the preceding `addiu`. The image has `lui $3` — a **general** register, not the
assembler temp — placed *before* the `addiu`, and stores through `$3`.

So the residue is **on the compiler side**: gcc must have materialised the address into `$3` itself. Two source
idioms were tested and neither reproduces it (`volatile` on the target, and an address in a pointer local); the
`volatile` form keeps the same schedule, and the pointer form emits `li $3,0x80130000` + `addiu`, four
instructions for the store instead of two.

That leaves one specific next test: **gcc 2.8.1** (1998, what a 1999 SDK would actually ship). p1/p2/p4 do not
distinguish 2.7.2 from 2.8.1 — they are three-instruction functions — but a store's address materialisation is
exactly the kind of thing that changed between those releases.

## 3. Two host problems, recorded not hidden

- **2.7's `ld` writes an empty file here.** It builds, runs, and emits zero bytes; linking therefore uses 2.42's
  `ld`, with 2.42's `objcopy` first, because 2.7 writes a `.symtab` whose `sh_info` modern `ld` rejects
  (*"local symbol at index N >= sh_info"*).
- **2.7's `configure` needs a modern `config.sub`**: it calls it with old-style multiple arguments, which current
  `config.sub` rejects and 2.7's own cannot answer for `aarch64-apple-darwin`.

`provision.sh` now builds all five toolchains — 2.42 `as`/`ld`, **2.7 `as`**, gcc 2.7.2, IDO 5.3 and 7.1 — and its
doctor reports each, including which one is the matching candidate and why.
