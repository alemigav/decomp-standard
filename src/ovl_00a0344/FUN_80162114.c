/* FUN_80162114
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162114  body 0x80162114..0x8016218f  size 124 B
 * body sha256 ac451ccd240b71d6350b736972ace19c2e3ae3a9d0f527a6690306064aa255a7
 * provider record sha256 34a0ee5fb683e760e756dcbdfce9a91f5bd9bdd078b0dbd7295f2971c2c3383c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162114(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x2c2) = 0;
    *(undefined2 *)(param_1 + 700) = *(undefined2 *)(param_1 + 0x2c0);
    *(uint *)(param_1 + 0x1e8) =
         (uint)*(byte *)(param_1 + 5) * 0x1000000 +
         ((uint)*(byte *)(param_1 + 0x2b4) << (*(byte *)(param_1 + 5) + 2 & 0x1f)) * 0x10000 + 0x700
    ;
  }
  func_0x80089d54(param_1,param_2,param_3,0x200);
  FUN_8016375c(param_1,0);
  return;
}
