/* FUN_80007a9c
 * image   boot (boot), base 0x80000480
 * address 0x80007a9c  body 0x80007a9c..0x80007b6b  size 208 B
 * body sha256 cb277fb4b5253df7a68b2048158ceac3d4a09148d0425b28fac50dd08e47d707
 * provider record sha256 8539e157814b2f194286d65dfb77e1d7bcb15b4499052ff4b63f37b752dfc481
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80007a9c(void)

{
  do {
  } while ((_DAT_a4600010 & 3) != 0);
  do {
  } while ((_DAT_a4600010 & 3) != 0);
  _DAT_a5000510 = *(undefined4 *)(_DAT_80016224 + 0x24);
  FUN_80007b6c();
  _DAT_a4600010 = 2;
  _DAT_800128d0 = _DAT_800128d0 | 0x100401;
  return;
}
