/* FUN_8006e138
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e138  body 0x8006e138..0x8006e1bb  size 132 B
 * body sha256 f3f80825b2cf54b93c745cb0bafcceec4d052b5dc7db4013285805615d0a2b80
 * provider record sha256 af88ff8c7e74e591d1b8b05e03bfed3a2033e0bc73034f71cf6f1d5f09c1c929
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006e138(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  iVar2 = iVar1 + 2;
  *(int *)(param_1 + 0x1c) = iVar2;
  iVar3 = (int)*(char *)(param_1 + 2);
  iVar1 = FUN_8006e1bc(param_1,iVar2,*(undefined1 *)(iVar1 + 1));
  if (iVar1 == 0) {
    *(char *)(param_1 + iVar3 + 8) = *(char *)(param_1 + iVar3 + 8) + -1;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) =
         *(undefined4 *)(param_1 + *(char *)(param_1 + iVar3 + 8) * 4 + iVar3 * 0x10 + 0x20);
  }
  return 1;
}
