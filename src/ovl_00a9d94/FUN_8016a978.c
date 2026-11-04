/* FUN_8016a978
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016a978  body 0x8016a978..0x8016aa1f  size 168 B
 * body sha256 f9da5a537b57dd517f0d89cb4423253f48f65ba2f19372598f4e8ae1e5f86d04
 * provider record sha256 17a25ba71ef02079ec61012c61668fda7eebe89edfc328315cab5dac59fd0edf
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016a978(int param_1,undefined4 param_2)

{
  int iVar1;
  
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,param_2);
  func_0x800424ec(param_2,iVar1 + 0xd40,param_2);
  func_0x800424ec(param_2,iVar1 + 0xeb8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1030,param_2);
  func_0x800424ec(param_2,iVar1 + 0x11a8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1320,param_2);
  return;
}
