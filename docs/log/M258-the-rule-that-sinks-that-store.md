# M258 — the rule that sinks that store is not in mips.c, and it is a dependence gcc drops

M257 left p7's case 0 at 0 of 14 words with the diagnosis "my store sinks below a load the image keeps in order".
The instruction was to start at `mips.c` and find the rule. **The rule is not in `mips.c`** — and finding where it
actually lives turns case 0 **byte-exact** and takes p7 from 60 to 74 of 84 words.

## 1. mips.c has no scheduler hook at all

A grep of `config/mips/mips.c` (gcc 2.8.1) for `adjust_cost`, `issue_rate`, `reorder` and `SCHED` returns
**nothing about scheduling**: every hit is `.set noreorder` emission. The port contributes no cost adjustment, no
issue rate and no DFA. Its entire scheduling contribution is one table in `config/mips/mips.md`:

```
147: (define_function_unit "memory" 1 0             ; load, "worst case" processors
       (and (eq_attr "type" "load")
            (eq_attr "cpu" "!r3000,r3900,r4600,r4650,r4100,r4300,r5000")) 3 0)
152: (define_function_unit "memory" 1 0             ; load, on R4300 and friends
       (and (eq_attr "type" "load")
            (eq_attr "cpu" "r3000,r3900,r4600,r4650,r4100,r4300,r5000"))  2 0)
157: (define_function_unit "memory"   1 0 (eq_attr "type" "store") 1 0)    ; store: READY-DELAY 1
```

So a **store's latency is 1 and a load's is 2** on this cpu. That number is the whole input the generic scheduler
gets from the MIPS backend.

## 2. The scheduler's rule, quoted

`sched.c`'s `priority()` (line 1453) is what turns that number into an order:

```c
	  prev_priority = priority (x) + insn_cost (x, prev, insn) - 1;
```

and the comment above it states the design intent exactly:

> When all instructions have a latency of 1, there is no need to move any instructions. Subtracting one here
> ensures that in such cases all instructions will end up with a priority of one, and hence no scheduling will be
> done.

**So a store cannot be given a priority of its own by the scheduler** — its `READY-DELAY` is 1, which the `- 1`
cancels out. Anything with a latency above 1 (a load, a `mult`, a `div`) raises the priority of *everything that
depends on it*, and the list scheduler then issues those first. In case 0 the `lw` of the device register starts
the RMW chain that feeds the closing `sw`, so it carries a priority of 2 while the `sw` has none.

That explains the *tendency*. It does not explain why the reordering is **legal** — a load may not cross a store
that might alias it. That decision is three functions in the same file (`sched.c:830`, `:862`, `:890`) which are
all the same shape:

```c
  return ((MEM_VOLATILE_P (x) && MEM_VOLATILE_P (mem))
	  || (memrefs_conflict_p (SIZE_FOR_MODE (mem), XEXP (mem, 0),
				  SIZE_FOR_MODE (x), XEXP (x, 0), 0)
	      && ! (MEM_IN_STRUCT_P (mem) && rtx_addr_varies_p (mem)
		    && GET_MODE (mem) != QImode && GET_CODE (XEXP (mem, 0)) != AND
		    && ! MEM_IN_STRUCT_P (x) && ! rtx_addr_varies_p (x))
	      && ! (MEM_IN_STRUCT_P (x) && rtx_addr_varies_p (x)
		    && GET_MODE (x) != QImode && GET_CODE (XEXP (x, 0)) != AND
		    && ! MEM_IN_STRUCT_P (mem) && ! rtx_addr_varies_p (mem))));
```

Read the two exemptions: **a conflict is suppressed when one side is a struct-member access whose address varies
and the other side is *not* a struct access**. That is a pre-`-fstrict-aliasing` type-based guess (2.8.1 has no
`-fstrict-aliasing`: M255 found the flag is not even accepted), and it is symmetric in the wrong way — it fires on
*mixed* pairs only.

## 3. Tested three ways, and the image agrees

| variant | memory pair | order |
|---|---|---|
| `s->f1e8 = …` (struct) × `*(u32*)(dev+0x19a5c)` (not) | **mixed** | `lw` **hoisted** above both `sw` — the dependence is dropped |
| `((struct Dev*)(dev+0x18000))->reg \|= 0xc0` (struct) | struct × struct | `sw … sw … lw` — dependence kept |
| both sides plain pointer stores (`*(u32*)((u8*)s+0x1e8)`) | plain × plain | `sw … sw … lw` — dependence kept |

Only the mixed pair loses its dependence, which is exactly what the two exemptions say. And the struct form
reproduces the image's arm **instruction for instruction**, all fourteen words:

```
             mine (v1)                    image (0x80057e54)
  lui v0,0x600 / ori v0,v0,0x700     lui v0,0x600 / ori v0,v0,0x700
  lui a1,0x1 / ori a1,a1,0x8000      lui a0,0x1 / ori a0,a0,0x8000
  sw v0,488(a0)                      sw v0,488(s0)
  li v0,1                            li v0,1
  lui v1,%hi / addiu / addu          lui v1,%hi / addiu / addu
  sb v0,6(a0)                        sb v0,6(s0)
  sw zero,480(a0)                    sw zero,480(s0)
  lw v0,6748(v1)                     lw v0,6748(v1)
  ori v0,v0,0xc0                     ori v0,v0,0xc0
  jr ra / sw v0,6748(v1)             sw v0,6748(v1)
```

Only the register names differ (`a0`/`a1` against the image's `s0`/`a0`) — because the image's function keeps its
first argument in a callee-saved register, which follows from the rest of the function being right.

## 4. The rule, stated once

**gcc 2.8.1 drops a memory dependence between a struct-member access and a non-struct access, and its pre-reload
scheduler (`sched.c`, `-fschedule-insns`, part of `-O2`) exploits that by hoisting the load — because a load's
`READY-DELAY` is 2 on R4300 and a store's is 1, so the store has no priority and drifts wherever the ready list
puts it.** In the original source the device window was therefore **the same kind of access as the struct**: a
struct member. Declaring `struct Dev { u8 pad[0x1a5c]; u32 reg; u32 reg2; };` and reaching it as
`((struct Dev *)(dev + 0x18000))->reg` restores the dependence and the order.

Two corollaries worth keeping:

- **`-mcpu` does not matter here.** `-mcpu=r4300` and `-mcpu=r4600` produce the identical schedule; the default
  is already in the 3-cycle load group and the direction of the effect does not change.
- **`-fno-schedule-insns2` changes nothing** (byte-identical output), so sched2 is not the pass. **`-fno-schedule-insns`
  does** change the order — but it is not the answer either: applied to both whole functions it is a wash
  (p7 60→59, p6 82→still 82 by content), so the image *was* scheduled, and the difference was never a flag.

## 5. While those compiles were set up, the `-O`/`-O2` ambiguity closed

The four generic probes could not separate `-O` from `-O2` (M250: both 4/4). The two recovered whole functions
can, and the answer is unambiguous:

| | `-O` | `-O2` |
|---|---|---|
| p6 (98 words) | 72 content | **82 content** |
| p7 (84 words) | 61 content, 10 hunks | **64 content, 6 hunks** |

**`-O2` wins on both.** The profile in the tool was already `-O2`, so this is a confirmation rather than a change,
and it closes the roadmap's open "`-O` vs `-O2` sweep" item — the probe it needed now exists.

## 6. State

- **p7: 74 of 84 words by offset, 75 of 84 by content, 2 hunks**, case 0 **14/14 byte-exact**, table **8/8**.
  The remaining residue is case 2 only (`lw 6752` hoisted above `sw 6748`), which is the *same* question one
  access pair further on.
- The corpus is **18 cases, all passing**; pin moved to 18.
- The lesson worth promoting: when a store and a load trade places, do not look at the scheduler's intent first —
  look at **whether gcc believes they can alias**, which is a source-shape fact about how each access is *typed*.
