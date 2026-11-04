# M120 — the caller-side check: 7 sites out of 14 371, and one of them read from the instructions

M119 ended with the mechanism and the input for a defect check: a callee declares the stack arguments it
reads, so a call site can be asked whether its caller ever stored them. That check now exists.

## The check

At every call site whose callee has a summary:

* the callee's `stk` biases are matched against the caller's frame slots at `spbias + bias`;
* a slot that is **absent** from the caller's state means no path in that function stored it;
* findings are split by where the slot lies:
  * **interior** (`key < 0`) — inside the caller's own frame, so a store was expected and is missing;
  * **forwarded** (`key ≥ 0`) — above the caller's entry `sp`, i.e. the value arrives from the caller's
    caller and is passed straight through, which is legitimate.

```
14 371 call site(s) analysed; 7 of them leave a stack argument unsupplied
  7 interior, 0 forwarded
```

All seven sit in one cluster, all at bias `+0x18`:

```
stage2  80092720 in 800926a0 -> 80093be0
stage2  8009287c in 800926a0 -> 80093ddc
stage2  80093cf4 in 80093be0 -> 80047824
stage2  800941d8 in 80093ddc -> 80047824
stage2  800941f8 in 80093ddc -> 80047824
stage2  80094380 in 80093ddc -> 80047824
stage2  800943a4 in 80093ddc -> 80047824
```

## One of them, read from the instructions

A scanner output is a candidate until the instruction is read, so `0x80092720`:

```
8009270c  24020001  li   v0,1
80092710  a202bf98  sb   v0,-0x4068(s0)
80092714  24020003  li   v0,3
80092718  a2420001  sb   v0,1(s2)
8009271c  a2400025  sb   v0,0x25(s0)
80092720  0c024ef8  jal  0x80093be0
80092724  a2400024  sb   v0,0x24(s0)      <- delay slot
```

No store to `sp+0x18` anywhere before the call, and the callee reads exactly that bias. **The finding is
consistent with the code.** Whether it is a defect in the game or a limitation of the model is a separate
question — read the callee at `0x80093be0` before claiming either.

## Honest limits of the check

* **A store on only one path counts as present.** Merging collapses a slot present-with-a-value on one path and
  absent on another to `U`, and presence, not knowledge, is what the check tests — so a genuinely conditional
  store can hide a real miss. This makes the check *conservative* (7 is a lower bound), which is the right
  direction for a defect finder.
* **Slots persist for the whole function.** A frame torn down and re-established gets no new namespace, so a
  stale slot can satisfy the check. Also conservative.
* It says nothing about whether the *value* is right, only whether anything was stored.

## Process error, again, in the same class

My first attempt to decode the flagged site used `rom[va - 0x7ffff480]` — the **cartridge** mapping — for
`stage2`, which lives in `assets/unpacked/`. The result was convincing-looking garbage (a `jal`-shaped word
decoded from data). This is the *seventh* instance of the hand-composed-address class the log already lists, and
it was caught only because the neighbouring words from `vaddr.py` disagreed with it. The rule stands and is not
improved by repetition: **`tools/vaddr.py`, never arithmetic.**

## Verification

```
provenance.py --self-test    10/10
provenance.py --self-test2   10/10      L10 added: one bad caller flagged, one good caller not
provenance.py --acceptance     3/3
provenance.py --stk-check                the corpus run above; --json writes the list
```

Fixture **L10** encodes both halves — a caller that stores the argument and one that does not — and asserts
exactly one finding, interior, at the bad call site. That is what stops the check from silently becoming a
no-op the next time `stk` or `resolve` is touched.
