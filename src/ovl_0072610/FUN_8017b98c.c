/* FUN_8017b98c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b98c  body 0x8017b98c..0x8017b9bb  size 48 B
 * body sha256 93586150a213ef2578b3bcb7d891839cf011703c5de52c29039c442ace26d241
 * provider record sha256 61553e7bd6717cc221a22593d5ff6c423e199b140660b329396b3ad944f6d474
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8017b98c(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_8017b8f4();
  uVar2 = FUN_8017b8f4();
  return iVar1 << 8 | uVar2;
}
