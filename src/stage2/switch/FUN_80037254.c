/* FUN_80037254
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037254  body 0x80037254..0x80037263  size 16 B
 * body sha256 e3939d93771f0325e1abc15c4324154288ba37d522b86080e23c1414896c3c38
 * provider record sha256 2c0cdd1ff92c7cd5ff4e051d0ed57d2a500d1116f398077fe94ac1c5dd523c54
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003722c::caseD_2(void)

{
  short sVar1;
  uint uVar2;
  int unaff_s0;
  int unaff_s1;
  short unaff_s2;
  short in_stack_00000012;
  short sStack00000014;
  
  sVar1 = FUN_80032d14(0,0,(int)sStack00000014,(int)in_stack_00000012);
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
