# M109 — driving the game through the debugger: the transport works, the input layer doesn't

Stopped at the owner's request. This note records what was measured before the stop, including one result
that is worth more than the experiment it came from: **ares' own input layer is why the controller dies**,
and it is measurable from the game side.

## The finding that explains the owner's controller

Inside a live N64 boot, stopped just after the per-frame SI read, the controller buffer reads:

```
80014fa0  ff 01 04 01 ff ff ff ff   ff 01 04 01 ff ff ff ff
80014fb0  ff 01 04 01 ff ff ff ff   ff 01 04 01 ff ff ff ff
80014fc0  fe 00 00 00 ...
```

Every one of the four channels carries `ff ff ff ff` as its response, which is the N64 "no controller"
pattern: the game is being told **no pad is plugged into any port**. Meanwhile macOS sees the pad:

```
hidutil list        -> 0x57e 0x2009 ... Bluetooth ... "Pro Controller"      (Nintendo, paired)
system_profiler     -> Pro Controller, Vendor 0x057E, Product 0x2009, HID ACL
```

So the controller is fine at the OS level and ares is feeding the game nothing. That is the whole of the
"works for a few seconds, then the character stops" symptom: it was never the pad, and it was not the
`Boot/*` settings (those were a separate, self-inflicted fault, below).

Also present in the system: a **virtual** pad `GamePad-1`, `Manufacturer: Microsoft`, which is *not* ares'
(it survives ares exiting) and is maintained by a LaunchAgent, `com.valvesoftware.steam.ipctool` (Steam's
IPC/input helper, running with no Steam client open; `kill` respawns it, and
`launchctl bootout gui/501/com.valvesoftware.steam.ipctool` returns `Boot-out failed: 3: No such process`
while the job stays listed). ares' port-1 binding is a single device id
(`0500d71f7e0500000920000001006803`, 46 bindings), so a binding that points at a shim which stops feeding
is indistinguishable from "the pad stopped working". Not proven which device ares bound — but the observable
fact above holds either way: **ares sends `ff ff ff ff`, and the game therefore reads no input.**

## The SI path, measured rather than assumed

`FUN_8000d1f0` is `__osSiRawStartDma` (it writes `0x1FC007C0` to `0xA4800010`). Breaking on its entry while
the game runs gives the live call:

| register | value | meaning |
|---|---|---|
| `a0` | `0` | direction: PIF -> RDRAM (the read that brings pad data in) |
| `a1` | `0x80014FA0` | the destination buffer |
| `ra` | `0x80006750` | the call site is `0x80006748`, so `0x80006750` is the first instruction after it |

`0x80016470` — the buffer named by `FUN_8000b4e0`/`FUN_8000aa10` — is **not** the live path: a breakpoint
just after that call (`0x8000b55c`) never fired in 10 s. The per-frame read is the one above, and stopping at
`0x80006750` puts us exactly where the buffer is filled and the game has not parsed it yet.

Buffer layout, from the response above: per channel 8 bytes = `ff | 01 04 01 | 4 response bytes`, so channel
0's pad data (buttons high, buttons low, stick X, stick Y) is at **buffer + 4**, and the four channels start at
+4, +12, +20, +28.

## What the debugger can do (all measured on this build)

* `M addr,len:hex` — **memory write works**; `X` (binary write) answers an empty packet, i.e. unsupported.
* `Z0`/`Z1`/`Z2`/`Z3`/`Z4` are all accepted; `c` stops with `S05` and a 568-byte register block.
* injection ran: at each stop at `0x80006750`, write 4 bytes at `buffer+4`, continue. **200 consecutive
  frames** completed this way — a held input is mechanically expressible.

## What is *not* established

**That the game acts on injected pads.** One observation was promising — after injecting
`00 10 00 00` for 60 frames the owner reported the screen changed — but `0x0010` is **R**, not Start
(Start is `0x1000`, i.e. `10 00 00 00`; A is `80 00 00 00`), and the title screen runs an attract loop, so
that observation is **not attributable**. The follow-up run (`10` neutral, `6` Start, `70` neutral, `6` A,
`108` neutral) was never observed. So the transport and the write path are established; the effect on the
game is not.

Consequence: **no room was reached**, and the open question (does any room's script make the game load a
bank-C record?) is exactly where M106 left it.

## Operational traps, all of them self-inflicted, all measured

* **`ares --setting name=value` persists into `~/Library/Application Support/ares/settings.bml`.** One launch
  with `Boot/AwaitGDBClient=true` leaves it on for every later launch, including a hand launch by the owner.
* **With `Boot/AwaitGDBClient=true` ares halts at `0xBFC00000`** (PIF ROM entry) with **RDRAM all zeros**;
  a client must connect and `c` before the game boots, and `c` without the await path does not start it.
* **With `Boot/Debugger=true` and no client at launch**, the same halt shape appears — a hand launch in that
  state looks like a frozen emulator with dead input.
* **A client that dies while the core is stopped wedges ares**: later `c` answers `S0b` (SIGSEGV) with the
  VI register frozen. Always `z0` and resume before closing; `watch`/`until`/`inject` do.
* Restored state at the end of this session: `Boot/Debugger=false`, `Boot/AwaitGDBClient=false`,
  `DebugServer/Enabled=false`, ares not running. The emulator is back to a normal, playable configuration.

## Where this leaves the project

The debugger is a working instrument (M108) and memory writes work (this note), but everything that needs a
**room** still needs someone to get the game into one, and ares currently cannot deliver input to the game at
all. The unblocked route is unchanged and does not involve the debugger: play in a normal launch, then
**Tools → Memory Editor → region `RDRAM` → `Memory` → `Export`**, and `tools/room_probe.py` /
`tools/walk_stream.py` answer from the dump in a second.

If ares' input is repaired (Settings → Input → Nintendo 64 → Controller Port 1 → Gamepad, bound explicitly to
`Pro Controller` rather than `Default`), the injection path in this note is ready to retry: the buffer, the
call site and the response offsets are all known, and the only missing piece is one observed button effect.
