/* FUN_80025130
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025130  body 0x80025130..0x8002534f  size 544 B
 * body sha256 ef9906b5a375888c6a93dfcc853b6cc73af2b872ead46f28b458db422b24f587
 * provider record sha256 60ba2ddd7b4d67a2d55907b2bf1b4c9352c36aec4c4595542e889ee3520817cf
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025130(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  iVar5 = DAT_801137d8;
  iVar3 = DAT_800c56f0;
  fVar1 = (float)DAT_801137d8;
  *(undefined **)(DAT_800c56f0 + 0x10) = &DAT_8001f7c0;
  puVar8 = *(undefined4 **)(iVar3 + 0x30);
  *(undefined **)(iVar3 + 0x18) = &DAT_800bc630;
  *puVar8 = 0xdb060000;
  puVar8[1] = 0;
  puVar8[2] = 0xde000000;
  puVar8[3] = &DAT_800efcc8;
  puVar8[4] = 0xed000000;
  iVar6 = DAT_801137dc;
  if (iVar5 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  fVar2 = (float)DAT_801137dc;
  if (DAT_801137dc < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  puVar8[5] = ((int)(fVar1 * 4.0) & 0xfffU) << 0xc | (int)(fVar2 * 4.0) & 0xfffU;
  uVar4 = DAT_8010b6fc;
  puVar8[6] = 0xfe000000;
  puVar8[7] = uVar4;
  puVar8[9] = &DAT_800d0fe0;
  puVar8[8] = 0xde010000;
  puVar8 = DAT_800df8b4;
  puVar7 = DAT_800df8b4 + 2;
  *DAT_800df8b4 = 0xde000000;
  DAT_800df8b4 = puVar7;
  puVar8[1] = &DAT_800efc60;
  puVar8 = DAT_800df8b4;
  fVar1 = (float)iVar5;
  puVar7 = DAT_800df8b4 + 2;
  *DAT_800df8b4 = 0xed000000;
  DAT_800df8b4 = puVar7;
  if (iVar5 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  fVar2 = (float)iVar6;
  if (iVar6 < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  puVar8[1] = ((int)(fVar1 * 4.0) & 0xfffU) << 0xc | (int)(fVar2 * 4.0) & 0xfffU;
  puVar8 = DAT_800df8b4;
  puVar7 = DAT_800df8b4 + 2;
  *DAT_800df8b4 = 0xde010000;
  DAT_800df8b4 = puVar7;
  puVar8[1] = &DAT_800de460;
  puVar8 = DAT_800df8b8;
  puVar7 = DAT_800df8b8 + 2;
  *DAT_800df8b8 = 0xe9000000;
  DAT_800df8b8 = puVar7;
  puVar8[1] = 0;
  puVar8 = DAT_800df8b8;
  puVar7 = DAT_800df8b8 + 2;
  *DAT_800df8b8 = 0xdf000000;
  DAT_800df8b8 = puVar7;
  puVar8[1] = 0;
  *(undefined4 *)(iVar3 + 4) = 6;
  *(undefined4 *)(iVar3 + 0x34) = 0;
  return;
}
