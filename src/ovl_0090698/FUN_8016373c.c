/* FUN_8016373c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016373c  body 0x8016373c..0x80163833  size 248 B
 * body sha256 8a39f79081b6dc1fb416b0ac9b79a4393e303a6c972d0dd1eaf4a9e41776cbe1
 * provider record sha256 7b57ff48c115ab3dd30930381174715a8f058a45d0e957f5e78a359899f8994f
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016373c(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  undefined2 uVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000300;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0x3c;
    uVar2 = func_0x80032e74(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2dc) + 0x28),
                            *(undefined4 *)(*(int *)(param_1 + 0x2dc) + 0x30),0x40);
    *(undefined2 *)(param_1 + 0x1f6) = uVar2;
  }
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x1f6);
  func_0x80089d54(param_1,param_2,param_3,0x400);
  FUN_80167938(param_1);
  FUN_801669f8(param_1,1);
  sVar1 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar1 + -1;
  *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 100;
  if (sVar1 == 1) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) {
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 0x2b6));
  }
  return;
}
