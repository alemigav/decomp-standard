/* FUN_8016655c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x8016655c  body 0x8016655c..0x8016658f  size 52 B
 * body sha256 bde3c57b790b2a7c165727b735087decdaa33cfb7cbdc7b412d912dcc67094cd
 * provider record sha256 6308ad3c8a44057e44a54361e33582aac71338c916ced1e37d52a7e6b264209a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016655c(int param_1,int param_2,int param_3)

{
  param_2 = (uint)*(ushort *)(param_1 + 0x1e0) - param_2;
  if ((param_3 < *(short *)(param_1 + 0x1e0)) &&
     (*(short *)(param_1 + 0x1e0) = (short)param_2, param_2 * 0x10000 >> 0x10 < param_3)) {
    *(short *)(param_1 + 0x1e0) = (short)param_3;
  }
  return;
}
