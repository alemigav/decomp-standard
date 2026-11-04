/* FUN_800283b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800283b0  body 0x800283b0..0x800283ef  size 64 B
 * body sha256 4fa9cf48f26e7e4d98c5eeada375d423312d2b123d5bc728e34e3ce07eb3b967
 * provider record sha256 7db9ba3820d152905993e73b6a7cce3419aeeafaece1e22cb116d2efa119d6cc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800283b0(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 4) = 0;
  }
  else {
    (**(code **)(*(int *)(param_1 + 4) + 0x28))();
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}
