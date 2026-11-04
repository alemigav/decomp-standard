"""Decode the RSP program the audio task hands the RCP, and say exactly what that buys.

`FUN_800a2e40` fills a task block at `0x80143c60` whose +0x10/+0x14 pair names `0x800b2700` and `0x1000`
(both folded out of `lui`/`addiu` pairs: no word of stage-2 contains the literal `0x800b2700`). The 4 096
bytes there are 1 024 words, and they are **not all program**: the project's own corpus declares a CPU
function at `0x800b3640`, 0xC0 bytes before the window ends, so the RSP program is the first 976 words and
the rest is the head of `FUN_800b3640` — the stride-0x1228 voice walk from M222. The declared size is IMEM's
capacity, not the code's length, and the overrun is recorded rather than corrected.

**What this decoder claims.** Four things, and nothing else:

  * **The word grid and the address rule.** An RSP program is 32-bit words in 4 KB of IMEM, so the program
    counter is 12 bits (Programming Manual p44: "The IMEM and DMEM are both 4 KB"). A `jal`/`j` therefore
    carries an absolute **IMEM offset** — `(instr_index << 2) & 0xFFF` — and is *not* PC-relative, while a
    branch is `PC + 4 + (offset << 2)`, also inside IMEM. This is measured: all 49 jump fields in the program
    have raw `instr_index << 2` inside one 4 KB page (`0x0400112c`-`0x04001eb4`), so the page bits carry no
    target information; unmasked, every one of them lies outside a 4 KB IMEM.
  * **The scalar subset's mnemonics**, as the *family* the manual names and nothing more: p44 says "The SU
    implements a subset of the R4000 instruction set" and p47 names the R4000 manual as that family's authority.
    Every scalar mnemonic is labelled `family` for that reason, with the page that delegates to it.
  * **DMEM-only data addressing**, from p139 ("The RSP software can only access DMEM") and p44 (4 KB of it):
    the 16-bit displacement of every `lw`/`sw`/`lhu`/… is a DMEM offset, and all 106 of them in this program
    land inside DMEM (max 0xd5c). `lwc2`/`swc2` move 128-bit rows between DMEM and the vector unit (p44: "The
    VU has eight 16-bit elements"); their immediate is a *different* field and is excluded from those counts.
  * **Control flow and boundaries**: entry at IMEM 0, the 19 `jal` targets as the other function roots, `jr`
    as returns, and every one of the 976 words either inside a function body, inside a listed gap, or
    accounted for as CPU code.

**What it refuses.** The local manual has no RSP encoding table — it settles the RSP's
*structure* (4 KB IMEM/DMEM p44, the SU's family p44/p47, DMEM-only data p139, physical addressing and the
16-entry segment table p47, the boot/task two-stage load p137) but tabulates **no opcode, no function code
and no COP2 encoding**. So:

  * the **vector unit's 254 words are named** — 252 of them, from the N64brew Wiki's VU tables (revision
    5539, CC BY-SA-4.0), each entry labelled `cited-external` because the table is not this repository's own
    document. M223 left all 254 unnamed on the grounds that naming them meant importing a table; M224
    narrowed that policy rather than the claim — an external table may be **used as a cited source**, which
    is what `THIRD_PARTY.md` §4b records, and 2 words are still refused because the table has **no row** for
    `funct 0x11`. Those two are the whole of `unreadable` now. The cited tables have two defects of their
    own, both recorded: the transpose group states an opcode that collides with the scalar group's, and the
    computational table omits `0x11` — the source documents what it documents, and this decoder reports the
    gaps instead of filling them;
  * **COP0 register numbers are unnamed here** — the map is external (see `rsp_iface.py`, which cites it),
    and this tool reports the number raw. `mfc0 a1,<reg 7>` is decoded as a COP0 move with the number raw;
    the five repeated write-three-then-poll-a-fourth blocks are described by *shape* and no direction is
    asserted;
  * **no DMEM offset, no command opcode and no mixer behaviour is named.** The program's DMEM layout is its
    own; nothing on the CPU side mirrors it, which is why the same facts appear under `rsp_only`. A decoded
    RSP program is not an understood mixer.

The task block is re-derived, not quoted: every field is folded out of the instruction that stores it and
`--check` re-runs the fold, including `lui v0,0x800b` + `addiu v0,v0,0x2700` = 0x800b2700 and
`subu` of two folded halves = 0xd0.

Usage:
  ./rsp_decode.py --write     # regenerate manifests/rsp_ucode.json from the image
  ./rsp_decode.py --check     # validate the committed artefact against a fresh derivation
  ./rsp_decode.py --disasm    # print the listing this decoder claims (all 1 024 words)
"""
import argparse
import hashlib
import json
import math
import re
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

IMAGE = ROOT / "assets" / "unpacked" / "00000_0014420_1172240.bin"
OUT = Path("manifests") / "rsp_ucode.json"

STAGE2_BASE = 0x80018A80          # the stage-2 member loads here (checkpoint/memory_regions.json)
TASK_BLOCK = 0x80143C60           # the audio task block FUN_800a2e40 fills
UCODE_VA = 0x800B2700             # task+0x10, the field this whole file is about
UCODE_SIZE = 0x1000               # task+0x14
TASK_WRITER = 0x800A2E40          # FUN_800a2e40: the only function that writes the block

SCHEMA = "rsp-ucode/1"
CORPUS = "src/stage2"
CORPUS_ADDR = re.compile(r"^ \* address (0x[0-9a-f]+)", re.M)
MANUAL = "docs/Nintendo_64_Programming_Manual_NU6-06-0030-001G_HQ.pdf"
MANUAL_PAGES = 534

# Every citation is a page of the local manual plus the sentence that page actually contains. The sentences
# were read out of the PDF's own text layer (PDFKit, 534 pp — `swiftc -O` a 20-line PDFDocument.string dump);
# none is paraphrased, and `--check` refuses a citation whose page is outside the manual or whose key is used
# without being defined here.
CITES = {
    "imem_dmem_4k": (44, "The IMEM and DMEM are\nboth 4 KB."),
    "su_r4000": (44, "The SU implements a\nsubset of the R4000 instruction set."),
    "vu_elements": (44, "The VU\nhas eight 16-bit elements."),
    "rsp_physical": (47, "The RSP hardware uses physical addresses."),
    "rsp_segments": (47, "Bits 24 through 27 of the segmented address are used to index into a 16-entry table"),
    "r4000_authority": (47, "see the MIPS Microprocessor R4000 User\u2019s Manual"),
    "task_pc0": (137, "the R4300 sets the RSP PC to 0."),
    "task_boot_ucode": (137, "the boot microcode takes over, loading the task microcode\n(and data) specified in the task list, and jumping to the beginning of the task."),
    "dmem_only": (139, "The RSP software can only access DMEM."),
    "dma_64bit": (139, "All data must first be transferred\ninto DMEM using DMA operations, which must be 64-bit aligned."),
}

# The rule the manifest states for every branch and jump the decoder follows.
ADDRESS_RULE = ("jal and j carry an absolute IMEM offset, not a PC-relative one: the RSP program counter is "
                "12 bits because IMEM is 4 KB (p44), so the target is (instr_index << 2) & 0xFFF. Measured, not "
                "assumed: all 49 jump fields in the program have raw instr_index<<2 inside one 4 KB page "
                "(0x0400112c-0x04001eb4), so the page bits are constant and carry no target information; "
                "unmasked, every one of the 49 lies outside a 4 KB IMEM. Branches are the opposite: PC + 4 + (offset<<2), "
                "also truncated to IMEM.")

FOLD_RULE = ("A stage-2 address is folded from the instructions that write the register before the store: "
             "`lui rt,imm16` sets rt = imm16 << 16, `addiu rt,rt,imm16` / `ori rt,rt,imm16` adds the low half, and "
             "`subu` folds when both halves are known. The fold records the instructions it used and --check "
             "re-derives it; no word of stage-2 contains the literal 0x800b2700 (0 occurrences), so the fold is "
             "the only evidence for the pointer.")

# Register names are the family's (p44/p47 name the R4000); the RSP has no names of its own in any local
# document, and r0 reads as zero everywhere.
REG = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
       "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
       "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]

# Family label: the mnemonic comes from the R4000/MIPS III table that p44 ("a subset of the R4000 instruction
# set") and p47 ("see the MIPS Microprocessor R4000 User's Manual") name for the SU. It is *not* a citation of
# an encoding this project holds, and the manifest says so per entry.
FAMILY = "family"

# --- scalar encodings -----------------------------------------------------------------------------------
# (mnemonic, form). Form decides the operand rendering. `family` entries are the SU's R4000 subset.
SPECIAL = {
    0x00: ("sll", "shift"),
    0x02: ("srl", "shift"),
    0x03: ("sra", "shift"),
    0x06: ("srlv", "R"),
    0x08: ("jr", "jr"),
    0x0D: ("break", "break"),
    0x21: ("addu", "R"),
    0x23: ("subu", "R"),
    0x24: ("and", "R"),
    0x25: ("or", "R"),
    0x2A: ("slt", "R"),
    0x2B: ("sltu", "R"),
}
REGIMM = {0x00: "bltz", 0x01: "bgez", 0x10: "bltzal", 0x11: "bgezal"}

# opcode -> (mnemonic, form, cite)
OPCODES = {
    0x02: ("j", "J", "task_pc0"),
    0x03: ("jal", "J", "task_pc0"),
    0x04: ("beq", "branch2", "imem_dmem_4k"),
    0x05: ("bne", "branch2", "imem_dmem_4k"),
    0x06: ("blez", "branch1", "imem_dmem_4k"),
    0x07: ("bgtz", "branch1", "imem_dmem_4k"),
    0x09: ("addiu", "imm", "su_r4000"),
    0x0B: ("sltiu", "imm", "su_r4000"),
    0x0C: ("andi", "imm", "su_r4000"),
    0x0D: ("ori", "imm", "su_r4000"),
    0x0E: ("xori", "imm", "su_r4000"),
    0x0F: ("lui", "lui", "su_r4000"),
    0x10: ("cop0", "cop0", "rsp_physical"),
    0x12: ("cop2", "cop2", "vu_elements"),
    # `lh` is in the subset the cited page names explicitly ("using the standard opcodes like LW / SW or
    # LH / LHU / SH"), and this program contains none of them -- added for `callback_table.py`, which
    # disassembles the CPU-side handler that reads the 0x36 dispatch table (M226). Zero words here, so
    # no count in this manifest moves.
    0x21: ("lh", "load", "dmem_only"),
    0x23: ("lw", "load", "dmem_only"),
    0x24: ("lbu", "load", "dmem_only"),
    0x25: ("lhu", "load", "dmem_only"),
    0x28: ("sb", "store", "dmem_only"),
    0x29: ("sh", "store", "dmem_only"),
    0x2B: ("sw", "store", "dmem_only"),
    0x32: ("lwc2", "cop2xfer", "vu_elements"),
    0x3A: ("swc2", "cop2xfer", "vu_elements"),
}

# --- the vector unit, cited -------------------------------------------------------------------------
# M223 refused to name these: the local manual tabulates no COP2 encoding, and naming would have meant
# importing a table. M224 narrowed that policy -- an external table may be used as a *cited* source, so
# each name below carries the row it came from. Source: N64brew Wiki, Reality_Signal_Processor/CPU_Core,
# revision 5539 (CC BY-SA-4.0), facts restated, no text reproduced. See docs/THIRD_PARTY.md 4b.
VU_EXT = {
    "vu_alu": ("https://n64brew.dev/wiki/Reality_Signal_Processor/CPU_Core", 5539,
               "the computational-instruction table: opcode -> mnemonic and description"),
    "vu_select": ("https://n64brew.dev/wiki/Reality_Signal_Processor/CPU_Core", 5539,
                  "the select-instruction table: opcode -> mnemonic and description"),
    "vu_single": ("https://n64brew.dev/wiki/Reality_Signal_Processor/CPU_Core", 5539,
                  "the single-lane table, including the vt_elem/vd_elem lane computation"),
    "vu_broadcast": ("https://n64brew.dev/wiki/Reality_Signal_Processor/CPU_Core", 5539,
                     "the element-field table: element value -> GNU assembly modifier"),
    "vu_transfer": ("https://n64brew.dev/wiki/Reality_Signal_Processor/CPU_Core", 5539,
                    "the load/store table: opcode -> row name and access size, and the field split"),
}

# The access sizes the cited table states, restated by instruction and direction so the gate can check the
# decoder's table against the citation rather than against itself. `lwc2` is opcode 0x32, `swc2` 0x3A.
CITED_ACCESS_SIZE = {
    (0x32, 0x00): 1, (0x3A, 0x00): 1, (0x32, 0x01): 2, (0x3A, 0x01): 2,
    (0x32, 0x02): 4, (0x3A, 0x02): 4, (0x32, 0x03): 8, (0x3A, 0x03): 8,
    (0x32, 0x04): 16, (0x3A, 0x04): 16, (0x32, 0x05): 16, (0x3A, 0x05): 16,
}

# opcode -> (mnemonic, description as the source states it, group)
VU_ALU = {
    0x00: ("vmulf", "multiply S1.15 x S1.15, rounding, signed clamp"),
    0x01: ("vmulu", "multiply S1.15 x S1.15, rounding, unsigned clamp"),
    0x04: ("vmudl", "multiply U0.16 x U0.16, signed clamp"),
    0x05: ("vmudm", "multiply S0.16 x U0.16, signed clamp"),
    0x06: ("vmudn", "multiply U0.16 x S0.16, signed clamp"),
    0x07: ("vmudh", "multiply S0.16 x S0.16, signed clamp"),
    0x08: ("vmacf", "vmulf, adding to the accumulator"),
    0x09: ("vmacu", "vmulu, adding to the accumulator"),
    0x0C: ("vmadl", "vmudl, adding to the accumulator"),
    0x0D: ("vmadm", "vmudm, adding to the accumulator"),
    0x0E: ("vmadn", "vmudn, adding to the accumulator"),
    0x0F: ("vmadh", "vmudh, adding to the accumulator"),
    0x10: ("vadd", "add with carry"),
    0x13: ("vabs", "absolute value"),
    0x14: ("vaddc", "add, writing the overflow into the carry"),
    0x1D: ("vsar", "read a portion of the accumulator into a vector register"),
    0x28: ("vand", "bitwise and"), 0x29: ("vnand", "bitwise nand"),
    0x2A: ("vor", "bitwise or"), 0x2B: ("vnor", "bitwise nor"),
    0x2C: ("vxor", "bitwise xor"), 0x2D: ("vnxor", "bitwise nxor"),
}
VU_SELECT = {
    0x20: ("vlt", "select the lower of two vectors"),
    0x21: ("veq", "compare two vectors for equality"),
    0x22: ("vne", "compare two vectors for difference"),
    0x23: ("vge", "select the greater or equal of two vectors"),
    0x24: ("vcl", "clip against two bounds, lower halves"),
    0x25: ("vch", "clip against two bounds, upper halves"),
    0x26: ("vcr", "clip against a power-of-two bound"),
    0x27: ("vmrg", "merge two vectors lane by lane using the flags"),
}
VU_SINGLE = {
    0x30: ("vrcp", "32-bit reciprocal of a 16-bit fixed point"),
    0x31: ("vrcpl", "32-bit reciprocal of a 32-bit fixed point"),
    0x32: ("vrcph", "upper 16 bits of a previous vrcp"),
    0x33: ("vmov", "copy one lane of a vector register into another"),
    0x34: ("vrsq", "32-bit reciprocal square root of a 16-bit fixed point"),
    0x35: ("vrsql", "32-bit reciprocal square root of a 32-bit fixed point"),
    0x36: ("vrsqh", "upper 16 bits of a previous vrsq"),
    0x37: ("vnop", "no operation (the source marks this one with a question mark)"),
    0x3F: ("vnull", "no operation (the source marks this one with a question mark)"),
}
# The fixed point formats and the operation class, both as the cited table states them, so the census below
# describes the program's arithmetic with cited words instead of an adjective.
VU_FORMAT = {
    "vmulf": "S1.15 x S1.15", "vmulu": "S1.15 x S1.15", "vmacf": "S1.15 x S1.15", "vmacu": "S1.15 x S1.15",
    "vmudl": "U0.16 x U0.16", "vmadl": "U0.16 x U0.16",
    "vmudm": "S0.16 x U0.16", "vmadm": "S0.16 x U0.16",
    "vmudn": "U0.16 x S0.16", "vmadn": "U0.16 x S0.16",
    "vmudh": "S0.16 x S0.16", "vmadh": "S0.16 x S0.16",
}
VU_KIND = {
    "vmulf": "multiply", "vmulu": "multiply", "vmudl": "multiply", "vmudm": "multiply",
    "vmudn": "multiply", "vmudh": "multiply",
    "vmacf": "multiply-accumulate", "vmacu": "multiply-accumulate", "vmadl": "multiply-accumulate",
    "vmadm": "multiply-accumulate", "vmadn": "multiply-accumulate", "vmadh": "multiply-accumulate",
    "vadd": "add", "vaddc": "add", "vabs": "absolute value", "vsar": "accumulator read",
    "vand": "bitwise", "vnand": "bitwise", "vor": "bitwise", "vnor": "bitwise",
    "vxor": "bitwise", "vnxor": "bitwise",
    "vlt": "select", "veq": "compare", "vne": "compare", "vge": "select", "vcl": "clip",
    "vch": "clip", "vcr": "clip", "vmrg": "merge",
    "vrcp": "reciprocal", "vrcpl": "reciprocal", "vrcph": "reciprocal",
    "vrsq": "reciprocal square root", "vrsql": "reciprocal square root", "vrsqh": "reciprocal square root",
    "vmov": "lane move", "vnop": "no operation", "vnull": "no operation",
}

# element value -> the GNU assembly modifier, for values 2..15; 0 and 1 are a normal register access
VU_BROADCAST = {2: "e(0q)", 3: "e(1q)", 4: "e(0h)", 5: "e(1h)", 6: "e(2h)", 7: "e(3h)",
                8: "e(0)", 9: "e(1)", 10: "e(2)", 11: "e(3)", 12: "e(4)", 13: "e(5)",
                14: "e(6)", 15: "e(7)"}
# load/store opcode -> (load mnemonic, store mnemonic, access size in bytes as the source states it)
VU_ROWS = {
    0x00: ("lbv", "sbv", 1), 0x01: ("lsv", "ssv", 2), 0x02: ("llv", "slv", 4),
    0x03: ("ldv", "sdv", 8), 0x04: ("lqv", "sqv", 16), 0x05: ("lrv", "srv", 16),
}
# Rows the source lists without stating an access size, so no address can be folded for them.
VU_ROWS_UNSCALED = {0x06: ("lpv", "spv"), 0x07: ("luv", "suv"), 0x08: ("lhv", "shv"),
                    0x09: ("lfv", "sfv"), 0x0B: ("ltv", "stv")}
# The source's transpose group states `0x01 swv`, which collides with the scalar group's `0x01 lsv/ssv`.
# Recorded as a defect in the source rather than resolved: no ltv/stv/swv appears in this program, so no
# claim here depends on it. Measured, not assumed -- `by_row` below counts what is present.
VU_SOURCE_DEFECTS = [
    "the transpose group lists `0x01 swv` while the scalar group lists `0x01 lsv/ssv`: one opcode cannot "
    "be both, so one of the two rows mis-states it. No word in this program uses the transpose group, so "
    "nothing here depends on which",
    "the computational table omits `funct 0x11`, which this program uses twice; it is left unnamed and "
    "listed rather than guessed at",
]

# Opcodes whose *existence* on the SU this repository cannot settle. They are decoded into their family shape
# for the listing, then listed in `unreadable` instead of being counted as understood instructions.
UNSETTLED = {
    0x14: ("beql", "the R4000 name of this shape is `beql`, a branch-likely; the local manual does not settle "
                   "whether the SU implements the branch-likely class, so the two words are listed, not assumed"),
}


def bits(word, hi, lo):
    return (word >> lo) & ((1 << (hi - lo + 1)) - 1)


def sx16(v):
    return v - 0x10000 if v & 0x8000 else v


def imem_target(word):
    """(raw, masked) for a J-form instruction: raw is the plain MIPS reading, masked the 12-bit IMEM offset."""
    raw = (word & 0x3FFFFFF) << 2
    return raw, raw & 0xFFF


def decode(word, va):
    """One word -> a decode record. Never names anything the local authority cannot support."""
    op = bits(word, 31, 26)
    rec = {"at": va, "word": word, "opcode": op, "mnemonic": None, "text": None,
           "cite": None, "status": FAMILY}
    if op == 0x00:
        funct = bits(word, 5, 0)
        if funct == 0x00 and word == 0:
            rec.update(mnemonic="nop", text="nop", cite="su_r4000")
            return rec
        if funct not in SPECIAL:
            return _unreadable(rec, "SPECIAL funct 0x%02x" % funct)
        mn, form = SPECIAL[funct]
        rs, rt, rd = bits(word, 25, 21), bits(word, 20, 16), bits(word, 15, 11)
        if form == "shift":
            rd, rt, sa = bits(word, 15, 11), bits(word, 20, 16), bits(word, 10, 6)
            rec.update(mnemonic=mn, text="%s %s,%s,%d" % (mn, REG[rd], REG[rt], sa), cite="su_r4000")
        elif form == "jr":
            rec.update(mnemonic=mn, text="jr %s" % REG[rs], cite="su_r4000",
                       jump_reg=rs, indirect=(rs != 31))
        elif form == "break":
            rec.update(mnemonic=mn, text="break", cite="su_r4000")
        else:
            rec.update(mnemonic=mn, text="%s %s,%s,%s" % (mn, REG[rd], REG[rs], REG[rt]), cite="su_r4000")
        return rec
    if op == 0x01:
        rt = bits(word, 20, 16)
        if rt not in REGIMM:
            return _unreadable(rec, "REGIMM rt 0x%02x" % rt)
        mn = REGIMM[rt]
        rs = bits(word, 25, 21)
        tgt = (va + 4 + (sx16(word & 0xFFFF) << 2)) & 0xFFF
        rec.update(mnemonic=mn, text="%s %s,0x%03x" % (mn, REG[rs], tgt), cite="imem_dmem_4k",
                   branch_target=tgt)
        return rec
    if op in (0x02, 0x03):
        mn = OPCODES[op][0]
        raw, masked = imem_target(word)
        rec.update(mnemonic=mn, text="%s 0x%03x" % (mn, masked), cite="task_pc0",
                   jump_target=masked, target_raw=raw)
        return rec
    if op in (0x04, 0x05, 0x06, 0x07):
        mn, form, cite = OPCODES[op]
        rs, rt = bits(word, 25, 21), bits(word, 20, 16)
        tgt = (va + 4 + (sx16(word & 0xFFFF) << 2)) & 0xFFF
        if form == "branch2":
            text = "%s %s,%s,0x%03x" % (mn, REG[rs], REG[rt], tgt)
        else:
            text = "%s %s,0x%03x" % (mn, REG[rs], tgt)
        rec.update(mnemonic=mn, text=text, cite=cite, branch_target=tgt)
        return rec
    if op in (0x09, 0x0B, 0x0D):
        mn = OPCODES[op][0]
        rs, rt, imm = bits(word, 25, 21), bits(word, 20, 16), sx16(word & 0xFFFF)
        rec.update(mnemonic=mn, text="%s %s,%s,%d" % (mn, REG[rt], REG[rs], imm), cite="su_r4000")
        return rec
    if op in (0x0C, 0x0E):
        mn = OPCODES[op][0]
        rs, rt = bits(word, 25, 21), bits(word, 20, 16)
        rec.update(mnemonic=mn, text="%s %s,%s,0x%04x" % (mn, REG[rt], REG[rs], word & 0xFFFF),
                   cite="su_r4000")
        return rec
    if op == 0x0F:
        rt = bits(word, 20, 16)
        rec.update(mnemonic="lui", text="lui %s,0x%04x" % (REG[rt], word & 0xFFFF), cite="su_r4000")
        return rec
    if op == 0x10:
        # COP0 move: the *kind* is family; the SP register's identity is in no local document, so `reg` is
        # reported raw and given no name.
        rs, rt, rd = bits(word, 25, 21), bits(word, 20, 16), bits(word, 15, 11)
        kind = {0x00: "mfc0", 0x04: "mtc0"}.get(rs)
        if kind is None:
            return _unreadable(rec, "COP0 rs 0x%02x" % rs)
        rec.update(mnemonic=kind, text="%s %s,<sp reg %d>" % (kind, REG[rt], rd), cite="rsp_physical",
                   sp_reg=rd, sp_reg_name=None)
        return rec
    if op == 0x12:
        return _vector(rec, word)
    if op in (0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B):
        mn, form, cite = OPCODES[op]
        rs, rt, off = bits(word, 25, 21), bits(word, 20, 16), sx16(word & 0xFFFF)
        rec.update(mnemonic=mn, text="%s %s,%d(%s)" % (mn, REG[rt], off, REG[rs]), cite=cite,
                   dmem_offset=off & 0xFFFF)
        return rec
    if op in (0x32, 0x3A):
        # M223 read bits 15:0 as a 16-bit signed displacement, could not make 0x2000 one, and excluded all
        # of these accesses from the DMEM statistics. The split is base / vt / row opcode (15:11) /
        # element (10:7) / offset (6:0), and the address is base + offset * access size (cited).
        load = op == 0x32
        base, vt, rowop, el, off = (bits(word, 25, 21), bits(word, 20, 16), bits(word, 15, 11),
                                    bits(word, 10, 7), bits(word, 6, 0))
        if rowop in VU_ROWS:
            name, scale = VU_ROWS[rowop][0 if load else 1], VU_ROWS[rowop][2]
        elif rowop in VU_ROWS_UNSCALED:
            name, scale = VU_ROWS_UNSCALED[rowop][0 if load else 1], None
        else:
            name, scale = None, None
        if name is None:
            return _unreadable(rec, "lwc2/swc2 row 0x%02x (not in the cited table)" % rowop)
        rec.update(mnemonic=name, cite="vu_transfer", vector_kind="vector_transfer",
                   vu_row=name, vu_row_opcode=rowop, vu_element=el, vu_offset=off, vu_scale=scale,
                   dmem_vector_offset=(off * scale) if scale else None,
                   text="%s v%d,%d(%s) [element %d%s]"
                        % (name, vt, off, REG[base], el,
                           "" if scale is None else ", x%d" % scale))
        return rec
    if op in UNSETTLED:
        mn = UNSETTLED[op][0]
        rec.update(mnemonic=mn, text="%s (unsettled)" % mn, cite="imem_dmem_4k", unsettled=op)
        return _unreadable(rec, "opcode 0x%02x (%s)" % (op, mn))
    return _unreadable(rec, "opcode 0x%02x" % op)


def _unreadable(rec, key):
    rec["status"] = "unreadable"
    rec["unreadable_key"] = key
    if rec["text"] is None:
        rec["text"] = "?? 0x%08x" % rec["word"]
    return rec


def _vector(rec, word):
    """COP2. Named from the cited table where it covers the word, and refused where it does not.

    Two of the source's groups share this shape (COP2, bit 25 set) and are told apart by the opcode:
    computational 0x00-0x2D, select 0x20-0x27 (inside that range but disjoint from it), single-lane
    0x30-0x3F. A single-lane word's `element` field is not a broadcast modifier at all -- it is two
    lane selectors, and the source gives the rule for computing the source lane, which is implemented
    here rather than approximated.
    """
    co = bits(word, 25, 25)
    if co == 0:
        rs = bits(word, 25, 21)
        kind = {0x00: "mfc2", 0x02: "cfc2", 0x04: "mtc2", 0x06: "ctc2"}.get(rs)
        if kind is None:
            return _unreadable(rec, "COP2 rs 0x%02x" % rs)
        rt, vreg = bits(word, 20, 16), bits(word, 15, 11)
        vs_elem = bits(word, 10, 7)
        rec.update(mnemonic=kind, cite="vu_transfer", vector_kind="transfer", vu_reg=vreg,
                   vs_elem=vs_elem,
                   text="%s %s,v%d[e byte %d]" % (kind, REG[rt], vreg, vs_elem))
        rec["status"] = "vector"
        return rec
    e, vt, vs, vd, fn = bits(word, 24, 21), bits(word, 20, 16), bits(word, 15, 11), bits(word, 10, 6), bits(word, 5, 0)
    if fn in VU_SINGLE:
        name, why = VU_SINGLE[fn]
        vd_reg, vt_elem, vd_elem = vs, e, vd      # bits 15:11 hold vd here, 10:6 hold vd_elem
        de = vd_elem & 7
        msb = vt_elem.bit_length() - 1
        # the source's rule: every bit of vt_elem from its topmost set bit upward is replaced by the
        # same-position bit of vd_elem, so a small vt_elem borrows from the destination lane
        se = (((vd_elem >> msb) << msb) | (vt_elem & ((1 << msb) - 1))) & 7 if msb > 0 else vt_elem & 7
        rec.update(mnemonic=name, status="vector", vector_kind="single", cite="vu_single",
                   vu={"element": e, "vt": vt, "vd": vd_reg, "opcode": fn,
                       "source_lane": se, "dest_lane": de},
                   why=why,
                   text="%s v%d[e(%d)],v%d[e(%d)]" % (name, vd_reg, de, vt, se))
        return rec
    group = "vu_alu" if fn in VU_ALU else "vu_select" if fn in VU_SELECT else None
    table = VU_ALU if fn in VU_ALU else VU_SELECT if fn in VU_SELECT else None
    if table is None:
        rec.update(status="vector", vector_kind="alu", cite="vu_alu",
                   vu={"element": e, "vt": vt, "vs": vs, "vd": vd, "funct": fn},
                   text="cop2 e=%d vt=v%d vs=v%d vd=v%d funct=0x%02x (unlisted)"
                        % (e, vt, vs, vd, fn),
                   unreadable_key="COP2 funct 0x%02x (not in the cited table)" % fn)
        rec["mnemonic"] = None
        return rec
    name, why = table[fn]
    mod = ("," + VU_BROADCAST[e]) if e in VU_BROADCAST else ""
    rec.update(mnemonic=name, status="vector", vector_kind="alu", cite=group, why=why,
               vu={"element": e, "vt": vt, "vs": vs, "vd": vd, "funct": fn},
               text="%s v%d,v%d,v%d%s" % (name, vd, vs, vt, mod))
    return rec



# --- image access ---------------------------------------------------------------------------------------
def stage2():
    """The unpacked stage-2 member, or None. The cartridge itself is never committed, so a fresh clone has
    the unpacked member but nothing else; if even that is absent every image-dependent case SKIPs."""
    return IMAGE.read_bytes() if IMAGE.exists() else None


def word_at(image, va):
    off = va - STAGE2_BASE
    return int.from_bytes(image[off:off + 4], "big")


def ucode_blob(image):
    return image[UCODE_VA - STAGE2_BASE:UCODE_VA - STAGE2_BASE + UCODE_SIZE]


def entropy(data):
    counts = {}
    for b in data:
        counts[b] = counts.get(b, 0) + 1
    n = len(data)
    return -sum(c / n * math.log2(c / n) for c in counts.values())


# --- constant folding over stage-2 ----------------------------------------------------------------------
# The task block's pointers exist nowhere as literals (measured: 0 occurrences of 0x800b2700 in stage-2), so
# each field value is re-derived from the instructions that write the register. This is the rule the manifest
# states, and `--check` re-runs it: a manifest value that no fold reproduces is a failure.
SPECIAL_DST = {0x00, 0x02, 0x03, 0x06, 0x21, 0x23, 0x24, 0x25, 0x2A, 0x2B}


def dst_reg(word):
    op = bits(word, 31, 26)
    if op == 0x00:
        return bits(word, 15, 11) if bits(word, 5, 0) in SPECIAL_DST else None
    if op in (0x02, 0x03):
        return None
    return bits(word, 20, 16)


def fold(image, at_va, reg, window=32):
    """The 32-bit value in `reg` just before `at_va`, folded from lui/addiu/ori/subu, or None.

    Returns (value, [instruction, ...]) with the trace in the order the instructions are written. Deliberately
    not a dataflow: it walks back at most `window` instructions and gives up on anything but a constant arm, so
    a value it cannot fold is reported as unfolded instead of guessed.
    """
    for step in range(1, window + 1):
        va = at_va - 4 * step
        if va < STAGE2_BASE:
            return None
        w = word_at(image, va)
        op = bits(w, 31, 26)
        if dst_reg(w) != reg:
            continue
        ins = "%08x %s" % (va, decode(w, va)["text"])
        if op == 0x0F:
            return ((w & 0xFFFF) << 16, [ins])
        if op in (0x09, 0x0D) and bits(w, 25, 21) == 0:
            low = (w & 0xFFFF) if op == 0x0D else sx16(w & 0xFFFF)
            return (low & 0xFFFFFFFF, [ins])
        if op in (0x09, 0x0D) and bits(w, 25, 21) == reg:
            base = fold(image, va, reg, window)
            if base is None:
                return None
            low = (w & 0xFFFF) if op == 0x0D else sx16(w & 0xFFFF)
            return ((base[0] + low) & 0xFFFFFFFF, base[1] + [ins])
        if op == 0x00 and bits(w, 5, 0) == 0x23:               # subu rd,rs,rt
            a = fold(image, va, bits(w, 25, 21), window)
            b = fold(image, va, bits(w, 20, 16), window)
            if a is None or b is None:
                return None
            return ((a[0] - b[0]) & 0xFFFFFFFF, a[1] + b[1] + [ins])
        return None
    return None


def source_of(image, at_va, reg, window=32):
    """What the store at `at_va` puts in `reg`: a folded constant, a load, or nothing this tool can name."""
    const = fold(image, at_va, reg, window)
    if const is not None:
        return {"kind": "const", "value": const[0], "trace": const[1]}
    for step in range(1, window + 1):
        va = at_va - 4 * step
        if va < STAGE2_BASE:
            break
        w = word_at(image, va)
        if dst_reg(w) != reg:
            continue
        ins = "%08x %s" % (va, decode(w, va)["text"])
        kind = "load" if bits(w, 31, 26) in (0x23, 0x24, 0x25) else "unknown"
        return {"kind": kind, "value": None, "trace": [ins]}
    return {"kind": "unknown", "value": None, "trace": []}


# --- the task block -------------------------------------------------------------------------------------
# (offset, name, the store instruction that writes it). The stores are the only writers: FUN_800a2e40 is the
# one function in the corpus that names 0x80143c60 at all.
TASK_FIELDS = [
    (0x00, "type_or_kind", 0x800A2E6C),
    (0x04, "flags_or_zero", 0x800A2EC4),
    (0x08, "pair_a_pointer", 0x800A2EC8),
    (0x0C, "pair_a_size", 0x800A2E88),
    (0x10, "ucode_pointer", 0x800A2E94),
    (0x14, "ucode_size", 0x800A2E9C),
    (0x18, "data_pointer", 0x800A2EA8),
    (0x1C, "data_size", 0x800A2ECC),
    (0x30, "list_pointer", 0x800A2ED0),
    (0x34, "frame_count", 0x800A2ED8),
]

TASK_ROLE = {
    0x00: "written 2 — the only word in the block that says what kind of block it is",
    0x04: "written zero; nothing in the block reads it back on the CPU side",
    0x08: "a pointer whose 0xd0-byte extent is CPU-shaped MIPS, not RSP code (see evidence E2): the role is "
          "recorded, not named",
    0x0C: "the first pair's size, folded as 0x80028b50 - 0x80028a80 = 0xd0 rather than stored as a constant",
    0x10: "this blob: the RSP program the task runs",
    0x14: "the blob's size, exactly IMEM's capacity",
    0x18: "a 0x800-byte region at 0x80136b50 that no other stage-2 instruction names (0 references measured), "
          "and whose last 0x5c0 bytes run past the image's end (0x80136d90) into memory this image does not "
          "contain",
    0x1C: "the region's size, 0x800",
    0x30: "a value loaded from 0x80143f50, not a constant: the pointer the work list is published through",
    0x34: "a halfword loaded through 0x80143f54: the count of work units in that list. Its store sits in the "
          "delay slot of the flush call at 0x800a2ed4, so the count and the flush are published in one "
          "instruction pair",
}


def task_section(image):
    fields = []
    for off, name, site in TASK_FIELDS:
        w = word_at(image, site)
        rec = decode(w, site)
        base_reg, dest_reg = bits(w, 25, 21), bits(w, 20, 16)
        disp = sx16(w & 0xFFFF)
        base = fold(image, site, base_reg, window=32)
        resolved = (base[0] + disp) & 0xFFFFFFFF if base else None
        src = source_of(image, site, dest_reg)
        fields.append({
            "offset": off,
            "name": name,
            "role": TASK_ROLE[off],
            "writer": "%08x %s" % (site, rec["text"]),
            "block_address": hex(resolved) if resolved is not None else None,
            "block_address_trace": base[1] if base else
                                   ["the base register is only half formed here: %s" % rec["text"]],
            "value": src["value"] if src["kind"] == "const" else None,
            "value_hex": hex(src["value"]) if src["kind"] == "const" else None,
            "value_kind": src["kind"],
            "value_trace": src["trace"],
        })
    return {
        "block": hex(TASK_BLOCK),
        "written_by": "src/stage2/FUN_800a2e40.c (the corpus's only reference to the block); every store is "
                      "re-decoded here and its base folded",
        "address_rule": FOLD_RULE,
        "fields": fields,
        "submitted_to": {
            "site": "0x800a2ee4",
            "instruction": "%08x %s" % (0x800A2EE4, decode(word_at(image, 0x800A2EE4), 0x800A2EE4)["text"]),
            "argument": "a0 = the block address, set in the delay slot at 0x800a2ee8 (%s)"
                        % decode(word_at(image, 0x800A2EE8), 0x800A2EE8)["text"],
            "handler": "*(0x80143ff0) — a function pointer, installed by FUN_800b1fc0 "
                       "(src/stage2/FUN_800b1fc0.c:14 `_DAT_80143ff0 = *param_1;`), so the submit path is "
                       "whatever the driver installed and not a named OS entry point",
            "cache_flush": "between the stores and the submit, 0x800a2ed8 calls 0x8000efa0 with "
                           "(list, count*0xa10): the recipe at 0x800a2eb0-0x800a2ec0 is "
                           "`sll a1,a2,2 / addu a1,a1,a2 / sll a1,a1,5 / addu a1,a1,a2 / sll a1,a1,4`, i.e. "
                           "0xa10 bytes per work unit, which is the manual's requirement that the task header "
                           "be written back before the RSP reads it (p47)",
        },
    }


# --- what the window actually holds ---------------------------------------------------------------------
def corpus_functions():
    """Function starts this project's own corpus declares, from the `address` line of each FUN_*.c header.

    This is the only mechanical way to ask "does a CPU function begin inside the RSP window?", and the answer
    is yes: FUN_800b3640 starts 0xC0 bytes before the window's end, so the declared 0x1000 overruns the
    program. The window is therefore split at that boundary and the tail is not decoded as a program.
    """
    out = {}
    for p in sorted((ROOT / CORPUS).glob("FUN_*.c")):
        m = CORPUS_ADDR.search(p.read_text(errors="replace")[:600])
        if m:
            out[int(m.group(1), 16)] = str(p.relative_to(ROOT))
    return out


def foreign_start():
    """Offset inside the window at which a corpus CPU function begins (== SIZE when none does)."""
    inside = [a for a in corpus_functions() if UCODE_VA < a < UCODE_VA + UCODE_SIZE]
    return min(inside) - UCODE_VA if inside else UCODE_SIZE


# --- the program ----------------------------------------------------------------------------------------
def analyses(words):
    """Decode every word once; callers share this."""
    return [decode(w, i * 4) for i, w in enumerate(words)]


def functions_of(dec):
    """Functions are rooted at IMEM 0 and at every `jal` target — nothing else is invented.

    A body runs from its entry to its first `jr` (plus that jump's delay slot), capped at the next root: a body
    that reaches the next root without a `jr` falls through, and the manifest says so instead of extending it
    over the neighbour. `j` targets are recorded as jumps, not roots, because a `j` is not a call.
    """
    roots = sorted({0} | {d["jump_target"] for d in dec if d["mnemonic"] == "jal"})
    out = []
    for i, entry in enumerate(roots):
        limit = roots[i + 1] if i + 1 < len(roots) else len(dec) * 4
        body, end, returned = dec[entry // 4:limit // 4], limit, False
        for d in body:
            if d["mnemonic"] == "jr":
                end, returned = min(limit, d["at"] + 8), True
                break
        # A branch out of the body that lands between its first exit and the next root proves those words are
        # still this function's: extend to cover them, repeatedly, so a two-exit routine is one function.
        changed = True
        while changed and end < limit:
            changed = False
            targets = [d["branch_target"] for d in dec[entry // 4:end // 4] if d.get("branch_target")]
            beyond = [t for t in targets if end <= t < limit]
            if beyond:
                end, changed = max(beyond) + 4, True
                for d in dec[end // 4 - 1:limit // 4]:
                    if d["mnemonic"] == "jr":
                        end = min(limit, d["at"] + 8)
                        break
        body = dec[entry // 4:end // 4]
        calls = [d["jump_target"] for d in body if d["mnemonic"] == "jal"]
        out.append({
            "entry": entry,
            "end": end,
            "instructions": len(body),
            "calls": sorted(set(calls)),
            "call_sites": len(calls),
            "jumps": sorted({d["jump_target"] for d in body if d["mnemonic"] == "j"}),
            "returns": sum(1 for d in body if d["mnemonic"] == "jr" and d.get("jump_reg") == 31),
            "indirect_exits": sorted(d["at"] for d in body if d.get("indirect")),
            "ends_in_return": returned,
        })
    return roots, out


def coverage(dec, funcs):
    """The words no function body covers, as runs. Listed, not attributed."""
    covered = bytearray(len(dec))
    for f in funcs:
        for i in range(f["entry"] // 4, f["end"] // 4):
            covered[i] = 1
    runs, start = [], None
    for i, c in enumerate(covered):
        if not c and start is None:
            start = i
        elif c and start is not None:
            runs.append({"start": start * 4, "end": i * 4, "words": i - start})
            start = None
    if start is not None:
        runs.append({"start": start * 4, "end": len(dec) * 4, "words": len(dec) - start})
    return runs


def program_section(dec, words, foff):
    """Everything about the program proper: the RSP words only. `foff` is where CPU code takes over."""
    rsp = dec[:foff // 4]
    roots, funcs = functions_of(rsp)
    gaps = coverage(rsp, funcs)
    raw_targets = [d["target_raw"] for d in rsp if d.get("target_raw") is not None]
    dmem = [d["dmem_offset"] for d in rsp
            if "dmem_offset" in d and d["mnemonic"] in ("lh", "lw", "lbu", "lhu", "sb", "sh", "sw")]
    vector_rows = {}
    for d in rsp:
        if d["vector_kind"] == "vector_transfer" if d.get("vector_kind") else False:
            vector_rows[d["vu_row"]] = vector_rows.get(d["vu_row"], 0) + 1
    sp_regs = {}
    for d in rsp:
        if "sp_reg" in d:
            key = "%s %d" % (d["mnemonic"], d["sp_reg"])
            sp_regs[key] = sp_regs.get(key, 0) + 1
    unresolved = [{"at": d["at"], "kind": "jr r%d (register indirect)" % d["jump_reg"],
                   "why": "the target is whatever the register holds at run time; the edge exists and its "
                          "destination does not. 0xf34 `jr t0` returns through r8, which the routine at 0xe34 "
                          "saves from ra in its first instruction (`or t0,zero,ra` at 0xe34), so the exit is a "
                          "return through a saved link rather than an unknown call"}
                  for d in rsp if d.get("indirect")]
    unresolved += [{"at": g["start"], "kind": "words no function covers",
                    "why": "%d words from 0x%03x are reached by no jal target and by no modelled fall-through; "
                           "listed as uncovered rather than assigned to a neighbour" % (g["words"], g["start"])}
                   for g in gaps]
    return {
        "words": len(dec),
        "rsp_words": len(rsp),
        "instructions": sum(1 for d in rsp if d["text"]),
        "entry": 0,
        "roots": roots,
        "functions": funcs,
        "gaps": gaps,
        "foreign": {
            "offset": foff,
            "words": len(dec) - len(rsp),
            "ident": hex(UCODE_VA + foff),
            "evidence": [
                # .get, not []: with no corpus under the window this must say so, not raise. A gate that
                # crashes has not failed, it has stopped being a gate (M216's rule, met here by M225 when a
                # sandbox without src/ turned this line into a KeyError).
                "the corpus declares a CPU function at 0x%x: %s"
                % (UCODE_VA + foff, corpus_functions().get(UCODE_VA + foff,
                                                          "none — no corpus function starts inside the "
                                                          "window the task declares")),
                "the RSP program's last exit is 0xf34 `jr t0` with its delay slot at 0xf38, followed by a "
                "`nop` fill at 0xf3c; the next word is the CPU function's body",
                "the words from 0x%03x build a KSEG0 address (`lui v0,0x8016` + `addiu v0,v0,-0x74e0` = "
                "0x80158b20) and load/store through it — an RSP load cannot name RDRAM (p139: the RSP software "
                "can only access DMEM), so these are not RSP instructions" % foff,
                "the arithmetic agrees with the corpus body: FUN_800b3640 walks a 0x1228-stride table and "
                "compares +0x1224 against _DAT_8015af70 (src/stage2/FUN_800b3640.c:22-27), and the words here "
                "carry `addiu a0,a0,0x1228` and `lw v0,0x1224(a0)`",
            ],
            "not_decoded_as": "program words: they are listed in no function, contribute to no jump target and "
                              "to no DMEM statistic",
        },
        "unresolved_targets": unresolved,
        "jump_encoding": {
            "rule": ADDRESS_RULE,
            "count": len(raw_targets),
            "raw_first": hex(min(raw_targets)),
            "raw_last": hex(max(raw_targets)),
            "raw_page_base": hex(min(raw_targets) & 0xFFFFF000),
            "raw_pages": len({t & 0xFFFFF000 for t in raw_targets}),
            "raw_outside_imem": sum(1 for t in raw_targets if t >= UCODE_SIZE),
            "masked_inside": sum(1 for t in raw_targets if (t & 0xFFF) < UCODE_SIZE),
            "masked_first": hex(min(t & 0xFFF for t in raw_targets)),
            "masked_last": hex(max(t & 0xFFF for t in raw_targets)),
            "note": "counted over RSP words only. The one jump in the CPU tail (0xfa8 `j`, raw target "
                    "0xb3650 = 0x800b3650) is excluded and is itself a CPU jump, which corroborates where the "
                    "program ends",
        },
        "dmem": {
            "words_with_displacement": len(dmem),
            "distinct_offsets": len(set(dmem)),
            "min": hex(min(dmem)),
            "max": hex(max(dmem)),
            "above_4k": sorted({o for o in dmem if o > 0xFFF})[:8],
            "vector_transfers": sum(vector_rows.values()),
            "vector_rows": dict(sorted(vector_rows.items())),
            "cop2_note": "retracted from M223: the lwc2/swc2 immediate is not a 16-bit displacement, it is a "
                         "row opcode (15:11), an element (10:7) and a 7-bit offset (6:0) scaled by the row's "
                         "access size, so all %d vector transfers are DMEM accesses with a computable offset "
                         "and are no longer excluded. Their absolute addresses need the base register's "
                         "value, which is folded in manifests/rsp_iface.json rather than here"
                         % sum(vector_rows.values()),
            "note": "the 16-bit displacements of lw/lbu/lhu/sb/sh/sw are DMEM offsets (p139: the RSP software "
                    "can only access DMEM; p44: 4 KB of it). No offset is given a name: a name would have to "
                    "come from the ucode's own layout, and nothing on the CPU side records it",
        },
        "sp_registers": {
            "moves": sp_regs,
            "note": "COP0 register numbers, raw. The SP register map is in no local document, so this counts "
                    "which numbers are written and which are polled and names none of them",
        },
    }


def vector_census(dec, foff):
    """What the named vector words say the units' arithmetic is, in the cited table's own terms."""
    rsp = dec[:foff // 4]
    by_kind, by_format, by_row, by_move = {}, {}, {}, {}
    for d in rsp:
        m = d["mnemonic"]
        if d.get("vector_kind") == "vector_transfer":
            by_row[m] = by_row.get(m, 0) + 1
            continue
        if d["status"] != "vector":
            continue
        if d.get("vector_kind") == "transfer":
            by_move[m] = by_move.get(m, 0) + 1
            continue
        if m in VU_KIND:
            by_kind[VU_KIND[m]] = by_kind.get(VU_KIND[m], 0) + 1
            if m in VU_FORMAT:
                by_format[VU_FORMAT[m]] = by_format.get(VU_FORMAT[m], 0) + 1
        elif m:
            by_kind[m] = by_kind.get(m, 0) + 1
    return {
        "named_words": sum(by_kind.values()),
        "by_kind": dict(sorted(by_kind.items())),
        "by_fixed_point_format": dict(sorted(by_format.items())),
        "by_transfer_row": dict(sorted(by_row.items())),
        "by_su_vu_move": dict(sorted(by_move.items())),
        "reading": "The arithmetic is a 16-bit fixed-point multiply-accumulate pipeline: %d words multiply "
                   "and %d accumulate the product, in the formats the cited table names, and %d read the "
                   "accumulator back out. Saturating is not a separate instruction — the multiply opcodes "
                   "clamp on extraction (cited) — so the mixer's headroom is decided by which format it "
                   "picks per stage, which is exactly what the counts above report. This says what the "
                   "units compute; it does not say what the mixer does with the result."
                   % (by_kind.get("multiply", 0), by_kind.get("multiply-accumulate", 0),
                      by_kind.get("accumulator read", 0)),
    }


# --- identity -------------------------------------------------------------------------------------------
def identity_section(image, dec, prog, blob, foff):
    """Measure the ABI shape, and decide only if a measurement forces one name."""
    dec = dec[:foff // 4]
    cop0 = [d for d in dec if d.get("sp_reg") is not None]
    writes = sorted({d["sp_reg"] for d in cop0 if d["mnemonic"] == "mtc0"})
    reads = sorted({d["sp_reg"] for d in cop0 if d["mnemonic"] == "mfc0"})
    lui_consts = ["%04x:0x%04x" % (d["at"], d["word"] & 0xFFFF) for d in dec if d["mnemonic"] == "lui"]
    entry = dec[:10]
    evidence = [
        {"id": "E0",
         "measurement": "IMEM 0x000-0x024 is a status poll and nothing else: `mfc0 a2,<cop0 11>` / "
                        "`andi a1,a2,1` / `beq a1,zero,0x028` / `andi a1,a2,0x100` / `beq a1,zero,0x028`, then a "
                        "spin `mfc0 a1,<cop0 11>` / `andi a1,a1,0x100` / `bgtz a1,0x018`, and only then does the "
                        "program touch anything (0x028 is the first vector instruction). %d of the program's %d "
                        "COP0 moves are in its first 0x3d0 bytes, and %d words are COP0 moves."
                        % (sum(1 for d in dec[:0x3d4 // 4] if d.get("sp_reg") is not None), len(cop0), len(cop0)),
         "reading": "a program that begins by polling a hardware status word and issuing no work before it is "
                    "reachable is ucode driven by a task, not a data table: the wait has to be for the engine "
                    "that started it. Register 11 is called the RSP status register by N64 documentation this "
                    "repository does not hold — the name is recorded as coming from outside this repository's "
                    "authority, the number and the poll are measured, and nothing downstream depends on the "
                    "name.",
         "status": "measured; register name outside local authority"},
        {"id": "E1",
         "measurement": "the task block carries four pointer+size pairs — +0x08/+0x0c, +0x10/+0x14, "
                        "+0x18/+0x1c, +0x30/+0x34 — and the +0x10/+0x14 pair names this blob (0x800b2700, "
                        "0x1000). Each value was folded out of the store that writes it, not quoted.",
         "reading": "the block is a task header in the p137 sense: a structure the CPU fills and hands over "
                    "with a pointer to the microcode and a pointer to the data to process.",
         "status": "measured"},
        {"id": "E2",
         "measurement": "the +0x08/+0x0c pair names 0x80028a80 with size 0xd0 (= 0x80028b50-0x80028a80), and the "
                        "bytes there are CPU-shaped MIPS: `lw v1,0(s0)`, `sw v0,0x14(v1)`, `jalr v0`, and a "
                        "`jr ra` at 0x80028b14 whose delay slot is `addiu sp,sp,0x28`. This project's corpus has "
                        "FUN_80028b1c starting 0x9c bytes later, so the 0xd0 extent straddles a function "
                        "boundary.",
         "reading": "the manual gives that pair the *boot microcode* role — RSP code the R4300 DMAs into IMEM "
                    "before the task microcode (p137) — and these bytes are not RSP code. Either the pair carries "
                    "something else in this cartridge, or the block is not the OSTask of p137. Recorded against "
                    "both candidates rather than smoothed.",
         "status": "measured, unresolved"},
        {"id": "E3",
         "measurement": "the declared size is 0x1000 = all of IMEM (p44), but the program is 0x%x bytes: the "
                        "corpus's own function FUN_800b3640 begins at 0x%x, 0x%x bytes before the window ends, "
                        "and the RSP program's last exit is 0xf34 `jr t0` (delay 0xf38, `nop` fill 0xf3c)."
                        % (foff, UCODE_VA + foff, UCODE_SIZE - foff),
         "reading": "the size field is IMEM's capacity, not the code's length: the declared 0x%x overruns the "
                    "program by 0x%x bytes into the next CPU function. A task that DMAs 0x1000 bytes into IMEM "
                    "therefore loads the whole program plus 0x%x bytes of CPU code that no exit reaches. The "
                    "overrun is recorded, not corrected."
                        % (UCODE_SIZE, UCODE_SIZE - foff, UCODE_SIZE - foff),
         "status": "measured"},
        {"id": "E3b",
         "measurement": "IMEM 0x02c-0x030 (`lw a0,0x30(r1)` and `lw v1,0x34(r1)`) read DMEM 0x30 and 0x34 — the "
                        "same two offsets the CPU writes at 0x800a2ed0/0x800a2ed4 as the work-list pointer and "
                        "its count — before the program has written anything to DMEM.",
         "reading": "the block at 0x80143c60 is in DMEM when the program starts, which is the mechanism p137 "
                    "describes (the R4300 DMAs the task header into DMEM, sets PC to 0). It also means the "
                    "program assumes r1 holds zero at entry, and nothing in this repository establishes what the "
                    "RSP's general registers hold when a task starts — the manual lists the boot ucode, the task "
                    "header, PC and the halt status and no register state (p137). The assumption is recorded; it "
                    "is not explained.",
         "status": "measured; entry register state unresolved"},
        {"id": "E4",
         "measurement": "%d COP0 moves: registers %s are written, registers %s are read. Five blocks repeat one "
                        "shape — write three registers carrying data, then poll a fourth, and clear register 7 "
                        "with `mtc0 zero` — at 0x350, 0x384, 0x3b4 and 0x228-0x3c8."
                        % (len(cop0), writes, reads),
         "reading": "the shape is one DMA primitive copied: a source, a destination and a length are written and a "
                    "busy flag is polled. Which number is which is *not* claimed — no local document maps the SP "
                    "registers — so the copy's direction stays unresolved even though the idiom is measured.",
         "status": "measured, names unresolved"},
        {"id": "E5",
         "measurement": "%d words address DMEM by 16-bit displacement, across %d distinct offsets from 0x%03x to "
                        "0x%03x. No offset is named."
                        % (prog["dmem"]["words_with_displacement"], prog["dmem"]["distinct_offsets"],
                           int(prog["dmem"]["min"], 16), int(prog["dmem"]["max"], 16)),
         "reading": "the program's whole interface with the CPU is DMEM plus DMA, and the layout it builds there "
                    "is the ucode's own. Nothing on the CPU side mirrors it, so no field of it can be matched "
                    "against a documented ABI from inside this repository.",
         "status": "measured, ABI match unavailable"},
        {"id": "E6",
         "measurement": "the +0x18 pair names 0x80136b50 with size 0x800, and no other instruction in stage-2 "
                        "names that address — 0 references, scanned as a `lui 0x8013` + `addiu 0x6b50` pair and "
                        "as a literal. Its last 0x5c0 bytes run past the image's end at 0x80136d90.",
         "reading": "the region the ucode is handed as data is never touched by the CPU: it is either the ucode's "
                    "own DMA target or its scratch, and which one is `rsp_only`.",
         "status": "measured"},
        {"id": "E7",
         "measurement": "the program's only four `lui` constants are %s." % ", ".join(lui_consts),
         "reading": "the last 0xc0 bytes build RDRAM addresses in code instead of taking them from a pointer, and "
                    "0x8016xxxx sits above this image's end. The scheme the manual describes is that the task "
                    "header carries the pointer to the data to process (p137), so a hard-coded RDRAM address is a "
                    "departure from it. It does not by itself name the ucode's author.",
         "status": "measured"},
        {"id": "E8",
         "measurement": "the first `what_would_decide` item was an RSP encoding table this repository could "
                        "cite. It arrived in M224 and was applied in M225: 252 of the 254 vector words now "
                        "carry a cited mnemonic, and the census says the units run a 16-bit fixed-point "
                        "multiply-accumulate pipeline (%d multiply, %d multiply-accumulate, %d accumulator "
                        "reads) in five cited formats. The same milestone measured the call structure: no "
                        "computed transfer anywhere, every `jal` direct, and no load that selects a target.",
         "reading": "the table did not make this ucode's identity decidable, and it decided *against* the "
                    "first candidate's predicted shape rather than for it: the ABI that candidate describes "
                    "predicts a command list the ucode dispatches on, and this program has no dispatch of "
                    "any kind. What the table bought is the arithmetic — the mixer is a fixed-point MAC "
                    "pipeline — which is a description of the units, not a name for the ucode.",
         "status": "measured"},
    ]
    return {
        "candidates": [
            {"name": "Nintendo libaudio aspMain (the AL* / alAudioFrame ABI)",
             "would_predict": ["a task header whose microcode pointer and boot pointer both name RSP code (p137)",
                               "a command list of fixed-format 64-bit commands the ucode dispatches on",
                               "work items read through DMEM structures the CPU filled"],
             "against": ["E2: the pair the manual gives the boot-ucode role names CPU code, not RSP code",
                         "E8: the shape this candidate predicts is absent — no computed transfer exists in "
                         "the program, so there is no command dispatch to find; the third prediction (work "
                         "items read through DMEM structures the CPU filled) is the only one still standing"],
             "verdict": "refuted on the shape it predicts: a command list the ucode dispatches on, and this "
                        "program dispatches on nothing (M224, manifests/rsp_iface.json). Not proven false — "
                        "an ABI can be re-fronted — but the prediction was made and it failed"},
            {"name": "a Factor 5 / MusyX driver",
             "would_predict": ["a private task shape and a private command format",
                               "a streaming ring fed by the CPU rather than a per-frame command list"],
             "against": ["nothing in this repository measures Factor 5 or MusyX: no string, no signature, no "
                         "shape attributable to either. The cartridge's sound path is already known to be a "
                         "private codec (M221/M222), which is a different claim"],
             "verdict": "unresolved — no measurement here bears on it"},
            {"name": "a cartridge-private ucode",
             "would_predict": ["a task block only this cartridge's submit path consumes",
                               "hard-coded RDRAM addresses in the ucode's tail",
                               "no dependence on a documented command format"],
             "against": ["E7 fits and E1/E2 are consistent, but 'private' is the residual rather than a positive "
                         "identification: it is what is left when the two named families fail to be forced"],
             "verdict": "the reading the measurements leave standing, not a name"},
        ],
        "evidence": evidence,
        "verdict": "unresolved",
        "deciding_measurement": None,
        "what_would_decide": [
            "ANSWERED (M224/M225): an RSP encoding table was cited, the 254 vector words are named and the "
            "COP0 registers have names and directions. It did not make the identity decidable — the jal "
            "fan-out did not read as a command switch, because there is no computed transfer at all (E8)",
            "a CPU-side consumer of the 0x800 bytes at 0x80136b50 (E6): what the ucode is expected to write "
            "there is an ABI fingerprint",
            "an independent copy of the same ucode from another N64 title: byte equality would settle provenance "
            "without a table",
        ],
    }


# --- rsp_only -------------------------------------------------------------------------------------------
def rsp_only_section(prog, blob, dec):
    return [
        {"what": "the DMEM layout the ucode builds",
         "why": "the program's only data addressing is a 16-bit DMEM displacement (%d words, %d distinct, "
                "0x%03x-0x%03x). The CPU writes no structure the ucode reads by name, so every offset is decided "
                "inside the RSP and nothing on the CPU side can be cited for it"
                % (prog["dmem"]["words_with_displacement"], prog["dmem"]["distinct_offsets"],
                   int(prog["dmem"]["min"], 16), int(prog["dmem"]["max"], 16)),
         "cpu_evidence": "none — measured by scanning every stage-2 instruction that touches the task's own "
                         "structures"},
        {"what": "what the vector unit's arithmetic computes",
         "why": "since M224 the 254 words are *named* — 252 of them from a cited table, 2 refused because it "
                "has no row for their function code — but a name is not a meaning. `vmadh v2,v1,v0` says which "
                "instruction runs, not which signal it filters, and the mixer's structure is in the "
                "accumulator's use, which no document here describes",
         "cpu_evidence": "none — the CPU never writes a vector register"},
        {"what": "the meaning of the 0x800 bytes at 0x80136b50 (task+0x18)",
         "why": "no stage-2 instruction reads or writes that address (0 references) and its tail runs past the "
                "image. Whether the ucode treats it as input or scratch is decided only by the RSP",
         "cpu_evidence": "the task field that names it, and nothing else"},
        {"what": "the command format the ucode dispatches on",
         "why": "the list the task publishes (task+0x30, from 0x80143f50) is only handed over; the ucode must DMA "
                "it into DMEM itself and what it does with the bytes is inside the RSP. The jal fan-out at the "
                "top of the program is the dispatch, but its arms are unnamed until the encodings are",
         "cpu_evidence": "src/stage2/FUN_800a4d30.c writes the list base; the list's contents come from the voice "
                         "path (M222), which stops at this same boundary"},
        {"what": "whether the ucode is correct, or what it sounds like",
         "why": "this tool decodes instructions. Nothing here has been executed, so no claim is made that the "
                "program runs, terminates, or mixes",
         "cpu_evidence": "none — by construction"},
    ]


# --- the manifest ---------------------------------------------------------------------------------------
def derive(image):
    """The whole artefact, from the image alone. --check compares the committed file to this."""
    blob = ucode_blob(image)
    words = [int.from_bytes(blob[i:i + 4], "big") for i in range(0, len(blob), 4)]
    dec = analyses(words)
    foff = foreign_start()
    prog = program_section(dec, words, foff)

    scalar, vector, unreadable = {}, {}, {}
    counts = {"scalar": 0, "vector": 0, "unreadable": 0, "foreign": len(words) - foff // 4}
    for d in dec[:foff // 4]:
        if d["status"] == "unreadable":
            counts["unreadable"] += 1
            key = d["unreadable_key"]
            g = unreadable.setdefault(key, {"key": key, "kind": "opcode", "words": 0, "first": d["at"],
                                            "cite": d["cite"],
                                            "why": "named in no document this repository holds"})
            g["words"] += 1
        elif d["status"] == "vector":
            counts["vector"] += 1
            # Named where the cited table covers the word (M224), and keyed by the raw field where it
            # does not. The distinction is in `status`, so a reader can count the refusals.
            key = d["mnemonic"] if d["mnemonic"] else d["unreadable_key"]
            v = vector.setdefault(key, {"key": key, "words": 0, "first": d["at"],
                                        "mnemonic": d["mnemonic"], "cite": d["cite"],
                                        "why": d.get("why"),
                                        "status": "cited-external" if d["mnemonic"] else "unresolved",
                                        "fields_example": d["text"]})
            v["words"] += 1
            if d.get("vu"):
                v["fields"] = {k: v2 for k, v2 in d["vu"].items()}
        else:
            counts["scalar"] += 1
            s = scalar.setdefault(d["mnemonic"], {"mnemonic": d["mnemonic"], "words": 0, "first": d["at"],
                                                  "cite": d["cite"], "status": FAMILY,
                                                  "form_example": d["text"]})
            s["words"] += 1
    for key in list(unreadable):
        if key.startswith("opcode 0x14"):
            unreadable[key]["why"] = UNSETTLED[0x14][1]
    # Only what the cited table does not cover: since M224 that is two words out of 254, and the schema's one
    # place to look for "what this decoder will not name" must carry them rather than the whole group.
    for key, v in vector.items():
        if v["status"] == "unresolved":
            unreadable[key] = {"key": key, "kind": "vector-unit", "words": v["words"],
                               "first": v["first"], "cite": v["cite"],
                               "why": "the cited instruction table has no row for this function code, so the "
                                      "word is identified as a vector-unit instruction and left unnamed "
                                      "rather than guessed at"}
    for d in dec[foff // 4:]:
        d["status"] = "foreign"
        d["text"] = "%s  [cpu code, %s]" % (d["text"], hex(UCODE_VA + foff))
    return {
        "tool": "rsp_decode.py",
        "schema": SCHEMA,
        "inputs": {
            "image": str(IMAGE.relative_to(ROOT)),
            "base": hex(STAGE2_BASE),
            "cartridge": "not needed: the blob is an unpacked member of stage-2",
            "manual": MANUAL,
            "manual_pages": MANUAL_PAGES,
            "reference": "DragonMinded/libdragon src/audio/rsp_mixer.S (Unlicense) was read as a coverage "
                         "reference for which instruction families a real RSP audio mixer uses (scalar "
                         "loads/stores, LWC2/SWC2 row transfers, COP2 ALU, COP0 clock/DMA moves). It named "
                         "nothing here: no encoding, no DMEM offset and no command opcode comes from it, and it "
                         "is a different, modern design — no byte of this cartridge is evidence about it or "
                         "from it",
        },
        "blob": {
            "addr": hex(UCODE_VA),
            "size": UCODE_SIZE,
            "image_offset": UCODE_VA - STAGE2_BASE,
            "sha256": hashlib.sha256(blob).hexdigest(),
            "entropy": round(entropy(blob), 3),
            "zero_bytes": blob.count(0),
            "bounded_by": [
                "before: the CPU function ending `lw ra,0x10(sp) / jr ra / addiu sp,sp,0x18` at 0x99c74, so "
                "0x99c80 is a function boundary and not the middle of one",
                "after: 0x9ac80 is `nop` then `addiu sp,sp,-0x40` at 0x9ac84, the next CPU function's prologue",
                "the blob's last word is `jr ra` at 0xffc and its delay slot is the first word outside the "
                "declared size — recorded, because that is the one place the declared 0x1000 cuts a pair",
            ],
            "contains_cartridge_bytes": False,
        },
        "decoder": {
            "coverage_rule": (
                "Every word is one of three things. `scalar`: named from the R4000/MIPS III table that p44 and "
                "p47 name for the SU — the manual does not tabulate the encoding, so each such entry is labelled "
                "`family`, not `cited`. `vector`: identified as a COP2 vector-unit instruction with its fields "
                "reported raw, its mnemonic null, and listed in `unreadable`. `unreadable`: named in no document "
                "this repository holds. Nothing is imported from another architecture's table, and no DMEM "
                "offset, SP register or command opcode acquires a name."),
            "scalar_ops": {k: scalar[k] for k in sorted(scalar)},
            "vector_ops": {k: vector[k] for k in sorted(vector)},
            "unreadable": [unreadable[k] for k in sorted(unreadable)],
            "counts": dict(counts, words=len(dec)),
        },
        "vector_census": vector_census(dec, foff),
        "program": prog,
        "identity": identity_section(image, dec, prog, blob, foff),
        "task": task_section(image),
        "rsp_only": rsp_only_section(prog, blob, dec),
        "citations": {k: {"page": v[0], "quote": v[1]} for k, v in sorted(CITES.items())},
        "external_sources": {
            "why": "The local manual tabulates no RSP encoding — it delegates the SU to the R4000 manual by "
                   "name (p44, p47) and says nothing about the vector unit's function codes. M223 therefore "
                   "left all 254 vector words unnamed. M224 narrowed the rule rather than the refusal: an "
                   "external table may be *used as a cited source* — attributed, no text reproduced, every "
                   "consequence re-measured against the cartridge — which is what this project already does "
                   "for OpenBiohazard2 (MIT) and libdragon (Unlicense). See docs/THIRD_PARTY.md 4b.",
            "sources": sorted({(v[0], v[1]) for v in VU_EXT.values()}),
            "licence": "CC BY-SA-4.0 (N64brew Wiki); facts restated, no text reproduced",
            "table_defects": VU_SOURCE_DEFECTS,
        },
    }




# --- checks ---------------------------------------------------------------------------------------------
def check(committed, image):
    """Every claim the manifest makes, re-derived. Returns [(label, ok), ...]; the caller prints them."""
    blob = ucode_blob(image)
    words = [int.from_bytes(blob[i:i + 4], "big") for i in range(0, len(blob), 4)]
    dec = analyses(words)
    fresh = derive(image)
    cases = []

    cases.append((f"the task block's +0x10 field names 0x{UCODE_VA:x}, which resolves to image offset "
                  f"0x{UCODE_VA - STAGE2_BASE:x} and {len(blob)} bytes there",
                  committed["blob"]["image_offset"] == UCODE_VA - STAGE2_BASE and len(blob) == UCODE_SIZE))

    cases.append((f"words × 4 == size ({len(words)} × 4 == {UCODE_SIZE})",
                  len(words) * 4 == committed["blob"]["size"] == UCODE_SIZE))

    cases.append((f"blob sha256 matches the committed record ({committed['blob']['sha256'][:16]}…)",
                  hashlib.sha256(blob).hexdigest() == committed["blob"]["sha256"]
                  == fresh["blob"]["sha256"]))

    cases.append((f"entropy matches ({committed['blob']['entropy']}, {committed['blob']['zero_bytes']} zero bytes)",
                  abs(entropy(blob) - committed["blob"]["entropy"]) < 5e-4
                  and blob.count(0) == committed["blob"]["zero_bytes"]))

    c = committed["decoder"]["counts"]
    cases.append((f"every word is classified: {c['scalar']} scalar + {c['vector']} vector + "
                  f"{c['unreadable']} unreadable + {c['foreign']} CPU = {len(words)}",
                  c["scalar"] + c["vector"] + c["unreadable"] + c["foreign"] == len(words) == c["words"]))

    foff = committed["program"]["foreign"]["offset"]
    corpus = corpus_functions()
    cases.append((f"the window is split where the project's corpus says a CPU function starts "
                  f"(0x{UCODE_VA + foff:x} = {corpus.get(UCODE_VA + foff, 'absent')}), and the split "
                  f"re-derives",
                  foreign_start() == foff == committed["program"]["foreign"]["offset"]
                  and f"{foff // 4}" and committed["program"]["foreign"]["words"] * 4 + foff == UCODE_SIZE
                  and (UCODE_VA + foff) in corpus))

    ops = committed["decoder"]["scalar_ops"]
    # Two sources now, and the artefact has to keep them apart: the manual for the SU's opcodes, the cited
    # wiki table for the 125 `lwc2`/`swc2` transfers, which are SU instructions that address the VU.
    from_manual = {k: v["cite"] for k, v in ops.items() if v["cite"] in CITES}
    from_ext = {k: v["cite"] for k, v in ops.items() if v["cite"] in VU_EXT}
    unresolved_cite = {k: v for k, v in ops.items()
                       if v["cite"] not in CITES and v["cite"] not in VU_EXT}
    cases.append((f"every named scalar encoding cites a source, and the manual and the external table are "
                  f"kept apart ({len(from_manual)} ops from the manual, "
                  f"{sum(ops[k]['words'] for k in from_ext)} words from {len(set(from_ext.values()))} "
                  f"external row cite(s), {len(unresolved_cite)} uncited)",
                  not unresolved_cite
                  and all(0 < CITES[v][0] <= MANUAL_PAGES for v in from_manual.values())
                  and all(VU_EXT[c][0].startswith("https://") for c in from_ext.values())))

    vops = committed["decoder"]["vector_ops"]
    ext = [v for v in vops.values() if v["status"] == "cited-external"]
    ext_cite = {v["cite"] for v in ext}
    cases.append((f"every named vector encoding cites an external source that is recorded as one "
                  f"({sum(v['words'] for v in ext)} words, citations {sorted(ext_cite)})",
                  ext_cite and ext_cite <= set(VU_EXT)
                  and all(VU_EXT[c][0].startswith("https://") and VU_EXT[c][1] > 0 for c in ext_cite)
                  and all(v["mnemonic"] for v in ext)))

    # --- M225: the naming has to re-derive from the words, not from the strings it wrote
    rsp = dec[:committed["program"]["foreign"]["offset"] // 4]
    bad_row, bad_off, bad_name = [], [], []
    for d in rsp:
        if d.get("vector_kind") != "vector_transfer":
            continue
        w = d["word"]
        row, off = bits(w, 15, 11), bits(w, 6, 0)
        if d["mnemonic"] != (VU_ROWS.get(row) or VU_ROWS_UNSCALED.get(row))[0 if bits(w, 31, 26) == 0x32 else 1]:
            bad_name.append(d["at"])
        if d["vu_offset"] != off or d["vu_row_opcode"] != row:
            bad_off.append(d["at"])
        # stated here independently of VU_ROWS, so a table edit cannot agree with itself
        scale = CITED_ACCESS_SIZE.get((bits(w, 31, 26), row))
        if d["vu_scale"] != scale or d["dmem_vector_offset"] != (off * scale if scale else None):
            bad_row.append(d["at"])
    cases.append((f"every vector transfer's row, offset and scaled address re-derive from bits 15:11, 6:0 "
                  f"and the row's access size "
                  f"({sum(1 for d in rsp if d.get('vector_kind') == 'vector_transfer')} transfers, "
                  f"{len(bad_name)} wrong name, {len(bad_off)} wrong offset, {len(bad_row)} wrong scale)",
                  not bad_name and not bad_off and not bad_row))

    lanes = [d for d in rsp if d.get("vector_kind") == "single"]
    lane_bad = []
    for d in lanes:
        w = d["word"]
        vt_elem, vd_elem = bits(w, 24, 21), bits(w, 10, 6)
        msb = vt_elem.bit_length() - 1
        se = ((((vd_elem >> msb) << msb) | (vt_elem & ((1 << msb) - 1))) & 7) if msb > 0 else vt_elem & 7
        if d["vu"]["source_lane"] != se or d["vu"]["dest_lane"] != (vd_elem & 7):
            lane_bad.append(d["at"])
        if d["vu"]["vd"] != bits(w, 15, 11):
            lane_bad.append(d["at"])
    # The borrow branch only changes the answer when vt_elem's top set bit is at or below lane 2. Measured:
    # this program's eight single-lane words all carry vt_elem = 12, so the branch is implemented from the
    # cited pseudo-code and *no word here exercises it* -- the gate cannot prove it, and says so.
    borrow = [d["at"] for d in lanes if bits(d["word"], 24, 21).bit_length() - 1 <= 2]
    cases.append((f"every single-lane word's lanes re-derive from the cited rule ({len(lanes)} words, "
                  f"{len(lane_bad)} wrong); the borrow branch is implemented but exercised by "
                  f"{len(borrow)} of them, so the gate does not prove it",
                  lanes and not lane_bad and len(borrow) == 0
                  and all(bits(d["word"], 24, 21) == 12 for d in lanes)))

    cen = committed["vector_census"]
    vc = committed["decoder"]["counts"]
    by_kind = sum(cen["by_kind"].values())
    moves = sum(cen["by_su_vu_move"].values())
    refused = sum(v["words"] for v in vops.values() if v["status"] == "unresolved")
    cases.append((f"the arithmetic census adds up: every vector word is either counted by kind, a SU/VU "
                  f"move, or a transfer, and the refused ones are the remainder "
                  f"({by_kind} by kind + {moves} moves + {refused} refused = {vc['vector']})",
                  by_kind + moves + refused == vc["vector"]
                  and sum(cen["by_transfer_row"].values())
                  == sum(1 for d in rsp if d.get("vector_kind") == "vector_transfer")
                  and sum(cen["by_fixed_point_format"].values())
                  <= cen["by_kind"].get("multiply", 0) + cen["by_kind"].get("multiply-accumulate", 0)))

    unre = committed["decoder"]["unreadable"]
    totale = sum(u["words"] for u in unre)
    named = sum(v["words"] for v in vops.values() if v["status"] == "cited-external")
    cases.append((f"every vector word is either named from the table or listed with its reason "
                  f"({named} named + {totale} refused = {c['vector']} vector words, "
                  f"{c['unreadable']} unreadable outside the vector unit)",
                  named + totale == c["vector"] and c["unreadable"] == 0
                  and totale > 0  # the table has a gap; a run where it does not must be looked at
                  and all(u.get("why") and u.get("key") and isinstance(u["first"], int) for u in unre)))

    je = committed["program"]["jump_encoding"]
    cases.append((f"call and jump targets are inside the program under the 12-bit IMEM rule "
                  f"({je['count']} fields, raw {je['raw_first']}..{je['raw_last']}, "
                  f"{je['raw_pages']} page(s), {je['raw_outside_imem']} raw targets outside a 4 KB IMEM, "
                  f"{je['masked_inside']} masked targets inside)",
                  je["raw_outside_imem"] == je["count"] == je["masked_inside"] and je["raw_pages"] == 1))

    funcs = committed["program"]["functions"]
    covered = sum(f["instructions"] for f in funcs) + sum(g["words"] for g in committed["program"]["gaps"])
    cases.append((f"function bodies plus listed gaps account for every RSP word "
                  f"({len(funcs)} functions, {covered} words == {committed['program']['rsp_words']})",
                  covered == committed["program"]["rsp_words"]))

    starts = [f["entry"] for f in funcs]
    cases.append(("no two function bodies overlap and every body starts at a root",
                  len({f["entry"] for f in funcs}) == len(funcs)
                  and all(f["end"] > f["entry"] for f in funcs)
                  and sorted(starts) == starts
                  and all(b["entry"] >= a["end"] for a, b in zip(funcs, funcs[1:]))))

    entry_ok = funcs[0]["entry"] == 0 and committed["program"]["entry"] == 0
    jal_roots = {d["jump_target"] for d in dec if d["mnemonic"] == "jal"}
    cases.append((f"the entry is IMEM 0 and the {len(jal_roots)} jal targets are exactly the other roots",
                  entry_ok and set(starts[1:]) == jal_roots))

    tf = committed["task"]["fields"]
    sites_ok, fold_ok = True, True
    for f in tf:
        want = TASK_BLOCK + f["offset"]
        try:
            have = int(f["block_address"], 16)
        except (TypeError, ValueError):
            have = None
        sites_ok &= have == want
        src = source_of(image, int(f["writer"].split()[0], 16),
                        bits(word_at(image, int(f["writer"].split()[0], 16)), 20, 16))
        fold_ok &= (src["kind"] == f["value_kind"]) and (
            src["value"] is None or src["value"] == f["value"])
    cases.append((f"all {len(tf)} task fields re-fold: each writer stores to 0x{TASK_BLOCK:x}+offset and each "
                  f"value re-derives", sites_ok))
    cases.append(("every task field's value is either a folded constant that re-derives or a load that is "
                  "recorded as a load", fold_ok))

    pair = [f for f in tf if f["offset"] == 0x10][0]
    literal = image.count(UCODE_VA.to_bytes(4, "big"))
    cases.append((f"the ucode pointer is a lui+addiu fold ({pair['value']:#x}) and the literal 0x{UCODE_VA:x} "
                  f"appears {literal} times in stage-2",
                  pair["value"] == UCODE_VA and literal == 0
                  and all("lui" in t for t in pair["value_trace"][:1])))

    ident = committed["identity"]
    cases.append((f"the identity verdict is one of the allowed words ({ident['verdict']}) and every candidate "
                  f"carries what would confirm or refute it",
                  ident["verdict"] in ("aspMain", "musyx", "unresolved")
                  and len(ident["candidates"]) >= 2
                  and all(x.get("verdict") and x.get("would_predict") and x.get("against")
                          for x in ident["candidates"])
                  and all(e.get("measurement") and e.get("reading") for e in ident["evidence"])))

    cases.append((f"every rsp_only entry says what is out of reach and why ({len(committed['rsp_only'])} entries)",
                  all(r.get("what") and r.get("why") and r.get("cpu_evidence")
                      for r in committed["rsp_only"])))

    committed_s = json.dumps(committed, sort_keys=True)
    fresh_s = json.dumps(fresh, sort_keys=True)
    cases.append(("the committed manifest equals a fresh derivation of the image", committed_s == fresh_s))
    return cases


def disasm(image, first=0, last=None):
    blob = ucode_blob(image)
    words = [int.from_bytes(blob[i:i + 4], "big") for i in range(0, len(blob), 4)]
    for i, w in enumerate(words):
        if i * 4 < first or (last is not None and i * 4 >= last):
            continue
        d = decode(w, i * 4)
        print("%04x  %08x  %-34s %s" % (i * 4, w, d["text"], "" if d["status"] != "unreadable"
                                        else "[unreadable]" if d["status"] == "unreadable" else ""))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--disasm", action="store_true")
    ap.add_argument("--first", type=lambda s: int(s, 0), default=0)
    ap.add_argument("--last", type=lambda s: int(s, 0), default=None)
    a = ap.parse_args()

    image = stage2()
    if a.write:
        if image is None:
            print("REFUSED: %s is not present, so there is nothing to decode" % IMAGE.relative_to(ROOT))
            return 2
        rep = derive(image)
        (ROOT / OUT).write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        c = rep["decoder"]["counts"]
        named = sum(v["words"] for v in rep["decoder"]["vector_ops"].values()
                    if v["status"] == "cited-external")
        print("wrote %s — %d words: %d RSP (%d scalar, %d vector of which %d named / %d refused, "
              "%d unreadable) + %d CPU; %d functions, %d gaps; identity %s"
              % (OUT, c["words"], rep["program"]["rsp_words"], c["scalar"], c["vector"], named,
                 c["vector"] - named, c["unreadable"], c["foreign"],
                 len(rep["program"]["functions"]), len(rep["program"]["gaps"]),
                 rep["identity"]["verdict"]))
        return 0

    if a.disasm:
        if image is None:
            print("SKIP (needs the unpacked stage-2 image)")
            return 0
        disasm(image, a.first, a.last)
        return 0

    if not a.check:
        ap.error("one of --write, --check, --disasm is required")

    if image is None:
        print("SKIP (needs the unpacked stage-2 image: %s)" % IMAGE.relative_to(ROOT))
        return 0

    committed = json.loads((ROOT / OUT).read_text())
    cases = check(committed, image)
    bad = 0
    for label, ok in cases:
        bad += not ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d rsp case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
