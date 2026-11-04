/* FUN_80059040
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059040  body 0x80059040..0x8005906b  size 44 B
 * body sha256 f430ab3b48fa8e1111ddfd0ee35bdb9b68492ce987d25dd64843bb21d5d4482f
 * provider record sha256 993ee6cfa43ba7995ab2ff1189919bce9cf3fb97f0e4357607d9cbbc601ba74b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058e58::caseD_6(void)

{
  char cVar1;
  int unaff_s0;
  
  cVar1 = FUN_80089d54();
  *(char *)(unaff_s0 + 6) = *(char *)(unaff_s0 + 6) + cVar1;
  return;
}
