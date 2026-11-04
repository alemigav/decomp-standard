#!/usr/bin/env python3
"""The MIPS-side voice descriptor: what the voice path writes, and the command it hands the audio engine.

The codec is settled (M221: 588 clips, 12 037 live blocks, 0 samples differing), so the open half of the
voice path is the one that reaches the mixer. That half is deliberately *not* traced past the microcode.
What this tool maps is the structure the CPU owns:

    base 0x80158b20, stride 0x1228, two slots, ending exactly on the sound system's first global

Each slot is a descriptor plus a 4 KiB DMA ring. `FUN_800b3704` claims a free slot and fills the interface
fields; `FUN_800b4930` zeroes the 0x190-byte state block, installs the ring source/buffer/size and the DMA
callback, and starts the reader; `FUN_800b4a04` pumps one pass (fetch a 0x400-byte chunk, synthesise up to
two 160-sample blocks); `FUN_800b53f4` reads the ring; `func_800b3b9c` runs both slots per frame and starts
or stops the engine voice. The command the CPU hands the engine is `FUN_800a924c`'s argument block, which
lands in a 0x68-byte engine voice record and a 0x18-byte handle record, and the audio task at 0x80143c60
carries the whole per-frame command list to the RSP.

Three things are kept apart on purpose, because conflating them is the mistake this file exists to avoid:

  * **the descriptor** — every field below is written or read by a MIPS instruction that this tool decodes
    out of the cartridge at a stated address, and cited to the `src/` statement that does it. A field whose
    writer cannot be produced this way would be `confidence: "unresolved"`, and none is.
  * **the ring/DMA state** — the same structure's second half: a 4 KiB object at +0x1a0 with 0x400-byte
    chunks and the cursors that keep the fetch and the read from colliding. `+0x1a4` and `+0x1a8` are *not*
    stream state: they are the first chunk's MORT header, read once through the ring.
  * **rsp_only** — the mixer. Its per-voice command record is written here (FUN_800a3bf4) but read only by
    the microcode, whose 0x1000-byte blob sits at 0x800b2700 with no function in the corpus covering it and
    no RSP disassembly anywhere in this repository. So this tool names no field of it and asserts no
    behaviour of it. `rsp_only` says what is out of reach and why.

The rate is the one hop that is *not* traced, and it is published as unresolved rather than smoothed: nothing
reads the MORT header's rate halfword at ring+6 (checked here by scanning every instruction of the stage-2
image for that displacement), so the descriptor's rate arrives as `FUN_800b3704`'s argument. For clip 0 the two
agree at 16 000 Hz because the default is 16 000 Hz, and agreement is not provenance.

Usage:
  ./voice_descriptor.py --write   # regenerate manifests/voice_descriptor.json from the cartridge
  ./voice_descriptor.py --check   # validate the committed artefact against a fresh derivation
"""
import argparse
import hashlib
import json
import re
import struct
import sys
import zlib
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

ROM = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
OUT = Path("manifests") / "voice_descriptor.json"

# The stage-2 member (file id 0), as the cartridge stores it: the code the voice path lives in.
STAGE2_OFF, STAGE2_LEN, STAGE2_BASE = 0x14420, 1172240, 0x80018A80   # member 0: 0x11e2d0 B

# The descriptor table. `_DAT_8015af70` is the next global after the second slot (FUN_800b3640.c:27), which
# is what fixes the slot count at two rather than the loop bound alone.
SLOT_BASE, SLOT_STRIDE, SLOT_COUNT, SLOT_END = 0x80158B20, 0x1228, 2, 0x8015AF70
RING_OFF, RING_SIZE, CHUNK, FETCH_MASK, READ_MASK = 0x1A0, 0x1000, 0x400, 0xFF8, 0xFFC
STATE_OFF = 0x11A0                    # the post-ring state begins exactly where the ring ends

# The command side: engine voice record, handle record, and the task block that carries the list to the RSP.
ENGINE_BASE, ENGINE_STRIDE = 0x80143F0C, 0x68
HANDLE_BASE, HANDLE_STRIDE = 0x801481E0, 0x18
TASK_BASE = 0x80143C60
LIST_BASE = 0x80143F50
UCODE_BLOB = 0x800B2700

# The voice bank (file 1979): 588 MORT records, offsets in the low 24 bits of a per-clip word.
BANK_CART, BANK_SIZE = 0x0338FEA, 8560916
MORT_HEADER = 12                      # magic 4 + blocks 2 + rate 2 + words 4
BLOCK_SAMPLES = 160

OUTPUT_WORDS = ("microcode", "ucode", "rsp", "mixer", "envelope", "ramp", "saturat", "dither", "adpcm",
                "reverb", "per-sample")

CITE = re.compile(r"^(src/[A-Za-z0-9_./-]+):(\d+): (.+)$")
DECOMPOSED = re.compile(r"-0x[0-9a-fA-F]{8}")
GLOBAL = re.compile(r"_[Dd][Aa][Tt]_([0-9a-fA-F]{8})")
ARITH = re.compile(r"^arith: (.+?) @ (src/.*)$")


class Unplaceable(Exception):
    pass


# --- the cartridge, and the stage-2 words ---------------------------------------------------------------
_stage2_cache = {}


def stage2():
    """The stage-2 image, inflated from the cartridge: a CMF-0x68 zlib member, not a raw slice."""
    if "b" not in _stage2_cache:
        rom = ROM.read_bytes()
        _stage2_cache["rom"] = rom
        stream = zlib.decompressobj()
        out = stream.decompress(rom[STAGE2_OFF:]) + stream.flush()
        if len(out) != STAGE2_LEN:
            raise Unplaceable("the member at %#x inflates to %d bytes, not %d"
                              % (STAGE2_OFF, len(out), STAGE2_LEN))
        _stage2_cache["b"] = out
    return _stage2_cache["b"]


def rom_bytes():
    stage2()
    return _stage2_cache["rom"]


def word(addr):
    blob = stage2()
    off = addr - STAGE2_BASE
    if not 0 <= off <= len(blob) - 4:
        raise Unplaceable("0x%08x is outside the stage-2 member" % addr)
    return struct.unpack_from(">I", blob, off)[0]


LOAD_STORE = {0x20: ("lb", 1), 0x21: ("lh", 2), 0x23: ("lw", 4), 0x24: ("lbu", 1), 0x25: ("lhu", 2),
              0x28: ("sb", 1), 0x29: ("sh", 2), 0x2B: ("sw", 4), 0x31: ("lwc1", 4), 0x35: ("ldc1", 8),
              0x39: ("swc1", 4), 0x3D: ("sdc1", 8), 0x09: ("addiu", None), 0x0D: ("ori", None)}


def decode(addr):
    """-> (mnemonic, signed immediate, width) for the instruction at `addr`. Only the forms the map needs."""
    w = word(addr)
    op = w >> 26
    if op not in LOAD_STORE:
        raise Unplaceable("0x%08x is opcode 0x%02x, not a load/store/add-immediate" % (addr, op))
    mnem, width = LOAD_STORE[op]
    imm = w & 0xFFFF
    return mnem, imm - 0x10000 if imm & 0x8000 else imm, width


def _by_offset(rows):
    return sorted(rows, key=lambda f: f["offset"])


def hexstr(value):
    return "0x%x" % value


def addr(value):
    """An address, however it is spelled: the artefact stores them as hex strings, JSON having no hex."""
    return int(value, 16) if isinstance(value, str) else int(value)


def offset_of(addr):
    """The field offset an instruction pins: its immediate, whatever the register base was called."""
    return decode(addr)[1]


# --- citations -------------------------------------------------------------------------------------------
def _norm(text):
    return " ".join(text.split())


def cite_line(citation):
    """-> (path, line number, statement) or raise. The form is `src/...#<line>: <statement>`."""
    m = CITE.match(citation)
    if not m:
        raise Unplaceable("not a src/ citation: %r" % citation)
    return m.group(1), int(m.group(2)), m.group(3)


def cite_source(citation):
    """-> the text of the source line a citation names, or raise if it does not resolve."""
    path, line, statement = cite_line(citation)
    target = ROOT / path
    if not target.exists():
        raise Unplaceable("%s does not exist" % path)
    lines = target.read_text(encoding="utf-8", errors="replace").splitlines()
    if not 1 <= line <= len(lines):
        raise Unplaceable("%s has %d lines, so %d is out of range" % (path, len(lines), line))
    text = lines[line - 1]
    if _norm(statement) not in _norm(text):
        raise Unplaceable("%s:%d does not contain %r" % (path, line, statement))
    return text


def names_offset(citation, offset):
    """Does the cited statement name this field offset, in either spelling the decompiler uses?

    `0x11a4` and `4516` are the direct spellings. The third is the one the slot code forces: with the base
    held in `iVar3`, `iVar3 + -0x7fea62cc` *is* `slot + 0x1214`, because the base is 0x80158b20.
    """
    text = cite_source(citation)
    if "0x%x" % offset in text.lower() or re.search(r"\b%d\b" % offset, text):
        return True
    for token in DECOMPOSED.findall(text):
        if (0x100000000 + int(token, 16)) - SLOT_BASE == offset:
            return True
    for token in GLOBAL.findall(text):
        address = int(token, 16)
        if address - SLOT_BASE == offset or address - TASK_BASE == offset:
            return True
    return False


def source_paths(citations):
    return sorted({cite_line(c)[0] for c in citations})


# --- the map ---------------------------------------------------------------------------------------------
def field(name, width, meaning, writers, readers=(), insn=None, offset=None, confidence="established"):
    """One field. The offset comes from the writer's own instruction wherever an instruction exists."""
    for c in list(writers) + list(readers):
        cite_source(c)
    if insn is not None:
        mnem, imm, insn_width = decode(insn)
        if offset is not None and imm != offset:
            raise Unplaceable("0x%08x writes +0x%x, not +0x%x" % (insn, imm, offset))
        if insn_width is not None and insn_width != width:
            raise Unplaceable("0x%08x is a %d-byte store but the field is %d" % (insn, insn_width, width))
        offset = imm
        pin = "instruction 0x%08x (%s)" % (insn, mnem)
    else:
        if offset is None:
            raise Unplaceable("%s: no instruction and no offset" % name)
        if not any(names_offset(c, offset) for c in writers):
            raise Unplaceable("%s: no writer statement names +0x%x" % (name, offset))
        pin = "cited statement"
    return {"offset": offset, "width": width, "name": name, "meaning": meaning,
            "writer": list(writers), "reader": list(readers),
            "evidence": pin, "confidence": confidence}


def descriptor_fields():
    """The two 0x1228-byte slots at 0x80158b20: codec state, stream state, and the start parameters."""
    B = "src/stage2/"
    return [
        # --- codec-private state, inside the 0x190 bytes FUN_800b4930 memsets --------------------------
        field("predictor_period", 2,
              "the long-term predictor's period in samples: initialised to 40, and re-latched from the "
              "incoming value only while it lies in 40..120 (a value outside is ignored, not clamped)",
              writers=[B + "FUN_800b4930.c:13: *(undefined2 *)(param_1 + 0x166) = 0x28;",
                       B + "FUN_800b63b4.c:24: param_1[0xb3] = (short)iVar6;"],
              readers=[B + "FUN_800b63b4.c:20: iVar6 = (int)(short)param_1[0xb3];"],
              insn=0x800B63D4),
        field("coefficient_banks", 0x20,
              "two 16-byte banks of eight dequantised coefficients; the reader selects one per call with "
              "+0x188, so 0x168 and 0x178 are one field with an index, not two",
              writers=[B + "FUN_800b4dc0.c:18: puVar4 = (undefined2 *)(param_1 + *(short *)(param_1 + 0x188) "
                          "* 0x10 + 0x168);"],
              readers=[B + "FUN_800b4dc0.c:18: puVar4 = (undefined2 *)(param_1 + *(short *)(param_1 + 0x188) "
                          "* 0x10 + 0x168);"],
              offset=0x168),
        field("bank_select", 2,
              "which of the two coefficient banks the next block reads; flipped after the mix, not before",
              writers=[B + "FUN_800b4dc0.c:34: *(ushort *)(param_1 + 0x188) = *(ushort *)(param_1 + 0x188) ^ 1;"],
              readers=[B + "FUN_800b4dc0.c:18: puVar4 = (undefined2 *)(param_1 + *(short *)(param_1 + 0x188) "
                          "* 0x10 + 0x168);"],
              offset=0x188),
        field("reader_cursor_a", 2,
              "one of the bit reader's two run-length cursors: decremented per code and reloaded when it "
              "reaches zero, at which point the other cursor is loaded (0x800b53f4's field map, M198)",
              writers=[B + "FUN_800b53f4.c:94: *(ushort *)(param_1 + 0x18a) = uVar5;",
                       B + "FUN_800b53f4.c:591: *(short *)(param_1 + 0x18a) = *(short *)(param_1 + 0x18a) + -1;"],
              readers=[B + "FUN_800b53f4.c:72: if (*(short *)(param_1 + 0x18a) == 0) {"],
              offset=0x18A),
        field("reader_cursor_b", 2,
              "the bit reader's second run-length cursor; same reload rule as +0x18a",
              writers=[B + "FUN_800b53f4.c:114: *(ushort *)(param_1 + 0x18c) = uVar5;",
                       B + "FUN_800b53f4.c:612: *(short *)(param_1 + 0x18c) = *(short *)(param_1 + 0x18c) + -1;"],
              readers=[B + "FUN_800b53f4.c:73: if (*(short *)(param_1 + 0x18c) == 0) {"],
              offset=0x18C),

        # --- the reader's interface: what the stream was told to consume --------------------------------
        field("dma_callback", 4,
              "the transfer routine the reader calls to fill the ring; FUN_800b44f4, which hands the bytes "
              "to FUN_800b4818 and posts the queue message",
              writers=[B + "FUN_800b4930.c:18: *(int *)(param_1 + 400) = param_5;"],
              readers=[B + "FUN_800b4a04.c:54: (**(code **)(param_1 + 400))"],
              insn=0x800B4990),
        field("source_rom", 4,
              "the record's address in the cartridge: the bank base (0x8015af78) plus the per-clip offset's "
              "low 24 bits, computed by the caller",
              writers=[B + "FUN_800b4930.c:14: *(int *)(param_1 + 0x194) = param_2;"],
              readers=[B + "FUN_800b4a04.c:55: (*(int *)(param_1 + 0x194) + *(uint *)(param_1 + 0x11d0),"],
              insn=0x800B497C),
        field("pcm_buffer", 4,
              "the PCM destination: 4320 16-bit samples for 16 kHz, either a heap block sized by "
              "FUN_800a9420 or one of the two static buffers at 0x8015af88",
              writers=[B + "FUN_800b4930.c:15: *(undefined4 *)(param_1 + 0x198) = param_3;"],
              readers=[B + "FUN_800b4a04.c:70: FUN_800b53f4(param_1,*(int *)(param_1 + 0x198) +"],
              insn=0x800B4980),
        field("pcm_units", 4,
              "that buffer's capacity in 16-bit units, and simultaneously the ring-of-PCM length the "
              "engine voice is told: the synthesis wraps at it and the engine drains against it",
              writers=[B + "FUN_800b4930.c:16: *(undefined4 *)(param_1 + 0x19c) = param_4;"],
              readers=[B + "FUN_800b4a04.c:71: (*(uint *)(param_1 + 0x11d8) % *(uint *)(param_1 + 0x19c) >> 2) * 8);"],
              insn=0x800B4984),

        # --- stream state, after the ring --------------------------------------------------------------
        field("blocks_remaining", 2,
              "blocks the record still declares, seeded from the header's +4 halfword and decremented per "
              "synthesised block; zero stops synthesis unless the stream is still fetching",
              writers=[B + "FUN_800b4930.c:29: *(undefined2 *)(param_1 + 0x11a0) = 0;",
                       B + "FUN_800b4a04.c:25: *(undefined2 *)(param_1 + 0x11a0) = *(undefined2 *)(param_1 + 0x1a4);",
                       B + "FUN_800b4a04.c:73: *(short *)(param_1 + 0x11a0) = sVar3;"],
              readers=[B + "FUN_800b4a04.c:63: if ((((*(char *)(param_1 + 0x11dd) != '\\x01') && "
                          "(*(short *)(param_1 + 0x11a0) == 0)) ||",
                       B + "func_800b3b9c.c:43: *(float *)(iVar3 + 0x1220) = "
                          "((float)*(ushort *)(iVar3 + 0x11a0) * 160.0) / fVar5;"],
              insn=0x800B49C4),
        field("header_blocks_echo", 2,
              "written from the same header halfword as +0x11a0, in the same few instructions, and read "
              "by nothing in the corpus: kept here as an unexplained write rather than explained away",
              writers=[B + "FUN_800b4930.c:27: *(undefined2 *)(param_1 + 0x11a2) = 0;",
                       B + "FUN_800b4a04.c:26: *(short *)(param_1 + 0x11a2) = (short)*(undefined4 *)(param_1 + 0x1a4);"],
              insn=0x800B49BC, confidence="writer only"),
        field("record_words_remaining", 4,
              "the record's declared length in WORDS, from the header's +8 word masked to 24 bits: "
              "decremented by 0x100 per 0x400-byte chunk, and below 0x101 it becomes the tail chunk's "
              "size in words times four",
              writers=[B + "FUN_800b4930.c:28: *(undefined4 *)(param_1 + 0x11a4) = 0;",
                       B + "FUN_800b4a04.c:27: *(uint *)(param_1 + 0x11a4) = *(uint *)(param_1 + 0x1a8) & 0xffffff;",
                       B + "FUN_800b4a04.c:35: *(uint *)(param_1 + 0x11a4) = *(uint *)(param_1 + 0x11a4) - 0x100;"],
              readers=[B + "FUN_800b4a04.c:49: iVar1 = *(uint *)(param_1 + 0x11a4) << 2;"],
              insn=0x800B49C0),
        field("drain_budget", 4,
              "the PCM still owed to the engine once the last block is written: set to the capacity, "
              "reduced by what the engine pulls, and reaching zero it makes the stream state 4",
              writers=[B + "FUN_800b4930.c:17: *(undefined4 *)(param_1 + 0x11a8) = 0;",
                       B + "FUN_800b4a04.c:77: *(undefined4 *)(param_1 + 0x11a8) = *(undefined4 *)(param_1 + 0x19c);",
                       B + "FUN_800b4d30.c:18: if ((0 < *(int *)(param_1 + 0x11a8)) && "
                          "(*(int *)(param_1 + 0x11a8) = iVar2, iVar2 < 1)) {"],
              readers=[B + "FUN_800b4d30.c:17: iVar2 = *(int *)(param_1 + 0x11a8) - param_2;"],
              insn=0x800B4988),
        field("dma_queue", 24,
              "the OSMesgQueue the reader blocks on while a chunk is in flight; osCreateMesgQueue is "
              "given 0x11ac as the queue and 0x11c4 as the message array, so the 24-byte object ends "
              "exactly where the message begins",
              writers=[B + "FUN_800b4930.c:19: osCreateMesgQueue(param_1 + 0x11ac,param_1 + 0x11c4,1);"],
              readers=[B + "FUN_800b4a04.c:20: iVar1 = osRecvMesg(param_1 + 0x11ac,0,0);"],
              insn=0x800B4968),
        field("dma_message", 4,
              "the one-message array beside that queue: the transfer routine posts to it and the reader "
              "only ever asks whether a message arrived, never what it says, so no instruction reads the "
              "value itself",
              writers=[B + "FUN_800b4930.c:19: osCreateMesgQueue(param_1 + 0x11ac,param_1 + 0x11c4,1);"],
              insn=0x800B496C, confidence="writer only"),
        field("bit_cursor", 4,
              "the codec's bit position inside the ring, in bits; seeded to 96 so the reader starts after "
              "the 12-byte header, and advanced by the synthesis",
              writers=[B + "FUN_800b4930.c:30: *(undefined4 *)(param_1 + 0x11c8) = 0;",
                       B + "FUN_800b4a04.c:24: *(undefined4 *)(param_1 + 0x11c8) = 0x60;"],
              readers=[B + "FUN_800b53f4.c:67: uVar14 = *(uint *)(param_1 + 0x11c8);"],
              insn=0x800B49C8),
        field("ring_consumed", 4,
              "the bit cursor rounded down to a 4-byte boundary; the reader's low-water mark, which "
              "decides whether another chunk may land in the ring",
              writers=[B + "FUN_800b4930.c:32: *(undefined4 *)(param_1 + 0x11cc) = 0;",
                       B + "FUN_800b4a04.c:74: *(uint *)(param_1 + 0x11cc) = *(uint *)(param_1 + 0x11c8) >> 3 "
                          "& 0xfffffffc;"],
              readers=[B + "FUN_800b4a04.c:42: ((uint)(*(int *)(param_1 + 0x11d0) - *(int *)(param_1 + 0x11cc)) < 0xc01)) {"],
              insn=0x800B49D0),
        field("rom_offset", 4,
              "bytes fetched from the record so far; it is also the ring window, because the destination "
              "is (rom_offset & 0xff8) + 0x1a0, and it is what the tail-chunk test keys off",
              writers=[B + "FUN_800b4930.c:31: *(undefined4 *)(param_1 + 0x11d0) = 0;",
                       B + "FUN_800b4a04.c:30: *(int *)(param_1 + 0x11d0) = iVar1 + 0x400;"],
              readers=[B + "FUN_800b4a04.c:43: if (*(int *)(param_1 + 0x11d0) == 0) {"],
              insn=0x800B49CC),
        field("units_delivered", 4,
              "PCM units the engine has pulled; the engine's refill callback advances it, so it is the "
              "engine's read position, not a count of work done",
              writers=[B + "FUN_800b4930.c:34: *(undefined4 *)(param_1 + 0x11d4) = 0;",
                       B + "FUN_800b4d30.c:26: *(uint *)(param_1 + 0x11d4) = *(int *)(param_1 + 0x11d4) + uVar1;"],
              readers=[B + "FUN_800b4a04.c:60: if ((uint)(*(int *)(param_1 + 0x11d8) - *(int *)(param_1 + 0x11d4)) <"],
              insn=0x800B49D8),
        field("units_written", 4,
              "PCM units synthesised, +160 per block with no bound other than the pass budget; the "
              "difference from +0x11d4 is what the engine still has to chew",
              writers=[B + "FUN_800b4930.c:33: *(undefined4 *)(param_1 + 0x11d8) = 0;",
                       B + "FUN_800b4a04.c:75: *(int *)(param_1 + 0x11d8) = *(int *)(param_1 + 0x11d8) + 0xa0;"],
              readers=[B + "FUN_800b4a04.c:71: (*(uint *)(param_1 + 0x11d8) % *(uint *)(param_1 + 0x19c) >> 2) * 8);"],
              insn=0x800B49D4),
        field("dma_in_flight", 1,
              "set when a transfer is issued and cleared when its message arrives; while it is set the "
              "reader skips issuing another",
              writers=[B + "FUN_800b4930.c:26: *(undefined1 *)(param_1 + 0x11dc) = 0;",
                       B + "FUN_800b4a04.c:53: *(undefined1 *)(param_1 + 0x11dc) = 1;"],
              readers=[B + "FUN_800b4a04.c:19: if (*(char *)(param_1 + 0x11dc) != '\\0') {"],
              insn=0x800B49B8),
        field("stream_state", 1,
              "the reader's phase: 0 idle, 1 armed (a source and a callback exist), 2 primed (the engine "
              "voice is live and the PCM has been consumed once), 3 draining, 4 done. Only 3 accepts "
              "pulls from the callback (FUN_800b4d30.c:16), so a chunk is never handed over before its "
              "PCM exists",
              writers=[B + "FUN_800b4930.c:24: *(undefined1 *)(param_1 + 0x11dd) = 1;",
                       B + "FUN_800b4a04.c:102: *(undefined1 *)(param_1 + 0x11dd) = 2;",
                       B + "FUN_800b4d90.c:13: *(undefined1 *)(param_1 + 0x11dd) = 3;",
                       B + "FUN_800b4d30.c:19: *(undefined1 *)(param_1 + 0x11dd) = 4;",
                       B + "FUN_800b4dac.c:12: *(undefined1 *)(param_1 + 0x11dd) = 4;"],
              readers=[B + "FUN_800b4a04.c:41: if (((*(byte *)(param_1 + 0x11dd) - 1 < 2) || "
                          "(*(byte *)(param_1 + 0x11dd) == 3)) &&"],
              insn=0x800B49B0),
        field("pass_budget", 1,
              "how many 160-sample blocks this pass may synthesise; FUN_800b4a04 copies it into a local "
              "and decrements that, so the field itself stays 2 for the stream's life",
              writers=[B + "FUN_800b4930.c:35: *(undefined1 *)(param_1 + 0x11de) = 2;"],
              readers=[B + "FUN_800b4a04.c:18: uVar5 = (uint)*(byte *)(param_1 + 0x11de);"],
              insn=0x800B49DC),

        # --- the start parameters: what the voice path was asked for, and where it went ----------------
        field("slot_state", 1,
              "the slot's own state, and the only thing the allocator scans for: 0 free, 1 started and "
              "waiting for the engine, 2 playing, 3 finishing. Written 1 by the starter and 2 by the "
              "frame thread when the stream reaches 2",
              writers=[B + "FUN_800b3704.c:62: (&DAT_80159d20)[iVar3] = 1;",
                       B + "func_800b3b9c.c:45: *(undefined1 *)(iVar3 + 0x1200) = 2;",
                       B + "FUN_800b40c4.c:29: *(undefined1 *)(iVar3 + 0x1200) = 0;"],
              readers=[B + "FUN_800b3704.c:25: if (*(char *)(iVar3 + 0x1200) == '\\0') break;"],
              insn=0x800B393C),
        field("param_a", 1,
              "the first of four parameters the caller passes straight through to the engine voice "
              "start; not interpreted anywhere on the MIPS side",
              writers=[B + "FUN_800b3704.c:37: *(undefined1 *)(iVar3 + -0x7fea62df) = param_4;"],
              readers=[B + "func_800b3b9c.c:49: *(undefined1 *)(iVar3 + 0x1201),*(undefined1 *)(iVar3 + 0x1202),"],
              insn=0x800B3824),
        field("param_b", 1,
              "the second passed-through parameter; live-updatable through func_800b3a68",
              writers=[B + "FUN_800b3704.c:38: *(undefined1 *)(iVar3 + -0x7fea62de) = param_5;"],
              readers=[B + "func_800b3b9c.c:49: *(undefined1 *)(iVar3 + 0x1201),*(undefined1 *)(iVar3 + 0x1202),"],
              insn=0x800B3828),
        field("param_c", 1,
              "the third passed-through parameter",
              writers=[B + "FUN_800b3704.c:39: *(undefined1 *)(iVar3 + -0x7fea62dd) = param_6;"],
              readers=[B + "func_800b3b9c.c:50: *(undefined1 *)(iVar3 + 0x1203),*(undefined1 *)(iVar3 + 0x1219),"],
              insn=0x800B382C),
        field("param_d", 1,
              "the fourth passed-through parameter: a different byte, same forward-only role",
              writers=[B + "FUN_800b3704.c:40: *(undefined1 *)(iVar3 + -0x7fea62c7) = param_7;"],
              readers=[B + "func_800b3b9c.c:50: *(undefined1 *)(iVar3 + 0x1203),*(undefined1 *)(iVar3 + 0x1219),"],
              insn=0x800B3830),
        field("engine_key", 1,
              "the first argument the engine voice start receives; it selects which of the engine's "
              "handles is allocated (FUN_800aedc0's search key), so it decides what kind of voice this is",
              writers=[B + "FUN_800b3704.c:35: *(undefined1 *)(iVar3 + -0x7fea62dc) = param_3;"],
              readers=[B + "func_800b3b9c.c:47: iVar2 = FUN_800a924c(*(undefined1 *)(iVar3 + 0x1204),"
                          "*(undefined4 *)(iVar3 + 0x1210),"],
              insn=0x800B380C),
        field("rate", 4,
              "the sample rate the engine voice is tuned to: it becomes the pitch word by way of "
              "/_DAT_80147fa4*4096, and the block rate by way of 160 samples per block. The caller "
              "supplies it (16000 by default, 8000 when the bank's flag byte is zero); nothing reads the "
              "record's own rate halfword - see unresolved",
              writers=[B + "FUN_800b3704.c:36: *(int *)(iVar3 + -0x7fea62d8) = param_2;"],
              readers=[B + "func_800b3b9c.c:36: iVar2 = *(int *)(iVar3 + 0x1208);"],
              insn=0x800B3810),
        field("engine_handle", 4,
              "the engine voice handle FUN_800a924c returned, or -1 while none is live; it is what the "
              "stop path passes to FUN_800a942c and what the release path tests before freeing the buffer",
              writers=[B + "FUN_800b3704.c:61: *(undefined4 *)(iVar3 + -0x7fea62d4) = 0xffffffff;",
                       B + "func_800b3b9c.c:52: *(int *)(iVar3 + 0x120c) = iVar2;"],
              readers=[B + "func_800b3b9c.c:66: FUN_800a942c(*(undefined4 *)(iVar3 + 0x120c));"],
              insn=0x800B3934),
        field("pcm_buffer_alloc", 4,
              "the same pointer as +0x198, kept separately for the engine handoff and for the release "
              "path: on a freed slot the engine is handed +0x1210, not +0x198",
              writers=[B + "FUN_800b3704.c:46: *(undefined4 *)(iVar3 + -0x7fea62d0) = uVar1;"],
              readers=[B + "func_800b3b9c.c:47: iVar2 = FUN_800a924c(*(undefined1 *)(iVar3 + 0x1204),"
                          "*(undefined4 *)(iVar3 + 0x1210),"],
              insn=0x800B38A4),
        field("pcm_capacity_alloc", 4,
              "the same capacity as +0x19c: (((rate<<3)/30 + 0x9f)/0xa0)*0xa0, which is 4320 samples at "
              "16 kHz - 27 blocks' worth, a fixed lookahead and not the clip's own length",
              writers=[B + "FUN_800b3704.c:42: *(uint *)(iVar3 + -0x7fea62cc) = (((uint)(param_2 << 3) / 0x1e + 0x9f) "
                          "/ 0xa0) * 0xa0;"],
              readers=[B + "func_800b3b9c.c:48: *(undefined4 *)(iVar3 + 0x1214),*(undefined4 *)(iVar3 + 0x1208),"],
              insn=0x800B3858),
        field("stop_countdown", 1,
              "set to 4 when the stream reports done and decremented by the frame thread; the slot is "
              "released when it reaches 0, which is how a finished voice survives its own final drain",
              writers=[B + "func_800b3b9c.c:31: *(undefined1 *)(iVar3 + 0x1218) = 4;",
                       B + "func_800b3b9c.c:69: *(char *)(iVar3 + 0x1218) = *(char *)(iVar3 + 0x1218) + -1;"],
              readers=[B + "func_800b3b9c.c:64: if (*(char *)(iVar3 + 0x1218) == '\\0') goto LAB_800b3d3c;"],
              offset=0x1218),
        field("pcm_units_delivered", 4,
              "PCM units the engine's callback has actually taken, accumulated by the callback itself and "
              "zeroed when the voice starts; FUN_800b3ddc divides it by the rate to build the progress the "
              "caller sees",
              writers=[B + "FUN_800b4478.c:15: *(int *)(param_5 + -0x7fea62c4) = *(int *)(param_5 + -0x7fea62c4) "
                          "+ param_2 + param_4;",
                       B + "func_800b3b9c.c:44: *(undefined4 *)(iVar3 + 0x121c) = 0;"],
              readers=[B + "FUN_800b3ddc.c:34: fVar5 = (float)*(int *)(iVar2 + -0x7fea62c4);"],
              offset=0x121C),
        field("declared_seconds", 4,
              "a float duration the frame thread computes once: (blocks_remaining * 160) / rate. It is "
              "written, never read in the corpus",
              writers=[B + "func_800b3b9c.c:43: *(float *)(iVar3 + 0x1220) = ((float)*(ushort *)(iVar3 + 0x11a0) "
                          "* 160.0) / fVar5;"],
              offset=0x1220, confidence="writer only"),
        field("voice_id", 4,
              "the caller's handle: FUN_800b3640 assigns a fresh id on every start and the control "
              "functions find a slot by scanning two entries for it",
              writers=[B + "FUN_800b3640.c:27: *(int *)(param_1 * 0x1228 + -0x7fea62bc) = _DAT_8015af70;"],
              readers=[B + "FUN_800b3ddc.c:23: if ((*(char *)(iVar2 + 0x1200) != '\\0') && "
                          "(*(int *)(iVar2 + 0x1224) == param_1))"],
              offset=0x1224),
    ]


def engine_fields():
    """The 0x68-byte engine voice record the command lands in (FUN_800a54ec, `param_2` is the command)."""
    B = "src/stage2/"
    return _by_offset([
        field("active", 1,
              "set by the engine when the record is armed by its start call (FUN_800a597c writes 1) and "
              "tested by the per-frame builder; 0 here means the frame is skipped",
              writers=[B + "FUN_800a54ec.c:22: *puVar4 = 0;"],
              readers=[B + "FUN_800a4560.c:35: if (*(char *)(iVar5 + _DAT_80143f0c) != '\\0') {"],
              insn=0x800A5520),
        field("start_flag_b", 1,
              "set to 1 on every start beside the zeroing of the word above; no reader found",
              writers=[B + "FUN_800a54ec.c:24: puVar4[1] = 1;"],
              insn=0x800A5528, confidence="writer only"),
        field("voice_flags", 2,
              "zeroed, then bit 0 is set unless the buffer address in the command starts with 0x8; the "
              "per-frame builder branches on it to choose which command layout it writes",
              writers=[B + "FUN_800a54ec.c:23: *(undefined2 *)(puVar4 + 2) = 0;",
                       B + "FUN_800a54ec.c:67: *(ushort *)(iVar1 + 2) = *(ushort *)(iVar1 + 2) | 1;"],
              readers=[B + "FUN_800a3bf4.c:103: if ((*(ushort *)(param_1 + 2) & 1) == 0) {"],
              insn=0x800A5524),
        field("pitch_word", 2,
              "the resampling ratio in 12-bit fixed point: (rate / _DAT_80147fa4) * 4096, clamped to "
              "0.5 (0x2000). At 16 kHz against a 32 kHz output this is 0x800",
              writers=[B + "FUN_800a54ec.c:21: *(undefined2 *)(puVar4 + 4) = 0x1000;",
                       B + "FUN_800a5a00.c:15: *(ushort *)(param_1 * 0x68 + _DAT_80143f0c + 4) = param_2;"],
              readers=[B + "FUN_800a3bf4.c:272: puVar7[0x11] = *(ushort *)(param_1 + 4);"],
              insn=0x800A5518),
        field("position_double", 8,
              "the voice's playback position carried as a double, so the fractional part survives between "
              "frames: the builder subtracts the integer part and keeps the remainder times 65536",
              writers=[B + "FUN_800a54ec.c:46: *(double *)(iVar1 + 8) = dVar5;"],
              readers=[B + "FUN_800a3bf4.c:45: FUN_800a6258(*(undefined8 *)(param_1 + 8));"],
              insn=0x800A55CC),
        field("position_integer", 4,
              "the integer part of that position, rewritten from it every frame by FUN_800a485c before "
              "the command list is built",
              writers=[B + "FUN_800a54ec.c:49: *(undefined4 *)(iVar1 + 0x10) = uVar2;",
                       B + "FUN_800a485c.c:31: *(uint *)(pcVar2 + 0x10) = (int)(dVar4 - 2147483648.0) | 0x80000000;"],
              readers=[B + "FUN_800a3bf4.c:113: *(uint *)(puVar7 + 0x18) = *(int *)(param_1 + 0x2c) + "
                          "(local_44 & 0xfffc) * 2;"],
              insn=0x800A55D8),
        field("position_previous", 4,
              "last frame's integer position; FUN_800a485c copies +0x10 into it before advancing, so the "
              "pair is the one-frame stride the builder measures",
              writers=[B + "FUN_800a54ec.c:48: *(undefined4 *)(iVar1 + 0x14) = uVar2;",
                       B + "FUN_800a485c.c:26: *(undefined4 *)(pcVar2 + 0x14) = *(undefined4 *)(pcVar2 + 0x10);"],
              insn=0x800A55D4, confidence="writer only"),
        field("pcm_base", 4,
              "the sample buffer from the command: for a MORT voice, the PCM the synthesis filled",
              writers=[B + "FUN_800a54ec.c:41: *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_2 + 4);"],
              readers=[B + "FUN_800a3bf4.c:119: *(uint *)(puVar7 + 0x12) = *(int *)(param_1 + 0x2c) + "
                          "(local_48 & 0xfffc) * 2;"],
              insn=0x800A55A8),
        field("buffer_end", 4,
              "the first of the three length words the command carries; for a MORT voice it is the same "
              "capacity as +0x38, which is why the +0x3c loop length comes out zero",
              writers=[B + "FUN_800a54ec.c:50: *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(param_2 + 0xc);"],
              readers=[B + "FUN_800a3bf4.c:61: if (local_48 + iVar10 < *(uint *)(param_1 + 0x30)) goto LAB_800a3dfc;"],
              insn=0x800A55E0),
        field("loop_start", 4,
              "the command's second length word; the MORT voice hands 0 here",
              writers=[B + "FUN_800a54ec.c:51: *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(param_2 + 0x10);"],
              readers=[B + "FUN_800a3bf4.c:57: uVar8 = *(int *)(param_1 + 0x34) + uVar2;"],
              insn=0x800A55E8),
        field("loop_end", 4,
              "the command's third length word; the MORT voice hands the capacity, the same value as "
              "+0x30",
              writers=[B + "FUN_800a54ec.c:52: *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(param_2 + 0x14);"],
              readers=[B + "FUN_800a3bf4.c:56: uVar2 = *(uint *)(param_1 + 0x38);"],
              insn=0x800A55F0),
        field("loop_length", 4,
              "buffer_end - (loop_start + loop_end), zeroed when it falls below 10: a derived word, not "
              "an input, and 0 for every MORT voice because +0x30 and +0x38 agree",
              writers=[B + "FUN_800a54ec.c:59: uVar3 = *(int *)(iVar1 + 0x30) - (*(int *)(iVar1 + 0x34) + "
                          "*(int *)(iVar1 + 0x38));",
                       B + "FUN_800a54ec.c:62: *(undefined4 *)(iVar1 + 0x3c) = 0;"],
              readers=[B + "FUN_800a3bf4.c:58: if ((uVar2 == 0) ||"],
              insn=0x800A560C),
        field("gain_target_0", 2,
              "one of four s16 TARGET gains at stride 2 (0x40, 0x42, 0x44, 0x46). The CPU computes each "
              "one itself, through two float tables: a packed word is split into a table index and an 8.8 "
              "fraction and interpolated, then stored as gain*32767. Which output channel each of the "
              "four feeds is not stated by any MIPS instruction - it is one of the unobservable entries "
              "this map lists rather than guesses",
              writers=[B + "FUN_800a54ec.c:29: *(undefined2 *)(puVar4 + 0x40) = 0;",
                       B + "FUN_800a5a60.c:18: FUN_800a5da0(iVar1 + 0x42,iVar1 + 0x40,param_2,param_3,param_4,"
                          "iVar1 + 0x44,param_5,iVar1 + 0x46);"],
              readers=[B + "FUN_800a3bf4.c:249: iVar3 = (int)((float)(int)*(short *)(param_1 + 0x40) * "
                          "*(float *)(param_1 + 0x4c)) * 0x10000 -"],
              insn=0x800A553C),
        field("gain_target_1", 2,
              "the second target gain (see +0x40)",
              writers=[B + "FUN_800a54ec.c:30: *(undefined2 *)(puVar4 + 0x42) = 0;",
                       B + "FUN_800a5a60.c:18: FUN_800a5da0(iVar1 + 0x42,iVar1 + 0x40,param_2,param_3,param_4,"
                          "iVar1 + 0x44,param_5,iVar1 + 0x46);"],
              readers=[B + "FUN_800a3bf4.c:255: iVar3 = (int)((float)(int)*(short *)(param_1 + 0x42) * "
                          "*(float *)(param_1 + 0x4c)) * 0x10000 -"],
              insn=0x800A5540),
        field("gain_target_2", 2,
              "the third target gain (see +0x40)",
              writers=[B + "FUN_800a54ec.c:31: *(undefined2 *)(puVar4 + 0x44) = 0;",
                       B + "FUN_800a5da0.c:32: *param_6 = (short)(int)(fVar3 * ((1.0 - fVar2) * "
                          "*(float *)(&DAT_80136304 + (param_5 >> 0x16) * 4)"],
              readers=[B + "FUN_800a3bf4.c:261: iVar3 = (int)((float)(int)*(short *)(param_1 + 0x44) * "
                          "*(float *)(param_1 + 0x4c)) * 0x10000 -"],
              insn=0x800A5544),
        field("gain_target_3", 2,
              "the fourth target gain (see +0x40)",
              writers=[B + "FUN_800a54ec.c:32: *(undefined2 *)(puVar4 + 0x46) = 0;",
                       B + "FUN_800a5a60.c:18: FUN_800a5da0(iVar1 + 0x42,iVar1 + 0x40,param_2,param_3,param_4,"
                          "iVar1 + 0x44,param_5,iVar1 + 0x46);"],
              readers=[B + "FUN_800a3bf4.c:265: fVar14 = (float)(int)*(short *)(param_1 + 0x46) * "
                          "*(float *)(param_1 + 0x4c);"],
              insn=0x800A554C),
        field("gain_current", 2,
              "the four running gains at stride 2 (0x18, 0x1a, 0x1c, 0x1e - one field of four): every "
              "frame the builder scales "
              "the matching target by the float at +0x4c, writes the result back here, and carries the "
              "difference to the old value as a per-frame step in the command list. So the descriptor "
              "holds current and target gains, and the CPU computes both",
              writers=[B + "FUN_800a54ec.c:25: *(undefined2 *)(puVar4 + 0x18) = 0;",
                       B + "FUN_800a3bf4.c:248: (short)(int)((float)(int)*(short *)(param_1 + 0x40) * "
                          "*(float *)(param_1 + 0x4c));"],
              readers=[B + "FUN_800a3bf4.c:243: *(int *)puVar7 = (int)*(short *)(param_1 + 0x18) << 0x10;"],
              insn=0x800A552C),
        field("record_mode", 1,
              "copied from the command's +0x18 byte, and it decides how the per-frame builder walks the "
              "buffer: 0 means stride-2 16-bit units at base + (position & ~3)*2, 3 means 0x28-byte "
              "blocks at base + 0x100, any other value falls through to the shared tail. The MORT voice "
              "always hands 0, so the PCM the codec writes is read back as plain 16-bit samples",
              writers=[B + "FUN_800a54ec.c:53: *(undefined1 *)(iVar1 + 0x5d) = *(undefined1 *)(param_2 + 0x18);"],
              readers=[B + "FUN_800a3bf4.c:104: if (param_1[0x5d] == '\\0') {"],
              insn=0x800A55F8),
    ])


def handle_fields():
    """The 0x18-byte record FUN_800a924c keeps per handle: what the release path needs, nothing else."""
    B = "src/stage2/"
    return [
        field("started", 1,
              "set to 1 by the start call and cleared by FUN_800a942c before it releases the handle",
              writers=[B + "FUN_800a924c.c:38: (&DAT_801481e0)[iVar2] = 1;"],
              readers=[B + "FUN_800a942c.c:14: if ((&DAT_801481e0)[param_1 * 0x18] == '\\x01') {"],
              insn=0x800A92F4),
        field("refill_callback", 4,
              "the routine the engine calls when it wants more PCM; the voice path passes FUN_800b4478, "
              "which advances the slot's +0x11d4 and returns nothing",
              writers=[B + "FUN_800a924c.c:37: *(undefined4 *)(&DAT_801481e4 + iVar2) = param_9;"],
              readers=[B + "FUN_800b4478.c:14: FUN_800b4d30(param_5 + -0x7fea74e0,param_2 + param_4);"],
              insn=0x800A92EC),
        field("buffer", 4,
              "the PCM buffer handed over, i.e. the slot's +0x1210; the engine passes it to the refill "
              "callback, whose calling side is not in the corpus",
              writers=[B + "FUN_800a924c.c:34: *(undefined4 *)(&DAT_801481e8 + iVar2) = param_2;"],
              insn=0x800A92D8, confidence="writer only"),
        field("length", 4,
              "its capacity in 16-bit units, i.e. the slot's +0x1214, beside the buffer above",
              writers=[B + "FUN_800a924c.c:35: *(undefined4 *)(&DAT_801481ec + iVar2) = param_3;"],
              insn=0x800A92DC, confidence="writer only"),
        field("zero", 4,
              "zeroed on every start; no reader found",
              writers=[B + "FUN_800a924c.c:36: *(undefined4 *)(&DAT_801481f0 + iVar2) = 0;"],
              insn=0x800A92E8, confidence="writer only"),
        field("voice_slot", 4,
              "which of the two slots this handle belongs to: it is passed to the refill callback as its "
              "fifth argument and multiplied by 0x1228 there, which is the link back from the engine to "
              "the descriptor",
              writers=[B + "FUN_800a924c.c:39: *(undefined4 *)(&DAT_801481f4 + iVar2) = param_10;"],
              readers=[B + "FUN_800b4478.c:13: param_5 = param_5 * 0x1228;"],
              insn=0x800A9300),
    ]


def task_fields():
    """The task block FUN_800a2e40 fills and hands to the microcode; the CPU's last word on the mix."""
    B = "src/stage2/"
    names = [("task_type", 4, 0x00,
              "the block's first word, written 2; the value is the only thing in the block that says what "
              "kind of task this is",
              [B + "FUN_800a2e40.c:18: _DAT_80143c60 = 2;"], []),
             ("command_list", 4, 0x30,
              "the per-frame command list base (0x80143f50), written back after a cache flush of "
              "frames*0xa10 bytes: this is what the task hands over",
              [B + "FUN_800a2e40.c:26: _DAT_80143c90 = _DAT_80143f50;",
               B + "FUN_800a2e40.c:28: func_0x8000efa0(_DAT_80143f50,uVar1 * 0xa10);"], []),
             ("frame_count", 4, 0x34,
              "how many 0xa10-byte frames that list holds, i.e. how many AI buffers are being handed over "
              "in one task",
              [B + "FUN_800a2e40.c:27: _DAT_80143c94 = uVar1;"], []),
             ("blob_pointer", 4, 0x10,
              "a pointer into the stage-2 member (0x800b2700) with a size word of 0x1000 beside it at "
              "+0x14. The corpus has no body between 0x800b2694 and 0x800b3640, so most of that range is "
              "outside it - but the range's last 0xc0 bytes run into FUN_800b3640, which is why the pair "
              "is recorded as it stands and its meaning left to unresolved",
              [B + "FUN_800a2e40.c:20: _DAT_80143c70 = &DAT_800b2700;",
               B + "FUN_800a2e40.c:21: _DAT_80143c74 = 0x1000;"], [])]
    rows = [field(n, w, m, wr, rd, offset=o, confidence="writer only") for n, w, o, m, wr, rd in names]
    return sorted(rows, key=lambda f: f["offset"])


def ring_section():
    B = "src/stage2/"
    return {
        "offset": RING_OFF,
        "size": RING_SIZE,
        "chunk": CHUNK,
        "fetch_window_mask": FETCH_MASK,
        "read_window_mask": READ_MASK,
        "contents": "the record's bytes, exactly as the cartridge holds them, refilled 0x400 at a time "
                    "through the DMA callback at descriptor+0x190",
        "layout": [
            {"offset": RING_OFF, "width": 2, "name": "magic",
             "meaning": "the record's first halfword, 'MO'; never read by the codec, which starts at +0x60",
             "writer": [B + "FUN_800b4a04.c:56: param_1 + (*(uint *)(param_1 + 0x11d0) & 0xff8) + 0x1a0,iVar1,"
                             "param_1 + 0x11ac);"],
             "reader": [], "evidence": "the DMA destination arithmetic, not a field read",
             "confidence": "byte map only"},
            {"offset": RING_OFF + 4, "width": 2, "name": "header_blocks",
             "meaning": "the MORT header's block count, and the only thing the reader takes out of the "
                        "ring: read as a halfword into descriptor+0x11a0 when rom_offset is still 0",
             "writer": [B + "FUN_800b4a04.c:30: *(int *)(param_1 + 0x11d0) = iVar1 + 0x400;"],
             "reader": [B + "FUN_800b4a04.c:25: *(undefined2 *)(param_1 + 0x11a0) = "
                             "*(undefined2 *)(param_1 + 0x1a4);"],
             "evidence": "instruction 0x800b4a50 (lhu r4,420(r16)) reads ring+4", "confidence": "established"},
            {"offset": RING_OFF + 6, "width": 2, "name": "header_rate",
             "meaning": "the MORT header's sample rate; NO instruction in any unpacked image reads this "
                        "halfword (every immediate 0x1a6/0x1a7 in the corpus belongs to a stack frame), so "
                        "the descriptor's rate cannot be traced through it - see unresolved",
             "writer": [B + "FUN_800b4a04.c:30: *(int *)(param_1 + 0x11d0) = iVar1 + 0x400;"],
             "reader": [], "evidence": "absence, established by scanning every image for the immediate",
             "confidence": "unread"},
            {"offset": RING_OFF + 8, "width": 4, "name": "header_words",
             "meaning": "the record's length in 32-bit words, masked to 24 bits into descriptor+0x11a4 and "
                        "from there into 4-byte tail-chunk arithmetic",
             "writer": [B + "FUN_800b4a04.c:30: *(int *)(param_1 + 0x11d0) = iVar1 + 0x400;"],
             "reader": [B + "FUN_800b4a04.c:27: *(uint *)(param_1 + 0x11a4) = *(uint *)(param_1 + 0x1a8) & 0xffffff;"],
             "evidence": "instruction 0x800b4a58 (lw r3,424(r16)) reads ring+8", "confidence": "established"},
        ],
        "chunking": {
            "rule": "the fetch destination is ring + (rom_offset & 0xff8); the byte count is 0x400, except "
                    "that once descriptor+0x11a4 (words still declared) falls below 0x101 it becomes "
                    "0x11a4<<2, i.e. the record's own tail",
            "fetch_when": "stream_state in {1,2,3} and (rom_offset - ring_consumed) < 0xc01, so at most "
                          "three chunks are ever outstanding in a 4 KiB ring",
            "evidence": [B + "FUN_800b4a04.c:42: ((uint)(*(int *)(param_1 + 0x11d0) - *(int *)(param_1 + 0x11cc)) < 0xc01)) {",
                         B + "FUN_800b4a04.c:49: iVar1 = *(uint *)(param_1 + 0x11a4) << 2;"],
        },
        "overlap": {
            "claim": "the ring and the post-ring state do not overlap: 0x1a0 + 0x1000 == 0x11a0",
            "evidence": [B + "FUN_800b53f4.c:71: uVar4 = *(uint *)(((int)uVar14 >> 3 & 0xffcU) + iVar6) >> (uVar14 & 0x1f);",
                         B + "FUN_800b4930.c:29: *(undefined2 *)(param_1 + 0x11a0) = 0;"],
        },
        "correction": "+0x1a4 and +0x1a8 are not stream state, though they sit where stream state would "
                      "expect to be: the ring spans 0x1a0..0x119f, so those two reads are ring bytes 4..11, "
                      "and they happen exactly once, while rom_offset is still 0 and the first chunk is the "
                      "record's header. Every actual stream field is at 0x11a0 and above.",
    }


def rsp_only_section():
    return [
        {"name": "command_record_semantics",
         "what": "what the microcode does with the 0x50-byte per-voice command record, and what each of "
                 "its words means",
         "why_unobservable": "FUN_800a3bf4 writes one record per active voice per frame into the list at "
                             "0x80143f50, and no MIPS instruction in the corpus ever reads that list back: "
                             "its only consumer is the RSP program, so every field's meaning is a property "
                             "of microcode that is not in the corpus."},
        {"name": "gain_application",
         "what": "how the four target gains at engine+0x40..0x46 are applied per sample, and which output "
                 "channel each of the four feeds",
         "why_unobservable": "the CPU only computes the target gains and the per-frame ramp step "
                             "(FUN_800a3bf4 divides the difference by 6 and shifts); applying that ramp "
                             "per sample, and choosing a channel, is the mixer's job and leaves no MIPS "
                             "trace."},
        {"name": "resampling",
         "what": "how the pitch word at engine+0x04 becomes an interpolated sample stream",
         "why_unobservable": "the CPU computes the ratio as (rate/_DAT_80147fa4)*4096 and stops there; "
                             "the filter, its taps and its rounding live in the ucode, which is not "
                             "disassembled anywhere in this repository."},
        {"name": "loop_choice",
         "what": "whether the mixer honours buffer_end (+0x30) or loop_end (+0x38) when they differ, and "
                 "what a non-zero loop_length (+0x3c) would sound like",
         "why_unobservable": "the MORT voice sets +0x30 == +0x38 == the capacity and +0x3c == 0, so the "
                             "distinction is unobservable from the CPU side by construction - the two "
                             "candidate readings agree on every voice this path starts."},
        {"name": "output_frames",
         "what": "how the 0x800-byte output buffer at 0x80136b50 is filled and how the AI receives it",
         "why_unobservable": "the task block names that buffer and its size, and no MIPS instruction in the "
                             "corpus writes or reads it; the mixer fills it and the handover to the audio "
                             "interface is outside the corpus."},
        {"name": "microcode_identity",
         "what": "what the 0x1000 bytes the task block points at (0x800b2700) actually are",
         "why_unobservable": "the corpus has no MIPS body between 0x800b2694 and 0x800b3640 and no RSP "
                             "disassembly exists anywhere in this repository, so the bytes are locatable "
                             "and their behaviour is not - and the declared 0x1000-byte range overruns into "
                             "FUN_800b3640, so even the extent is a claim this map does not make."},
    ]


LOAD_OPS = (0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B, 0x31, 0x35, 0x39, 0x3D)


def rate_halfword_readers():
    """Every stage-2 instruction that uses ring+6 or ring+7 as a memory displacement, as (pc, op, base)."""
    blob = stage2()
    words = struct.unpack(">%dI" % (len(blob) // 4), blob[:len(blob) // 4 * 4])
    hits = []
    for index, w in enumerate(words):
        op = w >> 26
        if op not in LOAD_OPS:
            continue
        imm = w & 0xFFFF
        if imm in (RING_OFF + 6, RING_OFF + 7):
            hits.append((STAGE2_BASE + index * 4, op, (w >> 21) & 0x1F))
    return hits


def stage2_bodies():
    """Every function body the corpus records for the stage-2 image, as (name, start, end)."""
    bodies = []
    pattern = re.compile(r"address (0x[0-9a-f]{8})  body (0x[0-9a-f]{8})\.\.(0x[0-9a-f]{8})")
    for path in sorted((ROOT / "src" / "stage2").glob("*.c")):
        m = pattern.search(path.read_text(encoding="utf-8", errors="replace")[:400])
        if m:
            bodies.append((path.stem, int(m.group(1), 16), int(m.group(3), 16)))
    return bodies


def unresolved_section():
    return [
        {"question": "Does the descriptor's rate come from the MORT header's rate halfword at ring+6?",
         "why": "no instruction reads ring+6 (scanned by immediate across every unpacked image), and "
                "FUN_800b3704 receives the rate as an argument, defaulting to 16000 or 8000 on the bank "
                "table's flag byte. For clip 0 the record declares 16000 and the default is 16000, so the "
                "numbers agree without a traced hop.",
         "would_settle_it": "the caller of FUN_800b3704 for clip 0, and what writes the bank table's flag "
                            "byte at _DAT_8015af7c."},
        {"question": "What reads descriptor+0x11a2?",
         "why": "it is written twice from the header's block count (+4) and read by nothing in the corpus.",
         "would_settle_it": "a reader in code outside the corpus, or a demonstration that the write is dead."},
        {"question": "What is _DAT_80147fa4, the divisor in the pitch word?",
         "why": "the pitch word is (rate / _DAT_80147fa4) * 4096, so every resampling claim needs this "
                "number, and it is RAM: written by FUN_800a80c8 from its argument, with no trace in the "
                "corpus to the caller that supplies the audio interface's frequency.",
         "would_settle_it": "the caller of FUN_800a80c8 and the AI frequency it installs."},
        {"question": "What advances the playback position at engine+0x10 for a MORT voice?",
         "why": "FUN_800a54ec writes +0x08/+0x10/+0x14 from the command, and for this path every one of "
                "them is zero; FUN_800a485c then rewrites +0x10 from +0x08's integer part each frame, "
                "which stays zero, and FUN_800a3bf4 reads +0x08 to size its per-frame step. No MIPS "
                "instruction in the corpus writes a non-zero position to this record, so either the "
                "position is irrelevant because the refill callback delivers PCM by the slot's own "
                "+0x11d4 counter, or something outside the corpus writes it.",
         "would_settle_it": "a watchpoint on engine+0x10 during a clip, or code outside the corpus that "
                            "stores to it."},
        {"question": "What is the 0x800b2700 / 0x1000 pointer-size pair in the audio task block?",
         "why": "the corpus has no body between 0x800b2694 and 0x800b3640, so the pair looks like a hole in "
                "the stage-2 image - but a 0x1000-byte range from 0x800b2700 ends at 0x800b3700 and thus "
                "overruns FUN_800b3640 by 0xc0 bytes, so it cannot be a plain extent of that image.",
         "would_settle_it": "the routine that consumes the task block, or a dump of the block at run time."},
        {"question": "What is the boot pointer the task block at +0x08 receives?",
         "why": "FUN_800a2e40 assigns the symbol Ghidra renders as `entry` to it, which is the image's own "
                "entry point (src/stage2/func_80018a80.c:11) and cannot be an RSP boot address; the "
                "decompiler has lost which variable that was.",
         "would_settle_it": "the linker symbol at that store, or a read of the value in a memory dump."},
    ]


# --- the clip trace --------------------------------------------------------------------------------------
def mort_records():
    """The bank's MORT records as (index, blocks, rate, declared words, record bytes)."""
    rom = rom_bytes()
    r4 = rom[BANK_CART:BANK_CART + BANK_SIZE]
    count = struct.unpack_from(">I", r4, 0)[0]
    vals = struct.unpack_from(">" + str(count) + "I", r4, 4)
    offs = [v & 0xFFFFFF for v in vals] + [len(r4)]
    rows = []
    for k in range(count):
        rec = r4[offs[k]:offs[k + 1]]
        if rec[:4] != b"MORT":
            continue
        blocks, rate, words = struct.unpack_from(">HHI", rec, 4)
        rows.append((k, blocks, rate, words, rec))
    return rows


def clip_trace(index=0):
    """One clip, end to end, with each hop stating where its number came from."""
    rows = mort_records()
    if not rows:
        raise Unplaceable("no MORT record in the bank")
    k, blocks, rate, words, rec = rows[index]
    length = len(rec)
    chunks = (length + CHUNK - 1) // CHUNK
    before_tail = (words & 0xFFFFFF) - 0x100 * (chunks - 1)
    tail = before_tail * 4
    capacity = (((rate << 3) // 0x1E + 0x9F) // 0xA0) * 0xA0
    samples = blocks * BLOCK_SAMPLES
    B = "src/stage2/"

    def v(field_name, value, source, via):
        return {"field": field_name, "value": value, "from": source, "via": via}

    return {
        "index": k,
        "record": {"bank_file": 1979, "bytes": length, "header_bytes": MORT_HEADER},
        "values": [
            v("+0x11a0 blocks_remaining", blocks, "cartridge:MORT+4",
              "arith: src @ " + B + "FUN_800b4a04.c:25: *(undefined2 *)(param_1 + 0x11a0) = "
                                    "*(undefined2 *)(param_1 + 0x1a4);"),
            v("+0x11a2 header_blocks_echo", blocks, "trace:+0x11a0 blocks_remaining",
              "arith: src @ " + B + "FUN_800b4a04.c:26: *(short *)(param_1 + 0x11a2) = "
                                    "(short)*(undefined4 *)(param_1 + 0x1a4);"),
            v("+0x11a4 record_words_remaining", words & 0xFFFFFF, "cartridge:MORT+8",
              "arith: src & 0xffffff @ " + B + "FUN_800b4a04.c:27: *(uint *)(param_1 + 0x11a4) = "
                                               "*(uint *)(param_1 + 0x1a8) & 0xffffff;"),
            v("record bytes", length, "cartridge:record_len",
              "arith: src @ " + B + "FUN_800b4a04.c:49: iVar1 = *(uint *)(param_1 + 0x11a4) << 2;"),
            v("bytes implied by the declared words", length, "trace:+0x11a4 record_words_remaining",
              "arith: src * 4 @ " + B + "FUN_800b4a04.c:49: iVar1 = *(uint *)(param_1 + 0x11a4) << 2;"),
            v("+0x11c8 bit_cursor", 0x60, "cartridge:header_bytes",
              "arith: src * 8 @ " + B + "FUN_800b4a04.c:24: *(undefined4 *)(param_1 + 0x11c8) = 0x60;"),
            v("chunk count", chunks, "trace:record bytes",
              "arith: (src + 0x3ff) // 0x400 @ " + B + "FUN_800b4a04.c:30: *(int *)(param_1 + 0x11d0) = iVar1 + 0x400;"),
            v("words left when the tail chunk is issued", before_tail, "trace:+0x11a4 record_words_remaining",
              "arith: src - 0x100 * %d @ " % (chunks - 1) + B + "FUN_800b4a04.c:35: *(uint *)(param_1 + 0x11a4) "
                                                          "= *(uint *)(param_1 + 0x11a4) - 0x100;"),
            v("tail chunk bytes", tail, "trace:words left when the tail chunk is issued",
              "arith: src * 4 @ " + B + "FUN_800b4a04.c:49: iVar1 = *(uint *)(param_1 + 0x11a4) << 2;"),
            v("+0x1208 rate", rate, "cartridge:MORT+6",
              "arith: src @ " + B + "FUN_800b3704.c:36: *(int *)(iVar3 + -0x7fea62d8) = param_2;"),
            v("+0x1214 pcm_capacity_alloc", capacity, "trace:+0x1208 rate",
              "arith: ((src << 3) // 0x1e + 0x9f) // 0xa0 * 0xa0 @ " + B + "FUN_800b3704.c:42: "
                                                                         "*(uint *)(iVar3 + -0x7fea62cc) = "
                                                                         "(((uint)(param_2 << 3) / 0x1e + 0x9f) / 0xa0) * 0xa0;"),
            v("+0x19c pcm_units", capacity, "trace:+0x1214 pcm_capacity_alloc",
              "arith: src @ " + B + "FUN_800b4930.c:16: *(undefined4 *)(param_1 + 0x19c) = param_4;"),
            v("buffer allocation bytes", (capacity + 4) * 2, "trace:+0x1214 pcm_capacity_alloc",
              "arith: (src + 4) * 2 @ " + B + "FUN_800a9420.c:12: return (param_1 + 4) * 2;"),
            v("+0x11d8 units_written (whole clip)", samples, "trace:+0x11a0 blocks_remaining",
              "arith: src * 160 @ " + B + "FUN_800b4a04.c:75: *(int *)(param_1 + 0x11d8) = "
                                         "*(int *)(param_1 + 0x11d8) + 0xa0;"),
        ],
        "hops_not_traced": [
            "+0x198/+0x1210 (the PCM buffer address) is a runtime allocation or one of the two static "
            "buffers at 0x8015af88; no cartridge byte decides it, so the trace stops at its size.",
            "the rate hop: the descriptor takes the caller's argument, and the record's own rate halfword "
            "is read by nothing (see unresolved). The values agree for this clip; the hop is not traced.",
        ],
    }


# --- derive ----------------------------------------------------------------------------------------------
def derive():
    """The whole artefact, from the cartridge plus the analysis this file carries."""
    desc = descriptor_fields()
    eng = engine_fields()
    handle = handle_fields()
    task = task_fields()
    ring = ring_section()
    rsp = rsp_only_section()
    unresolved = unresolved_section()
    trace = clip_trace(0)

    all_citations = []
    for f in desc + eng + handle + task:
        all_citations += list(f["writer"]) + list(f["reader"])
    for row in ring["layout"]:
        all_citations += list(row["writer"]) + list(row["reader"])
    all_citations += list(ring["chunking"]["evidence"]) + list(ring["overlap"]["evidence"])
    for row in trace["values"]:
        m = ARITH.match(row["via"])
        if m:
            all_citations.append(m.group(2))

    rom = rom_bytes()
    sources = []
    for path in source_paths(all_citations):
        sources.append({"path": path,
                        "sha256": hashlib.sha256((ROOT / path).read_bytes()).hexdigest()})

    return {
        "tool": "voice_descriptor.py",
        "schema": "voice-descriptor/1",
        "inputs": {
            "cartridge": {"path": str(ROM.relative_to(ROOT)), "bytes": len(rom),
                          "sha256": hashlib.sha256(rom).hexdigest()},
            "stage2_member": {"file_offset": STAGE2_OFF, "bytes": STAGE2_LEN, "base": hexstr(STAGE2_BASE),
                              "stored": "zlib, CMF 0x68", "sha256": hashlib.sha256(stage2()).hexdigest()},
            "voice_bank": {"file_offset": BANK_CART, "bytes": BANK_SIZE, "records": len(mort_records())},
            "sources": sources,
        },
        "descriptor": {
            "name": "voice_slot",
            "base": hexstr(SLOT_BASE),
            "stride": SLOT_STRIDE,
            "slots": SLOT_COUNT,
            "end": hexstr(SLOT_END),
            "end_evidence": ["src/stage2/FUN_800b3640.c:27: *(int *)(param_1 * 0x1228 + -0x7fea62bc) = "
                             "_DAT_8015af70;",
                             "src/stage2/FUN_800b3704.c:27: iVar3 = iVar3 + 0x1228;"],
            "stride_evidence": ["src/stage2/func_800b3b9c.c:72: iVar3 = iVar3 + 0x1228;",
                                "src/stage2/FUN_800b3704.c:27: iVar3 = iVar3 + 0x1228;"],
            "starters": ["FUN_800b3704", "FUN_800b4930", "FUN_800b4a04", "FUN_800b53f4",
                         "func_800b3b9c", "FUN_800b40c4"],
            "fields": desc,
            "command": {
                "name": "engine_handoff",
                "what": "FUN_800a924c's arguments, and the two records they land in. This is the CPU's "
                        "last statement about the voice before the microcode takes it.",
                "argument_block": [
                    {"offset": 0x00, "width": 4, "name": "flags_and_rate",
                     "meaning": "the rate OR'd with 0x00400000; the low half becomes the pitch word",
                     "writer": ["src/stage2/FUN_800a924c.c:40: local_48 = param_4 | 0x400000;"],
                     "reader": ["src/stage2/FUN_800a54ec.c:65: if ((*(uint *)(param_2 + 4) & 0xf0000000) != "
                                "0x80000000) {"],
                     "evidence": "instruction 0x800a930c stores rate|0x400000 to the block's first word",
                     "confidence": "established"},
                    {"offset": 0x04, "width": 4, "name": "buffer",
                     "meaning": "the PCM buffer address (the slot's +0x1210)",
                     "writer": ["src/stage2/FUN_800a924c.c:44: local_44 = param_2;"],
                     "reader": ["src/stage2/FUN_800a54ec.c:41: *(undefined4 *)(iVar1 + 0x2c) = "
                                "*(undefined4 *)(param_2 + 4);"],
                     "evidence": "instruction 0x800a9310", "confidence": "established"},
                    {"offset": 0x08, "width": 4, "name": "position",
                     "meaning": "a starting position, zero for the voice path",
                     "writer": ["src/stage2/FUN_800a924c.c:41: local_40 = 0;"],
                     "reader": ["src/stage2/FUN_800a54ec.c:42: dVar5 = (double)*(int *)(param_2 + 8);"],
                     "evidence": "instruction 0x800a9314", "confidence": "established"},
                    {"offset": 0x0C, "width": 4, "name": "length_a",
                     "meaning": "the capacity in 16-bit units (the slot's +0x1214)",
                     "writer": ["src/stage2/FUN_800a924c.c:45: local_3c = param_3;"],
                     "reader": ["src/stage2/FUN_800a54ec.c:50: *(undefined4 *)(iVar1 + 0x30) = "
                                "*(undefined4 *)(param_2 + 0xc);"],
                     "evidence": "instruction 0x800a9318", "confidence": "established"},
                    {"offset": 0x10, "width": 4, "name": "length_b",
                     "meaning": "zero for the voice path; this is the byte the MORT voice always hands 0",
                     "writer": ["src/stage2/FUN_800a924c.c:42: local_38 = 0;"],
                     "reader": ["src/stage2/FUN_800a54ec.c:51: *(undefined4 *)(iVar1 + 0x34) = "
                                "*(undefined4 *)(param_2 + 0x10);"],
                     "evidence": "instruction 0x800a931c", "confidence": "established"},
                    {"offset": 0x14, "width": 4, "name": "length_c",
                     "meaning": "the same capacity again, which is why the derived loop length is zero",
                     "writer": ["src/stage2/FUN_800a924c.c:46: local_34 = param_3;"],
                     "reader": ["src/stage2/FUN_800a54ec.c:52: *(undefined4 *)(iVar1 + 0x38) = "
                                "*(undefined4 *)(param_2 + 0x14);"],
                     "evidence": "instruction 0x800a9320", "confidence": "established"},
                    {"offset": 0x18, "width": 1, "name": "mode",
                     "meaning": "the buffer's record mode; 0 for the voice path, which is what tells the "
                                "consumer that the buffer holds plain 16-bit samples",
                     "writer": ["src/stage2/FUN_800a924c.c:43: local_30 = 0;"],
                     "reader": ["src/stage2/FUN_800a54ec.c:53: *(undefined1 *)(iVar1 + 0x5d) = "
                                "*(undefined1 *)(param_2 + 0x18);"],
                     "evidence": "instruction 0x800a9328", "confidence": "established"},
                ],
                "engine_voice": {"base": hexstr(ENGINE_BASE), "stride": ENGINE_STRIDE,
                                 "stride_evidence": ["src/stage2/FUN_800a54ec.c:20: puVar4 = (undefined1 *)"
                                                     "(_DAT_80143f0c + (param_1 & 0xffff) * 0x68);"],
                                 "fields": eng},
                "handle": {"base": hexstr(HANDLE_BASE), "stride": HANDLE_STRIDE,
                           "stride_evidence": ["src/stage2/FUN_800a924c.c:33: iVar2 = iVar1 * 0x18;"],
                           "fields": handle},
                "task": {"base": hexstr(TASK_BASE),
                         "list_base": hexstr(LIST_BASE),
                         "program_blob": hexstr(UCODE_BLOB),
                         "fields": task,
                         "evidence": ["src/stage2/FUN_800a2e40.c:29: (*_DAT_80143ff0)(&DAT_80143c60);"]},
            },
        },
        "ring": ring,
        "rsp_only": rsp,
        "clip_trace": trace,
        "unresolved": unresolved,
    }


def render(artefact):
    return json.dumps(artefact, indent=1, sort_keys=True) + "\n"


# --- check -----------------------------------------------------------------------------------------------
def offset_of_int(value):
    """A field offset, however it is spelled (the artefact keeps these as integers)."""
    return int(value, 0) if isinstance(value, str) else int(value)


def _iter_fields(artefact):
    for f in artefact["descriptor"]["fields"]:
        yield "descriptor", f
    command = artefact["descriptor"]["command"]
    for f in command["argument_block"]:
        yield "argument_block", f
    for group in ("engine_voice", "handle", "task"):
        for f in command[group]["fields"]:
            yield group, f


def _eval_arith(expr, src):
    """Evaluate a trace expression. Only integers, `src`, and the four arithmetic operators."""
    if not re.fullmatch(r"[0-9a-fxA-FXsrc+\-*/()<>|& ]+", expr):
        raise Unplaceable("refusing to evaluate %r" % expr)
    return eval(expr, {"__builtins__": {}}, {"src": src})     # noqa: S307 - charset checked above


def check():
    """Gated cases. The last line is the tally `acceptance.py` reads."""
    cases = []

    def case(label, ok, detail=""):
        cases.append((bool(ok), label, detail))

    def report():
        bad = [c for c in cases if not c[0]]
        for ok, label, detail in cases:
            print("  %s  %s%s" % ("PASS" if ok else "FAIL", label,
                                  "" if ok or not detail else "  (%s)" % detail))
        print("%d/%d voice-descriptor case(s)" % (len(cases) - len(bad), len(cases)))
        return 0 if not bad else 1

    try:
        committed = json.loads((ROOT / OUT).read_text())
        case("the committed artefact parses", True)
    except (OSError, ValueError) as exc:
        case("the committed artefact parses", False, str(exc))
        return report()

    fresh = derive()

    # The artefact is derived, not edited: a fresh derivation must reproduce it byte for byte.
    case("the committed artefact equals a fresh derivation",
         render(committed) == render(fresh),
         "run --write")

    # Every field names a writer, and that writer's citation resolves to the statement it quotes.
    bad = []
    for group, f in _iter_fields(committed):
        if not f.get("writer"):
            bad.append("%s: no writer" % f.get("name"))
            continue
        for c in f["writer"]:
            try:
                cite_source(c)
            except Unplaceable as exc:
                bad.append("%s: %s" % (f.get("name"), exc))
    case("every field names a writer whose src/ citation resolves to the quoted statement "
         "(%d field(s))" % len(list(_iter_fields(committed))), not bad, "; ".join(bad[:3]))

    bad = []
    for group, f in _iter_fields(committed):
        for c in f.get("reader") or []:
            try:
                cite_source(c)
            except Unplaceable as exc:
                bad.append("%s: %s" % (f.get("name"), exc))
    case("every reader citation resolves too", not bad, "; ".join(bad[:3]))

    # And the offsets are the cartridge's, not this file's: re-decode each writer instruction.
    bad, pinned = [], 0
    for group, f in _iter_fields(committed):
        m = re.match(r"^instruction (0x[0-9a-f]{8}) \((\w+)\)$", f.get("evidence", ""))
        if not m:
            continue
        pinned += 1
        try:
            mnem, imm, width = decode(int(m.group(1), 16))
        except Unplaceable as exc:
            bad.append("%s: %s" % (f["name"], exc))
            continue
        if imm != f["offset"]:
            bad.append("%s: instruction writes +0x%x, field says +0x%x" % (f["name"], imm, f["offset"]))
        elif mnem != m.group(2):
            bad.append("%s: cartridge has %s at %s" % (f["name"], mnem, m.group(1)))
        elif width is not None and width != f["width"]:
            bad.append("%s: instruction is %d byte(s), field says %d" % (f["name"], width, f["width"]))
    case("every instruction-pinned offset and width is what the cartridge holds at that address "
         "(%d of %d field(s) pinned by an instruction)" % (pinned, len(list(_iter_fields(committed)))),
         not bad and pinned > 0, "; ".join(bad[:3]))

    bad = []
    for group, f in _iter_fields(committed):
        if re.match(r"^instruction ", f.get("evidence", "")):
            continue
        if not any(names_offset(c, f["offset"]) for c in f.get("writer") or []):
            bad.append("%s has no statement naming +0x%x" % (f["name"], f["offset"]))
    case("the fields not pinned by an instruction are pinned by a statement that names their offset",
         not bad, "; ".join(bad[:3]))

    levels = sorted({f.get("confidence") for group, f in _iter_fields(committed)})
    bad = [f["name"] for group, f in _iter_fields(committed)
           if f.get("confidence") == "established" and not f.get("reader")]
    case("every field is marked established or writer only, and every established field names a reader "
         "(%s%s)" % (", ".join(levels), "" if not bad else "; no reader: " + ", ".join(bad[:3])),
         levels == ["established", "writer only"] and not bad, "")

    # The slot table is two slots because the region ends where the sound globals start.
    desc = committed["descriptor"]
    span = addr(desc["base"]) + desc["slots"] * desc["stride"]
    case("two %#x-byte slots fit %s..%#x exactly and stop on the first sound global (%s)"
         % (desc["stride"], desc["base"], span, desc["end"]),
         span == addr(desc["end"]) and desc["slots"] == SLOT_COUNT, "spans to %#x" % span)
    try:
        for c in desc["end_evidence"]:
            cite_source(c)
        ok = True
    except Unplaceable as exc:
        ok = False
        case("the slot region's end is cited", False, str(exc))
    if ok:
        case("the slot region's end is cited to a statement that names the global it stops on", True)
    case("the stride is cited twice and both citations agree",
         len(desc["stride_evidence"]) >= 2 and all(
             "0x1228" in cite_source(c) for c in desc["stride_evidence"]), "")

    # The ring is one 4 KiB object and its two masks address it the same way.
    ring = committed["ring"]
    case("the ring ends exactly where the post-ring state begins: %#x + %#x == %#x"
         % (ring["offset"], ring["size"], STATE_OFF),
         offset_of_int(ring["offset"]) + ring["size"] == STATE_OFF, "")
    case("the fetch window and the bit reader address the same 4 KiB object: the fetch mask %#x is the "
         "chunk-granular one, the cursor mask %#x its 4-byte-granular superset, and both top out one byte "
         "short of %#x" % (ring["fetch_window_mask"], ring["read_window_mask"], ring["size"]),
         (ring["fetch_window_mask"] | 4) == ring["read_window_mask"] == ring["size"] - 4
         and ring["chunk"] == CHUNK, "")
    case("the ring's header offsets lie inside the first chunk, so one fetch brings the whole header",
         all(offset_of_int(ring["offset"]) <= row["offset"] < offset_of_int(ring["offset"]) + ring["chunk"]
             for row in ring["layout"]),
         "")
    unread = [row["name"] for row in ring["layout"] if not row["reader"]]
    case("the ring's rate halfword is reported as unread rather than mapped to a consumer "
         "(unread row(s): %s)" % ", ".join(unread), "header_rate" in unread, "")

    # The clip trace: every value chains to a stated source, and the arithmetic is re-run here.
    trace = committed["clip_trace"]
    rows = mort_records()
    seen, bad = {}, []
    for row in trace["values"]:
        src_kind, _, src_name = row["from"].partition(":")
        if src_kind == "cartridge":
            table = {"MORT+4": rows[trace["index"]][1], "MORT+6": rows[trace["index"]][2],
                     "MORT+8": rows[trace["index"]][3], "record_len": len(rows[trace["index"]][4]),
                     "header_bytes": MORT_HEADER}
            src = table.get(src_name)
            if src is None:
                bad.append("%s: unknown cartridge source %r" % (row["field"], src_name))
                continue
        elif src_kind == "trace":
            if src_name not in seen:
                bad.append("%s chains to %r, which is not traced above it" % (row["field"], src_name))
                continue
            src = seen[src_name]
        else:
            bad.append("%s: source %r is neither cartridge: nor trace:" % (row["field"], row["from"]))
            continue
        m = ARITH.match(row["via"])
        if not m:
            bad.append("%s: via is not an 'arith: ... @ src/...' hop" % row["field"])
            continue
        try:
            cite_source(m.group(2))
        except Unplaceable as exc:
            bad.append("%s: %s" % (row["field"], exc))
            continue
        try:
            want = _eval_arith(m.group(1), src)
        except (Unplaceable, SyntaxError, TypeError, ZeroDivisionError) as exc:
            bad.append("%s: %s" % (row["field"], exc))
            continue
        if want != row["value"]:
            bad.append("%s: %r evaluates to %r from %r" % (row["field"], row["value"], want, row["from"]))
            continue
        seen[row["field"]] = row["value"]
    case("every clip_trace value chains to a stated source and its arithmetic re-evaluates to it "
         "(%d value(s))" % len(trace["values"]), not bad, "; ".join(bad[:3]))

    k, blocks, rate, words, rec = rows[trace["index"]]
    totals = {r["field"]: r["value"] for r in trace["values"]}
    case("the traced clip is clip %d of %d, as the cartridge holds it (%d blocks, %d Hz, %d bytes)"
         % (k, len(rows), blocks, rate, len(rec)),
         trace["index"] == 0 and totals["record bytes"] == len(rec)
         and totals["+0x11a0 blocks_remaining"] == blocks
         and totals["+0x1208 rate"] == rate, "")
    case("the declared length reconciles with the record's own size: %d words * 4 == %d bytes"
         % (totals["+0x11a4 record_words_remaining"], totals["record bytes"]),
         totals["+0x11a4 record_words_remaining"] * 4 == len(rec), "")
    case("the tail chunk the reader derives from its own word counter is the record's real remainder "
         "(%d words * 4 == %d bytes after %d chunks)"
         % (totals["words left when the tail chunk is issued"], totals["tail chunk bytes"],
            totals["chunk count"]),
         totals["tail chunk bytes"] == len(rec) - (totals["chunk count"] - 1) * CHUNK,
         "")
    case("the PCM capacity is the 0x10e0 samples the sound init hard-codes, and its allocation is "
         "(%#x + 4) * 2 == %d bytes" % (totals["+0x1214 pcm_capacity_alloc"],
                                        totals["buffer allocation bytes"]),
         totals["+0x1214 pcm_capacity_alloc"] == 0x10E0
         and totals["buffer allocation bytes"] == (0x10E0 + 4) * 2
         and "FUN_800a9420(0x10e0)" in cite_source("src/stage2/FUN_800b40c4.c:36: FUN_800a9420(0x10e0);"), "")

    # The separation of the two halves.
    fields = [f["name"] for group, f in _iter_fields(committed)]
    at = " ".join(f["meaning"].lower() for group, f in _iter_fields(committed))
    spelled = sorted(w for w in OUTPUT_WORDS if w in at)
    case("no descriptor field's meaning claims microcode behaviour (%d field(s) checked)"
         % len(fields), not spelled, "RSP-only vocabulary in a field: %s" % ",".join(spelled))
    bad = []
    for entry in committed["rsp_only"]:
        if not entry.get("why_unobservable") or len(entry["why_unobservable"]) < 60:
            bad.append("%s: no reason" % entry.get("name"))
        if entry.get("name") in fields:
            bad.append("%s: also a descriptor field" % entry.get("name"))
        if not any(w in (entry["what"] + " " + entry.get("why_unobservable", "")).lower()
                   for w in OUTPUT_WORDS):
            bad.append("%s: carries none of the RSP vocabulary it is supposed to hold" % entry.get("name"))
    case("every rsp_only entry carries a reason, and none of them is also a descriptor field "
         "(%d entries)" % len(committed["rsp_only"]), not bad, "; ".join(bad[:3]))
    case("the rsp_only list is not empty - the mixer is the unreachable half, and it says so",
         len(committed["rsp_only"]) >= 4 and len(committed["unresolved"]) >= 3, "")

    bad = [q["question"] for q in committed["unresolved"]
           if not q.get("question", "").endswith("?") or not q.get("why")]
    case("every unresolved entry states a question and why it is open (%d entr(ies))"
         % len(committed["unresolved"]), not bad, "; ".join(bad[:2]))
    case("the unestablished rate hop is one of the unresolved entries",
         any("rate" in q["question"].lower() for q in committed["unresolved"]), "")

    hashes = []
    for entry in committed["inputs"]["sources"]:
        path = ROOT / entry["path"]
        if not path.exists() or hashlib.sha256(path.read_bytes()).hexdigest() != entry["sha256"]:
            hashes.append(entry["path"])
    case("the %d cited source(s) are unchanged since the map was derived"
         % len(committed["inputs"]["sources"]), not hashes, "drifted: %s" % ", ".join(hashes[:3]))

    lo = min(int(f["evidence"].split()[1], 16) for group, f in _iter_fields(committed)
             if f.get("evidence", "").startswith("instruction "))
    hi = max(int(f["evidence"].split()[1], 16) for group, f in _iter_fields(committed)
             if f.get("evidence", "").startswith("instruction "))
    case("every pinned instruction lies inside the stage-2 member (%#x..%#x over %#x..%#x)"
         % (lo, hi, STAGE2_BASE, STAGE2_BASE + STAGE2_LEN),
         STAGE2_BASE <= lo and hi + 4 <= STAGE2_BASE + STAGE2_LEN, "")

    bodies = stage2_bodies()
    inside = sorted(n for n, start, end in bodies
                    if start < UCODE_BLOB + 0x1000 and end > UCODE_BLOB)
    case("the task block's blob range is mostly outside the corpus and overruns one body, which is why its "
         "meaning is left open (%d body/bodies inside %s..%s: %s)"
         % (len(inside), hexstr(UCODE_BLOB), hexstr(UCODE_BLOB + 0x1000), ", ".join(inside)),
         inside == ["FUN_800b3640"] and len(bodies) > 500, "bodies: %s" % ", ".join(inside[:4]))

    hits = rate_halfword_readers()
    stack = [hexstr(pc) for pc, op, base in hits if base == 29]
    case("no instruction of the stage-2 image reads the record's rate halfword: %d displacement(s) reach "
         "ring+6 or ring+7 and every one is a stack access (%s)"
         % (len(hits), ", ".join(stack) or "none"),
         all(base == 29 for pc, op, base in hits) and len(hits) < 6, "hit(s): %s" % hits[:4])

    raw = (ROOT / OUT).read_text()
    longest = max(len(s) for s in _strings(committed))
    case("the artefact carries no cartridge payload: %d bytes, longest string %d characters"
         % (len(raw), longest), len(raw) < 4 * 1024 * 1024 and longest < 600, "")

    return report()


def _strings(node):
    if isinstance(node, str):
        yield node
    elif isinstance(node, dict):
        for key, value in node.items():
            yield key
            for s in _strings(value):
                yield s
    elif isinstance(node, list):
        for value in node:
            for s in _strings(value):
                yield s


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true", help="regenerate %s" % OUT)
    ap.add_argument("--check", action="store_true", help="validate the committed artefact")
    args = ap.parse_args()
    if not (args.write or args.check):
        ap.error("one of --write or --check is required")

    if not ROM.exists():
        try:
            where = ROM.relative_to(ROOT)
        except ValueError:
            where = ROM
        print("SKIP: no cartridge at %s — every voice-descriptor case needs it" % where)
        return 0

    if args.write:
        try:
            artefact = derive()
        except Unplaceable as exc:
            print("FAIL: the map does not survive its own derivation — %s" % exc)
            return 1
        path = ROOT / OUT
        path.write_text(render(artefact))
        desc = artefact["descriptor"]
        print("-> %s (base %s, stride %#x, %d slot(s), %d descriptor field(s), %d rsp_only entr(ies))"
              % (OUT, desc["base"], desc["stride"], desc["slots"], len(desc["fields"]),
                 len(artefact["rsp_only"])))
        return 0

    try:
        return check()
    except Unplaceable as exc:
        print("FAIL: %s" % exc)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
