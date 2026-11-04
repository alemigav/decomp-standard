/* FUN_8016513c
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x8016513c  body 0x8016513c..0x8016518b  size 80 B
 * body sha256 9a056a290ec175f3eaeb5db320c27bf2927d83bbd9b1adfd8a62e62de767f9b1
 * provider record sha256 093e2ea57f0e624717cb5c77f9df62815722447baecea518cca54d2cefa167ba
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016513c(int param_1)

{
  *(undefined2 *)(param_1 + 100) = 0;
  (*(code *)(&PTR_FUN_801667e4)[*(byte *)(param_1 + 5) - 1])();
  func_0x80035b84(param_1);
  return;
}
