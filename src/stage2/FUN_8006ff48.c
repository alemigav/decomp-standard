/* FUN_8006ff48
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ff48  body 0x8006ff48..0x800700cf  size 392 B
 * body sha256 71d297cf11b762a287e72163e484cdeff5af5b2b4dc171f842a04aab5f7de3dc
 * recovered byte-exact (p6ff48: 98 of 98)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as P6FF48_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FUN_8006ff48(u8 *p, u32 idx, u32 v)
{
    switch (idx) {
    case 1: *(u16 *)(p + 0) = v; break;
    case 0: *(u16 *)(p + 2) = v; break;
    case 2: *(u8 *)(p + 4) = v; break;
    case 3: *(u8 *)(p + 5) = v; break;
    case 4: *(u8 *)(p + 6) = v; break;
    case 5: *(u8 *)(p + 7) = v; break;
    case 6: *(u8 *)(p + 8) = v; break;
    case 7: *(u16 *)(p + 426) = v; break;
    case 8: *(u8 *)(p + 10) = v; break;
    case 9: *(u8 *)(p + 11) = v; break;
    case 10: *(u32 *)(p + 16) = v; break;
    case 11: *(u32 *)(p + 40) = v; break;
    case 12: *(u32 *)(p + 44) = v; break;
    case 13: *(u32 *)(p + 48) = v; break;
    case 14: *(u16 *)(p + 100) = v; break;
    case 15: *(u16 *)(p + 102) = v; break;
    case 16: *(u16 *)(p + 104) = v; break;
    case 17: *(u8 *)(p + 418) = v; break;
    case 18: *(u16 *)(p + 496) = v; break;
    case 19: *(u16 *)(p + 606) = v; break;
    case 20: *(u16 *)(p + 608) = v; break;
    case 21: *(u16 *)(p + 610) = v; break;
    case 22: *(u16 *)(p + 616) = v; break;
    case 23: *(u16 *)(p + 624) = v; break;
    case 24: *(u16 *)(p + 626) = v; break;
    case 25: *(u16 *)(p + 628) = v; break;
    case 26: *(u16 *)(p + 630) = v; break;
    case 27: *(u8 *)(p + 480) = v; break;
    case 28: *(u16 *)(p + 480) = v; break;
    case 29: *(u16 *)(p + 482) = v; break;
    case 30: *(u16 *)(p + 484) = v; break;
    case 31: *(u8 *)(p + 490) = v; break;
    case 32: *(u16 *)(p + 304) = v; break;
    case 33: *(u16 *)(p + 308) = v; break;
    case 34: *(u16 *)(p + 306) = v; break;
    case 35: *(u16 *)(p + 310) = v; break;
    case 36: *(u16 *)(p + 314) = v; break;
    case 37: *(u16 *)(p + 312) = v; break;
    case 38: *(u16 *)(p + 634) = v; break;
    case 39: *(u16 *)(p + 436) = v; break;
    case 40: *(u16 *)(p + 438) = v; break;
    case 41: *(u16 *)(p + 692) = v; break;
    case 42: *(u16 *)(p + 694) = v; break;
    case 43: *(u8 *)(p + 623) = v; break;
    }
}
