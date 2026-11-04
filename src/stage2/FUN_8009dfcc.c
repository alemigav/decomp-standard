/* FUN_8009dfcc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009dfcc  body 0x8009dfcc..0x8009e043  size 120 B
 * body sha256 14e06e640d8955af2987951abd8c3b89af3a640fa529cf58c74157e37f405dbc
 * provider record sha256 24cad9c719ce829d0e391e9306ad4e0feace31e79f435c6dd247426753f3bebb
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009dfcc(void)

{
  if (DAT_8013273a == 10) {
    func_0x80004a6c(1,8);
  }
  if (DAT_8013273a == 0x14) {
    DAT_80132740 = 0x30;
    FUN_8009e8d4(7,0);
  }
  if (DAT_8013273a == 0x8c) {
    DAT_80132740 = 0x30;
    FUN_8009e8d4(0xb,0);
    DAT_8013273a = 0;
    DAT_8013272e = 4;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
