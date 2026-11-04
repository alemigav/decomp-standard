/* FUN_80164d9c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80164d9c  body 0x80164d9c..0x80164e33  size 152 B
 * body sha256 ab3667683c820b597f39e42dd3a5c5a93220499471144c8345488c03275e3fd0
 * provider record sha256 e4c4afee11e5daac15fc85c69154b357261dab446aecb83889ef8f55bc281f2d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164d9c(int param_1)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  
  if (-1 < _DAT_800e1322) {
    uVar3 = 0x1c2;
    if ((_DAT_800e10ec & 0x20) != 0) {
      uVar3 = 0x177;
    }
    if (((*(char *)(param_1 + 0x2c7) == '\0') &&
        (iVar1 = FUN_80164d04(param_1,*(ushort *)(param_1 + 0x1f2) < uVar3), iVar1 == 0)) &&
       (uVar2 = func_0x80033604(), (0x1a0 >> (uVar2 & 0xf) & 1U) != 0)) {
      *(undefined1 *)(param_1 + 5) = 7;
      *(undefined2 *)(param_1 + 6) = 0;
    }
  }
  return;
}
