/* FUN_80004cfc
 * image   boot (boot), base 0x80000480
 * address 0x80004cfc  body 0x80004cfc..0x80004ec3  size 252 B
 * body sha256 da5da3ae79bcfb1d7b9fc1a0bb2ee2fb1d5c92e1528d084f141b38157090ca58
 * provider record sha256 e1b6c33bd9329aa3d0ac75a815c13ab515830be33ff5584c178632d6e7015c3e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80004cfc(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_78 [88];
  ushort local_20 [4];
  
  FUN_800044f0(auStack_78);
  if ((param_1 != 0xffff) && (param_1 != -1)) {
    piVar1 = (int *)(param_1 * 8 + _DAT_80012874);
    uVar4 = piVar1[1];
    if (uVar4 != 0) {
      iVar2 = *piVar1;
      if (iVar2 < 0) {
        trap(0);
      }
      if ((uVar4 & 1) != 0) {
        uVar4 = uVar4 + 1;
      }
      func_0x800888ec(_DAT_800128a8 + iVar2 + uVar4,local_20,8);
      uVar3 = (int)((local_20[0] - 1) * 0x10000) >> 0x10;
      if (uVar3 < 0x10) {
                    /* WARNING: Jumptable with 0 entries at 0x80004dc4 */
                    /* WARNING: Treating indirect jump as call */
        uVar4 = (**(code **)(uVar3 * 4 + -0x7ffee6f0))();
        return uVar4;
      }
      inflate_free(auStack_78,2);
      return uVar4;
    }
  }
  inflate_free(auStack_78,2);
  return 0;
}
