/* FUN_80069338
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069338  body 0x80069338..0x8006944b  size 276 B
 * body sha256 12c00df2bfe725b0411e1ea4abffaa891c4326b746597852b20058a5632242a2
 * provider record sha256 598d8556d282845b80a70eddafae856d6f60437be162320d2a510f0f02205ee9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80069338(int *param_1,undefined4 param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_3[3];
  uVar3 = (uint)(*param_1 -
                ((int)((((uint)param_3[2] + (uint)*param_3) - (uint)(uVar1 >> 1)) * 0x10000) >> 0x10
                )) >> 0x1e & 2 |
          (uint)(*param_1 - ((int)(((uint)*param_3 + (uint)(uVar1 >> 1)) * 0x10000) >> 0x10)) >>
          0x1f;
  uVar2 = (uint)(uVar3 < 3);
  if (uVar3 == 2) {
    uVar2 = 1;
  }
  else if (uVar2 == 0) {
    uVar2 = 3;
    if (uVar3 == 3) {
      _DAT_80139e50 = *param_3;
      _DAT_80139e56 = param_3[3];
      _DAT_80139e52 = param_3[1];
      _DAT_80139e54 = uVar1;
      uVar2 = FUN_800691c0(param_1,param_2);
    }
  }
  else if (uVar3 == 0) {
    _DAT_80139e50 = (param_3[2] + *param_3) - param_3[3];
    _DAT_80139e56 = param_3[3];
    _DAT_80139e52 = param_3[1];
    _DAT_80139e54 = uVar1;
    uVar2 = FUN_800691c0(param_1,param_2);
  }
  return uVar2;
}
