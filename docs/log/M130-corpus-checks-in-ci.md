# M130 — can the last three checks run in CI? Two blockers, one of them removable

Asked directly: can the three pre-registered corpus checks run on a runner, or do they really need the
cartridge? Measured rather than argued.

## What they consume

`provenance.py --acceptance` needs three things:

1. **stage2's bytes** — 1 172 240 B of the cartridge's own code (`assets/unpacked/00000_…bin`), plus boot's
   70 KB;
2. **exact region boundaries** — previously assumed to be an optimisation;
3. `build/elfs/images.json` — 6 KB of metadata.

Item 1 is cartridge content. This project does not commit ROM bytes or extracted assets, and no amount of
tooling changes that: a decompressed code image *is* the cartridge's bytes. Only an owner-provided secret can
supply them to a runner.

## Item 2 is not optional — it is part of the evidence

Running the three checks with the Ghidra index replaced by the prologue heuristic (`--decomp` pointed at an
empty directory):

```
PASS  test 1a: FUN_800327ec reads its record fields through param(a0)
FAIL  test 1b: both call sites are in FUN_8003287c and the argument is unknown
      sites ['0x80032a04', '0x80032a84'], a0 ['ret(80001180)', 'ret(80001180)']
PASS  test 2: the map read and the pointer-table load report their known base
2/3 acceptance check(s)
```

Test 1b fails **and revives the M117 artifact** (`a0 = ret(80001180)` instead of `unk`) because the heuristic's
regions merge code differently, so the `lbu a0,-0x10(v0)` that overwrites `a0` lands elsewhere. So the exact
boundaries are load-bearing: a CI that had the ROM but not the index would report a *failure that is not real*.

## The removable half

Those boundaries are pure address metadata. `build/decomp/*/decompile-index.json` is 9.5 MB, of which almost
nothing is addresses — each function entry also carries `relative_path`, `sha256`, `limitations` prose and
`status`. Distilled to start/end pairs:

```
tools/export_ranges.py  →  fixtures/decomp/ranges.json
36 images, 3 678 ranges, 103 792 bytes
```

Committed, because this is the same class of fact `src/INDEX.md` already publishes (function addresses), and
because `--check` makes drift detectable:

```
$ python3 tools/export_ranges.py --check
PASS fixtures/decomp/ranges.json matches build/decomp (36 images, 3678 ranges)
```

`ghidra_regions` now tries `build/decomp`, then the fixture, then the heuristic — and the census line reports
which source served each image. Verified by removing the index:

```
$ provenance.py --acceptance --decomp /tmp/no-index
PASS test 1b … a0 ['unk', 'unk']      3/3 acceptance check(s)
```

## The CI tier that results

`.github/workflows/acceptance.yml` gained a gated step:

```yaml
- name: Cartridge-dependent suites (owner-provided secret)
  env:
    RE2_CART_B64: ${{ secrets.RE2_CART_B64 }}
  run: |
    [ -z "${RE2_CART_B64:-}" ] && { echo "…will SKIP (51 of 54 cases)"; exit 0; }
    printf '%s' "$RE2_CART_B64" | base64 -d > "rom/Resident Evil 2 (USA) (Rev 1).z64"
    python3 tools/unpack_zlib.py rom/*.z64 --out assets/unpacked     # 10 s
    python3 tools/build_images.py rom/*.z64                          # 0.8 s
```

* **without the secret**: 51 of 54, the three corpus checks SKIP, as before;
* **with it**: the cartridge is materialised, the 4 761 members unpacked, the 36 images built, and the three
  checks run for real → 54 of 54.

Verified end to end in a scratch clone, materialising the cartridge from a base64 of the local file exactly as
the workflow does.

## The policy part, stated plainly

Putting the cartridge in CI is the owner's decision, not a technical one: it means a copy of a
copyrighted ROM lives in a repository secret or a CI artifact store. Nothing in this repo changed about that —
`rom/` is still gitignored, no cartridge bytes are tracked, and the workflow only *uses* a secret if one exists.
The alternative is the split that already holds: 51 of 54 on the runner, 54 of 54 locally and in the hook.

## Reproduce

```
python3 tools/export_ranges.py --check
python3 tools/provenance.py --acceptance --decomp /tmp/empty     # proves the fixture stands in for the index
sh tools/ci.sh                                                   # 54/54 here, 51/54 on a bare clone
```
