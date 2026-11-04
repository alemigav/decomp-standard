/* FUN_800706cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800706cc  body 0x800706cc..0x80070707  size 60 B
 * body sha256 a93807bc2fd2834100a0656ad86d96c8468ba1c9c88234fc768572ac3819852a
 * provider record sha256 ca586997fc8d90f65c313b091e2bce3fa62745a7512e9cd09518b723c0a443cc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_800706cc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0x1c) = iVar1 + 8;
  iVar1 = FUN_80032e74(*(undefined4 *)(param_1 + 0x154),(int)*(short *)(iVar1 + 2),
                       (int)*(short *)(iVar1 + 4),(int)*(short *)(iVar1 + 6));
  return iVar1 == 0;
}
