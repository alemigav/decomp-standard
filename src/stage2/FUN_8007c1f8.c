/* FUN_8007c1f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c1f8  body 0x8007c1f8..0x8007c273  size 124 B
 * body sha256 b2a5029041a33d8841717dee97b3e55cbb3991cd2f4ad8873616216f96f1b238
 * provider record sha256 9e928f402170826c8a43b8f06af3a6d5d6605a4a145b5b1807cfb6c0cd5cb80f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c1f8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b1b0)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
