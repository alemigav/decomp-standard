/* FUN_80166de8
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80166de8  body 0x80166de8..0x80167023  size 572 B
 * body sha256 1aa7bf7701f8f2258f6b8dc91c746f51cde4204d0265215e9e5419a045f0fd1d
 * provider record sha256 3927af08a13d85c076f995b00fcc5f67074a9c38f5852e719971fb2c5437e2f3
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166de8(int param_1,undefined4 param_2,undefined4 param_3)

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
        goto LAB_80166ff4;
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
LAB_80166ff4:
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
