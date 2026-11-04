/* FUN_80163428
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163428  body 0x80163428..0x8016356f  size 328 B
 * body sha256 ff4a9343ea808404e616a27531216473b3040d99f1cb5ee501b3464979d2c376
 * provider record sha256 fa2c2f982db9bbf9ca632c6a46d2bdaace5ebb81e0e2d18f3debc424fc6c8177
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163428(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 0x2c3) == '\0') {
    iVar2 = -0x7ff1eed0;
  }
  else {
    iVar2 = _DAT_800e13ec;
  }
  uVar3 = 0xdac;
  if ((*(uint *)(iVar2 + 4) & 0xffff0000) == 0x1020000) {
    uVar3 = 5000;
  }
  if (uVar3 < *(uint *)(param_1 + 0x28c)) {
    if (((_DAT_800e112a & 1) != 0) || ((_DAT_800e1128 & 0x20) != 0)) {
      if ((_DAT_800e1128 & 0x80) == 0) {
        *(undefined1 *)(param_1 + 6) = 2;
        *(undefined4 *)(param_1 + 0x1e8) = 0x8000f00;
        _DAT_800e1128 = _DAT_800e1128 | 0x80;
      }
      else {
        uVar3 = func_0x80033604();
        bVar1 = (&DAT_80166c90)[uVar3 & 7];
        *(undefined1 *)(param_1 + 6) = 1;
        *(ushort *)(param_1 + 500) = (ushort)bVar1;
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0x8000f00;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  return;
}
