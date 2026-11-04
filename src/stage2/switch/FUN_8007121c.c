/* FUN_8007121c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007121c  body 0x8007121c..0x8007124b  size 48 B
 * body sha256 90466b63fca9a4e2c7c1beb1a0c516b95c9347a2b9fc87abbdb4f2d19f79b6d0
 * provider record sha256 c20f240082214274ca88ae0df9ba4a718ac0abd303a939b0f029e1636c993ad5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4
switchD_800711c4::caseD_3
          (undefined4 param_1,uint param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int unaff_s0;
  int unaff_s1;
  int iStack00000014;
  int iStack00000018;
  
  iVar1 = (&DAT_800e13e8)[(param_2 & 0xff) + 2];
  param_5 = (int)*(short *)(unaff_s0 + 6) + *(int *)(iVar1 + 0x28);
  iStack00000014 = (int)*(short *)(unaff_s0 + 8) + *(int *)(iVar1 + 0x2c);
  iStack00000018 = (int)*(short *)(unaff_s0 + 10) + *(int *)(iVar1 + 0x30);
  FUN_80077adc(param_4 << 0x18 | (param_3 >> 8) << 0x10 | param_3 & 0xff,&param_5);
  *(int *)(unaff_s1 + 0x1c) = unaff_s0 + 0xc;
  return 1;
}
