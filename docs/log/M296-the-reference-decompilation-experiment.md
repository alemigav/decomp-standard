# M296 — the reference-decompilation experiment: `osCreateMesgQueue` byte-exact, and OoT is a *later* libultra

The idea was that shared code — the boot/runtime layer — might already be solved in other decompilations. It is, and this
milestone both demonstrates that and pins the one thing that would have made it go wrong.

## 1. The reference has to be chosen for the right layer

`perfect_dark` is **not** a code reference: Rare modified libultra heavily, their own RSP microcode among it, so its
runtime is not the stock one. The narrower use M124 made of it — `include/PR/` **struct layouts** (controller, pak) —
still stands, because those are Nintendo's headers and engine-independent.

For stock libultra the right reference is **`zeldaret/oot`** (MIT), whose `src/libultra/os/` is Nintendo's own C. Our RSP
work is unaffected either way: that microcode was decoded separately and deliberately never named.

## 2. The experiment, and the result

Our symbol table already named eight libultra functions with addresses (M18/M22/M24/M27), all in the **boot** image —
which is the second useful thing this turned up: every one of the fifteen recovered functions before this milestone was
in stage-2, and the runtime lives somewhere else. So the test was direct: take Nintendo's C, compile it with our
pipeline, and compare at the known address.

`osCreateMesgQueue` at `0x80006d30` (boot, base `0x80000480`, raw at ROM `0x1000`):

```
image:  lui $2,0x8001 ; addiu $2,$2,0x2940 ; sw $2,0(a0) ; sw $2,4(a0) ;
        sw $0,8(a0) ; sw $0,12(a0) ; sw $6,16(a0) ; jr ra ; sw $5,20(a0)
ours :  identical, byte for byte — 36 B, 9 words
```

Six field stores at the six `OSMesgQueue` offsets, both queues pointing at the same `&__osThreadTail` (`0x80012940`), and
the last store in the `jr`'s delay slot. **Nintendo's libultra source, compiled by this gcc 2.8.1 + `as -g` pipeline,
reproduces the image exactly.** That is the proof that RE2's runtime was *rebuilt from libultra source with this
compiler* rather than linked as Nintendo's precompiled objects — which is also what the `or`/`addu` census said from the
other direction (zero `or rd,rs,zero` against 8,501 `addu`).

It is now a probe case, and the first one that does not read the stage-2 payload at all: `boot` is read from the ROM at
`0x1000`. It is also the first **library** function in the corpus, and it carries a real name from Nintendo's own API
rather than a `FUN_` label.

## 3. The caveat that makes the reference usable only per function

`osSetEventMesg` at `0x8000cc90` does **not** match OoT's version. Ours is 24 words: save three registers, call
`__osDisableInt` (`jal 0x800072e0`), store `queue` and `msg` into `__osEventStateTab[e]` (`0x80017730`), call
`__osRestoreInt` (`jal 0x80007300`), return. OoT's carries an extra `if (e == OS_EVENT_PRENMI)` block with
`__osShutdown`, `__osPreNMI` and an `osSendMesg` call.

So **RE2's libultra is an earlier revision than OoT's** — pre-PRENMI. The reference is therefore usable as *shape and
interface*, not as text to be trusted wholesale: each function has to be reconstructed against our own bytes, exactly as
game code is. That is not a small caveat; it is the difference between "the library is already solved" and "the library
is now a well-documented reconstruction target with known names".

## 4. What this changes in the project, and what it does not

- **A named, shared target class**: the runtime's functions have documented interfaces and struct layouts
  (`OSMesgQueue`, `OSThread`, `OSEvent`…), so each one is a `recovered.json` entry waiting to be measured — and their
  names are Nintendo's, not guesses.
- **A bug fixed on the way**: the analysis ladder counted a function at F1 only when the provider said `written`, so
  since M289 our own byte-exact reconstructions had been counted as *less* than a provider body. `status == "recovered"`
  now takes the same rung: **F1 3 402 → 3 416, F2 3 315 → 3 329** — fourteen functions had been silently demoted by the
  very mechanism that recorded their evidence.
- **Not** a claim that the runtime is solved: one function of eight known addresses is matched, and the revision
  question means the rest need their own reconstructions.

State: **fifteen functions recovered, fourteen byte-exact**, map
`3416 functions · █ 14 reproduced byte-for-byte · ▓ 1 recovered`, corpus **44 cases, all passing**, and the references
section of the README now says which project is a code reference and for which layer.
