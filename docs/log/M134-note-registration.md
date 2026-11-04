# M134 — the registration check extended to the notes themselves

M133 made the *headings* of two documents registered. The 64 files in `docs/log/` were still ungoverned: a note
could exist, be cited nowhere, and never be read — which is how a milestone with a real finding ends up invisible in
the index that is supposed to be the project's table of contents.

## The rule

```
PASS  (note registration)          all 64 note(s) are indexed and titled '# M<n>'
```

Two conditions per note, and nothing more:

* the note's path must appear as a `` `docs/log/….md` `` reference somewhere in
  `docs/reverse_engineering_log.md` — an index entry, which is what "registered" means here;
* its first line must begin `# M`, so a note announces its milestone and can be cross-checked against the file name.

## What it found immediately

Two gaps, both real:

* **`M79-interrupt-scope.md` had no index row at all.** The milestone existed, the note recorded a substantial
  finding (three PI interrupts dispatching into three threads with mask `0x0999` and pending `0x0010` recorded at
  dispatch, and nothing posting because no *work* exists), and the index simply skipped from M78 to M81. The note is
  now indexed as M79.
* **`M2-boot-code-decompiles.md` was a second M2 note** ("M2 (partial) — real ROM code reaches the decompiler") that
  the M2 row never mentioned. It is now listed beside `M2-code-data-boundaries.md`.

Neither would have been found by reading the index: by construction, an unindexed note is not in the thing you would
read.

## Verified by breaking it

```
$ printf '# M79 — an orphan probe note\n\nprobe\n' > docs/log/M79-orphan-probe.md
$ python3 tools/check_markers.py
FAIL  (note registration)          all 65 note(s) are indexed and titled '# M<n>'
MARKER CHECK FAILED:
  docs/log/M79-orphan-probe.md: note is not registered in the milestone table
exit 1
$ rm the probe
exit 0
```

## Fixture — 9/9

Two cases added, and one existing bed had to change: the synthetic notes now carry a `# M1 — a note` title, because
the title rule applies to them too. That is the fixture catching my own fixture — the same shape as M132's
nine-messages-for-one-missing-file.

```
PASS  a note that the milestone table never mentions is caught     <- new
PASS  a note without an '# M<n>' title is caught                   <- new
```

## Counts

`doc markers`: **9** synthetic cases, **17** repository checks (14 anchors + 3 aggregate rules). Suite total:
**86 cases across 9 fixtures**, all run by the hook and by `ci.sh`.

## What is still not covered

The reference can point at the *wrong* row — a note listed under a milestone it does not describe passes. And a note
can be indexed while its content is stale; nothing here compares the note to the code. Both are beyond a structural
check, and both are the kind of thing a reader notices rather than a script.

## Reproduce

```
python3 tools/check_markers.py --self-test    # 9/9
python3 tools/check_markers.py                # 17/17
python3 tools/acceptance.py                   # 86 cases, 9 fixtures
```
