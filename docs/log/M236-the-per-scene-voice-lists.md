# M236 — the per-scene voice lists are in the image, and bit 15 proves it

M233 closed the six sound commands but refused the mapping: `0x59 XaOn` indexes a table at `DAT_8011a718`,
that address is **zero in the image**, and it is written at run time. That refusal was too pessimistic — the
*selection* is dynamic, the *lists* are static, and they were sitting in the image the whole time.

## 1. What `FUN_800762b0` actually does

```
DAT_8011a718 = *((&PTR_PTR_80119e20)[0x800e110c < 0] + DAT_800e8ca8 * 4 + 4)
```

`0x80119e20` holds two pointers — `0x80119de0` and `0x80119e00` — so the sign bit of the sound flag word picks a
**bank**, and `DAT_800e8ca8 + 1` picks an entry within it. Each entry is a pointer to a `u16` array. And
`FUN_8017b530` writes the same kind of thing as a literal, `0x80115440`, which is the **first** of those
arrays. So the base looked zero for the same reason a `switch` looks empty before you read the cases.

## 2. The lists

| | |
|---|---|
| banks | **2** pointer tables: `0x80119de0` with **16** pointers, `0x80119e00` with **8** |
| distinct arrays | **16**, from `0x80115440` to `0x801158ec` |
| lengths | **14 .. 84** entries (last one bounded by its `0xffff` sentinel) |
| entries | **674** non-zero, **8** skipped slots of exactly `0` |
| flagged 8 kHz | **38** |

The second bank's eight pointers are all in the first bank's sixteen — it re-uses the tail, so the two banks
are views over one array region rather than two copies.

## 3. Why these are clip indices and not offsets

Three independent facts, and the third is the one that decides it:

1. masking bit 15 leaves every one of the 674 values below **588**, the size of the MORT bank — `0`
   unresolved;
2. the lengths and totals are those of a *cue list* (14–84 entries, a handful of skips), not of an offset table
   (no entry is ascending within an array, which an offset table's would be);
3. **bit 15 predicts the target clip's own declared rate on 673 of 674 entries.** `0x8000` means 8 kHz, and
   the MORT record's own `u16@+6` (M194) agrees: **38 at 8 000 Hz, 636 at 16 000 Hz, 1 disagreement**. That is
   not a resemblance between two numbers — it is one field predicting another across 674 samples of an
   independently-parsed structure.

**The one exception is named, not smoothed**: at `0x801158ec` index 64 the entry is `0x003d` — clip **61**
*without* the flag — while clip 61's record declares **8 000 Hz**, and the same clip appears as `0x803d`
*with* the flag in the first array. So bit 15 is the rate the *caller* passes (`FUN_80004a6c` chooses it), and
it agrees with the record 673 times; whether the loader would have preferred the record on the 674th is not
decidable from these bytes.

## 4. The chain, end to end

```
0x59 XaOn(byte, idx)        the script command; the byte is dead (M233)
  -> list[bank][idx]        the u16 at DAT_8011a718 + 2*idx
  -> clip = entry & 0x7fff, rate = entry & 0x8000 ? 8000 : 16000
  -> MORT record            cartridge id 1979, 588 records
  -> PCM                    voice_decode.transcribe(), M194-M199
```

Verified on the default list's first entry: `0x803d` → clip **61**, 194 blocks, **31 040 samples**, rate
**8 000** by flag and by record. So "voice clips → script events" is now a chain of measured steps rather than
a hope, and the three milestones it took were M233 (the command), M194–M199 (the codec) and this one.

## 5. What is not claimed

- **Which scene uses which list.** The selection is `DAT_800e8ca8 + 1`, and what writes that index is a
  run-time value — `0`, `2` and `0x1c` appear in the corpus — that this project has not tied to a room number.
- **That "scene" is "room".** The two banks might be two scenarios, two halves of one, or something else.
- **What a clip sounds like**, or which event triggers a given entry.
- **That the absent 48 means anything.** The backlog's "per-room 48-record sound table" does not appear here
  either: the lengths are 14, 16, 22, 30, 34, 42, 46, 52 (×2), 54, 60, 66, 72, 84 — 48 is not among them, and
  22/52/60 repeat. Whatever the requirement described, it is not these lists, and it is not the record-table
  family of M234.

## 6. The tool

`tools/voice_lists.py` → `manifests/voice_lists.json`, **9 cases**, 3 mutations: bit 15 stops selecting the
rate, the index mask widens, and the last array is bounded by the region constant instead of its sentinel.
That last one is the defect this file shipped for one run: bounding the final array with `0x80115a00` reported
**138** entries for an **84**-entry array, because the constant was the tool's assumption rather than the
data's. The length is now derived two ways and the artefact says which — `pointer distance` for fifteen arrays,
`sentinel 0xffff` for the last.
