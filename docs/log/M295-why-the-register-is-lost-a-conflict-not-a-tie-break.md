# M295 — why the register is lost: a conflict, not a tie-break, and not `local_alloc` at all

M294 closed the scan and left the question narrower: *why, in that one basic block, does our allocator lose `$2`?*
cc1's own pass dumps answer it, and the answer corrects the framing twice: the register is chosen by **`global_alloc`**, and
it is lost to a **conflict**, not a tie-break.

## 1. The disposition, from cc1's own dump

Compiling `0x8007e590`'s source with `-da` and reading the two dumps:

```
;; Register dispositions:  …  229 in 4   231 in 3   232 in 2  …
```

- **232** is the `22` — it gets **`$2`** (the image's register);
- **231** is the loaded `s->f5` — `$3`;
- **229** is the select's value — **`$4`**.

So the question is exactly "why not `$2` for 229", and the dump says which pass decided: the `.lreg` dump (after
local-alloc) still shows `(reg:QI 229)`, i.e. local-alloc did **not** allocate it. Its live range crosses three blocks,
so it is a **global** allocno and `global_alloc` chose. M293/M294's framing — "`local_alloc`'s tie-break" — was wrong.

## 2. The RTL, and where the two constants sit

From the post-global dump:

```
;; block 34  (label 529)
(insn 642 … (set (reg:QI 229) (const_int 5)))          ← the taken value, BEFORE the branch
(insn 533 … (set (reg:SI 231) (zero_extend (mem …5(s0)))))
(insn 535 … (set (reg:SI 232) (const_int 22)))
(jump_insn 536 … (if_then_else (ne 231 232) …)  REG_DEAD 231, REG_DEAD 232)
;; block 35
(insn 538 … (set (reg:QI 229) (const_int 4)))          ← the other value, AFTER the branch
;; block 36  (label 541)
(insn 546 … (set (mem …5(s0)) (reg:QI 229))  REG_DEAD 229)
```

**229 is live from insn 642 to the end of block 34**, and 232 lives in that same block. Their ranges overlap, so
`global_alloc` records a conflict between the two allocnos. `find_reg` scans registers in **ascending** order (MIPS defines
no `REG_ALLOC_ORDER`, so `local-alloc.c`/`global.c` both fall back to `regno = i`): `$2` is taken by 232, `$3` by 231 —
which also overlaps — so the first free register is **`$4`**. That is the whole mechanism.

## 3. The control: the same expression, where `$2` *is* chosen

The synthetic from M294, dumped the same way:

```
(insn 13 … (set (reg:SI 2 v0) (const_int 22)))
(jump_insn 14 … (ne v1 $2) … REG_DEAD $2)
;; block 1                                   ;; block 2
(insn 16 … (set (reg:QI 2 v0) (const_int 4)))    (reg:QI 2 v0) = 5
(insn 18 … (set (mem …) (reg:QI 2 v0)))
```

Here **both** constants sit *after* the branch, in blocks whose live set is exactly `{sp, ctx}`, so neither overlaps the
`22` and `$2` is free — cc1 uses `$2` for both, and reorg merges one of them into the delay slot as an *annulled* branch
(`bnel`).

So the difference between the two builds is **where the taken constant is materialised**: before the branch (ours) or
after it (the image's). Same final instruction sequence, after reorg moves the constant into the delay slot either way —
different conflict graph, therefore a different register.

## 4. Why the source cannot move it

The placement is not a property of the ternary; it is a property of its **enclosing `if`**. In the isolated shape gcc
counter-inverts the compare and puts both arms out of line; inside case 4's `if (!(A && B))` it expands the then-arm
inline before the branch. That is why thirty shapes failed: every shape that changes the placement (a named temporary, a
nested block, a cast, a differently-polarised comparison) also moves the twenty-two surrounding words — measured at 194,
194, 187 and 225 against 226 — because the placement *is* the surrounding code.

## 5. The answer, stated for the record

**The register is lost to a conflict, not a tie-break, and the conflict exists because cc1 materialised the taken
constant inside the branch's predecessor block, where it overlaps the `22` pseudo that already owns `$2`.** Not
`local_alloc`; not a tie-break; and not reachable from the source, because the block placement that creates the conflict
is set by the enclosing `if`, whose own code is byte-exact and must stay so.

`0x8007e590` therefore stays at **226 of 229** — thirteen of fourteen recovered functions byte-exact, one partial whose
three words now have a complete account: which pass chose (`global_alloc`), against which allocno (`232`, the `22`, in
`$2`), because of what (`a live-range overlap inside block 34`), and why no source shape avoids it (`the placement is
the enclosing block's`).
