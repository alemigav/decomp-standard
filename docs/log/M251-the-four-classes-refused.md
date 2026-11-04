# M251 — the four extra classes: the cartridge has no cheap probe for any of them

M250 asked for four more probes — a `switch` that compiles to a jump table, a struct copy, an integer divide and
a floating-point expression — to test codegen classes the first four do not reach. This attempts all four and
**refuses all four**, each with a measurement behind the refusal.

## 1. What was tried, in the order that was cheapest

**Compile a snippet, then search the 36 images for the exact bytes.** Six snippets, each compiled with gcc 2.8.1
and assembled with binutils 2.7, then searched for verbatim (the object's alignment padding cut at `jr ra`):

| snippet | bytes | occurrences in all 36 images |
|---|---|---|
| `int f(int a,int b){return a/b;}` | 52 | **0** |
| `unsigned f(unsigned a,unsigned b){return a/b;}` | 28 | **0** |
| `float f(float a,float b){return a*b;}` | 8 | **0** |
| `float f(float a,float b){return a-b;}` | 8 | **0** |
| `struct S{int a,b,c;}; void f(struct S*d,struct S*s){*d=*s;}` | 28 | **0** |
| `int f(int x){switch(x){case 1:return 3;case 100:return 7;default:return 0;}}` | 36 | **0** |

Zero for an eight-byte `mul.s $f0,$f12,$f14; jr ra` is the informative one: **this cartridge contains no function
that returns the product of its two float arguments.** The classes exist in the game, but not as leaves — so a
snippet cannot become a probe by search.

(One false start worth recording: the first search used the *whole* `.text`, which the assembler pads to 16 or 48
bytes. Every pattern then missed for a reason that had nothing to do with the compiler. Cutting the pattern at
`jr ra` + its delay slot is what makes the search meaningful.)

## 2. What the real functions look like

The only way to probe these classes is to reconstruct the C of a real function, so the smallest candidate in
each class was located and dumped. Two of the four turned out not to be functions:

| class | candidate | why it cannot be a probe |
|---|---|---|
| integer divide | `0x8006e8bc`, 56 B | **a fragment**: `lh v0,0(s1)`, `div v0,s0`, the full divide-by-zero and overflow checks, `mflo`, then `j 0x8006b…` — a **tail jump**, so the range ends inside a larger function |
| floating point | `0x80083e60`, 32 B | **a fragment too**: it computes with `f2`, which no o32 argument register carries, so its inputs are set before the range starts |
| switch | 86 dispatch heads | the arms are the table's **relocations**; comparing one needs every arm placed at its real address — a per-function link, not a snippet |
| struct copy | — | no function copies three consecutive words between two pointers, and the eight-word form is absent (0 hits) |

The divide candidate is also a useful near-miss: `void f(short *p,int q){*p=*p/q;}` compiles to the *same 64-byte
sequence* with `a0`/`a1` where the image has `s1`/`s0`, which is exactly what a fragment looks like — the same
code, compiled inside a caller that had already moved its arguments into callee-saved registers.

## 3. What this means

The compiler identification stands where M250 left it — **gcc 2.8.1, 4 of 4 probes, including a linked one that
2.7.2 cannot reproduce** — but it is now bounded honestly: the cheap probe classes are exhausted, and the next
four require *source reconstruction*, not another toolchain build. That is stage 3 work (typed interfaces and
behavioural contracts), not stage 4, and the corpus says so in `CLASSES_WITHOUT_A_PROBE` rather than leaving the
gap invisible.

Two routes forward, both stage-3:
- **recover the enclosing function** of `0x8006e8bc` and `0x80083e60` (the divide and FP fragments) from their
  real heads, so the probe is a whole function with known C. The corpus already has the boundary machinery
  (`dispatch_heads`, `handler_region`, the extent queue).
- **link one dispatch head** with its arms placed at their real addresses, which makes a jump-table `switch`
  comparable and would test the table addressing, the `sltiu` bound and the `jr` scheduling in one probe.
