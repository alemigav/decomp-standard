/* FUN_801665e8
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801665e8  body 0x801665e8..0x8016664b  size 100 B
 * body sha256 5499c1332d24235bcec8bd8a0dffa1fc12b3fd5894a9062acfc315fcc2d0be60
 * provider record sha256 42e2e77aee97c1f6312857aacfe95f2b4c8a7346d72c556c8e17a7feb56ca05f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801665e8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_80167340,param_2);
  uVar1 = func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_801673c8,uVar1);
  func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_80167440,uVar1);
  return;
}
