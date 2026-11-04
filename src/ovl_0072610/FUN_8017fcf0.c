/* FUN_8017fcf0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017fcf0  body 0x8017fcf0..0x8017ff77  size 648 B
 * body sha256 d9502aa33cfd1e60f7ba9c7094241193018b08a2346166f60da41cde9d37f4e8
 * provider record sha256 3fd01a00b8efee1dceede71f2be6b7eb2a7a096835d728c9f188cbc919fb5158
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017fcf0(short *param_1)

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
  
  iVar7 = (int)param_1[0x30];
  iVar9 = (int)param_1[0x10];
  iVar2 = (int)param_1[8];
  iVar5 = (int)param_1[0x38];
  iVar6 = (int)param_1[0x28];
  iVar8 = (int)param_1[0x18];
  iVar10 = param_1[0x20] * 0x100;
  if ((((((iVar10 == 0 && iVar7 == 0) && iVar9 == 0) && iVar2 == 0) && iVar5 == 0) && iVar6 == 0) &&
      iVar8 == 0) {
    sVar1 = (short)(*param_1 + 0x20 >> 6);
    param_1[0x38] = sVar1;
    param_1[0x30] = sVar1;
    param_1[0x28] = sVar1;
    param_1[0x20] = sVar1;
    param_1[0x18] = sVar1;
    param_1[0x10] = sVar1;
    param_1[8] = sVar1;
    *param_1 = sVar1;
    return;
  }
  iVar4 = (iVar2 + iVar5) * 0x235 + 4;
  iVar3 = iVar4 + iVar2 * 0x8e4 >> 3;
  iVar5 = iVar4 + iVar5 * -0xd4e >> 3;
  iVar2 = (iVar6 + iVar8) * 0x968 + 4;
  iVar6 = iVar2 + iVar6 * -799 >> 3;
  iVar8 = iVar2 + iVar8 * -0xfb1 >> 3;
  iVar2 = *param_1 * 0x100 + 0x2000;
  iVar10 = iVar2 + iVar10;
  iVar2 = iVar2 + param_1[0x20] * -0x100;
  iVar4 = (iVar9 + iVar7) * 0x454 + 4;
  iVar7 = iVar4 + iVar7 * -0xec8 >> 3;
  iVar9 = iVar4 + iVar9 * 0x620 >> 3;
  iVar4 = iVar3 + iVar6;
  iVar3 = iVar3 - iVar6;
  iVar6 = iVar5 + iVar8;
  iVar5 = iVar5 - iVar8;
  iVar8 = iVar10 + iVar9;
  iVar10 = iVar10 - iVar9;
  iVar9 = iVar2 + iVar7;
  iVar2 = iVar2 - iVar7;
  iVar7 = (iVar3 + iVar5) * 0xb5 + 0x80 >> 8;
  iVar5 = (iVar3 - iVar5) * 0xb5 + 0x80 >> 8;
  *param_1 = (short)(iVar8 + iVar4 >> 0xe);
  param_1[8] = (short)(iVar9 + iVar7 >> 0xe);
  param_1[0x10] = (short)(iVar2 + iVar5 >> 0xe);
  param_1[0x18] = (short)(iVar10 + iVar6 >> 0xe);
  param_1[0x20] = (short)(iVar10 - iVar6 >> 0xe);
  param_1[0x30] = (short)(iVar9 - iVar7 >> 0xe);
  param_1[0x28] = (short)(iVar2 - iVar5 >> 0xe);
  param_1[0x38] = (short)(iVar8 - iVar4 >> 0xe);
  return;
}
