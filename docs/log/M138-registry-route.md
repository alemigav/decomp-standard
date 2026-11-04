# M138 — the registry route pays: nine 8-byte entries, the room's own entry point, and two confirmed structures

M137 ended by proposing to walk the loader registry instead of guessing shapes. This is that walk. It
corrected one of our own documents, found the room's entry point, and produced the **first two structural
correspondences between the PS1 reference and our port that are confirmed in our own code** rather than
inferred from it.

## 1. The registry is 9 entries of 8 bytes — the "32-byte entry" reading was wrong

Measured from stage-2 (`0x8010b2e0`), each entry is **1 descriptor byte + 3 padding + 1 handler word**:

| slot | desc | handler | destination (M19 table) |
|---|---|---|---|
| 0 | 2 | `0x80180cd0` | `0x8017b410` |
| 1 | 3 | `0x8015b030` | `0x8015b030` |
| 2 | 4 | `0x8017b410` | `0x8017b410` |
| 3 | 10 | `0x8017b410` | `0x8017b410` |
| 4 | 5 | `0x8017b4a4` | `0x8017b410` |
| 5 | 8 | `0x8009c370` | `0x8017b410` (compressed length 0) |
| 6 | 7 | `0x8016e880` | `0x8016e880` |
| 7 | 6 | `0x800995fc` | `0x8015b030` (compressed length 0) |
| 8 | 9 | `0x8008b794` | `0x8017b410` |

The handler equals the load base exactly when the member is an overlay whose entry point is at base+0
(slots 1, 2, 3, 6); where the member is not loaded (compressed length 0) the handler is a stage-2
function instead (slots 5, 7, 8). `docs/format_notes.md` said "32-byte-per-entry, word 0 = descriptor,
word 1 = handler, six more per entry" — **corrected**: the six extra words are the next entries, and the
indexing `(&DAT_8010b2e0)[slot * 8]` is a **byte** stride.

Three entry points read the registry, all in stage-2, and the difference matters:

* `overlay_open(slot)` (`FUN_8004cc5c`) — inflate, then call the handler directly;
* `overlay_slot_reader(a, slot)` (`FUN_8004cca8`) — inflate, then `FUN_8004cd54(a, handler)`, which only
  **stores** the handler into a request structure and marks it pending;
* `overlay_slot_reader_b(slot)` (`FUN_8004cd08`) — inflate, then `FUN_8004ce40(handler)`, same idea via a
  different request slot.

Two of the three therefore do **not** call the handler: the call happens later, in the loader thread. That
is why an "open the room" search by call graph alone finds nothing — the handler is dispatched, not
invoked.

## 2. The room's entry point, and its state table

Slot 6 is the resident room overlay (`0x7c552` → `0x8016e880`, the one M98 mapped), and its handler is the
overlay's own entry:

```c
void entry(void) {
  FUN_8016e8d0();                                   /* the room setup — the script-buffer filler of M98 */
  do {
    (*(code *)(&PTR_FUN_80171860)[DAT_80171dd9])();  /* room state table, indexed by one byte */
    FUN_8016fb54();
    func_0x8004cd88(1);
  } while (true);
}
```

So the port's room loop is a **state table at `0x80171860` selected by the byte `0x80171dd9`** — a concrete
handle for Phase 2's "room header → what the room does", and the place any future room-behaviour work
should start.

## 3. The port's room initialiser, and the two confirmed structures

`FUN_800635b0` (stage-2, 657 lines of pseudocode) is the port's `Set_room`. In its first 60 lines:

* `FUN_80085398(DAT_800c52d8, DAT_800c52d8 + 0xaf800, &DAT_800b925c)` — clears a **718 848-byte** work
  region at `0x800c52d8`;
* `DAT_800df934 = DAT_800df930; DAT_800df92c = DAT_800df930;` — sets the **scene pointer and the script
  structure pointer to one base**. `DAT_800df930` is itself set from `DAT_800c52d8` (`FUN_80064ff0`), so
  the room's script chain and its scene data are the same region. This closes the M99 question "where does
  the stream come from" one level higher than before: not a cartridge address, but the room work region.
* `iVar18 = 0x21; do { *puVar13 = &DAT_800e8620; iVar18--; puVar13++; } while (iVar18 != 0);` —
  **33** pointers from `0x800e13ec`, every one set to the same default `0x800e8620`.
* `uVar19 = 0; do { puVar13[0x6892] = 0; uVar19++; puVar13 += 0xda; } while (uVar19 < 0x20);` —
  **32** slots cleared with **stride 0xda**.

The reference's `Set_room` does exactly the same two things: `G.pEnemy[1..0x21]` = **33** slots all set to
the dummy `Em_default`, and `pG->Ob_model[0..0x20)` = **32** entries cleared. **Counts and shape match in
our own code**, which is the first evidence of real shared structure rather than a plausible guess:

| reference | our port |
|---|---|
| 33 enemy slots, all default at room load (`Em_default`) | 33 pointers at `0x800e13ec`, all `0x800e8620` |
| 32 object-model slots cleared, and the model list ends at a high-water mark | 32 slots cleared, stride `0xda` |
| room work = free-work head, becomes `pRoom` | room work = `0x800c52d8`, cleared `0xaf800` bytes |
| `pEnemy[Id + 0x12]` routine table indexed by enemy id | routine table still to locate (next step) |

## 4. Why the stream has no fixed home — now answered one level up

M99 recorded that the command buffer's source `*(0x800df934)` is "zero in the image, so runtime", and
treated the stream as absent by construction. The corpus shows `_DAT_800df934` written from **nine sites
across six room overlays** (`ovl_007688e` at `0x8015fde0` and `0x8015bac8`, `ovl_00b08a2` at `0x80166a34`,
`ovl_007af7a`, `ovl_00ae24a`, `ovl_00a9d94`, `ovl_0095446`, `ovl_00a0344`) plus stage-2's
`FUN_800635b0`. **Each room overlay sets it during its own initialisation**, which is exactly why no
single cartridge address can hold the stream: the pointer is per-room state, set by that room's code.

## 5. What is still open, and the next anchored step

* **The enemy routine table.** The reference indexes `pEnemy[Id + 0x12]`. Our equivalent should be a table
  of 33+ routine pointers near the slot array `0x800e13ec = &DAT_800e13ec`; locating it makes the entity
  state machines addressable without any shape guessing.
* **The room header inside `0x800c52d8`.** The reference's header (8 counts, then 23 self-relative
  offsets) should now be tested against **that region as filled by the port**, rather than against the
  4 762 members — which is what produced M137's 12 unvalidated candidates.
* **The state table `0x80171860`.** Naming its entries is the cheapest route to "what a room does".

```
python3 tools/acceptance.py                    # 98 cases, 10 fixtures — unchanged by this milestone
```
