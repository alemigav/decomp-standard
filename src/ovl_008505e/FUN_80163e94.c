/* FUN_80163e94
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163e94  body 0x80163e94..0x80163f0f  size 124 B
 * body sha256 a474bd91525a1a94d7f8bf42b9727ef5faf80c41d6b75e317789792935ef4aac
 * provider record sha256 ab87468db07ca9236cd2d5efcf0e9997817f3d751d29b23a511433e16cfa78a7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163e94(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0x3c;
    *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
  }
  sVar1 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar1 + -1;
  if (sVar1 == 1) {
    *(undefined1 *)(param_1 + 5) = 0;
    *(undefined2 *)(param_1 + 6) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000f00;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  FUN_801664d8(param_1);
  return;
}
