/* FUN_8004fd1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004fd1c  body 0x8004fd1c..0x8004fea3  size 392 B
 * body sha256 5a02544da004f7d05aff632616bb2a8ebb6063699cb83efcea4a74b317992be8
 * recovered byte-exact (p6: 98 of 98 by offset and content)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as P6_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef struct { unsigned char b0, b1, b2, b3; } S;
void f(S *s, short *p, int idx) {
  switch (idx) {
  case 0: *p = s->b3 << 4; break;
  case 1: *p = (s->b1 / s->b2) << 4;
          if (s->b1 == s->b3 * s->b2 - 1) break;
          s->b1 = s->b1 + 1; break;
  case 2: *p = (s->b1 / s->b2) << 4;
          s->b1 = s->b1 + 1;
          if ((unsigned char)s->b1 != s->b3 * s->b2) break;
          s->b1 = 0; break;
  case 3: *p = (s->b1 / s->b2) << 4;
          s->b1 = s->b1 + 1;
          if ((unsigned char)s->b1 != s->b3 * s->b2) break;
          s->b1 = s->b1 - s->b2; s->b0 = 132; break;
  case 4: s->b1 = s->b1 - 1;
          *p = (s->b1 / s->b2) << 4;
          if (s->b1 == 0) { s->b1 = s->b1 + s->b2; s->b0 = 131; } break;
  }
}
