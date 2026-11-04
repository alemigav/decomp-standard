# M116 — frame slots: entry-relative keys, and proof that `spoff` is not an unresolved bucket

Two things needed saying about the frame. The slot keys were **wrong**, and the bucket was **misread**.

## The key bug

Stack slots were keyed by the byte bias off the *current* `sp`. A frame adjustment changes `sp`, so the same
local acquired two different keys and its spilled value was lost:

```
addiu sp,sp,-32
sw    a0,0x20(sp)      key 0x20
addiu sp,sp,-16
lw    v0,0x30(sp)      key 0x30   <- same local, different key, value lost
```

Slots are now keyed **relative to the function-entry sp**, with `State.spbias` tracking the adjustment, and
`addiu rt,sp,imm` producing a frame address at `spbias+imm`. A join where two predecessors disagree on `spbias`
sets it to `None`, which disables keying rather than mixing frames. Fixture **L8** encodes exactly the
sequence above and requires the reloaded value to keep its provenance.

## The regression I introduced, and the misreading it exposed

The first version stopped writing a value into the `sp` register at all (the adjustment went into `spbias`) —
and the `spoff` bucket collapsed from 27 413 to 182 while `unk` grew by the same amount. That revealed what the
bucket had always been: **accesses through `sp` reported their base as `spoff` only because the `sp` register
held a frame value**. So the base is now set explicitly for `sp`-relative accesses, entry-relative:

```
spoff 27 450      unk 20 592      attributed 14 787 (12.0 %)      total 122 902
```

## What the measurement says

```
frame slots: 310 294 access(es) through sp/a frame address,
             280 426 resolved to a stored value (90.4 %), 29 868 missed
```

**90.4 %.** Frame-slot resolution is not the weak point — it already works, and the ~30 000 misses are the
expected ones (a slot read before it is written on some path, or a frame whose `spbias` is unstable).

So `spoff` is **not** an unresolved bucket, and it should never have been read as one: it answers "where does
this operand read?" (the stack frame) while resolution answers "did the value it carried keep provenance?"
(90.4 % yes). Two different questions that happened to share a column.

## Attribution did not move, and why that is the honest result

`attributed` stayed at **14 787 (12.0 %)**. Frame slots hold saved registers, counters and handles far more
often than pointers, so resolving them rarely produces an address. This step bought **correctness**
(a fixture that would have failed before) and a **measurement** (90.4 %), not coverage — and the note says so
instead of presenting a reclassification as a win.

## Acceptance tests, re-run as instructed

* **test 1 unchanged and passing** — both call sites `a0=ret(80001180)`, `FUN_800327ec` returning `const(0)`.
* **test 2 unchanged** — `0x800329ec lbu base=800eb204+0+?`, `0x80032a5c lw base=800eb264+0+?`.

Fixtures: **10/10** and **8/8**.

## Verify

```
python3 tools/provenance.py --self-test && python3 tools/provenance.py --self-test2
python3 tools/provenance.py --census        # now prints the frame-slot hit rate alongside the buckets
```
