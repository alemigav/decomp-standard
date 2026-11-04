/* FUN_80044fdc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80044fdc  body 0x80044fdc..0x80046207  size 4652 B
 * body sha256 d14fafbd87a0f0ce23fcd3c6e416f9ac0f13f19fc2277c0a17d1fcff03acd69e
 * provider record sha256 2f3d3adaabcd012b8894f9bda3254255f62dad6621662ce1b3975766df96cae9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_80044fdc(undefined4 *param_1,byte *param_2,char param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  undefined *puVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  short sVar11;
  uint uVar10;
  ushort uVar13;
  uint uVar12;
  ushort uVar18;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar19;
  undefined4 uVar20;
  uint uVar21;
  ushort uVar22;
  uint uVar23;
  ushort uVar26;
  uint *puVar24;
  uint *puVar25;
  undefined4 *puVar27;
  undefined4 *puVar28;
  uint *puVar29;
  uint in_t5;
  uint uVar30;
  uint uVar31;
  uint unaff_s3;
  uint uVar32;
  uint uVar33;
  int iVar34;
  float fVar35;
  float fVar36;
  ushort uVar37;
  ushort uVar38;
  ushort uVar39;
  ushort uVar40;
  ushort uVar41;
  ushort uVar42;
  short local_92;
  ushort local_5a;
  ushort local_52;
  ushort local_42;
  
  if (&UNK_800dd4c1 <= param_1) {
    return param_1;
  }
  uVar22 = *(ushort *)(param_2 + 6);
  uVar21 = (uint)uVar22;
  uVar26 = *(ushort *)(param_2 + 4);
  uVar40 = *(ushort *)(param_2 + 0xc);
  uVar41 = *(ushort *)(param_2 + 0x14);
  uVar42 = *(ushort *)(param_2 + 0x1c);
  uVar37 = *(ushort *)(param_2 + 0xe);
  uVar38 = *(ushort *)(param_2 + 0x16);
  uVar39 = *(ushort *)(param_2 + 0x1e);
  uVar23 = (uint)uVar39;
  if ((((0x13f < *(short *)(param_2 + 4)) && (0x13f < (short)uVar40)) && (0x13f < (short)uVar41)) &&
     (0x13f < (short)uVar42)) {
    DAT_800efd90 = 0;
    return param_1;
  }
  if (((0xef < (short)uVar22) && (0xef < (short)uVar37)) &&
     ((0xef < (short)uVar38 && (0xef < (short)uVar39)))) {
    DAT_800efd90 = 0;
    return param_1;
  }
  if ((((int)((uint)uVar26 << 0x10) < 0) && ((int)((uint)uVar40 << 0x10) < 0)) &&
     (((int)((uint)uVar41 << 0x10) < 0 && ((int)((uint)uVar42 << 0x10) < 0)))) {
    DAT_800efd90 = 0;
    return param_1;
  }
  if (((((int)(uVar21 << 0x10) < 0) && ((int)((uint)uVar37 << 0x10) < 0)) &&
      ((int)((uint)uVar38 << 0x10) < 0)) && ((int)(uVar23 << 0x10) < 0)) {
    DAT_800efd90 = 0;
    return param_1;
  }
  bVar1 = param_2[8];
  uVar30 = (uint)bVar1;
  bVar2 = param_2[0x20];
  bVar3 = param_2[9];
  uVar31 = (uint)bVar3;
  bVar4 = param_2[0x21];
  puVar29 = *(uint **)(param_2 + 0x24);
  if (uVar30 < bVar2) {
    uVar13 = (ushort)bVar2 - (ushort)bVar1;
  }
  else {
    uVar13 = (ushort)bVar1 - (ushort)bVar2;
  }
  if (uVar13 == 0) {
    DAT_800efd90 = 0;
    return param_1;
  }
  if (bVar3 < bVar4) {
    uVar18 = (ushort)bVar4 - (ushort)bVar3;
  }
  else {
    uVar18 = (ushort)bVar3 - (ushort)bVar4;
  }
  if (uVar18 == 0) {
    DAT_800efd90 = 0;
    return param_1;
  }
  sVar11 = uVar42 - uVar26;
  if ((int)((uint)uVar42 << 0x10) <= (int)((uint)uVar26 << 0x10)) {
    sVar11 = uVar26 - uVar42;
  }
  if (sVar11 == 0) {
    uVar26 = uVar42 + 1;
  }
  iVar14 = uVar23 - uVar21;
  if ((int)(uVar23 << 0x10) <= (int)(uVar21 << 0x10)) {
    iVar14 = uVar21 - uVar23;
  }
  iVar14 = iVar14 << 0x10;
  if (iVar14 == 0) {
    uVar22 = uVar39 + 1;
    iVar14 = 0x10000;
  }
  uVar21 = *puVar29;
  iVar19 = (int)(short)uVar18;
  fVar36 = (DAT_801127fc * (float)(iVar14 >> 0x10)) / (float)iVar19;
  if (uVar21 == 1) {
    uVar23 = uVar30 & 7;
    uVar21 = (uint)uVar13 + uVar23 + 0xf;
    unaff_s3 = uVar21 & 0xfffffff8;
    uVar21 = uVar21 & 0xfff8;
    uVar30 = uVar30 & 0xfffffff8;
    local_92 = (short)uVar23;
    if ((int)(uVar21 * iVar19) < 0x801) {
LAB_800452d0:
      in_t5 = (uint)uVar18;
    }
    else {
      uVar23 = 0x800;
LAB_8004529c:
      in_t5 = uVar23 / uVar21;
      if (uVar21 == 0) {
        trap(0x1c00);
      }
      if ((uVar21 == 0xffffffff) && (uVar23 == 0x80000000)) {
        trap(0x1800);
      }
    }
  }
  else if ((uVar21 == 0) || ((uVar21 & 0xff) == 0xff)) {
    uVar23 = uVar30 & 0xf;
    uVar21 = (uint)uVar13 + uVar23 + 0xf;
    unaff_s3 = uVar21 & 0xfffffff0;
    uVar21 = uVar21 & 0xfff0;
    uVar30 = uVar30 & 0xfffffff0;
    local_92 = (short)uVar23;
    if ((int)(uVar21 * iVar19) < 0x1001) goto LAB_800452d0;
    uVar23 = 0x1000;
    goto LAB_8004529c;
  }
  fVar35 = (float)(int)(short)uVar22 * DAT_801127fc;
  if (fVar35 < 2.1474836e+09) {
    uVar22 = (ushort)(int)fVar35;
  }
  else {
    uVar22 = (ushort)(int)(fVar35 - 2.1474836e+09);
  }
  fVar35 = (float)(int)(short)uVar37 * DAT_801127fc;
  if (fVar35 < 2.1474836e+09) {
    uVar37 = (ushort)(int)fVar35;
  }
  else {
    uVar37 = (ushort)(int)(fVar35 - 2.1474836e+09);
  }
  fVar35 = (float)(int)(short)uVar38 * DAT_801127fc;
  if (fVar35 < 2.1474836e+09) {
    uVar38 = (ushort)(int)fVar35;
  }
  else {
    uVar38 = (ushort)(int)(fVar35 - 2.1474836e+09);
  }
  fVar35 = (float)(int)(short)uVar39 * DAT_801127fc;
  if (fVar35 < 2.1474836e+09) {
    uVar39 = (ushort)(int)fVar35;
  }
  else {
    uVar39 = (ushort)(int)(fVar35 - 2.1474836e+09);
  }
  fVar35 = (float)(int)(short)uVar26 * DAT_801127f8;
  if (fVar35 < 2.1474836e+09) {
    uVar26 = (ushort)(int)fVar35;
  }
  else {
    uVar26 = (ushort)(int)(fVar35 - 2.1474836e+09);
  }
  fVar35 = (float)(int)(short)uVar40 * DAT_801127f8;
  if (fVar35 < 2.1474836e+09) {
    uVar40 = (ushort)(int)fVar35;
  }
  else {
    uVar40 = (ushort)(int)(fVar35 - 2.1474836e+09);
  }
  fVar35 = (float)(int)(short)uVar41 * DAT_801127f8;
  if (fVar35 < 2.1474836e+09) {
    uVar41 = (ushort)(int)fVar35;
  }
  else {
    uVar41 = (ushort)(int)(fVar35 - 2.1474836e+09);
  }
  fVar35 = (float)(int)(short)uVar42 * DAT_801127f8;
  if (fVar35 < 2.1474836e+09) {
    uVar42 = (ushort)(int)fVar35;
  }
  else {
    uVar42 = (ushort)(int)(fVar35 - 2.1474836e+09);
  }
  iVar14 = 0;
  local_5a = 0;
  local_52 = (ushort)in_t5;
  puVar28 = param_1 + 2;
  *param_1 = 0xe7000000;
  param_1[1] = 0;
  DAT_800efd90 = 1;
  if ((DAT_800efd94 == -1) || (DAT_800efda4 != 1)) {
    if (param_3 == '\0') {
      *puVar28 = 0xde000000;
      puVar6 = &DAT_800efdf0;
    }
    else {
      *puVar28 = 0xde000000;
      puVar6 = &DAT_800efec8;
    }
    param_1[3] = puVar6;
    puVar28 = param_1 + 6;
    param_1[4] = 0xd7000002;
    param_1[5] = 0x80008000;
    DAT_800efda4 = 1;
  }
  else {
    if (param_3 == '\0') {
      *puVar28 = 0xde000000;
      puVar6 = &DAT_800efe68;
    }
    else {
      *puVar28 = 0xde000000;
      puVar6 = &DAT_800eff40;
    }
    puVar28 = param_1 + 4;
    param_1[3] = puVar6;
  }
  if ((DAT_800efd94 == *(int *)param_2) && (DAT_800efd98 == *puVar29)) goto LAB_80045a38;
  *puVar28 = 0xe7000000;
  puVar28[1] = 0;
  bVar1 = param_2[3];
  puVar27 = puVar28 + 2;
  if (bVar1 == 1) {
    if (*(short *)(param_2 + 0x1a) == 0) {
      uVar7 = 0x504240;
    }
    else {
      uVar7 = 0x504a50;
    }
    *puVar27 = 0xe200001c;
    puVar28[3] = uVar7;
    uVar20 = 0xfc6196c3;
    uVar7 = 0x112fffff;
    puVar28[4] = 0xfa000000;
    uVar21 = 0xffffff5c;
LAB_800458b8:
    puVar28[5] = uVar21;
    puVar28[6] = uVar20;
    puVar28[7] = uVar7;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        if (*(short *)(param_2 + 0x1a) == 0) {
          uVar7 = 0x504240;
        }
        else if (param_3 == '\0') {
          uVar7 = 0x504a50;
        }
        else {
          uVar7 = 0x504a70;
        }
        *puVar27 = 0xe200001c;
        puVar28[3] = uVar7;
        puVar28[4] = 0xfa000000;
        puVar28[5] = ((uint)*param_2 * 2 + -1) * 0x1000000 |
                     ((uint)param_2[1] * 2 - 1 & 0xff) << 0x10 |
                     ((uint)param_2[2] * 2 - 1 & 0xff) << 8;
        puVar28[6] = 0xfc11fe23;
        puVar28[7] = 0xfffff3f9;
        goto LAB_80045a20;
      }
    }
    else if ((bVar1 != 2) && (bVar1 == 4)) {
      if (*(short *)(param_2 + 0x1a) == 0) {
        uVar7 = 0x504240;
      }
      else {
        uVar7 = 0x504a50;
      }
      *puVar27 = 0xe200001c;
      puVar28[3] = uVar7;
      uVar20 = 0xfcff97ff;
      puVar28[4] = 0xfa000000;
      uVar21 = (uint)param_2[2];
      uVar7 = 0xff2cfe7f;
      goto LAB_800458b8;
    }
    if (param_3 == '\0') {
      uVar7 = 0x5048d0;
    }
    else {
      uVar7 = 0x504a70;
    }
    *puVar27 = 0xe200001c;
    puVar28[3] = uVar7;
    uVar21 = *puVar29;
    if ((uVar21 & 0xff) == 0xff) {
      uVar5 = *(ushort *)((uVar21 >> 0x18) * 2 + puVar29[6] + (uint)*(ushort *)(param_2 + 10));
      *param_2 = ((byte)(uVar5 >> 8) & 0xf8) + 1;
      param_2[1] = (char)((uVar5 & 0x7c0) >> 3) + 1;
      param_2[2] = ((byte)uVar5 & 0x3e) * '\x04' + 1;
      puVar28[4] = 0xfa000000;
      puVar28[5] = (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[2] << 8 |
                   uVar21 >> 0x10 & 0xff;
    }
    else {
      puVar28[4] = 0xfa000000;
      puVar28[5] = ((uint)*param_2 * 2 + -1) * 0x1000000 | ((uint)param_2[1] * 2 - 1 & 0xff) << 0x10
                   | ((uint)param_2[2] * 2 - 1 & 0xff) << 8 | 0x8a;
    }
    puVar28[6] = 0xfc119623;
    puVar28[7] = 0xff2fffff;
  }
LAB_80045a20:
  puVar28 = puVar28 + 8;
  DAT_800efd94 = *(int *)param_2;
  DAT_800efd98 = *puVar29;
LAB_80045a38:
  uVar23 = unaff_s3 & 0xffff;
  iVar34 = uVar23 - 1;
  puVar24 = puVar28 + -1;
  uVar32 = unaff_s3 << 0x10;
  uVar21 = (iVar34 * 4 & 0xfffU) << 0xc;
  iVar19 = (int)(uVar30 << 0x10) >> 0x11;
  uVar33 = ((int)((uVar23 >> 1) + 7) >> 3 & 0x1ffU) << 9;
  do {
    if ((int)(short)uVar18 <= (int)(short)iVar14) {
      *puVar28 = 0xe7000000;
      puVar28[1] = 0;
      puVar27 = puVar28 + 2;
      if (param_3 != '\0') {
        puVar27 = puVar28 + 6;
        puVar28[2] = 0xe3001201;
        puVar28[3] = 0x2000;
        puVar28[4] = 0xe3001801;
        puVar28[5] = 0xc0;
      }
      return puVar27;
    }
    if (&UNK_800dd4c0 < puVar28) {
      return puVar28;
    }
    if (local_5a == 0) {
      uVar8 = (uint)uVar22;
      uVar10 = (uint)uVar37;
    }
    else {
      fVar35 = (float)local_5a * fVar36;
      if (2.1474836e+09 <= fVar35) {
        fVar35 = fVar35 - 2.1474836e+09;
      }
      uVar8 = (uint)uVar22 + (int)fVar35;
      uVar10 = uVar8;
    }
    if ((int)(short)iVar14 + (int)(short)in_t5 < (int)(short)uVar18) {
      fVar35 = (float)local_52 * fVar36;
      if (2.1474836e+09 <= fVar35) {
        fVar35 = fVar35 - 2.1474836e+09;
      }
      uVar9 = (uint)uVar22 + (int)fVar35;
      uVar17 = uVar9;
    }
    else {
      uVar9 = (uint)uVar38;
      uVar17 = (uint)uVar39;
      in_t5 = (uint)uVar18 - iVar14;
    }
    iVar14 = iVar14 + in_t5;
    uVar12 = *puVar29;
    sVar11 = (short)uVar31;
    puVar25 = puVar24;
    puVar27 = puVar28;
    if (uVar12 == 1) {
      uVar12 = puVar29[5] + ((int)(uVar30 << 0x10) >> 0x10) + puVar29[1] * (int)sVar11;
      uVar15 = uVar12 & 0xfffffff8;
      local_42 = local_92 + (short)uVar12 & 7;
      uVar12 = uVar15 | uVar32;
      if (DAT_800efd9c != uVar12) {
        puVar24[1] = puVar29[1] - 1 & 0xfff | 0xfd480000;
        puVar24[2] = uVar15;
        uVar15 = ((int)(in_t5 << 0x10) >> 0xe) - 4U & 0xfff;
        puVar27 = puVar28 + 0xe;
        puVar24[4] = 0x7080200;
        uVar16 = ((int)(uVar23 + 7) >> 3 & 0x1ffU) << 9 | 0xf5480000;
        DAT_800efd9c = uVar12;
        puVar24[3] = uVar16;
        puVar24[5] = 0xe6000000;
        puVar24[6] = 0;
        puVar24[7] = 0xf4000000;
        puVar24[8] = uVar21 | uVar15 | 0x7000000;
        puVar24[9] = 0xe7000000;
        puVar24[10] = 0;
        puVar24[0xb] = uVar16;
        puVar24[0xc] = 0x80200;
        puVar25 = puVar24 + 0xe;
        puVar24[0xd] = 0xf2000000;
        *puVar25 = uVar21 | uVar15;
      }
      if (DAT_800efda0 != puVar29[6] + (uint)*(ushort *)(param_2 + 10)) {
        uVar12 = 0xf5000100;
        uVar15 = 0x73f0000;
        puVar24 = puVar25;
LAB_80045e4c:
        puVar24[1] = 0xfd100000;
        puVar24[2] = puVar29[6] + (uint)*(ushort *)(param_2 + 10);
        puVar24[3] = 0xe8000000;
        puVar24[4] = 0;
        puVar24[5] = uVar12;
        puVar24[6] = 0x7000000;
        puVar24[7] = 0xe6000000;
        puVar24[8] = 0;
        puVar24[9] = 0xf0000000;
        puVar24[10] = uVar15 | 0xc000;
        puVar25 = puVar24 + 0xc;
        puVar24[0xb] = 0xe7000000;
        *puVar25 = 0;
        puVar27 = puVar27 + 0xc;
        DAT_800efda0 = puVar29[6] + (uint)*(ushort *)(param_2 + 10);
      }
LAB_80045ffc:
      puVar25 = puVar25 + 2;
      puVar28 = puVar27;
    }
    else {
      if (uVar12 == 0) {
        uVar12 = puVar29[5] + iVar19 + (puVar29[1] >> 1) * (int)sVar11;
        local_42 = local_92 + ((ushort)uVar12 & 7) * 2;
        uVar12 = uVar12 & 0xfffffff8;
        uVar15 = uVar12 | uVar32;
        if (DAT_800efd9c != uVar15) {
          puVar24[1] = (puVar29[1] >> 1) - 1 & 0xfff | 0xfd480000;
          puVar24[2] = uVar12;
          uVar12 = ((int)(in_t5 << 0x10) >> 0xe) - 4U & 0xfff;
          puVar27 = puVar28 + 0xe;
          puVar24[4] = 0x7080200;
          DAT_800efd9c = uVar15;
          puVar24[3] = uVar33 | 0xf5480000;
          puVar24[5] = 0xe6000000;
          puVar24[6] = 0;
          puVar24[7] = 0xf4000000;
          puVar24[8] = (iVar34 * 2 & 0xfffU) << 0xc | uVar12 | 0x7000000;
          puVar24[9] = 0xe7000000;
          puVar24[10] = 0;
          puVar24[0xb] = uVar33 | 0xf5400000;
          puVar24[0xc] = 0xf80200;
          puVar25 = puVar24 + 0xe;
          puVar24[0xd] = 0xf2000000;
          *puVar25 = uVar21 | uVar12;
        }
        if (DAT_800efda0 != puVar29[6] + (uint)*(ushort *)(param_2 + 10)) {
          uVar12 = 0xf50001f0;
          uVar15 = 0x7030000;
          puVar24 = puVar25;
          goto LAB_80045e4c;
        }
        goto LAB_80045ffc;
      }
      puVar25 = puVar24 + 2;
      if ((uVar12 & 0xff) == 0xff) {
        uVar15 = puVar29[5];
        uVar12 = puVar29[1];
        puVar24[1] = 0xe3001001;
        *puVar25 = 0;
        DAT_800efda0 = -1;
        uVar15 = uVar15 + iVar19 + (uVar12 >> 1) * (int)sVar11;
        local_42 = local_92 + ((ushort)uVar15 & 7) * 2;
        uVar15 = uVar15 & 0xfffffff8;
        uVar12 = uVar15 | uVar32;
        puVar27 = puVar28 + 2;
        if (DAT_800efd9c != uVar12) {
          uVar16 = puVar29[1];
          puVar27 = puVar28 + 0x10;
          DAT_800efd9c = uVar12;
          puVar24[4] = uVar15;
          uVar12 = ((int)(in_t5 << 0x10) >> 0xe) - 4U & 0xfff;
          puVar24[3] = (uVar16 >> 1) - 1 & 0xfff | 0xfd880000;
          puVar24[5] = uVar33 | 0xf5880000;
          puVar24[6] = 0x7080200;
          puVar24[7] = 0xe6000000;
          puVar24[8] = 0;
          puVar24[9] = 0xf4000000;
          puVar24[10] = (iVar34 * 2 & 0xfffU) << 0xc | uVar12 | 0x7000000;
          puVar24[0xb] = 0xe7000000;
          puVar24[0xc] = 0;
          puVar24[0xd] = uVar33 | 0xf5800000;
          puVar24[0xe] = 0xf80200;
          puVar25 = puVar24 + 0x10;
          puVar24[0xf] = 0xf2000000;
          *puVar25 = uVar21 | uVar12;
        }
        goto LAB_80045ffc;
      }
    }
    puVar25[-1] = 0x1004008;
    *puVar25 = (uint)&DAT_800efda8;
    puVar28 = puVar28 + 0x16;
    puVar25[1] = 0x2180000;
    uVar31 = uVar31 + in_t5;
    puVar25[2] = (uint)uVar26 << 0x12 | (uVar8 & 0x3fff) << 2;
    puVar25[3] = 0x2180002;
    puVar25[4] = (uint)uVar40 << 0x12 | (uVar10 & 0x3fff) << 2;
    puVar25[5] = 0x2180004;
    puVar25[6] = (uint)uVar41 << 0x12 | (uVar9 & 0x3fff) << 2;
    puVar25[7] = 0x2180006;
    puVar25[8] = (uint)uVar42 << 0x12 | (uVar17 & 0x3fff) << 2;
    local_5a = local_5a + (short)in_t5;
    puVar25[9] = 0xee000000;
    local_52 = local_52 + (short)in_t5;
    puVar25[10] = (uint)*(ushort *)(param_2 + 0x1a) << 0x10 | 1;
    puVar25[0xb] = 0x2140000;
    uVar17 = (uint)local_42 << 0x16;
    puVar25[0xc] = uVar17;
    puVar25[0xd] = 0x2140002;
    uVar8 = ((uint)local_42 + (int)(short)uVar13) * 0x400000;
    puVar25[0xe] = uVar8;
    uVar10 = (int)(in_t5 << 0x10) >> 10;
    puVar25[0xf] = 0x2140004;
    puVar25[0x10] = uVar17 | uVar10;
    puVar25[0x11] = 0x2140006;
    puVar25[0x12] = uVar8 | uVar10;
    puVar24 = puVar25 + 0x14;
    puVar25[0x13] = 0x7000406;
    *puVar24 = 0x602;
  } while( true );
}
