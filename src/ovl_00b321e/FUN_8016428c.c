/* FUN_8016428c
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x8016428c  body 0x8016428c..0x80164397  size 268 B
 * body sha256 7d996b39e94a6ed6aa1e3ef99b180b298496c6c7dd64f9d2c8430887f7224b8c
 * provider record sha256 18af4f9bfa2daaeacb0937727a933b72247641fc9aa05b51e405493745f7f551
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016428c(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    uVar2 = *(uint *)(param_1 + 0x28c);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
  }
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 0x32;
    *(undefined2 *)(param_1 + 500) = 0x1c2;
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000f00;
    *(undefined1 *)(param_1 + 0x2bf) = 0x10;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 100) = 0;
    *(undefined1 *)(param_1 + 0x2de) = 0;
  }
  FUN_8016304c(param_1,param_2,param_3);
  sVar1 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar1 + -1;
  if ((sVar1 == 1) || ((int)uVar2 < 0x6a4)) {
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined2 *)(param_1 + 6) = 0;
  }
  FUN_801623ac(param_1);
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x80033648(param_1);
  return;
}
