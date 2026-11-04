/* FUN_80163d60
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163d60  body 0x80163d60..0x80163e93  size 308 B
 * body sha256 eeeefdb3e3b910dd46620b794e760c9af05f59ed6a45f8521b122dd564224c87
 * provider record sha256 fb4e641099cb7bbaed0ba0faec524f393251008cea37d14bff03417fa9e6f81c
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163d60(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined1 uVar4;
  uint uVar2;
  short sVar3;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    uVar4 = func_0x80065628();
    *(undefined1 *)(param_1 + 0x2b4) = uVar4;
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (byte)(&DAT_80166c88)[uVar2 & 7] + 0x1e;
    *(short *)(param_1 + 0x2b6) = *(short *)(param_1 + 0x2b6) + 300;
  }
  FUN_80166bd4(param_1);
  func_0x800653d0(param_1,0,*(undefined1 *)(param_1 + 0x2b4),1);
  sVar3 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                          (int)*(short *)(param_1 + 0x2c0));
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar3;
  func_0x80032b5c(param_1,0);
  sVar1 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar1 + -1;
  if (sVar1 == 1) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
    *(undefined1 *)(param_1 + 0x2b9) = 0;
  }
  FUN_80166590(param_1,(int)sVar3);
  func_0x80089d54(param_1,param_2,param_3,0x100);
  FUN_801664d8(param_1);
  FUN_80166b60(param_1);
  return;
}
