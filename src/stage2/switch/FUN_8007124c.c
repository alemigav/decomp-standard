/* FUN_8007124c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007124c  body 0x8007124c..0x800712e7  size 156 B
 * body sha256 e39795b4a68d46297152cb46c639d043b23d3ab86beccce9aaa3263e601d2e58
 * provider record sha256 6eedd22e2d36b0bbc9cbc124bbeee0dc8765fd8fe8c9f35d2cfcfe5c36ce0ce2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4
switchD_800711c4::caseD_4
          (undefined4 param_1,uint param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int unaff_s0;
  int unaff_s1;
  int iStack00000014;
  int iStack00000018;
  
  iVar1 = (param_2 & 0xff) * 0x368;
  param_5 = (int)*(short *)(unaff_s0 + 6) + *(int *)(&DAT_800e1920 + iVar1);
  iStack00000014 = (int)*(short *)(unaff_s0 + 8) + (&DAT_800e1924)[(param_2 & 0xff) * 0xda];
  iStack00000018 = (int)*(short *)(unaff_s0 + 10) + *(int *)(&DAT_800e1928 + iVar1);
  FUN_80077adc(param_4 << 0x18 | (param_3 >> 8) << 0x10 | param_3 & 0xff,&param_5);
  *(int *)(unaff_s1 + 0x1c) = unaff_s0 + 0xc;
  return 1;
}
