# M133 — the marker check now runs in both directions

M132 checked that the listed anchors are still present. That protects against a section *vanishing*; it does not
protect against a section being *added* without anyone registering it, which is how the list would slowly stop
describing the document. The check is now symmetric.

## The rule

```
PASS  (registration)               every level-2 heading is in the marker list
16/16 marker check(s)
```

Every `## ` heading in `docs/handover.md` and `docs/reverse_engineering_log.md` must appear **exactly** in the
marker list. Applied strictly, with two consequences worth stating:

* one marker was a *prefix* rather than a heading (`## Rules this project follows` against the real
  `## Rules this project follows (they have all been earned)`). Presence checks tolerate that; registration cannot,
  so markers are now exact heading text.
* **two sections were unregistered and are now protected**: "The ares dump workflow — now scripted" and "The
  runtime question this session chased, and where it stands", plus the log's "Retractions carried by later
  milestones" table header. The new rule found them immediately, which is the argument for the rule.

Heading scanning is **fence-aware**: a line starting `## ` inside a ``` block is a shell or Python comment, not a
heading, and treating it as one would produce phantom failures.

## Verified by breaking it

```
$ # add "## A brand new section nobody registered" to the handover
$ python3 tools/check_markers.py
15/16 marker check(s)
MARKER CHECK FAILED:
  docs/handover.md: unregistered heading: '## A brand new section nobody registered'
exit 1
$ # revert
$ python3 tools/check_markers.py
16/16 marker check(s)
exit 0
```

Exit status checked without a pipe (the earlier `| tail` masked it, which is the M118 lesson again in miniature).

## Fixture — 7/7

```
PASS  a complete document set passes
PASS  a missing handover section is named
PASS  a missing file is reported, once per required file
PASS  a dangling note reference is caught
PASS  a drifted table header in the log is caught
PASS  a heading absent from the marker list is caught        <- new
PASS  a ## line inside a fenced block is not treated as a heading   <- new
```

The second new case exists because the first implementation would have failed on any document containing a
commented example. It was written before the fence handling was believed.

## Counts

`tools/acceptance.py` now runs `doc markers (synthetic)` at **7** cases and `doc markers (repository)` at **16**
(14 anchors + 2 aggregate rules). Suite total: **83 cases across 9 fixtures**.

## What is still not covered

A heading can be renamed *and* registered, and the check will accept it — it guards existence and registration, not
wording. And `###` sub-headings are not scanned; the level-2 sections are the load-bearing structure, and adding
sub-headings to the list would make it noisy enough that it would get relaxed.

## Reproduce

```
python3 tools/check_markers.py            # 16/16
python3 tools/check_markers.py --list     # every anchor, with the reason it is required
python3 tools/acceptance.py               # 83 cases, 9 fixtures
```
