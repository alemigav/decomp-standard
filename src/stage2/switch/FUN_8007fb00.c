/* FUN_8007fb00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007fb00  body 0x8007fb00..0x8007fb0b  size 12 B
 * body sha256 d6d184a258a53371e45ddb229bbe87852108c9c51d792cab4ccff39369b7b46a
 * provider record sha256 834a25e7345afba1f06a5b97f301a208cccc7257a2c99fb60dd3769cf4f9343c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007f9a8::caseD_4(void)

{
  char cVar1;
  int unaff_s0;
  
  cVar1 = FUN_80089d54();
  *(char *)(unaff_s0 + 6) = *(char *)(unaff_s0 + 6) + cVar1;
  return;
}
