/* FUN_8009dedc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009dedc  body 0x8009dedc..0x8009df53  size 120 B
 * body sha256 136ca4b9772740dfcf6599611cac66197bc8d9348652175d7188e96cdd3ef0a0
 * provider record sha256 de84220c4d614b1fef794fa3edbfd8111071ccef342a82e1102dfc41211342a5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009dedc(void)

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
