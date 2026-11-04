/* FUN_800038f0
 * image   boot (boot), base 0x80000480
 * address 0x800038f0  body 0x800038f0..0x80003ed7  size 1512 B
 * body sha256 d0b7f1d124cdd6565920ed17e7c30e3d8c18c1a6e8205a1b9b419764759ac4cb
 * provider record sha256 cef083a1c5c7c3addd9bc67f5604d6465fe63043002f03caf1335bd7b29c486e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4
FUN_800038f0(int *param_1,uint param_2,uint param_3,int param_4,int param_5,uint *param_6,
            uint *param_7,int param_8)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  char cVar10;
  uint *puVar9;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  int iVar19;
  uint local_5b8 [16];
  undefined4 local_578;
  uint local_574;
  undefined4 local_570 [16];
  uint local_530 [288];
  uint local_b0 [16];
  uint *local_70;
  uint local_68;
  int local_64;
  uint local_60;
  int local_5c;
  int local_58;
  uint local_54;
  uint *local_48;
  int local_3c;
  uint *local_38;
  int local_34;
  undefined4 *local_30;
  
  local_5b8[0] = 0;
  local_5b8[1] = 0;
  local_5b8[2] = 0;
  local_5b8[3] = 0;
  local_5b8[4] = 0;
  local_5b8[5] = 0;
  local_5b8[6] = 0;
  local_5b8[7] = 0;
  local_5b8[8] = 0;
  local_5b8[9] = 0;
  local_5b8[10] = 0;
  local_5b8[0xb] = 0;
  local_5b8[0xc] = 0;
  local_5b8[0xd] = 0;
  local_5b8[0xe] = 0;
  local_5b8[0xf] = 0;
  uVar15 = param_2;
  piVar18 = param_1;
  do {
    iVar5 = *piVar18;
    piVar18 = piVar18 + 1;
    uVar15 = uVar15 - 1;
    local_5b8[iVar5] = local_5b8[iVar5] + 1;
  } while (uVar15 != 0);
  uVar15 = 1;
  if (local_5b8[0] == param_2) {
    uVar1 = 0;
    *param_6 = 0;
    *param_7 = 0;
  }
  else {
    puVar6 = local_5b8;
    do {
      puVar6 = puVar6 + 1;
      if (*puVar6 != 0) break;
      uVar15 = uVar15 + 1;
    } while (uVar15 < 0x10);
    uVar7 = *param_7;
    if (*param_7 < uVar15) {
      uVar7 = uVar15;
    }
    uVar16 = 0xf;
    puVar6 = local_5b8 + 0xf;
    do {
      if (*puVar6 != 0) break;
      uVar16 = uVar16 - 1;
      puVar6 = puVar6 + -1;
    } while (uVar16 != 0);
    if (uVar16 < uVar7) {
      uVar7 = uVar16;
    }
    iVar5 = 1 << (uVar15 & 0x1f);
    *param_7 = uVar7;
    if (uVar15 < uVar16) {
      puVar6 = local_5b8 + uVar15;
      uVar13 = uVar15;
      do {
        uVar2 = *puVar6;
        puVar6 = puVar6 + 1;
        if ((int)(iVar5 - uVar2) < 0) goto LAB_80003a80;
        uVar13 = uVar13 + 1;
        iVar5 = (iVar5 - uVar2) * 2;
      } while (uVar13 < uVar16);
    }
    uVar2 = local_5b8[uVar16];
    iVar5 = iVar5 - uVar2;
    uVar13 = 0;
    if (iVar5 < 0) {
LAB_80003a80:
      uVar1 = 0xfffffffd;
    }
    else {
      puVar6 = local_5b8;
      puVar9 = local_b0 + 2;
      local_5b8[uVar16] = uVar2 + iVar5;
      local_b0[1] = 0;
      uVar2 = uVar16;
      while( true ) {
        puVar6 = puVar6 + 1;
        uVar2 = uVar2 - 1;
        if (uVar2 == 0) break;
        uVar13 = uVar13 + *puVar6;
        *puVar9 = uVar13;
        puVar9 = puVar9 + 1;
      }
      uVar13 = 0;
      do {
        iVar14 = *param_1;
        param_1 = param_1 + 1;
        if (iVar14 != 0) {
          uVar2 = local_b0[iVar14];
          local_530[uVar2] = uVar13;
          local_b0[iVar14] = uVar2 + 1;
        }
        uVar13 = uVar13 + 1;
        iVar14 = -1;
      } while (uVar13 < param_2);
      uVar2 = 0;
      puVar6 = local_530;
      uVar13 = -uVar7;
      uVar11 = 0;
      uVar17 = 0;
      local_b0[0] = 0;
      local_570[0] = 0;
      local_5c = iVar5;
      local_54 = uVar16;
      if ((int)uVar15 <= (int)uVar16) {
        local_58 = 1;
        local_30 = local_570;
        local_34 = uVar15 * 4;
        local_70 = local_5b8;
        local_38 = local_5b8 + uVar15;
        local_68 = uVar7;
        local_60 = uVar15;
        do {
          local_64 = *local_38 - 1;
          if (local_64 != -1) {
            iVar5 = iVar14 << 2;
            local_3c = local_34;
            uVar15 = uVar13 + local_68;
            do {
              iVar3 = iVar14 * 4;
              if ((int)uVar15 < (int)local_60) {
                puVar9 = local_30 + iVar14;
                uVar13 = uVar15;
                iVar19 = iVar5;
                do {
                  puVar9 = puVar9 + 1;
                  iVar5 = iVar19 + 4;
                  iVar14 = iVar14 + 1;
                  uVar15 = local_54 - uVar13;
                  if (local_68 < local_54 - uVar13) {
                    uVar15 = local_68;
                  }
                  uVar16 = local_60 - uVar13;
                  uVar7 = local_58 << (uVar16 & 0x1f);
                  if (local_64 + 1U < uVar7) {
                    iVar8 = (uVar7 - 1) - local_64;
                    puVar12 = (uint *)((int)local_70 + local_3c);
                    if (uVar16 < uVar15) {
                      do {
                        uVar16 = uVar16 + 1;
                        puVar12 = puVar12 + 1;
                        if (uVar15 <= uVar16) break;
                        uVar7 = iVar8 * 2;
                        iVar8 = uVar7 - *puVar12;
                      } while (*puVar12 < uVar7);
                    }
                  }
                  uVar17 = local_58 << (uVar16 & 0x1f);
                  local_48 = param_6;
                  iVar8 = (**(code **)(param_8 + 0x20))
                                    (*(undefined4 *)(param_8 + 0x28),uVar17 + 1,8);
                  uVar11 = iVar8 + 8;
                  if (iVar8 == 0) {
                    if (iVar14 == 0) {
                      return 0xfffffffc;
                    }
                    FUN_800042f4(local_570[0],param_8);
                    return 0xfffffffc;
                  }
                  *local_48 = uVar11;
                  param_6 = (uint *)(iVar8 + 4);
                  *(undefined4 *)(iVar8 + 4) = 0;
                  *puVar9 = uVar11;
                  if (iVar14 != 0) {
                    *(uint *)((int)local_b0 + iVar19 + 4) = uVar2;
                    local_578._1_3_ = CONCAT12((char)local_68,local_578._2_2_);
                    local_578 = CONCAT13((char)uVar16,local_578._1_3_);
                    local_574 = uVar11;
                    puVar4 = (undefined4 *)
                             ((uVar2 >> (uVar13 - local_68 & 0x1f)) * 8 +
                             *(int *)((int)local_30 + iVar3));
                    *puVar4 = local_578;
                    puVar4[1] = uVar11;
                  }
                  if ((int)local_60 <= (int)(uVar13 + local_68)) break;
                  iVar3 = iVar3 + 4;
                  uVar13 = uVar13 + local_68;
                  iVar19 = iVar5;
                } while( true );
              }
              local_578._1_3_ = CONCAT12((char)local_60 - (char)uVar13,local_578._2_2_);
              if (puVar6 < local_530 + param_2) {
                uVar15 = *puVar6;
                if (uVar15 < param_3) {
                  cVar10 = '\0';
                  if (0xff < uVar15) {
                    cVar10 = '`';
                  }
                  local_574 = *puVar6;
                }
                else {
                  cVar10 = *(char *)((uVar15 - param_3) * 4 + param_5 + 3) + 'P';
                  local_574 = *(uint *)((*puVar6 - param_3) * 4 + param_4);
                }
                local_578 = CONCAT13(cVar10,local_578._1_3_);
                puVar6 = puVar6 + 1;
              }
              else {
                local_578 = CONCAT13(0xc0,local_578._1_3_);
              }
              iVar3 = local_58 << (local_60 - uVar13 & 0x1f);
              uVar15 = uVar2 >> (uVar13 & 0x1f);
              if (uVar15 < uVar17) {
                puVar4 = (undefined4 *)(uVar15 * 8 + uVar11);
                do {
                  *puVar4 = local_578;
                  puVar4[1] = local_574;
                  puVar4 = puVar4 + iVar3 * 2;
                  uVar15 = uVar15 + iVar3;
                } while (uVar15 < uVar17);
              }
              uVar15 = local_58 << (local_60 - 1 & 0x1f);
              uVar7 = uVar2 & uVar15;
              uVar2 = uVar2 ^ uVar15;
              while (uVar7 != 0) {
                uVar15 = uVar15 >> 1;
                uVar7 = uVar2 & uVar15;
                uVar2 = uVar2 ^ uVar15;
              }
              if ((uVar2 & (local_58 << (uVar13 & 0x1f)) - 1U) != *(uint *)((int)local_b0 + iVar5))
              {
                puVar9 = local_b0 + iVar14;
                do {
                  puVar9 = puVar9 + -1;
                  iVar5 = iVar5 + -4;
                  uVar13 = uVar13 - local_68;
                  iVar14 = iVar14 + -1;
                } while ((uVar2 & (1 << (uVar13 & 0x1f)) - 1U) != *puVar9);
              }
              local_64 = local_64 + -1;
              uVar15 = uVar13 + local_68;
            } while (local_64 != -1);
          }
          local_60 = local_60 + 1;
          local_34 = local_34 + 4;
          local_38 = local_38 + 1;
        } while ((int)local_60 <= (int)local_54);
      }
      uVar1 = 0;
      if ((local_5c != 0) && (local_54 != 1)) {
        uVar1 = 0xfffffffb;
      }
    }
  }
  return uVar1;
}
