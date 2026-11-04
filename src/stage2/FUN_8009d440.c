/* FUN_8009d440
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d440  body 0x8009d440..0x8009d55b  size 284 B
 * body sha256 fe5b3c33146a3c898355c40511d9b0ddf9c7543ccc41998fbdcf87c4c911c4fa
 * provider record sha256 f014ef2aa46a47cc52b034e1a725e9eac596321ccb372db7af6255955b5b58ba
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009d440(void)

{
  if (DAT_8013273a == 0x5e) {
    DAT_80132740 = 0;
    FUN_8009e8d4(0,1);
    func_0x80004a6c(1,4);
  }
  if (DAT_8013273a == 0x68) {
    DAT_80132740 = 0x60000;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x226) {
    DAT_80132708 = 0;
    DAT_8013270c = 0;
    DAT_80132710 = 0;
    DAT_80132714 = 0;
    DAT_80132718 = 0;
    DAT_8013271c = 0;
    DAT_80132720 = 0;
    DAT_80132728 = DAT_80132728 ^ 2;
    FUN_8009ced8();
    DAT_80132740 = 0x60000;
    FUN_8009e8d4(0xb,0);
  }
  if (DAT_8013273a == 0x244) {
    DAT_80132728 = 8;
    DAT_80132740 = 0x80000;
    FUN_8009e8d4(0x27,0);
    DAT_8013272e = 5;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
