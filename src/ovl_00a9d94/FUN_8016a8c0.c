/* FUN_8016a8c0
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016a8c0  body 0x8016a8c0..0x8016a977  size 184 B
 * body sha256 0ddaafda5fe2ac8eeab77817b0cbd22bc197f53a6b58c18d1ccd716fe4215a6d
 * provider record sha256 f2d399af87009a24d848842b08aaf0a43512d334171cbb97768f9dc74a0f8998
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016a8c0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,param_2);
  func_0x800424ec(param_2,iVar1 + 0xd40,param_2);
  func_0x800424ec(param_2,iVar1 + 0xeb8,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1610,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1788,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1900,param_2);
  func_0x800424ec(param_2,iVar1 + 0x1a78,param_2);
  return;
}
