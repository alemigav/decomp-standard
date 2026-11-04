/* FUN_80061b18
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80061b18  body 0x80061b18..0x80061bab  size 148 B
 * body sha256 547edf6b0086564a22bbd477d8d06cd5966a4c74863b5748c43dad0900ab9aa5
 * provider record sha256 788867168c101b35dec59e4910eb1fc2d55057375ab2cf85da37fb631e9f1917
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80061694::caseD_5(void)

{
  char cVar1;
  int unaff_s0;
  uint unaff_s2;
  
  *(undefined2 *)(unaff_s0 + 6) = 0x100;
  cVar1 = DAT_800df8c0;
  if (((unaff_s2 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + -0x20;
  }
  if (((unaff_s2 & 2) != 0) || ('\x19' < cVar1)) {
    *(short *)(unaff_s0 + 0x66) = *(short *)(unaff_s0 + 0x66) + 0x20;
  }
  return;
}
