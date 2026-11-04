/* FUN_801625b0
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801625b0  body 0x801625b0..0x80162693  size 228 B
 * body sha256 3e87e8527680fe75851dc0347e6c18b53e8addf04c2d9671a5229e3a2de4bdf7
 * provider record sha256 c2ebd081dce7cce54b761ff56888ca54d77a078b9734740a52aa5da692c61e34
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801625b0(int param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_38 [20];
  int local_24;
  int local_1c;
  
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,auStack_38);
  iVar1 = iVar1 + param_2 * 0x18f8 + 0x468;
  func_0x800424ec(auStack_38,iVar1 + -0x2e8,auStack_38);
  func_0x800424ec(auStack_38,iVar1 + -0x170,auStack_38);
  func_0x800424ec(auStack_38,iVar1 + 8,auStack_38);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (local_24 - *(int *)(iVar1 + 0x4c));
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - (local_1c - *(int *)(iVar1 + 0x54));
  return;
}
