# M2 (partial) — real ROM code reaches the decompiler

Observed 2026-10-30. The boot region was wrapped as ELF and analyzed by REA→Ghidra 12.2.

## Method

```sh
# VA 0x80000480 -> ROM offset 0x1480 (mapping confirmed in M1)
./tools/wrap_mips_elf.py --input "rom/Resident Evil 2 (USA) (Rev 1).z64" \
    --output /tmp/re2_boot.elf --base 0x80000480 --offset 0x1480 --length 0x20000
# then: rea open_binary {path, provider_id:"ghidra"} ; rea analyze_function {procedure:"0x80000480"}
```

Accepted as `format: elf, architecture: mips`, pinned `MIPS:BE:32:default`.

## What the decompiler produced

Assembly at the entry (verbatim):

```
0x80000480 lui t0,0x400        <- cold/warm boot test
0x80000484 and t0,t0,t1
0x80000488 beq t0,zero,0x800004d0
0x800004d0 mfc0 t0,Cause       <- exception path
0x800004d4 sw t0,0x120(k0)
0x800004e0 andi t1,t0,0x7c     <- dispatch on Cause code
0x800004e8 beq t1,0x24,0x800007d0
0x800004f4 beq t1,0x2c,0x80000920
0x80000524 lui at,0x8001 ... lbu/lw ... jr t2    <- jump table at 0x80011950/0x80011970
```

That is recognisably libultra exception-vector code: it reads `Cause`, stores it into
k0-relative state, and dispatches through an indirect jump table. Callees were
identified automatically: `FUN_80000ce4`, `FUN_80000f08`, `FUN_80000f60`.

## Honest limits of this result

- Ghidra emitted three warnings: *"Control flow encountered bad instruction data"*,
  *"Switch with 1 destination removed at 0x8000053c"*, *"Exceeded maximum restarts with
  more pending"*. Expected: this is a **flat blob with no code/data separation**, so
  the jump-table targets are unresolved and some bytes are data. `splat` exists to fix
  exactly this.
- The function body came back **non-contiguous** (4 ranges), which is normal for
  vector/dispatch code but means boundaries are guesses, not facts.
- **32-bit is the correct language choice**, not a limitation: N64 games run the
  R4300i in 32-bit mode with the o32 ABI even though the ISA is MIPS III. The `sd`
  instructions seen in the entry are 64-bit data moves that decode fine under the
  32-bit language; using `MIPS:BE:64:*` would model an ABI the game does not use.
- Nothing here is a decompilation yet. It is proof that the pipeline carries real ROM
  bytes into a working decompiler.

## Next

Install `splat`, write the config from `M1-rom-identification.md`, and get code/data
boundaries before analysing further — otherwise every conclusion about boundaries is a
guess.
