/* FUN_8017d610
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017d610  body 0x8017d610..0x8017d967  size 856 B
 * body sha256 b6684530d904e32367f2a5dc0c8e91c09e46b56c2ce9c92df0753edbfa0d3100
 * provider record sha256 80c93847d8c369230f518545e6f30c06df8a3ff88d58c7d18ddefd3912f71b9c
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017d610(void)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  func_0x80043620();
  iVar10 = 0;
  do {
    iVar6 = 0;
    iVar3 = (int)(short)iVar10;
    do {
      psVar2 = DAT_8017e8e0;
      iVar5 = (int)(short)iVar6;
      DAT_8017e8e0[iVar5 * 0x44 + iVar3 * 4 + 0x3405] = 0;
      iVar7 = (int)psVar2[iVar5 * 0x11 + iVar3 + 0x3888];
      iVar4 = func_0x80040968(iVar7 * 0x40 + psVar2[1] * -0x80);
      iVar4 = (iVar4 >> 6) * (int)DAT_8017e8e0[1];
      iVar7 = (iVar7 * 0x14) / 0xff + 0x50;
      if (iVar7 == 0) {
        trap(0x1c00);
      }
      if ((iVar7 == -1) && (iVar4 == -0x80000000)) {
        trap(0x1800);
      }
      iVar6 = iVar6 + 1;
      DAT_8017e8e0[iVar5 * 0x44 + iVar3 * 4 + 0x3405] =
           DAT_8017e8e0[iVar5 * 0x44 + iVar3 * 4 + 0x3405] + (short)(iVar4 / iVar7) + 0x29f;
    } while (iVar6 * 0x10000 >> 0x10 < 0x11);
    iVar10 = iVar10 + 1;
  } while (iVar10 * 0x10000 >> 0x10 < 0x11);
  iVar10 = 0;
  pbVar9 = (byte *)(DAT_8017e8e0 + 4);
  do {
    iVar6 = 0;
    iVar3 = (int)(short)iVar10;
    pbVar8 = pbVar9;
    do {
      iVar4 = (int)(short)iVar6;
      local_48 = *(undefined4 *)(DAT_8017e8e0 + iVar4 * 0x44 + iVar3 * 4 + 0x3404);
      local_44 = *(undefined4 *)(DAT_8017e8e0 + iVar4 * 0x44 + iVar3 * 4 + 0x3406);
      local_40 = *(undefined4 *)(DAT_8017e8e0 + iVar4 * 0x44 + iVar3 * 4 + 0x3448);
      local_3c = *(undefined4 *)(DAT_8017e8e0 + iVar4 * 0x44 + iVar3 * 4 + 0x344a);
      local_38 = *(undefined4 *)(DAT_8017e8e0 + iVar4 * 0x44 + iVar3 * 4 + 0x3408);
      local_34 = *(undefined4 *)(DAT_8017e8e0 + iVar4 * 0x44 + iVar3 * 4 + 0x340a);
      local_30 = *(undefined4 *)(DAT_8017e8e0 + iVar4 * 0x44 + iVar3 * 4 + 0x344c);
      local_2c = *(undefined4 *)(DAT_8017e8e0 + iVar4 * 0x44 + iVar3 * 4 + 0x344e);
      func_0x80042f9c(&local_48,&local_40,&local_38);
      func_0x80043460(pbVar8 + 4,pbVar8 + 0x10,pbVar8 + 0x1c);
      func_0x80042de0(&local_30);
      func_0x8004341c(pbVar8 + 0x28);
      iVar4 = (uint)*pbVar8 - (0xff - DAT_8017e8e0[iVar4 * 0x11 + iVar3 + 0x3888] >> 5);
      if (iVar4 < 0x28) {
        iVar4 = 0x28;
      }
      *pbVar8 = (byte)iVar4;
      pbVar9 = pbVar8 + 0x34;
      DAT_8017e754 = func_0x80046208(DAT_8017e754,pbVar8);
      psVar2 = DAT_8017e8e0;
      iVar6 = iVar6 + 1;
      pbVar8 = pbVar9;
    } while (iVar6 * 0x10000 >> 0x10 < 0x10);
    iVar10 = iVar10 + 1;
  } while (iVar10 * 0x10000 >> 0x10 < 0x10);
  sVar1 = DAT_8017e8e0[1];
  DAT_8017e8e0[1] = sVar1 + 1;
  if (200 < (short)(sVar1 + 1)) {
    psVar2[1] = 0;
    *psVar2 = *psVar2 + 1;
  }
  return;
}
