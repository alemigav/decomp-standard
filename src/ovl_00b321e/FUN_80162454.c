/* FUN_80162454
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80162454  body 0x80162454..0x80162563  size 272 B
 * body sha256 29d0a7ac16a586f84f338ded8936c6779ae2b54e3848315e7a3c0bcafa40787d
 * provider record sha256 f862c833d6d7c8b80a1829f6f1d68d3e3f82fa6d78dea89f02240b6997b8783e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162454(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  ushort uVar3;
  int iVar4;
  
  bVar1 = *(byte *)(param_1 + 0x2be);
  iVar4 = (uint)bVar1 * 4;
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined2 *)(param_1 + 0x1e2) = 0xffec;
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    uVar2 = *(undefined2 *)(&DAT_801666c4 + (iVar4 + 2) * 2);
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000700;
    *(undefined2 *)(param_1 + 100) = 0;
    *(undefined1 *)(param_1 + 700) = 1;
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(undefined2 *)(param_1 + 0x2dc) = *(undefined2 *)(param_1 + 0x32);
    *(undefined2 *)(param_1 + 500) = uVar2;
    *(undefined2 *)(param_1 + 0x2da) = *(undefined2 *)(param_1 + 0x2a);
    FUN_80162564(param_1);
  }
  uVar3 = *(short *)(param_1 + 0x1e2) - 0x14;
  *(ushort *)(param_1 + 0x1e2) = uVar3;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -0x36 + ((int)((uint)uVar3 << 0x10) >> 0x14)
  ;
  if (*(short *)(param_1 + 0x1e2) < *(short *)(&DAT_801666c4 + (iVar4 + 1) * 2)) {
    uVar2 = *(undefined2 *)(&DAT_801666c4 + (uint)bVar1 * 8);
    *(undefined2 *)(param_1 + 6) = 0x100;
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000700;
    *(undefined2 *)(param_1 + 0x1e0) = uVar2;
  }
  return;
}
