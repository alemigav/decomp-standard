/* FUN_80083f88
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083f88  body 0x80083f88..0x8008441f  size 1176 B
 * body sha256 b056fd9a68c84518a65487514d5c2f5739d6a404d7a6d58426bb08e90c12aeb7
 * provider record sha256 717dbe827e6d48f558153b8d6a55b42fff4bd106d696249cfa9e1f11a76b4cf0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80083f88(void)

{
  byte bVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  float fVar14;
  
  iVar8 = 0;
  uVar13 = 0;
  uVar12 = 0xbf800000;
  while (iVar8 < 4) {
    iVar3 = 0;
    if (iVar8 != 3) {
      iVar3 = iVar8 + 1;
    }
    iVar4 = DAT_800df940 + iVar8 * 4;
    iVar3 = DAT_800df940 + iVar3 * 4;
    iVar6 = (int)*(short *)(iVar3 + 4);
    iVar3 = (int)*(short *)(iVar3 + 6);
    fVar9 = (float)DAT_801315d8;
    FUN_80083e80((float)(int)*(short *)(iVar4 + 4),(float)(int)*(short *)(iVar4 + 6),iVar3,iVar6,
                 (float)iVar6,(float)iVar3,(float)DAT_801315d0,fVar9);
    if (((float)uVar12 == -1.0) || (fVar9 < (float)uVar12)) {
      uVar12 = (ulonglong)(uint)fVar9;
      iVar8 = iVar8 + 1;
    }
    else {
      iVar8 = iVar8 + 1;
    }
  }
  fVar9 = (float)uVar12 / 1e+06;
  for (puVar7 = &DAT_800e13f0; fVar14 = (float)uVar13, puVar7 != DAT_800df93c; puVar7 = puVar7 + 1)
  {
    puVar5 = (uint *)*puVar7;
    bVar1 = *(byte *)(puVar5 + 2);
    if (bVar1 != 0) {
      if (bVar1 < 0x11) {
        iVar8 = 0;
      }
      else {
        iVar8 = 0;
        if (bVar1 < 0x40) {
          iVar8 = *(byte *)(puVar5 + 2) - 0x10;
        }
      }
      if ((*puVar5 & 2) == 0) {
        uVar13 = (ulonglong)(uint)(fVar14 + *(float *)(&DAT_8011c6bc + iVar8 * 8));
      }
      else {
        uVar13 = (ulonglong)(uint)(fVar14 + (float)(&DAT_8011c6b8)[iVar8 * 2]);
      }
    }
  }
  iVar8 = (DAT_801315e0 - DAT_801315d4) * (DAT_801315e0 - DAT_801315d4);
  iVar3 = (DAT_801315dc - DAT_801315d0) * (DAT_801315dc - DAT_801315d0);
  iVar4 = (DAT_801315e4 - DAT_801315d8) * (DAT_801315e4 - DAT_801315d8);
  fVar11 = (float)iVar8;
  if (iVar8 < 0) {
    fVar11 = fVar11 + 4.2949673e+09;
  }
  fVar10 = (float)iVar3;
  if (iVar3 < 0) {
    fVar10 = fVar10 + 4.2949673e+09;
  }
  fVar2 = (float)iVar4;
  if (iVar4 < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  fVar11 = (fVar11 / (fVar10 + fVar2)) * 1000.0;
  if (fVar11 < 2.25) {
    fVar10 = 0.9;
  }
  else if (fVar11 < 16.0) {
    fVar10 = 0.75;
  }
  else {
    fVar10 = 0.45;
    if (fVar11 < 100.0) {
      fVar10 = 0.55;
    }
  }
  if (DAT_801315e0 < DAT_801315d4) {
    fVar10 = fVar10 * 1.25;
  }
  if (1.25 <= fVar9) {
    if (2.5 <= fVar9) {
      if (4.0 <= fVar9) {
        if (9.0 <= fVar9) {
          if (64.0 <= fVar9) {
            if (fVar9 < 144.0) {
              fVar10 = fVar10 + 0.1;
            }
          }
          else {
            fVar10 = fVar10 + 0.15;
          }
        }
        else {
          fVar10 = fVar10 + 0.2;
        }
      }
      else {
        fVar10 = fVar10 + 0.25;
      }
    }
    else {
      fVar10 = fVar10 + 0.3;
    }
  }
  else {
    fVar10 = fVar10 + 0.35;
  }
  iVar8 = 0x14 - (int)(fVar10 * fVar14);
  if (*(int *)((&PTR_PTR_8011c69c)[DAT_800e8ca8] + DAT_800e8caa * 4) != 0) {
    iVar8 = iVar8 - *(char *)(*(int *)((&PTR_PTR_8011c69c)[DAT_800e8ca8] + DAT_800e8caa * 4) +
                             (int)DAT_800e8cac);
  }
  if ((DAT_800e110c & 0x80000) != 0) {
    iVar8 = iVar8 + -5;
  }
  if ((DAT_800e10ec & 9) != 0) {
    iVar8 = iVar8 + -5;
  }
  if ((DAT_800e110c & 0x10) == 0) {
    iVar8 = iVar8 - (uint)(byte)(&DAT_8011c838)[DAT_8012bfa2];
  }
  else {
    iVar8 = iVar8 + -6;
  }
  if (iVar8 < 1) {
    iVar8 = 1;
  }
  else if (0x14 < iVar8) {
    iVar8 = 0x14;
  }
  return iVar8;
}
