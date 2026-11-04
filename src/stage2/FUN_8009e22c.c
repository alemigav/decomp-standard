/* FUN_8009e22c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009e22c  body 0x8009e22c..0x8009e323  size 248 B
 * body sha256 7e02b43234dd9e38c77d1e1f60164d444e1103038ffc16c5b2bf3ff5e9a75788
 * provider record sha256 9246244ec667d5c887d61d8fa43edcdbf12205a88752f70c1c3acbad5748dc81
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009e22c(void)

{
  if (DAT_8013273a == 1) {
    func_0x80004a6c(1,0xc);
  }
  if (DAT_8013273a == 0xb) {
    DAT_80132740 = 0x3000;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x1b9) {
    DAT_80132740 = 0x3000;
    FUN_8009e8d4(0xb,0);
    FUN_80025f78(1,2,&DAT_80132660);
    FUN_8009ce40();
  }
  if (DAT_8013273a == 0x1c3) {
    DAT_80132740 = 0xc000;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x2e2) {
    DAT_80132740 = 0xc000;
    FUN_8009e8d4(0xb,0);
  }
  if (DAT_8013273a == 0x300) {
    DAT_8013273a = 0;
    DAT_8013272e = 9;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
