# M5 — the PI DMA loader routines

2026-10-30. Goal: find the routine that programs cartridge DMA (`osPiStartDma`
lineage). Found, with two methodological corrections along the way.

## Method, and two errors worth remembering

1. **Register-name matching is not value tracking.** A first pass counted 105 "PI
   register stores" by matching `sw ...,4(v1)`-style patterns. That is wrong: the base
   register must *hold* `0xA460`, and `v1` frequently holds a RAM pointer. The sample I
   inspected turned out to be a 16-byte-record queue walk using `k0`/`k1` in the
   exception path, not DMA at all.
   Tracking which register actually receives `lui ,0xA460` (aborting the window when it
   is redefined) reduced 105 candidates to **2 true store sites**.
2. **A host/guest filesystem mix-up produced a false negative.** A "no such stores exist"
   conclusion was read from `/tmp/code.asm` on the *host* while the file had been written
   in the *guest*. Any check that spans the two must state which side it runs on.

## Found

| Function | Size | Evidence | Reading |
|---|---|---|---|
| `0x800077A0`–`0x80007964` | 460 B | polls `PI_STATUS` (`0xA4600010 & 3`) until idle; reads per-device timing bytes `5/6/7(s0)` and writes `0xA4600014` / `0x1C`; masks addresses with `0x1FFFFFFF`; writes `PI_DRAM_ADDR` (`0xA4600000`) and `PI_CART_ADDR` (`0xA4600004`) | **`osEPiStartDma` shape** — configure device timings, then start the transfer |
| `0x8000C3F0`–`0x8000C4B8` | 208 B | same 29-bit mask idiom, writes `PI_DRAM_ADDR` then `PI_CART_ADDR`, combines a global from `0x80000308` | second DMA start path (likely a raw/cart wrapper) |

So the cartridge loader in this build is **`0x800077A0`**, confirmed by behaviour rather
than by name.

## Who calls it — the interesting negative

Scanning the entire 64 MB for the `jal` encoding `0x0C001DE8` (target `0x800077A0`):

- **0 sites.** The routine is never called directly anywhere in the ROM.
- The sibling `0x8000C3F0` has exactly **one** caller, at ROM `0x16264DD` — deep in the
  cartridge, i.e. inside a bank whose VRAM base is not yet known.

Two consequences:

1. `0x800077A0` is reached **indirectly** — through the device-manager function-pointer
   dispatch we already found table evidence for (the 84-slot table at `0x128B8`, and the
   seven pointer tables after the code). This is normal libultra design (`__osPiDevMgr`).
2. The lone `jal` at `0x16264DD` is a concrete foothold in an unmapped bank. Resolving
   that bank's load address gives us both a real caller and, most likely, the descriptor
   table that maps ROM offsets to VRAM.

## Next

Determine the load address of the bank containing ROM `0x16264DD`, then read the
descriptor list its caller walks. The PI routine itself no longer needs finding.
