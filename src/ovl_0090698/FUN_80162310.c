/* FUN_80162310
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80162310  body 0x80162310..0x80162453  size 324 B
 * body sha256 10202a14395ca7445b02efa20806c3a6eb034bfa871a65a71ea11510acab8d1d
 * provider record sha256 2721b5bc1d40d7a9acdb2625cf2774d2d50f5db2f2d612a72c7467a92614ad85
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162310(int param_1)

{
  ushort uVar1;
  short sVar4;
  short sVar5;
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
  sVar5 = FUN_80166b04(param_1,0x400);
  if ((sVar5 != 0) && (uVar1 < 8000)) {
    *(undefined4 *)(param_1 + 4) = 0x1050000;
  }
  if ((_DAT_800e112a & 1) != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1090000;
    uVar2 = func_0x80033604();
    if ((uVar2 & 1) != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1050000;
    }
  }
  if (*(short *)(param_1 + 0x2b4) == 0) {
    if (((uVar1 < 0x1d4c) && (sVar4 == 0)) && (3000 < uVar1)) {
      *(undefined4 *)(param_1 + 4) = 0x1070000;
    }
    if (((uVar1 < 6000) && (sVar4 == 0)) && (1000 < uVar1)) {
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
