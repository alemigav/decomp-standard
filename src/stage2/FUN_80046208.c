/* FUN_80046208
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80046208  body 0x80046208..0x80046ec3  size 3260 B
 * body sha256 4264f22e05e246ff57b0ace6a6906ae6202c89ea0bcffa1a6d1f9b0de88fe653
 * provider record sha256 7fdddbcdb4130e93fa2d50d0ddd1109d21beb68f0f683a685f8fdbe96d7da79d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800462fc) */

uint * FUN_80046208(uint *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  uint *puVar12;
  uint *puVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  ushort uVar19;
  ushort uVar20;
  ushort uVar21;
  
  DAT_800efd90 = 0;
  uVar10 = (uint)param_2[0x2c] - (uint)param_2[8];
  if (param_2[9] < param_2[0x2d]) {
    uVar8 = (uint)param_2[0x2d] - (uint)param_2[9];
  }
  else {
    uVar8 = (uint)param_2[9] - (uint)param_2[0x2d];
  }
  piVar11 = *(int **)(param_2 + 0x30);
  uVar5 = uVar10 & 0xffff;
  if (*(short *)(param_2 + 4) < 0) {
    uVar10 = uVar10 + *(ushort *)(param_2 + 4);
    if ((int)uVar5 <= -(int)*(short *)(param_2 + 4)) {
      DAT_800efd90 = 0;
      return param_1;
    }
    uVar5 = (uint)param_2[8] - (uint)*(ushort *)(param_2 + 4);
  }
  else {
    uVar5 = (uint)param_2[8];
  }
  uVar6 = uVar8 & 0xffff;
  if ((int)(((uVar10 & 0xffff) + 7 & 0xfff8) * uVar6) < 0x801) {
    uVar6 = uVar10 + 7 & 0xfff8;
  }
  else {
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    uVar6 = 0x800 / uVar6 & 0xff8;
  }
  uVar19 = 0;
  if (0 < *(short *)(param_2 + 4)) {
    uVar19 = *(ushort *)(param_2 + 4);
  }
  fVar14 = (float)uVar19 * DAT_801127f8;
  if (2.1474836e+09 <= fVar14) {
    fVar14 = fVar14 - 2.1474836e+09;
  }
  uVar19 = 0;
  if (0 < *(short *)(param_2 + 0x10)) {
    uVar19 = *(ushort *)(param_2 + 0x10);
  }
  fVar15 = (float)uVar19 * DAT_801127f8;
  if (2.1474836e+09 <= fVar15) {
    fVar15 = fVar15 - 2.1474836e+09;
  }
  uVar19 = 0;
  if (0 < *(short *)(param_2 + 0x1c)) {
    uVar19 = *(ushort *)(param_2 + 0x1c);
  }
  fVar16 = (float)uVar19 * DAT_801127f8;
  if (2.1474836e+09 <= fVar16) {
    fVar16 = fVar16 - 2.1474836e+09;
  }
  uVar19 = 0;
  if (0 < *(short *)(param_2 + 0x28)) {
    uVar19 = *(ushort *)(param_2 + 0x28);
  }
  fVar17 = (float)uVar19 * DAT_801127f8;
  if (2.1474836e+09 <= fVar17) {
    fVar17 = fVar17 - 2.1474836e+09;
  }
  fVar18 = (float)*(ushort *)(param_2 + 6) * DAT_801127fc;
  if (fVar18 < 2.1474836e+09) {
    uVar19 = (ushort)(int)fVar18;
  }
  else {
    uVar19 = (ushort)(int)(fVar18 - 2.1474836e+09);
  }
  fVar18 = (float)*(ushort *)(param_2 + 0x12) * DAT_801127fc;
  if (fVar18 < 2.1474836e+09) {
    uVar20 = (ushort)(int)fVar18;
  }
  else {
    uVar20 = (ushort)(int)(fVar18 - 2.1474836e+09);
  }
  fVar18 = (float)*(ushort *)(param_2 + 0x1e) * DAT_801127fc;
  if (fVar18 < 2.1474836e+09) {
    uVar21 = (ushort)(int)fVar18;
  }
  else {
    uVar21 = (ushort)(int)(fVar18 - 2.1474836e+09);
  }
  fVar18 = (float)*(ushort *)(param_2 + 0x2a) * DAT_801127fc;
  if (2.1474836e+09 <= fVar18) {
    fVar18 = fVar18 - 2.1474836e+09;
  }
  uVar2 = (int)fVar14 & 0xffff;
  uVar9 = (int)fVar15 & 0xffff;
  uVar7 = (int)fVar17 & 0xffff;
  if ((uVar2 == uVar9) || (uVar3 = (int)fVar16 & 0xffff, uVar2 == uVar7)) {
    DAT_800efd90 = 0;
    return param_1;
  }
  if (uVar3 == uVar9) {
    DAT_800efd90 = 0;
    return param_1;
  }
  if (uVar3 == uVar7) {
    DAT_800efd90 = 0;
    return param_1;
  }
  if ((uVar10 & 0xffff) <= uVar6) {
    uVar6 = uVar10;
  }
  uVar10 = uVar6 + 3 & 0xfffc;
  if ((DAT_800efd94 == -1) || (puVar13 = param_1, DAT_800efda4 != 1)) {
    *param_1 = 0xe7000000;
    param_1[1] = 0;
    DAT_800efd90 = 1;
    puVar13 = param_1 + 8;
    param_1[2] = 0xde000000;
    param_1[3] = (uint)&DAT_800efdf0;
    param_1[4] = 0xd7000002;
    param_1[5] = 0x80008000;
    DAT_800efda4 = 1;
    param_1[6] = 0xd9fffffe;
    param_1[7] = 0;
  }
  if (*(int *)param_2 != DAT_800efd94) {
    puVar12 = puVar13;
    if (DAT_800efd90 == 0) {
      puVar12 = puVar13 + 2;
      *puVar13 = 0xe7000000;
      puVar13[1] = 0;
      DAT_800efd90 = 1;
    }
    bVar1 = param_2[3];
    if (bVar1 == 1) {
      uVar6 = 0x112fffff;
      *puVar12 = 0xe200001c;
      puVar12[1] = 0x504240;
      puVar12[2] = 0xfa000000;
      puVar12[3] = 0x3e3e3e5c;
      puVar12[4] = 0xfcf197e3;
LAB_800468a8:
      puVar12[5] = uVar6;
    }
    else {
      if ((1 < bVar1) || (bVar1 != 0)) {
        *puVar12 = 0xe200001c;
        puVar12[1] = 0x504240;
        puVar12[2] = 0xfa000000;
        uVar6 = 0xff2cfe7f;
        puVar12[3] = *param_2 | 0xbcbcbc00;
        puVar12[4] = 0xfcff97ff;
        goto LAB_800468a8;
      }
      *puVar12 = 0xe200001c;
      puVar12[1] = 0x504240;
      puVar12[2] = 0xfa000000;
      puVar12[3] = ((uint)*param_2 * 2 + -1) * 0x1000000 | ((uint)param_2[1] * 2 - 1 & 0xff) << 0x10
                   | ((uint)param_2[2] * 2 - 1 & 0xff) << 8;
      puVar12[4] = 0xfcffffff;
      puVar12[5] = 0xfffcf279;
    }
    puVar13 = puVar12 + 6;
    DAT_800efd94 = *(int *)param_2;
  }
  if (*piVar11 == 1) {
    uVar6 = piVar11[5] + (uVar5 & 0xf8) + piVar11[1] * (uint)param_2[9];
    uVar5 = uVar10 + (uVar5 & 7) + 3 & 0xfffc;
    uVar10 = uVar6 | uVar5 << 0x10;
    if (DAT_800efd9c != uVar10) {
      puVar12 = puVar13;
      if (DAT_800efd90 == 0) {
        *puVar13 = 0xe7000000;
        puVar13[1] = 0;
        DAT_800efd90 = 1;
        puVar12 = puVar13 + 2;
      }
      puVar13 = puVar12 + 0xe;
      iVar4 = piVar11[1];
      DAT_800efd9c = uVar10;
      puVar12[1] = uVar6;
      *puVar12 = iVar4 - 1U & 0xfff | 0xfd480000;
      uVar6 = ((int)(uVar5 + 7) >> 3 & 0x1ffU) << 9 | 0xf5480000;
      puVar12[2] = uVar6;
      puVar12[3] = 0x7080200;
      puVar12[4] = 0xe6000000;
      uVar5 = ((uVar5 - 1) * 4 & 0xfff) << 0xc;
      uVar10 = ((uVar8 & 0xffff) - 1) * 4 & 0xfff;
      puVar12[5] = 0;
      puVar12[6] = 0xf4000000;
      puVar12[7] = uVar5 | uVar10 | 0x7000000;
      puVar12[8] = 0xe7000000;
      puVar12[9] = 0;
      puVar12[10] = uVar6;
      puVar12[0xb] = 0x80200;
      puVar12[0xc] = 0xf2000000;
      puVar12[0xd] = uVar5 | uVar10;
    }
    if (DAT_800efda0 == piVar11[6] + (uint)*(ushort *)(param_2 + 10)) goto LAB_80046d10;
    if (DAT_800efd90 == 0) {
      *puVar13 = 0xe7000000;
      puVar13[1] = 0;
      DAT_800efd90 = 1;
      puVar13 = puVar13 + 2;
    }
    uVar10 = 0xf5000100;
    uVar8 = 0x73f0000;
  }
  else {
    if (*piVar11 != 0) goto LAB_80046d10;
    uVar6 = uVar10 + (uVar5 & 0xf) + 3 & 0xfffc;
    uVar5 = piVar11[5] + ((uVar5 & 0xf0) >> 1) + ((uint)piVar11[1] >> 1) * (uint)param_2[9];
    uVar10 = uVar5 | uVar6 << 0x10;
    if (DAT_800efd9c != uVar10) {
      puVar12 = puVar13;
      if (DAT_800efd90 == 0) {
        *puVar13 = 0xe7000000;
        puVar13[1] = 0;
        DAT_800efd90 = 1;
        puVar12 = puVar13 + 2;
      }
      puVar13 = puVar12 + 0xe;
      uVar2 = piVar11[1];
      uVar7 = ((int)((uVar6 >> 1) + 7) >> 3 & 0x1ffU) << 9;
      DAT_800efd9c = uVar10;
      puVar12[1] = uVar5;
      *puVar12 = (uVar2 >> 1) - 1 & 0xfff | 0xfd480000;
      puVar12[2] = uVar7 | 0xf5480000;
      puVar12[3] = 0x7080200;
      puVar12[4] = 0xe6000000;
      puVar12[5] = 0;
      uVar10 = ((uVar8 & 0xffff) - 1) * 4 & 0xfff;
      puVar12[6] = 0xf4000000;
      puVar12[7] = ((uVar6 - 1) * 2 & 0xfff) << 0xc | uVar10 | 0x7000000;
      puVar12[8] = 0xe7000000;
      puVar12[9] = 0;
      puVar12[10] = uVar7 | 0xf5400000;
      puVar12[0xb] = 0xf80200;
      puVar12[0xc] = 0xf2000000;
      puVar12[0xd] = ((uVar6 - 1) * 4 & 0xfff) << 0xc | uVar10;
    }
    if (DAT_800efda0 == piVar11[6] + (uint)*(ushort *)(param_2 + 10)) goto LAB_80046d10;
    if (DAT_800efd90 == 0) {
      *puVar13 = 0xe7000000;
      puVar13[1] = 0;
      DAT_800efd90 = 1;
      puVar13 = puVar13 + 2;
    }
    uVar10 = 0xf50001f0;
    uVar8 = 0x7030000;
  }
  *puVar13 = 0xfd100000;
  puVar13[1] = piVar11[6] + (uint)*(ushort *)(param_2 + 10);
  puVar13[2] = 0xe8000000;
  puVar13[3] = 0;
  puVar13[5] = 0x7000000;
  puVar13[4] = uVar10;
  puVar13[6] = 0xe6000000;
  puVar13[7] = 0;
  puVar13[8] = 0xf0000000;
  puVar13[9] = uVar8 | 0xc000;
  puVar13[10] = 0xe7000000;
  puVar13[0xb] = 0;
  puVar13 = puVar13 + 0xc;
  DAT_800efda0 = piVar11[6] + (uint)*(ushort *)(param_2 + 10);
LAB_80046d10:
  *puVar13 = 0x1004008;
  puVar13[1] = (uint)&DAT_800efda8;
  puVar13[2] = 0x2180000;
  puVar13[3] = (int)fVar14 << 0x12 | (uint)uVar19 << 2;
  puVar13[4] = 0x2180002;
  puVar13[5] = (int)fVar15 << 0x12 | (uint)uVar20 << 2;
  puVar13[6] = 0x2180004;
  puVar13[7] = (int)fVar16 << 0x12 | (uint)uVar21 << 2;
  puVar13[8] = 0x2180006;
  puVar13[9] = (int)fVar17 << 0x12 | ((int)fVar18 & 0xffffU) << 2;
  puVar13[10] = 0x2140000;
  puVar13[0xb] = 0;
  puVar13[0xc] = 0x2140002;
  puVar13[0xd] = ((uint)param_2[0x2c] - (uint)param_2[8]) * 0x400000;
  puVar13[0xe] = 0x2140004;
  puVar13[0xf] = ((uint)param_2[0x2d] - (uint)param_2[9]) * 0x40;
  puVar13[0x10] = 0x2140006;
  puVar13[0x11] =
       ((uint)param_2[0x2c] - (uint)param_2[8]) * 0x400000 |
       ((uint)param_2[0x2d] - (uint)param_2[9]) * 0x40;
  puVar13[0x12] = 0x7000406;
  puVar13[0x13] = 0x602;
  puVar13[0x14] = 0xe7000000;
  puVar13[0x15] = 0;
  return puVar13 + 0x16;
}
