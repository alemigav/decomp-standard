/* FUN_8007f6d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f6d8  body 0x8007f6d8..0x8007f76f  size 152 B
 * body sha256 64dc950e4d5de8f073bb8dcbdfb3932ecfea6942e1db6cd1bdfb6fd3f0fa1677
 * provider record sha256 b857968bd08bcebfed2ad9562fcc22623a6e78bbd9ea8e74bf9b5e7fb0e45916
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f6d8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b514)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}
