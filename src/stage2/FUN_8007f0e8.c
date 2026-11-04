/* FUN_8007f0e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f0e8  body 0x8007f0e8..0x8007f17f  size 152 B
 * body sha256 b682f615a22797b2e1b66608b668b3b38cadfad95fda08af5a7744d8397e69d0
 * provider record sha256 3fecbee8a443ad45bcf776ea43a15e1a5a90b61c5dbd8e4fe767a27a33515f74
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f0e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b2e4)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}
