/* FUN_8007ec14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ec14  body 0x8007ec14..0x8007ec5f  size 76 B
 * body sha256 f86a15fd9bc216da36834cd877fdab0551f746df5da98e44575942249e4dc00b
 * provider record sha256 ae07982b5ade18a7c51a90bee6604a7caa45df00fd2fff709fb229881cbcbe07
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e960::caseD_5(void)

{
  char cVar1;
  int unaff_s1;
  
  *(char *)(unaff_s1 + 0x1a2) = -(char)(*(int *)(unaff_s1 + 0x2c) / 0x708);
  cVar1 = FUN_80089d54();
  *(char *)(unaff_s1 + 7) = *(char *)(unaff_s1 + 7) + cVar1;
  return;
}
