/* FUN_8009feb8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009feb8  body 0x8009feb8..0x800a02f7  size 1088 B
 * body sha256 52199f5064e0dcb773194690af63c1f468adeb31d0365f2c60b578209c9004e8
 * provider record sha256 297f448f26280747be744269403afb5c7b62fd8045a7d16b4c30a9667e916205
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800a00c0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8009feb8(void)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  int local_38;
  undefined1 local_29;
  
  iVar15 = 0;
  local_29 = 0;
  local_38 = 0;
  do {
    if (*(int *)(_DAT_80143c58 + iVar15 + 0x574) != 0) {
      local_29 = 1;
      do {
        iVar12 = _DAT_80143c58 + iVar15;
        uVar14 = (uint)**(ushort **)(iVar12 + 0x574) + *(int *)(iVar12 + 0x570);
        if ((uint)(*(int *)(iVar12 + 0x56c) + *(int *)(_DAT_80143c58 + 0x120)) < uVar14) break;
        uVar9 = (uint)*(byte *)(iVar12 + 0x58c);
        *(uint *)(iVar12 + 0x570) = uVar14;
        piVar3 = _DAT_8013bc80;
        bVar1 = *(byte *)(*(int *)(iVar12 + 0x574) + 2);
        uVar11 = (uint)bVar1;
        bVar2 = *(byte *)(*(int *)(iVar12 + 0x574) + 3);
        uVar10 = (uint)bVar2;
        if ((uVar11 == 0xff) && (uVar10 == 0xff)) {
          *(undefined4 *)(iVar12 + 0x574) = 0;
        }
        else {
          iVar12 = 4;
          if ((bVar1 & 0x80) == 0) {
LAB_800a0098:
            if ((uVar11 != 0) || (_DAT_8013bc80 = piVar3, uVar10 != 0)) {
              uVar8 = (uint)*(byte *)(_DAT_80143c58 + iVar15 + 0x58f);
              iVar12 = 6;
              _DAT_8013bc80 = piVar3;
              if (((*(uint *)(_DAT_80143c58 + ((int)uVar8 >> 5) * 4 + 0x110) & 1 << (uVar8 & 0x1f))
                   != 0) && (iVar13 = *(int *)(_DAT_80143c58 + uVar9 * 4 + 0xf80), iVar13 != -1)) {
                uVar11 = uVar11 + (int)*(char *)(_DAT_80143c58 + iVar15 + 0x58e);
                uVar7 = 0x7f;
                if (((int)uVar11 < 0x80) && (uVar7 = uVar11, (int)uVar11 < 0)) {
                  uVar7 = 0;
                }
                uVar10 = uVar10 + (int)*(char *)(_DAT_80143c58 + iVar15 + 0x58d);
                if ((int)uVar10 < 0x80) {
                  if ((int)uVar10 < 0) {
                    uVar10 = 0;
                  }
                }
                else {
                  uVar10 = 0x7f;
                }
                if (_DAT_8013bc80 != (int *)0x0) {
                  _DAT_8013bc80 = (int *)*_DAT_8013bc80;
                  if (_DAT_8013bc80 != (int *)0x0) {
                    _DAT_8013bc80[1] = 0;
                  }
                  iVar5 = _DAT_80143c58;
                  piVar3[1] = 0;
                  iVar4 = *(int *)(iVar5 + 0xf78);
                  *piVar3 = iVar4;
                  if (iVar4 != 0) {
                    *(int **)(*(int *)(iVar5 + 0xf78) + 4) = piVar3;
                  }
                  *(int **)(_DAT_80143c58 + 0xf78) = piVar3;
                }
                if (piVar3 != (int *)0x0) {
                  if (DAT_80143c54 == '\0') {
                    uVar16 = 0;
                  }
                  else {
                    uVar16 = 0xffffffff;
                  }
                  iVar5 = FUN_800a6820(iVar13,uVar7 & 0xff,uVar10 & 0xff,0x40,uVar9,DAT_80143c53,0,
                                       uVar8,*(undefined1 *)(_DAT_80143c58 + uVar8 + 0x528),uVar16);
                  iVar13 = _DAT_80143c58;
                  if (iVar5 == -1) {
                    if (*piVar3 != 0) {
                      *(int *)(*piVar3 + 4) = piVar3[1];
                    }
                    if ((int *)piVar3[1] == (int *)0x0) {
                      *(int *)(_DAT_80143c58 + 0xf78) = *piVar3;
                    }
                    else {
                      *(int *)piVar3[1] = *piVar3;
                    }
                    *piVar3 = (int)_DAT_8013bc80;
                    if (_DAT_8013bc80 != (int *)0x0) {
                      _DAT_8013bc80[1] = (int)piVar3;
                    }
                    piVar3[1] = 0;
                    _DAT_8013bc80 = piVar3;
                  }
                  else {
                    piVar3[2] = iVar5;
                    iVar13 = iVar13 + iVar15;
                    piVar3[3] = uVar14 + *(ushort *)(*(int *)(iVar13 + 0x574) + 4);
                    iVar5 = *(int *)(iVar13 + 0x56c);
                    piVar3[4] = *(int *)(iVar13 + 0x568);
                    piVar3[5] = iVar5;
                  }
                }
              }
            }
          }
          else if (uVar10 == 0) {
            if (uVar9 == 9) {
              uVar14 = (uint)*(byte *)((uVar11 & 0x7f) + _DAT_80143c58 + 0x8c);
              _DAT_8013bc80 = piVar3;
              if (uVar14 != 0xff) {
                puVar6 = (ushort *)(uVar14 * 8 + *(int *)(_DAT_80143c58 + 0x88));
                *(uint *)(_DAT_80143c58 + 0xfa4) =
                     (uint)*puVar6 << 0x10 | (uint)*(byte *)(puVar6 + 1) << 8 |
                     (uint)*(byte *)((int)puVar6 + 3);
              }
            }
            else {
              uVar14 = (uint)*(byte *)((uVar11 & 0x7f) + _DAT_80143c58 + 8);
              _DAT_8013bc80 = piVar3;
              if (uVar14 != 0xff) {
                puVar6 = (ushort *)(uVar14 * 8 + *(int *)(_DAT_80143c58 + 4));
                *(uint *)(_DAT_80143c58 + uVar9 * 4 + 0xf80) =
                     (uint)*puVar6 << 0x10 | (uint)*(byte *)(puVar6 + 1) << 8 |
                     (uint)*(byte *)((int)puVar6 + 3);
              }
            }
          }
          else {
            if (uVar10 == 1) {
              uVar8 = 0x82;
            }
            else {
              uVar8 = uVar10 & 0x7f;
              if ((bVar2 & 0x80) == 0) goto LAB_800a0098;
              if (uVar8 == 0x68) {
                _DAT_8013bc80 = piVar3;
                if (*(char *)(_DAT_80143c58 + 0xff4) != '\0') {
                  FUN_800a15d0(_DAT_80143c58 + 0xfc8,*(undefined4 *)(_DAT_80143c58 + 0xff0),1);
                  *(undefined1 *)(_DAT_80143c58 + 0xff4) = 0;
                }
                goto LAB_800a0280;
              }
            }
            FUN_800ac614(uVar8,uVar9,DAT_80143c53,uVar11 & 0x7f);
          }
LAB_800a0280:
          *(int *)(_DAT_80143c58 + iVar15 + 0x574) =
               *(int *)(_DAT_80143c58 + iVar15 + 0x574) + iVar12;
        }
      } while (*(int *)(_DAT_80143c58 + iVar15 + 0x574) != 0);
    }
    iVar15 = iVar15 + 0x28;
    local_38 = local_38 + 1;
    if (0x3f < local_38) {
      return local_29;
    }
  } while( true );
}
