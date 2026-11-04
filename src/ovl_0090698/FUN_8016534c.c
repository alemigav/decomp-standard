/* FUN_8016534c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016534c  body 0x8016534c..0x80165407  size 188 B
 * body sha256 4355038f21bc6d8bb3bdb6dce451907f0ca1e8fef0e6cc5f091f5ae53754062c
 * provider record sha256 a9f74c047c22588096f8331a8b8e83e52bb0f97061b78425e9b3fab95e938729
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016534c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = func_0x80033604();
    iVar2 = (uVar1 & 0xf) + 3;
    if ((*(uint *)(*(int *)(param_1 + 0x234) + iVar2 * 0x178) & 0x4b) == 1) {
      FUN_8016703c(param_1,iVar2,5);
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 5);
  *(undefined1 *)(param_1 + 5) = 2;
  FUN_801647c8(param_1,param_2,param_3);
  return;
}
