# M246 — the compile-probe corpus: IDO is refuted, and 5.3 and 7.1 are the same compiler

The roadmap's stage 4 asks one question before any function is translated: what produced these bytes? The probe
corpus runs five C snippets through every available compiler profile and compares the emitted `.text` with the
image. The answer is **neither IDO version matches** — and the evidence is not a byte diff, because a wrong C
guess and a wrong compiler look identical in one.

## 1. The matrix

`cc -c -O2 -non_shared -mips2 -G {0,8}`, `.text` compared with the image at each probe's address:

| probe | class | IDO 5.3 -G0 | IDO 7.1 -G0 | IDO 7.1 -G8 |
|---|---|---|---|---|
| p1 `void f(void){}` | empty body | **MATCH** | **MATCH** | **MATCH** |
| p2 `int f(int a,int b){return b;}` | return an argument | differ | differ | differ |
| p3 conditional global store | relocation-bearing | differ | differ | differ |
| p4 byte-copy loop | delayed branch | differ | differ | differ |

Two things fall out immediately:

- **IDO 5.3 and IDO 7.1 emit byte-identical code on every probe.** They are not two hypotheses; carrying both
  as separate candidates was doubling the work for nothing.
- **The one match is the empty function**, which has no code to get wrong. Everything with a body differs.

## 2. Why the diff is not the argument

p3 differs at its first word: the object has `lui t6,0x0`, the image has `lui v0,0x8013`. That is not a codegen
difference — **an object file holds relocations, not addresses**, so any probe that names a global must differ
until it is *linked* at the right address. The corpus therefore reports p3 as genuine but uninformative, and the
load-bearing evidence is the census below. Linking objects with `uld` before comparing is the next piece of the
pipeline, not a defect of this one.

p2 and p4 differ for a different reason: p2 shows IDO *homing* both arguments to the stack
(`sw a0,0(sp); jr ra; move v0,a1`) where the image has none, and p4 shows a register-allocation difference
(`addu v1,a0,a2` against IDO's `addu v0,a0,a2`). Homing is a compiler behaviour, not a C behaviour.

## 3. The census that settles it

A move is the least ambiguous C in the language, so the idiom a compiler chooses for it is a fingerprint that
no C guess can spoil. Over all 1 938 stage-2 function ranges:

| idiom | count | who emits it |
|---|---|---|
| `addu rd,rs,$zero` | **6 560** | the GNU MIPS toolchain (`mipse-ultra-gcc`) |
| `or rd,rs,$zero` | **0** | IDO |

and IDO, asked directly, emits `or`:

```
int f(int a){return a;}   IDO 5.3: 03e00008 00801025   (jr ra; or v0,a0,zero)
                          IDO 7.1: 03e00008 00801025
                          image:   03e00008 00a01021   (jr ra; addu v0,a1,zero)
```

**6 560 moves, not one of them `or`.** A compiler that emits `or` for every move did not produce this
cartridge. IDO is refuted, both versions, on evidence that does not depend on recovering any function's C.

## 4. What that means for the plan

The next candidate is the **GNU MIPS toolchain** — the official N64 SDK's `mipse-ultra-gcc` (gcc 2.7.2/2.8.1),
which is exactly what the `Nintendo_64_Developer_Documents_v5.2` disc image in the owner's Downloads would
contain, and what `modern-n64-sdk` / `n64chain` are built around. The probe corpus is already written to take
another profile: adding `gcc-2.7.2` is a tuple in `PROFILES` and the same five probes answer the question again.

This is the outcome stage 4 was designed to produce before mass translation: a **refutation with a number**
rather than a hundred functions translated against the wrong compiler.

## 5. State of the tooling

- `tools/compile_probe.py` — the corpus, 4 cases: the matrix runs, the census holds (6 560 / 0), IDO emits `or`,
  and 5.3 ≡ 7.1.
- Both IDO versions run natively (M245) and GNU `as`/`ld` for mips are built, so any candidate profile can be
  tested the same day it is provisioned.
- Not done here, and named so it is not mistaken for done: no probe has been **linked**; p3 needs that before it
  says anything, and every later probe that names a symbol will too.
