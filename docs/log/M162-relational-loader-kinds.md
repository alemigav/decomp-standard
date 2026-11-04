# M162 — relational: the family is what the *model* loaders load

The corpus-wide comparison the last milestone called for is done, and it answered the question without guessing at
semantics. The `01 41` family is referenced by the **enemy-model and model loaders**, and is distinct from the
other resource kinds — which puts the texture reading back on the table, by a route that has nothing to do with
display lists.

## 1. The loader's tag vocabulary, read from `.rodata`

Every call to `func_0x80004cfc(id, dst, flag, tag)` passes a tag string. Reading them out of the image at the
addresses the call sites use:

| address | tag | address | tag |
|---|---|---|---|
| `0x800b8f64` | `TM3` | `0x800b925c` | `room` |
| `0x800b867c` | `EMD` | `0x800b9264`–`0x800b9298` | `RID FLR SCA RVD LIT SCD PR2 BLK E64 MSG OMD EDT` |
| `0x800b8700` | `EFF` | `0x800b9dcc` | `T64` |
| `0x800b8934` | `TIM` | `0x800b99cc` | `ITP` |
| `0x800b8680` | `SABUN` | `0x800b8e30` | `NEMESIS` |

The room-section list is the RDT vocabulary M137/M138 expected from the other direction, now confirmed in this
port's own strings.

## 2. Which kinds reference the family

Three tables are indexed by the *same* object-type byte (`*(byte *)(param_1 + 8)`), so sampling them says what
each kind's blocks look like:

| loader table | tag | blocks sampled | `0x01410000` (family) | other |
|---|---|---|---|---|
| `0x8010dba0` / `0x8010dbc0` | **TM3** | 40 | **16** | `0xf95f0000`, `0xf972ffde` |
| `0x80126c80` | **EMD** | 29 | **25** | `0x00400000` |
| `0x800ebb30` | **EFF** | 40 | **0** | `0x09000800`, `0x0b000a00`, `0x24002000` |
| `0x8012bec0` | **ITP** | 40 | **0** | `0xe3e3e3e3` **in all 40** |
| `0x8010dbe0` | (third parallel) | 32 | 0 | `0xf972ffde`, `0xf95f0000` |

So the family **is** what the model loaders load: **EMD (enemy model) 25 of 29**, **TM3 (model) 16 of 40**. And it
is cleanly *not* EFF or ITP — ITP being the most striking, all 40 of its targets starting with a uniform
`0xe3e3e3e3` run, which is also exactly what the constant-id `"MIX ITP"` load looked like (M161 §1's neighbour).

## 3. What that means, stated carefully

* It **rehabilitates part of** the earlier texture reading: a resource that both enemy and player/weapon models
  load is, on any reading of this engine, **texture data for those models**. M161's refutation of the
  *display-list* hypothesis stands untouched, and so does the refutation of a *clean RGBA5551* payload — this is a
  texture in some other packing, not a display list and not simple 16-bit RGBA.
* It **does not** claim the packing. What is now pinned is the *role*: the 355 blocks are the model loaders'
  textures. The payload/record split is a property of that kind.
* The ITP result is a real elimination: a kind whose targets uniformly begin `0xe3e3e3e3` cannot be the same kind
  as one whose targets begin `0x01410000`, and the family is not ITP.

## 4. Gate

`01 41 container` is now **15 cases**, four of them relational: EMD references family blocks, TM3 references family
blocks, and ITP and EFF reference **none**. The audit gained an entry that swaps the ITP table for the TM3 one,
so the "ITP references a different kind" case fails when the relation is broken — **15/15 audits, 0 vacuous**.

**169 cases across 17 fixtures**, `ci.sh: ok`, 18/18 marker checks.

## 5. What is still open, precisely

The packing, and the record semantics — but the search space has collapsed from "unknown data" to "a texture
format loaded by `FUN_80055574` next to a `TM3` model". `FUN_800824b8`, `FUN_800874d4` and `FUN_80087868` are
called on the loaded buffer in that function; reading *them* is the next step, because a texture decoder names its
own format: whatever those three do to the payload tells us whether it is indexed, tiled, or RLE, and what the
`N` records at the head are for.
