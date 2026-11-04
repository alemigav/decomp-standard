/* FUN_80093ddc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80093ddc  body 0x80093ddc..0x800946ef  size 2324 B
 * body sha256 b7687a7b12a936672795052637af480ab07a4dead1264a04122e382994fc17e9
 * provider record sha256 ee1e0c29fdb9885d7d97a5a267e57ac1f759a2374e292aec750ec2f24f228a1d
 * callees 14 direct (14 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80093ddc(void)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  undefined4 uVar4;
  char cVar5;
  char cVar6;
  short sVar7;
  short sVar9;
  int iVar8;
  uint uVar10;
  byte *pbVar11;
  ushort *puVar12;
  int iVar13;
  undefined2 *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  uint local_58;
  uint local_54;
  short sStack_4e;
  int local_4c;
  short sStack_46;
  int local_38;
  int local_34;
  int local_30;
  
  sVar9 = DAT_8012bfea;
  iVar13 = DAT_800c52dc;
  uVar22 = DAT_800c52dc + 0x3b910;
  local_54 = DAT_800c52dc + 0x3b800;
  iVar16 = DAT_800c52dc + 0x3b970;
  iVar20 = (int)DAT_8012bfe8;
  iVar21 = (int)DAT_8012bfea;
  if (DAT_8012fb72 == 0) {
    DAT_8012fb70 = DAT_8012fb70 + 2;
  }
  else {
    DAT_8012fb70 = DAT_8012fb70 + -2;
  }
  if (0x3e < DAT_8012fb70) {
    DAT_8012fb70 = 0x3f;
    DAT_8012fb72 = 1;
  }
  iVar15 = 2;
  if (DAT_8012fb70 < 1) {
    DAT_8012fb70 = 0;
    DAT_8012fb72 = 0;
  }
  sStack_46 = DAT_8012bfe8 + 6;
  puVar14 = (undefined2 *)(DAT_800c52dc + 0x3b8fe);
  pbVar11 = &DAT_8012fb08;
  local_58 = DAT_800c52dc + 0x3b8f0;
  do {
    iVar15 = iVar15 + -1;
    puVar14[-3] = sStack_46;
    bVar3 = *pbVar11;
    uVar10 = local_58 + 0x10;
    puVar14[-1] = 0xbf;
    *puVar14 = 0x29;
    puVar14[-2] = (ushort)bVar3 + sVar9;
    puVar14 = puVar14 + 8;
    FUN_8004789c(local_58,pbVar11[1],pbVar11[2],pbVar11[3]);
    pbVar11 = pbVar11 + -4;
    local_58 = uVar10;
  } while (iVar15 != 0);
  FUN_800478b8(iVar16,iVar20 + 0xfcU & 0xffff,iVar21 + 1U & 0xffff);
  *(undefined **)(iVar13 + 0x3b97c) = &DAT_8012f584;
  *(undefined2 *)(iVar13 + 0x3b97a) = 0xc0;
  if (DAT_8012bf99 == '\x02') {
    uVar4 = 0x80;
  }
  else {
    uVar4 = 0x40;
  }
  FUN_8004786c(iVar16,uVar4,uVar4,uVar4);
  FUN_800478b8(iVar13 + 0x3b984,iVar20 + 0xf8U & 0xffff,sVar9);
  *(undefined **)(iVar13 + 0x3b990) = &DAT_8012f530;
  *(undefined2 *)(iVar13 + 0x3b98e) = 0;
  FUN_800478b8(iVar13 + 0x3b998,iVar20 + 0x5eU & 0xffff,iVar21 + 0x7fU & 0xffff);
  if (((DAT_800df90c & 0x4008) == 0) || (DAT_8012bf9a == 0)) {
    uVar4 = 0x78;
  }
  else {
    uVar4 = 100;
  }
  FUN_800478ac(iVar13 + 0x3b998,0x12,uVar4);
  FUN_800478b8(iVar13 + 0x3b9ac,iVar20 + 0x5eU & 0xffff,iVar21 + 5U & 0xffff);
  if (((DAT_800df90c & 0x1004) == 0) || (DAT_8012bf9a == 0)) {
    uVar4 = 0x50;
  }
  else {
    uVar4 = 0x3c;
  }
  FUN_800478ac(iVar13 + 0x3b9ac,0x12,uVar4);
  iVar16 = 4;
  uVar18 = iVar13 + 0x3b9c0;
  do {
    iVar15 = (0x14 - iVar16) * 4;
    uVar17 = uVar18 + 0x14;
    FUN_800478b8(uVar18,(uint)*(ushort *)(&UNK_8012fb0c + iVar15) + iVar20 & 0xffff,
                 (uint)*(ushort *)(&UNK_8012fb0e + iVar15) + iVar21 +
                 ((uint)DAT_8012bfbc + iVar16 & 0x3f) * 2 & 0xffff);
    bVar1 = iVar16 != 0;
    iVar16 = iVar16 + -1;
    uVar18 = uVar17;
  } while (bVar1);
  iVar16 = 0x10;
  puVar12 = &DAT_8012fb48;
  while( true ) {
    iVar16 = iVar16 + -1;
    uVar18 = uVar17 + 0x14;
    FUN_800478b8(uVar17,(uint)*puVar12 + iVar20 & 0xffff,(uint)puVar12[1] + iVar21 & 0xffff);
    if (iVar16 == 0) break;
    puVar12 = puVar12 + -2;
    uVar17 = uVar18;
  }
  uVar17 = (uint)DAT_8012bf9a;
  if (uVar17 - 2 < 2) {
    if (uVar17 == 2) {
      sStack_4e = -0x14;
      local_4c = -1;
    }
    if (uVar17 == 3) {
      sStack_4e = 100;
      local_4c = 5;
    }
    if ((&DAT_800e8ef6)[((uint)DAT_8012bfbc + local_4c & 0x3f) * 4] == '\0') {
      FUN_80047824(local_54,0x28,0,0x28,0x1e);
      sVar9 = 0x18;
    }
    else {
      FUN_80047824(local_54,0x28,0,0x50,0x1e);
      sVar9 = 0x30;
    }
    sVar7 = DAT_8012bfea + sStack_4e + 0x1b;
    FUN_800478dc(local_54,DAT_8012bfe8 + 0x92,DAT_8012bfbd + sVar7,DAT_8012bfe8 + sVar9 + 0x93,
                 DAT_8012bfbd + sVar7,DAT_8012bfe8 + 0x92,
                 (short)DAT_8012bfbd + DAT_8012bfea + sStack_4e + 0x2e,DAT_8012bfe8 + sVar9 + 0x93,
                 (short)DAT_8012bfbd + DAT_8012bfea + sStack_4e + 0x2e);
  }
  else {
    local_54 = iVar13 + 0x3b828;
  }
  iVar15 = 5;
  uVar2 = iVar20 + 0x92U & 0xffff;
  local_38 = iVar21 + 0x81;
  local_34 = 0x92;
  iVar16 = 100;
  sVar9 = 0xb4;
  local_30 = 0x7f;
  uVar17 = iVar13 + 0x3b828;
  do {
    uVar19 = uVar17;
    local_38 = local_38 + -0x14;
    iVar16 = iVar16 + -0x14;
    local_34 = local_34 + -0x14;
    iVar15 = iVar15 + -1;
    local_30 = local_30 + -0x14;
    sVar9 = sVar9 + -0x1e;
    if ((&DAT_800e8ef6)[((uint)DAT_8012bfbc + iVar15 & 0x3f) * 4] == '\0') {
      FUN_80047824(uVar19,0x28,sVar9,0x28,0x1e);
      iVar8 = 0x18;
    }
    else {
      FUN_80047824(uVar19,0x28,sVar9,0x50,0x1e);
      iVar8 = 0x30;
    }
    uVar17 = iVar20 + iVar8 + 0x93U & 0xffff;
    FUN_800478dc(uVar19,uVar2,(int)DAT_8012bfbd + iVar21 + local_30 & 0xffff,uVar17,
                 (int)DAT_8012bfbd + iVar21 + local_30 & 0xffff,uVar2,
                 (int)DAT_8012bfbd + iVar21 + local_34 & 0xffff,uVar17,
                 (int)DAT_8012bfbd + iVar21 + local_34 & 0xffff);
    cVar6 = (&DAT_800e8ef4)[(iVar15 + (uint)DAT_8012bfbc & 0x3f) * 4];
    if (cVar6 == '\0') {
      cVar6 = 'd';
      iVar8 = iVar16 + iVar21 + 0x1d + (int)DAT_8012bfbd;
    }
    else {
      iVar8 = local_38 + DAT_8012bfbd;
    }
    FUN_8008c25c(iVar20 + 7,iVar8,6,cVar6);
    uVar17 = uVar19 + 0x28;
  } while (iVar15 != 0);
  iVar16 = iVar21 + (0x3f - (DAT_8012bfbc - 4 & 0x3f)) * 0x14 + 7;
  FUN_800478c4(uVar22,iVar20 + 5U & 0xffff,DAT_8012bfbd + iVar16 & 0xffff,iVar20 + 0xc4U & 0xffff,
               DAT_8012bfbd + iVar16 & 0xffff);
  bVar3 = DAT_8012bfbc + 2 & 0x3f;
  if ((bVar3 < 5) || (bVar3 == 0x3f)) {
    uVar22 = iVar13 + 0x3b920;
  }
  iVar16 = 2;
  iVar13 = 0x56;
  do {
    uVar17 = iVar21 + iVar13 & 0xffff;
    FUN_800478c4(uVar22,iVar20 + 5U & 0xffff,uVar17,iVar20 + 0xc4U & 0xffff,uVar17);
    iVar16 = iVar16 + -1;
    if (DAT_8012bf9a == 0) {
      cVar6 = '0';
      cVar5 = ' ';
      bVar3 = 8;
    }
    else {
      cVar6 = (byte)DAT_8012fb70 + 0x50;
      cVar5 = (byte)DAT_8012fb70 + 0x40;
      bVar3 = (byte)DAT_8012fb70 & 0x1f;
    }
    uVar17 = uVar22 + 0x10;
    FUN_8004788c(uVar22,cVar6,cVar5,bVar3);
    iVar13 = iVar13 + -0x14;
    uVar22 = uVar17;
  } while (iVar16 != 0);
  FUN_80043620();
  for (; DAT_800df8b4 = FUN_80044fdc(DAT_800df8b4,uVar19,0), local_54 < uVar19;
      uVar19 = uVar19 - 0x28) {
  }
  do {
    uVar18 = uVar18 - 0x14;
    FUN_80043620();
    DAT_800df8b8 = FUN_80043988(DAT_800df8b8,uVar18,0,0);
  } while (DAT_800c52dc + 0x3b970U < uVar18);
  do {
    uVar17 = uVar17 - 0x10;
    DAT_800df8b4 = FUN_80047298(DAT_800df8b4,uVar17);
  } while (DAT_800c52dc + 0x3b910U < uVar17);
  FUN_80043620();
  do {
    uVar22 = uVar10 - 0x10;
    *(undefined1 *)(uVar10 - 9) = 0x60;
    DAT_800df8b8 = FUN_80046f98(DAT_800df8b8,uVar22);
    uVar10 = uVar22;
  } while (DAT_800c52dc + 0x3b8f0U < uVar22);
  return;
}
