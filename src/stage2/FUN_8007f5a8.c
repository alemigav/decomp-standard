/* FUN_8007f5a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f5a8  body 0x8007f5a8..0x8007f63f  size 152 B
 * body sha256 b21b87b7cbdc7b9032acb88868de22b916191f31e88ddcc08d433549875ddaf3
 * provider record sha256 4635936a363d6589107802f365ab83c4efc801ce0924851c5f325fe2453502a4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f5a8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b4a4)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}
