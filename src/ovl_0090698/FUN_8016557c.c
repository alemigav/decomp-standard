/* FUN_8016557c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016557c  body 0x8016557c..0x801655df  size 100 B
 * body sha256 4f1d59e1ed2ca76e7425b116fa15d361e124b5abe1273be7df8cf166cdc0961d
 * provider record sha256 b2a8d57805bdc5f79ba566f625aa51fa4e5bcc49e64c2a423dc8781ce438c932
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016557c(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined1 *)(param_1 + 0x2d7) = 0x14;
  FUN_8016703c(param_1,0,10);
  *(undefined1 *)(param_1 + 5) = 7;
  FUN_80164a78(param_1,param_2,param_3);
  return;
}
