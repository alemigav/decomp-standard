/* FUN_80036ff8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036ff8  body 0x80036ff8..0x80037027  size 48 B
 * body sha256 96d4cc103c2b571cd8b2ba772b09340841ed366e8bb827b3584d809129bfc848
 * provider record sha256 46172ffa69bdc4234079d1c7067e02511f6f633c3ea8d2599f14a970ae64647d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80036ff0::caseD_0(void)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int unaff_s1;
  int unaff_s2;
  short unaff_s3;
  short sStack00000010;
  short sStack00000014;
  
  sVar1 = FUN_80032d14((int)*(short *)(unaff_s2 + 0x2a),(int)*(short *)(unaff_s2 + 0x32),
                       (int)*(short *)(unaff_s1 + 2),(int)*(short *)(unaff_s1 + 10));
  sVar2 = FUN_80032d14(0,0,(int)sStack00000010,(int)sStack00000014);
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
