/* FUN_80035c08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035c08  body 0x80035c08..0x80035c9b  size 148 B
 * body sha256 8f95225d470d474597c8766d3c42d38dc769c561efa4e10356f5c64112def42b
 * provider record sha256 7888af9694954ae9d52c65497efacfb643f4c7707db4cab8b855907147d6cdd6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80035c08(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb414,param_2);
  uVar1 = FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb4a8,uVar1);
  uVar1 = FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb53c,uVar1);
  uVar1 = FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb604,uVar1);
  FUN_80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_800eb684,uVar1);
  return;
}
