/* FUN_8009df54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009df54  body 0x8009df54..0x8009dfcb  size 120 B
 * body sha256 4db02b3ba0fc4859bb2cf493e84e17bea24b77d22537ffc254eb278bbfdc147c
 * provider record sha256 c6e5096163d40cecd37eaab2df19adad932d3b83adc6ad53c9f8e8aefe5c79fc
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009df54(void)

{
  if (DAT_8013273a == 1) {
    func_0x80004a6c(1,7);
  }
  if (DAT_8013273a == 0xb) {
    DAT_80132740 = 0xc;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x1b6) {
    DAT_80132740 = 0xc;
    FUN_8009e8d4(0xb,0);
    DAT_8013273a = 0;
    DAT_8013272e = 3;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
