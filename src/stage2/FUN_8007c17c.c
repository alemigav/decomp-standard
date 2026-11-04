/* FUN_8007c17c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c17c  body 0x8007c17c..0x8007c1f7  size 124 B
 * body sha256 8fdba8989cfa54b17ea2ff5dadb54ec973de64c7eaf9e0a6308b643c10c157bd
 * provider record sha256 cbf951daeefeb95ac09b7cd0dc2560d0bf816413189a06025ce779e10277fa7f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c17c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b178)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
