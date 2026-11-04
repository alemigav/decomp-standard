/* FUN_800ac0c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac0c8  body 0x800ac0c8..0x800ac393  size 716 B
 * body sha256 40264347270de9662df5a3db7daff4369c007458c791fd7a1f88ee799abe36b3
 * provider record sha256 461486552f695f4b12a912176daaf209c0cd7ae37a705547ec793746ed3596b1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800ac0c8(uint param_1,uint param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  
  param_3 = param_3 & 0xff;
  if (param_3 == 0xff) {
    uVar4 = param_1 & 0xff;
    if (uVar4 < 0x40) {
      iVar2 = (param_2 & 0xff) * 0x86;
      uVar4 = (uint)*(byte *)((param_1 & 0x1f) + iVar2 + -0x7feb3080);
      pbVar3 = (byte *)((param_1 & 0x1f) + iVar2 + -0x7feb3060);
    }
    else {
      if (1 < (param_1 + 0x80 & 0xff)) {
        if (0x45 < uVar4) {
          if ((param_1 - 0x60 & 0xff) < 6) {
            return 0;
          }
          return (uint)*(byte *)(uVar4 + (param_2 & 0xff) * 0x86 + -0x7feb3080) << 7;
        }
        bVar1 = *(byte *)(uVar4 + (param_2 & 0xff) * 0x86 + -0x7feb3080);
        goto LAB_800ac1f8;
      }
      iVar2 = (param_2 & 0xff) * 0x86;
      uVar4 = (uint)*(byte *)((param_1 & 0xfe) + iVar2 + -0x7feb3080);
      pbVar3 = (byte *)((param_1 & 0xfe) + iVar2 + -0x7feb307f);
    }
  }
  else {
    uVar4 = param_1 & 0xff;
    if (uVar4 < 0x40) {
      param_1 = param_1 & 0x1f;
      iVar2 = (param_2 & 0xff) * 0x86;
      iVar5 = param_1 + iVar2 + param_3 * 0x860;
      iVar2 = iVar2 + 0x20;
    }
    else {
      if (1 < (param_1 + 0x80 & 0xff)) {
        if (0x45 < uVar4) {
          if ((param_1 - 0x60 & 0xff) < 6) {
            return 0;
          }
          return (uint)*(byte *)(uVar4 + (param_2 & 0xff) * 0x86 + param_3 * 0x860 + -0x7feb7380) <<
                 7;
        }
        bVar1 = *(byte *)(uVar4 + (param_2 & 0xff) * 0x86 + param_3 * 0x860 + -0x7feb7380);
LAB_800ac1f8:
        uVar4 = 0;
        if (0x3f < bVar1) {
          uVar4 = 0x3fff;
        }
        return uVar4;
      }
      param_1 = param_1 & 0xfe;
      iVar2 = (param_2 & 0xff) * 0x86;
      iVar5 = param_1 + iVar2 + param_3 * 0x860;
      iVar2 = iVar2 + 1;
    }
    pbVar3 = (byte *)(param_1 + iVar2 + param_3 * 0x860 + -0x7feb7380);
    uVar4 = (uint)*(byte *)(iVar5 + -0x7feb7380);
  }
  return (uint)*pbVar3 | uVar4 << 7;
}
