/* FUN_8009202c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009202c  body 0x8009202c..0x800924bb  size 1168 B
 * body sha256 9668635340cbce9d3fc307ca43f7d050b7e1eca5565fa5ac747b2095a38e3b36
 * provider record sha256 ac20a2d7ea23769d44092b81be0172fda6584e77955e8fca62c9bfc89e61d1ea
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009202c(void)

{
  undefined1 uVar1;
  byte bVar2;
  char cVar4;
  uint uVar3;
  undefined4 uVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  short sVar12;
  undefined1 *puVar11;
  undefined1 *puVar10;
  int iVar13;
  uint uVar14;
  short *psVar15;
  undefined *puVar16;
  
  iVar9 = DAT_800c52dc;
  sVar7 = 0x40;
  if (DAT_8012bfc1 == '\0') {
    cVar4 = DAT_8012bfc0 + 4;
    if (0x50 < DAT_8012bfc0) {
      DAT_8012bfc1 = '\x01';
      cVar4 = DAT_8012bfc0 + 4;
    }
  }
  else {
    if (DAT_8012bfc0 < 10) {
      FUN_80077adc(0x22b0000,0);
      DAT_8012bfc1 = '\0';
    }
    cVar4 = DAT_8012bfc0 - 4;
  }
  iVar13 = 2;
  sVar12 = 0x1a;
  sVar6 = 0x1ea;
  DAT_8012bfc0 = cVar4;
  uVar3 = FUN_80091a70(DAT_8012bfb2,(&DAT_8012fa24)[DAT_8012f522]);
  puVar16 = (&PTR_DAT_80130cb4)[(uint)DAT_8012bfb2 * 2];
  iVar9 = iVar9 + 0x40878;
  do {
    iVar8 = iVar9;
    sVar12 = sVar12 + -5;
    sVar6 = sVar6 + -0xf0;
    iVar13 = iVar13 + -1;
    FUN_800478b8(iVar8,sVar6,sVar12);
    iVar9 = iVar8 + 0x28;
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar8,0,0);
  } while (iVar13 != 0);
  uVar14 = (uint)(byte)(&DAT_80130cb8)[(uint)DAT_8012bfb2 * 8];
  psVar15 = (short *)(iVar8 + 0x32);
  puVar11 = puVar16 + uVar14 * 0x10;
  do {
    puVar10 = puVar11 + -0x10;
    uVar14 = uVar14 - 1;
    FUN_800478b8(iVar9,*(short *)(puVar11 + -0xc) + DAT_8012bff0,
                 *(short *)(puVar11 + -10) + DAT_8012bff2);
    if ((DAT_8012bfb2 == 2) && (uVar14 == 0xe)) {
      if (DAT_800e8caa == 0xe) {
        iVar13 = FUN_800837ac(&DAT_800e8dac,8);
        if (iVar13 != 0) {
          iVar13 = FUN_800837ac(&DAT_800e8dac,0xc);
          if (iVar13 == 0) {
            uVar1 = puVar16[0xe0];
            uVar5 = 0x98;
            sVar7 = 0x1a0;
          }
          else {
            uVar1 = puVar16[0xe0];
            uVar5 = 0x50;
            sVar7 = 0x120;
          }
          FUN_800478ac(iVar9,uVar1,uVar5);
        }
        iVar13 = FUN_800837ac(&DAT_800e8dac,9);
        if (iVar13 != 0) {
          iVar13 = FUN_800837ac(&DAT_800e8dac,0xb);
          if (iVar13 == 0) {
            sVar7 = 0x1a0;
            FUN_800478ac(iVar9,*puVar10,0x50);
          }
          else {
            sVar7 = 0x120;
            FUN_800478ac(iVar9,*puVar10,0x98);
          }
        }
      }
      else {
        iVar13 = FUN_800837ac(&DAT_800e8d98,0x2c);
        if (iVar13 == 0) goto LAB_80092454;
        iVar13 = FUN_800837ac(&DAT_800e8dac,0xb);
        if (iVar13 == 0) {
          sVar7 = 0x20;
          FUN_800478ac(iVar9,puVar16[0xe0],0x50);
          iVar13 = FUN_800837ac(&DAT_800e8dac,0xc);
          if (iVar13 != 0) {
            sVar7 = 0x180;
          }
        }
        else {
          sVar7 = 0x180;
          FUN_800478ac(iVar9,puVar16[0xe0],0x98);
          iVar13 = FUN_800837ac(&DAT_800e8dac,0xc);
          if (iVar13 != 0) {
            sVar7 = 0x80;
          }
        }
      }
LAB_80092428:
      *psVar15 = sVar7;
      DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar9,0,0);
    }
    else {
      sVar7 = 0x80;
      iVar13 = FUN_800837ac(&DAT_800e8dac,puVar11[-3]);
      if (iVar13 != 0) {
        sVar7 = 0x120;
      }
      if (uVar14 == uVar3) {
        if (DAT_8012bfc1 == '\0') {
          sVar7 = sVar7 + 0x20;
        }
        else {
          uVar1 = puVar11[-3];
LAB_800923f8:
          sVar7 = 0x20;
          iVar13 = FUN_800837ac(&DAT_800e8dac,uVar1);
          if (iVar13 != 0) {
            sVar7 = 0xc0;
          }
        }
        goto LAB_80092428;
      }
      iVar13 = FUN_800837ac(&DAT_800e8db0,(&DAT_80130cb9)[(uint)DAT_8012bfb2 * 8]);
      if (iVar13 == 0) {
        iVar13 = FUN_800837ac(&DAT_800e8d98,puVar11[-4]);
        if (iVar13 != 0) goto LAB_80092428;
      }
      else {
        iVar13 = FUN_800837ac(&DAT_800e8d98,puVar11[-4]);
        if (iVar13 != 0) goto LAB_80092428;
        if ((DAT_800e1138 & 1) == 0) {
          bVar2 = puVar11[-2];
        }
        else {
          bVar2 = puVar11[-1];
        }
        if ((((bVar2 & 1) == 0) || ((DAT_800e110c & 0x40000000) != 0)) &&
           (((bVar2 & 2) == 0 || ((DAT_800e110c & 0x40000000) == 0)))) {
          uVar1 = puVar11[-3];
          goto LAB_800923f8;
        }
      }
    }
LAB_80092454:
    psVar15 = psVar15 + 0x14;
    iVar9 = iVar9 + 0x28;
    puVar11 = puVar10;
    if (uVar14 == 0) {
      if ((DAT_800e110c & 0x2000000) == 0) {
        FUN_80090ca0();
      }
      return;
    }
  } while( true );
}
