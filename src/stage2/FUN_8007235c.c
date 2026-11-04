/* FUN_8007235c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007235c  body 0x8007235c..0x800723cb  size 112 B
 * body sha256 620d3f41883c68820d7331bea6b9a96df7a5cc52cfbb692fba2ff6aa34219c9b
 * provider record sha256 5243cc670124c323f9a6e02caff50f3f7563bd557618860bf744af98c67a54a6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8007235c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_800777d8((uint)*(byte *)(iVar1 + 1) << 0x1c | (uint)*(byte *)(iVar1 + 2) << 0x18 |
               (uint)*(byte *)(iVar1 + 3) << 0x10 | (uint)*(byte *)(iVar1 + 4) << 8 |
               (uint)*(byte *)(iVar1 + 5));
  *(int *)(param_1 + 0x1c) = iVar1 + 6;
  return 1;
}
