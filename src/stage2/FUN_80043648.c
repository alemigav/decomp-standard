/* FUN_80043648
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80043648  body 0x80043648..0x80043867  size 544 B
 * body sha256 e5a70dabbbda7040137d3cb8b7e91613cce802d5e3ea598be94ba4bff11c17d1
 * provider record sha256 fcb475290fce2436278dd177ee5f3e77ce089d725c368bf8af851b763c2163cc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80043648(undefined4 param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  
  DAT_800efd94 = 0xffffffff;
  DAT_800efda0 = 0;
  DAT_800efd9c = 0;
  if (param_2 != param_3) {
    pbVar8 = (byte *)(param_2 + 9);
    iVar9 = param_2;
    do {
      iVar4 = *(int *)(pbVar8 + 0x1b);
      if ((((iVar4 != 0) && (*(short *)(pbVar8 + 0x19) != 0)) && (pbVar8[-6] != 2)) &&
         (uVar3 = *(uint *)(iVar4 + 4), bVar1 = *pbVar8, bVar2 = pbVar8[-1],
         iVar4 = *(int *)(iVar4 + 0x14), iVar9 != param_3)) {
        pbVar7 = (byte *)(iVar9 + 9);
        iVar6 = iVar9;
        do {
          iVar5 = *(int *)(pbVar7 + 0x1b);
          if ((iVar5 != 0) &&
             (*(int *)(iVar5 + 0x14) + (uint)(pbVar7[-1] >> 1) +
              (*(uint *)(iVar5 + 4) >> 1) * (uint)*pbVar7 ==
              iVar4 + (uint)(bVar2 >> 1) + (uVar3 >> 1) * (uint)bVar1)) {
            param_1 = FUN_80044548(param_1,iVar6);
          }
          iVar6 = iVar6 + 0x28;
          pbVar7 = pbVar7 + 0x28;
        } while (iVar6 != param_3);
      }
      pbVar8 = pbVar8 + 0x28;
      iVar9 = iVar9 + 0x28;
    } while (iVar9 != param_3);
  }
  DAT_800efd94 = 0xffffffff;
  DAT_800efda0 = 0;
  DAT_800efd9c = 0;
  if (param_2 != param_3) {
    pbVar8 = (byte *)(param_2 + 9);
    do {
      iVar9 = *(int *)(pbVar8 + 0x1b);
      if (((iVar9 != 0) && (*(short *)(pbVar8 + 0x19) != 0)) &&
         (uVar3 = *(uint *)(iVar9 + 4), bVar1 = *pbVar8, bVar2 = pbVar8[-1],
         iVar9 = *(int *)(iVar9 + 0x14), param_2 != param_3)) {
        pbVar7 = (byte *)(param_2 + 9);
        iVar4 = param_2;
        do {
          iVar6 = *(int *)(pbVar7 + 0x1b);
          if ((iVar6 != 0) &&
             (*(int *)(iVar6 + 0x14) + (uint)(pbVar7[-1] >> 1) +
              (*(uint *)(iVar6 + 4) >> 1) * (uint)*pbVar7 ==
              iVar9 + (uint)(bVar2 >> 1) + (uVar3 >> 1) * (uint)bVar1)) {
            param_1 = FUN_80044548(param_1,iVar4);
          }
          iVar4 = iVar4 + 0x28;
          pbVar7 = pbVar7 + 0x28;
        } while (iVar4 != param_3);
      }
      pbVar8 = pbVar8 + 0x28;
      param_2 = param_2 + 0x28;
    } while (param_2 != param_3);
  }
  return param_1;
}
