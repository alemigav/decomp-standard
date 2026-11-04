/* FUN_800635b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800635b0  body 0x800635b0..0x80064fef  size 6720 B
 * body sha256 162759406a84c59fe23eb5fec269b62096a9e938594b49076b6cda0e3473e52f
 * provider record sha256 9cc88f067fce678f62da16c1703bb27a79f9d69893fe764bf8de42c8dff95fac
 * callees 28 direct (28 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80064c3c) */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_800635b0(void)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  short *psVar8;
  uint uVar9;
  undefined **ppuVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  undefined2 *puVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  ushort *puVar21;
  undefined4 *puVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 local_50;
  undefined4 local_4c;
  ushort local_48;
  undefined4 local_44;
  undefined4 local_38;
  undefined4 local_34;
  ushort local_30;
  undefined4 local_2c;
  
  DAT_80112555 = 0;
  DAT_8011253d = 0;
  DAT_8011253e = 0;
  DAT_8011253f = 0;
  DAT_80112540 = 0;
  DAT_80112541 = 0;
  DAT_800e10e8 = 0;
  DAT_800e13b0 = 0;
  DAT_8011253c = 2;
  DAT_800e110c = DAT_800e110c & 0xfff00000;
  DAT_800e1320 = DAT_800e1320 & 63999;
  FUN_80085398(DAT_800c52d8,DAT_800c52d8 + 0xaf800,&DAT_800b925c);
  DAT_80115280 = 0;
  DAT_800df934 = DAT_800df930;
  DAT_800df92c = DAT_800df930;
  (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
  DAT_80112555 = DAT_80112555 + 1;
  if ((DAT_800e10ec & 0x2000000) != 0) {
    while (DAT_8011a378 == 0) {
      FUN_8004cd88(1);
    }
  }
  iVar18 = 0x21;
  FUN_800765e0();
  puVar13 = &DAT_800e13ec;
  DAT_80112555 = DAT_80112555 - 1;
  (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
  DAT_800df93c = &DAT_800e13f0;
  DAT_800e1126 = 0;
  do {
    *puVar13 = &DAT_800e8620;
    iVar18 = iVar18 + -1;
    puVar13 = puVar13 + 1;
  } while (iVar18 != 0);
  puVar13 = &DAT_800c76b0;
  DAT_800e18f2 = 0;
  DAT_800e18f6 = 0;
  DAT_800e85f8 = &DAT_800e18f8;
  uVar19 = 0;
  do {
    puVar13[0x6892] = 0;
    uVar19 = uVar19 + 1;
    puVar13 = puVar13 + 0xda;
  } while (uVar19 < 0x20);
  (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
  if (DAT_800e1138 != DAT_800e8cb8) {
    if ((short)DAT_800e8cb8 < 0xc) {
      if ((DAT_800e8cb8 & 1) == 0) {
        iVar18 = FUN_800837ac(&DAT_800e8eb8,5);
        if (iVar18 != 0) {
          DAT_800e8cb8 = 8;
        }
        iVar18 = FUN_800837ac(&DAT_800e8eb8,0xf);
        if (iVar18 != 0) {
          DAT_800e8cb8 = 10;
        }
      }
      else {
        iVar18 = FUN_800837ac(&DAT_800e8eb8,6);
        if (iVar18 != 0) {
          DAT_800e8cb8 = 9;
        }
      }
    }
    bVar1 = DAT_800e1138;
    DAT_800e1138 = (byte)DAT_800e8cb8;
    FUN_8008be28((int)(short)DAT_800e8cb8);
    FUN_80055574(&DAT_800e1130);
    DAT_800e1134 = 0;
    if (DAT_800e8cb8 - 0xe < 2) {
      DAT_800e8b4a = DAT_800e1322;
      DAT_800e8b3f = DAT_800e13e6;
      DAT_800e8b40 = DAT_800e13e4;
      DAT_800e13e6 = 0;
      DAT_800e13e4 = 0;
      DAT_800e1322 = 0;
    }
    else if (0xb < bVar1) {
      DAT_800e1322 = DAT_800e8b4a;
      DAT_800e13e6 = DAT_800e8b3f;
      DAT_800e13e4 = DAT_800e8b40;
    }
    DAT_8012bfb3 = 1;
    FUN_8007608c((byte)DAT_800e8cb8,1);
  }
  (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
  DAT_80131f0f = '\0';
  FUN_8004cd88();
  DAT_800e1124 = 0xd05;
  (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
  iVar18 = DAT_800df934;
  FUN_80082498(DAT_800df92c,0x19);
  *(int *)(DAT_800df92c + 0x24) = DAT_800df92c + 0x68;
  for (uVar19 = 1; uVar19 < 0x1e; uVar19 = uVar19 + 1) {
  }
  *(undefined2 *)(uVar19 * 0x20 + *(int *)(DAT_800df92c + 0x24)) = 0;
  (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
  iVar5 = func_0x80004cfc(*(undefined2 *)((&PTR_DAT_80129144)[DAT_800e8ca8] + DAT_800e8caa * 2),
                          DAT_800df92c + 0x68,1,&DAT_800b9264);
  iVar6 = iVar5 + 0x60;
  if (iVar5 < 1) {
    puVar15 = (undefined2 *)(DAT_800df92c + 0x68);
    FUN_80082498(iVar18,0x19);
    *(undefined1 *)(DAT_800df92c + 1) = 0;
    bVar1 = *(byte *)(DAT_800df92c + 1);
    while ((bVar1 < 0x10 &&
           (*(short *)((uint)*(byte *)(DAT_800df92c + 1) * 2 + DAT_800e8caa * 0x20 + DAT_800e1064)
            != 8))) {
      *(byte *)(DAT_800df92c + 1) = *(byte *)(DAT_800df92c + 1) + 1;
      bVar1 = *(byte *)(DAT_800df92c + 1);
    }
    *(undefined1 *)(iVar18 + 1) = *(undefined1 *)(DAT_800df92c + 1);
    uVar19 = 0;
    if (*(char *)(DAT_800df92c + 1) != '\0') {
      do {
        iVar6 = 0;
        *puVar15 = 0;
        puVar15[1] = 0x683c;
        puVar7 = puVar15;
        do {
          *(undefined4 *)(puVar7 + 2) = 1000;
          *(undefined4 *)(puVar7 + 8) = 100;
          iVar6 = iVar6 + 1;
          puVar7 = puVar7 + 2;
        } while (iVar6 < 3);
        uVar19 = uVar19 + 1;
        puVar15 = puVar15 + 0x10;
      } while (uVar19 < *(byte *)(DAT_800df92c + 1));
    }
    puVar15[-0x10] = 1;
    iVar6 = (uint)*(byte *)(iVar18 + 1) * 0x20 + 100;
  }
  else {
    *(undefined1 *)(DAT_800df92c + 1) = *(undefined1 *)(iVar5 + DAT_800df92c + 0x67);
  }
  uVar19 = iVar18 + iVar6;
  psVar8 = *(short **)(DAT_800df92c + 0x24);
  iVar18 = 0;
  if (*psVar8 != 1) {
    do {
      psVar8 = psVar8 + 0x10;
      iVar18 = iVar18 + 1;
    } while (*psVar8 != 1);
  }
  if (iVar18 == *(byte *)(DAT_800df92c + 1) - 1) {
    if ((uVar19 & 7) != 0) {
      uVar19 = uVar19 + 7 & 0xfffffff8;
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    iVar18 = func_0x80004cfc(*(undefined2 *)((&PTR_DAT_801294a4)[DAT_800e8ca8] + DAT_800e8caa * 2),
                             uVar19,1,&DAT_800b9268);
    *(uint *)(DAT_800df92c + 0x34) = uVar19;
    if (-1 < iVar18) {
      uVar19 = uVar19 + iVar18;
    }
    if ((uVar19 & 7) != 0) {
      uVar19 = uVar19 + 7 & 0xfffffff8;
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    iVar18 = func_0x80004cfc(*(undefined2 *)((&PTR_DAT_801296e4)[DAT_800e8ca8] + DAT_800e8caa * 2),
                             uVar19,1,&DAT_800b926c);
    *(uint *)(DAT_800df92c + 0x20) = uVar19;
    if (iVar18 < 1) {
      *(undefined4 *)(uVar19 + 4) = 1;
      uVar19 = uVar19 + 0x10;
    }
    else {
      uVar19 = uVar19 + iVar18;
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    if ((uVar19 & 7) != 0) {
      uVar19 = uVar19 + 7 & 0xfffffff8;
    }
    iVar18 = func_0x80004cfc(*(undefined2 *)((&PTR_DAT_80129264)[DAT_800e8ca8] + DAT_800e8caa * 2),
                             uVar19,1,&DAT_800b9270);
    *(uint *)(DAT_800df92c + 0x28) = uVar19;
    if (iVar18 < 1) {
      iVar18 = 0;
      puVar13 = *(undefined4 **)(DAT_800df92c + 0x28);
      for (uVar20 = 0; uVar9 = 0, uVar20 < *(byte *)(DAT_800df92c + 1); uVar20 = uVar20 + 1) {
        puVar15 = (undefined2 *)((int)puVar13 + 0x12);
        do {
          *(undefined1 *)puVar13 = 1;
          *(undefined1 *)((int)puVar15 + -0x11) = 0xff;
          *(char *)(puVar15 + -8) = (char)uVar20;
          *(char *)((int)puVar15 + -0xf) = (char)uVar9;
          puVar15[-7] = 0x9e58;
          puVar15[-6] = 0x9e58;
          puVar15[-5] = 0x9e58;
          puVar15[-4] = 0xadf8;
          puVar15[-3] = 0xadf8;
          puVar15[-2] = 0xadf8;
          puVar15[-1] = 0xadf8;
          *puVar15 = 0x9e58;
          puVar15 = puVar15 + 10;
          puVar13 = puVar13 + 5;
          uVar9 = uVar9 + 1;
          iVar18 = iVar18 + 0x14;
        } while (uVar9 < 2);
      }
      *puVar13 = 0xffffffff;
      iVar18 = iVar18 + 4;
    }
    puVar13 = (undefined4 *)(uVar19 + iVar18);
    uVar19 = (uint)DAT_80112555;
    *(undefined4 **)(DAT_800df92c + 0x2c) = puVar13;
    (&DAT_8011253c)[uVar19] = (&DAT_8011253c)[uVar19] + '\x01';
    iVar18 = func_0x80004cfc(*(undefined2 *)((&PTR_DAT_801295c4)[DAT_800e8ca8] + DAT_800e8caa * 2),
                             puVar13,1,&DAT_800b9274);
    if (iVar18 < 1) {
      iVar18 = 0;
      *(undefined4 **)(DAT_800df92c + 0x2c) = puVar13;
      for (uVar19 = 0; uVar20 = 0, uVar19 < *(byte *)(DAT_800df92c + 1); uVar19 = uVar19 + 1) {
        iVar5 = 0;
        iVar6 = 0;
        *(undefined1 *)(iVar18 + *(int *)(DAT_800df92c + 0x2c)) = 1;
        do {
          *(undefined1 *)(iVar18 + *(int *)(DAT_800df92c + 0x2c) + uVar20 + 1) = 1;
          *(undefined1 *)(iVar18 + *(int *)(DAT_800df92c + 0x2c) + iVar6 + 4) = 0x80;
          *(undefined1 *)(iVar18 + *(int *)(DAT_800df92c + 0x2c) + iVar6 + 5) = 0x80;
          *(undefined1 *)(iVar18 + *(int *)(DAT_800df92c + 0x2c) + iVar6 + 6) = 0x80;
          *(undefined2 *)(iVar18 + *(int *)(DAT_800df92c + 0x2c) + iVar5 + 0x10) = 0x5dc;
          *(undefined2 *)(iVar18 + *(int *)(DAT_800df92c + 0x2c) + iVar5 + 0x12) = 0x5dc;
          *(undefined2 *)(iVar18 + *(int *)(DAT_800df92c + 0x2c) + iVar5 + 0x14) = 0x5dc;
          iVar12 = uVar20 * 2;
          iVar6 = iVar6 + 3;
          *(undefined1 *)(iVar18 + *(int *)(DAT_800df92c + 0x2c) + uVar20 + 0xd) = 0x3f;
          uVar20 = uVar20 + 1;
          *(undefined2 *)(iVar18 + *(int *)(DAT_800df92c + 0x2c) + iVar12 + 0x22) = 2000;
          iVar5 = iVar5 + 6;
        } while (uVar20 < 3);
        puVar13 = puVar13 + 10;
        iVar18 = iVar18 + 0x28;
      }
    }
    else {
      puVar13 = (undefined4 *)((int)puVar13 + iVar18);
    }
    if (((uint)puVar13 & 7) != 0) {
      puVar13 = (undefined4 *)((int)puVar13 + 7U & 0xfffffff8);
    }
    uVar19 = (uint)DAT_80112555;
    *(undefined4 **)(DAT_800df92c + 0x48) = puVar13;
    (&DAT_8011253c)[uVar19] = (&DAT_8011253c)[uVar19] + '\x01';
    iVar18 = func_0x80004cfc(*(undefined2 *)((&PTR_DAT_80129804)[DAT_800e8ca8] + DAT_800e8caa * 2),
                             puVar13,1,"SCD (X)");
    if (iVar18 < 1) {
      *puVar13 = 0x60004;
      puVar13[1] = 0x10001;
      puVar13 = puVar13 + 2;
    }
    else {
      puVar13 = (undefined4 *)((int)puVar13 + iVar18);
    }
    if (((uint)puVar13 & 7) != 0) {
      puVar13 = (undefined4 *)((int)puVar13 + 7U & 0xfffffff8);
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    *(undefined4 **)(DAT_800df92c + 0x4c) = puVar13;
    if ((int)DAT_800e110c < 0) {
      ppuVar10 = &PTR_DAT_80129a44;
    }
    else {
      ppuVar10 = &PTR_DAT_80129924;
    }
    iVar18 = func_0x80004cfc(*(undefined2 *)(ppuVar10[DAT_800e8ca8] + DAT_800e8caa * 2),puVar13,1,
                             &DAT_800b9280);
    if (iVar18 < 1) {
      *puVar13 = 0x60004;
      puVar13[1] = 0x10001;
      puVar13 = puVar13 + 2;
    }
    else {
      puVar13 = (undefined4 *)((int)puVar13 + iVar18);
    }
    if (((uint)puVar13 & 7) != 0) {
      puVar13 = (undefined4 *)((int)puVar13 + 7U & 0xfffffff8);
    }
    iVar18 = 0;
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    for (uVar19 = 0; uVar19 < *(byte *)(DAT_800df92c + 1); uVar19 = uVar19 + 1) {
      sVar2 = *(short *)(uVar19 * 2 + *(int *)((&PTR_PTR_801122e4)[DAT_800e8ca8] + DAT_800e8caa * 4)
                        );
      if (sVar2 == -1) {
        *(undefined4 *)(iVar18 + *(int *)(DAT_800df92c + 0x24) + 0x1c) = 0xffffffff;
      }
      else {
        uVar14 = func_0x80004cfc(sVar2,puVar13,0x80000000,&DAT_800b9284);
        *(undefined4 **)(iVar18 + *(int *)(DAT_800df92c + 0x24) + 0x1c) = puVar13;
        iVar6 = FUN_800632d8(puVar13,uVar14);
        puVar13 = (undefined4 *)((int)puVar13 + iVar6 + 7 & 0xfffffff8);
      }
      iVar18 = iVar18 + 0x20;
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    iVar18 = func_0x80004cfc(*(undefined2 *)((&PTR_DAT_80129384)[DAT_800e8ca8] + DAT_800e8caa * 2),
                             puVar13,1,&DAT_800b9288);
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    *(undefined4 **)(DAT_800df92c + 0x38) = puVar13;
    if (0 < iVar18) {
      puVar13 = (undefined4 *)((int)puVar13 + iVar18);
    }
    if (((uint)puVar13 & 7) != 0) {
      puVar13 = (undefined4 *)((int)puVar13 + 7U & 0xfffffff8);
    }
    if (*(int *)((&PTR_PTR_80111668)[DAT_800e8ca8] + DAT_800e8caa * 4) == 0) {
      *puVar13 = 0xffffffff;
      *(undefined4 **)(DAT_800df92c + 0x50) = puVar13;
      puVar13 = puVar13 + 2;
    }
    else {
      *(int *)(DAT_800df92c + 0x50) = *(int *)((&PTR_PTR_80111668)[DAT_800e8ca8] + DAT_800e8caa * 4)
      ;
    }
    if (((uint)puVar13 & 7) != 0) {
      puVar13 = (undefined4 *)((int)puVar13 + 7U & 0xfffffff8);
    }
    puVar16 = &DAT_80124128;
    psVar8 = &DAT_801124d4;
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    for (uVar19 = 0; uVar19 < 8; uVar19 = uVar19 + 1) {
      if (*psVar8 != -1) {
        iVar18 = func_0x80004cfc(*psVar8,puVar13,0x80000000,&DAT_800b928c);
        uVar23 = puVar13[1];
        uVar24 = puVar13[2];
        uVar14 = puVar13[3];
        *puVar16 = *puVar13;
        puVar16[1] = uVar23;
        puVar16[2] = uVar24;
        puVar16[3] = uVar14;
        uVar14 = puVar13[5];
        uVar23 = puVar13[6];
        puVar16[4] = puVar13[4];
        puVar16[5] = uVar14;
        puVar16[6] = uVar23;
        puVar11 = (undefined4 *)((int)puVar13 + 0x1bU & 0xfffffff8);
        uVar20 = (uint)(puVar16[1] * puVar16[2]) >> 1;
        puVar16[5] = puVar11;
        iVar6 = puVar16[3] * puVar16[4] * 2;
        if (puVar13 + 5 != puVar11) {
          iVar5 = uVar20 + iVar6;
          while (iVar5 = iVar5 + -1, iVar5 != -1) {
            *(undefined1 *)((int)puVar11 + iVar5) = *(undefined1 *)((int)(puVar13 + 5) + iVar5);
          }
        }
        iVar5 = puVar16[5] + uVar20;
        uVar20 = iVar5 + 7U & 0xfffffff8;
        puVar16[6] = uVar20;
        FUN_80039a18(uVar20,iVar5,puVar16[3] << 1,iVar6,uVar19);
        puVar13 = (undefined4 *)(puVar16[6] + iVar6);
      }
      if (((uint)puVar13 & 7) != 0) {
        puVar13 = (undefined4 *)((int)puVar13 + 7U & 0xfffffff8);
      }
      puVar16 = puVar16 + 7;
      psVar8 = psVar8 + 1;
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    iVar6 = 0;
    if (*(int *)((&PTR_PTR_80111668)[DAT_800e8ca8] + DAT_800e8caa * 4) != 0) {
      for (; (iVar6 < 8 &&
             (uVar19 = (uint)*(byte *)(*(int *)((&PTR_PTR_80111668)[DAT_800e8ca8] + DAT_800e8caa * 4
                                               ) + iVar6), uVar19 != 0xff)); iVar6 = iVar6 + 1) {
        iVar18 = func_0x80004cfc((&DAT_801124d4)[uVar19],puVar13,0x80000000,&DAT_800b928c);
        if (-1 < iVar18) {
          uVar14 = puVar13[1];
          uVar23 = puVar13[2];
          uVar24 = puVar13[3];
          (&DAT_80124128)[uVar19 * 7] = *puVar13;
          (&DAT_8012412c)[uVar19 * 7] = uVar14;
          (&DAT_80124130)[uVar19 * 7] = uVar23;
          (&DAT_80124134)[uVar19 * 7] = uVar24;
          uVar14 = puVar13[5];
          uVar23 = puVar13[6];
          (&DAT_80124138)[uVar19 * 7] = puVar13[4];
          (&DAT_8012413c)[uVar19 * 7] = uVar14;
          (&DAT_80124140)[uVar19 * 7] = uVar23;
          puVar16 = (undefined4 *)((int)puVar13 + 0x1bU & 0xfffffff8);
          (&DAT_8012413c)[uVar19 * 7] = puVar16;
          uVar20 = (uint)((&DAT_8012412c)[uVar19 * 7] * (&DAT_80124130)[uVar19 * 7]) >> 1;
          iVar5 = (&DAT_80124134)[uVar19 * 7] * (&DAT_80124138)[uVar19 * 7] * 2;
          if (puVar13 + 5 != puVar16) {
            iVar12 = uVar20 + iVar5;
            while (iVar12 = iVar12 + -1, iVar12 != -1) {
              *(undefined1 *)((int)puVar16 + iVar12) = *(undefined1 *)((int)(puVar13 + 5) + iVar12);
            }
          }
          iVar12 = (&DAT_8012413c)[uVar19 * 7] + uVar20;
          uVar20 = iVar12 + 7U & 0xfffffff8;
          (&DAT_80124140)[uVar19 * 7] = uVar20;
          FUN_80039a18(uVar20,iVar12,(&DAT_80124134)[uVar19 * 7] << 1,iVar5,uVar19);
          puVar13 = (undefined4 *)((&DAT_80124140)[uVar19 * 7] + iVar5);
        }
        if (((uint)puVar13 & 7) != 0) {
          puVar13 = (undefined4 *)((int)puVar13 + 7U & 0xfffffff8);
        }
      }
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    if (*(short *)((&PTR_DAT_80129b6c)[DAT_800e8ca8] + DAT_800e8caa * 2) != -1) {
      iVar18 = func_0x80004cfc(*(short *)((&PTR_DAT_80129b6c)[DAT_800e8ca8] + DAT_800e8caa * 2),
                               puVar13,1,&DAT_800b9290);
      *(undefined4 **)(DAT_800df92c + 0x3c) = puVar13;
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    if (-1 < iVar18) {
      puVar13 = (undefined4 *)((int)puVar13 + iVar18);
    }
    puVar21 = *(ushort **)
               (DAT_800e8caa * 4 +
               *(int *)((&PTR_PTR_8012ba84)[(int)DAT_800e110c < 0] + DAT_800e8ca8 * 4));
    *(char *)(DAT_800df92c + 2) = (char)*puVar21;
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    if (*(char *)(DAT_800df92c + 2) == '\0') {
      *(undefined4 *)(DAT_800df92c + 0x30) = 0;
    }
    else {
      local_50 = 0;
      local_4c = 0;
      local_48 = 0xffff;
      local_44 = 0;
      *(undefined4 **)(DAT_800df92c + 0x30) = puVar13;
      puVar17 = puVar13 + 0x1b;
      puVar22 = puVar13 + 2;
      puVar11 = puVar13 + (uint)*(byte *)(DAT_800df92c + 2) * 0x2c;
      uVar19 = 0;
      puVar16 = puVar13;
      while( true ) {
        puVar13 = puVar11;
        if (*(byte *)(DAT_800df92c + 2) <= uVar19) break;
        uVar3 = puVar21[1];
        puVar21 = puVar21 + 2;
        uVar4 = *puVar21;
        if (uVar3 < 0xfff0) {
          if (uVar3 == local_48) {
            puVar17[-6] = local_44;
          }
          else {
            puVar11 = (undefined4 *)((int)puVar11 + 7U & 0xfffffff8);
            puVar17[-6] = puVar11;
            iVar18 = func_0x80004cfc(uVar3,puVar11,1,&DAT_800b9294);
            if (iVar18 < 1) {
              puVar17[-6] = 0;
            }
            else {
              FUN_800824b8(puVar17[-6]);
              local_44 = puVar17[-6];
              puVar11 = (undefined4 *)((int)puVar11 + iVar18);
              local_48 = uVar3;
            }
          }
        }
        else {
          puVar17[-6] = 0;
        }
        if (uVar4 < 0xfff0) {
          if (uVar4 == 0xffff) {
            puVar17[-9] = local_50;
            puVar17[-8] = local_4c;
          }
          else {
            if (puVar17[-6] != 0) {
              FUN_80087868(puVar22,uVar4);
            }
            puVar11 = (undefined4 *)
                      FUN_800874d4(puVar11,puVar16 + 0x12,puVar16 + 0x13,uVar4,puVar22);
            local_50 = puVar17[-9];
            local_4c = puVar17[-8];
          }
        }
        else {
          puVar17[-9] = 0;
          puVar17[-8] = 0;
        }
        *puVar16 = 0;
        *puVar17 = 0xffffffff;
        puVar17 = puVar17 + 0x2c;
        puVar22 = puVar22 + 0x2c;
        puVar16 = puVar16 + 0x2c;
        uVar19 = uVar19 + 1;
      }
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    puVar21 = &DAT_8012ba8e;
    puVar16 = puVar13 + 0x18c;
    puVar11 = puVar13 + 0x13;
    puVar17 = puVar13 + 2;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0xffff;
    local_2c = 0;
    DAT_80113894 = puVar13;
    for (uVar19 = 0; uVar19 < 9; uVar19 = uVar19 + 1) {
      uVar3 = *puVar21;
      uVar4 = puVar21[1];
      puVar11[8] = 0xffffffff;
      puVar21 = puVar21 + 2;
      if (uVar3 < 0xfff0) {
        if (uVar3 == local_30) {
          puVar11[2] = local_2c;
        }
        else {
          puVar16 = (undefined4 *)((int)puVar16 + 7U & 0xfffffff8);
          puVar11[2] = puVar16;
          iVar18 = func_0x80004cfc(uVar3,puVar16,1,&DAT_800b9294);
          if (iVar18 < 1) {
            puVar11[2] = 0;
          }
          else {
            FUN_800824b8(puVar11[2]);
            local_2c = puVar11[2];
            puVar16 = (undefined4 *)((int)puVar16 + iVar18);
            local_30 = uVar3;
          }
        }
      }
      else {
        puVar11[2] = 0;
      }
      if (uVar4 < 0xfff0) {
        if (uVar4 == 0xffff) {
          puVar11[-1] = local_38;
          *puVar11 = local_34;
        }
        else {
          if (puVar11[2] != 0) {
            FUN_80087868(puVar17,uVar4);
          }
          puVar16 = (undefined4 *)FUN_800874d4(puVar16,puVar13 + 0x12,puVar11,uVar4,puVar17);
          local_38 = puVar11[-1];
          local_34 = *puVar11;
        }
      }
      else {
        puVar11[-1] = 0;
        *puVar11 = 0;
      }
      *puVar13 = 0;
      puVar11 = puVar11 + 0x2c;
      puVar17 = puVar17 + 0x2c;
      puVar13 = puVar13 + 0x2c;
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    if (((uint)puVar16 & 7) != 0) {
      puVar16 = (undefined4 *)((int)puVar16 + 7U & 0xfffffff8);
    }
    *(undefined4 **)(DAT_800df92c + 8) = puVar16;
    iVar18 = func_0x80004cfc(*(undefined2 *)((&PTR_DAT_80112408)[DAT_800e8ca8] + DAT_800e8caa * 2),
                             puVar16,1,&DAT_800b9298);
    DAT_800df934 = (int)puVar16 + iVar18;
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    FUN_800359ac();
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    if ((DAT_800e10ec & 0x2000000) == 0) {
      FUN_80083c14((int)DAT_800e8cac);
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    FUN_80037428();
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    *(undefined *)(DAT_800df92c + 6) = (&PTR_DAT_801124b4)[DAT_800e8ca8][DAT_800e8caa];
    FUN_80076314();
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    FUN_8006d2c8();
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    FUN_80076b70();
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    if (*(int *)(DAT_800df92c + 0x10) != 0) {
      DAT_800df934 = *(int *)(DAT_800df92c + 0x10);
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    DAT_800df938 = &DAT_800e1130;
    DAT_800e1134 = 0;
    FUN_800559b0();
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    FUN_8006d8f0();
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    FUN_80076480();
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    FUN_80035a7c();
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    FUN_80031b78();
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    FUN_80065220();
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    while (DAT_80131f0f != '\0') {
      FUN_8004cd88(1);
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    FUN_8008c194();
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    if ((DAT_800e9012 & 0xf0) != 0) {
      FUN_80070708();
    }
    (&DAT_8011253c)[DAT_80112555] = (&DAT_8011253c)[DAT_80112555] + '\x01';
    DAT_801124d0 = DAT_800c52d8 - (DAT_800df934 + -0xaf800);
    if (DAT_801124d0 < 1) {
      DAT_80112538 = DAT_801124d0;
    }
    else if (DAT_801124d0 < DAT_80112538) {
      DAT_80112538 = DAT_801124d0;
    }
  }
  return;
}
