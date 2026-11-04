# M111 — experiment B, step 1: a provenance core that survives its own fixture

Experiment B was scoped long ago as "extend pointer provenance through stack slots, arguments and return
values" (`docs/format_notes.md`, *Experiments B and C: scoped, not done*). This is **step 1 only**: the
intra-procedural core, with the interprocedural layer explicitly forbidden until the fixture is 10/10 — and
it is 10/10.

## What was built

`tools/provenance.py`: an abstract value per register and per stack slot — `const(addr)`, `param(k)`,
`ret(fn)`, `load`, `unk` — over a **real per-region CFG with a merge at every join**, honouring MIPS delay
slots, clobbering caller-saved registers on a call, and invalidating a register on any load. Three modes:

```
./provenance.py --self-test                       # 10 hand-computed fixtures, all real mistakes
./provenance.py --target 0x800eb260 --window 0x10 # accesses into a window, with their abstract base
./provenance.py --census --json manifests/provenance.json
```

## The fixture, and the six bugs it caught

Each case encodes a mistake this project has actually made, or a merge rule a linear scan gets wrong. The
first run was **3/10**, and the failures were the analysis, not the expectations:

| bug | symptom | fix |
|---|---|---|
| `$zero` was an unknown register | `li` + `move` idioms produced `unk`; fixture 10 | `get(0)` returns `const(0)` |
| parameters were never named at entry | every access through `a0`–`a3` was `unk`; fixture 5 | `a0..a3 = param(0..3)` at region entry |
| `jal` did not clobber caller-saved (only `jalr` did) | a constant **survived a call**; fixture 7 | clobber + `v0 = ret(target)` on both |
| **delay slots were never executed** | the instruction after every branch/jump/call was skipped — fixtures 8 and 9 only "passed" because my own fixtures had hidden their setup *inside* a delay slot | execute `i+1` before applying the transfer |
| the region splitter cut at the first `jr ra` | **every leaf function after it was never analysed** — code with no prologue got no entry state. Caught by cross-checking a target the boot code provably reaches: `find_readers.py` reports `base=0x80012150` at `0x80001440`, `provenance.py` reported nothing | regions delimited by prologue **or** post-`jr ra` |
| attribution ignored reachability | published attributed total **2 910** while the `const` bucket held **1 293**: an unreached block still builds constants locally | attribution now requires a constant base **and** a provably reachable block |

The last two are the important ones. Both produced *plausible, publishable* numbers, and only a
cross-check against another instrument and an internal identity ("the buckets must sum to the operand
total") exposed them.

## The census, and the identity that makes it trustworthy

```
36 images: 81 067 memory operands
  const (reached)       1 293   1.6%   attributed addresses
  unreached+const       1 617          constants built in blocks with no proven entry
  param                   798          a0-a3 used directly as a base — step 2's first target
  load                    150          a base that came out of memory
  ret                   1 936          the `jal` sites themselves (v0 = ret(target), unresolved)
  unk                  17 688          reached, base unknown
  unreached            57 585          no entry state at all (indirect jumps, jump tables)
```

`1 293 + 1 617 + 798 + 150 + 1 936 + 17 688 + 57 585 = 81 067` exactly, and `attributed == const` by
construction. That identity is the check: if it ever fails, the run is not quotable.

The 73 % `unreached` is the honest shape of static reachability, not a defect: `jr v0` with a table-computed
target produces no edges, and this project's most important code — the 141-entry dispatcher — is exactly that
shape. Resolving those edges is `find_jump_tables.py`'s output, and consuming it belongs to step 2, where an
interprocedural pass knows which function the table pointers came from.

## What is deliberately NOT done

No interprocedural resolution. `param(k)` is **named, never resolved**; `ret(fn)` is **recorded, never
resolved**. That is the fence, and the numbers above are its exact input: 798 accesses sit on a parameter,
1 936 on a call's return value, and 1 617 on constants in code whose reachability is unproven.

The acceptance tests for step 2 were fixed before this code existed and are not yet run:

1. `FUN_800327ec`'s record fields must be attributed to `cart_record()`'s return at `0x80071ec0` — a
   two-hop chain (table entry → return → argument → fields);
2. the bank-C map reader `0x80032a5c` (`*(s4 + 0x800eb264)`, `s4 = s0 << 2`) must be found without being
   told, where `s0` is a parameter;
3. a stack-slot case verified by reading both instructions — already covered intra-procedurally by
   fixture 4, and it must keep working.

## Verify

```
python3 tools/provenance.py --self-test          # 10/10
python3 tools/provenance.py --census             # the buckets must sum to the operand total
python3 tools/provenance.py --target 0x800eb204  # nothing yet: that base is loaded, i.e. step 2
```

The last command is a negative result worth keeping: `0x800eb204` and `0x80115284` — the slot maps and the
scene-slot struct, both of which this project knows are read — produce **zero** intra-procedural hits, because
every access to them goes through a loaded base or a parameter. That is precisely the gap step 2 exists to
close, now measured rather than asserted.
