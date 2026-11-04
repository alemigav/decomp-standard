/* FUN_800370c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800370c0  body 0x800370c0..0x80037103  size 68 B
 * body sha256 7feff768aeb3b381b32ef61f98d6cdf461b80be91ed706a7d789d8055246891a
 * provider record sha256 f0fac1e7742a2671639a9f1060fc31875e53c71d4cc0abc1c75c80c37cda1e60
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80036ff0::caseD_4(void)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int unaff_s1;
  int unaff_s2;
  short unaff_s3;
  short sStack00000010;
  short sStack00000012;
  
  sVar1 = FUN_80032d14((int)*(short *)(unaff_s2 + 0x2e),(int)*(short *)(unaff_s2 + 0x2a),
                       (int)*(short *)(unaff_s1 + 6),(int)*(short *)(unaff_s1 + 2));
  sVar2 = FUN_80032d14(0,0,(int)sStack00000012,(int)sStack00000010);
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
