/* FUN_80070120
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80070120  body 0x80070120..0x800701d7  size 184 B
 * body sha256 059124164ee5297675a97c8d51432a62982b9636fbb050abccfbc4444e6fdbde
 * recovered byte-exact (p9: 46 of 46)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as P9_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

struct Ctx {
    u8 pad0[0x1c];
    u8 *ptr;
    u8 pad20[0x134];
    u8 *f154;
};

extern int FUN_800701d8(u8 *p, int a1);

int FUN_80070120(struct Ctx *s)
{
    u8 *p;
    unsigned int w;
    int v;
    int x;

    p = s->ptr;
    w = *(u16 *)(p + 2);
    v = *(s16 *)(p + 4);
    s->ptr = p + 6;
    x = FUN_800701d8(s->f154, w >> 8);

    switch (w & 0xff) {
    case 0: return x == v;
    case 1: return x > v;
    case 2: return x >= v;
    case 3: return x < v;
    case 4: return x <= v;
    case 5: return x != v;
    case 6: return (x & v) != 0;
    }
}
