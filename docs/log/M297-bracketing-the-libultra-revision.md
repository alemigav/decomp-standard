# M297 — bracketing the libultra revision, and the second runtime function

Two jobs: bracket the revision from the image, then work the runtime queue in address order. The bracket stands on three
independent pieces of evidence, and the second function matched on the first try *because* of it.

## 1. The bracket

**The header field.** The ROM header's libultra field (`0x0C`) reads **`0x00001444`**. Under the field's convention —
`0x14` = 20 → "2.0", trailing byte as the sub-revision letter — that is **libultra 2.0D**. Stated as a *hypothesis*: the
encoding is inferred from the field's layout, not from a document we hold, and no string in the 64 MB ROM names a
version (`libultra`, `LibUltra`, `Nintendo`, `R4300`, `IPL3`: **zero** occurrences each), so the field is the only
direct claim available.

**The PRENMI absence.** `osSetEventMesg` in this image is 24 words: save three registers, `__osDisableInt`, two stores
into `__osEventStateTab[e]`, `__osRestoreInt`, return. Nintendo's later libultra adds an
`if (e == OS_EVENT_PRENMI)` block there, with `__osShutdown`, `__osPreNMI` and an `osSendMesg` call. This image has no
such branch — so RE2's revision **predates PRENMI support**.

**The event numbering.** The four `osSetEventMesg` call sites our own analysis instrumented (M24) pass `AI=4`, `PI=6`,
`SP_BREAK=9`, `RDB=14`. The modern enum has `AI=6`, `PI=8`, `SP_BREAK=11`, `PRENMI=14` — every one of ours is **two or
three lower**, i.e. the table is compact without the events later revisions insert (`CART`, `PRENMI`). That is
consistent with, and independent of, the PRENMI result: not only is the *function* pre-PRENMI, the *enum* is too.

So the bracket is: **`0x00001444` (2.0D-era) ≤ RE2's libultra < OoT's**, and the operational consequence is the one that
matters — OoT's source is usable wherever a function's shape agrees with the image, and must not be trusted where it
does not. The agreement is now measurable per function, which is what the rest of this note does.

## 2. The queue, worked in address order

| function | address | words | status |
|---|---|---|---|
| `osCreateMesgQueue` | `0x80006d30` | 9 | **byte-exact** (M296) |
| `osCreateThread` | `0x80006d60` | 52 | not yet — needs the `OSThread` layout for this revision |
| `osRecvMesg` | `0x8000c9e0` | 73 | not yet |
| `osSendMesg` | `0x8000cb60` | 76 | not yet |
| `osSetEventMesg` | `0x8000cc90` | **24** | **byte-exact (new)** |
| `osStartThread` | `0x8000db90` | 70 | not yet |

`osSetEventMesg` is the milestone's second library function: **24 of 24 words, zero differences**, from Nintendo's
source with exactly the PRENMI block removed. Two things about it are worth recording beyond the match:

- **the index under-counts it**: `code_index.json` says 23 words, and the function is 24 — it ends one word after the
  provider's body (the epilogue's `addiu sp,sp,32`). The recovered fixture now carries 24, and coverage grew by those
  4 bytes (1 211 252 → 1 211 256).
- **it is the bracket made operational**: the same reference text *minus one block* reproduces the image byte for byte.
  That is what "pre-PRENMI" means in this project's terms — not a version label adopted from a changelog, but a measured
  difference in the code, with the delta named.

## 3. State

**Sixteen functions recovered, fifteen byte-exact**, of which **two are library functions** (both from the boot image,
both with Nintendo's own API names rather than `FUN_` labels). The map reads
`3416 functions · █ 15 reproduced byte-for-byte · ▓ 1 recovered`; corpus **45 cases, all passing**; every derived
artefact regenerated.

The remaining four are 52–76 words each and all need `OSThread` at *this* revision's offsets — which the image supplies
directly (`osCreateThread`'s stores name them: `context.pc` 0x100, `context.a0` 0x104, `context.sr` 0x118,
`context.fpcsr` 0x128, `context.ra` 0x12c, `context.sp` 0xf0/0xf4, `tlnext` 0x38, `state` 0x10, `flags` 0x12,
`id` 0x14, `fp` 0x11c, `priority` 0x04…). That is the next step, and it is a layout exercise rather than an archaeology
one, which is the difference this experiment was looking for.
