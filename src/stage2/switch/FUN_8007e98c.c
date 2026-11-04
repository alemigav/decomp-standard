/* FUN_8007e98c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e98c  body 0x8007e98c..0x8007e9d7  size 76 B
 * body sha256 a89c72e9d1f3f71aee5ad43da7f96941361f4efbbf78e8881d9ce2341f0b36b9
 * provider record sha256 8146395c3f53e29084607b7454bdfec2329249bb8c5ad08a85a417197ed76d20
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8007e960::caseD_1(void)

{
  char cVar1;
  char cVar2;
  int unaff_s1;
  
  FUN_80089d54();
  if ((*(char *)(unaff_s1 + 8) == 'E') || (cVar2 = '\x0e', *(char *)(unaff_s1 + 8) == 'O')) {
    cVar1 = *(char *)(unaff_s1 + 0x1e9);
    cVar2 = '\x1d';
  }
  else {
    cVar1 = *(char *)(unaff_s1 + 0x1e9);
  }
  if (cVar1 == cVar2) {
    *(undefined1 *)(unaff_s1 + 7) = 2;
  }
  return;
}
