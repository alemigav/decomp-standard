/* FUN_80024558
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80024558  body 0x80024558..0x80024783  size 556 B
 * body sha256 6ad71aaba8cd81874dab482f0f69a9197f528ac11c58c6710d66f2765dc6b44f
 * recovered byte-exact (p8: 139 of 139)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as P8_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
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
}
