# M298 — `osCreateThread`: the `OSThread` layout for this revision, 23 of 52, and why CI was queued

Two jobs: the next function in the queue, and the stuck CI run. The function is not finished, but its *layout* is now
derived and two of its three deviations are explained; CI turned out not to be broken at all.

## 1. CI was waiting for a runner, not failing

`gh run list` showed the M297 push `queued` for eleven minutes while the run before it started in seconds. The job list
says exactly what it was:

| job | labels | outcome |
|---|---|---|
| `ci` | `ubuntu-22.04` (hosted) | **queued, `runner=-`** — never assigned |
| `full` | `self-hosted, re2-cartridge` | **skipped** (as designed — no such runner here) |
| `full-url` | `ubuntu-22.04` | **skipped** |

So nothing in the workflow is wrong: `runs-on: ubuntu-22.04`, the concurrency group is `ci-refs/heads/master` with
`cancel-in-progress: true`, and the two cartridge jobs skipped because this repo registers **zero self-hosted runners**
(`gh api …/actions/runners` → `total_count: 0`). The `ci` job simply never received a hosted runner — a scheduler wait on
GitHub's side.

It cannot be cleared from here either: `POST /runs/<id>/rerun` answers *"This workflow is already running"*, and
`gh run cancel` answers *"Cannot cancel a workflow run that is completed"* — the run is marked completed at run level
while its one job is still queued, which is the known inconsistent state an unassigned job leaves behind. **The remedy is
a new push**: the next commit starts a fresh run, and the M296/M297 trees are green locally (`VERDICT PASS-FAST`) in the
meantime.

## 2. `OSThread`, as this revision lays it out

`osCreateThread`'s stores name every field it touches, so the layout is read off rather than assumed — and it disagrees
with the later libultra in exactly the places the revision bracket predicts:

| offset | field | note |
|---|---|---|
| `0x00` | `next` | |
| `0x04` | `priority` | |
| `0x08` | `queue` | |
| `0x0c` | `tlnext` | `= __osActiveQueue` (`0x8001294c`) |
| `0x10` | `state` (u16) | `= 1` (`OS_STATE_STOPPED`) |
| `0x12` | `flags` (u16) | |
| `0x14` | `id` | |
| `0x18` | `fp` | zeroed |
| `0x38` | `context.a0` (u64) | `= (u64)(s32)arg` — the high word is stored first |
| `0xf0` | `context.sp` (u64) | `= (u64)(s32)sp - 16` |
| `0x100` | `context.ra` (u64) | `= (u64)(s32)__osCleanupThread`, which is **`0x8000116C`** here |
| `0x118` | `context.sr` | **`0xFF03`, a literal** — the later source computes it from `OS_IM_ALL \| SR_EXL` |
| `0x11c` | `context.pc` | `= (u32)entry` |
| `0x128` | `context.rcp` | `= 0x3F` |
| `0x12c` | `context.fpcsr` | `= 0x01000800` = `FPCSR_FS \| FPCSR_EV` |

Two of those are revision markers in the same sense as M297's PRENMI: `sr` is a **literal** here rather than a computed
mask, and `ra` points at `__osCleanupThread` = `0x8000116C`, which the later tree places elsewhere.

## 3. What stops it at 23 of 52, and the toolchain defect that cost two attempts

The reconstruction follows Nintendo's statement order with this revision's constants, and the *code* is right — the
differences are scheduling. The first compile scored 10/52 because I wrote `thread->ra = (u64)(s32)0x8000116C`, a
literal that cc1 folded into `li -1` for the high word; the image materialises the **symbol** and sign-extends it at
runtime (`lui`/`addiu` then `sra`), which is what `__osCleanupThread` produces. Naming it took the score to **23/52**.

The remaining deltas are one block of instructions transposed: the image loads the 5th parameter (`sp`) at the top of the
function, before any store, and computes the `u64` pair much later; ours keeps the load next to its use. That is the
scheduler's placement of a parameter load in a 52-word straight-line body — the same class as `0x8007e590`'s single
register, and the reason this is recorded as progress rather than pinned.

And a defect worth its own line, found because transcribing a struct wants a column of offsets: **this `cc1` cannot parse
comments at all.** `/* … */` — trailing or on its own line — is a parse error, and when the preceding line also has a
missing typedef the two report identically, as mojibake. A `/* 0x100 */` column cost two compile attempts. It is now a row
in `docs/TOOLCHAIN.md`'s obstacle table, and it explains why every probe source in the corpus is comment-free.

## 4. State

The queue, unchanged except for what this pass established:

| function | words | status |
|---|---|---|
| `osCreateMesgQueue` | 9 | **byte-exact** |
| `osCreateThread` | 52 | **23/52** — layout derived, constants pinned, residue = parameter-load scheduling |
| `osRecvMesg` | 73 | not started |
| `osSendMesg` | 76 | not started |
| `osSetEventMesg` | 24 | **byte-exact** |
| `osStartThread` | 70 | not started |

Sixteen recovered, fifteen byte-exact, corpus 45 cases, all passing, local gate green. CI for the M297 push is still
waiting for a runner and will be replaced by this push's run.
