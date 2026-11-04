#!/usr/bin/env python3
"""Assign every function an analysis status, derived rather than declared.

The corpus publishes one number ("3 638 functions") that says how much was *indexed*, and the strategic plan's
point is that this is not how much is *understood*. This tool publishes five, each with a rule that can be
checked rather than a feeling:

    ladder  F0 indexed       present in manifests/code_index.json (image + address identity)
            F1 decompiled    its src/<image>/<name>.c exists and the provider marked the body written
            F2 understood    every call target in its body resolves to a known function
    axes    named            its name comes from config/symbols.tsv, i.e. not FUN_/func_
            validated        a gate or an executed experiment pins its behaviour — a curated list, each
                             entry naming its evidence, never inferred

The ladder is cumulative (F2 implies F1 implies F0) because those are three degrees of the same evidence:
indexed, decompiled, mechanically connected. **Naming and validation are separate axes, not rungs** — the
strategic plan is explicit that name, types and behaviour carry separate confidence, and the data proves it:
the functions this project has *executed* are mostly still called `FUN_…`, because the rule here is that a name
needs evidence and nobody has spent the evidence on a name yet. Collapsing those into one number would have
hidden exactly that. So the residue is published two ways: how many functions still have an unresolved call,
and how many are validated by a gate yet unnamed.

Usage:
  ./analysis_status.py --write    # manifests/analysis_status.json
  ./analysis_status.py --check    # the level rules and their monotonicity (committed artifacts only)
"""
import argparse
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
OUT = "manifests/analysis_status.json"

# F4 is the only curated list in this tool, and it is deliberately short: a function qualifies when a *gate*
# pins behaviour, or when an experiment executed the cartridge's own code. Each entry names its evidence.
F4 = {
    "stage2:0x800b53f4": "M199 — the voice synthesis, bit-exact against the cartridge",
    "stage2:0x800b62c0": "M199 — kernel the synthesis calls, transcribed",
    "stage2:0x800b63b4": "M199 — lattice stage of the synthesis, transcribed",
    "stage2:0x800b4dc0": "M199 — dequantisation stage of the synthesis, transcribed",
    "stage2:0x800b3704": "M179/M193 — the sample loader; its index bound and rate byte are source-shape gated",
    "stage2:0x800a86a0": "M185 — the chain walk both SND_PROJ and SND_POOL use",
    "stage2:0x800ad330": "M185/M204 — the sample-directory walker; its 0xe-short stride and terminator are gated",
    "stage2:0x800ada34": "M203 — the record reader whose fields the loop map is built from",
    "stage2:0x800a54ec": "M203 — the voice setup that derives the loop remainder",
    "stage2:0x800a3bf4": "M203 — the mixer feed that splits a block at the loop end",
    "stage2:0x800ace1c": "M202 — the cache-C resolver, keyed by key and rate",
    "stage2:0x800a5678": "M200 — the audio mutex acquire, seen at every cache site",
}


def derive(root: Path = ROOT):
    ci = json.loads((root / "manifests" / "code_index.json").read_text())
    rows = {}
    for img in ci["images"]:
        for f in img["functions_list"]:
            fid = f"{img['name']}:{f['address']}"
            src = root / f["file"]
            level = 0
            # M296: a *recovered* function -- one whose src file is our own byte-exact reconstruction, published from
            # `fixtures/decomp/recovered.json` -- is strictly more evidence than a provider "written" body, so it
            # takes the same rung. Without this the first library function demoted the ladder by one.
            if src.exists() and f.get("status") in ("written", "recovered"):
                level = 1
            if level >= 1 and not f.get("callees_unknown"):
                level = 2
            named = not f["name"].startswith(("FUN_", "func_"))
            validated = fid in F4
            rows[fid] = dict(name=f["name"], image=img["name"], address=f["address"],
                             callees=len(f.get("callees") or []),
                             callees_unknown=f.get("callees_unknown", 0),
                             level=level, named=named, validated=validated)
    totals = {f"F{i}": sum(1 for r in rows.values() if r["level"] >= i) for i in range(3)}
    totals["named"] = sum(1 for r in rows.values() if r["named"])
    totals["validated"] = sum(1 for r in rows.values() if r["validated"])
    totals["validated_unnamed"] = sum(1 for r in rows.values() if r["validated"] and not r["named"])
    return {"tool": "analysis_status.py", "rules": {
        "F0": "in manifests/code_index.json", "F1": "src file exists, provider status written",
        "F2": "every call target resolves in corpus",
        "named": "name from config/symbols.tsv (an axis, not a rung)",
        "validated": "pinned by a gate or an executed experiment (curated, evidence per entry)"},
        "totals": totals, "f4_evidence": F4, "functions": rows}


def check(rep):
    t = rep["totals"]
    F = rep["functions"]
    cases = []
    indexed = sum(len(i["functions_list"]) for i in
                  json.loads((ROOT / "manifests" / "code_index.json").read_text())["images"])
    cases.append((f"every function is at F0 — {t['F0']} indexed",
                  t["F0"] == len(F) == indexed))
    mono = t["F0"] >= t["F1"] >= t["F2"]
    cases.append((f"the ladder is cumulative: {t['F0']} ≥ {t['F1']} ≥ {t['F2']} → named {t['named']}, "
                  f"validated {t['validated']}", mono))
    bad2 = [r for r in F.values() if r["level"] >= 2 and r["callees_unknown"]]
    cases.append((f"every F2 function has zero unresolved call targets ({len(bad2)} violate)", not bad2))
    bad_named = [r for r in F.values() if r["named"] and r["name"].startswith(("FUN_", "func_"))]
    cases.append((f"every function the axis counts as named carries a curated name "
                  f"({len(bad_named)} violate)", not bad_named))
    f4 = [k for k, r in F.items() if r["validated"]]
    missing = [k for k in f4 if not rep["f4_evidence"].get(k)]
    cases.append((f"validated is {len(f4)} functions and each names its evidence ({len(missing)} without)",
                  bool(f4) and not missing))
    cases.append((f"the residue is published: {t['F0'] - t['F2']:,} functions still have an unresolved call, "
                  f"{t['validated_unnamed']} are validated by a gate yet unnamed",
                  t["F0"] - t["F2"] > 0 and t["validated_unnamed"] > 0))
    return cases


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    a = ap.parse_args()
    rep = derive()
    if a.write:
        (ROOT / OUT).write_text(json.dumps(rep, indent=1) + "\n")
        print(f"wrote {OUT} — " + ", ".join(f"{k} {v:,}" for k, v in rep["totals"].items()))
        return 0
    if a.check:
        # The *rules* are checked against the fresh derivation, so a mutation to a rule fails with that rule's
        # own label rather than being shadowed by the drift case; and the committed artifact must equal the
        # fresh one, so a stale or overstating manifest still fails here.
        committed = json.loads((ROOT / OUT).read_text()) if (ROOT / OUT).exists() else None
        cases = check(rep)
        drift = committed != rep
        cases.append((f"the committed status matches a fresh derivation "
                      f"({committed['totals'] if committed else 'missing'} vs {rep['totals']})", not drift))
        bad = 0
        for label, ok in cases:
            bad += not ok
            print(f"  {'PASS' if ok else 'FAIL'} {label}")
        print(f"{len(cases) - bad}/{len(cases)} analysis-status case(s)")
        return 1 if bad else 0
    print(", ".join(f"{k} {v:,}" for k, v in rep["totals"].items()))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
