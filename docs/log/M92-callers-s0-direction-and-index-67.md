# M92 — one caller, the s0 direction corrected, and index 67 is a build stamp

## 1. Callers of `FUN_8003287c`: exactly one, and no pointer table

| question | answer |
|---|---|
| direct `jal` sites | **1** — stage-2 `0x80071ec0`, inside `FUN_80071e14` |
| `0x8003287c` present as a 32-bit word anywhere (function-pointer table) | **none** in 36 images |

So the routine is reached from one place, and the slot it is given is

```
0x80071eb8  lw   v0, 0x5284(s1)     ; the slot object installed at 0x80115284
0x80071ebc  lbu  a0, 3(v0)          ; slot = byte 3 of that object
0x80071ec0  jal  FUN_8003287c
```

**The slot is a runtime byte and cannot be bounded statically** (M90: the object comes from a heap
field, both ares dumps predate its installation).

## 2. Retraction: the `s0` direction — it is `slot < 32`, not `slot ≤ 16`

M91 said "`s0` is 1 exactly when the slot argument is ≤ 16". That was wrong, and the instruction
sequence says so plainly:

```
0x80032890  addiu a1,a0,-16          ; a1 = slot - 16
0x800328c0  sltiu v0,a1,16           ; (slot-16) < 16  →  slot < 32
0x800328c4  beq   v0,zero,0x800328d0 ; slot >= 32 → skip
0x800328c8  addu  s1,a0,zero         ; delay slot: s1 = slot
0x800328cc  addiu s1,zero,16         ; slot < 32 → s1 = 16
0x800328d0  addiu v0,zero,16
0x800328d4  bne   s1,v0,0x80032934   ; taken iff slot >= 32
0x800328d8  addu  s0,zero,zero       ; delay slot — always executed
0x800328dc  addiu s0,zero,1          ; fall-through — only when slot < 32
0x8003298c  sll   s4,s0,2            ; s4 = 4 when slot < 32
0x80032a58  addu  v0,s4,s3           ; s3 = 0x800eb264
0x80032a5c  lw    v0,0(v0)           ; slot < 32 → 0x800eb268 → pointer #2 → bank C's map
```

**One line: `s0 = 1` iff `slot < 32`; `s0 = 0` otherwise. Bank C's map is the one used for slots
below 32.**

That inverts the question the last two notes asked. It is not "is the slot ever ≤ 16" — it is **"is
the slot ever below 32"**, and only slot **16** maps to anything in that half (`array2[0] = 39`;
slots 17–31 are zero). So the precise reachable sets are:

| slot | map used | record |
|---|---|---|
| 16 | array 2 | **39** — bank C's first payload (`cart 0xb6248`) |
| 32–49, 51, 52, 54, 55, 56, 58, 59, 62, 63 | array 1 | 12 … 38 — **bank B** |
| 17–31, and the mapped slots' zero neighbours | array 2 | zero → `cart_record(0)` |

Two things follow that were not stated before: **exactly one bank-C record is reachable (39)**, and
**a slot in 17–31 would call `cart_record(0)`** — the `OVERLAYTABLENUM` header — because the code does
not test the map byte for zero before calling. That is either unreachable by construction or a latent
bug; nothing here distinguishes them.

## 3. If a bank-C record *is* selected, the failure is silent

All 28 of records 39–66 take **branch 2 (inflate)**: none has `stored == 0` and none has
`stored == span`. And `FUN_800327ec` **never checks the return value** of `0x800045dc`:

```
0x80032838  jal  0x800045dc     ; inflate
0x8003283c  addiu a0,sp,0x10    ; (delay) — no test of v0 afterwards
0x80032840  addiu a0,sp,0x10
0x80032844  lw   s0,0x24(sp)
0x80032848  jal  0x80004594     ; inflate_free
0x80032850  j    0x80032a1c     ; jump back into the common path
```

So the three candidate outcomes for a selected bank-C slot resolve to the **second** one:

* ~~never selected~~ — cannot be established statically (the slot byte is runtime), and the map *is*
  read for slots < 32, so this is not structurally excluded;
* **selected, fails silently** — the working hypothesis: zlib rejects the `CM != 8` stream, the return
  is discarded, `inflate_free` runs, and the destination keeps whatever it held (the bank base that
  the initializer pointed it at);
* ~~record interpretation wrong~~ — refuted: records 39–66 read `stored` 7 640 … 60 against spans
  52 112 … 880, all branch 2.

The distinguishing test is now behavioural, not structural: **watch the slot byte at `0x80071ebc` and
see whether it is ever 16**, and if it is, watch the destination after the failed inflate.

## 4. The two maps agree exactly — the "27-item list" was a transcription error

Both maps have the **same 28 nonzero slots**:

```
16, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
51, 52, 54, 55, 56, 58, 59, 62, 63
```

`array1` carries 11…38 across them, `array2` carries 39…66. The list published in M88/M90 had 27
entries because I dropped **63** while transcribing — the value at slot 63 is 38 (array 1) and 66
(array 2). The data never disagreed; my list did.

## 5. Index 67 is deliberate, and it points at the build stamp

Boot calls `cart_record(67)` at `0x80004964` with a **literal** `0x43`:

```
0x80004954  addiu sp,sp,-0x120
0x80004958  addiu a0,zero,0x43      ; a0 = 67
0x80004964  jal   0x80001180        ; cart_record(67)
0x8000496c  addiu s0,sp,0x10
0x80004970  addu  a1,s0,zero
0x80004974  addiu a2,zero,0x28      ; length 40
```

Index 67 is the `0xCDCDCDCD` slot at `0x80012580`, whose **cart pointer is `0xc8624`** — and
`0xc8624` is exactly where the bank-C container ends. The 40 bytes there are:

```
00 00 1f 9b 00 00 00 00 "Tue Sep 28 02:31:44 1999" 0a 00 00 00 00 00 00 0a
```

**A build timestamp.** So the 67th entry is a sentinel whose pointer field carries a real address to a
real string, its `stored` field is a fill pattern the reader ignores, and boot reads 40 bytes of it.
That is neither a bounds check nor an off-by-one: it is a third kind of entry, and the cart table is
`1 header + 66 load records + 1 stamp record`.

## 6. Window convention, and what the corrected window found

`find_readers.py` treats the window as **half-open `[lo, hi)`**, so covering record 66's full body
means `0x80012590`, not `0x80012580`. Re-run at the corrected end:

```
0 direct access(es) to 0x800123c0..0x80012590 ; 9 base+register access(es) within 0x40
    boot 0x80001bb8  lw base+reg where base=0x80012590  in 0x80001698
    …
```

`0x80012590` is `cart_record(68)` — one past the table — but it is also the base of **zlib's static
inflate tables** (M81), and that is what these accesses are. So cart-record iteration remains closed,
with one more reason to be careful with the number `0x80012590`: it is two different things depending
on which structure you ask about.

## 7. Retraction ledger additions

* **M91's `slot ≤ 16`** → **`slot < 32`** (§2). The direction of a branch, for the fifth time.
* **M90's "bank C is compressed 6–7×"** — already retracted in M91; the branch data here completes it:
  every bank-C record is branch 2.
* **M88/M90's 27-slot list** → the data always had 28 (§4); my transcript lost 63.

## 8. Next

1. **Watch `0x80071ebc`** for the slot byte. If it is ever 16, bank C is live and the failed inflate is
   the behaviour to explain. If it is never 16, the second map is unreachable in play and "dead data"
   returns with the runtime evidence it needed.
2. **Then** the destination after a failed inflate: does anything read it, and does the game notice?
