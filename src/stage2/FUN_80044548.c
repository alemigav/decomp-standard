/* FUN_80044548
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80044548  body 0x80044548..0x80044fdb  size 2708 B
 * body sha256 68c269ccb65a523279ab2b32d3b1b5848d6f08cf642b6acb574863c65eb2d103
 * provider record sha256 3374a14a24141711072d989a94b66dc1c762f75666171946cc34a0df39ca594e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_80044548(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar4;
  uint uVar3;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  byte *pbVar13;
  short sVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  short sVar18;
  uint uVar19;
  uint uVar20;
  short sVar21;
  short sVar22;
  float fVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  int iVar28;
  short local_4a;
  
  if (&UNK_800dd4c0 < param_1) {
    return param_1;
  }
  pbVar13 = *(byte **)(param_2 + 0x24);
  DAT_800efd90 = 0;
  param_2[0x22] = 0;
  param_2[0x23] = 0;
  local_4a = *(short *)(param_2 + 0x1c);
  sVar18 = 1;
  if (*(short *)(param_2 + 0x1c) < *(short *)(param_2 + 4)) {
    sVar22 = local_4a;
    local_4a = *(short *)(param_2 + 4);
  }
  else {
    sVar22 = *(short *)(param_2 + 4);
  }
  sVar14 = *(short *)(param_2 + 6);
  sVar21 = *(short *)(param_2 + 0x1e);
  if (*(short *)(param_2 + 0x1e) < *(short *)(param_2 + 6)) {
    sVar21 = sVar14;
    sVar14 = *(short *)(param_2 + 0x1e);
  }
  if (local_4a < 0) {
    return param_1;
  }
  if (sVar21 < 0) {
    return param_1;
  }
  if (0x13f < sVar22) {
    return param_1;
  }
  if (0xef < sVar14) {
    return param_1;
  }
  uVar15 = (uint)param_2[8];
  uVar16 = (uint)param_2[9];
  uVar4 = (ushort)param_2[0x20] - (ushort)param_2[8];
  uVar20 = param_2[0x21] - uVar16;
  uVar24 = (uint)((float)(int)sVar22 * DAT_801127f8);
  uVar25 = (uint)((float)(int)local_4a * DAT_801127f8);
  uVar6 = uVar25 - uVar24;
  uVar26 = (uint)((float)(int)sVar14 * DAT_801127fc);
  uVar27 = (uint)((float)(int)sVar21 * DAT_801127fc);
  uVar17 = uVar27 - uVar26;
  fVar23 = (float)uVar4 / (float)(uVar6 & 0xffff);
  if ((short)uVar24 < 0) {
    iVar28 = (int)((float)(int)(short)uVar24 * fVar23);
    uVar15 = uVar15 - iVar28;
    if ((int)(uint)uVar4 <= -(int)(short)iVar28) {
      return param_1;
    }
    uVar24 = 0;
  }
  if ((short)uVar26 < 0) {
    iVar28 = (int)((float)(int)(short)uVar26 * fVar23);
    uVar16 = uVar16 - iVar28;
    if ((int)(uVar20 & 0xffff) <= iVar28 * -0x10000 >> 0x10) {
      return param_1;
    }
    uVar26 = 0;
  }
  uVar19 = (uint)uVar4 + (uVar15 & 0xf) + 0xf & 0xfff0;
  if (0x1000 < (int)(uVar19 * (uVar20 & 0xffff))) {
    uVar20 = (uVar20 & 0xffff) >> 1;
    uVar17 = (uVar17 & 0xffff) >> 1;
    uVar27 = uVar26 + uVar17;
    sVar18 = 2;
  }
  if ((DAT_800efd94 == -1) || (DAT_800efda4 != 1)) {
    puVar10 = param_1;
    if (DAT_800efd90 == 0) {
      puVar10 = param_1 + 2;
      *param_1 = 0xe7000000;
      param_1[1] = 0;
      DAT_800efd90 = 1;
    }
    puVar11 = puVar10 + 4;
    *puVar10 = 0xde000000;
    puVar10[1] = &DAT_800efdf0;
    puVar10[2] = 0xd7000002;
    puVar10[3] = 0x80008000;
    DAT_800efda4 = 1;
  }
  else {
    puVar10 = param_1;
    if (DAT_800efd90 == 0) {
      puVar10 = param_1 + 2;
      *param_1 = 0xe7000000;
      param_1[1] = 0;
      DAT_800efd90 = 1;
    }
    puVar11 = puVar10 + 2;
    *puVar10 = 0xde000000;
    puVar10[1] = &DAT_800efe68;
  }
  if ((DAT_800efd94 == *(int *)param_2) && (iVar28 = *(int *)pbVar13, DAT_800efd98 == iVar28))
  goto LAB_80044bcc;
  puVar10 = puVar11;
  if (DAT_800efd90 == 0) {
    puVar10 = puVar11 + 2;
    *puVar11 = 0xe7000000;
    puVar11[1] = 0;
    DAT_800efd90 = 1;
  }
  bVar1 = param_2[3];
  if ((bVar1 & 0xf) == 1) {
    if (((*(int *)pbVar13 == 0) || ((bVar1 & 0x10) != 0)) && ((bVar1 & 0x20) == 0)) {
      puVar11 = puVar10 + 6;
      *puVar10 = 0xe200001c;
      puVar10[1] = 0x5049d8;
      puVar10[2] = 0xfa000000;
      puVar10[3] = 0x3e3e3e5c;
      puVar10[4] = 0xfcf197e3;
      puVar10[5] = 0x112fffff;
    }
    else {
      puVar11 = puVar10 + 6;
      *puVar10 = 0xe200001c;
      puVar10[1] = 0x5048d0;
      param_2[2] = 0;
      param_2[1] = 0;
      *param_2 = 0;
      puVar10[2] = 0xfa000000;
      puVar10[3] = (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[2] << 8 | 0x9e;
      puVar10[4] = 0xfc119623;
      puVar10[5] = 0xff2fffff;
    }
  }
  else if (((bVar1 & 0xf) < 2) && ((bVar1 & 0xf) == 0)) {
    if (((*(int *)pbVar13 == 0) || ((bVar1 & 0x10) != 0)) && ((bVar1 & 0x20) == 0)) {
      puVar11 = puVar10 + 4;
      *puVar10 = 0xe200001c;
      puVar10[1] = 0x5049d8;
      puVar10[2] = 0xfcffffff;
      puVar10[3] = 0xfffcf279;
    }
    else {
      *puVar10 = 0xe200001c;
      puVar10[1] = 0x5048d0;
LAB_80044b34:
      puVar11 = puVar10 + 6;
      uVar2 = *(ushort *)
               ((uint)*pbVar13 * 2 + *(int *)(pbVar13 + 0x18) + (uint)*(ushort *)(param_2 + 10));
      bVar1 = pbVar13[1];
      *param_2 = (byte)(uVar2 >> 8) & 0xf8;
      param_2[1] = (byte)((uVar2 & 0x7c0) >> 3);
      param_2[2] = (byte)((uVar2 & 0x3e) << 2);
      puVar10[2] = 0xfa000000;
      puVar10[3] = (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[2] << 8 |
                   (uint)bVar1;
      puVar10[4] = 0xfc119623;
      puVar10[5] = 0xff2fffff;
    }
  }
  else {
    *puVar10 = 0xe200001c;
    puVar10[1] = 0x5048d0;
    if (((*(int *)pbVar13 != 0) && ((param_2[3] & 0x10) == 0)) || ((param_2[3] & 0x20) != 0))
    goto LAB_80044b34;
    puVar11 = puVar10 + 6;
    puVar10[2] = 0xfa000000;
    puVar10[3] = 0x80808058;
    puVar10[4] = 0xfcff97ff;
    puVar10[5] = 0xff2cfe7f;
  }
  DAT_800efd94 = *(int *)param_2;
  DAT_800efd98 = *(int *)pbVar13;
  iVar28 = *(int *)pbVar13;
LAB_80044bcc:
  if (((iVar28 == 0) || ((param_2[3] & 0x10) != 0)) && ((param_2[3] & 0x20) == 0)) {
    iVar28 = *(int *)(pbVar13 + 0x18) + (uint)*(ushort *)(param_2 + 10);
    puVar10 = puVar11;
    if (DAT_800efda0 != iVar28) {
      puVar10 = puVar11 + 0xc;
      *puVar11 = 0xfd100000;
      puVar11[1] = iVar28;
      puVar11[2] = 0xe8000000;
      puVar11[3] = 0;
      puVar11[5] = 0x7000000;
      puVar11[4] = 0xf5000100;
      puVar11[6] = 0xe6000000;
      puVar11[7] = 0;
      puVar11[8] = 0xf0000000;
      DAT_800efda0 = iVar28;
      puVar11[9] = 0x703c000;
      puVar11[10] = 0xe7000000;
      puVar11[0xb] = 0;
    }
  }
  else {
    puVar10 = puVar11 + 2;
    DAT_800efda0 = -1;
    *puVar11 = 0xe3001001;
    puVar11[1] = 0;
  }
  uVar9 = (((int)uVar19 >> 1) + 7 >> 3 & 0x1ffU) << 9;
  uVar5 = ((uVar20 & 0xffff) - 1) * 4 & 0xfff;
  uVar12 = ((uVar19 - 1) * 2 & 0xfff) << 0xc | uVar5 | 0x7000000;
  uVar6 = uVar6 & 0xffff;
  puVar7 = puVar10 + -1;
  while( true ) {
    if (sVar18 == 0) {
      return puVar10;
    }
    if (&UNK_800dd4c0 < puVar10) break;
    DAT_800efd9c = *(int *)(pbVar13 + 0x14) + ((uVar15 & 0xfff0) >> 1) +
                   (*(uint *)(pbVar13 + 4) >> 1) * (uVar16 & 0xffff);
    if ((*(int *)pbVar13 == 0) && ((param_2[3] & 0x20) == 0)) {
      puVar7[1] = (*(uint *)(pbVar13 + 4) >> 1) - 1 & 0xfff | 0xfd480000;
      puVar7[2] = DAT_800efd9c;
      puVar7[4] = 0x7080200;
      puVar7[3] = uVar9 | 0xf5480000;
      puVar7[5] = 0xe6000000;
      puVar7[6] = 0;
      puVar7[7] = 0xf4000000;
      puVar7[8] = uVar12;
      puVar7[9] = 0xe7000000;
      puVar7[10] = 0;
      puVar7[0xb] = uVar9 | 0xf5400000;
      puVar7[0xc] = 0x80200;
    }
    else {
      uVar3 = *(uint *)(pbVar13 + 4);
      puVar7[2] = DAT_800efd9c;
      puVar7[1] = (uVar3 >> 1) - 1 & 0xfff | 0xfd880000;
      puVar7[3] = uVar9 | 0xf5880000;
      puVar7[4] = 0x7080200;
      puVar7[5] = 0xe6000000;
      puVar7[6] = 0;
      puVar7[7] = 0xf4000000;
      puVar7[8] = uVar12;
      puVar7[9] = 0xe7000000;
      puVar7[10] = 0;
      puVar7[0xb] = uVar9 | 0xf5800000;
      puVar7[0xc] = 0x80200;
    }
    puVar11 = puVar10 + 0xe;
    puVar8 = puVar7 + 0xe;
    puVar7[0xd] = 0xf2000000;
    *puVar8 = ((uVar19 - 1) * 4 & 0xfff) << 0xc | uVar5;
    if ((uVar6 != 0) && ((uVar17 & 0xffff) != 0)) {
      puVar7[0xf] = 0xee000000;
      puVar7[0x10] = (uint)*(ushort *)(param_2 + 0x1a) << 0x10 | 1;
      puVar7[0x11] = (uVar25 & 0x3ff) << 0xe | (uVar27 & 0x3ff) << 2 | 0xe4000000;
      puVar7[0x12] = (uVar24 & 0x3ff) << 0xe | (uVar26 & 0x3ff) << 2;
      puVar11 = puVar10 + 0x16;
      puVar7[0x13] = 0xe1000000;
      puVar7[0x14] = (uVar15 & 0xf) << 0x15;
      puVar8 = puVar7 + 0x16;
      puVar7[0x15] = 0xf1000000;
      *puVar8 = (int)(((double)uVar4 * 1024.0) / (double)uVar6) << 0x10 |
                (int)(((double)(uVar20 & 0xffff) * 1024.0) / (double)(uVar17 & 0xffff)) & 0xffffU;
    }
    sVar18 = sVar18 + -1;
    uVar26 = uVar26 + uVar17;
    uVar27 = uVar27 + uVar17;
    uVar16 = uVar16 + uVar20;
    puVar7 = puVar8;
    puVar10 = puVar11;
  }
  return puVar10;
}
