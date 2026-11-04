/* FUN_80043988
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80043988  body 0x80043988..0x80044547  size 3008 B
 * body sha256 78e0cfe17b5224a082fca12a0f8b25109f0c8ad8529dd9541da3e4d2754e7f3a
 * provider record sha256 df57dc870ce21d555c466b45646efd5a90b496f7467fd3c6bf3b0ef2df8d7a7f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80043b0c) */
/* WARNING: Removing unreachable block (ram,0x80043bb8) */

undefined4 * FUN_80043988(undefined4 *param_1,byte *param_2,uint param_3,uint param_4)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  uint *puVar13;
  uint in_t5;
  uint in_t7;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint in_t9;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  ushort local_4a;
  ushort local_42;
  
  uVar14 = 0;
  uVar17 = (uint)param_2[9];
  uVar5 = param_3;
  if ((param_3 & 0xffff) == 0) {
    uVar5 = (uint)*(ushort *)(param_2 + 0x10);
  }
  uVar15 = param_4;
  if ((param_4 & 0xffff) == 0) {
    uVar15 = (uint)*(ushort *)(param_2 + 0x12);
  }
  if ((uVar5 & 0xffff) == 0) {
    DAT_800efd90 = 0;
    return param_1;
  }
  if ((uVar15 & 0xffff) == 0) {
    DAT_800efd90 = 0;
    return param_1;
  }
  local_4a = *(ushort *)(param_2 + 4);
  uVar16 = (uint)*(ushort *)(param_2 + 6);
  if ((param_3 & 0xffff) == 0) {
    fVar22 = 1.0;
  }
  else {
    fVar22 = (float)(param_3 & 0xffff) / (float)*(ushort *)(param_2 + 0x10);
  }
  if ((param_4 & 0xffff) == 0) {
    fVar21 = 1.0;
  }
  else {
    fVar21 = (float)(param_4 & 0xffff) / (float)*(ushort *)(param_2 + 0x12);
  }
  puVar13 = *(uint **)(param_2 + 0xc);
  uVar3 = uVar5 & 0xffff;
  if ((short)local_4a < 0) {
    uVar5 = uVar5 + local_4a;
    if ((int)uVar3 <= -(int)(short)local_4a) {
      DAT_800efd90 = 0;
      return param_1;
    }
    uVar3 = (uint)param_2[8] - (uint)local_4a;
    local_4a = 0;
  }
  else {
    uVar3 = (uint)param_2[8];
  }
  uVar4 = *puVar13;
  if (uVar4 == 1) {
    local_42 = (ushort)(uVar3 & 7);
    in_t7 = (uVar3 & 7) + uVar5 + 7 & 0xfff8;
    uVar3 = uVar3 & 0xf8;
    if ((int)(in_t7 * (uVar15 & 0xffff)) < 0x801) {
LAB_80043c10:
      in_t5 = uVar15;
      in_t9 = uVar15;
    }
    else {
      in_t5 = 0x800 / in_t7;
      if (in_t7 == 0) {
        trap(0x1c00);
      }
joined_r0x80043be0:
      fVar18 = (float)in_t5 / fVar21;
      if (2.1474836e+09 <= fVar18) {
        in_t9 = (int)(fVar18 - 2.1474836e+09);
      }
      else {
        in_t9 = (int)fVar18;
      }
    }
  }
  else if ((uVar4 == 0) || ((uVar4 & 0xff) == 0xff)) {
    local_42 = (ushort)(uVar3 & 0xf);
    uVar5 = (uVar3 & 0xf) + uVar5 + 0xf;
    in_t7 = uVar5 & 0xfffffff0;
    uVar5 = uVar5 & 0xfff0;
    uVar3 = uVar3 & 0xf0;
    if ((int)(uVar5 * (uVar15 & 0xffff)) < 0x1001) goto LAB_80043c10;
    if (uVar5 == 0) {
      trap(0x1c00);
    }
    in_t5 = 0x1000 / uVar5 & 0xfffffff0;
    goto joined_r0x80043be0;
  }
  sVar2 = *(short *)(param_2 + 0x10);
  if ((DAT_800efd94 == -1) || (DAT_800efda4 != 1)) {
    *param_1 = 0xe7000000;
    param_1[1] = 0;
    DAT_800efd90 = 1;
    puVar12 = param_1 + 6;
    param_1[2] = 0xde000000;
    param_1[3] = &DAT_800efdf0;
    param_1[4] = 0xd7000002;
    param_1[5] = 0x80008000;
    DAT_800efda4 = 1;
  }
  else {
    *param_1 = 0xe7000000;
    param_1[1] = 0;
    DAT_800efd90 = 1;
    puVar12 = param_1 + 4;
    param_1[2] = 0xde000000;
    param_1[3] = &DAT_800efe68;
  }
  if ((DAT_800efd94 == *(int *)param_2) && (DAT_800efd98 == *puVar13)) goto LAB_80043f0c;
  bVar1 = param_2[3];
  if (bVar1 == 1) {
    *puVar12 = 0xe200001c;
    puVar12[1] = 0x504240;
    puVar12[2] = 0xfa000000;
    puVar12[3] = 0x3e3e3e5c;
    puVar12[4] = 0xfcf197e3;
    puVar12[5] = 0x112fffff;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        uVar8 = 0x5041c8;
LAB_80043d90:
        *puVar12 = 0xe200001c;
        puVar12[1] = uVar8;
        puVar12[2] = 0xfa000000;
        puVar12[3] = ((uint)*param_2 * 2 + -1) * 0x1000000 |
                     ((uint)param_2[1] * 2 - 1 & 0xff) << 0x10 |
                     ((uint)param_2[2] * 2 - 1 & 0xff) << 8;
        puVar12[4] = 0xfc11fe23;
        puVar12[5] = 0xfffff3f9;
        goto LAB_80043ef0;
      }
    }
    else if ((bVar1 != 2) && (bVar1 == 3)) {
      uVar8 = 0xf0a4000;
      goto LAB_80043d90;
    }
    *puVar12 = 0xe200001c;
    puVar12[1] = 0x504240;
    bVar1 = *param_2;
    puVar12[2] = 0xfa000000;
    uVar5 = (uint)bVar1 + (uint)(bVar1 >> 1);
    if (uVar5 < 0xff) {
      uVar5 = uVar5 & 0xff | 0xbcbcbc00;
    }
    else {
      uVar5 = 0xbcbcbcff;
    }
    puVar12[3] = uVar5;
    puVar12[4] = 0xfcff97ff;
    puVar12[5] = 0xff2cfe7f;
  }
LAB_80043ef0:
  puVar12 = puVar12 + 6;
  DAT_800efd94 = *(int *)param_2;
  DAT_800efd98 = *puVar13;
LAB_80043f0c:
  uVar4 = in_t7 & 0xffff;
  uVar5 = ((uVar4 - 1) * 4 & 0xfff) << 0xc;
  puVar10 = puVar12 + -2;
  do {
    if ((uVar15 & 0xffff) <= (uVar14 & 0xffff)) {
      return puVar12;
    }
    if ((uVar15 & 0xffff) <= (uVar14 & 0xffff) + (in_t5 & 0xffff)) {
      in_t5 = uVar15 - uVar14;
      fVar18 = (float)(in_t5 & 0xffff) / fVar21;
      if (2.1474836e+09 <= fVar18) {
        fVar18 = fVar18 - 2.1474836e+09;
      }
      in_t9 = (uint)fVar18;
    }
    uVar14 = uVar14 + in_t5;
    puVar9 = puVar10;
    if (*puVar13 == 1) {
      uVar6 = puVar13[5] + (uVar3 & 0xff) + puVar13[1] * (uVar17 & 0xff);
      if (DAT_800efd9c != (uVar6 | in_t7 << 0x10)) {
        puVar10[2] = puVar13[1] - 1 & 0xfff | 0xfd480000;
        puVar10[3] = uVar6;
        uVar7 = ((int)(uVar4 + 7) >> 3 & 0x1ffU) << 9 | 0xf5480000;
        puVar10[4] = uVar7;
        puVar10[5] = 0x7080200;
        puVar10[6] = 0xe6000000;
        puVar10[7] = 0;
        uVar6 = ((in_t5 & 0xffff) - 1) * 4 & 0xfff;
        puVar10[8] = 0xf4000000;
        puVar12 = puVar12 + 0xe;
        puVar10[9] = uVar5 | uVar6 | 0x7000000;
        puVar10[10] = 0xe7000000;
        puVar10[0xb] = 0;
        puVar10[0xc] = uVar7;
        puVar10[0xd] = 0x80200;
        puVar9 = puVar10 + 0xe;
        *puVar9 = 0xf2000000;
        puVar10[0xf] = uVar5 | uVar6;
      }
      puVar10 = puVar9;
      puVar11 = puVar12;
      if (DAT_800efda0 != puVar13[6] + (uint)*(ushort *)(param_2 + 10)) {
        uVar8 = 0xf5000100;
        uVar6 = 0x73f0000;
LAB_8004422c:
        puVar9[2] = 0xfd100000;
        puVar9[3] = puVar13[6] + (uint)*(ushort *)(param_2 + 10);
        puVar9[4] = 0xe8000000;
        puVar9[5] = 0;
        puVar9[6] = uVar8;
        puVar9[7] = 0x7000000;
        puVar9[8] = 0xe6000000;
        puVar9[9] = 0;
        puVar9[10] = 0xf0000000;
        puVar9[0xb] = uVar6 | 0xc000;
        puVar9[0xc] = 0xe7000000;
        puVar9[0xd] = 0;
        DAT_800efda0 = puVar13[6] + (uint)*(ushort *)(param_2 + 10);
        puVar10 = puVar9 + 0xc;
        puVar11 = puVar12 + 0xc;
      }
    }
    else {
      puVar11 = puVar12;
      if (*puVar13 == 0) {
        uVar6 = puVar13[5] + ((uVar3 & 0xff) >> 1) + (puVar13[1] >> 1) * (uVar17 & 0xff);
        if (DAT_800efd9c != (uVar6 | in_t7 << 0x10)) {
          puVar10[2] = (puVar13[1] >> 1) - 1 & 0xfff | 0xfd480000;
          puVar10[3] = uVar6;
          uVar7 = ((int)((uVar4 >> 1) + 7) >> 3 & 0x1ffU) << 9;
          puVar10[4] = uVar7 | 0xf5480000;
          puVar10[5] = 0x7080200;
          puVar10[6] = 0xe6000000;
          puVar10[7] = 0;
          uVar6 = ((in_t5 & 0xffff) - 1) * 4 & 0xfff;
          puVar10[8] = 0xf4000000;
          puVar10[9] = (uVar4 - 1 & 0x7ff) << 0xd | uVar6 | 0x7000000;
          puVar10[10] = 0xe7000000;
          puVar10[0xb] = 0;
          puVar10[0xc] = uVar7 | 0xf5400000;
          puVar10[0xd] = 0xf80200;
          puVar9 = puVar10 + 0xe;
          *puVar9 = 0xf2000000;
          puVar12 = puVar12 + 0xe;
          puVar10[0xf] = uVar5 | uVar6;
        }
        puVar10 = puVar9;
        puVar11 = puVar12;
        if (DAT_800efda0 != puVar13[6] + (uint)*(ushort *)(param_2 + 10)) {
          uVar8 = 0xf50001f0;
          uVar6 = 0x7030000;
          goto LAB_8004422c;
        }
      }
    }
    fVar18 = (float)local_4a * DAT_801127f8;
    if (2.1474836e+09 <= fVar18) {
      fVar18 = fVar18 - 2.1474836e+09;
    }
    fVar19 = (float)(ushort)(local_4a + sVar2) * DAT_801127f8;
    if (2.1474836e+09 <= fVar19) {
      fVar19 = fVar19 - 2.1474836e+09;
    }
    fVar20 = (float)(uVar16 & 0xffff) * DAT_801127fc;
    if (2.1474836e+09 <= fVar20) {
      fVar20 = fVar20 - 2.1474836e+09;
    }
    uVar6 = (uint)fVar20;
    fVar20 = (float)(uVar16 + in_t9 & 0xffff) * DAT_801127fc;
    if (2.1474836e+09 <= fVar20) {
      fVar20 = fVar20 - 2.1474836e+09;
    }
    uVar7 = (uint)fVar20;
    puVar12 = puVar11;
    if (((*(short *)(param_2 + 0x10) != 0) && (*(short *)(param_2 + 0x12) != 0)) &&
       ((uVar6 & 0xffff) != (uVar7 & 0xffff))) {
      puVar10[2] = ((int)fVar19 & 0x3ffU) << 0xe | (uVar7 & 0x3ff) << 2 | 0xe4000000;
      puVar10[3] = ((int)fVar18 & 0x3ffU) << 0xe | (uVar6 & 0x3ff) << 2;
      puVar12 = puVar11 + 6;
      puVar10[4] = 0xe1000000;
      puVar10[5] = (uint)local_42 << 0x15;
      puVar10 = puVar10 + 6;
      fVar18 = (fVar22 * 1024.0) / DAT_801127f8;
      *puVar10 = 0xf1000000;
      if (2.1474836e+09 <= fVar18) {
        fVar18 = fVar18 - 2.1474836e+09;
      }
      fVar19 = ((float)(in_t5 & 0xffff) / (float)(int)((uVar7 & 0xffff) - (uVar6 & 0xffff))) *
               1024.0;
      if (2.1474836e+09 <= fVar19) {
        fVar19 = fVar19 - 2.1474836e+09;
      }
      puVar11[5] = (int)fVar18 << 0x10 | (int)fVar19 & 0xffffU;
    }
    uVar17 = in_t5 + uVar17;
    uVar16 = uVar16 + in_t9;
  } while( true );
}
