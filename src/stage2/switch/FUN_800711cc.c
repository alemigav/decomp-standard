/* FUN_800711cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800711cc  body 0x800711cc..0x800711db  size 16 B
 * body sha256 549c40cbb7e42a2b9c0370aff4084fda209d4ad98ad6c24e7fda069c39970163
 * provider record sha256 3e550d0baa5527b3ca8f4a48ea016b61ee3078724bd8269b34bd28ceaa845bf6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4
switchD_800711c4::caseD_0
          (undefined4 param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5)

{
  int unaff_s0;
  int unaff_s1;
  int iStack00000014;
  int iStack00000018;
  
  param_5 = (int)*(short *)(unaff_s0 + 6);
  iStack00000014 = (int)*(short *)(unaff_s0 + 8);
  iStack00000018 = (int)*(short *)(unaff_s0 + 10);
  FUN_80077adc(param_4 << 0x18 | (param_3 >> 8) << 0x10 | param_3 & 0xff,&param_5);
  *(int *)(unaff_s1 + 0x1c) = unaff_s0 + 0xc;
  return 1;
}
