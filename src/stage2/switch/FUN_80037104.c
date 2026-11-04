/* FUN_80037104
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037104  body 0x80037104..0x800371a3  size 160 B
 * body sha256 5066d86cf8a65a9ed86cff9bcb0a63961bcd7f0621e777166036ae844e57d2d9
 * provider record sha256 2d3ba05d11ab191818d8b3b72f31fdc32ec697185a0205b7cddfdd3520bea2cd
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80036ff0::caseD_5(void)

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
