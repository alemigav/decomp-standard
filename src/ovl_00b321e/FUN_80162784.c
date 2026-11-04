/* FUN_80162784
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80162784  body 0x80162784..0x80162857  size 212 B
 * body sha256 c84fc3eeddba637e6cc2872362a8509007dd1f4f2e23c9ba3f1b24d6c1d85d52
 * provider record sha256 3db5b6863ec5507ff48896bb8c765ef39752a4b831f7670faa5cd5b0da768653
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162784(int param_1)

{
  short sVar1;
  ushort uVar2;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
    FUN_80162564();
    *(undefined2 *)(param_1 + 0x1e2) = 0xffb0;
    func_0x80077d18(7,param_1);
  }
  func_0x80032bd8(param_1,0,0);
  sVar1 = *(short *)(param_1 + 0x1e0) + -10;
  *(short *)(param_1 + 0x1e0) = sVar1;
  if (sVar1 < 0xb) {
    *(undefined2 *)(param_1 + 0x1e0) = 5;
  }
  uVar2 = *(short *)(param_1 + 0x1e2) + 0x1e;
  *(ushort *)(param_1 + 0x1e2) = uVar2;
  if ((0 < (int)((uint)uVar2 << 0x10)) &&
     ((int)*(short *)(param_1 + 0x25e) <= *(int *)(param_1 + 0x2c))) {
    *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
    *(undefined2 *)(param_1 + 6) = 0x300;
    *(undefined1 *)(param_1 + 700) = 0;
    func_0x80077d18(7);
  }
  return;
}
