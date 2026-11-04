# M131 — a scripted edit now fails loudly instead of doing nothing

Three no-op patches in one arc: a dispatch table in `provenance.py` (`--corpus-self-test` parsed, was never
called, and the run silently printed the real census), a missing block in `ci.sh`, and **two handover sections**
(M128's enforcement table and M129's external-reference section) that were written, committed, and absent from
the file. The mechanism is always the same: `str.replace` returns the input unchanged when the anchor has
drifted, the script writes the same bytes back, and the commit message describes a change that is not there.

## `tools/patch_text.py`

Exact replacements, with the failure modes made loud:

| rule | why |
|---|---|
| the anchor must occur exactly `count` times (default 1) | an anchor found twice is a coin flip, and zero is the silent case |
| **all edits or none** | "the first two applied, the third did not" is the least recoverable outcome |
| `old == new` is an error | a replacement that cannot change anything is a no-op by construction |
| empty `old` is an error | it would match everywhere |
| the file is re-read after writing | a write that did not take is a failure, not a success |
| every file is written atomically | no half-written document |

Spec is JSON on stdin or `--spec`:

```
{"edits": [{"file": "docs/handover.md", "old": "…", "new": "…"},
           {"file": "tools/x.py", "old": "…", "new": "…", "count": 3}]}
```

Failure looks like this, and nothing is written:

```
$ printf '{"edits":[{"file":"docs/handover.md","old":"this anchor does not exist","new":"x"}]}' | patch_text.py
PATCH FAILED: edit 1: docs/handover.md — expected 1 occurrence(s) of the anchor, found 0
  anchor starts: 'this anchor does not exist'
nothing was written
exit=1
```

## Fixture — 6/6

```
PASS  an exact match is applied
PASS  a missing anchor fails instead of writing a no-op
PASS  an ambiguous anchor fails
PASS  edits are atomic: one bad anchor leaves every file untouched
PASS  a replacement that would change nothing is rejected
PASS  an explicit count is honoured
```

The tests initially left two of my own mistakes in the tool: a counter that always returned 1, and a cleanup step
that globbed `/tmp/tmp*` and would have deleted any unrelated temporary directory containing an `a.txt`. Both are
fixed — the cleanup now removes exactly the beds the test created. A test that damages the environment is worse
than no test.

## Wired in

* `tools/acceptance.py` gained the suite (7 fixtures, **60 cases**), so the pre-commit hook runs it;
* handover rule **7** now states the rule and names the tool;
* the two wiring edits in this milestone were themselves applied through `patch_text.py`, which is the only
  sensible way to introduce a guard against silent patches.

## What this does not catch

A patch that matches the wrong-but-plausible anchor. `patch_text` guarantees the edit landed where it was told
to; it cannot know the text chosen was the right text. That is still the marker-grep step in the rules, and it is
why the two missing handover sections were found by grepping for their headings rather than by re-reading a diff.
