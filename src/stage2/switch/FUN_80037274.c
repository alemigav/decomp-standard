/* FUN_80037274
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037274  body 0x80037274..0x80037297  size 36 B
 * body sha256 d2f84c61dc3d8960f141d60fdf0f2e593572b827f988ce496e464f1deefee789
 * provider record sha256 83584662b05b658a26bc28cd8e205d248a276da958a2ab9ac3ebcf1ebdbfff84
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003722c::caseD_4(void)

{
  short sVar1;
  uint uVar2;
  int unaff_s0;
  int unaff_s1;
  short unaff_s2;
  short sStack00000010;
  short sStack00000012;
  
  sVar1 = FUN_80032d14(0,0,(int)sStack00000012,(int)sStack00000010);
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
