/* re2_formats.h - the formats this project has measured, for a rebuild to consume.
 *
 * Every constant here comes from a measurement recorded in docs/log/M136-M171 and is gated:
 * tools/t64info.c includes this header and checks a real block, and tools/acceptance.py runs it.
 * Where a field is still unknown it is named unknown_* and left alone rather than guessed.
 */
#ifndef RE2_FORMATS_H
#define RE2_FORMATS_H

#include <stdint.h>
#include <stddef.h>

/* ---- the script VM (M136-M171) ---------------------------------------------------------------- */

#define RE2_SCD_TABLE_ENTRIES 141      /* the opcode -> handler table at 0x80113898, zero-terminated */

/* Command length per opcode, in bytes: each handler advances ctx+0x1c by its own amount (M136/M159).
 * 0 means "no constant advance" - the handler computes the pointer (jump, return, or block runner). */
static const uint8_t re2_scd_length[RE2_SCD_TABLE_ENTRIES] = {
     1,  0,  1,  0,  4,  2,  4,  4,  2,  1,  3,  1,
     1,  6,  2,  4,  0,  4,  2,  4,  6,  2,  2,  6,
     2,  0,  0,  6,  1,  4,  1,  1,  1,  4,  4,  6,
     4,  3,  6,  4,  1,  2,  1,  6, 20, 38,  3,  4,
     1,  1,  8,  8,  4,  3,  0,  4,  3,  8, 16, 32,
     2,  3,  6,  4,  8, 10,  1,  4, 22,  5, 10,  2,
    16,  8,  2,  3,  5, 22, 22,  4,  4,  6,  6,  6,
    22,  6,  4,  8,  4,  4,  2,  2,  3,  2,  2,  2,
    14,  4,  2,  1, 16,  2,  1, 28, 40, 30,  6,  4,
     1,  4,  6,  2,  1,  1, 16,  8,  4, 22,  3,  4,
     6,  1, 16, 16,  6,  6,  6,  6,  2,  3,  3,  1,
     2,  6,  1,  1,  3,  1,  6,  6,  8,
};

/* Opcodes with a fixed meaning, named from the licensed PlayStation table where it has one (M141). */
enum re2_scd_opcode {
    RE2_SCD_EVENT_EXEC    = 0x04, RE2_SCD_IF_ELSE_START = 0x06, RE2_SCD_ELSE_START = 0x07,
    RE2_SCD_SWITCH_CASE   = 0x14, RE2_SCD_GOTO          = 0x17, RE2_SCD_GOSUB      = 0x18,
    RE2_SCD_CHECK_BIT     = 0x21, RE2_SCD_SET_BIT       = 0x22, RE2_SCD_COMPARE    = 0x23,
    RE2_SCD_AOT_SET       = 0x2C, RE2_SCD_MEMBER_SET    = 0x34, RE2_SCD_DOOR_AOT   = 0x3B,
    RE2_SCD_SCE_EM_SET    = 0x44, RE2_SCD_PLC_NECK      = 0x41, RE2_SCD_DOOR_MODEL = 0x4D,
};

/* The scene-slot command (0x44 SceEmSet): byte 3 is the enemy Id, which the port resolves through a
 * map into a cartridge bank record (M94/M110/M145). */
#define RE2_SCD_SCE_EM_SET_LEN 22
#define RE2_SCD_SCE_EM_ID_BYTE 3

/* ---- T64 textures (M164-M167) ------------------------------------------------------------------ */

#define RE2_T64_MAGIC   0xBE1Eu
#define RE2_T64_HDR_LEN 16u
#define RE2_T64_FMT_CI4 1u             /* 4 bpp: two indices per byte, 16-entry palette */
#define RE2_T64_FMT_CI8 2u             /* 8 bpp: one index per byte, 256-entry palette */

typedef struct {                       /* big-endian on the wire */
    uint16_t magic;                    /* 0xBE1E */
    uint16_t height;                   /* TRUE pixel height (M166) */
    uint16_t width;
    uint16_t height_8bpp;             /* height * bpp / 8 - the field 4bpp tiles halve */
    uint16_t format;                   /* RE2_T64_FMT_* */
    uint16_t palette_entries;          /* 16 or 256 */
    uint16_t unknown_12;               /* always 0 in the 65 sampled tiles */
    uint16_t unknown_14;               /* always 0 */
} re2_t64_header;

static inline int re2_t64_bpp(const re2_t64_header *h) {
    return h->format == RE2_T64_FMT_CI8 ? 8 : 4;
}

/* palette + raw pixels; no compression anywhere (M165) */
static inline size_t re2_t64_pixel_bytes(const re2_t64_header *h) {
    return (size_t)h->width * h->height * (size_t)re2_t64_bpp(h) / 8u;
}
static inline size_t re2_t64_expected_len(const re2_t64_header *h) {
    return RE2_T64_HDR_LEN + (size_t)h->palette_entries * 2u + re2_t64_pixel_bytes(h);
}

/* the two laws M165 and M166 gated */
static inline int re2_t64_valid(const re2_t64_header *h, size_t block_len) {
    if (h->magic != RE2_T64_MAGIC) return 0;
    if (h->format != RE2_T64_FMT_CI4 && h->format != RE2_T64_FMT_CI8) return 0;
    if (h->palette_entries != 16u && h->palette_entries != 256u) return 0;
    if (h->height_8bpp != (uint16_t)(h->height * 8u / (unsigned)re2_t64_bpp(h))) return 0;
    return block_len == re2_t64_expected_len(h);
}

/* ---- the model container (M157-M163) ----------------------------------------------------------- */

#define RE2_MODEL_VERSION_321 0x0141u  /* the first halfword: a format version, not a magic */
#define RE2_MODEL_HDR_LEN     0x20u

typedef struct {
    uint16_t version;                  /* 0x0141 */
    uint16_t flags;                    /* 0 when the block still needs relocation */
    uint32_t field_4;
    uint32_t next_section;             /* relocated: += block base by FUN_800824b8 */
    uint32_t field_12;
    uint32_t field_16;
    uint32_t count;
} re2_model_header;

/* ---- room resources ---------------------------------------------------------------------------- */

/* DAT_80131fa8 maps a room byte to a file id; 256 entries, because the index is a byte (M157). */
#define RE2_ROOM_TABLE_ENTRIES 256

/* the section tags the loader passes to func_0x80004cfc (M162) */
static const char *const re2_resource_tags[] = {
    "RID", "FLR", "SCA", "RVD", "LIT", "SCD", "PR2", "BLK", "E64", "MSG", "OMD", "EDT",
    "TM3", "EMD", "EFF", "ITP", "TIM", "T64",
};

#endif /* RE2_FORMATS_H */
