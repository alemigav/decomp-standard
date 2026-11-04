/* FUN_800711dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800711dc  body 0x800711dc..0x800711fb  size 32 B
 * body sha256 59c850c28afd2685f6a77dd99824d40e7c890918bd7cee311bcb5e86e43644a8
 * provider record sha256 464a0dbd8b4b0233a33d22b76dc256d4a46b6d385207fbedf2c63faa490fad30
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4
switchD_800711c4::caseD_1
          (undefined4 param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5)

{
  int unaff_s0;
  int unaff_s1;
  int iStack00000014;
  int iStack00000018;
  
  param_5 = *(short *)(unaff_s0 + 6) + iRam00000028;
  iStack00000014 = *(short *)(unaff_s0 + 8) + iRam0000002c;
  iStack00000018 = *(short *)(unaff_s0 + 10) + iRam00000030;
  FUN_80077adc(param_4 << 0x18 | (param_3 >> 8) << 0x10 | param_3 & 0xff,&param_5);
  *(int *)(unaff_s1 + 0x1c) = unaff_s0 + 0xc;
  return 1;
}
