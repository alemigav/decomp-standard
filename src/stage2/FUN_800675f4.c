/* FUN_800675f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800675f4  body 0x800675f4..0x800679ef  size 1020 B
 * body sha256 37c1a7de6d848e51f6f2dc704fb03c5e3c3d6929f31351a5efee468de91cd9e6
 * provider record sha256 5b4788602bba00516d931d9ba9e0d512ea2915fc0bc8b463209c09a59007cf5f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800675f4(int param_1,int param_2,ushort *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  iVar7 = *(int *)(param_1 + 0x120);
  iVar10 = (int)(((uint)param_3[3] + (uint)param_3[1]) * 0x10000) >> 0x10;
  iVar9 = (int)(short)param_3[1];
  iVar12 = iVar10 - (iVar9 - param_2);
  iVar4 = (int)(short)*param_3;
  iVar11 = iVar12 * (iVar7 - iVar4);
  iVar2 = (int)(((uint)param_3[2] + (uint)*param_3) * 0x10000) >> 0x10;
  iVar6 = (iVar2 + param_2) - iVar4;
  iVar14 = iVar11 / iVar6;
  if (iVar6 == 0) {
    trap(0x1c00);
  }
  if ((iVar6 == -1) && (iVar11 == -0x80000000)) {
    trap(0x1800);
  }
  iVar13 = *(int *)(param_1 + 0x128);
  iVar11 = iVar13 - (iVar9 - param_2);
  if (iVar11 <= iVar14) {
    return 0;
  }
  iVar8 = (iVar4 / 0x12) * 0x10000 >> 0x10;
  iVar5 = (iVar9 / 0x12) * 0x10000 >> 0x10;
  iVar3 = (iVar2 / 0x12) * 0x10000 >> 0x10;
  iVar2 = (iVar10 / 0x12) * 0x10000 >> 0x10;
  iVar10 = iVar2 - iVar5;
  if (((iVar10 * (((int)*(short *)(param_1 + 0x1b4) / 0x12) * 0x10000 >> 0x10) -
       (iVar3 - iVar8) * (((int)*(short *)(param_1 + 0x1b6) / 0x12) * 0x10000 >> 0x10)) -
      iVar8 * iVar2) + iVar3 * iVar5 < 0) {
    if (((uint)(iVar7 - (iVar4 - param_2)) < (uint)param_3[2] + param_2) &&
       ((uint)(iVar13 - iVar9) < (uint)param_3[3] + param_2)) {
      uVar1 = FUN_80066ec8(param_1,param_2,param_3,iVar3,
                           (int)((ulonglong)((longlong)iVar9 * 0x38e38e39) >> 0x20));
      return uVar1;
    }
  }
  else {
    iVar11 = iVar11 - iVar14;
    iVar2 = (iVar6 * iVar11) / iVar12;
    if (iVar12 == 0) {
      trap(0x1c00);
    }
    if ((iVar12 == -1) && (iVar6 * iVar11 == -0x80000000)) {
      trap(0x1800);
    }
    iVar4 = iVar2 * iVar11 * iVar11;
    iVar6 = iVar2 * iVar2 + iVar11 * iVar11;
    iVar9 = iVar4 / iVar6;
    if (iVar6 == 0) {
      trap(0x1c00);
    }
    if ((iVar6 == -1) && (iVar4 == -0x80000000)) {
      trap(0x1800);
    }
    iVar11 = iVar2 * iVar2 * iVar11;
    iVar2 = iVar11 / iVar6;
    if (iVar6 == 0) {
      trap(0x1c00);
    }
    if ((iVar6 == -1) && (iVar11 == -0x80000000)) {
      trap(0x1800);
    }
    iVar11 = iVar9;
    if (iVar9 < 0) {
      iVar11 = -iVar9;
    }
    if (iVar11 < 0x191) {
      iVar11 = iVar2;
      if (iVar2 < 0) {
        iVar11 = -iVar2;
      }
      if (iVar11 < 0x191) {
        *(int *)(param_1 + 0x120) = iVar7 + iVar9;
        *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) - iVar2;
        if (-1 < (iVar7 / 0x12 - iVar8) * iVar10 - (iVar13 / 0x12 - iVar5) * (iVar3 - iVar8)) {
          return 1;
        }
      }
    }
    *(int *)(param_1 + 0x120) = (int)*(short *)(param_1 + 0x1b4);
    *(int *)(param_1 + 0x128) = (int)*(short *)(param_1 + 0x1b6);
  }
  return 1;
}
