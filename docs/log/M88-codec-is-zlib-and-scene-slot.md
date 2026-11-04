# M88 — the codec is zlib after all, and the scene slot traces to a heap object

## 1. The codec question, read rather than deferred

The audit was right that `0x80004550` answered a different question; the decompressor is
**`0x800045dc`**, and reading it settles the matter in one of the two directions it named — the one
that does **not** dissolve the mystery.

`0x800045dc`, from the boot bank:

```
addiu sp,sp,-0x20 ; sw s0,0x10(sp) ; s0 = a0
lui a1,0x8001 ; addiu a1,a1,6240          -> a1 = 0x80011860
ori   v0,zero,0x8000 ; sw v0,16(s0)       -> state->window size = 0x8000
sw a1,68(s0) ; sw a2,80(s0) ; sw a3,60(s0) ; sw a3,72(s0)
addiu a2,zero,56 ; jal 0x8000319c         -> version check(state, "…", sizeof(z_stream) = 56)
jal 0x8000472c                            -> the state machine's first step
```

and `0x80011860` is **text**, not a table:

```
31 2e 30 00 …  31 2e 30 00  69 6e 63 6f 6d 70 61 74 69 62 6c 65
"1.0"     …    "1.0"        "incompatible version"
```

That is zlib's version/`z_errmsg` block, and the call with `a2 = 56` is `inflate`'s
`stream_size != sizeof(z_stream)` check. Combined with what M9 already established — the 0x8000
window at `state+0x4c`, the `inflate.c` error strings in the same image, and every decoded stream
starting `68 de` with `(0x68*256+0xDE) % 31 == 0` — the answer is:

**The decompressor is stock zlib, and the harness's `zlib.decompress` hook is faithful.** That hook
had never been checked against the ROM; it is now, and it holds.

Which means the audit's other branch does **not** apply: bank C's bytes have no zlib header at all
(`02 23 18 00…`, where zlib requires `CM == 8`), so this function would reject them with
*"unknown compression method"*. **Bank C therefore does not go through the inflate branch.** The
paradox is not "the codec is custom"; it is "these records are not loaded here."

One naming correction while it is cheap: `0x80004550` allocates the `0x8000` window and zeroes
state fields — it is the init half — and `0x800045dc` is the engine entry that performs the version
check and runs the state machine. The notes' "inflate_init at 0x80004550, inflate at 0x800045dc"
is right in role, and M86's "reads no header and makes no decision" applies to `0x80004550` only.

## 2. The cross-check the audit asked for: `FUN_80001180` has no branch at all

```
0x80001180  sll  a0,a0,4
0x80001184  lui  v0,0x8001
0x80001188  addiu v0,v0,0x2150
0x8000118c  jr   ra
0x80001190  addu v0,v0,a0
```

It is pure address arithmetic — `index*16 + 0x80012150` — with **no test of any field**. So there is
no second consumer with a competing reading of the record: `FUN_800327ec` is the only code that
interprets `[0]`/`[1]`/`[8]`/`[12]`, and its branch test compares the stored size against
`vram_end − vram_start`, which is exactly M8's field meaning. The layout is confirmed by its only
interpreter, and branch 1 is genuinely dormant (`stored == span` for 0 of 66 records; `stored == 0`
for slots 5, 7, 8).

## 3. Two wrappers, one codec — the reconciliation

Both "inflaters" in the model are wrappers over the same three primitives:

| wrapper | callers | primitives, in order |
|---|---|---|
| `FUN_8004cbf4` (M16, registry slot) | `FUN_8004cc5c` | `inflate_init` → `inflate` → `inflate_free` |
| `FUN_800327ec` (M85, scene slot) | `FUN_8003287c` ×2 | `inflate_init` → `inflate` → `inflate_free`, **plus** a plain-path `0x800888ec` call |

So they are not rivals: they are two slot families sharing one decompressor. `FUN_800327ec` is the
richer one — it carries the `stored == span` plain path — and `FUN_8004cbf4` only has the
`stored == 0` early exit. Nothing in the model is dormant here; the "which is the loader" question
was a false dichotomy.

## 4. The scene slot byte: traced to its static limit

The chain is:

```
0x80071e50  lw   a0, 0x1c(s5)      ; a0 = a heap object's field
0x80071e54  slti v0, v0, 3         ; guarded by a counter < 3
0x80071e58  beq  v0, zero, +9      ; (skip when the counter has reached 3)
0x80071e5c  sw   a0, 0x5284(v1)    ; *(0x80115284) = that pointer   [v1 = 0x80110000]
        …
0x80071eb8  lw   v0, 0x5284(s1)    ; reload it
0x80071ebc  lbu  a0, 3(v0)         ; slot = byte 3 of the object
0x80071ec0  jal  FUN_8003287c
```

**Exactly one writer** exists in 36 images — `0x80071e5c` — and it is conditional. The pointer comes
from `s5+0x1c`, a **heap object**, so byte 3 of it is not in any image and cannot be enumerated
statically. That is where static analysis stops, and saying so is more useful than a guess: the
slot is a runtime value.

What *is* now known exactly is the condition to watch. Records 38–65 are selected by:

| map | slots that select a record in 38–65 |
|---|---|
| `0x800eb204` (bank B's half) | **slot 63 → 38** — one slot |
| `0x800eb234` (bank C's half) | **27 slots: 16, 32–49, 51, 52, 54–56, 58, 59, 62 → records 39–65** |

So bank C's records are reachable, but only through the second map and only from those slots. Nothing
yet shows the game selecting one; nothing shows it cannot. The instrument is the harness — now with
signed loads — reading byte 3 of the object at `*(0x80115284)` at the call site.

## 5. Fifth boundary error, same class, and the tool caught its own gap

`0x80011860` initially refused to resolve: `vaddr.py`'s boot source stopped at the end of the boot
*code* (`0x800115C0`) and did not cover the boot **data** that follows it in the same ROM range. So
the tool that exists to prevent hand-composed addresses had a boundary too narrow to be useful — and
it failed honestly, with a `LookupError`, instead of silently returning zeros. Fixed to
`ROM 0x1000..0x14420`, with the reason written into the source.

That is the fifth instance of the class, and the first where the failure was an exception rather than
a plausible wrong answer. That difference is the whole argument for the tool.

## 6. Housekeeping the audit asked for

* **`step`/`run` contracts documented** in `mips_harness.py`: `step` does not advance `pc` (the caller
  owns delay-slot arithmetic), `run` rezeros `r` and sets `ra = SENTINEL` (pass arguments, do not poke
  registers). Both traps produced plausible-wrong answers for me; the docstring is cheaper than the
  hour.
* **Retraction recorded in M86**: the "40-byte array with 30 distinct values and 2 in 38–65" reading
  is superseded — the structure is **two 48-byte arrays**, indexed `byte[slot−16]`, covering record
  indices 11–38 and 39–66, and the earlier numbers came from reading one pointer's target as if it
  were the whole map.
* **The 57→46 alias**: `beql s1,57` with `addiu s1,46` in the delay slot, i.e. slot 57 is remapped to
  46 before the index is taken. Two scene slots sharing one record is a legitimate asset-sharing
  pattern; the mechanism is now stated rather than the alias merely reported.

## 7. Next

1. **The other map.** `0x800eb268` holds the second pointer (`0x800eb234`) and no traced code loads
   it yet. Finding that reader names the bank-C caller, which is the last structural hole before the
   slot becomes a runtime question.
2. **Then the harness**: read `byte 3` of `*(0x80115284)` at `0x80071ec0` and see whether it ever
   lands in the 27 slots above.
3. The probe matrix needs no re-run: it never depended on loads, and its negatives stand.
