/* FUN_80057e1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80057e1c  body 0x80057e1c..0x80057f6b  size 336 B
 * body sha256 cc7459788028f0ee2ff4daadfa464a1a9e0c11f04a2e33ff8ea6455f06c619ef
 * recovered byte-exact (p7: 84 of 84)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as P7_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char  u8;
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
}
