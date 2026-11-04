/* FUN_8007c100
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c100  body 0x8007c100..0x8007c17b  size 124 B
 * body sha256 be34aeac8e95289adfb7f5b56d70dbbcdcc1e7c84d453609cff86c4f52276cb8
 * provider record sha256 67a5761345ba252597f989b8f36d91eba8b6fe339c7ef1c3e977dbaf63acd2e6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c100(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b140)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
