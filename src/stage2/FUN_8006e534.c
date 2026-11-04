/* FUN_8006e534
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e534  body 0x8006e534..0x8006e573  size 64 B
 * body sha256 ffb09736a136773ffbb66e7859bdd0d0ec0332c7af1babe39325904a24151c1a
 * provider record sha256 ee0842579906dab3549c11de2ecb4f197234c570f68f1c00f11593c843e2346a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006e534(int param_1)

{
  FUN_80065034();
  DAT_80114f3b = 1;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return 1;
}
