/* FUN_80164208
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80164208  body 0x80164208..0x8016439f  size 408 B
 * body sha256 28089495eccda485a6f143da5df67d13920c860998f6fb24060a6867d1041d8c
 * provider record sha256 8d5c589a6813a5337e54e1a4b7bb0f821b0af940705cf2a37e0f1d10f5b82339
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164208(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  short sVar3;
  undefined4 uVar2;
  int iVar4;
  int iVar5;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 0x2ce) = 4;
    *(undefined4 *)(param_1 + 0x1e8) = 0x16000f00;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    *(undefined1 *)(param_1 + 0x2cc) = 0;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) {
    *(undefined2 *)(param_1 + 0x1f6) = 0;
  }
  else {
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + 1;
  }
  if (*(short *)(param_1 + 0x1f6) < 6) {
    uVar1 = func_0x80033604();
    if ((uVar1 & 2) == 0) goto LAB_80164310;
    iVar4 = *(int *)(*(int *)(param_1 + 0x2c4) + 0x28);
    iVar5 = *(int *)(*(int *)(param_1 + 0x2c4) + 0x30);
  }
  else {
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + 1;
    if (0x14 < *(short *)(param_1 + 0x1f6)) {
      if (*(short *)(param_1 + 0x1f6) == 0x15) {
        *(undefined1 *)(param_1 + 0x2cc) = 0;
      }
      FUN_80162f58(param_1,0x32,0);
      goto LAB_80164324;
    }
LAB_80164310:
    iVar4 = (int)*(short *)(param_1 + 0x260);
    iVar5 = (int)*(short *)(param_1 + 0x262);
  }
  func_0x80032dbc(param_1,iVar4,iVar5,0x32);
LAB_80164324:
  func_0x800334c8(param_1,param_2,param_3,0);
  func_0x8008a994(param_1,param_2,param_3,0x100);
  func_0x80032b5c(param_1,0);
  sVar3 = *(short *)(param_1 + 500) + 1;
  *(short *)(param_1 + 500) = sVar3;
  uVar2 = 0x1000000;
  if ((0xb3 < sVar3) || (uVar2 = 0x10f0000, *(uint *)(param_1 + 0x28c) < 0x898)) {
    *(undefined4 *)(param_1 + 4) = uVar2;
  }
  return;
}
