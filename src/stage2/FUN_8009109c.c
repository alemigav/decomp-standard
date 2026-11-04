/* FUN_8009109c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009109c  body 0x8009109c..0x80091737  size 1692 B
 * body sha256 0ee2797da945d233282e59bebd54689df06265f52cebb601dc7adf99c27e9d1e
 * provider record sha256 5378a027de9bc1cdc0cbf21cfbadf76555ec52fa769e74ca478ff8ee52cf629b
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009109c(void)

{
  undefined1 uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  char cVar6;
  undefined4 uVar7;
  short sVar10;
  undefined1 *puVar9;
  undefined1 *puVar8;
  short sVar11;
  int iVar12;
  short sVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  short *psVar17;
  undefined *puVar18;
  
  FUN_80043620();
  iVar15 = DAT_800c52dc;
  iVar14 = 2;
  sVar13 = 0x40;
  uVar3 = FUN_80091738((int)DAT_800e8ca8,(int)DAT_800e8caa);
  iVar12 = iVar15 + 0x40828;
  uVar4 = FUN_80091a70(DAT_8012bfb2,(int)DAT_800e8caa);
  puVar18 = (&PTR_DAT_80130cb4)[(uint)DAT_8012bfb2 * 2];
  if (DAT_8012bfb2 < 2) {
    iVar12 = iVar15 + 0x40878;
  }
  else {
    sVar10 = 0x198;
    do {
      sVar10 = sVar10 + -0xc2;
      FUN_800478b8(iVar12,0x98,sVar10);
      iVar14 = iVar14 + -1;
      if (DAT_8012bfc1 == '\0') {
        uVar7 = 0x80;
      }
      else {
        uVar7 = 0x40;
      }
      FUN_8004786c(iVar12,uVar7,uVar7,uVar7);
      if (iVar14 == 0) {
        pbVar5 = &DAT_8012f970 + DAT_8012bfb2;
      }
      else {
        pbVar5 = &LAB_8012f988 + DAT_8012bfb2;
      }
      if ((1 < *pbVar5) && (iVar15 = FUN_800837ac(&DAT_800e8d94,*pbVar5), iVar15 != 0)) {
        DAT_800df8b8 = FUN_80043988(DAT_800df8b8,iVar12,0,0);
      }
      iVar12 = iVar12 + 0x28;
    } while (iVar14 != 0);
  }
  iVar15 = 2;
  sVar11 = 0x1a;
  sVar10 = 0x1ea;
  do {
    iVar14 = iVar12;
    sVar11 = sVar11 + -5;
    sVar10 = sVar10 + -0xf0;
    iVar15 = iVar15 + -1;
    FUN_800478b8(iVar14,sVar10,sVar11);
    iVar12 = iVar14 + 0x28;
    DAT_800df8b8 = FUN_80043988(DAT_800df8b8,iVar14,0,0);
  } while (iVar15 != 0);
  uVar16 = (uint)(byte)(&DAT_80130cb8)[(uint)DAT_8012bfb2 * 8];
  psVar17 = (short *)(iVar14 + 0x32);
  puVar9 = puVar18 + uVar16 * 0x10;
  do {
    puVar8 = puVar9 + -0x10;
    uVar16 = uVar16 - 1;
    FUN_800478b8(iVar12,*(short *)(puVar9 + -0xc) + DAT_8012bff0,
                 *(short *)(puVar9 + -10) + DAT_8012bff2);
    if ((DAT_8012bfb2 == 2) && (uVar16 == 0xe)) {
      if (DAT_800e8caa == 0xe) {
        iVar15 = FUN_800837ac(&DAT_800e8dac,8);
        if (iVar15 != 0) {
          iVar15 = FUN_800837ac(&DAT_800e8dac,0xc);
          if (iVar15 == 0) {
            uVar1 = puVar18[0xe0];
            uVar7 = 0x98;
            sVar13 = 0xa0;
          }
          else {
            uVar1 = puVar18[0xe0];
            uVar7 = 0x50;
            sVar13 = 0x120;
          }
          FUN_800478ac(iVar12,uVar1,uVar7);
        }
        iVar15 = FUN_800837ac(&DAT_800e8dac,9);
        if (iVar15 != 0) {
          iVar15 = FUN_800837ac(&DAT_800e8dac,0xb);
          if (iVar15 == 0) {
            sVar13 = 0xa0;
            FUN_800478ac(iVar12,*puVar8,0x50);
          }
          else {
            sVar13 = 0x120;
            FUN_800478ac(iVar12,*puVar8,0x98);
          }
        }
      }
      else {
        iVar15 = FUN_800837ac(&DAT_800e8d98,0x2c);
        if ((iVar15 == 0) &&
           (iVar15 = FUN_800837ac(&DAT_800e8db0,(&DAT_80130cb9)[(uint)DAT_8012bfb2 * 8]),
           iVar15 == 0)) goto LAB_80091568;
        iVar15 = FUN_800837ac(&DAT_800e8dac,0xb);
        if (iVar15 == 0) {
          sVar13 = 0x20;
          FUN_800478ac(iVar12,puVar18[0xe0],0x50);
          iVar15 = FUN_800837ac(&DAT_800e8dac,0xc);
          if (iVar15 != 0) {
            sVar13 = 0x80;
          }
        }
        else {
          sVar13 = 0x80;
          FUN_800478ac(iVar12,puVar18[0xe0],0x98);
          FUN_800837ac(&DAT_800e8dac,0xc);
        }
      }
LAB_8009154c:
      *psVar17 = sVar13;
      DAT_800df8b8 = FUN_80043988(DAT_800df8b8,iVar12,0,0);
    }
    else {
      sVar13 = 0x80;
      iVar15 = FUN_800837ac(&DAT_800e8dac,puVar9[-3]);
      if (iVar15 != 0) {
        sVar13 = 0x120;
      }
      if ((DAT_8012bfb2 == uVar3) && (uVar16 == uVar4)) {
        sVar13 = sVar13 + 0x20;
      }
      iVar15 = FUN_800837ac(&DAT_800e8db0,(&DAT_80130cb9)[(uint)DAT_8012bfb2 * 8]);
      if (iVar15 != 0) {
        iVar15 = FUN_800837ac(&DAT_800e8d98,puVar9[-4]);
        if (iVar15 == 0) {
          if ((DAT_800e1138 & 1) == 0) {
            bVar2 = puVar9[-2];
          }
          else {
            bVar2 = puVar9[-1];
          }
          if ((((bVar2 & 1) != 0) && ((DAT_800e110c & 0x40000000) == 0)) ||
             (((bVar2 & 2) != 0 && ((DAT_800e110c & 0x40000000) != 0)))) goto LAB_80091568;
          sVar13 = 0x20;
          iVar15 = FUN_800837ac(&DAT_800e8dac,puVar9[-3]);
          if (iVar15 != 0) {
            sVar13 = 0xc0;
          }
        }
        goto LAB_8009154c;
      }
      iVar15 = FUN_800837ac(&DAT_800e8d98,puVar9[-4]);
      if (iVar15 != 0) goto LAB_8009154c;
    }
LAB_80091568:
    psVar17 = psVar17 + 0x14;
    iVar12 = iVar12 + 0x28;
    puVar9 = puVar8;
    if (uVar16 == 0) {
      iVar12 = DAT_800c52dc + 0x40800;
      iVar15 = FUN_80091a70(DAT_8012bfb2,(int)DAT_800e8caa);
      puVar18 = (&PTR_DAT_80130cb4)[(uint)DAT_8012bfb2 * 2];
      if (DAT_8012bfb2 == uVar3) {
        DAT_8012bfec = ((short)((ulonglong)((longlong)(DAT_800e1158 + 28000) * 0x91a2b3c5) >> 0x28)
                       - (short)(DAT_800e1158 + 28000 >> 0x1f)) + DAT_8012bff0;
        DAT_8012bfee = DAT_8012bff2 - (short)((DAT_800e1160 + 28000) / 0x1c2);
        FUN_800478ac(iVar12,(DAT_800e1196 + 0x100 >> 9 & 7U) * 0xc,0);
        cVar6 = DAT_8012bfc0 + '(';
        FUN_8004786c(iVar12,cVar6,cVar6,cVar6);
        FUN_800478b8(iVar12,DAT_8012bfec + *(short *)(puVar18 + iVar15 * 0x10 + 8),
                     DAT_8012bfee + *(short *)(puVar18 + iVar15 * 0x10 + 10));
        DAT_800df8b8 = FUN_80043988(DAT_800df8b8,iVar12,0,0);
      }
      if ((DAT_800e110c & 0x2000000) == 0) {
        FUN_80090ca0();
      }
      return;
    }
  } while( true );
}
