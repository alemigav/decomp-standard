/* FUN_8017c788
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017c788  body 0x8017c788..0x8017cc93  size 1292 B
 * body sha256 6d873cca4ff9c8aaadb796112bb40c0f6471f1dc3706260a883e7b23e8910db4
 * provider record sha256 51735beb625ddbff6313699519be1ba38c95206bae9dee48c01eae128e7ea771
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8017c820) */
/* WARNING: Removing unreachable block (ram,0x8017c800) */
/* WARNING: Removing unreachable block (ram,0x8017c810) */
/* WARNING: Removing unreachable block (ram,0x8017c828) */
/* WARNING: Removing unreachable block (ram,0x8017cc34) */
/* WARNING: Removing unreachable block (ram,0x8017cc3c) */
/* WARNING: Removing unreachable block (ram,0x8017cc44) */

void FUN_8017c788(uint param_1,int *param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined *puVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  int iVar9;
  short *psVar10;
  uint uVar11;
  short sVar12;
  int *piVar13;
  byte *pbVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  
  piVar17 = DAT_80186c94;
  if (DAT_80186c94[0x108] == 1) {
    piVar17 = (int *)&DAT_80185824;
  }
  piVar13 = piVar17 + 7;
  if ((3 < (int)param_1) && (piVar13 = piVar17 + 0x87, DAT_8018575c == 1)) {
    piVar13 = piVar17 + 7;
  }
  if ((int)param_1 < 4) {
    iVar3 = FUN_8017f94c();
    iVar3 = *param_2 + iVar3;
    *param_2 = iVar3;
  }
  else if ((param_1 & 1) == 0) {
    iVar3 = FUN_8017f9ec();
    iVar3 = param_2[1] + iVar3;
    param_2[1] = iVar3;
  }
  else {
    iVar3 = FUN_8017f9ec();
    iVar3 = param_2[2] + iVar3;
    param_2[2] = iVar3;
  }
  if (DAT_80185780 != 0) {
    return;
  }
  iVar16 = 1;
  *(short *)(piVar17 + param_1 * 0x20 + 0x10e) = (short)(iVar3 << (3U - DAT_8018579c & 0x1f));
  iVar3 = DAT_80186c94[4];
  uVar15 = DAT_80186c94[3];
  while( true ) {
    piVar2 = DAT_80186c94;
    uVar11 = uVar15 >> 0x10;
    if ((uVar11 < 0x4000) || (DAT_801857b0 != 0)) {
      if (uVar11 < 0x400) {
        if (uVar11 < 0x200) {
          if (uVar11 < 0x100) {
            if (uVar11 < 0x80) {
              if (uVar11 < 0x40) {
                if (uVar11 < 0x20) {
                  if (uVar11 < 0x10) {
                    DAT_80185780 = 1;
                    return;
                  }
                  iVar9 = uVar11 * 3;
                  puVar4 = &DAT_801853fc;
                }
                else {
                  iVar9 = (uVar15 >> 0x11) * 3;
                  puVar4 = &UNK_801853cc;
                }
              }
              else {
                iVar9 = (uVar15 >> 0x12) * 3;
                puVar4 = &UNK_8018539c;
              }
            }
            else {
              iVar9 = (uVar15 >> 0x13) * 3;
              puVar4 = &UNK_8018536c;
            }
          }
          else {
            iVar9 = (uVar15 >> 0x14) * 3;
            puVar4 = &UNK_8018533c;
          }
        }
        else if (DAT_801857b0 == 0) {
          iVar9 = (uVar15 >> 0x16) * 3;
          puVar4 = &UNK_80185324;
        }
        else {
          iVar9 = (uVar15 >> 0x16) * 3;
          puVar4 = &UNK_8018533c;
        }
      }
      else if (DAT_801857b0 == 0) {
        iVar9 = (uVar15 >> 0x18) * 3;
        puVar4 = &DAT_80184f88;
      }
      else {
        iVar9 = (uVar15 >> 0x18) * 3;
        puVar4 = &DAT_8018503c;
      }
      pbVar14 = puVar4 + iVar9;
    }
    else {
      pbVar14 = &DAT_80184f64 + (uVar15 >> 0x1c) * 3;
    }
    uVar15 = uVar15 << (pbVar14[2] & 0x1f);
    iVar3 = iVar3 - (uint)pbVar14[2];
    if (iVar3 < 0x19) {
      if ((uint)DAT_80186c94[2] < *DAT_80186c94 + 0x7fcU) {
        do {
          uVar11 = 0x18 - iVar3;
          pbVar5 = (byte *)piVar2[2];
          iVar3 = iVar3 + 8;
          bVar1 = *pbVar5;
          piVar2[2] = (int)(pbVar5 + 1);
          uVar15 = uVar15 | (uint)bVar1 << (uVar11 & 0x1f);
        } while (iVar3 < 0x19);
      }
      else {
        do {
          if (*DAT_80186c94 + 0x800U <= (uint)DAT_80186c94[2]) {
            FUN_8017b7e8();
          }
          uVar11 = 0x18 - iVar3;
          iVar3 = iVar3 + 8;
          bVar1 = *(byte *)DAT_80186c94[2];
          DAT_80186c94[2] = (int)((byte *)DAT_80186c94[2] + 1);
          uVar15 = uVar15 | (uint)bVar1 << (uVar11 & 0x1f);
        } while (iVar3 < 0x19);
      }
    }
    piVar2 = DAT_80186c94;
    if (*pbVar14 == 0x40) break;
    uVar11 = uVar15 >> 0x1f;
    if (*pbVar14 == 0x41) {
      DAT_80186c94[4] = iVar3;
      piVar2[3] = uVar15;
      uVar6 = FUN_8017bec8(6);
      uVar7 = FUN_8017bec8(0xc);
      if ((uVar7 & 0x7ff) == 0) {
        DAT_80185780 = 1;
        return;
      }
      uVar11 = (int)uVar7 < 0x800 ^ 1;
      if (uVar11 != 0) {
        uVar7 = 0x1000 - uVar7;
      }
      iVar3 = DAT_80186c94[4];
      uVar15 = DAT_80186c94[3];
    }
    else {
      uVar15 = uVar15 << 1;
      iVar3 = iVar3 + -1;
      uVar6 = (uint)*pbVar14;
      uVar7 = (uint)pbVar14[1];
    }
    if (piVar17[0x10a] == 0) {
      puVar8 = &DAT_801854a0;
    }
    else {
      puVar8 = &DAT_801854e0;
    }
    psVar10 = (short *)((int)(piVar17 + param_1 * 0x20 + 0x10e) +
                       (uint)(byte)puVar8[iVar16 + uVar6] * 2);
    sVar12 = (short)((int)(uVar7 * piVar17[0x10d] * piVar13[(byte)puVar8[iVar16 + uVar6]]) >> 4);
    *psVar10 = sVar12;
    if (uVar11 != 0) {
      *psVar10 = -sVar12;
    }
    iVar16 = iVar16 + uVar6 + 1;
  }
  DAT_80186c94[4] = iVar3;
  piVar2[3] = uVar15;
  return;
}
