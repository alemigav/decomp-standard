/* FUN_80067a70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80067a70  body 0x80067a70..0x80067e6b  size 1020 B
 * body sha256 79fda097318075cd268e43627e7ea4263cb4973aa45f427f74cbc79e82045e14
 * provider record sha256 3735d94372e98b5e06eb0c79f018c7371678f32be4f95bc032d37ea501a6f538
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80067a70(int param_1,int param_2,ushort *param_3)

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
  
  iVar7 = *(int *)(param_1 + 0x120);
  iVar10 = (int)(((uint)param_3[3] + (uint)param_3[1]) * 0x10000) >> 0x10;
  iVar6 = (int)(short)param_3[1];
  iVar12 = (iVar10 + param_2) - iVar6;
  iVar8 = (int)(short)*param_3;
  iVar9 = iVar12 * (iVar7 - (iVar8 - param_2));
  iVar2 = (int)(((uint)param_3[2] + (uint)*param_3) * 0x10000) >> 0x10;
  iVar5 = iVar2 - (iVar8 - param_2);
  iVar13 = iVar9 / iVar5;
  if (iVar5 == 0) {
    trap(0x1c00);
  }
  if ((iVar5 == -1) && (iVar9 == -0x80000000)) {
    trap(0x1800);
  }
  iVar9 = *(int *)(param_1 + 0x128);
  if (iVar13 <= iVar9 - iVar6) {
    return 0;
  }
  iVar11 = (iVar8 / 0x12) * 0x10000 >> 0x10;
  iVar4 = (iVar6 / 0x12) * 0x10000 >> 0x10;
  iVar3 = (iVar2 / 0x12) * 0x10000 >> 0x10;
  iVar2 = (iVar10 / 0x12) * 0x10000 >> 0x10;
  iVar10 = iVar2 - iVar4;
  if (((iVar10 * (((int)*(short *)(param_1 + 0x1b4) / 0x12) * 0x10000 >> 0x10) -
       (iVar3 - iVar11) * (((int)*(short *)(param_1 + 0x1b6) / 0x12) * 0x10000 >> 0x10)) -
      iVar11 * iVar2) + iVar3 * iVar4 < 1) {
    iVar13 = (iVar9 - iVar6) - iVar13;
    iVar2 = (iVar5 * iVar13) / iVar12;
    if (iVar12 == 0) {
      trap(0x1c00);
    }
    if ((iVar12 == -1) && (iVar5 * iVar13 == -0x80000000)) {
      trap(0x1800);
    }
    iVar5 = iVar2 * iVar13 * iVar13;
    iVar6 = iVar2 * iVar2 + iVar13 * iVar13;
    iVar8 = iVar5 / iVar6;
    if (iVar6 == 0) {
      trap(0x1c00);
    }
    if ((iVar6 == -1) && (iVar5 == -0x80000000)) {
      trap(0x1800);
    }
    iVar13 = iVar2 * iVar2 * iVar13;
    iVar2 = iVar13 / iVar6;
    if (iVar6 == 0) {
      trap(0x1c00);
    }
    if ((iVar6 == -1) && (iVar13 == -0x80000000)) {
      trap(0x1800);
    }
    iVar13 = iVar8;
    if (iVar8 < 0) {
      iVar13 = -iVar8;
    }
    if (iVar13 < 0x191) {
      iVar13 = iVar2;
      if (iVar2 < 0) {
        iVar13 = -iVar2;
      }
      if (iVar13 < 0x191) {
        *(int *)(param_1 + 0x120) = iVar7 + iVar8;
        *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) - iVar2;
        if ((iVar7 / 0x12 - iVar11) * iVar10 - (iVar9 / 0x12 - iVar4) * (iVar3 - iVar11) < 1) {
          return 1;
        }
      }
    }
    *(int *)(param_1 + 0x120) = (int)*(short *)(param_1 + 0x1b4);
    *(int *)(param_1 + 0x128) = (int)*(short *)(param_1 + 0x1b6);
  }
  else if (((uint)(iVar7 - iVar8) < (uint)param_3[2] + param_2) &&
          ((uint)(iVar9 - (iVar6 - param_2)) < (uint)param_3[3] + param_2)) {
    uVar1 = FUN_80066ec8(param_1,param_2,param_3,iVar3,
                         (int)((ulonglong)((longlong)iVar6 * 0x38e38e39) >> 0x20));
    return uVar1;
  }
  return 1;
}
