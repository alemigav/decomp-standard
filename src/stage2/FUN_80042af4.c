/* FUN_80042af4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80042af4  body 0x80042af4..0x80042d5b  size 616 B
 * body sha256 15c6fd9228cd2bd7c0c3a7cf4c4b0e52bb0eda1c50fd3b8d1bc99928d3aa5b66
 * provider record sha256 ab93c4c286d5a6e6c85d65b8e827d941438a0dd8b37e2893810f7217e53581d2
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_80042af4(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)0x0;
  if (param_1 == (undefined4 *)0x0) {
    param_1 = DAT_800df8b0;
    puVar3 = DAT_800df8b0;
  }
  *param_1 = 0xe7000000;
  param_1[1] = 0;
  param_1[3] = &DAT_801315f0;
  param_1[2] = 0xdc080008;
  func_0x80009470(&DAT_80131600,&DAT_80131710,DAT_80131700,DAT_8013170c,DAT_80131704,DAT_80131708,
                  0x3f800000);
  param_1[4] = 0xda380007;
  param_1[5] = &DAT_80131600;
  param_1[6] = 0xdb0e0000;
  param_1[7] = 0;
  param_1[9] = &DAT_80131640;
  param_1[8] = 0xda380003;
  param_1[10] = 0xfcffffff;
  param_1[0xb] = 0xfffe793c;
  param_1[0xd] = &DAT_80131590;
  param_1[0xc] = 0xda380005;
  param_1[0xe] = 0xd7000000;
  param_1[0xf] = 0;
  param_1[0x11] = 0x80000;
  param_1[0x10] = 0xe3000c00;
  param_1[0x12] = 0xd9d0f9fa;
  param_1[0x13] = 0;
  if (DAT_80131730 == 0) {
    uVar2 = 0x220404;
    uVar1 = 0xf0a4000;
  }
  else {
    uVar2 = 0x220405;
    uVar1 = 0x552230;
  }
  param_1[0x14] = 0xd9ffffff;
  param_1[0x15] = uVar2;
  param_1[0x16] = 0xe200001c;
  param_1[0x17] = uVar1;
  param_1[0x18] = 0xe2001d00;
  param_1[0x19] = 0;
  param_1[0x1a] = 0xe3000a01;
  param_1[0x1b] = 0;
  if (puVar3 != (undefined4 *)0x0) {
    DAT_800df8b0 = param_1 + 0x1c;
    FUN_800856a4();
  }
  return param_1 + 0x1c;
}
