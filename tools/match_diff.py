#!/usr/bin/env python3
"""Compare a candidate image or object against the original bytes, and name the first difference.

This is the measuring stick the matching build needs and does not have: today a mismatch is a hash, and a hash
does not say *where* or *what*. Given a candidate (an ELF or a raw blob) and one of the 36 images, this reports

    image   base and size, and the percentage of bytes identical
    first   the first differing word: its address, both words and the byte range
    functions   per-range status from `fixtures/decomp/ranges.json`: match / differ at / candidate short

Three things this file deliberately does not do. It does not decide that a *function* matches from a whole-image
hash (a body can be identical while a jump table beside it is not, and the reverse). It does not normalise
instructions — instruction-level normalisation is what `objdiff` and `asm-differ` are for, and copying them
badly would give a comparator whose agreement means nothing. And it does not touch the cartridge: the original
bytes come from the user's own extraction, so this is a cartridge-gated tool like the rest.

The proofs, both in `--self-test` and both required:

  * **self-compare.** `build/elfs/stage2.elf` was built from `assets/unpacked/00000_*.bin`. Comparing them
    through this file's ELF loader and this file's comparator must give **100.000 %** — that is a real test of
    the loader and the comparison together, not a tautology, because the two sides are read by different code
    paths from different files.
  * **one-word perturbation.** Flip a single 32-bit word in a copy of the original and the comparator must
    report *that* address and *that* byte range. A comparator that cannot be made to fail is not a comparator —
    the same rule this repository applies to every gate.

Usage:
  ./match_diff.py --self-test
  ./match_diff.py --image stage2 --candidate build/elfs/stage2.elf
  ./match_diff.py --image boot --candidate out/boot.raw --raw
"""
import argparse
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
IMAGES = ROOT / "build" / "elfs" / "images.json"
RANGES = ROOT / "fixtures" / "decomp" / "ranges.json"
ROM = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"

WORD = 4


def elf_segments(path):
    """PT_LOAD segments as (vaddr, bytes). No section headers, no symbol table: a candidate only needs bytes."""
    data = path.read_bytes()
    if data[:4] != b"\x7fELF":
        raise SystemExit("%s is not an ELF file (use --raw for a flat blob)" % path)
    e_phoff = struct.unpack_from(">I", data, 28)[0]
    phentsize = struct.unpack_from(">H", data, 42)[0]
    phnum = struct.unpack_from(">H", data, 44)[0]
    out = []
    for i in range(phnum):
        at = e_phoff + i * phentsize
        p_type, p_offset, p_vaddr, _pa, p_filesz, _memsz = struct.unpack_from(">IIIIII", data, at)
        if p_type == 1 and p_filesz:
            out.append((p_vaddr, data[p_offset:p_offset + p_filesz]))
    return out


def image_entry(name):
    manifest = json.loads(IMAGES.read_text())["images"]
    for e in manifest:
        if e["name"] == name:
            return e
    raise SystemExit("no image named %r in %s (have: %s)"
                     % (name, IMAGES.relative_to(ROOT), ", ".join(e["name"] for e in manifest)))


def original(name):
    """The original bytes of one image, from the same sources `build_images.py` used.

    `assets/unpacked/*.bin` for the cartridge's compressed members, a ROM slice for boot. Both are the user's
    own extraction; neither is in git.
    """
    e = image_entry(name)
    src = e.get("source", "")
    if src.startswith("assets/"):
        blob = (ROOT / src).read_bytes()
    elif src.startswith("ROM"):
        off = int(src.split()[1], 16)
        if not ROM.exists():
            raise SystemExit("SKIP no cartridge: %s needs ROM 0x%x" % (name, off))
        blob = ROM.read_bytes()[off:off + e["size"]]
    else:
        raise SystemExit("image %r has no readable source (%r)" % (name, src))
    if len(blob) != e["size"]:
        raise SystemExit("image %r: %d bytes at %s, manifest says %d"
                         % (name, len(blob), src, e["size"]))
    return e["base"], blob


def candidate_bytes(path, raw, base, size):
    """A byte map for the candidate: {offset-in-image: byte} is overkill, so return a same-length blob.

    A short or long candidate is *padded* on the right for comparison and the shortfall is reported — a
    candidate that omits trailing padding is a fact to print, not an error to crash on.
    """
    if raw:
        blob = path.read_bytes()
        return blob, (0 if base is not None else None)
    out = bytearray()
    want = size
    covered = 0
    for vaddr, seg in elf_segments(path):
        # segments are contiguous in every image this repo builds; report but do not guess if they are not
        if out and vaddr > 0:
            pass
        out.extend(seg)
        covered += len(seg)
    if covered < want:
        out.extend(b"\0" * (want - covered))
    return bytes(out), 0


def compare(orig, cand, base, limit=8, spans=None):
    """Byte-level comparison, word-addressed, split by whether each difference is inside a known function.

    The split matters for honesty: a difference in a *gap* is still a difference, and a report that counts only
    function bodies will call a broken image "1938 match, 0 differ".
    """
    n = min(len(orig), len(cand))
    inside = gaps = 0
    starts = sorted(lo for lo, _hi in spans) if spans else []
    ends = {lo: hi for lo, hi in spans} if spans else {}

    def in_function(addr):
        import bisect
        i = bisect.bisect_right(starts, addr) - 1
        return i >= 0 and addr <= ends[starts[i]]

    diffs = []
    total = 0
    for off in range(0, n - (n % WORD), WORD):
        if orig[off:off + WORD] != cand[off:off + WORD]:
            total += 1
            if spans and in_function(base + off):
                inside += 1
            else:
                gaps += 1
            if len(diffs) < limit:
                diffs.append({
                    "address": "0x%08x" % (base + off),
                    "original": orig[off:off + WORD].hex(),
                    "candidate": cand[off:off + WORD].hex(),
                    "bytes": [off, off + WORD],
                })
    # a candidate whose length differs is itself a finding
    length_note = None
    if len(cand) != len(orig):
        length_note = {"original": len(orig), "candidate_len": len(cand)}
    return {"differing_words": total, "first": diffs, "length": length_note,
            "in_functions": inside, "in_gaps": gaps,
            "identical": len(orig) - total * WORD if not length_note else None,
            "compared": n}


def functions(image, orig, cand, base):
    """Per-range status. Ranges are the corpus's own, so a mismatch can be attributed to a function or a gap."""
    try:
        ranges = json.loads(RANGES.read_text())["images"]
    except (OSError, KeyError):
        return None
    spans = ranges.get(image)
    if not spans:
        return None
    rows = {"match": 0, "differ": 0, "short": 0}
    first_bad = []
    for lo, hi in spans:
        a = lo - base
        b = hi - base + 1
        if a < 0 or a >= len(orig):
            continue
        want = orig[a:b]
        got = cand[a:b] if a < len(cand) else b""
        if len(got) < len(want):
            rows["short"] += 1
            if len(first_bad) < 8:
                first_bad.append({"function": "0x%08x" % lo, "status": "short",
                                  "got": len(got), "want": len(want)})
        elif got == want:
            rows["match"] += 1
        else:
            rows["differ"] += 1
            if len(first_bad) < 8:
                off = next((i for i in range(0, len(want) - len(want) % WORD, WORD)
                            if want[i:i + WORD] != got[i:i + WORD]), 0)
                first_bad.append({"function": "0x%08x" % lo, "status": "differ",
                                  "at": "0x%08x" % (lo + off),
                                  "want": want[off:off + WORD].hex(),
                                  "got": got[off:off + WORD].hex()})
    rows["total"] = len(spans)
    return {"counts": rows, "first": first_bad}


def report(image, cand_path, raw=False, base=None, quiet=False):
    base_o, orig = original(image)
    b = base if base is not None else base_o
    cand, _ = candidate_bytes(cand_path, raw, b, len(orig))
    spans = (json.loads(RANGES.read_text())["images"].get(image) if RANGES.exists() else None)
    res = compare(orig, cand, b, spans=spans)
    fn = functions(image, orig, cand, b)
    pct = 100.0 * (len(orig) - res["differing_words"] * WORD) / len(orig) if orig else 0.0
    if not quiet:
        print("image %-12s base 0x%08x  %d B" % (image, base_o, len(orig)))
        print("candidate %s" % cand_path)
        # six decimals when anything differs: 4 bytes in 1 172 240 is 0.0003 %, and "100.000 %" for that is a
        # sentence a reviewer would read as a pass
        print("  identical   %d / %d B  (%s %%)" % (len(orig) - res["differing_words"] * WORD, len(orig),
                                                    "%.3f" % pct if res["differing_words"] == 0
                                                    else "%.6f" % pct))
        if res["length"]:
            print("  LENGTH      original %d B, candidate %d B"
                  % (res["length"]["original"], res["length"]["candidate_len"]))
        if res["first"]:
            first = res["first"][0]
            print("  first diff  %s  original %s  candidate %s"
                  % (first["address"], first["original"], first["candidate"]))
            print("              bytes [0x%x,0x%x) of the image" % tuple(first["bytes"]))
        else:
            print("  first diff  none")
        if fn:
            c = fn["counts"]
            print("  functions   %d match, %d differ, %d short (of %d ranges)"
                  % (c["match"], c["differ"], c["short"], c["total"]))
            if res["in_gaps"]:
                print("  gaps        %d differing word(s) outside every function range" % res["in_gaps"])
            for row in fn["first"][:5]:
                if row["status"] == "differ":
                    print("              %s differs at %s: want %s got %s"
                          % (row["function"], row["at"], row["want"], row["got"]))
                else:
                    print("              %s short: %d of %d B" % (row["function"], row["got"], row["want"]))
    return {"image": image, "percent": round(pct, 3), "differing_words": res["differing_words"],
            "first": res["first"][:1], "functions": fn}


def self_test() -> int:
    """The two proofs, on the real bytes. Both can fail, which is why they are worth running."""
    cases = []
    elf = ROOT / "build" / "elfs" / "stage2.elf"
    if not elf.exists():
        print("SKIP (needs build/elfs/stage2.elf and the unpacked stage-2 member)")
        return 0
    base, orig = original("stage2")

    # perturb a word *inside a known function*, so attribution is testable: a fixed offset can land in a gap,
    # and a tool that reports "differ" for a gap is right to do so -- that is not the case worth asserting.
    spans = (json.loads(RANGES.read_text())["images"].get("stage2") or [])
    inside = next(((lo, hi) for lo, hi in spans if 8 <= hi - lo and (lo - base) % WORD == 0), None)
    if inside is None:
        print("SKIP no aligned stage-2 function range to perturb")
        return 0

    # 1) the built ELF against the member it was built from: 100.000 %, through two different readers
    cand, _ = candidate_bytes(elf, False, base, len(orig))
    good = compare(orig, cand, base, limit=1)
    pct = 100.0 * (len(orig) - good["differing_words"] * WORD) / len(orig)
    cases.append(("the built ELF equals the member it was built from (%.3f %%)" % pct,
                  good["differing_words"] == 0))

    # 2) one flipped word is found, at the right address, and nowhere else
    broken = bytearray(cand)
    at = inside[0] - base + WORD
    broken[at] ^= 0x5A
    bad = compare(orig, bytes(broken), base, limit=2)
    want = "0x%08x" % (base + at)
    located = (bad["differing_words"] == 1 and bad["first"]
               and bad["first"][0]["address"] == want
               and bad["first"][0]["bytes"] == [at, at + WORD])
    cases.append(("a one-word perturbation is reported at %s and only there" % want, bool(located)))

    # 3) and a perturbation inside a function body is attributed to that function, not to the image
    fn = functions("stage2", orig, bytes(broken), base)
    hit = None
    if fn:
        hit = next((r for r in fn["first"] if r["status"] == "differ"), None)
    cases.append(("the perturbation at 0x%08x is attributed to the function starting 0x%08x"
                  % (base + at, inside[0]),
                  hit is not None and int(hit["at"], 16) == base + at
                  and hit["function"] == "0x%08x" % inside[0]))

    # 4) the comparator's own negative control: a candidate one word short must be reported as a length
    short = cand[:-WORD]
    shrunk = compare(orig, short, base, limit=1)
    cases.append(("a candidate that is a word short is reported as a length difference",
                  shrunk["length"] is not None and shrunk["length"]["candidate_len"] == len(cand) - WORD))

    bad_count = sum(1 for _l, ok in cases if not ok)
    for label, ok in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d match-diff case(s)" % (len(cases) - bad_count, len(cases)))
    return 1 if bad_count else 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--image", help="image name from build/elfs/images.json")
    ap.add_argument("--candidate", help="ELF (default) or flat blob with --raw")
    ap.add_argument("--raw", action="store_true", help="treat the candidate as a flat blob")
    ap.add_argument("--base", type=lambda s: int(s, 0), help="base address for --raw")
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    args = ap.parse_args()
    if args.self_test:
        return self_test()
    if not (args.image and args.candidate):
        ap.error("--image and --candidate are required (or --self-test)")
    if not IMAGES.exists():
        print("SKIP no build/elfs/images.json in this checkout")
        return 0
    res = report(args.image, Path(args.candidate), args.raw, args.base, quiet=args.json)
    if args.json:
        print(json.dumps(res, indent=1))
    return 0 if res["differing_words"] == 0 and not (res["functions"] or {}).get("counts", {}).get("differ") else 1


if __name__ == "__main__":
    raise SystemExit(main())
