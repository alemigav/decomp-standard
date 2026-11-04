/* FUN_8003a998
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a998  body 0x8003a998..0x8003a9a7  size 16 B
 * body sha256 629c8dfa6e468f9a9f442d90491de3b4c55a60919653eeceef91c89c5b625162
 * provider record sha256 351e0b4d7b869b0b06cdf0bd68d1b24c3eceabcc6552a2b3736a340ba0fdecac
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003a604::caseD_3(void)

{
  FUN_80027650(0);
  *(char *)(DAT_800ebb94 + 2) = *(char *)(DAT_800ebb94 + 2) + '\x01';
  return;
}
