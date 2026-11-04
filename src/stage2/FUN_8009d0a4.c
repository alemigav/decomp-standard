/* FUN_8009d0a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d0a4  body 0x8009d0a4..0x8009d1c7  size 292 B
 * body sha256 151aa23b3310189af42280c0fca421ecd0e3b030655f9761986ed2ed1a772a1d
 * provider record sha256 7e05cc5a3c8c4df100b29b51d649afb877d66713366a95ba4d808f9eec7608f8
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009d0a4(void)

{
  if (DAT_8013273a == 0xf0) {
    FUN_80025f78(1,2,&DAT_80132644);
    FUN_80025f78(0,2,&DAT_80132628);
    FUN_8009ce40();
  }
  if (DAT_8013273a == 0x1a4) {
    func_0x80004a6c(1,1);
  }
  if (DAT_8013273a == 0x1ae) {
    DAT_80132740 = 3;
    FUN_8009e8d4(7,1);
  }
  if (DAT_8013273a == 0x319) {
    DAT_80132740 = 3;
    FUN_8009e8d4(0xb,0);
  }
  if (DAT_8013273a == 0x337) {
    DAT_80132658 = DAT_800c52d8 + 62000;
    FUN_80025f78(0,2);
    FUN_8009ced8();
    DAT_8013272b = 0;
    FUN_8009ce40();
    DAT_80132728 = 8;
    DAT_80132740 = 0x3c;
    FUN_8009e8d4(0x17,0);
    DAT_8013272e = 2;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
