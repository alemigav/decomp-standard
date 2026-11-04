/* FUN_8017cee8
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017cee8  body 0x8017cee8..0x8017d307  size 1056 B
 * body sha256 25249a7893ff9553eb2513bd719eba90451778baab73774e9936147ab981c7cf
 * provider record sha256 2a4c873f3b486441930391cc81315b8389fc2f80b97b2bcf9fdaf2a4d821f753
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017cee8(void)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  char cVar10;
  int iVar8;
  int iVar9;
  int iVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 *local_30;
  
  func_0x80043620();
  psVar5 = DAT_8017e8e0;
  sVar2 = DAT_8017e8e0[1];
  DAT_8017e8e0[1] = sVar2 + 1;
  iVar9 = 0;
  if ((short)(sVar2 + 1) < psVar5[0x87aa]) {
    return;
  }
  do {
    iVar7 = 0;
    do {
      if (*(char *)(psVar5 + 2) != '\0') {
        iVar6 = ((iVar9 << 0x10) >> 0xd) + (short)iVar7 * 0x88;
        *(ushort *)((int)psVar5 + iVar6 + 0x680a) =
             *(short *)((int)psVar5 + iVar6 + 0x680a) + (ushort)*(byte *)(psVar5 + 2);
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar9 + 1;
    } while (iVar7 * 0x10000 >> 0x10 < 0x11);
    iVar9 = iVar6;
  } while (iVar6 * 0x10000 >> 0x10 < 0x11);
  cVar10 = *(char *)((int)DAT_8017e8e0 + 5) + -1;
  *(char *)((int)DAT_8017e8e0 + 5) = cVar10;
  if (cVar10 != '\0') goto LAB_8017d064;
  bVar1 = *(byte *)(DAT_8017e8e0 + 2);
  if (bVar1 == 3) {
    *(undefined1 *)((int)DAT_8017e8e0 + 5) = 5;
  }
  else if (bVar1 < 4) {
    if (bVar1 != 2) goto LAB_8017d03c;
    *(undefined1 *)((int)DAT_8017e8e0 + 5) = 8;
  }
  else if (bVar1 == 4) {
    *(undefined1 *)((int)DAT_8017e8e0 + 5) = 3;
  }
  else {
LAB_8017d03c:
    *(undefined1 *)((int)DAT_8017e8e0 + 5) = 1;
  }
  *(char *)(DAT_8017e8e0 + 2) = *(char *)(DAT_8017e8e0 + 2) - (*(char *)(DAT_8017e8e0 + 2) != '\0');
LAB_8017d064:
  iVar9 = 0;
  local_30 = &local_38;
  pbVar13 = (byte *)(DAT_8017e8e0 + 4);
  do {
    iVar7 = 0;
    iVar6 = (int)(short)iVar9;
    pbVar12 = pbVar13;
    do {
      iVar8 = (int)(short)iVar7;
      local_50 = *(undefined4 *)(DAT_8017e8e0 + iVar8 * 0x44 + iVar6 * 4 + 0x3404);
      local_4c = *(undefined4 *)(DAT_8017e8e0 + iVar8 * 0x44 + iVar6 * 4 + 0x3406);
      local_48 = *(undefined4 *)(DAT_8017e8e0 + iVar8 * 0x44 + iVar6 * 4 + 0x3448);
      local_44 = *(undefined4 *)(DAT_8017e8e0 + iVar8 * 0x44 + iVar6 * 4 + 0x344a);
      local_40 = *(undefined4 *)(DAT_8017e8e0 + iVar8 * 0x44 + iVar6 * 4 + 0x3408);
      local_3c = *(undefined4 *)(DAT_8017e8e0 + iVar8 * 0x44 + iVar6 * 4 + 0x340a);
      local_38 = *(undefined4 *)(DAT_8017e8e0 + iVar8 * 0x44 + iVar6 * 4 + 0x344c);
      local_34 = *(undefined4 *)(DAT_8017e8e0 + iVar8 * 0x44 + iVar6 * 4 + 0x344e);
      func_0x80042f9c(&local_50,&local_48,&local_40);
      uVar3 = DAT_8017e8e0[1];
      uVar4 = DAT_8017e8e0[0x87aa];
      func_0x80043460(pbVar12 + 4,pbVar12 + 0x10,pbVar12 + 0x1c);
      func_0x80042de0(local_30);
      func_0x8004341c(pbVar12 + 0x28);
      iVar11 = (int)(((uint)uVar3 - (uint)uVar4) * 0x10000) >> 0x10;
      sVar2 = (short)(iVar11 * iVar6 >> 1);
      local_4c = CONCAT22(local_4c._0_2_ + sVar2,local_4c._2_2_);
      local_44 = CONCAT22(local_44._0_2_ + sVar2,local_44._2_2_);
      sVar2 = (short)(iVar11 * (iVar6 + 1) >> 1);
      local_3c = CONCAT22(local_3c._0_2_ + sVar2,local_3c._2_2_);
      local_34 = CONCAT22(local_34._0_2_ + sVar2,local_34._2_2_);
      iVar8 = (0xff - DAT_8017e8e0[iVar8 * 0x11 + iVar6 + 0x3888]) / 0x1c + (uint)*pbVar12;
      if (0xfa < iVar8 * 0x10000 >> 0x10) {
        iVar8 = 0xfa;
      }
      *pbVar12 = (byte)iVar8;
      pbVar13 = pbVar12 + 0x34;
      DAT_8017e754 = func_0x80046208(DAT_8017e754,pbVar12);
      psVar5 = DAT_8017e8e0;
      iVar7 = iVar7 + 1;
      pbVar12 = pbVar13;
    } while (iVar7 * 0x10000 >> 0x10 < 0x10);
    iVar9 = iVar9 + 1;
  } while (iVar9 * 0x10000 >> 0x10 < 0x10);
  if (DAT_8017e8e0[0x87aa] + 0x30 < (int)DAT_8017e8e0[1]) {
    sVar2 = *DAT_8017e8e0;
    DAT_8017e8e0[1] = 0;
    *psVar5 = sVar2 + 1;
  }
  return;
}
