/* FUN_80168cb4
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80168cb4  body 0x80168cb4..0x80168d5b  size 168 B
 * body sha256 b540fb2129744db1a2fb6668232a630e5a8e4624ef785ad400b40ea8ccdf0a05
 * provider record sha256 16b7a09667cfe59e0fd572d47b974c2462e8ae03f5e08965ce5b9d270983d1fc
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80168cb4(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x180,param_2);
  func_0x800424ec(param_2,iVar1 + 0x2f8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x5e8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x760,param_2);
  func_0x800424ec(param_2,iVar1 + 0x8d8,param_2);
  return;
}
