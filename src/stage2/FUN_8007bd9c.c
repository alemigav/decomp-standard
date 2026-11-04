/* FUN_8007bd9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007bd9c  body 0x8007bd9c..0x8007be17  size 124 B
 * body sha256 b9bb64b6a52b6103cf8352641fa21f109ab71b5f1d7adae08df5e00952dd3fbc
 * provider record sha256 82341c5c6d69fd65f0f722ceac9a3489274b05654e163827b5c42041269d318e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007bd9c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011af80)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
