# M118 — frame slots are 98.5 % resolved; the residual is stack arguments, and the tests are now executable

Two things: the slot misses got classified by cause, and the two pre-registered acceptance tests became
checks that run instead of prose that drifts.

## Slot misses, by cause

The misses used to be one number. They are now three, and the split says what to do next:

```
frame slots: 401 478 access(es), 395 333 resolved (98.5 %)
             missed: 5 815 never stored in this region,
                     325 killed by a merge,
                       5 with an unstable frame
```

**98.5 %.** Frame-slot resolution is finished as far as intra-procedural analysis can take it. The residual is
almost entirely "never stored in this region" — reads of **incoming stack arguments**, which live on the
*caller's* frame and cannot be known without caller context. That is the honest boundary, and the only way past
it is propagating a callee's outgoing `sp+N` stores into its incoming stack parameters at each call site. That is
a real (bounded) piece of work and it is *not* done here; it is written down so it is not rediscovered as a
mystery later.

The other two categories are noise at this scale: 325 slots where the paths genuinely disagreed, 5 functions
whose `sp` never settles.

## The acceptance tests are executable now

```
$ python3 tools/provenance.py --acceptance
PASS  test 1a: FUN_800327ec reads its record fields through param(a0)
      offsets seen: ['0x0', '0x4', '0x8', '0xc']
PASS  test 1b: both call sites are in FUN_8003287c and the argument is unknown
      sites ['0x80032a04', '0x80032a84'], a0 ['unk', 'unk']
PASS  test 2: the map read and the pointer-table load report their known base
      got {'0x800329ec': '0x800eb204', '0x80032a5c': '0x800eb264'}
3/3 acceptance check(s)
```

Test 1's expectation is the **corrected** one from M117, as instructed: the structure holds and the argument is
`unk`. Encoding it as a check means the next refactor cannot silently restore the too-good artifact — a
`ret(80001180)` would now fail the run rather than read well in a note.

## Two bugs made while instrumenting, both worth naming

* **A stale `SLOT_STATS["miss"]` line crashed `--census`** — left behind when the census moved to layer 2 in
  M115. It was invisible for several runs because I was piping the output through `grep`, which filtered the
  traceback along with the noise. Rule: run a command plainly before filtering it.
* **I inserted uses of `stores_seen` and `classify` into `transfer` without giving it those parameters** — two
  NameErrors. The fixtures caught the first; the census caught the second. This is the ordinary cost of
  threading new state through a 1 200-line analysis, and the reason the fixtures are run before every commit.

## Numbers, unchanged in substance

```
3678 regions · 111 179 memory operands · 13 567 attributed (12.2 %)
spoff 27 350 · unk 25 355 · param 21 283 · unreached 16 005 · const 13 567
```

Fixtures **10/10** and **8/8**.

## Verify

```
python3 tools/provenance.py --self-test && python3 tools/provenance.py --self-test2
python3 tools/provenance.py --acceptance          # 3/3, the two pre-registered tests
python3 tools/provenance.py --census              # coverage line, buckets, slot-miss breakdown
```
