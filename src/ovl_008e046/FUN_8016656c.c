/* FUN_8016656c
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x8016656c  body 0x8016656c..0x801667a7  size 572 B
 * body sha256 4c701a8907a1d95517faecb02378d12d12b81e5409f6d8d74ffd272a6c96be04
 * provider record sha256 c56763ccdf5dfba189439aa7c46d0cbee6dd84e52115b21f46a5abf7abcc0da4
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016656c(int param_1,undefined4 param_2,undefined4 param_3)

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
        goto LAB_80166778;
      }
      if (bVar1 != 0) {
        return;
      }
      func_0x80077d18(7,param_1);
      FUN_80162ba4(param_1,&UNK_801673e8 + (uint)*(byte *)(param_1 + 0x2cb) * 8,0);
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
LAB_80166778:
        FUN_80165a84(param_1);
        return;
      }
      if (bVar1 != 0) {
        return;
      }
      func_0x80077d18(7,param_1);
      FUN_80162ba4(param_1,&UNK_801673e8 + (uint)*(byte *)(param_1 + 0x2cb) * 8,1);
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
