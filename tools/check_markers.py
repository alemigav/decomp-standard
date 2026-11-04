#!/usr/bin/env python3
"""Assert that the documents still contain the sections they are supposed to contain.

M131 built `tools/patch_text.py` so a scripted edit cannot silently do nothing. That fixes the *write*. It does
not fix the *check*: after an edit, the only thing that noticed a missing section was a human grepping for the
heading — and twice it did not notice at all. `docs/handover.md` lost two entire sections ("How green is
enforced" and "An external reference worth knowing about") that were written, committed, and absent from the file
through four commits, because `str.replace` wrote the input back unchanged and nobody looked.

This closes that loop. It knows a short list of anchors that must exist, and one structural rule — every
`docs/log/*.md` the milestone table points at must exist — so a dangling reference or a vanished section fails a
check instead of waiting to be re-read.

Design notes:

* the anchors are **literal strings**, not headings parsed as markdown: a heading whose text drifted is exactly
  the failure this is for, and parsing would be a second thing that can be wrong;
* failures name the file and the missing anchor, so the fix is obvious without opening the tool;
* `--self-test` covers the tool itself (missing marker, missing file, dangling reference, complete set), and the
  repository is checked by running it with no arguments.

Usage:
  ./check_markers.py             # check this repository
  ./check_markers.py --list      # show what is required, and why
  ./check_markers.py --self-test
"""
import argparse
import re
import sys
from pathlib import Path

HANDOVER = "docs/handover.md"
LOG = "docs/reverse_engineering_log.md"

# (file, required literal, why it is required)
MARKERS = [
    (HANDOVER, "## What this project is", "the first thing a cold session needs"),
    (HANDOVER, "## Verified state, in numbers", "the measured facts, with note pointers"),
    (HANDOVER, "## Tools, and how to run them", "the commands, including the suites"),
    (HANDOVER, "## How \"green\" is enforced", "which fixtures run where, and what CI cannot cover"),
    (HANDOVER, "## An external reference worth knowing about", "perfect_dark, and what it is good for"),
    (HANDOVER, "## The ares dump workflow — now scripted (`tools/ares_rsp.py`, M108)",
     "the ares route, and why the dumps are what it produced"),
    (HANDOVER, "## The runtime question this session chased, and where it stands",
     "the chain from a room script to the loader"),
    (HANDOVER, "## Rules this project follows (they have all been earned)",
     "the earned rules; rule 7 is the loud-patch rule"),
    (HANDOVER, "## The bank-C question: closed, with its scope stated", "the closed question, with limits"),
    (HANDOVER, "## Format reference: what is decoded", "the container, the VM and the texture, all gated"),
    (HANDOVER, "## How to rebuild", "provision, data, decompile, fixtures, gates - in that order"),
    (HANDOVER, "## 5b. Who verifies what, and the three edits that cannot happen silently",
     "the ratchet's three invariants, and the contract for whoever owns verification"),
    (HANDOVER, "## The script VM has a codename: TYRANT",
     "the name, and the caveat that it is this project's, not Capcom's"),
    (HANDOVER, "## Immediate next step", "so a rebuilt session knows where it stands"),
    (LOG, "## Retractions carried by later milestones", "the table itself, and its context"),
    (LOG, "| retracted | by | what changed |", "the retraction table header, which must survive edits"),
    (LOG, "## The errors worth remembering", "the error list; retractions are recorded in place"),
    (LOG, "## Working method that produced the answer", "how the work is done, not just what was found"),
]

NOTE_REF = re.compile(r"`(docs/log/[A-Za-z0-9._/-]+\.md)`")
INDEX_ROW = re.compile(r"^\| (M[0-9]+[a-z]?) \|")        # a milestone-table row
# Table shape. The milestone table has two legitimate formats -- the early rows are | tag | text | evidence |
# and the later ones | tag | title | detail | evidence | -- so the count is a *range*, not a value. What it
# catches is the failure M226 produced: a row inserted through a prefix anchor split its neighbour in half,
# leaving two rows of two and five cells that every other gate read as "M225 has no detail". Cells are split
# on unescaped pipes only, because `\|` inside a code span is text (three rows use it).
CELL_SPLIT = re.compile(r"(?<!\\)\|")
ROW_CELL_RANGE = (3, 4)
RETRACTION_CELLS = 3
NOTE_NUM = re.compile(r"^docs/log/(M[0-9]+[a-z]?)-")       # the milestone a note file names
TITLE_NUM = re.compile(r"^# (M[0-9]+[a-z]?)")             # the milestone a note's title claims


def headings(root, path):
    """Level-2 headings in a document, ignoring anything inside a fenced block.

    The fence tracking matters: a shell comment or a Python comment at the start of a line would
    otherwise be read as a heading and produce a phantom "unregistered heading" failure.
    """
    p = root / path
    if not p.exists():
        return []
    out, fence = [], False
    for line in p.read_text().splitlines():
        if line.startswith("```"):
            fence = not fence
            continue
        if not fence and line.startswith("## "):
            out.append(line.rstrip())
    return out


def check(root=Path(".")):
    """Return a list of (file, message) failures; empty means every anchor holds."""
    failures = []
    missing_files = set()
    for path, marker, _why in MARKERS:
        if path in missing_files:          # one message per absent file, not one per anchor in it
            continue
        p = root / path
        if not p.exists():
            failures.append((path, "file is missing"))
            missing_files.add(path)
            continue
        if marker not in p.read_text():
            failures.append((path, "missing anchor: %r" % marker))
    log = root / LOG
    if log.exists():
        for ref in sorted(set(NOTE_REF.findall(log.read_text()))):
            if not (root / ref).exists():
                failures.append((LOG, "dangling note reference: %s" % ref))
    # the reverse direction: a heading that no marker names is unprotected, and this is how a
    # document grows a section that nothing will notice losing
    for path in (HANDOVER, LOG):
        registered = {m for f, m, _w in MARKERS if f == path}
        for h in headings(root, path):
            if h not in registered:
                failures.append((path, "unregistered heading: %r" % h))
    # and the notes themselves: a note nobody indexes is a finding nobody will read, and a note that
    # does not announce its milestone is one that cannot be cross-checked at all
    refs = set(NOTE_REF.findall(log.read_text())) if log.exists() else set()
    notes_dir = root / "docs/log"
    for p in sorted(notes_dir.glob("*.md")) if notes_dir.exists() else []:
        rel = "docs/log/" + p.name
        body = p.read_text()
        if rel not in refs:
            failures.append((rel, "note is not registered in the milestone table"))
        first = body.splitlines()[0] if body.strip() else ""
        if not first.startswith("# M"):
            failures.append((rel, "note does not begin with a '# M<n>' title"))
        t = TITLE_NUM.match(first)
        f = NOTE_NUM.match(rel)
        if t and f and t.group(1) != f.group(1):
            failures.append((rel, "title says %s but the file name says %s" % (t.group(1), f.group(1))))
    # being registered is not the same as being registered correctly: a note cited under the wrong
    # milestone row is invisible to whoever reads that row. Only table rows count — a reference in
    # prose is a cross-reference, and there are two of those on purpose.
    if log.exists():
        for line in log.read_text().splitlines():
            row = INDEX_ROW.match(line)
            if not row:
                continue
            for ref in NOTE_REF.findall(line):
                n = NOTE_NUM.match(ref)
                if n and n.group(1) != row.group(1):
                    failures.append((LOG, "note %s is indexed under %s, but it is %s"
                                     % (ref, row.group(1), n.group(1))))
    # table shape: a row that lost or gained a cell still parses as a row, so the shape is checked directly
    if log.exists():
        for line in log.read_text().splitlines():
            row = INDEX_ROW.match(line)
            cells = [c for c in CELL_SPLIT.split(line.strip())[1:-1]]
            if row:
                if not (ROW_CELL_RANGE[0] <= len(cells) <= ROW_CELL_RANGE[1]) or \
                        not all(c.strip() for c in cells):
                    failures.append((LOG, "%s has %d cell(s): a row was split, a pipe went unescaped, or a "
                                     "cell is empty" % (row.group(1), len(cells))))
            elif line.startswith('| "'):
                if len(cells) != RETRACTION_CELLS or not all(c.strip() for c in cells):
                    failures.append((LOG, "retraction row has %d cells, not %d: %.60s"
                                     % (len(cells), RETRACTION_CELLS, line)))
    return failures


def self_test():
    import shutil
    import tempfile

    made = []

    def bed(files):
        d = Path(tempfile.mkdtemp())
        made.append(d)
        for name, body in files.items():
            (d / name).parent.mkdir(parents=True, exist_ok=True)
            (d / name).write_text(body)
        return d

    NOTE = "# M1 — a note\n\ntext\n"
    handover = "\n".join(m for _f, m, _w in MARKERS if _f == HANDOVER) + "\n"
    log_ok = "\n".join(m for _f, m, _w in MARKERS if _f == LOG) + "\n| M1 | x | `docs/log/M1-a.md` |\n"
    cases = []

    d = bed({HANDOVER: handover, LOG: log_ok, "docs/log/M1-a.md": NOTE})
    cases.append(("a complete document set passes", check(d) == []))

    d = bed({HANDOVER: handover.replace("## Immediate next step\n", ""), LOG: log_ok,
             "docs/log/M1-a.md": NOTE})
    f = check(d)
    cases.append(("a missing handover section is named",
                  len(f) == 1 and f[0][0] == HANDOVER and "Immediate next step" in f[0][1]))

    d = bed({LOG: log_ok, "docs/log/M1-a.md": NOTE})
    f = check(d)
    cases.append(("a missing file is reported, once per required file",
                  any(msg == "file is missing" for _p, msg in f) and len([1 for p, _ in f if p == HANDOVER]) == 1))

    d = bed({HANDOVER: handover, LOG: log_ok})
    f = check(d)
    cases.append(("a dangling note reference is caught",
                  any("dangling note reference: docs/log/M1-a.md" in msg for _p, msg in f)))

    d = bed({HANDOVER: handover, LOG: log_ok.replace("| retracted | by | what changed |\n", ""),
             "docs/log/M1-a.md": NOTE})
    f = check(d)
    cases.append(("a drifted table header in the log is caught",
                  any(p == LOG and "retracted" in msg for p, msg in f)))

    d = bed({HANDOVER: handover + "## An unregistered new section\n", LOG: log_ok,
             "docs/log/M1-a.md": NOTE})
    f = check(d)
    cases.append(("a heading absent from the marker list is caught",
                  any("unregistered heading" in msg and "unregistered new section" in msg
                      for _p, msg in f)))

    d = bed({HANDOVER: "```\n## not a heading, inside a fence\n```\n" + handover, LOG: log_ok,
             "docs/log/M1-a.md": NOTE})
    cases.append(("a ## line inside a fenced block is not treated as a heading", check(d) == []))

    d = bed({HANDOVER: handover, LOG: log_ok, "docs/log/M1-a.md": NOTE,
             "docs/log/M2-orphan.md": "# M2 — never indexed\n"})
    f = check(d)
    cases.append(("a note that the milestone table never mentions is caught",
                  any("docs/log/M2-orphan.md" == p and "not registered" in msg for p, msg in f)))

    d = bed({HANDOVER: handover, LOG: log_ok, "docs/log/M1-a.md": "no title here\n"})
    f = check(d)
    cases.append(("a note without an '# M<n>' title is caught",
                  any("does not begin with" in msg for _p, msg in f)))

    d = bed({HANDOVER: handover,
             LOG: log_ok.replace("| M1 | x |", "| M2 | x |"),
             "docs/log/M1-a.md": NOTE})
    f = check(d)
    cases.append(("a note indexed under the wrong milestone row is caught",
                  any("indexed under M2" in msg and "it is M1" in msg for _p, msg in f)))

    # M226: a row inserted through a prefix anchor split its neighbour in half, and every other gate read the
    # result as "M225 has no detail". The shape is what notices.
    d = bed({HANDOVER: handover,
             LOG: log_ok + "| M2 | **a title** | a detail | `docs/log/M2-b.md` |\n", "docs/log/M1-a.md": NOTE})
    f = check(d)
    cases.append(("a row of the newer four-cell shape passes", not [m for _p, m in f if "cell" in m]))

    d = bed({HANDOVER: handover,
             LOG: log_ok + "| M2 | **a title** |\n| M3 | a detail | `docs/log/M2-b.md` |\n",
             "docs/log/M1-a.md": NOTE})
    f = check(d)
    cases.append(("a row split in half by an insert is caught by its cell count",
                  any("has 2 cell(s)" in msg for _p, msg in f)))

    d = bed({HANDOVER: handover,
             LOG: log_ok + "| M2 | **a title** | a detail | with a stray | pipe | `docs/log/M2-b.md` |\n",
             "docs/log/M1-a.md": NOTE})
    f = check(d)
    cases.append(("an unescaped pipe inside a cell is caught",
                  any("has 6 cell(s)" in msg for _p, msg in f)))

    d = bed({HANDOVER: handover, LOG: log_ok,
             "docs/log/M1-a.md": NOTE.replace("# M1", "# M7")})
    f = check(d)
    cases.append(("a title that disagrees with its file name is caught",
                  any("title says M7" in msg for _p, msg in f)))

    d = bed({HANDOVER: handover, LOG: log_ok + "\nSee `docs/log/M1-a.md` for detail.\n",
             "docs/log/M1-a.md": NOTE})
    cases.append(("a cross-reference in prose is not treated as an index entry", check(d) == []))

    passed = 0
    for name, ok in cases:
        print("%s  %s" % ("PASS" if ok else "FAIL", name))
        passed += 1 if ok else 0
    for d in made:
        shutil.rmtree(d, ignore_errors=True)
    print("\n%d/%d" % (passed, len(cases)))
    return 0 if passed == len(cases) else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--list", action="store_true", help="show the required anchors and why")
    ap.add_argument("--root", default=".", help="repository root")
    args = ap.parse_args()

    if args.self_test:
        return self_test()

    if args.list:
        for path, marker, why in MARKERS:
            print("%-32s %-56s %s" % (path, marker, why))
        print("%-32s %s" % ("(structural)", "every docs/log/*.md the log references must exist"))
        return 0

    root = Path(args.root)
    failures = check(root)
    for path, marker, why in MARKERS:
        hit = not any(p == path and marker in msg for p, msg in failures)
        print("%s  %-28s %s" % ("PASS" if hit else "FAIL", path, marker))
    dangling = [msg for p, msg in failures if "dangling" in msg]
    print("%s  %-28s every referenced docs/log note exists (%d checked)" % (
        "FAIL" if dangling else "PASS", "(structural)",
        len(set(NOTE_REF.findall((root / LOG).read_text()))) if (root / LOG).exists() else 0))
    extra = [f for f in failures if f[1] == "file is missing"]
    for path, msg in extra:
        print("FAIL  %-28s %s" % (path, msg))

    registered_bad = [f for f in failures if "unregistered heading" in f[1]]
    print("%s  %-28s every level-2 heading is in the marker list" % (
        "FAIL" if registered_bad else "PASS", "(registration)"))
    note_bad = [f for f in failures if "not registered in the milestone table" in f[1]
                or "does not begin with" in f[1]]
    n_notes = len(list((root / "docs/log").glob("*.md"))) if (root / "docs/log").exists() else 0
    print("%s  %-28s all %d note(s) are indexed and titled '# M<n>'" % (
        "FAIL" if note_bad else "PASS", "(note registration)", n_notes))
    index_bad = [f for f in failures if "is indexed under" in f[1] or "title says" in f[1]]
    print("%s  %-28s each note is cited by its own milestone row, and titled to match" % (
        "FAIL" if index_bad else "PASS", "(index consistency)"))
    total = len(MARKERS) + 4
    failed = len({(p, m) for p, m in failures})
    print("\n%d/%d marker check(s)" % (total - min(failed, total), total))
    if failures:
        print("MARKER CHECK FAILED:")
        for path, msg in failures:
            print("  %s: %s" % (path, msg))
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
