# M121 — reading the callee: seven confident flags, all mine

M120 left seven sites flagged as "callee reads a stack argument the caller never stored". The instruction was
to read the callee and confirm. Reading it refuted the flags, then found two bugs in the check. Final verdict:
**0 of 14 371 call sites leave a stack argument unsupplied**, and the check still catches a genuinely missing
store in its fixture.

## What the callee actually does

`0x80047824`, the target of five of the flags:

```
80047824  97a20012  lhu  v0,0x12(sp)      <- reads an incoming HALFWORD at frame bias 18 decimal
80047828  a0850010  sb   a0,0x10(a0)
8004782c  a0850008  sb   a0,0x08(a0)
80047830  00a72821  addu a1,a1,a3
80047834  a0850020  sb   a0,0x20(a0)
80047838  a0850018  sb   a0,0x18(a0)
```

So the read is real — and the bias is **18 decimal = `0x12`**. The first tool output that started this was
`stk=[18]` with findings printed as `%+d`; I then went looking for a store at `sp+0x18` in the *caller*. That is
the decimal/hex confusion this project keeps meeting (M108's `p25` vs `p37` was the same family). `0x12` and
`0x18` are different offsets and the whole first verification pass was aimed at the wrong one.

## What the caller actually does

At the flagged call site `0x80093cf4` in `0x80093be0`:

```
80093cf4  0c011e09  jal  0x80047824
80093cf8  afbe0010  sw   s8,0x10(sp)      <- the DELAY SLOT stores the outgoing argument
```

The caller does supply it: a **4-byte** store at `0x10`, i.e. bytes `0x10..0x13`, which contains the callee's
halfword at `0x12`. My presence test asked "is there a slot keyed exactly `spbias+0x12`" — and a word store
keys only `0x10`.

## The two bugs in the check

1. **`stk` counted a call's return value as the function's own stack argument.** A `jal` pseudo-access carries
   the call's resolved return in `base`; when an inner callee returned `stkarg(b)`, that bias was recorded as the
   *caller's* incoming stack argument. Excluding call accesses from that loop took **7 → 5**.
2. **Presence was offset-granular, not byte-granular.** Stores now record the frame **bytes** they cover, using
   the access width (`sw` 4, `sh` 2, `sb` 1, `sd` 8), and the check asks whether *any byte* of the callee's read
   range was written. That took **5 → 0**.

## The verdict

```
14 371 call site(s) analysed; 0 of them leave a stack argument unsupplied
```

Across the whole cartridge, every call site supplies the stack arguments its callee reads. That is a **negative
result**, and the useful kind: the class is now *checked* rather than assumed.

The guard against a vacuous check is fixture **L10**, which still flags its synthetic bad caller (a callee reading
`0x10(sp)` called by a function that stores nothing) and still ignores the good one. A check that reports zero on
the code and one on a constructed defect is telling you something; a check that reports zero on both is telling
you nothing.

## What this cost, honestly

Three rounds on one flag family: a units slip, a wrong field in a summary, and a granularity error. Each was
caught by reading an instruction or by a fixture — never by re-reading my own output. The pattern worth keeping:
**when a scan produces a small, confident, clustered list, verify one item by reading the code before believing
the list.** That is what turned seven "defects" into zero, and it is cheaper than any amount of re-running.

## Verification

```
provenance.py --self-test    10/10
provenance.py --self-test2   10/10
provenance.py --acceptance     3/3
provenance.py --stk-check               0 of 14 371
```
