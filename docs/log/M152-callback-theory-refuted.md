# M152 — the callback theory is refuted by the code, and the interpreter loop is now read

The code-side search the owner asked for settles it in the negative, and reading the loop that calls these
functions answered a question that has been open since M136: what the handlers' return values *mean*.

## 1. No engine path starts a record other than 0

Every call site of `FUN_8006d5dc` — the function that sets `ctx+0x1c = script_base + u16[index]`:

| site | call | index |
|---|---|---|
| `0x8009b27c` (room script load) | `FUN_8006d5dc(&DAT_80114958, 0)` | **0** |
| `0x8006d628` (context starter) | `FUN_8006d5dc(&DAT_80113ad0 + iVar4)` where `iVar4 = (param_1*2 + param_1) * 0x7c = param_1 * 0x174` | **0** — the per-context pointer arithmetic, nothing else |
| `0x8006db98` | `FUN_8006d5dc(ctx, *(byte *)(*(ctx+0x1c) + 3))` | this **is** opcode `0x03`: a script-internal jump by table index |

So the engine starts **each context at record 0 of the room's script**, and the *only* way to a non-zero record
is `0x18 GoSub` or `0x03` from inside the script itself. **The callback theory is refuted**: there is no code
path that invokes an arbitrary record. The 8 opcodes from M151 therefore sit in records that nothing starts.

## 2. What that means for the dead-code list — stated precisely

M151's eight opcodes (`0x59 XaOn` 234, `0x4c SceEsprKill` 100, `0x6a` 51, `0x62` 38, `0x5f` 17, `0x7a` 15,
`0x71` 14, `0x7f` 10) are, on this evidence, **not executed in the room-script flow**: no engine call starts
their records and no script path from record 0 reaches them. What is *not* proven is that they never execute at
all — three stop reasons in my walk are still unmodelled (§4), so a complete proof would need those closed.

The honest status is therefore: **refuted theory, surviving observation, incomplete proof** — and that is worth
more than the earlier "plausibly engine-invoked" hedge, because the hedge is now dead.

## 3. The interpreter loop, read at last

`FUN_8009b880` is the scheduler that runs these contexts, and it fixes the meaning of every handler's return
value:

```c
do { iVar1 = table[ctx[0x1c]](ctx); } while (iVar1 == 1);      /* keep going only on 1 */
if (iVar1 == 2 || (char)ctx[(char)ctx[2] + 4] < 0) break;      /* 2 = yield out */
iVar1 = *(int *)(ctx + 0x140);                                  /* block pop */
ctx[0x140] = iVar1 - 4;
ctx[0x1c]  = *(int *)(iVar1 - 4);
ctx[(char)ctx[2] + 4] -= 1;
```

* **return 1 = "run me again"** — which is why the NOP handler returns 1 and why a *blocking* command like
  `~WaitCount` (0x0a) returns 2 only when its counter expires;
* **return 2 = yield** — `0x02 ~CondEnd`, `0x01` (record terminator) and the not-yet-expired `~WaitCount`;
* the **frame pop** is `ctx+0x1c = *(ctx+0x140 - 4)` with `ctx+0x140 -= 4` and the depth decrement at
  `ctx+thread+4` — the mechanism M150 modelled structurally from the handlers, now confirmed at the loop.

## 4. Two structural facts that invalidate earlier assumptions

* **886 of 1 087 record tables are not in ascending order.** Record 0 of block 932 sits at `0xfad5` while
  record 1 sits at `0x51`. So "records are laid out sequentially" is false, and every earlier test of mine
  that used "the next record's offset" as a record's *end* was measuring nonsense — that is why M149's
  "trailing bytes" test produced 2.7 MB of tail.
* **Corrected stop reasons** for a record-0 walk (the M151 census counted dynamic opcodes as truncations, a
  third measurement defect): **426** end at the `0x01` terminator — i.e. normally — 121 at `0x03`, 114 at a
  `0x10` block pop with an empty stack, ~250 leave the command stream, 19 at `0x19`, 1 at `0x36`. So the model
  does **not** truncate in 65 % of blocks; it ends normally in 39 % and needs three dynamics modelled
  (`0x03` in that particular census, `0x10` with an empty stack, and the stream exits) to explain the rest.

## 5. What is left

* **`0x10` with an empty stack** (114 blocks): in real execution the stack is not empty because the walk began
  mid-block at a record entered by a call. Running the walk from record 0 with an empty stack is the
  structural limitation, not a property of the code.
* **Leaving the command stream** (~250 blocks): worth one pass to see whether these are records whose code
  genuinely ends in data (inline tables) or a length error; `Switch` case tables were tested and ruled out
  (687 of 923 have no `Switch` nearby).
* With both closed, the 8-opcode observation becomes a proof — or disappears.

## 6. Gate

No suite changes: **133 cases across 14 fixtures**, `cfg_reach --check` 5/5, `ci.sh: ok`, 18/18 marker checks.
This milestone is code reading and measurement honesty, and both are recorded rather than assumed.
