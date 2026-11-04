/* FUN_80167330
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80167330  body 0x80167330..0x8016741b  size 236 B
 * body sha256 c7767bd11b9e9bc677bb5b1b99bd9d559d99c05104af328c68e90abcc34adb95
 * provider record sha256 cd3b54dd740e95bdc3a68636085d579f6a53a1a7e744be101889ef25602e7401
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80167330(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  
  if (param_2 == 0) {
    iVar5 = -0x7ff1eed0;
    uVar1 = *(uint *)(param_1 + 0x28c);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
    iVar5 = _DAT_800e13ec;
  }
  uVar2 = 0;
  if (((int)uVar1 < param_3) && (uVar2 = 0, (*(byte *)(iVar5 + 0x26f) & 0x80) == 0)) {
    if (param_2 == 0) {
      iVar3 = func_0x80059e00(0x14,0);
    }
    else {
      iVar3 = func_0x80080e00(param_1,0x14,0);
    }
    if (iVar3 == 2) {
      FUN_80167884(param_2);
      uVar2 = 1;
    }
    else {
      uVar4 = func_0x80033144(param_1,iVar5);
      FUN_80167830(param_2,uVar4);
      uVar2 = 1;
    }
  }
  return uVar2;
}
