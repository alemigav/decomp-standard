/* FUN_80037028
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037028  body 0x80037028..0x8003705b  size 52 B
 * body sha256 a439388ce1cac67d7fb7db1ab8747403130e17d0fb159dee9ee0665ee51f8813
 * provider record sha256 52192c14841c96d624fa9b06cd92961028f3ac882516b258ea7edb02af3af10c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80036ff0::caseD_1(void)

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
