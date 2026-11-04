#!/usr/bin/env python3
"""Refuse to let cartridge content into the repository — by content, not by file extension.

`tools/ci.sh` already scans tracked paths for `rom/`, `assets/`, `build/` and for `.z64/.n64/.bin/.elf`
extensions. That catches the ordinary mistake and misses the two that matter:

* `git add -f rom/x.dat` — the extension scan never looks at it;
* anything hiding under `fixtures/`, which the extension scan exempts wholesale so the synthetic corpus
  fixture can be committed.

This tool reads the bytes instead. Five checks over every tracked file:

1. **no N64 header.** A cartridge begins with a magic — `80 37 12 40` (z64), `37 80 40 12` (v64, byte
   swapped) or `40 12 37 80` (n64, word swapped). No file here begins with any of them.
2. **not the cartridge.** No file larger than 1 MiB hashes to `rom_sha256` from the committed
   `manifests/manifest.json`. This is name-independent: a renamed, re-extensioned dump still fails.
3. **no oversized blob.** 4 MiB per file (the largest tracked file is 1.6 MB), so a stray asset or a
   compressed member cannot slip in under cover of a text-looking path.
4. **the fixture exemption is one file.** `fixtures/corpus/cart.z64` — 8 192 bytes of synthetic words,
   committed on purpose since M129 — is allowlisted by name, must stay ≤ 1 MiB, and must not carry a magic.
   `fixtures/` gets no blanket exemption.
5. **no ROM-ish paths.** Nothing under `rom/`, `assets/` or `build/`, and no `docs/*.pdf` (the three
   Nintendo SDK manuals are local reference and gitignored).

Usage:
  ./artefact_scan.py            # the gate (prints N/M, exits non-zero on any failure)
  ./artefact_scan.py --self-test
"""
import argparse
import hashlib
import json
import os
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
MANIFEST = "manifests/manifest.json"
MAGICS = (b"\x80\x37\x12\x40", b"\x37\x80\x40\x12", b"\x40\x12\x37\x80")
FIXTURE = "fixtures/corpus/cart.z64"
FIXTURE_MAX = 1 << 20             # 1 MiB
FILE_MAX = 4 << 20                # 4 MiB
HASH_MIN = 1 << 20                # only hash files big enough to be a cartridge candidate
BAD_PREFIXES = ("rom/", "assets/", "build/")
BAD_SUFFIXES = (".pdf",)


def tracked(root):
    """Every tracked path, relative to `root`. Falls back to a walk when there is no work tree.

    The fallback matters: `audit_gates.py` copies the tree into a temporary directory with no `.git`, and
    a check that cannot run there is a check that cannot be audited.
    """
    try:
        out = subprocess.run(["git", "ls-files", "-z"], cwd=str(root), capture_output=True, text=True)
        if out.returncode == 0 and out.stdout:
            return [p for p in out.stdout.split("\0") if p]
    except OSError:
        pass
    found = []
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames[:] = sorted(d for d in dirnames if d not in (".git", "__pycache__"))
        for f in sorted(filenames):
            found.append(str((Path(dirpath) / f).relative_to(root)))
    return found


def expected_rom_sha(root):
    p = root / MANIFEST
    if not p.exists():
        raise SystemExit(f"{MANIFEST} is missing — it carries rom_sha256, which check 2 needs")
    return json.loads(p.read_text())["rom_sha256"]


def sha256(p):
    h = hashlib.sha256()
    with open(p, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def scan(root, files, rom_sha):
    """Return [(case name, ok, detail)] — the five content checks."""
    root = Path(root)
    detail = {"magic": [], "rom": [], "big": [], "fixture": [], "path": []}

    for rel in files:
        p = root / rel
        if not p.is_file():
            continue
        size = p.stat().st_size
        with open(p, "rb") as f:
            head = f.read(4)
        if head in MAGICS:
            detail["magic"].append(rel)
        if rel.startswith(BAD_PREFIXES) or rel.endswith(BAD_SUFFIXES):
            detail["path"].append(rel)
        if size > FILE_MAX:
            detail["big"].append(f"{rel} ({size} B)")
        if rel == FIXTURE and (size > FIXTURE_MAX or head in MAGICS):
            detail["fixture"].append(f"{rel} {size} B, head {head!r}")
        elif rel.startswith("fixtures/") and size > FIXTURE_MAX:
            detail["big"].append(f"{rel} ({size} B, unlisted fixture)")
        if size > HASH_MIN and sha256(p) == rom_sha:
            detail["rom"].append(f"{rel} ({size} B)")

    fixture_present = (root / FIXTURE).exists()
    checks = [
        ("no file begins with an N64 cartridge header", not detail["magic"],
         f"{detail['magic']}" if detail["magic"] else "0 of %d files" % len(files)),
        ("no file is the cartridge (sha256 vs the committed rom_sha256)", not detail["rom"],
         f"{detail['rom']}" if detail["rom"] else "no candidate matches"),
        (f"no file exceeds {FILE_MAX >> 20} MiB", not detail["big"],
         f"{detail['big']}" if detail["big"] else "largest is well under"),
        (f"the only fixture exemption is {FIXTURE}, ≤{FIXTURE_MAX >> 20} MiB and magic-free",
         fixture_present and not detail["fixture"],
         f"{detail['fixture']}" if detail["fixture"] else
         ("present and clean" if fixture_present else "fixture is missing")),
        ("no rom/, assets/, build/ or *.pdf is tracked", not detail["path"],
         f"{detail['path']}" if detail["path"] else "none"),
    ]
    return checks


def self_test():
    """Seven beds: each check must be shown to fire, and the allowlist to stay narrow."""
    cases = []

    def bed(files):
        d = Path(tempfile.mkdtemp(prefix="artefact."))
        for name, body in files.items():
            p = d / name
            p.parent.mkdir(parents=True, exist_ok=True)
            p.write_bytes(body)
        (d / MANIFEST).parent.mkdir(parents=True, exist_ok=True)
        (d / MANIFEST).write_text(json.dumps({"rom_sha256": "0" * 64}))
        return d

    def verdict(d, prefix):
        for name, ok, _det in scan(d, tracked(d), "0" * 64):
            if name.startswith(prefix):
                return ok
        raise AssertionError(prefix)

    d = bed({"a.txt": b"hello\n", FIXTURE: b"\0" * 8192})
    cases.append(("a clean tree passes every check", all(ok for _n, ok, _d in scan(d, tracked(d), "0" * 64)),
                  "5/5"))

    d = bed({"x.dat": MAGICS[0] + b"\0" * 100})
    cases.append(("a z64 header under a .dat name is caught",
                  verdict(d, "no file begins with") is False, "magic found"))

    d = bed({"y.bin": MAGICS[1] + b"\0" * 100})
    cases.append(("a byte-swapped (v64) header is caught",
                  verdict(d, "no file begins with") is False, "swapped magic found"))

    # a file whose hash equals the cartridge's, larger than the hashing threshold
    d = bed({})
    payload = os.urandom(2000) * 600          # ~1.2 MB
    (d / "blob.dat").write_bytes(payload)
    want = hashlib.sha256(payload).hexdigest()
    hit = [ok for name, ok, _det in scan(d, tracked(d), want) if name.startswith("no file is the cartridge")]
    cases.append(("a renamed cartridge is caught by its sha256, whatever the name",
                  hit == [False], "hash matched under the name blob.dat"))

    d = bed({"big.txt": b"x" * (FILE_MAX + 1)})
    cases.append(("a file over the size ceiling is caught",
                  verdict(d, f"no file exceeds {FILE_MAX >> 20} MiB") is False, "oversize found"))

    d = bed({FIXTURE: MAGICS[2] + b"\0" * 8192})
    cases.append(("the allowlisted fixture is still refused if it carries a magic",
                  verdict(d, "the only fixture exemption") is False, "fixture refused"))

    d = bed({"fixtures/other.bin": b"x" * (FIXTURE_MAX + 1)})
    cases.append(("a second file under fixtures/ gets no exemption",
                  verdict(d, "the only fixture exemption") is False, "unlisted fixture refused"))
    return cases


def report(cases):
    for name, ok, detail in cases:
        print(f"  {'ok  ' if ok else 'FAIL'} {name}" + (f" — {detail}" if detail else ""))
    good = sum(1 for _n, k, _d in cases if k)
    print(f"\n{good}/{len(cases)}")
    return 0 if good == len(cases) else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--self-test", action="store_true")
    args = ap.parse_args()
    if args.self_test:
        return report(self_test())
    print("artefact scan: is any cartridge content tracked?")
    return report(scan(ROOT, tracked(ROOT), expected_rom_sha(ROOT)))


if __name__ == "__main__":
    sys.exit(main())
