# M234 — the record-table families: two script ranges, one undecoded container, and no 48

The audio backlog left three questions open: which records the `DOOR_SCD` name covers, what the id families at
3379+n and 3504+n are, and whether a per-room **48-record** sound table exists. The first two are one question
about a container shape. The third is answerable, and the answer is no.

## 1. The shape, and why it is not a guess

A block whose head is a `u16` offset table is **self-describing**, because its first entry is the table's own
size:

```
u16 end       == 2 * count          the table ends exactly where it says it does
u16[count]    offsets, offsets[0] == end, strictly ascending, all inside the block
```

That makes the count a *derived* number rather than a stored one. It is also the rule `walk_stream.py`
already used: M146's tool walks id 1881 from `0x80400018`, and `offsets[0]` for 1881 is `0x12` — the same
address. So the container was already known; what was not known is that it is a **signature** with exactly
two homes, and that the first entry doubling as the size is what makes it one.

`end/2 - 1` is the error this file made first: it reads the same table one entry short, which shifts every
record boundary and reports 246 members instead of 245. It is now the first mutation.

## 2. Where the shape occurs

Scanning all **7 978** real entries (113 sentinels skipped) for the shape finds two ranges and nothing else:

| range | members | records | record 0 |
|---|---|---|---|
| **1881–1927** | **47** | 462 | `0x13 Switch` on **47 of 47** |
| **3504–3708** | **198** | 3 158 | `0x06` ×88, `0x18` ×59, `0x2c` ×13, `0x2d` ×10, … (14 distinct) |

The threshold is a measurement, not a definition, so both values are published: at **floor 3** the signature
admits 245 members and **0** outside those two ranges; at floor 2 it admits 256 and **4** outside
(`1928`, `1929`, `1930`, `3462` — the first three adjacent to the first range, with two plausible records
each). Floor 3 is where the signature stops matching anything else.

## 3. The second range is scripts, not a look-alike

Offsets alone do not make something a script. Every record entry in both ranges begins with a byte **below
141** — the opcode space `walk_stream.py` accepts:

| range | valid entry bytes | |
|---|---|---|
| 1881–1927 | **462 / 462** | 100 % |
| 3504–3708 | **3 158 / 3 158** | 100 % |

If those bytes were uniform the chance of that is `(141/256)^3158 ≈ 10^-827`. So the second range is the
same kind of object as the first — a block of script records. And the two differ in a way worth stating:
**the first range's record 0 is always `0x13 Switch`**, which is exactly what M146 decoded by hand for id
1881; the second range's record 0 is spread over 14 opcodes and `0x13` never appears there.

**What selects the second range is open.** No room-table id points into it, nothing in the corpus names those
ids, and the 47 first-range ids are all of `1881..1927`.

## 4. `DOOR_SCD` against the room table

`DAT_80131fa8` holds **147** distinct ids (M145, bound 256 by M156). Measured against the signature:

- **47** are record-table members — all of `1881..1927`, exactly;
- **100** are not, and the sampled ones are **not broken scripts but different objects**: `1928`/`1929` are
  88-byte stubs (`0x0004 0x0042 …`) and `1950`/`1978` begin `0x0141 0x0000`, the `01 41` container
  `tools/container_0141.py` already decodes.

So the name covers the room table's ids, and only the first 47 of them are blocks of this shape. The rest of
the room list is containers — which is consistent with the room loader treating the block as a whole rather
than assuming one format.

## 5. The 3379 family

**71** members, ids **3379–3503**, every one beginning with the same 8 bytes
`0002 3b00 0131 0000`. They are contiguous with the second script range on either side (3379–3503, then
3504–3708) and **none of them is a room id**. What the format is, is not decoded here: the head is invariant
across all 71, the bodies carry ascending `0x67xx`-tagged records, and that is as far as this milestone reads.

## 6. The 48

The record counts across all 245 members run **3..54** with **9** the mode (23 members), and **48 does not
occur**. The same is true of every sound structure already published: `snd_proj` has 6 lists over 417
records, `snd_macros` 327 sequences of 2..13 elements, `voice_descriptor` 2 slots. **No "per-room 48-record
sound table" exists in any structure measured so far.** That is a refusal about this cartridge, not a
correction of whoever wrote the requirement — a sound table of some other shape is not excluded by a test
over this one.

## 7. The tool

`tools/asset_families.py` → `manifests/asset_families.json`, **11 cases**, 3 mutations: the count rule read
one low, the floor dropped to 1, and the opcode ceiling dropped to 64. One defect of my own was caught while
writing it — the artefact-equality case compared a fresh derivation to the committed file and failed on **key
order alone**, because `json.dumps` sorts integer keys numerically and string keys lexicographically. The
comparison now round-trips both sides through JSON; the sorted-ness of a dict is not a fact about the
cartridge.

Not claimed: what the 3504..3708 range is *for*; what the 3379..3503 head means; that a record table implies
script bytes for every member (the entry-byte test is evidence over 245 blocks and 3 620 records, not a
decode of each); and that no other shape could hold a 48-record table.
