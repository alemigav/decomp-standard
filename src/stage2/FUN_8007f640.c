/* FUN_8007f640
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f640  body 0x8007f640..0x8007f6d7  size 152 B
 * body sha256 c7226a5e8f60d4328c8e04daa8da3ec43bde1346244ce88ba2cee924e1a19dc7
 * provider record sha256 cc1f6c6df45d59650cfd935b0f6d7b0c3d96c5c2f5fa65b31da8a3615e1fe544
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f640(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b4dc)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}
