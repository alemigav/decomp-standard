/* FUN_8007f180
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f180  body 0x8007f180..0x8007f217  size 152 B
 * body sha256 9cab0f18eceec4c68567fa0f9a64005c8d35fa561ac75234b26c029f00a48e11
 * provider record sha256 b9e431e1f9a90efce074d23be4dcc9b4d00fe52a12af43591ceec9f438d6d777
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f180(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b31c)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}
