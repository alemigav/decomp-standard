/* FUN_8017c38c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017c38c  body 0x8017c38c..0x8017c787  size 1020 B
 * body sha256 dec77be0cb021b346d64f53ab8a32ed055b110fc1ab655ff838e53245d1dd881
 * provider record sha256 ac573f950b62c5fd99be0da454aba2d71a314eee01798d2562f0e6e20d00687b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8017c534) */
/* WARNING: Removing unreachable block (ram,0x8017c54c) */
/* WARNING: Removing unreachable block (ram,0x8017c550) */
/* WARNING: Removing unreachable block (ram,0x8017c568) */
/* WARNING: Removing unreachable block (ram,0x8017c570) */
/* WARNING: Removing unreachable block (ram,0x8017c594) */

void FUN_8017c38c(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  ushort *puVar9;
  byte *pbVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  
  piVar1 = DAT_80186c94;
  iVar14 = 0;
  iVar11 = DAT_80186c94[4];
  uVar12 = DAT_80186c94[3];
  pbVar10 = (byte *)DAT_80186c94[2];
  do {
    uVar8 = uVar12 >> 0x10;
    if (uVar8 < 0x4000) {
      if (uVar8 < 0x400) {
        if (uVar8 < 0x200) {
          if (uVar8 < 0x100) {
            if (uVar8 < 0x80) {
              if (uVar8 < 0x40) {
                if (uVar8 < 0x20) {
                  if (uVar8 < 0x10) {
                    DAT_80185780 = 1;
                    return;
                  }
                  iVar6 = uVar8 * 3;
                  puVar3 = &DAT_801853fc;
                }
                else {
                  iVar6 = (uVar12 >> 0x11) * 3;
                  puVar3 = &UNK_801853cc;
                }
              }
              else {
                iVar6 = (uVar12 >> 0x12) * 3;
                puVar3 = &UNK_8018539c;
              }
            }
            else {
              iVar6 = (uVar12 >> 0x13) * 3;
              puVar3 = &UNK_8018536c;
            }
          }
          else {
            iVar6 = (uVar12 >> 0x14) * 3;
            puVar3 = &UNK_8018533c;
          }
        }
        else {
          iVar6 = (uVar12 >> 0x16) * 3;
          puVar3 = &UNK_80185324;
        }
      }
      else {
        iVar6 = (uVar12 >> 0x18) * 3;
        puVar3 = &DAT_80184f88;
      }
LAB_8017c50c:
      pbVar13 = puVar3 + iVar6;
    }
    else {
      if (iVar14 != 0) {
        iVar6 = (uVar12 >> 0x1c) * 3;
        puVar3 = &DAT_80184f64;
        goto LAB_8017c50c;
      }
      pbVar13 = &DAT_80184f40 + (uVar12 >> 0x1c) * 3;
    }
    uVar12 = uVar12 << (pbVar13[2] & 0x1f);
    iVar11 = iVar11 - (uint)pbVar13[2];
    if (iVar11 < 0x19) {
      if (pbVar10 < (byte *)(*DAT_80186c94 + 0x7fc)) {
        do {
          uVar8 = 0x18 - iVar11;
          iVar11 = iVar11 + 8;
          uVar12 = uVar12 | (uint)*pbVar10 << (uVar8 & 0x1f);
          pbVar10 = pbVar10 + 1;
        } while (iVar11 < 0x19);
      }
      else {
        do {
          if ((byte *)(*DAT_80186c94 + 0x800) <= pbVar10) {
            FUN_8017b7e8();
            pbVar10 = (byte *)DAT_80186c94[2];
          }
          uVar8 = 0x18 - iVar11;
          iVar11 = iVar11 + 8;
          uVar12 = uVar12 | (uint)*pbVar10 << (uVar8 & 0x1f);
          pbVar10 = pbVar10 + 1;
        } while (iVar11 < 0x19);
      }
    }
    piVar2 = DAT_80186c94;
    if (*pbVar13 == 0x40) {
      DAT_80186c94[4] = iVar11;
      piVar2[3] = uVar12;
      piVar2[2] = (int)pbVar10;
      return;
    }
    uVar8 = uVar12 >> 0x1f;
    if (*pbVar13 == 0x41) {
      DAT_80186c94[4] = iVar11;
      piVar2[3] = uVar12;
      piVar2[2] = (int)pbVar10;
      uVar4 = FUN_8017bec8(6);
      uVar5 = FUN_8017bec8(8);
      if (uVar5 == 0) {
        uVar5 = FUN_8017bec8(8);
      }
      else if (uVar5 == 0x80) {
        iVar11 = FUN_8017bec8(8);
        uVar5 = iVar11 - 0x100;
      }
      else if (0x80 < (int)uVar5) {
        uVar5 = uVar5 - 0x100;
      }
      uVar8 = -((int)uVar5 >> 0x1f);
      if (uVar8 != 0) {
        uVar5 = -uVar5;
      }
      iVar11 = DAT_80186c94[4];
      uVar12 = DAT_80186c94[3];
      pbVar10 = (byte *)DAT_80186c94[2];
    }
    else {
      uVar12 = uVar12 << 1;
      iVar11 = iVar11 + -1;
      uVar4 = (uint)*pbVar13;
      uVar5 = (uint)pbVar13[1];
    }
    puVar9 = (ushort *)
             ((int)piVar1 + (uint)(byte)(&DAT_801854a0)[iVar14 + uVar4] * 2 + param_1 * 0x80 + 0x438
             );
    uVar7 = (short)((int)((uVar5 * 2 + 1) * DAT_80186c94[0x10d] *
                         DAT_80186c94[(byte)(&DAT_801854a0)[iVar14 + uVar4] + 0x47]) >> 4) - 1U | 1;
    *puVar9 = uVar7;
    if (uVar8 != 0) {
      *puVar9 = -uVar7;
    }
    iVar14 = iVar14 + uVar4 + 1;
  } while( true );
}
