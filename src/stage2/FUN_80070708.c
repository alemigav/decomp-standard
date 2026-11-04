/* FUN_80070708
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80070708  body 0x80070708..0x80071177  size 2672 B
 * body sha256 cac2701a67342a42c8f33ab967fe16ac59c602320d14d3a14984177c56913ae4
 * provider record sha256 3fdd489e54c1da6032e2fc59736593e489514bec0e207072ff7e0adf24c2e24d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80070708(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  double dVar11;
  double dVar12;
  float fVar13;
  float fVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  undefined8 uVar19;
  float fVar20;
  
  uVar3 = DAT_800f9e30;
  if ((DAT_800e8ca8 != 0) && (_DAT_800e8ca8 != 0x10000)) {
    if (DAT_800e1138 - 0xe < 2) {
      DAT_80115124 = (uint)DAT_800e1138;
    }
    else {
      iVar9 = 0;
      if (1 < DAT_80115124 - 0xe) {
        uVar8 = 0;
        dVar18 = 32767.0;
        uVar19 = 0;
        dVar17 = 0.5;
        dVar15 = 0.0;
        dVar16 = 1.0;
        uVar10 = (uint)DAT_800e8604;
        DAT_80115124 = (uint)DAT_800e1138;
        iVar2 = DAT_800e110c >> 0x1f;
switchD_800708c8_caseD_17:
        bVar1 = uVar8 < uVar10;
        goto switchD_800708c8_default;
      }
      DAT_80115124 = (uint)DAT_800e1138;
    }
  }
  return;
switchD_800708c8_default:
  if (!bVar1) {
    DAT_800f9e30 = uVar3;
    return;
  }
  pcVar6 = (char *)(&DAT_800dfb60)[iVar9];
  iVar9 = iVar9 + 1;
  if ((pcVar6 == (char *)0x0) || (uVar8 = uVar8 + 1, *pcVar6 != '\x02'))
  goto switchD_800708c8_caseD_17;
  iVar4 = *(int *)(&DAT_80129e50 + (uint)(DAT_800e9012 >> 4) * 4) * (uint)*(ushort *)(pcVar6 + 0x10)
          * 0x41c64e6d + 0x3039;
  bVar1 = uVar8 < uVar10;
  fVar20 = (float)uVar19;
  switch(*(undefined2 *)(pcVar6 + 0xc)) {
  case 0x14:
    DAT_800f9e30 = iVar4 * 0x41c64e6d + 0x3039;
    fVar13 = (float)(((double)((DAT_800f9e30 >> 0x10 & 0x7fffU) % 0x7fff) / dVar18) * 15.0 + 15.0);
    fVar14 = fVar13;
    if (fVar13 < fVar20) {
      fVar14 = -fVar13;
    }
    fVar14 = fVar14 - (float)(int)fVar14;
    dVar12 = (double)fVar14;
    dVar11 = (double)fVar13;
    if (dVar17 < dVar12) {
      if (dVar11 <= dVar15) {
        fVar13 = fVar13 - fVar14;
        break;
      }
      dVar11 = dVar11 + (dVar16 - dVar12);
    }
    else {
LAB_8007098c:
      if (dVar15 <= dVar11) {
        fVar13 = fVar13 - fVar14;
        break;
      }
LAB_80070d68:
      dVar11 = dVar11 - (dVar16 - dVar12);
    }
LAB_80070d6c:
    fVar13 = (float)dVar11;
    break;
  case 0x15:
    DAT_800f9e30 = iVar4 * 0x41c64e6d + 0x3039;
    fVar13 = (float)(((double)((DAT_800f9e30 >> 0x10 & 0x7fffU) % 0x7fff) / dVar18) * 7.0 + 7.0);
    fVar14 = fVar13;
    if (fVar13 < fVar20) {
      fVar14 = -fVar13;
    }
    fVar14 = fVar14 - (float)(int)fVar14;
    dVar12 = (double)fVar14;
    dVar11 = (double)fVar13;
    if (dVar12 <= dVar17) goto LAB_8007098c;
    if (dVar15 < dVar11) {
      dVar11 = dVar11 + (dVar16 - dVar12);
      goto LAB_80070d6c;
    }
    fVar13 = fVar13 - fVar14;
    break;
  case 0x16:
    DAT_800f9e30 = iVar4 * 0x41c64e6d + 0x3039;
    fVar13 = (float)(((double)((DAT_800f9e30 >> 0x10 & 0x7fffU) % 0x7fff) / dVar18) * 8.0 + 8.0);
    fVar14 = fVar13;
    if (fVar13 < fVar20) {
      fVar14 = -fVar13;
    }
    fVar14 = fVar14 - (float)(int)fVar14;
    dVar12 = (double)fVar14;
    dVar11 = (double)fVar13;
    if (dVar12 <= dVar17) goto LAB_8007098c;
    if (dVar15 < dVar11) {
      dVar11 = dVar11 + (dVar16 - dVar12);
      goto LAB_80070d6c;
    }
    fVar13 = fVar13 - fVar14;
    break;
  case 0x17:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x24:
  case 0x25:
    goto switchD_800708c8_caseD_17;
  case 0x18:
    DAT_800f9e30 = iVar4 * 0x41c64e6d + 0x3039;
    fVar13 = (float)(((double)((DAT_800f9e30 >> 0x10 & 0x7fffU) % 0x7fff) / dVar18) * 6.0 + 6.0);
    fVar14 = fVar13;
    if (fVar13 < fVar20) {
      fVar14 = -fVar13;
    }
    fVar14 = fVar14 - (float)(int)fVar14;
    dVar12 = (double)fVar14;
    dVar11 = (double)fVar13;
    if (dVar17 < dVar12) {
      if (dVar15 < dVar11) {
        dVar11 = dVar11 + (dVar16 - dVar12);
        goto LAB_80070d6c;
      }
      fVar13 = fVar13 - fVar14;
    }
    else {
      if (dVar11 < dVar15) goto LAB_80070d68;
      fVar13 = fVar13 - fVar14;
    }
    break;
  case 0x19:
    DAT_800f9e30 = iVar4 * 0x41c64e6d + 0x3039;
    fVar13 = (float)(((double)((DAT_800f9e30 >> 0x10 & 0x7fffU) % 0x7fff) / dVar18) * 6.0 + 6.0);
    fVar14 = fVar13;
    if (fVar13 < fVar20) {
      fVar14 = -fVar13;
    }
    fVar14 = fVar14 - (float)(int)fVar14;
    dVar12 = (double)fVar14;
    dVar11 = (double)fVar13;
    if (dVar12 <= dVar17) goto LAB_8007098c;
    if (dVar15 < dVar11) {
      dVar11 = dVar11 + (dVar16 - dVar12);
      goto LAB_80070d6c;
    }
    fVar13 = fVar13 - fVar14;
    break;
  case 0x1d:
    DAT_800f9e30 = iVar4 * 0x41c64e6d + 0x3039;
    fVar13 = (float)(((double)((DAT_800f9e30 >> 0x10 & 0x7fffU) % 0x7fff) / dVar18) * 36.0 + 36.0);
    fVar14 = fVar13;
    if (fVar13 < fVar20) {
      fVar14 = -fVar13;
    }
    fVar14 = fVar14 - (float)(int)fVar14;
    dVar12 = (double)fVar14;
    dVar11 = (double)fVar13;
    if (dVar12 <= dVar17) goto LAB_8007098c;
    if (dVar15 < dVar11) {
      dVar11 = dVar11 + (dVar16 - dVar12);
      goto LAB_80070d6c;
    }
    fVar13 = fVar13 - fVar14;
    break;
  case 0x23:
  case 0x26:
  case 0x27:
  case 0x28:
    DAT_800f9e30 = iVar4 * 0x41c64e6d + 0x3039;
    fVar13 = (float)(((double)((DAT_800f9e30 >> 0x10 & 0x7fffU) % 0x7fff) / dVar18) * 7.0 + dVar15);
    fVar14 = fVar13;
    if (fVar13 < fVar20) {
      fVar14 = -fVar13;
    }
    fVar14 = fVar14 - (float)(int)fVar14;
    dVar12 = (double)fVar14;
    dVar11 = (double)fVar13;
    if (dVar17 < dVar12) {
      if (dVar15 < dVar11) {
        dVar11 = dVar11 + (dVar16 - dVar12);
        goto LAB_80070f70;
      }
      fVar13 = fVar13 - fVar14;
    }
    else if (dVar15 <= dVar11) {
      fVar13 = fVar13 - fVar14;
    }
    else {
      dVar11 = dVar11 - (dVar16 - dVar12);
LAB_80070f70:
      fVar13 = (float)dVar11;
    }
    pbVar7 = (byte *)(*(int *)((&PTR_PTR_80129e44)[-iVar2] + 4) + (int)fVar13 * 2);
    bVar1 = uVar8 < uVar10;
    if (pbVar7 != (byte *)0x0) {
      if (*pbVar7 == 0x14) {
        DAT_800f9e30 = DAT_800f9e30 * 0x41c64e6d + 0x3039;
        fVar13 = (float)(((double)((DAT_800f9e30 >> 0x10 & 0x7fffU) % 0x7fff) / dVar18) * 15.0 +
                        15.0);
        fVar14 = fVar13;
        if (fVar13 < fVar20) {
          fVar14 = -fVar13;
        }
        fVar14 = fVar14 - (float)(int)fVar14;
        dVar12 = (double)fVar14;
        dVar11 = (double)fVar13;
        if (dVar17 < dVar12) {
          if (dVar15 < dVar11) {
            dVar11 = dVar11 + (dVar16 - dVar12);
            goto LAB_80071084;
          }
          fVar13 = fVar13 - fVar14;
        }
        else if (dVar15 <= dVar11) {
          fVar13 = fVar13 - fVar14;
        }
        else {
          dVar11 = dVar11 - (dVar16 - dVar12);
LAB_80071084:
          fVar13 = (float)dVar11;
        }
        *(short *)(pcVar6 + 0xe) = (short)(int)fVar13;
      }
      goto LAB_80071094;
    }
  default:
    goto switchD_800708c8_default;
  }
  *(short *)(pcVar6 + 0xe) = (short)(int)fVar13;
  DAT_800f9e30 = DAT_800f9e30 * 0x41c64e6d + 0x3039;
  fVar13 = (float)(((double)((DAT_800f9e30 >> 0x10 & 0x7fffU) % 0x7fff) / dVar18) * 9.0 + dVar15);
  fVar14 = fVar13;
  if (fVar13 < fVar20) {
    fVar14 = -fVar13;
  }
  fVar14 = fVar14 - (float)(int)fVar14;
  dVar12 = (double)fVar14;
  dVar11 = (double)fVar13;
  if (dVar17 < dVar12) {
    if (dVar15 < dVar11) {
      dVar11 = dVar11 + (dVar16 - dVar12);
      goto LAB_80070e54;
    }
    fVar13 = fVar13 - fVar14;
  }
  else if (dVar15 <= dVar11) {
    fVar13 = fVar13 - fVar14;
  }
  else {
    dVar11 = dVar11 - (dVar16 - dVar12);
LAB_80070e54:
    fVar13 = (float)dVar11;
  }
  pbVar7 = (byte *)(*(int *)(&PTR_PTR_80129e44)[-iVar2] + (int)fVar13 * 2);
  bVar1 = uVar8 < uVar10;
  if (pbVar7 != (byte *)0x0) {
    if (*pbVar7 == 0x26) {
      pcVar6[0xe] = '\0';
      pcVar6[0xf] = '\x01';
    }
LAB_80071094:
    bVar1 = uVar8 < uVar10;
    if (pbVar7 != (byte *)0x0) {
      uVar5 = (uint)(byte)pcVar6[0x12];
      *(ushort *)(pcVar6 + 0xc) = (ushort)*pbVar7;
      bVar1 = uVar8 < uVar10;
      if (uVar5 < 0x20) {
        if (DAT_80113894 == 0) {
          bVar1 = uVar8 < uVar10;
        }
        else {
          bVar1 = uVar8 < uVar10;
          if ((&DAT_800e19bc)[uVar5 * 0xda] != 0) {
            FUN_8004f9f0(uVar5,DAT_80113894 + (uint)pbVar7[1] * 0xb0 + 8);
            bVar1 = uVar8 < uVar10;
          }
        }
      }
    }
  }
  goto switchD_800708c8_default;
}
