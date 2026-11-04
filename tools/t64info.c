/* t64info.c - parse a T64 texture block and check the laws in include/re2_formats.h.
 *
 * Usage: t64info <block.bin>
 * Exit 0 if the block satisfies the format; 1 otherwise (so a gate can assert both directions).
 * The input is an *already decompressed* block: the cartridge stores these as zlib members, which
 * tools/unpack_zlib.py extracts, and the loader inflates before use.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/re2_formats.h"

static uint16_t be16(const uint8_t *p) { return (uint16_t)((p[0] << 8) | p[1]); }

int main(int argc, char **argv)
{
    if (argc != 2) { fprintf(stderr, "usage: %s <block.bin>\n", argv[0]); return 2; }

    FILE *f = fopen(argv[1], "rb");
    if (!f) { perror("open"); return 2; }
    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (len < (long)RE2_T64_HDR_LEN) { fprintf(stderr, "too short: %ld\n", len); fclose(f); return 1; }

    uint8_t *buf = malloc((size_t)len);
    if (!buf || fread(buf, 1, (size_t)len, f) != (size_t)len) { perror("read"); fclose(f); free(buf); return 2; }
    fclose(f);

    re2_t64_header h;
    h.magic           = be16(buf + 0);
    h.height          = be16(buf + 2);
    h.width           = be16(buf + 4);
    h.height_8bpp     = be16(buf + 6);
    h.format          = be16(buf + 8);
    h.palette_entries = be16(buf + 10);
    h.unknown_12      = be16(buf + 12);
    h.unknown_14      = be16(buf + 14);

    int checks = 0, passed = 0;
#define CHECK(name, cond) do { checks++; if (cond) { passed++; printf("  PASS %s\n", name); } \
                               else printf("  FAIL %s\n", name); } while (0)

    printf("T64 block %s: %ld bytes\n", argv[1], len);
    printf("  magic 0x%04x  height %u  width %u  height_8bpp %u  format %u  palette %u\n",
           h.magic, h.height, h.width, h.height_8bpp, h.format, h.palette_entries);

    CHECK("magic is 0xBE1E", h.magic == RE2_T64_MAGIC);
    CHECK("format is 4 bpp or 8 bpp", h.format == RE2_T64_FMT_CI4 || h.format == RE2_T64_FMT_CI8);
    CHECK("palette is 16 or 256 entries", h.palette_entries == 16 || h.palette_entries == 256);
    CHECK("height_8bpp == height * bpp / 8", h.height_8bpp == (uint16_t)(h.height * 8u / (unsigned)re2_t64_bpp(&h)));
    CHECK("block length == 16 + palette*2 + w*h*bpp/8", (size_t)len == re2_t64_expected_len(&h));
    CHECK("both reserved words are zero", h.unknown_12 == 0 && h.unknown_14 == 0);

    printf("%d/%d t64info check(s)\n", passed, checks);
    free(buf);
    return passed == checks ? 0 : 1;
}
