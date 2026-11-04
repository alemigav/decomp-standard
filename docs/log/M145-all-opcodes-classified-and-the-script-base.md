# M145 — all 141 opcodes classified, and the script base turns out to be a cartridge block

The four remaining reads are done, `0x80114f2c` is traced to its loader, and the map is now complete:
**no opcode is `unverified` and none is `ambiguous`.**

## 1. The four reads

**`0x40 PlcDest` = 8** (the PlayStation size), and it needed a MIPS distinction I had wrong: the handler ends
a small `jr v0` dispatch table and *then* adds 8 to `t0`. My dataflow cleared caller-saved registers on every
`jr`, and `t0` is caller-saved — but **`jr` is a jump, not a call**: no register is clobbered by transferring
control. Clearing on `jal`/`jalr` only is what resolves it.

**`0x6b` = 4 and `0x7c` = 6.** Both end:

```
0x80072d5c  jr   ra
0x80072d60  sw   a1,28(a0)      ; the write-back, in the delay slot
```

and my handler extent is *exclusive* — the next handler starts at `0x80072d64` — so the loop stopped one
instruction short of the only store that mattered. The extent still ends there, but the **delay slot of a
terminator sitting on the last instruction belongs to the handler**, so it is now examined explicitly.

**`0x1b` → jump family, 6 bytes, `cmd + s16@2 + 6`, conditional.** Its two paths are exactly `ForStart`'s
shape: the zero-flag path computes `a3 + t0 + 6` into `ctx+0x1c`, the other advances `a3` by 6 and records a
loop target at `96(v0)`. The PlayStation table has **no entry for `0x1b`**, so the *name* is unknown while the
structure is not.

The result:

| class | count |
|---|---|
| `ok` (constant advance) | **129** |
| `jump` (computed target, size known) | **6** |
| `dynamic` (target is runtime state) | **6** |
| `unverified` | **0** |
| `ambiguous` | **0** |

**43 of 45 named opcodes match the PlayStation size exactly** — the only two exceptions are still
`0x09 Sleep` (our 1, PS1 4) and `0x26 Calc` (our 6, PS1 5 or 4).

## 2. `*(0x80114f2c)`: the script base is a loaded cartridge block

The word is **zero in the image**, so it is runtime state. Its writers are the answer:

| site | what it assigns |
|---|---|
| `0x8006d8f0` | `*(*(0x800df92c) + 0x48)` and `+ 0x4c` — the two stream pointers M98 found |
| `0x8006d998` | the same `+0x4c` |
| `0x80071e14` | the **`SceEmSet` handler itself** (`0x44`) |
| `0x8009b880`, `0x8009b27c` | `DAT_800c52dc + 0x3b800` — the room work region |

and `0x8009b27c` is the room-script load, in full:

```c
DAT_80114f2c = DAT_800c52dc + 0x3b800;                       /* inside the 718 848-byte room work region */
func_0x80004cfc(*(ushort *)(&DAT_80131fa8 + room_byte * 2),  /* file id, by room */
                DAT_80114f2c, 0, "DOOR_SCD");                 /* read the block into it */
FUN_8006d5dc(&DAT_80114958, 0);                               /* start script record 0 */
```

`FUN_8006d5dc` is **the same function opcode `0x03` calls** (M144): it resets the thread state and sets
`ctx+0x1c = base + u16[index]`. So the chain is complete and readable end to end:

```
room id byte (DAT_800dfb58+0xc) → DAT_80131fa8[room] → file id → func_0x80004cfc → script base → record 0
```

The id table starts **1881, 1882, 1883 …** (`0x759`–`0x760`) and continues to at least 1927, and
`func_0x80004cfc` is a **named** loader — other call sites use it as `(0x1f94, …, "Init tbl")` and
`(…, "CONF_LD")`, so the fourth argument is a diagnostic tag for a load-by-id.

**This corrects the scope of an earlier conclusion.** M99 recorded the command stream as "absent by
construction" — but that was specifically the resident overlay's BSS buffer at `0x80171df8`. The general
script base is a **cartridge block**, loaded by id, with `"DOOR_SCD"` as its tag. The streams *are* in the
assets; what was missing was the route to the id, and that route is now named.

## 3. A process note against myself

The updated walk-fixture case kept failing while the real output was correct: I had built the patch spec and
**never run it through `patch_text.py`**. That is precisely the silent no-op M131 exists to catch, and the tool
would have caught it in one line — the failure mode is not the tool's absence, it is not invoking it. Worth
recording because the project now has three of these (M131, M136's anchors, this) and the invariant is
"spec built ≠ spec applied".

**Gate: 117 cases across 11 fixtures** (the walk suite's `0x40` case now asserts the confirmed 8 rather than a
stop), `walk_stream --self-test` **20/20**, `ci.sh: ok`, 18/18 marker checks.

## 4. What is left

* **Resolve an id to a member.** `DAT_80131fa8[room]` → `func_0x80004cfc(id, …)`; the loader lives at
  `0x80004cfc` in the **boot** image, and the ids (1881+) should index the same descriptor space M19 used to
  tie the nine registry slots to members. That step turns "a room script exists" into "this member contains
  this room's script" — and then the decoder can finally run on real data with no dump at all.
* The **two size conflicts** (`0x09 Sleep`, `0x26 Calc`) — the PlayStation sizes are 4 and 5/4 where our
  handlers advance 1 and 6, which is either a port change or a name mismatch on those two numbers.
* The **name for `0x1b`**.

```
python3 tools/walk_stream.py --lens        # 129 ok, 6 jump, 6 dynamic, 0 unverified, 0 ambiguous
python3 tools/rdram_fixture.py             # 7/7
python3 tools/acceptance.py                # 117 cases, 11 fixtures
```
