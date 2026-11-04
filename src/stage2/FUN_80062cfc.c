/* FUN_80062cfc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062cfc  body 0x80062cfc..0x800632d7  size 1500 B
 * body sha256 2534f9a30cb42e50f4ab2880d6532bece57d5ada220212ba6a4366f5d54b48a8
 * provider record sha256 972052e8c7784a09c41f64a9d490a7affc695383257a1c05d0420a1436d0c2b3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_80062cfc(char param_1)

{
  byte bVar1;
  int iVar2;
  ushort uVar4;
  uint uVar3;
  ushort uVar6;
  uint uVar5;
  ushort uVar7;
  ushort uVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  ushort uVar12;
  ushort *puVar13;
  ushort *puVar14;
  ushort uVar15;
  uint uVar16;
  undefined4 *puVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined8 uVar22;
  float fVar23;
  
  if ((DAT_800e10ec & 0x40200000) == 0x40000000) {
    iVar9 = (int)DAT_800e8cac;
    puVar13 = *(ushort **)(iVar9 * 0x20 + *(int *)(DAT_800df92c + 0x24) + 0x1c);
    if (puVar13 != (ushort *)0xffffffff) {
      _DAT_80139df0 = *puVar13;
      _DAT_80139df2 = puVar13[1];
      _DAT_80139df4 = (float)DAT_801137d8;
      uVar16 = (uint)puVar13[2];
      puVar13 = puVar13 + 3;
      if (DAT_801137d8 < 0) {
        _DAT_80139df4 = _DAT_80139df4 + 4.2949673e+09;
      }
      _DAT_80139df8 = (float)DAT_801137dc;
      _DAT_80139df4 = _DAT_80139df4 / (float)_DAT_80139df0;
      if (DAT_801137dc < 0) {
        _DAT_80139df8 = _DAT_80139df8 + 4.2949673e+09;
      }
      _DAT_80139df8 = _DAT_80139df8 / (float)_DAT_80139df2;
      _DAT_80139dfc = uVar16;
      if (param_1 == '\0') {
        iVar9 = uVar16 - 1;
        _DAT_80139e0c = 0x100;
        _DAT_80139e18 = 0;
        _DAT_80139e10 = 1;
        _DAT_80139e00 = 1;
        if (iVar9 != -1) {
          puVar17 = (undefined4 *)(&DAT_80139bf0 + iVar9 * 4);
          do {
            *puVar17 = puVar13;
            if (((int)(short)*puVar13 & 0x8000U) == 0) {
              *puVar17 = 0;
              uVar15 = puVar13[1];
              if ((short)puVar13[1] < 0) {
                uVar15 = 0;
              }
              uVar6 = puVar13[2];
              if ((short)puVar13[2] < 0) {
                uVar6 = 0;
              }
              puVar14 = puVar13 + 4;
              uVar11 = puVar13[5] + uVar6;
              puVar13 = puVar13 + 6;
              for (; uVar6 < uVar11; uVar6 = uVar6 + 1) {
                for (uVar4 = uVar15; uVar4 != (ushort)(*puVar14 + uVar15); uVar4 = uVar4 + uVar8) {
                  bVar1 = *(byte *)puVar13;
                  uVar8 = (ushort)bVar1;
                  puVar13 = (ushort *)((int)puVar13 + 1);
                  if ((bVar1 & 0x80) != 0) {
                    uVar8 = uVar8 & 0x7f;
                  }
                }
              }
            }
            else {
              _DAT_80139e18 = 1;
              puVar13 = (ushort *)
                        (((uint)((int)puVar13 + 0x13) & 0xfffffff8) +
                        (uint)puVar13[4] * (uint)puVar13[5]);
            }
            if (((uint)puVar13 & 1) != 0) {
              puVar13 = (ushort *)((int)puVar13 + 1);
            }
            iVar9 = iVar9 + -1;
            puVar17 = puVar17 + -1;
          } while (iVar9 != -1);
        }
        if (_DAT_80139e18 != 0) {
          _DAT_80139e18 = (uint)((int)puVar13 + 7) & 0xfffffff8;
        }
      }
      else {
        uVar22 = 0x4f000000;
        puVar17 = (undefined4 *)(&DAT_80139bf0 + uVar16 * 4);
        while( true ) {
          uVar16 = uVar16 - 1;
          puVar17 = puVar17 + -1;
          if (uVar16 == 0xffffffff) break;
          puVar14 = puVar13 + 6;
          iVar2 = FUN_800837ac(&DAT_800e8db4 + iVar9 * 4,*puVar13 & 0x7fff);
          if (((int)(short)*puVar13 & 0x8000U) == 0) {
            *puVar17 = 0;
            uVar15 = puVar13[1];
            if ((short)puVar13[1] < 0) {
              uVar15 = 0;
            }
            uVar6 = puVar13[2];
            if ((short)puVar13[2] < 0) {
              uVar6 = 0;
            }
            uVar4 = FUN_80062c70((float)puVar13[3]);
            uVar11 = puVar13[4];
            uVar8 = puVar13[5] + uVar6;
            for (; uVar12 = uVar15, uVar6 < uVar8; uVar6 = uVar6 + 1) {
              while (uVar12 != (ushort)(uVar11 + uVar15)) {
                bVar1 = *(byte *)puVar14;
                uVar7 = (ushort)bVar1;
                puVar14 = (ushort *)((int)puVar14 + 1);
                if ((bVar1 & 0x80) == 0) {
                  if (iVar2 == 0) goto LAB_80062f78;
                  fVar18 = (float)uVar12 * _DAT_80139df4;
                  fVar23 = (float)uVar22;
                  if (fVar23 <= fVar18) {
                    fVar18 = fVar18 - fVar23;
                  }
                  fVar19 = (float)(ushort)(uVar12 + uVar7) * _DAT_80139df4;
                  if (fVar23 <= fVar19) {
                    fVar19 = fVar19 - fVar23;
                  }
                  fVar20 = (float)(uVar6 + 1) * _DAT_80139df8;
                  if (fVar23 <= fVar20) {
                    fVar20 = fVar20 - fVar23;
                  }
                  fVar21 = (float)uVar6 * _DAT_80139df8;
                  if (fVar23 <= fVar21) {
                    fVar21 = fVar21 - fVar23;
                  }
                  uVar5 = (uint)fVar21;
                  if (((int)fVar20 & 0xffffU) <= (uVar5 & 0xffff)) goto LAB_80062f78;
                  do {
                    uVar5 = uVar5 + 1;
                    puVar13 = (ushort *)
                              (DAT_8010b6f8 + ((int)fVar18 & 0xffffU) * 2 +
                              (uVar5 & 0xffff) * DAT_801137d8 * 2);
                    uVar10 = (int)fVar18;
                    do {
                      if ((uVar4 | 1) < *puVar13) {
                        *puVar13 = uVar4 | 1;
                      }
                      puVar13 = puVar13 + 1;
                      uVar3 = uVar10 & 0xffff;
                      uVar10 = uVar10 + 1;
                    } while (uVar3 < ((int)fVar19 & 0xffffU));
                  } while ((uVar5 & 0xffff) < ((int)fVar20 & 0xffffU));
                  uVar12 = uVar12 + uVar7;
                }
                else {
                  uVar7 = uVar7 & 0x7f;
LAB_80062f78:
                  uVar12 = uVar12 + uVar7;
                }
              }
            }
          }
          else {
            puVar14 = (ushort *)
                      (((uint)((int)puVar13 + 0x13) & 0xfffffff8) +
                      (uint)puVar13[4] * (uint)puVar13[5]);
          }
          puVar13 = puVar14;
          if (((uint)puVar14 & 1) != 0) {
            puVar13 = (ushort *)((int)puVar14 + 1);
          }
        }
      }
    }
  }
  return;
}
