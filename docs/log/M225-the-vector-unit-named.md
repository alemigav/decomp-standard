# M225 — the vector unit, named: 252 of 254, and the two that stayed refused

Step 3 of the RSP cycle. M223 refused to name the vector unit's 254 words; M224 narrowed the policy that
made the refusal automatic. This applies it: **252 of the 254 words now carry a cited mnemonic**, the two
`lwc2`/`swc2` misreads are corrected in the decoder that made them, and the arithmetic turns out to be
describable in the source's own terms. What it does not do is decide the ucode's identity — and the table
that was supposed to decide it is now the measurement that *refutes* the candidate it was meant to confirm.

## 1. The table arrived, and the words resolved

The N64brew Wiki's `Reality_Signal_Processor/CPU_Core` page (revision 5539, CC BY-SA-4.0) carries the
vector-unit instruction tables. Applied to the 211 non-transfer vector words:

| group | words | what M223 could say | what it says now |
|---|---|---|---|
| multiply | 48 | `funct` raw | `vmulf` 15, `vmudl` 3, `vmudm` 4, `vmudn` 15, `vmudh` 11 |
| multiply-accumulate | 68 | `funct` raw | `vmadh` 56, `vmadn` 10, `vmadm` 2 |
| add | 47 | `funct` raw | `vadd` 37, `vaddc` 10 |
| bitwise | 24 | `funct` raw | `vxor` 16, `vand` 8 |
| accumulator read | 10 | `funct` raw | `vsar` |
| lane move | 8 | `funct` raw | `vmov` |
| select / merge | 4 | `funct` raw | `vlt` 2, `vmrg` 2 |
| **refused** | **2** | `funct` raw | **still raw: the table has no row for `funct 0x11`** |

Plus the 43 `mtc2` moves, which are no longer "unresolved": the table gives `vs_elem` (bits 10:7) as a
**byte offset into the vector register**, not a lane index, so `mtc2 a1,v10` now reports which byte it
writes. That is the whole change: the artefact's `unreadable` list went from **31 groups / 254 words to 1
group / 2 words**.

The two refusals are the point as much as the 252 names are. **The source documents what it documents**,
and `funct 0x11` — which this cartridge executes twice, at `0x480` and `0x1b0` — is not in it. It is
listed with its reason and not filled in from anywhere else.

## 2. The arithmetic, in the source's own words

Naming the instructions buys a description of the mixer that is not an adjective. The formats the source
gives each multiply opcode, weighted by the words this program uses:

| fixed-point format | words |
|---|---|
| S0.16 × S0.16 (`vmudh`/`vmadh`) | **67** |
| U0.16 × S0.16 (`vmudn`/`vmadn`) | 25 |
| S1.15 × S1.15 (`vmulf`) | 15 |
| S0.16 × U0.16 (`vmudm`/`vmadm`) | 6 |
| U0.16 × U0.16 (`vmudl`) | 3 |

116 of the 211 words multiply or multiply-accumulate, 10 read the accumulator back out (`vsar`), and the
rest are adds and lane moves. Saturating is not a separate instruction — the multiply opcodes clamp on
extraction, as the cited page states — so a stage's headroom is decided by which format it is given, which
is exactly what this table reports.

That is a **description of the units, not of the mixer.** A name says which opcode runs, not which signal
path it serves; the structure is in how the accumulator is used across the frame loop, and no document
here describes that. The `rsp_only` entry was rewritten to say precisely this, because "unnamed" is no
longer the reason.

## 3. Two source defects, recorded rather than smoothed

1. **`0x01` cannot be both.** The transpose group lists `0x01 swv`; the scalar group lists `0x01 lsv/ssv`.
   One opcode, two rows. Nothing here depends on which is right — no transpose-group word appears in this
   program — so it is recorded (`external_sources.table_defects`) and left alone.
2. **The computational table has gaps.** It lists 22 opcodes out of a 48-code space; `0x11` is one of the
   holes and this cartridge uses it. The gaps are what make two refusals honest rather than lazy.

A third defect is mine and was caught by the gate: **one of my mutations was a no-op.** I anchored the
lane-selection mutation on the `vt_elem`/`vd_elem` borrow branch — and every one of this program's eight
single-lane words carries `vt_elem = 12`, whose top set bit is above the borrow region, so flipping the
branch changes nothing. `--lint` cannot see that; only running the mutation and finding exit 0 can. The
anchor now targets the destination-lane mask (`de = vd_elem & 7` → `de = vd_elem`, 5 of 8 words wrong), and
the borrow's unexercised status is **published in the case itself** so nobody reads a passing gate as proof
of it. This is the M220 vacuous-mutation defect met a second time, and it is now a stated property of the
case rather than a trap for the next reader.

## 4. The `lwc2`/`swc2` correction lands where it was made

M224 published the corrected field split in `rsp_iface.json` and said plainly that `rsp_ucode.json` still
carried M223's version. That is now closed: `rsp_decode.py` decodes base / vt / **row (15:11)** /
**element (10:7)** / **offset (6:0, scaled by the row's access size)**, so

```
M223:  e8232000  swc2 v3,8192(at)          <- 0x2000 read as a 16-bit displacement
now:   e8232000  sqv  v3,0(at) [element 0, x16]
M223:  c8a52801  lwc2 v5,10241(a1)
now:   c8a52801  lrv  v5,1(a1) [element 0, x16]
```

All 125 words now carry a row from the cited table — `ldv` 39, `sqv` 26, `ssv` 20, `lqv` 19, `lrv` 14,
`sdv` 4, `lsv` 2, `llv` 1 — and `dmem.excluded_cop2_transfers` is replaced by `vector_transfers` with the
per-row counts and the note that the absolute addresses need the base register's value, which is folded in
`rsp_iface.json`. `rsp_iface` no longer re-parses the word for this: it reads `vu_row`/`vu_offset`/`vu_scale`
from the decoder. Two parsers of one field is how M219 went wrong, and there is now one.

## 5. What the table decided: not the identity, and against the first candidate

M223's first `what_would_decide` item was *"an RSP encoding table this repository could cite: it would name
the 254 vector words and the COP0 registers, and the `jal` fan-out at `0x3c`-`0x2e0` would read as a command
switch."* The table arrived. Both halves of the prediction are now measurable, and the answer is recorded as
evidence **E8**:

* the words are named, and the COP0 registers are named (M224);
* **the `jal` fan-out does not read as a command switch** — M224 measured that the program contains no
  computed transfer at all.

So the candidate this table was fetched to confirm is **refuted on the shape it predicts**: the libaudio
ABI predicts a command list the ucode dispatches on, and this program dispatches on nothing. Its third
prediction — "work items read through DMEM structures the CPU filled" — is the one still standing, and it
is exactly what M224 found (two 0x50-byte parameter records, double-buffered). The verdict stays
`unresolved`: an ABI can be re-fronted, and MusyX was never tested either way.

That is the honest shape of a "what would decide this" list: it was answered, and the answer was not the
one the list was written hoping for.

## 6. What this still does not claim

* **Not what the mixer does.** §2 names the units. The signal path — which stage filters, which sums, which
  clips — is not in any document this project holds, and 173 words of the program remain unreachable by any
  edge this model knows (M224).
* **`vsar`'s portion mapping.** The cited page says the accumulator is 48 bits per lane, names its three
  16-bit portions (`ACCUM_LO`/`MD`/`HI`), and says `vsar` extracts one of them — but does not state which
  element value selects which portion. All 10 `vsar` words are named and their element field is reported
  raw; the mapping is **not** asserted.
* **Not that the names are right because they are cited.** They are right in the sense that a cited source
  says so; that is weaker than a measurement, and stronger than nothing. The two mutation-proofs in §3 are
  what tie the *decode* to the citation rather than to itself: the access sizes are restated independently
  of the table that produced them, so a table edit cannot agree with itself.

## 7. Gates

`rsp ucode (cartridge)`: **18 → 22 cases**. Three new ones, each re-deriving rather than re-reading: the
transfer row/offset/scale against an independently stated access-size table, the single-lane
source/destination lanes against the cited rule (with the unexercised-borrow property published), and the
arithmetic census's own accounting (`by_kind + moves + refused == vector`). Three mutations, all proven to
fail their own case in a throw-away copy before the commit — after the first attempt proved to be a no-op.

One defect found while wiring them: `rsp_decode.py` **crashed** instead of failing when the corpus was
absent (`corpus_functions()[UCODE_VA + foff]` → `KeyError`). A gate that raises has stopped being a gate;
it now uses `.get` and says "no corpus function starts inside the window". A clean checkout of `tools/` and
`manifests/` alone can no longer make it throw.

**And the M224 defect recurred, in my hands, one milestone later.** M224 found `acceptance.py` pinning the
audit at 107 while it ran 109, fixed it by typing 112, and wrote a paragraph about assertions that only one
entry point exercises. M225 then added three anchors and left the 112 standing, so the real total is **827
cases, not the 824 the pin derived** — caught by `ci` reporting 712 and the audit reporting 115, which only
reconcile at 827. The lesson was recorded and the *habit* was not changed, which is the difference between a
retraction and a fix. The pin is now **derived** (`acceptance.py` imports `audit_gates` and reads
`len(AUDITS)`, because one audit is one case), so adding an anchor can no longer leave a number behind.
A typed expected count is not an assertion; it is a thing to remember, and this project has now forgotten it
twice.
