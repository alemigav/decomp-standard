/* FUN_8005889c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005889c  body 0x8005889c..0x800588bb  size 32 B
 * body sha256 eaeb16e46258445860d3e3456a818a2803bd3b8f93e1ece76db5c8e7b85d03fa
 * provider record sha256 c8cdd6a53cbf7d67d4928aa8f555c0a874c48f699f35ecf9e92eeb5f1ac3584b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058894::caseD_0(void)

{
  char cVar1;
  char cVar2;
  uint *unaff_s1;
  
  *(undefined1 *)((int)unaff_s1 + 7) = 1;
  unaff_s1[0x7a] = 0x7000700;
  *unaff_s1 = *unaff_s1 | 4;
  cVar2 = FUN_80089d54();
  *(char *)((int)unaff_s1 + 7) = *(char *)((int)unaff_s1 + 7) + cVar2;
  cVar2 = '\x0e';
  if (*(char *)(unaff_s1 + 2) == '\x0f') {
    cVar1 = *(char *)((int)unaff_s1 + 0x1e9);
    cVar2 = '\x1a';
  }
  else {
    cVar1 = *(char *)((int)unaff_s1 + 0x1e9);
  }
  if (cVar1 == cVar2) {
    *(undefined1 *)((int)unaff_s1 + 7) = 2;
  }
  return;
}
