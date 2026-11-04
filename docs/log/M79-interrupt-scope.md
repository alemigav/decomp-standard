# M79 — Scoping the interrupt context path

**Question:** what does the harness need in order to take an interrupt, run the guest's handler, and return to
the interrupted code — without executing the boot chain off the end of its stack (the M78 crash)?

The answer turns out to be narrower than "implement context switching", because **the guest already does it**.

---

## 1. What the guest handler does (disassembled, not assumed)

`E_VEC` → preamble `lui k0,0x8000 ; addiu k0,k0,0x6d0 ; jr k0` → handler at `0x800006d0`:

```
0x800006d0  lui k0, 0x8001
0x800006d4  addiu k0, k0, 0x5000      k0 = 0x80015000, a fixed exception work area
0x800006d8  sd at, 0x20(k0)          SAVES 64-BIT REGISTERS with sd
0x800006dc  mfc0 k1, $12             read Status
0x800006e0  sw k1, 0x118(k0)         Status at +0x118 (the same slot __osCurrentThread uses in a thread)
0x800006e4  addiu at, zero, -0x4
0x800006e8  and                      mask the low two bits (IE, EXL)
0x800006ec  mtc0 k1, $12             write Status back
0x800006f0  sd t0, 0x58(k0)
0x800006f4  sd t1, 0x60(k0)
0x800006f8  sd t2, 0x68(k0)
0x80000700  mfc0 t0, $13             read Cause
…
0x80000730  mfc0 t2, $9              read Count
```

Later, at `0x80000764`–`0x80000768` it does `lw k0, 0x2950(k0)` — **`__osCurrentThread`** — and copies the frame
into the thread's own context. The restore side is the mirror image already mapped in M46
(`ld at…ra`, `mtc0 $12`, `lw pc` → `mtc0 $14`, `eret`).

**Consequence:** the harness must not implement context switching. It must implement **CP0 fidelity well enough
that the guest's own save/restore round-trips**. That is a much smaller and much better-defined job.

---

## 2. The gaps, each with the evidence that it matters

| # | gap | why it matters here | effort | risk |
|---|---|---|---|---|
| G1 | **Exception *entry* semantics for a taken interrupt during a delay slot** — `Cause.BD` and `EPC = branch address` | the idle spin `0x80000518`/`0x8000051c` is a branch + delay slot, so **the very first interrupt in this system lands in the delay-slot case**. My `take_exception(pc)` sets `EPC = pc` unconditionally | small | **high** — this is the most likely single cause of the M78 unwind |
| G2 | **`sd`/`ld` are 32-bit approximations.** The handler saves with `sd` (64-bit) and restores with `ld` | every register the handler preserves goes through 64-bit store/load. If high halves are wrong, `ra` may restore wrong | medium | high |
| G3 | **`Count`/`Compare` don't advance meaningfully** — `Count` increments per instruction, `Compare` never fires in practice | the handler reads `mfc0 $9` at `0x80000730` and the profiling path compares against `0x80012140` | small | medium |
| G4 | **Interrupt taken while a host hook is executing** | `pi_dma`/`inflate` are host functions; if the tick lands "inside" one, the guest never called it and the resume point is meaningless | small | medium |
| G5 | **Multiple simultaneous pending sources** — `Cause.IP` must show all of them, not just the last | the game registers AI, SP, PI and RDB and may have several pending at once | small | low |
| G6 | **`mtc0 $12` masking in the handler expects `EXL`/`IE` semantics to be honoured** | the handler clears bits 0–1 itself and relies on the hardware not re-taking the interrupt | small | low |
| G7 | **FPU context not saved/restored** if the handler saves `fcr31`/FPRs | only matters if a thread is interrupted mid-FP work | medium | low (defer) |

Already correct and **not** in scope: `EPC`/`EXL`/`ERL` acceptance rule, `eret`, `mtc0 $14`, MI
pending-until-guest-writes-`MI_INTR`, per-thread `MI_INTR_MASK` restore, `TLBR/TLBWI/TLBWR/TLBP` as no-ops.

---

## 3. Ordered plan, with an acceptance test each

**S1 — delay-slot-correct exception entry (G1).** Track whether the instruction about to retire is a delay
slot; on take, set `EPC` to the branch address and `Cause.BD = 1`. *Acceptance:* inject PI during the idle spin
and the handler returns to `0x80000518`, not `0x0`. **Do this first — it is both the smallest and the most
likely fix.**

**S2 — real 64-bit register file (G2).** Represent GPRs as 64-bit ints; `sd`/`ld` move the full value; 32-bit
ops sign-extend per MIPS III. *Acceptance:* `sd`/`ld` round-trip of `0xDEADBEEFCAFEBABE` is exact, and the
M78 unwind no longer loses `ra`.

**S3 — Count/Compare (G3).** Tick `Count` from a cycle proxy, fire `Compare` as a timer interrupt. *Acceptance:*
`mfc0 $9` inside the handler returns a value that advances between two interrupts.

**S4 — atomic host hooks (G4).** Defer the interrupt check until after a hook returns; never take an interrupt
"inside" one. *Acceptance:* injecting during a burst of `pi_dma`/`inflate` leaves `EPC` pointing at guest code.

**S5 — multi-source `Cause.IP` (G5).** *Acceptance:* assert PI and SP together; the handler sees both bits and
clears them independently.

**Deferred:** FPU context (G7) unless the interrupt test fails with FP state.

---

## 4. Non-goals

- No host-side context switching, thread table or register file. The guest owns all of it.
- No VI model: **VI is not a registered event** in this game (only AI/SP/PI/RDB on `0x80139f10`), so a VI
  interrupt dispatches to a null handler *even on hardware*.
- No RSP/RDP/AI emulation. Injecting a *completion* for a task the game never started will not be faithful; the
  honest event source here is **PI** (a DMA the guest itself programmed) — which the harness does model.

---

## 5. Acceptance criterion for the whole piece

> Inject one PI completion at the idle spin, and the guest's own handler runs, the event table is consulted, a
> message is delivered to its registered queue, a waiting thread wakes, and execution continues **without** the
> boot chain unwinding to `0x0`.

That is testable in one run, it is falsifiable, and it is the same sequence the console performs.

---

## 6. What this is worth, honestly

If S1 alone fixes it, the payoff is large: the harness could then progress past boot on its own, and the page
diff against ares becomes meaningful for later states. If it takes S1–S5, the work is bounded (all five are
local to `mips_harness.py` plus MI) but it is **emulator work**, not RE2 work — and the oracle already answers
RE2 questions more cheaply. Worth doing if the goal is a runnable reconstruction; not worth doing if the goal is
understanding the game.


---

## 7. S1 implemented — the crash is fixed

`Cpu.interrupt_entry()` now checks whether the next instruction is a delay slot, clears the pending branch, and
lets `take_exception(..., bd=in_delay)` set `EPC = pc-4` with `Cause.BD = 1`. Wired at every call site
(`Cpu.run`, `Sched.run`, and the harness runs).

**Measured, one PI injection at the idle spin:**

```
exc at instruction 400,000: EPC=0x80000518  BD=True  -> vector 0x80000180
no fault; 2,000,000 instructions completed
last 16 PCs: 0x8000051c 0x80000518 0x8000051c 0x80000518 …   (back in the idle spin)
```

`EPC` is the **branch** (`0x80000518`), not the delay slot (`0x8000051c`), `BD` is set, and — the point — **the
boot chain no longer unwinds to `0x0`.** One gap, one fix, and the M78 crash is gone.

**The handler really runs**, too (26 handler PCs, 1 000 000-instruction run):

- visited `0x800006d0` → `0x800006f4` (the save sequence) and **reached `0x80000730+`**, the event-send area;
- save area `0x80015000` holds `sr = 0xff03` — a real saved `Status`.

**But `validCount` on `0x80139f10` is still 0**, so the handler runs and returns *without* delivering an event
message. That is the next question, and it is now a clean one: the dispatch reaches the send area but nothing is
enqueued — either the event-table entry the handler consults is empty for this source, or the send is gated on
something (a registered-queue check) that this harness does not satisfy. It is no longer blocked by any crash.


---

## 8. The handler makes no calls at all — and that changes the delivery question

Tracing `0x80000720`–`0x800007b0` during a PI interrupt showed the region is **not** the event dispatch (my M79
label was wrong). It is the **context copy into the current thread**:

```
0x80000768  lw  k0, 0x2950(k0)      k0 = __osCurrentThread
0x8000076c  ld  t1, 0x20(k0)   / 0x80000770 sd t1, 0x20(k0)
0x80000774  ld  t1, 0x118(k0)  / 0x80000778 sd t1, 0x118(k0)
0x8000077c  ld  t1, 0x58(k0)   / 0x80000780 sd t1, 0x58(k0)      … +0x60, +0x68, +0x28, +0x30 …
```

A static scan settles the bigger question: **the whole handler `0x800006d0`–`0x800009bc` contains no `jal` at
all**, and it leaves through an **indirect `jr r10` at `0x800009bc`**.

So the event dispatch is not a call — the handler ends by jumping through a register. That means:

1. **No `osSendMesg` call exists inside the handler**, so the M24 census of `osSetEventMesg` registrations does
   not imply the handler posts them directly; it posts through the pointer it leaves by.
2. For the harness, the delivery question becomes: **what does `r10` hold at `0x800009bc`, and does that target
   exist and work in this emulation?** That is one register at one instruction — a bounded check, not another
   gap in the emulator.
3. The event queue writes observed so far come from `0x80000688` zeroing `0x80139f10`–`0x80139f2c` (init), and
   `0x80139f10` ends with `mtqueue = 0x80012940` (empty sentinel), `msg = 0x80139ff0` — a correctly initialised,
   empty queue.

**Next probe (one run, one register):** log `r10` at `0x800009bc` on the PI interrupt, and the first few PCs
after that jump.


---

## 9. `r10` = 0x80000c68 — the handler exits into the *dispatcher*, not an event notifier

Logged on a PI interrupt:

```
at 0x800009bc:  r10 = 0x80000c68   (valid RAM)     a0=0x1b928
jump lands at   0x80000c68 (via delay slot 0x800009c0)
0x80000c68  lw   t1, 0x4(k0)
0x80000c6c  lui  t2, 0x8001
0x80000c70  lw   t2, 0x2948(t2)      t2 = __OSRunQueue
0x80000c74  lw   t3, 0x4(t2)         t3 = node->priority
0x80000c78  slt  , t1, t3            compare priorities
0x80000c7c  beq  , zero, +0x7
0x80000c9c  lui  t1, 0x8001
0x80000ca0  addiu t1, t1, 0x2948     &__osRunQueue again
```

**The exception handler's exit is the thread dispatcher**, reached through `r10` — it reads `__osRunQueue`, compares
priorities and selects. It is **not** the event notifier the N64 manual describes, and there is no `osSendMesg` on
this path (consistent with the handler containing no calls at all).

**So the expectation carried since M24 was wrong for this build.** Interrupts here do not post messages to
`0x80139f10`; they **switch threads**, and whatever posting happens is done by the threads that get scheduled.
That reframes the whole queue investigation: the "event dispatcher" arrow in the M24 diagram does not exist in
RE2's handler, and the two application queues are fed by ordinary thread code, not by interrupt delivery.

Nothing in the harness is at fault here — `r10` is correct, the jump target exists, and the dispatcher reads the
run queue properly.

---

## 10. The dispatcher runs, but no thread ever posts

3 000 000 instructions from `main`, PI asserted every 300 000:

```
interrupts injected:      1  (of 10 intended)
queue validCount events:  0  on all three queues (0x80139f10, 0x8012bd30, 0x8012bcf8)
current thread:           0x8010b700 (thread 7)   run queue: empty
```

Two separate answers came out of it.

**1. Only the first injection landed, and the reason is the per-thread mask.** The guest restores `MI_INTR_MASK`
from the thread context on every dispatch (M47), so a host `|= 0x10` survives exactly until the next context
restore. Pending stays set, mask loses the bit, no further interrupt. A faithful event source therefore has to
re-assert the *pending* line and let the guest's mask decide — never write the mask.

**2. No thread posts, because no thread but the idler ever runs.** Thread 7 sits in the `b .` spin with an empty
run queue; threads 1 and 9 remain WAITING. So there is no candidate poster: the only runnable thread is the one
that spins, and the threads that would post are parked on the very queues being watched.

That is consistent with the oracle: `validCount = 0` on both application queues at the ares title screen *and*
after NEW GAME. Harness and machine agree on the observable state, and neither shows a post in the window that
can be compared. The remaining difference is that ares keeps running and eventually schedules work, while this
harness has nothing to schedule.

---

## 11. Can the probe reach the title screen? No — and not for lack of running time

Measured with `tools/probe.py` (which never writes the mask, so the guest's own per-thread mask decides):

| source | mask enables it? | interrupts | threads they landed in |
|---|---|---|---|
| PI `0x10` | **no** (mask `0x669`) | 1 | thread 7 |
| SP `0x01` | yes | 3 | threads 7, 1 |
| VI `0x08` | yes | 5 | threads 7, 9, `0x80017868`, 1 |
| DP `0x20` | yes | 5 | same five |

So the earlier failure was a **mask-selection error on my side**, not the harness: PI and AI are disabled in this
game's masks and asserting them was silently ignored.

**Progress is real but bounded.** With an enabled source the dispatcher genuinely switches threads — five
interrupts land in five different thread structures. But after ~174 000 instructions the system **settles back to
thread 7 idling**: run queue empty, all three `validCount`s 0, current thread `0x8010b700`. Running 6 000 000
instead of 4 000 000 changes nothing after that point, and speed is not the limit (465 000 instr/s).

**Two limits, and the second is fundamental.**

1. `MI pending` stays `0x08` — the guest handler never clears it, because VI is not a registered event here. So
   the line stays asserted while `Status`/mask stop accepting, and interrupts stop.
2. Injecting an interrupt line does not supply the **device state behind it**. The handler dispatches, finds an
   empty run queue, and returns. The game is waiting on *completions of work it started* — PI DMA, SP tasks, AI
   buffers, VI retraces tied to real video timing — and a bare interrupt cannot stand in for those.

**Conclusion: the probe covers the boot-to-idle window (≈175 000 instructions) and cannot carry the game further.
Past that point a driver model is required — which is a different project, and one that already exists in ares.**

---

## 12. PI completion + timer added: the drivers work, the *enables* are the blocker

Minimal driver model added to `tools/probe.py` (`--driver pi,timer`, now the default):

- **PI completion**: the `0x8000c870` DMA hook now sets `MI pending 0x10` after the copy, i.e. the guest can see
  the transfer finished. Measured: **2 completions per boot**, `MI pending` ends at **`0x18`** = VI `0x08` +
  PI `0x10` — both sources asserted simultaneously and independently, which is the S5 behaviour for free.
- **Count/Compare timer**: `Count` advances per instruction and sets the timer pending bit when it reaches
  `Compare`.

**Result: nothing wakes.**

```
interrupts taken: 5   (all between instructions 169,885 and 173,753; five distinct threads)
queue validCounts: 0 / 0 / 0        current thread 0x8010b700   run queue empty
MI pending 0x18     mask 0x0669
```

**Two enable-side blockers, both guest state we must not forge:**

1. **The mask does not enable PI.** `0x669` has bits `0x01`(SP), `0x08`(VI), `0x20`(DP) set and **`0x10`(PI)
   clear**. So the completion bit is *pollable* — a handler that reads `MI_INTR` will see it — but it can never
   raise a CPU interrupt. The driver supplies the fact; the guest decides whether to be interrupted by it.
2. **Interrupts stop after ~174 000 instructions.** The restored `Status` loses `IE`, so even sources the mask
   *does* enable stop being accepted. That is a property of the game's thread states at that point, not of the
   driver.

**So the bounded spike has an answer, and it is the negative one:** a PI completion and a timer did not wake
threads 1 or 9. They did everything a driver can do — set the device-visible completion flag, tick the counter —
and the system still settles to the idler with an empty run queue. The blocker is not missing device facts; it is
that the game's own thread states disable the interrupt sources the harness can supply, and forging those states
would be exactly the kind of approximation this project kept having to retract.

**Recommendation, unchanged and now evidence-backed: stop here.** Past the boot-to-idle window the harness needs
the game's *own* thread states to enable its own sources, which happens only when real work completes — RSP tasks
producing output, VI retraces tied to real video. That is an emulator, and ares is one.

---

## 13. Latched PI completion: real interrupts from a real device, still no post

`--driver pi` now latches completions and re-asserts the pending line while one is outstanding; the guest
acknowledges by writing `MI_INTR`. Run with **`--irq-source none`**, i.e. *no injected interrupt line at all* —
every interrupt below comes from the driver:

```
instr         EPC        BD    thread        mask    pending
170,807  0x8000730c   False  0x8010b700   0x0999    0x0010
173,767  0x8000730c   False  0x800164b0   0x0999    0x0010
174,288  0x8000730c   False  0x80112a40   0x0999    0x0010
queue validCounts: 0 / 0 / 0      run queue empty      current thread 0x8010b700
driver: 2 completions latched, 2 still outstanding
```

**Three interrupts, all from the device model, each with the mask (`0x0999`, PI `0x10` set) and the pending bit
(`0x0010`) recorded at the moment of dispatch**, landing in three distinct threads. The completion → interrupt →
dispatch chain works end to end without any injected line.

**And still nothing posts.** The threads that would post are never scheduled with work: the run queue stays empty,
the idler wins, and both application queues keep `mtqueue` pointing at their waiting thread with `validCount = 0`.

So the smallest real work item did exactly what it said on the tin — and it answers the question honestly: **the
missing piece was never the device signal.** A PI completion now raises a genuine interrupt, at a moment when the
guest's own mask enables it, and the handler runs. What is still absent is *work* — an RSP task producing output,
a DMA whose payload a thread then processes — and no amount of device signalling manufactures that.

**That is the boundary of this reconstruction, established rather than assumed.**
