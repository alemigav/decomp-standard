# M112 — experiment B, step 2: summaries resolve the record chain, and the map reader stays out of reach

Layer 2 is in: caller-independent **summaries** (`params`, `ret`, call list) computed by fixpoint, with
forward substitution at each `jal`. Both fixtures are green — step 1 still **10/10**, layer 2 **5/5** — and
the two pre-registered acceptance tests land one pass and one fail. The failures found three bugs in the
analysis, one of which was producing a *wrong address* on real code.

## Mechanism

A summary is expressed in its own parameter space, so it is caller-independent:

```
params[k]  which of the function's arguments it dereferences / lets escape into a callee
ret        what it returns: a constant, `param(k)` (its own argument), or unknown
```

At a call site the callee's `param(k)` is substituted with the caller's argument *value computed before the
clobber*, and `ret(f)` is substituted recursively with a `seen` set for recursion. Five rounds of fixpoint.

```
7093 regions; 2972 deref a parameter, 596 return a constant, 29 return a parameter
22790 call sites, 12942 resolve to a known region (57%)
```

## Acceptance test 1 — PASS

Pre-registered as: *"`FUN_800327ec`'s record fields must be attributed to `cart_record()`'s return at
`0x80071ec0` — a two-hop chain (table entry → return → argument → fields)"*.

Both hops are found without being told:

```
$ provenance.py --callers 0x800327ec
stage2  80032a04 in 8003287c   a0=ret(80001180)  a1=ret(80001180)  v0=ret(800327ec)
stage2  80032a84 in 8003287c   a0=ret(80001180)  a1=ret(80001180)  v0=ret(800327ec)

$ provenance.py --region 0x80032a5c
80032a74  lw  base=ret(80001180)  off=+0xc
80032a78  lw  base=ret(80001180)  off=+0x8
80032a90  lw  base=ret(80001180)  off=+0x0
80032a98  lw  base=ret(80001180)  off=+0x4
80032800  lw  base=param(a0)      off=+0x4        (inside FUN_800327ec)
```

So the chain is: the record pointer is the **return of `FUN_80001180`** (`cart_record` in the earlier notes
— the name maps to this address), it arrives as `a0` at the two call sites in `FUN_8003287c`, and inside
`FUN_800327ec` the fields are read at `+0x0`, `+0x4`, `+0x8`, `+0xc`. That independently confirms M85's
record layout (`[0]` cart pointer, `[1]` stored size, `[2]`/`[3]` the span) — this time by provenance rather
than by hand.

Note the call site is `0x80032a04`, not `0x80071ec0`: `0x80071ec0` is the call to `FUN_8003287c`, one hop
higher. The pre-registered wording named the wrong address; the chain behind it is what was tested.

## Acceptance test 2 — FAIL, with the reason measured

Pre-registered as: *"the bank-C map reader `0x80032a5c` must be found without being told, where `s0` is a
parameter"*. It is not found, and the site says why:

```
A 800329e4  lw   base=const(800f0000)  off=-0x4d9c  -> 800eb264      <- the map POINTER load: attributed
  800329ec  lbu  base=unk              off=-0x10                       <- the map BYTE read: unknown
  80032a5c  lw   base=unk              off=+0x0                        <- the load through the map: unknown
```

Reading the instructions at the site (`0x800329d8`–`0x800329f4`):

```
800329d8  52220001  beql  s1, v0, +1
800329dc  2411002e  addiu s1, zero, 0x2e     <- in the LIKELY delay slot: conditional
800329e0  3c03800f  lui   v1, 0x800f
800329e4  8c62b264  lw    v0, -0x4d9c(v1)    <- *(0x800eb264)
800329e8  02221021  addu  v0, s1, v0         <- base = map pointer + index
800329ec  9044fff0  lbu   a0, -0x10(v0)
800329f4  2473b264  addiu s3, v1, -0x4d9c    <- 0x800eb264 re-materialised in a register
```

Three distinct reasons, none of them "the tool is broken":

1. the address is `map_pointer + index` where the **index is conditional**, so it is genuinely not a
   compile-time constant — the honest answer is "unknown offset over a known base", which this layer cannot
   express yet (a `CONSTBASE` value kind is the next small addition);
2. `0x80032a5c`'s base arrives through a shift/clamp path that degrades to unknown;
3. the map *pointer itself* **is** attributed (`*(0x800eb264)` = `0x800eb204`, established with
   `--follow-pointers`, i.e. the M86 sign-extension case reproduced in real code), so the gap is one hop
   narrower than it was an hour ago, not wider.

## Bugs this step found — three in the analysis, one in the loader

* **Jump targets were masked to 16 bits.** `Instr.imm` took `word & 0xFFFF` for every instruction, but
  `j`/`jal` carry a **26-bit** field; every target past `0x3ffff` truncated, so interprocedural resolution
  pointed at the wrong function. Caught by fixture L2.
* **`sll` was swallowed as `nop`.** Both have funct `0x00`; the early `if f == 0x00: return` ate shifts, so
  a parameter-derived index was reported as a plain parameter. Caught by fixture L4.
* **Branch-likely delay slots were treated as always-executing.** `beql`/`bnel` execute the delay slot
  *only if the branch is taken*. With the old rule the `li s1, 0x2e` at `0x800329dc` was assumed, and the map
  byte read was published as `-> 0x800eb222` — **a confident, wrong address** derived from one branch
  outcome. Found by disassembling the site after noticing the result implied `s1 == 0x2e` unconditionally.
  Fixed by merging the with-delay-slot and without states, and locked by fixture **L5**.
* **Every non-boot image was being read from the wrong place.** Only `boot` sits uncompressed in the
  cartridge; the other 35 are decompressed zlib members under `assets/unpacked/`, so the loader was handing
  the analysis **compressed bytes**. The symptom was absurd and therefore catchable: stage2 had **zero**
  `jr ra` instructions and **one** prologue in 293 060 words, i.e. 2 regions instead of 3 478. The earlier
  boot-only cross-checks passed and hid it.

## Fixtures

```
provenance.py --self-test    10/10      (step 1, unchanged)
provenance.py --self-test2    5/5       L1 return-constant, L2 param-through-return,
                                       L3 unknown callee, L4 shifted param, L5 likely delay slot
```

## Next, in order

1. `CONSTBASE` — a value that is *constant base + unknown offset*, so reason 1 above becomes expressible
   ("reads `0x800eb204` + ?") instead of collapsing to unknown;
2. jump-table edges from `find_jump_tables.py`, which is what the 57 585 `unreached` operands need;
3. then re-run acceptance test 2. If it still fails, the failure will be about the *index's* conditional
   provenance rather than about the instrument, which is a different and more interesting statement.

## Verify

```
python3 tools/provenance.py --self-test && python3 tools/provenance.py --self-test2
python3 tools/provenance.py --callers 0x800327ec            # acceptance test 1
python3 tools/provenance.py --region 0x80032a5c --follow-pointers   # acceptance test 2
```
