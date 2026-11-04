/* FUN_801655b4
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801655b4  body 0x801655b4..0x8016566f  size 188 B
 * body sha256 2769eff86a96a37b17d48169671c1d23eeefde54415e8789fcec9a49472ddcd3
 * provider record sha256 a957cc6a8dcf6e480036d3339e1cad2aab0341fba2f049e190200428cb091732
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801655b4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  iVar2 = iVar1 + 0x38;
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,iVar2);
  func_0x800424ec(iVar2,iVar1 + 0x180,iVar1 + 0x1b0);
  func_0x800424ec(iVar2,iVar1 + 0x2f8,iVar1 + 0x328);
  func_0x800424ec(iVar2,iVar1 + 0x470,iVar1 + 0x4a0);
  func_0x80036290(param_1,iVar1,&DAT_8016731c);
  func_0x80036290(param_1,iVar1,&DAT_80167388);
  func_0x80036734(param_1,iVar1);
  return;
}
