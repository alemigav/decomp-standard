/* FUN_8009d900
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d900  body 0x8009d900..0x8009d977  size 120 B
 * body sha256 6e1bba7a56a264a1865d5e8b5538cd89205833b54170ccf517b9ae4f9f603de2
 * provider record sha256 df845a1cbbec3d324b59ea36a71f41bb1d8290bb23a51bde2e61eab2b24a94fb
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009d900(void)

{
  if (DAT_8013273a == 0xf0) {
    func_0x80004a6c(1,6);
  }
  if (DAT_8013273a == 0xfa) {
    DAT_80132740 = 3;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x20b) {
    DAT_80132740 = 3;
    FUN_8009e8d4(0xb,0);
    DAT_8013273a = 0;
    DAT_8013272e = 2;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
