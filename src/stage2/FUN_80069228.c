/* FUN_80069228
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069228  body 0x80069228..0x80069337  size 272 B
 * body sha256 06a11a1e9c6f1ece410375ef7e2b72246a476a542f73175480e903ff85228f0f
 * provider record sha256 d50967330c5910563d42c95f62a4ca70bd3896fb4f8ff03dec61362cf49a76e2
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80069228(int param_1,undefined4 param_2,ushort *param_3)

{
  uint uVar1;
  
  uVar1 = (uint)(param_3[3] >> 1);
  uVar1 = (uint)(*(int *)(param_1 + 0x120) -
                ((int)((((uint)param_3[2] + (uint)*param_3) - uVar1) * 0x10000) >> 0x10)) >> 0x1e &
          2 | (uint)(*(int *)(param_1 + 0x120) - ((int)((*param_3 + uVar1) * 0x10000) >> 0x10)) >>
              0x1f;
  if (uVar1 == 2) {
    FUN_80066ec8(param_1,param_2,param_3);
  }
  else {
    if (uVar1 < 3) {
      if (uVar1 != 0) {
        return;
      }
      _DAT_80139e50 = (param_3[2] + *param_3) - param_3[3];
      _DAT_80139e56 = param_3[3];
    }
    else {
      if (uVar1 != 3) {
        return;
      }
      _DAT_80139e50 = *param_3;
      _DAT_80139e56 = param_3[3];
    }
    _DAT_80139e52 = param_3[1];
    _DAT_80139e54 = param_3[3];
    FUN_80069090(param_1,param_2);
  }
  return;
}
