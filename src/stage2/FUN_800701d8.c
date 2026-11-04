/* FUN_800701d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800701d8  body 0x800701d8..0x8007040b  size 564 B
 * body sha256 7f6278acad1c1191c81cebcc85f65cd18922b2b248009d1bc3748c9e858d4b4c
 * recovered byte-exact (p701d8: 141 of 141)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as P701D8_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

struct T {
    u16  f0;
    u16  f2;
    u8   f4;
    u8   f5;
    u8   f6;
    u8   f7;
    u8   f8;
    u8 pad9[1];
    u8   f10;
    u8   f11;
    u8 pad12[4];
    u32  f16;
    u8 pad20[20];
    u32  f40;
    u32  f44;
    u32  f48;
    u8 pad52[48];
    s16  f100;
    s16  f102;
    s16  f104;
    u8 pad106[198];
    s16  f304;
    s16  f306;
    s16  f308;
    u16  f310;
    u16  f312;
    u16  f314;
    u8 pad316[102];
    u8   f418;
    u8 pad419[7];
    u16  f426;
    u8 pad428[8];
    s16  f436;
    s16  f438;
    u8 pad440[40];
    union { u8 b; s16 h; } f480;
    s16  f482;
    s16  f484;
    u8 pad486[4];
    u8   f490;
    u8 pad491[5];
    u16  f496;
    u8 pad498[108];
    s16  f606;
    s16  f608;
    s16  f610;
    u8 pad612[4];
    u16  f616;
    u8 pad618[5];
    u8   f623;
    s16  f624;
    s16  f626;
    s16  f628;
    s16  f630;
    u8 pad632[2];
    s16  f634;
    u8 pad636[56];
    u16  f692;
    u16  f694;
};

u32 FUN_800701d8(struct T *p, u32 idx)
{
    switch (idx) {
    case 1: return p->f0;
    case 0: return p->f2;
    case 2: return p->f4;
    case 3: return p->f5;
    case 4: return p->f6;
    case 5: return p->f7;
    case 6: return p->f8;
    case 7: return p->f426;
    case 8: return p->f10;
    case 9: return p->f11;
    case 10: return p->f16;
    case 11: return p->f40;
    case 12: return p->f44;
    case 13: return p->f48;
    case 14: return p->f100;
    case 15: return p->f102;
    case 16: return p->f104;
    case 17: return p->f418;
    case 18: return p->f496;
    case 19: return p->f606;
    case 20: return p->f608;
    case 21: return p->f610;
    case 22: return p->f616;
    case 23: return p->f624;
    case 24: return p->f626;
    case 25: return p->f628;
    case 26: return p->f630;
    case 27: return p->f480.b;
    case 28: return p->f480.h;
    case 29: return p->f482;
    case 30: return p->f484;
    case 31: return p->f490;
    case 32: return p->f304;
    case 33: return p->f308;
    case 34: return p->f306;
    case 35: return p->f310;
    case 36: return p->f314;
    case 37: return p->f312;
    case 38: return p->f634;
    case 39: return p->f436;
    case 40: return p->f438;
    case 41: return p->f692;
    case 42: return p->f694;
    case 43: return p->f623;
    }
}
