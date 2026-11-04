/* FUN_80164734
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164734  body 0x80164734..0x801647c7  size 148 B
 * body sha256 090adbed7e5be3b380f025715e82441fb0ae8b9b42ec4d576bf9ea6f58aa7e2d
 * provider record sha256 22a25ba8c0628986091950ffa5c1f33b88e6ae01bf6ff344354c3311696da268
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164734(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 0x2d8) = *(undefined1 *)(param_1 + 5);
  }
  if (*(short *)(param_1 + 0x1a8) == 0) {
    uVar1 = func_0x80074d64(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x30));
    *(undefined2 *)(param_1 + 0x1a8) = uVar1;
  }
  (*(code *)(&PTR_FUN_80167e8c)[*(byte *)(param_1 + 5) - 1])(param_1,param_2,param_3);
  return;
}
