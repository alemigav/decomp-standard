/* FUN_80004c34
 * image   boot (boot), base 0x80000480
 * address 0x80004c34  body 0x80004c34..0x80004c6b  size 56 B
 * body sha256 9d729c392e42815f928a4cdd8fe22ee7fd15b864ab2595b6e7dcdc0dc4c70805
 * provider record sha256 fd00a33dfd7c1828385c7b6f47834232e22f2bf13d93d97ed23afd19a80aca9c
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80004c34(void)

{
  char cVar1;
  
  cVar1 = func_0x800b43a0(_DAT_80012878);
  if (cVar1 == '\0') {
    _DAT_80012884 = 3;
  }
  return;
}
