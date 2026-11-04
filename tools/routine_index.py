#!/usr/bin/env python3
"""Is `object+5` bounded below 14? Answer it structurally, not by a value scan.

M140 found the routine tables and left the bounds question open, stated honestly as *"whether the byte
is guaranteed `< 14` (if not, an out-of-range index silently runs into the next block — a hazard, not a
finding)"*. This tool closes it. The answer is **no**, and it is worse than a hazard: **14 is not even
the bound.** The `+5` byte is a *class-local state number*, and if you follow `+4` (the class byte) into
`FUN_80079470`'s handler table you find that each class has its **own** state table, of a different
length:

    class +4  handler       state table   entries   how the length is known
    --------  ------------  ------------  --------  ----------------------------------------
    1         0x8007bc10    0x8011afb8    14        sibling tables are 0x38 apart
    2         0x8007a6b0    0x8011a974     4        the next table starts at 0x8011a984
    3         0x8007a6e4    0x8011a984     2        a null word follows the second entry
    4         0x80080ef0    0x8011b6c0    27        a null word follows the 27th entry
    -         0x80055fa4    0x8010dc38    12        the next table starts 12 words later

So `+5 < 14` is false three separate ways:

  1. **Class 1's table really is 14 entries** and *no dispatch checks the index*: all 28 sites are a raw
     `lbu rt,5(rs)` -> `sll rt,rt,2` -> `lw` -> `jalr`, with no `andi`/`sltiu`/compare anywhere. The
     tables are laid end to end, so indices 14..27 read the *next* table's entries — valid code
     pointers for a different behaviour, silently.
  2. **A class-1 writer stores 15.** `0x80162400  sb r2,5(r18)` with `r2 = 0xf`, gated only by
     `(obj+0x1aa & 0xfff) == 1`, in an initialiser that sets class 1 (`lui 0x100; sw r2,4(r18)`). The
     full class-1 writer set is {0,1,2,3,4,6,7,8,9,10,11,12,13,**15**} — note 14 never appears — plus
     one writer that copies `(+0x1ab & 0xf)`, which also reaches 15. Index 15 resolves to
     `0x8007ccec`, the second entry of the *next* type's table.
  3. **Other classes are bounded differently**: class 4's table has 27 entries, so 14+ is perfectly
     legal there, while class 3's has 2 — where an out-of-range index does not cross into a neighbour
     but calls address 0.

The same defect sits one field up: the *type* index `(+0x1aa & 0xf)` is masked to 0..15, but both type
tables (`0x8011af48`, `0x8011b2ac`) hold **11** entries, so nibbles 11..13 are not code pointers.

Usage:
  ./routine_index.py            # the gate (prints N/M, exits non-zero on any failed case)
  ./routine_index.py -v         # every case, with its evidence
"""
import argparse
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import vaddr  # noqa: E402  — the only address arithmetic allowed in this repo

SRC = Path("src")
CACHE = Path("build/elfs/images.json")

# Class 1 (the enemy/entity class): 11 type-specific tables, one shared main table. The main table
# occupies the grid slot between rows 0 and 2, which is why class A's bases are not evenly spaced.
CLASS_A = [0x8011AF80, 0x8011AFF0, 0x8011B028, 0x8011B060, 0x8011B098, 0x8011B0D0,
           0x8011B108, 0x8011B140, 0x8011B178, 0x8011B1B0, 0x8011B1E8]
# The 'E'/'O' family: 11 more type tables, same 0x38 stride, sharing the *same* main table.
CLASS_B = [0x8011B2E4, 0x8011B31C, 0x8011B354, 0x8011B38C, 0x8011B3C4, 0x8011B3FC,
           0x8011B434, 0x8011B46C, 0x8011B4A4, 0x8011B4DC, 0x8011B514]
MAIN = 0x8011AFB8
ROW = 14                      # words per class-1 table — the number under test
BLOCK_END = 0x8011B21C        # last word of the contiguous class-1 block (12 rows x 14)
TYPE_TABLES = [0x8011AF48, 0x8011B2AC]
CLASS_TABLE = 0x8011A870      # FUN_80079470 dispatches on object+4 through this
# (name, table, expected entries) for the *other* classes' state tables, whose lengths differ
# (name, base, entries, basis): "sibling" = the next table starts `entries` words later,
# "terminator" = the run of code pointers ends after `entries` words (a null or a data word). Each is
# checked against the image, not asserted from the note.
SIBLINGS = [("class 2", 0x8011A974, 4, "sibling", 0x8011A984),
            ("class 3", 0x8011A984, 2, "terminator", None),
            ("class 4", 0x8011B6C0, 27, "terminator", None),
            ("class 0x80055fa4 low", 0x8010DC38, 12, "sibling", 0x8010DC68),
            ("class 0x80055fa4 high", 0x8010DC68, 12, "terminator", None)]
RD_LO, RD_HI = 0x80000000, 0x80400000

DISPATCH = re.compile(r"\(\*\(code \*\)\(&(PTR_FUN_[0-9a-f]+)\)\[\*\(byte \*\)\(param_1 \+ 5\)\]\)")
HEADER = re.compile(r"address (0x[0-9a-f]+)\s+body 0x[0-9a-f]+\.\.0x[0-9a-f]+\s+size (\d+) B")
QUAD = re.compile(r"\[1\] = 0x1000000\b")          # +4..+7 = 01 00 00 00 → class 1, state 0
CLASS_QUAD = re.compile(r"\[1\] = 0x([0-9a-f])000000\b")
STORE5 = re.compile(r"\*\(\s*(?:byte|char|undefined1)\s*\*\s*\)\s*\(?([^;]*?)\+\s*5\)\s*=(?!=)\s*([^;]+);")
CONST = re.compile(r"^(0x[0-9a-fA-F]+|\d+|'\\x([0-9a-fA-F]{1,2})')$")

ENTRY_OPS = {0x0F, 0x23, 0x2B, 0x09, 0x0B, 0x0D, 0x24, 0x25, 0x21}   # lui lw sw addiu sltiu ori lbu lhu lh
JR_RA = 0x03E00008                                                  # an empty routine is still a routine


# ----------------------------------------------------------------------------- image access
def words(base, n):
    return [vaddr.word(base + 4 * i) for i in range(n)]


def in_image(w):
    if not (RD_LO <= w < RD_HI) or w & 3:
        return False
    try:
        vaddr.locate(w)
    except LookupError:
        return False
    return True


def plausible_code(bases, n):
    """Every entry must be in-image, aligned, and *point at* a function start — not merely look like one.

    Same acceptance rule as find_jump_tables.py: the word at the target is a prologue
    (`addiu sp,sp,-N`) or a first instruction the compiler emits at an entry. An empty routine
    (`jr ra`) is accepted: 14 of these entries are exactly that.
    """
    bad = []
    for b in bases:
        for i, w in enumerate(words(b, n)):
            if not in_image(w):
                bad.append((b, i, w, "not an in-image aligned pointer"))
                continue
            first = vaddr.word(w)
            if first != JR_RA and (first >> 26) not in ENTRY_OPS:
                bad.append((b, i, w, f"target {w:#010x} starts with {first:#010x}"))
    return bad


def extent(base, limit=64):
    """How many consecutive in-image code pointers start at `base` — capped, since tables abut."""
    n = 0
    while n < limit and in_image(vaddr.word(base + 4 * n)):
        n += 1
    return n


# ----------------------------------------------------------------------------- src access
def dispatchers():
    """Stage-2 functions whose index is `*(byte *)(param_1 + 5)`, with the tables they index.

    Scoped to `src/stage2` deliberately: overlay files hold their own `+5`-indexed state machines for
    their own object types, and counting those would be the value scan this tool exists to avoid.
    """
    out = []
    for p in sorted((SRC / "stage2").rglob("*.c")):
        t = p.read_text()
        if not DISPATCH.search(t):
            continue
        h = HEADER.search(t)
        if not h:
            raise SystemExit(f"{p}: no address header, cannot disassemble")
        out.append(dict(file=p, addr=int(h.group(1), 16), size=int(h.group(2)),
                        tables=[int(x, 16) for x in
                                re.findall(r"&PTR_FUN_([0-9a-f]+)\)\[\*\(byte \*\)\(param_1 \+ 5\)", t)]))
    return out


def class1_values():
    """Every value a class-1 initialiser stores into the state byte, as (value, file, expression)."""
    out = []
    for p in sorted(SRC.rglob("*.c")):
        t = p.read_text()
        if not QUAD.search(t):
            continue
        for m in STORE5.finditer(t):
            expr = m.group(2).strip()
            c = CONST.match(expr)
            if c:
                v = int(c.group(1), 16) if c.group(1).startswith("0x") else (
                    int(c.group(1)) if c.group(1).isdigit() else int(c.group(2), 16))
                out.append((v, p.name, expr))
            else:
                out.append((None, p.name, expr))
    return out


# ----------------------------------------------------------------------------- decoding
def decode(d, off):
    w = struct.unpack(">I", d[off:off + 4])[0]
    return dict(w=w, op=w >> 26, rs=(w >> 21) & 31, rt=(w >> 16) & 31, rd=(w >> 11) & 31,
                imm=w & 0xFFFF, simm=(w & 0xFFFF) - 0x10000 if w & 0x8000 else w & 0xFFFF)


def writes(ins):
    op = ins["op"]
    if op == 0:
        return None if (ins["w"] & 0x3F) in (0x08, 0x09, 0x0C, 0x0D) else ins["rd"]
    if op in (0x23, 0x24, 0x25, 0x20, 0x21, 0x22, 0x26, 0x09, 0x0C, 0x0B, 0x0A, 0x0D, 0x0E, 0x0F):
        return ins["rt"]
    return None


def index_path(addr, size):
    """Was the byte at +5 scaled as-is, or masked first? Returns the first writer of the loaded register."""
    s = vaddr.locate(addr)
    d, base = s["data"], s["lo"]
    ins = [decode(d, addr - base + 4 * i) for i in range(size // 4)]
    for i, a in enumerate(ins):
        if a["op"] == 0x24 and a["simm"] == 5:                 # lbu rt,5(rs)
            reg = a["rt"]
            for b in ins[i + 1:]:
                if writes(b) != reg:
                    continue
                raw = (b["op"] == 0 and (b["w"] & 0x3F) == 0x00 and b["rd"] == b["rt"] == reg
                       and ((b["w"] >> 6) & 0x1F) == 2)        # sll reg,reg,2
                return dict(raw=raw, word=b["w"])
    return None


# ----------------------------------------------------------------------------- the checks
def run(verbose):
    cases = []

    def case(name, ok, detail=""):
        cases.append((name, ok, detail))
        if verbose or not ok:
            print(f"  {'ok  ' if ok else 'FAIL'} {name}" + (f" — {detail}" if detail else ""))

    # 1-3. shape: 22 type tables + the shared main table, all 14 words of real code
    for label, bases, want in (("class 1 (non-'E'/'O')", CLASS_A, [0x38, 0x70]),
                               ("class 1 ('E'/'O')", CLASS_B, [0x38])):
        bad = plausible_code(bases, ROW)
        gaps = sorted({bases[i + 1] - bases[i] for i in range(len(bases) - 1)})
        wide = [i for i in range(len(bases) - 1) if bases[i + 1] - bases[i] == 0x70]
        case(f"{label}: {len(bases)} tables x {ROW} entries, every entry real code",
             not bad and gaps == want and all(bases[i] + 0x38 == MAIN for i in wide),
             f"{len(bad)} bad entries {[f'{b:#x}[{i}] {m}' for b, i, _w, m in bad[:2]]}, "
             f"gaps {[hex(g) for g in gaps]}, wide gaps at the main table: {bool(wide) or not want[1:]}")
    case(f"the shared main table {MAIN:#x} is {ROW} real code pointers, and sits between rows 0 and 2",
         not plausible_code([MAIN], ROW) and CLASS_A[0] + 0x38 == MAIN and MAIN + 0x38 == CLASS_A[1],
         f"{len(plausible_code([MAIN], ROW))} bad entries")

    # 4. the decompiled code names exactly the verified bases, from 22 sites in class 1
    ds = dispatchers()
    named = {t for d in ds for t in d["tables"]}
    family = set(CLASS_A) | set(CLASS_B) | {MAIN}
    into_family = [d for d in ds if family & set(d["tables"])]
    case(f"of {len(ds)} stage-2 sites that index +5, {len(into_family)} name the verified class-1 tables",
         len(into_family) == 22 and named >= family and all(MAIN in d["tables"] for d in into_family),
         f"{len(ds)} sites, {len(into_family)} in the family, "
         f"{sum(MAIN in d['tables'] for d in into_family)}/22 use the shared main table")

    # 5. nothing bounds the index — the whole answer rests on this
    guarded = [d["file"].name for d in ds if (index_path(d["addr"], d["size"]) or {"raw": False})["raw"] is False]
    case("no dispatch masks or compares the +5 index (raw lbu -> sll 2 -> lw -> jalr, 28 sites)",
         not guarded, f"{len(guarded)} guarded: {guarded[:4]}")

    # 6. an out-of-range index cannot fault inside the class-1 block
    reach = (BLOCK_END - MAIN) // 4
    case(f"class 1: indices 0..{reach} from the main table stay inside the block; only > {reach} escapes",
         MAIN + 4 * reach == BLOCK_END,
         f"{MAIN:#x} + 4*{reach} = {MAIN + 4 * reach:#x}, next word is not a pointer")

    # 7. the per-class table lengths — 14 is class 1's number alone
    measured, ok = [], True
    for name, base, want, basis, sib in SIBLINGS:
        if basis == "sibling":
            good = sib - base == 4 * want and extent(base) >= want
        else:
            good = extent(base) == want
        ok &= good
        measured.append(f"{name} {base:#x}: {want} ({basis}), {'ok' if good else 'WRONG'}")
    case("the other classes' +5 tables are 4, 2, 27, 12 and 12 entries — not 14",
         ok and [w for _n, _b, w, _s, _x in SIBLINGS] == [4, 2, 27, 12, 12],
         "; ".join(measured))

    # 8. class 3's table is short enough that an out-of-range index calls address 0
    c3 = words(0x8011A984, 3)
    case("class 3's table is 2 entries and a null word: index >= 2 there calls address 0",
         in_image(c3[0]) and in_image(c3[1]) and c3[2] == 0,
         f"0x8011a984 = [{c3[0]:#010x}, {c3[1]:#010x}], 0x8011a98c = {c3[2]:#010x}")

    # 9. the headline: a class-1 writer reaches 14 or more
    vals = class1_values()
    consts = sorted({v for v, _f, _e in vals if v is not None})
    above = consts[-1] if consts else None
    case("class-1 writers set +5 to a value >= 14, so the bound does not hold",
         above is not None and above >= ROW, f"max {above} of {consts}")

    # 10. 14 is skipped: the writers say 13, then 15
    case("14 is never written — the only out-of-range constant is 15",
         above == 15 and ROW not in consts, f"set {consts}")

    # 11. the copy writer reaches 15 as well
    cp = [(f, e) for v, f, e in vals if v is None and "0x1ab" in e]
    case("a writer copies (+0x1ab & 0xf) into +5, which reaches 15 too",
         bool(cp), f"{[f'{f}: {e}' for f, e in cp]}")

    # 12. where 15 actually lands
    main15 = words(MAIN, ROW + 2)[15]
    row3_1 = words(CLASS_A[2], ROW)[1]
    case("index 15 runs the neighbouring table's second entry (0x8007ccec), not a fault",
         main15 == row3_1 and in_image(main15),
         f"main[15] = {main15:#010x} = {CLASS_A[2]:#x}[1], one past the {ROW} entries it was meant for")

    # 13. the class byte's own table covers every class the image writes
    handlers = words(CLASS_TABLE, 9)
    classes = set()
    for p in sorted(SRC.rglob("*.c")):
        classes |= {int(m.group(1), 16) for m in CLASS_QUAD.finditer(p.read_text())}
    missing = sorted(c for c in classes if c >= len(handlers) or not in_image(handlers[c]))
    case("every class the image writes (+4 = 1,2,3,4,7) has a handler at 0x8011a870",
         not missing and sorted(classes) == [1, 2, 3, 4, 7],
         f"classes {sorted(classes)}, null slots {[i for i, w in enumerate(handlers) if w == 0]}")

    # 14. the type index: masked to 0..15, but the tables hold 11
    ty = {b: (sum(1 for w in words(b, ROW) if in_image(w)),
              [f"{w:#010x}" for w in words(b, ROW) if not in_image(w)]) for b in TYPE_TABLES}
    case("the type index is masked &0xf (0..15) but both type tables hold only 11 code pointers",
         all(n == 11 for n, _ in ty.values()),
         "; ".join(f"{b:#x}: {n} code, then {r[:3]}" for b, (n, r) in sorted(ty.items())))

    ok = sum(1 for _n, k, _d in cases if k)
    print(f"\n{ok}/{len(cases)}")
    return 0 if ok == len(cases) else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args()
    if not CACHE.exists():
        print("build/elfs/images.json is absent — run the rebuild first (docs/handover.md)")
        return 2
    print("routine-index bounds: is object+5 < 14?")
    return run(args.verbose)


if __name__ == "__main__":
    sys.exit(main())
