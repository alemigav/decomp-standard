/* FUN_80164d90
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164d90  body 0x80164d90..0x80164f13  size 388 B
 * body sha256 6c05eb8f065a389f1c23a7e691bbf2e95569a8bbe2012db747f1da72712018f8
 * provider record sha256 2ee0ee9d231ac1b3fd6145cc24de4e3cb5b414e7741fdb926d17b612d111fbd4
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164d90(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  *(ushort *)(param_1 + 500) = (_DAT_800e1196 & 0xfff) - (*(ushort *)(param_1 + 0x66) & 0xfff);
  uVar1 = func_0x80033604();
  *(short *)(param_1 + 500) =
       *(short *)(param_1 + 500) + *(short *)(&DAT_80166e6c + (uVar1 & 7) * 2);
  *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xdfff;
  *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
  if (*(char *)(param_1 + 4) == '\x02') {
    func_0x80077d18(1,param_1);
  }
  if ((*(byte *)(param_1 + 0x2bf) == 0) || (*(char *)(param_1 + 0x2c9) != '\0')) {
    if (*(char *)(param_1 + 0x2b5) == '\0') {
      *(undefined2 *)(param_1 + 6) = 0x200;
      *(undefined2 *)(param_1 + 0x1e0) = 0xf0;
      FUN_80165a5c(param_1,0);
    }
    else {
      *(undefined2 *)(param_1 + 6) = 0x100;
      *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) >> 1;
    }
    *(undefined1 *)(param_1 + 700) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0x11000700;
    *(undefined1 *)(param_1 + 0x2bf) = 1;
    *(undefined2 *)(param_1 + 0x1f6) = 0x200;
    func_0x80089d54(param_1,param_2,param_3,0x200);
    *(undefined1 *)(param_1 + 699) = 1;
    FUN_80166980(param_1,0,0);
  }
  else {
    *(byte *)(param_1 + 0x2bf) = *(byte *)(param_1 + 0x2bf) | 0x80;
    FUN_80165388(param_1,param_2,param_3);
  }
  return;
}
