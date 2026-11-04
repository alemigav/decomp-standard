/* FUN_80004bac
 * image   boot (boot), base 0x80000480
 * address 0x80004bac  body 0x80004bac..0x80004be3  size 56 B
 * body sha256 2d930f5040d6aca70664230cf121834c6548231f0ce850a3e96077bd18761cc8
 * provider record sha256 dc8b35ae61b6aa3b42a090635ceaf435893171a749216d8322b65f09b60186ae
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80004bac(void)

{
  (**(code **)(_DAT_80012884 * 4 + -0x7ffed774))();
  return;
}
