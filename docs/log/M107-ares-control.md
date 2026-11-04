# M107 — controlling ares directly (design)

## Why this is the next move

Every open question left in `docs/handover.md` has the same shape: *a runtime value that only exists while
the game runs*. Today each one costs a human action — play into a room, then Tools → Memory Editor →
region RDRAM → Memory → Export — and returns **one instant**, with no way to set a breakpoint, read a
register, or observe a transition. That is why the last five dumps only produced five instants of one
corridor.

`room_probe.py` and `walk_stream.py` already turn a dump into answers in one second. The bottleneck is
**producing dumps and observations**, and that bottleneck is addressable: ares v148 is not a black box.

## What ares v148 actually exposes (measured today)

```
/Applications/ares.app  v148
--help flags:  --system  --setting name=value  --dump-all-settings  --save-state slot(1-9)
               --settings-file  --kiosk  --fullscreen
no AppleScript dictionary (.sdef absent)
strings in the binary contain `qSupported`      <- a GDB remote-serial-protocol stub
settings present:  Boot/Debugger
                   DebugServer/Enabled, DebugServer/Port, DebugServer/UseIPv4
                   General/AutoSaveMemory, General/Rewind, General/RunAhead, General/ForceInterpreter
                   Paths/Debugging, Paths/Saves, Paths/Screenshots
```

Two of those matter more than everything else:

* **`DebugServer/Enabled` + `DebugServer/Port`** with a GDB RSP stub compiled in means ares can be
  **driven as a remote target**: breakpoints, register reads, memory reads, single-step, continue.
* **`--save-state slot` (1–9) + `Paths/Saves`** means a state captured inside a room can be **reloaded
  deterministically**, so a room does not have to be replayed by hand for every experiment.

## The three routes, cheapest first

### Route A — GDB remote protocol (the intended one)

Start ares with the debug server on, connect a small Python RSP client, and script it:

```sh
/Applications/ares.app/Contents/MacOS/ares \
  --system "Nintendo 64" "rom/…z64" \
  --setting DebugServer/Enabled=true --setting DebugServer/Port=1984 \
  --setting Boot/Debugger=true
```

then (RSP, all ASCII, `$…#cc` framing):

| need | RSP |
|---|---|
| what the stub supports | `qSupported` |
| read registers | `g` / `p n` |
| read memory — **the whole RDRAM** | `m 80000000,800000` chunks |
| write a breakpoint | `Z0,addr,4` |
| continue / step | `c` / `s` |
| a watchpoint (if supported) | `Z2`/`Z3` (write/read) or `Z4` (access) |

With that, the two things the last six notes could not do become one-line operations:

1. **watch `v0` at `0x80071eb0`** — set `Z0,80071eb0,4`, `c`, read `$v0` on each stop;
2. **dump RDRAM on demand** — `m 80000000,800000` in 512 KB chunks, no GUI and no human.

Deliverable: `tools/ares_rsp.py` — connect, `qSupported`, memory read, register read, breakpoint set,
continue, and a `--dump` mode that writes a file in the same 8 MB layout `room_probe.py` already reads.
Then `room_probe.py`/`walk_stream.py` work unchanged on scripted dumps.

### Route B — save states as fixtures (works even if RSP fights back)

`--save-state slot` plus `Paths/Saves` gives reproducible entry points: capture one state per room once,
then every experiment starts there. Combined with `Boot/Debugger`, or even alone, this removes the
"replay the corridor by hand" cost from every future question.

### Route C — UI scripting (last resort, likely fragile)

`System Events` can click menu items without a `.sdef`, and it is how the Memory Editor could be driven
today. It needs Accessibility permission for the terminal, is sensitive to window layout, and cannot read
registers. Worth one attempt only if A and B fail — and it would still leave the *observation* half
(breakpoints) unsolved.

## The first experiment, and how to know it failed

```
1. launch ares with DebugServer/Enabled=true, Port=1984, Boot/Debugger=true, a ROM, --kiosk
2. from Python: open TCP 127.0.0.1:1984, send `$qSupported#…`, read one reply
3. if the reply is a capability list -> Route A is open: implement memory + registers + breakpoints
   if the port never opens      -> the debugger must be a debug *build* of ares; record that and fall
                                   back to Route B
   if the app refuses to start  -> the setting names are wrong for v148; `--dump-all-settings` is the
                                   source of truth and the names above came from it
```

Acceptance, stated up front so it cannot be argued later: **`$qSupported` answered, then one 512 KB
`m` read returning bytes that match the same range of an existing hand-made dump.** Byte equality
against a known dump is the test — not "it connected".

## What this is *not*

It is not the harness coming back. `tools/mips_harness.py` models a CPU and stops where the cartridge's
hardware events begin (M78–M80); ares *is* the hardware model. Using it as a **target** rather than as a
manual oracle does not weaken the earlier finding that the harness cannot reach a room — it retires the
need to.

And it does not change the project's rule about ares: it stays an **optional external validator**. What
changes is that the validation stops costing a human action per observation.

## Risks and how they are handled

| risk | handling |
|---|---|
| ares' RSP is a private dialect | start from `qSupported`, implement only what it lists, and treat every unimplemented command as "not available" rather than guessing |
| the debug build is not the release build | if `DebugServer` requires a dev build, record it and use Route B; do not patch or rebuild ares in this repo |
| breakpoints perturb timing | a breakpoint on a *specific PC* is an observation, but state it as such: conclusions from a stopped machine are about the stop, not the run |
| dumps become "mine" rather than the owner's | dumps stay in `rom/` (gitignored) with ares' own timestamps, and each note records which dump it used |

## First experiment — result (measured)

Two launches, with the cartridge, `--kiosk`:

| settings | listener on the port | replies to `?`, `qSupported`, `g`, `m…` |
|---|---|---|
| `DebugServer/Enabled=true`, `DebugServer/Port=1984`, `DebugServer/UseIPv4=true`, **`Boot/Debugger=true`** | **binds** (TCP connect succeeds; port closes when ares exits, so the listener *was* ares) | **all empty** (0 bytes, no error, no reset) |
| `DebugServer/Enabled=true`, `DebugServer/Port=1985`, no `Boot/Debugger` | **refused** | n/a |

So:

* **`Boot/Debugger=true` is what starts the debugger**; `DebugServer/Enabled` alone does not bind a port.
* the stub **binds and accepts**, but answers **nothing** to standard RSP framing (`$…#cc`), to a bare
  `+`, or to a greeting read — over a 1.5–4 s window each.

That is a specific negative, not a dead end: the server wants a handshake or a dialect this client did not
send. The next probe is to read how the stub is driven (ares' own source for the debug server, or its
documentation) rather than guessing more framings. Two candidate explanations, both testable:

1. it is **not** GDB RSP — `qSupported` in the binary may belong to a different component, and ares'
   debugger may speak its own protocol;
2. it **is** RSP but expects the client to attach to a **paused** core (e.g. the emulator must already be
   stopped at the debugger prompt), so a client connecting to a running game is accepted and ignored.

Either way the harness for this is now known: `Boot/Debugger=true` + `DebugServer/Port=N` gives an open
socket on request, and `tools/ares_rsp.py` is the place to iterate on the handshake.
