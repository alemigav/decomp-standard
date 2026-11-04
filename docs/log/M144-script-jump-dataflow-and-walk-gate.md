# M144 — `0x03` is a script jump, the advance scan becomes a dataflow, and the walk is in the gate

Three things: the last named-but-unresolved opcode from M142 is characterised, the window search is replaced
by register tracking (which found two real bugs in my own reasoning), and the walk path — until now verified
only by hand — is a suite.

## 1. `0x03` writes no pointer at all: it delegates

The handler is seven instructions and contains **no store to `ctx+0x1c`**:

```
0x8006db98  addiu sp,sp,-24
0x8006dba0  lw    v0,28(a0)      ; the command
0x8006dba4  lbu   a1,3(v0)       ; byte 3 = an index
0x8006dba8  jal   0x8006d5dc     ; the callee sets the pointer
```

and the callee is explicit about what it does:

```c
iVar2 = DAT_80114f2c;                            /* the runtime script base, shared with GoSub */
uVar1 = *(ushort *)(param_2 * 2 + DAT_80114f2c); /* u16 table indexed by the command's byte 3 */
*(ctx + 0x140) = ctx + (char)ctx[2]*0x20 + 0xc0; /* frame pointer reset */
ctx[1] = 1; ctx[0] = 0; ctx[4] = 0xff; ctx[8] = 0xff;
*(uint *)(ctx + 0x1c) = iVar2 + uVar1;           /* ctx+0x1c = script_base + table[index] */
```

So `0x03` is a **script jump by table index** — an absolute jump into a script block, with the thread state
reset, and *no* return address saved (that is what separates it from `GoSub`, which saves `cmd+2` at
`ctx+0x144+idx*4`). It is dynamic for the same reason `GoSub` is: the base is `*(0x80114f2c)` at runtime.

Reading the neighbours settled five more without any guessing — they are not missing lengths, they are
**returns and table dispatches**:

| opcode | what it is |
|---|---|
| `0x01` | no pointer write at all: returns 2 and lets the dispatcher decide |
| `0x10` | block return: `ctx+0x1c = *(ctx + thread*8 + 0x20)` |
| `0x19` | return from the GoSub slot: `ctx+0x1c = *(ctx + 0x144 + idx*4)` — the address `0x18` saves |
| `0x1a` | block return: `ctx+0x1c = *(ctx + thread*8 + 0x60)` |
| `0x36` | table dispatch: `jr <*(0x800c**** + idx)>` — a callback pointer, not a command address |

`0x18`/`0x19` pairing is the cleanest confirmation in this area: one handler stores `cmd+2` into
`ctx+0x144+idx*4`, another loads it back.

## 2. The window search is replaced by a dataflow, and it caught two mistakes of mine

M143's rule — "the store may be up to 8 instructions after the `addiu`" — worked but was arbitrary: `0x32`
needed 4, `0x37` needed **9**, and every widening risked reaching into the next handler. `advance_set` now
tracks, inside the handler's own extent, which registers hold the command pointer plus a constant, and stops
tracking a register when something genuinely overwrites it.

Two bugs surfaced while doing it, and both are the same misunderstanding at different levels:

* **A store does not write a register.** My first version invalidated the tracked register on every
  `sw`, so `0x32`'s `sw a1,40(v1)` destroyed `a1` — the very register holding the pointer. Stores write
  memory; only loads and ALU results write registers.
* **A call clobbers only caller-saved registers.** I cleared everything on `jal`, which lost `0x2d`: that
  handler keeps the pointer in **`s2` across four calls** and adds 38 after them. Preserving `s0`–`s7` is
  what makes it resolve — to **38, exactly the PlayStation size**.

With those fixed:

| class | M143 | now |
|---|---|---|
| `ok` (constant advance) | 128 | **126** |
| `jump` (computed target, size known) | 5 | **5** |
| `dynamic` (target is runtime state) | — | **6** |
| `unverified` | 8 | **3** |
| `ambiguous` | 0 | **1** |

`0x1b` is the ambiguous one — it has two paths, advances `[6, 12]` — and `0x40 PlcDest`, `0x6b`, `0x7c` are the
three left unverified. **37 of 39 walkable named opcodes still match the PlayStation size exactly**, the two
exceptions unchanged (`0x09 Sleep` 1 vs 4, `0x26 Calc` 6 vs 5/4).

## 3. The walk path is in the gate

An RDRAM image is 8 MiB and any real one is cartridge-derived, so the dump is **built, not committed**:
`tools/rdram_fixture.py` writes eight megabytes of zeroes with five short command streams planted in it, then
walks each context and asserts on the output. Committed is the *scenario*, not the blob.

Seven cases, one per behaviour that used to be hand-checked:

```
PASS the walk starts where ctx0 points
PASS Goto derives its target from s16 at byte 4
PASS Goto is followed, not fallen through
PASS ElseStart offers both successors and takes the fall-through
PASS a dynamic opcode stops the walk and says why
PASS an unverified opcode stops instead of guessing
PASS SceEmSet prints its Id field
7/7 synthetic-rdram walk case(s)
```

**Gate: 117 cases across 11 fixtures**, `ci.sh: ok`, 18/18 marker checks.

## 4. The third-party lead: real project, unverified claim

`CalenCyr/SlugfestRecompiled` exists — **GPL-3.0**, C++, last pushed 2026-10-19, "a native PC port of Ken
Griffey Jr.'s Slugfest (N64, USA), built by static recompilation with **N64Recomp**, N64ModernRuntime, RT64
and RecompFrontend". Its README documents the cartridge's structure: a `0x80061600` loader holding libultra's
OS core, a 316-entry file table at `0x80066EB8` using a **MIO0 variant**, ten code modules at `0x80067DA8`
with overlays sharing two slots, **F3DEX2/F3DLX2.Rej** microcode, and audio microcode recompiled with
RSPRecomp.

What that gives us is **method, not semantics** — a second worked example of decomposing an N64 game into
loader + modules + overlays + microcode, and a **recompilation toolchain** that is a genuine alternative to
ares for Phase 4: static recompilation produces a native binary we could instrument, which sidesteps exactly
the wall M109 hit (ares feeding the game `ff ff ff ff`, i.e. no controller).

What I did **not** verify, and will not assert: that the same studio developed both games. It is checkable
(credits for the RE2 N64 port versus Angel Studios' N64 titles) but it is not checkable from this repository,
and nothing in this milestone depends on it.

## 5. What is left

* The three `unverified` opcodes (`0x40`, `0x6b`, `0x7c`) and the one `ambiguous` (`0x1b`) — four reads.
* `*(0x80114f2c)`, the script base that both `GoSub` and `0x03` need: with it, both become followable and
  sub-script entry points become readable.
* The recompilation route, if Phase 4 is wanted.

```
python3 tools/walk_stream.py --lens        # 126 ok, 5 jump, 6 dynamic, 3 unverified, 1 ambiguous
python3 tools/rdram_fixture.py             # 7/7, the walk path
python3 tools/acceptance.py                # 117 cases, 11 fixtures
```
