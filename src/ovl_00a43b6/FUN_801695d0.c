/* FUN_801695d0
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801695d0  body 0x801695d0..0x80169677  size 168 B
 * body sha256 d8b5507693434cf218003be2f14b355cd06e8899b8440858564c05450ce5d895
 * provider record sha256 d0109169b30fd2218ac83641502b0ab92782dd733999cd85e2c25a7ae57a1d17
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801695d0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x180,param_2);
  func_0x800424ec(param_2,iVar1 + 0x2f8,param_2);
  func_0x800424ec(param_2,iVar1 + 0xd40,param_2);
  func_0x800424ec(param_2,iVar1 + 0xeb8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1030,param_2);
  return;
}
