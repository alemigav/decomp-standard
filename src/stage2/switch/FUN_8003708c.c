/* FUN_8003708c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003708c  body 0x8003708c..0x800370bf  size 52 B
 * body sha256 daef59608f11d64f2d67648f7316c136a9819465d0408d596e59f9dd840444de
 * provider record sha256 d00cd6aa4e0d4e58459b0d4a8e18f8083099513add66824642d097015c02c614
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80036ff0::caseD_3(void)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int unaff_s1;
  int unaff_s2;
  short unaff_s3;
  short in_stack_00000012;
  short sStack00000014;
  
  sVar1 = FUN_80032d14((int)*(short *)(unaff_s2 + 0x32),(int)*(short *)(unaff_s2 + 0x2e),
                       (int)*(short *)(unaff_s1 + 10),(int)*(short *)(unaff_s1 + 6));
  sVar2 = FUN_80032d14(0,0,(int)sStack00000014,(int)in_stack_00000012);
  uVar3 = ((int)sVar2 - (int)sVar1) + (int)unaff_s3 & 0xfff;
  if ((int)unaff_s3 << 1 <= (int)uVar3) {
    if (uVar3 < 0x801) {
      sVar1 = *(short *)(unaff_s2 + 0x66) + unaff_s3;
    }
    else {
      sVar1 = *(short *)(unaff_s2 + 0x66) - unaff_s3;
    }
    *(short *)(unaff_s2 + 0x66) = sVar1;
  }
  return;
}
