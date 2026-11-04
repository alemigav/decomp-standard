#!/usr/bin/env python3
"""A ratchet on the gate registry: the tree must match the baseline, and decreases need a louder flag.

The reason this exists is the project's most common defect, which is not a wrong claim but a **gate that
could not fail**: six audit environments missing a directory, two mutations that failed for the wrong
reason, a `4 852 vs 4 761` miscount read as a missing class when it was 126 aliased entries. A verifier
that owns the gates inherits that failure mode in a new form — it can make its own suite pass by lowering
an expected count, by deleting a suite, or by editing the output it is supposed to check. Each is a
one-line edit and none looks like cheating in a diff.

Three invariants, all mechanical:

  match     `tools/acceptance.py` must register exactly the suites the baseline records, with exactly the
            recorded expected counts. Any difference — added, deleted, raised **or** lowered — fails, so
            a change is never silent. Accepting it is `--write`, which shows up as a diff.
  decrease  `--write` refuses to lower a count, or to drop a suite, unless `--allow-decrease` is passed.
            So the ordinary path cannot shrink the suite; shrinking it is a second, explicit act.
  src       the hash of the whole `src/` tree must equal the baseline's. A verifier may add cases; it may
            not touch the decompiled corpus to make them pass.

**The ratchet must itself be shown to fail, or it becomes the next gate that cannot fail.** `--check` on a
healthy repository passes whether or not these comparisons are wired, so `--self-test` breaks each
invariant on a synthetic root and requires detection.

That self-test found three defects in this file while it was being written, and all three are the same
class the tool exists to prevent:

1. `importlib` may serve a cached `.pyc`, so the ratchet could read a **stale registry** and report
   "monotone" about counts it never looked at. It now compiles the source text directly.
2. The src case was **vacuous**: it ran while the registry was still dirty from the previous case, so it
   failed for the *other* reason and would have passed with the src comparison removed entirely. Every
   case now restores the tree to its baselined state first.
3. A **raised** count passed `--check` silently, so "requires `--write`" was never enforced.

  ./ratchet.py --check                       # the three invariants against fixtures/gates/ratchet.json
  ./ratchet.py --write                       # re-baseline (counts and the src/ tree) — a deliberate act
  ./ratchet.py --write --allow-decrease      # ...and the only way a count may go down
  ./ratchet.py --self-test                   # prove each invariant detects its own violation
"""
import argparse
import hashlib
import json
import shutil
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
BASELINE = Path("fixtures") / "gates" / "ratchet.json"


def suites(root: Path) -> dict:
    """{name: expected cases} from the gate registry, executed rather than imported.

    Not `importlib`: the source loader may serve a cached `.pyc`, and a ratchet that reads a stale
    registry reports "monotone" about counts it never looked at.
    """
    path = root / "tools" / "acceptance.py"
    ns = {"__file__": str(path), "__name__": "_acceptance"}
    exec(compile(path.read_text(), str(path), "exec"), ns)
    return {name: expected for name, _cmd, expected, _rom in ns["SUITES"]}


def src_tree(root: Path) -> str:
    """One hash over (relative path, content hash) for every file under src/."""
    base = root / "src"
    if not base.is_dir():
        return "(absent)"
    h = hashlib.sha256()
    for p in sorted(x for x in base.rglob("*") if x.is_file()):
        rel = p.relative_to(base)
        # Only corpus content counts. A `.DS_Store` (or `__pycache__`) is not part of the decompilation, and
        # including it made this invariant *environment-dependent*: the baseline was written on a macOS tree
        # that had `src/.DS_Store`, so every fresh clone — and therefore every CI run — failed the hash while
        # the local check passed. That is the same defect class as the six audit-environment gaps: a check
        # failing on what surrounds the data rather than on the data. Caught by CI, not locally.
        if any(part.startswith(".") or part == "__pycache__" for part in rel.parts):
            continue
        h.update(str(rel).encode())
        h.update(b"\0")
        h.update(hashlib.sha256(p.read_bytes()).hexdigest().encode())
        h.update(b"\n")
    return h.hexdigest()


def load(root: Path) -> dict:
    p = root / BASELINE
    return json.loads(p.read_text()) if p.exists() else {"suites": {}, "src_tree": "(absent)"}


def changes(was: dict, now: dict):
    """The registry differences, split by kind — each kind is a separate invariant."""
    deleted = sorted(set(was) - set(now))
    added = sorted(set(now) - set(was))
    lowered = sorted(n for n in was if n in now and now[n] < was[n])
    raised = sorted(n for n in was if n in now and now[n] > was[n])
    return deleted, added, lowered, raised


def compare(root: Path):
    """[(label, ok, detail)] — one case per invariant."""
    base = load(root)
    now, was = suites(root), base.get("suites", {})
    deleted, added, lowered, raised = changes(was, now)
    tree_now, tree_was = src_tree(root), base.get("src_tree")
    drift = ([f"-{n}" for n in deleted] + [f"+{n}({now[n]})" for n in added]
             + [f"{n}:{was[n]}->{now[n]}" for n in lowered + raised])

    return [
        ("no suite was deleted from the registry", not deleted, f"missing: {deleted}" if deleted else "all present"),
        ("no expected count was lowered", not lowered,
         "; ".join(f"{n}: {was[n]} -> {now[n]}" for n in lowered) if lowered else f"{len(was)} counts monotone"),
        ("the registry matches the baseline (any change needs --write)", not drift,
         f"drift: {drift} — run --write" if drift else "identical"),
        ("src/ is byte-identical to the baseline", tree_now == tree_was,
         f"{tree_now[:12]} vs {str(tree_was)[:12]}" if tree_now != tree_was else f"tree {tree_now[:12]}"),
    ]


def run(root: Path, write: bool, allow_decrease: bool = False) -> int:
    if write:
        was, now = load(root).get("suites", {}), suites(root)
        deleted, added, lowered, raised = changes(was, now)
        if (lowered or deleted) and not allow_decrease:
            print(f"  REFUSED — this would lower {lowered} and drop {deleted}; "
                  f"pass --allow-decrease if that is really intended")
            return 1
        p = root / BASELINE
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(json.dumps({"suites": now, "src_tree": src_tree(root)}, indent=1) + "\n")
        print(f"  baselined {len(now)} suite(s) -> {p}")
        return 0

    cases = compare(root)
    passed = 0
    for label, ok, detail in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label} — {detail}")
    print(f"{passed}/{len(cases)} ratchet case(s)")
    return 0 if passed == len(cases) else 1


# --- the self-test: a synthetic root, so each invariant is broken *in isolation* --------------------

BASE = [("a", 5), ("b", 3)]


def stub(entries) -> str:
    rows = "".join(f'    ("{n}", ["true"], {c}, False),\n' for n, c in entries)
    return "SUITES = [\n" + rows + "]\n"


def seed(root: Path) -> Path:
    """A baselined synthetic repository; returns its registry path."""
    (root / "tools").mkdir(parents=True)
    (root / "src").mkdir()
    reg = root / "tools" / "acceptance.py"
    reg.write_text(stub(BASE))
    (root / "src" / "f.c").write_text("/* one function */\n")
    run(root, write=True)
    return reg


def restore(reg: Path, root: Path) -> None:
    """Put the tree back to its baselined state, so the next case can only fail for its own reason.

    Without this the src case failed because the *registry* was still dirty from the case before it, and
    would have reported detection even with the src comparison deleted. That is the vacuity this whole
    tool is about, and it was in this tool.
    """
    reg.write_text(stub(BASE))
    (root / "src" / "f.c").write_text("/* one function */\n")


def self_test() -> int:
    tmp = Path(tempfile.mkdtemp())
    cases = []
    try:
        root = tmp / "r"
        reg = seed(root)
        cases.append(("a freshly baselined root checks clean", run(root, False) == 0))

        restore(reg, root); reg.write_text(stub([("a", 4), ("b", 3)]))
        cases.append(("a lowered expected count is caught (alone)", run(root, False) == 1))

        restore(reg, root); reg.write_text(stub([("a", 5)]))
        cases.append(("a deleted suite is caught (alone)", run(root, False) == 1))

        restore(reg, root); reg.write_text(stub([("a", 5), ("b", 3), ("c", 2)]))
        cases.append(("an added suite is caught (alone)", run(root, False) == 1))

        restore(reg, root); reg.write_text(stub([("a", 6), ("b", 3)]))
        cases.append(("a raised count is caught without --write (alone)", run(root, False) == 1))

        restore(reg, root); (root / "src" / "f.c").write_text("/* edited to satisfy a test */\n")
        cases.append(("an edit to src/ is caught (alone)", run(root, False) == 1))

        # ...and an ignored file is not corpus content, so it must not move the hash — otherwise the
        # invariant depends on the machine, which is exactly how it failed on CI while passing locally
        restore(reg, root); (root / "src" / ".DS_Store").write_bytes(b"junk")
        cases.append(("an ignored file in src/ does not change the hash", run(root, False) == 0))

        restore(reg, root); reg.write_text(stub([("a", 4), ("b", 3)]))
        cases.append(("--write refuses to lower a count without --allow-decrease",
                      run(root, write=True) == 1))

        restore(reg, root); reg.write_text(stub([("a", 6), ("b", 3), ("c", 2)]))
        run(root, write=True)
        cases.append(("--write accepts a raised count, an added suite and a src/ edit",
                      run(root, False) == 0))

        reg.write_text(stub([("a", 4), ("b", 3), ("c", 2)]))
        cases.append(("--allow-decrease is the only way a count may go down",
                      run(root, write=True, allow_decrease=True) == 0 and run(root, False) == 0))
    finally:
        shutil.rmtree(tmp)

    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} ratchet self-test case(s)")
    return 0 if passed == len(cases) else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--allow-decrease", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--root", default=str(HERE.parent), help="repository root (for the self-test)")
    args = ap.parse_args()
    if args.self_test:
        return self_test()
    return run(Path(args.root), args.write, args.allow_decrease)


if __name__ == "__main__":
    raise SystemExit(main())
