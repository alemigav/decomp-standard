# M292 — the `$at`/`$v0` partial closes: the image splits no float address, and `0x80024558` is 139 of 139

The last residue on the oldest partial was two words — the pool address built in `$at` in the image and in `$v0` in
ours — and it was not an allocation tie-break after all. It is a **mode test in the compiler**, one line, and with it
`0x80024558` is **byte-exact**.

## 1. The tell was that one `lui` served two loads

M270 had called this "an allocation tie-break: the pool address in `$at` rather than a gcc register". Two things
argued against that, and both were in the listing:

- `$1` is **fixed** in this configuration (`FIXED_REGISTERS` opens `1, 1, 0, …`), so gcc cannot have allocated it;
- the image has **three** `lui $1,0x800b` instructions around the pool loads, and in our object the first and third are
  *already identical to the image* — only the middle one differs.

Dumping our own `.s` explained it. cc1 emits

```
    l.d  $f0,$LC0                       ← symbolic operand, no register base
    lui  $2,%hi($LC1)
    l.s  $f4,%lo($LC1)($2)              ← split: high into a pseudo, low in the load
```

A *symbolic* memory operand is expanded by the assembler, which uses `$1` as its scratch — that is where the image's
`lui $1` comes from. So the two `l.d` loads match because cc1 left them symbolic, and the `l.s` differs because cc1
**split** it.

The split rule is one guard in `mips_check_split`:

```c
  if (GET_MODE_SIZE (mode) > UNITS_PER_WORD)     /* M292 */
    return 0;
```

A double is 8 bytes, so it never splits — the assembler expands it with `$1`. A float is 4 bytes, so it *was* being
split into a pseudo register. The image splits no float address at all, so the guard also excludes the float class:

```c
  if (GET_MODE_CLASS (mode) == MODE_FLOAT
      || GET_MODE_SIZE (mode) > UNITS_PER_WORD)
    return 0;
```

## 2. Measured, and nothing else moves

| build | p6 | p7 | p9 | `0x80059868` | `0x80059530` | `0x800acae4` | `0x8007e590` | **p8** |
|---|---|---|---|---|---|---|---|---|
| before | 98 | 84 | 46 | 167 | 206 | 53 | 226/229 | **137/139** |
| **M292** | 98 | 84 | 46 | 167 | 206 | 53 | 226/229 | **139/139** |

Plus the eight later functions (`0x800701d8` 141, `0x8006fc5c` 53, `0x8006ff48` 98, `0x800701d8`, `0x800704e0` 123,
`0x8006e68c` 41, `0x8006e574` 23) — unchanged, and the corpus at **43 cases, all passing**. Only `0x8007e590`'s
`local_alloc` tie-break is left.

The change can only ever *add* an assembler expansion, never break one: not splitting is always safe (the assembler
materialises the address), splitting is an optimisation. That is why it costs nothing anywhere else.

## 3. The recipe, checked the way M291 taught

M291 left the ability to check this cheaply, so it was used: the edit went into
`tools/toolchain/patch_gcc281_fp.py` as edit 8, then

- extract the four source files from the pristine tarball, run the script **twice** — applied, then a no-op;
- `diff` the result against the build tree: **identical**, file for file;
- rebuild cc1 **from the script's own source**, install it, and re-measure — 139 of 139 and 43/43.

So the compiler that produces these numbers is the one the committed recipe produces, which is the property M291 found
had been silently false.

## 4. State

**Thirteen of fourteen recovered functions are byte-exact**: 23, 41, 46, 53, 53, 84, 98, 98, 98, 123, 139, 141, 167,
206 words. The map reads **`3416 functions · █ 13 reproduced byte-for-byte · ▓ 1 recovered, residue itemised`**, and the
one partial is `0x8007e590` at 226 of 229 — three words, one register, in case 4's value select, pinned at `>= 226` with
`case3 == 113`.

Both of the residues that were called "allocation tie-breaks" turned out to be **toolchain facts** once they were read
as instruction shapes rather than register names: the pool's sharing rule (M291) and the float-address split (M292).
That is worth recording against the reflex itself — when a residue is two words and one of them is `$at`, the question
to ask first is *who emitted this instruction*, not *which register did the allocator pick*.
