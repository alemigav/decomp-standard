/* FUN_8009e13c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e13c  body 0x8009e13c..0x8009e1b3  size 120 B
 * body sha256 3db4bd2758bdb0e8834b2a09bc220dfc5bc375dfd176c9366240cfde3d7f68ce
 * provider record sha256 701e1071f130d78951d1f1509875c7de6a934b10ba2e8ec5afa0f0a20bb62574
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e13c(void)

{
  if (DAT_8013273a == 0x5a) {
    func_0x80004a6c(1,10);
  }
  if (DAT_8013273a == 100) {
    DAT_80132740 = 0x300;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x150) {
    DAT_80132740 = 0x300;
    FUN_8009e8d4(0xb,0);
    DAT_8013273a = 0;
    DAT_8013272e = 7;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
