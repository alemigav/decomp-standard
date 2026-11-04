# M170 — `trap(0)` is `break`, and the exception path never returns

The guard in `0x8008548c` compiles to **`break`**, not to a conditional trap, and this port's exception path
provably cannot return from it. So the handle check is a **hard stop**: no fall-through, no retry, no recovery.

## 1. The instruction

Ghidra prints `trap(0)`, but the encoding at `0x80085534` is **`0x0000000D` — `break`** (ExcCode 9, Break), not
one of the `teq`/`tne` family. That matters, because a *conditional* trap can be arranged not to fire; `break`
always does.

## 2. The path it takes

Boot installs a four-instruction stub at each exception vector (`0x80000084`, `0x80000100`, `0x80000180`), and the
16 bytes sit literally in the boot image at file offset `0x340`:

```
lui   k0, 0x8000
addiu k0, k0, 0x06d0
jr    k0
nop                       -> every exception vectors to 0x800006d0
```

The handler there (`exception_handler`, which Ghidra could not decompile — "bad instruction data" — and which had
to be disassembled by hand) does:

1. masks interrupts (`mfc0 k1,$12` / `mtc0 k1,$12`),
2. saves the register file into a k0-based area at `0x80015000`,
3. **reads `Cause` (`mfc0 r8,$13`)** — so it is the real exception dispatcher, not a stub,
4. posts a **fault event** into the libultra queue at `0x80012140` (the `0x80000f60` pattern: head/limit check,
   event word, flag `2`, `Count` timestamp, head `+= 0x10`),
5. copies the interrupted registers into a fault-context block and stops.

## 3. The two absences that decide it

Exhaustive scan of the handler region `0x800006d0`–`0x80000f00`:

| instruction | count | consequence |
|---|---|---|
| `mfc0 $13` (Cause) | **2** | it is the exception path |
| **`mtc0 $14` (EPC)** | **0** | **nothing can skip the faulting instruction** |
| **`eret`** | **0** | **the handler never returns** |

Skipping a fault requires writing `EPC + 4`; returning requires `eret`. Neither exists. So the `break` cannot
fall through — and it will not even loop, because the interrupted thread is never resumed.

## 4. What that means for the handle guard (refining M169)

M169 recorded that the use path "traps". The stronger, verified statement is: **the use path is fatal and
unrecoverable**, by construction of the exception path rather than by its mnemonic. That also settles M168's
caveat properly — after 2^24 allocations the unmasked global counter would produce a **guaranteed crash**, not
silent corruption, because there is no handler that could skip the check. A design that wanted to *recover* from a
stale handle would need an EPC write somewhere; this port has none, so it chose the hard stop deliberately.

## 5. Gate

New cartridge-gated suite **`exception path (cartridge)`** — four cases: the handler reads `Cause`; **no EPC
write** exists; **no `eret`** exists; and the `jr k0` stub exists literally in the boot image (the installer
copies it, so the vectors themselves are runtime RAM). **187 cases across 18 fixtures**, `ci.sh: ok`, 18/18
marker checks, audit 15/15.

The first version of the stub case passed through a fallback (`or installed == STUB`) and was therefore vacuous —
the same defect this project keeps finding. It now searches the image for the 16-byte sequence, which is a check
that can fail.
