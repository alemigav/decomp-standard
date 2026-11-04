/* FUN_800a6c04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a6c04  body 0x800a6c04..0x800a76a3  size 2720 B
 * body sha256 a83d54b8570283caf74a8235713f7d3e1e3b563726ef2c4351888d710e8cdb8a
 * provider record sha256 edb5a08bbb484a3a3393de1fdca650a3999b41cd8a404270d5154d5a8bf303c7
 * callees 25 direct (25 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a6c04(void)

{
  byte bVar1;
  byte bVar2;
  char cVar9;
  uint uVar3;
  undefined2 uVar6;
  short sVar7;
  ushort uVar8;
  int iVar4;
  uint uVar5;
  uint uVar10;
  int *piVar11;
  int iVar12;
  undefined2 *puVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  
  piVar15 = (int *)&DAT_80144448;
  iVar16 = 0;
  if (DAT_80147a58 != 0) {
    puVar13 = (undefined2 *)0x8014450a;
    do {
      if (*piVar15 == 0) {
        cVar9 = FUN_800a5890(iVar16);
        if (cVar9 != '\0') goto LAB_800a6c84;
      }
      else {
        FUN_800b03cc(piVar15);
LAB_800a6c84:
        if (*(char *)((int)puVar13 + -5) == '\0') {
          iVar14 = 0;
          piVar11 = piVar15;
          do {
            uVar3 = piVar11[0x5b];
            if (uVar3 != 0) {
              uVar10 = piVar11[0x5a] + _DAT_80147848;
              if (uVar3 == 0) {
                trap(0x1c00);
              }
              if (uVar3 >> 8 == 0) {
                trap(0x1c00);
              }
              piVar11[0x5a] = uVar10;
              uVar6 = FUN_800ab330((uVar10 % uVar3 << 4) / (uVar3 >> 8) & 0xffff);
              *(undefined2 *)(piVar11 + 0x5c) = uVar6;
            }
            iVar14 = iVar14 + 1;
            piVar11 = piVar11 + 3;
          } while (iVar14 < 2);
          if ((*(uint *)(puVar13 + -0x4f) & 0x4000) != 0) {
            uVar3 = *(uint *)(puVar13 + -0x29);
            uVar10 = *(int *)(puVar13 + -0x2b) + _DAT_80147848;
            if (uVar3 == 0) {
              trap(0x1c00);
            }
            if (uVar3 >> 8 == 0) {
              trap(0x1c00);
            }
            *(uint *)(puVar13 + -0x2b) = uVar10;
            sVar7 = FUN_800ab330((uVar10 % uVar3 << 4) / (uVar3 >> 8) & 0xffff);
            *(int *)(puVar13 + -0x27) = (int)sVar7;
          }
          iVar14 = 0;
          piVar11 = piVar15;
          do {
            if (*(char *)((int)piVar15 + iVar14 + 0x48) != '\0') {
              cVar9 = *(char *)((int)piVar15 + iVar14 + 0xb0) + -1;
              *(char *)((int)piVar15 + iVar14 + 0xb0) = cVar9;
              if (cVar9 == '\0') {
                *(undefined1 *)((int)piVar15 + iVar14 + 0xb0) =
                     *(undefined1 *)((int)piVar15 + iVar14 + 0x48);
                piVar11[0x10] = 0;
              }
              else {
                piVar11[0x10] = piVar11[0x10] + piVar11[0x1f];
              }
            }
            iVar14 = iVar14 + 1;
            piVar11 = piVar11 + 1;
          } while (iVar14 < 2);
          if ((*(char *)(puVar13 + -0x3c) == -1) || (uVar8 = FUN_800ac948(piVar15), uVar8 < 0x1f81))
          {
            uVar3 = *(uint *)(puVar13 + -0x4f) & 0xbfffffff;
          }
          else {
            uVar3 = *(uint *)(puVar13 + -0x4f) | 0x40000000;
          }
          *(uint *)(puVar13 + -0x4f) = uVar3;
          if ((*(uint *)(puVar13 + -0x4f) & 0x1000) == 0) {
            if (*(char *)(puVar13 + -0x3c) != -1) {
              uVar8 = FUN_800ac968(piVar15);
              if (uVar8 < 0x1f81) {
                *(uint *)(puVar13 + -0x4f) = *(uint *)(puVar13 + -0x4f) & 0xfffff7ff;
                FUN_800ac734(*(undefined1 *)(puVar13 + -0x3c),*(undefined1 *)((int)puVar13 + -0x77),
                             0);
              }
              else {
                uVar3 = *(uint *)(puVar13 + -0x4f);
                if ((uVar3 & 0x800) == 0) {
                  if ((uVar3 & 0x80000) == 0) {
                    if ((*(char *)(puVar13 + -0x15) == '\x01') && ((uVar3 & 0x2000) == 0)) {
                      *(undefined4 *)(puVar13 + -0x1b) = 0;
                    }
                    else {
                      *(undefined4 *)(puVar13 + -0x1b) = *(undefined4 *)(puVar13 + -0x19);
                    }
                    *(uint *)(puVar13 + -0x17) = (uint)*(byte *)((int)puVar13 + -1) << 0x10;
                  }
                  if (*(char *)(puVar13 + -0x3c) != -1) {
                    FUN_800ac734(*(char *)(puVar13 + -0x3c),*(undefined1 *)((int)puVar13 + -0x77),1)
                    ;
                  }
                }
                *(uint *)(puVar13 + -0x4f) = *(uint *)(puVar13 + -0x4f) | 0x800;
              }
            }
            *(uint *)(puVar13 + -0x4f) = *(uint *)(puVar13 + -0x4f) | 0x2000;
          }
          uVar3 = *(uint *)(puVar13 + -0x4f);
          if ((uVar3 & 0x20) != 0) {
            *(uint *)(puVar13 + -0x4f) = uVar3 & 0xffffffdf | 0x10;
            FUN_800a597c(iVar16);
            uVar3 = *(uint *)(puVar13 + -0x4f);
          }
          if (((uVar3 & 0x80) != 0) && ((uVar3 & 0x40000000) == 0)) {
            *(uint *)(puVar13 + -0x4f) = uVar3 & 0xffffff6f;
            FUN_800a59d0(iVar16);
          }
          if ((*(int *)(puVar13 + -0x4d) != 0) &&
             (iVar14 = *(int *)(puVar13 + -0x4d) - (uint)(ushort)puVar13[-0x4b] * _DAT_80147848,
             *(int *)(puVar13 + -0x4d) = iVar14, iVar14 < 0)) {
            *(undefined4 *)(puVar13 + -0x4d) = 0;
          }
          if ((*(uint *)(puVar13 + -0x4f) & 0x10000) != 0) {
            uVar3 = *(int *)(puVar13 + -0xb) -
                    (*(uint *)(puVar13 + -0xd) >> 8) * *(int *)(puVar13 + -0x43);
            *(uint *)(puVar13 + -0x45) = uVar3;
            iVar14 = _DAT_80147848;
            if ((int)uVar3 < 0) {
              uVar10 = 0;
            }
            else {
              uVar10 = 0x7f0000;
              if (uVar3 < 0x7f0001) {
                uVar10 = uVar3;
              }
            }
            iVar4 = *(int *)(puVar13 + -0xd);
            *(uint *)(puVar13 + -0x45) = uVar10;
            *(int *)(puVar13 + -0xd) = iVar4 - iVar14;
            if (iVar4 - iVar14 == 0) {
              *(uint *)(puVar13 + -0x4f) = *(uint *)(puVar13 + -0x4f) & 0xfffeffff;
              *(undefined4 *)(puVar13 + -0x45) = *(undefined4 *)(puVar13 + -0xb);
            }
          }
          uVar3 = (uint)(ushort)puVar13[-0x39] * 0x10000 +
                  ((int)*(char *)(puVar13 + -1) << 0x10) / 100;
          if ((*(uint *)(puVar13 + -0x4f) & 0x40010) == 0) {
            uVar8 = puVar13[-5];
LAB_800a704c:
            iVar14 = uVar8 - 0x2000;
            if (uVar8 != 0x2000) {
              if (iVar14 < 0) {
                bVar2 = *(byte *)(puVar13 + -0x2c);
              }
              else {
                bVar2 = *(byte *)((int)puVar13 + -0x57);
              }
              uVar3 = uVar3 + (uint)bVar2 * iVar14 * 8;
            }
          }
          else if (*(char *)(puVar13 + -0x3c) != -1) {
            uVar8 = FUN_800ac8e8(piVar15);
            puVar13[-5] = uVar8;
            goto LAB_800a704c;
          }
          if ((*(uint *)(puVar13 + -0x4f) & 0x4000) != 0) {
            bVar2 = *(byte *)((int)puVar13 + -0x49);
            bVar1 = *(byte *)(puVar13 + -0x25);
            if (((*(uint *)(puVar13 + -0x4f) & 0x8000) == 0) || (*(char *)(puVar13 + -0x3c) == -1))
            {
              iVar14 = *(int *)(puVar13 + -0x27);
            }
            else {
              uVar10 = FUN_800ac928(piVar15);
              iVar14 = (int)(*(int *)(puVar13 + -0x27) * ((uVar10 & 0xffff) >> 7)) >> 7;
            }
            uVar3 = uVar3 + ((int)(((uint)bVar1 * 0x100 + ((uint)bVar2 << 8) / 100) * iVar14) >> 4);
          }
          if (((*(uint *)(puVar13 + -0x4f) & 0x800) != 0) &&
             (uVar10 = (uint)(*(int *)(puVar13 + -0x19) - *(int *)(puVar13 + -0x1b)) >> 8,
             uVar10 != 0)) {
            uVar5 = *(uint *)(puVar13 + -0x17);
            iVar14 = _DAT_80147848 * ((int)(uVar3 - uVar5) >> 8);
            if (uVar10 == 0) {
              trap(0x1c00);
            }
            if ((uVar10 == 0xffffffff) && (iVar14 == -0x80000000)) {
              trap(0x1800);
            }
            uVar10 = uVar5 + iVar14 / (int)uVar10;
            *(uint *)(puVar13 + -0x17) = uVar10;
            if (((uVar5 < uVar3) && (uVar10 < uVar3)) || ((uVar3 < uVar5 && (uVar3 < uVar10)))) {
              uVar3 = *(uint *)(puVar13 + -0x17);
              iVar14 = *(int *)(puVar13 + -0x1b) + _DAT_80147848;
            }
            else {
              iVar14 = *(int *)(puVar13 + -0x19);
            }
            *(int *)(puVar13 + -0x1b) = iVar14;
          }
          uVar10 = FUN_800a60f4(uVar3 >> 0x10 & 0xff,*(undefined4 *)(puVar13 + -0x33));
          iVar14 = uVar10 * 0x10000;
          if ((uVar3 & 0xffff) != 0) {
            uVar5 = FUN_800a61fc(uVar10 & 0xffff);
            iVar14 = iVar14 + ((uVar5 & 0xffff) - (uVar10 & 0xffff)) * (uVar3 & 0xffff);
          }
          uVar3 = iVar14 + *(int *)(puVar13 + -0x41) + *(int *)(puVar13 + -0x3f);
          if (*(char *)(puVar13 + -0x3c) == -1) {
            uVar3 = uVar3 >> 0x10;
          }
          else {
            uVar10 = FUN_800ac908(piVar15);
            uVar3 = (uVar3 >> 0x10) * (uVar10 & 0xffff) >> 0xd;
          }
          if ((DAT_80136311 != '\0') && (DAT_80136311 != '*')) {
            uVar10 = FUN_800ab3cc(iVar16);
            uVar3 = (uVar3 - 0x80) + (uVar10 & 0xff);
          }
          FUN_800a5a00(iVar16,uVar3 & 0xffff);
          if ((*(uint *)(puVar13 + -0x4f) & 0x20000) != 0) {
            uVar3 = *(int *)(puVar13 + -0x1d) -
                    (*(uint *)(puVar13 + -7) >> 8) * *(int *)(puVar13 + -0x1f);
            *(uint *)(puVar13 + -0x49) = uVar3;
            iVar14 = _DAT_80147848;
            if ((int)uVar3 < 0) {
              uVar10 = 0;
            }
            else {
              uVar10 = 0x7f0000;
              if (uVar3 < 0x7f0001) {
                uVar10 = uVar3;
              }
            }
            iVar4 = *(int *)(puVar13 + -7);
            *(uint *)(puVar13 + -0x49) = uVar10;
            *(int *)(puVar13 + -7) = iVar4 - iVar14;
            if (iVar4 - iVar14 < 1) {
              *(uint *)(puVar13 + -0x4f) = *(uint *)(puVar13 + -0x4f) & 0xfffdffff;
              *(undefined4 *)(puVar13 + -0x49) = *(undefined4 *)(puVar13 + -0x1d);
            }
          }
          iVar4 = *(int *)(puVar13 + -0x45);
          cVar9 = *(char *)(puVar13 + -0x3c);
          iVar14 = 0x348;
          if (*(char *)(puVar13 + -0x3b) != '\0') {
            iVar14 = 0x370;
          }
          iVar14 = (((*(int *)(puVar13 + -0x49) >> 7) *
                     (int)*(short *)(&DAT_80147ab8 + (uint)*(byte *)(puVar13 + -2) * 0x28) >> 7) *
                    (int)*(short *)(&DAT_80147aa0 + (uint)*(byte *)(puVar13 + -2) * 0x28) >> 7) *
                   (int)*(short *)(&DAT_80147aa0 + iVar14);
          if (*(byte *)((int)puVar13 + -0x93) != 0xff) {
            iVar14 = (iVar14 >> 7) * (uint)*(byte *)(*(byte *)((int)puVar13 + -0x93) + 0x80147a60);
          }
          if (DAT_80147fa9 == '\0') {
            uVar3 = 0;
            if (cVar9 != -1) {
              uVar3 = FUN_800ac888(piVar15);
              iVar14 = (iVar14 >> 7) * ((uVar3 & 0xffff) >> 7);
              if (iVar4 != 0x800000) {
                uVar3 = FUN_800ac8a8(piVar15);
                iVar4 = iVar4 + (((uVar3 & 0xffff) >> 7) - 0x40) * 0x10000;
                if (iVar4 < 0) {
                  iVar4 = 0;
                }
                else if (0x7f0000 < iVar4) {
                  iVar4 = 0x7f0000;
                }
              }
              uVar3 = FUN_800ac8c8(piVar15);
              uVar3 = (uVar3 & 0xffff) << 9;
              if (0x7f0000 < uVar3) {
                uVar3 = 0x7f0000;
              }
            }
          }
          else {
            if (cVar9 != -1) {
              uVar3 = FUN_800ac888(piVar15);
              iVar14 = (iVar14 >> 7) * ((uVar3 & 0xffff) >> 7);
            }
            iVar4 = 0x400000;
            uVar3 = 0;
          }
          if (iVar16 == 0) {
            FUN_800a860c();
          }
          iVar12 = 0;
          if (cVar9 != -1) {
            uVar10 = FUN_800ac988(piVar15);
            iVar12 = (int)(((uVar10 & 0xffff) >> 7) * iVar14) >> 7;
            if (0x7f0000 < iVar12) {
              iVar12 = 0x7f0000;
            }
            iVar12 = (iVar12 >> 7) * (uint)*(byte *)((int)puVar13 + -0x29);
            if (0x7f0000 < iVar12) {
              iVar12 = 0x7f0000;
            }
            iVar12 = iVar12 + (uint)*(byte *)(puVar13 + -0x14) * 0x10000;
            if (0x7f0000 < iVar12) {
              iVar12 = 0x7f0000;
            }
          }
          *puVar13 = (short)((uint)iVar14 >> 8);
          FUN_800a5a60(iVar16,iVar14,iVar4,uVar3,iVar12);
        }
      }
      iVar16 = iVar16 + 1;
      puVar13 = puVar13 + 0xd0;
      piVar15 = piVar15 + 0x68;
    } while (iVar16 < (int)(uint)DAT_80147a58);
  }
  piVar15 = (int *)&DAT_80147aa0;
  do {
    if (piVar15[3] != 0) {
      iVar16 = piVar15[1] - (piVar15[3] >> 8) * piVar15[2];
      *piVar15 = iVar16;
      if (iVar16 < 0) {
        *piVar15 = 0;
      }
      iVar16 = piVar15[3] - _DAT_80147848;
      piVar15[3] = iVar16;
      if (iVar16 < 1) {
        bVar2 = *(byte *)((int)piVar15 + 0x15);
        piVar15[3] = 0;
        *piVar15 = piVar15[1];
        if (bVar2 == 2) {
          FUN_800a0d1c(piVar15[4]);
        }
        else if (bVar2 < 3) {
          if (bVar2 == 1) {
            FUN_800a0f1c(piVar15[4]);
          }
        }
        else if (bVar2 == 3) {
          FUN_800a12f8(piVar15[4],0,0);
        }
      }
    }
    if (piVar15[9] != 0) {
      iVar16 = piVar15[7] - (piVar15[9] >> 8) * piVar15[8];
      piVar15[6] = iVar16;
      if (iVar16 < 0) {
        piVar15[6] = 0;
      }
      iVar16 = piVar15[9] - _DAT_80147848;
      piVar15[9] = iVar16;
      if (iVar16 < 1) {
        piVar15[9] = 0;
        piVar15[6] = piVar15[7];
      }
    }
    piVar15 = piVar15 + 10;
  } while ((int)piVar15 < -0x7feb8060);
  FUN_800a5cf4();
  return;
}
