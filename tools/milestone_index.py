#!/usr/bin/env python3
"""Generate `docs/MILESTONES.md`: every milestone, in order, with its evidence.

The record of this project is `docs/reverse_engineering_log.md` (one table row per milestone, plus a
retraction table) and `docs/log/M<n>-*.md` (one note per milestone). Neither is readable as a history: the
log's rows are **not in ascending order** — M0–M9 ascend, then M30→M10 *descend*, then M79, then M81→M176
ascend — and 50 milestone numbers have no row at all. This tool reads all three sources and emits the
recollection a reader actually wants, with the gaps named rather than papered over:

    rows in the log   129 rows / 127 distinct numbers (M19 and M23 each appear twice)
    notes             106 files
    gaps              50 numbers: 31–78, 80, 172 — of which 48, 51, 78 and 172 survive as commit subjects

Duplicated numbers are **not renamed**: the log's prose and the commit subjects say `M19`/`M23`, and
renumbering history to make a table tidier is a claim edit nothing can verify. The index marks them
(i)/(ii) instead.

`--check` regenerates the file in memory and fails if it differs from what is committed, so the index
cannot drift from the log. It reads **no git history**: a CI clone is shallow, so what a milestone's
evidence is has to be committed — that is what `fixtures/milestones/gaps.json` is for, seeded once by the
author with `--seed-gaps`.

Usage:
  ./milestone_index.py                  # regenerate docs/MILESTONES.md
  ./milestone_index.py --check          # fail if the committed file is stale
  ./milestone_index.py --self-test      # synthetic fixtures, including the failure modes
  ./milestone_index.py --seed-gaps      # rebuild fixtures/milestones/gaps.json from git (author only)
"""
import argparse
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
LOG = "docs/reverse_engineering_log.md"
NOTES = "docs/log"
GAPS = "fixtures/milestones/gaps.json"
# Commit subjects are *committed*, never read from git at check time — the same reason `gaps.json` is:
# a CI clone is shallow, so consulting history there would make the check fail on the environment rather
# than on the record. `--seed-gaps` rebuilds both.
CYCLE = 6          # milestones per cycle (docs/VERIFICATION.md: a cycle is the landing unit)
COMMITS = "fixtures/milestones/commits.json"
OUT = "docs/MILESTONES.md"
MAX = 176                    # the highest milestone number with a row; gaps may extend below only

ROW = re.compile(r"^\| (M\d+[a-z]?) \|")
TITLE = re.compile(r"^# (M\d+)[^—]*—\s*(.+)$")      # 'M2 (partial) — …' is a title too
CELL_SPLIT = re.compile(r"(?<!\\)\|")          # split on pipes that are not escaped


# --------------------------------------------------------------------------- parsing
def parse_log(text):
    """[(number:int, suffix:str, outcome:str, detail:str)] from the log's milestone table."""
    rows = []
    for line in text.splitlines():
        m = ROW.match(line)
        if not m:
            continue
        cells = [c.strip() for c in CELL_SPLIT.split(line.strip())[1:-1]]
        outcome = cells[1] if len(cells) > 1 else ""
        detail = cells[2] if len(cells) > 2 else ""
        tag = m.group(1)
        num = int(re.sub(r"[^0-9]", "", tag))
        rows.append({"tag": tag, "num": num, "outcome": outcome, "detail": detail})
    return rows


def parse_notes(root):
    """{number: [(filename, title), ...]} from each note's first line."""
    out = {}
    d = root / NOTES
    for p in sorted(d.glob("M*.md")) if d.exists() else []:
        first = p.read_text().splitlines()[0] if p.read_text().strip() else ""
        m = TITLE.match(first)
        if not m:
            raise SystemExit(f"{p}: first line is not '# M<n> — title'")
        num = int(re.sub(r"[^0-9]", "", m.group(1)))
        out.setdefault(num, []).append((p.name, m.group(2).strip()))
    return out


def short_title(row):
    """A title for rows with no note: the bold claim, unadorned and truncated."""
    t = row["outcome"].replace("**", "")
    t = re.split(r"(?<=[.a-z0-9`])\s—\s|:\s", t, maxsplit=1)[0]
    t = t.strip().rstrip(".:;,")
    return (t[:89] + "…") if len(t) > 90 else t


def load_gaps(root):
    p = root / GAPS
    if not p.exists():
        return []
    data = json.loads(p.read_text())
    return data["gaps"] if isinstance(data, dict) else data


# --------------------------------------------------------------------------- rendering
HEADER = """# Milestones

Every milestone this project recorded, in numeric order, with the evidence behind it.

**This file is generated** by `tools/milestone_index.py`; do not edit it by hand. `--check` fails when it
and `docs/reverse_engineering_log.md` disagree, so the two cannot drift. The *record* is that log (one line
per milestone, plus a retraction table) and `docs/log/M<n>-*.md` (one note per milestone); this is the index
to them, and the frontpage carries a curated [phase table](../README.md#milestones) over the same ground.

%d milestones are indexed. %d of them have a note; the rest are rows in the log that cite
`docs/format_notes.md` instead. **%d have no record at all** — %s — and they appear in place, marked
*(no row, no note)*: an index that hides its gaps is worse than one that names them. Why they are empty is
at the foot of this file.
"""


def render(root, log_text=None, notes=None, gaps=None):
    log_text = (root / LOG).read_text() if log_text is None else log_text
    notes = parse_notes(root) if notes is None else notes
    gaps = load_gaps(root) if gaps is None else gaps

    rows = parse_log(log_text)
    by_num = {}
    for r in rows:
        by_num.setdefault(r["num"], []).append(r)

    # which note belongs to a duplicated number? the one the row names, else the first
    def note_for(num, row=None):
        cands = notes.get(num, [])
        if not cands:
            return None
        if len(cands) == 1:
            return cands[0]
        if row is not None:
            for name, title in cands:
                if name in row["detail"]:
                    return (name, title)
        return cands[0]

    gap_by_num = {}
    for g in gaps:
        n = g["n"] if isinstance(g, dict) else int(g)
        gap_by_num[n] = g if isinstance(g, dict) else {"n": n, "status": "unrecorded"}

    lines = []
    total = max(list(by_num) + list(gap_by_num) + list(notes) + [MAX]) + 1
    with_notes = len({n for n in by_num if n in notes})
    missing = sorted(gap_by_num)
    lines.append((HEADER % (total, with_notes, len(missing), _range_text(missing))).rstrip())
    lines.append("")
    lines.append("| # | milestone | evidence |")
    lines.append("|---|---|---|")

    for num in range(total):
        for i, row in enumerate(by_num.get(num, [])):
            suffix = f" ({'i' if i == 0 else 'ii'})" if len(by_num[num]) > 1 else ""
            note = note_for(num, row)
            title = note[1] if note else short_title(row)
            if note:
                evidence = f"`{NOTES}/{note[0]}`"
            else:
                evidence = row["detail"] or "—"
            lines.append(f"| {num} | **M{num}**{suffix} — {_esc(title)} | {_esc(evidence)} |")
        if num in gap_by_num:
            g = gap_by_num[num]
            if g.get("status") == "commit-only" and g.get("evidence"):
                ev = ", ".join(f"`{e['sha']}` “{_esc(e['subject'])}”" for e in g["evidence"][:2])
                lines.append(f"| {num} | **M{num}** — *(no row, no note)* | commit only: {ev} |")
            else:
                lines.append(f"| {num} | **M{num}** — *(no row, no note)* | no evidence in the tree |")
    gap_nums = sorted(gap_by_num)
    commit_only = sorted(n for n in gap_nums if gap_by_num[n].get("status") == "commit-only")
    lines.append("")
    lines.append("## The gaps, and why they are empty")
    lines.append("")
    lines.append(f"**{len(gap_nums)}** milestone numbers have neither a row in "
                 "`docs/reverse_engineering_log.md` nor a note in `docs/log/`. The project did not keep a "
                 "note for every number it used: much of the middle work was recorded in "
                 "`docs/format_notes.md` and in commit messages instead, and the log's own numbering runs "
                 "M10–M30 in that style before resuming per-milestone notes at M81.")
    lines.append("")
    if commit_only:
        shown = ", ".join(f"M{n}" for n in commit_only)
        lines.append(f"* **{shown}** survive only as commit subjects, quoted above. Nothing further is "
                     "known about them, so nothing further is written.")
    lines.append(f"* **{_range_text([n for n in gap_nums if n not in commit_only])}** have no evidence in the "
                 "tree at all — no row, no note, no commit that names them.")
    lines.append("")
    lines.append("None of these gaps is reconstructed after the fact. A note written from guesswork would "
                 "be indistinguishable from a note written from measurement, and this project's whole "
                 "claim is that the difference is visible.")
    return "\n".join(lines) + "\n"


def load_commit_milestones(root):
    """Every milestone number named in a commit subject, from the committed fixture."""
    p = root / COMMITS
    if not p.exists():
        return set()
    return {int(n) for c in json.loads(p.read_text()).get("commits", [])
            for n in c.get("milestones", [])}


def record_highest(root):
    """The highest number the record accounts for — row, note or named gap."""
    nums = {r["num"] for r in parse_log((root / LOG).read_text())}
    nums |= set(parse_notes(root))
    nums |= {(g["n"] if isinstance(g, dict) else int(g)) for g in load_gaps(root)}
    return max(nums) if nums else 0


def _esc(s):
    return s.replace("|", "\\|").replace("\n", " ")


def _range_text(nums):
    """31-78, 80, 172 from a sorted list."""
    if not nums:
        return "none"
    out, start, prev = [], nums[0], nums[0]
    for n in nums[1:]:
        if n == prev + 1:
            prev = n
            continue
        out.append(f"{start}–{prev}" if prev > start else f"{start}")
        start = prev = n
    out.append(f"{start}–{prev}" if prev > start else f"{start}")
    return ", ".join(out)


# --------------------------------------------------------------------------- coverage
def coverage(root, log_text=None, notes=None, gaps=None):
    """The checks --check runs. Returns [(name, ok, detail)]."""
    log_text = (root / LOG).read_text() if log_text is None else log_text
    notes = parse_notes(root) if notes is None else notes
    gaps = load_gaps(root) if gaps is None else gaps
    rows = parse_log(log_text)
    row_nums = {r["num"] for r in rows}
    gap_nums = {(g["n"] if isinstance(g, dict) else int(g)) for g in gaps}

    cases = []
    missing_row_notes = sorted(n for n in row_nums if n not in notes)
    # A row must begin its line. This is not pedantry: M106 and M107 were once pasted into the middle of a
    # paragraph in the errors section, where the row regex never looked and no gate noticed (fixed in M177).
    anywhere = len(re.findall(r"\| M\d+[a-z]? \|", log_text))
    cases.append((f"no milestone row appears anywhere but at the start of a line ({anywhere} found)",
                  anywhere == len(rows),
                  f"{anywhere} occurrences vs {len(rows)} rows — {anywhere - len(rows)} spliced into prose"))

    cases.append((f"{len(rows)} rows, {len(row_nums)} distinct numbers, {len(notes)} notes",
                  len(rows) >= len(row_nums) and len(row_nums) >= len(notes) and all(
                      len(r["outcome"]) and len(r["detail"]) for r in rows),
                  f"{len(rows)} / {len(row_nums)} / {len(notes)}"))

    overlap = sorted(row_nums & gap_nums)
    cases.append(("no gap number also has a log row", not overlap, f"overlap {overlap}" if overlap else "0"))

    orphans = sorted(n for n in notes if n not in row_nums)
    cases.append(("every note is cited by a row of its own number", not orphans,
                  f"notes with no row: {orphans}" if orphans else "0"))

    covered = row_nums | gap_nums
    missing = [n for n in range(0, max(covered) + 1) if n not in covered]
    cases.append(("every number from 0 to the highest is a row, a note or a named gap", not missing,
                  f"unaccounted: {missing[:6]}" if missing else f"{len(covered)} numbers accounted for"))

    unevidenced = [g for g in gaps if isinstance(g, dict) and g.get("status") == "commit-only"
                   and not g.get("evidence")]
    bad_status = [g for g in gaps if isinstance(g, dict) and g.get("status") not in ("commit-only", "unrecorded")]
    cases.append(("every gap states its status, and commit-only gaps carry the commits",
                  not unevidenced and not bad_status,
                  f"{len(unevidenced)} commit-only without evidence, {len(bad_status)} bad status"))

    # A milestone that exists only as a commit subject. M181 was exactly this: the verifier was committed
    # with a contract and no record, and nothing noticed, because the check below only requires every
    # number *up to the highest* — so a trailing milestone with no row is structurally invisible.
    committed = load_commit_milestones(root)
    unaccounted_commits = sorted(n for n in committed if n not in (covered | set(notes)))
    cases.append((f"every M<n> in a commit subject is a row, a note or a named gap "
                  f"({len(committed)} numbers, max {max(committed) if committed else 0})",
                  not unaccounted_commits,
                  f"commits with no record: {unaccounted_commits[:6]}" if unaccounted_commits
                  else "all accounted for"))

    cases.append((f"rows without a note fall back to format_notes ({len(missing_row_notes)})",
                  all(rows[i]["detail"] for i in range(len(rows)) if rows[i]["num"] in missing_row_notes),
                  "every row-without-note names its evidence"))
    return cases


def check(root):
    expected = render(root)
    p = root / OUT
    cases = coverage(root)
    # The two cases are two-sided, like `acceptance.py` and the ratchet: the accounting case above catches a
    # commit with no record, and this one catches a record with no commit re-seed. A milestone cannot land
    # with one without failing the other.
    # A milestone's row is written *before* its commit exists, so the fixture is legitimately one behind
    # while a milestone is mid-landing: require the lag to be at most one. Requiring equality would fail on
    # every milestone in progress, and requiring nothing would let the fixture sleep forever; a lag of two
    # means a landing skipped the re-seed. The cost is stated rather than hidden: a skipped re-seed is
    # caught at the *next* milestone, not the same one.
    committed = load_commit_milestones(root)
    highest = record_highest(root)
    fixture = root / COMMITS
    top = max(committed) if committed else 0
    # M210: the lag is one **cycle**, not one milestone. Milestones are written and gated inside a cycle and
    # land together in its single commit, so while a cycle is open the record legitimately runs ahead of the
    # commit fixture by up to its size. The check still catches the thing it was built for -- a milestone whose
    # commit never arrives -- because a lag beyond a full cycle means the row outlived its landing.
    fresh = fixture.exists() and bool(committed) and highest - top <= CYCLE
    cases.append((f"the commit fixture is within one cycle of the record (commits reach {top}, "
                  f"the record reaches {highest}, cycle {CYCLE})", fresh,
                  "within the cycle lag" if fresh else ("fixture missing" if not fixture.exists()
                                           else "stale — run tools/milestone_index.py --seed-gaps")))
    cases.append((f"{OUT} matches the log, the notes and the gaps", p.exists() and p.read_text() == expected,
                  "identical" if p.exists() and p.read_text() == expected
                  else ("file is missing" if not p.exists() else "stale — run tools/milestone_index.py")))
    return cases


# --------------------------------------------------------------------------- self-test
def self_test():
    """Synthetic beds, one per failure mode this tool exists to catch. 8 cases."""
    cases = []

    def bed(files):
        d = Path(tempfile.mkdtemp(prefix="ms."))
        for name, body in files.items():
            p = d / name
            p.parent.mkdir(parents=True, exist_ok=True)
            p.write_text(body)
        return d

    def verdict(cases, prefix):
        for name, ok, _detail in cases:
            if name.startswith(prefix):
                return ok
        raise AssertionError(f"no case starts with {prefix!r}")

    def log(*rows):
        body = "| milestone | outcome | detail |\n|---|---|---|\n"
        for tag, outcome, detail in rows:
            body += f"| {tag} | {outcome} | {detail} |\n"
        return body

    # 1. duplicates are kept and marked (i)/(ii), never renamed
    d = bed({LOG: log(("M19", "**first**", "`docs/format_notes.md`"),
                      ("M19", "**second**", "`docs/format_notes.md`")),
             GAPS: '{"gaps": []}'})
    text = render(d, gaps=[])
    cases.append(("a duplicated number is kept and marked (i)/(ii)",
                  "**M19** (i)" in text and "**M19** (ii)" in text, "both rows rendered"))

    # 2. non-monotonic rows are sorted, not trusted
    d = bed({LOG: log(("M5", "**five**", "`docs/format_notes.md`"),
                      ("M3", "**three**", "`docs/format_notes.md`")), GAPS: '{"gaps": []}'})
    text = render(d, gaps=[])
    cases.append(("rows are sorted numerically regardless of file order",
                  text.index("**M3**") < text.index("**M5**"), "M3 above M5"))

    # 3. an escaped pipe inside a cell survives the split
    d = bed({LOG: log(("M1", "**one** with a \\| pipe", "`docs/format_notes.md`")), GAPS: '{"gaps": []}'})
    rows = parse_log((d / LOG).read_text())
    cases.append(("an escaped pipe does not split a cell",
                  len(rows) == 1 and "\\|" in rows[0]["outcome"], f"{rows[0]['outcome'][:40]!r}"))

    # 4. a note's title wins over the row's prose
    d = bed({LOG: log(("M7", "**the row says this**", "`docs/log/M7-x.md`")),
             "docs/log/M7-x.md": "# M7 — the note says this\n", GAPS: '{"gaps": []}'})
    text = render(d, gaps=[])
    cases.append(("a note's H1 title is preferred to the log row",
                  "the note says this" in text and "the row says this" not in text, "note wins"))

    # 5. a gap with commits renders its evidence; one without says so
    d = bed({LOG: log(("M1", "**one**", "`docs/format_notes.md`")), GAPS: '{"gaps": []}'})
    text = render(d, gaps=[{"n": 2, "status": "commit-only", "evidence": [{"sha": "abc1234", "subject": "did a thing"}]},
                           {"n": 3, "status": "unrecorded"}])
    cases.append(("a gap renders its commits, or states that there are none",
                  "abc1234" in text and "no evidence in the tree" in text, "both shapes rendered"))

    # 6. a gap that collides with a row is a failure
    d = bed({LOG: log(("M1", "**one**", "`docs/format_notes.md`")), GAPS: '{"gaps": []}'})
    cases.append(("a gap number that also has a row is refused",
                  verdict(coverage(d, gaps=[{"n": 1, "status": "unrecorded"}]), "no gap number") is False,
                  "overlap detected"))

    # 7. an orphan note (no row of its own number) is a failure
    d = bed({LOG: log(("M1", "**one**", "`docs/format_notes.md`")),
             "docs/log/M9-y.md": "# M9 — orphan\n", GAPS: '{"gaps": []}'})
    cases.append(("a note with no row of its own number is refused",
                  verdict(coverage(d, gaps=[]), "every note is cited by a row") is False, "orphan detected"))

    # 8. a row spliced into prose is caught — this is not hypothetical: M106 and M107 were once pasted
    # into the middle of error item 5 of the log, where the row regex never looked (fixed in M177)
    d = bed({LOG: log(("M1", "**one**", "`docs/format_notes.md`")) + "\nsome prose  | M2 | **two** | x |  and more\n",
             GAPS: '{"gaps": []}'})
    cases.append(("a row spliced into prose is refused",
                  verdict(coverage(d, gaps=[]), "no milestone row appears anywhere") is False,
                  "splice detected"))

    # 10. a milestone that exists only as a commit subject — the M181 shape, which no existing case could
    # see because everything below the highest number was accounted for
    d = bed({LOG: log(("M1", "**one**", "`docs/format_notes.md`")), GAPS: '{"gaps": []}',
             COMMITS: json.dumps({"commits": [{"sha": "abc1234", "subject": "M2: ghost",
                                               "milestones": [2]}]})})
    cases.append(("a milestone that exists only as a commit subject is refused",
                  verdict(coverage(d, gaps=[]), "every M<n> in a commit subject") is False,
                  "M181-shaped gap detected"))

    # 11. the other side: rows landed but the commit fixture was not re-seeded. M210 widened the tolerance
    # from one milestone to one *cycle* (rows are written inside a cycle and land in its single commit), so
    # this case now needs a lag past a full cycle -- which is exactly the state it is meant to refuse.
    d = bed({LOG: log(("M1", "**one**", "`docs/format_notes.md`"), ("M2", "**two**", "`docs/format_notes.md`")),
             GAPS: '{"gaps": []}',
             COMMITS: json.dumps({"commits": [{"sha": "abc1234", "subject": "M1: one", "milestones": [1]}]})})
    (d / LOG).write_text(log(*[(f"M{n}", f"**{n}**", "`docs/format_notes.md`") for n in range(1, CYCLE + 3)]))
    cases.append(("a stale commit fixture is refused (a full cycle of landings without re-seeding)",
                  verdict(check(d), "the commit fixture is within one cycle") is False, "staleness detected"))

    # 9. --check fails on a tampered output file
    d = bed({LOG: log(("M1", "**one**", "`docs/format_notes.md`")), GAPS: '{"gaps": []}'})
    good = render(d, gaps=[])
    (d / OUT).write_text(good + "\n| 99 | hand edit | — |\n")
    cases.append(("a hand-edited index fails --check",
                  verdict(check(d), f"{OUT} matches the log") is False, "tamper detected"))
    return cases


# --------------------------------------------------------------------------- seed
def seed_gaps(root):
    """Author-only: rebuild fixtures/milestones/gaps.json from the log and git history."""
    rows = {r["num"] for r in parse_log((root / LOG).read_text())}
    notes = set(parse_notes(root))
    logged = subprocess.run(["git", "log", "--format=%H\t%s"], cwd=str(root),
                            capture_output=True, text=True).stdout.splitlines()
    evidence = {}
    for line in logged:
        sha, subject = line.split("\t", 1)
        for m in re.findall(r"\bM(\d+)\b", subject):
            evidence.setdefault(int(m), []).append({"sha": sha[:7], "subject": subject})
    gaps = []
    for n in range(0, max(rows) + 1):
        if n in rows or n in notes:
            continue
        gaps.append({"n": n, "status": "commit-only" if n in evidence else "unrecorded",
                     "evidence": evidence.get(n, [])})
    out = root / GAPS
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps({"note": "Milestones with no row and no note in docs/. Seeded by "
                                       "`tools/milestone_index.py --seed-gaps`; never read from git at "
                                       "check time, because a CI clone is shallow.",
                               "gaps": gaps}, indent=1) + "\n")
    commits = []
    for line in logged:
        sha, subject = line.split("\t", 1)
        nums = sorted({int(m) for m in re.findall(r"\bM(\d+)\b", subject)})
        if nums:
            commits.append({"sha": sha[:7], "subject": subject, "milestones": nums})
    (root / COMMITS).write_text(json.dumps(
        {"note": "Commit subjects that name a milestone. Seeded with gaps.json by the same command, for the "
                 "same reason: a check must not read git history, because a CI clone is shallow.",
         "commits": commits}, indent=1) + "\n")
    return len(gaps)


def report(cases):
    for name, ok, detail in cases:
        print(f"  {'ok  ' if ok else 'FAIL'} {name}" + (f" — {detail}" if detail else ""))
    good = sum(1 for _n, k, _d in cases if k)
    print(f"\n{good}/{len(cases)}")
    return 0 if good == len(cases) else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true", help="fail if the committed index is stale")
    ap.add_argument("--self-test", action="store_true", help="synthetic fixtures only")
    ap.add_argument("--seed-gaps", action="store_true", help="rebuild the gap list from git (author only)")
    args = ap.parse_args()

    if args.self_test:
        return report(self_test())
    if args.seed_gaps:
        n = seed_gaps(ROOT)
        print(f"wrote {GAPS} with {n} gap(s)")
        return 0
    if args.check:
        return report(check(ROOT))

    text = render(ROOT)
    (ROOT / OUT).write_text(text)
    print(f"wrote {OUT} ({len(text.splitlines())} lines)")
    return report(coverage(ROOT))


if __name__ == "__main__":
    sys.exit(main())
