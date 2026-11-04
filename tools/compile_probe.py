#!/usr/bin/env python3
"""The compile-probe corpus: which compiler profile reproduces this cartridge's code generation?

The matching roadmap's stage 4 asks one question before any function is translated: *what produced these
bytes?* This runs a small corpus of C snippets through every available compiler profile, compares the emitted
`.text` with the image, and — because a wrong C guess and a wrong compiler look identical in a byte diff —
carries a **codegen census** that fingerprints the image independently of any C.

Two things this file proved on its first run, both of which changed the plan:

  * **IDO 5.3 and IDO 7.1 are byte-identical** on every probe (`cc -O2 -non_shared -mips2 -G {0,8}`). They are
    not two hypotheses, they are one, and carrying both doubled the work for nothing.
  * **Neither reproduces the cartridge's move idiom.** For `int f(int a){return a;}` IDO emits
    `or v0,a0,zero` (`0x00801025`). The cartridge's own code contains `addu rd,rs,zero` **8 501** times and
    `or rd,rs,zero` **zero** times. That is not a C-writing problem — a move is the least ambiguous C in the
    language — it is a code-generator difference, and it **refutes IDO** for this target. `addu`-for-move is
    the GNU MIPS toolchain's idiom (the official SDK's `mipse-ultra-gcc`), which is the next candidate.

Why the byte diff alone cannot settle it, and is kept anyway: an object file holds **relocations**, not
addresses, so any probe that touches a global or a call differs from the image by construction. Probe 3
demonstrates that (`lui t6,0x0` against the image's `lui v0,0x8013`) and is reported as `relocated`, not as a
mismatch. The corpus therefore earns its keep on self-contained code, and the census carries the argument.

Two defects in *this* toolchain build are known and are not the C's fault, so they are named here rather
than debugged again every time a probe looks wrong: (a) **`as` must be given `-mcpu=r4300`** -- without it
binutils 2.7 does not set `cop_interlocks` and inserts a hazard `nop` after every `mtc1`, which costs one
recovered function 71 words; (b) **`cc1` writes every constant-pool FP literal as 0** (a 16-byte-union
`bcopy` of `CONST_DOUBLE_LOW` on a 64-bit host), so a float in `.rodata` cannot be compared at all -- only
the `.text` that loads it. Both are recorded in M260.

Usage:
  ./compile_probe.py --check     # run the corpus and the census
  ./compile_probe.py --list      # the probes and what class each one covers
"""
import argparse
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
TC = ROOT / "build" / "toolchain"
IMAGE = ROOT / "assets" / "unpacked" / "00000_0014420_1172240.bin"
RANGES = ROOT / "fixtures" / "decomp" / "ranges.json"
BASE = 0x80018A80
WORK = ROOT / "build" / "probe"
# M296: the *boot* image is not an unpacked member -- it sits raw at ROM 0x1000 and loads at 0x80000480, which is where
# the runtime lives. Every other probe compares against the stage-2 payload above, so the library layer needs its own
# reader. Same skip semantics: no cartridge, no case.
ROM = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
BOOT_ROM_OFF = 0x1000
BOOT_BASE = 0x80000480
BOOT_SIZE = 69952

# (id, source, address, size, class). Addresses are real stage-2 functions chosen by shape, not by address.
# The four codegen classes the corpus does NOT cover, and why. This is a refusal with a measurement behind
# it, not an omission: a probe needs a real function whose C is recoverable, and for these four the cartridge
# does not supply one at the sizes that make reconstruction cheap.
CLASSES_WITHOUT_A_PROBE = {
    # the switch class is probed by `switch_head()` below rather than by the generic loop: it needs the jump
    # table placed at the image's table address, which the generic link script does not do.
    "struct copy": "no function in the 36 images copies three consecutive words between two pointers, and the "
                   "eight-word copy this corpus can compile (0 hits in every image) is not there either",
    "integer divide": "candidate 0x8006e8bc is a *fragment*: it loads through s1, divides by s0 and ends in "
                      "`j 0x8006b...` — a tail jump, so the range boundary is inside a larger function",
    "floating point": "candidate 0x80083e60 is a fragment too: it computes with f2, which no argument "
                      "register carries, so its inputs come from before the range start",
}
PROBES = [
    ("p1", "void probe_empty(void) {}", 0x80029390, 8, "empty body"),
    ("p2", "int probe_second(int a, int b) { return b; }", 0x80035E34, 8, "return an argument"),
    # the image branches `beq` (skip the store when zero), so the source condition is `!= 0`; the globals are
    # named by their real addresses, which is what lets the linker script place them from the names
    ("p3", "extern int D_801314CC;\nextern int D_801344C0;\n"
           "void probe_cond_store(void) { if (D_801314CC != 0) { D_801344C0 = 1; } }",
     0x80025D60, 32, "conditional global store (relocation-bearing -- compared after linking)"),
    ("p4", "void probe_copy(char *d, char *s, int n) { char *e = d + n; do { *d++ = *s++; } while (d < e); }",
     0x80082474, 36, "byte-copy loop (delayed branch; the do-while form is the one that matches)"),
    ("p5", "int probe_ident(int a) { return a; }", None, 0, "identity (the move idiom)"),
]
# (label, kind, toolchain directory, flags). `kind` picks the pipeline: IDO's `cc` assembles with its own as1;
# gcc 2.7.2's `cc1` emits assembly that needs an assembler, and its `move` pseudo-instruction is expanded by
# *that* assembler -- modern gas picks `or`, the cartridge has `addu`, so the pipeline normalises it (below).
PROFILES = [("ido-5.3 G0", "ido", "ido-5.3", ["-O2", "-non_shared", "-mips2", "-G", "0"]),
            ("ido-7.1 G0", "ido", "ido-7.1", ["-O2", "-non_shared", "-mips2", "-G", "0"]),
            ("gcc2.7.2 -O", "gcc", "mips-gcc-2.7.2", ["-O", "-G", "0"]),
            ("gcc2.7.2 -O2", "gcc", "mips-gcc-2.7.2", ["-O2", "-G", "0"]),
            ("gcc2.8.1 -O", "gcc", "mips-gcc-2.8.1", ["-O", "-G", "0", "-mcpu=r4300"]),
            ("gcc2.8.1 -O2", "gcc", "mips-gcc-2.8.1", ["-O2", "-G", "0", "-mcpu=r4300"])]


def text_of(obj, name=".text"):
    d = Path(obj).read_bytes()
    if d[:4] != b"\x7fELF":
        return b""
    shoff, = struct.unpack_from(">I", d, 32)
    entsize, = struct.unpack_from(">H", d, 46)
    shnum, = struct.unpack_from(">H", d, 48)
    strndx, = struct.unpack_from(">H", d, 50)
    secs = [struct.unpack_from(">10I", d, shoff + i * entsize) for i in range(shnum)]
    stroff = secs[strndx][4]
    for s in secs:
        end = d.index(b"\0", stroff + s[0])
        if d[stroff + s[0]:end] == name.encode():
            return d[s[4]:s[4] + s[5]]
    return b""


MOVE = re.compile(r"^(\s*)move(\s+)(\$\d+),(\$\d+)\s*$", re.M)
GAS = TC / "binutils" / "bin"
# The SDK-era assembler, if it has been built: binutils 2.7's `as` expands `move` to `addu` on its own, which is
# the cartridge's idiom, so the pipeline prefers it and only falls back to modern gas + an explicit rewrite.
AS27 = TC / "src" / "bu27-build" / "gas" / "as.new"
SYM = re.compile(r"^D_([0-9A-Fa-f]{8})$")


def undefined_symbols(obj):
    """Names the object needs from outside, so a linker script can place them.

    This project already names globals by address (`D_801314CC`), so the script can be generated from the names
    instead of maintained by hand -- and if a name does not carry an address, linking fails loudly rather than
    silently placing it at zero.
    """
    d = Path(obj).read_bytes()
    if d[:4] != b"\x7fELF":
        return []
    shoff, = struct.unpack_from(">I", d, 32)
    shentsize, = struct.unpack_from(">H", d, 46)
    shnum, = struct.unpack_from(">H", d, 48)
    secs = [struct.unpack_from(">10I", d, shoff + i * shentsize) for i in range(shnum)]
    out = []
    for s in secs:
        if s[1] != 2:                      # SHT_SYMTAB
            continue
        strtab = secs[s[6]][4]
        for i in range(s[5] // 16):
            name_off, value, size, info, other, shndx = struct.unpack_from(">IIIBBH", d, s[4] + i * 16)
            end = d.index(b"\0", strtab + name_off)
            name = d[strtab + name_off:end].decode("latin-1")
            if shndx == 0 and value == 0 and name:      # SHN_UNDEF
                out.append(name)
    return out


def link_script(probe_addr, obj, workdir):
    names = undefined_symbols(obj)
    lines = ["ENTRY(_start)", "SECTIONS {", "  . = 0x%08X;" % probe_addr,
             "  .text : { *(.text) }",
             '  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.sbss) *(.bss) *(.data) }',
             "}"]
    head = []
    for n in names:
        m = SYM.match(n)
        if not m:
            return None, "undefined symbol %r carries no address in its name" % n
        head.append("%s = 0x%s;" % (n, m.group(1)))
    script = workdir / ("%s_%s.ld" % (workdir.name, probe_addr))
    script.write_text("\n".join(head + lines) + "\n")
    return script, None


def compile_probe(directory, flags, pid, out, kind="ido", flags_addr=None):
    cfile = WORK / ("%s.c" % pid)
    cfile.parent.mkdir(parents=True, exist_ok=True)
    cfile.write_text(PROBES_BY_ID[pid][1] + "\n")
    if kind == "ido":
        cc = TC / directory / "cc"
        if not cc.exists():
            return None, "no toolchain at %s" % cc.relative_to(ROOT)
        env = {"USR_LIB": str(cc.parent), "PATH": "/usr/bin:/bin"}
        proc = subprocess.run([str(cc), "-c"] + flags + ["-o", str(out), str(cfile)],
                              capture_output=True, text=True, env=env)
        if proc.returncode:
            return None, "compile failed"
        return text_of(out), None
    # gcc 2.7.2: cc1 emits assembly, then an assembler encodes it. The `move` pseudo-instruction is expanded by
    # the assembler, and the cartridge's expansion is `addu rd,rs,$zero` where modern gas chooses `or`. The
    # pipeline reproduces the cartridge's expansion explicitly rather than pretending the difference is codegen.
    cc1 = TC / directory / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists():
        return None, "no cc1 at %s" % cc1.relative_to(ROOT)
    asm = WORK / ("%s_%s.s" % (pid, directory))
    proc = subprocess.run([str(cc1), "-quiet"] + flags + ["-mips2", str(cfile), "-o", str(asm)],
                          capture_output=True, text=True, env={"PATH": "/usr/bin:/bin"})
    if proc.returncode:
        return None, "cc1 failed"
    if gas == GAS / "mips-linux-gnu-as":
        # only modern gas needs this: binutils 2.7 already expands `move` to `addu`
        text = asm.read_text()
        asm.write_text(MOVE.sub(r"\1addu\2\3,\4,$0", text))
    proc = subprocess.run([str(gas), "-EB", "-mips2", "-G", "0", "-o", str(out), str(asm)],
                          capture_output=True, text=True, env={"PATH": "/usr/bin:/bin"})
    if proc.returncode:
        return None, "assemble failed"
    if gas == AS27:
        # binutils 2.7 writes a `.symtab` whose sh_info modern ld rejects ("local symbol at index N >= sh_info"),
        # so the object is rewritten by 2.42's objcopy before linking. Its own ld 2.7 builds but produces an
        # empty file on this host, which is recorded in docs/TOOLCHAIN.md rather than worked around silently.
        fixed = out.with_suffix(".fix.o")
        subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), str(out), str(fixed)],
                       capture_output=True, text=True)
        if fixed.exists():
            out = fixed
    if flags_addr is None:
        return text_of(out), None
    script, err = link_script(flags_addr, out, WORK)
    if err:
        return None, err
    elf = out.with_suffix(".elf")
    proc = subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(script), "-o", str(elf), str(out)],
                          capture_output=True, text=True, env={"PATH": "/usr/bin:/bin"})
    if proc.returncode:
        return None, "link failed"
    return text_of(elf), None


PROBES_BY_ID = {}


def census(image):
    """How the cartridge writes a register move, over its own function bodies.

    A move is `addu rd,rs,$zero` (`rt == 0`) in the GNU toolchain and `or rd,rs,$zero` in IDO. Counting both
    across every function range is the fingerprint, because it does not depend on guessing any C.
    """
    counts = {"addu": 0, "or": 0}
    spans = json.loads(RANGES.read_text())["images"]["stage2"]
    for lo, hi in spans:
        for va in range(lo, hi - 3, 4):
            x = struct.unpack_from(">I", image, va - BASE)[0]
            if x >> 26:
                continue
            fn, rd, rs, rt = x & 0x3F, (x >> 11) & 31, (x >> 21) & 31, (x >> 16) & 31
            if rd == 0 or rt != 0 or rs == 0:
                continue
            if fn == 0x21:
                counts["addu"] += 1
            elif fn == 0x25:
                counts["or"] += 1
    counts["ranges"] = len(spans)
    return counts


# Dispatch heads, one per (bound, table, index source). Each is compiled as a switch with the same number of
# cases and linked with `.rodata` at *that head's* table address, so the comparison covers the two things that
# vary between them: the `sltiu` bound and the table address materialisation.
HEADS = [
    dict(tag="p6", head=0x8004FD1C, bound_at=0x8004FD1C, jr=0x8004FD3C, table=0x800B8BD0, bound=5,
         index="an incoming argument", cases=5),
    dict(tag="p7", head=0x80057E1C, bound_at=0x80057E30, jr=0x80057E4C, table=0x800B8F78, bound=7,
         index="the byte at ctx+6", cases=7),
    dict(tag="p8", head=0x80024558, bound_at=0x8002456C, jr=0x8002458C, table=0x800B69B0, bound=6,
         index="a global byte", cases=6),
    dict(tag="p9", head=0x80070120, bound_at=0x80070158, jr=0x80070174, table=0x800B96A8, bound=7,
         index="a command byte, `andi 0xff`", cases=7),
]


def _switch_source(ncases):
    body = "".join("    case %d: return %d;\n" % (i, i * 3 + 1) for i in range(ncases))
    return "int f(int idx) {\n  switch (idx) {\n%s  }\n  return 0;\n}\n" % body


def _words(blob, base, lo, hi):
    return [blob[lo - base + 4 * i:lo - base + 4 * i + 4] for i in range((hi - lo) // 4)]


def dispatch_signature(words):
    """The dispatch's own construction: the bound, the table address, the shift, and the op sequence.

    Registers are deliberately not compared -- which register holds the index is the register allocator's choice
    for the *whole* function -- and neither is the **delay slot**, which is filled from whatever the enclosing
    function has to put there (this cartridge uses it for the `lui`, for a frame store, or for the `sll`,
    depending on the head). The values that are read from every word, slot included, are the bound, the table
    address and the shift; only the *op sequence* excludes the slot.
    """
    ints = [int.from_bytes(w, "big") for w in words]
    bound = next((x & 0xFFFF for x in ints if (x >> 26) == 0x0B), None)
    table = None
    for i, x in enumerate(ints):
        if (x >> 26) == 0x0F:
            hi, rt = (x & 0xFFFF) << 16, (x >> 16) & 31
            for y in ints[i + 1:]:
                if (y >> 26) == 0x09 and ((y >> 21) & 31) == rt:
                    lo = (y & 0xFFFF) - (0x10000 if y & 0x8000 else 0)
                    table = (hi + lo) & 0xFFFFFFFF
                    break
            if table is not None:
                break
    shift = next(((x >> 6) & 0x1F for x in ints
                  if (x >> 26) == 0 and (x & 0x3F) == 0 and (x >> 16) & 31 != 0), None)
    branch = next((i for i, x in enumerate(ints) if (x >> 26) in (4, 5)), None)
    ops = []
    for i, x in enumerate(ints):
        if branch is not None and i == branch + 1:
            ops.append("slot")
            continue
        op, fn = x >> 26, x & 0x3F
        if op == 0x0B:
            ops.append("sltiu")
        elif op == 0x0F:
            ops.append("lui")
        elif op == 0x09:
            ops.append("addiu")
        elif op == 0 and fn == 0x00:
            ops.append("sll")
        elif op == 0 and fn == 0x21:
            ops.append("addu")
        elif op == 0x23:
            ops.append("lw")
        elif op == 0 and fn == 0x08:
            ops.append("jr")
            break
    return {"bound": bound, "table": table, "shift": shift, "ops": ops}


def head_probe(spec):
    """Compile a switch with `spec["cases"]` cases, link `.rodata` at the head's table, and signature-compare."""
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / ("%s.c" % spec["tag"])
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(_switch_source(spec["cases"]))
    s, o, fx = (c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o"))
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    ld.write_text("SECTIONS {\n  . = 0x%08X;\n  .text : { *(.text) }\n  . = 0x%08X;\n"
                  "  .rodata : { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) "
                  "*(.pdr) *(.data) *(.bss) *(.mdebug) }\n}\n" % (spec["bound_at"], spec["table"]))
    elf = c.with_suffix(".elf")
    # The object's `.rodata` aligns the table to 16 bytes; this cartridge's tables are 8-aligned
    # (`0x800b8f78`, `0x800b96a8`), so a script that places `.rodata` *at* the image's table address lands the
    # table 8 bytes late. Link once, read where the table actually went, and shift the section by that pad.
    def link(at):
        ld.write_text("SECTIONS {\n  . = 0x%08X;\n  .text : { *(.text) }\n  . = 0x%08X;\n"
                      "  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) "
                      "*(.comment) *(.pdr) *(.data) *(.bss) *(.mdebug) }\n}\n" % (spec["bound_at"], at))
        rc = subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                            capture_output=True).returncode
        return None if rc else text_of(elf)

    blob = link(spec["table"])
    if blob is None:
        return None
    first = next((i for i in range(0, len(blob) - 3, 4)
                  if int.from_bytes(blob[i:i + 4], "big") >> 26 == 0x0B), None)
    if first is None:
        return None
    image = IMAGE.read_bytes()
    want = dispatch_signature(_words(image, BASE, spec["bound_at"], spec["jr"] + 8))
    mine_blob = blob
    start = first
    got = dispatch_signature([mine_blob[start + 4 * k:start + 4 * k + 4]
                              for k in range((spec["jr"] - spec["bound_at"] + 8) // 4)])
    # What is codegen and what is layout. The **bound** and the **shift** are the compiler's decisions and are
    # compared exactly. The **table address** is codegen *if* the object's `.rodata` puts the table first: where
    # something precedes it the linked address is the image's plus that pad, which is a fact about this object's
    # layout and is reported rather than smoothed. The **op sequence** is not compared: the delay slot absorbs one
    # instruction and its content is the arms' (this cartridge's heads put the `lui`, a frame store, or the `sll`
    # there, while ours always puts the `lui`).
    pad = (got["table"] - spec["table"]) if got["table"] is not None else None
    return {"spec": spec, "want": want, "got": got, "table_pad": pad,
            "match": want["bound"] == got["bound"] and want["shift"] == got["shift"],
            "table_match": want["table"] == got["table"],
            "table_pad_is_layout": pad is not None and pad % 8 == 0}


# p6 as a whole function: the head and its five arms recovered from the disassembly. This is the only probe that
# compares the delay slot, because the slot is filled from the arms -- here the arms use the pointer and gcc puts
# it in `a3`, which is exactly what the image does.
P6_SOURCE = """typedef struct { unsigned char b0, b1, b2, b3; } S;
void f(S *s, short *p, int idx) {
  switch (idx) {
  case 0: *p = s->b3 << 4; break;
  case 1: *p = (s->b1 / s->b2) << 4;
          if (s->b1 == s->b3 * s->b2 - 1) break;
          s->b1 = s->b1 + 1; break;
  case 2: *p = (s->b1 / s->b2) << 4;
          s->b1 = s->b1 + 1;
          if ((unsigned char)s->b1 != s->b3 * s->b2) break;
          s->b1 = 0; break;
  case 3: *p = (s->b1 / s->b2) << 4;
          s->b1 = s->b1 + 1;
          if ((unsigned char)s->b1 != s->b3 * s->b2) break;
          s->b1 = s->b1 - s->b2; s->b0 = 132; break;
  case 4: s->b1 = s->b1 - 1;
          *p = (s->b1 / s->b2) << 4;
          if (s->b1 == 0) { s->b1 = s->b1 + s->b2; s->b0 = 131; } break;
  }
}
"""
P6_REGIONS = [("head", 0x8004FD1C, 40), ("arm0", 0x8004FD44, 16), ("arm1", 0x8004FD54, 76),
              ("arm2", 0x8004FDA0, 84), ("arm3", 0x8004FDF4, 92), ("arm4", 0x8004FE50, 84)]


def p6_function():
    """Compile the recovered whole function and diff it **content-aligned**.

    The first version sliced both sides at the image's region addresses, which silently compares misaligned code
    the moment any region differs in size — arms 2-4 read as 0/21 while in fact starting 8 bytes later with the
    same instructions. `SequenceMatcher` over the instruction sequences is the honest comparison: it says how many
    instructions differ and where, rather than pretending the offsets line up.
    """
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p6full.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(P6_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    ld.write_text("SECTIONS {\n  . = 0x8004FD1C;\n  .text : { *(.text) }\n  . = 0x800B8BD0;\n"
                  "  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) "
                  "*(.comment) *(.pdr) *(.data) *(.bss) *(.mdebug) }\n}\n")
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    blob = text_of(elf)
    want = [image[0x8004FD1C - BASE + 4 * i:0x8004FD1C - BASE + 4 * i + 4] for i in range((0x8004FEA4 - 0x8004FD1C) // 4)]
    got = [blob[4 * i:4 * i + 4] for i in range(len(blob) // 4)]
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    hunks = [o for o in sm.get_opcodes() if o[0] != "equal"]
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    divu = sum(1 for w in got if int.from_bytes(w, "big") >> 26 == 0 and (int.from_bytes(w, "big") & 0x3F) == 0x1B)
    off = sum(1 for a, b in zip(want, got) if a == b)
    return {"image_instrs": len(want), "got_instrs": len(got), "same": same, "hunks": len(hunks),
            "same_offset": off, "extra": len(got) - len(want), "divu": divu,
            "first": "0x%08x" % (0x8004FD1C + 4 * hunks[0][1]) if hunks else None}


def p7e590_residue():
    """Characterise the last three words of `0x8007e590` exactly, and test whether shape can move them.

    M289-M295 converged on "case 4's select register is a `global_alloc` conflict" without decoding the three
    words. This does the decode: same opcodes, same immediates, same base register — **only the destination
    register differs** (`$2` in the image, `$4` here). It then compiles three alternative spellings of the same
    select and checks that they produce byte-identical `.text`, which is what makes the tie-break's
    unreachability a measurement rather than an opinion (M304).
    """
    import json
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    image = IMAGE.read_bytes()
    lo, n, table = 0x8007E590, 229, 0x800B9C78
    syms = "".join("%s = 0x%X;\n" % (k, v) for k, v in P7E590_SYMS)

    def build(src, tag):
        d = WORK / "p7res"
        d.mkdir(parents=True, exist_ok=True)
        c, s, o, fx, elf = d / ("%s.c" % tag), d / ("%s.s" % tag), d / ("%s.o" % tag), d / ("%s.f.o" % tag), d / ("%s.elf" % tag)
        c.write_text(src)
        if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                          capture_output=True).returncode:
            return None
        if subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                          capture_output=True).returncode:
            return None
        subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                        "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
        (d / "l.ld").write_text("ENTRY(FUN_8007e590)\nSECTIONS {\n  . = 0x8007E590;\n  .text : { *(.text) }\n"
                                "  . = 0x800B9C78;\n  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { "
                                "*(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) "
                                "*(.mdebug*) *(.gnu.attributes) *(.note.GNU-stack) }\n}\n" + syms)
        if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(d / "l.ld"), "-o", str(elf), str(fx)],
                          capture_output=True).returncode:
            return None
        return text_of(elf)

    blob = build(P7E590_SOURCE, "base")
    if blob is None:
        return None
    got = [blob[4 * i:4 * i + 4] for i in range(len(blob) // 4)]
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range(n)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    diffs = [i for i in range(n) if want[i] != got[i]]

    def decode(w):
        v = int.from_bytes(w, "big")
        return {"op": v >> 26, "rs": (v >> 21) & 31, "rt": (v >> 16) & 31, "imm": v & 0xFFFF}

    pairs = [(decode(want[i]), decode(got[i])) for i in diffs]
    shape_only = (len(diffs) == 3 and all(a["op"] == b["op"] and a["imm"] == b["imm"]
                                         and a["rt"] != b["rt"] for a, b in pairs)
                  and [b["op"] for _a, b in pairs] == [9, 9, 0x28])
    # three ways of writing the same select must be byte-identical: the allocator ignores the spelling
    variants = {
        "tmp": P7E590_SOURCE.replace("s->f5 = (s->f5 == 22) ? 4 : 5;",
                                     "{ u8 v = (s->f5 == 22) ? 4 : 5; s->f5 = v; }", 1),
        "pre5": P7E590_SOURCE.replace("s->f5 = (s->f5 == 22) ? 4 : 5;",
                                      "{ u32 v = 5; if (s->f5 == 22) v = 4; s->f5 = v; }", 1),
        "cast": P7E590_SOURCE.replace("s->f5 = (s->f5 == 22) ? 4 : 5;",
                                      "s->f5 = (u8)((s->f5 == 22) ? 4 : 5);", 1),
    }
    same = 0
    for tag, src in variants.items():
        b = build(src, tag)
        if b is not None and b == blob:
            same += 1
    return {"image_instrs": n, "same_offset": off, "diffs": diffs, "residue_regs":
            [(a["rt"], b["rt"]) for a, b in pairs], "shape_only": shape_only,
            "spellings_tested": len(variants), "spellings_identical": same}


def permuter_rescore():
    """Score the committed permuter harness (`fixtures/permuter/p6/`) with the word metric.

    decomp-permuter steers toward `target.o`, which is a *proxy*: 116 instructions compiled from an earlier
    draft, against a 98-instruction function in the image, with unresolved relocations. That is fine for a
    candidate generator and useless as a verdict, which is why the pool is scored here instead -- same
    pipeline, same link addresses, words compared against the image (M299, M300).

    The point of the fixture is reproducibility: `build/` is gitignored, so the inputs to M256/M259 were
    gone by the time the verdict was questioned. Only our own artifacts are committed.
    """
    import json
    fx = ROOT / "fixtures" / "permuter" / "p6"
    rec = json.loads((fx / "scores.json").read_text())
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    image = IMAGE.read_bytes()
    lo, n, table = 0x8004FD1C, 98, 0x800B8BD0
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range(n)]

    def score(src):
        d = WORK / "perm"
        d.mkdir(parents=True, exist_ok=True)
        c = d / "c.c"
        c.write_text(src)
        s, o, fx, elf = d / "c.s", d / "c.o", d / "c.fix.o", d / "c.elf"
        if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                          capture_output=True).returncode:
            return None
        if subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                          capture_output=True).returncode:
            return None
        # binutils 2.42's `ld` rejects a 2.7 `as` object's symtab, so it goes through objcopy first -- the
        # same normalisation every other probe in this file does.
        subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), str(o), str(fx)], capture_output=True)
        (d / "c.ld").write_text("SECTIONS {\n  . = 0x8004FD1C;\n  .text : { *(.text) }\n  . = 0x800B8BD0;\n"
                                "  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) "
                                "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.mdebug) }\n}\n")
        if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(d / "c.ld"), "-o", str(elf), str(fx)],
                          capture_output=True).returncode:
            return None
        blob = text_of(elf)
        got = [blob[4 * i:4 * i + 4] for i in range(len(blob) // 4)]
        return sum(1 for a, b in zip(want, got) if a == b)

    scores = {}
    for f, tag in [(fx / "base.c", "base")] + [(p, p.stem) for p in sorted(fx.glob("candidate-*.c"))]:
        scores[tag] = score(f.read_text())
    def target_words(name):
        """Word count of a committed/generated objective object, or 0 when it has not been built."""
        obj = fx / name
        if not obj.exists():
            return 0, b""
        blob = WORK / "perm" / ("%s.bin" % obj.stem)
        blob.parent.mkdir(parents=True, exist_ok=True)
        subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "-O", "binary", "--only-section=.text",
                        str(obj), str(blob)], capture_output=True)
        raw = blob.read_bytes() if blob.exists() else b""
        blob.unlink(missing_ok=True)
        return len(raw) // 4, raw

    draft_words, _draft_raw = target_words("target-draft.o")
    image_tgt_words, image_tgt_raw = target_words("target.o")
    return {"image_words": n, "table": table, "scores": scores, "recorded": rec.get("candidates", {}),
            "target_words": draft_words, "draft_words": draft_words,
            "image_target_words": image_tgt_words,
            "image_target_exact": image_tgt_raw == b"".join(want) if image_tgt_raw else False}


def permuter_rescore_boot():
    """Score the `osCreateThread` permuter fixture (`fixtures/permuter/d60/`) against the boot image.

    Companion to `permuter_rescore()`, and the negative half of the same experiment (M303): the permuter closed
    p6's *shape* residue and moves nothing on this **allocation** residue, which is the split the corpus keeps
    re-learning -- size is not what makes a function hard, allocation is.
    """
    import json
    fx = ROOT / "fixtures" / "permuter" / "d60"
    rec = json.loads((fx / "scores.json").read_text())
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists() or not ROM.exists():
        return None
    image = ROM.read_bytes()[BOOT_ROM_OFF:BOOT_ROM_OFF + BOOT_SIZE]
    lo, n = 0x80006D60, 52
    syms = [("__osActiveQueue", 0x8001294C), ("__osDisableInt", 0x800072E0),
            ("__osRestoreInt", 0x80007300), ("__osCleanupThread", 0x8000116C)]
    want = [image[lo - BOOT_BASE + 4 * i:lo - BOOT_BASE + 4 * i + 4] for i in range(n)]

    def score(src):
        d = WORK / "permb"
        d.mkdir(parents=True, exist_ok=True)
        c = d / "c.c"
        c.write_text(src)
        s, o, fx_o, elf = d / "c.s", d / "c.o", d / "c.fix.o", d / "c.elf"
        if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                          capture_output=True).returncode:
            return None
        if subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                          capture_output=True).returncode:
            return None
        subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), str(o), str(fx_o)], capture_output=True)
        (d / "c.ld").write_text("SECTIONS {\n  . = 0x80006D60;\n  .text : { *(.text) }\n  /DISCARD/ : { *(.reginfo) "
                                "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.mdebug) *(.rodata) "
                                "*(.gnu.attributes) }\n}\n"
                                + "".join("%s = 0x%X;\n" % (k, v) for k, v in syms))
        if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(d / "c.ld"), "-o", str(elf), str(fx_o)],
                          capture_output=True).returncode:
            return None
        blob = text_of(elf)
        got = [blob[4 * i:4 * i + 4] for i in range(len(blob) // 4)]
        return {"off": sum(1 for a, b in zip(want, got) if a == b), "got": len(got)}

    base = score((fx / "base.c").read_text())
    cands = {p.name: score(p.read_text()) for p in sorted(fx.glob("candidate-*.c"))}
    best = cands.get("candidate-765-1.c")
    return {"image_words": n, "base": base, "candidate": best, "recorded": rec.get("byte_metric", {})}


# p7 as a whole function: the recovery done for p6, on the head whose bound is **7** and whose index is the byte at
# `ctx+6`. Two things make it a different question from p6: its seven arms live inside ONE contiguous 336-byte
# range rather than in six separate corpus functions, and two of them fall through (`0` into `1`, `4` into `5`),
# so the image's table entries land mid-arm. The three externs and both callees must be *placed* at their image
# addresses, or the link has nothing to compare.
P7_SOURCE = """typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u32 f0;
    u16 f4;
    u8  mode;
    u8  f7;
    u8  pad[0x1d8];
    u32 f1e0;
    u32 f1e4;
    u32 f1e8;
};

struct Dev { u8 pad[0x1a5c]; u32 reg; u32 reg2; };

extern u8 D_800C76B0[];
extern u8 D_8012BFA8[];
extern u8 D_80131780[];

extern int  FUN_80089d54(struct Ctx *s, int a1, void *tbl, u32 flags);
extern void FUN_800551e0(void);

void FUN_80057e1c(struct Ctx *s, int a1, void *tbl)
{
    u8 *q;

    switch (s->mode) {
    case 0: {
        u8 *dev;
        s->f1e8 = 0x06000700;
        s->mode = 1;
        s->f1e0 = 0;
        dev = D_800C76B0;
        ((struct Dev *)(dev + 0x18000))->reg |= 0xc0;
        }

    case 1:
        s->mode += FUN_80089d54(s, a1, tbl, 0x200);
        break;
    case 2: {
        u8 *dev;
        D_8012BFA8[0] = 2;
        dev = D_800C76B0;
        ((struct Dev *)(dev + 0x18000))->reg |= 0x8000;
        D_80131780[0] = 1;
        q = D_80131780;
        *(u32 *)(q + 0x44) = ((struct Dev *)(dev + 0x18000))->reg2;
        s->mode = 3;
        break;
    }
    case 3:
        break;
    case 4:
        s->f1e8 = 0x06000700;
        s->mode = 5;

    case 5:
        s->mode += FUN_80089d54(s, a1, tbl, 0x10200);
        break;
    case 6: {
        u8 *dev;
        FUN_800551e0();
        *(u32 *)&s->f4 = 0x01000000;
        dev = D_800C76B0;
        ((struct Dev *)(dev + 0x18000))->reg &= ~0x80;
        ((struct Dev *)(dev + 0x18000))->reg &= ~0x40;
        break;
    }
    }
}"""
P7_TABLE = 0x800B8F78
P7_SYMS = [("D_800C76B0", 0x800C76B0), ("D_8012BFA8", 0x8012BFA8), ("D_80131780", 0x80131780),
           ("FUN_80089d54", 0x80089D54), ("FUN_800551e0", 0x800551E0)]


def p7_function():
    """Compile the recovered p7 and compare 84 words of text plus the 8-word jump table.

    Two numbers on purpose: the text is the reconstruction's business and the table is the *link's*, so
    conflating them would let a correct table hide a wrong arm. `objcopy --set-section-alignment` is required
    because binutils 2.7's `as` leaves `.text` at 16-byte alignment, which shifts the whole function by 4 bytes
    and makes every word look different for a reason that has nothing to do with the C.
    """
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p7full.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(P7_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    syms = "".join("%s = 0x%X;\n" % (n, a) for n, a in P7_SYMS)
    ld.write_text("ENTRY(f_probe)\nSECTIONS {\n  . = 0x80057E1C;\n  .text : { *(.text) }\n"
                  "  . = 0x800B8F78;\n  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n" + syms)
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    lo, hi = 0x80057E1C, 0x80057F6C
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range((hi - lo) // 4)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    hunks = [o for o in sm.get_opcodes() if o[0] != "equal"]
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    tw = [image[P7_TABLE - BASE + 4 * i:P7_TABLE - BASE + 4 * i + 4] for i in range(8)]
    ro = text_of(elf, ".rodata")
    gw = [ro[4 * i:4 * i + 4] for i in range(len(ro) // 4)][:8]
    off = sum(1 for a, b in zip(want, got) if a == b)
    return {"image_instrs": len(want), "got_instrs": len(got), "same": same, "hunks": len(hunks),
            "same_offset": off,
            "extra": len(got) - len(want), "table_same": sum(1 for a, b in zip(tw, gw) if a == b),
            "arm0": sum(1 for i in range(14) if want[14 + i] == got[14 + i]),
            "first": "0x%08x" % (lo + 4 * hunks[0][1]) if hunks else None}



# p8 as a whole function: bound **6**, index a **global byte**, table `0x800b69b0`. It is the first probe whose arms
# are *Gfx command packets* (`w0`/`w1` word pairs written through a block-scoped temp pointer), so it exercises the
# `move/addiu/sw/sw` idiom rather than a state machine. Two layout facts make it unlike p6/p7, and both are
# reported instead of smoothed: our `.rodata` holds the constant pool **before** the jump table (the image has
# [table][pool]), so the table lands 16 bytes late; and `cc1` in this build writes every FP pool literal as **0**
# (a host-portability defect -- see the module docstring), so the pool's one float cannot be compared at all.
P8_SOURCE = """typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern u8 DAT_800e923c;
extern u32 DAT_801137d8;
extern u32 DAT_801137dc;
extern u32 DAT_8010b6fc;
extern u32 DAT_800c4f08[];

Gfx *FUN_80024558(Gfx *p)
{
    switch (DAT_800e923c) {
    case 0:
        { Gfx *_g = p; p = p + 1; _g->w0 = 0xE3001001; _g->w1 = 0; }
        { Gfx *_g = p; p = p + 1; _g->w0 = 0xE200001C; _g->w1 = 0; }
        { Gfx *_g = p; p = p + 1; _g->w0 = 0xE3000A01; _g->w1 = 0x00200000; }
        { Gfx *_g = p; p = p + 1; _g->w0 = 0x0A000000; _g->w1 = (u32)DAT_800c4f08; }
        break;
    case 1:
    case 2:
    case 5:
        break;
    case 3:
    case 4:
        { Gfx *_g = p; p = p + 1; _g->w0 = 0xE7000000; _g->w1 = 0; }
        { Gfx *_g = p; p = p + 1; _g->w0 = 0xFF100000 | ((DAT_801137d8 - 1) & 0xFFF); _g->w1 = DAT_8010b6fc; }
        { Gfx *_g = p; p = p + 1; _g->w0 = 0xED000000; _g->w1 = (((s32)((float)DAT_801137d8 * 4.0f)) & 0xFFF) << 12
                            | (((s32)((float)DAT_801137dc * 4.0f)) & 0xFFF); }
        { Gfx *_g = p; p = p + 1; _g->w0 = 0xE3000A01; _g->w1 = 0x00300000; }
        { Gfx *_g = p; p = p + 1; _g->w0 = 0xFCFFFFFF; _g->w1 = 0xFFFE793C; }
        { Gfx *_g = p; p = p + 1; _g->w0 = 0xE200001C; _g->w1 = 0x0F0A4000; }
        { Gfx *_g = p; p = p + 1; _g->w0 = 0xF7000000; _g->w1 = 0xFFFCFFFC; }
        { Gfx *_g = p; p = p + 1; _g->w0 = 0xF6000000 | (((DAT_801137d8 - 1) & 0x3FF) << 14) | (((DAT_801137dc - 1) & 0x3FF) << 2); _g->w1 = 0; }
        break;
    }
    return p;
}"""
P8_TABLE = 0x800B69B0
P8_ARMS = [0x80024594, 0x80024770, 0x80024770, 0x80024600, 0x80024600, 0x80024770]
P8_SYMS = [("DAT_800e923c", 0x800E923C), ("DAT_801137d8", 0x801137D8), ("DAT_801137dc", 0x801137DC),
           ("DAT_8010b6fc", 0x8010B6FC), ("DAT_800c4f08", 0x800C4F08)]


def p8_function():
    """Compile the recovered p8 and compare 139 words of text, its 27-word first arm, and the jump table.

    `as` must be told `-mcpu=r4300`: without it the assembler does not set `cop_interlocks` and inserts a hazard
    `nop` after every `mtc1`, which costs this function **71 words** (45 of 139 against 116 of 139). That is a
    property of the *assembler the SDK used*, not of the C, so the whole pipeline passes it now.
    """
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p8full.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(P8_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    syms = "".join("%s = 0x%X;\n" % (n, a) for n, a in P8_SYMS)
    ld.write_text("ENTRY(f_probe)\nSECTIONS {\n  . = 0x80024558;\n  .text : { *(.text) }\n"
                  "  . = 0x800B69B0;\n  .rodata : { *(.rodata) *(.rodata.*) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n" + syms)
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    lo = 0x80024558
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range(139)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    hunks = len([o for o in sm.get_opcodes() if o[0] != "equal"])
    c0 = (0x80024594 - lo) // 4
    arm0 = sum(1 for i in range(27) if want[c0 + i] == got[c0 + i])
    ro = [text_of(elf, ".rodata")[4 * i:4 * i + 4].hex() for i in range(len(text_of(elf, ".rodata")) // 4)]
    run = ["%08x" % w for w in P8_ARMS]
    table_at = None
    for i in range(len(ro) - 5):
        if ro[i:i + 6] == run:
            table_at = i
    return {"image_instrs": len(want), "got_instrs": len(got), "same_offset": off, "same": same,
            "hunks": hunks, "arm0": arm0, "table_at": table_at, "table_words": 6 if table_at is not None else 0}


def fp_pool_check():
    """The instrument's float path: constants must go to the pool, and the pool must carry their real bits.

    Not a cartridge probe -- a check on the compiler, and it encodes the two things M261/M265 measured. (a) The
    image contains **zero `mtc1 $at` in 1.9 MB**, i.e. no `li.s`/`li.d` expansion anywhere, so its compiler never
    took the immediate path for a float constant: ours must not either. (b) The pool word must be the real IEEE
    pattern; before M261 every one of them was `0`. Both are asserted because a rebuilt compiler can get one
    right and the other wrong -- which is exactly what happened between M261 and M265.
    """
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    if not cc1.exists():
        return None
    out = {}
    for tag, source, expect in (("big", "float probe_fp(float x) { return x * 3.0e38f; }", "0x7f61b1e6"),
                                ("small", "float probe_fp2(float x) { return x * 4.0f; }", "0x40800000")):
        c = WORK / ("fp_%s.c" % tag)
        c.parent.mkdir(parents=True, exist_ok=True)
        c.write_text(source + "\n")
        s = c.with_suffix(".s")
        if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                          capture_output=True).returncode:
            return None
        text = s.read_text()
        words = re.findall(r"^\s*\.word\s+(0x[0-9a-fA-F]+)", text, re.M)
        out[tag] = words[0] if words else None
        out[tag + "_inline"] = "li.s" in text
    # the image itself: no li.s expansion exists anywhere in it
    image = IMAGE.read_bytes()[: (IMAGE.stat().st_size // 4) * 4]
    words = struct.unpack(">%dI" % (len(image) // 4), image)
    out["image_li_s"] = sum(1 for w in words if (w & 0xFFE007FF) == 0x44800800)
    return out



# p9 as a whole function: bound **7**, index a **command byte after `andi 0xff`**, table `0x800b96a8`, 46 words.
# It is the smallest recovery and the first that is a *predicate dispatcher* rather than a state machine: the seven
# arms are `==`, `>`, `>=`, `<`, `<=`, `!=` and `(a & b) != 0` on a callee's return value, and the arms fall into a
# shared epilogue. Two shape facts were measured, not guessed: the field loaded with `lhu` must be held in a **32-bit**
# local (a `u16` local re-extends it in every arm and scores 9 of 46), and the source has **no `default:` and no
# trailing `return`** -- the out-of-range path lands on the epilogue with `v0` still 0 from the `sltiu`, and adding
# either costs 16 words.
P9_SOURCE = """typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

struct Ctx {
    u8 pad0[0x1c];
    u8 *ptr;
    u8 pad20[0x134];
    u8 *f154;
};

extern int FUN_800701d8(u8 *p, int a1);

int FUN_80070120(struct Ctx *s)
{
    u8 *p;
    unsigned int w;
    int v;
    int x;

    p = s->ptr;
    w = *(u16 *)(p + 2);
    v = *(s16 *)(p + 4);
    s->ptr = p + 6;
    x = FUN_800701d8(s->f154, w >> 8);

    switch (w & 0xff) {
    case 0: return x == v;
    case 1: return x > v;
    case 2: return x >= v;
    case 3: return x < v;
    case 4: return x <= v;
    case 5: return x != v;
    case 6: return (x & v) != 0;
    }
}"""
P9_TABLE = 0x800B96A8
P9_SYMS = [("FUN_800701d8", 0x800701D8)]


def p9_function():
    """Compile the recovered p9 and compare its 46 words plus the 8-word jump table.

    The table here is 8 words for 7 cases: the eighth entry is zero and is never read -- the bound check sends the
    out-of-range index to the epilogue instead.
    """
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p9full.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(P9_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    syms = "".join("%s = 0x%X;\n" % (n, a) for n, a in P9_SYMS)
    ld.write_text("ENTRY(f_probe)\nSECTIONS {\n  . = 0x80070120;\n  .text : { *(.text) }\n"
                  "  . = 0x800B96A8;\n  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n" + syms)
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    lo = 0x80070120
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range(46)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    hunks = len([o for o in sm.get_opcodes() if o[0] != "equal"])
    tw = [image[P9_TABLE - BASE + 4 * i:P9_TABLE - BASE + 4 * i + 4] for i in range(8)]
    ro = text_of(elf, ".rodata")
    gw = [ro[4 * i:4 * i + 4] for i in range(8)]
    return {"image_instrs": len(want), "got_instrs": len(got), "same_offset": off, "same": same,
            "hunks": hunks, "extra": len(got) - len(want),
            "table_same": sum(1 for a, b in zip(tw, gw) if a == b),
            "first": ("0x%08x" % (lo + 4 * [o for o in sm.get_opcodes() if o[0] != "equal"][0][1]))
                     if any(o[0] != "equal" for o in sm.get_opcodes()) else None}



# The largest whole function recovered so far: 167 words, bound **7**, index `lbu 6(ctx)` -- the same index source
# p7 uses -- and 7 contiguous arms whose sizes are wildly uneven (41 words against 6). It is a game-state machine
# that touches the same device window as p7. Three shape levers were required and each is a *measured* discriminator:
# a word field and the bytes inside it must be **one union member** (sibling `u8` fields let gcc prove the byte reads
# disjoint from the word store and re-schedule the whole body: 136 of 167), the fields written with `lhu`/`sh` must be
# **`u16` with an explicit `(s16)` cast** only in the predicates (declaring them `s16` costs 7 words), and a compound
# test must be **nested `if`s** rather than `&&` because the pointer assignment between them is what stops the symbol
# address from being kept live across the branch (a flat chain costs 10 words in that arm). There is no pool literal
# in it at all -- every constant is `lui`/`ori` or an immediate -- so the pool pathologies of p6/p8 cannot arise here.
P59868_SOURCE = """typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

struct Dev {
    u8  pad[0x1c6a];
    u8  f1c6a;
};

struct Ctx {
    u32 f0;
    u16 f4;
    u8  mode;
    u8  f7;
    u8  pad8[0x28 - 0x8];
    u8  f28[0x1a4 - 0x28];
    u32 f1a4;
    u8  pad1a8[0x1e0 - 0x1a8];
    u16 f1e0;
    s16 f1e2;
    s16 f1e4;
    u8  pad1e6[2];
    union {
        u32 w;
        u8  b[4];
    } f1e8;
    u8  pad1ec[0x1f2 - 0x1ec];
    s16 f1f2;
    u16 f1f4;
    u8  pad1f6[0x218 - 0x1f6];
    u32 f218;
    u8  pad21c[0x224 - 0x21c];
    u32 f224;
    u32 f228;
    u8  pad22c[0x25c - 0x22c];
    u8  f25c;
    u8  pad25d[0x26f - 0x25d];
    u8  f26f;
};

extern u8 D_800C76B0[];

extern void FUN_80077adc(u32 a0, void *a1);
extern void FUN_80032b5c(void *a0, u32 a1);
extern int  FUN_80089d54(struct Ctx *a0, u32 a1, u32 a2, u32 a3);
extern int  FUN_800331b8(void);
extern void FUN_800551e0(void);

void FUN_80059868(struct Ctx *s)
{
    switch (s->mode) {
    case 0:
        s->f1e8.w = 0x05000300;
        s->mode = 1;
        s->f1e0 = 400;
        s->f1e2 = 0;
        s->f1e4 = 0;
        s->f26f |= 0x80;
        s->f25c |= 0x12;
        FUN_80077adc(0x04020001, s->f28);
        s->f0 &= ~4;

    case 1: {
        u8 *dev;
        if (s->f1e8.b[1] == 5) {
            dev = D_800C76B0;
            if (((struct Dev *)(dev + 0x18000))->f1c6a == 3)
                FUN_80077adc(0x04020001, s->f28);
        }
        FUN_80032b5c(s, 0);
        s->mode += FUN_80089d54(s, s->f224, s->f228, 0x400);
        if (s->f1e8.b[2])
            s->f1e0 -= 20;
        else
            s->f1e0 -= 50;
        if ((s16)s->f1e0 < 0)
            s->f1e0 = 0;
        break;
    }
    case 2:
        s->f1e8.w = 0x04000300;
        s->mode = 3;
        s->f1f4 = 30;
        if (s->f1f2 < 150)
            s->f1f4 = 60;
        if (s->f1f2 < 70)
            s->f1f4 += 50;
        if (s->f1f2 < 30)
            s->f1f4 += 50;
        if (s->f1f2 == 0)
            s->f1f4 += 100;

    case 3:
        FUN_80089d54(s, s->f224, s->f228, 0x10400);
        s->f1f4 -= FUN_800331b8() * 3 + 1;
        if ((s16)s->f1f4 < 0)
            s->mode = 4;
        break;
    case 4:
        s->f1e8.w = 0x01000300;
        s->mode = 5;
        s->f26f = 0;

    case 5:
        if (FUN_80089d54(s, s->f224, s->f228, 0x400) != 0) {
            s->mode = 6;
            s->f1e8.w = 0x06000300;
        }
        break;
    case 6:
        if (FUN_80089d54(s, s->f1a4, s->f218, 0x10400) != 0) {
            FUN_800551e0();
            *(u32 *)&s->f4 = 0x01000000;
            s->f26f = 0;
            s->f25c &= 0xed;
        }
        break;
    }
}"""
P59868_TABLE = 0x800B9040
P59868_SYMS = [("D_800C76B0", 0x800C76B0), ("FUN_80077adc", 0x80077ADC), ("FUN_80032b5c", 0x80032B5C),
               ("FUN_80089d54", 0x80089D54), ("FUN_800331b8", 0x800331B8), ("FUN_800551e0", 0x800551E0)]
P59868_ARMS = [0x800598A0, 0x800598FC, 0x800599A0, 0x80059A20, 0x80059A6C, 0x80059A84, 0x80059AB4]


def p59868_function():
    """Compile the 167-word state machine and compare every word plus its 8-word jump table."""
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p59868.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(P59868_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    syms = "".join("%s = 0x%X;\n" % (n, a) for n, a in P59868_SYMS)
    ld.write_text("ENTRY(f_probe)\nSECTIONS {\n  . = 0x80059868;\n  .text : { *(.text) }\n"
                  "  . = 0x800B9040;\n  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n" + syms)
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    lo, n = 0x80059868, 167
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range(n)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    hunks = len([o for o in sm.get_opcodes() if o[0] != "equal"])
    tw = [image[P59868_TABLE - BASE + 4 * i:P59868_TABLE - BASE + 4 * i + 4] for i in range(8)]
    ro = text_of(elf, ".rodata")
    gw = [ro[4 * i:4 * i + 4] for i in range(8)]
    arms_exact = sum(1 for a in P59868_ARMS if want[(a - lo) // 4] == got[(a - lo) // 4])
    return {"image_instrs": n, "got_instrs": len(got), "same_offset": off, "same": same, "hunks": hunks,
            "extra": len(got) - n, "table_same": sum(1 for a, b in zip(tw, gw) if a == b),
            "arms_exact": arms_exact}



# The widest dispatch recovered so far: 206 words, bound **12**, index `lbu 6(ctx)`, twelve arms from 32 words down
# to 9, and a shared 5-word tail. It is the state machine that runs *immediately before* 0x80059868 in the same
# module -- its last word is 0x80059864 and the other function starts at 0x80059868 -- so they share the `Ctx` layout
# and the device idiom, and this one's source reuses them. Three facts are pinned by single words here: a negative
# constant stored into a `u16` field must arrive as a *signed* value (`addiu rt,zero,-800`, not `ori rt,zero,0xfce0`),
# two structurally identical clamps in one function need **opposite** comparisons (`blez` here, `bgez` eight cases
# later), and a `* k` is visible in the shamt of the `sll` feeding its `addu` (this function's is `* 5`, its
# neighbour's `* 3`).
P59530_SOURCE = """typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

struct Ctx {
    u32 f0;
    u16 f4;
    u8  mode;
    u8  f7;
    u8  pad8[0x28 - 0x8];
    u8  f28[0x1a4 - 0x28];
    u32 f1a4;
    u8  pad1a8[4];
    u32 f1ac;
    u8  pad1b0[0x1e0 - 0x1b0];
    u16 f1e0;
    s16 f1e2;
    s16 f1e4;
    u8  pad1e6[2];
    union {
        u32 w;
        u8  b[4];
    } f1e8;
    u8  pad1ec[0x1f2 - 0x1ec];
    s16 f1f2;
    u16 f1f4;
    u8  pad1f6[0x218 - 0x1f6];
    u32 f218;
    u8  pad21c[0x224 - 0x21c];
    u32 f224;
    u32 f228;
    u8  pad22c[0x25c - 0x22c];
    u8  f25c;
    u8  pad25d[0x26f - 0x25d];
    u8  f26f;
};

extern void FUN_80077adc(u32 a0, void *a1);
extern void FUN_80032b5c(void *a0, u32 a1);
extern int  FUN_80089d54(struct Ctx *a0, u32 a1, u32 a2, u32 a3);
extern int  FUN_800331b8(void);
extern void FUN_800551e0(void);
extern void FUN_80052bd0(u32 a0, u32 a1);
extern void FUN_80052c6c(u32 a0, u32 a1, u32 a2);

void FUN_80059530(struct Ctx *s)
{
    switch (s->mode) {
    case 0:
        s->f1e8.w = 0x02000300;
        s->mode = 1;
        *(s16 *)&s->f1e0 = -800;
        s->f1e2 = 0;
        s->f1e4 = 0;
        s->f26f |= 0x80;
        s->f25c |= 0x12;
        FUN_80077adc(0x04010001, s->f28);
        s->f0 &= ~4;

    case 1:
        if (!s->f1e8.b[2])
            s->mode = 2;
        FUN_80032b5c(s, 0);
        FUN_80089d54(s, s->f224, s->f228, 0x400);
        s->f1e0 += 150;
        if (s->f1ac & 1)
            s->mode = 5;
        break;
    case 2:
        s->f1e8.w = 0x03000300;
        s->mode = 3;
        FUN_80077adc(0x022a0001, s->f28);

    case 3:
        FUN_80032b5c(s, 0);
        s->mode += FUN_80089d54(s, s->f224, s->f228, 0x400);
        s->f1e0 += 15;
        if ((s16)s->f1e0 > 0)
            s->f1e0 = 0;
        break;
    case 4:
        FUN_800551e0();
        *(u32 *)&s->f4 = 0x01000000;
        s->f26f = 0;
        s->f25c &= 0xed;
        break;
    case 5:
        s->f1e8.w = 0x00000300;
        s->mode = 6;
        FUN_80077adc(0x02290001, s->f28);
        FUN_80077adc(0x04020001, s->f28);
        FUN_80052bd0(1, 0);
        FUN_80052c6c(5, 250, 0);

    case 6:
        s->mode += FUN_80089d54(s, s->f224, s->f228, 0x400);
        break;
    case 7:
        s->f1e8.w = 0x04000300;
        s->mode = 8;
        s->f1f4 = 30;
        if (s->f1f2 < 150)
            s->f1f4 = 60;
        if (s->f1f2 < 70)
            s->f1f4 += 50;
        if (s->f1f2 < 30)
            s->f1f4 += 50;
        if (s->f1f2 == 0)
            s->f1f4 += 100;

    case 8:
        FUN_80089d54(s, s->f224, s->f228, 0x10400);
        s->f1f4 -= FUN_800331b8() * 5 + 1;
        if ((s16)s->f1f4 < 0)
            s->mode = 9;
        break;
    case 9:
        s->f1e8.w = 0x01000300;
        s->mode = 10;
        s->f26f = 0;

    case 10:
        if (FUN_80089d54(s, s->f224, s->f228, 0x400) != 0) {
            s->mode = 11;
            s->f1e8.w = 0x06000300;
        }
        break;
    case 11:
        if (FUN_80089d54(s, s->f1a4, s->f218, 0x10400) != 0)
            s->mode = 4;
        break;
    }
}"""
P59530_TABLE = 0x800B9010
P59530_WORDS = 206
P59530_SYMS = [("FUN_80077adc", 0x80077ADC), ("FUN_80032b5c", 0x80032B5C), ("FUN_80089d54", 0x80089D54),
               ("FUN_800331b8", 0x800331B8), ("FUN_800551e0", 0x800551E0), ("FUN_80052bd0", 0x80052BD0),
               ("FUN_80052c6c", 0x80052C6C)]


def p59530_function():
    """Compile the twelve-arm state machine and compare its 206 words plus the 12-word jump table."""
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p59530.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(P59530_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    syms = "".join("%s = 0x%X;\n" % (n, a) for n, a in P59530_SYMS)
    ld.write_text("ENTRY(f_probe)\nSECTIONS {\n  . = 0x80059530;\n  .text : { *(.text) }\n"
                  "  . = 0x800B9010;\n  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n" + syms)
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    lo, n = 0x80059530, P59530_WORDS
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range(n)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    hunks = len([o for o in sm.get_opcodes() if o[0] != "equal"])
    tw = [image[P59530_TABLE - BASE + 4 * i:P59530_TABLE - BASE + 4 * i + 4] for i in range(12)]
    ro = text_of(elf, ".rodata")
    gw = [ro[4 * i:4 * i + 4] for i in range(12)]
    return {"image_instrs": n, "got_instrs": len(got), "same_offset": off, "same": same, "hunks": hunks,
            "extra": len(got) - n, "table_same": sum(1 for a, b in zip(tw, gw) if a == b)}



# The first target whose dispatch is on an **offset domain**: the index is `(cmd & 0xff) - 128`, not a raw byte, so
# cases are `0x80..0x85` and the table's 7th word is never read. 53 words, and the head does most of the work -- it
# clamps the third argument into `[0, 0x3fff]` before the switch. Four shape facts are pinned by it: a clamp written
# as a **ternary** reproduces `bltz … slti … beqzl` where an if/else-if gets the first branch inverted; a **truncation**
# `(u8)x` is not a mask `x & 0xff` (cc1 reuses a live `li v0,255` and emits `and rd,rs,v0`); two separate `slti`s mean
# **nested ifs** rather than a folded range test; and a switch phi landing in `a0` rather than `t0` is the signal that
# an incoming parameter is **still live to a later call** -- here param0 is the call's own first argument.
PACAE4_SOURCE = """typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

struct Snd {
    u8 pad0[0x4a];
    u8 f4a;
    u8 f4b;
};

extern void FUN_800ab7e0(u32 a0, u32 a1, u32 a2, u16 a3);

void FUN_800acae4(struct Snd *s, u32 cmd, s16 v)
{
    int c;
    u32 id;

    id = (u32)s;
    v = v < 0 ? 0 : (v >= 0x4000 ? 0x3fff : v);
    c = cmd;
    switch (cmd & 0xff) {
    case 0x80:
        c = 0x80;
        break;
    case 0x81:
        c = 0x82;
        break;
    case 0x82:
        c = 0xa0;
        break;
    case 0x83:
        c = 0xa1;
        break;
    case 0x84:
        c = 0x83;
        break;
    case 0x85:
        c = 0x84;
        break;
    }
    if ((c & 0xff) < 0xa2) {
        if ((c & 0xff) >= 0xa0)
            return;
    }
    if (s->f4a == 0xff)
        return;
    id = (u8)cmd;
    cmd = s->f4a;
    FUN_800ab7e0(id, cmd, s->f4b, v);
}"""
PACAE4_TABLE = 0x800BA890
PACAE4_WORDS = 53
PACAE4_SYMS = [("FUN_800ab7e0", 0x800AB7E0)]

P7E590_SOURCE = """typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx {
    u32 f0;
    u8 pad4;
    u8 f5;
    u8 f6;
    u8 f7;
    u8 f8;
    u8 pad9[0x2a - 0x9];
    u16 f2a;
    u32 f2c;
    u8 pad30[0x32 - 0x30];
    u16 f32;
    u16 f34;
    u16 f36;
    u16 f38;
    u8 pad3a[0x66 - 0x3a];
    u16 f66;
    u8 pad68[0x1a2 - 0x68];
    u8 f1a2;
    u8 pad1a3[0x1b4 - 0x1a3];
    u16 f1b4;
    u16 f1b6;
    u8 pad1b8[0x1e0 - 0x1b8];
    u16 f1e0;
    u8 pad1e2[0x1e8 - 0x1e2];
    union {
        u32 w;
        u8 b[4];
    } f1e8;
    u8 pad1ec[0x214 - 0x1ec];
    u32 f214;
    u8 pad218[0x21c - 0x218];
    u32 f21c;
    u32 f220;
    u8 pad224[0x22c - 0x224];
    u32 f22c;
    u32 f230;
    u8 pad234[0x25e - 0x234];
    u16 f25e;
    u8 pad260[0x26f - 0x260];
    u8 f26f;
    u8 pad270[0x2b0 - 0x270];
    u16 f2b0;
};

extern u8 D_800C76B0[];
extern u16 D_8010BA78[];
extern int FUN_80089d54(struct Ctx *s, u32 a1, u32 a2, u32 a3);
extern void FUN_80032b5c(struct Ctx *s, u32 a1);
extern int FUN_800331b8(void);
extern void FUN_800551e0(void);
extern void FUN_80077f30(u32 a0, u32 a1, struct Ctx *s);

void FUN_8007e590(struct Ctx *s)
{
    switch (s->f7) {
    case 0: {
        u16 t;
        u32 g;

        s->f7 = 1;
        s->f1e8.b[0] = 6;
        if (s->f6 & 2)
            s->f1e8.b[0] = 7;
        t = s->f2b0;
        g = s->f0;
        s->f1e8.b[2] = 7;
        s->f1e8.b[1] = 0;
        s->f1e8.w = 0x700;
        s->f1e0 = 50;
        *(u16 *)((u8 *)s + 0x66) = t;
        s->f0 = g | 4;
        }

    case 1:
        FUN_80089d54(s, s->f21c, s->f220, 0x200);
        if (*(u16 *)((u8 *)s + 0x66) & 0x200)
            *(u16 *)((u8 *)s + 0x66) += (*(u16 *)((u8 *)s + 0x66) >> 2) & 0xff;
        else
            *(u16 *)((u8 *)s + 0x66) -= (*(u16 *)((u8 *)s + 0x66) >> 2) & 0xff;
        if (*(u16 *)((u8 *)s + 0x66) & 0x3e0)
            return;
        *(u16 *)((u8 *)s + 0x66) &= 0xff00;
        s->f7 = 2;
        if (!(s->f6 & 2))
            return;
        s->f7 = 0;
        s->f5 = s->f5 + 1;
        return;
    case 2:
        s->f7 = 3;
        s->f1e8.b[0] = 6;
        s->f1e8.b[2] = 3;

    case 3: {
        u8 c;

        if (s->f1e8.b[1] == 17) {
            s->f26f = s->f26f | 0x80;
        }
        c = s->f8;
        if (c == 69 || c == 79) {
            if (s->f1e8.b[1] == 99) {
                s->f1e8.b[2] = 0;
                if (s->f8 < 16)
                    s->f1e0 = D_8010BA78[s->f8 + 16];
                else
                    s->f1e0 = D_8010BA78[s->f8 - 64];
                FUN_80032b5c(s, 0);
                s->f2c -= 1800;
                s->f25e -= 1800;
                s->f1a2 = s->f1a2 + 1;
                s->f34 = s->f1b4 = s->f2a;
                s->f38 = s->f1b6 = s->f32;
                s->f36 = *(u16 *)((u8 *)s + 0x2e);
            }
            if (s->f1e8.b[1] == 119) {
                s->f26f = s->f26f & 0x7f;
                s->f0 = s->f0 & ~4;
            }
        } else {
            if (s->f1e8.b[1] == 29) {
                if (c < 16)
                    s->f1e0 = D_8010BA78[s->f8 + 16];
                else
                    s->f1e0 = D_8010BA78[s->f8 - 64];
                FUN_80032b5c(s, 0);
                s->f2c -= 1800;
                s->f25e -= 1800;
                s->f1a2 = s->f1a2 + 1;
                s->f34 = s->f1b4 = s->f2a;
                s->f38 = s->f1b6 = s->f32;
                s->f36 = *(u16 *)((u8 *)s + 0x2e);
            }
            if (s->f1e8.b[1] == 49) {
                s->f26f = s->f26f & 0x7f;
                s->f0 = s->f0 & ~4;
            }
        }
        s->f7 = s->f7 + FUN_80089d54(s, s->f22c, s->f230, 0x400);
        break;
    }
    case 4: {
        u8 *dev = D_800C76B0;

        if (!((*(u32 *)(dev + 0x18000 + 0x1a5c) & 0x10000000)
              && s == (struct Ctx *)*(u32 *)(dev + 0x18000 + 0x1d3c)))
            s->f5 = (s->f5 == 22) ? 4 : 5;
        else
            s->f5 = 0;
        s->f6 = 0;
        s->f7 = 0;
        return;
    }
    }
    {
        u32 v = *(u32 *)s->f214;

        if (v & 0x4000) {
            u32 b = (v & 0x2000) >> 13;
            u8 *dev;

            FUN_80077f30(1, b * 3 + 4, s);
            dev = D_800C76B0;
            *(u16 *)(dev + 0x18000 + 0x1a7a) |= 4;
        }
    }
}"""
P7E590_TABLE = 0x800B9C78
P7E590_WORDS = 229
P7E590_CASE3 = 0x8007E6A8
P7E590_CASE3_WORDS = 113
P7E590_SYMS = [("D_800C76B0", 0x800C76B0), ("D_8010BA78", 0x8010BA78),
               ("FUN_80089d54", 0x80089D54), ("FUN_80032b5c", 0x80032B5C),
               ("FUN_80077f30", 0x80077F30)]

P701D8_SOURCE = """typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

struct T {
    u16  f0;
    u16  f2;
    u8   f4;
    u8   f5;
    u8   f6;
    u8   f7;
    u8   f8;
    u8 pad9[1];
    u8   f10;
    u8   f11;
    u8 pad12[4];
    u32  f16;
    u8 pad20[20];
    u32  f40;
    u32  f44;
    u32  f48;
    u8 pad52[48];
    s16  f100;
    s16  f102;
    s16  f104;
    u8 pad106[198];
    s16  f304;
    s16  f306;
    s16  f308;
    u16  f310;
    u16  f312;
    u16  f314;
    u8 pad316[102];
    u8   f418;
    u8 pad419[7];
    u16  f426;
    u8 pad428[8];
    s16  f436;
    s16  f438;
    u8 pad440[40];
    union { u8 b; s16 h; } f480;
    s16  f482;
    s16  f484;
    u8 pad486[4];
    u8   f490;
    u8 pad491[5];
    u16  f496;
    u8 pad498[108];
    s16  f606;
    s16  f608;
    s16  f610;
    u8 pad612[4];
    u16  f616;
    u8 pad618[5];
    u8   f623;
    s16  f624;
    s16  f626;
    s16  f628;
    s16  f630;
    u8 pad632[2];
    s16  f634;
    u8 pad636[56];
    u16  f692;
    u16  f694;
};

u32 FUN_800701d8(struct T *p, u32 idx)
{
    switch (idx) {
    case 1: return p->f0;
    case 0: return p->f2;
    case 2: return p->f4;
    case 3: return p->f5;
    case 4: return p->f6;
    case 5: return p->f7;
    case 6: return p->f8;
    case 7: return p->f426;
    case 8: return p->f10;
    case 9: return p->f11;
    case 10: return p->f16;
    case 11: return p->f40;
    case 12: return p->f44;
    case 13: return p->f48;
    case 14: return p->f100;
    case 15: return p->f102;
    case 16: return p->f104;
    case 17: return p->f418;
    case 18: return p->f496;
    case 19: return p->f606;
    case 20: return p->f608;
    case 21: return p->f610;
    case 22: return p->f616;
    case 23: return p->f624;
    case 24: return p->f626;
    case 25: return p->f628;
    case 26: return p->f630;
    case 27: return p->f480.b;
    case 28: return p->f480.h;
    case 29: return p->f482;
    case 30: return p->f484;
    case 31: return p->f490;
    case 32: return p->f304;
    case 33: return p->f308;
    case 34: return p->f306;
    case 35: return p->f310;
    case 36: return p->f314;
    case 37: return p->f312;
    case 38: return p->f634;
    case 39: return p->f436;
    case 40: return p->f438;
    case 41: return p->f692;
    case 42: return p->f694;
    case 43: return p->f623;
    }
}"""
P701D8_TABLE = 0x800B96C8
P701D8_WORDS = 141
P701D8_TABLE_WORDS = 44

P6FC5C_SOURCE = """typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed char    s8;
typedef short          s16;
typedef unsigned int   u32;

struct Ctx {
    u8  pad0[0x1c];
    u8 *f1c;
    u8  pad20[0x154 - 0x20];
    u8 *f154;
};

extern int FUN_800844cc(s16 v);

int FUN_8006fc5c(struct Ctx *ctx)
{
    u8 *p;
    u8 *rec;
    s8 a;
    s8 idx;
    u16 v;

    p = ctx->f1c;
    a = *(s8 *)(p + 2);
    idx = *(s8 *)(p + 3);
    v = *(u16 *)(p + 4);
    rec = (u8 *)(*(u32 *)(ctx->f154 + 0x234) + a * 376);
    switch (idx) {
    case 2:
        *(u16 *)(rec + 2) = v;
        break;
    case 3:
        *(u16 *)(rec + 0) = v;
        break;
    case 0:
        *(u16 *)(rec + 0x60) = v;
        *(u16 *)(rec + 0xcc) = FUN_800844cc((s16)v);
        break;
    case 1:
        *(u8 *)(rec + 0x62) = v;
        *(u8 *)(rec + 0xce) = v;
        break;
    case 4:
        *(u16 *)(rec + 0x58) = v;
        break;
    case 5:
        *(u16 *)(rec + 0x5a) = v;
        break;
    case 6:
        *(u16 *)(rec + 0x5c) = v;
        break;
    }
    ctx->f1c += 6;
    return 1;
}"""
P6FC5C_TABLE = 0x800B95D8
P6FC5C_WORDS = 53
P6FC5C_SYMS = [("FUN_800844cc", 0x800844CC)]

P6FF48_SOURCE = """typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FUN_8006ff48(u8 *p, u32 idx, u32 v)
{
    switch (idx) {
    case 1: *(u16 *)(p + 0) = v; break;
    case 0: *(u16 *)(p + 2) = v; break;
    case 2: *(u8 *)(p + 4) = v; break;
    case 3: *(u8 *)(p + 5) = v; break;
    case 4: *(u8 *)(p + 6) = v; break;
    case 5: *(u8 *)(p + 7) = v; break;
    case 6: *(u8 *)(p + 8) = v; break;
    case 7: *(u16 *)(p + 426) = v; break;
    case 8: *(u8 *)(p + 10) = v; break;
    case 9: *(u8 *)(p + 11) = v; break;
    case 10: *(u32 *)(p + 16) = v; break;
    case 11: *(u32 *)(p + 40) = v; break;
    case 12: *(u32 *)(p + 44) = v; break;
    case 13: *(u32 *)(p + 48) = v; break;
    case 14: *(u16 *)(p + 100) = v; break;
    case 15: *(u16 *)(p + 102) = v; break;
    case 16: *(u16 *)(p + 104) = v; break;
    case 17: *(u8 *)(p + 418) = v; break;
    case 18: *(u16 *)(p + 496) = v; break;
    case 19: *(u16 *)(p + 606) = v; break;
    case 20: *(u16 *)(p + 608) = v; break;
    case 21: *(u16 *)(p + 610) = v; break;
    case 22: *(u16 *)(p + 616) = v; break;
    case 23: *(u16 *)(p + 624) = v; break;
    case 24: *(u16 *)(p + 626) = v; break;
    case 25: *(u16 *)(p + 628) = v; break;
    case 26: *(u16 *)(p + 630) = v; break;
    case 27: *(u8 *)(p + 480) = v; break;
    case 28: *(u16 *)(p + 480) = v; break;
    case 29: *(u16 *)(p + 482) = v; break;
    case 30: *(u16 *)(p + 484) = v; break;
    case 31: *(u8 *)(p + 490) = v; break;
    case 32: *(u16 *)(p + 304) = v; break;
    case 33: *(u16 *)(p + 308) = v; break;
    case 34: *(u16 *)(p + 306) = v; break;
    case 35: *(u16 *)(p + 310) = v; break;
    case 36: *(u16 *)(p + 314) = v; break;
    case 37: *(u16 *)(p + 312) = v; break;
    case 38: *(u16 *)(p + 634) = v; break;
    case 39: *(u16 *)(p + 436) = v; break;
    case 40: *(u16 *)(p + 438) = v; break;
    case 41: *(u16 *)(p + 692) = v; break;
    case 42: *(u16 *)(p + 694) = v; break;
    case 43: *(u8 *)(p + 623) = v; break;
    }
}"""
P6FF48_TABLE = 0x800B95F8
P6FF48_WORDS = 98
P6FF48_TABLE_WORDS = 44

P6E68C_SOURCE = """typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

struct Ctx {
    u8  pad0[0x1c];
    u8 *f1c;
};

extern s16 D_800E8C78[];

int FUN_8006e68c(struct Ctx *ctx)
{
    u8 *p;
    u32 w;
    int v;
    int u;

    p = ctx->f1c;
    w = *(u16 *)(p + 2);
    v = *(s16 *)(p + 4);
    ctx->f1c += 6;
    u = *(s16 *)&D_800E8C78[w >> 8];
    switch (w & 0xff) {
    case 0: return u == v;
    case 1: return u > v;
    case 2: return u >= v;
    case 3: return u < v;
    case 4: return u <= v;
    case 5: return u != v;
    case 6: return (u & v) != 0;
    }
}"""
P6E68C_TABLE = 0x800B9540
P6E68C_WORDS = 41
P6E68C_SYMS = [("D_800E8C78", 0x800E8C78)]

P6E574_SOURCE = """typedef unsigned char  u8;
typedef unsigned int   u32;

struct Ctx {
    u8  pad0[0x1c];
    u8 *f1c;
};

extern u32 D_80115090[];

int FUN_8006e574(struct Ctx *ctx)
{
    u8 *p;
    int a;
    int b;
    int c;

    p = ctx->f1c;
    a = *(u8 *)(p + 1);
    b = *(u8 *)(p + 2);
    c = *(u8 *)(p + 3);
    ctx->f1c += 4;
    return ((*(u32 *)(D_80115090[a] + ((b >> 5) << 2)) & (0x80000000u >> (b & 31))) != 0) ^ (c == 0);
}"""
P6E574_TABLE = 0x800B9540
P6E574_WORDS = 23
P6E574_SYMS = [("D_80115090", 0x80115090)]

P704E0_SOURCE = """typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 D_80115120;

u8 *FUN_800704e0(u8 *p, u32 idx)
{
    switch (idx) {
    case 1:
        return p;
        break;
    case 0:
        return p + 2;
        break;
    case 2:
        D_80115120++;
        return p + 4;
        break;
    case 3:
        D_80115120++;
        return p + 5;
        break;
    case 4:
        D_80115120++;
        return p + 6;
        break;
    case 5:
        D_80115120++;
        return p + 7;
        break;
    case 6:
        D_80115120++;
        return p + 8;
        break;
    case 7:
        return p + 426;
        break;
    case 8:
        D_80115120++;
        return p + 10;
        break;
    case 9:
        D_80115120++;
        return p + 11;
        break;
    case 10:
        return p + 16;
        break;
    case 11:
        return p + 40;
        break;
    case 12:
        return p + 44;
        break;
    case 13:
        return p + 48;
        break;
    case 14:
        return p + 100;
        break;
    case 15:
        return p + 102;
        break;
    case 16:
        return p + 104;
        break;
    case 17:
        return p + 418;
        break;
    case 18:
        return p + 496;
        break;
    case 19:
        return p + 606;
        break;
    case 20:
        return p + 608;
        break;
    case 21:
        return p + 610;
        break;
    case 22:
        return p + 616;
        break;
    case 23:
        return p + 624;
        break;
    case 24:
        return p + 626;
        break;
    case 25:
        return p + 628;
        break;
    case 26:
        return p + 630;
        break;
    case 27:
        D_80115120++;
        return p + 480;
        break;
    case 28:
        return p + 480;
        break;
    case 29:
        return p + 482;
        break;
    case 30:
        return p + 484;
        break;
    case 31:
        D_80115120++;
        return p + 490;
        break;
    case 32:
        return p + 304;
        break;
    case 33:
        return p + 308;
        break;
    case 34:
        return p + 306;
        break;
    case 35:
        return p + 310;
        break;
    case 36:
        return p + 314;
        break;
    case 37:
        return p + 312;
        break;
    case 38:
        return p + 634;
        break;
    case 39:
        return p + 436;
        break;
    case 40:
        return p + 438;
        break;
    case 41:
        return p + 692;
        break;
    case 42:
        return p + 694;
        break;
    case 43:
        D_80115120++;
        return p + 623;
        break;
    }
}"""
P704E0_TABLE = 0x800B9778
P704E0_WORDS = 123
P704E0_SYMS = [("D_80115120", 0x80115120)]

OSMQ_SOURCE = """typedef int s32;
typedef unsigned int u32;
typedef struct OSThread_s OSThread;
typedef void *OSMesg;

typedef struct {
    OSThread *mtqueue;
    OSThread *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;

extern OSThread __osThreadTail;

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 count)
{
    mq->mtqueue = (OSThread *)&__osThreadTail;
    mq->fullqueue = (OSThread *)&__osThreadTail;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msg;
}"""
OSMQ_ADDR = 0x80006D30
OSMQ_WORDS = 9
OSMQ_SYMS = [("__osThreadTail", 0x80012940)]

# M297: the same function from a *later* libultra carries an `if (e == OS_EVENT_PRENMI)` block with `__osShutdown`,
# `__osPreNMI` and an `osSendMesg` call. This image has no such branch -- 24 words of disable-int / two stores /
# restore-int -- which is the operational form of the revision bracket: Nintendo's source minus that one block
# reproduces the image exactly.
OSEV_SOURCE = """typedef int s32;
typedef unsigned int u32;
typedef void *OSMesg;
typedef struct { void *mtqueue; void *fullqueue; s32 validCount; s32 first; s32 msgCount; OSMesg *msg; } OSMesgQueue;
typedef struct { OSMesgQueue *queue; OSMesg msg; } __OSEventState;

extern __OSEventState __osEventStateTab[];
extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32 mask);

void osSetEventMesg(u32 e, OSMesgQueue *mq, OSMesg msg)
{
    u32 prevInt = __osDisableInt();
    __OSEventState *msgs = &__osEventStateTab[e];

    msgs->queue = mq;
    msgs->msg = msg;

    __osRestoreInt(prevInt);
}"""
OSEV_ADDR = 0x8000CC90
OSEV_WORDS = 24
OSEV_SYMS = [("__osEventStateTab", 0x80017730), ("__osDisableInt", 0x800072E0),
             ("__osRestoreInt", 0x80007300)]


def pacae4_function():
    """Compile the clamp-then-dispatch predicate and compare its 53 words plus the 7-word jump table."""
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "pacae4.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(PACAE4_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    syms = "".join("%s = 0x%X;\n" % (n, a) for n, a in PACAE4_SYMS)
    ld.write_text("ENTRY(f_probe)\nSECTIONS {\n  . = 0x800acae4;\n  .text : { *(.text) }\n"
                  "  . = 0x800BA890;\n  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n" + syms)
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    lo, n = 0x800ACAE4, PACAE4_WORDS
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range(n)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    hunks = len([o for o in sm.get_opcodes() if o[0] != "equal"])
    tw = [image[PACAE4_TABLE - BASE + 4 * i:PACAE4_TABLE - BASE + 4 * i + 4] for i in range(7)]
    ro = text_of(elf, ".rodata")
    gw = [ro[4 * i:4 * i + 4] for i in range(7)]
    return {"image_instrs": n, "got_instrs": len(got), "same_offset": off, "same": same, "hunks": hunks,
            "extra": len(got) - n, "table_same": sum(1 for a, b in zip(tw, gw) if a == b)}


def p7e590_function():
    """Compile the 229-word seven-arm switch and compare it, its 113-word case-3 arm and its jump table.

    Deliberately a *partial* pin, like p8: 226 of 229 words are identical by offset and the three that are not
    are one register in case 4's value select (`li a0,5` where the image has `li v0,5`), which fifteen
    restructurings did not move (M278 section 4). The pin is `>=` so an improvement passes and a regression fails.
    """
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p7e590.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(P7E590_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    syms = "".join("%s = 0x%X;\n" % (n, a) for n, a in P7E590_SYMS)
    ld.write_text("ENTRY(FUN_8007e590)\nSECTIONS {\n  . = 0x8007e590;\n  .text : { *(.text) }\n"
                  "  . = 0x800B9C78;\n  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n" + syms)
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    lo, n = 0x8007E590, P7E590_WORDS
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range(n)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    hunks = len([o for o in sm.get_opcodes() if o[0] != "equal"])
    c3 = (P7E590_CASE3 - lo) // 4
    case3 = sum(1 for i in range(P7E590_CASE3_WORDS) if got[c3 + i] == want[c3 + i])
    tw = [image[P7E590_TABLE - BASE + 4 * i:P7E590_TABLE - BASE + 4 * i + 4] for i in range(6)]
    ro = text_of(elf, ".rodata")
    gw = [ro[4 * i:4 * i + 4] for i in range(6)]
    return {"image_instrs": n, "got_instrs": len(got), "same_offset": off, "same": same, "hunks": hunks,
            "extra": len(got) - n, "case3": case3,
            "table_same": sum(1 for a, b in zip(tw, gw) if a == b)}


def p701d8_function():
    """Compile the 44-arm accessor dispatcher and compare its 141 words plus the 44-word jump table.

    The arms are the discriminator this function exists to pin: the image has `load; jr ra; nop` per arm (3 words,
    44 x 3 + a 9-word head = 141), which only appears when the assembler is told `-g`. With the default
    `mips_optimize` of 2, gas swaps the branch with the preceding load (its "fill the branch delay slot" rule in
    tc-mips.c), the arms become 2 words and the object is 100 words. `-g` sets `mips_optimize = 0`, and across the
    whole 1.9 MB image not one of the 2 237 `jr ra` instructions has a load in its delay slot (M281).
    """
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p701d8.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(P701D8_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    ld.write_text("ENTRY(FUN_800701d8)\nSECTIONS {\n  . = 0x800701d8;\n  .text : { *(.text) }\n"
                  "  . = 0x800B96C8;\n  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n")
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    lo, n = 0x800701D8, P701D8_WORDS
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range(n)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    hunks = len([o for o in sm.get_opcodes() if o[0] != "equal"])
    tw = [image[P701D8_TABLE - BASE + 4 * i:P701D8_TABLE - BASE + 4 * i + 4]
          for i in range(P701D8_TABLE_WORDS)]
    ro = text_of(elf, ".rodata")
    gw = [ro[4 * i:4 * i + 4] for i in range(P701D8_TABLE_WORDS)]
    return {"image_instrs": n, "got_instrs": len(got), "same_offset": off, "same": same, "hunks": hunks,
            "extra": len(got) - n,
            "table_same": sum(1 for a, b in zip(tw, gw) if a == b)}


def p6fc5c_function():
    """Compile the 53-word seven-arm record writer and compare its words plus the 7-word jump table.

    Smallest member of the arm-shaped family the `-g` fix unlocked, and the first one whose arms are **stores**: the
    dispatch writes a halfword into `base + a * 376` at one of seven offsets, and the case bodies are emitted in the
    order the image shows (2, 3, 0, 1, 4, 5, 6), which is the source order -- the ascending source scores 41 of 53.
    """
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p6fc5c.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(P6FC5C_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    syms = "".join("%s = 0x%X;\n" % (n, a) for n, a in P6FC5C_SYMS)
    ld.write_text("ENTRY(FUN_8006fc5c)\nSECTIONS {\n  . = 0x8006fc5c;\n  .text : { *(.text) }\n"
                  "  . = 0x800B95D8;\n  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n" + syms)
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    lo, n = 0x8006FC5C, P6FC5C_WORDS
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range(n)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    hunks = len([o for o in sm.get_opcodes() if o[0] != "equal"])
    tw = [image[P6FC5C_TABLE - BASE + 4 * i:P6FC5C_TABLE - BASE + 4 * i + 4] for i in range(7)]
    ro = text_of(elf, ".rodata")
    gw = [ro[4 * i:4 * i + 4] for i in range(7)]
    return {"image_instrs": n, "got_instrs": len(got), "same_offset": off, "same": same, "hunks": hunks,
            "extra": len(got) - n,
            "table_same": sum(1 for a, b in zip(tw, gw) if a == b)}


def p6ff48_function():
    """Compile the 98-word 44-arm accessor *setter* and compare its words plus the 44-word jump table.

    The write half of the pair whose read half is `0x800701d8`: same offsets, same 44 indices, but each arm is a single
    store and is only 2 words -- `jr ra` with the store in its delay slot -- so the extent is 98 rather than 141. The
    arms are in the image's order 1, 0, 2, 3, ... (ascending scores 96 of 98), the same transposition the getter needs.
    """
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p6ff48.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(P6FF48_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    ld.write_text("ENTRY(FUN_8006ff48)\nSECTIONS {\n  . = 0x8006ff48;\n  .text : { *(.text) }\n"
                  "  . = 0x800B95F8;\n  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n")
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    lo, n = 0x8006FF48, P6FF48_WORDS
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range(n)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    hunks = len([o for o in sm.get_opcodes() if o[0] != "equal"])
    tw = [image[P6FF48_TABLE - BASE + 4 * i:P6FF48_TABLE - BASE + 4 * i + 4]
          for i in range(P6FF48_TABLE_WORDS)]
    ro = text_of(elf, ".rodata")
    gw = [ro[4 * i:4 * i + 4] for i in range(P6FF48_TABLE_WORDS)]
    return {"image_instrs": n, "got_instrs": len(got), "same_offset": off, "same": same, "hunks": hunks,
            "extra": len(got) - n,
            "table_same": sum(1 for a, b in zip(tw, gw) if a == b)}


def _arm_probe(source, lo, n, table, table_words, syms, tag):
    """Compile one arm-shaped function and compare its words plus its jump table.

    Shared by the two leaves found inside `0x8006e6b8`'s index gap (M285/M286); the corpus's other builders predate
    having two probes of the same shape to add at once.
    """
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / ("%s.c" % tag)
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(source)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    symtxt = "".join("%s = 0x%X;\n" % (k, v) for k, v in syms)
    ld.write_text("SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  . = %#x;\n  .rodata : ALIGN(8) "
                  "{ *(.rodata) }\n  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) "
                  "*(.bss) *(.sbss) *(.mdebug*) *(.gnu.attributes) *(.note.GNU-stack) }\n}\n" % (lo, table)
                  + symtxt)
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range(n)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    same = sum(i2 - i1 for tag_, i1, i2, _j1, _j2 in sm.get_opcodes() if tag_ == "equal")
    hunks = len([o for o in sm.get_opcodes() if o[0] != "equal"])
    tw = [image[table - BASE + 4 * i:table - BASE + 4 * i + 4] for i in range(table_words)]
    ro = text_of(elf, ".rodata")
    gw = [ro[4 * i:4 * i + 4] for i in range(table_words)]
    return {"image_instrs": n, "got_instrs": len(got), "same_offset": off, "same": same, "hunks": hunks,
            "extra": len(got) - n,
            "table_same": sum(1 for a, b in zip(tw, gw) if a == b)}


def p6e68c_function():
    return _arm_probe(P6E68C_SOURCE, 0x8006E68C, P6E68C_WORDS, P6E68C_TABLE, 7, P6E68C_SYMS, "p6e68c")


def p6e574_function():
    return _arm_probe(P6E574_SOURCE, 0x8006E574, P6E574_WORDS, P6E574_TABLE, 0, P6E574_SYMS, "p6e574")


def p704e0_function():
    """The 123-word 44-arm *address-of* dispatcher: each arm returns `p + offset`, ten also bump a u16 counter."""
    return _arm_probe(P704E0_SOURCE, 0x800704E0, P704E0_WORDS, P704E0_TABLE, 44, P704E0_SYMS, "p704e0")


def osmq_function():
    """`osCreateMesgQueue` from the *boot* image -- the first library function in the corpus (M296).

    Nintendo's libultra C, transcribed with our own typedefs, compiled by the same pipeline: 9 words that come out
    byte-identical, including the shared `&__osThreadTail` (0x80012940) and the store that lands in the `jr` delay slot.
    It is also the first case that does not read the stage-2 payload: `boot` is raw at ROM 0x1000 and loads at
    0x80000480.
    """
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists() or not ROM.exists():
        return None
    rom = ROM.read_bytes()
    image = rom[BOOT_ROM_OFF:BOOT_ROM_OFF + BOOT_SIZE]
    if len(image) != BOOT_SIZE:
        return None
    c = WORK / "osmq.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(OSMQ_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    syms = "".join("%s = 0x%X;\n" % (n, a) for n, a in OSMQ_SYMS)
    ld.write_text("SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n" % OSMQ_ADDR + syms)
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    lo, n = OSMQ_ADDR, OSMQ_WORDS
    want = [image[lo - BOOT_BASE + 4 * i:lo - BOOT_BASE + 4 * i + 4] for i in range(n)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    hunks = len([o for o in sm.get_opcodes() if o[0] != "equal"])
    return {"image_instrs": n, "got_instrs": len(got), "same_offset": off, "hunks": hunks,
            "extra": len(got) - n}


def osev_function():
    """`osSetEventMesg` from the *boot* image -- the pre-PRENMI revision (M297)."""
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists() or not ROM.exists():
        return None
    image = ROM.read_bytes()[BOOT_ROM_OFF:BOOT_ROM_OFF + BOOT_SIZE]
    if len(image) != BOOT_SIZE:
        return None
    c = WORK / "osev.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(OSEV_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                   capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    syms = "".join("%s = 0x%X;\n" % (n, a) for n, a in OSEV_SYMS)
    ld.write_text("SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n" % OSEV_ADDR + syms)
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    lo, n = OSEV_ADDR, OSEV_WORDS
    want = [image[lo - BOOT_BASE + 4 * i:lo - BOOT_BASE + 4 * i + 4] for i in range(n)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    off = sum(1 for a, b in zip(want, got) if a == b)
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    hunks = len([o for o in sm.get_opcodes() if o[0] != "equal"])
    return {"image_instrs": n, "got_instrs": len(got), "same_offset": off, "hunks": hunks,
            "extra": len(got) - n}


def check():
    if not IMAGE.exists():
        print("SKIP (needs assets/unpacked, i.e. the unpacked cartridge)")
        return 0
    image = IMAGE.read_bytes()
    for pid, src, addr, size, cls in PROBES:
        PROBES_BY_ID[pid] = (addr, src, size, cls)
    cases, rows = [], []

    for pid, src, addr, size, cls in PROBES:
        if addr is None:
            continue
        want = image[addr - BASE:addr - BASE + size]
        for profile, kind, directory, flags in PROFILES:
            work = WORK / ("%s_%s.o" % (pid, profile.replace(" ", "_").replace(".", "")))
            got, err = compile_probe(directory, flags, pid, work, kind, flags_addr=addr)
            if err:
                rows.append((pid, profile, "no-toolchain", err))
                continue
            if got[:size] == want:
                # an object may pad `.text` past the image's extent; the content is what is compared, and the
                # padding is reported rather than hidden
                rows.append((pid, profile, "MATCH",
                             "%d B%s" % (size, "" if len(got) == size else
                                         " (object pads to %d B)" % len(got))))
            else:
                first = next((i for i in range(0, min(len(want), len(got)), 4)
                              if want[i:i + 4] != got[i:i + 4]), None)
                if first is None:
                    rows.append((pid, profile, "length",
                                 "%d B emitted against %d B in the image" % (len(got), len(want))))
                else:
                    rows.append((pid, profile, "differ",
                                 "+0x%x want %s got %s" % (first, want[first:first + 4].hex(),
                                                           got[first:first + 4].hex())))

    have = [r for r in rows if r[2] != "no-toolchain"]
    cases.append((f"the corpus runs on {len({r[1] for r in have})} profile(s) "
                  f"({len(rows)} probe/profile pair(s))", bool(have)))

    # the census is the load-bearing case: it fingerprints the image without any C
    cen = census(image)
    cases.append((f"the cartridge writes a move as `addu` {cen['addu']} times and as `or` {cen['or']} times "
                  f"over {cen['ranges']} function ranges",
                  cen["addu"] > 1000 and cen["or"] == 0))

    # and IDO is refuted by that, not by a byte diff
    ido_or = None
    probe5 = PROBES_BY_ID["p5"]
    for profile, kind, directory, flags in PROFILES:
        work = WORK / ("p5_%s.o" % profile.replace(" ", "_").replace(".", ""))
        got, err = compile_probe(directory, flags, "p5", work, kind)
        if not err and len(got) >= 8:
            ido_or = struct.unpack_from(">I", got, 4)[0] & 0x3F
            break
    cases.append((f"IDO emits `or` (funct 0x25) for `int f(int a){{return a;}}` and the cartridge emits "
                  f"`addu` (0x21), so IDO does not match this target",
                  ido_or == 0x25))

    # which profile actually reproduces the image
    per_profile = {}
    for _pid, profile, verdict, _detail in rows:
        per_profile.setdefault(profile, [0, 0])
        per_profile[profile][0] += verdict == "MATCH"
        per_profile[profile][1] += 1
    gcc_best = max((v[0] for k, v in per_profile.items() if k.startswith("gcc")), default=0)
    g28 = max((v[0] for k, v in per_profile.items() if k.startswith("gcc2.8.1")), default=0)
    g27 = max((v[0] for k, v in per_profile.items() if k.startswith("gcc2.7.2")), default=0)
    ido_best = max((v[0] for k, v in per_profile.items() if k.startswith("ido")), default=0)
    cases.append((f"gcc 2.8.1 reproduces {g28} of 4 probes byte-for-byte (gcc 2.7.2: {gcc_best}, IDO: {ido_best})",
                  g28 >= 4))
    cases.append((f"gcc 2.7.2 reproduces {g27} of 4 (it cannot do p3) against IDO's {ido_best} "
                  f"({ {k: '%d/%d' % tuple(v) for k, v in sorted(per_profile.items())} })",
                  g27 == 3 and ido_best <= 1))

    # p3 links now, and its residue is the *assembler's* store expansion, not the compiler's: the image has
    # `lui v1` hoisted into the beq delay slot and sw through v1; we get the same three operations with the
    # address in the assembler temp and the slot filled by the addiu. Reported as numbers, not smoothed.
    p3 = {r[1]: r[2] for r in rows if r[0] == "p3"}
    cases.append((f"p3 is compared **after linking** and the version decides it: {p3} — 2.8.1 materialises the "
                  f"store's address into a general register and schedules it into the delay slot, 2.7.2 leaves it "
                  f"to the assembler's temp",
                  p3.get("gcc2.8.1 -O2") == "MATCH" and p3.get("gcc2.7.2 -O2") == "differ"))

    # 5.3 and 7.1 are not two hypotheses
    same = all(r53[2] == r71[2] and r53[3] == r71[3] for r53, r71 in
               zip([r for r in rows if r[1].startswith("ido-5.3")],
                   [r for r in rows if r[1].startswith("ido-7.1")]))
    cases.append(("IDO 5.3 and 7.1 emit identical code on every probe, so they are one hypothesis",
                  same))

    for spec in HEADS:
        pr = head_probe(spec)
        if not pr:
            cases.append((f"{spec['tag']} ({spec['index']}): not run", False))
            continue
        row = (f"{spec['tag']} bound {spec['bound']} shift {pr['got']['shift']} table 0x{spec['table']:08x} "
               f"idx {spec['index']}: bound+shift {'match' if pr['match'] else 'DIFFER'}, table "
               f"{'at the image address' if pr['table_match'] else 'at +%d (object .rodata pad)' % pr['table_pad']}")
        cases.append((row, pr["match"]))

    p6f = p6_function()
    permf = permuter_rescore()
    permb = permuter_rescore_boot()
    p7res = p7e590_residue()
    p7f = p7_function()
    p8f = p8_function()
    p9f = p9_function()
    p167f = p59868_function()
    p59530f = p59530_function()
    pacae4f = pacae4_function()
    p7e590f = p7e590_function()
    p701d8f = p701d8_function()
    p6fc5cf = p6fc5c_function()
    p6ff48f = p6ff48_function()
    p6e68cf = p6e68c_function()
    p6e574f = p6e574_function()
    p704e0f = p704e0_function()
    osmqf = osmq_function()
    osev_f = osev_function()
    fpf = fp_pool_check()
    cases.append((f"p6's whole function, content-aligned: {p6f['same']} of {p6f['image_instrs']} instructions "
                  f"identical, {p6f['hunks']} difference hunk(s), {p6f['extra']} extra instruction(s), "
                  f"first at {p6f['first']}" if p6f else "p6 whole function: not run",
                  bool(p6f) and p6f["same_offset"] >= 98 and p6f["same"] >= 98))

    cases.append((f"the divide-then-increment order the arms need is what gcc emits: {p6f['divu']} `divu` sites "
                  f"in the compiled body, and each is followed by a reload"
                  if p6f else "p6 whole function: not run",
                  bool(p6f) and p6f["divu"] == 4))

    cases.append((f"p6 is BYTE-EXACT over the image's {p6f['image_instrs']} words: "
                  f"{p6f['same_offset']} identical by offset, and the only difference is "
                  f"{p6f['extra']} word(s) of trailing .text alignment padding past the image's extent "
                  f"-- the arm-4 statement order was the last thing wrong" if p6f else "p6 exactness: not run",
                  bool(p6f) and p6f["same_offset"] == p6f["image_instrs"]))

    _p7tail = (", first residue at " + p7f["first"]) if p7f and p7f["first"] else ", nothing left to explain"
    cases.append((f"p7's whole function, recovered: {p7f['same_offset']} of {p7f['image_instrs']} words "
                  f"identical by offset and {p7f['same']} aligned by content ({p7f['hunks']} hunk(s)"
                  f"{_p7tail})" if p7f else "p7 whole function: not run",
                  bool(p7f) and p7f["same_offset"] == 84 and p7f["hunks"] == 0))

    cases.append((f"p7 is the first whole function reproduced BYTE-FOR-BYTE from reconstructed C: "
                  f"{p7f['same_offset']} of {p7f['image_instrs']} words identical by offset and "
                  f"{p7f['hunks']} hunks -- which needs `-mcpu=r4300` on cc1, because the cpu selects the load "
                  f"READY-DELAY (2 on r4300, 3 on the default) and with it the scheduler costs"
                  if p7f else "p7 exactness: not run",
                  bool(p7f) and p7f["same_offset"] == p7f["image_instrs"] and p7f["hunks"] == 0))

    cases.append((f"p7's case 0 is byte-exact ({p7f['arm0']} of 14 words) once the device window is a "
                  f"struct member: a mixed struct/non-struct pair is a dependence gcc 2.8.1 drops, so the "
                  f"scheduler hoists the load past the two stores"
                  if p7f else "p7 case 0: not run",
                  bool(p7f) and p7f["arm0"] == 14))

    cases.append((f"p7's jump table lands on the image's own 0x800b8f78 and matches {p7f['table_same']} of 8 words "
                  f"only because the linker places it, not the source" if p7f else "p7 table: not run",
                  bool(p7f) and p7f["table_same"] == 8))

    cases.append((f"p8's whole function, recovered: {p8f['same_offset']} of {p8f['image_instrs']} words identical "
                  f"by offset and {p8f['same']} aligned by content ({p8f['hunks']} hunk(s)); its 27-word first arm "
                  f"is {p8f['arm0']} of 27 -- byte-exact, with the pool's per-use double and its unsplit float address"
                  if p8f else "p8 whole function: not run",
                  bool(p8f) and p8f["same_offset"] == p8f["image_instrs"] and p8f["arm0"] == 27))

    cases.append((f"p8's jump table matches all 6 arm addresses by content, {p8f['table_at']} words into "
                  f".rodata" if p8f else "p8 table: not run",
                  bool(p8f) and p8f["table_words"] == 6))

    cases.append((f"float constants go to the pool, as the image does, and carry their real bits: "
                  f"4.0f emits {fpf['small']} and 3.0e38f emits {fpf['big']} against IEEE "
                  f"0x40800000/0x7f61b1e6, with no `li.s` in either ({not fpf['small_inline']} and "
                  f"{not fpf['big_inline']}) -- and the image itself has {fpf['image_li_s']} `mtc1 $at` "
                  f"in its whole 1.9 MB, so it never used the immediate path either"
                  if fpf else "fp pool: not run",
                  bool(fpf) and fpf["small"] == "0x40800000" and fpf["big"] == "0x7f61b1e6"
                  and not fpf["small_inline"] and not fpf["big_inline"] and fpf["image_li_s"] == 0))

    cases.append((f"p9 is BYTE-EXACT over the image's {p9f['image_instrs']} words ({p9f['same_offset']} "
                  f"identical by offset, {p9f['same']} by content, first difference at {p9f['first']}) -- a "
                  f"predicate dispatcher, and the third whole function reproduced from reconstructed C"
                  if p9f else "p9 whole function: not run",
                  bool(p9f) and p9f["same_offset"] == p9f["image_instrs"]))

    cases.append((f"p9's jump table matches {p9f['table_same']} of 8 words at the image's own 0x800b96a8 -- the "
                  f"eighth entry is zero and never read, because the bound check sends the out-of-range index to "
                  f"the epilogue" if p9f else "p9 table: not run",
                  bool(p9f) and p9f["table_same"] == 8))

    cases.append((f"the {p167f['image_instrs']}-word state machine at 0x80059868 is BYTE-EXACT: "
                  f"{p167f['same_offset']} identical by offset and {p167f['same']} by content, all "
                  f"{p167f['arms_exact']} arm entries identical, the only difference being "
                  f"{p167f['extra']} word of trailing .text padding -- and it needs union members, a "
                  f"u16 field with an (s16) cast in the predicates, and nested ifs rather than &&"
                  if p167f else "0x80059868: not run",
                  bool(p167f) and p167f["same_offset"] == p167f["image_instrs"]))

    cases.append((f"its jump table matches {p167f['table_same']} of 8 words at the image's own "
                  f"0x800b9040, and .rodata holds nothing else -- the function has no pool literal at all"
                  if p167f else "0x80059868 table: not run",
                  bool(p167f) and p167f["table_same"] == 8))

    cases.append((f"the {p59530f['image_instrs']}-word twelve-arm state machine at 0x80059530 is "
                  f"BYTE-EXACT: {p59530f['same_offset']} identical by offset and {p59530f['same']} by "
                  f"content, the widest dispatch recovered -- twelve arms and a shared tail, and it needs "
                  f"a signed store into a u16 field and opposite clamp directions two cases apart"
                  if p59530f else "0x80059530: not run",
                  bool(p59530f) and p59530f["same_offset"] == p59530f["image_instrs"]))

    cases.append((f"its jump table matches {p59530f['table_same']} of 12 words at the image's own "
                  f"0x800b9010" if p59530f else "0x80059530 table: not run",
                  bool(p59530f) and p59530f["table_same"] == 12))

    cases.append((f"the {pacae4f['image_instrs']}-word clamp-then-dispatch predicate at 0x800acae4 is "
                  f"BYTE-EXACT: {pacae4f['same_offset']} identical by offset and {pacae4f['same']} by "
                  f"content -- the first target that dispatches on an offset domain, `(cmd & 0xff) - 128`"
                  if pacae4f else "0x800acae4: not run",
                  bool(pacae4f) and pacae4f["same_offset"] == pacae4f["image_instrs"]))

    cases.append((f"its jump table matches {pacae4f['table_same']} of 7 words at the image's own "
                  f"0x800ba890" if pacae4f else "0x800acae4 table: not run",
                  bool(pacae4f) and pacae4f["table_same"] == 7))

    cases.append((f"`0x8007e590`'s last three words are decoded, not described: {p7res['same_offset']} of "
                  f"{p7res['image_instrs']} match and the differing words {p7res['diffs']} are `li`,`li`,`sb` "
                  f"with the same immediates and base register, differing ONLY in the destination "
                  f"({p7res['residue_regs']} = image $2 against ours $4) -- a pure allocator tie-break (M304)"
                  if p7res else "0x8007e590 residue: not run",
                  bool(p7res) and p7res["same_offset"] == 226 and p7res["shape_only"]))

    cases.append((f"and the tie-break is not shape-reachable: {p7res['spellings_identical']} of "
                  f"{p7res['spellings_tested']} alternative spellings of the same select compile to "
                  f"byte-identical `.text`, so no rewording of the statement moves the register (M304)"
                  if p7res else "0x8007e590 spellings: not run",
                  bool(p7res) and p7res["spellings_identical"] == p7res["spellings_tested"] == 3))

    cases.append((f"the {p7e590f['image_instrs']}-word seven-arm switch at 0x8007e590 is recovered to "
                  f"{p7e590f['same_offset']} words identical by offset and {p7e590f['same']} by content "
                  f"({p7e590f['hunks']} hunk(s)): its 113-word case-3 arm is {p7e590f['case3']} of 113, the "
                  f"device-update tail is exact, and the three words left are one register in case 4's select"
                  if p7e590f else "0x8007e590: not run",
                  bool(p7e590f) and p7e590f["same_offset"] >= 226 and p7e590f["case3"] == 113))

    cases.append((f"its jump table matches {p7e590f['table_same']} of 6 words at the image's own 0x800b9c78, "
                  f"the sixth zero because the bound is 5 and the out-of-range arm is the code after the "
                  f"switch" if p7e590f else "0x8007e590 table: not run",
                  bool(p7e590f) and p7e590f["table_same"] == 6))

    cases.append((f"the {p701d8f['image_instrs']}-word 44-arm accessor dispatcher at 0x800701d8 is BYTE-EXACT: "
                  f"{p701d8f['same_offset']} identical by offset and {p701d8f['same']} by content -- one load and "
                  f"a `jr ra` per arm, and its arms are the reason the assembler needs `-g`"
                  if p701d8f else "0x800701d8: not run",
                  bool(p701d8f) and p701d8f["same_offset"] == p701d8f["image_instrs"]))

    cases.append((f"its jump table matches {p701d8f['table_same']} of 44 words at the image's own 0x800b96c8, "
                  f"every arm 3 words because gas's delay-slot swap is off under `-g`"
                  if p701d8f else "0x800701d8 table: not run",
                  bool(p701d8f) and p701d8f["table_same"] == 44))

    cases.append((f"the {p6fc5cf['image_instrs']}-word seven-arm record writer at 0x8006fc5c is BYTE-EXACT: "
                  f"{p6fc5cf['same_offset']} identical by offset and {p6fc5cf['same']} by content -- smallest member "
                  f"of the arm-shaped family, a store into `base + a * 376` at one of seven offsets"
                  if p6fc5cf else "0x8006fc5c: not run",
                  bool(p6fc5cf) and p6fc5cf["same_offset"] == p6fc5cf["image_instrs"]))

    cases.append((f"its jump table matches {p6fc5cf['table_same']} of 7 words at the image's own 0x800b95d8, and the "
                  f"case bodies come out in the image's order 2, 3, 0, 1, 4, 5, 6 rather than ascending"
                  if p6fc5cf else "0x8006fc5c table: not run",
                  bool(p6fc5cf) and p6fc5cf["table_same"] == 7))

    cases.append((f"the {p6ff48f['image_instrs']}-word 44-arm accessor setter at 0x8006ff48 is BYTE-EXACT: "
                  f"{p6ff48f['same_offset']} identical by offset and {p6ff48f['same']} by content -- the write half "
                  f"of the pair whose read half is 0x800701d8, same offsets, one store per arm"
                  if p6ff48f else "0x8006ff48: not run",
                  bool(p6ff48f) and p6ff48f["same_offset"] == p6ff48f["image_instrs"]))

    cases.append((f"its jump table matches {p6ff48f['table_same']} of 44 words at the image's own 0x800b95f8, with "
                  f"the arms 2 words each because the store rides in the `jr ra` slot"
                  if p6ff48f else "0x8006ff48 table: not run",
                  bool(p6ff48f) and p6ff48f["table_same"] == 44))

    cases.append((f"the {p6e68cf['image_instrs']}-word seven-operator predicate dispatcher at 0x8006e68c is "
                  f"BYTE-EXACT: {p6e68cf['same_offset']} identical by offset and {p6e68cf['same']} by content -- the "
                  f"leaf that 0x8006e6b8's dispatch actually belongs to, same operator set as 0x80070120"
                  if p6e68cf else "0x8006e68c: not run",
                  bool(p6e68cf) and p6e68cf["same_offset"] == p6e68cf["image_instrs"]))

    cases.append((f"its jump table matches {p6e68cf['table_same']} of 7 words at 0x800b9540, and the table it reads "
                  f"from is the external 0x800e8c78 indexed by `w >> 8`"
                  if p6e68cf else "0x8006e68c table: not run",
                  bool(p6e68cf) and p6e68cf["table_same"] == 7))

    cases.append((f"the {p6e574f['image_instrs']}-word bit-test leaf at 0x8006e574 is BYTE-EXACT: "
                  f"{p6e574f['same_offset']} identical by offset and {p6e574f['same']} by content -- it needed the "
                  f"table pointer as the first addend and the offset written as a shift, not a multiply"
                  if p6e574f else "0x8006e574: not run",
                  bool(p6e574f) and p6e574f["same_offset"] == p6e574f["image_instrs"]))

    cases.append((f"the {p704e0f['image_instrs']}-word 44-arm address-of dispatcher at 0x800704e0 is BYTE-EXACT: "
                  f"{p704e0f['same_offset']} identical by offset and {p704e0f['same']} by content -- the third member "
                  f"of the accessor family, returning `p + offset` and bumping a u16 counter in ten of its arms"
                  if p704e0f else "0x800704e0: not run",
                  bool(p704e0f) and p704e0f["same_offset"] == p704e0f["image_instrs"]))

    cases.append((f"its jump table matches {p704e0f['table_same']} of 44 words at the image's own 0x800b9778, with the "
                  f"counter arms sharing one increment tail through a `j`"
                  if p704e0f else "0x800704e0 table: not run",
                  bool(p704e0f) and p704e0f["table_same"] == 44))

    cases.append((f"`osCreateMesgQueue` in the *boot* image at 0x80006d30 is BYTE-EXACT: "
                  f"{osmqf['same_offset']} of {osmqf['image_instrs']} words -- the first library function in the "
                  f"corpus, the first case that does not read the stage-2 payload, and the proof that RE2's runtime "
                  f"was rebuilt from libultra source with this compiler (M296)"
                  if osmqf else "osCreateMesgQueue: not run",
                  bool(osmqf) and osmqf["same_offset"] == osmqf["image_instrs"]))

    cases.append((f"`osSetEventMesg` at 0x8000cc90 is BYTE-EXACT: {osev_f['same_offset']} of "
                  f"{osev_f['image_instrs']} words -- and it is the revision marker: Nintendo's later source has an "
                  f"`OS_EVENT_PRENMI` block this image does not, and removing exactly that block reproduces it (M297)"
                  if osev_f else "osSetEventMesg: not run",
                  bool(osev_f) and osev_f["same_offset"] == osev_f["image_instrs"]))

    cases.append((f"the {len(CLASSES_WITHOUT_A_PROBE)} remaining uncovered classes are refused with a reason, "
                  f"not silently dropped ({', '.join(sorted(CLASSES_WITHOUT_A_PROBE))})",
                  len(CLASSES_WITHOUT_A_PROBE) == 3
                  and all(len(v) > 40 for v in CLASSES_WITHOUT_A_PROBE.values())))

    s = permf["scores"] if permf else {}
    cases.append((f"the committed permuter harness (`fixtures/permuter/p6/`) re-scores to its recorded verdict: "
                  f"base {s.get('base')} of {permf['image_words'] if permf else 98}, the two candidates from the "
                  f"proxy-objective run at {s.get('candidate-1780-1')} and {s.get('candidate-1980-26')}"
                  if permf else "permuter fixtures: not run",
                  bool(permf) and s.get("base") == 86
                  and s.get("candidate-1780-1") == 94 and s.get("candidate-1980-26") == 94))

    cases.append((f"the permuter's own search, pointed at the image rather than the proxy, reaches BYTE-EXACTNESS: "
                  f"`candidate-image-310-1.c` scores {s.get('candidate-image-310-1')} of "
                  f"{permf['image_words'] if permf else 98} -- and it is a DIFFERENT shape from the hand "
                  f"reconstruction (a `new_var` temporary in case 4 instead of two transposed statements), so the "
                  f"94/98 plateau was the objective, not the tool (M302)"
                  if permf else "permuter image run: not run",
                  bool(permf) and s.get("candidate-image-310-1") == permf["image_words"]))

    cases.append((f"the permuter's *draft* objective is a proxy, not the function: `target-draft.o` holds "
                  f"{permf['draft_words']} instructions against the image's {permf['image_words']} and carries "
                  f"unresolved relocations -- which is why the word metric, not the permuter's score, is the "
                  f"verdict (M300)" if permf else "permuter draft target: not run",
                  bool(permf) and permf["draft_words"] == 116 and permf["image_words"] == 98))

    cases.append((f"the permuter's `osCreateThread` residue reproduces: the M298 draft scores "
                  f"{permb['base']['off']} of {permb['image_words']} words and compiles to "
                  f"{permb['base']['got']} instructions -- the boot-image objective is buildable too "
                  f"(`make_target.py --image-offset 0x1000`) (M303)"
                  if permb else "osCreateThread permuter fixture: not run",
                  bool(permb) and permb["base"]["off"] == 23 and permb["base"]["got"] == 52))

    cases.append((f"and nothing in its 52-candidate pool improves it: the best is {permb['candidate']['off']} of "
                  f"{permb['image_words']} but emits {permb['candidate']['got']} instructions against the image's "
                  f"{permb['image_words']}, so it overshoots the function -- a SHAPE search does not move an "
                  f"ALLOCATION residue, which is the boundary this experiment establishes (M303)"
                  if permb else "osCreateThread pool: not run",
                  bool(permb) and permb["candidate"]["off"] == 26
                  and permb["candidate"]["got"] > permb["image_words"]))

    cases.append((f"`make_target.py` builds the permuter's objective from the image itself: `target.o` is "
                  f"{permf['image_target_words']} words and byte-identical to 0x8004fd1c, with no relocations "
                  f"-- so the objective is the cartridge, and its one asymmetry (a resolved pool reference "
                  f"against a candidate's `R_MIPS_HI16`) is stated rather than hidden (M302)"
                  if permf and permf["image_target_words"] else "image target: not built (run make_target.py)",
                  bool(permf) and permf["image_target_words"] == 98 and permf["image_target_exact"]))

    bad = sum(1 for _l, ok in cases if not ok)
    print("%-4s %-13s %-10s %s" % ("prb", "profile", "verdict", "detail"))
    for pid, profile, verdict, detail in rows:
        print("%-4s %-13s %-10s %s" % (pid, profile, verdict, detail))
    print()
    for label, ok in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d compile-probe case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--list", action="store_true")
    args = ap.parse_args()
    if args.list:
        for pid, src, addr, size, cls in PROBES:
            print("%-3s %-46s %s" % (pid, cls, ("0x%08x %d B" % (addr, size)) if addr else "-"))
        print("\nclasses with no probe, and why:")
        for cls, why in CLASSES_WITHOUT_A_PROBE.items():
            print("   %-22s %s" % (cls, why[:96]))
        return 0
    if not args.check:
        ap.error("one of --check, --list is required")
    return check()


if __name__ == "__main__":
    raise SystemExit(main())
