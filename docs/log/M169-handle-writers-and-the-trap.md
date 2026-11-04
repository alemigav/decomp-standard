# M169 — nothing else writes the handle, and the use path doesn't just compare: it traps

Two answers, one of them a correction to M168.

## 1. Every writer to the handle word, across all 36 images

`DAT_8012487c` is the handle array; a slot record is **16 bytes**, which the allocators pin exactly:

| offset | word | role |
|---|---|---|
| +0 | `DAT_8012487c` | **the handle** `slot \| counter<<8` |
| +4 | `DAT_80124880` | block pointer A — *and* the free-list link while free |
| +8 | `DAT_80124884` | list link (used by `0x800855d8`, zeroed by `0x800856a4`) |
| +12 | `DAT_80124888` | block pointer B (pairs only) |

**Writers to +0 — the handle — are exactly three sites:**

| site | what it does |
|---|---|
| `FUN_80085164`, `FUN_8008522c` | **mint**: `= slot \| DAT_80124858 << 8` |
| `FUN_800850e0` | **initialise**: `= 0` for all 128 slots |
| `FUN_80085398` | **range release**: `\|= 0xff`, deliberately invalidating the stored value |

`FUN_80085300` (single release) **does not write it** — it only compares. So the equality check there cannot be
bypassed by a third writer: there is no third writer.

Three functions take a **pointer into** the array and look like they might write it, and none of them does:

* `0x800856a4` writes `puVar2[2]` per slot — that is **+8**, the list link, not the handle;
* `0x800855d8` writes `puVar3[2]` — again **+8** (it links the slot into the `0x8012507c` work list);
* `0x8008548c` and `0x8008548c`-style readers only **compare** (§2).

## 2. The correction: the use path **traps**

M168 said the equality check in `FUN_80085300` "is the only thing standing between the design and a reissued slot
being freed by an old owner". True for *release* — but the same comparison exists on the **use** path, and there it
is fatal:

```c
/* 0x8008548c — taking a handle from a structure and resolving it */
uVar3  = *(uint *)(*(int *)(*(int *)(psVar6 + -2) + 8) * 4 + param_1[0x2b]);   /* the handle */
puVar5 = &DAT_8012487c + (uVar3 & 0x7f) * 4;
if (uVar3 != *puVar5) {
    trap(0);                       /* a deliberate fatal, not a silent skip */
}
```

So the invariant is enforced **at both ends with different severity**:

| path | on a stale handle |
|---|---|
| release (`FUN_80085300`) | **silently ignored** — no double free, no diagnostic |
| use (`0x8008548c`) | **`trap(0)`** — the game dies rather than touch the wrong block |

That is a stronger design than M168 described, and it makes the earlier caveat sharper: because the counter is
*global* and never masked, the failure mode after 2^24 allocations would be a **trap in the use path**, not a silent
corruption. A design that trampolined stale handles would need the mask; this one traps instead, which is the
choice a real-time loader makes when correctness matters more than recovery.

## 3. What this settles

* **Confirmed**: nothing else writes the handle. Three writers, all accounted for, and two of the three are
  deliberately invalidating.
* **Corrected**: the equality check is not one guard but **two**, on release (silent) and on use (fatal).
* **Confirmed**: the 16-byte slot layout, from the allocators' own stores — `[handle][ptrA/free-next][link][ptrB]`.

## 4. Scope, as before

A **code reading**: four functions quoted line by line, falsifiable, but not gated — the registry is runtime state
with no cartridge bytes to assert against. **183 cases across 17 fixtures**, `ci.sh: ok`, 18/18 marker checks,
audit 15/15 — unchanged, because nothing here is a fixture.
