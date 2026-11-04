# M137 — Phase 2 starts from a reference, and its fingerprints do not yet fire on our data

The owner's Phase 2 asks for the room header, the entity system and collision. Our own notes have none of
those (they cover the cartridge, compression, the media container, and code) — so this milestone records
where a reference exists, what it actually says, and **three tests that came back negative**, which is
what stops the next session from re-deriving the same non-answers.

## 1. The reference, and how it may be used

`MeganGrass/bio2-ds` — *Resident Evil 2 Dual Shock Ver. (SLUS_00748) Disassembly/Decompilation* — is the
only RE2 PS1 decompilation that exists, and it is **not open source**: no licence, Capcom/Sony copyright
stated in its own README, derived from a retail disc plus the symbol file (`MAIN.SYM`) of the October 1997
prototype. Its README also records that it contains no Capcom source, SDK or assets, and that its C was
bulk-exported from Ghidra with an LLM.

**Posture, same as `perfect_dark` at M124: reference only.** Structures and semantics may be read to
generate hypotheses; nothing is copied into this repository, and nothing from it is committed. Its C is
not authoritative — a claim taken from it is a *candidate* until our own disassembly confirms it.

Why it is worth reading at all: every RE title that launched on PlayStation is an iteration of one engine,
and RE2 N64 is a port of RE2 PS1 (R3000 → R4300), so the room format and the entity system are expected to
be the same design with a different encoding.

## 2. What the reference says about the room file (hypotheses, with fingerprints)

From `ROOM.C`/`ROOM.H`, in my own words:

* **Load**: the room file ("RDT") is read into the *free-work head*, which then **becomes** `pRoom`. So
  the room header is the first bytes of the loaded file, not a separate allocation.
* **Relocation, two passes.** Every pointer in the file is stored as a **byte offset**, fixed up by adding
  the file base: pass 1 walks the header's pointer run from `pEdt0` up to `Cut`; pass 2 fixes the
  cut-table entries (`pSp`) and each model's `Tim_adr`/`Tmd_adr`. This is the single most testable
  property of the format.
* **Header shape**: eight byte-sized counts (`nSprite, nCut, nOmodel, nItem, nDoor, nRoom_at, Reverb_lv,
  nSprite_max`), then that pointer run (`pEdt0, pVh0, pVb0, padd0, padd1, pRbj_end, pSca, pRcut, pVcut,
  pLight, pOmodel, pFloor, pBlock, pMessage, pMessage_sub, pScrl, pScdx, pScd, pEsp_hed, pEsp_end,
  pEsp_tim, pEsp_tim_end, pRbj` — 23 words), then the cut array.
* **Script and text live in that header**: `pScdx`/`pScd` (script index + script data), `pMessage`/
  `pMessage_sub`, `pScrl`. That is the PS1 counterpart of our `*(0x800df92c)` stream chain, which is why
  this reference is relevant to the VM rather than only to geometry.
* **Room blocks**: `pRbj[0]` = byte offset of the entry table from `pRbj`, `pRbj[1]` = entry count, each
  entry 8 bytes `{Data_ofs, Seq_ofs}`. Entries are **filtered by a flag word**, one bit per entry, and the
  loader compacts surviving blocks and rewrites their offsets — i.e. room *events* are gated by game flags
  and the block set is fixed at room load.
* **Alternate block variant**: index `+0x7d` selects it when `Font_type != 0`.
* An `Rdt_tbl[7]` array maps stage → room-name table, rooms named `ROOM<s><rr><cc>_RDT`.

## 3. What the reference says about entities (hypotheses)

* `G.pEnemy` is an array of `ENEMY_WORK*`, slots `1..0x21` (**33**), every slot initialised to a shared
  dummy (`Em_default`) at room load; `pEm` is the current slot pointer, `ppEnemy_end` the high-water mark.
* **Per-type update routine**: `((EM_ROUTINE)G.pEnemy[pEm->Id + 0x12])(pEm)` — the routine table sits at
  `pEnemy[0x12]` and is indexed by the enemy's `Id`. An enemy runs when `Be_flg & 1`.
* **State fields** on the work struct: `Type` (high bit preserved across the update — it is set/cleared
  around the call), `Timer0`, `Timer1`, `Routine_0..3` (one 32-bit word, written with a single store),
  `Move_no`, `Sce_flg`.
* A second dispatch is derived from `Timer0`: `Routine = ((Timer0 & 0xff00) - 0x100) | 4`, then the same
  routine is called again — i.e. **animation/move state and behaviour state are separate indices** packed
  into one field.

## 4. The three tests, and why all three are negative

**(a) RBJ shape in our overlays — absent.** The reference's `[table offset][count]` + `count`×`{Data_ofs,
Seq_ofs}` shape, with the strict condition `offset == 8 + 8*count`, returns **0 hits** in
`ovl_007c552`, `ovl_0072610` and `ovl_0078c0e` (15 360 / 49 568 / 59 104 B); the relaxed form returns one
trivial `count = 1` hit in each of two images. So our resident overlay does not carry the room block the
way the PS1 loader expects.

**(b) The 23-word offset run — 12 candidates, all suspect.** Requiring ≥18 distinct non-zero words, all
below the file size, with the last reaching into the file and the maximum beyond 40 % of it, gives **12 of
4 762** members. Against a null of 20 KB random data (0 hits, 4 samples) that looks like signal, but it is
not evidence: every one of the 12 is a **member the loader registry never references**, and these files
are low-byte data in which 23 small distinct words are cheap. The first hit's own numbers show the risk —
`02585_3c3c412_14600.bin` reports the run at offset 14 380, i.e. 220 bytes from the end of a 14 600-byte
file, which is not a header.

**(c) Destination mapping — mismatched.** The reference reads the room into the free-work head; in our
port the registry (`0x8010b2e0`, 32-byte entries) sends four members to `0x8017b410` (`0x72610`,
`0x78c0e`, `0x7af7a`, `0x7e132`) and the resident overlay to `0x8016e880` (`0x7c552`). Which of those is
"the room" is **not established by the reference**, because the port's free-work bookkeeping is its own.

## 5. What this leaves, and the next experiment

The reference is usable and the design is very likely shared — but **none of its fingerprints fire on our
data yet**, and shape-based scanning is exactly the technique that produced three false answers earlier in
this project (fills walking forever, a 340× "signal" that was periodicity). The next step should therefore
be **anchored on our own code, not on shape**:

1. read the **handler** for the free-work slot (`DAT_8010b2e4 + slot*8`, the word after each descriptor
   index) — that handler is the port's `Set_room`, and it names the destination and the relocation pass;
2. from that handler, take the room member's identity and only then test the header shape against **that**
   member, not against all 4 762;
3. for entities, look for the port's equivalent of `pEnemy[Id + 0x12]` — a routine table at a fixed
   offset past an enemy-pointer array — which is a far stronger fingerprint than a run of small words.

## 6. Note on the three SDK manuals now in `docs/`

`Nintendo_64_Programming_Manual` (534 pp), `Nintendo_64_EXEGCC_Compiler_User_Guide` (126 pp) and
`Nintendo_64_S2DEX_Microcode_Users_Guide` (38 pp) were added as local reference. The first two carry a text
layer; **S2DEX is a scan with no text layer** and needs OCR before it is searchable. They are copyrighted
Nintendo documents, so like the ROM they stay **out of git** (`docs/*.pdf` is ignored); `ci.sh`'s tracked
artefact scan is unchanged by them.
