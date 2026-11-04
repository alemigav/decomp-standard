/* FUN_8009e1b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e1b4  body 0x8009e1b4..0x8009e22b  size 120 B
 * body sha256 2ef700edeafb1dc86694a4e2f061a5bafaf6d28d3693a4cd9f014551e3b994e0
 * provider record sha256 7458926f4725e89c601bf5acb09b66f66b2e4caf544b1b07636bb704a6db459b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e1b4(void)

{
  if (DAT_8013273a == 1) {
    func_0x80004a6c(1,0xb);
  }
  if (DAT_8013273a == 0xb) {
    DAT_80132740 = 0xc00;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x10a) {
    DAT_80132740 = 0xc00;
    FUN_8009e8d4(0xb,0);
    DAT_8013273a = 0;
    DAT_8013272e = 8;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
