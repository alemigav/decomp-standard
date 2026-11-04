# M2 — real code/data boundaries (splat)

Observed 2026-10-30. Tool: **splat 0.50.1** + **spimdisasm 1.42.4**, run inside the
Linux nanocore (no MIPS toolchain exists on the Mac: Apple's clang has the MIPS target
stripped, and no `mips-linux-gnu-*` binaries ship with macOS).

## How the toolchain was stood up

```sh
# in the nanocore (Debian 13 arm64)
sudo apt-get install binutils-mips-linux-gnu          # 2.44 — as/objdump/ld for MIPS
pipx install splat64                                  # 0.50.1
# splat64's PyPI metadata omits hard dependencies; these were injected one by one:
pipx inject splat64 spimdisasm n64img mapfile_parser intervaltree tqdm pyyaml watchdog pypng
# two of them are Rust extensions with no aarch64 wheels, so a Rust toolchain was needed:
curl -sSf https://sh.rustup.rs | sh -s -- -y --profile minimal
sudo apt-get install build-essential                  # rust needs a C linker
~/.local/share/pipx/venvs/splat64/bin/python -m pip install pygfxd crunch64
```

`crunch` (a different package) fails to build and is **not** the same as `crunch64`;
only the latter is needed. Installing them as one `pipx inject` batch fails entirely if
any single package fails — inject them individually.

## What splat derived from the ROM

`splat create_config` produced `config/residentevilii.yaml` with these segments:

| Segment | ROM range | VRAM | Type |
|---|---|---|---|
| `header` | 0x0 | — | header |
| `ipl3` | 0x40 | — | bin (CIC bootcode) |
| `entry` | 0x1000 | **0x80000480** | code |
| `main` | 0x1068 | 0x800004E8 | code |
| *(data)* | 0x12140 → 0x4000000 | — | bin |

So **code ends at ROM 0x12140**; everything after is unclassified data. That is the
first real code/data boundary this project has, and it was derived, not guessed.

Other fields splat read from the header itself:

- `compiler: KMC` — **the compiler is detected as KMC, not IDO or GCC.** This is the
  single most important fact for M5 (a matching build needs the right compiler).
- `mips_abi_float_regs: o32` — consistent with the 32-bit ABI conclusion from M0.
- `sha1: 62ec19bead748c12d38f6c5a7ab0831edbd3d44b` — whole-ROM identity (distinct from
  the bootcode-only SHA-1 in M1).
- Its own warning, unprompted: *"This game uses a non-traditional entrypoint, meaning
  splat's analysis may be wrong"*.

## Result

`config/functions.csv` — **243 functions**, all with explicit sizes, spanning
**0x80000480 … 0x800115B0**, 69,176 bytes (67.6 KB) of sized code.

Largest: `func_80001698` (3,108 B), `func_80005438` (2,636 B), `func_800023D8` (1,972 B).

## Cross-validation against Ghidra (independent tool, independent method)

M2-partial had Ghidra analyse the same bytes from a flat ELF wrap. Splat, working from
symbol/reloc analysis rather than recursive descent, produced the *same* three callees:

| Function | Ghidra | splat |
|---|---|---|
| `0x80000CE4` | `FUN_80000ce4` | `func_80000CE4` ✅ |
| `0x80000F08` | `FUN_80000f08` | `func_80000F08` ✅ |
| `0x80000F60` | `FUN_80000f60` | `func_80000F60` ✅ |

Two tools agreeing on a boundary is meaningful; one tool asserting it is not.

## Where the two tools disagree — and why it matters

The entry function:

- **splat**: `nonmatching entrypoint, 0x68` → 104 bytes, ending at the next function.
- **Ghidra**: body reported as **4 non-contiguous ranges**, 332 bytes total, spanning
  0x80000480–0x80000953.

Neither is "wrong". Splat's linear pass stops at the next detected function; Ghidra
followed the exception handler's branches into code that splat assigned to `main`.
Since the entry is an exception vector with a jump table at `0x80011950`, the honest
statement is: **the entry's true extent is unknown**, and it should be treated as a
range to be resolved by hand, not a fact.

## Limits of this milestone

- **99.89 % of the ROM is still `bin`** — 67 MB unclassified. Only the first 74 KB has
  boundaries. Extending it is iterative: add segments, name symbols, re-split.
- Function sizes are spimdisasm's inference from code flow, not verified extents.
- No matching build exists; nothing proves these bytes came from a specific compiler
  version yet.
