/* FUN_80162e84
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80162e84  body 0x80162e84..0x80162f47  size 196 B
 * body sha256 c6fc6536789082233264219a27751677408889427db98966d08f2149521d13d4
 * provider record sha256 ca2ea6dc34a62cfd181ff8e32e6b54e1206f0476045b2835ba3c66b570d30265
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162e84(int param_1)

{
  short sVar1;
  
  if (*(int *)(param_1 + 0x2c) < _DAT_800e138e + -0x12c0) {
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
