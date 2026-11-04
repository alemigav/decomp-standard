# M141 — OpenBiohazard2 names the opcodes, and it breaks the "one length per opcode" claim

`OpenBiohazard2/OpenBiohazard2` is **MIT**, 137 files, Go, and it contains both halves of what Phase 1 and
Phase 2 needed: `fileio/rdt_*.go` (the room file: `scd`, `flr`, `lit`, `msg`, `pri`, `rid`, `sca`, `esp`,
`vab`) and a `script/` package with **named opcode structs** — `script.go`, `scriptcontrolflow.go`,
`scriptevent.go`, `scriptthread.go`, `scriptaot.go`, `scriptsprite.go`, `scriptcalculator.go`,
`scriptanimation.go`, `scriptopcodedocs.go`, plus `game/roomscript.go`. Unlike `bio2-ds` (no licence) this is
code we may read, quote and reuse **with attribution**.

## 1. The table, extracted

46 opcodes are declared as Go structs with the opcode number in a comment and one field per command field;
because `encoding/binary` adds no padding, summing the fields gives the **PS1 command length**. Comparing
that against the length map M136 measured from our handler advances:

| verdict | count | meaning |
|---|---|---|
| shared opcode numbers | **45** of our 141 | the numbering is the same VM |
| **exact length match** | **27** | name is certain |
| differs, but the PS1 size is one of the handler's advances | **16** | name is highly likely; our published length is a *sibling* size |
| neither | **2** | `0x32 PosSet` (ours 4, PS1 8), `0x46 AotReset` (ours 2, PS1 10) — open |

The 27 certain names:

```
0x04 EventExec      0x23 Compare        0x3e MemberCompare   0x59 XaOn
0x06 IfElseStart    0x24 Save           0x3f PlcMotion       0x5d MizuDivSet
0x14 SwitchCase     0x25 Copy           0x41 PlcNeck         0x60 KageSet
0x21 CheckBitTest   0x29 CutChg         0x43 PlcFlag         0x67 AotSet4p
0x22 SetBit         0x2c AotSet         0x44 SceEmSet        0x68 DoorAotSet4p
0x2e WorkSet        0x34 MemberSet      0x4c SceEsprKill
0x3b DoorAotSet     0x3c CutAuto        0x4d DoorModelSet
```

So **43 of our 141 opcodes now have a name**. The remaining 96 numbers are simply **not in
OpenBiohazard2's implemented subset** (it declares 45) — that is not evidence they are N64-specific.

## 2. What this confirms, independently of the reference decompilation

* **`0x44` is `SceEmSet`** — "scene enemy set" — 22 bytes, and its field order is
  `Opcode, Dummy, Aot, Id, Type, Status, Floor, SoundFlag, ModelType, EmSetFlag`, then `X, Y, Z, DirY,
  Motion, CtrFlag`. **Byte 3 is `Id`**, which is *exactly* the operand M94 measured (`lbu a0,3(descriptor)`)
  and M110 tracked across three rooms as the value 31. The operand was never an anonymous "slot": it is an
  **enemy id**.
* **`0x4d` is `DoorModelSet`**, 22 bytes in both — the one handler that needed M136's cross-register
  fallback. Two independent measurements agreeing on an awkward case is worth more than the 27 easy ones.
* **`0x2c` = `AotSet` (20)**, **`0x3b` = `DoorAotSet` (32)**, **`0x67`/`0x68` = `AotSet4p`/`DoorAotSet4p`
  (28/40)** all match exactly — the object/AOT family, which is what the 22-byte `SceEmSet` sits beside.

## 3. The correction M136 needs

For **16** opcodes the handler contains **more than one advance constant inside its own Ghidra function**,
and the PS1 size is among them:

| opcode | M136 length | PS1 size | advances inside the handler |
|---|---|---|---|
| `0x2d` ObjModelSet | 3 | **38** | 3, 16, 38 |
| `0x4e` ItemAotSet | 2 | **22** | 2, 22, 30, 38 |
| `0x69` ItemAotSet4p | 2 | **30** | 2, 30, 38 |
| `0x46` AotReset | 2 | 10 | 2, 16, 38 |
| `0x3a` SceEsprOn | 5 | **16** | 2, 3, 4, 5, 6, 8, 16, 22 |
| `0x54` SceEspr3DOn | 5 | **22** | 1–6, 8, 22 |
| `0x2d`, `0x4e`, `0x69`, `0x37`, `0x40`, `0x51`, `0x52`, `0x26`, `0x07`, `0x09`, `0x0d`, `0x13`, `0x17`, `0x18` | … | | see the corpus |

M136 published "141 of 141 opcodes mapped, one length each" and `walk_stream.py` advances by that single
number. **For these 16 that is not the command length** — it is *the first advance the scan found*, and the
handler selects among several sizes. A walk using the published value therefore **desynchronises** on any
command of those opcodes, which is a plausible explanation for walks that "ended" earlier than expected.

The encoding is most likely per-opcode *families* selected by a sub-field (the PS1 table has several such
pairs: `AotSet`/`AotSet4p`, `DoorAotSet`/`DoorAotSet4p`, `ItemAotSet`/`ItemAotSet4p`, and
`Calc`/`Calc2` share opcode `0x26` with sizes 5 and 4 — the same opcode number with two sizes, which is the
mechanism directly visible in the source). So this is not a defect in our measurement so much as a defect in
**the claim that one length per opcode suffices**.

## 4. What it re-frames, carefully

M110 measured: byte 3 = **31** in three rooms, the map entry for 31 is 0, so the loader is handed
`cart_record(0)` and the failed inflate is discarded. That measurement stands unchanged. What changes is the
interpretation: byte 3 is `SceEmSet`'s **`Id`**, so `FUN_8003287c(id)` is the port's *id → bank record*
resolver, and "slot 31 selects nothing" reads as **an enemy id whose record is empty in this build** — the
same "unreachable in this build" shape M89 found, now with a name attached. Stated as a hypothesis
consistent with the measurement, not as a new measurement.

## 5. Next

1. **Import the opcode table as a fixture** (`fixtures/scd/opcodes.json`, 45 entries, with the MIT
   attribution and the repo URL) and have `walk_stream.py` print names — the first change to the VM tools
   that is *derived from licensed source* rather than inferred.
2. **Make the walk length-safe**: where a handler holds several advances, either take the PS1 size for the
   named opcode or fail loudly rather than advancing by a guess. M136's non-vacuity rule applies: a walk that
   silently desynchronises is worse than one that stops.
3. Settle the two unexplained opcodes, `0x32 PosSet` (4 vs 8) and `0x46 AotReset` (2 vs 10), from the
   handlers themselves.

```
python3 tools/acceptance.py                    # 98 cases, 10 fixtures — unchanged by this milestone
```
