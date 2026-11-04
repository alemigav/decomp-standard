/* FUN_8007bf10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007bf10  body 0x8007bf10..0x8007bf8b  size 124 B
 * body sha256 536796c25d969b2a1f489c91b8d0d3b307740ae945f2349380d70273271e20f2
 * provider record sha256 cb6b8fcd5a5c822ae6e32fca3f134c1cb759dc88dacfbae02f8862486f8131df
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007bf10(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b060)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
