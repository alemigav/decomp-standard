/* FUN_8003a980
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a980  body 0x8003a980..0x8003a98b  size 12 B
 * body sha256 a1bb53aa8aee733b7a66915e8541be69c1cc451a794f39b23402c30387ef0269
 * provider record sha256 07c4919556ce0705567dab7ffad970c074bb8f73ea39c0a227cf49c54c90dfec
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003a604::caseD_1(void)

{
  FUN_800275c0(0,0x1800,0x8421,0);
  *(char *)(DAT_800ebb94 + 2) = *(char *)(DAT_800ebb94 + 2) + '\x01';
  return;
}
