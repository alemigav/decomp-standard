/* FUN_80162f74
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80162f74  body 0x80162f74..0x801630a7  size 308 B
 * body sha256 49ae8e53ec2005e5367a1b93193cd684281ed0f32abb1efd4ed9219edba0b989
 * provider record sha256 7b343137a8b0b842ee7a4577bb68d03441461dfdab6ae698b6a040260bc47365
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162f74(int param_1)

{
  ushort uVar1;
  short sVar4;
  uint uVar2;
  undefined4 uVar3;
  
  FUN_8016224c();
  if (*(char *)(param_1 + 0x2d3) == '\0') {
    uVar1 = *(ushort *)(param_1 + 0x28e);
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x292);
  }
  sVar4 = FUN_80166b04(param_1,0x80);
  FUN_80166b04(param_1,0x100);
  FUN_80166b04(param_1,0x400);
  if ((_DAT_800e112a & 1) != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1090000;
    uVar2 = func_0x80033604();
    if ((uVar2 & 1) != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1050000;
    }
  }
  if (*(short *)(param_1 + 0x2b4) == 0) {
    if (uVar1 - 0xbb9 < 0x1193) {
      if (sVar4 == 0) {
        uVar2 = func_0x80033604();
        uVar3 = 0x1070000;
        if ((0x340 >> (uVar2 & 0xf) & 1U) == 0) {
          uVar3 = 0x1010000;
        }
      }
      else {
        uVar3 = 0x1010000;
      }
      *(undefined4 *)(param_1 + 4) = uVar3;
    }
    if ((uVar1 < 3000) && (sVar4 == 0)) {
      uVar2 = func_0x80033604();
      uVar3 = 0x1070000;
      if ((0x340 >> (uVar2 & 0xf) & 1U) != 0) {
        uVar3 = 0x1080000;
      }
      *(undefined4 *)(param_1 + 4) = uVar3;
    }
  }
  return;
}
