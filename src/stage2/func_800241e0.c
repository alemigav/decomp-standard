/* func_800241e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800241e0  body 0x800241e0..0x800243cf  size 496 B
 * body sha256 003c91ad8849814be1e290672a006e790872dc7e1326cab6230c65dadc664ddc
 * provider record sha256 d3d478482e71070af8f9e398692dcca508839f49de42a3b31c1e5c25db39babe
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * func_800241e0(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  *param_1 = 0xe7000000;
  param_1[1] = 0;
  iVar4 = DAT_801137f0;
  fVar1 = (float)DAT_801137f0;
  uVar6 = DAT_801137f0 - 1;
  uVar7 = uVar6 & 0xfff | 0xff100000;
  param_1[3] = DAT_8010b6e0;
  param_1[2] = uVar7;
  param_1[4] = 0xed000000;
  iVar5 = DAT_801137f4;
  if (iVar4 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  fVar2 = (float)DAT_801137f4;
  if (DAT_801137f4 < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  param_1[5] = ((int)(fVar1 * 4.0) & 0xfffU) << 0xc | (int)(fVar2 * 4.0) & 0xfffU;
  param_1[7] = 0x300000;
  param_1[6] = 0xe3000a01;
  param_1[8] = 0xfcffffff;
  param_1[9] = 0xfffe793c;
  param_1[10] = 0xe200001c;
  param_1[0xb] = 0xf0a4000;
  param_1[0xc] = 0xf7000000;
  param_1[0xd] = 0;
  uVar3 = DAT_8010b6e4;
  uVar6 = (uVar6 & 0x3ff) << 0xe | (iVar5 - 1U & 0x3ff) << 2 | 0xf6000000;
  param_1[0xe] = uVar6;
  param_1[0xf] = 0;
  param_1[0x10] = 0xe7000000;
  param_1[0x11] = 0;
  param_1[0x12] = uVar7;
  param_1[0x13] = uVar3;
  param_1[0x14] = uVar6;
  param_1[0x15] = 0;
  param_1[0x16] = 0xe7000000;
  param_1[0x17] = 0;
  return param_1 + 0x18;
}
