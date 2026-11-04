/* FUN_80163908
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80163908  body 0x80163908..0x80163a53  size 332 B
 * body sha256 ec285d60bbe139ef03d56c14aaded856091589413633d270992866bcb1a54065
 * provider record sha256 d0b80b3ebd265b0b44aec1d7dc19401951553e134c9560609665878bd41bf667
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163908(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  
  FUN_80163868();
  if (*(char *)(param_1 + 0x2d3) == '\0') {
    iVar3 = -0x7ff1eed0;
  }
  else {
    iVar3 = _DAT_800e13ec;
  }
  iVar3 = *(int *)(iVar3 + 0x2c) - *(int *)(param_1 + 0x2c);
  if (0xdac < iVar3) {
    iVar1 = func_0x80074d64(*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x30));
    if (iVar1 < *(short *)(param_1 + 0x25e)) {
      iVar3 = (iVar1 - (*(int *)(param_1 + 0x2c) + 0x898)) / 100;
      *(short *)(param_1 + 500) = (short)iVar3;
      if (iVar3 * 0x10000 < 0) {
        *(undefined2 *)(param_1 + 500) = 0;
      }
    }
    else {
      *(short *)(param_1 + 500) = (short)((iVar3 + -0xdac) / 100);
    }
    if (*(short *)(param_1 + 500) != 0) {
      uVar2 = func_0x80033604();
      *(undefined1 *)(param_1 + 5) = 1;
      *(undefined1 *)(param_1 + 0x2cd) = 2;
      *(undefined2 *)(param_1 + 6) = 0;
      *(ushort *)(param_1 + 500) = *(short *)(param_1 + 500) + (uVar2 & 3);
      return;
    }
  }
  *(undefined1 *)(param_1 + 5) = 2;
  *(undefined2 *)(param_1 + 6) = 0x100;
  uVar2 = func_0x80033604();
  *(ushort *)(param_1 + 500) = (uVar2 & 0xf) + 0x1e;
  return;
}
