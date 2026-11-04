/* FUN_80047298
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047298  body 0x80047298..0x80047823  size 1420 B
 * body sha256 449d11329231834c2e629a5f5753d0bb73d1b7c7e5d3ce531ac95730f1ee442d
 * provider record sha256 ac93b19e335c6e7c4d0b9975ade55032a990d7936648d86269d90f0d99e030c4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_80047298(undefined4 *param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  fVar5 = (float)*(ushort *)(param_2 + 4) * DAT_801127f8;
  if (2.1474836e+09 <= fVar5) {
    fVar5 = fVar5 - 2.1474836e+09;
  }
  fVar6 = (float)*(ushort *)(param_2 + 6) * DAT_801127fc;
  if (2.1474836e+09 <= fVar6) {
    fVar6 = fVar6 - 2.1474836e+09;
  }
  fVar7 = (float)*(ushort *)(param_2 + 8) * DAT_801127f8;
  if (2.1474836e+09 <= fVar7) {
    fVar7 = fVar7 - 2.1474836e+09;
  }
  fVar8 = (float)*(ushort *)(param_2 + 10) * DAT_801127fc;
  if (2.1474836e+09 <= fVar8) {
    fVar8 = fVar8 - 2.1474836e+09;
  }
  fVar9 = (float)*(ushort *)(param_2 + 4) * DAT_801127f8;
  if (2.1474836e+09 <= fVar9) {
    fVar9 = fVar9 - 2.1474836e+09;
  }
  fVar10 = (float)*(ushort *)(param_2 + 6) * DAT_801127fc;
  if (2.1474836e+09 <= fVar10) {
    fVar10 = fVar10 - 2.1474836e+09;
  }
  fVar11 = (float)*(ushort *)(param_2 + 8) * DAT_801127f8;
  if (2.1474836e+09 <= fVar11) {
    fVar11 = fVar11 - 2.1474836e+09;
  }
  fVar12 = (float)*(ushort *)(param_2 + 10) * DAT_801127fc;
  if (2.1474836e+09 <= fVar12) {
    fVar12 = fVar12 - 2.1474836e+09;
  }
  *param_1 = 0xe7000000;
  param_1[1] = 0;
  puVar3 = param_1 + 2;
  if (DAT_800efda4 != 0) {
    puVar3 = param_1 + 6;
    param_1[2] = 0xd9c0f9fb;
    param_1[3] = 0;
    param_1[4] = 0xd7000000;
    param_1[5] = 0x80008000;
    DAT_800efda4 = 0;
  }
  *puVar3 = 0xde000000;
  puVar3[1] = &DAT_800efe68;
  puVar4 = puVar3 + 2;
  if (*(int *)param_2 != DAT_800efd94) {
    if (param_2[3] == 0) {
      *puVar4 = 0xe200001c;
      puVar3[3] = 0x504240;
      puVar3[4] = 0xfa000000;
      puVar3[5] = (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[2] << 8 | 0xff;
      puVar3[6] = 0xfcffffff;
      puVar3[7] = 0xfffdf6fb;
      puVar4 = puVar3 + 8;
    }
    else if (param_2[3] == 4) {
      *puVar4 = 0xe200001c;
      puVar3[3] = 0x504240;
      uVar1 = (uint)param_2[2] + (uint)*param_2 + (uint)param_2[1];
      if (uVar1 < 0x1ff) {
        uVar1 = uVar1 >> 1;
      }
      else {
        uVar1 = 0x1ff;
      }
      puVar3[4] = 0xfa000000;
      uVar2 = (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[2] << 8;
      if (0x2f < uVar1) {
        uVar2 = uVar2 | uVar1 & 0xff;
      }
      puVar3[5] = uVar2;
      puVar3[6] = 0xfcffffff;
      puVar3[7] = 0xfffdf6fb;
      puVar4 = puVar3 + 8;
    }
    DAT_800efd94 = *(int *)param_2;
  }
  *puVar4 = 0x1004008;
  puVar4[1] = &DAT_800efda8;
  puVar4[2] = 0x2180000;
  puVar4[3] = ((int)fVar5 + 1) * 0x40000 | ((int)fVar6 & 0xffffU) << 2;
  puVar4[5] = ((int)fVar7 + 1) * 0x40000 | ((int)fVar8 + 1U & 0xffff) << 2;
  puVar4[4] = 0x2180002;
  puVar4[7] = (int)fVar9 << 0x12 | ((int)fVar10 + 1U & 0xffff) << 2;
  puVar4[6] = 0x2180004;
  puVar4[8] = 0x2180006;
  puVar4[9] = (int)fVar11 << 0x12 | ((int)fVar12 & 0xffffU) << 2;
  puVar4[10] = 0x6000204;
  puVar4[0xb] = 0x40600;
  return puVar4 + 0xc;
}
