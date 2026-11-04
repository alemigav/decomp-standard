#!/usr/bin/env python3
"""Apply exact string replacements, and **fail loudly** when a replacement would do nothing.

Three times in one arc a scripted edit silently did nothing: `str.replace` returns the input unchanged when the
anchor is not found, the file is written back identical, and the commit message describes a change that is not
there. Two of those were handover edits — the document the project says to start from — and one was a dispatch
table, so the flag parsed and was never called.

The rule this tool enforces: an edit either matches exactly and is verified, or the run fails and **no file is
written**. It is atomic across all edits, because "the first two applied, the third did not" is the least
recoverable outcome.

Spec, as JSON on stdin or `--spec FILE`:

    {"edits": [
      {"file": "docs/handover.md", "old": "…", "new": "…"},
      {"file": "tools/x.py", "old": "…", "new": "…", "count": 3}
    ]}

`count` is the required number of occurrences (default: exactly 1). Ambiguity is a failure, not a coin flip.

Usage:
  ./patch_text.py --self-test
  cat spec.json | ./patch_text.py
  ./patch_text.py --spec spec.json
"""
import argparse
import json
import shutil
import sys
import tempfile
from pathlib import Path


class PatchError(Exception):
    pass


def apply_edits(edits, root=Path(".")):
    """Apply every edit or none. Returns a list of (file, count) actually changed."""
    planned = {}
    for n, e in enumerate(edits, 1):
        try:
            path = root / e["file"]
            old, new = e["old"], e["new"]
            want = int(e.get("count", 1))
        except KeyError as exc:
            raise PatchError("edit %d is missing key %s" % (n, exc))
        if old == new:
            raise PatchError("edit %d: `old` and `new` are identical — that is a no-op by construction" % n)
        if not old:
            raise PatchError("edit %d: empty `old` would match everywhere" % n)
        text = planned.get(path, None)
        if text is None:
            if not path.exists():
                raise PatchError("edit %d: %s does not exist" % (n, path))
            text = path.read_text()
        found = text.count(old)
        if found != want:
            where = ""
            head = old.strip().splitlines()[0][:70] if old.strip() else ""
            if head:
                where = "  anchor starts: %r" % head
            raise PatchError("edit %d: %s — expected %d occurrence(s) of the anchor, found %d%s"
                             % (n, e["file"], want, found, where))
        planned[path] = text.replace(old, new)
    # verification, before any write
    for path, text in planned.items():
        if text == path.read_text():
            raise PatchError("%s would be written unchanged" % path)
    changed = []
    for path, text in planned.items():
        tmp = Path(tempfile.mkdtemp()) / path.name
        tmp.write_text(text)
        # `replace` installs a *new* inode, so the original's mode goes with the old file: without this
        # every edit dropped the executable bit, and an edit to tools/pre-commit.sh would have quietly
        # disabled the commit hook. Found when a ci.sh edit changed 100755 to 100644 (M174).
        shutil.copymode(path, tmp)
        tmp.replace(path)                     # atomic per file
        back = path.read_text()
        if back != text:
            raise PatchError("%s did not read back as written" % path)
        changed.append(str(path))
    return changed


def self_test():
    cases = []
    made = []

    def bed(files):
        d = Path(tempfile.mkdtemp())
        made.append(d)
        for name, body in files.items():
            (d / name).write_text(body)
        return d

    d = bed({"a.txt": "one two three\n"})
    try:
        apply_edits([{"file": "a.txt", "old": "two", "new": "2"}], d)
        cases.append(("an exact match is applied",
                      (d / "a.txt").read_text() == "one 2 three\n"))
    except PatchError as exc:
        cases.append(("an exact match is applied", False))
        print("      unexpected: %s" % exc)

    d = bed({"a.txt": "one two three\n"})
    try:
        apply_edits([{"file": "a.txt", "old": "two", "new": "two"}], d)
        cases.append(("an edit whose old and new are identical is refused", False))
    except PatchError as exc:
        # the *specific* guard must be the one that fired: any PatchError would also pass if a later
        # verification happened to reject the edit, which makes the case vacuous (found by audit_gates).
        cases.append(("an edit whose old and new are identical is refused",
                      "identical" in str(exc) and (d / "a.txt").read_text() == "one two three\n"))

    d = bed({"a.txt": "one two three\n"})
    before = (d / "a.txt").read_text()
    try:
        apply_edits([{"file": "a.txt", "old": "four", "new": "4"}], d)
        cases.append(("a missing anchor fails instead of writing a no-op", False))
    except PatchError:
        cases.append(("a missing anchor fails instead of writing a no-op",
                      (d / "a.txt").read_text() == before))

    d = bed({"a.txt": "x x\n"})
    before = (d / "a.txt").read_text()
    try:
        apply_edits([{"file": "a.txt", "old": "x", "new": "y"}], d)      # 2 occurrences, want 1
        cases.append(("an ambiguous anchor fails", False))
    except PatchError:
        cases.append(("an ambiguous anchor fails", (d / "a.txt").read_text() == before))

    d = bed({"a.txt": "aaa\n", "b.txt": "bbb\n"})
    before_a, before_b = (d / "a.txt").read_text(), (d / "b.txt").read_text()
    try:
        apply_edits([{"file": "a.txt", "old": "aaa", "new": "AAA"},
                     {"file": "b.txt", "old": "zzz", "new": "ZZZ"}], d)
        cases.append(("edits are atomic: one bad anchor leaves every file untouched", False))
    except PatchError:
        cases.append(("edits are atomic: one bad anchor leaves every file untouched",
                      (d / "a.txt").read_text() == before_a and (d / "b.txt").read_text() == before_b))

    d = bed({"a.txt": "same\n"})
    try:
        apply_edits([{"file": "a.txt", "old": "same", "new": "same"}], d)
        cases.append(("a replacement that would change nothing is rejected", False))
    except PatchError:
        cases.append(("a replacement that would change nothing is rejected", True))

    d = bed({"a.txt": "a a a\n"})
    try:
        apply_edits([{"file": "a.txt", "old": "a", "new": "b", "count": 3}], d)
        cases.append(("an explicit count is honoured",
                      (d / "a.txt").read_text() == "b b b\n"))
    except PatchError as exc:
        cases.append(("an explicit count is honoured", False))
        print("      unexpected: %s" % exc)

    d = bed({"hook.sh": "#!/bin/sh\necho hi\n"})
    (d / "hook.sh").chmod(0o755)
    try:
        apply_edits([{"file": "hook.sh", "old": "hi", "new": "hello"}], d)
        cases.append(("an edit preserves the file's mode", (d / "hook.sh").stat().st_mode & 0o777 == 0o755))
    except PatchError:
        cases.append(("an edit preserves the file's mode", False))

    passed = 0
    for name, ok in cases:
        print("%s  %s" % ("PASS" if ok else "FAIL", name))
        passed += 1 if ok else 0
    for d in made:                      # only the beds this test made, never a /tmp glob
        shutil.rmtree(d, ignore_errors=True)
    print("\n%d/%d" % (passed, len(cases)))
    return 0 if passed == len(cases) else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--spec", help="JSON file; default is stdin")
    ap.add_argument("--root", default=".", help="base directory for relative paths")
    args = ap.parse_args()

    if args.self_test:
        return self_test()

    raw = Path(args.spec).read_text() if args.spec else sys.stdin.read()
    try:
        spec = json.loads(raw)
        edits = spec["edits"]
        if not isinstance(edits, list) or not edits:
            raise PatchError("`edits` must be a non-empty list")
        changed = apply_edits(edits, Path(args.root))
    except PatchError as exc:
        print("PATCH FAILED: %s" % exc, file=sys.stderr)
        print("nothing was written", file=sys.stderr)
        return 1
    except (json.JSONDecodeError, KeyError) as exc:
        print("PATCH FAILED: bad spec (%s)" % exc, file=sys.stderr)
        return 1

    for path in changed:
        print("patched %s" % path)
    print("%d file(s) changed, each verified after write" % len(changed))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
