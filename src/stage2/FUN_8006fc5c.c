/* FUN_8006fc5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fc5c  body 0x8006fc5c..0x8006fd2f  size 212 B
 * body sha256 50cec2e8f833fa57e558125a0fe44ddf89ff0fcba539d0e525cf5ab30190388e
 * recovered byte-exact (p6fc5c: 53 of 53)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as P6FC5C_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char  u8;
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
}
