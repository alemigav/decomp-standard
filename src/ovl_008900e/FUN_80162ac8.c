/* FUN_80162ac8
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80162ac8  body 0x80162ac8..0x80162ba3  size 220 B
 * body sha256 3e570e4f327a9cc7d4dc3f8da2417d01c585872930437249bf98d37f737272c1
 * provider record sha256 199d7126e8730d1da72203d1bfbfb42f5da9bb27448beccfb13ae8a538e5fa0e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162ac8(int param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_38 [20];
  int local_24;
  int local_1c;
  
  iVar1 = *(int *)(param_1 + 0x234);
  func_0x80040e58(param_1 + 100,param_1 + 0x14);
  func_0x800424ec(param_1 + 0x14,iVar1 + 8,auStack_38);
  iVar1 = iVar1 + param_2 * 0x5e0 + 0x1780;
  func_0x800424ec(auStack_38,iVar1 + -0x2e8,auStack_38);
  func_0x800424ec(auStack_38,iVar1 + -0x170,auStack_38);
  func_0x800424ec(auStack_38,iVar1 + 8,auStack_38);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (local_24 - *(int *)(iVar1 + 0x4c));
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - (local_1c - *(int *)(iVar1 + 0x54));
  return;
}
