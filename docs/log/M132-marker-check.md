# M132 — the marker check: the loop M131 left open

`tools/patch_text.py` (M131) stops a scripted edit from silently doing nothing. It cannot stop the *next* thing
from going unnoticed: after an edit lands, somebody has to verify the document actually says what it should. Twice
that verification did not happen — `docs/handover.md` was missing two whole sections through four commits — and
both times the failure was invisible because the file was valid, just incomplete.

## `tools/check_markers.py`

A short list of anchors that must exist, checked as **literal strings**, plus one structural rule.

```
$ python3 tools/check_markers.py
PASS  docs/handover.md               ## What this project is
PASS  docs/handover.md               ## Verified state, in numbers
PASS  docs/handover.md               ## Tools, and how to run them
PASS  docs/handover.md               ## How "green" is enforced
PASS  docs/handover.md               ## An external reference worth knowing about
PASS  docs/handover.md               ## Rules this project follows
PASS  docs/handover.md               ## The bank-C question: closed, with its scope stated
PASS  docs/handover.md               ## Immediate next step
PASS  docs/reverse_engineering_log.md  | retracted | by | what changed |
PASS  docs/reverse_engineering_log.md  ## The errors worth remembering
PASS  docs/reverse_engineering_log.md  ## Working method that produced the answer
PASS  (structural)                   every referenced docs/log note exists (60 checked)

12/12 marker check(s)
```

Choices worth stating:

* **literal strings, not parsed headings.** A heading whose text drifted is exactly the failure this exists for;
  parsing markdown would add a second thing that can be wrong.
* **one aggregate structural rule**: every `docs/log/*.md` the milestone table points at must exist. That is the
  dangling-reference class — including the stray file a mistyped shell redirect once produced — and it currently
  covers 60 references.
* **`--list`** prints the anchors and *why* each is required, so the list is self-documenting rather than a magic
  array someone deletes when it gets in the way.

## Fixture — 5/5, and the repository check is a suite too

```
PASS  a complete document set passes
PASS  a missing handover section is named
PASS  a missing file is reported, once per required file
PASS  a dangling note reference is caught
PASS  a drifted table header in the log is caught
```

Writing the third case found a real defect in the tool: a missing file was reported **once per anchor inside it**
(nine messages for the handover). The fixture expected one, the tool emitted nine — so the tool was fixed rather
than the expectation, and the fixture is what forced the question.

Two suites are wired into `tools/acceptance.py`: the synthetic fixture (**5**) and the repository's own markers
(**12**). Total is now **77 cases across 9 fixtures**, and the pre-commit hook plus `ci.sh` run all of it — so a
document that loses a section fails the next commit, locally, without anyone remembering to grep.

## What this still cannot do

It checks that the *anchors* are present, not that the prose under them is right: a section can be emptied and
still pass. And the anchor list is maintained by hand — an important new section is unprotected until someone adds
it. Both are acceptable for the failure actually observed (whole sections vanishing silently), and neither is a
reason to trust the documents further than the anchors go.

## Reproduce

```
python3 tools/check_markers.py            # 12/12
python3 tools/check_markers.py --list     # what is required, and why
python3 tools/check_markers.py --self-test
python3 tools/acceptance.py               # 77 cases, 9 fixtures
```
