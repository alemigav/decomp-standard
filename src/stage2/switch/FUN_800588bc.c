/* FUN_800588bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800588bc  body 0x800588bc..0x8005890f  size 84 B
 * body sha256 12714088a3f2468e581bdcd603e801836fc1bcd253549cf2ca09be39151558f2
 * provider record sha256 ee647446b298124d08282e4aa38ec9288aeafbf31f23deca9a90a2510e883b99
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058894::caseD_1(void)

{
  char cVar1;
  char cVar2;
  int unaff_s1;
  
  cVar2 = FUN_80089d54();
  *(char *)(unaff_s1 + 7) = *(char *)(unaff_s1 + 7) + cVar2;
  cVar2 = '\x0e';
  if (*(char *)(unaff_s1 + 8) == '\x0f') {
    cVar1 = *(char *)(unaff_s1 + 0x1e9);
    cVar2 = '\x1a';
  }
  else {
    cVar1 = *(char *)(unaff_s1 + 0x1e9);
  }
  if (cVar1 == cVar2) {
    *(undefined1 *)(unaff_s1 + 7) = 2;
  }
  return;
}
