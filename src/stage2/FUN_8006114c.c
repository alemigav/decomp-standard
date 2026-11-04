/* FUN_8006114c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006114c  body 0x8006114c..0x80061273  size 296 B
 * body sha256 5a60085c9d29022250697e7c6ae574c7b7a33bfae76d345065e8d154efdbecd8
 * provider record sha256 0170c13048f9ce866a9dc33dbf7a7be72080085b72eb40f1429f657d7347a2eb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8006114c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint unaff_s7;
  
  uVar7 = 0x7fffffff;
  if (*(byte *)(param_1 + 8) < 0x10) {
    unaff_s7 = 0;
  }
  else {
    iVar6 = 4;
    iVar5 = 0;
    pbVar4 = (byte *)(param_3 + (uint)*(byte *)(param_1 + 8) * 8 + -0x80);
    do {
      iVar2 = *(int *)(param_1 + 0x234) + (uint)*pbVar4 * 0x178;
      iVar3 = *(int *)(iVar2 + 0x50) - *(int *)(param_2 + 0x18);
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      iVar1 = *(int *)(iVar2 + 0x4c) - *(int *)(param_2 + 0x14);
      iVar2 = *(int *)(iVar2 + 0x54) - *(int *)(param_2 + 0x1c);
      iVar2 = FUN_80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
      if ((uint)(iVar3 + iVar2) < uVar7) {
        unaff_s7 = (uint)*pbVar4 | iVar5 << 0x10;
        uVar7 = iVar3 + iVar2;
      }
      pbVar4 = pbVar4 + 2;
      iVar6 = iVar6 + -1;
      iVar5 = iVar5 + 1;
    } while (iVar6 != 0);
  }
  return unaff_s7;
}
