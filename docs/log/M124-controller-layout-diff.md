# M124 — the controller layout, diffed against perfect_dark's libultra

Our pad layout was derived empirically: from a live SI buffer in M109, and reused by the stack-argument and
injection work in M121/M123. `perfect_dark` ships the libultra source that builds that buffer, so the layout can
now be diffed against the authoritative definition instead of only against itself.

## The reference

`perfect_dark/src/lib/ultra/io/controller.h` — note that `include/PR/os.h` exists but is an umbrella; the pad
structures live in `include/PR/os_cont.h` and the PIF block layout in the libultra source:

```c
typedef struct {                    /* the command block AND the response, 8 bytes          */
	u8  dummy;    /* 0x0 */   /* = CONT_CMD_NOP (0xff)                                     */
	u8  txsize;   /* 0x1 */   /* = CONT_CMD_READ_BUTTON_TX (1)                             */
	u8  rxsize;   /* 0x2 */   /* = CONT_CMD_READ_BUTTON_RX (4); bits 6-7 carry the error   */
	u8  cmd;      /* 0x3 */   /* = CONT_CMD_READ_BUTTON (1)                                */
	u16 button;   /* 0x4 */   /* big-endian; initialised to -1                             */
	s8  stick_x;  /* 0x6 */   /* initialised to -1                                         */
	s8  stick_y;  /* 0x7 */
} __OSContReadFormat;
```

and `osContGetReadData` walks exactly that: `ptr += sizeof(__OSContReadFormat)` (8), `data->errno = CHNL_ERR(...)`,
then `button`, `stick_x`, `stick_y`. `__osPackReadData` writes the same struct `__osMaxControllers` times and
terminates the list with `*ptr = CONT_CMD_END` (`0xfe`).

## The diff

| offset | perfect_dark | our observation (dump `…-132952`) | |
|---|---|---|---|
| +0 | `dummy = CONT_CMD_NOP` = `0xff` | `ff` | match |
| +1 | `txsize = 1` | `01` | match |
| +2 | `rxsize = 4` | `04` | match |
| +3 | `cmd = 1` (`READ_BUTTON`) | `01` | match |
| +4..5 | `u16 button`, big-endian | idle pad → `00 00` | match |
| +6 | `s8 stick_x` | `00` | match |
| +7 | `s8 stick_y` | `00` | match |
| stride | `sizeof(__OSContReadFormat)` = 8 | 8 bytes per channel | match |
| terminator | `CONT_CMD_END` = `0xfe` after the channel array | `fe` at `+0x20`, after four blocks | match |
| error | `CHNL_ERR = (rxsize & 0xC0) >> 4` | not in the payload at all | **corrects us** |

Stored artifact, not a live read:

```
80014fa0  ff 01 04 01 00 00 00 00      channel 0: NOP, tx 1, rx 4, cmd READ_BUTTON, idle
80014fa8  ff 01 04 01 00 00 00 00      channel 1
80014fb0  ff 01 04 01 00 00 00 00      channel 2
80014fb8  ff 01 04 01 00 00 00 00      channel 3
80014fc0  fe 00 00 00 00 00 00 00      CONT_CMD_END
```

## What the diff changes in our record

1. **"ares reports no controller" (M109) is wrong.** The error is not in the payload: it is bits 6–7 of `rxsize`.
   ares' response was `ff 01 04 01 ff ff ff ff` — `rxsize = 0x04`, so `CHNL_ERR = 0`, i.e. **no error**, and the
   payload decodes as `button = 0xffff`, `stick_x = -1`, `stick_y = -1`: a pad with **every button held** and both
   sticks pinned to their minimum. The game was not told "no controller"; it was told "all buttons pressed".
   Retracted here rather than quietly dropped.
2. **`0x80016470` is the Controller Pak buffer, not a second button buffer.** The dump holds
   `ff 23 01 03 c0 1b 00 00` = NOP, `txsize = 0x23` (35 = `CONT_CMD_WRITE_MEMPACK_TX`), `rxsize = 1`,
   `cmd = 3` (`CONT_CMD_WRITE_MEMPACK`). That explains M109's observation that a breakpoint on that buffer's path
   "never fired" during button reads: it is the pak-write path, and both buffers are live for different commands.
3. **The M109 button misread has a cause.** `button` is a big-endian `u16` at +4, so `00 10 00 00` is `0x0010` =
   **R**, and `Start` would have been `10 00 00 00` (`0x1000`). The layout, not carelessness alone, is why the
   byte pair reads the way it does.

## What it does not change

Nothing in the provenance work: no value kind, no summary field, and no acceptance check depends on the payload
semantics — they depend on the *block* layout, which matches exactly. Fixtures **10/10**, **12/12**, acceptance
**3/3**, unchanged.

## Verdict on the audit's suggestion, for this item

This is the case where `perfect_dark` earns its place: libultra is engine-independent, so a Rare decompilation
documents *Capcom's* OS calls just as well. Two of our three corrections here came from it, and the third (the
pak buffer) came from applying its constants to a byte pattern we already had.

## Reproduce

```
python3 - <<'PY'
from pathlib import Path
d = Path("rom/Resident Evil 2 (USA) (Rev 1)-rdram-20261031-132952.bin").read_bytes()
o = 0x80014FA0 - 0x80000000
for i in range(0, 0x28, 8):
    print("%08x  %s" % (0x80014FA0 + i, " ".join("%02x" % b for b in d[o+i:o+i+8])))
PY
```
