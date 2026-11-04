/* func_800aa8dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aa8dc  body 0x800aa8dc..0x800aa93f  size 100 B
 * body sha256 fcd52e17d611d733d099f3c56d80a1f6e8a7ce414ebcc6ee0f5ba3d73706312b
 * provider record sha256 935e29b06dc80e4f2f90ad7866ecf53972e16a4650f3ab1c81a49a73821320d7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800aa8dc(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    if ((*(uint *)(param_1 + 8) & 0x10000) != 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x34);
    }
    FUN_800a56c0();
  }
  return uVar1;
}
