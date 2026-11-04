/* FUN_80165da8
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165da8  body 0x80165da8..0x80165f7f  size 472 B
 * body sha256 f0bac25f0403be2430f090a157b6a5e8052d9b5c0e00cf418d697610a871de1d
 * provider record sha256 aed16eb6581aee18583e2a90cb449e47beea625b4221151e1cdd2f4419bee38d
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165da8(int param_1)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  undefined1 uVar4;
  
  if (-1 < _DAT_800e1322) {
    if ((*(uint *)(param_1 + 0x2c4) & 10) == 10) {
      FUN_80165c68(param_1,0xd);
      *(undefined1 *)(param_1 + 0x2b8) = 0;
      *(ushort *)(param_1 + 0x2c6) = *(ushort *)(param_1 + 0x2c6) & 0xffb7;
    }
    else if (*(char *)(param_1 + 0x2b8) == '\0') {
      if ((((*(int *)(param_1 + 0x28c) - 0x385U < 0x189b) && ((_DAT_800e1128 & 1) == 0)) &&
          ((*(ushort *)(param_1 + 0x2c6) & 2) != 0)) &&
         (iVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x100), iVar1 == 0)) {
        _DAT_800e1128 = _DAT_800e1128 | 1;
        *(ushort *)(param_1 + 0x2c6) = *(ushort *)(param_1 + 0x2c6) | 4;
        uVar2 = func_0x80033604();
        if ((uVar2 & 0xf) == 0) {
          FUN_80165c68(param_1,0xb);
        }
        else {
          FUN_80165c68(param_1,0xd);
        }
      }
      else if (*(char *)(param_1 + 0xd) == '\0') {
        bVar3 = *(byte *)(param_1 + 0x2ba);
        if (bVar3 == 0) {
          if (((0xe6 < *(short *)(param_1 + 0x1e0)) && ((_DAT_800e1128 & 1) == 0)) &&
             (iVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x100), iVar1 == 0)) {
            FUN_80165c68(param_1,0xc);
          }
          bVar3 = *(byte *)(param_1 + 0x2ba);
        }
        if (10 < bVar3) {
          FUN_80165c68(param_1,8);
          bVar3 = func_0x80033604();
          *(byte *)(param_1 + 700) = bVar3 & 0x7f;
          uVar4 = func_0x80065628();
          *(undefined1 *)(param_1 + 699) = uVar4;
        }
        if (100 < *(short *)(param_1 + 0x1e0)) {
          *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + -4;
        }
        *(char *)(param_1 + 0x2ba) = *(char *)(param_1 + 0x2ba) + '\x01';
      }
      else {
        *(undefined1 *)(param_1 + 0x2ba) = 0;
      }
    }
    else {
      *(char *)(param_1 + 0x2b8) = *(char *)(param_1 + 0x2b8) + -1;
    }
  }
  return;
}
