/* FUN_80059530
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059530  body 0x80059530..0x80059867  size 824 B
 * body sha256 4e9130daac83a293ebfb9c3b51dafd722fbed4ab4a82b71a1a33cae2667792bf
 * recovered byte-exact (p59530: 206 of 206)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as P59530_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char  u8;
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
}
