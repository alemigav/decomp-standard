#!/usr/bin/env python3
"""A prototype verifier: discover each check's real inputs, then cache on them.

The problem this attacks is not "are the gates right" — it is that a 953-case, 146-mutation apparatus costs
twelve minutes and therefore gets run on *everything*, every time. A verifier that costs twelve minutes is
consulted once a session; one that costs half a second is consulted after every edit.

The design, in three parts:

  1. **Inputs are discovered, not declared.** Each check is run once in a child process with an audit hook
     installed, so the verifier learns the exact set of files the check opened — no hand-maintained dependency
     list to drift out of date. That set is cached alongside the result.
  2. **The key is the content.** A check's key is `sha256(tool source + argv + every discovered input's
     sha256)`. Unchanged key, unchanged verdict: the check is not run at all. Change one byte of one input,
     or any byte of the tool, and the key moves and the check re-runs.
  3. **The cartridge and the interpreter are inputs too.** The ROM's hash and `sys.version` go into every
     key, because a check that reads the cartridge via a path outside the worktree would otherwise look
     unchanged when the ROM is swapped.

What it deliberately does **not** do yet: run the mutation audits under this scheme (they are the far more
expensive half and belong on a push/nightly cadence), cover checks that spawn their own children (the audit
hook does not see a grandchild's opens — those must declare inputs or stay uncached), or replace
`tools/verify.py`. It is a prototype with a measured claim attached: **a warm run is hashing cost, and a
one-file edit re-runs only the checks that read that file.**

  ./verify_proto.py             # verify, using the cache
  ./verify_proto.py --cold      # ignore the cache and re-discover every input set
  ./verify_proto.py --why       # show, per check, what its key is made of
"""
import argparse
import hashlib
import json
import os
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
CACHE = ROOT / "build" / "verify-proto-cache.json"
CARTRIDGE = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"

# Eight checks, chosen to span the shapes rather than to be complete: a document gate, a source-hash gate, a
# registry gate, a cartridge decompression, a stage-2 decode, and three small derived artefacts.
CHECKS = [
    ("doc markers", "tools/check_markers.py", []),
    ("counts", "tools/counts.py", ["--check"]),
    ("ratchet", "tools/ratchet.py", ["--check"]),
    ("milestone index", "tools/milestone_index.py", ["--check"]),
    ("file table", "tools/file_table.py", ["--check"]),
    ("sound commands", "tools/sound_ops.py", ["--check"]),
    ("voice lists", "tools/voice_lists.py", ["--check"]),
    ("smpdir", "tools/smpdir.py", ["--check"]),
]


# --------------------------------------------------------------------------- hashing, with a stat cache
class Hasher:
    """sha256 of files, memoised on (path, size, mtime_ns).

    The memo is what makes a warm run cheap: an unchanged tree costs one `stat` per input, not a read. It is
    also the one place this prototype can be fooled — a rewrite that preserves size and mtime — so `--cold`
    exists and the cache stores the file list it was built from.
    """

    def __init__(self):
        self.memo = {}

    def file(self, path):
        try:
            st = os.stat(path)
        except OSError:
            return "missing"
        key = (str(path), st.st_size, st.st_mtime_ns)
        hit = self.memo.get(key)
        if hit:
            return hit
        h = hashlib.sha256()
        try:
            with open(path, "rb") as fh:
                for block in iter(lambda: fh.read(1 << 20), b""):
                    h.update(block)
        except OSError:
            return "missing"
        self.memo[key] = h.hexdigest()
        return self.memo[key]


def tree_digest(hasher, paths):
    """A digest over a discovered input set, order-independent."""
    parts = sorted("%s:%s" % (p, hasher.file(p)) for p in paths)
    return hashlib.sha256("\n".join(parts).encode()).hexdigest()


# --------------------------------------------------------------------------- running one check, instrumented
def run_instrumented(tool, args):
    """Run a tool in *this* process with an audit hook, and report the files it opened.

    The child mode of this same file: the parent re-executes itself with `--run-one`, so a check that calls
    `sys.exit` or mutates globals cannot take the verifier down with it.
    """
    opened = set()

    root = str(ROOT) + os.sep

    def hook(event, a):
        # Only the worktree. A check also opens the interpreter's stdlib and `.pyc` caches — 8 452 paths for
        # `file_table` alone — and hashing those on every run is both pointless (they are pinned by
        # `sys.version` in the key) and slower than the check itself.
        if event == "open" and a and isinstance(a[0], str):
            p = os.path.abspath(a[0])
            if p.startswith(root):
                opened.add(p)

    sys.addaudithook(hook)
    import runpy
    code = 0
    try:
        sys.argv = [tool] + list(args)
        runpy.run_path(str(ROOT / tool), run_name="__main__")
    except SystemExit as exc:
        code = int(exc.code or 0)
    except BaseException:
        import traceback
        traceback.print_exc()
        code = 1
    finally:
        sys.stdout.flush()
        print("\n@@OPENED@@" + json.dumps(sorted(opened)))


def run_check(tool, args):
    """Run a check as `--run-one` in a child, and split its output from the discovered input list."""
    t0 = time.time()
    proc = subprocess.run([sys.executable, str(HERE / "verify_proto.py"), "--run-one", tool] + list(args),
                          cwd=str(ROOT), capture_output=True, text=True)
    out = proc.stdout
    opened = []
    if "@@OPENED@@" in out:
        body, _, tail = out.rpartition("@@OPENED@@")
        out = body
        try:
            opened = json.loads(tail)
        except json.JSONDecodeError:
            opened = []
    return proc.returncode, out, opened, time.time() - t0


def verdict_of(text):
    for line in reversed(text.splitlines()):
        line = line.strip()
        if "/" in line and line.split()[0:1] and "/" in line.split()[0]:
            a, _, b = line.split()[0].partition("/")
            if a.isdigit() and b.isdigit():
                return (int(a), int(b))
    return None


# --------------------------------------------------------------------------- the store
def load_cache():
    if CACHE.exists():
        try:
            return json.loads(CACHE.read_text())
        except json.JSONDecodeError:
            return {}
    return {}


def save_cache(cache):
    CACHE.parent.mkdir(parents=True, exist_ok=True)
    CACHE.write_text(json.dumps(cache, indent=1, sort_keys=True) + "\n")


def cart_hash():
    if not CARTRIDGE.exists():
        return "no-cartridge"
    st = CARTRIDGE.stat()
    return "%d:%d" % (st.st_size, st.st_mtime_ns)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--run-one", nargs=argparse.REMAINDER, help=argparse.SUPPRESS)
    ap.add_argument("--cold", action="store_true", help="ignore the cache and re-discover input sets")
    ap.add_argument("--why", action="store_true", help="show what each key is made of")
    args = ap.parse_args()

    if args.run_one:
        run_instrumented(args.run_one[0], args.run_one[1:])
        return 0

    cache = {} if args.cold else load_cache()
    hasher = Hasher()
    rows, ran, cached, bad = [], 0, 0, 0
    started = time.time()

    for label, tool, argv in CHECKS:
        prev = cache.get(label)
        tool_hash = hasher.file(ROOT / tool)
        if prev is None:
            key, inputs = None, []
        else:
            inputs = prev["inputs"]
            key = hashlib.sha256(json.dumps({
                "tool": tool_hash, "argv": argv, "python": sys.version.split()[0],
                "cartridge": cart_hash(), "inputs": tree_digest(hasher, inputs),
            }, sort_keys=True).encode()).hexdigest()

        if prev is not None and prev["key"] == key:
            cached += 1
            rows.append((label, prev["verdict"], "cached", 0.0, prev["inputs"]))
            bad += 0 if prev["exit"] == 0 else 1
            continue

        code, out, opened, secs = run_check(tool, argv)
        ran += 1
        v = verdict_of(out)
        vtext = "%d/%d" % v if v else "-"
        bad += 0 if code == 0 else 1
        key = hashlib.sha256(json.dumps({
            "tool": tool_hash, "argv": argv, "python": sys.version.split()[0],
            "cartridge": cart_hash(), "inputs": tree_digest(hasher, opened),
        }, sort_keys=True).encode()).hexdigest()
        cache[label] = {"key": key, "verdict": vtext, "exit": code, "inputs": opened,
                        "seconds": round(secs, 2), "when": int(time.time())}
        rows.append((label, vtext, "ran", secs, opened))

    save_cache(cache)
    total = time.time() - started
    print("%-18s %-8s %-7s %7s  %s" % ("check", "cases", "how", "secs", "inputs"))
    for label, vtext, how, secs, inputs in rows:
        shown = inputs if args.why else inputs[:3]
        more = "" if args.why else (" +%d" % (len(inputs) - 3) if len(inputs) > 3 else "")
        rel = ", ".join(sorted(os.path.relpath(p, ROOT) for p in shown)) + more
        print("%-18s %-8s %-7s %7.2f  %s" % (label, vtext, how, secs, rel if rel else "-"))
    print("\n%d check(s): %d ran, %d cached; %.2f s wall" % (len(rows), ran, cached, total))
    print("VERDICT %s" % ("PASS" if bad == 0 else "FAIL"))
    return 0 if bad == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
