/* FUN_80165e5c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165e5c  body 0x80165e5c..0x80165f7b  size 288 B
 * body sha256 b6f8c44df8941265f49c9f583641861345dff878a0c96805b182a8c47d1aa6b4
 * provider record sha256 571503f70780c0d7442851f0764be8399bc5bce04dae56637030298e5c5dd25a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165e5c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x250);
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x3f00;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
    iVar1 = *(int *)(param_1 + 0x28) - *(int *)(iVar4 + 0x28);
    iVar2 = *(int *)(param_1 + 0x30) - *(int *)(iVar4 + 0x30);
    sVar3 = func_0x80040bb4(iVar1 * iVar1 + iVar2 * iVar2);
    *(short *)(param_1 + 0x1f6) = sVar3 + -0x5bf;
    *(undefined1 *)(param_1 + 0x206) = 7;
    func_0x80077adc(0x4010001,param_1 + 0x28);
  }
  if (*(char *)(param_1 + 0x206) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)*(char *)(param_1 + 0x206) *
            ((int)((uint)*(ushort *)(param_1 + 0x1f6) << 0x10) >> 0x13);
    *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + -1;
  }
  FUN_80166ea0(param_1,iVar4,iVar1 + 0x5bf);
  iVar4 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar4 != 0) {
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  return;
}
