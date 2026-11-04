/* FUN_8017d308
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017d308  body 0x8017d308..0x8017d60f  size 776 B
 * body sha256 bb360fc02b7ae128d6e27e374949533c564caf42bb46d0726a2bd6fb410c7c48
 * provider record sha256 9cf9285b8ed3d49270bfe7fc3d8b07d50399557b34b18202db64e506c9f420b9
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017d308(void)

{
  short *psVar1;
  ushort uVar3;
  uint uVar2;
  int iVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  short *psVar8;
  short *psVar9;
  int iVar10;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  func_0x80043620();
  iVar10 = 0;
  psVar8 = DAT_8017e8e0 + 4;
  do {
    uVar2 = 0;
    do {
      sVar6 = (short)uVar2;
      if (((short)iVar10 == 0xf) && ((uVar2 & 1) != 0)) {
        uVar3 = func_0x80033604();
        DAT_8017e8e0[sVar6 * 0x44 + 0x3442] = DAT_8017e8e0[sVar6 * 0x44 + 0x3442] + (uVar3 & 1);
      }
      if ((((short)iVar10 == 0xc) && ((uVar2 & 1) == 0)) && ((DAT_8017e8e0[1] & 1U) != 0)) {
        iVar5 = iVar10;
        do {
          uVar3 = func_0x80033604();
          iVar4 = ((iVar5 << 0x10) >> 0xd) + sVar6 * 0x88;
          iVar5 = iVar5 + 1;
          *(ushort *)((int)DAT_8017e8e0 + iVar4 + 0x680c) =
               *(short *)((int)DAT_8017e8e0 + iVar4 + 0x680c) + (uVar3 & 1);
        } while (iVar5 * 0x10000 >> 0x10 < 0x11);
      }
      uVar2 = uVar2 + 1;
    } while ((int)(uVar2 * 0x10000) >> 0x10 < 0x11);
    iVar10 = iVar10 + 1;
  } while (iVar10 * 0x10000 >> 0x10 < 0x11);
  iVar10 = 0;
  do {
    iVar5 = 0;
    iVar4 = (iVar10 << 0x10) >> 0xd;
    psVar9 = psVar8;
    do {
      iVar7 = (short)iVar5 * 0x88;
      local_40 = *(undefined4 *)((int)DAT_8017e8e0 + iVar4 + iVar7 + 0x6808);
      local_3c = *(undefined4 *)((int)DAT_8017e8e0 + iVar4 + iVar7 + 0x680c);
      local_38 = *(undefined4 *)((int)DAT_8017e8e0 + iVar4 + iVar7 + 0x6890);
      local_34 = *(undefined4 *)((int)DAT_8017e8e0 + iVar4 + iVar7 + 0x6894);
      local_30 = *(undefined4 *)((int)DAT_8017e8e0 + iVar4 + iVar7 + 0x6810);
      local_2c = *(undefined4 *)((int)DAT_8017e8e0 + iVar4 + iVar7 + 0x6814);
      local_28 = *(undefined4 *)((int)DAT_8017e8e0 + iVar4 + iVar7 + 0x6898);
      local_24 = *(undefined4 *)((int)DAT_8017e8e0 + iVar4 + iVar7 + 0x689c);
      func_0x80042f9c(&local_40,&local_38,&local_30);
      func_0x80043460(psVar9 + 2,psVar9 + 8,psVar9 + 0xe);
      func_0x80042de0(&local_28);
      func_0x8004341c(psVar9 + 0x14);
      psVar8 = psVar9 + 0x1a;
      DAT_8017e754 = func_0x80046208(DAT_8017e754,psVar9);
      psVar1 = DAT_8017e8e0;
      iVar5 = iVar5 + 1;
      psVar9 = psVar8;
    } while (iVar5 * 0x10000 >> 0x10 < 0x10);
    iVar10 = iVar10 + 1;
  } while (iVar10 * 0x10000 >> 0x10 < 0x10);
  sVar6 = DAT_8017e8e0[1];
  DAT_8017e8e0[1] = sVar6 + 1;
  if (0x3c < (short)(sVar6 + 1)) {
    psVar1[1] = 0;
    *psVar1 = *psVar1 + 1;
  }
  return;
}
