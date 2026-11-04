/* FUN_8016272c
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x8016272c  body 0x8016272c..0x801627a7  size 124 B
 * body sha256 4176ec20c053cee89502158cda2e8a47dcadfcc104fc9a5f66f67f86fa5fe524
 * provider record sha256 0e1c581a08c055c424e784d96fe7b61c6cc21c4e9bb0cb1c2e2541ed3d8db4a1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016272c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_80167fd4)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_80167ffc)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
