#!/usr/bin/env python3
"""Project the decompiler's journals into a committed, readable source tree.

The authoritative output stays in `build/decomp/<image>/` (gitignored, resumable, journaled).
This step is a projection, not a second source of truth: it rewrites `src/<image>/` from
`decompile-index.json` every run, so the committed tree can never drift from the journal.

Per-function file names come from our own seed list where one exists (config/symbols.tsv ->
build/seeds/<image>.tsv), otherwise from the provider's name (FUN_xxxxxxxx). Every file carries
a provenance header: load address, image base, body range, body size, and the body's sha256.

Callees are derived here, not taken from the index — the index carries no call edges. The
derivation is a direct scan of the image bytes for `jal`, which is exact for direct calls and
blind to indirect ones (M27 showed the message sends are indirect, so absence of an edge here
is not absence of a call).

Coverage is reported per image: the union of function body ranges against the image extent,
plus every code byte no function claims. Those gaps are where data lives inside a code image.

Usage:
  ./export_src.py --images build/elfs/images.json --decomp build/decomp --src src
"""
import argparse
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

import recovered

SAFE = re.compile(r"[^A-Za-z0-9_.]")
# M288: the provider labels a jump-table's case bodies `switchD_<dispatch>::caseD_<n>`. They are **not
# functions** -- they are reachable only through the table that the enclosing function owner dispatches on --
# and a seed name must not promote one, because the seed list is a naming aid and the provider's label is the
# evidence about *kind*. The projection therefore keeps their pseudocode but publishes them as fragments.
FRAGMENT = re.compile(r"^switchD_([0-9a-f]{8})::(?:caseD_[0-9a-z]+|default)$")


def read_seeds(path: Path) -> dict:
    names = {}
    if path.exists():
        for line in path.read_text().splitlines():
            parts = line.split("\t")
            if len(parts) >= 3:
                names[int(parts[0], 16)] = parts[2].strip()
    return names


def image_bytes(elf: Path, size: int) -> bytes:
    """The PT_LOAD contents sit at a fixed offset in the wrapper (see wrap_mips_elf.py)."""
    data = elf.read_bytes()
    return data[0x100:0x100 + size]


def global_names(path: Path) -> dict:
    """address -> name for the whole corpus, so a call into another image gets its real name.

    Each image is analysed alone, so `osCreateThread` at 0x80006d60 is named in the boot bank
    but appears as `func_0x80006d60` inside stage-2's pseudocode. The rename is pure text
    substitution over an established name, applied at projection time, never in the journal.
    """
    names = {}
    if path.exists():
        for line in path.read_text().splitlines():
            line = line.split("#", 1)[0].strip()
            if line:
                parts = [x.strip() for x in line.split("\t")]
                if len(parts) >= 3:
                    names[int(parts[0], 0)] = parts[2]
    return names


def rename_references(text: str, names: dict) -> str:
    import re
    def sub(m):
        try:
            addr = int(m.group(1), 16)
        except (TypeError, ValueError):
            return m.group(0)
        return names.get(addr, m.group(0))
    return re.sub(r"\b(?:func|FUN)_0x([0-9a-fA-F]{8})\b", sub, text)


def strip_provider_preamble(text: str) -> str:
    """Drop REA's leading `// name: … // limitations: …` block.

    It is identical for every function in an image (the same analysis profile and the same
    provider caveats), so keeping it in 3 267 files would bury the pseudocode. The limitations
    are recorded once per image in manifests/code_index.json instead.
    """
    lines = text.splitlines()
    i = 0
    while i < len(lines) and (lines[i].startswith("//") or not lines[i].strip()):
        i += 1
    return "\n".join(lines[i:]).lstrip("\n")


def jal_targets(code: bytes, base: int) -> dict:
    """address -> [targets] for every direct call inside the image."""
    n = len(code) // 4
    words = struct.unpack(f">{n}I", code[:n * 4])
    out = {}
    for i, w in enumerate(words):
        if (w >> 26) == 0x03:
            pc = base + i * 4
            out.setdefault(pc, []).append((pc & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
    return out


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--images", default="build/elfs/images.json")
    ap.add_argument("--elfs", default="build/elfs")
    ap.add_argument("--decomp", default="build/decomp")
    ap.add_argument("--seeds", default="build/seeds")
    ap.add_argument("--src", default="src")
    ap.add_argument("--symbols", default="config/symbols.tsv")
    a = ap.parse_args()

    images = json.loads(Path(a.images).read_text())["images"]
    gnames = global_names(Path(a.symbols))
    src = Path(a.src)
    src.mkdir(parents=True, exist_ok=True)

    # every function start across the corpus, so a call edge can be classified internal/external
    corpus, per_image = set(), []
    for img in images:
        index = Path(a.decomp) / img["name"] / "decompile-index.json"
        if not index.exists():
            sys.exit(f"missing {index} — run the batch decompile first")
        doc = json.loads(index.read_text())
        per_image.append((img, doc["functions"], doc["provider"]))
        corpus.update(int(e["address"], 16) for e in doc["functions"])

    merged, rows = {"tool": "export_src.py", "images": []}, []
    for img, entries, provider in per_image:
        seeds = read_seeds(Path(a.seeds) / f"{img['name']}.tsv")
        code = image_bytes(Path(a.elfs) / f"{img['name']}.elf", img["size"])
        calls = jal_targets(code, img["base"])

        outdir = src / img["name"]
        outdir.mkdir(parents=True, exist_ok=True)
        fragdir = outdir / "switch"          # M288: case bodies, kept but not functions
        fragdir.mkdir(parents=True, exist_ok=True)
        for stale in list(outdir.glob("*.c")) + list(fragdir.glob("*.c")):
            stale.unlink()
        written = 0

        covered, functions, fragments = set(), [], []
        for e in entries:
            addr = int(e["address"], 16)
            frag = FRAGMENT.match(e.get("name", ""))
            name = seeds.get(addr) or e["name"]
            if addr not in seeds and name in ("entry", "entrypoint"):
                # `tools/wrap_mips_elf.py` sets e_entry = the image base, so Ghidra labels the
                # first function `entry`. That is our wrapper's artefact, not a game symbol, and
                # naming it as one would violate the rule that a name needs evidence.
                name = f"func_{addr:08x}"
            ranges = e["body"]["ranges"] if e["body"]["available"] else []
            for r in ranges:
                s, t = int(r["start"], 16), int(r["end"], 16)
                covered.update(range(s, t + 1, 4))
            body = rename_references(
                strip_provider_preamble(
                    (Path(a.decomp) / img["name"] / e["relative_path"]).read_text()), gnames)
            callees = sorted({t for s, ts in calls.items()
                              for t in ts if ranges and
                              any(int(r["start"], 16) <= s <= int(r["end"], 16) for r in ranges)})
            fname = SAFE.sub("_", name) + ".c"
            # Hash the pseudocode we actually write. The provider's record hash covers its own
            # `// limitations:` preamble, which names the seed file and its entry counts, so it
            # changes whenever seeds change even when not one line of pseudocode moved.
            body_sha = hashlib.sha256(body.encode()).hexdigest()
            span = (f"{ranges[0]['start']}..{ranges[-1]['end']}" if ranges else "no body")
            header = (f"/* {name}\n"
                      f" * image   {img['name']} ({img['role']}), base {img['base']:#010x}\n"
                      f" * address {e['address']}  body {span}  size "
                      f"{sum(int(r['end'], 16) - int(r['start'], 16) + 1 for r in ranges)} B\n"
                      f" * body sha256 {body_sha}\n"
                      f" * provider record sha256 {e.get('sha256', '-')}\n"
                      f" * callees {len(callees)} direct "
                      f"({sum(1 for c in callees if c in corpus)} in corpus)\n"
                      f" * provider {provider['name']} {provider['version']}\n"
                      f" */\n")
            target = (fragdir if frag else outdir) / fname
            target.write_text(header + body)
            record = dict(address=e["address"], name=name, file=str(target),
                          size=sum(int(r["end"], 16) - int(r["start"], 16) + 1
                                   for r in ranges),
                          sha256=body_sha, provider_sha256=e.get("sha256", ""),
                          status=e["status"],
                          callees=[hex(c) for c in callees if c in corpus],
                          callees_unknown=len([c for c in callees if c not in corpus]))
            if frag:
                # the provider says this body is a case of the switch at frag.group(1); it is published
                # with its pseudocode intact but not counted, not listed and not named as a function
                record["switch"] = "0x" + frag.group(1)
                fragments.append(record)
            else:
                functions.append(record)

        # M289: apply the recovered-function fixture. For every function we have reconstructed and pinned with a
        # compile-probe case, the provider's body is replaced by the measured extent, the entries that start inside
        # it are absorbed (they are its dispatch arms), and `src/<image>/<name>.c` publishes *our* reconstruction
        # instead of the provider's head-only pseudocode. Functions the provider never claimed are added.
        for e in recovered.load().get(img["name"], []):
            absorbed = [f for f in functions + fragments
                        if e["start"] <= int(f["address"], 16) <= e["end"]]
            functions = [f for f in functions if f not in absorbed]
            fragments = [f for f in fragments if f not in absorbed]
            for gone in absorbed:                 # a case body absorbed into its owner keeps no file of its own
                Path(gone["file"]).unlink(missing_ok=True)
            for w_ in range(e["start"], e["end"] + 1, 4):
                covered.add(w_)
            addr_s = "0x%08x" % e["start"]
            name = seeds.get(e["start"]) or ("FUN_%08x" % e["start"])
            body = recovered.source(e)
            recovered_calls = {t for s, ts in calls.items()
                               for t in ts if e["start"] <= s <= e["end"]}
            fname = SAFE.sub("_", name) + ".c"
            body_sha = hashlib.sha256(body.encode()).hexdigest()
            header = (f"/* {name}\n"
                      f" * image   {img['name']} ({img['role']}), base {img['base']:#010x}\n"
                      f" * address {addr_s}  body 0x{e['start']:08x}..0x{e['end']:08x}  size {e['words'] * 4} B\n"
                      f" * body sha256 {body_sha}\n"
                      f" * recovered {e['verdict']} ({e['probe']})\n"
                      f" * provider {provider['name']} {provider['version']}: body was the head only; this file is "
                      f"the reconstruction, kept in tools/compile_probe.py as {e['source']}\n"
                      f" * extents and pins: fixtures/decomp/recovered.json\n"
                      f" */\n")
            (outdir / fname).write_text(header + body)
            record = dict(address=addr_s, name=name, file=str(outdir / fname), size=e["words"] * 4,
                          sha256=body_sha, provider_sha256="", status="recovered",
                          callees=[hex(c) for c in sorted(recovered_calls) if c in corpus],
                          callees_unknown=len([c for c in recovered_calls if c not in corpus]))
            functions.append(record)

        gaps = sorted(set(range(img["base"], img["base"] + img["size"], 4)) - covered)
        runs = []
        for g in gaps:
            if runs and g - runs[-1][1] == 4:
                runs[-1][1] = g
            else:
                runs.append([g, g])
        named = sum(1 for f in functions if not f["name"].startswith(("FUN_", "func_")))
        merged["images"].append(dict(
            name=img["name"], role=img["role"], base=hex(img["base"]), size=img["size"],
            functions=len(functions), named=named, functions_named=named,
            limitations=sorted({l for e in entries for l in e.get("limitations", [])}),
            # M206: `covered` is a set of 4-byte word *starts*, so the byte total is len * 4. It was
            # published as a raw word count under a byte-shaped name -- the same class of error M205
            # fixed one layer up.
            covered_words=len(covered), covered_bytes=len(covered) * 4,
            coverage=round(len(covered) * 4 / max(img["size"], 1), 4),
            unclaimed_runs=len(runs), unclaimed_bytes=len(gaps) * 4, functions_list=functions,
            fragments=len(fragments), fragments_list=fragments))
        rows.append((img, len(functions), named, len(covered) * 4, len(gaps) * 4, len(runs)))

    Path("manifests/code_index.json").write_text(json.dumps(merged, indent=1) + "\n")

    total_f = sum(r[1] for r in rows)
    total_b = sum(r[3] for r in rows)
    total_img = sum(i["size"] for i, *_ in rows)
    lines = ["# Decompiled code corpus — index", "",
             f"{total_f} functions across {len(rows)} images, "
             f"{total_b:,} of {total_img:,} image bytes inside a known function body "
             f"({100.0 * total_b / max(total_img, 1):.1f} %).", "",
             "Generated by `tools/export_src.py` from `build/decomp/*/decompile-index.json`;",
             "the journals are authoritative and this tree is a projection of them.", "",
             "| image | role | base | bytes | functions | named | claimed | unclaimed | runs |",
             "|---|---|---|---|---|---|---|---|---|"]
    for img, n, named, cov, unc, runs in rows:
        lines.append(f"| `{img['name']}` | {img['role']} | `{img['base']:#010x}` | {img['size']:,} "
                     f"| {n} | {named} | {cov:,} | {unc:,} | {runs} |")
    lines += ["", "An **unclaimed run** is code-shaped bytes no function body covers — data islands "
              "inside a code image, or a function the provider did not find. Both are worth reading.",
              "", "Names come from `config/symbols.tsv`; anything else is `FUN_xxxxxxxx`, which means "
              "unnamed, not unknown-to-be-code."]
    Path(src / "INDEX.md").write_text("\n".join(lines) + "\n")

    print(f"{total_f} functions, {len(rows)} images, {total_b:,}/{total_img:,} B claimed "
          f"({100.0 * total_b / max(total_img, 1):.1f} %)")
    print(f"{'image':>16} {'funcs':>6} {'named':>6} {'claimed':>9} {'unclaimed':>10} {'runs':>5}")
    for img, n, named, cov, unc, runs in sorted(rows, key=lambda r: -r[1])[:12]:
        print(f"{img['name']:>16} {n:6d} {named:6d} {cov:9,} {unc:10,} {runs:5d}")
    print(f"\nwrote {src}/INDEX.md and manifests/code_index.json")


if __name__ == "__main__":
    main()
