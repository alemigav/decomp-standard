/* FUN_800704e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800704e0  body 0x800704e0..0x800706cb  size 492 B
 * body sha256 7415b4cb88158b39d1dff9ca4bfcf9b6545fdbbf4da22086e80f02afd773b433
 * recovered byte-exact (p704e0: 123 of 123)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as P704E0_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 D_80115120;

u8 *FUN_800704e0(u8 *p, u32 idx)
{
    switch (idx) {
    case 1:
        return p;
        break;
    case 0:
        return p + 2;
        break;
    case 2:
        D_80115120++;
        return p + 4;
        break;
    case 3:
        D_80115120++;
        return p + 5;
        break;
    case 4:
        D_80115120++;
        return p + 6;
        break;
    case 5:
        D_80115120++;
        return p + 7;
        break;
    case 6:
        D_80115120++;
        return p + 8;
        break;
    case 7:
        return p + 426;
        break;
    case 8:
        D_80115120++;
        return p + 10;
        break;
    case 9:
        D_80115120++;
        return p + 11;
        break;
    case 10:
        return p + 16;
        break;
    case 11:
        return p + 40;
        break;
    case 12:
        return p + 44;
        break;
    case 13:
        return p + 48;
        break;
    case 14:
        return p + 100;
        break;
    case 15:
        return p + 102;
        break;
    case 16:
        return p + 104;
        break;
    case 17:
        return p + 418;
        break;
    case 18:
        return p + 496;
        break;
    case 19:
        return p + 606;
        break;
    case 20:
        return p + 608;
        break;
    case 21:
        return p + 610;
        break;
    case 22:
        return p + 616;
        break;
    case 23:
        return p + 624;
        break;
    case 24:
        return p + 626;
        break;
    case 25:
        return p + 628;
        break;
    case 26:
        return p + 630;
        break;
    case 27:
        D_80115120++;
        return p + 480;
        break;
    case 28:
        return p + 480;
        break;
    case 29:
        return p + 482;
        break;
    case 30:
        return p + 484;
        break;
    case 31:
        D_80115120++;
        return p + 490;
        break;
    case 32:
        return p + 304;
        break;
    case 33:
        return p + 308;
        break;
    case 34:
        return p + 306;
        break;
    case 35:
        return p + 310;
        break;
    case 36:
        return p + 314;
        break;
    case 37:
        return p + 312;
        break;
    case 38:
        return p + 634;
        break;
    case 39:
        return p + 436;
        break;
    case 40:
        return p + 438;
        break;
    case 41:
        return p + 692;
        break;
    case 42:
        return p + 694;
        break;
    case 43:
        D_80115120++;
        return p + 623;
        break;
    }
}
