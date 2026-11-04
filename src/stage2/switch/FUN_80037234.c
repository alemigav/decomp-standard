/* FUN_80037234
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037234  body 0x80037234..0x80037243  size 16 B
 * body sha256 98a816fcda196826625ab9c71b9375b6494892c1bf1151df933d308fdf8fe0f9
 * provider record sha256 13b71466af6a68894c4c6c4570a615edac052ceae4726fa9431dbc3695f41879
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003722c::caseD_0(void)

{
  short sVar1;
  uint uVar2;
  int unaff_s0;
  int unaff_s1;
  short unaff_s2;
  short sStack00000010;
  short sStack00000014;
  
  sVar1 = FUN_80032d14(0,0,(int)sStack00000010,(int)sStack00000014);
  uVar2 = (unaff_s0 - sVar1) + (int)unaff_s2 & 0xfff;
  if ((int)unaff_s2 << 1 <= (int)uVar2) {
    if (uVar2 < 0x801) {
      sVar1 = *(short *)(unaff_s1 + 0x66) + unaff_s2;
    }
    else {
      sVar1 = *(short *)(unaff_s1 + 0x66) - unaff_s2;
    }
    *(short *)(unaff_s1 + 0x66) = sVar1;
  }
  return;
}
