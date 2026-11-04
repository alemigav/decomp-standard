#!/usr/bin/env python3
"""Patch gcc 2.8.1 for the constant-pool float defect (M261).

A CONST_DOUBLE holds two 32-bit *target-pattern* words, and the fast path in `immed_real_const_1` that stores
one is guarded by `sizeof u == 2 * sizeof (HOST_WIDE_INT)` -- false on a 64-bit host (8 == 16). So SFmode and
DFmode fell through to the "more than two words" path, where a raw bcopy dropped the emulator's packed *internal*
form into the rtx, and every reader decoded it as a target pattern. Two measured symptoms: every constant-pool
float came out as 0, and `mips_const_double_ok` -- which reads the same words -- never chose `li.s`, so the
fix also *changes codegen*, not just data.

Usage: patch_gcc281_fp.py <path to the unpacked gcc-2.8.1 source>
Idempotent: a source that already carries the marker is left alone. Every anchor is required to match exactly
once, so a source that drifts fails loudly instead of being half-patched.
"""
import sys
from pathlib import Path

MARKER = "M26"   # matches M261 and M264, so a file that carries either is left alone
EDITS = [
    ('varasm.c', '  if (sizeof u == 2 * sizeof (HOST_WIDE_INT))\n    return immed_double_const (u.i[0], u.i[1], mode);', '  /* M261: a CONST_DOUBLE holds two 32-bit words, and every reader -- including the constant pool -- decodes\n     them as the *target* bit pattern. Store that, and not the emulator\'s packed internal form. The test that\n     used to guard this path, `sizeof u == 2 * sizeof (HOST_WIDE_INT)`, is false on a 64-bit host (8 == 16), so\n     SFmode and DFmode fell through to the "more than two words" path below, where a raw bcopy dropped the\n     packed form into the rtx and every reader decoded it as a pattern: every pool float came out as 0.  */\n#ifdef REAL_VALUE_TO_TARGET_SINGLE\n  if (mode == SFmode || mode == DFmode)\n    {\n      long w0 = 0, w1 = 0;\n\n      if (mode == SFmode)\n\tREAL_VALUE_TO_TARGET_SINGLE (d, w0);\n      else\n\t{\n\t  long w[2];\n\t  REAL_VALUE_TO_TARGET_DOUBLE (d, w);\n\t  w0 = w[0];\n\t  w1 = w[1];\n\t}\n      return immed_double_const (w0, w1, mode);\n    }\n#endif\n\n  if (sizeof u == 2 * sizeof (HOST_WIDE_INT))\n    return immed_double_const (u.i[0], u.i[1], mode);', True),
    ('real.h', '#define REAL_VALUE_FROM_CONST_DOUBLE(to, from)\t\t\\\ndo { union real_extract u;\t\t\t\t\\\n     bcopy ((char *) &CONST_DOUBLE_LOW ((from)), (char *) &u, sizeof u); \\\n     to = u.d; } while (0)', '/* M261: the inverse of immed_real_const_1, which now stores the target bit pattern in the two words of a\n   CONST_DOUBLE. Reading them back as a packed emulator value is what made every constant-pool float 0.  */\n#define REAL_VALUE_FROM_CONST_DOUBLE(to, from)\t\t\t\t\\\ndo {\t\t\t\t\t\t\t\t\t\\\n     if (GET_MODE ((from)) == SFmode)\t\t\t\t\t\\\n       (to) = ereal_from_float ((HOST_WIDE_INT) CONST_DOUBLE_LOW ((from)));\t\\\n     else\t\t\t\t\t\t\t\t\\\n       {\t\t\t\t\t\t\t\t\\\n\t HOST_WIDE_INT w_[2];\t\t\t\t\t\t\\\n\t w_[0] = CONST_DOUBLE_LOW ((from));\t\t\t\t\\\n\t w_[1] = CONST_DOUBLE_HIGH ((from));\t\t\t\t\\\n\t (to) = ereal_from_double (w_);\t\t\t\t\\\n       }\t\t\t\t\t\t\t\t\\\n} while (0)'),
    ('varasm.c', '\t  bcopy ((char *) &CONST_DOUBLE_LOW (x), (char *) &u, sizeof u);\n\t  assemble_real (u.d, pool->mode);', '\t  REAL_VALUE_FROM_CONST_DOUBLE (u.d, x);\n\t  assemble_real (u.d, pool->mode);'),
]

# M265: the two changes the constant-pool matching needs, and they are coupled -- each alone moves p8 *away* from
# the image. (a) the cartridge contains zero `mtc1 $at` in 1.9 MB, so its compiler never took the `li.s`/`li.d`
# immediate path and every float constant came from memory; (b) the image's .rodata is `[table][pool]`, which only
# happens if the pool is emitted *after* the function body.
EDITS += [
    ("config/mips/mips.c",
     """  if (op == CONST0_RTX (mode))
    return TRUE;

  /* ??? li.s does not work right with SGI's Irix 6 assembler.  */""",
     """  if (op == CONST0_RTX (mode))
    return TRUE;

  /* M265: the cartridge contains **no `li.s`/`li.d` expansion at all** -- zero `mtc1 $at` in 1.9 MB of text --
     so the original compiler never took the immediate path for a float constant: every one is loaded from the
     pool. Returning FALSE makes this build place them the same way. Placement only; the pool word's *value* is
     the separate M261 fix. This is coupled with CONSTANT_POOL_BEFORE_FUNCTION below: alone it grows the pool in
     front of the jump table and shifts every table reference (p8 134/139 against 136/139).  */
  return FALSE;

  /* ??? li.s does not work right with SGI's Irix 6 assembler.  */"""),
    ("config/mips/mips.h",
     '#define ASM_OUTPUT_FLOAT(STREAM,VALUE)\t\t\t\t\t\\\n  mips_output_float (STREAM, VALUE)\n',
     "/* M265: the image's .rodata is [jump table][constant pool], so the pool has to be emitted after the\n   function body. The default (varasm.c) puts it before the body, which makes it [pool][table] and shifts every\n   table reference once the pool is non-empty -- and it is non-empty now that float constants are pooled.  */\n\n#define CONSTANT_POOL_BEFORE_FUNCTION 0\n\n#define ASM_OUTPUT_FLOAT(STREAM,VALUE)\t\t\t\t\t\\\n  mips_output_float (STREAM, VALUE)\n"),
]


# M292: the other half of the $at/$v0 residue, one layer over. `mips_check_split` refuses to split an address when
# the *mode* is wider than a word, which is why a DFmode pool load stays symbolic and the assembler expands it with
# $1 -- but SFmode is 4 bytes, so the SF pool address was being split into a pseudo register and the load came out as
# `lui $2` where the image has `lui $1`. The image splits no float address at all, so the guard also excludes the
# float class: FUN_80024558 goes from 137 to 139 of 139 with no change to any other recovered function.
EDITS += [
    ('config/mips/mips.c',
     '  if (GET_MODE_SIZE (mode) > UNITS_PER_WORD)\n    return 0;',
     '  /* M292: the image splits no *float* address. A load whose address stays symbolic is expanded by\n     the assembler with $1, which is what its pool loads show (lui $1 + a %lo displacement). A DFmode\n     load already took that path because 8 > UNITS_PER_WORD; an SFmode one is 4 bytes and was being\n     split into a pseudo register instead.  */\n  if (GET_MODE_CLASS (mode) == MODE_FLOAT\n      || GET_MODE_SIZE (mode) > UNITS_PER_WORD)\n    return 0;'),
]


# M291: the pool's *sharing* rule. The image gives every DFmode constant its own pool slot -- the double 2^32
# appears seven times inside FUN_800a3094, at 0x800ba630..0x800ba660 -- and shares its SFmode ones (both 4.0f
# reads in FUN_80024558 hit one slot). M267 removed deduplication for *every* mode and lost 46 words, because
# the float side then flooded the pool. Excluding only DFmode from both lookups is the asymmetry the image shows,
# and it moves FUN_80024558 from 136 to 137 of 139 words with no change to any other recovered function.
# The first anchor names `CONST_DOUBLE_LOW (r) == i0`, because the bare tail matches immed_real_const_1's loop
# as well; the second is space-indented in the pristine source.
EDITS += [
    ('varasm.c',
     '    if (CONST_DOUBLE_LOW (r) == i0 && CONST_DOUBLE_HIGH (r) == i1\n\t&& GET_MODE (r) == mode)\n      return r;',
     '    if (CONST_DOUBLE_LOW (r) == i0 && CONST_DOUBLE_HIGH (r) == i1\n\t&& GET_MODE (r) == mode\n\t/* M291: the image keeps one pool slot per *use* of a double constant and one per *value* of a\n\t   float constant; see the note in force_const_mem.  */\n\t&& mode != DFmode)\n      return r;'),
    ('varasm.c', '    if (compare_constant_rtx (mode, x, desc))',
     '    if (compare_constant_rtx (mode, x, desc) && mode != DFmode)   /* M291, see above */'),
]


def main(argv):
    if len(argv) != 2:
        print("usage: patch_gcc281_fp.py <gcc-2.8.1 source dir>", file=sys.stderr)
        return 2
    src = Path(argv[1])
    texts = {}
    for name, old, new, *rest in EDITS:
        one_shot = bool(rest and rest[0])
        p = src / name
        if p not in texts:
            if not p.is_file():
                print("missing: %s" % p, file=sys.stderr)
                return 1
            texts[p] = p.read_text()
        # One-shot applies to the edits that need it, not to the whole file (M291). The M261 writer edit
        # re-states the lines it replaces, so a per-anchor test cannot see that it has already run -- running it
        # twice duplicated the block, which is how this check was found (M261). But making it a *per-file* test
        # meant every later edit to varasm.c was skipped on a fresh tree, so a provisioned compiler differed from
        # the one the corpus was matched with: the pool-writer edit and both M291 anchors silently never applied.
        if one_shot and MARKER in texts[p]:
            continue
        seen = texts[p].count(old)
        if seen == 0:
            # the anchor is gone: that is "already applied" when the replacement is present, and a hard error
            # when it is not (M291 -- the old rule treated a second run as a failure, so re-provisioning a tree
            # stopped at the first non-idempotent-anchor edit).
            if new in texts[p]:
                continue
            print("anchor found 0 times in %s -- refusing" % p, file=sys.stderr)
            return 1
        if seen != 1:
            print("anchor found %d times in %s -- refusing" % (seen, p), file=sys.stderr)
            return 1
        texts[p] = texts[p].replace(old, new, 1)
    changed = [(p, t) for p, t in texts.items() if t != p.read_text()]
    if not changed:
        print("gcc 2.8.1: constant-pool fp patch already applied (M261)")
        return 0
    for p, t in changed:
        p.write_text(t)
    print("gcc 2.8.1: constant-pool fp patch applied (M261)")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
