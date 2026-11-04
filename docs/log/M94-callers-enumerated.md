# M94 — callers of `FUN_8003287c`, enumerated, and the slot values they pass

## The enumeration — one caller, four ways of looking for more

| how a call could exist | result |
|---|---|
| direct `jal` | **exactly 1** — stage-2 `0x80071ec0`, inside `FUN_80071e14` |
| `lui`+imm construction of `0x8003287c` followed by `jalr` | **none** in 36 images |
| `0x8003287c` present as a 32-bit word (pointer table) | **none** |
| branch/jump into the function body (`0x8003287c..0x80032910`) from outside | **none** — the only other transfers into that range are the function's own internal `beq 0x800328d0` and `regimm 0x800328ec` |

So there is one call site, it enters at the function start, and nothing else reaches the routine.

## The slot values: no literals, one runtime byte

```
0x80071eb8  8e225284  lw   v0, 0x5284(s1)    ; s1 = 0x8011xxxx → the object pointer at 0x80115284
0x80071ebc  90440003  lbu  a0, 3(v0)         ; slot = byte 3 of that object
0x80071ec0  0c00ca1f  jal  FUN_8003287c
```

**No call passes a literal slot**, because there is only one call and its argument is a byte read from
memory. The value is one per call, and `M90`/`M92` established that the object is a heap structure
installed by one conditional store (`0x80071e5c`) that neither existing ares dump captures.

What each possible value then does — the whole range, since the byte is unchecked:

| slot | index `slot-16` | behaviour |
|---|---|---|
| 0–15 | **negative** | reads the word(s) *before* the 48-byte map — the byte index is not bounds-checked |
| **16** | 0 → record 39 | bank C's first payload; zlib rejects it (`CM != 8`); the return is discarded, so the destination keeps its prior contents |
| 17–31 | map byte 0 | `cart_record(0)` is `OVERLAYTABLENUMC`; `record[1] = 0x4c415954 ≠ 0` so branch 2 fires: **inflate 1.28 GB from cart `0x0f564552`**, four times past the cartridge end |
| 32–63 | 16–47 → records 11–38 | bank B; the live path |
| 64–255 | > 47 | reads past the end of the 48-byte map into whatever follows |

Two of those ranges (0–15 and 64–255) are unchecked index excursions, and 17–31 is an
out-of-cartridge read. Only 32–63 is a normal path.

## Reachability of the single caller

`FUN_80071e14` has **no `jal` caller** either, but its address **does** appear as data — at
`0x801139a8`, inside a run of in-image pointers at `0x80113898..0x80113ac8` (141 words, stride 4;
only 55 of the targets begin with a prologue, so the run may hold more than one structure).
`find_readers.py` finds **no constructed-base access** to `0x801139a8` and **no base+register access
within 0x40**, so the table is read through a base that itself came from memory — beyond static reach,
the same wall as the slot object.

Chain, as far as it is established:

```
[ untraced reader ] → *0x801139a8 (entry 68 of a pointer run) → FUN_80071e14
                    → slot = byte 3 of *(0x80115284) → FUN_8003287c → cart_record → FUN_800327ec
```

## One more arithmetic slip, caught by the tool

Locating the table, I converted `2148612520` to `0x80113a68` in my head. It is `0x801139a8` — off by
`0xC0`. I then read the wrong address and got a table of *different* functions, which looked plausible
(the neighbouring words were real code pointers) — exactly the failure mode of the four earlier
address errors, and the sixth instance. The right answer came from asking `vaddr`/`find_readers`
instead of subtracting in my head, which is what those tools exist for.

## Next

The slot byte is the only remaining unknown in this path, and it is a runtime value: watch
`0x80071ebc` for `a0 ∈ [16, 32)` (two distinct failure modes) and, more broadly, log the byte's
distribution to see whether slots 32–63 (the live path) are what actually occur.
