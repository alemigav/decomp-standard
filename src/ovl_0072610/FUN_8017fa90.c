/* FUN_8017fa90
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017fa90  body 0x8017fa90..0x8017fcef  size 608 B
 * body sha256 a7022adc95d0f81e6cd91bb4bf3f52123e9bccca63e2341152ce65b1096fd924
 * provider record sha256 dd6446fb17a575abcdb8de6b3332107cca7d5a3b8d2f11ec244bfdcc0ee528b6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017fa90(short *param_1)

{
  short sVar1;
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
  
  iVar7 = (int)param_1[6];
  iVar9 = (int)param_1[2];
  iVar2 = (int)param_1[1];
  iVar4 = (int)param_1[7];
  iVar6 = (int)param_1[5];
  iVar8 = (int)param_1[3];
  iVar10 = param_1[4] * 0x800;
  if ((((((iVar10 == 0 && iVar7 == 0) && iVar9 == 0) && iVar2 == 0) && iVar4 == 0) && iVar6 == 0) &&
      iVar8 == 0) {
    sVar1 = *param_1 << 3;
    param_1[7] = sVar1;
    param_1[6] = sVar1;
    param_1[5] = sVar1;
    param_1[4] = sVar1;
    param_1[3] = sVar1;
    param_1[2] = sVar1;
    param_1[1] = sVar1;
    *param_1 = sVar1;
    return;
  }
  iVar5 = (iVar2 + iVar4) * 0x235;
  iVar3 = iVar5 + iVar2 * 0x8e4;
  iVar5 = iVar5 + iVar4 * -0xd4e;
  iVar2 = (iVar6 + iVar8) * 0x968;
  iVar6 = iVar2 + iVar6 * -799;
  iVar2 = iVar2 + iVar8 * -0xfb1;
  iVar4 = *param_1 * 0x800 + 0x80;
  iVar10 = iVar4 + iVar10;
  iVar4 = iVar4 + param_1[4] * -0x800;
  iVar11 = (iVar9 + iVar7) * 0x454;
  iVar7 = iVar11 + iVar7 * -0xec8;
  iVar11 = iVar11 + iVar9 * 0x620;
  iVar12 = iVar3 + iVar6;
  iVar3 = iVar3 - iVar6;
  iVar6 = iVar5 + iVar2;
  iVar5 = iVar5 - iVar2;
  iVar8 = iVar10 + iVar11;
  iVar10 = iVar10 - iVar11;
  iVar9 = iVar4 + iVar7;
  iVar4 = iVar4 - iVar7;
  iVar7 = (iVar3 + iVar5) * 0xb5 + 0x80 >> 8;
  iVar2 = (iVar3 - iVar5) * 0xb5 + 0x80 >> 8;
  *param_1 = (short)((uint)(iVar8 + iVar12) >> 8);
  param_1[1] = (short)((uint)(iVar9 + iVar7) >> 8);
  param_1[2] = (short)((uint)(iVar4 + iVar2) >> 8);
  param_1[3] = (short)((uint)(iVar10 + iVar6) >> 8);
  param_1[4] = (short)((uint)(iVar10 - iVar6) >> 8);
  param_1[6] = (short)((uint)(iVar9 - iVar7) >> 8);
  param_1[5] = (short)((uint)(iVar4 - iVar2) >> 8);
  param_1[7] = (short)((uint)(iVar8 - iVar12) >> 8);
  return;
}
