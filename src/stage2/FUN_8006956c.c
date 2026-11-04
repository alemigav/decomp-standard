/* FUN_8006956c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006956c  body 0x8006956c..0x8006967f  size 276 B
 * body sha256 67f8c3381e77275c54a10f95a0272d524cf2b49a2d3b285828ec3c473ec31e47
 * provider record sha256 2e73c869c85da794057e0e8f26b97294449db0fbadaaaf5c328c191bbcb187ec
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8006956c(int param_1,undefined4 param_2,undefined2 *param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_3[2];
  uVar3 = (uint)(*(int *)(param_1 + 8) -
                ((int)((((uint)(ushort)param_3[3] + (uint)(ushort)param_3[1]) - (uint)(uVar1 >> 1))
                      * 0x10000) >> 0x10)) >> 0x1e & 2 |
          (uint)(*(int *)(param_1 + 8) -
                ((int)(((uint)(ushort)param_3[1] + (uint)(uVar1 >> 1)) * 0x10000) >> 0x10)) >> 0x1f;
  uVar2 = (uint)(uVar3 < 3);
  if (uVar3 == 2) {
    uVar2 = 1;
  }
  else if (uVar2 == 0) {
    uVar2 = 3;
    if (uVar3 == 3) {
      _DAT_80139e52 = param_3[1];
      _DAT_80139e54 = param_3[2];
      _DAT_80139e50 = *param_3;
      _DAT_80139e56 = uVar1;
      uVar2 = FUN_800691c0(param_1,param_2);
    }
  }
  else if (uVar3 == 0) {
    _DAT_80139e52 = (param_3[3] + param_3[1]) - param_3[2];
    _DAT_80139e54 = param_3[2];
    _DAT_80139e50 = *param_3;
    _DAT_80139e56 = uVar1;
    uVar2 = FUN_800691c0(param_1,param_2);
  }
  return uVar2;
}
