/* FUN_8007f510
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f510  body 0x8007f510..0x8007f5a7  size 152 B
 * body sha256 5446658d220f0f9ca7caec32e63433b3a7d038919234242b23c736a1bb615557
 * provider record sha256 3cfd3862d5771541036b4e2cbdf7024fe2d4b538a870d79dedee5d89e4a50d93
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f510(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b46c)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}
