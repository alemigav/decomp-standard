# M3 — libultra naming, and what other N64 decomps do differently

2026-10-30. The naming task produced a result that refutes the task's premise, and the
research produced a compute plan. Both are recorded here.

## 1. Naming the "three functions the entry calls"

Ghidra's `callees` list from M2 gave three addresses. Decompiling and disassembling each
one showed that **two of the three are not routines at all**:

| Address | Instructions observed | Verdict | Name assigned | Confidence |
|---|---|---|---|---|
| `0x80000CE4` | `nop` · `eret` (8 bytes) | an **exception return tail**, not a callable function | `exception_return_eret` | medium |
| `0x80000F08` | `lw s5,0x14(sp)` … `lw s0,0(sp)` · `jr ra` · `addiu sp,sp,0x20` | a **register-restore epilogue**: pops six saved registers and returns | `func_80000F08_epilogue` | medium |
| `0x80000F60` | scans table `@0x800138B0` (count `@0x80013EB4`), compares `(n+7)&~7`, sets a used flag, returns a pointer | a real function, allocator-shaped (find-block-that-fits) | `func_80000F60_alloc_scan` | low-medium |

`eret` is MIPS "exception return" — the instruction that leaves exception mode. A routine
cannot usefully be *called* into `eret` and return, so Ghidra's "callee" was an artefact of
analysing a flat blob: the exception handler branches into these tails.

### But the re-split contradicted my own verdict

After naming, splat's output shows the code **`jal exception_return_eret`** from at least
four sites (`0x800009E8`, `0x80000A48`, `0x80000AA4`, `0x80000ABC`). Code does call that
address. Two readings, both defensible:

- libultra's exception path is entered by *jumping* to a shared epilogue; the `jal`s are
  how handler paths hand off to it, and `eret` is the intended terminal instruction.
- or `0x80000CE4` is genuinely mid-routine and the "function start" is earlier.

**What is established:** the bytes are `nop; eret`, and ≥4 sites reference that address.
**What is not:** which side of the boundary the true function starts on. Recorded as
unresolved; a hand trace of the exception vector is required to settle it.

## 2. Did naming extend coverage? No.

| Metric | before names | after names |
|---|---|---|
| entry size (splat) | `0x68` | `0x68` |
| functions | 243 | 243 |
| sized code | 69,176 B | 69,176 B |
| code span | 0x80000480–0x800115B0 | same |

**Symbol names label code; they do not discover it.** The binding constraint is that
splat's generated config put everything after ROM `0x12140` into a single `bin` segment, so
67 MB was never examined. Naming was cheap and correct to do, but it cannot move the
0.11 % → 100 % needle. That needs structure, not labels.

## 3. What other N64 decomps do (borrowed conventions)

Surveyed `pmret/papermario` (a 40 MB ROM decomp — the closest precedent to RE2's 64 MB),
plus the standard toolchain.

Adoptable as-is:

- **`asm/nonmatchings/` + `src/` layout.** Unmatched functions stay as asm; matched ones
  move to C. Paper Mario's `decomp.yaml` encodes exactly this:
  `ver/us/{baserom.z64, asm, asm/nonmatchings, build/{elf,map,z64}}`.
- **Per-version directories from day one** (`ver/<region>/...`) even though we only have
  US Rev 1 — it costs nothing now and avoids a painful migration later.
- **`splat split --use-cache`** — re-splits only *changed* segments. This is the single
  biggest compute saving: an iterative workflow re-splits dozens of times per session.
- **`--modes`** to regenerate only selected segments when touching one bank.
- **Symbol files as the interface**, not code edits: `symbol_addrs.txt` drives naming
  everywhere (splat, asm-differ, the linker).

## 4. What is different about RE2 — where the compute must go

| Property | RE2 | Consequence |
|---|---|---|
| Compiler | **KMC** (auto-detected) | The ecosystem's matching tooling (`asm-differ`, `decomp-permuter`, IDO 7.1 hacks) is tuned for **IDO/GCC**. Nearly all transferable lore assumes IDO. Expect matching to be harder or to require a KMC toolchain hunt before M5 is even meaningful. |
| Size | **512 Mbit / 64 MB** | 1.6× Paper Mario, 8× OOT. Never run a whole-ROM pass: scope every run. |
| Code fraction | unknown, but the first 74 KB holds 243 functions and the rest is data | the ROM is dominated by FMV/assets. **Compute should find code, not disassemble data.** |
| Entry | `0x80000480`, non-standard | splat itself warns its analysis may be wrong; boundaries near the vector need hand checks. |
| Streaming | rooms loaded on demand (unverified) | if true, a single flat VRAM map is **wrong** beyond the boot bank, and the bank table is the unlock. |

### Compute plan that follows

1. **Never analyse 64 MB at once.** Work in declared windows; `--use-cache` between runs.
2. **Find the load/bank table first.** It converts "67 MB unknown" into N segments with
   known VRAM bases — that is what turns flat-blob guessing into real boundaries. Everything
   else is downstream of this.
3. **Cheap discovery before expensive analysis:** scan the ROM for `jr ra`-dense regions and
   for pointer tables (32-bit words in `0x8000_0000–0x8040_0000`) to locate code banks
   without disassembling.
4. **Reserve Ghidra for chosen functions**, not for sweeps: each import costs ~6 s plus
   decompile time, and its output is already verbose.
