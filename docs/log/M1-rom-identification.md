# M1 — ROM identification

Observed 2026-10-30 with `tools/n64info.py`. Read-only; nothing modified.

| Field | Value |
|---|---|
| File | `rom/Resident Evil 2 (USA) (Rev 1).z64` |
| Size | 67,108,864 bytes = **512 Mbit** (the largest N64 cartridge size) |
| Byte order | **z64 / big-endian native** — no byte swap needed |
| Header name | `Resident Evil II` |
| Cart ID / country / rev | `NREE`, USA (`0x45`), revision 1 |
| Clock rate field | 15 |
| libultra field | `0x00001444` |
| CRC1 / CRC2 | `0xaa18b1a5` / `0x07db6aeb` |
| **Entry point** | **`0x80000480`** |
| Bootcode region SHA-1 head | `1b9cf71e1f30fdc2045b426ff6b14d1127555a7f` |

## What is established

1. **Byte order is native z64.** All three magic patterns were considered
   (`80 37 12 40` z64 / `37 80 40 12` v64 / `40 12 37 80` n64); this dump is the
   first. No normalisation step is required.
2. **VIRTUAL→FILE mapping confirmed empirically.** The conventional N64 mapping is
   `file_offset = 0x1000 + (vaddr - 0x80000000)`. For the declared entry
   `0x80000480` that gives **file offset `0x1480`**, where the first words are:

   ```
   3c080400  lui t0, 0x0400
   01094024  and t0, t0, t1
   11000011  beq t0, zero, +0x44
   00000000  nop
   f74101b0  sd  ...        <- opcode 0x3D = MIPS III 64-bit store
   ```

   `sd` confirms MIPS III (R4300i) instruction encoding, i.e. the bytes at that
   offset are code, not data. The mapping holds.

3. **The entry point is not the libultra default.** `0x80000480` is `0x80` past the
   usual `0x80000400`. Consistent with a custom boot flow; the two-word entry test
   (`lui t0,0x0400 / and / beq`) is the standard cold-vs-warm boot check, so the
   vector is real. It does mean **splat's default entry of `0x80000400` is wrong for
   this ROM** — the config must use `0x80000480`.

## What is NOT established

- **CRC is not verified.** `n64crc`'s 256-entry table is not reimplemented here, and
  the header CRC values are only meaningful compared with a computed pair. Until that
  runs, the dump is *structurally* valid, not *integrity* validated.
- **The CIC is not named.** The bootcode SHA-1 is recorded so it can be matched
  against n64crc's fingerprint table later. CIC choice affects the CRC seed and, if we
  ever emulate or reflash, the boot hardware model.
- Nothing here proves the dump is complete on-cartridge (i.e. the tail isn't padding
  or a bad read). A second independent dump compared by hash would settle it.

## Consequence for M2

`splat` config must set:

```yaml
options:
  basename: re2
  base_path: .
  target_path: rom/Resident Evil 2 (USA) (Rev 1).z64
  asm_path: asm
  src_path: src
  build_path: build
  ld_script_path: linker.ld
  find_file_boundaries: True
  header_symbols: True
  symbol_addrs_path: symbol_addrs.txt
  undefined_funcs_auto_path: undefined_funcs_auto.txt
  undefined_syms_auto_path: undefined_syms_auto.txt
segments:
  - name: ipl3
    type: code
    start: 0x80000400
    vram: 0x80000400
    subsegments:
      - [0x1000, bin]                 # 4 KiB ROM header, not loaded as code
  - name: boot
    type: code
    start: 0x1480
    vram: 0x80000480
    subsegments:
      - [0x1480, asm]
```

`start` is a ROM offset; `vram` is the address it is linked at. The header occupies
`0x0–0xFFF` and is not part of the loaded image.
