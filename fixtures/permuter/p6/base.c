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
          if (s->b1 == 0) { s->b0 = 131; s->b1 = s->b1 + s->b2; } break;
  }
}
