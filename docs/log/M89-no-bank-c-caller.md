# M89 — there is no bank-C caller

**RETRACTED (M91): the reader exists at `0x80032a5c`.** The loader selects between the two maps
with `s4 = s0 << 2` and reads `*(s4 + 0x800eb264)`, so `s0 != 0` reads pointer #2 — bank C's map.
The four closure checks below were all true of the shape `find_readers.py` could see
(constructed base + immediate) and blind to base + register. Read this note as the record of how
that closure failed, not as the finding. The answer to the question is a negative, and it is a clean one.** The pointer to the only map that
selects bank C's records is **never read by any code in the cartridge**.

## 1. The question, made precise

Bank C's records are reached only through `byte[slot-16]`, and there are **two** maps, pointed at by
two consecutive words:

| word | points to | values | which records |
|---|---|---|---|
| `0x800eb264` | `0x800eb204` | 11 … 38 | **bank B** (dest `0x80161cf0`) |
| `0x800eb268` | `0x800eb234` | 39 … 66 | **bank C** (dest `0x8016e880`) |

That alignment is exact on both sides, which is itself the confirmation that the map reading is
right: indices 11–38 are precisely the records whose destination is `0x80161cf0`, and 39–66
precisely those whose destination is `0x8016e880`.

## 2. The scan

`tools/find_readers.py` answers "who touches this address" as a tool rather than as another heredoc —
a forward abstract pass per image, with memory accesses resolved only when the base register holds a
constructed constant, and each hit attributed to its enclosing function.

```
$ ./find_readers.py 0x800eb260 0x800eb270
1 access(es) to 0x800eb260..0x800eb270 across 36 images
      stage2 0x800329e4  lw    v0, -19868(v1)  -> 0x800eb264   in 0x8003287c
```

One access, and it is the one already traced. `0x800eb268` has **no access at all**.

Two follow-up checks close the ways a reader could still exist outside a constructed base:

| target | constructed as `lui`+imm | present as a 32-bit word |
|---|---|---|
| `0x800eb264` (pointer #1 slot) | **1** (`0x800329e4`) | 0 |
| `0x800eb268` (pointer #2 slot) | **0** | **0** |
| `0x800eb204` (array 1 base) | 0 | 1 — the word at `0x800eb264` |
| `0x800eb234` (array 2 base) | 0 | 1 — the word at `0x800eb268` |
| `0x800eb26c` ("d:/bio2/…" string) | 0 | 0 |

To read `0x800eb268` a program must either **construct** it (0 sites) or **load** it from a place it
was stored (0 occurrences anywhere), or derive it as `0x800eb264 + 4` — and the single site that
loads `0x800eb264` goes straight to `addu v0,s1,v0` / `lbu a0,-16(v0)` without touching `+4`.

So: **no bank-C caller exists in the mapped code.** Bank C is never loaded.

## 3. What that means

* **Bank C is dead data.** 28 well-formed records, a populated map, a destination bank installed by
  an initializer — and nothing reads the pointer to the map that selects them. The data is not
  mysterious because it is exotic; it is unreachable.
* **The codec question for R4 is moot.** M86/M88 worried that a record with `stored < span` takes the
  inflate branch on non-zlib bytes. That cannot happen, because no record 39–66 is ever passed to the
  loader. Nothing needs to decode bank C for the game to run.
* **It explains the earlier oddities** rather than leaving them as anomalies: bank C's payloads have
  decompressed sizes identical to bank B's (a parallel bank built for the same slot family), tile
  exactly, and use a different container (built or packed by a tool whose output this build never
  consumes). The "second staging bank" is a build-time artefact, like the unused
  `d:/bio2/prog/em00_0.bin` path string next to it.
* **The one record that *is* reachable** is index 38 (parser slot 37 — see §4), the *last* of bank B,
  via slot 63. Bank C contributes nothing reachable.

## 4. Numbering correction, carried by every earlier note

`cart_record(i)` returns `0x80012150 + i*16`, so **index 0 is the `OVERLAYTABLENUM` header**, index 1
is the first real record, and index 67 is the `0xCDCDCDCD` slot. `read_overlay_table.py` numbers the
*valid* records from 0, so:

> **parser `slot` = `cart_record` index − 1**, throughout M81–M88.

So "bank C is parser slots 38–65" is **records 39–66**, and "bank B is parser slots 10–37" is
**records 11–38**. Verified directly: `cart_record(11)` = cart `0x7fc12` (bank B's first),
`cart_record(38)` = cart `0xb6040` (bank B's last), `cart_record(39)` = cart `0xb6248` (bank C's
first), `cart_record(66)` = cart `0xc85e8` (bank C's last).

Both statements were true all along; the labels differed, and one of them said "38–65" where the map
says "39–66". The map alignment in §1 is only visible once the offset is applied, which is why it
went unnoticed.

## 5. What is still not established

* **The negative is scoped to this cartridge's mapped code.** A path in code we have not mapped (the
  61 KB of code-like gap) could in principle read `0x800eb268`, but it would still have to construct
  or load it, and neither happens anywhere in the 1.95 MB of code the corpus contains.
* **Why bank C exists at all** is a build-history question, not a code question. The parallel sizes
  and the PSX path string beside the maps point at a build or platform variant.
* **Bank B's own loader is now the interesting one** — the records 11–38 path is live, and it is the
  one the scene slot feeds.

## 6. Next

1. **Stop treating R4's tail as a codec problem.** It is one staging bank of a two-bank design whose
   second consumer does not exist here. That closes the thread opened in M82.
2. The live question is bank B's slot selection: 27 slots select records 11–38, and the slot byte at
   `*(0x80115284)+3` is written from a heap object (`M88` §4). The harness — now with correct signed
   loads — is the instrument.
