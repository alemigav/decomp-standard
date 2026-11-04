/* FUN_80058f38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058f38  body 0x80058f38..0x80058f4b  size 20 B
 * body sha256 227e349866e3714bdc9eb3975dce5a64142a0324ddb9edb741e9c15d6c7dd7ad
 * provider record sha256 26698da79f87aa5712e52fb14e60b5c4361fcc0371acc4a4885edb5a936b176c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058e58::caseD_2(void)

{
  char cVar1;
  int unaff_s0;
  
  *(undefined1 *)(unaff_s0 + 6) = 3;
  *(undefined4 *)(unaff_s0 + 0x1e8) = 0x7000700;
  cVar1 = FUN_80089d54();
  *(char *)(unaff_s0 + 6) = *(char *)(unaff_s0 + 6) + cVar1;
  return;
}
