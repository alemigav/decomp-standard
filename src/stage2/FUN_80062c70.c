/* FUN_80062c70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062c70  body 0x80062c70..0x80062cfb  size 140 B
 * body sha256 716c9fd7e7fb3d9235aeabd85d452405d1c8e3fb5ccb8147db87078e395b3103
 * provider record sha256 ea6cf81394d2de55f95132ebb5a7a0230aae4a07ea9ed67e6384d0e75a98f61a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined2 FUN_80062c70(float param_1)

{
  undefined2 uVar1;
  
  param_1 = param_1 * 32.0;
  if (param_1 < 512.0) {
    param_1 = 512.0;
  }
  uVar1 = FUN_80062b80(((int)(((-param_1 * DAT_800efc54 + DAT_800efc58) / --param_1) * 16352.0 +
                             16352.0) << 0x10) >> 0xd);
  return uVar1;
}
