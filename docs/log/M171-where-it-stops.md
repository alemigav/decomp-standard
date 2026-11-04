# M171 — where it stops, and why nothing software can do will restart it

M170 showed the exception path never returns. This pins *where* it ends up and whether anything can leave it.

## 1. Where: one convergence point, entered seven ways

Scanning the whole handler (`0x800006d0`–`0x80000f00`) for backward branches gives a single destination:

```
0x800009c8: beq zero,zero, 0x8000098c
0x800009d4: beq zero,zero, 0x8000098c
0x800009f8: beq zero,zero, 0x8000098c
0x80000a50: beq zero,zero, 0x8000098c
0x80000b9c: beq zero,zero, 0x8000098c
0x80000c24: beq zero,zero, 0x8000098c
0x80000c48: beq zero,zero, 0x8000098c
```

**`0x8000098c` is the terminus.** (There is one other loop, `0x80000cb4`↔`0x80000db0`, but it is a bounded
per-slot walk — it does not escape the handler either.)

## 2. What the terminus does

```c
0x8000098c  andi t1, s0, 0xff00        ; state index (already masked)
0x800009a4  lui  at, 0x8001
0x800009a8  addu at, at, t2
0x800009ac  lbu  t2, 6480(at)          ; 0x80011950[idx]  — a state byte, **BSS**
0x800009b0  lui  at, 0x8001
0x800009b4  addu at, at, t2
0x800009b8  lw   t2, 6512(at)          ; 0x80011970[idx]  — a handler pointer, **BSS**
0x800009bc  jr   t2                    ; dispatch
0x800009c8  beq  zero, zero, 0x8000098c
```

So it is a **fault-dispatch loop**, not a bare `while(1)`: each iteration reads a byte from `0x80011950` and a
pointer from `0x80011970`, jumps through the pointer, and the dispatched code branches back to the top. Both
tables are **BSS** — they lie outside the boot image and are built at runtime, which is why they read as zero in
the cartridge.

## 3. Why nothing software can restart it

Three properties, all checked mechanically rather than argued:

| property | check | result |
|---|---|---|
| the loop cannot change its own state | scan the convergence block for **stores** and **COP0 writes** | **none of either** |
| it cannot return | `eret` scan over the whole handler (M170) | **0** |
| it cannot be preempted | `Status` was written with interrupts masked on entry (M170/M171) | masked |
| nothing else can run | single CPU, spinning here; no other agent writes the two BSS tables | no writer in the corpus |

So the loop's only inputs are two BSS tables that nothing in the running system can modify while it spins. **The
only exit is a hardware reset** — the console's reset line, which clears BSS and restarts boot.

One nuance worth stating: if no fault handler was registered, `0x80011970[idx]` is **0** and `jr t2` jumps to
address 0, which raises an address error, which re-enters the handler — an **exception storm** rather than a quiet
spin. Either way the machine does not continue; the difference is whether it dies silently or noisily.

## 4. What this closes

The chain from M168 is now complete and each link is checked:

* the guard is `break`, which always fires (M170);
* the exception path has no EPC write and no `eret`, so it cannot skip or return (M170);
* it converges on a dispatch loop that cannot alter its own state and cannot be preempted (this milestone);
* so a stale texture handle is a **fatal, unrecoverable stop**, and the only recovery is a reset.

That is a much stronger statement than "the code traps", and it is the kind of property a real-time loader
deliberately buys: an incorrect handle cannot silently corrupt the scene, because the machine refuses to continue.

## 5. Gate

`exception path (cartridge)` is now **8 cases** — four new ones: every exception path converges on one address
(≥ 5 entries), the convergence block contains **no stores**, it contains **no COP0 writes**, and it dispatches
through the BSS pointer table with `jr`. **191 cases across 18 fixtures**, `ci.sh: ok`, 18/18 marker checks, audit
15/15.

The table-detection case failed on first run because I looked for the offsets as `addiu` immediates when the code
loads them with `lbu`/`lw` — a reminder that these scans must be written against the real encoding, not the shape
I expected.
