/* FUN_8009d2fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d2fc  body 0x8009d2fc..0x8009d43f  size 324 B
 * body sha256 c50110cd8b925cd47c25bc192df02fa16e6587e3734c111ac87e878adb43969c
 * provider record sha256 a576950c2033d4c815d8189da6a9d5c49a12d5ae8996d8b9d774e57ce8e714ff
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009d2fc(void)

{
  if (DAT_8013273a == 0x5e) {
    FUN_80025f78(1,2,&DAT_8013267c);
    DAT_8013272b = 3;
    FUN_8009ce40();
    DAT_80132740 = 0x7800;
    FUN_8009e8d4(7,0);
    func_0x80004a6c(1,3);
  }
  if (DAT_8013273a == 0x68) {
    DAT_80132740 = 0x18000;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0xcc) {
    DAT_80132740 = 0x400;
    FUN_8009e8d4(0x4b,0);
  }
  if (DAT_8013273a == 0x17d) {
    DAT_80132740 = 0x18000;
    FUN_8009e8d4(0xb,0);
  }
  if (DAT_8013273a == 0x19b) {
    FUN_80025f78(0,2,&DAT_80132698);
    DAT_8013272b = 3;
    DAT_80132728 = 0;
    FUN_8009ced8();
    DAT_8013272b = 0;
    FUN_8009ce40();
    DAT_80132740 = 0x7800;
    FUN_8009e8d4(0xb,0);
    DAT_8013272e = 4;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
