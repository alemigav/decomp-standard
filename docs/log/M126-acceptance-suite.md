# M126 — `pad_layout` in the acceptance suite, and a mixed-errno fixture that changed a behaviour

Five tools had five fixtures and no single verdict. There is now one entry point, and the SI decoder gained the
fixture that mixes a good channel with a bad one.

## Mixed-errno fixture

```
ch0  IDLE      rx=0x04 errno=0  idle: no buttons, sticks centred
ch1  NO_PAD    rx=0x84 errno=8  payload present but not a pad reading
ch2  START     rx=0x04 errno=0  Start
terminator 0xfe CONT_CMD_END
```

Each channel is classified independently and a bad neighbour does not affect the others — asserted as
`[0, 8, 0]`, with channel 2 still decoding `Start`.

### It changed the decoder, not just the test

Writing the assertion `"button" not in chans[1]` failed, because the tool was still populating `button`,
`stick_x` and `stick_y` from an errored block's bytes. That is wrong against the reference: libultra's
`osContGetReadData` only assigns those fields

```c
if (data->errno == 0) { data->button = ...; data->stick_x = ...; data->stick_y = ...; }
```

so an errored channel's bytes are *not* a pad state and must not be presented as one — that is precisely the
shape of the M109 misread this tool exists to prevent. An errored channel now returns `errno`, `valid = False`,
and a meaning that says the payload is present but is not a pad reading; no `button` key is created.

## `tools/acceptance.py`

```
$ python3 tools/acceptance.py
suite                    cases      verdict
provenance self-test     10/10      PASS
provenance self-test2    12/12      PASS
provenance acceptance    3/3        PASS
pad_layout self-test     8/8        PASS
mips harness             15/15      PASS

all suites pass (48 cases across 5 fixtures)
```

It does not re-implement any check: it invokes each suite, parses the last `N/M` line, and fails on a non-zero
exit **or** on a case count that differs from the expected one. That second rule matters — a fixture that
quietly loses cases still reports `PASS` on its own, and this is the only place that notices.

Verified rather than assumed: tampering the expected count to 99 produces

```
pad_layout self-test (tampered expectation) 8/8  FAIL  EXPECTED 99 CASES, found 8
exit=1
```

## State

```
provenance self-test    10/10
provenance self-test2   12/12
provenance acceptance    3/3
pad_layout self-test     8/8      (+1: mixed errno)
mips harness            15/15
```

## Reproduce

```
python3 tools/acceptance.py          # one verdict for everything
python3 tools/acceptance.py -v       # plus each failing suite's own output
python3 tools/pad_layout.py --self-test
```
