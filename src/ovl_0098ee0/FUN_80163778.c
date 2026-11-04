/* FUN_80163778
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80163778  body 0x80163778..0x801638d7  size 352 B
 * body sha256 38405707274b18fdf2a33c80649aa6cf6d16bfbfb651104c0b2d319a778e6f38
 * provider record sha256 ee09b6135018559c28b1b68d7e9ee3cc670eec0f55e6d9cf2af244051f71cd01
 * callees 7 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163778(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  short sVar4;
  
  FUN_801633bc();
  if ((*(ushort *)(param_1 + 0x1aa) & 0x300) == 0x100) {
    bVar1 = *(uint *)(param_1 + 0x28c) < 0x1965;
  }
  else {
    bVar1 = *(uint *)(param_1 + 0x28c) < 0x157d;
  }
  if (bVar1) {
    FUN_801621c4(param_1);
    if (*(char *)(param_1 + 6) == '\0') {
      *(undefined2 *)(param_1 + 500) = 0;
      *(undefined2 *)(param_1 + 0x1f6) = 0;
      *(undefined1 *)(param_1 + 0x1e9) = 0;
      *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    }
    else if (*(char *)(param_1 + 6) != '\x01') {
      return;
    }
    func_0x80036c68(param_1,1,0xf,0);
    if (*(int *)(param_1 + 0x1b0) != 0) {
      uVar2 = func_0x8006a42c(param_1 + 0x28);
      iVar3 = func_0x80032f64(param_1,(int)(((uVar2 & 0xffff) * 0x400 + 0x800) * 0x10000) >> 0x10,
                              0x50);
      if (iVar3 == 0) {
        *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
      }
      else if (*(short *)(param_1 + 500) < 0x10) {
        *(undefined2 *)(param_1 + 500) = 0;
      }
    }
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),0x30);
    if ((*(int *)(param_1 + 0x1b0) != 0) && (0x3c < *(short *)(param_1 + 500))) {
      sVar4 = FUN_80162b88(param_1);
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar4 * 0x20;
      if (0x5c < *(short *)(param_1 + 500)) {
        *(undefined2 *)(param_1 + 500) = 0;
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  return;
}
