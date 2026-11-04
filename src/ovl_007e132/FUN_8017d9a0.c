/* FUN_8017d9a0
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017d9a0  body 0x8017d9a0..0x8017e14f  size 1968 B
 * body sha256 9828b7834568a1d2be623e2e4266e4c86caeeb9f3227d4c64636edb5296645d0
 * provider record sha256 ffd86ec3904acae841a0c7b72f159646ac990145cf9d2fcb3c2e4d4126779742
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017d9a0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  char *pcVar15;
  int unaff_s3;
  undefined2 uVar16;
  int iVar17;
  int iVar18;
  short local_70;
  undefined2 uStack_6e;
  undefined4 local_6c;
  short local_68;
  undefined2 uStack_66;
  undefined4 local_64;
  short local_60;
  undefined2 uStack_5e;
  undefined4 local_5c;
  short local_58;
  undefined2 uStack_56;
  undefined4 local_54;
  ushort local_4a;
  short local_42;
  short local_3a;
  int local_38;
  int local_34;
  undefined4 local_30;
  uint local_2c;
  
  func_0x80043620();
  local_34 = (int)((100 - (uint)*(ushort *)(DAT_8017e8e0 + 6)) * 0x10000) >> 0x10;
  if (local_34 == 100) {
    func_0x80077adc(0x1000000,0);
  }
  if (-1 < local_34) {
    local_30 = local_34 * 3;
    local_3a = 0;
    do {
      local_42 = 0;
      iVar1 = (int)local_3a;
      pcVar15 = (char *)(DAT_8017e8e0 + iVar1 * 0x3400 + 0x7354);
      do {
        local_4a = 0;
        iVar17 = (int)local_42;
        iVar18 = iVar17 * 8;
        local_38 = iVar17 + 2;
        local_2c = (uint)(local_34 < 0x14);
        do {
          iVar9 = (short)local_4a * 0x88;
          iVar2 = iVar18 + iVar9 + DAT_8017e8e0;
          uVar11 = *(undefined4 *)(iVar2 + 0x680c);
          iVar7 = iVar18 + iVar9 + DAT_8017e8e0;
          uVar12 = *(undefined4 *)(iVar7 + 0x691c);
          iVar3 = iVar9 + DAT_8017e8e0 + iVar18;
          iVar9 = iVar9 + DAT_8017e8e0 + iVar18;
          uVar13 = *(undefined4 *)(iVar3 + 0x6814);
          uVar14 = *(undefined4 *)(iVar9 + 0x6924);
          local_70 = (short)((uint)*(undefined4 *)(iVar2 + 0x6808) >> 0x10);
          local_68 = (short)((uint)*(undefined4 *)(iVar7 + 0x6918) >> 0x10);
          local_60 = (short)((uint)*(undefined4 *)(iVar3 + 0x6810) >> 0x10);
          local_58 = (short)((uint)*(undefined4 *)(iVar9 + 0x6920) >> 0x10);
          local_6c._2_2_ = (undefined2)uVar11;
          local_6c._0_2_ = (short)((uint)uVar11 >> 0x10);
          local_64._2_2_ = (undefined2)uVar12;
          local_64._0_2_ = (short)((uint)uVar12 >> 0x10);
          local_5c._0_2_ = (short)((uint)uVar13 >> 0x10);
          local_54._0_2_ = (short)((uint)uVar14 >> 0x10);
          if (iVar1 == 1) {
            iVar2 = (*(ushort *)(DAT_8017e8e0 + 6) - 4) * 0x10000;
            iVar3 = iVar2 >> 0x10;
            if (-1 < iVar3) {
              if (iVar3 < 5) {
                *pcVar15 = (char)((uint)iVar2 >> 0x10) * '(';
                unaff_s3 = iVar3 * iVar3 * 0xe + 200;
              }
              else {
                *pcVar15 = -0x38;
                unaff_s3 = 0x1b8;
              }
              local_70 = local_70 + 0x104;
              local_68 = local_68 + 0x104;
              local_60 = local_60 + 0x104;
              local_58 = local_58 + 0x104;
              local_6c._0_2_ = local_6c._0_2_ + -0x70;
              local_64._0_2_ = local_64._0_2_ + -0x70;
              local_5c._0_2_ = local_5c._0_2_ + -0x70;
              local_54._0_2_ = local_54._0_2_ + -0x70;
LAB_8017dd68:
              local_5c._2_2_ = (undefined2)uVar13;
              local_54._2_2_ = (undefined2)uVar14;
              uVar11 = local_6c;
              uVar12 = local_64;
              uVar13 = local_5c;
              uVar14 = local_54;
            }
          }
          else if (iVar1 < 2) {
            if (iVar1 == 0) {
              if (*(short *)(DAT_8017e8e0 + 6) < 5) {
                *pcVar15 = (char)*(short *)(DAT_8017e8e0 + 6) * '(';
                unaff_s3 = (int)*(short *)(DAT_8017e8e0 + 6) * (int)*(short *)(DAT_8017e8e0 + 6) *
                           0xe + 0x168;
              }
              else {
                *pcVar15 = -0x38;
                unaff_s3 = 600;
              }
              local_70 = local_70 + 0x5a;
              local_68 = local_68 + 0x5a;
              local_60 = local_60 + 0x5a;
              local_58 = local_58 + 0x5a;
            }
          }
          else if (iVar1 == 2) {
            iVar2 = (*(ushort *)(DAT_8017e8e0 + 6) - 9) * 0x10000;
            iVar3 = iVar2 >> 0x10;
            if (-1 < iVar3) {
              if (iVar3 < 3) {
                *pcVar15 = (char)((uint)iVar2 >> 0x10) * '(';
                unaff_s3 = iVar3 * iVar3 * 10 + 0xa0;
              }
              else {
                *pcVar15 = -0x38;
                unaff_s3 = 0x140;
              }
              local_70 = local_70 + -0x10e;
              local_68 = local_68 + -0x10e;
              local_60 = local_60 + -0x10e;
              local_58 = local_58 + -0x10e;
              local_6c._0_2_ = local_6c._0_2_ + -0x54;
              local_64._0_2_ = local_64._0_2_ + -0x54;
              local_5c._0_2_ = local_5c._0_2_ + -0x54;
              local_54._0_2_ = local_54._0_2_ + -0x54;
              goto LAB_8017dd68;
            }
          }
          local_54 = uVar14;
          local_5c = uVar13;
          local_64 = uVar12;
          local_6c = uVar11;
          if (*pcVar15 != '\0') {
            uVar16 = (undefined2)unaff_s3;
            _local_70 = CONCAT22(local_70,uVar16);
            _local_68 = CONCAT22(local_68,uVar16);
            _local_60 = CONCAT22(local_60,uVar16);
            _local_58 = CONCAT22(local_58,uVar16);
            sVar4 = local_6c._0_2_ << 1;
            sVar8 = local_5c._0_2_ << 1;
            sVar5 = local_64._0_2_ << 1;
            sVar6 = local_54._0_2_ << 1;
            local_6c._0_2_ = sVar4;
            local_64._0_2_ = sVar5;
            local_5c._0_2_ = sVar8;
            local_54._0_2_ = sVar6;
            if (0x14 < *(short *)(DAT_8017e8e0 + 6)) {
              uVar10 = (uint)local_4a;
              iVar3 = (int)(uVar10 << 0x10) >> 0x10;
              iVar2 = func_0x800408c0(iVar1 * 0x10000 + iVar3 * 0x40);
              iVar3 = func_0x800408c0((iVar1 * 7 + iVar3) * 0x100);
              iVar2 = ((iVar2 + iVar3 + 0x1000) / 0x140) * (*(short *)(DAT_8017e8e0 + 6) + -0x14);
              uVar10 = (int)(uVar10 << 0x10) >> 0x11 & 3;
              if (uVar10 == 1) {
                iVar3 = (iVar2 * (iVar17 + 1)) / 0x28;
                sVar4 = (short)(iVar3 >> 4);
                sVar6 = (short)(iVar3 >> 3);
                iVar3 = (iVar2 * local_38) / 0x28;
                sVar5 = (short)(iVar3 >> 4);
                sVar8 = (short)(iVar3 >> 3);
LAB_8017dffc:
                local_54._0_2_ = local_54._0_2_ + sVar8;
                local_5c._0_2_ = local_5c._0_2_ + sVar5;
                local_64._0_2_ = local_64._0_2_ + sVar6;
                local_6c._0_2_ = local_6c._0_2_ + sVar4;
              }
              else if (uVar10 < 2) {
                if (uVar10 == 0) {
LAB_8017de70:
                  sVar4 = (short)((iVar2 * (iVar17 + 1)) / 0x28 >> 4);
                  sVar5 = (short)((iVar2 * local_38) / 0x28 >> 4);
                  sVar6 = sVar4;
                  sVar8 = sVar5;
                  goto LAB_8017dffc;
                }
              }
              else {
                if (uVar10 == 2) {
                  iVar3 = (iVar2 * (iVar17 + 1)) / 0x28;
                  sVar4 = (short)(iVar3 >> 3);
                  sVar6 = (short)(iVar3 >> 4);
                  iVar3 = (iVar2 * local_38) / 0x28;
                  sVar5 = (short)(iVar3 >> 3);
                  sVar8 = (short)(iVar3 >> 4);
                  goto LAB_8017dffc;
                }
                if (uVar10 == 3) goto LAB_8017de70;
              }
              if (iVar17 == 0xf) {
                sVar4 = (short)(iVar2 >> 4);
                local_5c._0_2_ = local_5c._0_2_ + sVar4;
                local_54._0_2_ = local_54._0_2_ + sVar4;
              }
            }
            func_0x80042f9c(&local_70,&local_68,&local_60);
            func_0x80043460(pcVar15 + 4,pcVar15 + 0x10,pcVar15 + 0x1c);
            func_0x80042de0(&local_58);
            if ((local_34 < 0x29) && (*pcVar15 = (char)(local_30 << 1), local_2c != 0)) {
              *(undefined2 *)(DAT_8017e8e0 + 0x10f56) = 1;
              pcVar15[0x16] = '\0';
              pcVar15[0x17] = -0x4b;
              *pcVar15 = (char)local_30;
            }
            func_0x8004341c(pcVar15 + 0x28);
            DAT_8017e754 = func_0x80046208(DAT_8017e754,pcVar15);
          }
          local_4a = local_4a + 2;
          pcVar15 = pcVar15 + 0x34;
        } while ((short)local_4a < 0x10);
        local_42 = local_42 + 1;
      } while (local_42 < 0x10);
      local_3a = local_3a + 1;
    } while (local_3a < 3);
    *(short *)(DAT_8017e8e0 + 6) = *(short *)(DAT_8017e8e0 + 6) + 1;
  }
  return;
}
