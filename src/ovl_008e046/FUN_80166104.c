/* FUN_80166104
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80166104  body 0x80166104..0x80166367  size 612 B
 * body sha256 78ecd0d43020ec424c8e815879579c1a83f1fe234c9af6c3ea929dfd73a65045
 * provider record sha256 3786cad13f158501c78675a3fefec2f945c0926f6680aa871f109b1720e2e1da
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166104(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar3;
  char cVar4;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        if (bVar1 != 3) {
          return;
        }
        *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
        if (*(short *)(param_1 + 0x2d6) < -500) {
          *(short *)(param_1 + 0x2d6) = *(short *)(param_1 + 0x2d6) + 0x50;
        }
        func_0x800334c8(param_1,param_2,param_3,0);
        iVar2 = func_0x8008a994(param_1,param_2,param_3,0x400);
        if (iVar2 != 0) {
          *(undefined2 *)(param_1 + 0x2d6) = 0xfe0c;
          *(undefined1 *)(param_1 + 0x2ce) = 3;
          *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
          FUN_80165a84(param_1);
        }
        func_0x80032b5c(param_1,0);
        return;
      }
      if (*(short *)(param_1 + 0x1f2) < 0) {
        *(undefined1 *)(param_1 + 7) = 0;
        *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
        return;
      }
      uVar3 = *(short *)(param_1 + 500) - 1;
      *(ushort *)(param_1 + 500) = uVar3;
      if ((int)((uint)uVar3 << 0x10) < 1) {
        *(undefined4 *)(param_1 + 0x1e8) = 0x10000300;
        *(undefined2 *)(param_1 + 500) = 0;
        *(undefined1 *)(param_1 + 7) = 3;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    func_0x80077d18(7,param_1);
    FUN_80162ba4(param_1,&UNK_801673e8 + (uint)*(byte *)(param_1 + 0x2cb) * 8,0);
    *(undefined2 *)(param_1 + 0x1e0) = 0x32;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    func_0x800837d0((int)*(short *)(*(int *)(param_1 + 0x2c4) + 0x66),param_1 + 0x1e0,
                    param_1 + 0x1e0);
    func_0x80032ef4(param_1,(int)((*(ushort *)(*(int *)(param_1 + 0x2c4) + 0x66) + 0x800) * 0x10000)
                            >> 0x10,0x80);
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 500) = uVar3 & 0x11;
    *(undefined2 *)(param_1 + 0x170) = 0xfd60;
    *(undefined2 *)(param_1 + 0x172) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000000;
    *(undefined1 *)(param_1 + 7) = 1;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
  }
  cVar4 = func_0x8008a994(param_1,param_2,param_3,0x1000);
  *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + cVar4;
  if (-800 < *(short *)(param_1 + 0x2d6)) {
    *(short *)(param_1 + 0x2d6) = *(short *)(param_1 + 0x2d6) + -0x28;
  }
  *(undefined1 *)(param_1 + 0x2ce) = 3;
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)*(short *)(param_1 + 0x1e0);
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)*(short *)(param_1 + 0x1e4);
  return;
}
