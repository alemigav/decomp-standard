/* FUN_800acae4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800acae4  body 0x800acae4..0x800acbb7  size 212 B
 * body sha256 da07c38baa55ef26e87c25bba601763393d776e85bee218f731aa0f493587f70
 * recovered byte-exact (pacae4: 53 of 53)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as PACAE4_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

struct Snd {
    u8 pad0[0x4a];
    u8 f4a;
    u8 f4b;
};

extern void FUN_800ab7e0(u32 a0, u32 a1, u32 a2, u16 a3);

void FUN_800acae4(struct Snd *s, u32 cmd, s16 v)
{
    int c;
    u32 id;

    id = (u32)s;
    v = v < 0 ? 0 : (v >= 0x4000 ? 0x3fff : v);
    c = cmd;
    switch (cmd & 0xff) {
    case 0x80:
        c = 0x80;
        break;
    case 0x81:
        c = 0x82;
        break;
    case 0x82:
        c = 0xa0;
        break;
    case 0x83:
        c = 0xa1;
        break;
    case 0x84:
        c = 0x83;
        break;
    case 0x85:
        c = 0x84;
        break;
    }
    if ((c & 0xff) < 0xa2) {
        if ((c & 0xff) >= 0xa0)
            return;
    }
    if (s->f4a == 0xff)
        return;
    id = (u8)cmd;
    cmd = s->f4a;
    FUN_800ab7e0(id, cmd, s->f4b, v);
}
