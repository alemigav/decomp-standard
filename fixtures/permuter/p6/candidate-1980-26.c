
typedef struct 
{
  unsigned char b0;
  unsigned char b1;
  unsigned char b2;
  unsigned char b3;
} S;
inline unsigned char inline_fn(S *arg0)
{
  return arg0->b2;
}

inline unsigned char inline_fn2(S *arg0)
{
  return arg0->b1;
}

void f(S *s, short *p, int idx)
{
  switch (idx)
  {
    case 0:
      *p = s->b3 << 4;
      break;

    case 1:
      *p = (inline_fn2(s) / inline_fn(s)) << 4;
      if (inline_fn2(s) == ((s->b3 * s->b2) - 1))
    {
      break;
    }
      s->b1 = s->b1 + 1;
      break;

    case 2:
      *p = (inline_fn2(s) / s->b2) << 4;
      s->b1 = s->b1 + 1;
      if (((unsigned char) s->b1) != (s->b3 * inline_fn(s)))
    {
      break;
    }
      s->b1 = 0;
      break;

    case 3:
      *p = (inline_fn2(s) / inline_fn(s)) << 4;
      s->b1 = s->b1 + 1;
      if (((unsigned char) s->b1) != (s->b3 * s->b2))
    {
      break;
    }
      s->b1 = s->b1 - s->b2;
      s->b0 = 132;
      break;

    case 4:
      s->b1 = inline_fn2(s) - 1;
      *p = (s->b1 / s->b2) << 4;
      if (s->b1 == 0)
    {
      s->b0 = 131;
      s->b1 = inline_fn2(s) + inline_fn(s);
    }
      break;

  }

}
