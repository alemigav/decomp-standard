# M276 — 0x800acae4: the streak held, and four shape facts a 53-word function can pin

After M275's half-done 229-word function, the next target was chosen deliberately to be *small* — 53 words — and it
came out **byte-exact**: **53 of 53 by offset and by content**, jump table **7 of 7** at `0x800ba890`, with only the
`as` alignment padding past the extent (the sixth instance of that class).

## 1. What it is

A **clamp-then-dispatch predicate**, and the first target whose dispatch is on an **offset domain**: the index is
`(cmd & 0xff) - 128`, so the cases are `0x80…0x85` and the table's 7th word is never read. The head does most of the
work — it clamps the third argument into `[0, 0x3fff]` before the switch — and the six arms are two words each with
one 18-word arm carrying the default and the epilogue.

```c
v = v < 0 ? 0 : (v >= 0x4000 ? 0x3fff : v);
c = cmd;
switch (cmd & 0xff) {
case 0x80: c = 0x80; break;   case 0x81: c = 0x82; break;   case 0x82: c = 0xa0; break;
case 0x83: c = 0xa1; break;   case 0x84: c = 0x83; break;   case 0x85: c = 0x84; break;
}
if ((c & 0xff) < 0xa2) { if ((c & 0xff) >= 0xa0) return; }
if (s->f4a == 0xff) return;
id = (u8)cmd;
cmd = s->f4a;
FUN_800ab7e0(id, cmd, s->f4b, v);
```

Per region: **head 25/25**, arms 0–5 **2/2 each**, tail **16/16** — measured separately before the total was believed.

## 2. Four shape facts this function pins, each a discriminator

| fact | wrong shape | how the image says so |
|---|---|---|
| a clamp written as a **ternary** | if/else-if inverts the first branch | `bltz … slti … beqzl` is exactly `v < 0 ? 0 : (v >= K ? K-1 : v)` |
| a **truncation** `(u8)x` is not a mask `x & 0xff` | `x & 0xff` | cc1 reuses an already-live `li v0,255` and emits `and rd,rs,v0` instead of an `andi` |
| two separate `slti`s ⇒ **nested ifs** | one folded range test | `x >= A \|\| x < B` would fold into the `addiu`/`sltiu` range idiom; the image has two `slti`s |
| a switch phi landing in `a0` rather than `t0` | — | it means an incoming parameter is **still live to a later call**; here param0 *is* the call's first argument, which is why the head parks it in `t1` |

The second one is the most portable: **when a value is truncated for storage or argument-passing, the source used a
cast, not a mask**, and the difference is visible as `andi` (immediate) versus `and` (register holding 255).

## 3. Coverage, and the shape of the method

| function | words | result |
|---|---|---|
| `0x80070120` | 46 | exact |
| `0x800acae4` | **53** | **exact** |
| `0x80057e1c` | 84 | exact |
| `0x8004fd1c` | 98 | exact |
| `0x80024558` | 139 | 136, residue is allocation |
| `0x80059868` | 167 | exact |
| `0x80059530` | 206 | exact |
| `0x8007e590` | 229 | 95 so far (M275) |

**Six of eight exact.** The two failures are the largest two, and they fail differently: `0x80024558` is off by three
words of allocation, `0x8007e590` is half-done because its 113-word arm's statement order is unsolved. Everything at
or below 206 words has come out exact.

That is now the honest predictor, and it is a *size* predictor with a mechanism behind it: below roughly 200 words the
reconstruction's data flow pins the allocation tightly enough that the compiler has no freedom left to disagree with;
above it, one wrong local width or statement order has room to move the whole body.

Corpus **30 cases, all passing**; the map now shows a sixth bright cell, from one table entry plus `--write`.
