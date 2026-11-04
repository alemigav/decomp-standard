/* FUN_800856f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800856f0  body 0x800856f0..0x800874d3  size 7652 B
 * body sha256 e8ce32eaba0ba14ccce2f355cd435ee8ff68dba12cd8de989aed8e12e40d8e12
 * provider record sha256 f604054391360b198b663befa8e93b6ed7bcc3e0a735358ff185ca479ed49cbd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80086d14) */
/* WARNING: Removing unreachable block (ram,0x80086d5c) */

void FUN_800856f0(void)

{
  undefined4 *puVar1;
  short sVar2;
  ushort uVar3;
  bool bVar4;
  bool bVar5;
  undefined4 *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  int iVar17;
  int iVar18;
  byte *pbVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int *piVar23;
  int iVar24;
  uint uVar25;
  int local_60;
  uint local_5c;
  uint local_58;
  uint *local_40;
  uint local_3c;
  uint local_38;
  int *local_2c;
  
  piVar23 = DAT_80124884;
  puVar1 = DAT_800df8b0;
  local_5c = 0;
  local_58 = 0;
  puVar6 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xdb020000;
  DAT_800df8b0 = puVar6;
  puVar1[1] = 0x18;
  puVar6 = DAT_800df8b0;
  puVar1 = DAT_800df8b0 + 1;
  DAT_800df8b0 = DAT_800df8b0 + 2;
  *puVar1 = &DAT_80124848;
  *puVar6 = 0xdc08060a;
  puVar1 = DAT_800df8b0;
  puVar6 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xdc08090a;
  DAT_800df8b0 = puVar6;
  puVar1[1] = &DAT_80124840;
  puVar1 = DAT_800df8b0;
  puVar6 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xdb040004;
  DAT_800df8b0 = puVar6;
  puVar1[1] = 6;
  puVar1 = DAT_800df8b0;
  puVar6 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xdb04000c;
  DAT_800df8b0 = puVar6;
  puVar1[1] = 6;
  puVar1 = DAT_800df8b0;
  puVar6 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xdb040014;
  DAT_800df8b0 = puVar6;
  puVar1[1] = 0xfffa;
  puVar1 = DAT_800df8b0;
  puVar7 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xdb04001c;
  DAT_800df8b0 = puVar7;
  puVar1[1] = 0xfffa;
  puVar7 = DAT_800df8b0;
  if (piVar23 != (int *)0x0) {
    puVar16 = DAT_800df8b0 + 2;
    *DAT_800df8b0 = 0xe7000000;
    DAT_800df8b0 = puVar16;
    puVar7[1] = 0;
    puVar7 = DAT_800df8b0;
    puVar16 = DAT_800df8b0 + 2;
    *DAT_800df8b0 = 0xd9d0f9fa;
    DAT_800df8b0 = puVar16;
    puVar7[1] = 0;
    puVar7 = DAT_800df8b0;
    puVar16 = DAT_800df8b0 + 2;
    *DAT_800df8b0 = 0xd7000000;
    DAT_800df8b0 = puVar16;
    puVar7[1] = 0;
    puVar7 = DAT_800df8b0;
    puVar16 = DAT_800df8b0 + 2;
    *DAT_800df8b0 = 0xfc327e64;
    DAT_800df8b0 = puVar16;
    puVar7[1] = 0x55fefb7d;
    puVar7 = DAT_800df8b0;
    puVar16 = DAT_800df8b0 + 2;
    *DAT_800df8b0 = 0xd9d0f9fa;
    DAT_800df8b0 = puVar16;
    puVar7[1] = 0;
    puVar7 = DAT_800df8b0;
    if (DAT_80131730 == 0) {
      puVar16 = DAT_800df8b0 + 2;
      *DAT_800df8b0 = 0xd9ffffff;
      DAT_800df8b0 = puVar16;
      puVar7[1] = 0x220404;
      uVar14 = 0xf0a4000;
      puVar7 = DAT_800df8b0;
    }
    else {
      puVar16 = DAT_800df8b0 + 2;
      *DAT_800df8b0 = 0xd9ffffff;
      DAT_800df8b0 = puVar16;
      puVar7[1] = 0x220405;
      uVar14 = 0x552230;
      puVar7 = DAT_800df8b0;
    }
    DAT_800df8b0 = puVar7 + 2;
    *puVar7 = 0xe200001c;
    puVar7[1] = uVar14;
    puVar7 = DAT_800df8b0;
    puVar16 = DAT_800df8b0 + 2;
    *DAT_800df8b0 = 0xe3000a01;
    DAT_800df8b0 = puVar16;
    puVar7[1] = 0;
    for (; puVar7 = DAT_800df8b0, piVar23 != (int *)0x0; piVar23 = (int *)piVar23[1]) {
      pbVar19 = *(byte **)(*piVar23 + 8);
      puVar16 = DAT_800df8b0 + 2;
      *DAT_800df8b0 = 0xe7000000;
      DAT_800df8b0 = puVar16;
      puVar7[1] = 0;
      uVar14 = piVar23[2];
      if ((uVar14 != 0) && (local_5c != uVar14)) {
        iVar21 = *(int *)(uVar14 + 0x38);
        uVar15 = uVar14 + 8;
        uVar11 = 6;
        for (iVar17 = 1; puVar7 = DAT_800df8b0, uVar8 = uVar11 & 0xff, iVar17 <= iVar21;
            iVar17 = iVar17 + 1) {
          uVar11 = uVar11 + 3;
          puVar16 = DAT_800df8b0 + 1;
          DAT_800df8b0 = DAT_800df8b0 + 2;
          *puVar16 = uVar15;
          uVar15 = uVar15 + 0x10;
          *puVar7 = uVar8 << 8 | 0xdc08000a;
        }
        puVar16 = DAT_800df8b0 + 2;
        *DAT_800df8b0 = ((iVar21 + 1) * 3 + 3U & 0xff) << 8 | 0xdc08000a;
        DAT_800df8b0 = puVar16;
        puVar7[1] = uVar14;
        puVar7 = DAT_800df8b0;
        local_5c = piVar23[2];
        puVar16 = DAT_800df8b0 + 2;
        *DAT_800df8b0 = 0xdb020000;
        DAT_800df8b0 = puVar16;
        puVar7[1] = iVar21 * 0x18;
      }
      puVar7 = DAT_800df8b0;
      puVar16 = DAT_800df8b0 + 2;
      *DAT_800df8b0 = 0xfa000000;
      DAT_800df8b0 = puVar16;
      puVar7[1] = (uint)*pbVar19 << 0x18 | (uint)pbVar19[1] << 0x10 | (uint)pbVar19[2] << 8 |
                  (uint)pbVar19[3];
      puVar7 = DAT_800df8b0;
      puVar16 = DAT_800df8b0 + 2;
      *DAT_800df8b0 = 0xfb000000;
      DAT_800df8b0 = puVar16;
      puVar7[1] = (uint)pbVar19[4] << 0x18 | (uint)pbVar19[5] << 0x10 | (uint)pbVar19[6] << 8 |
                  (uint)pbVar19[7];
      puVar7 = DAT_800df8b0;
      puVar16 = DAT_800df8b0 + 2;
      *DAT_800df8b0 = 0xda380000;
      DAT_800df8b0 = puVar16;
      puVar7[1] = piVar23[3] + 0x68;
      puVar7 = DAT_800df8b0;
      if (piVar23[4] == 0) {
        puVar16 = DAT_800df8b0 + 2;
        *DAT_800df8b0 = 0xdb060008;
        DAT_800df8b0 = puVar16;
        puVar7[1] = *(uint *)*piVar23;
      }
      else {
        puVar16 = DAT_800df8b0 + 2;
        *DAT_800df8b0 = 0xdb060008;
        DAT_800df8b0 = puVar16;
        puVar7[1] = piVar23[4];
      }
      puVar7 = DAT_800df8b0;
      puVar16 = DAT_800df8b0 + 2;
      *DAT_800df8b0 = 0xde000000;
      DAT_800df8b0 = puVar16;
      puVar7[1] = *(uint *)(*piVar23 + 4);
      puVar7 = DAT_800df8b0;
      puVar16 = DAT_800df8b0 + 2;
      *DAT_800df8b0 = 0xd8380002;
      DAT_800df8b0 = puVar16;
      puVar7[1] = 0x40;
    }
  }
  puVar7 = DAT_800df8b0;
  puVar16 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xe7000000;
  DAT_800df8b0 = puVar16;
  puVar7[1] = 0;
  puVar7 = DAT_800df8b0;
  puVar16 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xd7000002;
  DAT_800df8b0 = puVar16;
  puVar7[1] = 0x80008000;
  puVar7 = DAT_800df8b0;
  puVar16 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xe3000c00;
  DAT_800df8b0 = puVar16;
  puVar7[1] = 0x80000;
  puVar7 = DAT_800df8b0;
  puVar16 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xe2001e01;
  DAT_800df8b0 = puVar16;
  puVar7[1] = 0;
  puVar7 = DAT_800df8b0;
  puVar16 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xe3001201;
  DAT_800df8b0 = puVar16;
  puVar7[1] = 0x2000;
  puVar7 = DAT_800df8b0;
  puVar16 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xe3000d01;
  DAT_800df8b0 = puVar16;
  puVar7[1] = 0;
  puVar7 = DAT_800df8b0;
  puVar16 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xe3001402;
  DAT_800df8b0 = puVar16;
  puVar7[1] = 0xc00;
  puVar7 = DAT_800df8b0;
  puVar16 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xe3000f00;
  DAT_800df8b0 = puVar16;
  puVar7[1] = 0;
  puVar7 = DAT_800df8b0;
  puVar16 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xfc127e24;
  DAT_800df8b0 = puVar16;
  puVar7[1] = 0xfffff3f9;
  puVar7 = DAT_800df8b0;
  puVar16 = DAT_800df8b0 + 2;
  *DAT_800df8b0 = 0xe3000a01;
  DAT_800df8b0 = puVar16;
  puVar7[1] = 0;
  for (iVar17 = 0; puVar7 = DAT_800df8b0, iVar17 < 2; iVar17 = iVar17 + 1) {
    puVar16 = DAT_800df8b0 + 2;
    *DAT_800df8b0 = 0xd9d0f9fa;
    DAT_800df8b0 = puVar16;
    puVar7[1] = 0;
    puVar7 = DAT_800df8b0;
    if (iVar17 == 0) {
      if (DAT_80131778 == 0) {
        puVar16 = DAT_800df8b0 + 2;
        *DAT_800df8b0 = 0xfc127e24;
        DAT_800df8b0 = puVar16;
        puVar7[1] = 0xfffff3f9;
      }
      else {
        puVar16 = DAT_800df8b0 + 2;
        *DAT_800df8b0 = 0xfc6278c4;
        DAT_800df8b0 = puVar16;
        puVar7[1] = 0xfff3ffff;
      }
      puVar7 = DAT_800df8b0;
      if (DAT_80131730 == 0) {
        puVar16 = DAT_800df8b0 + 1;
        DAT_800df8b0 = DAT_800df8b0 + 2;
        *puVar16 = 0x220404;
        *puVar7 = 0xd9ffffff;
        uVar14 = 0xf0a4000;
        puVar7 = DAT_800df8b0;
      }
      else {
        puVar16 = DAT_800df8b0 + 1;
        DAT_800df8b0 = DAT_800df8b0 + 2;
        *puVar16 = 0x220405;
        *puVar7 = 0xd9ffffff;
        uVar14 = 0x552230;
        puVar7 = DAT_800df8b0;
      }
      DAT_800df8b0 = puVar7 + 2;
      puVar7[1] = uVar14;
      *puVar7 = 0xe200001c;
    }
    else {
      if (DAT_80131778 == 0) {
        puVar16 = DAT_800df8b0 + 2;
        *DAT_800df8b0 = 0xfc127e24;
        DAT_800df8b0 = puVar16;
        puVar7[1] = 0xfffff3f9;
      }
      else {
        puVar16 = DAT_800df8b0 + 2;
        *DAT_800df8b0 = 0xfc6278c4;
        DAT_800df8b0 = puVar16;
        puVar7[1] = 0xfff3ffff;
      }
      puVar7 = DAT_800df8b0;
      if (DAT_80131730 == 0) {
        puVar16 = DAT_800df8b0 + 1;
        DAT_800df8b0 = DAT_800df8b0 + 2;
        *puVar16 = 0x220404;
        *puVar7 = 0xd9ffffff;
      }
      else {
        puVar16 = DAT_800df8b0 + 1;
        DAT_800df8b0 = DAT_800df8b0 + 2;
        *puVar16 = 0x220405;
        *puVar7 = 0xd9ffffff;
      }
    }
    bVar5 = true;
    local_60 = 0x7e;
    local_40 = &DAT_80124870;
    local_3c = DAT_8012486c;
    local_38 = 2;
    local_2c = &DAT_80124890;
    while (puVar7 = DAT_800df8b0, local_60 = local_60 + -1, local_60 != -1) {
      if (local_38 == 0) {
        local_38 = 1;
        local_3c = *local_40;
        local_40 = local_40 + 1;
      }
      if (((local_3c & local_38) != 0) && (piVar23 = (int *)local_2c[1], piVar23 != (int *)0x0)) {
        iVar21 = 2;
        if ((piVar23[5] & 2U) != 0) {
          iVar21 = 0;
        }
        if (iVar17 == 1) {
          puVar16 = DAT_800df8b0 + 1;
          DAT_800df8b0 = DAT_800df8b0 + 2;
          *puVar16 = 0x404a70;
          *puVar7 = 0xe200001c;
        }
        puVar7 = DAT_800df8b0;
        if ((piVar23[5] & 8U) == 0) {
          puVar16 = DAT_800df8b0 + 2;
          *DAT_800df8b0 = 0xe3001201;
          DAT_800df8b0 = puVar16;
          puVar7[1] = 0x2000;
        }
        else {
          puVar16 = DAT_800df8b0 + 2;
          *DAT_800df8b0 = 0xe3001201;
          DAT_800df8b0 = puVar16;
          puVar7[1] = 0;
        }
        iVar24 = 0;
        if (((iVar17 == 0) && (*(ushort *)(*local_2c + 8) < 5)) ||
           ((iVar17 == 1 && (4 < *(ushort *)(*local_2c + 8))))) {
          uVar14 = 0;
          uVar15 = iVar21 << 0x12;
          uVar11 = iVar21 << 8;
          while (puVar7 = DAT_800df8b0, (int)uVar14 < 2) {
            uVar8 = uVar14 << 7;
            if (uVar14 == 0) {
              iVar21 = *local_2c;
            }
            else {
              iVar21 = local_2c[2];
            }
            if (iVar21 == 0) {
              uVar14 = uVar14 + 1;
            }
            else {
              iVar24 = iVar24 + 1;
              uVar9 = (uint)*(ushort *)(iVar21 + 2);
              uVar22 = 0;
              while (uVar9 = (int)uVar9 >> 1, uVar9 != 0) {
                uVar22 = uVar22 + 1;
              }
              uVar9 = (uint)*(ushort *)(iVar21 + 4);
              uVar20 = 0;
              while (uVar9 = (int)uVar9 >> 1, uVar9 != 0) {
                uVar20 = uVar20 + 1;
              }
              puVar16 = DAT_800df8b0 + 2;
              *DAT_800df8b0 = 0xe7000000;
              DAT_800df8b0 = puVar16;
              puVar7[1] = 0;
              puVar7 = DAT_800df8b0;
              sVar2 = *(short *)(iVar21 + 8);
              if ((sVar2 == 1) || (sVar2 == 7)) {
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe3001001;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0x8000;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xfd100000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = iVar21 + 0x10;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe8000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = (uVar14 & 0xf) << 4 | 0xf5000100;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0x7000000;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe6000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xf0000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0x703c000;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe7000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xfd500000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = iVar21 + 0x30;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = uVar8 & 0x1ff | 0xf5500000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = uVar15 | (uVar20 & 0xf) << 0xe | 0x7000000 | (8 - uVar20 & 0xf) << 10 |
                            uVar11 | (uVar22 & 0xf) << 4 | 8 - uVar22 & 0xf;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe6000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xf3000000;
                DAT_800df8b0 = puVar16;
                uVar12 = (uint)(*(ushort *)(iVar21 + 2) >> 4);
                uVar9 = 0x800;
                if (uVar12 != 0) {
                  uVar9 = uVar12 + 0x7ff;
                }
                uVar10 = ((int)((uint)*(ushort *)(iVar21 + 2) * (uint)*(ushort *)(iVar21 + 4) + 3)
                         >> 2) - 1;
                if (0x7ff < (int)uVar10) {
                  uVar10 = 0x7ff;
                }
                uVar25 = uVar9;
                if (uVar12 != 0) {
                  uVar25 = uVar9 / uVar12;
                  if (uVar12 == 0) {
                    trap(0x1c00);
                  }
                  if ((uVar12 == 0xffffffff) && (uVar9 == 0x80000000)) {
                    trap(0x1800);
                  }
                }
                uVar13 = (uVar14 & 7) << 0x18;
                puVar7[1] = (uVar10 & 0xfff) << 0xc | 0x7000000 | uVar25 & 0xfff;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe7000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar16 = DAT_800df8b0;
                uVar3 = *(ushort *)(iVar21 + 2);
                puVar7 = DAT_800df8b0 + 1;
                DAT_800df8b0 = DAT_800df8b0 + 2;
                *puVar7 = uVar13 | (uVar14 & 0xf) << 0x14 | uVar15 | (uVar20 & 0xf) << 0xe |
                          (8 - uVar20 & 0xf) << 10 | uVar11 | (uVar22 & 0xf) << 4 | 8 - uVar22 & 0xf
                ;
                uVar9 = uVar8 & 0x1ff | 0xf5400000;
                uVar12 = (uint)(uVar3 >> 1);
              }
              else if ((sVar2 == 2) || (sVar2 == 8)) {
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe3001001;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0x8000;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xfd100000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = iVar21 + 0x10;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe8000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xf5000100;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0x7000000;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe6000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xf0000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0x73fc000;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe7000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xfd500000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = iVar21 + 0x210;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = uVar8 & 0x1ff | 0xf5500000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = uVar15 | (uVar20 & 0xf) << 0xe | 0x7000000 | (8 - uVar20 & 0xf) << 10 |
                            uVar11 | (uVar22 & 0xf) << 4 | 8 - uVar22 & 0xf;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe6000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xf3000000;
                DAT_800df8b0 = puVar16;
                uVar12 = (uint)(*(ushort *)(iVar21 + 2) >> 3);
                uVar9 = 0x800;
                if (uVar12 != 0) {
                  uVar9 = uVar12 + 0x7ff;
                }
                uVar10 = ((int)((uint)*(ushort *)(iVar21 + 2) * (uint)*(ushort *)(iVar21 + 4) + 1)
                         >> 1) - 1;
                if (0x7ff < (int)uVar10) {
                  uVar10 = 0x7ff;
                }
                uVar25 = uVar9;
                if (uVar12 != 0) {
                  uVar25 = uVar9 / uVar12;
                  if (uVar12 == 0) {
                    trap(0x1c00);
                  }
                  if ((uVar12 == 0xffffffff) && (uVar9 == 0x80000000)) {
                    trap(0x1800);
                  }
                }
                puVar7[1] = (uVar10 & 0xfff) << 0xc | 0x7000000 | uVar25 & 0xfff;
                puVar7 = DAT_800df8b0;
                uVar13 = (uVar14 & 7) << 0x18;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe7000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar16 = DAT_800df8b0;
                uVar12 = (uint)*(ushort *)(iVar21 + 2);
                puVar7 = DAT_800df8b0 + 1;
                DAT_800df8b0 = DAT_800df8b0 + 2;
                *puVar7 = uVar13 | uVar15 | (uVar20 & 0xf) << 0xe | (8 - uVar20 & 0xf) << 10 |
                          uVar11 | (uVar22 & 0xf) << 4 | 8 - uVar22 & 0xf;
                uVar9 = uVar8 & 0x1ff | 0xf5480000;
              }
              else if (sVar2 == 6) {
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe3001001;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xfd700000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = iVar21 + 0x10;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = uVar8 & 0x1ff | 0xf5700000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = uVar15 | (uVar20 & 0xf) << 0xe | 0x7000000 | (8 - uVar20 & 0xf) << 10 |
                            uVar11 | (uVar22 & 0xf) << 4 | 8 - uVar22 & 0xf;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe6000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xf3000000;
                DAT_800df8b0 = puVar16;
                uVar12 = (uint)(*(ushort *)(iVar21 + 2) >> 4);
                uVar9 = 0x800;
                if (uVar12 != 0) {
                  uVar9 = uVar12 + 0x7ff;
                }
                uVar10 = ((int)((uint)*(ushort *)(iVar21 + 2) * (uint)*(ushort *)(iVar21 + 4) + 3)
                         >> 2) - 1;
                if (0x7ff < (int)uVar10) {
                  uVar10 = 0x7ff;
                }
                uVar25 = uVar9;
                if (uVar12 != 0) {
                  uVar25 = uVar9 / uVar12;
                  if (uVar12 == 0) {
                    trap(0x1c00);
                  }
                  if ((uVar12 == 0xffffffff) && (uVar9 == 0x80000000)) {
                    trap(0x1800);
                  }
                }
                puVar7[1] = (uVar10 & 0xfff) << 0xc | 0x7000000 | uVar25 & 0xfff;
                puVar7 = DAT_800df8b0;
                uVar13 = (uVar14 & 7) << 0x18;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe7000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar16 = DAT_800df8b0;
                uVar3 = *(ushort *)(iVar21 + 2);
                puVar7 = DAT_800df8b0 + 1;
                DAT_800df8b0 = DAT_800df8b0 + 2;
                *puVar7 = uVar13 | uVar15 | (uVar20 & 0xf) << 0xe | (8 - uVar20 & 0xf) << 10 |
                          uVar11 | (uVar22 & 0xf) << 4 | 8 - uVar22 & 0xf;
                uVar9 = uVar8 & 0x1ff | 0xf5600000;
                uVar12 = (uint)(uVar3 >> 1);
              }
              else if (sVar2 == 9) {
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe3001001;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xfd700000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = iVar21 + 0x10;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = uVar8 & 0x1ff | 0xf5700000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = uVar15 | (uVar20 & 0xf) << 0xe | 0x7000000 | (8 - uVar20 & 0xf) << 10 |
                            uVar11 | (uVar22 & 0xf) << 4 | 8 - uVar22 & 0xf;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe6000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xf3000000;
                DAT_800df8b0 = puVar16;
                uVar12 = (uint)(*(ushort *)(iVar21 + 2) >> 3);
                uVar9 = 0x800;
                if (uVar12 != 0) {
                  uVar9 = uVar12 + 0x7ff;
                }
                uVar10 = ((int)((uint)*(ushort *)(iVar21 + 2) * (uint)*(ushort *)(iVar21 + 4) + 1)
                         >> 1) - 1;
                if (0x7ff < (int)uVar10) {
                  uVar10 = 0x7ff;
                }
                uVar25 = uVar9;
                if (uVar12 != 0) {
                  uVar25 = uVar9 / uVar12;
                  if (uVar12 == 0) {
                    trap(0x1c00);
                  }
                  if ((uVar12 == 0xffffffff) && (uVar9 == 0x80000000)) {
                    trap(0x1800);
                  }
                }
                puVar7[1] = (uVar10 & 0xfff) << 0xc | 0x7000000 | uVar25 & 0xfff;
                puVar7 = DAT_800df8b0;
                uVar13 = (uVar14 & 7) << 0x18;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xe7000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar16 = DAT_800df8b0;
                uVar12 = (uint)*(ushort *)(iVar21 + 2);
                puVar7 = DAT_800df8b0 + 1;
                DAT_800df8b0 = DAT_800df8b0 + 2;
                *puVar7 = uVar13 | uVar15 | (uVar20 & 0xf) << 0xe | (8 - uVar20 & 0xf) << 10 |
                          uVar11 | (uVar22 & 0xf) << 4 | 8 - uVar22 & 0xf;
                uVar9 = uVar8 & 0x1ff | 0xf5680000;
              }
              else {
                if (sVar2 == 5) {
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = 0xe3001001;
                  DAT_800df8b0 = puVar16;
                  puVar7[1] = 0;
                  puVar7 = DAT_800df8b0;
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = 0xfd180000;
                  DAT_800df8b0 = puVar16;
                  puVar7[1] = iVar21 + 0x10;
                  puVar7 = DAT_800df8b0;
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = uVar8 & 0x1ff | 0xf5180000;
                  DAT_800df8b0 = puVar16;
                  puVar7[1] = uVar15 | (uVar20 & 0xf) << 0xe | 0x7000000 | (8 - uVar20 & 0xf) << 10
                              | uVar11 | (uVar22 & 0xf) << 4 | 8 - uVar22 & 0xf;
                  puVar7 = DAT_800df8b0;
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = 0xe6000000;
                  DAT_800df8b0 = puVar16;
                  puVar7[1] = 0;
                  puVar7 = DAT_800df8b0;
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = 0xf3000000;
                  DAT_800df8b0 = puVar16;
                  uVar12 = (uint)(*(ushort *)(iVar21 + 2) >> 1);
                  uVar9 = 0x800;
                  if (uVar12 != 0) {
                    uVar9 = uVar12 + 0x7ff;
                  }
                  uVar10 = (uint)*(ushort *)(iVar21 + 2) * (uint)*(ushort *)(iVar21 + 4) - 1;
                  if (0x7ff < (int)uVar10) {
                    uVar10 = 0x7ff;
                  }
                  uVar25 = uVar9;
                  if (uVar12 != 0) {
                    uVar25 = uVar9 / uVar12;
                    if (uVar12 == 0) {
                      trap(0x1c00);
                    }
                    if ((uVar12 == 0xffffffff) && (uVar9 == 0x80000000)) {
                      trap(0x1800);
                    }
                  }
                  puVar7[1] = (uVar10 & 0xfff) << 0xc | 0x7000000 | uVar25 & 0xfff;
                  puVar7 = DAT_800df8b0;
                  uVar13 = (uVar14 & 7) << 0x18;
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = 0xe7000000;
                  DAT_800df8b0 = puVar16;
                  puVar7[1] = 0;
                  puVar16 = DAT_800df8b0;
                  uVar3 = *(ushort *)(iVar21 + 2);
                  puVar7 = DAT_800df8b0 + 1;
                  DAT_800df8b0 = DAT_800df8b0 + 2;
                  *puVar7 = uVar13 | uVar15 | (uVar20 & 0xf) << 0xe | (8 - uVar20 & 0xf) << 10 |
                            uVar11 | (uVar22 & 0xf) << 4 | 8 - uVar22 & 0xf;
                  uVar9 = 0xf5180000;
                }
                else {
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = 0xe3001001;
                  DAT_800df8b0 = puVar16;
                  puVar7[1] = 0;
                  puVar7 = DAT_800df8b0;
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = 0xfd100000;
                  DAT_800df8b0 = puVar16;
                  puVar7[1] = iVar21 + 0x10;
                  puVar7 = DAT_800df8b0;
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = uVar8 & 0x1ff | 0xf5100000;
                  DAT_800df8b0 = puVar16;
                  puVar7[1] = uVar15 | (uVar20 & 0xf) << 0xe | 0x7000000 | (8 - uVar20 & 0xf) << 10
                              | uVar11 | (uVar22 & 0xf) << 4 | 8 - uVar22 & 0xf;
                  puVar7 = DAT_800df8b0;
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = 0xe6000000;
                  DAT_800df8b0 = puVar16;
                  puVar7[1] = 0;
                  puVar7 = DAT_800df8b0;
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = 0xf3000000;
                  DAT_800df8b0 = puVar16;
                  iVar18 = (int)(uint)*(ushort *)(iVar21 + 2) >> 2;
                  uVar9 = 0x800;
                  if (iVar18 != 0) {
                    uVar9 = iVar18 + 0x7ff;
                  }
                  uVar12 = (uint)*(ushort *)(iVar21 + 2) * (uint)*(ushort *)(iVar21 + 4) - 1;
                  if (0x7ff < (int)uVar12) {
                    uVar12 = 0x7ff;
                  }
                  uVar25 = (int)(uint)*(ushort *)(iVar21 + 2) >> 2;
                  uVar10 = uVar9;
                  if (uVar25 != 0) {
                    uVar10 = uVar9 / uVar25;
                    if (uVar25 == 0) {
                      trap(0x1c00);
                    }
                    if ((uVar25 == 0xffffffff) && (uVar9 == 0x80000000)) {
                      trap(0x1800);
                    }
                  }
                  puVar7[1] = (uVar12 & 0xfff) << 0xc | 0x7000000 | uVar10 & 0xfff;
                  puVar7 = DAT_800df8b0;
                  uVar13 = (uVar14 & 7) << 0x18;
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = 0xe7000000;
                  DAT_800df8b0 = puVar16;
                  puVar7[1] = 0;
                  puVar16 = DAT_800df8b0;
                  uVar3 = *(ushort *)(iVar21 + 2);
                  puVar7 = DAT_800df8b0 + 1;
                  DAT_800df8b0 = DAT_800df8b0 + 2;
                  *puVar7 = uVar13 | uVar15 | (uVar20 & 0xf) << 0xe | (8 - uVar20 & 0xf) << 10 |
                            uVar11 | (uVar22 & 0xf) << 4 | 8 - uVar22 & 0xf;
                  uVar9 = 0xf5100000;
                }
                uVar9 = uVar8 & 0x1ff | uVar9;
                uVar12 = (uint)uVar3 << 1;
              }
              *puVar16 = ((int)(uVar12 + 7) >> 3 & 0x1ffU) << 9 | uVar9;
              puVar7 = DAT_800df8b0;
              puVar16 = DAT_800df8b0 + 2;
              *DAT_800df8b0 = 0xf2000000;
              DAT_800df8b0 = puVar16;
              puVar7[1] = uVar13 | ((*(ushort *)(iVar21 + 2) - 1) * 4 & 0xfff) << 0xc |
                          (*(ushort *)(iVar21 + 4) - 1) * 4 & 0xfff;
              uVar14 = uVar14 + 1;
            }
          }
          if (iVar24 == 2) {
            puVar16 = DAT_800df8b0 + 2;
            *DAT_800df8b0 = 0xe3000a01;
            DAT_800df8b0 = puVar16;
            puVar7[1] = 0x100000;
            puVar7 = DAT_800df8b0;
            puVar16 = DAT_800df8b0 + 2;
            *DAT_800df8b0 = 0xfc177e04;
            DAT_800df8b0 = puVar16;
            puVar7[1] = 0x2ffd7ff9;
            puVar16 = DAT_800df8b0;
            puVar7 = DAT_800df8b0 + 1;
            DAT_800df8b0 = DAT_800df8b0 + 2;
            *puVar7 = 0xc192230;
            *puVar16 = 0xe200001c;
            puVar7 = DAT_800df8b0;
            puVar16 = DAT_800df8b0 + 2;
            *DAT_800df8b0 = 0xd7000802;
            DAT_800df8b0 = puVar16;
            puVar7[1] = 0x80008000;
          }
          for (; puVar7 = DAT_800df8b0, piVar23 != (int *)0x0; piVar23 = (int *)piVar23[1]) {
            uVar14 = piVar23[5] & 1;
            if (local_58 != uVar14) {
              puVar16 = DAT_800df8b0 + 2;
              *DAT_800df8b0 = 0xda380007;
              DAT_800df8b0 = puVar16;
              puVar7[1] = (uint)&DAT_80131600;
              puVar7 = DAT_800df8b0;
              local_58 = uVar14;
              if (uVar14 == 0) {
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xd9fffdff;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar16 = DAT_800df8b0;
                puVar7 = DAT_800df8b0 + 1;
                DAT_800df8b0 = DAT_800df8b0 + 2;
                *puVar7 = 0x400;
                *puVar16 = 0xd9ffffff;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xda380005;
                DAT_800df8b0 = puVar16;
                puVar7[1] = (uint)&DAT_80131590;
              }
              else {
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xd9fffbff;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar16 = DAT_800df8b0;
                puVar7 = DAT_800df8b0 + 1;
                DAT_800df8b0 = DAT_800df8b0 + 2;
                *puVar7 = 0x200;
                *puVar16 = 0xd9ffffff;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xda380005;
                DAT_800df8b0 = puVar16;
                puVar7[1] = (uint)&DAT_80131738;
              }
            }
            puVar7 = DAT_800df8b0;
            if ((piVar23[5] & 0x10U) == 0) {
              if (iVar24 == 2) {
                uVar14 = (uint)(byte)DAT_80124838;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = uVar14 | 0xfa000000;
                DAT_800df8b0 = puVar16;
                puVar7[1] = uVar14 << 0x18 | uVar14 << 0x10 | uVar14 << 8 | uVar14;
              }
              else {
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xfa0000ff;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0xffffffff;
              }
            }
            else {
              puVar16 = DAT_800df8b0 + 2;
              *DAT_800df8b0 = 0xfa0000ff;
              DAT_800df8b0 = puVar16;
              puVar7[1] = *(uint *)(piVar23[3] + 100);
            }
            puVar7 = DAT_800df8b0;
            bVar4 = (piVar23[5] & 0x16U) == 0;
            if (bVar5 != bVar4) {
              bVar5 = bVar4;
              if (bVar4) {
                puVar16 = DAT_800df8b0 + 1;
                DAT_800df8b0 = DAT_800df8b0 + 2;
                *puVar16 = 0x20000;
                *puVar7 = 0xd9ffffff;
                puVar7 = DAT_800df8b0;
                if (DAT_80131778 == 0) {
                  puVar16 = DAT_800df8b0 + 1;
                  DAT_800df8b0 = DAT_800df8b0 + 2;
                  *puVar16 = 0xfffff3f9;
                  *puVar7 = 0xfc127e24;
                }
                else {
                  puVar16 = DAT_800df8b0 + 2;
                  *DAT_800df8b0 = 0xfc6278c4;
                  DAT_800df8b0 = puVar16;
                  puVar7[1] = 0xfff3ffff;
                }
              }
              else {
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xd9fdffff;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0;
                puVar7 = DAT_800df8b0;
                puVar16 = DAT_800df8b0 + 2;
                *DAT_800df8b0 = 0xfc11fe23;
                DAT_800df8b0 = puVar16;
                puVar7[1] = 0xfffff3f9;
              }
            }
            puVar7 = DAT_800df8b0;
            puVar16 = DAT_800df8b0 + 2;
            *DAT_800df8b0 = 0xe7000000;
            DAT_800df8b0 = puVar16;
            puVar7[1] = 0;
            puVar7 = DAT_800df8b0;
            uVar14 = piVar23[2];
            if ((uVar14 != 0) && (iVar21 = 1, local_5c != uVar14)) {
              uVar15 = uVar14 + 8;
              uVar11 = 6;
              iVar18 = *(int *)(uVar14 + 0x38);
              puVar16 = DAT_800df8b0 + 2;
              *DAT_800df8b0 = 0xdb020000;
              DAT_800df8b0 = puVar16;
              puVar7[1] = iVar18 * 0x18;
              for (; puVar7 = DAT_800df8b0, uVar8 = uVar11 & 0xff, iVar21 <= iVar18;
                  iVar21 = iVar21 + 1) {
                uVar11 = uVar11 + 3;
                puVar16 = DAT_800df8b0 + 1;
                DAT_800df8b0 = DAT_800df8b0 + 2;
                *puVar16 = uVar15;
                uVar15 = uVar15 + 0x10;
                *puVar7 = uVar8 << 8 | 0xdc08000a;
              }
              puVar16 = DAT_800df8b0 + 2;
              *DAT_800df8b0 = ((iVar18 + 1) * 3 + 3U & 0xff) << 8 | 0xdc08000a;
              DAT_800df8b0 = puVar16;
              puVar7[1] = uVar14;
              puVar7 = DAT_800df8b0;
              puVar16 = DAT_800df8b0 + 2;
              *DAT_800df8b0 = 0xdb020000;
              DAT_800df8b0 = puVar16;
              puVar7[1] = iVar18 * 0x18;
              local_5c = piVar23[2];
            }
            puVar7 = DAT_800df8b0;
            puVar16 = DAT_800df8b0 + 2;
            *DAT_800df8b0 = 0xda380000;
            DAT_800df8b0 = puVar16;
            puVar7[1] = piVar23[3] + 0x68;
            puVar7 = DAT_800df8b0;
            if (piVar23[4] == 0) {
              puVar16 = DAT_800df8b0 + 2;
              *DAT_800df8b0 = 0xdb060008;
              DAT_800df8b0 = puVar16;
              puVar7[1] = *(uint *)*piVar23;
            }
            else {
              puVar16 = DAT_800df8b0 + 2;
              *DAT_800df8b0 = 0xdb060008;
              DAT_800df8b0 = puVar16;
              puVar7[1] = piVar23[4];
            }
            puVar7 = DAT_800df8b0;
            puVar16 = DAT_800df8b0 + 2;
            *DAT_800df8b0 = 0xde000000;
            DAT_800df8b0 = puVar16;
            puVar7[1] = *(uint *)(*piVar23 + 4);
            puVar7 = DAT_800df8b0;
            puVar16 = DAT_800df8b0 + 2;
            *DAT_800df8b0 = 0xd8380002;
            DAT_800df8b0 = puVar16;
            puVar7[1] = 0x40;
          }
          if (iVar24 == 2) {
            puVar16 = DAT_800df8b0 + 2;
            *DAT_800df8b0 = 0xe7000000;
            DAT_800df8b0 = puVar16;
            puVar7[1] = 0;
            puVar7 = DAT_800df8b0;
            puVar16 = DAT_800df8b0 + 2;
            *DAT_800df8b0 = 0xe3000a01;
            DAT_800df8b0 = puVar16;
            puVar7[1] = 0;
            puVar7 = DAT_800df8b0;
            if (DAT_80131778 == 0) {
              puVar16 = DAT_800df8b0 + 2;
              *DAT_800df8b0 = 0xfc127e24;
              DAT_800df8b0 = puVar16;
              puVar7[1] = 0xfffff3f9;
            }
            else {
              puVar16 = DAT_800df8b0 + 2;
              *DAT_800df8b0 = 0xfc6278c4;
              DAT_800df8b0 = puVar16;
              puVar7[1] = 0xfff3ffff;
            }
            puVar7 = DAT_800df8b0;
            puVar16 = DAT_800df8b0 + 2;
            *DAT_800df8b0 = 0xd7000002;
            DAT_800df8b0 = puVar16;
            puVar7[1] = 0x80008000;
          }
        }
      }
      local_2c = local_2c + 4;
      local_38 = local_38 << 1;
    }
  }
  return;
}
