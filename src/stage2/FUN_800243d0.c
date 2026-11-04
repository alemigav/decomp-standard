/* FUN_800243d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800243d0  body 0x800243d0..0x80024557  size 392 B
 * body sha256 a221f5cdeecfe7cf44dcd9c6f514c27dd05cdbb5beaaec004d04c091dc65e867
 * provider record sha256 74e5409966581c8c8aa1376af55d16abca981eab671e66a54565b5253f036d81
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_800243d0(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = DAT_801137d8;
  *param_1 = 0xe7000000;
  param_1[1] = 0;
  param_1[2] = iVar3 - 1U & 0xfff | 0xff100000;
  fVar1 = (float)iVar3;
  param_1[3] = DAT_800c4f18;
  param_1[4] = 0xed000000;
  iVar4 = DAT_801137dc;
  if (iVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  fVar2 = (float)DAT_801137dc;
  if (DAT_801137dc < 0) {
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
  param_1[0xd] = 0xfffdfffd;
  param_1[0xe] = (iVar3 - 1U & 0x3ff) << 0xe | (iVar4 - 1U & 0x3ff) << 2 | 0xf6000000;
  param_1[0xf] = 0;
  return param_1 + 0x10;
}
