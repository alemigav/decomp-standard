/* FUN_8007be94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007be94  body 0x8007be94..0x8007bf0f  size 124 B
 * body sha256 aaffe16bb1e7872c9bb1e0467c197752cd5f878a4d1e6457e6ad23c51527047b
 * provider record sha256 48738b31d9e4981d11ce31d6d4d59dc68698f9db8e6b03ce83b56f48b8124abb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007be94(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b028)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
