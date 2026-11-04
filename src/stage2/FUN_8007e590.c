/* FUN_8007e590
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e590  body 0x8007e590..0x8007e923  size 916 B
 * body sha256 fe21c08aaf6088f878899b23bdee806226d220d20c65e14e83ab8d45deea160b
 * recovered partial: 226 of 229, three words of allocation (p7e590: 226 of 229)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as P7E590_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
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
}
