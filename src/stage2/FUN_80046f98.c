/* FUN_80046f98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80046f98  body 0x80046f98..0x80047297  size 768 B
 * body sha256 5797d96544f6a0ba5522da7cb6cf7a4a74f82a402c28f76d610622c5b8cd6c54
 * provider record sha256 cad9c786dda39e4e003af53749688d6e6404919593062d7b04a970a8cce27af2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint * FUN_80046f98(uint *param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  uVar7 = (uint)*(short *)(param_2 + 8);
  uVar1 = *(ushort *)(param_2 + 10);
  if (((int)uVar7 < 0) &&
     (iVar6 = -uVar7, uVar7 = 0, (int)(uint)*(ushort *)(param_2 + 0xc) <= iVar6)) {
    return param_1;
  }
  sVar2 = *(short *)(param_2 + 8);
  sVar3 = *(short *)(param_2 + 0xc);
  sVar4 = *(short *)(param_2 + 10);
  sVar5 = *(short *)(param_2 + 0xe);
  *param_1 = 0xe7000000;
  param_1[1] = 0;
  if ((DAT_800efd94 == -1) || (DAT_800efda4 != 0)) {
    puVar8 = param_1 + 6;
    param_1[2] = 0xde000000;
    param_1[3] = (uint)&DAT_800efdf0;
    param_1[4] = 0xd7000000;
    param_1[5] = 0x80008000;
    DAT_800efda4 = 0;
  }
  else {
    puVar8 = param_1 + 4;
    param_1[2] = 0xde000000;
    param_1[3] = (uint)&DAT_800efe68;
  }
  puVar9 = puVar8 + 6;
  *puVar8 = 0xe200001c;
  puVar8[1] = 0x504240;
  puVar8[2] = 0xfa000000;
  fVar11 = (float)(uVar7 & 0xffff) * DAT_801127f8;
  puVar8[3] = (uint)*(byte *)(param_2 + 4) << 0x18 | (uint)*(byte *)(param_2 + 5) << 0x10 |
              (uint)*(byte *)(param_2 + 6) << 8 | (uint)*(byte *)(param_2 + 7);
  puVar8[4] = 0xfcffffff;
  puVar8[5] = 0xfffdf6fb;
  if (2.1474836e+09 <= fVar11) {
    fVar11 = fVar11 - 2.1474836e+09;
  }
  fVar12 = (float)(ushort)(sVar2 + sVar3) * DAT_801127f8;
  if (2.1474836e+09 <= fVar12) {
    fVar12 = fVar12 - 2.1474836e+09;
  }
  fVar13 = (float)uVar1 * DAT_801127fc;
  if (2.1474836e+09 <= fVar13) {
    fVar13 = fVar13 - 2.1474836e+09;
  }
  fVar14 = (float)(ushort)(sVar4 + sVar5) * DAT_801127fc;
  if (2.1474836e+09 <= fVar14) {
    fVar14 = fVar14 - 2.1474836e+09;
  }
  puVar10 = puVar9;
  if ((*(short *)(param_2 + 0xc) != 0) && (*(short *)(param_2 + 0xe) != 0)) {
    puVar10 = puVar8 + 8;
    *puVar9 = ((int)fVar12 & 0x3ffU) << 0xe | ((int)fVar14 & 0x3ffU) << 2 | 0xf6000000;
    puVar8[7] = ((int)fVar11 & 0x3ffU) << 0xe | ((int)fVar13 & 0x3ffU) << 2;
  }
  return puVar10;
}
