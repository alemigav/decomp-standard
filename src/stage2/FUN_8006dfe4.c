/* FUN_8006dfe4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dfe4  body 0x8006dfe4..0x8006e09b  size 184 B
 * body sha256 6c9bb678973521b19876dbe513dd5a281ac8c3170da626010f73b78c49f512ef
 * provider record sha256 0be561cd5713d6a33429a44fb0349c2c32c68300ebcd01d3b6e8a3026ebadefb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006dfe4(int param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = (int)*(char *)(param_1 + 2);
  iVar3 = *(int *)(param_1 + 0x1c);
  iVar7 = param_1 + iVar5;
  cVar2 = *(char *)(iVar7 + 8) + '\x01';
  *(char *)(iVar7 + 8) = cVar2;
  sVar1 = *(short *)(iVar3 + 2);
  iVar6 = param_1 + cVar2 * 4 + iVar5 * 0x10;
  *(int *)(iVar6 + 0x20) = iVar3;
  iVar4 = iVar3 + 4;
  *(int *)(param_1 + 0x1c) = iVar4;
  *(int *)(iVar6 + 0x60) = iVar4 + sVar1;
  *(undefined1 *)(param_1 + (int)cVar2 + iVar5 * 4 + 0xc) = *(undefined1 *)(iVar7 + 4);
  iVar3 = FUN_8006e1bc(param_1,iVar4,*(undefined1 *)(iVar3 + 1));
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar6 + 0x60);
    *(char *)(iVar7 + 8) = *(char *)(iVar7 + 8) + -1;
  }
  return 1;
}
