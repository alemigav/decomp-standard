/* FUN_8006e68c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e68c  body 0x8006e68c..0x8006e72f  size 164 B
 * body sha256 d9b36ac47d0cfd9fd734d2aaa7cd13a035029c2e8f8f3c955a741f3499e79128
 * recovered byte-exact (p6e68c: 41 of 41)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as P6E68C_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char  u8;
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
}
