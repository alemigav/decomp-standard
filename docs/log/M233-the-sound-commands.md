# M233 — the sound commands: six opcodes, one that plays nothing, and one dead operand

The audio backlog asked which script events start a voice and what they pass. This answers that for the six
opcodes that touch the sound subsystem, from their handlers, and it refutes one of the names it inherited.

## 1. Which six, and why the sixth has no name

`0x51 SceBgmControl`, `0x59 XaOn`, `0x84 SndMode`, `0x85 SndPlay3D`, `0x86 SndBusy` are named by the licensed
PS1 table (M142). `0x83` has **no** name. It is included because it sits *inside* one contiguous handler run:

| opcode | name | handler | extent | bytes | carved as | advance | operands |
|---|---|---|---|---|---|---|---|
| `0x51` | SceBgmControl | `0x8007235c` | `0x8007235c..0x800723cb` | 112 | function_body | **6** | `lbu@1..5` |
| `0x59` | XaOn | `0x80072548` | `0x80072548..0x800725ab` | 100 | function_body | **4** | `lbu@1`, `lhu@2` |
| `0x83` | — | `0x80073410` | `0x80073410..0x80073447` | 56 | fragment | **1** | none |
| `0x84` | SndMode | `0x80073448` | `0x80073448..0x800734af` | 104 | fragment | **2** | `lbu@1` |
| `0x85` | SndPlay3D | `0x800734b0` | `0x800734b0..0x80073563` | 180 | function_body | **6** | `lbu@1`, `lbu@2`, `lhu@4`, `lbu@3` |
| `0x86` | SndBusy | `0x80073564` | `0x80073564..0x8007358f` | 44 | fragment | **1** | none |

`0x83..0x86` are adjacent with no gap between them (`0x80073410 → 0x80073590`), which is a measurement; being
unnamed is why `0x83` is listed rather than dropped. Every advance here is **re-derived from the store the
handler makes to `ctx+0x1c`**, not read out of the registry, and all six agree with the published value.

Three of the six are **fragments**, not function bodies: they are stubs inside a larger body, so there is no
decompiled C of their own to read. Their readings below are from words.

## 2. `0x85 SndPlay3D` plays nothing

Its only call is `FUN_8006ab40`, and **that function makes no call at all**. So nothing reachable from the
command reaches the sound engine. What it does instead:

```
cmd+1, cmd+2  two indices into DAT_800e13e8 (the object/entity table), scaled by 4
              each slot's +0x28, +0x2c, +0x30 are copied out: two 12-byte positions
cmd+4 (u16)   passed as the 3rd argument
cmd+3 (u8)    passed as the 4th argument
              jal FUN_8006ab40(from, to, u16, u8); return (result == 0)
```

and `FUN_8006ab40` is a **zone-visibility test**: it walks 16-byte records at `*(0x800df92c + 0x20)`, tests
the segment between the two positions against each rectangle, honours an elevation band
(`>> 0xb`, `& 0x1f`), and **masks the records against the `u16`**. So the `u16` is a selector mask and the
byte is an early-out flag, not a sound id.

The command returns a boolean to the script. Whatever `SndPlay3D` means on the PlayStation, here it is
*"is this segment visible across zones, and stop at the first one that is"*. **The name is not supported by
the bytes**, and this note is where that is said.

## 3. `0x59 XaOn` reaches the engine — and its byte is dead

Two hops, and the second one crosses an image:

```
0x80072548  lbu a0, 1(cmd) ; lhu a1, 2(cmd) ; jal 0x80004a6c
0x80004a6c  boot image. if (DAT_8011a718) { v = u16[DAT_8011a718][a1];
                                          starts a voice at 0x800b3704 with
                                          (v, v&0x8000 ? 8000 : 16000, 0x7f, vol, 0x3f, 0, 0) }
0x800b3704  stage2, function body 0x800b3704..0x800b398b — the voice starter
```

The `u16`'s top bit selects **8 kHz vs 16 kHz**, so the table entries carry a rate flag. And the byte the
command passes is **dead**: the first instruction in the boot callee that touches `a0` is
`lw a0,-22760(v0)` — a *write before any read*. The nine later uses are a scratch register, which is what a
dead argument looks like when you count uses instead of checking order. `a1` is live, as the test requires.

So `XaOn` is effectively a **three-byte** command: `0x59`, a dummy byte, and a `u16` index.

## 4. What the table is, and why the "per-room" reading is refused

`DAT_8011a718` is the table base, and it is **zero in the image**. Two writers:

* `FUN_800762b0`: `base = *((&PTR_PTR_80119e20)[0x800e110c < 0] + DAT_800e8ca8*4 + 4)` — one of **two** pointer
  tables chosen by the sign bit of the sound flag word, indexed by `DAT_800e8ca8` (values 0, 2 and 0x1c are
  written elsewhere), field +4;
* the overlay `FUN_8017b530`: `base = 0x80115440`, a literal, under `(0x800e10ec & 4) != 0`.

So the table is selected at run time from a per-scene index this tool cannot resolve, and the backlog's
"per-room 48-record sound tables" is **not established** here: `DAT_800e8ca8` is a stage-like index, and no
count of 48 appears in any derived quantity. That is a refusal, not a negative.

## 5. The two commands that call nothing

`0x83` advances 1 and copies a halfword from `0x8010132e` to `0x80101322`, zeroing `0x801013e4`/`0x801013e6`
on the way — a state reset with **no operand at all**. `0x86` advances 1 and returns `lhu 0x1d34(0x800df6b0)` =
`*(u16*)0x801013e4 < 1` — the flag `0x83` just cleared. So `0x83`/`0x86` are a **pair**: park and test.

`0x84 SndMode` advances 2 and reads one byte, storing it at `0x8012f522`; it also sets `sb 4` at
`0x8012bfa8`, `sb 1` at `0x80131780`, ORs `0x8000` into `0x800e110c` — **the same flag word `0x59` ORs `0x20`
into** — and copies `0x800e1110` into `0x801317c4`.

## 6. The tool, and what it does not prove

`tools/sound_ops.py` → `manifests/sound_ops.json`, **10 cases**, 3 mutations (the context pointer not followed
through `s1 = a0`; `lhu` dropped from the load set; the advance taken from the registry). Two defects of my
own were caught by its own cases while writing it:

* the operand scan held **one register** and read `0x83`'s `lhu v1,0x1c7e(v0)` as an operand *after* `v0` had
  been rebuilt as `0x800df6b0` — a rebuilt base is not a command pointer, so the alias has to be dropped at
  every rewrite;
* the first version of the **cases** read the *committed artefact*, which makes them tautologies: no change to
  a derivation can move a number read back out of the file it was written to. They now grade the fresh
  derivation, which is why the mutations bite the cases that name them.

Not claimed: that a voice id selects a specific clip; that the zone mask corresponds to rooms; the semantics
of `0x83`/`0x84`/`0x86` beyond the words they write; and that anything here reconciles the `DOOR_SCD` family
or the 33xx/35xx asset families the backlog names — those are still open, and no corpus source names the file-table ids
3379 or 3504, and the families at those ids are unexamined.
