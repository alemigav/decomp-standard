/* FUN_8007be18
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007be18  body 0x8007be18..0x8007be93  size 124 B
 * body sha256 1b4dcd0154514a95d620ca9ce2c596463780d1263d229d89f5b934dacdb3994e
 * provider record sha256 af08d339c0df76b49ab717a396655b1acf426f66585f0428522e8048b2b4935f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007be18(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011aff0)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
