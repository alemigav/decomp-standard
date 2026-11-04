/* FUN_8017b50c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b50c  body 0x8017b50c..0x8017b597  size 140 B
 * body sha256 d9f2b75d50959918221d63db3dae556f69aa9572b2c0b781dc550c514886ebf0
 * provider record sha256 446ca563e15ea12eb82bb29d55a834d5d429057f9a4dbbfd3dfa78ef8ae4f7a8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8017b50c(undefined4 param_1,int *param_2,uint param_3)

{
  if (DAT_80184b28 == 0) {
    FUN_8017b44c();
  }
  *param_2 = (DAT_80184b24 + 0x1000) - DAT_80184b28;
  DAT_80184b28 = DAT_80184b28 - param_3;
  if (DAT_80184b2c < param_3) {
    param_3 = DAT_80184b2c;
  }
  DAT_80184b2c = DAT_80184b2c - param_3;
  return param_3;
}
