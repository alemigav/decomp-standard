/* FUN_8004d3a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d3a0  body 0x8004d3a0..0x8004d79b  size 1020 B
 * body sha256 7593ba77a35d2d1c3b3d180ba9fbfe938e08b775eb90d1574f969a0c995176a3
 * provider record sha256 6eb5e7c2fb9c635c36b4755000fbcbb6082c84baca3ee2e72fce76741ba8045c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8004d3a0(uint *param_1,uint *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  
  uVar4 = *param_2;
  uVar3 = 0;
  if (((*param_1 | uVar4) & 2) == 0) {
    if ((*param_1 & uVar4 & 0x1000) == 0) {
      uVar3 = 0;
      if ((uVar4 & 4) == 0) {
        puVar13 = param_1 + 0x48;
        _DAT_80139b94 = param_1[0xa1];
        _DAT_80139b90 = 0;
        while (_DAT_80139b94 = _DAT_80139b94 - 1, -1 < (int)_DAT_80139b94) {
          puVar10 = param_2 + 0x48;
          uVar4 = (uint)*(ushort *)((int)puVar13 + 0x16);
          _DAT_80139b98 = param_2[0xa1];
          while (_DAT_80139b98 = _DAT_80139b98 - 1, -1 < (int)_DAT_80139b98) {
            iVar9 = uVar4 + *(ushort *)((int)puVar10 + 0x16);
            iVar11 = *puVar10 - *puVar13;
            if ((uint)(iVar9 * 2) < (uint)(iVar11 + iVar9)) {
              puVar10 = puVar10 + 8;
            }
            else {
              iVar12 = puVar10[2] - puVar13[2];
              if ((uint)(iVar9 * 2) < (uint)(iVar12 + iVar9)) {
                puVar10 = puVar10 + 8;
              }
              else {
                iVar2 = FUN_80040bb4(iVar11 * iVar11 + iVar12 * iVar12);
                iVar9 = iVar9 - iVar2;
                if (iVar9 < 1) {
                  puVar10 = puVar10 + 8;
                }
                else {
                  iVar5 = puVar10[1] - puVar13[1];
                  iVar8 = (uint)*(ushort *)((int)puVar10 + 0x1a) +
                          (uint)*(ushort *)((int)puVar13 + 0x1a);
                  if ((-iVar8 < iVar5) && (iVar5 < iVar8)) {
                    iVar2 = iVar2 + 1;
                    iVar5 = (iVar11 * iVar9) / iVar2;
                    if (iVar2 == 0) {
                      trap(0x1c00);
                    }
                    if ((iVar2 == -1) && (iVar11 * iVar9 == -0x80000000)) {
                      trap(0x1800);
                    }
                    iVar6 = ((int)*(short *)((int)param_2 + 0x36) + (int)*(short *)(puVar10 + 5)) -
                            puVar13[1];
                    iVar14 = (iVar12 * iVar9) / iVar2;
                    if (iVar2 == 0) {
                      trap(0x1c00);
                    }
                    if ((iVar2 == -1) && (iVar12 * iVar9 == -0x80000000)) {
                      trap(0x1800);
                    }
                    if ((iVar6 <= -iVar8) || (iVar8 <= iVar6)) {
                      uVar7 = param_1[10];
                      if ((((int)*(short *)(param_2 + 0xd) < (int)uVar7) &&
                          ((int)uVar7 < (int)param_2[10])) ||
                         (((int)uVar7 < (int)*(short *)(param_2 + 0xd) &&
                          ((int)param_2[10] < (int)uVar7)))) {
                        iVar8 = -(iVar11 * iVar9) / iVar2;
                        if (iVar2 == 0) {
                          trap(0x1c00);
                        }
                        if ((iVar2 == -1) && (-(iVar11 * iVar9) == -0x80000000)) {
                          trap(0x1800);
                        }
                        iVar5 = uVar4 * 2;
                        if (iVar8 < 1) {
                          iVar5 = uVar4 * -2;
                        }
                        iVar5 = iVar5 - iVar8;
                      }
                      uVar7 = param_1[0xc];
                      if ((((int)*(short *)(param_2 + 0xe) < (int)uVar7) &&
                          ((int)uVar7 < (int)param_2[0xc])) ||
                         (((int)uVar7 < (int)*(short *)(param_2 + 0xe) &&
                          ((int)param_2[0xc] < (int)uVar7)))) {
                        iVar11 = -(iVar12 * iVar9) / iVar2;
                        if (iVar2 == 0) {
                          trap(0x1c00);
                        }
                        if ((iVar2 == -1) && (-(iVar12 * iVar9) == -0x80000000)) {
                          trap(0x1800);
                        }
                        iVar14 = uVar4 * 2;
                        if (iVar11 < 1) {
                          iVar14 = uVar4 * -2;
                        }
                        iVar14 = iVar14 - iVar11;
                      }
                    }
                    if ((*param_1 & 0x100000) != 0) {
                      iVar9 = iVar5;
                      if (iVar5 < 0) {
                        iVar9 = -iVar5;
                      }
                      if (100 < iVar9) {
                        if (iVar5 < 0) {
                          iVar5 = -100;
                        }
                        else {
                          iVar14 = 100;
                        }
                      }
                      iVar9 = iVar14;
                      if (iVar14 < 0) {
                        iVar9 = -iVar14;
                      }
                      if ((100 < iVar9) && (bVar1 = iVar14 < 0, iVar14 = 100, bVar1)) {
                        iVar14 = -100;
                      }
                    }
                    _DAT_80139b90 = 1;
                    param_2[10] = param_2[10] + iVar5;
                    param_2[0xc] = param_2[0xc] + iVar14;
                    *puVar10 = *puVar10 + iVar5;
                    puVar10[2] = puVar10[2] + iVar14;
                    *(undefined1 *)((int)param_2 + 0xd) = *(undefined1 *)(param_1 + 3);
                  }
                  puVar10 = puVar10 + 8;
                }
              }
            }
          }
          puVar13 = puVar13 + 8;
        }
        uVar3 = _DAT_80139b90;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}
