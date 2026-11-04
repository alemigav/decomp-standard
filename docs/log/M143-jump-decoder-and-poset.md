# M143 — the jump family decodes, and `0x32 Poset` was never missing a length, only a window

Two of the five "unverified but named" opcodes from M142 are settled, and the control-flow family now has a
decoder instead of a stop.

## 1. The jump family, decoded from the handlers

Each of the five was read instruction by instruction. What they have in common: **none of them advances the
pointer by a constant — each computes the next pointer from an operand**, which is why the advance scan
found nothing and why M142's stop was correct rather than a gap.

| opcode | name | size | operand | destination |
|---|---|---|---|---|
| `0x07` | `ElseStart` | **4** | `u16` at byte 2 | `cmd + u16` (and the frame is popped) |
| `0x0d` | `ForStart` | **6** | `s16` at byte 2 | `cmd + s16 + 6` — the `+6` is its own size |
| `0x13` | `Switch` | **4** | `u16` at byte 2 | case-table skip target; the body then scans `0x0c`-marked case entries |
| `0x17` | `Goto` | **6** | `s16` at byte 4 | `cmd + s16` |
| `0x18` | `GoSub` | **2** | `u8` at byte 1 | **dynamic**: `*(0x80114f2c)[index] + record.u16@0` |

The evidence, per opcode, is in the tool as `JUMP_FAMILY[...]["from"]`, e.g. for `Goto`:

```
0x8006e3a4  lh   t0,4(a1)      ; operand = signed halfword at command+4
0x8006e3bc  addu a1,a1,t0      ; target = command + operand
0x8006e3d0  sw   a1,28(a0)     ; ctx+0x1c = target   (in the delay slot of jr ra)
```

**All five sizes equal the PlayStation sizes exactly** (4/6/4/6/2) — five independent agreements, on the one
family where our own measurement had nothing to offer.

`successors(op, cmd, addr)` returns the targets: unconditional `Goto` yields one, the conditional ones yield
the jump target *and* the fall-through, and `GoSub` yields `None` because both halves of its destination are
outside the command — the base is `*(0x80114f2c)` at runtime, the offset is `u16@0` of a 64-byte record. The
command carries only the record index. Callers therefore get an honest "dynamic" rather than a plausible
address.

## 2. `0x32 Poset`: the length was there all along

The handler is eleven instructions:

```
0x8006fe44  lw   v0,28(a0)     ; the command pointer
0x8006fe4c  lh   a1,2(v0)  /  lh a2,4(v0)  /  lh a3,6(v0)   ; three signed halfwords
0x8006fe58  addiu v0,v0,8      ; <- the advance
0x8006fe5c  sw   a1,40(v1)  /  sw a2,44(v1)  /  sw a3,48(v1)
0x8006fe68  sw   v0,28(a0)     ; write-back, FOUR instructions after the add
```

The advance is **8**, which is exactly the PlayStation size. M136 published **4** and M142 called the opcode
`unverified`, both for the same reason: the advance scan required the write-back within **two** instructions
of the `addiu`, and this handler records three other fields first. Widening to eight instructions — while
insisting that the **first** write to `ctx+0x1c` is the one that counts — settles it.

## 3. The same window fix quietly repaired more, and one tightening caught a real error

Widening the window moved **11 opcodes** from `unverified` to `ok`. One of them was wrong in the other
direction, and the fixture is what surfaced it:

* **`0x28`** does `lw v0,28(a0)` → `addiu v0,v0,1` → **`jal`** → `sw v0,28(a0)`. The store is the `jal`'s
  **delay slot**, so it executes *before* the call, and the advance really is 1 — a call boundary alone must
  **not** invalidate a candidate;
* **`0x45`** stores `cmd+5` in the **delay slot of `jr ra`**, same situation.

So the rule is now: a call or return ends the candidate, *but its delay slot is checked first* — and any
**other** write to `ctx+0x1c` in between invalidates the candidate outright. With that, the classes are:

| class | count |
|---|---|
| `ok` (single constant advance) | **128** |
| `jump` (computed target, size known) | **5** |
| `unverified` | **8** |
| `ambiguous` | 0 |

**133 of 141 opcodes are now walkable**, against 117 at M142. The eight that remain are genuinely not
constant-add handlers: `0x03` writes the pointer from a `jal`'s result, and the others (`0x01`, `0x10`,
`0x19`, `0x1a`, `0x1b`, `0x36`, `0x37 ScaIdSet`) store a register that was computed elsewhere in the handler.

## 4. The walk now follows control flow

`walk_stream.py` gained a `jump` branch: it prints the command, every successor with its derivation, and then
* follows an unconditional computed target (`Goto`),
* follows the **fall-through** of a conditional one and prints the alternative it did not take,
* **stops** on `GoSub`, saying the destination is dynamic.

Verified end to end on a synthetic 8 MiB RDRAM (no cartridge, no dump needed):

```
=== walking from ctx0 = 0x80200000 ===
  [ 0] 0x80200000: opcode 0x17 Goto len  6 -> 17 00 00 00 00 10
        cmd+16                             -> 0x80200010
        following the computed target (not the fall-through)
  [ 1] 0x80200010: opcode 0x00 len  1 -> 00
```

That test is a hand-run script, **not** in the gate — stated because the gate does not cover the walk path at
all (it needs a dump). The fixture covers the decoder's arithmetic: **20/20**, five new cases for
`Goto`/`ElseStart`/`ForStart`/`Switch`/`GoSub`.

**Gate**: `walk_stream length map 20/20`; **110 cases across 10 fixtures**; `ci.sh: ok`.

## 5. What is left

* The **8 unverified** opcodes, each needing to be read rather than scanned — `0x03` first, since a `jal`'s
  return value as the next command pointer is a legible pattern.
* **`GoSub`'s script table** at `*(0x80114f2c)`: with that base (runtime), `GoSub` becomes followable and
  sub-script entry points become readable.
* A **committed synthetic dump** so the walk path itself is in the gate instead of in a hand-run script.

```
python3 tools/walk_stream.py --lens        # 128 ok, 5 jump, 8 unverified, 0 ambiguous
python3 tools/walk_stream.py --self-test   # 20/20
python3 tools/acceptance.py                # 110 cases, 10 fixtures
```
