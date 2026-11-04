# M122 — the register-argument check: same method, different question, and it needed four calibrations

The stack check asks whether the caller *stored* the slot. A register is never empty, so the analogous question
is about **shape**: the callee dereferences `a_k`, and the caller passes a constant — can that constant be a
pointer this build uses?

## The check

For every call site whose callee dereferences parameter `k`, the caller's `a_k` is classified:

| class | meaning |
|---|---|
| **plausible address** | a constant in KSEG0 RDRAM (`0x80000480..0x80800000`) or KSEG1 cartridge (`0xA0000000..0xBFFFFFFF`) |
| **cannot be one** | any other constant — flagged |
| derived | parameter, return value, loaded value: unknown but pointer-shaped, not flagged |
| unknown | not judged |

The KSEG-only window is a deliberate, stated choice: a physical-address (KUSEG `0x0..0x7FFFFF`) pointer would be
a false positive, and the corpus uses KSEG vaddrs throughout. My first window included KUSEG and accepted
`0x1234` — the check was near-vacuous until that was tightened.

```
14 371 call sites · 47 774 dereferenced register arguments
  4 560 passed a plausible-address constant      84 cannot be one
  29 252 derived                                 13 878 unknown
14 flagged sites
```

## Four calibrations, each found by verification

1. **"Dereferences" was really "dereferences or escapes."** `params` was built from a set that also collected
   *forwarded* arguments, so any pass-through parameter looked pointer-taking: a libultra callee appeared to
   dereference all four of its arguments when it only ever dereferences `a0`. Flags **269 → 48**.
2. **Dereferences are path-insensitive.** Reading one flag showed `beq s4,zero,+7` before the store, with
   `s4 = a1`: the caller's `0` means "no output pointer", and the callee guards it. Dereferences now record
   whether the base register was **compared against zero on that path** (`State.tested`), and guarded
   dereferences no longer make a parameter "pointer-taking". Flags **48 → 14**.
3. **The guard flag was set for loads but not stores** — and the flagged access in point 2 is an `sw`. Missing
   that kept the same site flagged through a whole cycle.
4. **Findings were keyed by `pc` alone, and overlay vaddrs collide.** The flag list named `ovl_007fc12` at
   `0x801622fc` while reading that address in that image showed `sh v1,0x136(s2)`, not a call: another overlay
   loading at `0x8016xxxx` had a `jal` there, and one finding was overwriting the other. Findings are now
   keyed by **`(image, pc)`**, and the printer takes the owner from the same pass — the M112 lesson ("a seed
   address does not identify an image") reaching the reporting layer.

## What the 14 remaining flags are

Two families, both read:

* `ovl_008505e`, 3 sites: `a1 = 0` into `0x800653d0`, whose `a1` dereferences at `0x8006550c`/`0x80065510` *are*
  detected as guarded — these come from other `a1` accesses in the same function.
* `ovl_0098ee0` and `ovl_009aed0`, 11 sites: small integers (`0x0a`…`0x32`) passed as `a0` into dispatch-shaped
  functions (`0x80162114`, `0x80162694`) that take a pointer on other paths.

Both are the same phenomenon: **a parameter whose meaning varies by path or by caller** — an id here, a pointer
there. Deciding those needs path sensitivity (or interprocedural argument typing), which this analysis does not
have. So the check is a **diagnostic**, not a verdict: 14 candidates, **none verified as a defect**, and the
honest statement is that the shape test cannot resolve polymorphism.

## Verification

```
provenance.py --self-test    10/10
provenance.py --self-test2   11/11     L11 added: a non-pointer constant is flagged, a valid pointer is not
provenance.py --acceptance     3/3
provenance.py --arg-check               the numbers above; --json writes the list
```
