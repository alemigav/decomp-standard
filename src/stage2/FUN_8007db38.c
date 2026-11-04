/* FUN_8007db38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007db38  body 0x8007db38..0x8007db6b  size 52 B
 * body sha256 6a1931baf1c104efd6dcc5d54ee0c59d03de2f1afe1a69f393d87bf43fd0ecaf
 * provider record sha256 bf42ecd7dc48dd5899652e82aab9a3a83a0e497f636f6394aec51d9f7ddb67ce
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007db38(int param_1)

{
  (*(code *)(&PTR_FUN_8011b28c)[*(byte *)(param_1 + 6)])();
  return;
}
