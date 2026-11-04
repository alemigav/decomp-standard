/* FUN_80068e4c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80068e4c  body 0x80068e4c..0x8006908f  size 580 B
 * body sha256 99044876f1b54920e634530966ff827a6767aa929548e6960af92694146bd1ae
 * provider record sha256 cd60545ab63a3ff514616b4adb2b4fee5693de67612e790f0a77b8e3eee901db
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80068e4c(int *param_1,int param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  
  uVar1 = *param_3;
  uVar2 = param_3[1];
  iVar9 = param_1[2];
  iVar4 = *param_1;
  iVar12 = (uint)param_3[2] + (uint)uVar1;
  iVar11 = (uint)param_3[3] + (uint)uVar2;
  iVar7 = (int)(((uint)uVar2 + (uint)(param_3[3] >> 1)) * 0x10000) >> 0x10;
  uVar10 = iVar9 - iVar7;
  iVar8 = (int)(((uint)uVar1 + (uint)(param_3[2] >> 1)) * 0x10000) >> 0x10;
  uVar6 = iVar4 - iVar8;
  uVar5 = uVar10 >> 0x1e & 2 | uVar6 >> 0x1f;
  if (uVar5 == 1) {
    iVar4 = (((iVar11 * 0x10000 >> 0x10) + param_2) - iVar7) * (iVar4 - ((short)uVar1 - param_2));
    iVar8 = iVar8 - ((short)uVar1 - param_2);
    if (iVar8 == 0) {
      trap(0x1c00);
    }
    if ((iVar8 == -1) && (iVar4 == -0x80000000)) {
      trap(0x1800);
    }
    if ((int)uVar10 < iVar4 / iVar8) {
      return 1;
    }
  }
  else {
    if (uVar5 < 2) {
      if (uVar5 != 0) {
        return 0;
      }
      iVar11 = (iVar11 * 0x10000 >> 0x10) + param_2;
      iVar4 = (iVar7 - iVar11) * uVar6;
      iVar8 = ((iVar12 * 0x10000 >> 0x10) + param_2) - iVar8;
      if (iVar8 == 0) {
        trap(0x1c00);
      }
      if ((iVar8 == -1) && (iVar4 == -0x80000000)) {
        trap(0x1800);
      }
      bVar3 = iVar9 - iVar11 < iVar4 / iVar8;
    }
    else {
      if (uVar5 != 2) {
        if (uVar5 != 3) {
          return 0;
        }
        iVar4 = (((short)uVar2 - param_2) - iVar7) * (iVar4 - ((short)uVar1 - param_2));
        iVar8 = iVar8 - ((short)uVar1 - param_2);
        if (iVar8 == 0) {
          trap(0x1c00);
        }
        if ((iVar8 == -1) && (iVar4 == -0x80000000)) {
          trap(0x1800);
        }
        if (iVar4 / iVar8 < (int)uVar10) {
          return 1;
        }
        return 0;
      }
      iVar4 = (iVar7 - ((short)uVar2 - param_2)) * uVar6;
      iVar8 = ((iVar12 * 0x10000 >> 0x10) + param_2) - iVar8;
      if (iVar8 == 0) {
        trap(0x1c00);
      }
      if ((iVar8 == -1) && (iVar4 == -0x80000000)) {
        trap(0x1800);
      }
      bVar3 = iVar4 / iVar8 < iVar9 - ((short)uVar2 - param_2);
    }
    if (bVar3) {
      return 1;
    }
  }
  return 0;
}
