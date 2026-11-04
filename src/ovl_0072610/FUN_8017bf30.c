/* FUN_8017bf30
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017bf30  body 0x8017bf30..0x8017c38b  size 1116 B
 * body sha256 d848de0d57fff0d1e62ba007a1d265fbc7d15d5c7da6e91cba6c7671ff6f1961
 * provider record sha256 4105be639f5b966e9105afbf24b60eaad8af2ce1ff67e667553dc47df7b044d0
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8017c14c) */
/* WARNING: Removing unreachable block (ram,0x8017c168) */
/* WARNING: Removing unreachable block (ram,0x8017c180) */
/* WARNING: Removing unreachable block (ram,0x8017c188) */
/* WARNING: Removing unreachable block (ram,0x8017c1ac) */

void FUN_8017bf30(int param_1,int *param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined *puVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  ushort *puVar10;
  ushort uVar11;
  int iVar12;
  uint uVar13;
  byte *pbVar14;
  int *piVar15;
  
  piVar15 = DAT_80186c94 + param_1 * 0x20 + 0x10e;
  if (param_1 < 4) {
    iVar3 = FUN_8017f94c();
    iVar3 = *param_2 + iVar3;
    *param_2 = iVar3;
  }
  else if (param_1 == 4) {
    iVar3 = FUN_8017f9ec();
    iVar3 = param_2[1] + iVar3;
    param_2[1] = iVar3;
  }
  else {
    iVar3 = FUN_8017f9ec();
    iVar3 = param_2[2] + iVar3;
    param_2[2] = iVar3;
  }
  *(short *)piVar15 = (short)(iVar3 << 3);
  iVar3 = 1;
  if (DAT_80185780 == 0) {
    iVar12 = DAT_80186c94[4];
    uVar13 = DAT_80186c94[3];
    while( true ) {
      piVar2 = DAT_80186c94;
      uVar9 = uVar13 >> 0x10;
      if (uVar9 < 0x4000) {
        if (uVar9 < 0x400) {
          if (uVar9 < 0x200) {
            if (uVar9 < 0x100) {
              if (uVar9 < 0x80) {
                if (uVar9 < 0x40) {
                  if (uVar9 < 0x20) {
                    if (uVar9 < 0x10) {
                      DAT_80185780 = 1;
                      return;
                    }
                    iVar8 = uVar9 * 3;
                    puVar4 = &DAT_801853fc;
                  }
                  else {
                    iVar8 = (uVar13 >> 0x11) * 3;
                    puVar4 = &UNK_801853cc;
                  }
                }
                else {
                  iVar8 = (uVar13 >> 0x12) * 3;
                  puVar4 = &UNK_8018539c;
                }
              }
              else {
                iVar8 = (uVar13 >> 0x13) * 3;
                puVar4 = &UNK_8018536c;
              }
            }
            else {
              iVar8 = (uVar13 >> 0x14) * 3;
              puVar4 = &UNK_8018533c;
            }
          }
          else {
            iVar8 = (uVar13 >> 0x16) * 3;
            puVar4 = &UNK_80185324;
          }
          pbVar14 = puVar4 + iVar8;
        }
        else {
          pbVar14 = &DAT_80184f88 + (uVar13 >> 0x18) * 3;
        }
      }
      else {
        pbVar14 = &DAT_80184f64 + (uVar13 >> 0x1c) * 3;
      }
      uVar13 = uVar13 << (pbVar14[2] & 0x1f);
      iVar12 = iVar12 - (uint)pbVar14[2];
      if (iVar12 < 0x19) {
        if ((uint)DAT_80186c94[2] < *DAT_80186c94 + 0x7fcU) {
          do {
            uVar9 = 0x18 - iVar12;
            pbVar5 = (byte *)piVar2[2];
            iVar12 = iVar12 + 8;
            bVar1 = *pbVar5;
            piVar2[2] = (int)(pbVar5 + 1);
            uVar13 = uVar13 | (uint)bVar1 << (uVar9 & 0x1f);
          } while (iVar12 < 0x19);
        }
        else {
          do {
            if (*DAT_80186c94 + 0x800U <= (uint)DAT_80186c94[2]) {
              FUN_8017b7e8();
            }
            uVar9 = 0x18 - iVar12;
            iVar12 = iVar12 + 8;
            bVar1 = *(byte *)DAT_80186c94[2];
            DAT_80186c94[2] = (int)((byte *)DAT_80186c94[2] + 1);
            uVar13 = uVar13 | (uint)bVar1 << (uVar9 & 0x1f);
          } while (iVar12 < 0x19);
        }
      }
      piVar2 = DAT_80186c94;
      if (*pbVar14 == 0x40) break;
      uVar9 = uVar13 >> 0x1f;
      if (*pbVar14 == 0x41) {
        DAT_80186c94[4] = iVar12;
        piVar2[3] = uVar13;
        uVar6 = FUN_8017bec8(6);
        uVar7 = FUN_8017bec8(8);
        if (uVar7 == 0) {
          uVar7 = FUN_8017bec8(8);
        }
        else if (uVar7 == 0x80) {
          iVar12 = FUN_8017bec8(8);
          uVar7 = iVar12 - 0x100;
        }
        else if (0x80 < (int)uVar7) {
          uVar7 = uVar7 - 0x100;
        }
        uVar9 = -((int)uVar7 >> 0x1f);
        if (uVar9 != 0) {
          uVar7 = -uVar7;
        }
        iVar12 = DAT_80186c94[4];
        uVar13 = DAT_80186c94[3];
      }
      else {
        uVar13 = uVar13 << 1;
        iVar12 = iVar12 + -1;
        uVar6 = (uint)*pbVar14;
        uVar7 = (uint)pbVar14[1];
      }
      puVar10 = (ushort *)((int)piVar15 + (uint)(byte)(&DAT_801854a0)[iVar3 + uVar6] * 2);
      uVar11 = (short)((int)(uVar7 * DAT_80186c94[0x10d] *
                            DAT_80186c94[(byte)(&DAT_801854a0)[iVar3 + uVar6] + 7]) >> 3) - 1U | 1;
      *puVar10 = uVar11;
      if (uVar9 != 0) {
        *puVar10 = -uVar11;
      }
      iVar3 = iVar3 + uVar6 + 1;
    }
    DAT_80186c94[4] = iVar12;
    piVar2[3] = uVar13;
  }
  return;
}
