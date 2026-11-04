/* FUN_80165c1c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165c1c  body 0x80165c1c..0x80165d1f  size 260 B
 * body sha256 3b658ab1f0bdee217dc6aa280ba6966829e4ba357ae60be76c280e78d4fe7e5d
 * provider record sha256 20668108c41b3c61ec8b02270fdfdd33d349adb043394948fde919a6fe8f66d0
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165c1c(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_8016561c();
    uVar1 = func_0x80033604();
    FUN_80166b98(param_1,(&DAT_80167230)[uVar1 & 0xf],10);
    uVar1 = func_0x80033604();
    FUN_80166b98(param_1,(&DAT_80167230)[uVar1 & 0xf],10);
    uVar1 = func_0x80033604();
    FUN_80166b98(param_1,(&DAT_80167230)[uVar1 & 0xf],10);
    uVar1 = 0;
    iVar2 = 0;
    *(undefined1 *)(param_1 + 0x25d) = 0;
    *(undefined1 *)(param_1 + 0x2d8) = 0x2d;
    *(undefined1 *)(param_1 + 0x2c1) = 7;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
    do {
      uVar1 = uVar1 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar2 + 0x60) = 0x3f3f3f;
      iVar2 = iVar2 + 0x178;
    } while (uVar1 < 0x1a);
  }
  else {
    FUN_801656c0(param_1);
  }
  *(undefined2 *)(param_1 + 0x2d4) = 1;
  return;
}
