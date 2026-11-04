/* FUN_800036f0
 * image   boot (boot), base 0x80000480
 * address 0x800036f0  body 0x800036f0..0x800037bb  size 204 B
 * body sha256 505a70fd95dc0c72fdb659f27faf364bc126b55c8c11dc184ae41e522d552c9b
 * provider record sha256 7e791ebf31ff6944bb8668078ece6cd370a0f8427365e3128b42bde243d17187
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800036f0(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (((param_1 == 0) || (*(int **)(param_1 + 0x1c) == (int *)0x0)) ||
     (**(int **)(param_1 + 0x1c) != 6)) {
    uVar1 = 0xfffffffe;
  }
  else {
    iVar2 = FUN_800011a0(1,param_2,param_3);
    uVar1 = 0xfffffffd;
    if (iVar2 == *(int *)(param_1 + 0x30)) {
      *(undefined4 *)(param_1 + 0x30) = 1;
      uVar3 = *(uint *)(*(int *)(param_1 + 0x1c) + 0x10);
      uVar4 = param_3;
      if (param_3 >> (uVar3 & 0x1f) != 0) {
        uVar4 = (1 << (uVar3 & 0x1f)) - 1;
        param_2 = param_2 + (param_3 - uVar4);
      }
      FUN_80002314(*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x14),param_1,param_2,uVar4);
      uVar1 = 0;
      **(undefined4 **)(param_1 + 0x1c) = 7;
    }
  }
  return uVar1;
}
