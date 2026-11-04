/* FUN_80035c9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035c9c  body 0x80035c9c..0x80035dbb  size 288 B
 * body sha256 624b56252ef71849192fabaacbdf6affef4736490746faf2ed7c94b600fe5f3f
 * provider record sha256 13662bc68435ef131b37103179db24c8df765f802cb80acb607166586fa6cb2f
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80035c9c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x234);
  FUN_80040e58(param_1 + 100,param_1 + 0x14);
  iVar3 = iVar1 + 0x38;
  FUN_800424ec(param_1 + 0x14,iVar1 + 8,iVar3);
  iVar2 = iVar1 + 0x1b0;
  FUN_800424ec(iVar3,iVar1 + 0x180,iVar2);
  FUN_800424ec(iVar2,iVar1 + 0x2f8,iVar1 + 0x328);
  FUN_800424ec(iVar2,iVar1 + 0x760,iVar1 + 0x790);
  FUN_800424ec(iVar3,iVar1 + 0xd40,iVar1 + 0xd70);
  FUN_800424ec(iVar3,iVar1 + 0x11a8,iVar1 + 0x11d8);
  FUN_80036290(param_1,iVar1,&DAT_800eb414);
  FUN_80036290(param_1,iVar1,&DAT_800eb4a8);
  FUN_80036290(param_1,iVar1,&DAT_800eb53c);
  FUN_80036290(param_1,iVar1,&DAT_800eb604);
  FUN_80036290(param_1,iVar1,&DAT_800eb684);
  FUN_80036694(param_1);
  return;
}
