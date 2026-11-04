/* FUN_80162748
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162748  body 0x80162748..0x801627c7  size 128 B
 * body sha256 0722c563020af107e840fd41161e210d535fc6438cad0dce7acfe279dd68d08f
 * provider record sha256 d9d716d8d0e5f0309a3fddf7f5628c550196e7f161b087da6a8109b51ae14462
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162748(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_80166d98)[*(byte *)(param_1 + 6)])();
  func_0x80089d54(param_1,param_2,param_3,0x100);
  FUN_801664d8(param_1);
  FUN_80166b60(param_1);
  FUN_80166ba0(param_1);
  return;
}
