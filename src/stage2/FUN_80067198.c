/* FUN_80067198
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80067198  body 0x80067198..0x80067577  size 992 B
 * body sha256 44058406ef4df660f499fd097f47a23c81d969d705fd68db3fc0a96e67dfcbdc
 * provider record sha256 f9eca67185bc9b2566e1e74d23eb5cc9b12b08d9a7880a664e36e306ada08068
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80067198(int param_1,int param_2,short *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  uVar7 = (uint)(ushort)param_3[3];
  iVar8 = *(int *)(param_1 + 0x120);
  iVar6 = (int)*param_3;
  iVar11 = (param_2 * -2 - uVar7) * (iVar8 - (iVar6 - param_2));
  uVar5 = (uint)(ushort)param_3[2];
  iVar3 = uVar5 + param_2 * 2;
  iVar14 = iVar11 / iVar3;
  if (iVar3 == 0) {
    trap(0x1c00);
  }
  if ((iVar3 == -1) && (iVar11 == -0x80000000)) {
    trap(0x1800);
  }
  iVar9 = *(int *)(param_1 + 0x128);
  iVar3 = (int)param_3[1];
  iVar11 = iVar9 - (uVar7 + iVar3);
  if (iVar11 <= iVar14) {
    return 0;
  }
  iVar13 = (iVar6 / 0x12) * 0x10000 >> 0x10;
  iVar1 = (int)(uVar7 + iVar3) / 0x12;
  iVar15 = (int)(uVar5 + iVar6) / 0x12;
  iVar4 = (iVar3 / 0x12) * 0x10000 >> 0x10;
  iVar12 = iVar4 - iVar1;
  iVar10 = iVar15 - iVar13;
  if (((iVar12 * (((int)*(short *)(param_1 + 0x1b4) / 0x12) * 0x10000 >> 0x10) -
       iVar10 * (((int)*(short *)(param_1 + 0x1b6) / 0x12) * 0x10000 >> 0x10)) - iVar13 * iVar4) +
      iVar15 * iVar1 < 0) {
    if (((uint)(iVar8 - iVar6) < uVar5 + param_2) && ((uint)(iVar9 - iVar3) < uVar7 + param_2)) {
      uVar2 = FUN_80066ec8(param_1,param_2,param_3);
      return uVar2;
    }
  }
  else {
    iVar11 = iVar11 - iVar14;
    iVar3 = (uVar5 + param_2) * iVar11;
    param_2 = uVar7 + param_2;
    iVar6 = iVar3 / param_2;
    if (param_2 == 0) {
      trap(0x1c00);
    }
    if ((param_2 == -1) && (iVar3 == -0x80000000)) {
      trap(0x1800);
    }
    iVar3 = iVar6 * iVar11 * iVar11;
    iVar14 = iVar6 * iVar6 + iVar11 * iVar11;
    iVar15 = iVar3 / iVar14;
    if (iVar14 == 0) {
      trap(0x1c00);
    }
    if ((iVar14 == -1) && (iVar3 == -0x80000000)) {
      trap(0x1800);
    }
    iVar11 = iVar6 * iVar6 * iVar11;
    iVar3 = iVar11 / iVar14;
    if (iVar14 == 0) {
      trap(0x1c00);
    }
    if ((iVar14 == -1) && (iVar11 == -0x80000000)) {
      trap(0x1800);
    }
    iVar11 = iVar15;
    if (iVar15 < 0) {
      iVar11 = -iVar15;
    }
    if (iVar11 < 0x191) {
      iVar11 = iVar3;
      if (iVar3 < 0) {
        iVar11 = -iVar3;
      }
      if (iVar11 < 0x191) {
        *(int *)(param_1 + 0x120) = iVar8 - iVar15;
        *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) - iVar3;
        if (-1 < (iVar8 / 0x12 - iVar13) * iVar12 - (iVar9 / 0x12 - iVar1) * iVar10) {
          return 1;
        }
      }
    }
    *(int *)(param_1 + 0x120) = (int)*(short *)(param_1 + 0x1b4);
    *(int *)(param_1 + 0x128) = (int)*(short *)(param_1 + 0x1b6);
  }
  return 1;
}
