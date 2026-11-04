/* FUN_80067ee0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80067ee0  body 0x80067ee0..0x800682db  size 1020 B
 * body sha256 3dc8addf81c2dc8e639a51b99d38a7e09d302e20b86ea70bce15e78545986412
 * provider record sha256 897b52c1966749fe1d41f540ee99cb942b1ce06dbade103dd715fdb79261bda2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80067ee0(int param_1,int param_2,ushort *param_3)

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
  
  iVar12 = *(int *)(param_1 + 0x120);
  iVar7 = (int)(short)param_3[1];
  iVar5 = (int)(((uint)param_3[3] + (uint)param_3[1]) * 0x10000) >> 0x10;
  iVar8 = iVar5 + param_2;
  iVar3 = (int)(short)*param_3;
  iVar9 = (iVar7 - iVar8) * (iVar12 - iVar3);
  iVar2 = (int)(((uint)param_3[2] + (uint)*param_3) * 0x10000) >> 0x10;
  iVar4 = (iVar2 + param_2) - iVar3;
  iVar14 = iVar9 / iVar4;
  if (iVar4 == 0) {
    trap(0x1c00);
  }
  if ((iVar4 == -1) && (iVar9 == -0x80000000)) {
    trap(0x1800);
  }
  iVar9 = *(int *)(param_1 + 0x128);
  if (iVar14 <= iVar9 - iVar8) {
    return 0;
  }
  iVar13 = (iVar3 / 0x12) * 0x10000 >> 0x10;
  iVar6 = (iVar5 / 0x12) * 0x10000 >> 0x10;
  iVar5 = (iVar2 / 0x12) * 0x10000 >> 0x10;
  iVar2 = (iVar7 / 0x12) * 0x10000 >> 0x10;
  iVar11 = iVar2 - iVar6;
  iVar10 = iVar5 - iVar13;
  if (((iVar11 * (((int)*(short *)(param_1 + 0x1b4) / 0x12) * 0x10000 >> 0x10) -
       iVar10 * (((int)*(short *)(param_1 + 0x1b6) / 0x12) * 0x10000 >> 0x10)) - iVar13 * iVar2) +
      iVar5 * iVar6 < 1) {
    iVar14 = (iVar9 - iVar8) - iVar14;
    iVar8 = iVar8 - iVar7;
    iVar2 = (iVar4 * iVar14) / iVar8;
    if (iVar8 == 0) {
      trap(0x1c00);
    }
    if ((iVar8 == -1) && (iVar4 * iVar14 == -0x80000000)) {
      trap(0x1800);
    }
    iVar8 = iVar2 * iVar14 * iVar14;
    iVar3 = iVar2 * iVar2 + iVar14 * iVar14;
    iVar4 = iVar8 / iVar3;
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (iVar8 == -0x80000000)) {
      trap(0x1800);
    }
    iVar14 = iVar2 * iVar2 * iVar14;
    iVar8 = iVar14 / iVar3;
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (iVar14 == -0x80000000)) {
      trap(0x1800);
    }
    iVar14 = iVar4;
    if (iVar4 < 0) {
      iVar14 = -iVar4;
    }
    if (iVar14 < 0x191) {
      iVar14 = iVar8;
      if (iVar8 < 0) {
        iVar14 = -iVar8;
      }
      if (iVar14 < 0x191) {
        *(int *)(param_1 + 0x120) = iVar12 - iVar4;
        *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) - iVar8;
        if ((iVar12 / 0x12 - iVar13) * iVar11 - (iVar9 / 0x12 - iVar6) * iVar10 < 1) {
          return 1;
        }
      }
    }
    *(int *)(param_1 + 0x120) = (int)*(short *)(param_1 + 0x1b4);
    *(int *)(param_1 + 0x128) = (int)*(short *)(param_1 + 0x1b6);
  }
  else if (((uint)(iVar12 - (iVar3 - param_2)) < (uint)param_3[2] + param_2) &&
          ((uint)(iVar9 - (iVar7 - param_2)) < (uint)param_3[3] + param_2)) {
    uVar1 = FUN_80066ec8(param_1,param_2,param_3);
    return uVar1;
  }
  return 1;
}
