/* FUN_800711fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800711fc  body 0x800711fc..0x8007121b  size 32 B
 * body sha256 dedadccf3d51869140e29c44e302cc71300f78ff89520b0568d8af7f7a024b2a
 * provider record sha256 23ce5823c0d32c1021473ad77d7d3c9d32c3c4dbe6d9f645fe247f670fc9ede3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4
switchD_800711c4::caseD_2
          (undefined4 param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5)

{
  int unaff_s0;
  int unaff_s1;
  int iStack00000014;
  int iStack00000018;
  
  param_5 = (int)*(short *)(unaff_s0 + 6) + *(int *)(DAT_800e13ec + 0x28);
  iStack00000014 = (int)*(short *)(unaff_s0 + 8) + *(int *)(DAT_800e13ec + 0x2c);
  iStack00000018 = (int)*(short *)(unaff_s0 + 10) + *(int *)(DAT_800e13ec + 0x30);
  FUN_80077adc(param_4 << 0x18 | (param_3 >> 8) << 0x10 | param_3 & 0xff,&param_5);
  *(int *)(unaff_s1 + 0x1c) = unaff_s0 + 0xc;
  return 1;
}
