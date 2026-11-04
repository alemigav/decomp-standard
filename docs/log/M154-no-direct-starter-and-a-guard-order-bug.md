# M154 — no direct starter exists, `0x0f` was mis-sized, and a guard-order bug made my own model inert

Three results: the search the owner asked for comes back empty, reading `0x0f` corrected a published length,
and finding it exposed a bug that invalidates the reachability numbers of the last four milestones.

## 1. The direct-write search: nothing starts a fragment

148 stores to `+0x1c` exist in the 36 decompiled images. Classified:

| kind | example | verdict |
|---|---|---|
| the handlers' own advances | `*(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;` | expected — this *is* the VM |
| `0x0f`'s block runner | `0x8006dfe4` writes `cmd+4` then the block end | legitimate, and now modelled (§2) |
| **`0x8002cfdc`** — writes `*(*param_1 + 0x1c) = iVar2` | a double indirection, the best candidate | **not a script write**: the same routine writes `*param_1 + 0x14 = 0x6b` and `+0x18`, then calls `*(*param_1 + 4)`, and compares against `0xc0`/`0xd0` with `& 7` masks — that is **controller/pad state in a different struct**, not a context |
| boot-image and overlay struct fields | `*(short *)(*(int *)(uVar8 + 0xfd0) + 0x1c)` | different structures entirely |

So **no code writes a context's command pointer to start a script except the handlers and `FUN_8006d5dc`**. The
115 fragment blocks have no starter in these images; the callback theory stays refuted and the fragments stay
unexplained by anything we can see.

## 2. `0x0f` read in full — and it was mis-sized

`FUN_8006dfe4` is the **if/else block runner**:

```c
iVar5 = (char)ctx[2];                      /* thread */
iVar3 = ctx[0x1c];                          /* the command */
depth = ++ctx[iVar5 + 8];
slot  = ctx + depth*4 + iVar5*0x10;
*(slot + 0x20) = iVar3;                     /* push the command pointer */
iVar4 = iVar3 + 4;      ctx[0x1c] = iVar4;  /* **advance 4**, the block body */
*(slot + 0x60) = iVar4 + *(short *)(iVar3 + 2);   /* the block END */
iVar3 = FUN_8006e1bc(ctx, iVar4, *(byte *)(iVar3 + 1));  /* run the block, span = byte 1 */
if (iVar3 == 0) { ctx[0x1c] = *(slot + 0x60); depth--; }  /* false -> skip to the end */
```

So the header is **`[opcode][span][u16 end]` = 4 bytes**, and the block that follows starts at `cmd+4`. The
length map published **2** — the scan had found an `addiu …,2` (`span`-sized) elsewhere in the handler and
taken it as the command length. Corrected via an explicit `LENGTH_OVERRIDE` in `walk_stream.py` that carries
the instructions, so `--lens` now prints `0x0f … len 4` and the decoder no longer desynchronises by two bytes
on every if/else construct (317 occurrences in the corpus).

## 3. My own bug: a guard order made the whole dynamic branch dead code

`cfg_reach.py` guarded with

```python
if r is None or r["length"] is None or p + r["length"] > len(raw): break
```

**before** looking at `r["status"] — and dynamic opcodes have `length = None`. Every pop, every `0x03` target
and every `0x19` return was therefore unreachable *code*, while the branch that handles them sat right below it
looking correct. In other words: from M150 to M153, the reachability tool ignored exactly the mechanism those
milestones were about, and the suite's own case — *"block returns no longer stop the walk"* — passed by never
running them at all. **Third instance of the same lesson**: a check must be able to fail for the right reason.

With the guard reordered, the honest numbers are:

| mode | record starts reached from record 0 |
|---|---|
| `--entry` (plain) | 1 117 / 5 738 = **19.5 %** |
| `--entry --generous` (an unresolvable pop resumes at every record start) | 1 695 / 6 123 = **27.7 %** |
| all starts seeded | 100 % (tautological, kept only as a completeness check) |

and the dead-only list settles at **three**:

| opcode | occurrences | len | what it is |
|---|---|---|---|
| `0x6a` | 50 | 6 | object-table field writer on `*(0x800c76b0+0x20000)+636`, stride 20 |
| `0x7a` | 13 | 16 | stride-76 table at `*(ctx+0x154)+0x234`, flags/values into an entry |
| `0x7f` | 9 | 6 | the same object table, stride 20 |

All three are **object/effect table writers** — consistent with code that would run for an entity or effect that
never spawns in the reachable flow.

## 4. What is now settled, and what is not

* **Settled:** no engine path starts a non-zero record (M152); no code anywhere writes a context's command
  pointer outside the handlers and `FUN_8006d5dc` (this milestone); `0x0f`'s size and role; and the interpreter
  loop's return-value semantics.
* **Not settled:** why 115 blocks begin with a return, and therefore whether the three opcodes are dead in an
  absolute sense. There is no starter *in these 36 images* — that is the strongest form the claim can take
  without a runtime capture.

## 5. Gate

**133 cases across 14 fixtures**, `cfg_reach --check` 5/5, `ci.sh: ok`, 18/18 marker checks. The profile was
regenerated after the `0x0f` correction (counts unchanged at 102 673 commands; `0x0f` 317).
