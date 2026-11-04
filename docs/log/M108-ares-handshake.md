# M108 — the ares handshake: one byte, and then the whole machine

M107 ended on a specific negative: with `Boot/Debugger=true` and `DebugServer/Port=1984` the port binds,
but the stub answered **zero bytes** to `$qSupported#37`, `?`, `g`, `m…` and a bare `+`. Two candidate
explanations were left open (not RSP at all, or RSP that wants a halted core). Both are wrong. The stub is
full GDB RSP and it was hanging up on our **first byte**.

## The instrument

`tools/ares_rsp.py`, written for this question, so that a failure reports *which kind* of failure it is:

```
probe   connect, log any unsolicited greeting, `qSupported`, parse the reply, enable no-ack, `qThreadExtraInfo`
regs    `g` — length and raw hex, no invented layout
regmap  derive each register's size and offset by reading `p n` and concatenating
read    `m addr,len` with a hexdump
dump    8 MiB of RDRAM in 2 KiB chunks, optional byte-equality check against an existing dump
bp      `Z0`/`Z1`/`Z2` (exec / write watch / access watch)
until   set one breakpoint, continue, report the stop and the register block
cont    `c` or `s`
raw     one literal packet, for dialect exploration
launch  start ares with DebugServer/Enabled, Port, UseIPv4, Boot/Debugger
```

A read that returns 0 bytes is reported as **CLOSED** and a read that times out as **NO REPLY**. M107 could
not distinguish those two, and they mean opposite things (`$qSupported` was in fact CLOSED, i.e. actively
rejected — not ignored).

## The answer, from the shipped binary

The binary has symbols. `nm -arch arm64` lists `nall::GDB::Server::{onConnect,onText,updateLoop,onDisconnect,
resetClientData}`, and the reject message is referenced from `nall::TCPText::Server::onData` at
`0x1001ef1cc`:

```
1001ef1e8:  ldrb  w8, [x0, #0xc8]        ; firstDataSeen
1001ef1ec:  tbnz  w8, #0, 0x1001ef218    ; already seen -> go decode
1001ef1f0:  mov   w19, #1
1001ef1f4:  strb  w19, [x0, #0xc8]       ; set it
1001ef1f8:  ldrb  w8, [x20]              ; data[0]
1001ef1fc:  cmp   w8, #0x2b              ; '+'
1001ef200:  b.ne  0x1001ef248            ; -> "Non-GDB client detected (%s), disconnect client"
1001ef204:  ... virtual call [vtable+8]  ; -> GDB::Server::onConnect()
```

So the rule is: **the first byte ares ever reads from the socket must be `+`**. A client that opens with
`$qSupported#37` is classified as a non-GDB peer and the connection is closed — which is exactly the M107
observation, byte for byte. Sending one bare `+` before any packet fixes it:

```
[tx] +
[tx] $qSupported#37
[rx] +$PacketSize=4096;fork-events-;swbreak+;hwbreak-;vContSupported-QStartNoAckMode+;xmlRegisters+;qXfer:features:read+
```

(Note the missing `;` between `vContSupported-` and `QStartNoAckMode+` — the stub concatenates two
capability strings. A parser that splits on `;` gets `vContSupported-QStartNoAckMode` as one token; the
tool reports it as parsed rather than silently dropping it.)

`qXfer:features:read:target.xml:0,fff` → `l<target version="1.0"><architecture>mips:4000</architecture></target>`.

## What now works, measured

| operation | result |
|---|---|
| `qSupported` | answered, **`PacketSize=4096`** (so the largest safe `m` is 2048 bytes: the reply is hex-doubled) |
| 512 KiB `m` read | **0.4 s** wall clock for 512 KiB in 2 KiB chunks |
| full 8 MiB `dump` | **89 s**, `8 388 608` bytes, no GUI; `tools/room_probe.py` reads the result and reports its verdict ("predates a room load", correct for a boot-state machine), so scripted dumps are drop-in replacements for hand exports |
| `Z0,addr,4` | `OK` |
| `c` after a breakpoint on a **code path the game takes** | stop reply **`S05`** and the register block |
| `c` when the address is not reached | no stop; the breakpoint stays set until the connection closes |
| `g` | **568 bytes = 71 registers × 8 bytes** |
| `p n` | per-register reads, `n = 0…70`, each 8 bytes |
| live-ness | two `g` snapshots 2 s apart differ → **the machine runs**; `Boot/AwaitGDBClient=true` did not leave it halted |

`PacketSize=4096` is the one hard limit to respect; a 32 KiB chunk (what the draft used) would have been
silently truncated.

## Acceptance, and how it had to be restated

M107 fixed the test as: `qSupported` answered, then one **512 KiB `m` read byte-equal to the same range of
an existing hand-made dump**. The first half passes. The second half **cannot pass in a live boot state,
and measuring it says why**:

```
live 0x80000000..0x80080000  vs  …-132952.bin
  522 131 / 524 288 equal, 2 157 differing in 945 ranges, first difference at 0x800127cf
```

The first difference is exactly **one byte past the last ROM-copied byte**, and 945 scattered 1–4 byte
ranges after it are runtime state (zlib tables built at boot, stack, timers) — two different *moments*, not
a transport defect. A state-dependent test cannot distinguish a working read from a correct-in-the-aggregate
one, so the acceptance was replaced by a stronger, state-free one: compare live memory with the
**cartridge**, over the region where a dump is byte-identical to ROM.

```
ROM 0x1000 maps to vram 0x80000480            (found in a dump: rom[0x1000:0x1040] at file off 0x480)
live 0x80000480 + 0x1234f  vs  rom/*.z64 @ 0x1000
  74 575 / 74 575 equal, 0 differing
```

**74575/74575.** The read path is byte-exact against an artefact that does not depend on when it was read.
To make dumps that *are* comparable with the hand-made ones, the missing piece is Route B (`--save-state`),
not the protocol.

## The register file, derived rather than assumed

`g` is 568 bytes, which is neither 32×4 nor a clean MIPS set, so nothing about it was guessed:

* `p 0 … p 70` all answer with **8 bytes each**, and 71 × 8 = 568, so the file is uniform;
* the `p n` concatenation did **not** equal `g` at first — and the cause was mine, not the stub's: the
  `p` index is **decimal**, and `regmap` formatted it as hex, so `p10` read register 16. With `p%d` the
  mismatch disappears. The earlier reading ("expected, the two reads are different moments") was a
  rationalisation of a bug; see the addendum below;
* two stops at two different addresses isolate **index 37**: it held `0xffffffff80000518` and then
  `0xffffffff8000051c`, i.e. sign-extended 32-bit, and equal to the breakpoint address → **PC = 37**;
* index 4 held `0x054d442b` then `0x0550ab84`. The static decode of the stop's neighbour explains it:

```
0x80000518  rom 0x1098  1000ffff  beq $0,$0,-1      ; a spin loop, the branch lands on itself
0x8000051c  rom 0x109c  64840001  daddiu a0,a0,1    ; rs=4 rt=4, so register 4 is a0
```

so **index 4 = a0**, by two independent paths (an instruction that names register 4, and a live counter that
increments between stops). Indices 0–31 are therefore the GPRs; PC at 37 rather than 34 leaves three
registers between `lo` and PC that are **not yet identified**, and this note does not name them.

## What this changes for the project

Every remaining question in `docs/handover.md` needed a human to play into a room and click Export, once per
instant. That loop is gone: a dump is now one command, a register at a stop is one command, and the
"M107 experiment" — *watch `v0` at `0x80071eb0`* — is an `until` call away as soon as a room is loaded.

What it does **not** do: reach a room. The machine now boots and runs under GDB control, so the next
blocker is unchanged and is still the one that settles the original question — **a dump, or a breakpoint, in
a different room**. Route B (`--save-state slot` + `Paths/Saves`) is what makes that reproducible;
`Boot/AwaitGDBClient` and `Boot/Debugger` are separate switches and only the latter gates the listener.

## Addendum — the `p` index is decimal, and `--setting` persists

Two corrections found while using the tool, both cheap to state and expensive to get wrong:

* **`p n` takes a decimal index.** `p37` is PC; `p25` is register 25 (not 37). Verified: `raw p37` ->
  `ffffffff80000518` while stopped there, `raw p25` -> `0000000000000000`. Every `p` request in this tool
  now formats the index with `%d`.
* **ares' `--setting name=value` persists into `~/Library/Application Support/ares/settings.bml`.**
  Launching once with `Boot/AwaitGDBClient=true` leaves it true for every later launch, including one the
  owner starts by hand — and in that state ares runs a few seconds of boot and then **halts waiting for a
  GDB client**: the machine sits at `0xBFC00000` (PIF entry) with RDRAM all zeros and `c` alone does not
  release it. That is a live confounder for anything measured on a hand-launched ares, and it looks exactly
  like "the game froze / the controller stopped working". The settings a launch needs are therefore written
  down, not inherited: `Boot/Debugger`, `Boot/AwaitGDBClient`, `DebugServer/{Enabled,Port,UseIPv4}`.
* Consequence for the workflow: the machine is **running** while a client is attached and idle (measured:
  VI_ORIGIN flips across quiet windows), and it keeps running after a clean disconnect — but a session that
  ends while the core is stopped on a breakpoint can leave ares wedged (`c` then answering `S0b`, SIGSEGV,
  VI frozen). Always `z0` before closing, which `watch`/`until` do.
* `M` (write memory) is supported and `X` is not; `Z2`/`Z3`/`Z4` watchpoints are accepted. `FUN_8000d1f0`
  is `__osSiRawStartDma`, so controller bytes arrive in an **RDRAM** buffer that the debugger can overwrite
  — the basis for driving the game without the owner's hardware.

## Errors this note earned

* **`strings -t x` offsets on this universal binary are 0x4000 low.** `strings -a -t x ares` reported
  `qSupported` at `0xdd51f5`; the bytes are at `0xdd91f5`. Every offset taken from `strings` was wrong, and
  the first disassembly attempt searched the wrong place. Search the file for the bytes instead.
* **Apple's `/usr/bin/objdump` ignores `--start-address`, `--stop-address` and `--disassemble-symbols`** —
  it disassembles from the beginning regardless. The workable method is `objdump -d --arch=arm64` once into
  a file (122 MB, ~4 s) and then `grep` by address, with `nm -arch arm64` for the symbol boundaries.
* **A fat binary has two copies of every string.** `qSupported` exists at `0xdd91f5` (x86_64 slice) and
  `0x237d23b` (arm64 slice); only the second one is reachable from the code that runs on this Mac.
* **A passing "concat equals `g`" test needs a halted core.** On a running target it fails for a reason that
  has nothing to do with the protocol; state the precondition instead of the conclusion.
* **A hex reply that starts with `E` is not necessarily an error.** The first full dump aborted at
  `0x800a3000` because the four bytes there are `e4 82 00 54` (`swc1 f2,0x54(a0)`) and the client read a
  leading `E` as RSP's error code. RSP errors are `E` + **1–2** hex digits; anything longer is data. The
  guard is now a full match on `E[0-9a-f]{1,2}`, and the failure was caught only because `dump` refuses to
  write a short file.
* **The M107 acceptance test was state-dependent and would have been argued about.** Two moments of the same
  emulator differ in ~0.4 % of RDRAM, so "byte-equal to a dump" conflates transport with timing. Compare
  against the cartridge, or pin the state first.

## Reproduce

```sh
python3 tools/ares_rsp.py launch --rom "rom/Resident Evil 2 (USA) (Rev 1).z64"   # listener on 9123
python3 tools/ares_rsp.py probe                                                  # qSupported + features
python3 tools/ares_rsp.py --quiet read 0x80012150 32                             # "OVERLAYTABLENUM" + 0x43
python3 tools/ares_rsp.py --quiet dump /tmp/live.bin --base 0x80000480 --size 0x1234f \
        --expect "rom/Resident Evil 2 (USA) (Rev 1).z64" --expect-base 0x1000     # 74575/74575
python3 tools/ares_rsp.py --quiet until 0x80000518                               # S05 + registers
python3 tools/ares_rsp.py --quiet dump "rom/…-rdram-scripted-$(date +%Y%m%d-%H%M%S).bin"   # 8 MiB, 89 s
python3 tools/room_probe.py rom/*-scripted-*.bin                                 # the dump is usable
python3 tools/ares_rsp.py --no-lead-ack probe                                    # the M107 negative, on demand
```
