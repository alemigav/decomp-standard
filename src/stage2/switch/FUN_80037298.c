/* FUN_80037298
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037298  body 0x80037298..0x8003730f  size 120 B
 * body sha256 3b07ff18a500ee74c409596ad51933ed7dc324c8d452a0931b2db2d09b597164
 * provider record sha256 8ef266d37b8c7ed1fe1fbf1730665fbd9342c00d89501d6e69612b0d7c728da0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003722c::caseD_5(void)

{
  short sVar1;
  uint uVar2;
  int unaff_s0;
  int unaff_s1;
  short unaff_s2;
  short sStack00000010;
  short sStack00000012;
  
  sVar1 = FUN_80032d14(0,0,(int)sStack00000012,(int)sStack00000010);
  uVar2 = (sVar1 - unaff_s0) + (int)unaff_s2 & 0xfff;
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
