/* FUN_8009dbec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009dbec  body 0x8009dbec..0x8009dce3  size 248 B
 * body sha256 56862e90e16e4c7f5b24315747209b9cecc72b7d6279a0a49eba3635b2dcd3a0
 * provider record sha256 fe0ebdb568602e2eb2751dd70c946c51ecce269bc25e5809bc5f2036adb78cc7
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009dbec(void)

{
  int iVar1;
  
  if (DAT_8013273a == 0x80) {
    func_0x80004a6c(1,0xc);
  }
  if (DAT_8013273a == 0x8a) {
    DAT_80132740 = 0xc00;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x133) {
    DAT_80132740 = 0xc00;
    FUN_8009e8d4(0xb,0);
  }
  if (DAT_8013273a == 0x205) {
    FUN_80077430(0x5a,0x18);
    DAT_80132728 = 8;
    FUN_8009ced8();
    DAT_80132729 = 0;
    DAT_8013272c = 2;
  }
  if ((0x205 < DAT_8013273a) && (iVar1 = FUN_8002767c(DAT_8013272b), iVar1 != 0)) {
    DAT_80132740 = 0;
    FUN_8009e8d4(0,1);
    DAT_80132729 = 1;
    DAT_8013272e = 7;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
