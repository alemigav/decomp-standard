# M271 — p9 recovered byte-exact on the second attempt, and the shape facts that made it so

The instruction was to take the next function from the dispatch-head queue and run it the same way. The next one is
**p9 at `0x80070120`** — the fourth of M253's heads, and the only one that had never been recovered as a whole
function (it was signature-compared only). It is also the smallest: **46 words**.

## 1. What the function is

A **predicate dispatcher**, not a state machine. It advances a pointer by 6 bytes out of a cursor field, reads a
command word from it, calls the next function with `(ctx->f154, command >> 8)`, and switches on the low byte:

```c
p = s->ptr;  w = *(u16 *)(p + 2);  v = *(s16 *)(p + 4);  s->ptr = p + 6;
x = FUN_800701d8(s->f154, w >> 8);
switch (w & 0xff) {
case 0: return x == v;      case 1: return x > v;       case 2: return x >= v;
case 3: return x < v;       case 4: return x <= v;      case 5: return x != v;
case 6: return (x & v) != 0;
}
```

Every arm is 2 or 3 words (`slt`/`sltu`/`xor`/`and` plus a `j` back to a shared epilogue), and the head is 23 words.

## 2. The result: 46 of 46, third byte-exact function

| region | words |
|---|---|
| head `0x80070120` | **23 / 23** |
| cases 0–6 (`0x8007017c … 0x800701bc`) | **18 / 18** |
| epilogue `0x800701c4` | **5 / 5** |
| **whole function** | **46 / 46 by offset, 46 / 46 content-aligned** |
| **jump table at `0x800b96a8`** | **8 / 8** |

The single "hunk" is two zero words **past the image's extent** (`0x800701d8` is the next function): binutils 2.7's
`as` pads `.text` to 16-byte alignment and `--set-section-alignment .text=4` rewrites `sh_addralign` without
shrinking the section — the same residue class as p6's and p8's padding.

Independently re-measured after the recovery, not taken on report: same 46/46 and 8/8.

## 3. Two shape facts that are *measured*, and one that is provable

- **Variable width, not statement order.** `w` must be held in a **32-bit** local. With a `u16` local gcc keeps an
  HImode pseudo and re-emits `andi $s0,0xffff` before the `srl` and the `sll`/`sra` re-sign-extension in all seven
  arms: **9 of 46**. Every other shape lever this arc has tried was about ordering; here the lever was width.
- **The source has no `default:` and no trailing `return`.** The out-of-range path lands on the epilogue with `v0`
  still 0 from the bound's `sltiu`, so the function "returns 0" by falling through. Adding either a `default:
  return 0;` or a trailing `return 0;` costs **16 words** (30 of 46). That is a cheap, general shape test: **does
  the image contain the `li v0,0`?** If not, the C had no default.
- **The tail arm falls into the epilogue** rather than jumping to it, because gcc needs no jump for the last case
  body — which is why the last arm is 2 words and the others are 3.

## 4. Corpus

p9 joins the probe as a fourth whole-function case plus a table case, so the corpus is **24 cases, all passing**,
with the pins asserting exactness (`same_offset == 46`) rather than a threshold. Coverage of reconstructed functions
is now: **`0x8004fd1c` exact (98), `0x80057e1c` exact (84), `0x80070120` exact (46), `0x80024558` 136 of 139.**

## 5. What this says about the method

Three of four recovered functions are byte-exact, and the failures cluster in one place: the 139-word function whose
residue is allocation (M270). The 46-word one came out exact on the second attempt, with the first attempt already
at 30 of 46. That is the shape of the method working: **small functions with unambiguous data flow come out exact,
and the cost is reconstruction time, not compiler archaeology** — the archaeology (M257–M265) was paid once and now
applies to every function.

The README's *The matching build* table and the P16 phase row were updated to four recovered and three exact; the
case counts moved with the two new gates.
