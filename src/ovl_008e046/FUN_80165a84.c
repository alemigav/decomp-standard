/* FUN_80165a84
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80165a84  body 0x80165a84..0x80165b23  size 160 B
 * body sha256 085d978bf22b5431a5262a6902f77e8ab891fe80c8a586fd49ad5dc13ad4a215
 * provider record sha256 0279f8fbfe55701266333da0bf8784a09fc17e24a07e3f1a969979b0f12d8fea
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165a84(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*(uint *)(param_1 + 0x28c) < 0x9c4) {
    iVar1 = func_0x80032e74(*(undefined4 *)(param_1 + 0x2c4),*(undefined4 *)(param_1 + 0x28),
                            *(undefined4 *)(param_1 + 0x30),0x140);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 4) = 0x1130000;
      *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 1;
      return;
    }
    uVar2 = func_0x80033604();
    uVar3 = 0x10c0000;
    if ((uVar2 & 1) == 0) {
      uVar3 = 0x10f0000;
    }
  }
  else {
    iVar1 = func_0x80032e74(*(undefined4 *)(param_1 + 0x2c4),*(undefined4 *)(param_1 + 0x28),
                            *(undefined4 *)(param_1 + 0x30),0x1e0);
    uVar3 = 0x10c0000;
    if (iVar1 == 0) {
      uVar3 = 0x1140000;
    }
  }
  *(undefined4 *)(param_1 + 4) = uVar3;
  return;
}
