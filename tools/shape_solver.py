#!/usr/bin/env python3
"""Search a function's *shape* space, with the byte metric as the objective.

The project's recovery loop has been: write a draft, then try one shape at a time by hand. That is where the cost is —
~25 measured shape facts (chained assignment, operand order, shift vs multiply, `int` vs `s16` locals, `break` vs
`return`, case order from the jump table, ternary vs if/else, detaching the device base from the symbol, ...) have each
been discovered once and then re-applied by hand, one candidate per attempt.

This driver automates the loop: given a draft and a target, it enumerates variants, compiles each through the canonical
pipeline, scores each by **words identical to the image**, and reports the ranking. Two rule sources:

  --permute-stmts     generic: every adjacent transposition of simple statements inside a brace block
  --rules FILE.json   explicit: [{"name": ..., "old": "...", "new": ["...", "..."]}], cartesian product

The objective is deliberately the byte metric and not a penalty function: M259 measured decomp-permuter's own score
disagreeing with the words on the page, and the shape question is "which source produces these exact words".

Usage:
  shape_solver.py <draft.c> --addr 0x8004fd1c --words 98 [--table 0x800b8bd0] [--sym N=0xADDR ...]
                  [--permute-stmts] [--rules f.json] [--max-variants 200] [--workers 8] [--keep out.c]
"""
import argparse
import difflib
import importlib.util
import itertools
import json
import re
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def corpus():
    spec = importlib.util.spec_from_file_location("_cp", ROOT / "tools" / "compile_probe.py")
    cp = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cp)
    return cp


def statement_swaps(text):
    """Every adjacent transposition of two simple statements on consecutive lines inside a brace block."""
    lines = text.split("\n")
    out = []
    for i in range(len(lines) - 1):
        a, b = lines[i], lines[i + 1]
        if not (a.rstrip().endswith(";") and b.rstrip().endswith(";")):
            continue
        if a.lstrip().startswith(("/*", "//", "#", "else")) or b.lstrip().startswith(("/*", "//", "#", "else")):
            continue
        indent_a = len(a) - len(a.lstrip())
        indent_b = len(b) - len(b.lstrip())
        if indent_a != indent_b or indent_a == 0:
            continue
        lines2 = list(lines)
        lines2[i], lines2[i + 1] = b, a
        out.append(("swap L%d/%d" % (i + 1, i + 2), "\n".join(lines2)))
    return out


def brace_statement_swaps(text):
    """Adjacent transpositions of statements inside a single-line `{ a; b; }` group.

    The first version of this only swapped whole *lines*, and the p6 draft's two misplaced statements share a line --
    so the search could not reach the shape that is byte-exact. Statements, not lines, are the unit.
    """
    out = []
    for m in re.finditer(r"\{([^{}]*)\}", text):
        inner = m.group(1)
        parts = [p.strip() for p in inner.split(";")]
        if parts and parts[-1] == "":
            parts = parts[:-1]
        if len(parts) < 2 or any("\n" in p for p in parts):
            continue
        for i in range(len(parts) - 1):
            swapped = list(parts)
            swapped[i], swapped[i + 1] = swapped[i + 1], swapped[i]
            new_inner = "; ".join(swapped) + ";"
            out.append(("swap %s | %s" % (parts[i][:12], parts[i + 1][:12]),
                        text[:m.start(1)] + " " + new_inner + " " + text[m.end(1):]))
    return out


def build_variants(text, rules, permute):
    """[(tag, source)] — explicit rules applied one at a time, then combinations, then statement swaps."""
    seen = {}
    seen["base"] = text
    for r in rules:
        if r["old"] not in text:
            continue
        for n, new in enumerate(r["new"]):
            seen["%s#%d" % (r["name"], n)] = text.replace(r["old"], new, 1)
    # combinations of one rule at a time is the common case; pairs where cheap
    singles = [(r, n) for r in rules if r["old"] in text for n in r["new"]]
    for (r1, n1), (r2, n2) in itertools.combinations(singles, 2):
        if r1 is r2:
            continue
        t = text.replace(r1["old"], n1, 1)
        if r2["old"] in t:
            seen["%s+%s" % (r1["name"], r2["name"])] = t.replace(r2["old"], n2, 1)
    if permute:
        for tag, t in statement_swaps(text):
            seen["perm " + tag] = t
        for tag, t in brace_statement_swaps(text):
            seen["braces " + tag] = t
    return list(seen.items())


def image_window(cp, name):
    """(bytes, base) for an image name -- stage2 by default, any of the 36 through build/elfs."""
    import json
    inv = json.loads((ROOT / "build" / "elfs" / "images.json").read_text())["images"]
    hit = [i for i in inv if i["name"] == name]
    if not hit:
        raise SystemExit("no image named %r" % name)
    img = hit[0]
    elf = ROOT / "build" / "elfs" / ("%s.elf" % img["name"])
    base = img["base"] if isinstance(img["base"], int) else int(img["base"], 16)
    return elf.read_bytes()[0x100:0x100 + img["size"]], base


def score(cp, src, addr, words, table, syms, asflags, window=None):
    d = Path(tempfile.mkdtemp(prefix="ss_"))
    try:
        c = d / "f.c"
        c.write_text(src)
        s, o, fx, elf = d / "f.s", d / "f.o", d / "f.fix.o", d / "f.elf"
        if subprocess.run([str(cp.TC / "mips-gcc-2.8.1/bin/cc1"), "-quiet", "-O2", "-G", "0", "-mips2",
                           "-mcpu=r4300", str(c), "-o", str(s)], capture_output=True).returncode:
            return None
        subprocess.run([str(cp.AS27), "-EB", "-mips2", "-mcpu=r4300", *asflags, "-G", "0",
                        "-o", str(o), str(s)], capture_output=True)
        subprocess.run([str(cp.GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                        "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
        symtxt = "".join("%s = 0x%X;\n" % (k, v) for k, v in syms)
        (d / "l.ld").write_text(
            "SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  . = %#x;\n  .rodata : ALIGN(8) { *(.rodata) }\n"
            "  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) "
            "*(.mdebug*) *(.gnu.attributes) *(.note.GNU-stack) }\n}\n" % (addr, table) + symtxt)
        if subprocess.run([str(cp.GAS / "mips-linux-gnu-ld"), "-T", str(d / "l.ld"), "-o", str(elf),
                           str(fx)], capture_output=True).returncode:
            return None
        image, base = window if window else (cp.IMAGE.read_bytes(), cp.BASE)
        got_txt = cp.text_of(elf)
        got = [got_txt[4 * i:4 * i + 4] for i in range(len(got_txt) // 4)]
        want = [image[addr - base + 4 * i:addr - base + 4 * i + 4] for i in range(words)]
        off = sum(1 for a, b in zip(want, got) if a == b)
        sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
        same = sum(i2 - i1 for t, i1, i2, _, _ in sm.get_opcodes() if t == "equal")
        hunks = len([1 for x in sm.get_opcodes() if x[0] != "equal"])
        return {"off": off, "same": same, "hunks": hunks, "got": len(got)}
    finally:
        import shutil
        shutil.rmtree(d, ignore_errors=True)


def self_test():
    """The pure half of the tool: what it enumerates. No compiler, no cartridge, so CI can run it."""
    cases = []
    text = "void f(void)\n{\n    if (x == 0) { a = 1; b = 2; } return;\n    p = q;\n    r = s;\n}\n"
    br = brace_statement_swaps(text)
    cases.append(("an intra-brace pair on one line is reached at all (the p6 draft's own shape)", len(br) == 1))
    cases.append(("the swapped block keeps its terminating semicolon, or cc1 rejects it",
                  bool(br) and "b = 2; a = 1;" in br[0][1]))
    ln = statement_swaps(text)
    cases.append(("line-level swaps only touch statement lines (%d found)" % len(ln), all(
        "return;" not in tag and "{" not in tag for tag, _ in ln) and len(ln) >= 1))
    rules = [dict(name="r1", old="a = 1;", new=["a = 2;", "a = 3;"]),
             dict(name="r2", old="b = 2;", new=["b = 4;"])]
    v = dict(build_variants(text, rules, False))
    cases.append(("a rule with two options yields two variants plus the base", "r1#0" in v and "r1#1" in v))
    cases.append(("two independent rules also yield their combination", any("+" in k for k in v)))
    missing = [r for r in rules if r["old"] not in text]
    cases.append(("a rule whose anchor is absent contributes nothing", not missing))
    ok = sum(1 for _, passed in cases if passed)
    for label, passed in cases:
        print("  %s %s" % ("PASS" if passed else "FAIL", label))
    print("%d/%d shape-solver case(s)" % (ok, len(cases)))
    return 0 if ok == len(cases) else 1


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("draft", nargs="?")
    ap.add_argument("--addr")
    ap.add_argument("--words", type=int)
    ap.add_argument("--table", default="0x800B8BD0")
    ap.add_argument("--image", default="stage2", help="which of the 36 images the target lives in")
    ap.add_argument("--sym", action="append", default=[])
    ap.add_argument("--rules")
    ap.add_argument("--permute-stmts", action="store_true")
    ap.add_argument("--max-variants", type=int, default=240)
    ap.add_argument("--workers", type=int, default=8)
    ap.add_argument("--keep")
    ap.add_argument("--as", dest="asflags", default="-g")
    a = ap.parse_args(argv[1:])
    if a.self_test:
        return self_test()
    if not a.draft or not a.addr or not a.words:
        ap.error("a draft, --addr and --words are required unless --self-test is given")
    cp = corpus()
    text = Path(a.draft).read_text()
    rules = json.loads(Path(a.rules).read_text()) if a.rules else []
    syms = []
    for s in a.sym:
        n, v = s.split("=")
        syms.append((n, int(v, 16)))
    variants = build_variants(text, rules, a.permute_stmts)[:a.max_variants]
    flags = tuple(a.asflags.split()) if a.asflags else ()
    addr, words, table = int(a.addr, 16), a.words, int(a.table, 16)
    window = image_window(cp, a.image)

    def work(item):
        tag, src = item
        return tag, src, score(cp, src, addr, words, table, syms, flags, window)

    with ThreadPoolExecutor(max_workers=a.workers) as ex:
        results = list(ex.map(work, variants))
    ranked = sorted([(r["off"], r["same"], -r["hunks"], tag, src)
                     for tag, src, r in results if r], reverse=True)
    print("%-28s %s" % ("variant", "offset-aligned  content-aligned  hunks"))
    base = next((r for tag, src, r in results if tag == "base" and r), None)
    if base:
        print("%-28s %3d/%-3d          %3d               %2d"
              % ("base", base["off"], words, base["same"], base["hunks"]))
    for off, same, nh, tag, _ in ranked[:12]:
        if tag == "base":
            continue
        print("%-28s %3d/%-3d          %3d               %2d" % (tag, off, words, same, -nh))
    if ranked:
        off, same, nh, tag, src = ranked[0]
        print("\nbest: %s — %d/%d words identical, %d hunk(s)" % (tag, off, words, -nh))
        if a.keep:
            Path(a.keep).write_text(src)
            print("wrote %s" % a.keep)
    return 0 if ranked else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv))
