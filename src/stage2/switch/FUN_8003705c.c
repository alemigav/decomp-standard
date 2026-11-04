/* FUN_8003705c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003705c  body 0x8003705c..0x8003708b  size 48 B
 * body sha256 7e5b89b7e95277bc6a0b54d13cbda5d5f449a259519aec4d8bd23f203db69794
 * provider record sha256 f7f7502c57c1c0e9f15f03fa30a13db2fb594a96c3b9c74e2c81e04ca5520b0f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80036ff0::caseD_2(void)

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
  uVar3 = ((int)sVar1 - (int)sVar2) + (int)unaff_s3 & 0xfff;
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
