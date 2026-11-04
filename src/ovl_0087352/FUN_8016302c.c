/* FUN_8016302c
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x8016302c  body 0x8016302c..0x801630ef  size 196 B
 * body sha256 9a8a3a89ef74f8733efefa1437bb61404c6181ff4d09883e7fde383b3a8ba150
 * provider record sha256 6faedc22a0083ee48f0f19a7ed96d07a6dd50aab68edcfe9e3ef7a7ea980cea6
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016302c(int param_1)

{
  short sVar1;
  
  if (_DAT_800e138e + -0x708 < *(int *)(param_1 + 0x2c)) {
    FUN_80165c68(param_1,4);
  }
  sVar1 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar1;
  if (sVar1 == -1) {
    FUN_80165c68(param_1,4);
  }
  FUN_80165c74(param_1);
  if ((_DAT_800e1322 < 0) && (*(char *)(param_1 + 0x2bd) < '\x01')) {
    FUN_80165ff0(param_1);
  }
  else {
    FUN_80165da8(param_1);
    FUN_80165f80(param_1);
  }
  return;
}
