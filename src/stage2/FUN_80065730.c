/* FUN_80065730
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80065730  body 0x80065730..0x80065f43  size 2068 B
 * body sha256 38cd2757b278de2cb42a3a1dba53bede29635f9282478dce30d216fbf081e607
 * provider record sha256 9f1bf4e955d9959c4c24b876305f175c5ac62ee770d23c238bf4348ae046dc5d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80065730(uint param_1,byte param_2,short param_3,short param_4)

{
  undefined1 uVar2;
  int iVar1;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  ushort *puVar12;
  int iVar13;
  short sVar14;
  short sVar15;
  short *psVar16;
  undefined2 *puVar17;
  ushort *puVar18;
  uint uVar19;
  ushort *puVar20;
  short *psVar21;
  ushort local_200 [16];
  ushort local_1e0 [16];
  ushort local_1c0 [16];
  short local_1a0;
  short local_19e;
  short local_19c;
  short local_19a;
  short local_198;
  short local_196;
  undefined1 local_158;
  byte local_157;
  int local_148 [4];
  int local_138;
  uint local_134;
  int local_130;
  int local_128;
  uint local_124;
  int local_120;
  undefined1 local_118;
  char local_117;
  undefined2 local_108 [3];
  undefined2 local_102;
  short local_100;
  short local_fe;
  short local_fc;
  short local_fa;
  byte local_88;
  short local_7a;
  short local_72;
  ushort local_6a;
  int local_68;
  char local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined1 *local_4c;
  uint local_48;
  undefined1 *local_40;
  ushort *local_3c;
  int local_38;
  undefined2 *local_30;
  
  local_7a = param_3;
  local_88 = param_2;
  local_72 = param_4;
  puVar18 = local_200;
  psVar21 = &local_1a0;
  local_6a = (ushort)(1 << (param_2 & 0x1f));
  uVar19 = 0;
  local_30 = local_108;
  local_48 = (uint)param_2;
  local_68 = 0x7fffffff;
  local_4c = &local_158;
  local_50 = DAT_800df938;
  local_1e0[0] = (ushort)(1 << (param_1 & 0x1f));
  local_1c0[0] = 0;
  local_1a0 = *(short *)(DAT_800df938 + 0x2a);
  local_19e = *(short *)(DAT_800df938 + 0x32);
  local_158 = (char)param_1;
  local_200[0] = *(ushort *)((param_1 & 0xff) * 0xc + *(int *)(DAT_800df92c + 0x38) + 0xe);
  puVar11 = &local_118;
  puVar12 = local_1e0;
  iVar1 = *(int *)(DAT_800df92c + 0x38);
  psVar16 = &local_19e;
  puVar17 = &local_102;
  puVar20 = local_1c0;
  while ((local_200[0] != 0 || (puVar18 != local_200))) {
    uVar3 = *puVar18;
    if (uVar3 == 0) {
      puVar18 = puVar18 + -1;
      psVar21 = psVar21 + -2;
      uVar19 = uVar19 - 1;
      local_30 = local_30 + -4;
      param_1 = (uint)(byte)local_4c[uVar19 & 0xff];
      puVar11 = puVar11 + -1;
      puVar12 = puVar12 + -1;
      psVar16 = psVar16 + -2;
      puVar17 = puVar17 + -4;
      puVar20 = puVar20 + -1;
    }
    else if ((local_6a & uVar3) == 0) {
      uVar7 = param_1 & 0xff;
      param_1 = 0;
      if ((*puVar18 & 1) == 0) {
        for (param_1 = 1; ((int)(uint)*puVar18 >> (param_1 & 0x1f) & 1U) == 0; param_1 = param_1 + 1
            ) {
        }
      }
      psVar21 = psVar21 + 2;
      iVar13 = iVar1 + uVar7 * 0xc;
      iVar6 = iVar1 + (param_1 & 0xff) * 0xc;
      local_30 = local_30 + 4;
      puVar11 = puVar11 + 1;
      *puVar18 = *puVar18 & ~(ushort)(1 << (param_1 & 0x1f));
      iVar10 = (int)*(short *)(iVar13 + 10);
      iVar5 = (int)*(short *)(iVar6 + 6);
      iVar9 = (int)*(short *)(iVar13 + 6);
      iVar8 = (int)*(short *)(iVar6 + 10);
      if ((iVar9 == iVar8) || (iVar10 == iVar5)) {
        sVar15 = *(short *)(iVar13 + 6);
        if (iVar10 == iVar5) {
          sVar15 = *(short *)(iVar13 + 10);
        }
        iVar10 = (int)sVar15;
        iVar5 = (int)*(short *)(iVar13 + 4);
        if ((int)*(short *)(iVar13 + 4) < (int)*(short *)(iVar6 + 4)) {
          iVar5 = (int)*(short *)(iVar6 + 4);
        }
        iVar4 = (int)*(short *)(iVar13 + 8);
        if ((int)*(short *)(iVar6 + 8) < (int)*(short *)(iVar13 + 8)) {
          iVar4 = (int)*(short *)(iVar6 + 8);
        }
        sVar14 = (short)((uint)(iVar5 + iVar4) >> 1);
        uVar2 = 0;
        iVar9 = iVar10;
      }
      else {
        sVar14 = *(short *)(iVar13 + 4);
        if (*(short *)(iVar13 + 8) == *(short *)(iVar6 + 4)) {
          sVar14 = *(short *)(iVar6 + 4);
        }
        iVar4 = (int)sVar14;
        if (iVar9 < iVar5) {
          iVar9 = iVar5;
        }
        if (iVar8 < iVar10) {
          iVar10 = iVar8;
        }
        sVar15 = (short)((uint)(iVar9 + iVar10) >> 1);
        uVar2 = 1;
        iVar5 = iVar4;
      }
      *local_30 = (short)iVar5;
      puVar17[2] = (short)iVar9;
      puVar17[3] = (short)iVar4;
      puVar17[4] = (short)iVar10;
      *puVar11 = uVar2;
      iVar10 = (int)psVar16[-1] - (int)sVar14;
      if (iVar10 < 0) {
        iVar10 = -iVar10;
      }
      iVar9 = (int)*psVar16 - (int)sVar15;
      if (iVar9 < 0) {
        iVar9 = -iVar9;
      }
      uVar19 = uVar19 + 1;
      puVar18 = puVar18 + 1;
      puVar20[1] = *puVar20 + (short)iVar10 + (short)iVar9;
      *psVar21 = sVar14;
      psVar16[2] = sVar15;
      local_4c[uVar19 & 0xff] = (char)param_1;
      uVar3 = *puVar12 | (ushort)(1 << (param_1 & 0x1f));
      puVar12[1] = uVar3;
      *puVar18 = *(ushort *)((param_1 & 0xff) * 0xc + iVar1 + 0xe) & ~uVar3;
      puVar12 = puVar12 + 1;
      psVar16 = psVar16 + 2;
      puVar17 = puVar17 + 4;
      puVar20 = puVar20 + 1;
    }
    else {
      iVar13 = iVar1 + (param_1 & 0xff) * 0xc;
      iVar6 = iVar1 + local_48 * 0xc;
      *puVar18 = uVar3 & ~local_6a;
      iVar10 = (int)*(short *)(iVar13 + 10);
      iVar5 = (int)*(short *)(iVar6 + 6);
      iVar9 = (int)*(short *)(iVar13 + 6);
      iVar8 = (int)*(short *)(iVar6 + 10);
      if ((iVar9 == iVar8) || (iVar10 == iVar5)) {
        sVar15 = *(short *)(iVar13 + 6);
        if (iVar10 == iVar5) {
          sVar15 = *(short *)(iVar13 + 10);
        }
        iVar10 = (int)sVar15;
        iVar5 = (int)*(short *)(iVar13 + 4);
        if ((int)*(short *)(iVar13 + 4) < (int)*(short *)(iVar6 + 4)) {
          iVar5 = (int)*(short *)(iVar6 + 4);
        }
        iVar4 = (int)*(short *)(iVar13 + 8);
        if ((int)*(short *)(iVar6 + 8) < (int)*(short *)(iVar13 + 8)) {
          iVar4 = (int)*(short *)(iVar6 + 8);
        }
        sVar14 = (short)((uint)(iVar5 + iVar4) >> 1);
        uVar2 = 0;
        iVar9 = iVar10;
      }
      else {
        sVar14 = *(short *)(iVar13 + 4);
        if (*(short *)(iVar13 + 8) == *(short *)(iVar6 + 4)) {
          sVar14 = *(short *)(iVar6 + 4);
        }
        iVar4 = (int)sVar14;
        if (iVar9 < iVar5) {
          iVar9 = iVar5;
        }
        if (iVar8 < iVar10) {
          iVar10 = iVar8;
        }
        sVar15 = (short)((uint)(iVar9 + iVar10) >> 1);
        uVar2 = 1;
        iVar5 = iVar4;
      }
      puVar17[1] = (short)iVar5;
      puVar17[2] = (short)iVar9;
      puVar17[3] = (short)iVar4;
      puVar17[4] = (short)iVar10;
      puVar11[1] = uVar2;
      psVar16[1] = sVar14;
      psVar16[2] = sVar15;
      psVar16[3] = local_7a;
      psVar16[4] = local_72;
      iVar10 = (int)*psVar21 - (int)sVar14 >> 3;
      iVar9 = (int)*psVar16 - (int)sVar15 >> 3;
      local_40 = puVar11;
      local_3c = puVar12;
      local_38 = iVar1;
      iVar1 = FUN_80040bb4(iVar10 * iVar10 + iVar9 * iVar9);
      iVar10 = (int)local_7a - (int)sVar14 >> 3;
      iVar9 = (int)local_72 - (int)sVar15 >> 3;
      iVar10 = FUN_80040bb4(iVar10 * iVar10 + iVar9 * iVar9);
      iVar10 = (uint)*puVar20 + iVar1 + iVar10;
      local_4c[(uVar19 & 0xff) + 1] = local_88;
      puVar11 = local_40;
      puVar12 = local_3c;
      iVar1 = local_38;
      if (iVar10 < local_68) {
        param_1 = (uint)local_157;
        local_60 = (int)local_19c;
        local_5c = (int)local_19a;
        local_64 = local_117;
        local_68 = iVar10;
        local_138 = (int)local_100;
        local_130 = (int)local_fe;
        local_128 = (int)local_fc;
        local_120 = (int)local_fa;
        local_58 = (int)local_198;
        local_54 = (int)local_196;
      }
    }
  }
  if (local_64 == '\0') {
    iVar1 = local_5c - *(int *)(local_50 + 0x30);
    if (iVar1 == 0) {
      iVar10 = 0x7fffffff;
    }
    else {
      iVar9 = (local_60 - *(int *)(local_50 + 0x28)) * 0x1000;
      iVar10 = iVar9 / iVar1;
      if (iVar1 == 0) {
        trap(0x1c00);
      }
      if ((iVar1 == -1) && (iVar9 == -0x80000000)) {
        trap(0x1800);
      }
    }
    if (iVar10 < 0) {
      iVar10 = -iVar10;
    }
    iVar9 = local_5c;
    if ((10000 < iVar10) && (iVar9 = local_5c + -800, iVar1 < 0)) {
      iVar9 = local_5c + 800;
    }
    local_5c = iVar9;
    iVar1 = 800;
    iVar10 = 0;
  }
  else {
    iVar1 = local_60 - *(int *)(local_50 + 0x28);
    if (iVar1 == 0) {
      iVar10 = 0x7fffffff;
    }
    else {
      iVar9 = (local_5c - *(int *)(local_50 + 0x30)) * 0x1000;
      iVar10 = iVar9 / iVar1;
      if (iVar1 == 0) {
        trap(0x1c00);
      }
      if ((iVar1 == -1) && (iVar9 == -0x80000000)) {
        trap(0x1800);
      }
    }
    if (iVar10 < 0) {
      iVar10 = -iVar10;
    }
    iVar9 = local_60;
    if ((10000 < iVar10) && (iVar9 = local_60 + -800, iVar1 < 0)) {
      iVar9 = local_60 + 800;
    }
    local_60 = iVar9;
    iVar1 = 0;
    iVar10 = 800;
  }
  local_148[1] = 0;
  local_148[0] = local_58 - *(int *)(local_50 + 0x28);
  local_148[2] = local_54 - *(int *)(local_50 + 0x30);
  local_134 = 0;
  local_138 = local_138 - (*(int *)(local_50 + 0x28) - iVar1);
  local_130 = local_130 - (*(int *)(local_50 + 0x30) - iVar10);
  local_124 = 0;
  local_128 = local_128 - (*(int *)(local_50 + 0x28) + iVar1);
  local_120 = local_120 - (*(int *)(local_50 + 0x30) + iVar10);
  FUN_80040c6c(&local_138,local_148,&local_138);
  FUN_80040c6c(&local_128,local_148,&local_128);
  if ((local_134 & 0x80000000) != (local_124 & 0x80000000)) {
    local_60 = local_58;
    local_5c = local_54;
  }
  *(undefined2 *)(local_50 + 0x260) = local_60._2_2_;
  *(undefined2 *)(local_50 + 0x262) = local_5c._2_2_;
  return;
}
