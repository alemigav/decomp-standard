# M100 — the watch is set and the probe is built; the one input needed cannot be made here

## 1. The watch, with a positive control

`tools/probe.py` already had the mechanism (`--reg R@PC` logs a register at a PC). The watch asked for:

```
$ python3 tools/probe.py --steps 2000000 --irq-source none --reg 4@0x80071ebc
entry 0x80000520: 2,000,000 instructions; faults=none
interrupts taken: 3  (source none) …
  (no register line)
```

**`a0` at `0x80071ebc` is never reached in 2 000 000 instructions.** Absence only means something if the
instrument works, so the same watch on a PC that *is* executed:

```
$ python3 tools/probe.py --steps 50000 --irq-source none --reg 4@0x80000520
  instr         0  pc 0x80000520  r4 = 0x0000000000000000  thread 0x0
```

The mechanism prints when the PC is hit and stays silent when it is not. **The reason is already
established and unchanged**: the harness runs the boot chain to the boot-to-idle boundary (thread 7
spinning at `0x80000518`, threads 1 and 9 blocked on queues nothing posts to) and no room ever loads, so
the scene-slot loader is never called. This is the same wall as M24–M80, not a new one.

## 2. The dump probe, and what it says about the dumps that exist

`tools/room_probe.py` reads one ares RDRAM export and walks the whole chain in the order that fails
informatively:

1. `*(0x80115284)` — zero ⇒ the dump predates a room load, say so and stop;
2. otherwise byte 3 = the slot, classified by the M92/M93 table;
3. `*(0x800df92c)` → `+0x48`/`+0x4c` → the command stream;
4. scan that stream for opcode `0x44` **at the 22-byte stride** settled in M99 and print every
   command's byte 3 — the slot values the game actually selects.

Run against both dumps in the repository:

```
=== …-215324.bin (8,388,608 B RDRAM) ===
  *(0x80115284) = 0x00000000   *(0x800df92c) = 0x00000000
  -> the scene slot context is NOT installed: this dump predates a room load.
=== …-215657.bin (8,388,608 B RDRAM) ===
  … same …
```

Both are title-screen / post-NEW-GAME captures and both say so. **No block can be dumped from them**,
and the tool refuses rather than printing a plausible number from a misaligned scan.

## 3. The one input that cannot be produced here

A dump **after a room has loaded** requires playing the game into a room. That is a human action in a
GUI; nothing in this repository can do it, and the ares GUI's `Goto` field cannot be driven by
automation (M69: text is accepted, the commit never fires). So the remaining step is yours, and it is
three actions plus one command:

1. `./run-rom.sh`, then start a game and **walk into a room** (any room with a loaded scene; the
   in-game map/first corridor is enough — what matters is that a room's script is running).
2. In ares: **Tools → Memory Editor → region `RDRAM` → the `Memory` row → `Export`**, and save the
   dump beside the ROM (`rom/` is gitignored).
3. `python3 tools/room_probe.py "rom/<the new dump>.bin"`.

That single command then reports the slot, which branch of the loader it triggers, and every
opcode-`0x44` command's byte 3 — i.e. the enumeration that five sessions of static work narrowed down
to a single runtime byte read.

## 4. What is already true and does not depend on that dump

| link | state |
|---|---|
| handler table `0x80113898`, 141 entries, index = command byte 0 | static |
| dispatcher `FUN_8006da14`, contexts `0x80113ad0 + i*0x174` (10) | static |
| command pointer `ctx+0x1c`, advanced per handler | static |
| opcode `0x44` → `FUN_80071e14`, **22-byte commands**, byte 3 = slot | static |
| slot → map → record → `FUN_800327ec` → inflate/stale destination | static |
| the slot **value**, and which commands the game actually runs | **runtime — needs the dump** |

So the tool and the watch are both in place, both tested (one against a positive control, one against
two real dumps), and both correctly report that the missing piece is a post-room memory image.
