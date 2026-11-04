# M135 — being registered is not the same as being registered correctly

M134 required every note to be cited somewhere in the milestone table. "Somewhere" is too weak: a note cited under
the wrong row is invisible to whoever reads that row, and the index then quietly lies about which milestone the
finding belongs to.

## The rule

```
PASS  (index consistency)          each note is cited by its own milestone row, and titled to match
```

Two comparisons, both from data already on disk:

* for a reference inside a **milestone-table row**, the row's `M<n>` must equal the milestone the note's file name
  declares (`docs/log/M79-…` cited by row M79). 65 such references today;
* a note's **title** must declare the same milestone as its file name (`# M79 — …` in `M79-….md`), which catches the
  case where a note is copied from one milestone and only partly renamed.

## The scope decision that matters

References also appear **in prose** — the errors list and the working-method section cite notes as
cross-references, and there are exactly two of those. Those are not index entries and must not be checked the same
way, or the rule would forbid legitimate cross-references. So the check only inspects lines matching
`^\| M<n> \|`, and a fixture case asserts that a prose reference passes.

That distinction was measured before the rule was written: 65 references inside rows, 2 outside, **0 mismatches**
either way. So the rule cost no cleanup — it is a guard, not a repair, this time.

## Verified by breaking it

```
$ # add a second note to the M133 row
$ python3 tools/check_markers.py
MARKER CHECK FAILED:
  docs/reverse_engineering_log.md: note docs/log/M134-note-registration.md is indexed under M133, but it is M134
exit 1
$ # revert
exit 0
```

## Fixture — 12/12

Three cases added: a note cited by the wrong row, a title that disagrees with its file name, and a **prose
cross-reference that must not be flagged**. That third one is the guard on the guard: without it, a later
"tightening" could make the check reject the log's own cross-references and someone would relax it entirely.

`doc markers` is now **12** synthetic + **18** repository checks (14 anchors + 4 aggregate rules). Suite total:
**90 cases across 9 fixtures** (10 + 12 + 3 + 6 + 8 + 6 + 12 + 18 + 15).

## What is still not covered

The row's *prose* can describe a different milestone than the note it cites — only the note pointer and the note's
own title are compared, not the narrative. Catching that needs semantics, not structure.

## Reproduce

```
python3 tools/check_markers.py --self-test    # 12/12
python3 tools/check_markers.py                # 18/18
python3 tools/acceptance.py                   # 90 cases, 9 fixtures
```
