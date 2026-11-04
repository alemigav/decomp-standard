# M125 — the CHNL_ERR path, made executable

M124 corrected a claim in this log by reading libultra: a channel's error is bits 6–7 of `rxsize`, not
anything in the payload, so ares' `ff 01 04 01 ff ff ff ff` was a pad reporting **every button held**, not
"no controller". A correction that lives only in prose drifts back. It is now a tool with a fixture.

## `tools/pad_layout.py`

Decodes one SI command block (`__OSContReadFormat`, 8 bytes per channel, list ended by `CONT_CMD_END`):

```
$ pad_layout.py --hex "ff 01 04 01 ff ff ff ff"
  ch0  READ_BUTTON  tx=1  rx=0x04 errno=0  button=0xffff
       A,B,Z,Start,D-Up,D-Down,D-Left,D-Right,L,R,C-Up,C-Down,C-Left,C-Right  stick=(-1,-1)
       -> every button held, sticks at minimum (a pad state, NOT 'no controller')
```

* `errno = (rxsize & 0xC0) >> 4` — the real rule, and a payload is only read when it is zero;
* command names from `CONT_CMD_*`, so a pak block is not mistaken for a pad reading;
* button bits decoded, which is what pins `0x1000` = Start and `0x0010` = R (M109's misread);
* a **zeroed tail is not a channel**: the real pak buffer is one command followed by zeros, and a naive walk
  reports a phantom `REQUEST_STATUS` there. That wart was caught by running the tool on the stored dump, not
  by thinking about it.

On the stored dump (`…-132952`):

```
80014fa0  ch0..ch3  READ_BUTTON  errno=0  button=0x0000  stick=(0,0)   -> idle: no buttons, sticks centred
          terminator 0xfe CONT_CMD_END
80016470  ch0       WRITE_MEMPACK tx=35 rx=0x01 errno=0  -> not a pad reading
          terminator 0x00 (a zeroed tail)
```

## The fixture — 7/7

| case | asserts |
|---|---|
| idle pad | errno 0, `button = 0`, sticks 0, meaning "idle" |
| **ares all-ones** | errno **0**, `valid`, `button = 0xffff`, sticks `-1`, **all 14 buttons named**, and the meaning string literally contains "NOT 'no controller'" |
| real channel error | `rxsize = 0x84` → errno **8**, payload invalid, no `button` claimed |
| pak-write block | `WRITE_MEMPACK`, tx 0x23, rx 1, "not a pad reading" |
| four blocks + `0xfe` | the dump's shape decodes to 4 channels and `CONT_CMD_END` |
| zeroed tail | ends the list, and is **not** `CONT_CMD_END` |
| button bits | `0x1000` is Start, `0x0010` is R |

The second row is the regression guard for M124: if anyone re-derives "all-ones means no controller", that
fixture fails.

## State of every suite

```
pad_layout.py --self-test        7/7      (new)
provenance.py --self-test       10/10
provenance.py --self-test2      12/12
provenance.py --acceptance       3/3
test_harness.py                 15/15     (the MIPS fixture, unchanged)
```

## Reproduce

```
python3 tools/pad_layout.py --self-test
python3 tools/pad_layout.py --rdram "rom/Resident Evil 2 (USA) (Rev 1)-rdram-20261031-132952.bin"
python3 tools/pad_layout.py --rdram … --addr 0x80016470
```
