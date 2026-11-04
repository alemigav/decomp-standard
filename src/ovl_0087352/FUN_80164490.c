/* FUN_80164490
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80164490  body 0x80164490..0x80164503  size 116 B
 * body sha256 a41a45edca17b8392216d2d9e22ce8ca07c47e7713cfcb10bfd9eb4372f4b12a
 * provider record sha256 ec1da804f993e71f1589bc413db5ed3c120e2f1f5bf5e488b4873dca19dcc84f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164490(int param_1,undefined4 param_2,undefined4 param_3)

{
  func_0x800653d0(param_1,&DAT_800e1158,0,0);
  (*(code *)(&PTR_FUN_80166680)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
