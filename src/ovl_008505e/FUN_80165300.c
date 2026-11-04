/* FUN_80165300
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165300  body 0x80165300..0x80165387  size 136 B
 * body sha256 878a0a48962792a7ac2eac01f93965990ed0878625071e2140b19a8a33c0045a
 * provider record sha256 ef670bc8ea7d34554537755c8da878e4d8ff382625c81082073eefb874dcb7d3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165300(int param_1)

{
  uint uVar1;
  
  (*(code *)(&PTR_FUN_80166e7c)[*(byte *)(param_1 + 6)])();
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,uVar1 & 0xf,0);
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,uVar1 & 0xf,0);
  uVar1 = func_0x80033604();
  FUN_80166980(param_1,uVar1 & 0xf,5);
  return;
}
