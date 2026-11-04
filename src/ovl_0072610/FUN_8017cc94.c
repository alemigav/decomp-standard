/* FUN_8017cc94
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017cc94  body 0x8017cc94..0x8017d0e3  size 1104 B
 * body sha256 e7f46013c6612fc9b9b827f3076a63dee703cb938b118a8d7a9c7577b7f4e96e
 * provider record sha256 ee815a10ad6ea43ec4c5847f1f22d6fe98e9f67775f53e53216efe0241b3ac9b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8017cd28) */
/* WARNING: Removing unreachable block (ram,0x8017cd08) */
/* WARNING: Removing unreachable block (ram,0x8017cd18) */
/* WARNING: Removing unreachable block (ram,0x8017cd30) */
/* WARNING: Removing unreachable block (ram,0x8017d084) */
/* WARNING: Removing unreachable block (ram,0x8017d08c) */
/* WARNING: Removing unreachable block (ram,0x8017d094) */

void FUN_8017cc94(int param_1)

{
  byte bVar1;
  int *piVar2;
  undefined *puVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  int iVar8;
  short sVar9;
  uint uVar10;
  short *psVar11;
  byte *pbVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  
  piVar16 = DAT_80186c94;
  if (DAT_80186c94[0x108] == 1) {
    piVar16 = (int *)&DAT_80185824;
  }
  piVar17 = piVar16 + 0x47;
  if ((3 < param_1) && (piVar17 = piVar16 + 199, DAT_8018575c == 1)) {
    piVar17 = piVar16 + 0x47;
  }
  iVar15 = 0;
  iVar14 = DAT_80186c94[4];
  uVar13 = DAT_80186c94[3];
  while( true ) {
    piVar2 = DAT_80186c94;
    uVar10 = uVar13 >> 0x10;
    if (uVar10 < 0x4000) {
      if (uVar10 < 0x400) {
        if (uVar10 < 0x200) {
          if (uVar10 < 0x100) {
            if (uVar10 < 0x80) {
              if (uVar10 < 0x40) {
                if (uVar10 < 0x20) {
                  if (uVar10 < 0x10) {
                    DAT_80185780 = 1;
                    return;
                  }
                  iVar8 = uVar10 * 3;
                  puVar3 = &DAT_801853fc;
                }
                else {
                  iVar8 = (uVar13 >> 0x11) * 3;
                  puVar3 = &UNK_801853cc;
                }
              }
              else {
                iVar8 = (uVar13 >> 0x12) * 3;
                puVar3 = &UNK_8018539c;
              }
            }
            else {
              iVar8 = (uVar13 >> 0x13) * 3;
              puVar3 = &UNK_8018536c;
            }
          }
          else {
            iVar8 = (uVar13 >> 0x14) * 3;
            puVar3 = &UNK_8018533c;
          }
        }
        else {
          iVar8 = (uVar13 >> 0x16) * 3;
          puVar3 = &UNK_80185324;
        }
      }
      else {
        iVar8 = (uVar13 >> 0x18) * 3;
        puVar3 = &DAT_80184f88;
      }
      pbVar12 = puVar3 + iVar8;
    }
    else if (iVar15 == 0) {
      pbVar12 = &DAT_80184f40 + (uVar13 >> 0x1c) * 3;
    }
    else {
      pbVar12 = &DAT_80184f64 + (uVar13 >> 0x1c) * 3;
    }
    uVar13 = uVar13 << (pbVar12[2] & 0x1f);
    iVar14 = iVar14 - (uint)pbVar12[2];
    if (iVar14 < 0x19) {
      if ((uint)DAT_80186c94[2] < *DAT_80186c94 + 0x7fcU) {
        do {
          uVar10 = 0x18 - iVar14;
          pbVar4 = (byte *)piVar2[2];
          iVar14 = iVar14 + 8;
          bVar1 = *pbVar4;
          piVar2[2] = (int)(pbVar4 + 1);
          uVar13 = uVar13 | (uint)bVar1 << (uVar10 & 0x1f);
        } while (iVar14 < 0x19);
      }
      else {
        do {
          if (*DAT_80186c94 + 0x800U <= (uint)DAT_80186c94[2]) {
            FUN_8017b7e8();
          }
          uVar10 = 0x18 - iVar14;
          iVar14 = iVar14 + 8;
          bVar1 = *(byte *)DAT_80186c94[2];
          DAT_80186c94[2] = (int)((byte *)DAT_80186c94[2] + 1);
          uVar13 = uVar13 | (uint)bVar1 << (uVar10 & 0x1f);
        } while (iVar14 < 0x19);
      }
    }
    piVar2 = DAT_80186c94;
    if (*pbVar12 == 0x40) break;
    uVar10 = uVar13 >> 0x1f;
    if (*pbVar12 == 0x41) {
      DAT_80186c94[4] = iVar14;
      piVar2[3] = uVar13;
      uVar5 = FUN_8017bec8(6);
      uVar6 = FUN_8017bec8(0xc);
      if ((uVar6 & 0x7ff) == 0) {
        DAT_80185780 = 1;
        return;
      }
      uVar10 = (int)uVar6 < 0x800 ^ 1;
      if (uVar10 != 0) {
        uVar6 = 0x1000 - uVar6;
      }
      iVar14 = DAT_80186c94[4];
      uVar13 = DAT_80186c94[3];
    }
    else {
      uVar13 = uVar13 << 1;
      iVar14 = iVar14 + -1;
      uVar5 = (uint)*pbVar12;
      uVar6 = (uint)pbVar12[1];
    }
    if (piVar16[0x10a] == 0) {
      puVar7 = &DAT_801854a0;
    }
    else {
      puVar7 = &DAT_801854e0;
    }
    psVar11 = (short *)((int)piVar16 +
                       (uint)(byte)puVar7[iVar15 + uVar5] * 2 + param_1 * 0x80 + 0x438);
    sVar9 = (short)((int)((uVar6 * 2 + 1) * piVar16[0x10d] * piVar17[(byte)puVar7[iVar15 + uVar5]])
                   >> 5);
    *psVar11 = sVar9;
    if (uVar10 != 0) {
      *psVar11 = -sVar9;
    }
    iVar15 = iVar15 + uVar5 + 1;
  }
  DAT_80186c94[4] = iVar14;
  piVar2[3] = uVar13;
  return;
}
