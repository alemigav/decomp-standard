# M7 — The ROM→VRAM mapping was wrong, and it invalidated every address so far

**Status:** corrected, three independent proofs. Supersedes the address claims in
`M3-libultra-naming-and-research.md`, `M4-bank-structure.md` and `M5-pi-loader-found.md`.

## The correct mapping

```
vram = rom_offset + 0x7FFFF480        (for the boot bank)
ROM 0x1000  <->  vram 0x80000480
```

`splat create_config` had this right from the start (`vram: 0x80000480`). The error was mine:
`tools/wrap_mips_elf.py`'s usage example wrapped at `--base 0x80000000`, so every arithmetic
`vram = 0x80000000 + (rom - 0x1000)` in the notes — and every Ghidra read on such a wrapper —
landed **0x480 bytes (1152 B) too high in vram, i.e. 0x480 too low in ROM**.

## Three independent proofs

Each one alone would be suggestive; together they close it.

1. **`jal` targets land on prologues.** Decoding the 554 `jal` instructions in the boot bank and
   mapping the target back to a ROM offset, then asking whether that word is an
   `addiu sp,sp,-N` prologue:

   | vram of ROM 0x1000 | targets in bank | land on a prologue |
   |---|---|---|
   | `0x80000000` | 533 | 5 (0.9%) |
   | `0x80000400` | 534 | 4 (0.7%) |
   | **`0x80000480`** | **535** | **302 (56.4%)** |
   | `0x80000800` | 532 | 1 (0.2%) |

   Chance alignment of `0x27BD…` words at 302 independent offsets is not a thing.

2. **Embedded strings' addresses are constructed in code.** Collecting every `lui`+`addiu`/`ori`
   constant pair in the image, then asking how many of the 19 241 ASCII runs past the code end have
   their address built that way:

   | base | strings whose address is constructed |
   |---|---|
   | **`0x80000480`** | **26** (`invalid block type`, `invalid stored block lengths`, `invalid distance code`, …) |
   | `0x80000400` | 4 |
   | `0x80000000` | **0** |

   Zero under the old base. This test needs no code-shape heuristic at all.

3. **The first bytes of the bank are a boot entry.** ROM 0x1000 is
   `lui sp,0x803F ; ori sp,sp,0xFFF0` — stack pointer set to the top of RDRAM — then
   `lui t0,0x8001 ; addiu t0,0x38A0` and `lui t1,0x8002 ; addiu t1,0x8A80`. Only a cold entry
   initialises `sp`. Under the old base this word was vram 0x80000000 and the header entry
   (0x80000480) pointed at ROM 0x1480, mid-function.

Corroboration: under base 0x80000480, **144 / 243** of splat's own function starts land on
prologues (the other 99 are genuinely frame-less leaves); under base 0x80000000 only **3 / 243** do.

## What this invalidates

- **The three "libultra callees" were read at the wrong ROM offsets.** The *shapes* are real code,
  but they are not at the addresses they were named after:

  | named | what is actually at that address | where the described bytes really are |
  |---|---|---|
  | `0x80000CE4` "eret stub" | `03e09025` = `move s2,ra` — **a real splat function start**, and the target of 4 `jal`s | the `nop; eret` is at **`0x80001164`** (mid-function) |
  | `0x80000F08` "epilogue" | `0080c825` = `move t9,a0` | `lw s5,0x14(sp)…` epilogue is at **`0x80001388`** |
  | `0x80000F60` "alloc scan" | `lui a0,0x8001` | `(n+7)&~7` alignment block is at **`0x800013e0`** |

  So `0x80000CE4` is *not* an exception-return stub; it is an ordinary function that four sites
  call, which resolves the Arc-24 contradiction ("`jal` targets the `nop; eret` address") — the
  `jal`s target a normal function, and the `eret` was simply at a different offset.

- **The DMA functions have callers after all.** With corrected addresses:

  | function | vram | callers |
  |---|---|---|
  | A — PI programmer (460 B) | **`0x80007C20`** | 3, all in-bank: `0x80007804`, `0x8000799C`, `0x80007A54` |
  | B — raw PI path (208 B) | **`0x8000C870`** | 1: `0x80000610` |

  Both are genuine function starts with frames (`addiu sp,sp,-0x28` and `-0x20`) and save `s0`/`s1`.
  The earlier "zero direct callers anywhere in 64 MB" was an artefact of sweeping for the encoding
  of addresses that were not the functions.

- **The cross-bank foothold at ROM `0x16264DD` does not exist.** It was an unaligned byte match
  (M6), and it was a match for the encoding of a mis-mapped address. There is nothing there.

- **"Ghidra and splat disagree on the entry extent" was the mapping bug, not a tool disagreement.**
  The two were reading ROM offsets 0x480 apart and labelling both with the same numbers.

## What survives unchanged

- Code boundary `0x1000`–`0x12140`, 243 functions, 69 176 B, `unknown 67 MB (99.89%)`.
- The cartridge is banked (30 687 in-range pointers across all 64 64 KB buckets).
- The region past the code end is mostly the runtime, including a **zlib `inflate`**
  (`invalid block type`, `invalid distance code`, `incorrect data check`, `insufficient memory`).
- The ROM→VRAM map is not a stored table of `(rom, vram)` pairs (M6).

## The new lead the corrected constants exposed

The boot init calls B at `0x80000610` with a four-argument pattern; the two instructions before it
build the mask `lui v0,0x0FFF ; ori v0,0xFFFF` = `0x0FFFFFFF` and the delay slot applies it:

```
0x80000600  addu a0,zero,zero          a0 = 0
0x80000604  addu a2,s1,zero            a2 = s1
0x80000608  lw   a1,0(s0)              a1 = *s0        <- a descriptor field
0x8000060c  addu a3,s2,zero            a3 = s2
0x80000610  jal  0x8000C870            B(a0,a1,a2,a3)
0x80000614  and  a1,a1,v0              delay: a1 &= 0x0FFFFFFF  (28-bit physical mask)
```

So B is invoked **with a physical address masked out of a loaded word**, and `s0` is a pointer to a
descriptor. That is the shape of a bank loader after all — the argument triple is
`(0, phys & 0x0FFFFFFF, s1, s2)` rather than `(dram, cart, len)`.

## Method note

The mistake was arithmetic, not judgement: one example line in a tool's docstring set the base, and
fifteen note files inherited it. **Any vram address must be checked against a base recovery test
before it is used**, which takes seconds:

    for each candidate base: fraction of jal targets landing on prologues + count of
    embedded-string addresses that are constructed as lui/addiu constants
