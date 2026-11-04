/* FUN_8006e8bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e8bc  body 0x8006e8bc..0x8006e8f3  size 56 B
 * body sha256 c01997d4ad93739b89dd1b2101d7374794d2e67b4cb9ce29cb5fd473e58d4298
 * provider record sha256 d8cfeabe58ce81c019b04ba096b36b7a13b38567de839a21fce0b16c2b9a85a2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e880::caseD_3(void)

{
  int unaff_s0;
  short *unaff_s1;
  
  if (unaff_s0 == 0) {
    trap(0x1c00);
  }
  if ((unaff_s0 == -1) && (*unaff_s1 == -0x80000000)) {
    trap(0x1800);
  }
  *unaff_s1 = (short)((int)*unaff_s1 / unaff_s0);
  return;
}
