/* FUN_8017df6c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017df6c  body 0x8017df6c..0x8017ebb7  size 3148 B
 * body sha256 433e5f5361ebb0c71e7b4be8d7ddf5d066cc69b63f1ead5c41c5c46b4ec76d81
 * provider record sha256 9d6038eaf4163ba0529ce3d1a2845e398e1578b80e49c840a9bda35f897af115
 * callees 20 direct (20 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8017e6c4) */
/* WARNING: Removing unreachable block (ram,0x8017e2d0) */
/* WARNING: Removing unreachable block (ram,0x8017e0bc) */
/* WARNING: Removing unreachable block (ram,0x8017e0e8) */
/* WARNING: Removing unreachable block (ram,0x8017e104) */
/* WARNING: Removing unreachable block (ram,0x8017e02c) */
/* WARNING: Removing unreachable block (ram,0x8017e038) */
/* WARNING: Removing unreachable block (ram,0x8017dfe4) */
/* WARNING: Removing unreachable block (ram,0x8017dff4) */
/* WARNING: Removing unreachable block (ram,0x8017e1a8) */
/* WARNING: Removing unreachable block (ram,0x8017e1b4) */
/* WARNING: Removing unreachable block (ram,0x8017e204) */
/* WARNING: Removing unreachable block (ram,0x8017e214) */
/* WARNING: Removing unreachable block (ram,0x8017e20c) */
/* WARNING: Removing unreachable block (ram,0x8017e474) */
/* WARNING: Removing unreachable block (ram,0x8017e480) */
/* WARNING: Removing unreachable block (ram,0x8017e528) */
/* WARNING: Removing unreachable block (ram,0x8017e794) */
/* WARNING: Removing unreachable block (ram,0x8017e7ac) */
/* WARNING: Removing unreachable block (ram,0x8017e7c0) */
/* WARNING: Removing unreachable block (ram,0x8017e844) */
/* WARNING: Removing unreachable block (ram,0x8017e858) */
/* WARNING: Removing unreachable block (ram,0x8017e7d0) */
/* WARNING: Removing unreachable block (ram,0x8017e7f4) */
/* WARNING: Removing unreachable block (ram,0x8017e864) */
/* WARNING: Removing unreachable block (ram,0x8017e874) */
/* WARNING: Removing unreachable block (ram,0x8017e9c4) */
/* WARNING: Removing unreachable block (ram,0x8017e9d0) */
/* WARNING: Removing unreachable block (ram,0x8017e9d4) */
/* WARNING: Removing unreachable block (ram,0x8017e880) */
/* WARNING: Removing unreachable block (ram,0x8017e8bc) */
/* WARNING: Removing unreachable block (ram,0x8017e8c8) */
/* WARNING: Removing unreachable block (ram,0x8017e8d0) */
/* WARNING: Removing unreachable block (ram,0x8017e900) */
/* WARNING: Removing unreachable block (ram,0x8017e8e8) */
/* WARNING: Removing unreachable block (ram,0x8017e908) */
/* WARNING: Removing unreachable block (ram,0x8017e918) */
/* WARNING: Removing unreachable block (ram,0x8017e934) */
/* WARNING: Removing unreachable block (ram,0x8017e948) */
/* WARNING: Removing unreachable block (ram,0x8017e954) */
/* WARNING: Removing unreachable block (ram,0x8017e910) */
/* WARNING: Removing unreachable block (ram,0x8017e964) */
/* WARNING: Removing unreachable block (ram,0x8017e968) */
/* WARNING: Removing unreachable block (ram,0x8017e974) */
/* WARNING: Removing unreachable block (ram,0x8017e99c) */
/* WARNING: Removing unreachable block (ram,0x8017e9a8) */
/* WARNING: Removing unreachable block (ram,0x8017e9bc) */
/* WARNING: Removing unreachable block (ram,0x8017e9f0) */
/* WARNING: Removing unreachable block (ram,0x8017ea78) */
/* WARNING: Removing unreachable block (ram,0x8017eac0) */
/* WARNING: Removing unreachable block (ram,0x8017ead4) */
/* WARNING: Removing unreachable block (ram,0x8017eae0) */
/* WARNING: Removing unreachable block (ram,0x8017eb54) */
/* WARNING: Removing unreachable block (ram,0x8017eb6c) */

void FUN_8017df6c(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  uint local_88;
  uint local_84;
  undefined1 auStack_78 [8];
  uint local_70;
  int local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50 [4];
  int local_40;
  int local_3c;
  int local_38;
  
  local_3c = DAT_8018574c * DAT_80185750;
  if (DAT_801857a0 != 3) {
    local_3c = local_3c >> 1;
  }
  local_40 = 0;
  local_38 = 0;
  DAT_80185780 = 0;
  do {
    DAT_80186c94 = &DAT_80185824;
    if (local_38 != 0) goto LAB_8017e1d8;
    DAT_80186c94 = &DAT_80185824;
    iVar1 = FUN_8017bbb0(0x17);
    if ((iVar1 != 0) && (DAT_80185780 == 0)) {
      if (local_3c <= local_40) {
        return;
      }
      local_38 = FUN_8017f870();
      if (DAT_80185780 == 0) goto LAB_8017e1d8;
    }
LAB_8017e060:
    do {
      DAT_80185780 = 0;
      DAT_80186c94 = &DAT_80185824;
      if (local_3c <= local_40) {
        DAT_80185780 = 0;
        return;
      }
      FUN_8017d214();
      uVar2 = FUN_8017bbb0(0x20);
      if (0xae < uVar2 - 0x101) {
        return;
      }
      FUN_8017bd8c();
      iVar1 = FUN_8017d524();
      local_38 = FUN_8017f870();
    } while (DAT_80185780 != 0);
    local_b0 = 0;
    local_b4 = 0;
    local_b8 = 0;
    local_94 = 0;
    local_98 = 0;
    local_a4 = 0;
    local_a8 = 0;
    local_8c = 0;
    local_90 = 0;
    local_9c = 0;
    local_a0 = 0;
    local_40 = (iVar1 * 0x80 + (uVar2 & 0xff) + -1) * DAT_8018574c + local_38 + -1;
    local_38 = 1;
LAB_8017e1d8:
    if (local_3c <= local_40) {
      return;
    }
    if (local_38 == 1) {
      FUN_8017ebb8(&local_70,&local_6c,&local_68,&local_64,&local_60,&local_5c,&local_58,&local_54,
                   local_50);
      if (DAT_80185780 == 0) {
        if ((local_70 & 0x10) != 0) {
          iVar1 = FUN_8017bec8(5);
          if (*(int *)(DAT_80186c94 + 0x41c) == 0) {
            *(int *)(DAT_80186c94 + 0x434) = iVar1;
          }
          else if (*(int *)(DAT_80186c94 + 0x424) == 0) {
            *(int *)(DAT_80186c94 + 0x434) = iVar1 << 1;
          }
          else {
            *(uint *)(DAT_80186c94 + 0x434) = (uint)(byte)(&DAT_80185560)[iVar1];
          }
        }
        if (((local_70 & 8) != 0) || (((local_70 & 1) != 0 && (DAT_801857ac != 0)))) {
          if (*(int *)(DAT_80186c94 + 0x41c) == 0) {
            FUN_801802a8(&local_a8,auStack_78,DAT_80185770,DAT_80185770,0,0,DAT_80185778);
          }
          else {
            FUN_80180150(&local_a8,auStack_78,&local_88,0,local_60,local_5c,DAT_8018578c,
                         DAT_80185790,local_58,local_54);
          }
        }
        if (DAT_80185780 == 0) {
          if ((local_70 & 4) != 0) {
            if (*(int *)(DAT_80186c94 + 0x41c) == 0) {
              FUN_801802a8(&local_a0,auStack_78,DAT_80185774,DAT_80185774,0,0,DAT_8018577c);
            }
            else {
              FUN_80180150(&local_a8,auStack_78,&local_88,1,local_60,local_5c,DAT_80185794,
                           DAT_80185798,0,local_54);
            }
          }
          if (DAT_80185780 == 0) {
            if (((local_70 & 1) != 0) && (DAT_801857ac != 0)) {
              FUN_8017bbe8(1);
            }
            if ((local_70 & 2) == 0) {
              if ((local_70 & 1) == 0) {
                uVar2 = 0;
              }
              else {
                uVar2 = (1 << (DAT_80185768 & 0x1f)) - 1;
              }
            }
            else {
              uVar2 = FUN_8017f7dc();
              if (DAT_8018575c == 2) {
                uVar3 = FUN_8017bec8(2);
                uVar2 = uVar2 << 2 | uVar3;
              }
              else if (DAT_8018575c == 3) {
                uVar3 = FUN_8017bec8(6);
                uVar2 = uVar2 << 6 | uVar3;
              }
            }
            if (DAT_80185780 == 0) {
              iVar1 = 0;
              if (0 < (int)DAT_80185768) {
                do {
                  FUN_8017ede4(iVar1);
                  if (((int)uVar2 >> (DAT_80185768 - (iVar1 + 1) & 0x1f) & 1U) != 0) {
                    if ((local_70 & 1) == 0) {
                      if (*(int *)(DAT_80186c94 + 0x41c) == 0) {
                        FUN_8017c38c(iVar1);
                      }
                      else {
                        FUN_8017cc94(iVar1);
                      }
                    }
                    else if (*(int *)(DAT_80186c94 + 0x41c) == 0) {
                      FUN_8017bf30(iVar1,&local_b8);
                    }
                    else {
                      FUN_8017c788(iVar1,&local_b8);
                    }
                    if (DAT_80185780 != 0) goto LAB_8017e060;
                  }
                  iVar1 = iVar1 + 1;
                  if ((int)DAT_80185768 <= iVar1) break;
                } while( true );
              }
              if ((local_70 & 1) == 0) {
                local_b0 = 0;
                local_b4 = 0;
                local_b8 = 0;
              }
              else if (DAT_801857ac == 0) {
                local_94 = 0;
                local_98 = 0;
                local_a4 = 0;
                local_a8 = 0;
                local_8c = 0;
                local_90 = 0;
                local_9c = 0;
                local_a0 = 0;
              }
              if ((DAT_8018576c == 2) && ((local_70 & 9) == 0)) {
                local_94 = 0;
                local_98 = 0;
                local_a4 = 0;
                local_a8 = 0;
                if (DAT_801857a0 == 3) {
                  local_64 = 2;
                }
                else {
                  local_88 = (uint)(DAT_801857a0 == 2);
                  local_64 = 1;
                }
              }
              if (local_68 == 4) {
                local_94 = 0;
                local_98 = 0;
                local_a4 = 0;
                local_a8 = 0;
                local_8c = 0;
                local_90 = 0;
                local_9c = 0;
                local_a0 = 0;
              }
              goto LAB_8017e788;
            }
          }
        }
      }
      goto LAB_8017e060;
    }
    iVar1 = 0;
    if (0 < (int)DAT_80185768) {
      do {
        FUN_8017ede4(iVar1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)DAT_80185768);
    }
    local_b0 = 0;
    local_b4 = 0;
    local_b8 = 0;
    if (DAT_8018576c == 2) {
      local_94 = 0;
      local_98 = 0;
      local_a4 = 0;
      local_a8 = 0;
    }
    if (DAT_801857a0 == 3) {
      local_64 = 2;
    }
    else {
      local_88 = (uint)(DAT_801857a0 == 2);
      local_64 = 1;
      local_84 = local_88;
    }
    uVar2 = 0;
    local_6c = (uint)(DAT_8018576c == 1) << 3;
    local_70 = local_70 & 0xfffffffe;
LAB_8017e788:
    if (DAT_8018574c == 0) {
      trap(0x1c00);
    }
    if ((DAT_8018574c == -1) && (local_40 == -0x80000000)) {
      trap(0x1800);
    }
    iVar6 = local_40 % DAT_8018574c << 4;
    iVar1 = local_40 / DAT_8018574c << 4;
    if ((local_70 & 1) == 0) {
      FUN_801818a0(iVar6,iVar1,local_70,local_64,&local_a8,&local_88,auStack_78,local_6c);
    }
    iVar4 = 0;
    if (0 < (int)DAT_80185768) {
      iVar5 = 0x438;
      do {
        if (((int)uVar2 >> (DAT_80185768 - (iVar4 + 1) & 0x1f) & 1U) != 0) {
          FUN_8017ff78(DAT_80186c94 + iVar5);
          FUN_8017eed4(iVar4,iVar6,iVar1,local_50[0],(local_70 ^ 1) & 1);
        }
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0x80;
      } while (iVar4 < (int)DAT_80185768);
    }
    local_40 = local_40 + 1;
    local_38 = local_38 + -1;
  } while( true );
}
