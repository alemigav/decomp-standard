/* FUN_8017dca4
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017dca4  body 0x8017dca4..0x8017dd6f  size 204 B
 * body sha256 428f9e547c4ae933fe1c9bf9200eb37cbe74c1b2b1dd42530c37a477281708d3
 * provider record sha256 06a26b8132f55ec12025ccb1257e9c5848bb36c154df2883222547a4b0efd740
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017dca4(void)

{
  *(undefined4 *)(DAT_80186c94 + 0x42c) = 1;
  DAT_801857dc = FUN_8017bec8(10);
  FUN_8017bbe8(1);
  DAT_801857e0 = FUN_8017bec8(0xf);
  if (0x3fff < DAT_801857e0) {
    DAT_801857e0 = DAT_801857e0 + -0x8000;
  }
  FUN_8017bbe8(1);
  DAT_801857e4 = FUN_8017bec8(0xf);
  if (0x3fff < DAT_801857e4) {
    DAT_801857e4 = DAT_801857e4 + -0x8000;
  }
  DAT_801857c0 = FUN_8017bec8(2);
  DAT_801857e8 = FUN_8017bec8(1);
  DAT_801857ec = FUN_8017bec8(1);
  return;
}
