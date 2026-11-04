/* FUN_80164a38
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164a38  body 0x80164a38..0x80164b7f  size 328 B
 * body sha256 e1ee44b01e4345dad412c13297ce70b77f145bfabc552f1ae1d9b1770f141bdc
 * provider record sha256 229b455ca64d095969bcf70dfa79b7d508af5a6b6f5f06f1a66eb9835b32b074
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164a38(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  func_0x80077d18(3,param_1);
  *(undefined1 *)(param_1 + 0x2d6) = *(undefined1 *)(param_1 + 5);
  if ((*(byte *)(param_1 + 0x2bd) & 1) == 0) {
    *(undefined1 *)(param_1 + 5) = 7;
    FUN_80166270(param_1,0,3);
  }
  else {
    bVar1 = *(char *)(param_1 + 0x2cb) - 0xf;
    *(byte *)(param_1 + 0x2cb) = bVar1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    if ((int)((uint)bVar1 << 0x18) < 0) {
      *(undefined1 *)(param_1 + 0x2cb) = 0;
    }
    if (*(char *)(param_1 + 0x2cb) == '\0') {
      uVar3 = 3;
      iVar2 = 0x468;
      do {
        uVar3 = uVar3 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar2 + 0x60) =
             *(undefined4 *)
              (&DAT_801667c8 + (((int)*(char *)(param_1 + 0x2cb) / 10) * 0x1000000 >> 0x16));
        iVar2 = iVar2 + 0x178;
      } while (uVar3 < 7);
    }
    if (*(char *)(param_1 + 700) == '\0') {
      *(undefined2 *)(param_1 + 6) = 0x200;
    }
    else if (*(char *)(param_1 + 0x2c5) == '\0') {
      *(undefined2 *)(param_1 + 6) = 0x100;
      FUN_801647ac(param_1,param_2,param_3);
    }
    else {
      *(undefined2 *)(param_1 + 6) = 0x300;
    }
  }
  return;
}
