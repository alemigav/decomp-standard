#!/usr/bin/env python3
"""Drive ares' built-in GDB server over the remote-serial protocol.

M107 established that ares v148 links a GDB stub and that `DebugServer/Port` binds a listener only
when `Boot/Debugger=true`, but every standard RSP packet got **zero bytes back** — a specific negative
with two open explanations (wrong framing, or a client that must attach to a halted core). This tool is
the instrument for that question, so it is built to *report what happened* rather than to assume:

  * every byte sent and received is logged with a `[tx]`/`[rx]` prefix;
  * a read that returns 0 bytes is reported as **CLOSED** (the peer shut the socket) and a read that
    returns nothing before the deadline is reported as **NO REPLY** — M107 could not tell these apart,
    and they mean opposite things (a rejected packet vs. a packet the stub never consumes);
  * an unrequested greeting is logged if one arrives, before anything is sent.

The protocol facts behind the framing, measured from the shipped binary (not from a GDB manual):

  * the mangled name `N4nall3GDB6ServerE` at file offset `0xd28c70` — ares links nall's GDB server;
  * its reply strings sit in one cluster at `0xdd91f1`: `OK`, `E00`, `T05`, `S05`, `PacketSize=`,
    `;vContSupported-`, `QStartNoAckMode+`, `;xmlRegisters+;qXfer:features:read+`, `qOffsets` ->
    `Text=0;Data=0;Bss=0`, `qAttached` -> `1`, `vMustReplyEmpty`, `vCtrlC`, `vKill`, `vCont?` ->
    `vCont;c;s`, plus `Unknown-Command: %s (data: %s)` and `Non-GDB client detected (message: %s)`;
  * `DebugServer/Port` defaults to **9123** in `settings.bml` (not GDB's 1234), and `Boot/AwaitGDBClient`
    exists next to `Boot/Debugger`.

The `Non-GDB client detected` string is the reason this client is strict about checksums: a packet whose
`#cc` is wrong cannot be distinguished by the stub from a non-GDB peer, so a malformed packet would look
exactly like "the stub ignores standard RSP".

Usage:
  ./ares_rsp.py probe                       # connect, log greeting, qSupported, report the raw reply
  ./ares_rsp.py regs                        # `g`, reported as length + raw hex (no invented layout)
  ./ares_rsp.py regmap                      # derive each register's size and offset from `p n`
  ./ares_rsp.py read 0x80012150 64          # `m addr,len`
  ./ares_rsp.py dump out.bin [--expect FILE] # 8 MiB RDRAM in 32 KiB chunks, optional byte-equality check
  ./ares_rsp.py watch 0x80071ebc --stops 20     # a0 (and PC) at every hit, one connection
  ./ares_rsp.py bp 0x80071eb0 && ./ares_rsp.py cont
  ./ares_rsp.py raw 'qAttached'             # send one literal packet, for dialect exploration
  ./ares_rsp.py launch --rom rom/nree.z64   # start ares with Boot/Debugger + DebugServer/Port
"""
import argparse
import re
import socket
import subprocess
import sys
import time
from pathlib import Path

DEFAULT_HOST = "127.0.0.1"
DEFAULT_PORT = 9123          # ares' own default in settings.bml
RD_BASE = 0x80000000
RDRAM_SIZE = 0x800000        # 8 MiB, the size of every ares "Memory -> Export" dump in rom/
CHUNK = 0x800                # 2 KiB per `m` request: the stub advertises PacketSize=4096, and a
                             # reply is hex-doubled, so 2048 bytes is the largest safe request
DEFAULT_TIMEOUT = 3.0


def checksum(payload):
    return sum(payload.encode()) & 0xFF


def pkt(payload):
    return "$%s#%02x" % (payload, checksum(payload))


def is_error(reply):
    """RSP says `E` + 1-2 hex digits. Memory *data* can start with the byte 0xE4 (e.g. `swc1`), so a
    bare `startswith("E")` reads code as an error — the bug that aborted the first 8 MiB dump at
    0x800a3000, whose first four bytes are `e4 82 00 54`."""
    return re.fullmatch(r"E[0-9a-fA-F]{1,2}", reply) is not None


class Rsp:
    """A GDB-RSP client that refuses to hide a failure."""

    def __init__(self, host=DEFAULT_HOST, port=DEFAULT_PORT, timeout=DEFAULT_TIMEOUT, quiet=False):
        self.host, self.port, self.timeout, self.quiet = host, port, timeout, quiet
        self.sock = None
        self.closed = False
        self.noack = False
        self.rx_log = []

    # ---- logging -------------------------------------------------------------------------------
    def log(self, tag, text):
        if not self.quiet:
            print("[%s] %s" % (tag, text))

    def _log_bytes(self, tag, data):
        if self.quiet:
            return
        if isinstance(data, str):
            data = data.encode("latin-1")
        shown = data if len(data) <= 96 else data[:96] + b"..." + (b"(%d bytes)" % len(data))
        try:
            text = shown.decode("ascii")
        except UnicodeDecodeError:
            text = shown.hex()
        self.log(tag, text)

    # ---- transport -----------------------------------------------------------------------------
    LEAD_ACK = True          # set from --no-lead-ack; see the comment inside connect()

    def connect(self, lead_ack=None):
        lead_ack = self.LEAD_ACK if lead_ack is None else lead_ack
        self.sock = socket.create_connection((self.host, self.port), timeout=self.timeout)
        self.sock.settimeout(self.timeout)
        self.log("..", "connected to %s:%d" % (self.host, self.port))
        if lead_ack:
            # nall::TCPText::Server::onData (0x1001ef1cc) rejects the connection unless the FIRST byte
            # it ever reads is '+': `ldrb w8,[x20]; cmp w8,#0x2b; b.ne -> "Non-GDB client detected"`.
            # A client that opens with '$qSupported#..' is therefore hung up on, which is exactly the
            # M107 negative. So the ack byte goes out on its own before any packet.
            self.send_raw(b"+")

    def close(self):
        if self.sock:
            try:
                self.sock.close()
            except OSError:
                pass
            self.sock = None

    def _recv(self, deadline):
        """Return bytes, b'' for a peer close, or None if the deadline expired."""
        remaining = deadline - time.monotonic()
        if remaining <= 0:
            return None
        self.sock.settimeout(remaining)
        try:
            data = self.sock.recv(65536)
        except socket.timeout:
            return None
        except OSError as exc:
            self.log("!!", "socket error: %s" % exc)
            return b""
        if data == b"":
            self.closed = True
        return data

    def greeting(self, wait=0.5):
        """Log anything the stub volunteers before we speak. Returns the bytes."""
        data = self._recv(time.monotonic() + wait)
        if data is None:
            self.log("..", "no greeting within %.1fs" % wait)
            return b""
        if data == b"":
            self.log("!!", "CLOSED before greeting")
            return b""
        self._log_bytes("rx", data)
        return data

    def send_raw(self, data):
        self._log_bytes("tx", data)
        self.sock.sendall(data.encode("latin-1") if isinstance(data, str) else data)

    def read_packet(self, timeout=None):
        """Read one `$...#cc` packet, swallowing acks. Returns payload str, or None."""
        deadline = time.monotonic() + (self.timeout if timeout is None else timeout)
        buf = bytearray()
        while True:
            chunk = self._recv(deadline)
            if chunk is None:
                if buf:
                    self.log("!!", "NO REPLY mid-packet after %d bytes: %r" % (len(buf), bytes(buf)))
                else:
                    self.log("!!", "NO REPLY within %.1fs" % (self.timeout if timeout is None else timeout))
                return None
            if chunk == b"":
                self.log("!!", "CLOSED by peer" + (" mid-packet (%d bytes): %r" % (len(buf), bytes(buf)) if buf else ""))
                return None
            self._log_bytes("rx", chunk)
            buf += chunk
            while b"$" in buf:
                start = buf.index(b"$")
                if start:
                    del buf[:start]          # drop acks (+/-) and any leading noise
                if buf.count(b"$") < 2 and b"#" not in buf:
                    break                    # need more
                if b"#" not in buf or len(buf) < buf.index(b"#") + 3:
                    break                    # checksum not complete yet
                end = buf.index(b"#")
                body = bytes(buf[1:end]).decode("latin-1")
                want = int(bytes(buf[end + 1:end + 3]), 16)
                got = checksum(body)
                del buf[:end + 3]
                if not self.noack:
                    self.send_raw(b"+")
                if want != got:
                    self.log("!!", "checksum mismatch: packet says #%02x, payload sums to #%02x" % (want, got))
                    return body
                self.rx_log.append(body)
                return body

    def cmd(self, payload, timeout=None):
        self.send_raw(pkt(payload))
        return self.read_packet(timeout)

    # ---- protocol ops --------------------------------------------------------------------------
    def qsupported(self):
        reply = self.cmd("qSupported")
        if reply is None:
            return None
        features = {}
        for item in reply.split(";"):
            if not item:
                continue
            if item.endswith("+") or item.endswith("-"):
                features[item[:-1]] = item[-1]
            elif "=" in item:
                k, v = item.split("=", 1)
                features[k] = v
            else:
                features[item] = True
        return reply, features

    def read_mem(self, addr, length):
        """`m addr,len`. Returns bytes, or None with the reason already logged."""
        reply = self.cmd("m%x,%x" % (addr, length))
        if reply is None:
            return None
        if reply == "":
            self.log("!!", "empty reply to `m` = the stub does not implement memory reads")
            return None
        if is_error(reply):
            self.log("!!", "stub refused `m %x,%x`: %s" % (addr, length, reply))
            return None
        try:
            data = bytes.fromhex(reply)
        except ValueError:
            self.log("!!", "non-hex reply to `m`: %r" % reply[:64])
            return None
        if len(data) != length:
            self.log("!!", "short read at %08x: asked %d, got %d" % (addr, length, len(data)))
        return data

    def read_regs(self):
        reply = self.cmd("g")
        if reply is None:
            return None
        if reply == "" or is_error(reply):
            self.log("!!", "stub refused `g`: %r" % reply)
            return None
        return bytes.fromhex(reply)


# ---- subcommands --------------------------------------------------------------------------------
def do_launch(args):
    exe = Path(args.ares) / "Contents" / "MacOS" / "ares"
    if not exe.exists():
        sys.exit("no ares at %s" % exe)
    cmd = [str(exe), "--system", "Nintendo 64", str(args.rom),
           "--setting", "DebugServer/Enabled=true",
           "--setting", "DebugServer/Port=%d" % args.port,
           "--setting", "DebugServer/UseIPv4=true",
           "--setting", "Boot/Debugger=true"]
    if args.log:
        with open(args.log, "ab") as log:
            proc = subprocess.Popen(cmd, stdout=log, stderr=log)
        print("$ " + " ".join(cmd))
        print("[..] ares pid %d, output -> %s" % (proc.pid, args.log))
        return proc
    if args.await_gdb:
        cmd += ["--setting", "Boot/AwaitGDBClient=true"]
    print("$ " + " ".join(cmd))
    proc = subprocess.Popen(cmd, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    print("[..] ares pid %d" % proc.pid)
    return proc


def do_probe(args):
    rsp = Rsp(args.host, args.port, args.timeout, args.quiet)
    rsp.connect()
    rsp.greeting(args.greeting)
    result = rsp.qsupported()
    if result is None:
        print("\nVERDICT: no qSupported reply — the stub does not answer standard RSP on this socket.")
        rsp.close()
        return 1
    reply, features = result
    print("\nqSupported -> %s" % reply)
    print("parsed %d feature(s):" % len(features))
    for k in sorted(features):
        print("  %-28s %s" % (k, features[k]))
    if features.get("QStartNoAckMode") == "+":
        if rsp.cmd("QStartNoAckMode") == "OK":
            rsp.noack = True
            print("[..] no-ack mode enabled")
    pid = rsp.cmd("qThreadExtraInfo,1")
    print("qThreadExtraInfo,1 -> %s" % (pid if pid is not None else "<no reply>"))
    print("\nVERDICT: the stub speaks RSP. Memory/register reads are the next test.")
    rsp.close()
    return 0


def do_regs(args):
    rsp = Rsp(args.host, args.port, args.timeout, args.quiet)
    rsp.connect()
    rsp.greeting(0.2)
    data = rsp.read_regs()
    if data is None:
        rsp.close()
        return 1
    print("\ng -> %d bytes (%d registers if 4 bytes each)" % (len(data), len(data) // 4))
    print("raw: %s" % data.hex())
    if args.words:
        print("no register-name mapping is asserted here; the layout is not established yet.")
        for i in range(0, len(data) - 3, 4):
            print("  [%3d] %08x" % (i // 4, int.from_bytes(data[i:i + 4], "big")))
    rsp.close()
    return 0


def do_read(args):
    rsp = Rsp(args.host, args.port, args.timeout, args.quiet)
    rsp.connect()
    rsp.greeting(0.2)
    data = rsp.read_mem(args.addr, args.length)
    rsp.close()
    if data is None:
        return 1
    for off in range(0, len(data), 16):
        row = data[off:off + 16]
        print("%08x  %-47s  |%s|" % (
            args.addr + off,
            " ".join("%02x" % b for b in row),
            "".join(chr(b) if 32 <= b < 127 else "." for b in row)))
    return 0


def do_dump(args):
    rsp = Rsp(args.host, args.port, args.timeout, args.quiet)
    rsp.connect()
    rsp.greeting(0.2)
    out = bytearray()
    addr = args.base
    while len(out) < args.size:
        want = min(CHUNK, args.size - len(out))
        data = rsp.read_mem(addr, want)
        if data is None or len(data) != want:
            print("FAILED after %d of %d bytes at %08x — nothing written" % (len(out), args.size, addr))
            rsp.close()
            return 1
        out += data
        addr += want
        if not args.quiet:
            print("  %08x..%08x  %d/%d" % (addr - want, addr, len(out), args.size), end="\r")
    rsp.close()
    path = Path(args.out)
    path.write_bytes(bytes(out))
    print("\nwrote %s (%d bytes)" % (path, len(out)))
    if args.expect:
        ref = Path(args.expect).read_bytes()
        base = args.expect_base
        if base + len(out) > len(ref):
            print("reference %s is only %d bytes, cannot cover %08x+%x" % (ref, len(ref), base, args.size))
            return 1
        mine = bytes(out)
        theirs = ref[base:base + len(out)]
        diff = [i for i in range(len(mine)) if mine[i] != theirs[i]]
        print("byte equality with %s over %08x..%08x: %d/%d equal, %d differing" % (
            Path(args.expect).name, args.base, args.base + len(out), len(mine) - len(diff), len(mine), len(diff)))
        for i in diff[:8]:
            print("  %08x: live %02x  dump %02x" % (args.base + i, mine[i], theirs[i]))
        return 0 if not diff else 2
    return 0


def do_bp(args):
    rsp = Rsp(args.host, args.port, args.timeout, args.quiet)
    rsp.connect()
    rsp.greeting(0.2)
    kind = {1: "Z0", 2: "Z1", 4: "Z2"}[args.kind]       # 1=exec, 2=write watch, 4=access watch
    reply = rsp.cmd("%s,%x,%d" % (kind, args.addr, args.width))
    print("%s,%x,%d -> %r" % (kind, args.addr, args.width, reply))
    rsp.close()
    return 0 if reply == "OK" else 1


def do_cont(args):
    rsp = Rsp(args.host, args.port, args.timeout, args.quiet)
    rsp.connect()
    rsp.greeting(0.2)
    payload = "s" if args.step else "c"
    rsp.send_raw(pkt(payload))
    reply = rsp.read_packet(timeout=args.wait)
    print("%s -> %r" % (payload, reply))
    rsp.close()
    return 0 if reply else 1


def do_regmap(args):
    """Derive the register file from the stub: `g` plus `p n` for each n, concatenated and checked."""
    rsp = Rsp(args.host, args.port, args.timeout, args.quiet)
    rsp.connect()
    rsp.greeting(0.1)
    if args.halt:
        if rsp.cmd("Z0,%x,4" % args.halt) != "OK":
            print("could not set the halting breakpoint")
            rsp.close()
            return 1
        rsp.send_raw(pkt("c"))
        if rsp.read_packet(timeout=args.wait) is None:
            print("no stop at %08x within %.0fs" % (args.halt, args.wait))
            rsp.close()
            return 1
        print("[..] halted at %08x, so `g` and the `p n` reads are one instant" % args.halt)
    blob = rsp.read_regs()
    if blob is None:
        rsp.close()
        return 1
    rows, off = [], 0
    while off < len(blob):
        reply = rsp.cmd("p%d" % len(rows))
        if reply is None or reply == "" or is_error(reply):
            print("`p %x` answered %r — stopping the scan" % (len(rows), reply))
            break
        data = bytes.fromhex(reply)
        rows.append(data)
        off += len(data)
    rsp.close()
    cat = b"".join(rows)
    print("g = %d bytes; %d register(s) via `p n`; concatenation %s" % (
        len(blob), len(rows), "matches g exactly" if cat == blob else "DIFFERS from g"))
    if cat != blob:
        print("  g = %s" % blob.hex())
        print("  p = %s" % cat.hex())
    print("  idx  bytes  value")
    for i, data in enumerate(rows):
        print("  %3d  %5d  %s" % (i, len(data), data.hex()))
    return 0


def do_until(args):
    """Set one breakpoint, continue, and report the stop — the M107 use case, as one command."""
    rsp = Rsp(args.host, args.port, args.timeout, args.quiet)
    rsp.connect()
    rsp.greeting(0.1)
    reply = rsp.cmd("Z0,%x,%d" % (args.addr, args.width))
    if reply != "OK":
        print("breakpoint refused: %r" % reply)
        rsp.close()
        return 1
    print("[..] breakpoint at %08x accepted" % args.addr)
    rsp.send_raw(pkt("c"))
    stop = rsp.read_packet(timeout=args.wait)
    if stop is None:
        print("no stop within %.1fs (the breakpoint stays set until this connection closes)" % args.wait)
        rsp.close()
        return 1
    print("stop: %r" % stop)
    regs = rsp.read_regs()
    if regs:
        print("registers (%d bytes): %s" % (len(regs), regs.hex()))
    rsp.close()
    return 0


DERIVED_REGS = {0: "r0", 4: "a0", 37: "pc"}     # derived by measurement in M108; nothing else is named


def do_watch(args):
    """Hit one address repeatedly and report chosen registers at every stop, in one connection."""
    rsp = Rsp(args.host, args.port, args.timeout, args.quiet)
    rsp.connect()
    rsp.greeting(0.1)
    reply = rsp.cmd("Z0,%x,%d" % (args.addr, args.width))
    if reply != "OK":
        print("breakpoint refused: %r" % reply)
        rsp.close()
        return 1
    names = ", ".join("%s=r%d" % (DERIVED_REGS.get(r, "r%d" % r), r) for r in args.reg)
    print("[..] breakpoint at %08x; watching %s" % (args.addr, names))
    hits = 0
    try:
        for n in range(1, args.stops + 1):
            rsp.send_raw(pkt("c"))
            stop = rsp.read_packet(timeout=args.wait)
            if stop is None:
                print("no stop within %.0fs after %d hit(s)" % (args.wait, hits))
                break
            hits += 1
            fields = []
            for r in args.reg:
                reply = rsp.cmd("p%d" % r)
                if reply is None or reply == "" or is_error(reply):
                    fields.append("%s=<no read>" % DERIVED_REGS.get(r, "r%d" % r))
                    continue
                raw = bytes.fromhex(reply)
                fields.append("%s=%s" % (DERIVED_REGS.get(r, "r%d" % r),
                                         "0x" + raw[-4:].hex() if len(raw) == 8 else "0x" + raw.hex()))
            print("stop %2d  %-8s %s" % (n, stop, "  ".join(fields)))
    finally:
        rsp.cmd("z0,%x,%d" % (args.addr, args.width))
        rsp.close()
    print("%d stop(s)" % hits)
    return 0 if hits else 1


def do_inject(args):
    """Hold a controller input by rewriting the pad buffer at every SI read.

    `FUN_8000d1f0(0, &DAT_80016470)` is the SI DMA that pulls the PIF response into RDRAM (0x80016470),
    so the breakpoint goes just after that call: the buffer is filled, and the game has not parsed it yet.
    Each stop rewrites the bytes and resumes, which is how a held direction is produced without a pad.
    """
    rsp = Rsp(args.host, args.port, args.timeout, args.quiet)
    rsp.connect()
    rsp.greeting(0.1)
    if rsp.cmd("Z0,%x,4" % args.bp) != "OK":
        print("breakpoint refused")
        rsp.close()
        return 1
    patch = {}
    for item in (args.patch or []):
        off, val = item.split(":")
        patch[int(off, 0)] = bytes.fromhex(val)
    script = None
    if args.script:
        script = []
        for seg in args.script.split(","):
            n, val = seg.split("x")
            script.append((int(n), bytes.fromhex(val)))
        total = sum(n for n, _ in script)
        print("[..] script: %s (%d frames)" % (
            ", ".join("%dx%s" % (n, v.hex()) for n, v in script), total))
        args.frames = total
    elif args.patch:
        pass
    print("[..] bp %08x, buffer %08x (%d B), patch %s" % (
        args.bp, args.buf, args.len, ", ".join("%d:%s" % (k, v.hex()) for k, v in sorted(patch.items())) or "none"))
    hits = 0
    base = None
    try:
        for frame in range(args.frames):
            rsp.send_raw(pkt("c"))
            stop = rsp.read_packet(timeout=args.wait)
            if stop is None:
                print("no stop within %.0fs after %d hit(s)" % (args.wait, hits))
                break
            hits += 1
            if base is None:
                base = bytearray(rsp.read_mem(args.buf, args.len) or b"")
                if not base:
                    print("could not read the buffer")
                    break
                if not patch and script is None:
                    print("[..] buffer at the first stop (%d B):" % len(base))
                    for i in range(0, len(base), 16):
                        print("  %08x  %s" % (args.buf + i, base[i:i+16].hex()))
                    break
            if frame == 0 and args.show:
                print("[..] before patch: %s" % bytes(base).hex())
            patched = bytearray(base)
            for off, val in patch.items():
                patched[off:off + len(val)] = val
            if script is not None:
                acc, val = 0, script[0][1]
                for n, v in script:
                    if hits <= acc + n:
                        val = v
                        break
                    acc += n
            if script is not None:
                patched[4:8] = val
            rsp.cmd("M%x,%x:%s" % (args.buf, len(patched), patched.hex()))
            if frame == 0 and args.show:
                print("[..] after patch : %s" % bytes(patched).hex())
    finally:
        rsp.cmd("z0,%x,4" % args.bp)
        rsp.close()
    print("%d frame(s)" % hits)
    return 0


def do_raw(args):
    rsp = Rsp(args.host, args.port, args.timeout, args.quiet)
    rsp.connect()
    rsp.greeting(0.2)
    reply = rsp.cmd(args.packet)
    print("reply: %r" % reply)
    rsp.close()
    return 0 if reply is not None else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--host", default=DEFAULT_HOST)
    ap.add_argument("--port", type=int, default=DEFAULT_PORT)
    ap.add_argument("--timeout", type=float, default=DEFAULT_TIMEOUT)
    ap.add_argument("--quiet", action="store_true", help="suppress the tx/rx byte log")
    ap.add_argument("--no-lead-ack", action="store_true",
                    help="do not send the bare '+' the stub demands first (reproduces the M107 negative)")
    sub = ap.add_subparsers(dest="cmd", required=True)

    def add(name, fn):
        p = sub.add_parser(name)
        p.set_defaults(fn=fn)
        return p

    p = add("probe", do_probe)
    p.add_argument("--greeting", type=float, default=0.5, help="seconds to wait for an unsolicited greeting")

    p = add("regs", do_regs)
    p.add_argument("--words", action="store_true", help="also print 4-byte groups, unlabelled")

    p = add("read", do_read)
    p.add_argument("addr", type=lambda s: int(s, 0))
    p.add_argument("length", type=lambda s: int(s, 0))

    p = add("dump", do_dump)
    p.add_argument("out")
    p.add_argument("--base", type=lambda s: int(s, 0), default=RD_BASE)
    p.add_argument("--size", type=lambda s: int(s, 0), default=RDRAM_SIZE)
    p.add_argument("--expect", help="compare the read against this existing dump")
    p.add_argument("--expect-base", type=lambda s: int(s, 0), default=0,
                   help="offset inside --expect that corresponds to --base (default 0)")

    p = add("bp", do_bp)
    p.add_argument("addr", type=lambda s: int(s, 0))
    p.add_argument("--width", type=int, default=4)
    p.add_argument("--kind", type=int, default=1, choices=(1, 2, 4))

    p = add("cont", do_cont)
    p.add_argument("--step", action="store_true")
    p.add_argument("--wait", type=float, default=5.0)

    p = add("regmap", do_regmap)
    p.add_argument("--halt", type=lambda s: int(s, 0), help="breakpoint to halt on before comparing")
    p.add_argument("--wait", type=float, default=15.0)

    p = add("until", do_until)
    p.add_argument("addr", type=lambda s: int(s, 0))
    p.add_argument("--width", type=int, default=4)
    p.add_argument("--wait", type=float, default=10.0)

    p = add("watch", do_watch)
    p.add_argument("addr", type=lambda s: int(s, 0))
    p.add_argument("--reg", type=lambda s: int(s, 0), action="append",
                   help="register index to read at each stop (repeatable); default 4 (a0) and 37 (pc)")
    p.add_argument("--stops", type=int, default=10)
    p.add_argument("--width", type=int, default=4)
    p.add_argument("--wait", type=float, default=30.0)

    p = add("inject", do_inject)
    p.add_argument("--bp", type=lambda s: int(s, 0), required=True, help="stop just after the SI read")
    p.add_argument("--buf", type=lambda s: int(s, 0), default=0x80016470)
    p.add_argument("--len", type=lambda s: int(s, 0), default=64)
    p.add_argument("--patch", action="append", help="offset:hexbytes, repeatable")
    p.add_argument("--frames", type=int, default=120)
    p.add_argument("--show", action="store_true")
    p.add_argument("--script", help="NxHHHHHHHH,Nx... segments written to offset 4, cycled")
    p.add_argument("--wait", type=float, default=10.0)

    p = add("raw", do_raw)
    p.add_argument("packet")

    p = add("launch", do_launch)
    p.add_argument("--rom", required=True)
    p.add_argument("--ares", default="/Applications/ares.app")
    p.add_argument("--await-gdb", action="store_true", help="also set Boot/AwaitGDBClient=true")
    p.add_argument("--log", help="append ares' own stdout/stderr here (it prints GDB connect/disconnect)")

    args = ap.parse_args()
    if getattr(args, "cmd", None) == "watch" and not args.reg:
        args.reg = [4, 37]
    Rsp.LEAD_ACK = not args.no_lead_ack
    return args.fn(args) or 0


if __name__ == "__main__":
    sys.exit(main())
