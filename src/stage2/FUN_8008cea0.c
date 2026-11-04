/* FUN_8008cea0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008cea0  body 0x8008cea0..0x8008d00b  size 364 B
 * body sha256 d44b79591047722bad060c3d45f56e0211a81c85dd4c2783c04cc42ec1f291af
 * provider record sha256 34f2473b2849f42320e3cd3e83667e4b3af212fba340ae23a21aa244eb337227
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8008cea0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)DAT_8012bfa0;
  uVar2 = (uint)(byte)(&DAT_800e8ec9)[uVar3 * 4];
  iVar1 = FUN_800837ac(&DAT_800e8b58,param_1);
  if (iVar1 != 0) {
    return 1;
  }
  if (uVar2 != 0xff) {
    if (((param_1 == 0xf) || (param_1 == 0x13)) || (param_1 == 0x12)) {
      if ((short)(DAT_8012bfc4 + 1) < 8) {
        DAT_8012bfc4 = DAT_8012bfc4 + 1;
        return 1;
      }
      DAT_8012bfc4 = 0;
      if (uVar2 == 0) {
        DAT_8012bfc4 = 0;
        return 0;
      }
      uVar2 = uVar2 - 1;
      FUN_8008c33c(uVar3,uVar2);
    }
    if (param_1 == 0x10) {
      if ((short)(DAT_8012bfc4 + 1) < 8) {
        DAT_8012bfc4 = DAT_8012bfc4 + 1;
        return 1;
      }
      DAT_8012bfc4 = 0;
      if (uVar2 == 0) {
        DAT_8012bfc4 = 0;
        return 0;
      }
      uVar2 = uVar2 - 1;
      FUN_8008c33c(uVar3,uVar2);
    }
    if (param_1 == 0xe) {
      if (param_2 == 0) {
        iVar1 = uVar2 - 1;
      }
      else {
        iVar1 = uVar2 - 4;
      }
    }
    else {
      if (uVar2 == 0) {
        return 0;
      }
      iVar1 = uVar2 - 1;
    }
    FUN_8008c33c(uVar3,iVar1);
  }
  return 1;
}
