# M91 — the bank-C map *is* read, and bank C is not compressed

Two things I asserted in M89/M90 are wrong. Both were caught by the same class of mistake, and both
are retracted here with the measurement that overturns them.

## 1. Retraction: "there is no bank-C caller"

M89 closed the map as an entry point with four checks. **The reader exists** — at `0x80032a5c`, in the
same function M89 was looking at:

```
0x800329f4  addiu s3,v1,-19868      ; s3 = 0x800eb264  — the address OF the pointer pair
0x800329f8  bne  s0,zero,0x80032a58 ; two branches, selected by s0
   …
0x8003298c  sll  s4,s0,2            ; s4 = s0 << 2   → 0 or 4
0x80032a58  addu v0,s4,s3           ;   s4 + 0x800eb264
0x80032a5c  lw   v0,0(v0)           ;  s0=0 → pointer #1 (bank B); s0≠0 → pointer #2 (bank C)
0x80032a60  addu v0,s1,v0           ; + slot
0x80032a64  lbu  a0,-16(v0)         ; a0 = map[slot-16]
0x80032a68  jal  0x80001180         ; cart_record(index)
```

So the loader reads **both** maps, choosing between them with a 4-byte offset.

**Corrected (M92): the condition is `slot < 32`, not `slot <= 16`.** `a1 = slot - 16`;
`sltiu v0,a1,16` tests `slot < 32`; `s1` becomes 16 when that holds, and `bne s1,16` then falls
through, executing the delay slot `s0 = 0` and the next instruction `s0 = 1`. So `s0 = 1` iff
`slot < 32`, and that selects pointer #2 — bank C's map. The direction of this branch was the fifth
direction error in the project; see M92 §2 for the instruction-by-instruction derivation.

**Why the closure failed.** `find_readers.py` resolved only `constructed base + immediate`. Here the
address is `constructed base + register`: `s4` is unknown to the scan because it is `s0 << 2`, and `s0`
comes from a comparison. The four checks in M89 were all true of the *shape the tool could see* — one
`lw` with a `-19868` immediate, no `lui`+imm construction of `0x800eb268`, no occurrence of it as a
word — and all four were blind to the fifth shape.

That is the same lesson as the `addiu`/`ori` bug, one level up: **the scan's matching rule is a
hand-written constant that defines what the search can see.** `find_readers.py` now reports
`base+register` accesses separately when a constructed base lies within `0x40` of the window, and with
that rule it finds the reader immediately:

```
$ ./find_readers.py 0x800eb268 0x800eb26c
0 direct access(es) … 1 base+register access(es) within 0x40 of the window
      stage2 0x80032a5c  lw  base+reg where base=0x800eb264  in 0x8003287c   <- MAY reach the window
```

The sharper consequence: the earlier statement "bank C's records all point at payloads the loader
would reject" still holds, but "the loader never receives them" does not. **The open question is now
narrow and named: is `FUN_8003287c` ever called with a slot ≤ 16?** If yes, bank C is live and the
game must be able to load those 28 records; if no, the second branch is dead code and "dead data"
returns by a different route.

## 2. Retraction: "bank C is itself compressed 6–7×"

Refuted by Shannon, using numbers already measured:

| slot | stored | span | span/stored | H (bits/byte) | max lossless compression |
|---|---|---|---|---|---|
| 38 | 7 640 | 52 112 | 6.82 | **3.591** | **2.23×** |
| 39 | 3 728 | 21 216 | 5.69 | 3.680 | 2.17× |
| 40 | 3 888 | 18 960 | 4.88 | 3.705 | 2.16× |

At `H = 3.6` bits/byte no lossless code can exceed **8/3.6 ≈ 2.2×**, and real compressed output is
near-random (~7.9 bits/byte — note slot 6, the zlib member, measures **7.945**, exactly as it
should). So bank C's stored bytes are **not compressed output**: they are low-entropy structured
data, which is what the 4-byte record grid said all along.

The ratio 6.8 is **`span / stored`**, i.e. *destination range over input size* — not a decompression
factor. Nothing in `FUN_800327ec` even uses `span` as a length; it appears only in the branch test.

So the honest description of bank C: **28 payloads of structured, low-entropy data with a
destination range 5–7× their stored size**, and no established procedure that expands them. The
"codec" framing was a category error, and `format_notes.md` §5's addendum should be read with this
correction.

One asymmetry worth keeping: for **bank B**, `span` *is* a verified decompressed size — M21 executed
the loader and matched the manifest exactly, six slots, no exceptions. For bank C nothing verifies
`span` at all.

## 3. The flags that did hold

* **`cart_record` iteration is closed.** No code forms an effective address in
  `0x800123c0..0x80012580` (records 39–66) directly. There are exactly **seven** `jal` sites to
  `cart_record`: boot `0x800005ac` with index **1**, boot `0x80004964` with index **67** (the invalid
  slot — worth a look), and five in stage-2 with the index **loaded** (the two slot-loader paths and
  three registry readers).
* **Content equality (bank C vs bank B) is unresolved**, and nothing byte-aligned can settle it: if
  bank C's representation is procedural rather than compressed, byte comparison with plaintext must
  fail regardless of content. The completion estimate must therefore say: bank B's 28 records are
  accounted for; bank C's 28 payloads are **only** accounted for if their content coincides with bank
  B's, which is unproven. Two readings remain live and they differ by 311 KB of asset coverage.
* **Reason 4, restated as the audit asked**: the `sb …,3(…)` scan found 115 candidates — far too many
  to audit — and `sh …,2(…)` or `sw …,0(…)` write byte 3 without appearing in that count, so the true
  writer set is larger and its composition unknown. That is a **limitation of the instrument**, not
  evidence that no static answer exists. Narrowing needs a watchpoint on byte 3, or full dataflow
  from the heap object to `*(0x80115284)`.
* **Branch 1 wording corrected**: not "unreachable" but **"no record in this cartridge satisfies its
  test"** — the three records with `delta == 0` are exactly the three with `stored == 0`, so branch 0
  always fires first. A hypothetical record with `stored == span != 0` would reach it.
* **Post-room dump caveat**: the two existing dumps are title-screen and post-NEW-GAME, so a
  post-room read requires playing to a room. And a null there would **not** mean "the scene path is
  not exercised" — the game visibly loads assets — it would mean **a second asset path exists that we
  have not found.** That is the stronger claim and the one to expect.

## 4. Retraction ledger

The off-by-one and the two above join the table in `reverse_engineering_log.md`, which is now labelled
**M90 §9** so later retractions can cite it by milestone. Count: **seven** entries — M81 (code-by-
every-signal), M82 (99.6 % region), M82 (61.6 % differential), M86 (40-byte array), M81–M88
(off-by-one), **M89 (no bank-C caller)**, **M90 (compressed 6–7×)**.

## 5. Next, in order

1. **Ask whether `FUN_8003287c` is called with slot ≤ 16.** One caller is known (`0x80071ec0`, slot
   from `arg0->0x1c + 3`), but the routine may have others we have not enumerated now that we know it
   is reached indirectly. If any call has slot ≤ 16, bank C is live and everything above changes
   again.
2. **A post-room ares dump** answers both the slot byte and whether `s0` ever goes nonzero.
3. Only then: what the 28 payloads contain.
