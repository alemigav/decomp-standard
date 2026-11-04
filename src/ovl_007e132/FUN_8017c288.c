/* FUN_8017c288
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017c288  body 0x8017c288..0x8017c31b  size 148 B
 * body sha256 56aa640266865fc99bf63ba715f5503670742d99458cb74da0e070aec4c772ce
 * provider record sha256 4fbae0313124dd247c0fd7e32be0155075b7508d4f72a0cc4397edf0bb1cbf2a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017c288(void)

{
  if (DAT_8017e735 == '\0') {
    FUN_8017e20c(0xc68);
    DAT_8017e735 = '\x01';
  }
  FUN_8017c664();
  DAT_8017e704 = DAT_8017e704 + 1;
  if ((int)(uint)*(ushort *)(DAT_8017e73c + 0x14) < (int)DAT_8017e704) {
    DAT_8017e730 = 0;
    DAT_8017e72e = 0;
    DAT_8017e700 = 0;
    DAT_8017e704 = 0;
    DAT_8017e702 = DAT_8017e702 + 1;
  }
  return;
}
