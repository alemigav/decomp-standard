/* FUN_80167a30
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80167a30  body 0x80167a30..0x80167c6b  size 572 B
 * body sha256 74f6571505fbf1a1418d0cca7544e575c69b3826e0f38fe679c37b99021a6530
 * provider record sha256 58b969172e44396ac37976ffc9baf5aaf359bf7448b8df8c01e99fe095e28aac
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167a30(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  short local_20 [2];
  short local_1c;
  
  if ((*(ushort *)(param_1 + 0x26c) & 0x20) == 0) {
    bVar1 = *(byte *)(param_1 + 7);
    if (bVar1 != 1) {
      if (1 < bVar1) {
        if (bVar1 != 2) {
          return;
        }
        if (*(short *)(param_1 + 0x1f2) < 0) {
          *(undefined4 *)(param_1 + 4) = 0x3000000;
          return;
        }
        goto LAB_80167c3c;
      }
      if (bVar1 != 0) {
        return;
      }
      func_0x80077d18(7,param_1);
      FUN_80162ba4(param_1,&UNK_80168bf4 + (uint)*(byte *)(param_1 + 0x2cb) * 8,0);
      *(undefined2 *)(param_1 + 0x1e0) = 100;
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      func_0x80032ef4(param_1,(int)((*(ushort *)(*(int *)(param_1 + 0x2c4) + 0x66) + 0x800) *
                                   0x10000) >> 0x10,0x80);
      *(undefined4 *)(param_1 + 0x1e8) = 0x8000300;
      *(undefined1 *)(param_1 + 7) = 1;
      *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffd;
    }
  }
  else {
    bVar1 = *(byte *)(param_1 + 7);
    if (bVar1 != 1) {
      if (1 < bVar1) {
        if (bVar1 != 2) {
          return;
        }
        if (*(short *)(param_1 + 0x1f2) < 0) {
          *(undefined4 *)(param_1 + 4) = 0x3000000;
          return;
        }
LAB_80167c3c:
        FUN_80166c7c(param_1);
        return;
      }
      if (bVar1 != 0) {
        return;
      }
      func_0x80077d18(7,param_1);
      FUN_80162ba4(param_1,&UNK_80168bf4 + (uint)*(byte *)(param_1 + 0x2cb) * 8,1);
      *(undefined2 *)(param_1 + 0x1e0) = 100;
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      func_0x80032ef4(param_1,(int)*(short *)(*(int *)(param_1 + 0x2c4) + 0x66),0x80);
      *(undefined4 *)(param_1 + 0x1e8) = 0x8000300;
      *(undefined1 *)(param_1 + 7) = 1;
      *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffd;
    }
  }
  if (0 < *(short *)(param_1 + 0x1e0)) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + -6;
  }
  func_0x800837d0((int)*(short *)(*(int *)(param_1 + 0x2c4) + 0x66),param_1 + 0x1e0,local_20);
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)local_20[0];
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)local_1c;
  cVar2 = func_0x8008a994(param_1,param_2,param_3,0x400);
  *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + cVar2;
  return;
}
